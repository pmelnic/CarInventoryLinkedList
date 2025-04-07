#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
typedef struct Car Car;
typedef struct Node Node;
struct Car {
	int Year;
	char* manufacturer;
	float cc;
};

struct Node {
	Car car;
	Node* next;
};



int main() {
	return 0;
}