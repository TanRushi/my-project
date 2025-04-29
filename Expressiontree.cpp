#include <iostream>
#include <stack>
#include <cctype> // for isalpha and isdigit
using namespace std;
// Node structure for the expression tree
struct Node {
char data;
Node* left;
Node* right;
Node(char val) : data(val), left(NULL), right(NULL) {}
};
// Expression Tree class
class ExpressionTree {
public:
// Function to construct tree from postfix expression
Node* constructFromPostfix(string postfix) {
stack<Node*> st;
// Replace range-based loop with traditional for loop
for (int i = 0; i < postfix.length(); i++) {
char ch = postfix[i];
if (isalnum(ch)) { // If operand, create a node and push it to the stack
st.push(new Node(ch));
} else { // Operator, pop two nodes from the stack, create a new node
Node* node = new Node(ch);
node->right = st.top(); st.pop();
node->left = st.top(); st.pop();
st.push(node);
}
}
return st.top(); // The root of the expression tree
}
// Function to construct tree from prefix expression
Node* constructFromPrefix(string prefix) {
stack<Node*> st;
// Replace range-based loop with traditional for loop (traverse from right to left)
for (int i = prefix.length() - 1; i >= 0; i--) {
char ch = prefix[i];
if (isalnum(ch)) { // If operand, create a node and push it to the stack
st.push(new Node(ch));
} else { // Operator, pop two nodes from the stack, create a new node
Node* node = new Node(ch);
node->left = st.top(); st.pop();
node->right = st.top(); st.pop();
st.push(node);
}
}
return st.top(); // The root of the expression tree
}
// Recursive In-order Traversal
void inorderRecursive(Node* root) {
if (root == NULL) return;
inorderRecursive(root->left);
cout << root->data << " ";
inorderRecursive(root->right);
}
// Recursive Pre-order Traversal
void preorderRecursive(Node* root) {
if (root == NULL) return;
cout << root->data << " ";
preorderRecursive(root->left);
preorderRecursive(root->right);
}
// Recursive Post-order Traversal
void postorderRecursive(Node* root) {
if (root == NULL) return;
postorderRecursive(root->left);
postorderRecursive(root->right);
cout << root->data << " ";
}
// Non-recursive In-order Traversal
void inorderNonRecursive(Node* root) {
stack<Node*> st;
Node* current = root;
while (current != NULL || !st.empty()) {
while (current != NULL) {
st.push(current);
current = current->left;
}
current = st.top();
st.pop();
cout << current->data << " ";
current = current->right;
}
}
// Non-recursive Pre-order Traversal
void preorderNonRecursive(Node* root) {
if (root == NULL) return;
stack<Node*> st;
st.push(root);
while (!st.empty()) {
Node* current = st.top();
st.pop();
cout << current->data << " ";
if (current->right) st.push(current->right);
if (current->left) st.push(current->left);
}
}
// Non-recursive Post-order Traversal
void postorderNonRecursive(Node* root) {
if (root == NULL) return;
stack<Node*> st1, st2;
st1.push(root);
while (!st1.empty()) {
Node* current = st1.top();
st1.pop();
st2.push(current);
if (current->left) st1.push(current->left);
if (current->right) st1.push(current->right);
}
while (!st2.empty()) {
cout << st2.top()->data << " ";
st2.pop();
}
}
};
// Main function to demonstrate the expression tree operations
int main() {
ExpressionTree tree;
string postfix, prefix;
cout << "Enter postfix expression: ";
cin >> postfix;
Node* rootPostfix = tree.constructFromPostfix(postfix);
cout << "Recursive In-order Traversal of Postfix Tree: ";
tree.inorderRecursive(rootPostfix);
cout << "\nNon-recursive In-order Traversal of Postfix Tree: ";
tree.inorderNonRecursive(rootPostfix);
cout << "\nRecursive Pre-order Traversal of Postfix Tree: ";
tree.preorderRecursive(rootPostfix);
cout << "\nNon-recursive Pre-order Traversal of Postfix Tree: ";
tree.preorderNonRecursive(rootPostfix);
cout << "\nRecursive Post-order Traversal of Postfix Tree: ";
tree.postorderRecursive(rootPostfix);
cout << "\nNon-recursive Post-order Traversal of Postfix Tree: ";
tree.postorderNonRecursive(rootPostfix);
cout << "\n\nEnter prefix expression: ";
cin >> prefix;
Node* rootPrefix = tree.constructFromPrefix(prefix);
cout << "Recursive In-order Traversal of Prefix Tree: ";
tree.inorderRecursive(rootPrefix);
cout << "\nNon-recursive In-order Traversal of Prefix Tree: ";
tree.inorderNonRecursive(rootPrefix);
cout << "\nRecursive Pre-order Traversal of Prefix Tree: ";
tree.preorderRecursive(rootPrefix);
cout << "\nNon-recursive Pre-order Traversal of Prefix Tree: ";
tree.preorderNonRecursive(rootPrefix);
cout << "\nRecursive Post-order Traversal of Prefix Tree: ";
tree.postorderRecursive(rootPrefix);
cout << "\nNon-recursive Post-order Traversal of Prefix Tree: ";
tree.postorderNonRecursive(rootPrefix);
return 0;
}