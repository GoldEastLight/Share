

#include"linklist.h"
#include"stdio.h"
typedef struct _tag_LinkList 
{
	LinkListNode header;
	int length;
}TLinkList;
LinkList* LinkList_Create()
{
	TLinkList* tmp = NULL;
	tmp = (TLinkList*)malloc(sizeof(TLinkList));
	if (tmp == NULL)
	{
		printf("func LinkList_Create() err \n");
		return NULL;
	}
	memset(tmp , 0, sizeof(TLinkList));
	tmp->length = 0;
	//tmp->node.next = NULL;
	return NULL;
}

void LinkList_Destroy(LinkList* list)
{
	if (list != NULL)
	{
		free(list);
	}
	return NULL;
}


void LinkList_Clear(LinkList* list)
{
	if (list == NULL)
	{
		return;
	}
	TLinkList*tmp = (TLinkList*)list;
	tmp->header.next = NULL;
	tmp->length = 0;
	return NULL;
}


int LinkList_Length(LinkList* list)
{
	if (list == NULL)
	{
		return;
	}
	TLinkList*tmp = (TLinkList*)list;

	return tmp->length;
}


int LinkList_Insert(LinkList* list, LinkListNode* node, int pos)
{
	if (list == NULL || node == NULL || pos < 0)
	{
		return -1;
	}
	TLinkList* tmp = (TLinkList*)list;
	LinkListNode *current = &(tmp->header);
	for (int i = 0; i < pos; i++)
	{
		current = current->next;
	}
	node->next = current->next;
	current->next = node;
	tmp->length++;
	return 0;
}


LinkListNode* LinkList_Get(LinkList* list, int pos)
{
	return NULL;
}


LinkListNode* LinkList_Delete(LinkList* list, int pos)
{
	return NULL;
}


