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



















// student.cpp
#include "student.h"
#include <iostream>

// constructor
Student::Student(int studentID, int days, int age, std::string fname, std::string lname, std::string email, std::string degree)
    : studentID(id), days(days), age(age), fname(fname), lname(lname), email(email), degree(degree) {}


// Define accesssors and mutators
int Student::getStudentID() const { return studentID; }
void Student::setStudentID(std::string studentID) { this->studentID = studentID; }

int Student::getDays() const { return days; }
void Student::setDays(int days) { this->days = days; }

int Student::getAge() const { return age; }
void Student::setage(int age) { this->age = age; }

std::string Student::getFname() const { return fname; }
void Student::setFname(std::string fname) { this->fname = fname; }

std::string Student::getLname() const { return lname; }
void Student::setLame(std:string lname) { this->lname = lname; }

std::string Student::getEmail() const { return email; }
void Student::setEmail(std::string email) { this->email = email; }

std::string Student::getDegree() const { return degree; }
void Student::setDegree(std::string degree) { this->degree = degree; }




















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

// Implement function add student
void Roster::add(int studentID, std::string firstName, std::string lastName, int age, int daysPerCourse, std::string emailAddress, std:: Degree degree) {
    int daysPerCourse[3] = { daysPerCourse1, daysPerCourse2, daysPerCourse3 };
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] == nullptr) {
            classRosterArray[i] == new Student(studentID, firstName, lastName, age, daysPerCourse, emailAddress, degree);
            break;
        }
    }
}
   

// implment function remove
void Roster::remove(std::string id) {
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
            delete classRosterArray[i];
            classRosterArray[i] = nullprt;
            std::cout << "Student " << studentID << " removed." << std::endl;
            return;
        }
    }
    std::cout << "Student" << studentID << " not found." << std::endl;
}





// implment function print_all
void Roster::printAll() const {
    for (const auto& student : students) {
        student.print();
    }
}

// implment function print_average_days_in_course
void Roster::printAverageDaysInCourse(std::string studentID) const {
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getstudentID() == studentID) {
            int* days = classRosterArray[i]->getDays();
            std::cout << "Average days in Courses for " << studentID << ": "
                << (days[0] + days[1] + days[2]) / 3.0 << std::endl;
            return;
        }
    }
}

//**//
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


//**//
void Roster::printByDegree(DegreeProgram degree) const {
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getDegree() == degree) {
            classRosterArray[i]->print();
        }
    }
}


//**//
Roster::~Roster() {
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr) {
            delete classRosterArray[i];
        }
    }
}













// main.cpp


