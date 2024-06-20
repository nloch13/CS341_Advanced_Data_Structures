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
#include <fstream>
#include <iomanip>
#include "Student.h"

void sort(Student students []);

int main()
{
    char fileName[100];
    char id[6];
    int gradePoints;
    int creditHours;
    int studentNumber = 0;

    std::cout << "Enter the file name: ";
    std::cin >> fileName;
    std::ifstream inputFile(fileName);
    Student students[30];

    std::cout << "****      Welcome to Nate's GPA Calculator Program!       ****" << std::endl;
    std::cout << " " << std::endl;

    while (inputFile >> id >> gradePoints >> creditHours)
        {
            Student newStudent(id, gradePoints, creditHours);

            students[studentNumber] = newStudent;

            studentNumber++;
        }
        
    sort(students);

    inputFile.close();

    for(Student student:students)
    {
        student.printInfo();
    }

    std::cout <<"Thank you for using my GPA calcutlator program - goodbye!" << std::endl;

    return 0;
}

void sort(Student students [])
    {
        for ( int i = 0; i < 30 - 1; i++)
        {
            for ( int j=0; j < 30 - i - 1; j++)
            {
                if (students[j].getGPA() < students[j+1].getGPA())
                {
                    Student Num = students[j];
                    students[j] = students[j+1];
                    students[j+1] = Num;
                }
            }
        }
    } 