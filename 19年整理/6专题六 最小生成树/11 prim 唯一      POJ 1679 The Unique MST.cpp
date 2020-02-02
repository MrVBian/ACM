#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
const int maxn = 110;
const int inf = 0x3f3f3f3f;
int cas=1;
int n, m;
int G[maxn][maxn], vst[maxn], d[maxn];

void Prim(int s){
    for(int i = 0; i<= n; ++i){
        d[i] = G[s][i];
        vst[i] = 0;
    }
    vst[s] = 1;
    int flag=0, sum=0;

    for(int i = 0; i < n-1; ++i){
        int Min = inf;
        int k = -1;
        for(int j = 1; j <= n; ++j){
            if(!vst[j] && Min > d[j]){
                Min = d[j];
                k = j;
            }
        }
        int ans = 0;// ��¼��ͬȨֵ�ı��м���
        for(int j = 1; j <= n; ++j)
            if(vst[j] && G[k][j] == Min)// �ѱ�ѡ�еĵ����Ƿ����ر�
                ans++;
        if(ans > 1){// �������1,˵��������·Ҳ�ܴﵽ�õ�,��������Ψһ
            flag = 1;
            break;
        }
        vst[k] = 1;
        sum += Min;
        for(int j = 1; j <= n; ++j)
            if(!vst[j] && d[j] > G[k][j])
                d[j] = G[k][j];
    }
    if(flag)
        printf("Not Unique!\n");
    else
        printf("%d\n",sum);
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(i == j)
                    G[i][j] = 0;
                else
                    G[i][j] = inf;
            }
        }
        for(int i = 0; i < m; ++i){
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            G[u][v] = G[v][u] = w;
        }
        Prim(1);   //�ӵ� 1 ��ʼ��.
    }
}
