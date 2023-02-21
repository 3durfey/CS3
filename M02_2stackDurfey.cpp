#include <iostream> 
#include <stack> 
#include <math.h>
using namespace std;


int main() {
	stack<int> stack1;
    string binaryNum;
    cout << "enter binary number: ";
    cin >> binaryNum;

    for(int x = 0; x < binaryNum.length(); x++) {
        stack1.push(binaryNum[x] - '0');
    }
	
    double decimal = 0;
    int temp = 0;
	while (!stack1.empty()) {
        decimal += stack1.top() * pow(2, temp);
        stack1.pop();
        temp++;
	}
    cout << endl;
    cout << "decimal value: " << decimal << endl;
}