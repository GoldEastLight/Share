
#define  _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "linklist.h"

typedef struct _tag_LinkList
{
	LinkListNode header;
	int		length;
}TLinkList;
//
LinkList* LinkList_Create()  //O(1)
{
	TLinkList *tmp = NULL;

	tmp = (TLinkList *)malloc(sizeof(TLinkList));
	if (tmp == NULL)
	{
		printf("func LinkList_Create() err \n");
		return NULL;
	}
	memset(tmp, 0, sizeof(TLinkList));
	tmp->length = 0;
	tmp->header.next = NULL; //
	return tmp;
}

void LinkList_Destroy(LinkList* list)  //O(1)
{
	if (list == NULL)
	{
		return ;
	}
	free(list);
	return ;
}

void LinkList_Clear(LinkList* list)   //O(1)
{
	TLinkList *tList = NULL;
	tList = (TLinkList *)list;
	if (tList == NULL)
	{
		return ;
	}
	tList->header.next = NULL;
	tList->length = 0;

	return ;
}

int LinkList_Length(LinkList* list)  //O(1)
{
	TLinkList *tList = NULL;
	tList = (TLinkList *)list;
	if (tList == NULL)
	{
		return -1;
	}
	return tList->length;
}

int LinkList_Insert(LinkList* list, LinkListNode* node, int pos)  //O(n)
{
	int				i = 0;
	LinkListNode	*current = NULL;
	TLinkList		*tList = NULL;

	tList = (TLinkList *)list;
	
	if (list==NULL || node==NULL || pos<0)
	{
		return -1;
	}

	current = &(tList->header);
	for (i=0; i<pos; i++)
	{
		current = current->next;
	}
	//新结点 连接 后继链表
	node->next = current->next;

	//前面的链表 连接 新结点
	current->next = node;

	tList->length ++;
	return 0;
}

LinkListNode* LinkList_Get(LinkList* list, int pos)  //O(n)
{
	int				i = 0;
	LinkListNode	*current = NULL;
	TLinkList		*tList = NULL;

	tList = (TLinkList *)list;

	if (list==NULL || pos<0)
	{
		return NULL;
	}

	current = &(tList->header); //赋值指针变量初始化
	for (i=0; i<pos; i++)
	{
		current = current->next;
	}
	return current->next;
}

LinkListNode* LinkList_Delete(LinkList* list, int pos) //O(n)
{
	int				i = 0;
	LinkListNode	*current = NULL;
	LinkListNode	*ret = NULL;
	TLinkList		*tList = NULL;

	tList = (TLinkList *)list;
	if (list==NULL || pos<0)
	{
		return NULL;
	}

	current = &(tList->header);
	for (i=0; i<pos; i++)
	{
		current = current->next;
	}
	ret = current->next; //缓存要删除的结点

	current->next = ret->next;

	tList->length --;

	return ret;
}

