#pragma once
#include "student.h"

class Roster
{
private:
    const static int numberOfStudents = 5;

public:
    ~Roster();
    int lastIndex = -1;
    Student* classRosterArray[numberOfStudents];
    void parse(string row);
    void add(string ID,

        string firstName,

        string lastName,

        string emailAddress,

        int age,

        int daysInCourse1,

        int daysInCourse2,

        int daysInCourse3,

        Degree dep);

    void remove(string ID);

    void printAll();

    void printAverageDaysInCourse(string ID);

    void printInvalidEmails();

    void printByDegreeProgram(Degree dep);
};