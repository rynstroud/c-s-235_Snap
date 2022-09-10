//
//  Csg.h
//  Lab 02: SNAP
//
//  Created by little g
//
#include "Course.h"
#include "Student.h"
#include <string>
#include <sstream>
using namespace std;
#ifndef Csg_h
#define Csg_h

class Csg : public Course, public Student
{
private:
    string grade;
public:
    Csg() : Course(), Student() { grade = "none"; }
    Csg(string& c, string& s, string& g) : Course(c), Student(s), grade(g) {}
    string getGrade() { return grade; }
    string toString() const
    {
        stringstream out;
        out << "csg(" << course << ", " << studID << ", " << grade << ")";
        return out.str();
    }
    
    friend ostream& operator<< (ostream& os, const Csg& csg)
    {
        os << csg.toString();
       return os;
    }
};

#endif /* Csg_h */
