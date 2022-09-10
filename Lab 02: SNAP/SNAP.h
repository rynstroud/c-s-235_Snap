//
//  SNAP.h
//  Lab 02: SNAP
//
//  Created by little g
//

#ifndef SNAP_h
#define SNAP_h
#include <sstream>
#include <string>
#include "Student.h"
using namespace std;

class SNAP : public Student
{
private:
    string name;
    string address;
    string phone;
public:
    SNAP() : Student() { name = "no name", address = "no address", phone = "no phone"; }
    SNAP(string id, const string& n, const string& a, const string& p) : Student(id),
        name(n), address(a), phone(p) {}
    ~SNAP() = default;
    string getName() { return name; }
    string getAddr() { return address; }
    string getPhone() { return phone; }
    
    string toString() const
    {
        stringstream out;
        out << "snap(" << studID << ", " << name << ", " << address << ", " << phone << ")";
        return out.str();
    }

    friend ostream& operator<< (ostream& os, const SNAP& snap)
    {
        os << snap.toString();
        return os;
    }
};

#endif /* SNAP_h */
