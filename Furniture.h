#ifndef _FURNITURE_H_
#define _FURNITURE_H_
#include <string>
#include "Factory.h"
using namespace std;

class Furniture:public Factory
{
    private:
        string TypeOfFurniture;
        float Dimensions[3];
        string Colour;
        string Material;
        float Price;

    public:    
        Furniture();
        Furniture(const Furniture&);
        Furniture(const string& inType);
        ~Furniture();

        void Print() const override;
        void Save(ostream&) const override;
        void Load (istream&) override;
        bool Menu () override;

        string GetType();
        string GetColour();
        string GetMaterial();
        float GetPrice();
        string GetDimensions() const;


        void SetType(string inType);
        void SetColour(string inColour);
        void SetMaterial(string inMaterial);
        void SetPrice(float inPrice);
        void SetDimensions(float x, float y, float z);
};
#endif