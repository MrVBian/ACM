#include<iostream>
using namespace std;

int Find(int s[],int x)
{
    for(;s[x]>0;x=s[x]) ;
    return x;
}

int Find2(int s[],int x)//·��ѹ��
{
    if(s[x]<0)
        return x;
    else
        return s[x]=Find2(s,s[x]);
}

int Find3(int s[],int x,int ans=0)//·��ѹ��
{
    if(s[x]<0){
        if(ans>0)
            s[x]=s[x]-ans+1;
        return x;
    }
    else
        return s[x]=Find3(s,s[x],ans+1);
}

void Union(int s[],int Root1,int Root2)//���ȹ鲢  �߶�
{
    if(s[Root2]<s[Root1])
        s[Root1]=Root2;
    else{
        if(s[Root1]==s[Root2])    Root1--;
        s[Root2]=Root1;
    }
}

void Union2(int s[],int Root1,int Root2)//���ȹ鲢  ��ģ
{
    if(s[Root2]<s[Root1]){
        s[Root2]+=s[Root1];
        s[Root1]=Root2;
    }
    else{
        s[Root1]+=s[Root2];
        s[Root2]=Root1;
    }
}

void Traversal(int s[],int n)
{
    for(int i=0;i<n;i++)
        cout<<"�±꣺"<<i<<"  s["<<i<<"]:"<<s[i]<<endl;
}

int main()
{
    cout<<"��������"<<endl;
    int s[10];
    Traversal(s,10);
}
