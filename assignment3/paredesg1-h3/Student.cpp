//
// Created by Georg on 2/22/2023.
//

#include "Student.h"


using namespace std;
Student::Student(int id, string name) :
        id_(id),
        name_(std::move(name)) {}

// Destructor
Student::~Student() {
    Logger::instance().log("Destroying student " + to_string(id_) + "\n");
    for (Grade *grade: grades_) {
        delete grade;
    }
}

// Copy constructor
Student::Student(const Student &other) :
        id_(other.id_),
        name_(other.name_) {
    Logger::instance().log("Copying student " + to_string(id_) + "\n");
    for (Grade *grade: other.grades_) {
        grades_.push_back(new Grade(*grade));
    }
}

// Assignment operator
Student &Student::operator=(const Student &other) {
    Logger::instance().log("Assigning student " + to_string(id_) + " to " + to_string(other.id_) + "\n");
    if (this != &other) {
        id_ = other.id_;
        name_ = other.name_;
        for (Grade *grade: grades_) {
            delete grade;
        }
        grades_.clear();
        for (Grade *grade: other.grades_) {
            grades_.push_back(new Grade(*grade));
        }
    }

    return *this;
}
// Mutators

void Student::addGrade(Grade *grade) {
    grades_.push_back(grade);
}

// Helper functions
int Student::calculateFinal() const {
    int totalPoints = 0;
    int pointsEarned = 0;
    double weightTotal = 0;
    for (Grade *grade: grades_) {
        totalPoints += grade->getTotalPoints();
        pointsEarned += grade->getPointsEarned();
        weightTotal += grade->getWeight();
    }

    double finalGrade = static_cast<double>(pointsEarned) / totalPoints;
    double weightedGrade = finalGrade * weightTotal;

    int finalGradePercent = lround(weightedGrade * 100.0);


    Logger::instance().log(
            "Calculating final grade for student " + to_string(id_) + ": " + to_string(finalGradePercent));
    return finalGradePercent;
}

string Student::calculateLetterGrade() const {
    int finalGrade = calculateFinal();
    Logger::instance().log("Calculating final letter grade for student " + to_string(id_));
    if (finalGrade >= 90) {
        return "A";
    } else if (finalGrade < 90 && finalGrade >= 80) {
        return "B";
    } else if (finalGrade < 80 && finalGrade >= 70) {
        return "C";
    } else if (finalGrade < 70 && finalGrade >= 60) {
        return "D";
    } else {
        return "F";
    }
}

string Student::printReport() const {
    string report = "Student ID: " + to_string(id_) + "\n";
    report += "Name: " + name_ + "\n";
    report += "Grades:\n";
    for (Grade *grade: grades_) {
        report += "\t" + grade->getAssignment() + ": " + to_string(grade->getPointsEarned()) + "/" +
                  to_string(grade->getTotalPoints()) + "\n";
    }
    report += "Final grade: " + to_string(calculateFinal()) + " (" + calculateLetterGrade() + ")\n";
    Logger::instance().log("Printing report for student " + to_string(id_));
    return report;
}