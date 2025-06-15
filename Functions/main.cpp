#include <iostream>
#include <ctime>
using namespace std;

//#define TASK_1
//#define TASK_2
//#define TASK_3
//#define TASK_4
//#define TASK_5

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
// ������� ��� ������������ ������ ����� ������ ������� �����
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

// ������� ��� ������������ ������ ����� ������ ������� ������
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

    // �������� ������ ������ ������� �����
    for (int i = 0; i < rows; ++i) 
    {
        shiftRowLeft(array[i], cols, shift);
    }

    cout << "Array after left shift:" << endl;
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cout << array[i][j] << " ";
        }
        cout << endl;
    }

    // �������� ������ ������ ������� ������
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
// ������� ��� ���������� ���������� �������
void sort2DArray(int array[][3], int rows, int cols) 
{
    int totalElements = rows * cols;
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
                // ����� ����������
                int temp = array[currentRow][currentCol];
                array[currentRow][currentCol] = array[nextRow][nextCol];
                array[nextRow][nextCol] = temp;
            }
        }
    }
}

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

    sort2DArray(array, rows, cols);

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

#ifdef TASK_5
void findDuplicates(const int array[][5], int rows) 
{
    int count[16] = { 0 };

    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < 5; ++j)
        {
            count[array[i][j]]++;
        }
    }

    for (int i = 0; i < 16; ++i) 
    {
        if (count[i] > 1)
        {
            cout << "Value: " << i << ", Count: " << count[i] << endl;
        }
    }
}

int main() {
    const int rows = 4;
    const int cols = 5;
    int array[rows][cols] = 
    {
        {1, 2, 3, 4, 5},
        {6, 7, 0, 9, 1},
        {10, 11, 12, 13, 2},
        {14, 15, 0, 1, 3}
    };

    findDuplicates(array, rows);
}
#endif //TASK_5


/*
������� � ��� ����� ����, ����������� ������������ ��������.
������� ��������� ���������� �������� ��� ����� ��������� � ���������� �������� ������, � ����� ������� ��� ����� �������� � ��������.
������ ��� ������������ ������� � ����� �������� � ��������.
��������� ��������� �������: 
type name(parameters)
{
	...;
	group-of-statements;
	...;
}

type - ��� ������������ ��������.
����� ������� �� ���������� ��������� �����-�� �������� - ��������� ����� ������.
� ������ �������� �� ���� �++ ���� ��� ����� �������� � ����������� ��� ��������� ���� �������.
������� ����� ��������� �������� ������ ������������� ����.
��������� ������� �� ��������� ������� ��������, ��������� ��������� ������ � ��� �����.
��������: ����� ������� ������� ���-���� �� �����, ���� ��������� �������� � ������, ���� �������� �������� � ������.
����� �������� ������ �� ����� ��������� � ��� ������������ �������� ������� void - �������.
���� ��� ����������� ������� ������� �� void, �� � �� ���� ����������� ������ ���� �������� return � ����������� ���������.
�������� ����� return �������� ������ �������, ��������� �������� �� ����� ������, � ����� ��������� ���������� �� ����� ������
���� ������� ������ �� ���������, �� return ������ �� �����������, �� ��� ����� ������������ ��� ���� ����� �������� ������ ������� ��� ��������� ���������������.
����� ��������� ����� return � ���� ������� ������ ������ �� ������������.

name - ��� �������.
��� ����������� ������� ������������ ����� �� ������������, ��� ��� ���������� ����������.

parameters - ����������� ��������� �������.
����������� ��������� - ��� ����� ������� ����������, ����������� � ��������� �������.
��� ���������� �������� ����������, �.�. ���������� ������ � ��� �������, � ������� ��� ����������.
��������� ���������� ��������� �� ���������� �������.

group-of-statements - ��� ���� �������.
� ���� ������� ����� ������ ��� ��� ������, ����� ���������� ������ �������.
*/