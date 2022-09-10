//
//  Student.h
//  Lab 02: SNAP
//
//  Created by little g
//
#include <iostream>
#include <string>
using namespace std;

#ifndef Student_h
#define Student_h

class Student
{
protected:
    string studID;
public:
    Student() { studID = "0"; }
    Student(string id) : studID(id) {}
    ~Student() = default;
    string getStudID() const { return studID; }
    virtual string toString() const
    {
        stringstream out;
        out <<  "Student(" << studID << ")";
        return out.str();
    }
    
    friend ostream& operator<< (ostream& os, const Student& student)
    {
        os << student.toString();
        return os;
    }
};


#endif /* Student_h */
