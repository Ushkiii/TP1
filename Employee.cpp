#include <Employee.h>
#include <string>
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


Employee::~Employee(){cout<<"Destructor\n";}

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
    
}