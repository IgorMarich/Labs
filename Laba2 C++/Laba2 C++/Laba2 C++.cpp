// Laba2 C++.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
#include <cstdio>

class Vector {
public:
    double* arr1D;
	int N;
	Vector()
	{

	}
    Vector(int n)
    {
		N = n;
    arr1D = new double[n];
    
    }
    
    double* AddArr1D()
    {
        for (int i = 0; i < N; i++)
        {
            *(arr1D + i) = (double)i * exp(3.14 * i / 100);
        }
		return arr1D;
    }

    
    double* PrintArr1D()
    {
		std::cout << "[";
        for (int i = 0; i < N; i++)
        {
            std::cout <<  *(arr1D + i)<< " ";
        }
        std::cout << "]" << std::endl;
		return arr1D;
    }

	Vector& operator++() // префиксный инкремент
	{
		for (size_t i = 0; i < N; i++)
		{
			this->arr1D[i]++;
		}
		return *this;
	}

	Vector& operator++(int value) // постфиксный инкремент
	{
		Vector temp(*this);
		for (size_t i = 0; i < N; i++)
		{
			this->arr1D[i]++;
		}
		return *this;
	}

	Vector& operator--() // префиксный dickремент
	{
		for (size_t i = 0; i < N; i++)
		{
			this->arr1D[i]--;
		}
		return *this;
	}

	Vector& operator--(int value)
	{
		Vector temp(*this);
		
		for (size_t i = 0; i < N; i++)
		{
			this->arr1D[i]--;
		}
		return *this;
	}

	//double* operator [] (int i) { return firstArray; }
	double& operator[] (const int index) { return arr1D[index]; }

    ~Vector()
    {
        delete[] arr1D;
    }

};


class Matrix
{
public:
	
	double** arr2D;
	int S, M;

	Matrix(int s, int m)
	{
		S = s;
		M = m;
		 arr2D = new double* [S];
		for (int i = 0; i < S; ++i)
		{
			*(arr2D + i) = new double[M];
		}
	}

	double** array2D(double* arr1D)
	{


		for (int i = 0; i < S; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (j == 0)
				{
					*(*(arr2D + i) + j) = *(arr1D + i * S + 1) + *(arr1D + i * S + 2) + *(arr1D + i * S + 3);
				}
				else
				{
					*(*(arr2D + i) + j) = *(arr1D + i * S + j);
				}
			}
		}
		return arr2D;
	}

	double** printArray2D()
	{
		std::cout << "[";
		for (int i = 0; i < S; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				std::cout << *(*(arr2D + i) + j) << " \t  ";
			}
			std::cout << std::endl;
		}
		std::cout << "]";
		return 0;
	}

	const double at(int i, int j)
	{
		return arr2D[i][j];
	}

	void setAt(int i, int j, double value) 
	{
	       arr2D[i][j] = value;
	}

	Matrix& operator++() // префиксный инкремент
	{
		for (size_t i = 0; i < S; ++i) {
			for (size_t j = 0; j < M; ++j)
				this->arr2D[i][j]++;
		}
		return *this;
	}

	Matrix& operator++(int) // постфиксный инкремент
	{
	
		++(*this);
		return *this;
		
		

	}

	Matrix& operator--() // префиксный инкремент
	{
		for (size_t i = 0; i < S; ++i) {

			for (size_t j = 0; j < M; ++j)
				(*(this->arr2D + i))[j]--;
		}

		return *this;
	}

	Matrix& operator--(int)
	{
		--(*this);
		return *this;
		
	}


	~Matrix()
	{
		for (int i = 0; i < S; i++)
		{
			delete[] * (arr2D + i);
		}
		delete[] arr2D;
	}
};


int main()
{      
	setlocale(LC_ALL, "Russian");
	Vector Vector(16);
	Vector.AddArr1D();
    Vector.PrintArr1D();
	Vector[3] = 100;
	Vector[2] = 1;
	printf("четвертый элемент массива после присваивания Vector %f\n", Vector[3]);


	printf("  Vector++: %f\n", Vector[3]++);
	printf("  Vector--: %f\n", Vector[3]--);
    printf(" ++Vector : %f\n", ++ Vector[3]);
    printf(" --Vector : %f\n",  --Vector[3]);

	Matrix Matrix(4, 4);
	Matrix.array2D(Vector.AddArr1D());
	Matrix.printArray2D();
	printf(" элемент массива до присваивания Matrix %f\n", Matrix.at(1, 1));
	Matrix.setAt(1, 1, 100);
	printf(" элемент массива после присваивания Matrix % f\n",  Matrix.at(1, 1));
	
	printf("четвертый элемент массива 1) Matrix %f\n",  Matrix++.at(1, 1));
	
	printf("четвертый элемент массива 2) Matrix %f\n", Matrix--.at(1, 1));
	printf("третий элемент массива после присваивания Matric %f\n", Matrix.at(1, 1));
	++Matrix;
	printf("третий элемент массива Matrix 1) %f\n",  Matrix.at(1, 1));
	--Matrix;
	printf("третий элемент массива Matrix 2) %f\n", Matrix.at(1, 1));
}

