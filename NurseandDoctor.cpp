//
// Created by Georg on 4/10/2023.
//



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
        cout << "Invalid input. Please enter an integer value." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    newPatient.priority = number;

    patientList.push_back(newPatient);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
    auto highestPriorityIter = max_element(untreatedPatientList.begin(), untreatedPatientList.end(), ComparePriority());
    Patient highestPriority = *highestPriorityIter;
    untreatedPatientList.erase(highestPriorityIter);

    highestPriority.treated = true;
    treatedPatientList.push_back(highestPriority);

    srand(time(nullptr));
    int sleepTime = rand() % 3 + 1;
    sleep(sleepTime);

    cout << "Treated " + highestPriority.firstName + " " + highestPriority.lastName + " with priorty of " +
            to_string(highestPriority.priority) << endl;
    Logger::instance().log("Treated " + highestPriority.firstName + highestPriority.lastName + "with priorty of " +
                           to_string(highestPriority.priority));
}

void NurseandDoctor::printPatientReport(vector<Patient> &untreatedPatientList, vector<Patient> &treatedPatientList) {
    string firstName, middleName, lastName, doctor, patientFirstName, patientMiddleName, patientLastName, patientDoctor;
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

    transform(firstName.begin(), firstName.end(), firstName.begin(), ::tolower);
    transform(middleName.begin(), middleName.end(), middleName.begin(), ::tolower);
    transform(lastName.begin(), lastName.end(), lastName.begin(), ::tolower);
    transform(doctor.begin(), doctor.end(), doctor.begin(), ::tolower);

    cout << "Printing out Patient " + firstName + " " + lastName << endl;
    Logger::instance().log("Printing out Patient " + firstName + " " + lastName);

    for (auto &patient: untreatedPatientList) {
        patientFirstName = patient.firstName;
        patientMiddleName = patient.middleName;
        patientLastName = patient.lastName;
        patientDoctor = patient.doctor;

        transform(patientFirstName.begin(), patientFirstName.end(), patientFirstName.begin(), ::tolower);
        transform(patientMiddleName.begin(), patientMiddleName.end(), patientMiddleName.begin(), ::tolower);
        transform(patientLastName.begin(), patientLastName.end(), patientLastName.begin(), ::tolower);
        transform(patientDoctor.begin(), patientDoctor.end(), patientDoctor.begin(), ::tolower);

        if (patientFirstName == firstName && patientMiddleName == middleName && patientLastName == lastName &&
            patientDoctor == doctor) {
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
        patientFirstName = patient.firstName;
        patientMiddleName = patient.middleName;
        patientLastName = patient.lastName;
        patientDoctor = patient.doctor;

        transform(patientFirstName.begin(), patientFirstName.end(), patientFirstName.begin(), ::tolower);
        transform(patientMiddleName.begin(), patientMiddleName.end(), patientMiddleName.begin(), ::tolower);
        transform(patientLastName.begin(), patientLastName.end(), patientLastName.begin(), ::tolower);
        transform(patientDoctor.begin(), patientDoctor.end(), patientDoctor.begin(), ::tolower);

        if (patientFirstName == firstName && patientMiddleName == middleName && patientLastName == lastName &&
            patientDoctor == doctor) {
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
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
        cout << "No Patients to treat!!" << endl;
        Logger::instance().log("No patients.");
        return;
    }

    auto it = std::max_element(untreatedPatientList.begin(), untreatedPatientList.end(), ComparePriority());
    int highestPriorityIndex = std::distance(untreatedPatientList.begin(), it);

    aliments = "{";
    for (const auto &ailment: untreatedPatientList[highestPriorityIndex].ailments) {
        aliments += ailment + ", ";
    }
    if (untreatedPatientList[highestPriorityIndex].ailments.empty()) {
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


