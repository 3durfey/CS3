/*
*Author: Peter Durfey
*Purpose: sets/maps assignment
*Date: 3/21/2023
*/
#include <iostream>
#include <map>
#include <fstream>

using namespace std;

int main() {

map<string, string> statesMap;
map<string, string>::iterator it;

statesMap.insert({"Indiana", "Indianapolis"});
statesMap.insert({"Alabama", "Juneau"});
statesMap.insert({"Alaska", "Phoenix"});
statesMap.insert({"Arizona", "Phoenix"});
statesMap.insert({"Arkansas", "Little Rock"});
statesMap.insert({"California", "Sacramento"});
statesMap.insert({"Colorado", "Denver"});
statesMap.insert({"Connecticut", "Hartford"});
statesMap.insert({"Deleware", "Dover"});
statesMap.insert({"Florida", "Tallahassee"});

string userChoice;
cout << "Enter state: ";
cin >> userChoice;

it = statesMap.find(userChoice);

cout << "The capital of " << it->first << " is " <<  it->second << endl;



}