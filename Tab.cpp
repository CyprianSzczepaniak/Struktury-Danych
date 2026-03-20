#include "Tab.hpp"
#include <iostream>

using namespace std;

Tab::Tab() : array(nullptr), capacity(0), size(0) {}

Tab::~Tab() {
    delete[] array;
}

void Tab::resize() {
    if (capacity < 1)
        capacity = 1;
    else
        capacity *= 2;

    int* temp = new int[capacity];
    for (int i = 0; i < size; i++) {
        temp[i] = array[i];
    }

    delete[] array;
    array = temp;
}

void Tab::add_end(int value) {
    if (size == capacity)
        resize();
    array[size] = value;
    size++;
}

void Tab::add_front(int value) {
    if (size == capacity)
        resize();
    for (int i = size; i > 0; i--) {
        array[i] = array[i - 1];
    }
    array[0] = value;
    size++;
}

void Tab::add_anywhere(int index, int value) {
    if (index < 0 || index > size) return;

    if (size == capacity)
        resize();

    if (index == 0) {
        add_front(value);
    } else if (index == size) {
        add_end(value);
    } else {
        for (int i = size; i > index; i--) {
            array[i] = array[i - 1];
        }
        array[index] = value;
        size++;
    }
}

void Tab::remove_anywhere(int index) {
    if (index < 0 || index >= size) return;

    for (int i = index; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    size--;
}

void Tab::remove_end() {
    if (size == 0) return;
    size--;
}

void Tab::remove_front() {
    if (size == 0) return;
    for (int i = 0; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    size--;
}

int Tab::find(int value) {
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            return i;
        }
    }
    return -1;
}