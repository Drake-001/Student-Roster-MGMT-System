// main.cpp
#include "roster.h"
#include <iostream>
#include <sstream>

int main() {

    std::cout << "Course: Scripting and Programming Applications" << std::endl;
    std::cout << "Programming Language Used: C++" << std::endl;
    std::cout << "WGU student ID: 011395991" << std::endl;
    std::cout << "Student Name: Drake Davis" << std::endl;


    const std::string studentData[] =
    { "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmail.com,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99@yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Drake,Davis,drakedavis0203@gmail.com,32,30,30,30,SOFTWARE" };




    Roster roster;

    for (int i = 0; i < 5; ++i) {
        std::string data = studentData[i];
        std::stringstream ss(data);

        // Declare variables for student data
        std::string studentID, firstName, lastName, emailAddress, degreeString; 
        int age, daysInCourse1, daysInCourse2, daysInCourse3;
        DegreeProgram degree;

        // Parse and assign values to variables
        std::getline(ss, studentID, ',');
        std::getline(ss, firstName, ',');
        std::getline(ss, lastName, ',');
        std::getline(ss, emailAddress, ',');
        ss >> age;
        ss.ignore(); // Ignores comma
        ss >> daysInCourse1;
        ss.ignore(); 
        ss >> daysInCourse2;
        ss.ignore(); 
        ss >> daysInCourse3;
        ss.ignore(); 
        std::getline(ss, degreeString, ',');


        // Converts the degree string to the degree enum
        if (degreeString == "SOFTWARE") {
            degree = SOFTWARE;
        }
        else if (degreeString == "SECURITY") {
            degree = SECURITY;
        }
        else {
            degree = NETWORK;
        }

        // Add the employee to the roster
        roster.add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degree);
    }

    roster.printAll();
    roster.printInvalidEmails();
    
    for (int i = 0; i < 5; ++i) {
        if (roster.getStudent(i) != nullptr) { 
            roster.printAverageDaysInCourse(roster.getStudent(i)->getStudentID());
        }
    }

    roster.printByDegreeProgram(SOFTWARE);
    roster.remove("A3");
    roster.printAll();
    roster.remove("A3");

    return 0;
}

