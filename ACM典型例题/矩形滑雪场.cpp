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


//trs喜欢滑雪。他来到了一个滑雪场，这个滑雪场是一个矩形，为了简便，我们用r行c列的矩阵来表示每块地形。为了得到更快的速度，滑行的路线必须向下倾斜。         例如样例中的那个矩形，可以从某个点滑向上下左右四个相邻的点之一。例如24-17-16-1，其实25-24-23…3-2-1更长，事实上这是最长的一条。
//输入格式：
//第1行:  两个数字r，c(1< =r,c< =100)，表示矩阵的行列。 第2..r+1行:每行c个数，表示这个矩阵。
//输出格式：
//仅一行:  输出1个整数，表示可以滑行的最大长度。
//
//样例输入
//5 5
//1 2 3 4 5
//16 17 18 19 6
//15 24 25 20 7
//14 23 22 21 8
//13 12 11 10 9
//样例输出
//25
