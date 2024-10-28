#ifndef _CAR_H_
#define _CAR_H_
#include <iostream>
#include "Factory.h"
#include <string>
using namespace std;

class Car:public Factory
{
    private:
        string model;
        string numberPlate;
    public: 
        Car();
        Car(const Car&);
        Car(const string& inmodel);
        ~Car();


        void Print() const override;
        void Save(ostream&) const override;
        void Load (istream&) override;
        bool Menu () override;
        string GetModel();
        string GetNumberPlate();
        void SetModel(string inmodel);
        void SetNumberPlate(string inNumberPlate);
        
};

#endif