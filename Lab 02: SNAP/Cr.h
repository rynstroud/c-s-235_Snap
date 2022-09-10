//
//  Cr.h
//  Lab 02: SNAP
//
//  Created by little g
//
#include <iostream>
#include "Course.h"
using namespace std;

#ifndef Cr_h
#define Cr_h

class Cr : public Course
{
private:
    string room;
public:
    Cr() : Course() { room = "no room"; }
    Cr(const string& c, const string& r) : Course(c),
        room(r) {}
    ~Cr() = default;
    string getRoom() { return room; }
    string toString() const
    {
        stringstream out;
        out << "cr(" << course << ", " << room << ")";
        return out.str();
    }

    friend ostream& operator<< (ostream& os, const Cr& cr)
    {
        os << cr.toString();
        return os;
    }
};

#endif /* Cr_h */
