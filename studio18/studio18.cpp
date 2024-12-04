#include <iostream>     // std::cout
#include <iterator>     // std::ostream_iterator
#include <vector>       // std::vector
#include <algorithm>    // std::copy
#include <numeric>      // std::accumulate


using namespace std;
int main(){


    //#2.
    int arr[] = {-2, 19, 80, -47, 80, 80, -2, 19, 19};  
    int* start = arr;
    int* end = arr+9;
   
    
    ostream_iterator<int> out_it(cout, " ");
    
    // copy(start, end, out_it);

    //#3.
    // vector<int> vec;
    // back_insert_iterator<vector<int> > back_it (vec);
    // copy(start, end, back_it);
    //  for (vector<int>::iterator it = vec.begin(); it!= vec.end(); ++it )
    //     cout << ' ' << *it;

     

    //#4.
    // sort(start, end);
    // copy(start, end, out_it);

    //#5
    // sort(start, end);
    
    // while(start < end - 1){
    //     auto it = adjacent_find(start, end);
    //     while(*it == *(it+1) ){
    //         cout << *it << ' ';
    //         it++;
            
    //     }
    //     cout << *it;
    //     cout << endl;
    //     start = it;
    // }
   
   //#6.
//    sort(start, end, greater<int>());
//    copy(start, end, out_it);

   //#7.

   
    sort(start, end, greater<int>());

    cout << "median : " << *(start+ (int)((end-start)/2)) << endl;
    cout << "mean : " << accumulate(start, end, 0)/(end-start) << endl;
    int max = -1;
    int mode = 0;
    while(start != end){
        int counter = count(start, end, *start);
        if(max < counter){
            max = counter;
            mode = *start;
        }
        start++;
    }
    cout << "mode : " << mode << endl;
   


}