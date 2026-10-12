#include "Matrix.h"
#include <random>
#include <algorithm>

Matrix::Matrix(int rows, int cols) : mRows(rows), mCols(cols), mElements(rows * cols, 0.0) {
    if (rows <= 0 || cols <= 0) {
        throw std::out_of_range("A sorok es oszlopok szama pozitiv kell legyen!");
    }
}


Matrix::Matrix(const Matrix& other) : mRows(other.mRows), mCols(other.mCols), mElements(other.mElements) {}


Matrix::Matrix(Matrix&& other) noexcept
    : mRows(other.mRows), mCols(other.mCols), mElements(std::move(other.mElements)) {
    other.mRows = 0;
    other.mCols = 0;
}


Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        mRows = other.mRows;
        mCols = other.mCols;
        mElements = other.mElements;
    }
    return *this;
}


Matrix& Matrix::operator=(Matrix&& other) noexcept {
    if (this != &other) {
        mRows = other.mRows;
        mCols = other.mCols;
        mElements = std::move(other.mElements);
        other.mRows = 0;
        other.mCols = 0;
    }
    return *this;
}


void Matrix::fillMatrix(double value) {
    std::fill(mElements.begin(), mElements.end(), value);
}


void Matrix::randomMatrix(int a, int b) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(a, b);
    for (auto& elem : mElements) {
        elem = dis(gen);
    }
}

void Matrix::printMatrix(std::ostream& os) const {
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            os << (*this)(i, j) << " ";
        }
        os << "\n";
    }
}

Matrix operator+(const Matrix& x, const Matrix& y) {
    if (x.mRows != y.mRows || x.mCols != y.mCols) {
        throw std::out_of_range("A matrixok meretei nem egyeznek meg az osszeadasnal!");
    }
    Matrix result(x.mRows, x.mCols);
    for (size_t i = 0; i < x.mElements.size(); ++i) {
        result.mElements[i] = x.mElements[i] + y.mElements[i];
    }
    return result;
}

Matrix operator*(const Matrix& x, const Matrix& y) {
    if (x.mCols != y.mRows) {
        throw std::out_of_range("A matrixok dimenzioi nem megfeleloek a szorzasoz!");
    }
    Matrix result(x.mRows, y.mCols);
    result.fillMatrix(0.0);
    for (int i = 0; i < x.mRows; ++i) {
        for (int j = 0; j < y.mCols; ++j) {
            double sum = 0.0;
            for (int k = 0; k < x.mCols; ++k) {
                sum += x(i, k) * y(k, j);
            }
            result(i, j) = sum;
        }
    }
    return result;
}

std::istream& operator>>(std::istream& is, Matrix& mat) {
    for (int i = 0; i < mat.mRows; ++i) {
        for (int j = 0; j < mat.mCols; ++j) {
            is >> mat(i, j);
        }
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const Matrix& mat) {
    mat.printMatrix(os);
    return os;
}

double* Matrix::operator[](int row) {
    if (row < 0 || row >= mRows) {
        throw std::out_of_range("Sor index tartomanyon kivul!");
    }
    return &mElements[row * mCols];
}

const double* Matrix::operator[](int row) const {
    if (row < 0 || row >= mRows) {
        throw std::out_of_range("Sor index tartomanyon kivul!");
    }
    return &mElements[row * mCols];
}

double& Matrix::operator()(int row, int col) {
    if (row < 0 || row >= mRows || col < 0 || col >= mCols) {
        throw std::out_of_range("Index tartomanyon kivul!");
    }
    return mElements[row * mCols + col];
}

const double& Matrix::operator()(int row, int col) const {
    if (row < 0 || row >= mRows || col < 0 || col >= mCols) {
        throw std::out_of_range("Index tartomanyon kivul!");
    }
    return mElements[row * mCols + col];
}