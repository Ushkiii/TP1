#include<iostream>
#include"Furniture.h"
#include<string>


using namespace std;


Furniture::Furniture(){}

Furniture::Furniture(const Furniture& furniture)
{
    TypeOfFurniture=furniture.TypeOfFurniture;
    Dimensions[3]=furniture.Dimensions[3];
    Colour=furniture.Colour;
    Material=furniture.Material;
    Price=furniture.Price;

    cout<<"Copy constructor\n";

}

Furniture::Furniture(const string& inType)
{
    TypeOfFurniture=inType;
    cout<<"Constructor with parameters\n";

}

Furniture::~Furniture(){cout<<"Destructor Furniture";}

string Furniture::GetDimensions() const
{
     return std::to_string(Dimensions[0]) + " " +  std::to_string(Dimensions[1]) + " "+ std::to_string(Dimensions[2]);
}
void Furniture::Print() const
{
    cout<<"Type:"<<TypeOfFurniture<<endl;
    cout<<"Colour:"<<Colour<<endl;
    cout<<"Material:"<<Material<<endl;
    cout<<"Price:"<<Price<<endl;
    cout<<"Dimensions:"<<""<<GetDimensions()<<endl;

}

string Furniture::GetColour()
{
    return Colour;
}

string Furniture::GetType()
{
    return TypeOfFurniture;
}

string Furniture::GetMaterial()
{
    return Material;
}
float Furniture::GetPrice()
{
    return Price;
}



void Furniture::SetType(string inType)
{
    TypeOfFurniture=inType;
}
void Furniture::SetColour(string inColour)
{
    Colour=inColour;
}
void Furniture::SetMaterial(string inMaterial)
{
    Material=inMaterial;
}
void Furniture::SetPrice(float inPrice)
{
    Price=inPrice;
}
void Furniture::SetDimensions(float x, float y, float z)
{
    Dimensions[0]=x;
    Dimensions[1]=y;
    Dimensions[2]=z;
}

void Furniture::Save(ostream& os) const{
    os<< "Furniture:\n";
    os<<"Type:"<<TypeOfFurniture<<endl;
    os<<"Material:"<<Material<<endl;
    os<<"Dimensions:"<<Dimensions[0]<<""<<Dimensions[1]<<""<<Dimensions[2]<<endl;
    os<<"Price:"<<Price<<endl;
    os<<"Colour:"<<Colour<<endl;
    os<<"end"<<endl;
    cout<<"The Furniture is saved succesfully"<<endl;
}

void Furniture:: Load(istream& is)
{
    while (!is.eof())
    {
        string key, value;
        is>>key;
        if(key=="end")
            break;
        is>>value;
        if (key=="Type:")
        {
           TypeOfFurniture=value;
        }
        else if (key=="Dimensions:")
        {
            Dimensions[0]=stof(value);
            is>>Dimensions[1]>>Dimensions[2];
        }
        else if (key=="Price:")
        {
            Price=stof(value);
        }
        else if (key=="Material:")
        {
            Material=value;
        }
        else if (key=="Colour:")
        {
            Colour=value;
        }
    }
    cout<<"The Furniture is loaded succesfully"<<endl;
}


bool Furniture:: Menu()
{   
    int menu;
    while (1)
    {
        cout<<"Menu:\n";
        cout<<"1.Print information about furniture\n";
        cout<<"2.Set Type\n";
        cout<<"3.Set Material\n";
        cout<<"4.Set Colour\n";
        cout<<"5.Set Price\n";
        cout<<"6.Set Dimensions\n";
        cout<<"7.Exit\n";
        cin>>menu;
        switch (menu)
        {
        case 1:
            this->Print();
            break;
        case 2:
            {
                string user_Type;
                cout<<"Enter Type:";
                cin>> user_Type;
                this->SetType(user_Type);
            }
            break;
        case 3:
            {
                string user_Material;
                cout<<"Enter Material:";
                cin>> user_Material;
                this->SetMaterial(user_Material);
            }
            break;
        case 4:
            {
                string user_Colour;
                cout<<"Enter salary:";
                cin>>user_Colour;
                this->SetColour(user_Colour);
            }
            break;
        case 5:
            {
                float user_Price;
                cout<<"Enter adress:";
                cin>>user_Price;
                this->SetPrice(user_Price);
            }
            break;
        case 6:
            {
                float x,y,z;
                cout<<"Enter dimensions:";
                cin >> x >> y >> z;
                this->SetDimensions(x,y,z);
            }
            break;
        case 7:
            return true;
            break;
        default:
            cerr << "Invalid choice.\n";
            return true;
            break;
        }
    }
    

}