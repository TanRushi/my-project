#include <iostream>
using namespace std;
// Define the structure for a Node in the In-order Threaded Binary Tree
struct Node {
int data;
Node *left, *right;
bool lthread, rthread; // To indicate if left or right are threads
// Constructor
Node(int val) {
data = val;
left = right = NULL;
lthread = rthread = true; // Initially all threads are true
}
};
// Function to insert a node in the In-order Threaded Binary Tree
Node* insert(Node* root, int key) {
Node* ptr = root;
Node* par = NULL; // Parent of the current node
// Find the appropriate parent node under which the new key should be added
while (ptr != NULL) {
// If the key is already present, return the root
if (key == ptr->data) {
cout << "Duplicate key not allowed\n";
return root;
}
par = ptr;
if (key < ptr->data) {
if (ptr->lthread == false)
ptr = ptr->left;
else
break;
} else {
if (ptr->rthread == false)
ptr = ptr->right;
else
break;
}
}
// Create a new node
Node* temp = new Node(key);
if (par == NULL) {
root = temp; // The new node is the root if the tree was empty
} else if (key < par->data) {
temp->left = par->left;
temp->right = par;
par->lthread = false;
par->left = temp;
} else {
temp->left = par;
temp->right = par->right;
par->rthread = false;
par->right = temp;
}
return root;
}
// Function to find the leftmost node of a subtree
Node* leftMost(Node* node) {
if (node == NULL)
return NULL;
while (node->lthread == false)
node = node->left;
return node;
}
// In-order traversal using threading
void inOrder(Node* root) {
if (root == NULL) {
cout << "Tree is empty\n";
return;
}
Node* cur = leftMost(root);
while (cur != NULL) {
cout << cur->data << " ";
if (cur->rthread)
cur = cur->right;
else
cur = leftMost(cur->right);
}
}
// Driver program to test the above functions
int main() {
Node* root = NULL;
int n, val;
cout << "Enter the number of elements in the tree: ";
cin >> n;
cout << "Enter the elements:\n";
for (int i = 0; i < n; ++i) {
cin >> val;
root = insert(root, val);
}
cout << "In-order traversal of the threaded binary tree:\n";
inOrder(root);
return 0;
}