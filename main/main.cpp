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
    int studentID;
    int daysPerCourse[3] = { 30, 30, 30 };
    int age;
    std::string firstName;
    std::string lastName;
    std::string emailAddress;
    std::string degree;

public:
    // Declare constructors
    Student(int studentID, int days, int age, std::string fname, std::string lname, std::string email, std::string degree);

    // Declare accessors and mutators
    int getStudentID() const;
    void setStudentID(int id);

    int getDaysPerCourse() const;
    void setDaysPerCourse(int days);

    int age() const;
    void setAge(int age);

    std::string getFirstName() const;
    void setFirstName(std::string fName);

    std::string getLastName();
    void setLastName(std::string lName);

    std::string getEmailAddress() const;
    void setEmailAddress(std::string email);

    std::string getDegree() const;
    void setDegree(std::string graduated);

    void print() const;
};
#endif







// roster.h
#ifndef ROSTER_H
#define ROSTER_H
#include "student.h"

class Roster {
private:
    // Array attribute to hold 5 students
    Student* classRosterArray[5];

public:
    // Constructor
    Roster();

    // Declare accessors and mutators
    void add(int id, std::string firstName, std::string email, int year,
        int CourseDays1, int CourseDays2, int CourseDays3, Degreeprogram degreeProgram);

    void remove(std::string id);

    void printAll() const;

    void printAverageDaysInCourse(int id) const;

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
  
    // roster.cpp
    // implment function add

    // implment function remove

    // implment function print_all

    // implment function print_average_days_in_course

    // implment print_invalid_emails

    // implment print_by_degree_program


