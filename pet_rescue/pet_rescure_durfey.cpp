/* 
*  Author: Peter Durfey
*  Date last updated: 1/30/2023
* Purpose:  pet rescue
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    int cont = 0;
    while(cont == 0)
    {
    int choice;
    cout << "Press 1 to add a pet and 2 to view pets: ";
    while(!(cin >> choice) || choice > 2 || choice < 1)
    {
        cout << "Invalid entry\n";
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Press 1 to add a pet and 2 to view pets: ";
    }
    if(choice == 2)
    {
        ifstream petFiles ("data.txt");
        string line;
        if(petFiles.is_open())
        {
            while( getline (petFiles,line))
            {
                cout << line << '\n';
            }
            petFiles.close();
        }
    }
    else
    {

        string name, species, breed, color;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter species: ";
        cin >> species;
        cout << "Enter breed: ";
        cin >> breed;
        cout << "Enter color: ";
        std::cin >> color;

        ofstream of;
        of.open("data.txt", ios::app);
        of << "\n" << name;
        of << "         |       " << species;
        of << "         |       " << breed;
        of << "         |       " << color;
    }
    cout << "Enter 0 to perform another task or another key to quit" << endl;
    cin >> cont;
    }
}