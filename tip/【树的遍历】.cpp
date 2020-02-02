#include <iostream>
#include <stack>
#include <malloc.h>
#include <cstdio>
#include <queue>
using namespace std;
typedef struct node {
    char data;
    struct node *lchild;
    struct node *rchild;
    int flag;
    node(int x) : data(x), lchild(NULL), rchild(NULL), flag(0) {}
}BiNode,*BiTree;

int k=0;
void createTree(BiTree &T)   //����ݹ鴴����������ע����������ͣ�T�������� "*&" ,����� "**" �����ԼӸĶ���OK...
{
    char ch;
    cin.get(ch).get();
    if (ch==' ') T=NULL;
    else{
        T=(BiTree)malloc(sizeof(BiNode));
        T->data=ch;
        T->flag=k++;
        createTree(T->lchild);
        createTree(T->rchild);
    }
}

//�ݹ�

//�������
void PreOrderTraversal(BiTree BT)
{
	if(BT){
		printf("%c  ",BT->data);
		PreOrderTraversal(BT->lchild);
		PreOrderTraversal(BT->rchild);
	}
}


//�������
void InOrderTraversal(BiTree BT)
{
	if(BT){
		InOrderTraversal(BT->lchild);
		printf("%c  ",BT->data);
		InOrderTraversal(BT->rchild);
	}
}


//�������
void PostOrderTraversal(BiTree BT)
{
	if(BT){
		PostOrderTraversal(BT->lchild);
		PostOrderTraversal(BT->rchild);
		printf("%c  ",BT->data);
	}
}


//�������
void LeverOrderTraversal(BiTree BT)
{
    queue<BiTree> q;
    BiTree p;
    p=BT;
    q.push(p);
    while(!q.empty()){
        p=q.front();
        q.pop();
        cout<<p->data<<"  ";
        if(p->lchild)
            q.push(p->lchild);
        if(p->rchild)
            q.push(p->rchild);
    }
}


void preOrderNode(BiTree T)          // ǰ�����
{
    stack<BiTree> s;
    BiTree p;
    p=T;
    while (p!=NULL||!s.empty()){
        while (p!=NULL){
            cout<<p->data<<"  ";
            s.push(p);
            p=p->lchild;
        }
        if (!s.empty())
        {
            p=s.top();
            s.pop();
            p=p->rchild;
        }
    }
}


void inOrderNode(BiTree T)       //�������
{
    stack<BiTree> s;
    BiTree p;
    p=T;
    while(p!=NULL||!s.empty()){
        while(p!=NULL){
            s.push(p);
            p=p->lchild;
        }
        if(!s.empty()){
            p=s.top();
            s.pop();
            cout<<p->data<<"  ";
            p=p->rchild;
        }
    }
}


void postOrderNode(BiTree T)          //�������
{
    stack<BiTree> s;
    BiTree p;
    p=T;
    int *Tap=new int[256];
    while(p!=NULL||!s.empty()){
        while(p!=NULL){
            s.push(p);
            Tap[s.top()->flag]=0;
            p=p->lchild;
        }
        while(!s.empty()&&Tap[s.top()->flag]==1){
            cout<<s.top()->data<<"  ";
            s.pop();
        }
        if(!s.empty()){
            p=s.top();
            Tap[s.top()->flag]=1;
            p=p->rchild;
        }
    }
    delete []Tap;
}


void MorrisIn(BiTree T){
    if(T==NULL)
        return;
    BiTree cur,mostRight;
    cur = T;
    mostRight = NULL;
    while( cur != NULL ){
        mostRight = cur->lchild;
        if( mostRight != NULL){
            while( mostRight->rchild != NULL && mostRight->rchild != cur)
                mostRight = mostRight->rchild;
            if( mostRight->rchild == NULL){
                mostRight->rchild = cur;
                cur = cur->lchild;
                continue ;
            }else{
                mostRight->rchild = NULL;
            }
        }
        printf("%c  ",cur->data);
        cur = cur->rchild;
    }
    printf("\n");
}


void MorrisPre(BiTree T){
    if(T==NULL)
        return;
    BiTree cur,mostRight;
    cur = T;
    mostRight = NULL;
    while( cur != NULL ){
//        printf("%c  ",cur->data);
        mostRight = cur->lchild;
        if( mostRight != NULL){
            while( mostRight->rchild != NULL && mostRight->rchild != cur)
                mostRight = mostRight->rchild;
            if( mostRight->rchild == NULL){
                printf("%c  ",cur->data);
                mostRight->rchild = cur;
                cur = cur->lchild;
                continue ;
            }else{
                mostRight->rchild = NULL;
            }
        }else{
            printf("%c  ",cur->data);
        }
        cur = cur->rchild;
    }
    printf("\n");
}


void reverse(BiTree from, BiTree to){
    if (from == to)
        return;
    BiTree x = from, y = from->rchild, z;
    while (1){
        z = y->rchild;
        y->rchild = x;
        x = y;
        y = z;
        if (x == to)
            break;
    }
}


void printReverse(BiTree from, BiTree to){
    reverse(from, to);
    BiTree p = to;
    while (1){
        printf("%c  ",p->data);
        if (p == from)
            break;
        p = p->rchild;
    }
    reverse(to, from);
}


void MorrisPost(BiTree root){
    BiNode dump(0);
    dump.lchild = root;
    BiTree cur = &dump, prev = NULL;
    while (cur){
        if (cur->lchild == NULL)
            cur = cur->rchild;
        else{
            prev = cur->lchild;
            while (prev->rchild != NULL && prev->rchild != cur)
                prev = prev->rchild;
            if (prev->rchild == NULL){
                prev->rchild = cur;
                cur = cur->lchild;
            }else{
                printReverse(cur->lchild, prev);
                prev->rchild = NULL;
                cur = cur->rchild;
            }
        }
    }
    printf("\n");
}


int main()
{
    BiTree T;
    createTree(T);
    cout<<"ǰ�������  �ݹ�   �ǵݹ�"<<endl;
    PreOrderTraversal(T);cout<<endl;//ǰ�����
    preOrderNode(T);cout<<endl;//�ǵݹ�
    cout<<endl;

    cout<<"���������  �ݹ�   �ǵݹ�"<<endl;
    InOrderTraversal(T);cout<<endl;//�������
    inOrderNode(T);cout<<endl;//�ǵݹ�
    cout<<endl;

    cout<<"���������  �ݹ�   �ǵݹ�"<<endl;
    PostOrderTraversal(T);cout<<endl;//�������
    postOrderNode(T);cout<<endl;//�ǵݹ�
    cout<<endl;

    cout<<"���������  �ǵݹ�"<<endl;
    LeverOrderTraversal(T);cout<<endl;//�������
    cout<<endl;

    cout<<"Morris������  ǰ��   ����   ����"<<endl;
    MorrisPre(T);
    MorrisIn(T);
    MorrisPost(T);
}
//A B D     F E       C G   H     I5
