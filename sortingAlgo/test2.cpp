#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct Node {
	int data;
	Node* next;
};
void splitList(Node* source, Node** frontList, Node** backList)
{
	Node* fast;
	Node* slow;
	slow = source;
	fast = source->next;

	while (fast != NULL) {
		fast = fast->next;
		if (fast != NULL) {
			slow = slow->next;
			fast = fast->next;
		}
	}
	*frontList = source;
	*backList = slow->next;
	slow->next = NULL;
}
Node* combineAndSort(Node* a, Node* b)
{
	Node* result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (a->data <= b->data) {
		result = a;
		result->next = combineAndSort(a->next, b);
	}
	else {
		result = b;
		result->next = combineAndSort(a, b->next);
	}
	return (result);
}

void MergeSort(Node** listHead) {
	Node* head = *listHead;
	Node* x;
	Node* y;
	if ((head == NULL) || (head->next == NULL)) {
		return;
	}
	splitList(head, &x, &y);
	MergeSort(&x);
	MergeSort(&y);
	*listHead = combineAndSort(x, y);
}
void selectionSort(Node* listHead) {
    Node* temp = listHead;
    while(temp) {
        Node* temp2 = temp->next;
        Node* lowestValue = temp;
        while(temp2) {
            if(lowestValue->data > temp2->data) {
                lowestValue = temp2;
            }
            temp2 = temp2->next;
        }
        int data = temp->data;
        temp->data = lowestValue->data;
        lowestValue->data = data;
        temp = temp->next;
    }
}
void print(Node* node) {
	while (node != NULL) {
		cout << node->data << endl;
		node = node->next;
	}
    cout << endl;
}
void addNode(Node** head, int info) {
	Node* newNode = new Node();
	newNode->data = info;
	newNode->next = (*head);
    *head = newNode;
}

int main() {
    Node* mergeSortList = NULL;
    Node* selectionSortList = NULL;
    fstream fileStream;
    int number;
    string filename = "input.txt";
    fileStream.open(filename.c_str());

    if(fileStream.is_open()) {
        while(fileStream >> number) {
	        addNode(&mergeSortList, number);
            addNode(&selectionSortList, number);
        }
    }

    auto start = high_resolution_clock::now();
	MergeSort(&mergeSortList);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Sort time: " << duration.count() << endl;
	cout << "Merge Sort List: " << endl;

    auto start2 = high_resolution_clock::now();
    selectionSort(selectionSortList);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop - start);
    cout << "Sort time: " << duration.count() << endl;
    cout << "Selection Sort List: " << endl;
}
 