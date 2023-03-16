
#include <chrono>
#include <random>
#include "OOversion.h"
#include "Templateversion.cpp"

int main() {
    bool result;
    // Generate 1,000,000 random ints between 0 and 1000
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, 1000);
    cout<<"appel"<<endl;
    vector<IComparable*> intVec;
    for (int i = 0; i < 1000000; i++) {
        IntWrapper* intWrapper = new IntWrapper(dis(gen));
        intVec.push_back(intWrapper);
        delete intWrapper;

    }
    cout<<"appel"<<endl;
    // Generate 1,000,000 random strings of length 1-4
    uniform_int_distribution<int> strLenDis(1, 4);
    uniform_int_distribution<int> strCharDis(97, 122);

    vector<IComparable*> strVec;
    for (int i = 0; i < 1000000; i++) {
        string str;
        int len = strLenDis(gen);
        for (int j = 0; j < len; j++) {
            char c = strCharDis(gen);
            str += c;
        }
        StringWrapper* stringWrapper = new StringWrapper(str);
        strVec.push_back(stringWrapper);
        delete stringWrapper;

    }
    cout<<"appel"<<endl;
    // Sort and verify ints
    auto intStart = chrono::high_resolution_clock::now();
    sortVector(intVec);
    auto intEnd = chrono::high_resolution_clock::now();
    cout << "Ints sorted in " << chrono::duration_cast<chrono::milliseconds>(intEnd - intStart).count() << " ms" << endl;
    result = isSorted(intVec);
    cout << "Ints sorted correctly: " << result << endl;
    cout<<"appel"<<endl;
    // Sort and verify strings
    auto strStart = chrono::high_resolution_clock::now();
    sortVector(strVec);
    auto strEnd = chrono::high_resolution_clock::now();
    cout << "Strings sorted in " << chrono::duration_cast<chrono::milliseconds>(strEnd - strStart).count() << " ms" << endl;
    result = isSorted(strVec);
    cout << "Strings sorted correctly: " << result << endl;
    cout<<"appel"<<endl;

    return 0;
}
