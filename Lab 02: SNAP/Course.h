//
//  Course.h
//  Lab 02: SNAP
//
//  Created by little g
//
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#ifndef Course_h
#define Course_h

class Course 
{
protected:
    string course;
public:
    Course() { course = "none"; }
    Course(string c) : course(c) {}
    ~Course() = default;
    string getCourse() const { return course; }
    virtual string toString() const
    {
        stringstream out;
        out <<  "Course (" << course << ")";
        return out.str();
    }
    friend ostream& operator<< (ostream& os, const Course& course)
    {
        os << course.toString();
        return os;
    }
};


#endif /* Course_h */
