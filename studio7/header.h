//header.h
//Donggyu Kim, donggyukim@wustl.edu
//header file
#include <set>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <ostream>


namespace enumerations{
enum class Pressure {lo, med, hi, pop};
enum class Weekday {mon, tue, wed, thu, fri, sat, sun};

std::ostream& operator<<(std::ostream&os, const Pressure& p);

Pressure& operator++(Pressure& p); //prefix
Pressure& operator--(Pressure& p);

std::ostream& operator<<(std::ostream&os, const Weekday& w);

Weekday operator++(Weekday& wkdy, int); //postfix
Weekday operator--(Weekday& wkdy, int);

};