//
// Created by George on 2/25/2023.
//

#ifndef PAREDESG1_H3_STUDENT_H
#define PAREDESG1_H3_STUDENT_H


#include "cmath"
#include <algorithm>
#include "string"
#include "vector"
#include <utility>
#include "logger.h" // assuming logger is defined in logger.h
#include "Grade.h"


class Student {
public:
    // Constructor
    Student(int id, string name);

    // Destructor
    ~Student();
    // Copy constructor
    Student(const Student &other);

    // Assignment operator
    Student &operator=(const Student &other);
    // Mutators

    void addGrade(Grade *grade) ;

    // Helper functions
    int calculateFinal() const ;

    string calculateLetterGrade() const ;

    string printReport() const ;

private:
    int id_;
    string name_;
    vector<Grade *> grades_;
};


#endif //PAREDESG1_H3_STUDENT_H