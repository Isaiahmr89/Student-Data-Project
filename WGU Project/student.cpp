#include <iostream>
#include <string>
#include "student.h"

using namespace std;

Student::Student()
{
    this->age = 0;
    this->degreeProgram = Degree::SECURITY;
}

Student::Student(string id, string fname, string lname, string email, int age, int days[], Degree deg)
{
    studentID = id;
    firstName = fname;
    lastName = lname;
    emailAddress = email;
    this->age = age;
    for (int i = 0; i < 3; ++i)
    {
        daysToComplete[i] = days[i];
    }
    this->degreeProgram = deg;
}

void Student::setStudentID(string id)
{
    studentID = id;
}

void Student::setFirstName(string fname)
{
    firstName = fname;
}

void Student::setLastName(string lname)
{
    lastName = lname;
}

void Student::setEmailAddress(string email)
{
    emailAddress = email;
}

void Student::setAge(int age)
{
    this->age = age;
}

void Student::setDaysToComplete(int days[])
{
    for (int i = 0; i < 3; ++i)
    {
        daysToComplete[i] = days[i];
    }
}

void Student::setDegreeProgram(Degree deg)
{
    degreeProgram = deg;
}

string Student::getStudentID()
{
    return studentID;
}

string Student::getFirstName()
{
    return firstName;
}

string Student::getLastName()
{
    return lastName;
}

string Student::getEmailAddress()
{
    return emailAddress;
}

int Student::getAge()
{
    return age;
}

int* Student::getDaysToComplete()
{
    return daysToComplete;
}

Degree Student::getDegreeProgram()
{
    return degreeProgram;
}

void Student::print()
{
    cout << studentID << '\t' << firstName << '\t' << lastName << '\t' << emailAddress << '\t' << age << '\t' << "{" << daysToComplete[0] << ", " << daysToComplete[1] << ", " << daysToComplete[2] << "}" << '\t' << degreeProgramString[this->getDegreeProgram()] << endl;
};