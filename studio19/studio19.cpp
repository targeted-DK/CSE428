#include "header.h"
#include <iostream>
#include <set>
#include <algorithm>    // std::copy
#include <iterator>     // std::front_inserter
#include <list>         // std::list

using namespace std;


int main(int argc, char *argv[]){

    //#2.
    // set<string> set_str;
    // set<string>::iterator it = set_str.begin();
    // copy(argv, argv + argc, inserter(set_str, it));
    // std::ostream_iterator<int> out_it (std::cout,", ");
    // copy(set_str.begin(), set_str.end(), std::ostream_iterator<std::string>(std::cout, "\n"));

    //#3.
    // set<char*> set_char;
    // set<char*>::iterator it = set_char.begin();
    // copy(argv, argv + argc, inserter(set_char, it));
    // std::ostream_iterator<int> out_it (std::cout,", ");
    // copy(set_char.begin(), set_char.end(), std::ostream_iterator<char*>(std::cout, "\n"));

    //#4
    // set<string> set_str;
    // std::set<std::string, decltype(test)*> set_str(test);
    // std::copy(argv, argv + argc, std::inserter(set_str, set_str.end()));
    // std::copy(set_str.begin(), set_str.end(), std::ostream_iterator<std::string>(std::cout, "\n"));

    //#5.
    // std::multiset<std::string, decltype(test)*> multiset_str(test);
    // std::copy(argv, argv + argc, std::inserter(multiset_str, multiset_str.end()));
    // std::copy(multiset_str.begin(), multiset_str.end(), std::ostream_iterator<std::string>(std::cout, "\n"));

    //#6.
    // std::multiset<std::string, decltype(test)*> multiset_str(test);
    // std::copy(argv, argv + argc, std::inserter(multiset_str, multiset_str.end()));
    // std::string target = "a";
    // auto range = multiset_str.equal_range(target);
    // std::copy(range.first, range.second, std::ostream_iterator<std::string>(std::cout, "\n"));

    //#7.
    std::multiset<std::string, decltype(test)*> multiset_str(test);
    std::copy(argv, argv + argc, std::inserter(multiset_str, multiset_str.end()));
    std::string target = "a";
    auto range = multiset_str.equal_range(target);
    std::copy(range.first, range.second, std::ostream_iterator<std::string>(std::cout, "\n"));
    cout << "after erase" << endl;
    //Version 1
    multiset_str.erase(range.first);
    //Version 2
    multiset_str.erase(range.first, range.second);
    for (const auto& str : multiset_str) {
        std::cout << str << "\n";
    }




    return 0;



}