#include <iostream>
#include <vector>
using namespace std;

vector<string> returnLongestString(vector<string> vectorArray){
    int numOfLetters = vectorArray.at(0).length();
    vector<string> longestStrings;

    for(int i = 0; i < vectorArray.size(); i++){
        if(vectorArray.at(i).length() >= numOfLetters){
            if (vectorArray.at(i).length() > numOfLetters){
                numOfLetters = vectorArray.at(i).length();
                longestStrings.clear();
                longestStrings.push_back(vectorArray.at(i));
            }
            else{
                longestStrings.push_back(vectorArray.at(i));
            }
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
    for(int i = 0; i < userInputtedStrings.size(); i++){
        cout << userInputtedStrings.at(i) << ", ";
    }

    cout << endl << endl << "The longest string/s are/is: "<< endl;
    longestStringArray = returnLongestString(userInputtedStrings);
    for(int i = 0; i < longestStringArray.size(); i++){
        cout << longestStringArray.at(i) << ", ";
    }
    return 0;
}
