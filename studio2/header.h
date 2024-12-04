#include <iostream>
#include <ostream>

using namespace std;

enum class Weekday {mon, tue, wed, thu, fri, sat, sun};
enum class Pressure {lo, med, hi, pop};

ostream& operator<<(ostream& os, const Weekday& wkdy);
ostream& operator<<(ostream&os, const Pressure& p);

Weekday operator++(Weekday& wkdy, int); //Question : How is different from Weekday operator++(Weekday& wkdy);
Weekday operator--(Weekday& wkdy, int);

Pressure& operator++(Pressure& p);
Pressure& operator--(Pressure& p);


//questions on return types and how do you overload postfix?

