/* 
*  Author: Peter Durfey
*  Date last updated: 1/24/2023
*  Purpose:  convert roman numeral to integer
*/
#include <iostream>
#include <map>
using namespace std;

class romanType
{
    int decimal;
    string romanNumeral;
    map<char, int> intValues;

    public:
    romanType(string romanNumeral)
    {
        this->romanNumeral = romanNumeral;
        this->romanNumeral = calculateRomanNumeral(romanNumeral);
        intValues.insert(pair<char, int>('I', 1));
        intValues.insert(pair<char, int>('V', 5));
        intValues.insert(pair<char, int>('X', 10));
        intValues.insert(pair<char, int>('L', 50));
        intValues.insert(pair<char, int>('C', 100));
        intValues.insert(pair<char, int>('D', 500));
        intValues.insert(pair<char, int>('M', 1000));
    }
    int calculateRomanNumeral(string romanNumeral)
    {
        int totalIntValue = intValues.at(romanNumeral[romanNumeral.length() - 1]);
        int previousRomanNumeral = intValues.at(romanNumeral[romanNumeral.length() - 1]);
        //itterate over roman numeral and create integer with total value
        for(int x = romanNumeral.length() - 2; x >= 0; x--) 
        {
            if(intValues.at(romanNumeral[x]) < previousRomanNumeral) 
            {
                totalIntValue -= previousRomanNumeral;
                totalIntValue += previousRomanNumeral - intValues.at(romanNumeral[x]);
            }
            else 
            {
                totalIntValue += intValues.at(romanNumeral[x]);
            }
        }
        return totalIntValue;
    }
    int getDecimalValue()
    {
        return this->decimal;
    }
};

int main() { 
    //get roman numeral from user 
    string input;
    romanType romanType1("X");
    cout << romanType1. getDecimalValue() << endl;
    

}

