#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include "degree.h"

using namespace std;

class Student
{

private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysToComplete[3];
    Degree degreeProgram;

public:
    Student();

    Student(string studentID, string firstName, string lastName, string emailAddress, int age, int days[], Degree degreeProgram);
    // SET ID
    void setStudentID(string id);
    // SET FIRST NAME
    void setFirstName(string fname);
    // SET LAST NAME
    void setLastName(string lname);
    // SET EMAIL
    void setEmailAddress(string email);
    // SET AGE
    void setAge(int age);
    // SET DAYS TO COMPLETE
    void setDaysToComplete(int days[]);
    // SET DEGREE
    void setDegreeProgram(Degree deg);

    // Get Student ID
    string getStudentID();
    // Get First Name
    string getFirstName();
    // Get Last Name
    string getLastName();
    // Get Emal Address
    string getEmailAddress();
    // Get Age
    int getAge();
    // Get Days To Complete
    int* getDaysToComplete();
    // Get Degree Program
    Degree getDegreeProgram();

    void print();

};
#endif