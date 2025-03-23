// 单链表
#include <stdio.h>
#include <iostream>

typedef struct Node {
	int data;
	Node* next;
}Node;

// 初始化头节点(注意，头节点是一直存在的)
Node* InitHead()
{
	Node* head = new Node();
	head -> data = 0; // 可以表示为有多少个元素
	head -> next = NULL;
	return head;
}

// 头插法
void headInsert(Node* list,int data)
{
	Node* node = new Node();  //创建一个新的节点
	node -> data = data;  // 写入新节点的data数据
	node -> next = list->next;  // 将新节点的next域变为头节点的next域，替代原先的节点next域
	list -> next = node;  //将一直存在的头节点的next域变为新插入的节点
	list -> data++;  // 将头节点的数据域++，意味着加入了一个数据
}

// 尾插法
void tailInsert(Node* list, int data)
{
	// 保存头节点
	Node* head = list;

	Node* node = new Node();
	node -> data = data;
	node -> next = NULL;
	// 寻找最后一个节点
	list = list->next;  //头节点是一直存在的，所以将指针指向头节点的next即是头节点之后的第一个元素
	// 判断什么时候到最后一个节点
	while (list -> next)  // 找到最后一个节点的NULL
	{
		list = list-> next;
	}
	// 跳出循环即找到最后一个节点
	list -> next = node;
	head -> data++;
}
//
//// 删除节点(删除这个data){只能删除最近的数值，有BUG}
void deleteNode(Node* list, int data)
{
	if (list == NULL || list -> next == NULL)
	{
		return;
	}

	// 保存头节点
	Node* pre = list;
	// 当前节点
	Node* current = list -> next;

	while (current)
	{
		if (current->data == data)
		{
			pre -> next = current -> next;
			current->next = NULL;
			free(current);
			break;
		}
		pre = current;
		current = current -> next;
	}
	list->data--;
}
//
void printList(Node* list)
{
	if (list == NULL || list->next == NULL)
	{
		return;
	}
	printf("总共有%d个数据\n", list->data);

	list = list->next;

	while (list)
	{
		printf("%d\n",list->data);
		list = list -> next;
	}
}
//
int main()
{
	Node* list = InitHead();
	headInsert(list, 1);
	headInsert(list, 2);
	headInsert(list, 3);
	headInsert(list, 4);
	headInsert(list, 5);
	tailInsert(list, 6);
	tailInsert(list, 7);
	tailInsert(list, 8);
	tailInsert(list, 9);
	tailInsert(list, 10);
	printList(list);
	deleteNode(list, 5);
	deleteNode(list, 10);
	deleteNode(list, 6);
	printList(list);
	return 0;
}