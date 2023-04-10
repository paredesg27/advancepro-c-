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
     static void setDebug(bool debug){
        debugMode = debug;
    }

    static void log(const string &message) {

        if (debugMode){
            cout << message<<"IN DEBUG" << endl;
        } else{
            cout << message << endl;
            ofstream logFile;
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
bool Logger::debugMode = false;
string Logger::fileName = "log.txt";


#endif //HOSPITALADMIN_LOGGER_H
