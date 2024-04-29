
#include <iostream>
#include <Windows.h>
#include <string>
#include "modul.h"
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cherga* chergaHead = NULL;
    stack* stackHead = NULL;
    int k=0; int numStudents;
    mylist* listHead = NULL;
    student newStudent;
    int maxYear;
    char nameToEdit[30];
    char newCountry[30];
    bool success;
    while (k != 13) {
        printMenu();
        cin >> k;
        switch (k)
        {
        case 1:
            cout << "Введіть максимальний рік вступу: ";
            cin >> maxYear;
            listHead = createList(chergaHead, stackHead, maxYear);
            break;
        case 2:
            printList(listHead);
            printQueue(chergaHead);
            printStack(stackHead);
            break;
        case 3:
           
            if (listHead != NULL) {
                cout << "Скільки студентів ви хочете додати? ";
                cin >> numStudents;

                for (int i = 0; i < numStudents; ++i) {
                    cout << "Введіть дані для студента " << i + 1 << ":" << endl;
                    cout << "Прізвище: ";
                    cin >> newStudent.name;
                    cout << "Країна: ";
                    cin >> newStudent.country;
                    cout << "Рік вступу: ";
                    cin >> newStudent.year;
                    cout << "Ціна: ";
                    cin >> newStudent.price;

                    addToUnorderedList(listHead, newStudent, chergaHead, stackHead, maxYear);
                }
            }
            else {
                cout << "Спочатку введіть максимальний рік вступу (вибір 1)." << endl;
            }

            break;
        case 4:
            sortList(listHead); 
            break;
        case 5:
            if (listHead != NULL) {
                cout << "Скільки студентів ви хочете додати? ";
                cin >> numStudents;

                for (int i = 0; i < numStudents; ++i) {
                    cout << "Введіть дані для студента " << i + 1 << ":" << endl;
                    cout << "Прізвище: ";
                    cin >> newStudent.name;
                    cout << "Країна: ";
                    cin >> newStudent.country;
                    cout << "Рік вступу: ";
                    cin >> newStudent.year;
                    cout << "Ціна: ";
                    cin >> newStudent.price;
            addToOrderedList(listHead, newStudent);
                }
            }
            else {
                cout << "Спочатку введіть максимальний рік вступу (вибір 1)." << endl;
            }

            break;
        case 6:
         /*  cout << "Введіть ім'я: ";
           cin >> nameToEdit;
           cout << "Введіть країну: ";
           cin >> newCountry;
            bool success = editCountry(listHead, nameToEdit, newCountry);*/
            break;
        case 7:
            printCountries(listHead);
            break;
        default:
            break;
        }
    }
   
}

