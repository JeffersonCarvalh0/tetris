# include <SFML/Graphics.hpp>
# include <iostream>
# include "defs.h"
# include "tetrimino.h"

class Window {
public:
    sf::RenderWindow window;
    T t;

    Window() {
        window.create(sf::VideoMode(WIDTH, HEIGHT), "Tetris");

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
        window.draw(t);
        window.display();
    }

    void keyPressed() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) t.move(0, -BLOCK_SIZE);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) t.move(-BLOCK_SIZE, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) t.move(0, BLOCK_SIZE);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) t.move(BLOCK_SIZE, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) t.rotate(-90);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) t.rotate(90);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
        std::cout << t.getOrigin().x << ' ' << t.getOrigin().y << '\n';
    }
};

int main() {
    Window window;
    return 0;
}
