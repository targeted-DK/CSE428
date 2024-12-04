//source.cpp
//Donggyu Kim
//source file for studio6
#include "header.h"
#include <iostream>

using namespace std;

Test::Test () 
    : x_(0), y_(0) {

      cout << "default constructor called" << endl;

      cout << this << endl;

      cout << this->x_ << endl;
      cout << this->y_ << endl;
    };

Test::Test (const Test & obj) 
    : x_(obj.x_), y_(obj.y_){

      cout << "copy constructor called" << endl;

      cout << this << endl;

      cout << this->x_ << endl;
      cout << this->y_ << endl;
    };

  int Test::getX () const{

    return x_; 
  };

    int Test::getY () const{

    return y_; 
  };

Test& Test::setX(int x){
    this->x_ = x;
    return *this;
};

Test& Test::setY(int y){
    this->y_ = y;
    return *this;
};

Test returnbyValue(Test test){
  cout << "here2" << endl;
  return test;
};





int main(int argc, char *argv[]){

    Test m;
cout << "here1" << endl;
    returnbyValue(m);
cout << "here3" << endl;
cout << "m.x_ is " <<  m.getX() <<  " and m.y_ is " << m.getY() << endl;

    m.setX(7).setY(3); // chained use of mutator functions
      returnbyValue(m);

cout << "m.x is " << m.getX() << " and m.y is " << m.getY() << endl;

Test n(m); // copy construction
  returnbyValue(n);

cout << "n.x = " << n.getX() << " and n.y = " << n.getY() << endl;


    // Test test;
    // Test& test1 = test;

    // cout << test.getX() << endl;
    // cout << test.getY() << endl;
    // cout << test1.getX() << endl;
    // cout << test1.getY() << endl;
    // test.setX(1);
    // test.setY(2);
    // test1.setX(1);
    // test1.setY(2);

    // cout << test.getX() << endl;
    // cout << test.getY() << endl;
    // cout << test1.getX() << endl;
    // cout << test1.getY() << endl;

};


