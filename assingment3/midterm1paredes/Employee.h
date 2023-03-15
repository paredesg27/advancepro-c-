//
// Created by Georg on 3/15/2023.
//

#ifndef MIDTERM1PAREDES_EMPLOYEE_H
#define MIDTERM1PAREDES_EMPLOYEE_H

#include "string"
#include<iostream>

using namespace std;

class Employee {
public:
    // Constructor
    Employee(string name, string jobTitle);

    // Destructor
    ~Employee();

    // Copy constructor
    Employee(const Employee &other);

    // Assignment operator
    Employee &operator=(const Employee &other);

    double getWeeklyPay(double hours);

private:
    string name;
    string jobTitle;
    double *salary;

};


#endif //MIDTERM1PAREDES_EMPLOYEE_H
