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
#endif#pragma once
