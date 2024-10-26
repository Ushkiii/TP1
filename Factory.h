#include <iostream>
using namespace std;
class Factory{
public:    

    Factory(){}
    virtual ~Factory() {};

    virtual void Print()              const = 0;
    virtual void Save(ostream&)  const = 0;
    virtual void Load(istream&)        = 0;
    virtual bool Menu()                     = 0;
};
