
#include "Student.h"

using namespace std;

int main() {

    Grade grade1(90, 100, 0.15, "Homework 1");
    Grade grade2(90, 100, 0.1, "Homework 2");
    Grade grade3(98, 100, 0.4, "Exam 1");
    Grade grade4(85, 100, 0.4, "Exam 2");

    Student student(1, "bob Smith");
    student.addGrade(&grade1);
    student.addGrade(&grade2);
    student.addGrade(&grade3);
    student.addGrade(&grade4);

    Logger::instance().log(student.printReport());


    Student studentCopy(student);
    Logger::instance().log(studentCopy.printReport());

    Student studentCopy2 = student;
    Logger::instance().log(studentCopy2.printReport());

//

    Grade grade5(40, 100, 0.2, "Homework 1");
    Grade grade6(60, 100, 0.2, "Homework 2");
    Grade grade7(77, 100, 0.4, "Exam 1");
    Grade grade8(85, 100, 0.4, "Exam 2");

    // Create a student and add the grades
    Student student1(2, "allen ally");
    student1.addGrade(&grade5);
    student1.addGrade(&grade6);
    student1.addGrade(&grade7);
    student1.addGrade(&grade8);

    Student studentCopy3(student1);
    Student studentCopy4 = student1;


     Logger::instance().log(student1.printReport());
    Logger::instance().log(studentCopy3.printReport());
    Logger::instance().log(studentCopy4.printReport());

    return 0;
}

