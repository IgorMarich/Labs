#include "Summator.h"
#include <fstream>
#include <iostream>


double Summator::calculate()
{
	double sum = 0;
	for (size_t i = 0; i < numberOperands -1; i++)
	{
		sum += operandArray[i];
	}
	return sum;
}

void Summator::logToScreen()
{
	for (int i = 1; i < numberOperands + 2; i++)
	{
		cout << " operands" << i << ",";
	}
	cout << endl;

	for (int i = 0; i < numberOperands ; i++) {
		if (operandArray[i] >= 0)
		{
			cout << operandArray[i] << " + ";
		}
		else
		{
			cout << "(" << operandArray[i] << ")" << " + ";
		}

	}
	cout << operandArray[numberOperands] << endl;
    cout << " Result =  " << calculate() << endl << endl;

}

void Summator::logToFile(const string& filename)
{
	ofstream fout;
	fout.open("D:/" + filename + ".txt", fstream::app);
	cout << "Summator recorded in " << filename << ".txt"<< endl<< endl;
	for (int i = 1; i < numberOperands + 2; i++)
	{
		fout << " operands" << i << ",";
	}
	fout << endl;

	for (int i = 0; i < numberOperands; i++) {
		if (operandArray[i] >= 0)
		{
			fout << operandArray[i] << " + ";
		}
		else
		{
			fout << "(" << operandArray[i] << ")" << " + ";
		}

	}
	fout << operandArray[numberOperands] << endl;
    fout << " Result =  " << calculate() << endl << endl;

}
