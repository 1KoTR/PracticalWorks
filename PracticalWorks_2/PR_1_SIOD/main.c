#include <stdio.h>
#include <malloc.h>

#define MAX_MONUMENT_NAME 20
#define MAX_MONUMENT_LOCATION 20
#define MAX_MONUMENT_TYPE 10
#define MAX_MONUMENT_ARCHITECT 20

typedef struct monument
{
	char name[MAX_MONUMENT_NAME];
	char location[MAX_MONUMENT_LOCATION];
	char type[MAX_MONUMENT_TYPE];
	char architect[MAX_MONUMENT_ARCHITECT];
	int year;
}
Data;

typedef struct Node
{
	struct Node* pNext;
	struct Node* pPrev;
	Data data;
}
Node;

typedef struct List
{
	size_t size;
	Node* head;
	Node* last;
}
List;

List* CreateList();
void AddElementToList(List*, size_t, Data);
void AddToListFront(List*, Data);
Node* GetElementFromList(List*, size_t);

int main()
{
	List* list = CreateList();

	Data data1;
	data1.year = 100;

	Data data2;
	data2.year = 200;

	Data data3;
	data3.year = 300;

	Data data4;
	data4.year = 400;

	AddToListFront(list, data1);
	AddToListFront(list, data2);
	AddToListFront(list, data3);

	AddElementToList(list, 0, data4);

	printf("\tlist size : %u\n", list->size);
	printf("\telem1 : %d\n", GetElementFromList(list, 0)->data.year);
	printf("\telem2 : %d\n", GetElementFromList(list, 1)->data.year);
	printf("\telem3 : %d\n", GetElementFromList(list, 2)->data.year);
	printf("\telem4 : %d\n", GetElementFromList(list, 3)->data.year);

	getchar();
	return 0;
}

List* CreateList()
{
	List* list = malloc(sizeof(List));

	list->size = 0;
	list->head = NULL;
	list->last = NULL;

	return list;
}
void AddElementToList(List* list, size_t index, Data data)
{
	if (list->size <= index)
	{
		printf("Error : IndexOutOfRange");
	}

	Node* tmp = GetElementFromList(list, index);

	Node *elm = malloc(sizeof(Node));
	elm->pNext = tmp;
	elm->pPrev = tmp->pPrev;
	elm->data = data;

	tmp->pPrev = elm;

	list->size++;
}
void AddToListFront(List* list, Data data)
{
	Node *tmp = malloc(sizeof(Node));

	tmp->pNext = list->head;
	tmp->pPrev = NULL;
	tmp->data = data;

	list->head = tmp;
	list->size++;

	if (list->size == 1)
		list->last = tmp;
}
Node* GetElementFromList(List* list, size_t index)
{
	if (list->size <= index)
	{
		printf("Error : IndexOutOfRange");
	}

	Node* tmp;
	size_t i;
	if (list->size / 2 >= index)
	{
		tmp = list->head;
		i = 0;
		while (i < index)
		{
			tmp = tmp->pNext;
			i++;
		}
	}
	else
	{
		tmp = list->last;
		i = list->size - 1;
		while (i > index)
		{
			tmp = tmp->pPrev;
			i--;
		}
	}
	return tmp;
}
//void DeleteFront(List* list)
//{
//	Node* tmp = list->head;
//	list->head = tmp->pNext;
//	free(tmp);
//	list->size--;
//}
//void DeleteList(List* list)
//{
//	while (list->size)
//		DeleteFront(list);
//	free(list);
//}