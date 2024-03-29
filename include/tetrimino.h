# ifndef TETRIMINO_H
# define TETRIMINO_H

# include <SFML/Graphics.hpp>
# include "defs.h"

class Board;

class Tetrimino : public sf::Drawable, public sf::Transformable {
    friend class Board;
public:
    TetriminoType type;

protected:
    sf::VertexArray blocks;
    sf::Vector2f center;
    sf::Texture &texture;
    bool atFloor;

protected:
    void createBlock(int x, int y, int n);

public:
    Tetrimino(sf::Texture &texture);
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    void matrixMove(Direction direction);
    void matrixRotate(Direction direction);
    bool isAtFloor();
};

namespace Tetriminoes {
    class I : public Tetrimino {
    public:
        I(sf::Texture &texture);
    };

    class J : public Tetrimino {
    public:
        J(sf::Texture &texture);
    };

    class L : public Tetrimino {
    public:
        L(sf::Texture &texture);
    };

    class O : public Tetrimino {
    public:
        O(sf::Texture &texture);
    };

    class S : public Tetrimino {
    public:
        S(sf::Texture &texture);
    };

    class T : public Tetrimino {
    public:
        T(sf::Texture &texture);
    };

    class Z : public Tetrimino {
    public:
        Z(sf::Texture &texture);
    };
}

# endif /* end of include guard: TETRIMINO_h */
