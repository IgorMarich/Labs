#pragma once
#pragma once
#include "Car.h"



class passengerŅar : public Car
{
    passengerŅar();
    passengerŅar(const string& Firm, const string& Model, const string& Number, int Price, int Year, int Mileage);
    ~passengerŅar();
protected:
    std::string firm;
    std::string model;
    std::string number;
    int price;
    int year;
    int mileage;
};