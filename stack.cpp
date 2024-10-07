#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 100; // Maximum size of the stack

class Stack {
private:
    char arr[MAX_SIZE]; // Change the data type to char
    int top;


public:
    Stack() {
        top = 0;
    }

    bool isEmpty() {
        return (top == 0);
    }

    bool isFull() {
        return (top == MAX_SIZE - 1);
    }

    int opening(char let) {
        switch (let) {

        case '(':
            return 1;
        case '[':
            return 2;
        case '{':
            return 3;
        default:
            return 0;
        }
    }

    int closing(char let) {
        switch (let) {

        case ')':
            return 1;
        case ']':
            return 2;
        case '}':
            return 3;
        default:
            return 0;
        }
    }

    bool push(char element) { // Accept char type

        /*cout << 1;
        for (int i = 0; i < top; i++) {
            cout << arr[i]<< ' ';
        }
        cout << endl; 
        */

        if (!isFull()) {
            if (opening(element)) {
                arr[top] = element;
                top++;
                return 1;
            }
            else {
                if (!isEmpty()) {
                    if (opening(topElement()) == closing(element)) {
                        pop();
                        return 1;
                    }
                }
            }

        }
        else {
            cout << "Stack is full. Cannot push element " << element << ".\n";
        }
        return 0;
    }

    void pop() {
        if (!isEmpty()) {
            char poppedElement = arr[top]; // Change the data type to char
            top--;

        }
        else {
            cout << "Stack is empty. Cannot pop from an empty stack.\n";
        }
    }

    char topElement() {
        if (!isEmpty()) {
            return arr[top-1];
        }
        else {
            cout << "Stack is empty.\n";
            return '\0'; // Return null character for empty stack
        }
    }
};
int main() {
    Stack myStack;
    string input = "2+4-5(87192479_7348){72648]76823[]";
    bool ans = 1;
    for (int i = 0; i < input.length(); i++) {
        if (myStack.opening(input[i]) or myStack.closing(input[i])) {
            ans = ans && myStack.push(input[i]);
        }

    }
    if (ans and myStack.isEmpty())
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
