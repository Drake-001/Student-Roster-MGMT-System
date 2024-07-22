// roster.h
#pragma once
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
    Student* getStudent(int index) const;
    
    // Destructor
    ~Roster();
};
#endif
