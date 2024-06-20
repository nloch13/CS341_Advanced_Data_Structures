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

class Student
{
    public:
        Student() {}
        Student(std::string id, int gradePoints, int creditHours);
        ~Student() {}
        std::string getid();
        void setid(char id_);
        int getgradePoints();
        void setgradePoints(int gradePoints);
        int getcreditHours();
        void setcreditHours(int creditHours);
        char getLetterGrade();
        void setLetterGrade(char letterGrade);
        void printInfo();
        double getGPA();
        void setGPA(double gpa);
        
        

    private:
        std::string id_;
        int gradePoints_;
        int creditHours_;
        char letterGrade_;
        double gpa_;
};