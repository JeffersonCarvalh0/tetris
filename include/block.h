# include <SFML/Window.hpp>
# include <SFML/Graphics.hpp>
# include "defs.h"

class Block {
private:
    sf::RectangleShape square;
    int board_x, board_y;

public:
    Block(int x, int y);
    int getX();
    int getY();
    void move(Direction direction);
    void draw(sf::RenderWindow &window);
};
