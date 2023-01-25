#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<string> userInputtedStrings;
    string inputString;
    cout << "Enter any number of String.Press the enter key to stop" << endl;
    while( inputString != "done"){
        if (cin.peek() =='\n'){
            break;
        }
        cin >> inputString;
        userInputtedStrings.push_back(inputString);
    }
    cout << "User inputted string were"<< endl;
    for(int i=0; i < userInputtedStrings.size(); i++){
        cout << userInputtedStrings.at(i) << ", ";
    }
    //delete done from vector
    cout<< endl << "The longest string/s are/is: "<< endl;
    //call longeststring method
    //print out strings


    return 0;
}
