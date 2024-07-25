#include <iostream>
#include <ChessBoard.hpp>

int main()
{
    int boardSize = 7;
    ChessBoard board(boardSize);
    std::vector<ChessBoard> solutions = board.solveQueensPuzzle(0);
    if (!solutions.size()) {
        return 1;
    }
    for (int i = 0; i < solutions.size(); i++) {
        for (int j = 0; j < boardSize; j++) {
            std::cout << solutions[i].checkQueen(j) << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}
