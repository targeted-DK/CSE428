#include <iostream>
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

