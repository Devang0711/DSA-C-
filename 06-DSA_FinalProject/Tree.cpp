#include "Tree.h"
#include <iostream>
#include <queue>
using namespace std;

BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

BinarySearchTree::~BinarySearchTree() {
    destroy(root);
}

void BinarySearchTree::destroy(TreeNode* node) {
    if (node == nullptr) return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}

// ---------- Insert ----------
TreeNode* BinarySearchTree::insertHelper(TreeNode* node, int val) {
    if (node == nullptr) return new TreeNode(val);
    if (val < node->data) node->left = insertHelper(node->left, val);
    else if (val > node->data) node->right = insertHelper(node->right, val);
    // duplicates are ignored
    return node;
}

void BinarySearchTree::insert(int val) {
    root = insertHelper(root, val);
}

// ---------- Delete ----------
TreeNode* BinarySearchTree::findMin(TreeNode* node) const {
    while (node->left != nullptr) node = node->left;
    return node;
}

TreeNode* BinarySearchTree::deleteHelper(TreeNode* node, int val) {
    if (node == nullptr) return nullptr;

    if (val < node->data) {
        node->left = deleteHelper(node->left, val);
    } else if (val > node->data) {
        node->right = deleteHelper(node->right, val);
    } else {
        // node found
        if (node->left == nullptr) {
            TreeNode* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            TreeNode* temp = node->left;
            delete node;
            return temp;
        } else {
            TreeNode* successor = findMin(node->right);
            node->data = successor->data;
            node->right = deleteHelper(node->right, successor->data);
        }
    }
    return node;
}

bool BinarySearchTree::remove(int val) {
    if (!search(val)) return false;
    root = deleteHelper(root, val);
    return true;
}

// ---------- Search ----------
bool BinarySearchTree::searchHelper(TreeNode* node, int val) const {
    if (node == nullptr) return false;
    if (node->data == val) return true;
    if (val < node->data) return searchHelper(node->left, val);
    return searchHelper(node->right, val);
}

bool BinarySearchTree::search(int val) const {
    return searchHelper(root, val);
}

// ---------- Height ----------
int BinarySearchTree::heightHelper(TreeNode* node) const {
    if (node == nullptr) return -1;
    int lh = heightHelper(node->left);
    int rh = heightHelper(node->right);
    return 1 + max(lh, rh);
}

int BinarySearchTree::height() const {
    return heightHelper(root);
}

bool BinarySearchTree::isEmpty() const {
    return root == nullptr;
}

// ---------- Depth-First Traversals ----------
void BinarySearchTree::preOrderHelper(TreeNode* node, vector<int> &out) const {
    if (node == nullptr) return;
    out.push_back(node->data);      // Root
    preOrderHelper(node->left, out);  // Left
    preOrderHelper(node->right, out); // Right
}

void BinarySearchTree::inOrderHelper(TreeNode* node, vector<int> &out) const {
    if (node == nullptr) return;
    inOrderHelper(node->left, out);   // Left
    out.push_back(node->data);      // Root
    inOrderHelper(node->right, out);  // Right
}

void BinarySearchTree::postOrderHelper(TreeNode* node, vector<int> &out) const {
    if (node == nullptr) return;
    postOrderHelper(node->left, out);  // Left
    postOrderHelper(node->right, out); // Right
    out.push_back(node->data);       // Root
}

vector<int> BinarySearchTree::preOrder() const {
    vector<int> out;
    preOrderHelper(root, out);
    return out;
}

vector<int> BinarySearchTree::inOrder() const {
    vector<int> out;
    inOrderHelper(root, out);
    return out;
}

vector<int> BinarySearchTree::postOrder() const {
    vector<int> out;
    postOrderHelper(root, out);
    return out;
}

// ---------- Breadth-First Traversal (Level Order) ----------
vector<int> BinarySearchTree::levelOrder() const {
    vector<int> out;
    if (root == nullptr) return out;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        out.push_back(curr->data);

        if (curr->left != nullptr) q.push(curr->left);
        if (curr->right != nullptr) q.push(curr->right);
    }
    return out;
}

void BinarySearchTree::printTraversal(const vector<int> &values) const {
    cout << "[ ";
    for (int v : values) cout << v << " ";
    cout << "]\n";
}
