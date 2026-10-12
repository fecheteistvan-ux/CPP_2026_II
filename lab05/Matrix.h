#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <vector>
#include <stdexcept>
class Matrix {
public:
    // Konstruktorok és destruktor
    Matrix(int rows = 10, int cols = 10);
    Matrix(const Matrix& other); // Copy ctor
    Matrix(Matrix&& other) noexcept; // Move ctor
    ~Matrix() = default; // vector automatikusan
     // Értékadás
     Matrix& operator=(const Matrix& other); // Copy assignment
    Matrix& operator=(Matrix&& other) noexcept; // Move assignment
    // Feltöltő metódusok
    void fillMatrix(double value);
    void randomMatrix(int a, int b);
    // Kiíratás
    void printMatrix(std::ostream& os = std::cout) const;
    // Lekérdezések
    bool isSquare() const { return mRows == mCols; }
    int getRows() const { return mRows; }
    int getCols() const { return mCols; }
    // Operátorok
    friend Matrix operator+(const Matrix& x, const Matrix& y);
    friend Matrix operator*(const Matrix& x, const Matrix& y);
    friend std::istream& operator>>(std::istream& is, Matrix& mat);
    friend std::ostream& operator<<(std::ostream& os, const Matrix& mat);
    // Indexelés
    double* operator[](int row);
    const double* operator[](int row) const;
    // Alternatív biztonságos indexelő
    double& operator()(int row, int col);
    const double& operator()(int row, int col) const;
private:
    int mRows;
    int mCols;
    std::vector<double> mElements; // sorfolytonos tárolás (row-major)
};
#endif /* MATRIX_H */