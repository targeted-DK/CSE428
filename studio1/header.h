#include <iostream>


using namespace std;

struct Test{

    int x;
    public :
        Test(int x1) : x(x1){};
        // 4 default operators  - copy, destruct, << , 
        // Test() = delete;
        // ~Test() = delete;
        // Test &operator=(const Test&) = delete;
        
};

// template<typename T = int> 
// struct Foo {
   
//     public:
//         T x;
//         Foo(T x1 = 0);
// };


//reference : https://stackoverflow.com/questions/10744787/operator-must-take-exactly-one-argument
template<typename T>
class Foo {
    private : 
        T x;
    
    public : 
    Foo(T x1 = 0);

    friend ostream& operator<<<T>(ostream& os, const Foo<T>& f);
};

template<typename T>
ostream& operator<<(ostream& os, const Foo<T>& f);