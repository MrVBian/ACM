#include<iostream>
#include<climits>
#include<cstdio>
#include<queue>
using namespace std;

typedef struct HeapStruct{
    int *Data;
    int Size;
    int Capacity;
}*MaxHeap;

MaxHeap Create(int MaxSize)
{
    MaxHeap H=new HeapStruct;
    H->Data=new int [MaxSize+1];
    H->Size=0;
    H->Capacity=MaxSize;
    H->Data[0]=INT_MAX;
    return H;
}

bool IsFull(MaxHeap H)
{
    return H->Size==H->Capacity;
}

bool IsEmpty(MaxHeap H)
{
    return H->Size==0;
}

void Insert(MaxHeap H,int item)
{
    int i;
    if(IsFull(H)){
        printf("��������");
        return;
    }
    i=++H->Size;
    for(;H->Data[i/2]<item;i/=2)
        H->Data[i]=H->Data[i/2];
    H->Data[i]=item;
}

int DeleteMax(MaxHeap H)
{
    int Parent,Child;
    int MaxItem,temp;
    if(IsEmpty(H)){
        printf("������Ϊ��");
        return -1;
    }
    MaxItem=H->Data[1];//ȡ����������ֵ
    //�����������һ��Ԫ�شӸ���㿪ʼ���Ϲ����²���
    temp=H->Data[H->Size--];
    for(Parent=1;Parent*2<=H->Size;Parent=Child){
        Child = Parent * 2;
        if( (Child!=H->Size) &&
            (H->Data[Child] < H->Data[Child+1]) )
            Child++;//Childָ�������ӽ��Ľϴ���
        if(temp>=H->Data[Child])    break;
        else//�ƶ�tempԪ�ص���һ��
            H->Data[Parent]=H->Data[Child];
    }
    H->Data[Parent]=temp;
    return MaxItem;
}

void LeverOrderTraversal(MaxHeap H)
{
    for(int i=1;i<=H->Size;i++)
        cout<<H->Data[i]<<"  ";
}

int main()
{
    cout<<"������"<<endl;
    MaxHeap H;
    H=Create(10);
    int n,m;
    cout<<"���������Ԫ�ظ�����";
    cin>>n;
    cout<<"���������Ԫ��ֵ��";
    for(int i=0;i<n;i++){
        cin>>m;
        Insert(H,m);
    }
    cout<<"���������";
    LeverOrderTraversal(H);
    cout<<endl;
    cout<<"ɾ���ĶѶ�"<<endl;
    DeleteMax(H);
    cout<<"���������";
    LeverOrderTraversal(H);
}
