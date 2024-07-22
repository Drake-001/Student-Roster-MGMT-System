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

void Student::print() const {
    std::cout << "Student ID: " << studentID << "\t";
    std::cout << "First Name: " << firstName << "\t";
    std::cout << "Last Name: " << lastName << "\t";
    std::cout << "Age: " << age << "\t";
    std::cout << "Days in Course: {" << daysPerCourse[0] << ", " << daysPerCourse[1] << ", " << daysPerCourse[2] << "}\t";
    std::cout << "Degree Program: ";
    if (degreeProgram == SECURITY) {
        std::cout << "Security";
    } else if (degreeProgram == NETWORK) {
        std::cout << "Network";
    } else if (degreeProgram == SOFTWARE) {
        std::cout << "Software";
    }
    std::cout << std::endl;
}
