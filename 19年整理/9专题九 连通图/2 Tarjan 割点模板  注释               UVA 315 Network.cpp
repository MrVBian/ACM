
/**
����
һ������u�Ǹ�㣬���ҽ�������(1)��(2)
(1) uΪ��������u�ж���һ��������
(2) u��Ϊ���������������(u,v)Ϊ��֦��(��� ���ӱߣ���uΪv���������еĸ���)��ʹ�� dfn(u)<=low(v)��
��Ҳ����˵ V û�취�ƹ� u �㵽��� u dfnҪС�ĵ㣩
ע��������˵������ָ��DFS�µ�������*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

#define N 10010
int dfn[N];  ///�������ȱ�����������ʱ��
int low[N];///��������ܵ���֮ǰ�����ʱ���
int Father[N];///��������ڵ�ĸ��׽ڵ�
int n,Time;
vector<vector<int> >G;

void init() {
    G.clear();
    G.resize(n+1);
    memset(low,0,sizeof(low));
    memset(dfn,0,sizeof(dfn));
    memset(Father,0,sizeof(Father));
    Time=0;
}

void Tarjan(int u,int fa) {
    low[u]=dfn[u]=++Time;
    Father[u]=fa;
    int len=G[u].size(), v;
    for(int i=0; i<len; i++) {
        v=G[u][i];
        if(!dfn[v]) {
            Tarjan(v,u);
            low[u]=min(low[u],low[v]);
        } else if(fa!=v)
            low[u]=min(dfn[v],low[u]);
    }
}

void solve() {
    int Rootson=0,ans=0;  ///���ڵ���ӵ�����
    bool Cut[N]= {false}; ///������飬�ж�������Ƿ��Ǹ��


    Tarjan(1,0);ge'dian

    for(int i=2; i<=n; i++) {
        int v=Father[i];
        if(v==1)  ///Ҳ�Ǿ�˵ i�ĸ����Ǹ��ڵ�
            Rootson++;
        else if(dfn[v]<=low[i])  ///�ж��Ƿ�����������2��
            Cut[v]=true;
    }
    for(int i=2; i<=n; i++) {
        if(Cut[i])
            ans++;
    }
    if(Rootson>1)  ///����������1��
        ans++;
    printf("%d\n",ans);
}

int main() {
    while(scanf("%d",&n),n) {
        int a,b;
        char ch;
        init();
        while(scanf("%d",&a),a) {
            while(scanf("%d%c",&b,&ch)) {
                G[a].push_back(b);
                G[b].push_back(a);
                if(ch=='\n')
                    break;
            }
        }
        solve();
    }
    return 0;
}
