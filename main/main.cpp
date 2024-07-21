#include <iostream>
#include <string>

// degree.h
#ifndef DEGREE_H
#define DEGREE_H

enum DegreeProgram {SECURITY, NETWORK, SOFTWARE};

#endif 

// student.h
#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include "degree.h"
#include <string>

// Define student class
class Student {
    // Define attributes
private:
    std::string studentID;
    int daysPerCourse[3];
    int age;
    std::string firstName;
    std::string lastName;
    std::string emailAddress;
    DegreeProgram degreeProgram;

public:
    // Declare constructors
    Student(std::string studentID, int days[], int age, std::string firstName, std::string lastName, std::string emailAddress, DegreeProgram degreeProgram);

    // Declare accessors and mutators
    std::string getStudentID() const;
    void setStudentID(std::string id);

    int* getDaysPerCourse();
    void setDaysPerCourse(int days[]);

    int getAge() const;
    void setAge(int age);

    std::string getFirstName() const;
    void setFirstName(std::string fName);

    std::string getLastName();
    void setLastName(std::string lName);

    std::string getEmailAddress() const;
    void setEmailAddress(std::string email);

    DegreeProgram getDegreeProgram() const;
    void setDegreeProgram(DegreeProgram degreeProgram);


    void print() const;
};
#endif

// student.cpp
#include "student.h"
#include <iostream>

// constructor
Student::Student(std::string studentID, int days[], int age, std::string firstName, std::string lastName, std::string emailAddress, DegreeProgram degreeProgram)
    : studentID(studentID), firstName(firstName), lastName(lastName), emailAddress(emailAddress), age(age), degreeProgram(degreeProgram) {
    for (int i = 0; i < 3; ++i) {
        daysPerCourse[i] = days[i];
    }
}

// Define accesssors and mutators
std::string Student::getStudentID() const { return studentID; }
void Student::setStudentID(std::string studentID) { this->studentID = studentID; }

int* Student::getDaysPerCourse() { return daysPerCourse; }
void Student::setDaysPerCourse(int days[]) {
    for (int i = 0; i < 3; ++i) {
        daysPerCourse[i] = days[i];
    }
}

int Student::getAge() const { return age; }
void Student::setAge(int age) { this->age = age; }

std::string Student::getFirstName() const { return firstName; }
void Student::setFirstName(std::string firstName) { this->firstName = firstName; }

std::string Student::getLastName() const { return lastName; }
void Student::setLastName(std::string lastName) { this->lastName = lastName; }

std::string Student::getEmailAddress() const { return emailAddress; }
void Student::setEmailAddress(std::string emailAddress) { this->emailAddress = emailAddress; }

DegreeProgram Student::getDegreeProgram() const { return degreeProgram; }
void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }

// roster.h
#ifndef ROSTER_H
#define ROSTER_H
#include "student.h"

class Roster {
private:
    // Array attribute to hold 5 students
    Student* classRosterArray[5];

public:
    Roster();

    // Declare accessors and mutators
    void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age,
        int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void remove(std::string studentID);
    void printAll() const;
    void printAverageDaysInCourse(std::string studentID) const;
    void printInvalidEmails() const;
    void printByDegreeProgram(DegreeProgram degreeProgram) const;

    // Destructor
    ~Roster();
};
#endif

// roster.cpp
#include "roster.h"
#include <iostream>

// Constructor to initialize the ptr array
Roster::Roster() {
    for (int i = 0; i < 5; ++i) {
        classRosterArray[i] = nullptr;
    }
}

// Implement function add student
void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age,
    int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    int daysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] == nullptr) {
            classRosterArray[i] = new Student(studentID, daysInCourse, age, firstName, lastName, emailAddress, degreeProgram); // Added break to exit loop after adding
            break;
        }
    }
}



   
// implment function remove
void Roster::remove(std::string studentID) {
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;
            std::cout << "Student " << studentID << " removed." << std::endl;
            return;
        }
    }
    std::cout << "Student " << studentID << " not found." << std::endl;
}

// implment function print all
void Roster::printAll() const {
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr) {
            classRosterArray[i]->print();
        }
    }
}

// function print average days in course
void Roster::printAverageDaysInCourse(std::string studentID) const {
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
            int* days = classRosterArray[i]->getDaysPerCourse();
            std::cout << "Average days in Courses for " << studentID << ": "
                << (days[0] + days[1] + days[2]) / 3.0 << std::endl;
            return;
        }
    }
}

// function prints invalid email
void Roster::printInvalidEmails() const {
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr) {
            std::string email = classRosterArray[i]->getEmailAddress();
            if (email.find(' ') != std::string::npos || email.find('@') == std::string::npos || email.find('.') == std::string::npos) {
                std::cout << "Invalid email: " << email << std::endl;
            }
        }
    }
}

// function print degrees by program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) const {
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}

Roster::~Roster() {
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr) {
            delete classRosterArray[i];
        }
    }
}

// main.cpp
#include "roster.h"
#include <iostream>
#include <sstream>

int main() {
    const std::string studentData[] =
    { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Drake,Davis,drakedavis0203@gmail.com,32,30,30,30,SOFTWARE" };

    std::cout << "Course: Scripting and Programming Applications" << std::endl;
    std::cout << "Programming Language Used: C++" << std::endl;
    std::cout << "WGU student ID: 011395991" << std::endl;
    std::cout << "Student Name: Drake Davis" << std::endl;


    Roster roster;

    for (int i = 0; i < 5; ++i) {
        std::string data = studentData[i];
        std::stringstream ss(data);

        // Declare variables for student data
        std::string studentID, firstName, lastName, emailAddress, degreeString, 
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

