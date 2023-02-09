/*
*Author: Peter Durfey
*Purpose: create linked list
*Date: 2/8/2023
*/
#include <iostream>
using namespace std;

struct node
{
    string info;
    struct node *next;
};

class linkedList
{
    private:
        node *first, *last;
    public:
        linkedList()
        {
            first = NULL;
            last = NULL;
        }
    void addNodeToEnd(string input)
    {
        node *temp = new node;
        temp->info = input;
        temp->next = NULL;

        if(first == NULL)
        {
            first = temp;
            last = temp;
        }
        else
        {
            last->next = temp;
            last = last->next;
        }
    }
    void addNodeToBeginning(string input)
    {
        node *temp = new node;
        temp->info = input;
        temp->next = NULL;
        if(first == NULL)
        {
            first = temp;
            last = temp;
        }
        else
        {
            first->next = temp;
            first = first->next;
        }
    }
    string getLastNode()
    {
        return last->info;
    }
    string getFirstNode()
    {
        return first->info;
    }
};
int main() 
{
    linkedList linkedListA;
    linkedListA.addNodeToEnd("1");
    linkedListA.addNodeToEnd("2");
    cout << "first node: " << linkedListA.getFirstNode() << endl;
    cout << "Last node: " << linkedListA.getLastNode() << endl;

    linkedListA.addNodeToBeginning("3");
    linkedListA.addNodeToBeginning("4");

    cout << "first node: " << linkedListA.getFirstNode() << endl;
    cout << "last node: " << linkedListA.getLastNode() << endl;


}