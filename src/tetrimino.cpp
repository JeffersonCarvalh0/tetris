# include <algorithm>
# include <iostream>
# include "tetrimino.h"

Tetrimino::Tetrimino(sf::Texture &texture): texture(texture) {
    blocks.setPrimitiveType(sf::Quads);
    blocks.resize(16);
}

void Tetrimino::createBlock(int x, int y, int n, int t) {
    x *= BLOCK_SIZE; y *= BLOCK_SIZE; n *= 4;
    blocks[n + 0].position = sf::Vector2f(x, y);
    blocks[n + 1].position = sf::Vector2f(x + BLOCK_SIZE, y);
    blocks[n + 2].position = sf::Vector2f(x + BLOCK_SIZE, y + BLOCK_SIZE);
    blocks[n + 3].position = sf::Vector2f(x, y + BLOCK_SIZE);

    blocks[n + 0].texCoords = sf::Vector2f(t * BLOCK_SIZE, 0);
    blocks[n + 1].texCoords = sf::Vector2f((t + 1) * BLOCK_SIZE, 0);
    blocks[n + 2].texCoords = sf::Vector2f((t + 1) * BLOCK_SIZE, BLOCK_SIZE);
    blocks[n + 3].texCoords = sf::Vector2f(t * BLOCK_SIZE, BLOCK_SIZE);
}

void Tetrimino::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    states.texture = &texture;
    target.draw(blocks, states);
}

void Tetrimino::matrixMove(Direction direction) {
    sf::Vector2f previous = getPosition();

    if (direction == RIGHT) move(BLOCK_SIZE, 0);
    if (direction == LEFT) move(-BLOCK_SIZE, 0);
    if (direction == DOWN) move(0, BLOCK_SIZE);

    sf::Transform currentTransform = getTransform();
    bool valid = true;
    for (int i = 0; i < 4 && valid; ++i) {
        sf::Vector2f v = currentTransform.transformPoint(blocks[i * 4].position);
        int x = std::min(v.x, currentTransform.transformPoint(blocks[(i * 4) + 2].position).x);
        int y = std::min(v.y, currentTransform.transformPoint(blocks[(i * 4) + 2].position).y);
        x /= BLOCK_SIZE; y /= BLOCK_SIZE;

        std::cout << x << ' ' << y << '\n';

        if (x >= MATRIX_W || x < 0) valid = false;
        if (y >= MATRIX_H || y < 0) valid = false;
    }

    std::cout << "\n\n";

    if (!valid) setPosition(previous);
}

void Tetrimino::matrixRotate(Direction direction) {
    if (direction == RIGHT) rotate(90);
    if (direction == LEFT) rotate(-90);

    sf::Transform currentTransform = getTransform();
    int smaller_x = MATRIX_W, greater_x = 0;
    for (int i = 0; i < 4; ++i) {
        int x = currentTransform.transformPoint(blocks[i * 4].position).x;
        x = std::min(x, int(currentTransform.transformPoint(blocks[(i * 4) + 2].position).x));
        x /= BLOCK_SIZE;

        smaller_x = std::min(smaller_x, x);
        greater_x = std::max(greater_x, x);
    }

    if (smaller_x < 0) move(abs(smaller_x) * BLOCK_SIZE, 0);
    if (greater_x >= MATRIX_W) move(-((greater_x + 1) - MATRIX_W) * BLOCK_SIZE, 0);
}

Tetriminoes::I::I(sf::Texture &texture): Tetrimino(texture) {
    center.x = (4 * BLOCK_SIZE) + (BLOCK_SIZE / 2);
    center.y = BLOCK_SIZE + (BLOCK_SIZE / 2);
    setOrigin(center);

    createBlock(3, 1, 0, 3);
    createBlock(4, 1, 1, 3);
    createBlock(5, 1, 2, 3);
    createBlock(6, 1, 3, 3);

    move(center);
}

Tetriminoes::J::J(sf::Texture &texture): Tetrimino(texture) {
    center.x = (4 * BLOCK_SIZE) + (BLOCK_SIZE / 2);
    center.y = (2 * BLOCK_SIZE) + (BLOCK_SIZE / 2);
    setOrigin(center);

    createBlock(5, 1, 0, 6);
    createBlock(3, 2, 1, 6);
    createBlock(4, 2, 2, 6);
    createBlock(5, 2, 3, 6);

    move(center);
}

Tetriminoes::L::L(sf::Texture &texture): Tetrimino(texture) {
    center.x = (4 * BLOCK_SIZE) + (BLOCK_SIZE / 2);
    center.y = (2 * BLOCK_SIZE) + (BLOCK_SIZE / 2);
    setOrigin(center);

    createBlock(3, 1, 0, 5);
    createBlock(3, 2, 1, 5);
    createBlock(4, 2, 2, 5);
    createBlock(5, 2, 3, 5);

    move(center);
}

Tetriminoes::O::O(sf::Texture &texture): Tetrimino(texture) {
    center.x = (5 * BLOCK_SIZE);
    center.y = (2 * BLOCK_SIZE);
    setOrigin(center);

    createBlock(4, 1, 0, 9);
    createBlock(5, 1, 1, 9);
    createBlock(4, 2, 2, 9);
    createBlock(5, 2, 3, 9);

    move(center);
}

Tetriminoes::S::S(sf::Texture &texture): Tetrimino(texture) {
    center.x = (4 * BLOCK_SIZE) + (BLOCK_SIZE / 2);
    center.y = (2 * BLOCK_SIZE) + (BLOCK_SIZE / 2);
    setOrigin(center);

    createBlock(5, 1, 0, 8);
    createBlock(4, 1, 1, 8);
    createBlock(4, 2, 2, 8);
    createBlock(3, 2, 3, 8);

    move(center);
}

Tetriminoes::T::T(sf::Texture &texture): Tetrimino(texture) {
    center.x = (4 * BLOCK_SIZE) + (BLOCK_SIZE / 2);
    center.y = (2 * BLOCK_SIZE) + (BLOCK_SIZE / 2);
    setOrigin(center);

    createBlock(4, 1, 0, 4);
    createBlock(3, 2, 1, 4);
    createBlock(4, 2, 2, 4);
    createBlock(5, 2, 3, 4);

    move(center);
}

Tetriminoes::Z::Z(sf::Texture &texture): Tetrimino(texture) {
    center.x = (4 * BLOCK_SIZE) + (BLOCK_SIZE / 2);
    center.y = (2 * BLOCK_SIZE) + (BLOCK_SIZE / 2);
    setOrigin(center);

    createBlock(3, 1, 0, 7);
    createBlock(4, 1, 1, 7);
    createBlock(4, 2, 2, 7);
    createBlock(5, 2, 3, 7);

    move(center);
}
