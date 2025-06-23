#include <iostream>
using namespace std;

//#define ARRAYS

//Single Responibility Principle - принцип единой ответственности.

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void Print(int arr[], const int n);
void Sort(int arr[], const int n);

#ifdef ARRAYS
void main()
{
	setlocale(LC_ALL, "");
	const int n = 10;
	int arr[n];
	FillRand(arr, n, 100, 1000);
	cout << "Оригинальный массив:" << endl;
	Print(arr, n);
	Sort(arr, n);
	cout << "Отсортированный массив:" << endl;
	Print(arr, n);
}
#endif //ARRAYS

void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++) 
	{
		arr[i] = minRand + rand() % (maxRand - minRand + 1);
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

/*
Передача массива в функци.
Для того чтобы показать что принимаемый параметр функции массив после его имени ставится квадратные скобки [].
Кроме того, функция, работающая с массивом, также в обязательном порядке будет принимать его размер.
void Print(int arr[], const int n);
При вызове такой функции массив особым образом не обозначается, а просто передается его имя следующим образом:
Print(arr, n);

Любая функция для работы с массивом ... сам массив и его размер.

*/
