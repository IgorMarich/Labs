#include "Subtractor.h"
#include <fstream>
#include <iostream>

double Subtractor::calculate()
{
	double sum = operandArray[0];
	for (size_t i = 1; i < numberOperands; i++)
	{
		sum -= operandArray[i];
	}
	return sum;
}

void Subtractor::logToScreen()
{
	for (int i = 1; i < numberOperands + 1; i++)
	{
		cout << " operands" << i << ",";
	}
	cout << endl;
	for (int i = 0; i < numberOperands - 1; i++) {

		if (operandArray[i] >= 0)
		{
			cout << operandArray[i] << " - ";
		}
		else
		{
			cout << "(" << operandArray[i] << ")" << " - ";
		}
	}
	cout << operandArray[numberOperands - 1] << endl;
	cout << " Result =  " << calculate() << endl << endl;

}

void Subtractor::logToFile(const string& filename)
{
	ofstream fout;
	fout.open("D:/" + filename + ".txt", fstream::app);
	cout << " Subtractor recorded in " << filename << ".txt"<< endl<<endl;
	for (int i = 1; i < numberOperands + 1; i++)
	{
		fout << " operands" << i << ",";
	}
	fout << endl;
	for (int i = 0; i < numberOperands - 1; i++) {

		if (operandArray[i] >= 0)
		{
			fout << operandArray[i] << " - ";
		}
		else
		{
			fout << "(" << operandArray[i] << ")" << " - ";
		}
	}
	fout << operandArray[numberOperands - 1] << endl;
	fout << " Result =  " << calculate() << endl << endl;


}

