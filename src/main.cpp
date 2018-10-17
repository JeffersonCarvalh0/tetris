# include <SFML/Graphics.hpp>
# include <memory>
# include <random>
# include <set>
# include <iostream>

# include "defs.h"
# include "board.h"
# include "tetrimino.h"

class Window {
public:
    sf::RenderWindow window;
    sf::Texture tileset;
    sf::Clock clock;

    std::unique_ptr<Tetrimino> t;
    std::unique_ptr<Board> board;

    std::set<int> bag;
    std::random_device rd;
    std::default_random_engine generator;

    Window() {
        window.create(sf::VideoMode(WIDTH, HEIGHT), "Tetris");
        tileset.loadFromFile("../assets/textures/blocks.png");
        tileset.setSmooth(true);

        board = std::unique_ptr<Board>(new Board(tileset));
        newPiece();

        generator = std::default_random_engine(rd());

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
            if (t->isAtFloor()) board->drawBlocks(*t), newPiece();
            movePiece(DOWN); clock.restart();
        }

        window.draw(*board);
        window.draw(*t);
        window.display();
    }

    void keyPressed() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) t->move(0, -BLOCK_SIZE);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) movePiece(LEFT);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) movePiece(DOWN);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) movePiece(RIGHT);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) t->matrixRotate(LEFT);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) t->matrixRotate(RIGHT);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) t->hardDrop();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) switchTetrimino(I);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) switchTetrimino(J);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) switchTetrimino(L);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) switchTetrimino(O);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) switchTetrimino(S);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) switchTetrimino(T);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)) switchTetrimino(Z);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
    }

    void switchTetrimino(TetriminoType tt) {
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
        switchTetrimino(static_cast<TetriminoType>(p));
    }

    void movePiece(Direction direction) {
        sf::Vector2f previous = t->getPosition();
        t->matrixMove(direction);

        if (board->checkCollision(*t)) {
            t->setPosition(previous);
            if (direction == DOWN)
                board->drawBlocks(*t), newPiece();
        }
    }
};

int main() {
    Window window;
    return 0;
}
