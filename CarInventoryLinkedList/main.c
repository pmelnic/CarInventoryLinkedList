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
//Inseram la inceputul listei
void insertAtBeginning(Node** start, Car car) {
	Node* newNode = malloc(sizeof(Node));
	newNode->car = car;	
	newNode->next = *start;
	*start = newNode;
}
//Inseram la finalul listei
void insertAtEnd(Node** start, Car car) {
	Node* newNode = malloc(sizeof(Node));
	newNode->car = car;
	newNode->next = NULL;
	if (*start != NULL) {
		Node* temporar = *start;
		while (temporar->next != NULL) {
			temporar = temporar->next;
		}
		temporar->next = newNode;

	}
	else {
		*start = newNode;
	}
}
//Stergem de la finalul Listei
Car deleteFromBeginning(Node** start) {
	//Verificam daca lista este goala
	if (*start != NULL) {
		Node* deleted = *start;
		*start = (*start)->next;
		
		Car deletedCar = deleted->car;
		
		free(deleted);
		return deletedCar;
	}
	else {
		printf("List is empty\n");
		Car err = { .year = 0, .manufacturer = "ERR", .cc = 0 };
		return err;
	}
}


void printCar(Car car) {
	printf("%s from %d has %5.2f\n", car.manufacturer, car.year, car.cc);
}
void parseListAndPrint(Node* start) {
	while (start!= NULL) {
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

	Car c2;
	c2.year = 2025;
	c2.manufacturer = malloc(strlen("Audi") + 1);
	strcpy(c2.manufacturer, "Audi");
	c2.cc = 98.5;
	insertAtBeginning(&list, c2);
	
	Car c3;
	c3.year = 2030;
	c3.manufacturer = malloc(strlen("Mercedes") + 1);
	strcpy(c3.manufacturer, "Mercedes");
	c3.cc = 98.5;
	deleteFromBeginning(&list);
	insertAtEnd(&list, c3);
	parseListAndPrint(list);
	Car deletedCar = deleteFromBeginning(&list);
	printCar(deletedCar);
	
	return 0;
}