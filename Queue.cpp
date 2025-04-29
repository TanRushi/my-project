#include <iostream>
using namespace std;
// Node structure for the linked list
struct Node {
int data;
Node* next;
};
// Circular Queue class using linked list
class CircularQueue {
private:
Node* front; // Front points to the first node in the queue
Node* rear; // Rear points to the last node in the queue
public:
// Constructor
CircularQueue() {
front = rear = NULL;
}
// Insertion (Enqueue) operation
void enqueue(int value) {
Node* newNode = new Node();
newNode->data = value;
newNode->next = NULL;
// If the queue is empty
if (front == NULL) {
front = rear = newNode;
rear->next = front; // Circular connection
} else {
rear->next = newNode;
rear = newNode;
rear->next = front; // Maintain circular connection
}
cout << value << " enqueued into the queue.\n";
}
// Deletion (Dequeue) operation
void dequeue() {
if (front == NULL) {
cout << "Queue Underflow. The queue is empty.\n";
return;
}
// If there is only one element
if (front == rear) {
cout << front->data << " dequeued from the queue.\n";
delete front;
front = rear = NULL;
} else {
Node* temp = front;
cout << front->data << " dequeued from the queue.\n";
front = front->next;
rear->next = front; // Maintain circular connection
delete temp;
}
}
// Display the queue in forward order
void displayForward() {
if (front == NULL) {
cout << "The queue is empty.\n";
return;
}
Node* temp = front;
cout << "Queue (forward): ";
do {
cout << temp->data << " ";
temp = temp->next;
} while (temp != front);
cout << endl;
}
// Display the queue in reverse order
void displayReverse(Node* current) {
// Base condition: queue is empty
if (front == NULL) {
cout << "The queue is empty.\n";
return;
}
// Base condition for recursion: current reached the front node again
if (current->next == front) {
cout << current->data << " ";
return;
}
// Recursive call for the next node
displayReverse(current->next);
cout << current->data << " "; // Print current node after recursive call
}
// Public function to start reverse display
void displayReverse() {
if (front == NULL) {
cout << "The queue is empty.\n";
return;
}
cout << "Queue (reverse): ";
displayReverse(front);
cout << endl;
}
};
int main() {
CircularQueue queue;
int choice, value;
do {
cout << "\nMenu:\n";
cout << "1. Enqueue\n";
cout << "2. Dequeue\n";
cout << "3. Display Forward\n";
cout << "4. Display Reverse\n";
cout << "5. Exit\n";
cout << "Enter your choice: ";
cin >> choice;
switch (choice) {
case 1:
cout << "Enter value to enqueue: ";
cin >> value;
queue.enqueue(value);
break;
case 2:
queue.dequeue();
break;
case 3:
queue.displayForward();
break;
case 4:
queue.displayReverse();
break;
case 5:
cout << "Exiting...\n";
break;
default:
cout << "Invalid choice. Please try again.\n";
break;
}
} while (choice != 5);
return 0;
}