# include <algorithm>
# include <cmath>
# include "tetrimino.h"

Tetrimino::Tetrimino(sf::Texture &texture): texture(texture) {
    blocks.setPrimitiveType(sf::Quads);
    blocks.resize(16);
    atFloor = false;
}

void Tetrimino::createBlock(int x, int y, int n) {
    x *= BLOCK_SIZE; y *= BLOCK_SIZE; n *= 4;
    blocks[n].position = sf::Vector2f(x, y);
    blocks[n + 1].position = sf::Vector2f(x + BLOCK_SIZE, y);
    blocks[n + 2].position = sf::Vector2f(x + BLOCK_SIZE, y + BLOCK_SIZE);
    blocks[n + 3].position = sf::Vector2f(x, y + BLOCK_SIZE);

    int t = static_cast<int>(type);
    blocks[n].texCoords = sf::Vector2f(t * BLOCK_SIZE, 0);
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
        v.x = std::min(v.x, currentTransform.transformPoint(blocks[(i * 4) + 2].position).x);
        v.y = std::min(v.y, currentTransform.transformPoint(blocks[(i * 4) + 2].position).y);
        v.x = std::round(v.x / BLOCK_SIZE); v.y = std::round(v.y / BLOCK_SIZE);


        if (v.x >= MATRIX_W || v.x < 0) valid = false;
        if (v.y >= MATRIX_H) valid = false, atFloor = true;
    }

    if (!valid) setPosition(previous);
}

void Tetrimino::matrixRotate(Direction direction) {
    if (direction == RIGHT) rotate(90);
    if (direction == LEFT) rotate(-90);

    sf::Transform currentTransform = getTransform();
    int smaller_x = MATRIX_W, greater_x = 0;
    bool valid = true;
    for (int i = 0; i < 4; ++i) {
        sf::Vector2f v = currentTransform.transformPoint(blocks[i * 4].position);
        v.x = std::min(v.x, currentTransform.transformPoint(blocks[(i * 4) + 2].position).x);
        v.y = std::min(v.y, currentTransform.transformPoint(blocks[(i * 4) + 2].position).y);
        v.x = std::round(v.x / BLOCK_SIZE); v.y = std::round(v.y / BLOCK_SIZE);

        if (v.y >= MATRIX_H) valid = false;

        smaller_x = std::min(smaller_x, static_cast<int>(v.x));
        greater_x = std::max(greater_x, static_cast<int>(v.x));
    }

    if (valid) {
        if (smaller_x < 0) move(abs(smaller_x) * BLOCK_SIZE, 0);
        if (greater_x >= MATRIX_W) move(-((greater_x + 1) - MATRIX_W) * BLOCK_SIZE, 0);
    } else {
        if (direction == RIGHT) rotate(-90);
        if (direction == LEFT) rotate(90);
    }
}

bool Tetrimino::isAtFloor() { return atFloor; }

Tetriminoes::I::I(sf::Texture &texture): Tetrimino(texture) {
    type = TetriminoType::I;
    center.x = (4 * BLOCK_SIZE) + (BLOCK_SIZE / 2);
    center.y = BLOCK_SIZE + (BLOCK_SIZE / 2);
    setOrigin(center);

    createBlock(3, 1, 0);
    createBlock(4, 1, 1);
    createBlock(5, 1, 2);
    createBlock(6, 1, 3);

    move(center);
}

Tetriminoes::J::J(sf::Texture &texture): Tetrimino(texture) {
    type = TetriminoType::J;
    center.x = (4 * BLOCK_SIZE) + (BLOCK_SIZE / 2);
    center.y = (2 * BLOCK_SIZE) + (BLOCK_SIZE / 2);
    setOrigin(center);

    createBlock(5, 1, 0);
    createBlock(3, 2, 1);
    createBlock(4, 2, 2);
    createBlock(5, 2, 3);

    move(center);
}

Tetriminoes::L::L(sf::Texture &texture): Tetrimino(texture) {
    type = TetriminoType::L;
    center.x = (4 * BLOCK_SIZE) + (BLOCK_SIZE / 2);
    center.y = (2 * BLOCK_SIZE) + (BLOCK_SIZE / 2);
    setOrigin(center);

    createBlock(3, 1, 0);
    createBlock(3, 2, 1);
    createBlock(4, 2, 2);
    createBlock(5, 2, 3);

    move(center);
}

Tetriminoes::O::O(sf::Texture &texture): Tetrimino(texture) {
    type = TetriminoType::O;
    center.x = (5 * BLOCK_SIZE);
    center.y = (2 * BLOCK_SIZE);
    setOrigin(center);

    createBlock(4, 1, 0);
    createBlock(5, 1, 1);
    createBlock(4, 2, 2);
    createBlock(5, 2, 3);

    move(center);
}

Tetriminoes::S::S(sf::Texture &texture): Tetrimino(texture) {
    type = TetriminoType::S;
    center.x = (4 * BLOCK_SIZE) + (BLOCK_SIZE / 2);
    center.y = (2 * BLOCK_SIZE) + (BLOCK_SIZE / 2);
    setOrigin(center);

    createBlock(5, 1, 0);
    createBlock(4, 1, 1);
    createBlock(4, 2, 2);
    createBlock(3, 2, 3);

    move(center);
}

Tetriminoes::T::T(sf::Texture &texture): Tetrimino(texture) {
    type = TetriminoType::T;
    center.x = (4 * BLOCK_SIZE) + (BLOCK_SIZE / 2);
    center.y = (2 * BLOCK_SIZE) + (BLOCK_SIZE / 2);
    setOrigin(center);

    createBlock(4, 1, 0);
    createBlock(3, 2, 1);
    createBlock(4, 2, 2);
    createBlock(5, 2, 3);

    move(center);
}

Tetriminoes::Z::Z(sf::Texture &texture): Tetrimino(texture) {
    type = TetriminoType::Z;
    center.x = (4 * BLOCK_SIZE) + (BLOCK_SIZE / 2);
    center.y = (2 * BLOCK_SIZE) + (BLOCK_SIZE / 2);
    setOrigin(center);

    createBlock(3, 1, 0);
    createBlock(4, 1, 1);
    createBlock(4, 2, 2);
    createBlock(5, 2, 3);

    move(center);
}
