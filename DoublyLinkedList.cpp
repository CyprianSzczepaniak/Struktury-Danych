#include "DoublyLinkedList.hpp"
#include <iostream>
using namespace std;

DLList::DLList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

DLList::~DLList() {
    Node *current = head;
    while (current != nullptr) {
        Node *nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

void DLList::add_end(int value) {
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

void DLList::add_front(int value) {
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    size++;
}

void DLList::add_anywhere(int value, int index) {
    if( index < 0 || index > size) {
        cout<<"----Index out of bounds----"<<endl;
        return;
    }
    if(index == 0 ) {
        add_front(value);
        return;
    }
    if(index == size) {
        add_end(value);
        return;
    }

    Node* newNode = new Node;
    newNode->data = value;

    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    Node* previousNode = current->prev;

    newNode->next = current;
    newNode->prev = previousNode;

    previousNode->next = newNode;
    current->prev = newNode;

    size++;
}

void DLList::remove_anywhere(int index) {
    if(index < 0 || index >= size) {
        cout<<"----Index out of range----"<<endl;
        return;
    }
    if(index == 0) {
        remove_front();
        return;
    }
    if(index == size-1) {
        remove_end();
        return;
    }

    Node* toDelete = head;
    for (int i = 0; i < index; i++) {
        toDelete = toDelete->next;
    }
    toDelete->prev->next = toDelete->next;

    toDelete->next->prev = toDelete->prev;

    delete toDelete;
    size--;
}

void DLList::remove_front() {
    if(head == nullptr) {
        cout<<"----Empty List----"<<endl;
        return;
    }

    Node* temp = head;

    if(head == tail) {
        head = nullptr;
        tail = nullptr;
    }else {
        head=head->next;
        head->prev = nullptr;
    }
    delete temp;
    size--;
}

void DLList::remove_end() {
    if(head == nullptr) {
        cout<<"----Empty List----"<<endl;
        return;
    }

    if(head == tail) {
        remove_front();
        return;
    }

    Node* toDelete = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete toDelete;
    size--;
}

int DLList::find(int value) {
    if(head == nullptr) {
        cout<<"----Empty List----"<<endl;
        return -1;
    }
    Node* current = head;
    int index = 0;

    while(current != nullptr) {
        if(current->data == value) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}
