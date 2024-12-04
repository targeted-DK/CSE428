#include "header.h"
#include <memory>


using namespace std;

std::unique_ptr<BaseClass> createObject() {
    return std::unique_ptr<BaseClass>(new BaseClass());
}

void useObject(std::unique_ptr<BaseClass>& objPtr) {
    objPtr->display(); 
}


int main(){
    3.
    BaseClass b;
    BaseClass bc = BaseClass(b);
    4.
    BaseClass* b = new BaseClass[3];
    delete b;

    5.6.
    shared_ptr<BaseClass> p1 = make_shared<BaseClass>();

 
    shared_ptr<BaseClass> p2 = make_shared<BaseClass>(*p1);

    std::weak_ptr<BaseClass> p3 = p1;

    std::cout << "Assigning p2 to p1..." << std::endl; 
    p2 = p1;
    std::cout << "Assigned p2 to p1." << std::endl;

    shared_ptr<BaseClass> p4 = p3.lock();

    if (!p4) {
        std::cout << "The weak_ptr no longer points to a valid object." << std::endl;
    } else {
       
        p4->display();
        p4 = nullptr;
    }
    7. 
    unique_ptr<BaseClass> p1 = createObject();
    useObject(p1);
    
    int SUCCESS = 0;

    return SUCCESS;
}