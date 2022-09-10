//
//  main.cpp
//  Lab 02: SNAP
//
//  Created by little g
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

#include "SNAP.h"
#include "Csg.h"
#include "Cdh.h"
#include "Cr.h"

using namespace std;

bool isValid(string className)
{
    bool isValid = false;
    if ((className == "snap") || ( className == "csg") || (className == "cdh") || (className == "cr")) {
        isValid = true;
    }
    return isValid;
}

void addSNAP(vector<SNAP*>& snapList, string& specs)
{
    SNAP* newSNAP = nullptr;
    string studentID = specs.substr(1, specs.find(',') - 1);
    specs = specs.substr(specs.find(',') + 1);
    string name = specs.substr(0, specs.find(','));
    specs = specs.substr(specs.find(',') + 1);
    string address = specs.substr(0, specs.find(','));
    specs = specs.substr(specs.find(',') + 1, specs.find(')') - 2);
    string phoneNum = specs.substr(0, specs.find(')'));
    newSNAP = new SNAP(studentID, name, address, phoneNum);
    snapList.push_back(newSNAP);
}

void addCsg(vector<Csg*>& csgList, string& specs)
{
    Csg* newCsg = nullptr;
    string course = specs.substr(1, specs.find(',') - 1);
    specs = specs.substr(specs.find(',') + 1);
    string student = specs.substr(0, specs.find(','));
    specs = specs.substr(specs.find(',') + 1);
    string grade = specs.substr(0, specs.find(')'));
    newCsg = new Csg(course, student, grade);
    csgList.push_back(newCsg);
}

void addCdh(vector<Cdh*>& cdhList, string& specs)
{
    Cdh* newCdh = nullptr;
    string course = specs.substr(1, specs.find(',') - 1);
    specs = specs.substr(specs.find(',') + 1);
    string day = specs.substr(0, specs.find(','));
    specs = specs.substr(specs.find(',') + 1);
    string hour = specs.substr(0, specs.find(')'));
    newCdh = new Cdh(course, day, hour);
    cdhList.push_back(newCdh);
}

void addCr(vector<Cr*>& crList, string& specs)
{
    Cr* newCr = nullptr;
    string course = specs.substr(1, specs.find(',') - 1);
    specs = specs.substr(specs.find(',') + 1);
    string room = specs.substr(0, specs.find(')'));
    newCr = new Cr(course, room);
    crList.push_back(newCr);
}

int main(int argc, const char * argv[]) {
     //Checking for correct number of arguments
    if (argc < 3)
    {
       cerr << "Please provide the name of input and output files, thanks\n";
       return 1;
    }
    
    //Checking if input file opens
    ifstream in(argv[1]);
    if (!in)
    {
        cerr << "Failure to open input file: " << argv[1] << endl;
        return 2;
    }
    
    //Checking if output file opens
    ofstream out(argv[2]);
    if (!out)
    {
        in.close();
        cerr << "Failure to open output file: " << argv[1] << endl;
        return 3;
    }
    
    vector<SNAP*> snapList;
    vector<Csg*> csgList;
    vector<Cdh*> cdhList;
    vector<Cr*> crList;
    
    out << "Input Strings:" << endl;
    //reading in the file
    for (string line; getline(in, line);)
    {
        try
        {
            //getting the class name
            size_t p = 0;
            while (isalpha(line[p]))++p;
            string className = line.substr(0, p);
            string specifics = (line.substr(p, line.size() - p));
            if (isValid(className))
            {
                //sorting the contents into their classes
                out << line << endl;
                if (className == "snap")
                {
                    addSNAP(snapList, specifics);
                }
                else if (className == "csg")
                {
                    addCsg(csgList, specifics);
                }
                else if (className == "cdh")
                {
                    addCdh(cdhList, specifics);
                }
                else if (className == "cr")
                {
                    addCr(crList, specifics);
                }
            }
            else {
                throw string(line);
            }
        }  catch(string errorString)
            {
                out << "**Error: " << line << endl;
            }
    }
   
    // Outputting the contents of each individual vector
    out << "\nVectors:\n";
    for (int i = 0; i < snapList.size(); i++)
    {
        out << *snapList.at(i) << endl;
    }
    for (int i = 0; i < csgList.size(); i++)
    {
        out << *csgList.at(i) << endl;
    }
    for (int i = 0; i < cdhList.size(); i++)
    {
        out << *cdhList.at(i) << endl;
    }
    for (int i = 0; i < crList.size(); i++)
     {
         out << *crList.at(i) << endl;
     }
    
    //outputting the courses, names, and grades
    out << "\nCourse Grades:\n";
    for (int i = 0; i < csgList.size(); i++)
    {
        out << csgList.at(i)->getCourse() << ",";
        string id = csgList.at(i)->getStudID();
        for (int j = 0; j < snapList.size(); j++)
        {
            //getting the name (from a different class)
            if (id == snapList.at(j)->getStudID())
            {
                out << snapList.at(j)->getName() << ",";
                break;
            }
        }
        out << csgList.at(i)->getGrade() << endl;
    }
    
    //outputting student schedules
    out << "\nStudent Schedules:\n";
    for (int i = 0; i < snapList.size(); i++)
    {
        out << endl << snapList.at(i)->getName() <<", " << snapList.at(i)->getStudID() << ", " << snapList.at(i)->getAddr() << ", " << snapList.at(i)->getPhone() << endl;
        for (int j = 0; j < csgList.size(); j++)
        {
            if (csgList.at(j)->getStudID() == snapList.at(i)->getStudID())
            {
                out << csgList.at(j)->getCourse() << " ";
                for (int k = 0; k < cdhList.size(); k++)
                {
                    if (csgList.at(j)->getCourse() == cdhList.at(k)->getCourse())
                    {
                        out << cdhList.at(k)->getDay();
                    }
                }
                for (int k = 0; k < cdhList.size(); k++)
                {
                    if (csgList.at(j)->getCourse() == cdhList.at(k)->getCourse())
                    {
                        out << " " << cdhList.at(k)->getHour() << ", ";
                        break;
                    }
                }
                for (int k = 0; k < crList.size(); k++)
                {
                    if (crList.at(k)->getCourse() == csgList.at(j)->getCourse())
                    {
                        out << crList.at(k)->getRoom() << endl;
                        break;
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < snapList.size(); i++)
    {
        delete snapList.at(i);
    }
    for (int i = 0; i < csgList.size(); i++)
    {
        delete csgList.at(i);
    }
    for (int i = 0; i < cdhList.size(); i++)
    {
        delete cdhList.at(i);
    }
    for (int i = 0; i < crList.size(); i++)
    {
        delete crList.at(i);
    }
    return 0;
}
