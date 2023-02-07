/* 
*  Author: Peter Durfey
*  Date last updated: 1/24/2023
*  Purpose:  convert roman numeral to integer
*/
#include <iostream>
#include <map>
using namespace std;

bool checkValidInput(string input)
{
    bool invalidInput;
    for(int x = 0; x < input.length(); x++)
    {
        if(input[x] == 'I' || input[x] == 'L' || input[x] == 'V' || input[x] == 'X' || input[x] == 'C' || input[x] == 'D' || input[x] == 'M')
        {
            invalidInput = false;
        }   
        else
        {
            return true;
        }
    }
    return invalidInput;
};

class romanType
{
    int decimal;
    string romanNumeral;
    map<char, int> intValues;

    public:
    romanType(string romanNumeral)
    {
        populateMap();
        this->romanNumeral = romanNumeral;
        this->decimal = calculateDecimalValue(romanNumeral);
    }
    void populateMap()
    {
        intValues.insert(pair<char, int>('I', 1));
        intValues.insert(pair<char, int>('V', 5));
        intValues.insert(pair<char, int>('X', 10));
        intValues.insert(pair<char, int>('L', 50));
        intValues.insert(pair<char, int>('C', 100));
        intValues.insert(pair<char, int>('D', 500));
        intValues.insert(pair<char, int>('M', 1000)); 
    }
    int calculateDecimalValue(string romanNumeral)
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
    string getRomanNumeral()
    {
        return this->romanNumeral;
    }
};

int main() { 
    //get roman numeral from user 
    string input;
    cout << "Enter roman numeral: " << endl;
    cin >> input;
    while(checkValidInput(input))
    {
        cout << "Invalid input. Enter roman numeral: " << endl;
        cin >> input;
    }
    romanType romanType1(input);
    int choice;
    cout << "press 1 for decimal value or 2 for roman numeral" << endl;
    while(!(cin>> choice) || choice > 2 || choice < 1)
    {
        cout << "Invalid entry/n";
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Please Re-Enter choice: ";
    }
    if(choice == 1)
    {
        cout << romanType1.getDecimalValue() << endl;
    }
    else
    {
        cout << romanType1.getRomanNumeral() << endl;
    }
}


