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
        t = std::unique_ptr<Tetrimino>(new Tetriminoes::I(tileset));

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
            if (t->isAtFloor()) {
                board->drawBlocks(*t);
                newPiece();
            }

            t->matrixMove(DOWN); clock.restart();
        }

        window.draw(*board);
        window.draw(*t);
        window.display();
    }

    void keyPressed() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) t->move(0, -BLOCK_SIZE);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) t->matrixMove(LEFT);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) t->matrixMove(DOWN);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) t->matrixMove(RIGHT);
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
            for (int i = 3; i <= 7; ++i) bag.insert(i);

        std::uniform_int_distribution<int> random_piece(*bag.begin(), *bag.rbegin());
        int t = random_piece(generator);

        bag.erase(t);
        switchTetrimino(static_cast<TetriminoType>(t));
    }
};

int main() {
    Window window;
    return 0;
}
