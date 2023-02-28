//
// Created by Georg on 2/22/2023.
//

#ifndef PAREDESG1_H3_MAIN_H
#define PAREDESG1_H3_MAIN_H


using namespace std;
class Singleton{
    class Grade {
    private:
        int pointsEarned;
        int totalPoints;
        double weight;
        string assignment;
    public:
        Grade(int pointsE, int totalP, double weightGrade, string assignmentName): pointsEarned(pointsE), totalPoints(totalP), weight(weightGrade), assignment(assignmentName){}
    };
    class Student {

    private:
        int id;
        string name;
        vector<Grade*> Grades;
        int assignmentGrade;

    public:
        Student(int sid, string sname, vector<> sgrades): id(sid), name(sname), Grades(sgrades){}

        int calculateFinal() {
            int assignmentPoints = Grades[1];
            int assignmentPointsEarned = Grades[0];
            assignmentGrade = assignmentPointsEarned/assignmentPoints;

            return assignmentGrade;
        }

        string calculateLetterGrade() {
            string grade;
            if (assignmentGrade<= 90 && assignmentGrade <= 100){
                grade = "A";
            }
            else if (assignmentGrade<= 80 && assignmentGrade < 90){
                grade = "B";
            }
            else if (assignmentGrade<= 70 && assignmentGrade < 80){
                grade = "C";
            }
            else if (assignmentGrade<= 60 && assignmentGrade < 70){
                grade = "D";
            }
            else if (assignmentGrade <= 50 && assignmentGrade < 60){
                grade = "F";
            }
            else{
                return "letter grade error";
            }


            return grade;

        }

        string printReport() {
            string report ="Student: "+ to_string(id) + ","  + name + to_string(assignmentGrade) + grade;

            return report;
        }
    };
    class Logger {
    private:

    public:
        void log(string outputs){
        cout>>outputs>>;
    }

    };
};




#endif //PAREDESG1_H3_MAIN_H
