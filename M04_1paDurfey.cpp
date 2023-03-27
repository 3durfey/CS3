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
    map<string, int> map1;
    map<string, int>::iterator it;
    
    fstream txtFile;
    string word;
    string filename = "sets_map.txt";
    txtFile.open(filename.c_str());
    if(txtFile.is_open()) {
        while(txtFile >> word) {
            if(map1.find(word) == map1.end() || map1.size() == 0) {
                map1.insert({word, 1});
            } else {
                it = map1.find(word);
                it->second++;
            }
        }
        txtFile.close();
    }
    for(it = map1.begin(); it != map1.end(); ++it) {
        if(!(it->second > 1)) {
            cout << it->first << endl;
        }
    }
}