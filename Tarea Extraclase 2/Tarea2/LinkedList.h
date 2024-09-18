#ifndef LINKED_LIST_H
#define LINKED_LIST_H

class LinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };
    Node* head;

public:
    LinkedList();
    ~LinkedList();
    void append(int val);
    void printList();
    void deleteNode(int val);
};

#endif // LINKED_LIST_H