//
// Created by Georg on 2/22/2023.
//
#include "string"
#include "vector"

using namespace std;
class Student {

private:
    int id;
    string name;
    vector<char> Grades;

public:
    int calculateFinal(int val = 1) {
        int value = val;

        return value;
    }

    string calculateLetterGrade(string tempGrade = "Z") {
        string grade = tempGrade;


        return grade;

    }

    string printReport(string tempReport = "tempReport") {
        string report;

        return report;
    }
};