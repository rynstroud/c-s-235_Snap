//
//  Cdh.h
//  Lab 02: SNAP
//
//  Created by little g
//
#include <iostream>
#include "Course.h"
using namespace std;

#ifndef Cdh_h
#define Cdh_h

class Cdh : public Course
{
private:
    string day;
    string hour;
public:
    Cdh() : Course() { day = "no day", hour = "no hour"; }
    Cdh(const string& c, const string& d, const string& h) : Course(c),
        day(d), hour(h) {}
    ~Cdh() = default;
    string getDay() { return day; }
    string getHour() { return hour; }
    string toString() const
    {
        stringstream out;
        out << "cdh(" << course << "," << day << ", " << hour << ")";
        return out.str();
    }
    friend ostream& operator<< (ostream& os, const Cdh& cdh)
    {
        os << cdh.toString();
        return os;
    }
};

#endif /* Cdh_h */
