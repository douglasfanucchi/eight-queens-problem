#ifndef CHESS_BOARD_H
# define CHESS_BOARD_H

#include <vector>
#include <string>

class ChessBoard {
    protected:
        int dimension;
        std::vector<char> leftDiagonals, rightDiagonals, columns, rows, rowPosition;
        std::vector<ChessBoard> solutions;
    public:
        ChessBoard(int);
        bool isAvailable(int, int);
        void putQueen(int, int);
        void removeQueen(int, int);
        std::string checkQueen(int) const;
        std::vector<ChessBoard> solveQueensPuzzle(int row = 0);
};

#endif
