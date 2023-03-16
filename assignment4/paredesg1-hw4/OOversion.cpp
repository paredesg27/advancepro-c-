//
// Created by Georg on 3/16/2023.
//
#include "OOversion.h"

IntWrapper::IntWrapper(int val) {
    this->value = val;
}

bool IntWrapper::isLessThan(const IComparable &other) const {
    const IntWrapper &otherInt = dynamic_cast<const IntWrapper &>(other);
    return value < otherInt.value;
}

StringWrapper::StringWrapper(const string &val) {
    this->value = val;
}

bool StringWrapper::isLessThan(const IComparable& other) const  {
const StringWrapper& otherStr = dynamic_cast<const StringWrapper&>(other);
return value < otherStr.value;
}

void sortVector(vector<IComparable *> &vec) {
    int n = vec.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (vec[j+1]->isLessThan(*vec[j])) {
                swap(vec[j], vec[j+1]);
            }
        }
    }
}

// Sorting verification function

bool isSorted(const vector<IComparable *> &vec) {
    for (int i = 1; i < vec.size(); i++) {
        if ((*vec[i]).isLessThan(*(vec[i - 1]))) {
            return false;
        }
    }
    return true;
}