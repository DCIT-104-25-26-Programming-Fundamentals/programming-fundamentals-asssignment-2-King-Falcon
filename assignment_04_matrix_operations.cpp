// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_SIZE = 10;

void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(const int src[MAX_SIZE][MAX_SIZE], int dest[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            dest[j][i] = src[i][j];
        }
    }
}

void addMatrices(const int a[MAX_SIZE][MAX_SIZE], const int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyMatrices(const int a[MAX_SIZE][MAX_SIZE], const int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int m, int n, int p) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int matA[MAX_SIZE][MAX_SIZE];
    int matB[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];
    
    int rowsA, colsA;
    int rowsB, colsB;

    cout << "PART A: TRANSPOSE" << endl;
    cout << "Enter number of rows: ";
    cin >> rowsA;
    cout << "Enter number of columns: ";
    cin >> colsA;
    
    if (rowsA > MAX_SIZE || colsA > MAX_SIZE || rowsA <= 0 || colsA <= 0) {
        cout << "Invalid dimensions. Maximum size is 10." << endl;
        return 1;
    }

    readMatrix(matA, rowsA, colsA);
    cout << "\nOriginal Matrix:" << endl;
    printMatrix(matA, rowsA, colsA);

    transposeMatrix(matA, result, rowsA, colsA);
    cout << "\nTransposed Matrix:" << endl;
    printMatrix(result, colsA, rowsA);

    cout << "\n PART B: ADDITION" << endl;
    cout << "Reading Matrix B (same dimensions as Matrix A):" << endl;
    readMatrix(matB, rowsA, colsA);

    addMatrices(matA, matB, result, rowsA, colsA);
    cout << "\nSum of Matrices:" << endl;
    printMatrix(result, rowsA, colsA);

    cout << "\n PART C: MULTIPLICATION" << endl;
    cout << "Enter number of rows for Matrix B: ";
    cin >> rowsB;
    cout << "Enter number of columns for Matrix B: ";
    cin >> colsB;

    if (rowsB > MAX_SIZE || colsB > MAX_SIZE || rowsB <= 0 || colsB <= 0) {
        cout << "Invalid dimensions. Maximum size is 10." << endl;
        return 1;
    }

    if (colsA != rowsB) {
        cout << "Error: Columns of Matrix A must equal Rows of Matrix B." << endl;
        return 1;
    }

    cout << "Reading elements for Matrix B:" << endl;
    readMatrix(matB, rowsB, colsB);

    multiplyMatrices(matA, matB, result, rowsA, colsA, colsB);
    cout << "\nProduct of Matrices (A x B):" << endl;
    printMatrix(result, rowsA, colsB);

    return 0;
}
