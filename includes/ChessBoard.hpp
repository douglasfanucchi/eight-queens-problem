#ifndef CHESS_BOARD_H
# define CHESS_BOARD_H

#include <vector>

class ChessBoard {
    protected:
        int dimension;
        std::vector<char> leftDiagonals, rightDiagonals, columns, rows;
    public:
        ChessBoard(int);
        bool isAvailable(int, int);
        void putQueen(int, int);
};

#endif
