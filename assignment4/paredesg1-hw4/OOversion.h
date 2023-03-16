//
// Created by Georg on 3/16/2023.
//

#ifndef PAREDESG1_HW4_OOVERSION_H
#define PAREDESG1_HW4_OOVERSION_H

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// IComparable interface
class IComparable {
public:
    virtual bool isLessThan(const IComparable &other) const = 0;
    virtual ~IComparable() {}
};

// IntWrapper class
class IntWrapper : public IComparable {
private:
    int value;
public:

    IntWrapper(int val);

    virtual bool isLessThan(const IComparable &other) const override;

    int getValue() const;
};

// StringWrapper class
class StringWrapper : public IComparable {
private:
    string value;
public:
    StringWrapper(const string &val);

    virtual bool isLessThan(const IComparable &other) const override;

    string getValue() const;
};

// Sorting function
void sortVector(vector<IComparable *> &vec);

// Sorting verification function
bool isSorted(const vector<IComparable *> &vec);

#endif //PAREDESG1_HW4_OOVERSION_H
