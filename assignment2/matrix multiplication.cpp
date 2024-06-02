#include <iostream>
using namespace std;

class Matrix {
private:
    int rows, cols;
    double** data;

public:
   
    Matrix(int r, int c) {
        rows = r;
        cols = c;
        data = new double*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new double[cols];
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    void input() {
        cout << "Enter values for a " << rows << "x" << cols << " matrix:\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cin >> data[i][j];
            }
        }
    }

    void print() const {
        cout << "Matrix (" << rows << "x" << cols << "):\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }


    Matrix operator*(const Matrix& other) const {
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }
};

int main() {
    int m, n;
    cout << "Enter the number of rows and columns for the first matrix (m n): ";
    cin >> m >> n;
    Matrix matA(m, n);
    Matrix matB(n, m);
    Matrix matC(m, m);
    cout << "Input values for matrix A:\n";
    matA.input();
    cout << "Input values for matrix B:\n";
    matB.input();
    matC = matA * matB;
    cout << "Matrix A:\n";
    matA.print();
    cout << "Matrix B:\n";
    matB.print();
    cout << "Matrix C (A * B):\n";
    matC.print();
    return 0;
}
