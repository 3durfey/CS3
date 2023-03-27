/*
*Author: Peter Durfey
*Purpose: compare sorting algo
*Date: 3/21/2023
*/

#include <iostream>
#include <list>
#include <fstream>
using namespace std;

string selectionSort(list <int> tempList) {
    list <int>::iterator it;
    list <int>::iterator smallestWord;
    list <int> sortedList;

    for(int x  = 0; x < tempList.size(); x++) {
        smallestWord = tempList.begin();
        for(it = tempList.begin(); it != tempList.end(); ++it) {
            if(*it < *smallestWord) {
                smallestWord = it;
            }
        }
        sortedList.push_back(*smallestWord);
        tempList.remove(*smallestWord);
    }
    for(it = sortedList.begin(); it != sortedList.end(); ++it) {
            cout << *it << endl;
        }
    return "sort completed";
}


int main () {
    fstream fileStream;
    int word;
    string filename = "input.txt";
    list <int> listOfStrings;
    list <int>::iterator it;
    list <int>::iterator smallestWord;
    list <int> sortedList;
    

    fileStream.open(filename.c_str());
    if(fileStream.is_open()) {
        while(fileStream >> word) {
            listOfStrings.push_front(word);
        }
    }
    cout << selectionSort(listOfStrings) << endl;
}