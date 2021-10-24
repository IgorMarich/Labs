// Laba2.3 C++.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
#include<algorithm>

using namespace std;

class Car
{
public:
    int count = 0;
    // конструкторы
    Car()
    {

    }

    Car(const string& Firm, const string& Model, const string& Number, int Price, int Year, int Mileage)
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
    void serialize()
    {
        ofstream fich;
        
        if (count == 1)
        {
          
            fich.open("output.txt", fstream::out);
            fich << firm << endl;
            fich << model << endl;
            fich << number << endl;
            fich  << price << endl;
            fich << year << endl;
            fich << mileage << endl;
            fich.close();
        }
        else {
            fich.open("output.txt", ios_base::app);
            fich << endl;
            fich << firm << endl;
            fich << model << endl;
            fich << number << endl;
            fich << price << endl;
            fich << year << endl;
            fich << mileage << endl;
            fich.close();
        }

    }
    void serialize(const string& filename)
    {
        ofstream fich;
        fich.open( filename +".txt", fstream::out);
        fich << firm << endl;
        fich << model << endl;
        fich << number << endl;
        fich << price << endl;
        fich << year << endl;
        fich << mileage << endl;
        fich.close();
    }
    //считывание с файла
    void deserialize() {
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
    void deserialize(const string& filename)
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
    //поездка
    void trip(int distance)
    {
        mileage += distance;
    }

    
    //сетеры
   void setFirm( const string& Firm)
   {
       firm = Firm;
   }
   void setModel(const string& Model)
   {
       model = Model;
   }
   void setNumber(const string& Number)
   {
       number = Number;
   }
   void setPrice(int Price)
   {
       price = Price;
   }
   void setYear(int Year)
   {
       year = Year;
   }
   void setMileage(int Mileage)
   {
       mileage = Mileage;
   }

   //гетеры
   string& getFirm()
   {
       return firm;
   }
   string& Model()
   {
       return model;
   }
   string& getNumber()
   {
       return number;
   }
   int getPrice()
   {
       return price;
   }
   int  getYear()
   {
       return year;
   }
   int getMileage()
   {
       return mileage;
   }
private:
    std::string firm;
    std::string model;
    std::string number;
    int price;
    int year;
    int mileage;
};

//сортировка
int* Sort(int* a)
{
   
    for (int i = 0; i < 4; i++)
        for (int j = i + 1; j < 4; j++)
            if (a[i] < a[j])
            {
                int buf = a[i];
                a[i] = a[j];
                a[j] = buf;
            }
    return a;
}

int main()
{
    setlocale(LC_ALL, "rus");
    int const lengh = 3;
    int const N = 4;
    int trip = 4576;

    Car car[lengh];
    car[0].setFirm("Lada");
    car[0].setModel("vesta");
    car[0].setNumber("AA777A");
    car[0].setPrice(500000);
    car[0].setYear(2021);
    car[0].setMileage(0);

    car[1].setFirm("Opel");
    car[1].setModel("vivaro");
    car[1].setNumber("BB732H");
    car[1].setPrice(2500000);
    car[1].setYear(2010);
    car[1].setMileage(0);

    car[2].setFirm("Lada");
    car[2].setModel("vesta");
    car[2].setNumber("HH734B");
    car[2].setPrice(500000);
    car[2].setYear(2015);
    car[2].setMileage(0);

    Car* sportCar = new Car("Reno", "logan", "HA421H", 1300000, 2014, 0);

    car[0].trip(1476);
    car[1].trip(733542);
    car[2].trip(36543);

     sportCar->trip(41234);
    
    int carOld[N]{ 0 };
    int carNew[N]{ 0 };

    
   
    int j1 = 0;
    int j2 = 0;
    for (int i = 0; i < lengh; i++)
    {
        
        if (car[i].getYear() <= 2011 )
        {
             
           carOld[j1] = car[i].getMileage();

           j1++;
        }
        else
        {
             
            carNew[j2] = car[i].getMileage();
            j2++;
        }
    }
    if (sportCar->getYear() <= 2011)
    {
        carOld[j1] = sportCar->getMileage();
        j1++;
    }
    else
    {
        carNew[j2] = sportCar->getMileage();
        j2++;

    }
    
     Sort(carNew);
     Sort(carOld);

     for (int i = 0; i < j2; i++)
     {
         cout << "машины от 2011 года выпуска:" << carNew[i] << " - пробег" << endl;

     }
     for (int i = 0; i < j1; i++)
     {
         cout <<"машины до 2011 года выпуска:" << carOld[i] << " - пробег" << endl;
     }
}

