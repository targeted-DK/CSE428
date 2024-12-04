/* A C++ Program in the spirit of the classic example from page 6
   of Kernighan and Ritchie's The C Programming Language, 2nd. Ed. */

#include <iostream> // for cout ostream and endl manipulator
#include <fstream>
using namespace std; // optional, could say std::cout and std::endl below instead

const int SUCCESS = 0; // by convention, where non-zero results are error codes
const int FAIL = 1;
const int WRONGNAME = 2;
int main (int argc, char *argv[]) { // argc and argv not used, but their types are specified
std::string input;
std::string text;
ofstream ofs;
cin >> input;

if(input != "helloworld"){
  ofs.open("helloworld");
  ofs <<  WRONGNAME;
  return WRONGNAME;
}
ofs.open(input);
cin >> text;
ofs << text;
ofs.close();


 if(argc > 2){
return SUCCESS;
} else {
return FAIL;
}

 //   cout << "hello, world!" << endl; // procedural: has an effect

   // return SUCCESS; // functional: returns a success/failure code
}

