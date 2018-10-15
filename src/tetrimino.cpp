# include <iostream>
# include "tetrimino.h"

Tetrimino::Tetrimino(sf::Texture &texture): texture(texture) {
    blocks.setPrimitiveType(sf::Quads);
    blocks.resize(16);
    matrixCoords.resize(4);
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
    bool valid = true;

    if (direction == DOWN) {
        for (auto &coord : matrixCoords)
            if (coord.y + 1 > MATRIX_H - 1) valid = false;
        if (valid) {
            for (auto &coord : matrixCoords) ++coord.y;
            move(0, BLOCK_SIZE);
        }
    }

    if (direction == LEFT) {
        for (auto &coord : matrixCoords)
            if (coord.x - 1 < 0) valid = false;
        if (valid) {
            for (auto &coord : matrixCoords) --coord.x;
            move(-BLOCK_SIZE, 0);
        }
    }

    if (direction == RIGHT) {
        for (auto &coord : matrixCoords)
            if (coord.x + 1 > MATRIX_W - 1) valid = false;
        if (valid) {
            for (auto &coord : matrixCoords) ++coord.x;
            move(BLOCK_SIZE, 0);
        }
    }
}

Tetriminoes::I::I(sf::Texture &texture): Tetrimino(texture) {
    center.x = (4 * BLOCK_SIZE) + (BLOCK_SIZE / 2);
    center.y = BLOCK_SIZE + (BLOCK_SIZE / 2);
    setOrigin(center);

    createBlock(3, 1, 0, 3); matrixCoords[0].x = 3; matrixCoords[0].y = 1;
    createBlock(4, 1, 1, 3); matrixCoords[1].x = 4; matrixCoords[1].y = 1;
    createBlock(5, 1, 2, 3); matrixCoords[2].x = 5; matrixCoords[2].y = 1;
    createBlock(6, 1, 3, 3); matrixCoords[3].x = 6; matrixCoords[3].y = 1;

    move(center);
}

Tetriminoes::J::J(sf::Texture &texture): Tetrimino(texture) {
    center.x = (4 * BLOCK_SIZE) + (BLOCK_SIZE / 2);
    center.y = (2 * BLOCK_SIZE) + (BLOCK_SIZE / 2);
    setOrigin(center);

    createBlock(5, 1, 0, 6); matrixCoords[0].x = 5; matrixCoords[0].y = 1;
    createBlock(3, 2, 1, 6); matrixCoords[1].x = 3; matrixCoords[1].y = 2;
    createBlock(4, 2, 2, 6); matrixCoords[2].x = 4; matrixCoords[2].y = 2;
    createBlock(5, 2, 3, 6); matrixCoords[3].x = 5; matrixCoords[3].y = 2;

    move(center);
}

Tetriminoes::L::L(sf::Texture &texture): Tetrimino(texture) {
    center.x = (4 * BLOCK_SIZE) + (BLOCK_SIZE / 2);
    center.y = (2 * BLOCK_SIZE) + (BLOCK_SIZE / 2);
    setOrigin(center);

    createBlock(3, 1, 0, 5); matrixCoords[0].x = 3; matrixCoords[0].y = 1;
    createBlock(3, 2, 1, 5); matrixCoords[1].x = 3; matrixCoords[1].y = 2;
    createBlock(4, 2, 2, 5); matrixCoords[2].x = 4; matrixCoords[2].y = 2;
    createBlock(5, 2, 3, 5); matrixCoords[3].x = 5; matrixCoords[3].y = 2;

    move(center);
}

Tetriminoes::O::O(sf::Texture &texture): Tetrimino(texture) {
    center.x = (5 * BLOCK_SIZE);
    center.y = (2 * BLOCK_SIZE);
    setOrigin(center);

    createBlock(4, 1, 0, 9); matrixCoords[0].x = 4; matrixCoords[0].y = 1;
    createBlock(5, 1, 1, 9); matrixCoords[1].x = 5; matrixCoords[1].y = 1;
    createBlock(4, 2, 2, 9); matrixCoords[2].x = 4; matrixCoords[2].y = 2;
    createBlock(5, 2, 3, 9); matrixCoords[3].x = 5; matrixCoords[3].y = 2;

    move(center);
}

Tetriminoes::S::S(sf::Texture &texture): Tetrimino(texture) {
    center.x = (4 * BLOCK_SIZE) + (BLOCK_SIZE / 2);
    center.y = (2 * BLOCK_SIZE) + (BLOCK_SIZE / 2);
    setOrigin(center);

    createBlock(5, 1, 0, 8); matrixCoords[0].x = 5; matrixCoords[0].y = 1;
    createBlock(4, 1, 1, 8); matrixCoords[1].x = 4; matrixCoords[1].y = 1;
    createBlock(4, 2, 2, 8); matrixCoords[2].x = 4; matrixCoords[2].y = 2;
    createBlock(3, 2, 3, 8); matrixCoords[3].x = 3; matrixCoords[3].y = 2;

    move(center);
}

Tetriminoes::T::T(sf::Texture &texture): Tetrimino(texture) {
    center.x = (4 * BLOCK_SIZE) + (BLOCK_SIZE / 2);
    center.y = (2 * BLOCK_SIZE) + (BLOCK_SIZE / 2);
    setOrigin(center);

    createBlock(4, 1, 0, 4); matrixCoords[0].x = 4; matrixCoords[0].y = 1;
    createBlock(3, 2, 1, 4); matrixCoords[1].x = 3; matrixCoords[1].y = 2;
    createBlock(4, 2, 2, 4); matrixCoords[2].x = 4; matrixCoords[2].y = 2;
    createBlock(5, 2, 3, 4); matrixCoords[3].x = 5; matrixCoords[3].y = 2;

    move(center);
}

Tetriminoes::Z::Z(sf::Texture &texture): Tetrimino(texture) {
    center.x = (4 * BLOCK_SIZE) + (BLOCK_SIZE / 2);
    center.y = (2 * BLOCK_SIZE) + (BLOCK_SIZE / 2);
    setOrigin(center);

    createBlock(3, 1, 0, 7); matrixCoords[0].x = 3; matrixCoords[0].y = 1;
    createBlock(4, 1, 1, 7); matrixCoords[1].x = 4; matrixCoords[1].y = 1;
    createBlock(4, 2, 2, 7); matrixCoords[2].x = 4; matrixCoords[2].y = 2;
    createBlock(5, 2, 3, 7); matrixCoords[3].x = 5; matrixCoords[3].y = 2;

    move(center);
}
