//
// Created by George on 2/25/2023.
//

#ifndef PAREDESG1_H3_STUDENT_H
#define PAREDESG1_H3_STUDENT_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "logger.h" // assuming logger is defined in logger.h
#include "Grade.h"


class Student {
public:
    // Constructor
    Student(int id, const string &name) :
            id_(id),
            name_(name) {}

    // Destructor
    ~Student() {
        Logger::instance().log("Destroying student " + to_string(id_) + "\n");
        for (Grade *grade: grades_) {
            delete grade;
        }
    }

    // Copy constructor
    Student(const Student &other) :
            id_(other.id_),
            name_(other.name_) {
        Logger::instance().log("Copying student " + to_string(id_) + "\n");
        for (Grade *grade: other.grades_) {
            grades_.push_back(new Grade(*grade));
        }
    }

    // Assignment operator
    Student &operator=(const Student &other) {
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

    // Accessors
    int getId() const {
        Logger::instance().log("Getting Student ID\n");
        return id_;
    }

    const string &getName() const {
        Logger::instance().log("Getting Student Name\n");
        return name_;
    }

    const vector<Grade *> &getGrades() const {
        Logger::instance().log("Getting Student Grades\n");
        return grades_;
    }

    // Mutators
    void setName(const string &name) {
        Logger::instance().log("Setting Student Name\n");
        name_ = name;
    }

    void addGrade(Grade *grade) {
        grades_.push_back(grade);
    }

    // Helper functions
    int calculateFinal() const {
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

        int finalGradePercent = weightedGrade * 100.0 + 0.5;


        Logger::instance().log(
                "Calculating final grade for student " + to_string(id_) + ": " + to_string(finalGradePercent));
        return finalGradePercent;
    }

    string calculateLetterGrade() const {
        int finalGrade = calculateFinal();
        Logger::instance().log("Calculating final letter grade for student " + to_string(id_));
        if (finalGrade <= 100 && finalGrade >= 90) {
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

    string printReport() const {
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

private:
    int id_;
    string name_;
    vector<Grade *> grades_;
};


#endif //PAREDESG1_H3_STUDENT_H
