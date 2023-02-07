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
    int *ptr = arrayExample;
    //first element in array through pointer
    cout << "first element in array through pointer " << *ptr << endl;
    //second element using array, also using pointer arithmetic. Pointer arithmetic is incrementing a pointer value. Incrementing it by 1 will go to the next memory address (the next 4 bytes).
    cout << "second element using array " << *ptr++ << endl;

    //another coding example using pointer arithmetic, the time complexity would be O(n) since it would grow with the size of the array
    int arrayLength = 5;
    ptr = arrayExample;
    for(int x = 1; x < arrayLength; x++)
    {
        cout << "Array number " << x << " value: " << *ptr << endl;
        ptr++;
    }

}