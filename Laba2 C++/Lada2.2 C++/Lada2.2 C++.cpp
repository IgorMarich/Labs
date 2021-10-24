// Lada2.2 C++.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

class Fraction {
public:
    static int counter;
    double fraction;
    double result;
    int X,Y,resX,resY;
    
    Fraction(int x, int y) {

        
        X = x;
        Y = y;
        fraction = X / Y;
        resX = X;
        resY = Y;
        result = resX / resY;
        counter++;

    }
   

    void operator+(Fraction& fraction) {
        if (fraction.Y == Y ) 
        {
           resX = X + fraction.X;
           resY = Y;
        }
        else if (fraction.Y < Y && Y % fraction.Y == 0)
        {
            int g = Y / fraction.Y;
            resY = Y;
            resX = X + fraction.X * g;
        }
        else   if ( fraction.Y > Y && fraction.Y % Y == 0 )
            {
            int g = fraction.Y / Y;
                resY  = fraction.Y;
                resX = X*g + fraction.X;
            }
            else
            {
                resX = (X * fraction.Y) + (fraction.X * Y);
                 resY = Y*fraction.Y;
            }
            
        }
    
    void operator -(Fraction& fraction) {
        if (fraction.Y == Y )
        {
           resX = X - fraction.X;
           resY = Y;
        }
        else if (fraction.Y < Y && Y % fraction.Y == 0)
        {
            int g = Y / fraction.Y;
            resY = Y;
            resX = X - fraction.X * g;

        }
        else if (fraction.Y > Y && fraction.Y % Y == 0)
        {
            int g = fraction.Y / Y;
            resY = fraction.Y;
            resX = X*g - fraction.X;
        }
        else
        {
            resX = (X * fraction.Y) - (fraction.X * Y);
            resY = Y*fraction.Y;
        }
    }
    void operator*(Fraction& fraction) {
         resX = X*fraction.X;
         resY = Y *fraction.Y;
    }
    void operator/(Fraction& fraction) {
        resX = X*fraction.Y;
        resY = Y*fraction.X;
    }


    void reduce() {
        int temp = gcd(X, Y);
        this->X /= temp;
        this->Y /= temp;
    }

    static int gcd(int a, int b) {
        while (a != 0 && b != 0) {
            if (a > b) a %= b;
            else b %= a;
        }
        return a + b;
    }

    static void printAsFraction(double decimal_fraction) {
        while (decimal_fraction - (int)decimal_fraction != 0) {
            decimal_fraction *= 10;
        }
        int a = 10;
        while (decimal_fraction / a > 1) {
            a *= 10;
        }
        int temp = gcd(decimal_fraction, a);
        decimal_fraction /= temp;
        a /= temp;
        std::cout << decimal_fraction << "/" << a << std::endl;
    }
    static void printAsFraction(char* decimal_fraction) {
        int cnt = 0;
        char* temp = decimal_fraction;

        while (*decimal_fraction) {
            decimal_fraction++;
            cnt++;
            if (*decimal_fraction == '.') break;
        }

        decimal_fraction++;
        char* a = new char[cnt];
        for (int i = 0; i < cnt; i++) {
            a[i] = temp[i];
        }

        std::string s = a;
        int n = stoi(s);
        std::string ss = decimal_fraction;
        int length = ss.length();
        int m = stoi(ss);
        int y = pow(10, length);
        int x = m + n * y;

        int temp1 = gcd(x, y);
        x /= temp1;
        y /= temp1;

        std::cout << x << "/" << y << std::endl;
    }
};


int Fraction::counter = 0;

int main()
{
    setlocale(LC_ALL, "Russian");

    Fraction a(39, 60);
 
    Fraction b(45, 12);
    
    std::cout << "Количество экземпляров " << Fraction::counter << std::endl;

    a.reduce();
    b.reduce();

    std::cout << "Сокращение дроби: " << a.X << "/" << a.Y << std::endl;
    std::cout << "Сокращение дроби: " << b.X << "/" << b.Y << std::endl;

   
    a + b;
    std::cout << "Сумма дробей: " << a.resX << "/" << a.resY << std::endl;
   
    a - b;
    std::cout << "Разность дробей: " << a.resX << "/" << a.resY << std::endl;

    a / b;
    std::cout << "Деление дробей :" << a.resX << "/" << a.resY << std::endl;
    
    a*b;
    std::cout << "Умножение дробей :" << a.resX << "/" << a.resY << std::endl;

    std::cout << "Наибольший общий делитель: " << a.gcd(20, 40) << std::endl;

    std::cout << "перегруженый метод вывода десятичной дроби 1: ";
    Fraction::printAsFraction(0.43);

    std::cout << "перегруженый метод вывода десятичной дроби 2: ";
    char dec[] = "0.25";
    Fraction::printAsFraction(dec);

}