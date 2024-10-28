#include "Employee.h"
#include <string>
#include <iostream>
using namespace std;


Employee::Employee(){cout<<"Constructor\n";}

Employee::Employee(const Employee& employee)
{
    Name=employee.Name;
    JobTitle=employee.JobTitle;
    Salary=employee.Salary;
    Adress=employee.Adress;
    PhoneNumber=employee.PhoneNumber;
    cout<<"Copy constructor\n";
}

Employee::Employee(const string inName)
{
    Name=inName;
    cout<<"Constructor with parameters\n";
}


Employee::~Employee(){cout<<"Destructor Employee\n";}

void Employee::Print() const
{
    cout<<"Employee:\n ";
    cout<<"Name: "<<Name<<endl;
    cout<<"Salary: "<<Salary<<endl;
    cout<<"Adress: "<<Adress<<endl;
    cout<<"Phone number: "<<PhoneNumber<<endl;

}

string Employee:: GetName()
{
    return Name;
}

string Employee:: GetJobTitle()
{
    return JobTitle;
}

string Employee:: GetAdress()
{
    return Adress;
}

float Employee:: GetSalary()
{
    return Salary;
}

string Employee:: GetPhoneNumber()
{
    return PhoneNumber;
}

void Employee::SetName(string inName)
{
    Name=inName;
}

void Employee::SetJobTitle(string inJobTitle)
{
    JobTitle=inJobTitle;
}

void Employee::SetAdress(string inAdress)
{
    Adress=inAdress;
}
void Employee::SetSalary(float inSalary)
{
    Salary=inSalary;
}

void Employee::SetPhoneNumber(string inPhoneNumber)
{
    PhoneNumber=inPhoneNumber;
}


void Employee:: Save(ostream& os) const
{
    os<<"Employee: \n";
    os<<"Name:"<<Name<<endl;
    os<<"JobTitle:"<<JobTitle<<endl;
    os<<"Salary:"<<Salary<<endl;
    os<<"Adress:"<< Adress<<endl;
    os<<"PhoneNumber:"<<PhoneNumber<<endl;
    os<<"end"<<endl;
    cout<<"The employee is saved succesfully\n";
}


void Employee:: Load(istream& is)
{
    while (!is.eof())
    {
        string key, value;
        is>>key;
        if(key=="end")
            break;
        is>>value;
        if (key=="Name:")
        {
           Name=value;
        }
        else if (key=="JobTitle:")
        {
            JobTitle=value;
        }
        else if (key=="Salary:")
        {
            Salary=stof(value);
        }
        else if (key=="Adress:")
        {
            Adress=value;
        }
        else if (key=="PhoneNumber:")
        {
            PhoneNumber=value;
        }
    }
    cout<<"The employee is loaded succesfully"<<endl;
}

bool Employee:: Menu()
{   
    int menu;
    while (1)
    {
        cout<<"Menu:\n";
        cout<<"1.Print information about employee\n";
        cout<<"2.Set name\n";
        cout<<"3.Set job title\n";
        cout<<"4.Set salary\n";
        cout<<"5.Set adress\n";
        cout<<"6.Set phone number\n";
        cout<<"7.Exit\n";
        cin>>menu;
        switch (menu)
        {
        case 1:
            this->Print();
            break;
        case 2:
            {
                string user_Name;
                cout<<"Enter name:";
                cin>> user_Name;
                this->SetName(user_Name);
            }
            break;
        case 3:
            {
                string user_JobTitle;
                cout<<"Enter job title:";
                cin>> user_JobTitle;
                this->SetJobTitle(user_JobTitle);
            }
            break;
        case 4:
            {
                float user_Salary;
                cout<<"Enter salary:";
                cin>>user_Salary;
                this->SetSalary(user_Salary);
            }
            break;
        case 5:
            {
                string user_Adress;
                cout<<"Enter adress:";
                cin>>user_Adress;
                this->SetAdress(user_Adress);
            }
            break;
        case 6:
            {
                string user_PhoneNumber;
                cout<<"Enter phone number:";
                cin>>user_PhoneNumber;
                this->SetPhoneNumber(user_PhoneNumber);
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