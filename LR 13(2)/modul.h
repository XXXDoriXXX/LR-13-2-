#ifndef MODUL_H
#define MODUL_H
struct student {
	char name[30];
	char country[30];
	int year;
	double price;
};
struct mylist
{
	student data;
	mylist* next;
};
struct stack
{
	student data;
	stack* next;
};
struct cherga
{
	student data;
	cherga* next;
};
void printStack(stack* stackHead);
void printQueue(cherga* queueHead);
void printList(mylist* head);
mylist* createList(cherga*& chergaHead, stack*& stackHead, int maxYear);
void addToUnorderedList(mylist*& head, student newData, cherga*& chergaHead, stack*& stackHead, int maxYear);
void sortList(mylist*& head);
void addToOrderedList(mylist*& head, student newData);
//bool editCountry(mylist* head, const char* nameToEdit, const char* newCountry);
void printCountries(mylist* head);
void printMenu();
#endif