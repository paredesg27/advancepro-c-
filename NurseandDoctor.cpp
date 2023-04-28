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

    cout << "Enter patient's suffix(Enter for blank):\n";
    string suffixInput;
    cin.ignore();
    getline(cin, suffixInput);
    if (!suffixInput.empty()) {
        newPatient.suffix = suffixInput;
    }

    cout << "Enter patient's ailments (type 'done' to finish):\n";
    string ailements;
    while (cin >> ailements && ailements != "done") {
        newPatient.ailments.push_back(ailements);
        cout << "Enter another ailment (type 'done' to finish):\n";
    }

    cout << "Enter patient's doctor:\n";
    cin >> newPatient.doctor;

    newPatient.treated = false;

    int number;
    cout << "Enter patient's priority:" << endl;
    while (!(cin >> number)) {
        cout << "Invalid input. Please enter an integer value.\n" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    newPatient.priority = number;

    patientList.push_back(newPatient);
    ailements = "{";
    for (const auto &ailment: newPatient.ailments) {
        ailements += ailment + ", ";
    }
    if (newPatient.ailments.empty()) {
        ailements += "}";
    } else {
        ailements[ailements.length() - 2] = '}';
    }
    cout << "Added Patient: " + newPatient.firstName + " " + newPatient.lastName << endl;
    Logger::instance().log("Added Patient with the following info \n");
    Logger::instance().log("firstName:" + newPatient.firstName
                           + "\nmiddleName: " + newPatient.middleName
                           + "\nlastName: " + newPatient.lastName
                           + "\nSuffix: " + newPatient.suffix
                           + "\nDoctor: " + newPatient.doctor
                           + "\nTreated: " + to_string(newPatient.treated)
                           + "\nSymptoms: " + ailements
                           + "\nPriority: " + to_string(newPatient.priority));

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
    cout << "Treated " + highestPriority.firstName + " " + highestPriority.lastName + " with priorty of " +
            to_string(highestPriority.priority) << endl;
    Logger::instance().log("Treated " + highestPriority.firstName + highestPriority.lastName + "with priorty of " +
                           to_string(highestPriority.priority));
}

void NurseandDoctor::printPatientReport(vector<Patient> &untreatedPatientList, vector<Patient> &treatedPatientList) {
    string firstName;
    string middleName;
    string lastName;
    string doctor;
    bool patinetFound = false;
    string aliments;

    cout << "Enter patient's first name:\n";
    cin >> firstName;

    cout << "Enter patient's middle name:\n";
    cin >> middleName;

    cout << "Enter patient's last name:\n";
    cin >> lastName;
    cout << "Enter patient's Doctor:\n";
    cin >> doctor;

    cout << "Printing out Patient" + firstName + " " + lastName << endl;
    Logger::instance().log("Printing out Patient" + firstName + " " + lastName);

    for (auto &patient: untreatedPatientList) {
        if (patient.firstName == firstName && patient.middleName == middleName && patient.lastName == lastName &&
            patient.doctor == doctor) {
            patinetFound = true;
            aliments = "{";
            for (const auto &ailment: patient.ailments) {
                aliments += ailment + ", ";
            }
            if (patient.ailments.empty()) {
                aliments += "}";
            } else {
                aliments[aliments.length() - 2] = '}';
            }
            aliments += "}";
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

    // Search untreated patients
    for (auto &patient: treatedPatientList) {
        if (patient.firstName == firstName && patient.middleName == middleName && patient.lastName == lastName &&
            patient.doctor == doctor) {
            patinetFound = true;
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
    if (patinetFound == false) {
        Logger::instance().log("Patient Search results in not found");
        cout << "Patient Not Found, try again" << endl;
    }
}

void NurseandDoctor::printTreatedPatients(vector<Patient> &treatedPatientList) {
    string aliments;
    cout << "Printing All Treated Patients" << endl;
    Logger::instance().log("Print All Treated Patients\n");
    // Search treated patients
    for (auto &patient: treatedPatientList) {
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

void NurseandDoctor::nextPatient(vector<Patient> &untreatedPatientList) {
    string aliments;
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
    aliments = "{";
    for (const auto &ailment: untreatedPatientList[highestPriorityIndex].ailments) {
        aliments += ailment + ", ";
    }
    if (highestPriority.ailments.empty()) {
        aliments += "}";
    } else {
        aliments[aliments.length() - 2] = '}';
    }
    cout << "Next Patient to be treated is:\n"
            "firstName:" + untreatedPatientList[highestPriorityIndex].firstName
            + "\nmiddleName: " + untreatedPatientList[highestPriorityIndex].middleName
            + "\nlastName: " + untreatedPatientList[highestPriorityIndex].lastName
            + "\nSuffix: " + untreatedPatientList[highestPriorityIndex].suffix
            + "\nDoctor: " + untreatedPatientList[highestPriorityIndex].doctor
            + "\nTreated: " + to_string(untreatedPatientList[highestPriorityIndex].treated)
            + "\nSymptoms: " + aliments
            + "\nPriority: " + to_string(untreatedPatientList[highestPriorityIndex].priority) << endl;

    Logger::instance().log("Next Patient to be treated is: \n"
                           "firstName:" + untreatedPatientList[highestPriorityIndex].firstName
                           + "\nmiddleName: " + untreatedPatientList[highestPriorityIndex].middleName
                           + "\nlastName: " + untreatedPatientList[highestPriorityIndex].lastName
                           + "\nSuffix: " + untreatedPatientList[highestPriorityIndex].suffix
                           + "\nDoctor: " + untreatedPatientList[highestPriorityIndex].doctor
                           + "\nTreated: " + to_string(untreatedPatientList[highestPriorityIndex].treated)
                           + "\nSymptoms: " + aliments
                           + "\nPriority: " + to_string(untreatedPatientList[highestPriorityIndex].priority));
}


