#include"Car.h"
#include <iostream>
#include <fstream>


using namespace std;




Car::Car()
{

}

Car::Car(const string& Firm, const string& Model, const string& Number, int Price, int Year, int Mileage)
{
    firm = Firm;
    model = Model;
    number = Number;
    price = Price;
    year = Year;
    mileage = Mileage;
    count++;
}
//запись в файл
void Car::serialize()
{
    ofstream fout;

    if (count == 1)
    {

        fout.open("output.txt", fstream::out);
        fout << firm << endl;
        fout << model << endl;
        fout << number << endl;
        fout << price << endl;
        fout << year << endl;
        fout << mileage << endl;
        fout.close();
    }
    else {
        fout.open("output.txt", ios_base::app);
        fout << endl;
        fout << firm << endl;
        fout << model << endl;
        fout << number << endl;
        fout << price << endl;
        fout << year << endl;
        fout << mileage << endl;
        fout.close();
    }

}
void Car::serialize(const string& filename)
{
    ofstream fout;
    fout.open(filename + ".txt", fstream::out);
    fout << firm << endl;
    fout << model << endl;
    fout << number << endl;
    fout << price << endl;
    fout << year << endl;
    fout << mileage << endl;
    fout.close();
}
//считывание с файла
void Car::deserialize() {
    fstream fin; //ifstream - file input
    fin.open("output.txt", fstream::in);
    int cnt = 0;

    double cash;
    if (count == 1)
    {
        fin >> firm;
        fin >> model;
        fin >> number;
        fin >> price;
        fin >> year;
        fin >> mileage;
    }
    else {
        while (cnt < count)
        {
            fin >> firm;
            fin >> model;
            fin >> number;
            fin >> price;
            fin >> year;
            fin >> mileage;
            cnt++;
        }
    }
}
void Car::deserialize(const string& filename)
{
    fstream fin;
    fin.open(filename + ".txt", fstream::in);

    fin >> firm;
    fin >> model;
    fin >> number;
    fin >> price;
    fin >> year;
    fin >> mileage;
}

void Car::trip(int n)
{
    mileage += n;
}

double consume(double  distance_passed)
{
    int res = distance_passed * 0.08;

    return res;

}

//сетеры
void Car::setFirm(const string& Firm)
{
    firm = Firm;
}
void Car::setModel(const string& Model)
{
    model = Model;
}
void Car::setNumber(const string& Number)
{
    number = Number;
}
void Car::setPrice(int Price)
{
    price = Price;
}
void Car::setYear(int Year)
{
    year = Year;
}
void Car::setMileage(int Mileage)
{
    mileage = Mileage;
}

//гетеры
string& Car::getFirm()
{
    return firm;
}
string& Car::Model()
{
    return model;
}
string& Car::getNumber()
{
    return number;
}
int Car::getPrice()
{
    return price;
}
int  Car::getYear()
{
    return year;
}
int Car::getMileage()
{
    return mileage;
}
int Car::count = 0;
Car::~Car()
{

}


