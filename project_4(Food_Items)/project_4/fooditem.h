#ifndef FOODITEM_H
#define FOODITEM_H

#include <iostream>
using namespace std;

class fooditem{
    public:
    void print();
    void setEnergy(double energy); 
    void setFat(double fat);
    void setSugar(double sugar);
    void setProtien(double protien);
    void setSodium (double sodium);
    void setFood(string food);
    double getEnergy();
    double getFat();
    double getSugar();
    double getProtien();
    double getSodium();
    string getFood();
    fooditem(double e ,double f,double s,double p,double so, string fo); // a constructor to set all the attributes of objects by one step
    fooditem operator+(const fooditem& c);
    void operator+=(const fooditem& c);
    private:
    double Energy;
    double Fat;
    double Sugar;
    double Protien;
    double Sodium;
    string Food;
    
};

#endif