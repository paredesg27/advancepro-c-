//
// Created by Georg on 4/10/2023.
//


#include <limits>
#include "NurseandDoctor.h"

void NurseandDoctor::addPatient(vector<Patient> &patientList) {
    Patient newPatient;

    cout << "Enter patient's first name:\n";
    cin >> newPatient.firstName;

    cout << "Enter patient's middle name:\n";
    cin >> newPatient.middleName;

    cout << "Enter patient's last name:\n";
    cin >> newPatient.lastName;

    cout << "Enter patient's suffix:\n";
    cin >> newPatient.suffix;

    cout << "Enter patient's ailments (type 'done' to finish):\n";
    string ailment;
    while (cin >> ailment && ailment != "done") {
        newPatient.ailments.push_back(ailment);
        cout << "Enter another ailment (type 'done' to finish):\n";
    }

    cout << "Enter patient's doctor:\n";
    cin >> newPatient.doctor;

    newPatient.treated = false;

    int number;
    cout << "Enter patient's priority:\n" << endl;
    while (!(cin >> number)) {
        cout << "Invalid input. Please enter an integer value.\n" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    newPatient.priority = number;

    patientList.push_back(newPatient);

    Logger::instance().log("Patient added successfully.\n");

}

void NurseandDoctor::treatPatientHighestPriority(vector<Patient> &untreatedPatientList,
                                                 vector<Patient> &treatedPatientList) {
    if (untreatedPatientList.empty()) {
        Logger::instance().log("No patients to treat.");
        return;
    }
    Patient highestPriority = untreatedPatientList[0];
    int highestPriorityIndex = 0;
    for (int i = 0; i < untreatedPatientList.size(); i++) {
        if (untreatedPatientList[i].priority > highestPriority.priority) {
            highestPriority = untreatedPatientList[i];
            highestPriorityIndex = i;
        }
    }

    highestPriority.treated = true;
    treatedPatientList.push_back(highestPriority);
    untreatedPatientList.erase(untreatedPatientList.begin() + highestPriorityIndex);

    srand(time(nullptr));
    int sleepTime = rand() % 3 + 1;
    sleep(sleepTime);
    Logger::instance().log("Successfully treated highest priority patient.\n");
}

void NurseandDoctor::printPatientReport(vector<Patient> &untreatedPatientList, vector<Patient> &treatedPatientList) {
    string firstName;
    string middleName;
    string lastName;
    string doctor;
    bool patinetFound = false;
    string aliments = "{";

    cout << "Enter patient's first name:\n";
    cin >> firstName;

    cout << "Enter patient's middle name:\n";
    cin >> middleName;

    cout << "Enter patient's last name:\n";
    cin >> lastName;
    cout << "Enter patient's Doctor:\n";
    cin >> doctor;

    for (auto &patient: untreatedPatientList) {
        if (patient.firstName == firstName && patient.middleName == middleName && patient.lastName == lastName &&
            patient.doctor == doctor) {
            patinetFound = true;
            for (const auto &ailment: patient.ailments) {
                aliments = ailment + ", ";
            }
            aliments += "}";

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

    // Search untreated patients
    for (auto &patient: treatedPatientList) {
        if (patient.firstName == firstName && patient.middleName == middleName && patient.lastName == lastName &&
            patient.doctor == doctor) {
            patinetFound = true;
            for (const auto &ailment: patient.ailments) {
                aliments = ailment + ", ";
            }
            aliments += "}";

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
    if (patinetFound == false) {
        Logger::instance().log("Patient Search results in not found");
        cout << "Patient Not Found, try again" << endl;
    }
}

void NurseandDoctor::printTreatedPatients(vector<Patient> &treatedPatientList) {
    string aliments = "{";
    // Search treated patients
    for (auto &patient: treatedPatientList) {
        for (const auto &ailment: patient.ailments) {
            aliments = ailment + ", ";
        }
        aliments += "}";

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

void NurseandDoctor::nextPatient(vector<Patient> &untreatedPatientList) {
    string aliments = "{";
    if (untreatedPatientList.empty()) {
        Logger::instance().log("No patients.");
        return;
    }
    Patient highestPriority = untreatedPatientList[0];
    int highestPriorityIndex = 0;
    int i = 0;
    for (; i < untreatedPatientList.size(); i++) {
        if (untreatedPatientList[i].priority > highestPriority.priority) {
            highestPriority = untreatedPatientList[i];
            highestPriorityIndex = i;
        }
    }
    for (const auto &ailment: untreatedPatientList[i].ailments) {
        aliments = ailment + ", ";
    }
    aliments += "}";

    Logger::instance().log("Next Patient to be treated is: \n"
                           "firstName:" + untreatedPatientList[i].firstName
                           + "\n middleName: " + untreatedPatientList[i].middleName
                           + "\nlastName: " + untreatedPatientList[i].lastName
                           + "\nSuffix: " + untreatedPatientList[i].suffix
                           + "\nDoctor: " + untreatedPatientList[i].doctor
                           + "\nTreated: " + to_string(untreatedPatientList[i].treated)
                           + "\n Symptoms: " + aliments
                           + "\n Priority: " + to_string(untreatedPatientList[i].priority));
}


