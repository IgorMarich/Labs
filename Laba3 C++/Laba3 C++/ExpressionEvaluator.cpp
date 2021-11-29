#pragma once

#include "ExpressionEvaluator.h"


ExpressionEvaluator::ExpressionEvaluator()
{
	operandArray = new double[20];
	for (size_t i = 0; i < 20; i++)
	{
		operandArray[i] = 0;
	}
}
ExpressionEvaluator::ExpressionEvaluator(int n)
{
	operandArray = new double[n];
	for (size_t i = 0; i < n; i++)
	{
		operandArray[i] = 0;
	}
}
ExpressionEvaluator:: ~ExpressionEvaluator()
{
	delete[] operandArray;
}

void ExpressionEvaluator::setOperand(size_t pos, double value)
{
	operandArray[pos] = value;
	if (pos > numberOperands) {
		numberOperands = pos;
	}
}

void ExpressionEvaluator::setOperands(double* ops, size_t n)
{
	for (int i = 0; i < n; i++) {
		operandArray[i] = ops[i];
	}
	if (n > numberOperands) {
		numberOperands = n;
	}

}

