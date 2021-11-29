#include "minibus.h"


minibus::minibus()
{

}

minibus::minibus(const string& Firm, const string& Model, const string& Number, int Price, int Year, int Mileage)
{
    firm = Firm;
    model = Model;
    number = Number;
    price = Price;
    year = Year;
    mileage = Mileage;
    count++;
}
minibus::~minibus()
{

}

double consume(double  distance_passed)
{
    int res = distance_passed * 0.12;

    return res;

}