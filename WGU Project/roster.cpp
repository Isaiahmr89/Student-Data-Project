#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

void Roster::parse(string studentData)
{
    size_t lhs, rhs;

    lhs = 0;

    // finds ID
    rhs = studentData.find(",", lhs);
    string ID = studentData.substr(lhs, rhs - lhs);

    // finds first name
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string firstName = studentData.substr(lhs, rhs - lhs);

    // finds last name
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string lastName = studentData.substr(lhs, rhs - lhs);

    // finds email address
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string emailAddress = studentData.substr(lhs, rhs - lhs);

    // finds age
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int age = stoi(studentData.substr(lhs, rhs - lhs));

    // finds average days in first course
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse1 = stoi(studentData.substr(lhs, rhs - lhs));

    // finds average days in second course
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse2 = stoi(studentData.substr(lhs, rhs - lhs));

    // finds average days in third course
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse3 = stoi(studentData.substr(lhs, rhs - lhs));

    // finds degree program
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string degree = studentData.substr(lhs, rhs - lhs);

    Degree dep = SECURITY;
    if (degree == "NETWORK")
    {
        dep = NETWORK;
    }

    if (degree == "SOFTWARE")
    {
        dep = SOFTWARE;
    }

    this->add(ID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, dep);
}

void Roster::add(string ID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree dep)
{
    int days[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

    classRosterArray[++lastIndex] = new Student(ID, firstName, lastName, emailAddress, age, days, dep);
}

void Roster::remove(string ID)
{
    bool found = false;
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (this->classRosterArray[i]->getStudentID() == ID) // ID found
        {
            found = true;

            delete this->classRosterArray[i];

            this->classRosterArray[i] = this->classRosterArray[lastIndex];
            Roster::lastIndex--; // Roster array is not one element smaller
        }
    }
    if (found)
    {
        cout << endl;
    }
    else cout << "The student with the ID: " << ID << " was not found." << endl;
}


void Roster::printAll()
{
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        this->classRosterArray[i]->print();
    }
}

void Roster::printAverageDaysInCourse(string ID)
{
    for (int i = 0; i <= Roster::lastIndex; i++)

        if (classRosterArray[i]->getStudentID() == ID)
        {
            cout << "Student ID " << classRosterArray[i]->getStudentID() << ": ";
            cout << "average days in course is: " << (classRosterArray[i]->getDaysToComplete()[0] + classRosterArray[i]->getDaysToComplete()[1] + classRosterArray[i]->getDaysToComplete()[2]) / 3 << endl;
        }
}

void Roster::printInvalidEmails()
{
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        string emailAddress = classRosterArray[i]->getEmailAddress();

        if ((emailAddress.find("@") != string::npos) && (emailAddress.find(".") != string::npos))
        {
            if (emailAddress.find(" ") != string::npos)
            {
                cout << emailAddress << " - is invalid." << endl;
            }
        }
        else
        {
            cout << emailAddress << " - is invalid." << endl;
        }
    }
}

void Roster::printByDegreeProgram(Degree dep)
{
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (Roster::classRosterArray[i]->getDegreeProgram() == dep)
            classRosterArray[i]->print();
    }
}

Roster::~Roster()
{
    cout << endl;
    cout << "Destructor starting..." << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << "Deleting student: " << i + 1 << endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}