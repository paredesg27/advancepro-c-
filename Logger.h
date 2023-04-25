//
// Created by Georg on 4/10/2023.
//

#ifndef HOSPITALADMIN_LOGGER_H
#define HOSPITALADMIN_LOGGER_H
//
#include <iostream>
#include <fstream>

using namespace std;

class Logger {
private:
    static bool debugMode;
    static string fileName;
public:
    static Logger &instance() {
        static Logger logger;
        return logger;
    }

    static void setDebug() {
        debugMode = !debugMode;
        cout<<"debug is:" + debugMode <<endl;
    }
    static void loggingNormal(){
        debugMode = false;
        cout<<"Set logging in normal mode" <<endl;
    }
    static void loggingFile(){
        debugMode = true;
        cout<<"Set logging in debug mode" <<endl;
    }

    static void log(const string &message) {

        if (debugMode) {
            cout << message << "IN DEBUG" << endl;
        } else {

            ofstream logFile(fileName, ios::app);
            logFile.open(fileName, ios::app);
            if (logFile.is_open()) {
                logFile << message << endl;
                logFile.close();
            } else {
                cout << "Error: Failed to open log file " << fileName << endl;
            }

        }

    }

    Logger(const Logger &) = delete;

    Logger &operator=(const Logger &) = delete;


    Logger() = default;
};


#endif //HOSPITALADMIN_LOGGER_H
