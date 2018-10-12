# include <SFML/Graphics.hpp>
# include "defs.h"
# include "tetrimino.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Tetris");

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        window.clear(sf::Color::Black);

        I i;
        J j;
        L l;
        O o;
        S s;
        T t;
        Z z;

        j.move(0, BLOCK_SIZE * 2);
        l.move(0, BLOCK_SIZE * 4);
        o.move(0, BLOCK_SIZE * 6);
        s.move(0, BLOCK_SIZE * 8);
        t.move(0, BLOCK_SIZE * 10);
        z.move(0, BLOCK_SIZE * 12);

        window.draw(i);
        window.draw(j);
        window.draw(l);
        window.draw(o);
        window.draw(s);
        window.draw(t);
        window.draw(z);

        window.display();
    }

    return 0;
}
