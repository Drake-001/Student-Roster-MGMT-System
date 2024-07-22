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