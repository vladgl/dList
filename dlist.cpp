#include"dList.h"
dList* createDList()
{
	dList *tmp = (dList*)malloc(sizeof(dList));
	tmp->head = tmp->tail = NULL;
	return tmp;
}
void deleteDList(dList **plist)
{
	Node *tmp = (*plist)->head;
	Node *next = NULL;
	while (tmp != NULL)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(*plist);
	(*plist) = NULL;
}
void pushFront(dList *list, char *str)
{
	Node *tmp = (Node*)malloc(sizeof(Node));

	strcpy_s(tmp->str, 50 * sizeof(char), str);
	tmp->next = list->head;
	tmp->prev = NULL;

	if (list->head != NULL)
		list->head->prev = tmp;

	if (list->tail == NULL)
		list->tail = tmp;
	list->head = tmp;
}
void popFront(dList *list)
{
	if (list->head != NULL)
	{
		Node *tmp = NULL;
		tmp = list->head;
		if (list->head == list->tail)
			list->head = list->tail = NULL;
		else {
			list->head = list->head->next;
			list->head->prev = NULL;
		}
		free(tmp);
	}
}
void pushBack(dList *list, char *str)
{
	Node *tmp = (Node*)malloc(sizeof(Node));

	strcpy_s(tmp->str, 50 * sizeof(char), str);
	tmp->prev = list->tail;
	tmp->next = NULL;

	if (list->tail != NULL)
		list->tail->next = tmp; 

	if (list->head == NULL)
		list->head = tmp;
	list->tail = tmp;
}
void popBack(dList *list)
{
	if (list->tail != NULL)
	{
		Node *tmp = NULL;
		tmp = list->tail;
		if (list->head == list->tail)
			list->head = list->tail = NULL;
		else {
			list->tail = list->tail->prev;
			list->tail->next = NULL;
		}
		free(tmp);
	}
}
Node *getNth(dList *list, int n)  //нумерация элементов списка начинается с нуля!
{
	Node *tmp = list->head;

	int i = 0;

	while ((tmp != NULL) && (i < n))
	{
		tmp = tmp->next;
		i++;
	}
	return tmp;
}
void insert(dList* list, int n, char *s)   //вставка на n-ую позицию (то есть, перед элементом с номером n при нумерации с 0)
{
	Node *tmp = getNth(list, n);
	Node *node = (Node*)malloc(sizeof(Node));

	strcpy_s(node->str, 50 * sizeof(char), s);

	if (tmp == NULL) {
		printf("List is empty or list overflow!\n");
		return;
	}
	if (tmp->prev == NULL)
	{
		node->next = tmp;
		node->prev = NULL;
		list->head = node;
		tmp->prev = node;
	}
	else {
		node->next = tmp;
		node->prev = tmp->prev;
		tmp->prev->next = node;
		tmp->prev = node;
	}
}
void deleteNth(dList* list, int n)  //нумерация с 0!
{
	Node *tmp = getNth(list, n);

	if (tmp == NULL) {
		printf("List is empty or list overflow!\n");
		return;
	}
	if (tmp->next != NULL)
	{
		tmp->next->prev = tmp->prev;
		if (tmp->prev != NULL)
			tmp->prev->next = tmp->next;
		else list->head = tmp->next;
	}
	else
	{
		list->tail = tmp->prev;
		if (tmp->prev != NULL)
			tmp->prev->next = NULL;
		else list->head = NULL;
	}
	free(tmp);
}
void printList(dList *list)
{
	Node *tmp = list->head;
	while (tmp != NULL)
	{
		printf("%s ", tmp->str);
		tmp = tmp->next;
	}
	printf("\n");
}
void printReverseList(dList *list)
{
	Node *tmp = list->tail;
	while (tmp != NULL)
	{
		printf("%s ", tmp->str);
		tmp = tmp->prev ;
	}
	printf("\n");
}