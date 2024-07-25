#include <ChessBoard.hpp>

ChessBoard::ChessBoard(int dimension) : dimension(dimension) {
    this->columns.resize(dimension);
    this->rows.resize(dimension);
    this->leftDiagonals.resize(2 * dimension - 1);
    this->rightDiagonals.resize(2 * dimension - 1);

    std::fill(this->columns.begin(), this->columns.end(), true);
    std::fill(this->rows.begin(), this->rows.end(), true);
    std::fill(this->leftDiagonals.begin(), this->leftDiagonals.end(), true);
    std::fill(this->rightDiagonals.begin(), this->rightDiagonals.end(), true);
}

bool ChessBoard::isAvailable(int row, int col) {
    int bias = this->dimension - 1;
    return this->columns[col]
        && this->leftDiagonals[row + col]
        && this->rightDiagonals[row - col + bias]
        && this->rows[row];
}
