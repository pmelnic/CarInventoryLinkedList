#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
typedef struct Car Car;
typedef struct Node Node;
struct Car {
	int year;
	char* manufacturer;
	float cc;
};

struct Node {
	Car car;
	Node* next;
};
Node* createNode(Car car) {
	Node* newNode = malloc(sizeof(Node));
	newNode->car = car;
	newNode->next = NULL;
	return newNode;
}
void insertAtBeginning(Node** start, Car car) {
	Node* newNode = malloc(sizeof(Node));
	newNode->car = car;	
	newNode->next = *start;
	*start = newNode;
}
void printCar(Car car) {
	printf("%s from %d has %5.2f\n", car.manufacturer, car.year, car.cc);
}
void parseListAndPrint(Node* start) {
	while (start) {
		printCar(start->car);
		start = start->next;
	}
}



int main() {
	Node* list = NULL;
	Car c;
	c.year = 2020;
	c.manufacturer = malloc(strlen("BMW") + 1);
	strcpy(c.manufacturer, "BMW");
	c.cc = 1998.5;
	insertAtBeginning(&list, c);
	printCar(c);

	return 0;
}