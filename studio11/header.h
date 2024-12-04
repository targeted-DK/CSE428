#include <string>

class MyClass{
    private :
        std::string var;

    public:
        //#3.
        MyClass() = default;
        MyClass(const std::string& str);
        MyClass(const MyClass& other);
        virtual ~MyClass();
        virtual void print();
       MyClass& operator=(const MyClass& myclass);
};



// Declare and define a public assignment operator for your class, 
// which takes a const reference to an object of the class type and returns a non-const reference to an object of the class type. 
// That operator should (1) first print out the address and private member variable of the object on which it is being called, 
// followed by the address and private member variable of the object that was passed into it;
//  (2) assign its private member variable the private member variable of the object that was passed into it; and then
//   (3) return a (non-const) reference to the object on which it was invoked.
