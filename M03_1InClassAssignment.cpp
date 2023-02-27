/*
Author: Peter Durfey
Assignment: Write a program that converts an infix expression into an equivalent postfix expression.
*/

#include <iostream>
#include <queue>

using namespace std;

struct Person {
    string name;
    int numberInLine;
};

int main() {
    queue<Person> lineQ;
    Person person1;
    Person person2;
    Person person3;
    Person person4;
    Person person5;
    person1.numberInLine = lineQ.size() + 1;
    person1.name = "ben";
    lineQ.push(person1);
    person2.numberInLine = lineQ.size() + 1;
    person2.name = "tom";
    lineQ.push(person2);
    person3.numberInLine = lineQ.size() + 1;
    person3.name = "tyler";
    lineQ.push(person3);
    person4.numberInLine = lineQ.size() + 1;
    person4.name = "samantha";
    lineQ.push(person4);
    person5.numberInLine = lineQ.size() + 1;
    person5.name = "erika";
    lineQ.push(person5);
    
    while(!lineQ.empty()) {
        cout << "Hello, " << lineQ.front().name << endl;
        cout << "Place in line " << lineQ.front().numberInLine << endl;
        lineQ.pop();
    }
    cout << "We are now closed, thanks for coming!" << endl;
    

}
