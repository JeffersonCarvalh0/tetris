# include <iostream>
# include "tetrimino.h"

Tetrimino::Tetrimino() {
    blocks.setPrimitiveType(sf::Quads);
    blocks.resize(16);
}

void Tetrimino::createBlock(int x, int y, int n) {
    x *= BLOCK_SIZE; y *= BLOCK_SIZE; n *= 4;
    blocks[n + 0].position = sf::Vector2f(x, y);
    blocks[n + 1].position = sf::Vector2f(x + BLOCK_SIZE, y);
    blocks[n + 2].position = sf::Vector2f(x + BLOCK_SIZE, y + BLOCK_SIZE);
    blocks[n + 3].position = sf::Vector2f(x, y + BLOCK_SIZE);

    for (int i = n; i < n + 4; ++i) blocks[i].color = color;
}

void Tetrimino::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(blocks, states);
}

I::I() {
    color = sf::Color::Cyan;
    createBlock(3, 1, 0);
    createBlock(4, 1, 1);
    createBlock(5, 1, 2);
    createBlock(6, 1, 3);
}

J::J() {
    color = sf::Color::Blue;
    createBlock(5, 1, 0);
    createBlock(3, 2, 1);
    createBlock(4, 2, 2);
    createBlock(5, 2, 3);
}

L::L() {
    color = sf::Color(255, 165, 0);
    createBlock(3, 1, 0);
    createBlock(3, 2, 1);
    createBlock(4, 2, 2);
    createBlock(5, 2, 3);
}

O::O() {
    color = sf::Color::Yellow;
    createBlock(4, 1, 0);
    createBlock(5, 1, 1);
    createBlock(4, 2, 2);
    createBlock(5, 2, 3);
}

S::S() {
    color = sf::Color::Green;
    createBlock(5, 1, 0);
    createBlock(4, 1, 1);
    createBlock(4, 2, 2);
    createBlock(3, 2, 3);
}

T::T() {
    color = sf::Color::Magenta;
    createBlock(4, 1, 0);
    createBlock(3, 2, 1);
    createBlock(4, 2, 2);
    createBlock(5, 2, 3);
}

Z::Z() {
    color = sf::Color::Red;
    createBlock(3, 1, 0);
    createBlock(4, 1, 1);
    createBlock(4, 2, 2);
    createBlock(5, 2, 3);
}
