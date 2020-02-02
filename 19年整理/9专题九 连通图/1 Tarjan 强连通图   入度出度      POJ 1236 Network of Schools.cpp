#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#include<stack>

using namespace std;

const int maxn = 110;

int n;
int dfn[maxn], low[maxn], vst[maxn];
int belong[maxn];//belong[i]��ʾi�����������ĸ��ڵ�
int cnt;
int out[maxn], in[maxn];
int tot;

struct Edge {
    int v;
    int next;
} edge[maxn*maxn];

int edgecount;
int head[maxn];

void init() {
    edgecount = 0;
    memset(head, -1, sizeof(head));
}

void add(int u, int v) {
    edge[++edgecount].v = v;
    edge[edgecount].next = head[u];
    head[u] = edgecount;
}

stack<int> s;
void Tarjan(int u) { //�ӽڵ�x��ʼ����
    dfn[u] = low[u] = ++tot;
    vst[u] = 1;//Ϊ1��ʾ�ڶ�������
    s.push(u);
    for(int k = head[u]; k != -1; k = edge[k].next) {
        int v = edge[k].v;
        if(!dfn[v]) { //��δ���ʹ�
            Tarjan(v);
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

int main() {
    int v;
    while(~scanf("%d", &n)) {
        init();
        for(int u=1; u<=n; u++) {
            while(scanf("%d",&v) && v!=0)
                add(u,v);
        }
        tot = 0;
        cnt = 0;//�����ĵ���
        for(int i = 0; i <= n; ++i) {
            dfn[i] = low[i] = 0;
            in[i] = out[i] = 0;
            vst[i] = 0;
        }
        for(int i = 1; i <= n; ++i) {
            if(dfn[i] == 0)
                Tarjan(i);
        }
        for(int u = 1; u <= n; ++u) {
            for(int k = head[u]; k != -1; k = edge[k].next) {
                int v = edge[k].v;
                if(belong[u] != belong[v]) {
                    out[belong[u]]++;   // ����belong[u]�ĳ���
                    in[belong[v]]++;    // ����belong[v]�����
                }

            }
        }

        int ans1 = 0;
        int ans2 = 0;
        for(int i = 1; i <= cnt; ++i) {
            if(in[i] == 0)ans1++;
            if(out[i] == 0)ans2++;
        }
        ans2 = max(ans1, ans2);
        if(cnt == 1)printf("1\n0\n");
        else printf("%d\n%d\n", ans1, ans2);
    }
    return 0;
}
