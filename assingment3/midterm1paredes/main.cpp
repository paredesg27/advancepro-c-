#include <iostream>
#include "Employee.h"
#include <functional>
using namespace std;

int main() {
    Employee employee("bob", "janitor");



//    employee.getWeeklyPay();
    employee.getWeeklyPay(55);

    Employee employeeCopy(employee);
//    employeeCopy.getWeeklyPay();
    employeeCopy.getWeeklyPay(55);

    Employee employee1Assingment = employee;
//    employee1Assingment.getWeeklyPay();
    employee1Assingment.getWeeklyPay(55);



    return 0;
}
