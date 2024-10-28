#include <Car.h>
#include <iostream>
using namespace std;

Car::Car(){cout<<"constructor\n";};

Car::Car(const Car& car)
{
    model=car.model;
    numberPlate=car.numberPlate;
    cout<<"Copy constructor\n";
}

Car::Car(const string& inmodel)
{
    model=inmodel;
    cout<<"Constructor with parameters\n";
}


Car::~Car(){cout<<"Destructor\n";}


void Car:: Print() const
{
    cout<<"Model: "<<model<<'\n'<<"Number plate: "<<numberPlate<<endl;

}

string Car::GetModel()
{
    return model;
}

string Car::GetNumberPlate()
{
    return numberPlate;
}

void Car::SetModel(string inmodel)
{
    model=inmodel;
}

void Car::SetNumberPlate(string inNumberPlate)
{
    numberPlate=inNumberPlate;
}

void Car::Save(ostream& os) const{
    os<< "Car:\n";
    os<<"model: "<<model<<endl;
    os<<"NumberPlate: "<<numberPlate<<endl;
    os<<"end"<<endl;
    cout<<"The car is saved succesfully"<<endl;
}

void Car::Load(istream& is) {
    while (!is.eof())
    {
        string key, value;
        is>> key;
        if(key=="end")
            break;
        is>>value;
        if (key=="model")
        {
            model=value;
        }
        else if (key=="NumberPlate")
        {
            numberPlate=value;
        }
        


    }
    cout<<"The car is loaded succesfully"<<endl;
}


bool Car::Menu(){
    int menu;
    while (1)
    {
        cout<<"Menu:\n";
        cout<<"1.Print car information\n";
        cout<<"2.Set car model\n";
        cout<<"3.Set car number plate\n";
        cout<<"4.Exit\n";
        cin>>menu;
        switch (menu)
        {
        case 1:
            this->Print();
            break;
        case 2:
            {
                string model_user;
                cout<<"Enter car model: ";
                cin>>model_user;
                this->SetModel(model_user);
            }
            break;
        case 3:
            {
                string numberPlate_user;
                cout<<"Enter car model: ";
                cin>>numberPlate_user;
                this->SetModel(numberPlate_user);
            }
            break;
        case 4:
            return false;
            break;
        default: 
                cerr << "Invalid choice.\n";
                return true;
                break;
        }
    
        }
        
    
}