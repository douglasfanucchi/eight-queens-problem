#include <ChessBoard.hpp>

ChessBoard::ChessBoard(int dimension) : dimension(dimension) {
    this->columns.resize(dimension);
    this->rows.resize(dimension);
    this->rowPosition.resize(dimension);
    this->leftDiagonals.resize(2 * dimension - 1);
    this->rightDiagonals.resize(2 * dimension - 1);

    std::fill(this->columns.begin(), this->columns.end(), true);
    std::fill(this->rows.begin(), this->rows.end(), true);
    std::fill(this->leftDiagonals.begin(), this->leftDiagonals.end(), true);
    std::fill(this->rightDiagonals.begin(), this->rightDiagonals.end(), true);
}

ChessBoard::ChessBoard(const ChessBoard &obj) {
    this->rowPosition = obj.rowPosition;
}

bool ChessBoard::isAvailable(int row, int col) {
    int bias = this->dimension - 1;
    return this->columns[col]
        && this->leftDiagonals[row + col]
        && this->rightDiagonals[row - col + bias]
        && this->rows[row];
}

void ChessBoard::putQueen(int row, int col) {
    int bias = this->dimension - 1;
    this->columns[col] = 0;
    this->leftDiagonals[row + col] = 0;
    this->rightDiagonals[row - col + bias] = 0;
    this->rows[row] = 0;
    this->rowPosition[row] = col;
}

void ChessBoard::removeQueen(int row, int col) {
    int bias = this->dimension - 1;
    this->columns[col] = true;
    this->leftDiagonals[row + col] = true;
    this->rightDiagonals[row - col + bias] = true;
    this->rows[row] = true;
}

std::string ChessBoard::checkQueen(int row) const {
    return "Queen at (" + std::to_string(row) + ", " + std::to_string(this->rowPosition[row]) + ")";
}

std::vector<ChessBoard> ChessBoard::solveQueensPuzzle(int row) {
    for (int col = 0; col < this->dimension; col++) {
        if (!this->isAvailable(row, col)) {
            continue;
        }
        this->putQueen(row, col);
        if (row < this->dimension - 1) {
            this->solveQueensPuzzle(row + 1);
        } else {
            this->solutions.push_back(*this);
        }
        this->removeQueen(row, col);
    }
    return this->solutions;
}
