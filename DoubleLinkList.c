#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
	int data;
	struct Node* pre;
	struct Node* next;
} Node;

Node* InitLinkedList()
{
	Node* L = (Node*)malloc(sizeof(Node));
	L->data = 0;
	L->pre = NULL;
	L->next = NULL;
	return L;
}

// ͷ�巨
void headInsert(Node* L, int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	if (L->next == NULL)
	{
		node->next = L->next;
		node->pre = L;
		L->next = node;
	}
	else 
	{
		node->pre = L;
		node->next = L->next;
		L->next->pre = node;
		L->next = node;
	}
	L->data++;
}

void printfList(Node* L)
{
	Node* node = L->next;
	while (node)
	{
		printf("%d\n", node->data);
		node = node->next;
	}
	printf("NULL\n");
}

// β�巨
void tailInsert(Node* L, int data)
{
	Node* node = L;
	Node* n = (Node*)malloc(sizeof(Node));
	n->data = data;
	while (node->next)
	{
		node = node->next;
	}
	n->next = node->next;
	node->next = n;
	n->pre = node;
	L->data++;
}

// ɾ���ڵ�
bool deleteNode(Node* L, int data)
{
	Node* node = L->next;
	while (node)
	{
		if (node->data == data)
		{
			node->pre->next = node->next;
			node->next->pre = node->pre;
			free(node);
			L->data--;
			return true;
		}
		node = node->next;
	}
	return false;
}

int main()
{
	Node* L = InitLinkedList();
	headInsert(L, 1);
	headInsert(L, 2);
	headInsert(L, 3);
	headInsert(L, 4);

	tailInsert(L, 5);
	tailInsert(L, 6);

	if (deleteNode(L, 5)) 
	{
		printf("ɾ���ɹ�!\n");
	}
	else 
	{
		printf("ɾ��ʧ��!\n");
	}
	printf("�ܹ�%d��Ԫ��\n", L->data);
	printfList(L);
	return 0;
}

