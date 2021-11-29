#include"CustomExpressionEvaluator.h"
#include <fstream>
#include <iostream>

void CustomExpressionEvaluator::shuffle()
{
    double temp;
    for (size_t i = 0; i < numberOperands; i++)
    {
        for (int k = i + 1; k < numberOperands; k++)
        {
            if (operandArray[i] > 0)
            {
                if (operandArray[k] > 0)
                {
                    if (operandArray[i] < operandArray[k])
                    {
                        temp = operandArray[i];
                        operandArray[i] = operandArray[k];
                        operandArray[k] = temp;
                    }
                }
            }
        }
    }
}
void CustomExpressionEvaluator::shuffle(size_t i, size_t j)
{

    double temp;
    temp = operandArray[i];
    operandArray[i] = operandArray[j];
    operandArray[j] = temp;


}


double CustomExpressionEvaluator::calculate()
{
    double res = 0;
    for (int i = 0; i < numberOperands; i++)
    {
        if (i == 0 || i == 1)
        {
            res += operandArray[i] / 2;
        }
        else
        {
            res += operandArray[i];
        }
    }
    return res;
}

void CustomExpressionEvaluator::logToScreen()
{
    
    for (int i = 1; i < numberOperands+1; i++)
    {
        cout << " operands" << i << ",";
    }
    cout << endl;
    for (int i = 0; i < numberOperands ; i++)
    {
        if (i == 0)
        {
            if (operandArray[i] >= 0 && operandArray[i + 1] >= 0)
            {
                cout << "(" << operandArray[i] << " + " << operandArray[i + 1] << " ) " << "/2";
            }
            else if (operandArray[i] < 0 && operandArray[i + 1] < 0)
            {
                cout << "(" << "(" << operandArray[i] << ")" << " + " << "(" << operandArray[i + 1] << ")" << ")" << "/2";
            }
            else if (operandArray[i] >= 0 && operandArray[i + 1] < 0)
            {
                cout << "(" << operandArray[i] << " + " << "(" << operandArray[i + 1] << ")" << ")" << "/2";
            }
            else if (operandArray[i] < 0 && operandArray[i + 1] >= 0)
            {
                cout << "(" << "(" << operandArray[i] << ") " << " + " << operandArray[i + 1] << ")" << "/2";
            }
        }
        if (i > 1)
        {
            if (operandArray[i] >= 0)
            {
                cout << "+" << operandArray[i];
            }
            else
            {
                cout << "+" << "(" << operandArray[i] << ")";
            }

        }
    }
    cout << endl;
    cout << " Result =  " << calculate() << endl << endl;
}

void CustomExpressionEvaluator::logToFile(const string& filename)
{
    ofstream fout;
    fout.open("D:/" + filename + ".txt", fstream::app);
    cout << " CustomExpressionEvaluator recorded in  " << filename << ".txt" << endl<<endl;
    for (int i = 1; i < numberOperands + 1; i++)
    {
        fout << " operands" << i << ",";
    }
    fout << endl;
    for (int i = 0; i < numberOperands; i++)
    {
        if (i == 0)
        {
            if (operandArray[i] >= 0 && operandArray[i + 1] >= 0)
            {
                fout << "(" << operandArray[i] << " + " << operandArray[i + 1] << " ) " << "/2";
            }
            else if (operandArray[i] < 0 && operandArray[i + 1] < 0)
            {
                fout << "(" << "(" << operandArray[i] << ")" << " + " << "(" << operandArray[i + 1] << ")" << ")" << "/2";
            }
            else if (operandArray[i] >= 0 && operandArray[i + 1] < 0)
            {
                fout << "(" << operandArray[i] << " + " << "(" << operandArray[i + 1] << ")" << ")" << "/2";
            }
            else if (operandArray[i] < 0 && operandArray[i + 1] >= 0)
            {
                fout << "(" << "(" << operandArray[i] << ") " << " + " << operandArray[i + 1] << ")" << "/2";
            }
        }
        if (i > 1)
        {
            if (operandArray[i] >= 0)
            {
                fout << "+" << operandArray[i];
            }
            else
            {
                fout << "+" << "(" << operandArray[i] << ")";
            }

        }
    }
    fout << endl;
    fout << " Result =  " << calculate() << endl << endl;
}
