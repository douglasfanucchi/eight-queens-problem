#ifndef CHESS_BOARD_H
# define CHESS_BOARD_H

#include <vector>
#include <string>

class ChessBoard {
    protected:
        int dimension;
        std::vector<char> leftDiagonals, rightDiagonals, columns, rows, rowPosition;
    public:
        ChessBoard(int);
        bool isAvailable(int, int);
        void putQueen(int, int);
        void removeQueen(int, int);
        std::string checkQueen(int) const;
};

#endif
