#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define _ref(i,a,b) for(int i=(a);i<=(b);i++)
typedef struct node{
    int h;
    int x;
    int y;
}Node;

bool cmp(Node a,Node b)
{
    if(a.h>b.h) return true;
    return false;
}

int dp[10001];

int main()
{
    int r,c;
    cin>>r>>c;
    Node a[r*c+1];
    int k=0;
    _ref(i,1,r)
    _ref(j,1,c){
        cin>>a[++k].h;
        a[k].x=i,a[k].y=j;
    }
    sort(a+1,a+k+1,cmp);
//    for(int i=1;i<=k;i++)
//        cout<<a[i].h<<' ';

    int Max=1;
    _ref(i,1,k){
        dp[i]=1;
        _ref(j,1,i-1){
            if( ((a[i].x==a[j].x&&abs(a[i].y-a[j].y)==1) ||
                 (a[i].y==a[j].y&&abs(a[i].x-a[j].x)==1))&&a[i].h<a[j].h )
                  dp[i]=max(dp[i],dp[j]+1);
        }
        Max=max(Max,dp[i]);
    }
    cout<<Max;
}


//trsϲ����ѩ����������һ����ѩ���������ѩ����һ�����Σ�Ϊ�˼�㣬������r��c�еľ�������ʾÿ����Ρ�Ϊ�˵õ�������ٶȣ����е�·�߱���������б��         ���������е��Ǹ����Σ����Դ�ĳ���㻬�����������ĸ����ڵĵ�֮һ������24-17-16-1����ʵ25-24-23��3-2-1��������ʵ���������һ����
//�����ʽ��
//��1��:  ��������r��c(1< =r,c< =100)����ʾ��������С� ��2..r+1��:ÿ��c��������ʾ�������
//�����ʽ��
//��һ��:  ���1����������ʾ���Ի��е���󳤶ȡ�
//
//��������
//5 5
//1 2 3 4 5
//16 17 18 19 6
//15 24 25 20 7
//14 23 22 21 8
//13 12 11 10 9
//�������
//25
