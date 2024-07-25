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
    ASSERT_TRUE(board.isAvailable(2, 1));
}

void test_should_get_queen_position_by_a_given_row()
{
    ChessBoard board(2);
    int row = 1;
    board.putQueen(row, 1);
    std::string expected = "Queen at (1, 1)";

    std::string result = board.checkQueen(row);

    ASSERT_STREQ(expected, result);
}

void test_should_remove_queen_from_position()
{
    ChessBoard board(2);
    board.putQueen(0, 0);

    board.removeQueen(0, 0);

    ASSERT_TRUE(board.isAvailable(0, 0));
}

void test_should_solve_the_queens_problem_in_a_4x4_board()
{
    ChessBoard board(4);

    std::vector<ChessBoard> solutions = board.solveQueensPuzzle();

    ASSERT_STREQ("Queen at (0, 1)", solutions[0].checkQueen(0));
    ASSERT_STREQ("Queen at (1, 3)", solutions[0].checkQueen(1));
    ASSERT_STREQ("Queen at (2, 0)", solutions[0].checkQueen(2));
    ASSERT_STREQ("Queen at (3, 2)", solutions[0].checkQueen(3));

    ASSERT_STREQ("Queen at (0, 2)", solutions[1].checkQueen(0));
    ASSERT_STREQ("Queen at (1, 0)", solutions[1].checkQueen(1));
    ASSERT_STREQ("Queen at (2, 3)", solutions[1].checkQueen(2));
    ASSERT_STREQ("Queen at (3, 1)", solutions[1].checkQueen(3));
}

void RUN_CHESS_BOARD_TEST_SUITE()
{
    test_should_create_a_2x2_chess_board();
    test_should_put_queen_into_first_position();
    test_should_get_queen_position_by_a_given_row();
    test_should_remove_queen_from_position();
    test_should_solve_the_queens_problem_in_a_4x4_board();
}