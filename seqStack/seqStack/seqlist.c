#define  _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "seqlist.h"


//��������ģ�����Ա�
typedef struct _tag_SeqList
{
	int		capacity;
	int		length;
	//int *node[100];
	int		**node;  //int node[capacity] //
					//int *node[capacity];

	//int *node; //   int node[i]===> *(node+i)
}TSeqList;


//���� ����
SeqList* SeqList_Create(int capacity) //O(1)
{
	int			ret;
	TSeqList	*tmp = NULL;
	tmp = (TSeqList *)malloc(sizeof(TSeqList));
	if (tmp == NULL)
	{
		ret =1;
		printf("func SeqList_Create() err :%d \n", ret);
		return NULL;
	}
	memset(tmp, 0, sizeof(TSeqList));
	tmp->capacity = capacity;
	tmp->length = 0;
	tmp->node = (int **)malloc(sizeof(void *) * capacity);
	if (tmp->node == NULL)
	{
		ret = 2;
		printf("func SeqList_Create() malloc err :%d \n", ret);
		return NULL;
	}
	memset(tmp->node, 0, sizeof(void *) * capacity);

	return tmp;
}

//���� ����
int SeqList_Create2(int capacity, SeqList**handle)
{
	int			ret = 0;
	TSeqList	*tmp = NULL;
	tmp = (TSeqList *)malloc(sizeof(TSeqList));
	if (tmp == NULL)
	{
		ret =1;
		printf("func SeqList_Create2() err :%d \n", ret);
		return ret;
	}
	memset(tmp, 0, sizeof(TSeqList));
	tmp->capacity = capacity;
	tmp->length = 0;
	tmp->node = (int **)malloc(sizeof(void *) * capacity);
	if (tmp->node == NULL)
	{
		ret = 2;
		printf("func SeqList_Create2() malloc err :%d \n", ret);
		return ret;
	}

	*handle = tmp;
	return ret;
}

//���� ����
void SeqList_Destroy(SeqList* list)  //O(1)
{
	TSeqList	*tmp = NULL;
	if (list == NULL)
	{
		return ;
	}

	tmp = (TSeqList *)list;

	if (tmp->node != NULL)
	{
		free(tmp->node);
	}
	free(tmp);
	return ;
}

////���� ���
void SeqList_Clear(SeqList* list) //O(1)
{
	TSeqList	*tmp = NULL;
	if (list == NULL)
	{
		return ;
	}

	tmp = (TSeqList *)list;
	tmp->length = 0;
	memset(tmp->node, 0, (tmp->capacity * sizeof(void *)) );

	return ;
}

//���� ����
int SeqList_Length(SeqList* list) //O(1)
{
	TSeqList	*tmp = NULL;
	if (list == NULL)
	{
		return -1;
	}
	tmp = (TSeqList *)list;

	return tmp->length;
}


//���� ���� 
int SeqList_Capacity(SeqList* list) //O(1)
{
	TSeqList	*tmp = NULL;
	if (list == NULL)
	{
		return -1;
	}
	tmp = (TSeqList *)list;
	return tmp->capacity;
}

//���� ��ĳһ��λ�� ����Ԫ��
int SeqList_Insert(SeqList* list, SeqListNode* node, int pos)  //O(n)
{
	TSeqList	*tList = NULL;
	int i = 0;
	if (list == NULL ||  node==NULL)
	{
		return -1;
	}
	tList = (TSeqList *)list;
	//������� 
	if (tList->length >= tList->capacity)
	{
		return -2;
	}

	//posλ�õ��ݴ���
	if (pos > tList->length )
	{
		pos = tList->length;
	}

	for (i=tList->length; i>pos; i--)  //n
	{
		tList->node[i] = tList->node[i-1];
	}

	tList->node[i] = (int* )node; //ok
	tList->length ++;

	return 0;
}

//��ȡĳһ��λ�õ�������
SeqListNode* SeqList_Get(SeqList* list, int pos)  //O(1)
{
	TSeqList	*tList = NULL;
	SeqListNode *tmp = NULL;

	tList = (TSeqList *)list;

	if (list == NULL || pos<0 || pos >=tList->length )
	{
		return NULL;
	}
	tmp = tList->node[pos];

	return tmp;
}

//ɾ��ĳһ��λ�õĽ��
SeqListNode* SeqList_Delete(SeqList* list, int pos)  ////O(n)
{
	int			i = 0;
	TSeqList	*tList = NULL;
	SeqListNode *tmp = NULL; 

	tList = (TSeqList *)list;
	if (list == NULL || pos <0 || pos >= tList->length)
	{
		return NULL;
	}
	tmp = tList->node[pos];

	// pos = 3
	for (i=pos+1; i<tList->length; i++)
	{
		tList->node[i-1] = tList->node[i];

	}
	tList->length --;
	return tmp;
}

