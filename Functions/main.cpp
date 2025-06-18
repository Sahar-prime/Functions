#include <iostream>
#include <ctime>
using namespace std;

//#define TASK_1
//#define TASK_2
//#define TASK_3
//#define TASK_4
//#define SARRUS_METHOD
//#define MATRIX_MULTIPLICATION
#define UROK

#ifdef TASK_1
void findMinMax(const int array[][3], int rows, int& min, int& max) 
{
    min = array[0][0];
    max = array[0][0];

    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < 3; ++j) 
        {
            if (array[i][j] < min) min = array[i][j];
            if (array[i][j] > max) max = array[i][j];
        }
    }
}

int main() 
{
    const int rows = 3;
    const int cols = 3;
    int array[rows][cols] =
    {
        {3, 7, 1},
        {8, 4, 9},
        {2, 5, 6}
    };

    int min, max;
    findMinMax(array, rows, min, max);

    cout << "Min: " << min << ", Max: " << max << endl;
}
#endif //TASK_1

#ifdef TASK_2
// Функция для циклического сдвига одной строки массива влево
void shiftRowLeft(int row[], int size, int shift)
{
    for (int s = 0; s < shift; ++s)
    {
        int temp = row[0];
        for (int i = 0; i < size - 1; ++i)
        {
            row[i] = row[i + 1];
        }
        row[size - 1] = temp;
    }
}

// Функция для циклического сдвига одной строки массива вправо
void shiftRowRight(int row[], int size, int shift) 
{
    for (int s = 0; s < shift; ++s)
    {
        int temp = row[size - 1];
        for (int i = size - 1; i > 0; --i)
        {
            row[i] = row[i - 1];
        }
        row[0] = temp;
    }
}

int main() 
{
    const int rows = 3;
    const int cols = 3;
    int array[rows][cols] = 
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int shift = 1;

    // Сдвигаем каждую строку массива влево
    for (int i = 0; i < rows; ++i) 
    {
        shiftRowLeft(array[i], cols, shift);
    }

    cout << "Array after left shift:" << endl;
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    // Сдвигаем каждую строку массива вправо
    for (int i = 0; i < rows; ++i) 
    {
        shiftRowRight(array[i], cols, shift);
    }

    cout << "Array after right shift:" << endl;
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}
#endif //TASK_2

#ifdef TASK_3
int main()
{
    const int rows = 3;
    const int cols = 3;
    int array[rows][cols] =
    {
        {5, 3, 8},
        {2, 7, 1},
        {4, 9, 6}
    };

    // Общее количество элементов
    int totalElements = rows * cols;

    // Сортировка пузырьком
    for (int i = 0; i < totalElements - 1; ++i)
    {
        for (int j = 0; j < totalElements - i - 1; ++j)
        {
            int currentRow = j / cols;
            int currentCol = j % cols;
            int nextRow = (j + 1) / cols;
            int nextCol = (j + 1) % cols;

            if (array[currentRow][currentCol] > array[nextRow][nextCol])
            {
                // Обмен значениями
                int temp = array[currentRow][currentCol];
                array[currentRow][currentCol] = array[nextRow][nextCol];
                array[nextRow][nextCol] = temp;
            }
        }
    }

    // Вывод отсортированного массива
    cout << "Sorted array:" << endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}
#endif //TASK_3

#ifdef TASK_4
int main()
{
    const int rows = 3;
    const int cols = 3;
    int array[rows][cols];
    bool used[100] = { false };

    srand(static_cast<unsigned int>(time(nullptr)));

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            int random;
            do 
            {
                random = rand() % 100;
            } while (used[random]);

            used[random] = true;
            array[i][j] = random;
        }
    }

    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}
#endif //TASK_4

#ifdef SARRUS_METHOD
//определитель порядка методом Саррюса:
int main()
{
    setlocale(LC_ALL, "");
    int matrix[3][3] =
    { 
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int det = 
        matrix[0][0] * matrix[1][1] * matrix[2][2] +
        matrix[0][1] * matrix[1][2] * matrix[2][0] +
        matrix[0][2] * matrix[1][0] * matrix[2][1] -
        matrix[0][2] * matrix[1][1] * matrix[2][0] -
        matrix[0][0] * matrix[1][2] * matrix[2][1] -
        matrix[0][1] * matrix[1][0] * matrix[2][2];

    cout << "Определитель матрицы: " << det << endl;
}
#endif //SARRUS_METHOD

#ifdef MATRIX_MULTIPLICATION
//написать алгоритм умножения матриц

// Функция для умножения двух матриц
void multiplyMatrices(int matrix1[2][3], int matrix2[3][2], int result[2][2]) 
{
    for (int i = 0; i < 2; ++i) 
    {
        for (int j = 0; j < 2; ++j) 
        {
            result[i][j] = 0;
            for (int k = 0; k < 3; ++k) 
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Функция для вывода матрицы
void printMatrix(int matrix[2][2])
{
    for (int i = 0; i < 2; ++i) 
    {
        for (int j = 0; j < 2; ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    // Пример матриц
    int matrix1[2][3] =
    {
        {1, 2, 3},
        {4, 5, 6}
    };

    int matrix2[3][2] = 
    {
        {7, 8},
        {9, 10},
        {11, 12}
    };

    int result[2][2];

    // Умножение матриц
    multiplyMatrices(matrix1, matrix2, result);

    // Вывод результата
    cout << "Result of matrix multiplication:" << endl;
    printMatrix(result);
}

#endif //MATRIX_MULTIPLICATION

#ifdef UROK
void main() 
{
    setlocale(LC_ALL, "");

}
#endif //UROK

/*
Функции — это блоки кода, выполняющие определенные операции.
Функции позволяют разместить исходный код одной программы в нескольких исходный файлов, а также сделать код более логичным и понятным.
Прежде чем использовать функцию её нужно объявить и написать.
Синтаксис написания функций: 
type name(parameters)
{
	...;
	group-of-statements;
	...;
}

type - тип возращаемого значения.
Любая функция по завершении возращает какое-то значение - результат своей работы.
У любого значения на язык С++ есть тип этого значения и указывается при написании этой функции.
Функция может возращать значения любого существующего типа.
Некоторые функции не возращают никакие значения, поскольку результат работы и так виден.
Например: когда функция выводит что-либо на экран, либо записывет значения в память, либо изменяет значения в памяти.
Таким функциям ничего не нужно возращать и тип возращаемого значения пишется void - пустота.
Если тип возращаемой функции отличен от void, то в ее теле обязательно должно быть написано return с возращаемым значением.
Ключевое слово return прерывет работу функции, возращает значение на место вызова, а также возращает управление на место вызова
Если функция ничего не возращает, то return писать не обязательно, но его можно использовать для того чтобы прервать работу функции при некоторых обстоятельствах.
После ключевого слово return в теле функции больше ничего не выполняеться.

name - имя функции.
Для именнование функции используются такие же индификаторы, как при именовании переменных.

parameters - принимаемые параметры функции.
Принимаемые параметры - это самые обычные переменные, объявленные в заголовке функции.
Эти переменные являются локальными, т.е. существуют только в той функции, в которой они объявленны.
Локальные переменные удаляются по завершению функции.

group-of-statements - это тело функции.
В теле функции можно писать все что угодно, кроме РЕАЛИЗАЦИИ другой функции.
*/