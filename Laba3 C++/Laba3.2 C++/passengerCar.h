#pragma once
#pragma once
#include "Car.h"



class passenger�ar : public Car
{
    passenger�ar();
    passenger�ar(const string& Firm, const string& Model, const string& Number, int Price, int Year, int Mileage);
    ~passenger�ar();
protected:
    std::string firm;
    std::string model;
    std::string number;
    int price;
    int year;
    int mileage;
};