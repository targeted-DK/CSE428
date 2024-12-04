//BaseClass.h
//Author : Donggyu Kim, donggyukim@wustl.edu
//BaseClass header file

#pragma once

class BaseClass {
    public :
        BaseClass();
        ~BaseClass();
        virtual void test();

};

// In each of the classes put the keyword virtual before the declaration of the member function you added in the previous exercise. 
// Build and run the program again, and as the answer to this exercise please
//  (1) show the output that the program produced and
//   (2) explain briefly how and why the program's output differed when you used the keyword virtual vs. when you didn't.

