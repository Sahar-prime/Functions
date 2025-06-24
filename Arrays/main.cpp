#include <iostream>
#include <cmath>    //Для функции pow()

using namespace std;

#define ARRAYS

//Single Responibility Principle - принцип единой ответственности.

const int ROWS = 3;
const int COLS = 4;

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(double arr[], const int n, int minRand, int maxRand, int decimalPlaces = 2);
void FillRand(int arr[][COLS], const int ROWS, const int COLS);

void Print(int arr[], const int n);
void Print(double arr[], const int n);
void Print(int arr[ROWS][COLS], const int ROWS, const int COLS);

void Sort(int arr[], const int n);

int Sum(int arr[], const int n);

double Avarage(int arr[], const int n);

#ifdef ARRAYS
void main()
{
	setlocale(LC_ALL, "");
	const int n = 10;
	int arr[n];
	FillRand(arr, n);
	cout << "Оригинальный массив:" << endl;
	Print(arr, n);
	Sort(arr, n);
	cout << "Отсортированный массив:" << endl;
	Print(arr, n);
	cout << "Сумма элементов массива: " << Sum(arr, n) << endl;
	cout << "Средне-Арифметическое элементов массива: " << Avarage(arr, n) << endl << endl;

	const int D_SIZE = 8;
	double d_arr[D_SIZE];
	FillRand(d_arr, D_SIZE, 0, 100, 3); // Updated to include decimalPlaces
	Print(d_arr, D_SIZE);
	cout << endl;

	int i_arr_2[ROWS][COLS];
	FillRand(i_arr_2, ROWS, COLS);
	Print(i_arr_2, ROWS, COLS);
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

int Sum(int arr[], const int n) 
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	return sum;
}

double Avarage(int arr[], const int n) 
{
	return (double)Sum(arr, n) / n;
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