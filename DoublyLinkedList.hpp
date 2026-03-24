#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP


class DLList {
public:
    DLList();           // Konstruktor
    ~DLList();          // Destruktor

    // Metody wymagane przez projekt
    void add_end(int value);
    void add_front(int value);
    void add_anywhere(int value, int index);

    void remove_anywhere(int index);
    void remove_end();
    void remove_front();

    int find(int value);
    void display();

private:
    // Struktura pojedynczego ogniwa listy
    struct Node {
        int data;
        Node* next;
        Node* prev;
    };

    Node* head;         // Wskaźnik na początek listy
    Node* tail;         // Wskaźnik na koniec listy
    int size;           // Aktualna liczba elementów w liście
};

#endif