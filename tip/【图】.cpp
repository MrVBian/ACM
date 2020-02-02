#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct AdjNode
{
	int data;
	int visit;
	struct AcrNode * pNext;
	struct AdjNode * pNode;
}ADJ,*PADJ;

typedef struct AcrNode
{
	struct AdjNode * node;
	struct AcrNode * pNext;
}ACR,*PACR;

static PADJ pHead;
static int num;
static int n;

void creat();
PADJ findpoint(int count);
void init_visit();
void DFSTraverse(PADJ adj);
void BFSTraverse(PADJ q);

int main()
{
	printf("������ͼ�Ľ������\n");
	scanf("%d",&num);
	printf("������ߵ��ܸ�����\n");
	scanf("%d",&n);

	creat();
	printf("��ȱ���Ϊ��\n");
	DFSTraverse(pHead->pNode);
	printf("\n");
	init_visit();
	printf("��ȱ���Ϊ��\n");
	BFSTraverse(pHead->pNode);
	init_visit();
	printf("\n");

	return 0;
}

void creat()
{
	pHead = (PADJ)malloc(sizeof(ADJ));
	int x,y;
	PACR p,q;
	PADJ pTail = pHead;
	PADJ pT;
	for(int i = 0;i<num;i++)
	{
		PADJ pNew = (PADJ)malloc(sizeof(ADJ));
		printf("�������%d���ڵ���ֵ����ֵ�����ظ�����\n",i+1);
		scanf("%d",&pNew->data);
		pNew->pNext = NULL;
		pNew->pNode = NULL;
		pNew->visit = 0;
		pTail->pNode = pNew;
		pTail = pNew;
	}
	for(int j = 0;j<n;j++)
	{
		printf("����������ӵ����㣨������ֵ��\n");
		scanf("%d %d",&x,&y);
		PACR s1 = (PACR)malloc(sizeof(ACR));
		s1->node = findpoint(y);
		pT = findpoint(x);
		s1->pNext = pT->pNext;
		pT->pNext = s1;
		PACR s2 = (PACR)malloc(sizeof(ACR));
		s2->node = findpoint(x);
		pT = findpoint(y);
		s2->pNext = pT->pNext;
		pT->pNext = s2;
	}
	return;
}

void DFSTraverse(PADJ P)
{
	PACR acr;
	PADJ adj;
	adj = P;
	printf("%d	",adj->data);
	adj->visit = 1;
	if(adj->pNext == NULL)
		return;
	else
		acr = adj->pNext;
	while(acr != NULL)
	{
		if(acr->node->visit == 0)
		{
			DFSTraverse(acr->node);
			acr = acr->pNext;
		}
		else
			acr = acr->pNext;
	}
	return;
}

void BFSTraverse(PADJ q)
{
	PADJ * P = (PADJ *)malloc(num*sizeof(PADJ));
	int front,rear;
	PACR acr;
	PADJ adj;
	adj = q;
	front = rear = -1;
	printf("%d	",adj->data);
	adj->visit = 1;
	P[++rear] = adj;
	while(front != rear)
	{
		adj = P[++front];
		acr = adj->pNext;
		while(acr != NULL)
		{
			adj = acr->node;
			if(adj->visit == 0)
			{
				printf("%d	",adj->data);
				adj->visit = 1;
				P[++rear] = adj;
			}
			acr = acr->pNext;
		}
	}
	return;
}

void init_visit()
{
	PADJ pTail = pHead;
	while(pTail->pNode != NULL)
	{
		pTail->pNode->visit = 0;
		pTail = pTail->pNode;
	}
	return;
}

PADJ findpoint(int count)
{
	PADJ pTail = pHead;
	while(pTail->pNode != NULL)
	{
		if(pTail->pNode->data == count)
		{
			return pTail->pNode;
		}
		pTail = pTail->pNode;
	}
	printf("�޸���ֵ�ĵ�!\n");
	exit(-1);
}

