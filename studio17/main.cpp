#include <iostream>
#include "template.h"
#include <iostream>
#include <deque>
#include <vector>
#include <list>
#include <array>

#define SUCCESS 0


using namespace std;

int main(){


  

  
//     cout << "Size of the array: " << sizeof(myArray) << " bytes" << endl;
//     cout << "Size of the array element type: " << sizeof(myArray[0]) << " bytes" << endl;

//  int myArray[] = {1, 2, 3, 4, 5};
//     int* pointerToEnd = myArray + (sizeof(myArray) / sizeof(myArray[0]));

    
//      iterateAndPrint(myArray, pointerToEnd);

//     deque<int> myDeque;
//     vector<int> myVector;
//     list<int> myList;

//     for (auto i = 0; i < sizeof(myArray) / sizeof(myArray[0]); ++i) {
//         myDeque.emplace_back(myArray[i]);
//         myVector.emplace_back(myArray[i]);
//         myList.emplace_back(myArray[i]);
//     }

//     cout << "Contents of myDeque:" <<endl;
//     iterateAndPrint(myDeque.begin(), myDeque.end());

//     cout << "\nContents of myVector:" <<endl;
//     iterateAndPrint(myVector.begin(), myVector.end());

//     cout << "\nContents of myList:" <<endl;
    // iterateAndPrint(myList.begin(), myList.end());

    // vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // vector<int>::iterator vec_itr = vec.begin() + 1;

    // iterateAndPrint(vec.begin(), vec_itr);
    // iterateAndPrint(vec_itr, vec.end());
    // vec_itr = vec.begin() + (vec.end() - vec.begin()) / 2;

    // iterateAndPrint(vec.begin(), vec_itr);
    //  iterateAndPrint(vec_itr, vec.end());


    array<int, 5> myArray = {1, 2, 3, 4, 5};
    cout << "Array element: " << myArray[0] << endl;

   
    deque<int> myDeque = {1, 2, 3, 4, 5};
    cout << "Deque element: " << myDeque[0] << endl;

    
    vector<int> myVector = {1, 2, 3, 4, 5};
    cout << "Vector element: " << myVector[0] << endl;

   
    list<int> myList = {1, 2, 3, 4, 5};
    // cout << "List element: " << myList[0] << endl; // Will not compile, list does not support [] operator








    
    return SUCCESS;
}

