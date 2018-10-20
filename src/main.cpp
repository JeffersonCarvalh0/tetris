# include <SFML/Graphics.hpp>
# include <memory>
# include <random>
# include <set>

# include "defs.h"
# include "board.h"
# include "tetrimino.h"

class Window {
public:
    sf::RenderWindow window;
    sf::Texture tileset;
    sf::Font roboto;
    sf::Text scoreText;
    sf::Clock clock;

    std::shared_ptr<Tetrimino> t;
    std::shared_ptr<Tetrimino> onHold;
    std::unique_ptr<Board> board;

    std::set<int> bag;
    std::random_device rd;
    std::default_random_engine generator;

    int score;

    Window() {
        window.create(sf::VideoMode(SCREEN_WIDTH, HEIGHT), "Tetris");
        tileset.loadFromFile("../assets/textures/blocks.png");
        tileset.setSmooth(true);

        initializeText();

        board = std::unique_ptr<Board>(new Board(tileset));
        newPiece();

        generator = std::default_random_engine(rd());
        score = 0;

        while (window.isOpen()) {
            sf::Event event;

            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) window.close();
                if (event.type == sf::Event::KeyPressed) keyPressed();
            }
            update();
        }
    }

    void update() {
        window.clear(sf::Color::Black);

        if (clock.getElapsedTime().asMilliseconds() >= 1000) {
            if (t->isAtFloor()) score += board->update(*t), newPiece();
            movePiece(DOWN); clock.restart();
        }

        drawHUD();
        window.draw(*board);
        window.draw(*t);
        window.display();
    }

    void keyPressed() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) t->move(0, -BLOCK_SIZE);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) movePiece(LEFT);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) movePiece(DOWN);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) movePiece(RIGHT);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) rotatePiece(LEFT);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) rotatePiece(RIGHT);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) performHardDrop();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
    }

    void switchTetrimino(TetriminoType tt, std::shared_ptr<Tetrimino> &t) {
        switch (tt) {
            case I:
                t = std::unique_ptr<Tetrimino>(new Tetriminoes::I(tileset)); break;
            case J:
                t = std::unique_ptr<Tetrimino>(new Tetriminoes::J(tileset)); break;
            case L:
                t = std::unique_ptr<Tetrimino>(new Tetriminoes::L(tileset)); break;
            case O:
                t = std::unique_ptr<Tetrimino>(new Tetriminoes::O(tileset)); break;
            case S:
                t = std::unique_ptr<Tetrimino>(new Tetriminoes::S(tileset)); break;
            case T:
                t = std::unique_ptr<Tetrimino>(new Tetriminoes::T(tileset)); break;
            case Z:
                t = std::unique_ptr<Tetrimino>(new Tetriminoes::Z(tileset)); break;
        }
    }

    void newPiece() {
        if (bag.empty())
            for (int i = 3; i <= 9; ++i) bag.insert(i);

        std::uniform_int_distribution<int> random_piece(0, bag.size() - 1);
        int p = random_piece(generator);

        auto it = bag.begin();
        std::advance(it, p);
        p = *it;

        bag.erase(p);
        if (onHold != nullptr) {
            switchTetrimino(onHold->type, t);
            switchTetrimino(static_cast<TetriminoType>(p), onHold);
        } else {
            switchTetrimino(static_cast<TetriminoType>(p), t);
            p = random_piece(generator);
            it = bag.begin(); std::advance(it, p);
            p = *it; bag.erase(p);
            switchTetrimino(static_cast<TetriminoType>(p), onHold);
        }

        onHold->move(WIDTH, BLOCK_SIZE * 3);
    }

    bool movePiece(Direction direction) {
        sf::Vector2f previous = t->getPosition();
        t->matrixMove(direction);
        bool moved = true;

        if (board->checkCollision(*t) || t->isAtFloor()) {
            t->setPosition(previous);
            if (direction == DOWN)
                score += board->update(*t), newPiece();
            moved = false;
        }
        return moved;
    }

    void rotatePiece(Direction direction) {
        t->matrixRotate(direction);

        if (board->checkCollision(*t)) {
            if (direction == RIGHT) t->matrixRotate(LEFT);
            if (direction == LEFT) t->matrixRotate(RIGHT);
        }
    }

    void performHardDrop() {
        while (movePiece(DOWN) && !t->isAtFloor());
        clock.restart();
    }

    void initializeText() {
        roboto.loadFromFile("../assets/fonts/Roboto-Regular.ttf");
        scoreText.setFont(roboto);
        scoreText.setString("Score: 0");
        scoreText.setCharacterSize(24);
        scoreText.setFillColor(sf::Color::White);
        scoreText.setStyle(sf::Text::Bold);
        scoreText.setPosition(WIDTH + BLOCK_SIZE, BLOCK_SIZE);
    }

    void drawHUD() {
        sf::RectangleShape line(sf::Vector2f(1, HEIGHT));
        line.setPosition(WIDTH, 0);
        window.draw(line);

        scoreText.setString("Score: " + std::to_string(score));
        window.draw(scoreText);
        window.draw(*onHold);
    }
};

int main() {
    Window window;
    return 0;
}
