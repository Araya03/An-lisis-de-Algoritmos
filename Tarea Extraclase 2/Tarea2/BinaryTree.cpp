#include "BinaryTree.h"
#include <iostream>
using namespace std;

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

BinarySearchTree::~BinarySearchTree() {
    destroyTree(root);
}

void BinarySearchTree::destroyTree(TreeNode* node) {
    if (node != nullptr) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

BinarySearchTree::TreeNode* BinarySearchTree::insert(TreeNode* node, int val) {
    if (node == nullptr) {
        return new TreeNode(val);
    }
    if (val < node->data) {
        node->left = insert(node->left, val);
    } else if (val > node->data) {
        node->right = insert(node->right, val);
    }
    return node;
}

void BinarySearchTree::insert(int val) {
    root = insert(root, val);
}

void BinarySearchTree::inorder(TreeNode* node) {
    if (node != nullptr) {
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
}

void BinarySearchTree::inorder() {
    inorder(root);
    cout << endl;
}

BinarySearchTree::TreeNode* BinarySearchTree::search(TreeNode* node, int val) {
    if (node == nullptr || node->data == val) {
        return node;
    }
    if (val < node->data) {
        return search(node->left, val);
    }
    return search(node->right, val);
}

BinarySearchTree::TreeNode* BinarySearchTree::deleteNode(TreeNode* root, int val) {
    if (root == nullptr) {
        return root;
    }
    if (val < root->data) {
        root->left = deleteNode(root->left, val);
    } else if (val > root->data) {
        root->right = deleteNode(root->right, val);
    } else {
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        TreeNode* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

BinarySearchTree::TreeNode* BinarySearchTree::minValueNode(TreeNode* node) {
    TreeNode* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

void BinarySearchTree::deleteNode(int val) {
    root = deleteNode(root, val);
}

BinarySearchTree::TreeNode* BinarySearchTree::search(int val) {
    return search(root, val);
}