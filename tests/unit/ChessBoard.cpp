#include <asserts.hpp>
#include <ChessBoard.hpp>

void test_should_create_a_2x2_chess_board()
{
    ChessBoard board(2);

    ASSERT_TRUE(board.isAvailable(0, 0));
    ASSERT_TRUE(board.isAvailable(0, 1));
    ASSERT_TRUE(board.isAvailable(1, 0));
    ASSERT_TRUE(board.isAvailable(1, 1));
}

void test_should_put_queen_into_first_position()
{
    ChessBoard board(3);

    board.putQueen(0, 0);

    ASSERT_FALSE(board.isAvailable(0, 0));
    ASSERT_FALSE(board.isAvailable(0, 1));
    ASSERT_FALSE(board.isAvailable(0, 2));
    ASSERT_FALSE(board.isAvailable(1, 0));
    ASSERT_FALSE(board.isAvailable(1, 1));
    ASSERT_FALSE(board.isAvailable(2, 0));
    ASSERT_FALSE(board.isAvailable(2, 2));
    ASSERT_TRUE(board.isAvailable(1, 2));
    ASSERT_TRUE(board.isAvailable(2, 2));
}

void RUN_CHESS_BOARD_TEST_SUITE()
{
    test_should_create_a_2x2_chess_board();
    test_should_put_queen_into_first_position();
}