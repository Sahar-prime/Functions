#include <iostream>
#include <cmath>    //Для функции pow()

using namespace std;

//#define ARRAYS

//Single Responibility Principle - принцип единой ответственности.

const int ROWS = 3;
const int COLS = 4;

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(double arr[], const int n, int minRand = 0, int maxRand = 100, int decimalPlaces = 2);
void FillRand(int arr[][COLS], const int ROWS, const int COLS);
void FillRand(double arr[][COLS], const int ROWS, const int COLS);

void Print(int arr[], const int n);
void Print(double arr[], const int n);
void Print(int arr[ROWS][COLS], const int ROWS, const int COLS);
void Print(double arr[ROWS][COLS], const int ROWS, const int COLS);

void Sort(int arr[], const int n);
void Sort(double arr[], const int n);

int Sum(int arr[], const int n);
double Sum(double arr[], const int n);
int Sum(int arr[ROWS][COLS], const int ROWS, const int COLS);
double Sum(double arr[ROWS][COLS], const int ROWS, const int COLS);

double Average(int arr[], const int n);
double Average(double arr[], const int n);
double Average(int arr[ROWS][COLS], const int ROWS, const int COLS);
double Average(double arr[ROWS][COLS], const int ROWS, const int COLS);

int minValueIn(int arr[], const int n);
double minValueIn(double arr[], const int n);
int minValueIn(int arr[ROWS][COLS], const int ROWS, const int COLS);
double minValueIn(double arr[ROWS][COLS], const int ROWS, const int COLS);

int maxValueIn(int arr[], const int n);
double maxValueIn(double arr[], const int n);
int maxValueIn(int arr[ROWS][COLS], const int ROWS, const int COLS);
double maxValueIn(double arr[ROWS][COLS], const int ROWS, const int COLS);

#ifdef ARRAYS
void main()
{
	setlocale(LC_ALL, "");
    const int n = 10;
    int arr[n];
    FillRand(arr, n);
    cout << "Оригинальный массив для int:" << endl;
    Print(arr, n);
    Sort(arr, n);
    cout << "Отсортированный массив для int:" << endl;
    Print(arr, n);
    cout << "Сумма элементов массива для int: " << Sum(arr, n) << endl;
    cout << "Средне-Арифметическое элементов массива для int: " << Average(arr, n) << endl;
    cout << "Минимальное значение в массиве для int: " << minValueIn(arr, n) << endl;
    cout << "Максимальное значение в массиве для int: " << maxValueIn(arr, n) << endl << endl;

    double d_arr[n];
    FillRand(d_arr, n, 0, 100, 3);
    cout << "Оригинальный массив для double:" << endl;
    Print(d_arr, n);
    Sort(d_arr, n);
    cout << "Отсортированный массив для double:" << endl;
    Print(d_arr, n);
    cout << "Сумма элементов массива для double: " << Sum(d_arr, n) << endl;
    cout << "Средне-Арифметическое элементов массива для double: " << Average(d_arr, n) << endl;
    cout << "Минимальное значение в массиве для double: " << minValueIn(d_arr, n) << endl;
    cout << "Максимальное значение в массиве для double: " << maxValueIn(d_arr, n) << endl << endl;

    int i_arr_2[ROWS][COLS];
    FillRand(i_arr_2, ROWS, COLS);
    cout << "Двумерный массив для int:" << endl;
    Print(i_arr_2, ROWS, COLS);
    cout << "Сумма элементов двумерного массива для int: " << Sum(i_arr_2, ROWS, COLS) << endl;
    cout << "Средне-Арифметическое элементов двумерного массива для int: " << Average(i_arr_2, ROWS, COLS) << endl;
    cout << "Минимальное значение в двумерном массиве для int: " << minValueIn(i_arr_2, ROWS, COLS) << endl;
    cout << "Максимальное значение в двумерном массиве для int: " << maxValueIn(i_arr_2, ROWS, COLS) << endl << endl;

    double d_arr_2[ROWS][COLS];
    FillRand(d_arr_2, ROWS, COLS);
    cout << "Двумерный массив для double:" << endl;
    Print(d_arr_2, ROWS, COLS);
    cout << "Сумма элементов двумерного массива для double: " << Sum(d_arr_2, ROWS, COLS) << endl;
    cout << "Средне-Арифметическое элементов двумерного массива для double: " << Average(d_arr_2, ROWS, COLS) << endl;
    cout << "Минимальное значение в двумерном массиве для double: " << minValueIn(d_arr_2, ROWS, COLS) << endl;
    cout << "Максимальное значение в двумерном массиве для double: " << maxValueIn(d_arr_2, ROWS, COLS) << endl << endl;
}

#endif //ARRAYS

void FillRand(int arr[], const int n, int minRand, int maxRand)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = minRand + rand() % (maxRand - minRand + 1);
    }
}

void FillRand(double arr[], const int n, int minRand, int maxRand, int decimalPlaces)
{
    int multiplier = pow(10, decimalPlaces);
    minRand *= multiplier;
    maxRand *= multiplier;
    for (int i = 0; i < n; i++)
    {
        arr[i] = minRand + rand() % (maxRand - minRand + 1);
        arr[i] /= multiplier;
    }
}

void FillRand(int arr[][COLS], const int ROWS, const int COLS)
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            arr[i][j] = rand() % 100;
        }
    }
}

void FillRand(double arr[][COLS], const int ROWS, const int COLS)
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            arr[i][j] = (rand() % 10000) / 100.0;
        }
    }
}

void Print(int arr[], const int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

void Print(double arr[], const int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

void Print(int arr[ROWS][COLS], const int ROWS, const int COLS)
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void Print(double arr[ROWS][COLS], const int ROWS, const int COLS)
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void Sort(int arr[], const int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void Sort(double arr[], const int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int Sum(int arr[], const int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

double Sum(double arr[], const int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int Sum(int arr[ROWS][COLS], const int ROWS, const int COLS)
{
    int sum = 0;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            sum += arr[i][j];
        }
    }
    return sum;
}

double Sum(double arr[ROWS][COLS], const int ROWS, const int COLS)
{
    double sum = 0;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            sum += arr[i][j];
        }
    }
    return sum;
}

double Average(int arr[], const int n)
{
    return (double)Sum(arr, n) / n;
}

double Average(double arr[], const int n)
{
    return Sum(arr, n) / n;
}

double Average(int arr[ROWS][COLS], const int ROWS, const int COLS)
{
    return (double)Sum(arr, ROWS, COLS) / (ROWS * COLS);
}

double Average(double arr[ROWS][COLS], const int ROWS, const int COLS)
{
    return Sum(arr, ROWS, COLS) / (ROWS * COLS);
}

int minValueIn(int arr[], const int n) {
    int minVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}

double minValueIn(double arr[], const int n) {
    double minVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}


int minValueIn(int arr[ROWS][COLS], const int ROWS, const int COLS) {
    int minVal = arr[0][0];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (arr[i][j] < minVal) {
                minVal = arr[i][j];
            }
        }
    }
    return minVal;
}

double minValueIn(double arr[ROWS][COLS], const int ROWS, const int COLS) 
{
    double minVal = arr[0][0];
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++) 
        {
            if (arr[i][j] < minVal) 
            {
                minVal = arr[i][j];
            }
        }
    }
    return minVal;
}

int maxValueIn(int arr[], const int n)
{
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

double maxValueIn(double arr[], const int n) 
{
    double maxVal = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int maxValueIn(int arr[ROWS][COLS], const int ROWS, const int COLS) 
{
    int maxVal = arr[0][0];
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++) 
        {
            if (arr[i][j] > maxVal) 
            {
                maxVal = arr[i][j];
            }
        }
    }
    return maxVal;
}

double maxValueIn(double arr[ROWS][COLS], const int ROWS, const int COLS) 
{
    double maxVal = arr[0][0];
    for (int i = 0; i < ROWS; i++) 
    {
        for (int j = 0; j < COLS; j++)
        {
            if (arr[i][j] > maxVal) 
            {
                maxVal = arr[i][j];
            }
        }
    }
    return maxVal;
}

/*
Передача массива в функци.
Для того чтобы показать что принимаемый параметр функции массив после его имени ставится квадратные скобки [].
Кроме того, функция, работающая с массивом, также в обязательном порядке будет принимать его размер.
void Print(int arr[], const int n);
При вызове такой функции массив особым образом не обозначается, а просто передается его имя следующим образом:
Print(arr, n);

Любая функция для работы с массивом ... сам массив и его размер.

Перегрузка функций назывется ситуация, когда есть 2 и более функции с одинаковым именем, но с разным списком приниаемым параметром.
Список принимаемых параметров перегруженных функций может отличаться так и типом, как и кол-вом аргументов.
Тип возращаемого значения с перегруженной функцией также может отличаться, но перегруженные функции не могут отличаться лишь типом возращаемого значения, поскольку компилятор определяет, какой экземпляр перегруженной функции нужно вызвать лишь по списку принимаемых параметров.
Реализации перегруженной функции также может отличаться или быть одинаковым.
Как правило, если список принимаемых параметров перегруженной функции отличаеться лишь типом аргументов, реализации таких функций будет одинковым или как минимум очень похожи.
Но, если список принимаемых параметров перегруженной функци отличаеться кол-вом аргументов, то скорее всего и реализации таких функций будет разными.
Если функция не умеет работать с каким-либо типом данных, то её нужно перегрузить для этого типа данных.

*/