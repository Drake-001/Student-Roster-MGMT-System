// main.cpp
#include "roster.h"
#include <iostream>
#include <sstream>

/* Main function:
- initializes roster class,
- provides student array
- performs add, remove, and printing functions
*/

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


    // Instance of Roster class
    Roster roster;

    // Adds new student via loops through student array 
    for (int i = 0; i < 5; ++i) {
        std::string data = studentData[i];
        std::stringstream ss(data); // creates string stream object to read/write string as stream

        // Declares array variables
        std::string studentID, firstName, lastName, emailAddress, degreeString; 
        int age, daysInCourse1, daysInCourse2, daysInCourse3;
        DegreeProgram degree;

        /*Parse and assign values to variables
        Loop extracts student data from string stream based off presence of commas 
        First 5 lines look for commas to separate string data
        Next 8 lines ignore commas after extraction
        */ 
        std::getline(ss, studentID, ',');   
        std::getline(ss, firstName, ',');   
        std::getline(ss, lastName, ',');
        std::getline(ss, emailAddress, ',');
        std::getline(ss, degreeString, ',');
        ss >> age;
        ss.ignore();
        ss >> daysInCourse1;
        ss.ignore(); 
        ss >> daysInCourse2;
        ss.ignore(); 
        ss >> daysInCourse3;
        ss.ignore(); 


        // Converts to degree enum from 'degree.h' header file from degree string
        if (degreeString == "SOFTWARE") {
            degree = SOFTWARE;
        }
        else if (degreeString == "SECURITY") {
            degree = SECURITY;
        }
        else {
            degree = NETWORK;
        }

        // Adds student to array
        roster.add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degree);
    }

    // Prints all students
    roster.printAll();

    // Prints invalid email addresses not in array
    roster.printInvalidEmails();
    
    // Prints average days per course
    for (int i = 0; i < 5; ++i) {
        if (roster.getStudent(i) != nullptr) { 
            roster.printAverageDaysInCourse(roster.getStudent(i)->getStudentID());
        }
    }

    // Prints the students according to their respective programs
    roster.printByDegreeProgram(SOFTWARE);
    
    // Removes student ID 'A3' from array then prints all students
    roster.remove("A3");
    roster.printAll();

    // Test - tries removing student ID 'A3' but will produce error 
    roster.remove("A3");

    return 0;
}

