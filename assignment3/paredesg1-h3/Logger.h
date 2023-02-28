//
// Created by George on 2/25/2023.
//

#ifndef PAREDESG1_H3_LOGGER_H
#define PAREDESG1_H3_LOGGER_H
#include <iostream>

using namespace std;

class Logger {
public:
    static Logger &instance() {
        static Logger logger;
        return logger;
    }

    static void log(const string &message) {

        cout << message << endl;
    }

    Logger(const Logger &) = delete;

    Logger &operator=(const Logger &) = delete;


    Logger() = default;
};

#endif //PAREDESG1_H3_LOGGER_H
