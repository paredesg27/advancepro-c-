#include <iostream>
#include "Student.h"
using namespace std;

int main() {

    // Create some grades for a student
    Grade grade1( 90, 100, 0.1, "Homework 1");
    Grade grade2( 90, 100, 0.1, "Homework 2");
    Grade grade3( 98, 100, 0.4,"Exam 1");
    Grade grade4(85, 100, 0.4,"Exam 2");

    // Create a student and add the grades
    Student student(1, "bob Smith");
    student.addGrade(&grade1);
    student.addGrade(&grade2);
    student.addGrade(&grade3);
    student.addGrade(&grade4);

    // Print the student's report
   cout << student.printReport() << endl;

    // Test the copy constructor
    Student studentCopy(student);
    cout << studentCopy.printReport() << endl;

    // Test the assignment operator
    Student studentCopy2 = student;
    cout << studentCopy2.printReport() << endl;



    Grade grade5( 40, 100, 0.7, "Homework 1");
    Grade grade6( 60, 100, 0.6, "Homework 2");
    Grade grade7( 77, 100, 0.1,"Exam 1");
    Grade grade8(85, 100, 0.9,"Exam 2");

    // Create a student and add the grades
    Student student1(2, "allen ally");
    student1.addGrade(&grade5);
    student1.addGrade(&grade6);
    student1.addGrade(&grade7);
    student1.addGrade(&grade8);

    // Print the student's report
    cout << student1.printReport() << endl;

    // Test the copy constructor
    Student student1Copy(student1);
    cout << student1Copy.printReport() << endl;

    // Test the assignment operator
    Student studentCopy3 = student1;
    cout << studentCopy3.printReport() << endl;

    return 0;
}


