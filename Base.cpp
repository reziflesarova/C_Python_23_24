#include <iostream>
#include <cstdlib>  // pro generování náhodných čísel
#include <ctime>    // pro inicializaci generátoru náhodných čísel

using namespace std;

struct Matrix
{
    int** matrix;
    int rows;
    int cols;
};

// funkce pro vypsání matice
void print2DMatrix(Matrix* matrix)
{
    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = 0; j < matrix->cols; j++)
            cout << matrix->matrix[i][j] << "\t";
        cout << endl;
    }
}

int** init2DArray(int rows, int cols)
{
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];
    }
    return matrix;
}

Matrix* initMatrix(int rows, int cols)
{
    Matrix* m = new Matrix;
    m->cols = cols;
    m->rows = rows;
    m->matrix = init2DArray(rows, cols);
    return m;
}

void fillMatrix(Matrix* matrix)
{
    // Inicializace generátoru náhodných čísel
    srand(time(NULL));

    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = 0; j < matrix->cols; j++)
        {
            // Generování náhodného čísla od 1 do 100
            matrix->matrix[i][j] = rand() % 100 + 1;
        }
    }
}

int main()
{
    int rows, cols;

    cout << "Rows: ";
    cin >> rows;

    cout << "Columns: ";
    cin >> cols;

    Matrix* matrix1 = initMatrix(rows, cols);
    fillMatrix(matrix1);
    print2DMatrix(matrix1);

    return 0;
}