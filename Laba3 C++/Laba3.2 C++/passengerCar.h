#pragma once
#pragma once
#include "Car.h"



class passengerÑar : public Car
{
    passengerÑar();
    passengerÑar(const string& Firm, const string& Model, const string& Number, int Price, int Year, int Mileage);
    ~passengerÑar();
protected:
    std::string firm;
    std::string model;
    std::string number;
    int price;
    int year;
    int mileage;
};