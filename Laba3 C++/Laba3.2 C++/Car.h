#pragma once
#pragma once
#include <string>
#include "IFuelConsumer.h"
using namespace std;


class Car : public  IFuelConsumer
{
public:
    int count = 0;
    // конструкторы
    Car();
    Car(const string& Firm, const string& Model, const string& Number, int Price, int Year, int Mileage);

    void serialize();
    void serialize(const string& filename);
    void deserialize();
    void deserialize(const string& filename);
    void trip(int distance);
    void setFirm(const string& Firm);
    void setModel(const string& Model);
    void setNumber(const string& Number);
    void setPrice(int Price);
    void setYear(int Year);
    void setMileage(int Mileage);

    string& getFirm();
    string& Model();
    string& getNumber();
    int getPrice();
    int  getYear();
    int getMileage();
    static int count;
    ~Car();
protected:
    std::string firm;
    std::string model;
    std::string number;
    int price;
    int year;
    int mileage;
};

