#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

int main()
{

    const string studentData[] =

    { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
     "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
     "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
     "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
     "A5,Isaiah,Ragland,iragla6@wgu.edu,25,25,30,35,SOFTWARE" };

    cout << "Scripting and Programming - Applications - C867" << endl;
    cout << "Language: C++" << endl;
    cout << "WGU Student ID: 009570014" << endl;
    cout << "Name: Isaiah Ragland" << endl;
    cout << endl;

    const int numOfStudents{ 5 };

    Roster classRoster;

    // Displays all student data
    for (int i = 0; i < numOfStudents; i++)
    classRoster.parse(studentData[i]);
    cout << "Displayng all students: " << endl;
    cout << endl;
    classRoster.printAll();
    cout << endl;

    // Displays students with invalid email addresses
    cout << "Displaying students with invalid emails: " << endl;
    cout << endl;
    classRoster.printInvalidEmails();
    cout << endl;

    // Displays average days in courses
    cout << "Displaying average days in courses: " << endl;
    cout << endl;
    for (int i = 0; i < numOfStudents; i++)
    {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
    }
    cout << endl;

    // Displays by Degree Type 'SOFTWARE'
    cout << "Displaying students in degree program: SOFTWARE" << endl;
    cout << endl;
    for (int i = 0; i < 1; i++)
    {
        classRoster.printByDegreeProgram(SOFTWARE);
    }
    cout << endl;

    // Removes student from the array
    cout << "Removing Student ID A3: " << endl;
    classRoster.remove("A3");

    classRoster.printAll(); // Displays class roster again - 1 (A3)
    cout << endl;

    cout << "Removing student A3 again." << endl;
    cout << endl;
    classRoster.remove("A3");
};