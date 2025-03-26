// 循环链表
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;

// 初始化链表（头节点）
Node* InitList()
{
	Node* list = (Node*)malloc(sizeof(Node));
	list->data = 0; //存储多少个节点
	list->next = list;
	return list;
}

// 头插法
void headInsert(Node* list, int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = list->next;
	list->next = node;
}

// 尾插法
void tailInsert(Node* list, int data) 
{
	Node* n = list;
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	while (n->next != list)
	{
		n = n->next;
	}
	node->next = list;
	n->next = node;
}

// 删除
int deleteNode(Node* list, int data)
{
	Node* node = list->next;
	Node* preNode = list;
	while (node != list)
	{
		if (node->data == data)
		{
			preNode->next = node->next;
			free(node);
			return 1;
		}
		preNode = node;
		node = node->next;
	}
	return 0;
}
void printList(Node* list) 
{
	Node* node = list->next;
	while (node!=list)
	{
		printf("%d\n", node->data);
		node = node->next;
	}
	printf("NULL\n");
}

int main()
{
	Node* L = InitList();
	headInsert(L, 1);
	headInsert(L, 2);
	headInsert(L, 3);
	headInsert(L, 4);
	tailInsert(L, 5);
	tailInsert(L, 6);
	tailInsert(L, 7);

	if (deleteNode(L, 1))
	{
		printf("删除成功\n");
	}
	else {
		printf("删除失败\n");
	}

	printList(L);
	
	return 0;
}
