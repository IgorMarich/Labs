#include "passengerCar.h"
#include <iostream>
#include <fstream>


using namespace std;




passenger�ar::passenger�ar()
{

}

passenger�ar::passenger�ar(const string& Firm, const string& Model, const string& Number, int Price, int Year, int Mileage)
{
    firm = Firm;
    model = Model;
    number = Number;
    price = Price;
    year = Year;
    mileage = Mileage;
    count++;
}
double consume(double  distance_passed)
{
    int res = distance_passed * 0.06;

    return res;

}
passenger�ar::~passenger�ar()
{

}