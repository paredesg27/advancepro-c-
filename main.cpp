#include <iostream>
#include <vector>

using namespace std;

enum string_code {
    eAdd,
    eTreat,
    ePrintPatient,
    ePrintAllTreatedPatients,
    eNextPatient,
    ePrintAllTriagePatients,
    eYouAreGod,
    ePrintPatientsByDoctor,
    eAddPatientByFile,
    eLogNormal,
    eDebugMode,
    eLogDebug,
    eHelp

};

string_code hashit(string const &inString) {
    if (inString == "add") return eAdd;
    if (inString == "treat") return eTreat;
    if (inString == "print patient") return ePrintPatient;
    if (inString == "print all treated patients") return ePrintAllTreatedPatients;
    if (inString == "next patient") return eNextPatient;
    if (inString == "print all triage patients") return ePrintAllTriagePatients;
    if (inString == "god") return eYouAreGod;
    if (inString == "print patients by doctor") return ePrintPatientsByDoctor;
    if (inString == "add patient by file") return eAddPatientByFile;
    if (inString == "log in normal mode") return eLogNormal;
    if (inString == "debug mode") return eDebugMode;
    if (inString == "log in debug mode") return eLogDebug;
    if (inString == "help") return eHelp;

}

int main() {
    string inputString;
    cout << "Enter an option(help for list of options and done to stop):" << endl;
    while ((cin >> inputString) && inputString != "done") {
        switch (hashit(inputString)) {
            case eAdd: {
                cout << "adding patient" << endl;
                break;
            }

            case eTreat: {
                cout << "treating patient at top of triage order" << endl;
                break;
            }
            case ePrintPatient: {
                cout << "printing patient x" << endl;
                break;
            }

            case ePrintAllTreatedPatients: {
                cout << "Print all treated Patients" << endl;
                break;
            }
            case eNextPatient: {
                cout << "Printing next patient" << endl;
                break;
            }

            case ePrintAllTriagePatients: {
                cout << "Print all triage patients" << endl;
                break;
            }
            case eYouAreGod: {
                cout << "Healed the world" << endl;
                break;
            }

            case ePrintPatientsByDoctor: {
                cout << "Printing patients by Doctor x" << endl;
                break;
            }
            case eAddPatientByFile: {
                cout << "adding patients by file x" << endl;
                break;
            }

            case eLogNormal: {
                cout << "Set logging to file, normal mode" << endl;
                break;
            }
            case eDebugMode: {
                cout << "Set to debug mode" << endl;
                break;
            }

            case eLogDebug: {
                cout << "Set logging to console, debug mode" << endl;
                break;
            }
            case eHelp: {
                cout << "Here are all the accepted inputted values and their functions: " << endl;

                cout << "add:\n to add a patient to system " << endl;
                cout << "treat:\n treat a patient in triage order " << endl;
                cout << "print patient:\n prints out a specific patient report" << endl;
                cout << "print all treated patients:\n prints out all treated patients  " << endl;
                cout << "next patient:\n prints out the next  " << endl;
                cout << "Here are all the accepted inputted values and their functions: " << endl;
                cout << "Here are all the accepted inputted values and their functions: " << endl;
                cout << "Here are all the accepted inputted values and their functions: " << endl;
                cout << "Here are all the accepted inputted values and their functions: " << endl;
                cout << "Here are all the accepted inputted values and their functions: " << endl;
                cout << "Here are all the accepted inputted values and their functions: " << endl;
                cout << "Here are all the accepted inputted values and their functions: " << endl;

                break;
            }


        }
    }
    return 0;
}
