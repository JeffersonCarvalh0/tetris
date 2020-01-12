# include <SFML/Graphics.hpp>
# include <SFML/Audio.hpp>
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
    sf::SoundBuffer rotateBuffer, pieceLandBuffer, scoreBuffer, gameOverBuffer;
    sf::Sound rotateSound, pieceLandSound, scoreSound, gameOverSound;
    sf::Font roboto;
    sf::Text scoreText;
    sf::Text gameOverText;
    sf::Text gameOverText2;
    sf::Clock clock;

    std::shared_ptr<Tetrimino> t;
    std::shared_ptr<Tetrimino> onHold;
    std::unique_ptr<Board> board;

    std::set<int> bag;
    std::random_device rd;
    std::default_random_engine generator;

    bool switched;
    bool isOver;

    int score;

    Window() {
        window.create(sf::VideoMode(SCREEN_WIDTH, HEIGHT), "Tetris");
        tileset.loadFromFile("../assets/textures/blocks.png");
        roboto.loadFromFile("../assets/fonts/Roboto-Regular.ttf");
        tileset.setSmooth(true);

        rotateBuffer.loadFromFile("../assets/sounds/rotate.wav");
        pieceLandBuffer.loadFromFile("../assets/sounds/piece-land.wav");
        scoreBuffer.loadFromFile("../assets/sounds/score.wav");
        gameOverBuffer.loadFromFile("../assets/sounds/game-over.wav");

        rotateSound.setBuffer(rotateBuffer);
        pieceLandSound.setBuffer(pieceLandBuffer);
        scoreSound.setBuffer(scoreBuffer);
        gameOverSound.setBuffer(gameOverBuffer);

        initializeText();

        board = std::unique_ptr<Board>(new Board(tileset));
        newPiece();

        generator = std::default_random_engine(rd());
        score = 0;
        isOver = false;

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

        if (clock.getElapsedTime().asMilliseconds() >= 1000 && !isOver) {
            if (t->isAtFloor()) score += board->update(*t), newPiece();
            movePiece(DOWN); clock.restart();
        }

        drawHUD();
        window.draw(*board);
        window.draw(*t);
        window.display();
    }

    void keyPressed() {
        if (!isOver) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) holdPiece();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) movePiece(LEFT);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) movePiece(DOWN);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) movePiece(RIGHT);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) rotatePiece(LEFT);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) rotatePiece(RIGHT);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) performHardDrop();
        } else {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) restart();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
    }

    void switchTetrimino(TetriminoType tt, std::shared_ptr<Tetrimino> &t) {
        switch (tt) {
            case I:
                t = std::shared_ptr<Tetrimino>(new Tetriminoes::I(tileset)); break;
            case J:
                t = std::shared_ptr<Tetrimino>(new Tetriminoes::J(tileset)); break;
            case L:
                t = std::shared_ptr<Tetrimino>(new Tetriminoes::L(tileset)); break;
            case O:
                t = std::shared_ptr<Tetrimino>(new Tetriminoes::O(tileset)); break;
            case S:
                t = std::shared_ptr<Tetrimino>(new Tetriminoes::S(tileset)); break;
            case T:
                t = std::shared_ptr<Tetrimino>(new Tetriminoes::T(tileset)); break;
            case Z:
                t = std::shared_ptr<Tetrimino>(new Tetriminoes::Z(tileset)); break;
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
        if (onHold) {
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
        switched = false;

        if (board->checkCollision(*t)) {
            isOver = true;
            gameOverSound.play();
        }
    }

    bool movePiece(Direction direction) {
        sf::Vector2f previous = t->getPosition();
        t->matrixMove(direction);
        bool moved = true;

        if (board->checkCollision(*t) || t->isAtFloor()) {
            t->setPosition(previous);
            if (direction == DOWN) {
                int points = board->update(*t);
                points ? scoreSound.play() : pieceLandSound.play();
                score += points;
                newPiece();
            }
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

        rotateSound.play();
    }

    void performHardDrop() {
        while (movePiece(DOWN) && !t->isAtFloor());
        clock.restart();
    }

    void configureText(sf::Text &text) {
        text.setFont(roboto);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
        text.setStyle(sf::Text::Bold);
    }

    void initializeText() {
        configureText(scoreText);
        scoreText.setString("Score: 0");
        scoreText.setPosition(WIDTH + BLOCK_SIZE, BLOCK_SIZE);

        configureText(gameOverText);
        gameOverText.setString("Game over!");
        gameOverText.setPosition(WIDTH + BLOCK_SIZE, 2 * BLOCK_SIZE);

        configureText(gameOverText2);
        gameOverText2.setString("Press 'R' to start again");
        gameOverText2.setCharacterSize(18);
        gameOverText2.setPosition(WIDTH + BLOCK_SIZE, 8 * BLOCK_SIZE);
    }

    void drawHUD() {
        sf::RectangleShape line(sf::Vector2f(1, HEIGHT));
        line.setPosition(WIDTH, 0);
        window.draw(line);

        scoreText.setString("Score: " + std::to_string(score));
        window.draw(scoreText);
        window.draw(*onHold);
        if (isOver) window.draw(gameOverText), window.draw(gameOverText2);
    }

    void holdPiece() {
        if (!switched) {
            std::shared_ptr<Tetrimino> temp = t;
            switchTetrimino(onHold->type, t);
            switchTetrimino(temp->type, onHold);
            onHold->move(WIDTH, BLOCK_SIZE * 3);
            switched = true;
        }
    }

    void restart() {
        isOver = false; score = 0;
        board->clear(); t.reset(); onHold.reset();
        bag.clear();
        newPiece();
    }
};

int main() {
    Window window;
    return 0;
}
