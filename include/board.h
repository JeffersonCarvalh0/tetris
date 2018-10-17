# ifndef BOARD_H
# define BOARD_H

# include <SFML/Graphics.hpp>
# include "defs.h"
# include "tetrimino.h"

class Board : public sf::Drawable {
private:
    std::vector<sf::VertexArray> mat;
    sf::Texture &tileset;

private:
    void applyTexture(int i, int j, int t);

public:
    Board(sf::Texture &tileset);
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    void drawBlocks(Tetrimino &t);
};

# endif /* end of include guard: BOARD_H */
