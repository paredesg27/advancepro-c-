//
// Created by Georg on 4/10/2023.
//

#include "HospitalAdmin.h"
void HospitalAdmin::printTriageReport(const vector<Patient> &triageVector) {
    string ailements = "{";
    Logger::instance().log("Triage Report:\n");
    if (triageVector.empty()) {
        Logger::instance().log("No patients in triage\n");
        return;
    }

    for (const auto& patient : triageVector) {
        for (const auto& ailment: patient.ailments) {
            ailements = ailment + ", ";
        }
        ailements += "}";

        Logger::instance().log("Name:" + patient.firstName
        + "\n Priority: " + to_string(patient.priority)
        + "\n Symptoms: " + ailements);

    }
}
