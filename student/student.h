#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <string>

// Define student class
class Student {
    // Define attributes
private:
    int studentID;
    int daysPerCourse[3] = { 30, 30, 30};
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
};

// need to add print function here

#endif // STUDENT_H