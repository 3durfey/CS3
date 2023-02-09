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
            last = temp;
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
            temp->next = first;
            first = temp;
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
    string search(string x)
    {
        node* temp = first;
        while (temp != NULL) 
        {
            if (temp->info == x)
            {
                return "found";
            }
            temp = temp->next;
        }
        return "not found";
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
    linkedListA.addNodeToBeginning("3434");
    linkedListA.addNodeToBeginning("4434");
    linkedListA.addNodeToBeginning("411");
    linkedListA.addNodeToBeginning("427");
    linkedListA.addNodeToBeginning("477");
    linkedListA.addNodeToBeginning("498");
    linkedListA.addNodeToBeginning("489");

    cout << "first node: " << linkedListA.getFirstNode() << endl;
    cout << "last node: " << linkedListA.getLastNode() << endl;

    cout << "searching for 477 results: " << endl;
    cout << linkedListA.search("477") << endl;
}