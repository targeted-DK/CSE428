//header.h
//Donggyu Kim, donggyukim@wustl.edu
//header file
#include <set>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <ostream>


using namespace std;

enum class Pressure {lo, med, hi, pop};
ostream& operator<<(ostream&os, const Pressure& p);
Pressure& operator++(Pressure& p); //prefix
Pressure& operator--(Pressure& p);
enum class Weekday {mon, tue, wed, thu, fri, sat, sun};
ostream& operator<<(ostream&os, const Pressure& p);
Weekday operator++(Weekday& wkdy, int); //postfix
Weekday operator--(Weekday& wkdy, int);
