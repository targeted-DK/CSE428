#include "header.h"


using namespace std;

size_t BaseClass::count = 0;

BaseClass::BaseClass() {
    id =  BaseClass::count;
    BaseClass::count++;
    std::cout << "Default constructor. id: " << id << ", Address: " << this << std::endl;
}

BaseClass::BaseClass(const BaseClass& other) {
    id = other.id;
    BaseClass::count++;  // Increment objectCount
    std::cout << "Copy constructor. id: " << id << ", Address: " << this << std::endl;
}

BaseClass::~BaseClass() {
    std::cout << "Destructor. id: " << id << ", Address: " << this << std::endl;
}

void BaseClass::display() const {
    std::cout << "Display function. id: " << id << ", Address: " << this << std::endl;
}

