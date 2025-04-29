#include <iostream>
#include <cctype> // For isalnum() and isdigit()
#include <cstdlib> // For exit()
#include <cstring> // For string handling
using namespace std;
// Node structure for the linked list
struct Node {
char data; // To store both operands and operators
Node* next;
};
// Stack class using singly linked list
class Stack {
private:
Node* top;
public:
Stack() {
top = NULL; // Initialize the top pointer as NULL
}
// Push operation (insert a new element on top of the stack)
void push(char value) {
Node* newNode = new Node();
newNode->data = value;
newNode->next = top;
top = newNode;
}
// Pop operation (remove the top element from the stack)
char pop() {
if (top == NULL) { // Check for stack underflow
cout << "Stack Underflow\n";
exit(1);
}
char value = top->data;
Node* temp = top;
top = top->next;
delete temp;
return value;
}
// Peek operation (return the top element without removing it)
char peek() {
if (top == NULL) { // Check if the stack is empty
cout << "Stack is empty\n";
exit(1);
}
return top->data;
}
// Check if the stack is empty
bool isEmpty() {
return top == NULL;
}
};
// Function to determine the precedence of operators
int precedence(char op) {
if (op == '+' || op == '-') {
return 1;
}
if (op == '*' || op == '/') {
return 2;
}
return 0;
}
// Function to check if a character is an operator
bool isOperator(char ch) {
return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}
// Function to convert infix expression to postfix expression
void infixToPostfix(const char infix[], char postfix[]) {
Stack stack; // Stack for holding operators
int j = 0; // Index for postfix array
for (int i = 0; infix[i] != '\0'; i++) {
char ch = infix[i];
// If the character is an operand, add it to the output
if (isalnum(ch)) {
postfix[j++] = ch;
}
// If the character is '(', push it onto the stack
else if (ch == '(') {
stack.push(ch);
}
// If the character is ')', pop and output from the stack until '(' is encountered
else if (ch == ')') {
while (!stack.isEmpty() && stack.peek() != '(') {
postfix[j++] = stack.pop();
}
stack.pop(); // Remove '(' from stack
}
// If the character is an operator
else if (isOperator(ch)) {
while (!stack.isEmpty() && precedence(stack.peek()) >= precedence(ch)) {
postfix[j++] = stack.pop();
}
stack.push(ch); // Push the current operator to the stack
}
}
// Pop all remaining operators from the stack
while (!stack.isEmpty()) {
postfix[j++] = stack.pop();
}
postfix[j] = '\0'; // Null-terminate the postfix expression
}
// Function to evaluate the postfix expression
int evaluatePostfix(const char postfix[]) {
Stack stack;
for (int i = 0; postfix[i] != '\0'; i++) {
char ch = postfix[i];
// If the character is an operand, push it onto the stack
if (isdigit(ch)) {
stack.push(ch - '0'); // Convert char to int and push it
}
// If the character is an operator, pop two elements and perform the operation
else if (isOperator(ch)) {
int val2 = stack.pop();
int val1 = stack.pop();
switch (ch) {
case '+':
stack.push(val1 + val2);
break;
case '-':
stack.push(val1 - val2);
break;
case '*':
stack.push(val1 * val2);
break;
case '/':
stack.push(val1 / val2);
break;
}
}
}
return stack.pop(); // The final result is the top of the stack
}
int main() {
char infix[100], postfix[100];
cout << "Enter infix expression: ";
cin >> infix;
infixToPostfix(infix, postfix);
cout << "Postfix expression: " << postfix << endl;
int result = evaluatePostfix(postfix);
cout << "Evaluation of postfix expression: " << result << endl;
return 0;
}
