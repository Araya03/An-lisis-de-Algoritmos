#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    Node* current = head;
    Node* next;
    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
}

void LinkedList::append(int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void LinkedList::printList() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void LinkedList::deleteNode(int val) {
    Node* temp = head;
    Node* prev = nullptr;
    if (temp != nullptr && temp->data == val) {
        head = temp->next;
        delete temp;
        return;
    }
    while (temp != nullptr && temp->data != val) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Nodo no encontrado" << endl;
        return;
    }
    prev->next = temp->next;
    delete temp;
}