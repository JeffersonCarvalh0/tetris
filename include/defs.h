# ifndef DEFS_H
# define DEFS_H

const int SCREEN_WIDTH = 480;
const int WIDTH = 240;
const int HEIGHT = 480;
const int MATRIX_W = 10;
const int MATRIX_H = 20;
const int BLOCK_SIZE = WIDTH / MATRIX_W;

enum Direction { UP, DOWN, LEFT, RIGHT };
enum TetriminoType { I = 3, T, L, J, Z, S, O };

# endif /* end of include guard: DEFS_H */
