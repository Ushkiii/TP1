#include <string>
#include <Factory.h>
using namespace std;
class Keeper
{
    private:
        string SaveFile;
        Factory**  ObjectBuff;
        int counter;
        int Size;
        void  ReallocBuff(int nCopacity);
    public:
        Keeper();
        Keeper(int count);
        Keeper(const Keeper&);
        ~Keeper();

        bool Save();
        void Load();
        void Print() const;
        bool SaveFile(const string& SaveFile);
        void Pushback(Factory* ptr);
        int Size() const;
        Factory& operator[](int index);
        void operator+=(Factory* ptr);


};