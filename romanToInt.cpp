#include <iostream>
#include <map>
using namespace std;

int main()
{
    //get roman numeral from user 
    cout << "Enter roman Numeral: ";
    
    //create map with values for each roman numeral
    map<char, int> intValues;
    intValues.insert(pair<char, int>('I', 1));
    intValues.insert(pair<char, int>('V', 5));
    intValues.insert(pair<char, int>('X', 10));
    intValues.insert(pair<char, int>('L', 50));
    intValues.insert(pair<char, int>('C', 100));
    intValues.insert(pair<char, int>('D', 500));
    intValues.insert(pair<char, int>('M', 1000));

    string romanNumeral1 = "MDCLXVI";
    int totalIntValue = intValues.at(romanNumeral1[romanNumeral1.length() - 1]);
    int previousRomanNumeral = intValues.at(romanNumeral1[romanNumeral1.length() - 1]);
    //itterate over roman numeral and create integer with total value
    for(int x = romanNumeral1.length() - 2; x >= 0; x--) {
        if(intValues.at(romanNumeral1[x]) < previousRomanNumeral) {
            totalIntValue -= previousRomanNumeral;
            totalIntValue += previousRomanNumeral - intValues.at(romanNumeral1[x]);
        }
        else {
            totalIntValue += intValues.at(romanNumeral1[x]);
        }
    }
    cout << totalIntValue << endl;
}

