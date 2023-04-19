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
    cout << "Enter patient's priority:\n";
    while (!(cin >>number)){
        cout << "Invalid input. Please enter an integer value.\n";
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

