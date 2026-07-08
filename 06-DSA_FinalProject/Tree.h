#ifndef TREE_H
#define TREE_H

#include <vector>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

    TreeNode* insertHelper(TreeNode* node, int val);
    TreeNode* deleteHelper(TreeNode* node, int val);
    TreeNode* findMin(TreeNode* node) const;
    bool searchHelper(TreeNode* node, int val) const;
    int heightHelper(TreeNode* node) const;
    void destroy(TreeNode* node);

    void preOrderHelper(TreeNode* node, vector<int> &out) const;
    void inOrderHelper(TreeNode* node, vector<int> &out) const;
    void postOrderHelper(TreeNode* node, vector<int> &out) const;

public:
    BinarySearchTree();
    ~BinarySearchTree();

    void insert(int val);
    bool remove(int val);
    bool search(int val) const;
    int height() const;
    bool isEmpty() const;

    // Depth-First Traversals
    vector<int> preOrder() const;   // Root -> Left -> Right
    vector<int> inOrder() const;    // Left -> Root -> Right (gives sorted order for BST)
    vector<int> postOrder() const;  // Left -> Right -> Root

    // Breadth-First Traversal (level order), uses a queue internally
    vector<int> levelOrder() const;

    void printTraversal(const vector<int> &values) const;
};

#endif // TREE_H
