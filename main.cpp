#include "Tab.hpp"
#include "SinglyLinkedList.hpp"
#include "DoublyLinkedList.hpp"
#include <chrono>
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int iterations = 20;
    int size_of_structure[8] = {10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000};
    int choice1, choice2;

    do {
        cout << "----------------------------" << endl;
        cout << "------------MENU------------" << endl;
        cout << "1. Tablica" << endl;
        cout << "2. Lista jednokierunkowa" << endl;
        cout << "3. Lista dwukierunkowa" << endl;
        cout << "4. Exit" << endl;
        cout << "----------------------------" << endl;
        cin >> choice1;

        switch (choice1) {
            case 1: {
                cout << "--- BADANIA: TABLICA DYNAMICZNA ---" << endl;
                cout << "1. Dodawanie na koniec (O(1) amortyzowane)" << endl;
                cout << "2. Dodawanie na poczatek (O(n))" << endl;
                cout << "3. Dodawanie gdziekolwiek (O(n))" << endl;
                cout << "4. Usuwanie z konca (O(1))" << endl;
                cout << "5. Usuwanie z poczatku (O(n))" << endl;
                cout << "6. Usuwanie gdziekolwiek (O(n))" << endl;
                cout << "7. Wyszukiwanie elementu (O(n))" << endl;
                cout << "8. Powrot" << endl;
                cin >> choice2;
                if (choice2 >= 1 && choice2 <= 7) {
                    cout << "Rozmiar [N] Sredni_Czas [ns]" << endl;

                    for (int i = 0; i < 8; i++) {
                        long long total_time = 0;
                        int N = size_of_structure[i];

                        for (int j = 0; j < iterations; j++) {
                            Tab temp_tab;

                            srand(j);
                            for (int k = 0; k < N; k++) {
                                temp_tab.add_end(rand() % 100);
                            }

                            auto start = chrono::high_resolution_clock::now();

                            if (choice2 == 1) temp_tab.add_end(rand() % 100);
                            else if (choice2 == 2) temp_tab.add_front(rand() % 100);
                            else if (choice2 == 3) temp_tab.add_anywhere(N / 2, rand() % 100);
                            else if (choice2 == 4) temp_tab.remove_end();
                            else if (choice2 == 5) temp_tab.remove_front();
                            else if (choice2 == 6) temp_tab.remove_anywhere(N / 2);
                            else if (choice2 == 7) temp_tab.find(rand() % 100);

                            auto stop = chrono::high_resolution_clock::now();

                            total_time += chrono::duration_cast<chrono::nanoseconds>(stop - start).count();

                        }

                        cout << N << ";" << total_time / iterations << endl;
                    }
                }
                break;
            }

            case 2: {
                cout << "--- BADANIA: LISTA JEDNOKIERUNKOWA ---" << endl;
                cout << "1. Dodawanie na koniec (O(1) - dzieki tail)" << endl;
                cout << "2. Dodawanie na poczatek (O(1))" << endl;
                cout << "3. Dodawanie gdziekolwiek (O(n))" << endl;
                cout << "4. Usuwanie z konca (O(n) - w l. jednokierunkowej)" << endl;
                cout << "5. Usuwanie z poczatku (O(1))" << endl;
                cout << "6. Usuwanie gdziekolwiek (O(n))" << endl;
                cout << "7. Wyszukiwanie elementu (O(n))" << endl;
                cout << "8. Powrot" << endl;
                cin >> choice2;

                if (choice2 >= 1 && choice2 <= 7) {
                    cout << "Rozmiar [N]; Sredni_Czas [ns]" << endl;

                    for (int i = 0; i < 8; i++) {
                        long long total_time = 0;
                        int N = size_of_structure[i];

                        for (int j = 0; j < iterations; j++) {
                            SLList temp_list;

                            srand(j);
                            for (int k = 0; k < N; k++) {
                                temp_list.add_end(rand() % 100);
                            }

                            auto start = chrono::high_resolution_clock::now();

                            if (choice2 == 1) temp_list.add_end(rand() % 100);
                            else if (choice2 == 2) temp_list.add_front(rand() % 100);
                            else if (choice2 == 3) temp_list.add_anywhere(rand() % 100, N / 2);
                            else if (choice2 == 4) temp_list.remove_end();
                            else if (choice2 == 5) temp_list.remove_front();
                            else if (choice2 == 6) temp_list.remove_anywhere(N / 2);
                            else if (choice2 == 7) temp_list.find(rand() % 100);

                            auto stop = chrono::high_resolution_clock::now();

                            total_time += chrono::duration_cast<chrono::nanoseconds>(stop - start).count();
                        }

                        cout << N << ";" << total_time / iterations << endl;
                     }
                }
                break;
            }

            case 3: {
                cout << "--- BADANIA: LISTA DWUKIERUNKOWA ---" << endl;
                cout << "1. Dodawanie na koniec (O(1))" << endl;
                cout << "2. Dodawanie na poczatek (O(1))" << endl;
                cout << "3. Dodawanie gdziekolwiek (O(n))" << endl;
                cout << "4. Usuwanie z konca (O(1) - przewaga nad jednokierunkowa!)" << endl;
                cout << "5. Usuwanie z poczatku (O(1))" << endl;
                cout << "6. Usuwanie gdziekolwiek (O(n))" << endl;
                cout << "7. Wyszukiwanie elementu (O(n))" << endl;
                cout << "8. Powrot" << endl;
                cin >> choice2;

                if (choice2 >= 1 && choice2 <= 7) {
                    cout << "Rozmiar [N]; Sredni_Czas [ns]" << endl;

                    for (int i = 0; i < 8; i++) {
                        long long total_time = 0;
                        int N = size_of_structure[i];

                        for (int j = 0; j < iterations; j++) {
                            DLList temp_dll; // Twoja nowa lista dwukierunkowa

                            // Wypełnianie struktury - uzywamy srand(j) dla powtarzalnosci
                            srand(j);
                            for (int k = 0; k < N; k++) {
                                temp_dll.add_end(rand() % 100);
                            }

                            auto start = chrono::high_resolution_clock::now();

                            if (choice2 == 1) temp_dll.add_end(rand() % 100);
                            else if (choice2 == 2) temp_dll.add_front(rand() % 100);
                            else if (choice2 == 3) temp_dll.add_anywhere(rand() % 100, N / 2);
                            else if (choice2 == 4) temp_dll.remove_end();
                            else if (choice2 == 5) temp_dll.remove_front();
                            else if (choice2 == 6) temp_dll.remove_anywhere(N / 2);
                            else if (choice2 == 7) temp_dll.find(rand() % 100);

                            auto stop = chrono::high_resolution_clock::now();

                            total_time += chrono::duration_cast<chrono::nanoseconds>(stop - start).count();
                        }

                        cout << N << ";" << total_time / iterations << endl;
                    }
                }
                break;
            }

        }

    } while (choice1 != 4);

    return 0;
}