#include <iostream>
#include <vector>
using namespace std;
//George Paredes CSC 402

vector<string> LongestLength(const vector<string> & vectorArray){
    unsigned int numOfLetters = vectorArray.at(0).length();
    vector<string> longestStrings;

    for(const auto & i : vectorArray){
            if (i.length() > numOfLetters){
                numOfLetters = i.length();
                longestStrings.clear();
                longestStrings.push_back(i);
            }
            else if (i.length() == numOfLetters) {
                longestStrings.push_back(i);
            }
    }
    return longestStrings;
}

int main() {
    vector<string> userInputtedStrings;
    string inputString;
    vector<string> longestStringArray;

    cout << "Enter any number of strings. Enter \"done\" to stop" << endl;
    while(cin >> inputString && inputString != "done"){
        userInputtedStrings.push_back(inputString);
    }

    cout << endl << "User inputted string were:"<< endl;
    for(const auto & userInputtedString : userInputtedStrings){
        cout << userInputtedString << ", ";
    }

    cout << endl << endl << "The longest string/s are/is: "<< endl;
    longestStringArray = LongestLength(userInputtedStrings);
    for(const auto & i : longestStringArray){
        cout << i << ", ";
    }
    return 0;
}
