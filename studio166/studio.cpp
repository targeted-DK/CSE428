#include "studio.h"
#include "header.h"

using namespace std;

void template_func(std::ostream& os, const std::string& str){
    os << "\"" <<  str << "\"" <<  endl;
}

void template_func(std::ostream& os, const char * const c){
     os << "[" << c << " " << reinterpret_cast<const void*>(c) << "] " << endl;
}

void template_func(std::ostream& os, MyClass myclass){
     os << "{" << myclass << "} " << endl;
}