/*
*Author: Peter Durfey
*Purpose: inclass regex question
*Date: 3/21/2023
*/
#include <iostream>
#include <regex>

using namespace std;

int main() {
    string password;
    smatch match;
    bool upperCase = false;
    bool lowerCase = false;
    bool number = false;
    bool minLength = false;
    bool extraChar = false;

    regex upperCaseExpression{"[A-Z]+"};
    regex lowerCaseExpression{"[a-z]+"};
    regex numberExpression{"[0-9]+"};
    regex extraCharExpression{"[!@#$%&^*]+"};

    cout << "Enter password: ";
    getline(cin, password);

    if(password.length() < 8) {
        cout << "Invalid Password length" << endl;
    } else {
        upperCase = regex_search(password, upperCaseExpression);
        lowerCase = regex_search(password, lowerCaseExpression);
        number = regex_search(password, numberExpression);
        extraChar = regex_search(password, extraCharExpression);
        cout << upperCase  << " " <<  lowerCase  << " " <<  number  << " " <<  extraChar << endl;
        cout << match[0] << endl;
        if(upperCase && lowerCase && number && extraChar) {
            cout << "Valid Password" << endl;
        } else {
            cout << "Invalid Password" << endl;
        }
    }
}