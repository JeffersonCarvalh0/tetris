# include <cmath>
# include <algorithm>
# include "board.h"

Board::Board(sf::Texture &tileset): tileset(tileset) {
    mat.resize(MATRIX_H);
    for (int i = 0; i < MATRIX_H; ++i) {
        mat[i].setPrimitiveType(sf::Quads);
        mat[i].resize(MATRIX_W * 4);

        int y = i * BLOCK_SIZE;
        for (int j = 0; j < MATRIX_W; ++j) {
            int x = j * BLOCK_SIZE;
            mat[i][(j * 4)].position = sf::Vector2f(x, y);
            mat[i][(j * 4) + 1].position = sf::Vector2f(x + BLOCK_SIZE, y);
            mat[i][(j * 4) + 2].position = sf::Vector2f(x + BLOCK_SIZE, y + BLOCK_SIZE);
            mat[i][(j * 4) + 3].position = sf::Vector2f(x, y + BLOCK_SIZE);
        }
    }
}

void Board::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.texture = &tileset;
    for (int i = 0; i < MATRIX_H; ++i) target.draw(mat[i], states);
}

void Board::drawBlocks(Tetrimino &t) {
    for (int i = 0; i < 4; ++i) {
        sf::Transform transform = t.getTransform();
        sf::Vector2f coord = transform.transformPoint(t.blocks[i * 4].position);
        coord.x = std::min(coord.x, transform.transformPoint(t.blocks[(i * 4) + 2].position).x);
        coord.y = std::min(coord.y, transform.transformPoint(t.blocks[(i * 4) + 2].position).y);

        int x = std::round(coord.x / BLOCK_SIZE);
        int y = std::round(coord.y / BLOCK_SIZE);
        applyTexture(y, x, t.type);
    }
}

void Board::applyTexture(int i, int j, int t) {
    j *= 4; t = static_cast<int>(t);
    mat[i][j].texCoords = sf::Vector2f(t * BLOCK_SIZE, 0);
    mat[i][j + 1].texCoords = sf::Vector2f((t + 1) * BLOCK_SIZE, 0);
    mat[i][j + 2].texCoords = sf::Vector2f((t + 1) * BLOCK_SIZE, BLOCK_SIZE);
    mat[i][j + 3].texCoords = sf::Vector2f(t * BLOCK_SIZE, BLOCK_SIZE);
}
