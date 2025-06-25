#include "FillRand.h"

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