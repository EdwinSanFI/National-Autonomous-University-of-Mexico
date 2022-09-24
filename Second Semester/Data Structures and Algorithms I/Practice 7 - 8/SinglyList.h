#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct List List;

List createList();
void print_list(List);
void insertNodeBeginning(List*,int);
void insertNodeEnd(List*,int);
void deleteNodeBeginning(List*);
void deleteNodeEnd(List*);
int primerElemento(List);

int tamano(List);

void insertNodeSpecificPosition(List*, int, int);
void deleteSpecificNode(List*, int);
int searchNode(List, int);
void deleteNodesLessThan(List* ,int);