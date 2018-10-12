# ifndef TETRIMINO_H
# define TETRIMINO_H

# include <SFML/Graphics.hpp>
# include <vector>
# include "defs.h"

class Tetrimino : public sf::Drawable, public sf::Transformable {
protected:
    sf::VertexArray blocks;
    sf::Color color;

protected:
    void createBlock(int x, int y, int z);

public:
    Tetrimino();
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

class I : public Tetrimino {
public:
    I();
};

class J : public Tetrimino {
public:
    J();
};

class L : public Tetrimino {
public:
    L();
};

class O : public Tetrimino {
public:
    O();
};

class S : public Tetrimino {
public:
    S();
};

class T : public Tetrimino {
public:
    T();
};

class Z : public Tetrimino {
public:
    Z();
};

# endif /* end of include guard: TETRIMINO_h */
