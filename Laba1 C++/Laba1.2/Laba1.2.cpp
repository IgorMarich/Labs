

#include <iostream>
double** array2D(double** arr2D, double* arr1D, int S, int M)
{
	
	
	for (int i = 0; i < S; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (j == 0)
			{
				*(*(arr2D + i) + j) = *(arr1D + i*S + 1) + *(arr1D + i*S + 2) + *(arr1D + i*S + 3);
			}
			else
			{
				*(*(arr2D + i) + j) = *(arr1D + i * S + j);
			}
		}
	}
	return arr2D;
}
double** printArray2D(double** arr2D, int S, int M)
{
	std::cout << "[";
	for (int i = 0; i < S; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
		 std::cout << *(*( arr2D + i) + j) << " \t  "; 
		}
		std::cout << std::endl;
	}
	std::cout << "]" ;
	return 0;
}
int main()
{
	
	const int N = 16; 
	const int S = 4;
	const int M = 4;
	// выделяем память под одномерный массив
	double* arr1D = new double[N];
	// выделям память под двумерный массив 
	double** arr2D = new double* [S];
	for (int i = 0; i < S; ++i)
	{
		*(arr2D + i) = new double[M];
	}
	// заполняем одномерный массив
	for (int i = 0; i < 16; i++)
	{
		*(arr1D + i) = (double)i * exp(3.14 * i / 100);
	 }
	// выводим одномерный массив на экран
	std::cout << "[";
	for (int i = 0; i < 16; i++)
	{
		std::cout <<  *(arr1D + i) << " " ;
	}
	std::cout << "]" << std::endl;

	// заполняем двумерный массив 
	array2D(arr2D, arr1D,  S,  M);
	 // выводим двумерный массив 
	printArray2D(arr2D, S, M);
	
	delete[] arr1D;
	for (int i = 0; i < S; i++)
	{
		delete[] * (arr2D + i);
 }
	delete[] arr2D;

	return 0;
}

