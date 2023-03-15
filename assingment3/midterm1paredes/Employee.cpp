//
// Created by Georg on 3/15/2023.
//

#include "Employee.h"

using namespace std;

Employee::Employee(string name, string jobTitle) :
        name(name),
        jobTitle(jobTitle) {
    cout << "creating object" << endl;
}

Employee::~Employee() {
    cout << "\n Calling Destructor" << endl;
}

Employee::Employee(const Employee &other) :
        name(other.name),
        jobTitle(other.jobTitle) { cout << "\ncopying object" << endl; }

Employee &Employee::operator=(const Employee &other) {
    cout << "/n assigning student" << endl;
    if (this != &other){
        name = other.name;
        jobTitle = other.jobTitle;
    }
    return *this;
}


double Employee::getWeeklyPay(double hours = 40) {
    string response = name + " the " + jobTitle + " got paid $";
    int pay;
    if (hours > 40) {
        pay = ((hours - 40) * (15 * 1.5)) + (40 * 15);
    } else {
        pay = hours * 15;
    }
    response += to_string(pay) + " this week!";
    cout << response << endl;
    *salary += pay;
    return pay;

}
