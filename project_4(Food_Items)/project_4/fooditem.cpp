#include <iostream>
#include "fooditem.h"
using namespace std;


fooditem::fooditem(double e ,double f,double s,double p,double so, string fo){
    setEnergy(e);
    setFat(f);
    setSugar(s);
    setProtien(p);
    setSodium(so);
    setFood(fo);
    
}

    void fooditem:: setEnergy(double energy){
        if (energy<0){
        cout<<"invalid"<<endl;
        }
        else {
            Energy = energy;    
        }
    }
    void fooditem:: setFat(double fat){
        if (fat<0){
        cout<<"invalid"<<endl;
        }
        else {
            Fat = fat;    
        }        
    }
    void fooditem:: setSugar(double sugar){
        if (sugar<0){
        cout<<"invalid"<<endl;
        }
        else {
            Sugar = sugar;    
        }
        
    }
    void fooditem:: setProtien(double protien){
        if (protien<0){
        cout<<"invalid"<<endl;
        }
        else {
            Protien = protien;    
        }
        
    }
    void fooditem:: setSodium (double sodium){
        if (sodium<0){
        cout<<"invalid"<<endl;
        }
        else {
            Sodium = sodium;    
        }
        
    }
        
    
    void fooditem:: setFood(string food){
    Food = food; 
        
    }
    double fooditem::  getEnergy(){
        return Energy;
    }
    double fooditem:: getFat(){
        return Fat;
    }
    double fooditem:: getSugar(){
        return Sugar;
    }
    double fooditem:: getProtien(){
        return Protien; 
    }
    double fooditem:: getSodium(){
        return Sodium;
    }
    string fooditem:: getFood(){
        return Food; 
    }
    fooditem fooditem::operator+(const fooditem& c){
        fooditem result (0,0,0,0,0,"total");
        result.Energy = Energy+c.Energy;
        result.Fat = Fat+c.Fat;
        result.Sugar = Sugar+c.Sugar;
        result.Protien = Protien+c.Protien;
        result.Sodium = Sodium+c.Sodium;
        result.Food="total";
        return result; 
    }    
    void fooditem::operator+=(const fooditem& c){
    Energy += c.Energy;
    Fat += c.Fat;
    Sugar+=c.Sugar;
    Protien+=c.Protien;
    Sodium+=c.Sodium;
    Food = "total"; 
}

        void fooditem:: print(){
        cout<<"total energy is: "<< Energy<<endl;
        cout<<"Total fats are: "<<Fat<<endl;
        cout<<"Total amount of sugar is: " <<Sugar<<endl;
        cout<<"Total amount of protien is: "<<Protien<<endl;
        cout<<"Total amount of sodium is: " << Sodium<<endl;
    }