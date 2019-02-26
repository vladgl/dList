#pragma once
#include "headers.h"
#include<string.h>
typedef struct Node {
	char str[50];
	struct Node *prev;
	struct Node *next;
} Node;
typedef struct dList {
	Node *head;
	Node *tail;
} dList;
dList* createDList();
void deleteDList(dList**);
void pushFront(dList *, char *);
void popFront(dList*);
void pushBack(dList *, char *);
void popBack(dList*);
Node *getNth(dList*, int);
void insert(dList*, int, char*);
void deleteNth(dList*, int);
void printList(dList*);
void printReverseList(dList*);