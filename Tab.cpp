#include "Tab.hpp"
using namespace std;

Tab::Tab() : array(nullptr), capacity(0), size(0) {}

Tab::~Tab() {
    delete[] array;
}

void Tab::resize(){
if (capacity<1)
    capacity = 1;
else
  capacity *= 2;
int* temp = new int[capacity];
for (int i = 0; i < size; i++)
  temp[i] = array[i];
delete[] array;
array = temp;
}

void Tab::add_end(int value) {
  if (size==capacity)
    resize();
  array[size] = value;
  size++;
}

void Tab::add_front (int value) {
  if (size==capacity)
    resize();
  for (int i = size; i > 0; i--)
    array[i] = array[i - 1];
  array[0] = value;
  size++;
}

void Tab::add_anywhere (int value, int index) {
  if (size==capacity)
    resize();
  if (index==0)
    add_front(value);
  else if (index==size)
    add_end(value);
  else{
    for (int i = size; i > index; i--)
      array[i] = array[i - 1];
    array[index] = value;
    size++;
  }
}