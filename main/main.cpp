#include <iostream>
#include <string>

// degree.h
class DegreeProgram {
	string SECURITY = "Security";
	string NETWORK = "Network";
	string SOFTWARE = "Software";
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
string classRoster[5];

class Roster {
private:
    // Array attribute to hold 5 students
    Student* classRoster[5];
    int studentNum;

public:
    // roster.h
    // Constructor
    Roster();
    // Declare accessors and mutators
    int getClassRosterArray() const {
        return classRosterArray[5];
    }   
    // Destructor
    ~Roster();
    void setClassRosterArray(
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,[firstname],[lastname],[emailaddress],[age], [numberofdaystocomplete3courses],SOFTWARE"
};


    void add(char id, char firstName, char email, int year, int CourseDays1, int CourseDays2, int CourseDays3, Degreeprogram degreeprogram) {
        studentID = id;
        age = year;
        daysInCourse1 = CourseDays1;
        daysInCourse2 = CourseDays2;
        daysInCourse3 = CourseDays3;
        // Not sure bout here;
    };

    void remove(char id) {
        studentID = id;
    };

    void printAll(char list) {
        classRosterArray = list;
    };

    void printAverageDaysInCourse() {
    };

    void printInvalidEmails() {
    };

    void printByDegreeProgram() {
    };

    // roster.cpp
    // Constructor to initialize the array
    classRoster(std::string arr[5]) {
        for (int i = 0; i < 5; ++i) {
            classRoster[i] = arr[i];
        }
    }
    
    // roster.cpp
    // implment function add

    // implment function remove

    // implment function print_all

    // implment function print_average_days_in_course

    // implment print_invalid_emails

    // implment print_by_degree_program
};

