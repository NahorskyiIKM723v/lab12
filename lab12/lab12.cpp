#include <iostream>
#include <Windows.h>
using namespace std;

int sumRows(int** matrix, int rows, int cols) {
    int sum = 0;
    for (int i = 0; i < rows; ++i) {
        int maxElement = matrix[i][0];
        for (int j = 1; j < cols; ++j) {
            if (matrix[i][j] > maxElement) {
                maxElement = matrix[i][j];
            }
        }
        sum += maxElement;
    }
    return sum;
}
int* flatten(int** matrix, int rows, int cols) {
    int* flattened = new int[rows * cols];
    int index = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            flattened[index++] = matrix[i][j];
        }
    }
    return flattened;
}
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int rows, cols;
    cout << "Введіть кількість рядків: ";
    cin >> rows;
    cout << "Введіть кількість стовпців: ";
    cin >> cols;

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    cout << "Введіть елементи матриці:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Введіть елемент [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    int sum = sumRows(matrix, rows, cols);
    cout << "Сума максимальних значень у рядках: " << sum << endl;

    int* flattened = flatten(matrix, rows, cols);

    cout << "Одновимірний масив: ";
    for (int i = 0; i < rows * cols; ++i) {
        cout << flattened[i] << " ";
    }

    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] flattened;

    return 0;
}
