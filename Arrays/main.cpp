#include <iostream>
#include"Const.h"
#include "FillRand.h"
#include "Print.h"
#include "stdafx.h"
#include "Sort.h"
#include "Sum.h"

#define ARRAYS

//Single Responibility Principle - принцип единой ответственности.

double Avarage(int arr[], const int n);

int minValueIn(int arr[], const int n);
int maxValueIn(int arr[], const int n);

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
	cout << "Средне-Арифметическое элементов массива: " << Avarage(arr, n) << endl;
	cout << "Минимальное значение в массиве: " << minValueIn(arr, n) << endl;
	cout << "Максимальное значение в массиве: " << maxValueIn(arr, n) << endl << endl;

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

double Avarage(int arr[], const int n) 
{
	return (double)Sum(arr, n) / n;
}

int minValueIn(int arr[], const int n) {
	int minVal = arr[0]; // Assume first element is the minimum initially
	for (int i = 1; i < n; i++) {
		if (arr[i] < minVal) {
			minVal = arr[i];
		}
	}
	return minVal;
}
int maxValueIn(int arr[], const int n) {
	int maxVal = arr[0]; // Assume first element is the maximum initially
	for (int i = 1; i < n; i++) {
		if (arr[i] > maxVal) {
			maxVal = arr[i];
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