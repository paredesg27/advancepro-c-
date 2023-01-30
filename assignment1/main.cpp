#include <iostream>
#include <vector>
using namespace std;

int * returnLongestString(vector<string> vectorArray){
    int numOfLetters = 0;
    vector<string> longestStrings;
    for(int i = 0; i < vectorArray.size(); i++){
        if (i == 0){
            numOfLetters = vectorArray.at(i).length();
            longestStrings.push_back(vectorArray.at(i));
        }
        else if(vectorArray.at(i).length() >= numOfLetters){
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
    return longestStrings();
}

int main() {
    vector<string> userInputtedStrings;
    string inputString;
    vector<string> longestStringArray;
    cout << "Enter any number of String. Enter \"done\" to stop" << endl;
    while( inputString != "done"){
        cin >> inputString;
        userInputtedStrings.push_back(inputString);
    }
    //delete done from vector
    userInputtedStrings.pop_back();
    cout << "User inputted string were"<< endl;
    for(int i=0; i < userInputtedStrings.size(); i++){
        cout << userInputtedStrings.at(i) << ", ";
    }


    cout<< endl << "The longest string/s are/is: "<< endl;
    //call longeststring method
    longestStringArray = returnLongestString(userInputtedStrings);
    //print out strings


    return 0;
}
