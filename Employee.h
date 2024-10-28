#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_
#include "Factory.h"
#include <string>

class Employee: public Factory{
    private:
        string Name;
        string JobTitle;
        float Salary;
        string Adress;
        string PhoneNumber;
    public:
        Employee();
        Employee(const Employee&);
        Employee(const string inName);
        ~Employee();

        void Print() const override;
        void Save(ostream&) const override;
        void Load (istream&) override;
        bool Menu () override;


        string GetName();
        string GetJobTitle();
        float GetSalary();
        string GetAdress();
        string GetPhoneNumber();

        void SetName(string inName);
        void SetJobTitle(string inJobTitle);
        void SetSalary(float inSalary);
        void SetAdress(string inAdress);
        void SetPhoneNumber(string inPhoneNumber);
};

#endif