//
// Created by Georg on 2/22/2023.
//

#include "Grade.h"


Grade::Grade(int pointsEarned, int totalPoints, double weight, const string &assignment) :
        points_earned(pointsEarned),
        total_points(totalPoints),
        weight_grade(weight),
        assignment_grade(assignment) {}

int Grade::getPointsEarned() const {
    return points_earned;
}

int Grade::getTotalPoints() const {
    return total_points;
}

double Grade::getWeight() const {
    return weight_grade;
}

 string Grade::getAssignment() const {
    return assignment_grade;
}

void Grade::setPointsEarned(int pointsEarned) {
    points_earned = pointsEarned;
}

void Grade::setTotalPoints(int totalPoints) {
    total_points = totalPoints;
}

void Grade::setWeight(double weight) {
    weight_grade = weight;
}

void Grade::setAssignment(const string &assignment) {
    assignment_grade = assignment;
}