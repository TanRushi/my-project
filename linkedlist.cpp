#include <iostream>
using namespace std;
class node {
public:
int data;
node* next;
node(int data) {
this->data = data;
this->next = NULL;
}
};
void print(node* &head) {
node* temp = head;
while (temp!= NULL) {
cout << temp->data << " -> ";
temp = temp->next;
}
cout << "NULL" << endl;
}
void insertathead(node*& head,node* &tail, int d) {
node* temp = new node(d);
if(head==NULL){
head=temp;
tail=temp;
}
else{
temp->next = head;
head = temp;
}
}
void insertattail(node*& head, node*& tail, int d) {
node* temp = new node(d);
if (head == NULL) {
head = temp;
tail = temp;
} else {
tail->next = temp;
tail = temp;
}
}
void insertatany(node* &head, node* &tail, int position, int d) {
if (position == 1) {
insertathead(head,tail, d);
return;
}
node* temp = head;
int count = 1;
while (temp != NULL && count < position - 1) {
temp = temp->next;
count++;
}
if (temp == NULL) {
cout << "Position out of bounds" << endl;
return;
}
node* needtoinsert = new node(d);
needtoinsert->next = temp->next;
temp->next = needtoinsert;
if (needtoinsert->next == NULL) {
tail = needtoinsert;
}
}
// Delete the head node
void deleteathead(node*& head, node*& tail) {
if (head == NULL) {
cout << "List is empty. Cannot delete." << endl;
return;
}
node* temp = head;
head = head->next;
if (head == NULL) {
tail = NULL;
}
delete temp;
}
// Delete the tail node
void deleteattail(node*& head, node*& tail) {
if (head == NULL) {
cout << "List is empty. Cannot delete." << endl;
return;
}
if (head->next == NULL) {
delete head;
head = NULL;
tail = NULL;
return;
}
node* temp = head;
while (temp->next != tail) {
temp = temp->next;
}
delete tail;
temp->next = NULL;
tail = temp;
}
// Delete a node at a specific position
void deleteatany(node*& head, node*& tail, int position) {
if (head == NULL) {
cout << "List is empty. Cannot delete." << endl;
return;
}
if (position == 1) {
deleteathead(head, tail);
return;
}
node* current = head;
int count = 1;
while (current != NULL && count < position - 1) {
current = current->next;
count++;
}
if (current == NULL || current->next == NULL) {
cout << "Position out of bounds" << endl;
return;
}
node* toDelete = current->next;
current->next = toDelete->next;
if (toDelete->next == NULL) {
tail = current;
}
delete toDelete;
}
int main() {
node* head = NULL;
node* tail = NULL;
int choice, data, position;
while (true) {
cout << "\nMenu:\n";
cout << "1. Insert at head\n";
cout << "2. Insert at tail\n";
cout << "3. Insert at a specific position\n";
cout << "4. Delete at head\n";
cout << "5. Delete at tail\n";
cout << "6. Delete at a specific position\n";
cout << "7. Print the list\n";
cout << "8. Exit\n";
cout << "Enter your choice: ";
cin >> choice;
switch (choice) {
case 1:
cout << "Enter data to insert at head: ";
cin >> data;
insertathead(head,tail, data);
break;
case 2:
cout << "Enter data to insert at tail: ";
cin >> data;
insertattail(head, tail, data);
break;
case 3:
cout << "Enter position to insert: ";
cin >> position;
cout << "Enter data to insert: ";
cin >> data;
insertatany(head, tail, position, data);
break;
case 4:
deleteathead(head, tail);
break;
case 5:
deleteattail(head, tail);
break;
case 6:
cout << "Enter position to delete: ";
cin >> position;
deleteatany(head, tail, position);
break;
case 7:
print(head);
break;
case 8:
cout << "Exiting...\n";
return 0;
default:
cout << "Invalid choice. Please try again.\n";
}
}
return 0;
}