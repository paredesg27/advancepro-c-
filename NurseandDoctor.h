//
// Created by Georg on 4/10/2023.
//

#ifndef HOSPITALADMIN_NURSEANDDOCTOR_H
#define HOSPITALADMIN_NURSEANDDOCTOR_H

#include <string>
#include <vector>
#include <unistd.h>
#include <iostream>
#include "Logger.h"

using namespace std;
struct Patient {
    string firstName;
    string middleName;
    string lastName;
    string suffix;
    vector<string> ailments;
    string doctor;
    bool treated;
    int priority;
};

class NurseandDoctor {
private:


public:
    static void addPatient(vector<Patient>& patientList);

    static void treatPatientHighestPriority(vector<Patient> &untreatedPatientList,vector<Patient> &treatedPatientList);

    static void printPatientReport(vector<Patient> &untreatedPatientList, vector<Patient> &treatedPatientList);

    static void printTreatedPatients(vector<Patient> &treatedPatientList);

    static void nextPatient(vector<Patient> &untreatedPatientList);

};


#endif //HOSPITALADMIN_NURSEANDDOCTOR_H
