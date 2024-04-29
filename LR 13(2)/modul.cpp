#include "modul.h"
#include<string>
#include <Windows.h>
#include<iostream>
using namespace std;
mylist* createList(cherga*& chergaHead, stack*& stackHead, int maxYear) {
    mylist* listHead = NULL;
    mylist* listCurrent = NULL;

    int numRecords;
    cout << "������ ������� ������: ";
    cin >> numRecords;

    for (int i = 0; i < numRecords; ++i) {
       
        mylist* newListnode = new mylist;

        cout << "������ ��'�: ";
        cin.ignore();
        cin.getline(newListnode->data.name, 30);

        cout << "������ �����: ";
        cin.getline(newListnode->data.country, 30);

        cout << "������ ��: ";
        cin >> newListnode->data.year;

        cout << "������ ����: ";
        cin >> newListnode->data.price;

      
        newListnode->next = NULL;

     
        if (listHead == NULL) {
            listHead = newListnode;
        }
        else {
            listCurrent->next = newListnode;
        }
        listCurrent = newListnode;

      
        if (strcmp(newListnode->data.country, "������") != 0) {
            // ��������� �� �����
            cherga* newchergaHead = new cherga;
            for (int j = 0; j < 30; ++j) {
                newchergaHead->data.name[j] = newListnode->data.name[j];
                newchergaHead->data.country[j] = newListnode->data.country[j];
            }
            newchergaHead->data.year = newListnode->data.year;
            newchergaHead->data.price = newListnode->data.price;
            newchergaHead->next = NULL;

            if (chergaHead == NULL) {
                chergaHead = newchergaHead;
            }
            else {
                cherga* chergaCurrent = chergaHead;
                while (chergaCurrent->next != NULL) {
                    chergaCurrent = chergaCurrent->next;
                }
                chergaCurrent->next = newchergaHead;
            }
        }

        // ������ � ����
        if (newListnode->data.year > maxYear) {
            stack* newStackNode = new stack;
            for (int j = 0; j < 30; ++j) {
                newStackNode->data.name[j] = newListnode->data.name[j];
                newStackNode->data.country[j] = newListnode->data.country[j];
            }
            newStackNode->data.year = newListnode->data.year;
            newStackNode->data.price = newListnode->data.price;
            newStackNode->next = stackHead;
            stackHead = newStackNode;
        }
    }

    return listHead;
}
void printList(mylist* head) {
    cout << "������ ��������:" << endl;
    while (head != NULL) {
        cout << "��'�: " << head->data.name << ", �����: " << head->data.country
            << ", г�: " << head->data.year << ", ֳ��: " << head->data.price << endl;
        head = head->next;
    }
}

// ������� ��� ��������� ����� �� �����
void printQueue(cherga* chergaHead) {
    cout << "����� ��������:" << endl;
    while (chergaHead != NULL) {
        cout << "��'�: " << chergaHead->data.name << ", �����: " << chergaHead->data.country
            << ", г�: " << chergaHead->data.year << ", ֳ��: " << chergaHead->data.price << endl;
        chergaHead = chergaHead->next;
    }
}

// ������� ��� ��������� ����� �� �����
void printStack(stack* stackHead) {
    cout << "���� ��������:" << endl;
    while (stackHead != NULL) {
        cout << "��'�: " << stackHead->data.name << ", �����: " << stackHead->data.country
            << ", г�: " << stackHead->data.year << ", ֳ��: " << stackHead->data.price << endl;
        stackHead = stackHead->next;
    }
}
void addToUnorderedList(mylist*& head, student newData, cherga*& chergaHead, stack*& stackHead, int maxYear) {
    mylist* newNode = new mylist;
    newNode->data = newData;
    newNode->next = head;
    head = newNode;

  
    if (strcmp(newData.country, "������") != 0) {
        cherga* newchergaHead = new cherga;
        newchergaHead->data = newData;
        newchergaHead->next = NULL;

        if (chergaHead == NULL) {
            chergaHead = newchergaHead;
        }
        else {
            cherga* chergaCurrent = chergaHead;
            while (chergaCurrent->next != NULL) {
                chergaCurrent = chergaCurrent->next;
            }
            chergaCurrent->next = newchergaHead;
        }
    }

  
    if (newData.year > maxYear) {
        stack* newStackNode = new stack;
        newStackNode->data = newData;
        newStackNode->next = stackHead;
        stackHead = newStackNode;
    }
}
void sortList(mylist*& head) {
    if (head == NULL || head->next == NULL) {
        return;
    }
    bool swapped;
    mylist* ptr;
    mylist* lastPtr = NULL;

    do {
        swapped = false;
        ptr = head;

        while (ptr->next != lastPtr) {
            if (strcmp(ptr->data.name, ptr->next->data.name) > 0) {
             
                student temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = true;
            }
            ptr = ptr->next;
        }
        lastPtr = ptr;
    } while (swapped);
}
void addToOrderedList(mylist*& head, student newData) {
    mylist* newNode = new mylist;
    newNode->data = newData;
    newNode->next = NULL;

    if (head == NULL || strcmp(newData.name, head->data.name) < 0) {
       
        newNode->next = head;
        head = newNode;
        return;
    }

    mylist* current = head;
    while (current->next != NULL && strcmp(newData.name, current->next->data.name) > 0) {
       
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}
void editcountry(mylist* head) {





}

void printCountries(mylist* head) {
    
    string countries[100]; 
    int count = 0;

   
    while (head != NULL) {
        bool found = false;
        for (int i = 0; i < count; ++i) {
            if (strcmp(head->data.country, countries[i].c_str()) == 0) {
                found = true;
                break;
            }
        }
        if (!found) {
            countries[count] = head->data.country;
            count++;
        }
        head = head->next;
    }

 
    cout << "������ ����:" << endl;
    for (int i = 0; i < count; ++i) {
        cout << countries[i] << endl;
    }
}
void printMenu() {
    cout << "���� ������ �����:" << std::endl;
    cout << "1. ��������� ������, ����� �� �����" << std::endl;
    cout << "2. ���� ������ ��������, ����� �� �����" << std::endl;
    cout << "3. ��������� ��������" << std::endl;
    cout << "4. ���������� ������ ��������" << std::endl;
    cout << "5. ��������� �������������� ������ ��������" << std::endl;
    cout << "6. ����������� ����� ��������" << std::endl;
    cout << "7. ���� ��� ����" << std::endl;
    cout << "��� ���� (�������� 13 ��� ������): ";
}
