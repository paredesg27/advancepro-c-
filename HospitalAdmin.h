//
// Created by Georg on 4/10/2023.
//

#ifndef HOSPITALADMIN_HOSPITALADMIN_H
#define HOSPITALADMIN_HOSPITALADMIN_H

#include <variant>
#include <sstream>
#include <map>
#include <functional>
#include "NurseandDoctor.h"


class HospitalAdmin {
private:

public:
    static void printTriageReport(const vector<Patient> &triageVector);

    static void addPatientsByFile(vector<Patient> &untreatedPatients, vector<Patient> &treatedPatients);

    static void youAreGod(vector<Patient> &untreatedPatients, vector<Patient> &treatedPatients);

    static void printPatientsByDoctor(vector<Patient> &untreatedPatients, vector<Patient> &treatedPatients);
};


#endif //HOSPITALADMIN_HOSPITALADMIN_H
