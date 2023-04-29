//
// Created by Georg on 4/10/2023.
//


#include "HospitalAdmin.h"

void HospitalAdmin::printTriageReport(const vector<Patient> &triageVector) {
    string ailements;
    Logger::instance().log("Triage Report:\n");
    cout << "Printing all Triage Patients: " << endl;
    if (triageVector.empty()) {
        cout << "No patients in triage!" << endl;
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

void HospitalAdmin::addPatientsByFile(vector<Patient> &untreatedPatients, vector<Patient> &treatedPatients) {
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
                if (addedPatient.treated == true){
                    treatedPatients.push_back(addedPatient);
                }
                else{
                    untreatedPatients.push_back(addedPatient);
                    createdPatients.push_back(addedPatient);
                    addedPatient = Patient();
                }

            }
        } else {
            istringstream iss(line);
            string key, value;
            getline(iss, key, ':');
            getline(iss, value);

            map<string, function<void(string)>> setter = {
                    {"firstName",  [&](const string &val) { addedPatient.firstName = val; }},
                    {"middleName", [&](const string &val) { addedPatient.middleName = val; }},
                    {"lastName",   [&](const string &val) { addedPatient.lastName = val; }},
                    {"suffix",     [&](const string &val) { addedPatient.suffix = val; }},
                    {"ailment",    [&](const string &val) { addedPatient.ailments.push_back(val); }},
                    {"doctor",     [&](const string &val) { addedPatient.doctor = val; }},
                    {"treated",    [&](const string &val) { addedPatient.treated = (val == "1"); }},
                    {"priority",   [&](const string &val) { addedPatient.priority = stoi(val); }}
            };

            if (setter.find(key) != setter.end()) {
                setter[key](value);
            }
        }
    }
    if (!addedPatient.firstName.empty() || !addedPatient.lastName.empty()) {
        if (addedPatient.treated == true){
            treatedPatients.push_back(addedPatient);
        }
        else{
            untreatedPatients.push_back(addedPatient);
            createdPatients.push_back(addedPatient);
            addedPatient = Patient();
        }
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

        cout << "firstName:" + patient.firstName + "\nlastName: " + patient.lastName << endl;

        Logger::instance().log("firstName:" + patient.firstName
                               + "\nmiddleName: " + patient.middleName
                               + "\nlastName: " + patient.lastName
                               + "\nSuffix: " + patient.suffix
                               + "\nDoctor: " + patient.doctor
                               + "\nTreated: " + to_string(patient.treated)
                               + "\nSymptoms: " + aliments
                               + "\nPriority: " + to_string(patient.priority));
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
    string aliments, doctorName, lowercasePatientDoctor;

    cout << "Enter the name of the doctor: " << endl;
    getline(cin, doctorName);

    transform(doctorName.begin(), doctorName.end(), doctorName.begin(), ::tolower);


    cout << "Patients by Doctor Report created" << endl;
    Logger::instance().log("Patients by doctor report created");

    for (const auto &patient: untreatedPatients) {
        lowercasePatientDoctor = patient.doctor;
        transform(lowercasePatientDoctor.begin(), lowercasePatientDoctor.end(), lowercasePatientDoctor.begin(),
                  ::tolower);
        if (lowercasePatientDoctor == doctorName) {
            patientsSortedByDoctor[patient.doctor].push_back(patient);
        }
    }
    for (const auto &patient: treatedPatients) {
        lowercasePatientDoctor = patient.doctor;
        transform(lowercasePatientDoctor.begin(), lowercasePatientDoctor.end(), lowercasePatientDoctor.begin(),
                  ::tolower);
        if (lowercasePatientDoctor == doctorName) {
            patientsSortedByDoctor[patient.doctor].push_back(patient);
        }
    }
    if (patientsSortedByDoctor.empty()) {
        cout << "Doctor not found" << endl;
        Logger::instance().log("Doctor not found");
        return;
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
                                       + "\nmiddleName: " + patient.middleName
                                       + "\nlastName: " + patient.lastName
                                       + "\nSuffix: " + patient.suffix
                                       + "\nDoctor: " + patient.doctor
                                       + "\nTreated: " + to_string(patient.treated)
                                       + "\nSymptoms: " + aliments
                                       + "\nPriority: " + to_string(patient.priority));
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
