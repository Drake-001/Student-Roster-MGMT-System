// roster.h
#ifndef ROSTER_H
#define ROSTER_H
#include "student.h"

class Roster {
private:
    // Array attribute to hold 5 students
    Student* classRosterArray[5];
    int studentNum;

public:
    // Constructor
    Roster();


    // Declare accessors and mutators
    void add(std::string id, std::string firstName, std::string email, int year,
        int CourseDays1, int CourseDays2, int CourseDays3, Degreeprogram degreeProgram);

    void remove(std::string id);

    void printAll();

    void printAverageDaysInCourse(std::string id);

    void printInvalidEmails();

    void printByDegreeProgram(DegreeProgram degreeProgram);

    // Destructor
    ~Roster();
};