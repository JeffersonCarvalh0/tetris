# include <SFML/Graphics.hpp>
# include <iostream>
# include <memory>

# include "defs.h"
# include "tetrimino.h"

class Window {
public:
    sf::RenderWindow window;
    std::unique_ptr<Tetrimino> t;
    sf::Transform rotation;

    Window() {
        window.create(sf::VideoMode(WIDTH, HEIGHT), "Tetris");

        t = std::unique_ptr<Tetrimino>(new Tetriminoes::I());

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
        window.draw(*t);
        window.display();
    }

    void keyPressed() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) t->move(0, -BLOCK_SIZE);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) t->move(-BLOCK_SIZE, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) t->move(0, BLOCK_SIZE);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) t->move(BLOCK_SIZE, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) t->rotate(-90);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) t->rotate(90);
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
                t = std::unique_ptr<Tetrimino>(new Tetriminoes::I()); break;
            case J:
                t = std::unique_ptr<Tetrimino>(new Tetriminoes::J()); break;
            case L:
                t = std::unique_ptr<Tetrimino>(new Tetriminoes::L()); break;
            case O:
                t = std::unique_ptr<Tetrimino>(new Tetriminoes::O()); break;
            case S:
                t = std::unique_ptr<Tetrimino>(new Tetriminoes::S()); break;
            case T:
                t = std::unique_ptr<Tetrimino>(new Tetriminoes::T()); break;
            case Z:
                t = std::unique_ptr<Tetrimino>(new Tetriminoes::Z()); break;
        }
    }
};

int main() {
    Window window;
    return 0;
}
