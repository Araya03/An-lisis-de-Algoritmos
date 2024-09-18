#ifndef BINARY_TREE_H
#define BINARY_TREE_H

class BinarySearchTree {
private:
    struct TreeNode {
        int data;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
    };
    TreeNode* root;
    TreeNode* insert(TreeNode* node, int val);
    void inorder(TreeNode* node);
    TreeNode* search(TreeNode* node, int val);
    TreeNode* deleteNode(TreeNode* root, int val);
    TreeNode* minValueNode(TreeNode* node);

public:
    BinarySearchTree();
    ~BinarySearchTree();
    void destroyTree(TreeNode* node);
    void insert(int val);
    void inorder();
    TreeNode* search(int val);
    void deleteNode(int val);
};

#endif // BINARY_TREE_H