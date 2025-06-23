#include <iostream>
using namespace std;

//Single Responibility Principle - принцип единой ответственности.

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void Print(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "");
	const int n = 10;
	int arr[n];
	FillRand(arr, n, 100, 1000);
	Print(arr, n);
}

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