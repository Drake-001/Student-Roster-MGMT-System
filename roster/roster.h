#pragma once
#ifndef ROSTER_H
#define ROSTER_H

#include <string>

// Define roster class
class Roster {
    // Define attributes
private:
    const classRosterArray[5] =
    { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,[firstname],[lastname],[emailaddress],[age], [numberofdaystocomplete3courses],SOFTWARE"
    };
    std::string add;

    
public:
    // Declare constructors
    Roster() {
    };

    Student* classRosterArray[5];

    // Declare accessors and mutators
    int getClassRosterArray() const {
        return classRosterArray[5];
    }
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

   

