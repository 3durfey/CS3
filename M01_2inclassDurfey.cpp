/*
* Author: Peter Durfey
* Date: 2/6/2023
* Purpose: explain pointers with coding examples
*/

#include <iostream>
using namespace std;

int main()
{
    //a pointer is a variable that holds the memory address of another variable, it is initialized and declared in the following way:
    int num = 2;
    int* numberPointer = &num;
    //variable is accessed through pointer in the following way:
    cout << *numberPointer << endl;
    //an array name is a pointer with the pointer pointing at the very first memory address of the array, which can be incrementing in memory to get the rest of the array
    int arrayExample[4] = {1,3,4,5};
    //first element in array through pointer
    cout << "first element in array through pointer " << *arrayExample << endl;
    //second element using array 
    cout << "second element using array " << *arrayExample + 1 << endl;


}