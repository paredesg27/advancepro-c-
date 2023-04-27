//
// Created by Georg on 4/10/2023.
//

#include <sstream>
#include <map>
#include "HospitalAdmin.h"

void HospitalAdmin::printTriageReport(const vector<Patient> &triageVector) {
    string ailements = "{";
    Logger::instance().log("Triage Report:\n");
    if (triageVector.empty()) {
        Logger::instance().log("No patients in triage\n");
        return;
    }

    for (const auto &patient: triageVector) {
        for (const auto &ailment: patient.ailments) {
            ailements = ailment + ", ";
        }
        ailements += "}";

        Logger::instance().log("firstName:" + patient.firstName
                               + "\n middleName: " + patient.middleName
                               + "\nlastName: " + patient.lastName
                               + "\nSuffix: " + patient.suffix
                               + "\nDoctor: " + patient.doctor
                               + "\nTreated: " + to_string(patient.treated)
                               + "\n Symptoms: " + ailements
                               + "\n Priority: " + to_string(patient.priority));

    }
}

void HospitalAdmin::addPatientsByFile(vector<Patient> &untreatedPatients) {
    string filename;
    cout << "Enter the filename: " << endl;
    getline(cin, filename);
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: could not open file " << filename << endl;
        Logger::instance().log("Error: could not open file " + filename);
        return;
    }
    vector<Patient> filePatients;
    Patient addedPatient;

    string line;
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string key, value;
        std::getline(ss, key, ':');
        std::getline(ss, value);

        if (key == "firstName") {
            addedPatient.firstName = value;
        } else if (key == "middleName") {
            addedPatient.middleName = value;
        } else if (key == "lastName") {
            addedPatient.lastName = value;
        } else if (key == "suffix") {
            addedPatient.suffix = value;
        } else if (key == "ailment") {
            addedPatient.ailments.push_back(value);
        } else if (key == "doctor") {
            addedPatient.doctor = value;
        } else if (key == "treated") {
            addedPatient.treated = (value == "1");
        } else if (key == "priority") {
            addedPatient.priority = std::stoi(value);
        }

        if (line.empty() && (!addedPatient.firstName.empty() || !addedPatient.lastName.empty())) {
            untreatedPatients.push_back(addedPatient);
            addedPatient = Patient();
        }

    }
    cout << "Added patients from file: " << filename << endl;
    Logger::instance().log("Added patients from file: " + filename);
}

void HospitalAdmin::youAreGod(vector<Patient> &untreatedPatients, vector<Patient> &treatedPatients) {
    int i = 0;
    for (auto &patient: untreatedPatients) {
        patient.treated = true;
        treatedPatients.push_back(patient);
        untreatedPatients.erase(untreatedPatients.begin() + i);
        i++;
    }
}

void HospitalAdmin::printPatientsByDoctor(vector<Patient> &untreatedPatients, vector<Patient> &treatedPatients) {
    map<string, vector<Patient>> patientsSortedByDoctor;
    string aliments;

    for (const auto &patient: untreatedPatients) {
        patientsSortedByDoctor[patient.doctor].push_back(patient);
    }
    for (const auto &patient: treatedPatients) {
        patientsSortedByDoctor[patient.doctor].push_back(patient);
    }

    for (const auto &[doctor, patients]: patientsSortedByDoctor) {
        cout << "Doctor: " << doctor << endl;
        Logger::instance().log("Doctor: " + doctor);
        cout << "Untreated patients:" << endl;
        Logger::instance().log("\nUntreated patients:\n");
        for (const auto &patient: patients) {
            if (!patient.treated) {


                aliments = "{";
                for (const auto &ailment: patient.ailments) {
                    aliments = ailment + ", ";
                }
                aliments += "}";

                cout << "firstName:" + patient.firstName
                        + "\n middleName: " + patient.middleName
                        + "\nlastName: " + patient.lastName
                        + "\nSuffix: " + patient.suffix
                        + "\nDoctor: " + patient.doctor
                        + "\nTreated: " + to_string(patient.treated)
                        + "\n Symptoms: " + aliments
                        + "\n Priority: " + to_string(patient.priority) << endl;
                Logger::instance().log("firstName:" + patient.firstName
                                       + "\n middleName: " + patient.middleName
                                       + "\nlastName: " + patient.lastName
                                       + "\nSuffix: " + patient.suffix
                                       + "\nDoctor: " + patient.doctor
                                       + "\nTreated: " + to_string(patient.treated)
                                       + "\n Symptoms: " + aliments
                                       + "\n Priority: " + to_string(patient.priority));
            }
        }
        cout << "Treated patients:" << endl;
        Logger::instance().log("Treated patients:");
        for (const auto &patient: patients) {
            if (patient.treated) {
                aliments = "{";
                for (const auto &ailment: patient.ailments) {
                    aliments = ailment + ", ";
                }
                aliments += "}";
                cout << "firstName:" + patient.firstName
                        + "\n middleName: " + patient.middleName
                        + "\nlastName: " + patient.lastName
                        + "\nSuffix: " + patient.suffix
                        + "\nDoctor: " + patient.doctor
                        + "\nTreated: " + to_string(patient.treated)
                        + "\n Symptoms: " + aliments
                        + "\n Priority: " + to_string(patient.priority) << endl;

                Logger::instance().log("firstName:" + patient.firstName
                                       + "\n middleName: " + patient.middleName
                                       + "\nlastName: " + patient.lastName
                                       + "\nSuffix: " + patient.suffix
                                       + "\nDoctor: " + patient.doctor
                                       + "\nTreated: " + to_string(patient.treated)
                                       + "\n Symptoms: " + aliments
                                       + "\n Priority: " + to_string(patient.priority));
            }
        }
        cout << "Patients by doctor report created" << endl;
        Logger::instance().log("Patients by doctor report created");

    }
}
