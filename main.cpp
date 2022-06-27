#include <iostream>

using namespace std;

float** getNewArray (float** array, int rows, int columns) {
    float** newArray = new float *[rows];

    for (int i = 0; i < rows; i++) {
        newArray[i] = new float[columns / 2];
    }

    for (int i = 0; i < rows; i++) {
        int n = 0;
        for (int j = 1; j <= columns; j++) {
            if (j % 2 == 0) {
                newArray[i][n] = array[i][j - 1];
                n++;
            }
        }
    }
    return newArray;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int rows, columns;
    cout << "Enter the quantity of rows:";
    cin >> rows;
    cout << "Enter the quantity of columns:";
    cin >> columns;

    float** numbers = new float *[rows];

    for (int i = 0; i < rows; i++) {
        numbers[i] = new float[columns];
    }

    for (int i = 0; i < rows; i++) {
        cout << "\n";
        for (int j = 0; j < columns; j++) {
            numbers[i][j] = rand();
            cout << numbers[i][j] << " ";
        }
    }

    cout << "\n    |" << "\n    |" << "\n    V";

    float** result = getNewArray(numbers, rows, columns);

    for (int i = 0; i < rows; i++) {
        cout << "\n";
        for (int j = 0; j < (columns / 2); j++) {
            cout << result[i][j] << " ";
        }
    }

    for (int i = 0; i < rows; i++) {
        delete[] numbers[i];
        delete[] result[i];
    }

    delete[] numbers;
    delete[] result;

    return 0;
}
