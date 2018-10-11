# include "catch.hpp"
# include "block.h"

Block block(0, 0);

SCENARIO("Block") {
    GIVEN("A Block") {
        WHEN("The block is at position 0, 0 and moved to the left") {
            block.move(LEFT);

            THEN("It shouldn't move") {
                REQUIRE(block.getX() == 0);
                REQUIRE(block.getY() == 0);
            }
        }

        WHEN("The block is at position 0, 0 and moved up") {
            block.move(UP);

            THEN("It shouldn't move") {
                REQUIRE(block.getX() == 0);
                REQUIRE(block.getY() == 0);
            }
        }

        WHEN("The block is at position 0, 0 and moved to the right") {
            block.move(RIGHT);

            THEN("It should move one position to the right") {
                REQUIRE(block.getX() == 1);
                REQUIRE(block.getY() == 0);
            }
        }

        WHEN("The block is at position 1, 0 and moved down") {
            block.move(DOWN);

            THEN("It should move one position down") {
                REQUIRE(block.getX() == 1);
                REQUIRE(block.getY() == 1);
            }
        }

        WHEN("The block is at the bottom of the board and moved down") {
            for (int i = 1; i < MATRIX_H; ++i) block.move(DOWN);
            block.move(DOWN);

            THEN("It shouldn't move") {
                REQUIRE(block.getX() == 1);
                REQUIRE(block.getY() == MATRIX_H - 1);
            }
        }

        WHEN("The block is at the rightmost position and moved to the right") {
            for (int i = 1; i < MATRIX_W; ++i) block.move(RIGHT);
            block.move(RIGHT);

            THEN("It shouldn't move") {
                REQUIRE(block.getX() == MATRIX_W - 1);
                REQUIRE(block.getY() == MATRIX_H - 1);
            }
        }
    }
}
