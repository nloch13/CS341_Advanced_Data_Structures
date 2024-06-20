// Keepin' It Classy 
// Assignment #1
// CS341 Spring 2024
// Due 02/02/2024
// By: Nathaniel Loch
//
// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// nloch

#include <iostream>
#include <iomanip>
#include "Student.h"

Student::Student(std::string id, int gradePoints, int creditHours)
{
   id_ = id;
   gradePoints_ = gradePoints;
   creditHours_ = creditHours;
   letterGrade_ = ' ';
   gpa_ = -1;

}

std::string Student::getid() 
{
    return id_;
}

void Student::printInfo()
{
    std::cout << id_ << ": " << std::fixed << std::setprecision(2) << getGPA() << "  " << getLetterGrade() <<std::endl;
}

double Student::getGPA()
{
    double tempGP = gradePoints_;
    double tempCH = creditHours_;
    gpa_ = tempGP / tempCH ;
    return gpa_;
}

void Student::setGPA(double gpa)
{
    gpa_ = gpa;
}

void Student::setid(char id)
{
    id_ = id;
}

int Student::getgradePoints()
{
    return gradePoints_;
}

void Student::setgradePoints(int gradePoints)
{
    gradePoints_ = gradePoints;
}

int Student::getcreditHours()
{
    return creditHours_;
}

void Student::setcreditHours(int creditHours)
{
    creditHours_ = creditHours;
}

char Student::getLetterGrade()
{
    if (gpa_ >= 4.0)
    {
        letterGrade_ = 'A';
    }
    else if (gpa_ >= 3.0)
    {
        letterGrade_ = 'B';
    }
    else if (gpa_ >= 2.0)
    {
        letterGrade_ = 'C';
    }
    else if (gpa_ >= 1.0)
    {
        letterGrade_ = 'D';
    }
    else 
    {
        letterGrade_ = 'F';
    }

    return letterGrade_;
}

void Student::setLetterGrade(char letterGrade)
{
    letterGrade_ = letterGrade;
}