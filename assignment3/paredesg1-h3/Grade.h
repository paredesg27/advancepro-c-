//
// Created by George on 2/25/2023.
//

#ifndef PAREDESG1_H3_GRADE_H
#define PAREDESG1_H3_GRADE_H

#include "string"

using namespace std;

class Grade {
public:
    Grade(int pointsEarned, int totalPoints, double weight, const string &assignment);

    int getPointsEarned() const ;

    int getTotalPoints() const ;

    double getWeight() const ;

    string getAssignment() const ;

    void setPointsEarned(int pointsEarned) ;

    void setTotalPoints(int totalPoints);

    void setWeight(double weight) ;

    void setAssignment(const string &assignment) ;

private:
    int points_earned;
    int total_points;
    double weight_grade;
    string assignment_grade;


};

#endif //PAREDESG1_H3_GRADE_H