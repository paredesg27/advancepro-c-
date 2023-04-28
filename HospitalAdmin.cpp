//
// Created by Georg on 4/10/2023.
//

#include <sstream>
#include <map>
#include <functional>
#include "HospitalAdmin.h"

void HospitalAdmin::printTriageReport(const vector<Patient> &triageVector) {
    string ailements;
    Logger::instance().log("Triage Report:\n");
    cout << "Print all Triage Patients: " << endl;
    if (triageVector.empty()) {
        Logger::instance().log("No patients in triage\n");
        return;
    }

    for (const auto &patient: triageVector) {
        ailements = "{";
        for (const auto &ailment: patient.ailments) {
            ailements += ailment + ", ";
        }
        if (patient.ailments.empty()) {
            ailements += "}";
        } else {
            ailements[ailements.length() - 2] = '}';
        }

        cout << "firstName:" + patient.firstName
                + "\nmiddleName: " + patient.middleName
                + "\nlastName: " + patient.lastName
                + "\nSuffix: " + patient.suffix
                + "\nDoctor: " + patient.doctor
                + "\nTreated: " + to_string(patient.treated)
                + "\nSymptoms: " + ailements
                + "\nPriority: " + to_string(patient.priority) << endl;

        Logger::instance().log("firstName:" + patient.firstName
                               + "\nmiddleName: " + patient.middleName
                               + "\nlastName: " + patient.lastName
                               + "\nSuffix: " + patient.suffix
                               + "\nDoctor: " + patient.doctor
                               + "\nTreated: " + to_string(patient.treated)
                               + "\nSymptoms: " + ailements
                               + "\nPriority: " + to_string(patient.priority));

    }
}

void HospitalAdmin::addPatientsByFile(vector<Patient> &untreatedPatients) {
    string filename;
    string aliments;
    cout << "Enter the filename: " << endl;
    getline(cin, filename);

    ifstream file(filename, ios::in);

    if (!file.is_open()) {
        cout << "Error: could not open file " << filename << endl;
        Logger::instance().log("Error: could not open file " + filename);
        return;
    }
    vector<Patient> createdPatients;
    Patient addedPatient;
    string line;
    while (getline(file, line)) {
        if (line.empty()) {
            if (!addedPatient.firstName.empty() || !addedPatient.lastName.empty()) {
                untreatedPatients.push_back(addedPatient);
                createdPatients.push_back(addedPatient);
                addedPatient = Patient();
            }
        } else {
            istringstream iss(line);
            string key, value;
            getline(iss, key, ':');
            getline(iss, value);
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
                addedPatient.treated = (value == "true");
            } else if (key == "priority") {
                addedPatient.priority = stoi(value);
            }
        }
    }

    if (!addedPatient.firstName.empty() || !addedPatient.lastName.empty()) {
        untreatedPatients.push_back(addedPatient);
        createdPatients.push_back(addedPatient);
    }
    file.close();

    for (const auto &patient: createdPatients) {
        aliments = "{";
        for (const auto &ailment: patient.ailments) {
            aliments += ailment + ", ";
        }
        if (patient.ailments.empty()) {
            aliments += "}";
        } else {
            aliments[aliments.length() - 2] = '}';
        }

        cout << "firstName:" + patient.firstName
                + "\nlastName: " + patient.lastName
             << endl;

        Logger::instance().log("firstName:" + patient.firstName
                               + "\n middleName: " + patient.middleName
                               + "\nlastName: " + patient.lastName
                               + "\nSuffix: " + patient.suffix
                               + "\nDoctor: " + patient.doctor
                               + "\nTreated: " + to_string(patient.treated)
                               + "\n Symptoms: " + aliments
                               + "\n Priority: " + to_string(patient.priority));
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
    cout << "You healed all the triage patients!! SO MAGICAL" << endl;
    Logger::instance().log("User called good function\n");
}

void HospitalAdmin::printPatientsByDoctor(vector<Patient> &untreatedPatients, vector<Patient> &treatedPatients) {
    map<string, vector<Patient>> patientsSortedByDoctor;
    string aliments, doctorName;

    cout << "Enter the name of the doctor: "<<endl;
    getline(cin, doctorName);

    cout << "Patients by doctor report created" << endl;
    Logger::instance().log("Patients by doctor report created");

    for (const auto &patient: untreatedPatients) {
        if (patient.doctor == doctorName) {
            patientsSortedByDoctor[patient.doctor].push_back(patient);
        }
    }
    for (const auto &patient: treatedPatients) {
        if (patient.doctor == doctorName) {
            patientsSortedByDoctor[patient.doctor].push_back(patient);
        }
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
                    aliments += ailment + ", ";
                }
                if (patient.ailments.empty()) {
                    aliments += "}";
                } else {
                    aliments[aliments.length() - 2] = '}';
                }

                cout << "firstName:" + patient.firstName
                        + "\nmiddleName: " + patient.middleName
                        + "\nlastName: " + patient.lastName
                        + "\nSuffix: " + patient.suffix
                        + "\nDoctor: " + patient.doctor
                        + "\nTreated: " + to_string(patient.treated)
                        + "\nSymptoms: " + aliments
                        + "\nPriority: " + to_string(patient.priority) << endl;
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
                    aliments += ailment + ", ";
                }
                if (patient.ailments.empty()) {
                    aliments += "}";
                } else {
                    aliments[aliments.length() - 2] = '}';
                }
                cout << "firstName:" + patient.firstName
                        + "\nmiddleName: " + patient.middleName
                        + "\nlastName: " + patient.lastName
                        + "\nSuffix: " + patient.suffix
                        + "\nDoctor: " + patient.doctor
                        + "\nTreated: " + to_string(patient.treated)
                        + "\nSymptoms: " + aliments
                        + "\nPriority: " + to_string(patient.priority) << endl;

                Logger::instance().log("firstName:" + patient.firstName
                                       + "\nmiddleName: " + patient.middleName
                                       + "\nlastName: " + patient.lastName
                                       + "\nSuffix: " + patient.suffix
                                       + "\nDoctor: " + patient.doctor
                                       + "\nTreated: " + to_string(patient.treated)
                                       + "\nSymptoms: " + aliments
                                       + "\nPriority: " + to_string(patient.priority));
            }
        }
    }
}
