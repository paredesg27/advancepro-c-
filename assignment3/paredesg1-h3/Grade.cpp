//
// Created by George on 2/25/2023.
//

#ifndef PAREDESG1_H3_GRADE_H
#define PAREDESG1_H3_GRADE_H

#include "string"

using namespace std;

class Grade {
public:
    Grade(int pointsEarned, int totalPoints, double weight, const string &assignment) :
            points_earned(pointsEarned),
            total_points(totalPoints),
            weight_grade(weight),
            assignment_grade(assignment) {}

    int getPointsEarned() const {
        return points_earned;
    }

    int getTotalPoints() const {
        return total_points;
    }

    double getWeight() const {
        return weight_grade;
    }

    const string &getAssignment() const {
        return assignment_grade;
    }

    void setPointsEarned(int pointsEarned) {
        points_earned = pointsEarned;
    }

    void setTotalPoints(int totalPoints) {
        total_points = totalPoints;
    }

    void setWeight(double weight) {
        weight_grade = weight;
    }

    void setAssignment(const string &assignment) {
        assignment_grade = assignment;
    }

private:
    int points_earned;
    int total_points;
    double weight_grade;
    string assignment_grade;


};

#endif //PAREDESG1_H3_GRADE_H
