#include "SinglyLinkedList.hpp"
#include <iostream>
using namespace std;

// Konstruktor: Inicjalizuje pustą listę

SLList::SLList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

// Destruktor: Czyści całą listę węzeł po węźle
SLList::~SLList() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

//Dodawanie na Koniec
void SLList::add_end(int value) {
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else { // przypadek gdy wezeł jest pusty
        tail->next = newNode;
        tail = tail->next;
    }
    size++; // aktualizujemy rozmiar struktury
}

//Dodawanie na początku, tworzy nowy element i przypina wskaźnik head
void SLList::add_front(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;

    //Jeśli lista jest pusta, nowy węzeł staje sie jednocześnie początekim i konćzem
    if (head == nullptr) {
        head = newNode;
        tail = newNode;

    } else {
        //w przeciwnym wypadku nowy węzeł staje sie nowym headem
        head =  newNode;
    }
    size++; // aktualizujemy rozmiar struktury
}

void SLList::add_anywhere(int value, int index) {
    if (index > size || index < 0) {
        cout<<"----Index out of bounds----"<<endl;
        return;
    }
    if (index == 0) {
        add_front(value);
        return;
    }
    if (index == size) {
        add_end(value);
        return;
    }
    else {
        //Znalezienie elementu bezpośrednio przed miejscem wstawienia
        Node* temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }

        //Alokacja nowego węzła "dynamicznie"
        Node* newNode = new Node;
        newNode->data = value;

        //Rozcięcie i szycie
        newNode->next = temp->next;

        //element poprzedni (temp) wskazuje teraz na nasz nowy węzeł
        temp->next = newNode;

        size++;
    }
}

void SLList::remove_anywhere(int index) {
    if (index >= size || index < 0) {
        cout<<"----Index out of bounds----"<<endl;
        return;
    }
    if (index == 0) {
        remove_front();
        return;
    }
    if (index == size-1) {
        remove_end();
        return;
    }else {
        Node* temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
        size--;
    }
}

void SLList::remove_front() {
    if (head == nullptr) {
        cout<<"----Empty List----"<<endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head == nullptr) {
        tail = nullptr;
    }
    delete temp;
    size--;
}

void SLList::remove_end() {
    //sprawdzamy czy lista nie jest pusta
    if (head == nullptr) {
        cout<<"----Empty List----"<<endl;
        return;
    }//jeśli jest jeden element to head i tail wskazują na nullptr
    if (head == tail) {
        remove_front();
        return;
    }
    Node* temp = head;
    //szukamy przed ostatniego elementu który ma się stać ostatnim po remove
    while (temp->next != tail) {
        temp = temp->next;
    }
    //usuwanie i aktualizacja wsaźnika
    delete tail;
    tail = temp;
    tail->next = nullptr;

    size--;
}

int SLList::find(int value) {
    if (head == nullptr) {
        cout<<"----Empty List----"<<endl;
        return -1;
    }
    //wskaźnik pomocniczy do przejścia po liście
    Node* current = head;
    int index = 0; // pozycja jesli znalezniono element
    //petla przechodząca przez wszyskie wezły
    while (current != nullptr) {
        if (current->data == value) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}