#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#include<stack>

using namespace std;

const int maxn = 1e5+10;

int n, m;
int dfn[maxn], low[maxn], vst[maxn];
int belong[maxn];//belong[i]��ʾi�����������ĸ��ڵ�
int cnt;
int tot;
int degree[maxn];

struct Edge {
    int v;
    int next;
} edge[maxn * 2];

int edgecount;
int head[maxn];

void init() {
    edgecount = 0;
    memset(head, -1, sizeof(head));
    memset(degree, 0, sizeof(degree));
}

void add(int u, int v) {
    edge[++edgecount].v = v;
    edge[edgecount].next = head[u];
    head[u] = edgecount;
}

stack<int> s;
void Tarjan(int u, int pre) { //�ӽڵ�x��ʼ����
    dfn[u] = low[u] = ++tot;
    vst[u] = 1;//Ϊ1��ʾ�ڶ�������
    s.push(u);
    for(int k = head[u]; k != -1; k = edge[k].next) {
        int v = edge[k].v;
        if(v == pre) // ˫��ͨ���������ܻ���
            continue;
        if(!dfn[v]) { //��δ���ʹ�
            Tarjan(v, u);
            low[u] = min(low[u], low[v]);
        } else if(vst[v]) { //�����ʹ������ڶ�����
            low[u] = min(low[u], dfn[v]);
        }
    }
    if(low[u] == dfn[u]) {
        int x;
        ++cnt;
        while(1) {
            x = s.top();
            s.pop();
            vst[x] = 0;
            belong[x] = cnt;
            if(x == u)
                break;
        }
    }
}

const int Hash = 5010;
bool mp[Hash*Hash];

int main() {
    scanf("%d%d", &n, &m);
    init();
    int x, y;
    for(int i = 0; i < m; ++i){
        scanf("%d%d", &x, &y);
        int v = x * Hash + y; // ȥ�ر�
        if( mp[v] )
            continue;
        mp[x*Hash+y] = 1;
        add(x, y);
        add(y, x);
    }
    tot = 0;
    cnt = 0;// �����ĵ���
    for(int i = 0; i <= n; ++i) {
        dfn[i] = low[i] = 0;
        vst[i] = 0;
    }
    for(int i = 1; i <= n; ++i) {
        if(dfn[i] == 0)
            Tarjan(i, i);
    }
    for(int u = 1; u <= n; ++u) {
        for(int k = head[u]; k != -1; k = edge[k].next) {
            int v = edge[k].v;
            if(belong[u] != belong[v]) {
                degree[belong[u]] ++;   // u v | v u �ظ�����
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= cnt; ++i)
        if(degree[i] == 1)
            ans++;

    printf("%d\n", (ans+1)/2 );

    return 0;
}
