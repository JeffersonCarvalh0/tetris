# include <SFML/Graphics.hpp>
# include "defs.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Tetris");

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        window.clear(sf::Color::Black);
        window.display();
    }

    return 0;
}
