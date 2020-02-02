#include<iostream>
#include<queue>
#include<cstddef>
using namespace std;

typedef struct BinNode *BinTree;
struct BinNode{
    int Data;
    BinTree Left;
    BinTree Right;
};


//�����������Ĳ����㷨
BinTree Insert(BinTree T,int x)
{
    if(!T){
        T=new BinNode;
        T->Data=x;
        T->Right=T->Left=NULL;
    }else{
        if(T->Data>x)
            T->Left=Insert(T->Left,x);
        else if(T->Data<x)
            T->Right=Insert(T->Right,x);
        else
            ;//�Ѵ��ڸ�ֵ
    }
    return T;
}

BinTree CreateTree(BinTree T,int n)
{
    int x;
    cin>>x;
    n--;
    T=new BinNode;
    T->Data=x;
    T->Left=T->Right=NULL;
    while(n--){
        cin>>x;
        Insert(T,x);
    }
    return T;
}

void LeverOrderTraversal(BinTree T)
{
    BinTree p;
    p=T;
    queue<BinTree> q;
    q.push(p);
    while(!q.empty()){
        p=q.front();
        q.pop();
        cout<<p->Data<<"  ";
        if(p->Left)
            q.push(p->Left);
        if(p->Right)
            q.push(p->Right);
    }
}

//�ݹ�������
BinTree Find(BinTree T,int x)
{
    if(!T)
        return NULL;
    if(T->Data>x)
        return Find(T->Left,x);
    else if(T->Data<x)
        return Find(T->Right,x);
    else
        return T;
}


//����������
BinTree DFind(BinTree T,int x)
{
    while(T){
        if(T->Data>x)
            T=T->Left;
        else if(T->Data<x)
            T=T->Right;
        else
            return T;
    }
    return NULL;
}


//�ݹ�������С���ֵ
BinTree FindMax(BinTree T)
{
    if(!T)
        return NULL;
    if(!T->Right)
        return T;
    else
        return FindMax(T->Right);
}

BinTree FindMin(BinTree T)
{
    if(!T)
        return NULL;
    if(!T->Left)
        return T;
    else
        return FindMin(T->Left);
}


//�������������Сֵ
BinTree DFindMax(BinTree T)
{
    if(T)
        while(T->Right)
            T=T->Right;
    return T;
}

BinTree DFindMin(BinTree T)
{
    if(T)
        while(T->Left)
            T=T->Left;
    return T;
}


BinTree Delete(BinTree T,int x)
{
    if(!T)
        cout<<"ɾ����ֵ������"<<endl;
    else if(T->Data>x)
        T->Left=Delete(T->Left,x);//���Ե�����ǰд�õ�Find ��Find����ΪNULLʱ���"ɾ����ֵ������"
    else if(T->Data<x)
        T->Right=Delete(T->Right,x);
    else{
        BinTree temp;
        if(T->Right&&T->Left){
            temp=DFindMax(T->Left); //���������ֵ����������Сֵ
          //temp=DFindMin(T->Right);
            T->Data=temp->Data;
            T->Left=Delete(T->Left,T->Data);
          //T->Right=Delete(T->Right,T->Data);
        }
        else{
            temp=T;
            if(!T->Left)
                T=T->Right;
            else if(!T->Right)
                T=T->Left;
            delete temp;
        }
    }
    return T;
}

void InOrderTraversal(BinTree BT)
{
	if(BT){
		InOrderTraversal(BT->Left);
		cout<<BT->Data<<"  ";
		InOrderTraversal(BT->Right);
	}
}

int main()
{
    BinTree T;
    cout<<"��������������Binary Tree������������";
    int n;
    cin>>n;
    cout<<"���������ݣ�";
    T=CreateTree(T,n);
    cout<<"���������";
    LeverOrderTraversal(T);

    cout<<endl;
    cout<<"�������";
    InOrderTraversal(T);


    cout<<endl;
    cout<<"���ֵ�ݹ飺"<<FindMax(T)->Data<<"   �ǵݹ飺"<<DFindMax(T)->Data<<endl;
    cout<<"��Сֵ�ݹ飺"<<FindMin(T)->Data<<"   �ǵݹ飺"<<DFindMin(T)->Data<<endl;

    cout<<"������Ҫɾ����ֵ��";
    cin>>n;
    Delete(T,n);
    cout<<"���������";
    LeverOrderTraversal(T);
}
