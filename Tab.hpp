#ifndef TAB_H
#define TAB_H
class Tab {
  public:
      Tab();
      ~Tab();
      void add_end(int value);
      void add_front(int value);
      void add_anywhere(int value, int index);
      void remove_anywhere(int index);
      void remove_end();
      void remove_front();
      int find(int value);
  private:
    int size; //size of the array
    int* array; //pointer to the array
    int capacity; //current capacity of the array
    void resize();
};
#endif
