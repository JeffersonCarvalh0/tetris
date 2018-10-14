# ifndef DEFS_H
# define DEFS_H

const int WIDTH = 300;
const int HEIGHT = 600;
const int MATRIX_W = 10;
const int MATRIX_H = 20;
const int BLOCK_SIZE = WIDTH / MATRIX_W;

enum Direction { UP, DOWN, LEFT, RIGHT };
enum TetriminoType { I = 1, J, L, O, S, T, Z };

# endif /* end of include guard: DEFS_H */
