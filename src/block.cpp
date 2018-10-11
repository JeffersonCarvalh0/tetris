# include "block.h"

Block::Block(int x, int y): board_x(x), board_y(y) {
    square = sf::RectangleShape(sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE));
    square.setPosition(board_x * WIDTH / 10, board_y * HEIGHT / 10);
}

int Block::getX() { return board_x; }
int Block::getY() { return board_y; }

void Block::move(Direction direction) {
    if (direction == UP && board_y > 0)
        square.move(0, -BLOCK_SIZE), --board_y;
    if (direction == DOWN && board_y < MATRIX_H - 1)
        square.move(0, BLOCK_SIZE), ++board_y;
    if (direction == LEFT && board_x > 0)
        square.move(-BLOCK_SIZE, 0), --board_x;
    if (direction == RIGHT && board_x < MATRIX_W - 1)
        square.move(BLOCK_SIZE, 0), ++board_x;
}

void Block::draw(sf::RenderWindow &window) {
    window.draw(square);
}
