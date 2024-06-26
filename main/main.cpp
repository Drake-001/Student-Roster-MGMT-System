#include <iostream>
#include <string>

// degree.h
enum DegreeProgram {
	 SECURITY = "Security",
	 NETWORK = "Network",
	 SOFTWARE = "Software";
};

// student.h
#pragma once
#ifndef STUDENT_H
#define STUDENT_H

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
    Student(int id, int days, int year, string fn, string ln, string email, string deg) {
        studentID = id;
        age = year;
        firstName = fn;
        lastName = ln;
        emailAddress = email;
        degree = deg;
        // daysPerCourse = days;
    }

    // Declare accessors and mutators
    int getID() const {
        return studentID;
    }
    void setStudentID(int id) {
        studentID = id;
    }

    int getDaysPerCourse() const {
        return daysPerCourse[3];
    }
    void setDaysPerCourse(int days1, int days2, int days3) {
        daysPerCourse[0] = days1;
        daysPerCourse[1] = days2;
        daysPerCourse[2] = days3;
    }

    int age() const {
        return age;
    }
    void setAge(int bDay) {
        age = bDay;
    }

    std::string getFirstName() const {
        return firstName;
    }
    void setFirstName(const std::string& fName) {
        firstName = fName;
    }

    std::string getLastName() const {
        return lastName;
    }
    void setLastName(const std::string& lName) {
        lastName = lName;
    }

    std::string getEmailAddress() const {
        return emailAdress;
    }
    void setEmailAddress(const std::string& email) {
        emailAdress = email;
    }

    std::string getDegree() const {
        return degree;
    }
    void setDegree(const std::string& graduated) {
        degree = graduated;
    }
};    // need to add print function here

#endif


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



    // roster.cpp
    // Constructor to initialize the ptr array
    Roster(Student* arr[5]) {
        for (int i = 0; i < 5; ++i) {
            classRosterArray[i] = arr[i];
        }
    }
    
    // roster.cpp
    // implment function add

    // implment function remove

    // implment function print_all

    // implment function print_average_days_in_course

    // implment print_invalid_emails

    // implment print_by_degree_program


