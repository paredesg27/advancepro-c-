#include <iostream>
#include <vector>
#include <unordered_map>
#include "HospitalAdmin.h"
#include "NurseandDoctor.h"

using namespace std;

enum class string_code {
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
    eHelp,
    eUnknown,
    eDone

};

string_code hashit(string const &inString) {
    static const unordered_map<string, string_code> commands{
            {"add",                        string_code::eAdd},
            {"treat",                      string_code::eTreat},
            {"print patient",              string_code::ePrintPatient},
            {"print all treated patients", string_code::ePrintAllTreatedPatients},
            {"next patient",               string_code::eNextPatient},
            {"print all triage patients",  string_code::ePrintAllTriagePatients},
            {"god",                        string_code::eYouAreGod},
            {"print patients by doctor",   string_code::ePrintPatientsByDoctor},
            {"add patient by file",        string_code::eAddPatientByFile},
            {"log in normal mode",         string_code::eLogNormal},
            {"debug mode",                 string_code::eDebugMode},
            {"log in debug mode",          string_code::eLogDebug},
            {"help",                       string_code::eHelp},
            {"done",                       string_code::eDone}
    };

    auto iter = commands.find(inString);
    if (iter != commands.end()) {
        return iter->second;
    } else {
        return string_code::eUnknown;
    }
}

int main() {
    vector<Patient> unTreatedPatients;
    vector<Patient> treatedPatients;
    string inputString = "help";
    bool loop = true;
    while (loop) {
        cout << "Enter an option(type 'help' for a list of options and 'done' to stop):" << endl;
        getline(cin, inputString);
        switch (hashit(inputString)) {
            case string_code::eAdd: {
                NurseandDoctor::addPatient(unTreatedPatients);
                break;
            }//bug causes it to go twice

            case string_code::eTreat: {
                NurseandDoctor::treatPatientHighestPriority(unTreatedPatients, treatedPatients);
                break;
            }//done
            case string_code::ePrintPatient: {
                NurseandDoctor::printPatientReport(unTreatedPatients, treatedPatients);
                break;//done
            }

            case string_code::ePrintAllTreatedPatients: {
                NurseandDoctor::printTreatedPatients(treatedPatients);
                break;
            }//done
            case string_code::eNextPatient: {
                NurseandDoctor::nextPatient(unTreatedPatients);
                break;
            }//done

            case string_code::ePrintAllTriagePatients: {
                HospitalAdmin::printTriageReport(unTreatedPatients);
                break;
            }//done
            case string_code::eYouAreGod: {
               HospitalAdmin::youAreGod(unTreatedPatients, treatedPatients);
                break;
            }//done

            case string_code::ePrintPatientsByDoctor: {
                HospitalAdmin::printPatientsByDoctor(unTreatedPatients, treatedPatients);
                break;
            }//done
            case string_code::eAddPatientByFile: {
                HospitalAdmin::addPatientsByFile(unTreatedPatients);
                break;
            }//done

            case string_code::eLogNormal: {
                Logger::loggingNormal();
                break;
            }
            case string_code::eDebugMode: {
                Logger::setDebug();
                break;//done
            }

            case string_code::eLogDebug: {
                Logger::loggingFile();
                break;
            }
            case string_code::eDone: {
                loop = false;
                break;
            }
            case string_code::eHelp: {
                cout << "\nHere are all the accepted inputted values and their functions(do not include \":\"):\n"
                     << endl;

                cout << "add:\n to add a patient to system\n" << endl;
                cout << "treat:\n treat a patient in triage order\n" << endl;
                cout << "print patient:\n prints out a specific patient report\n" << endl;
                cout << "print all treated patients:\n prints out all treated patients\n" << endl;
                cout << "next patient:\n prints out the next patient to be treated\n" << endl;
                cout << "print all triage patients:\n prints a report of all patients\n" << endl;
                cout << "god:\n YOU MAGICALLY HEAL ALL THE PATIENTS\n" << endl;
                cout << "print patients by doctor:\n prints out all patients of a doctor\n" << endl;
                cout << "add patient by file:\n insert a file of patients to be added\n" << endl;
                cout << "log in normal mode:\n logs system operations into a file in normal mode\n" << endl;
                cout << "debug mode:\n turns on debugging mode\n" << endl;
                cout << "log in debug mode:\n logs system operations to console in debug mode\n" << endl;
                break;
            }
            default: {
                cout << "\nError: \"" << inputString
                     << "\" is not a recognized command. Type \"help\" for a list of valid commands.\n" << endl;

                break;
            }
        }

    }


//    for (int i = 0; i < unTreatedPatients.size(); i++) {
//        cout << unTreatedPatients[i].firstName << " ";
//    }
    return 0;
}
