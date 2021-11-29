#pragma once
#pragma once
#include "Car.h"




class minibus : public Car
{
    minibus();
    minibus(const string& Firm, const string& Model, const string& Number, int Price, int Year, int Mileage);
    ~minibus();
protected:
    std::string firm;
    std::string model;
    std::string number;
    int price;
    int year;
    int mileage;
};