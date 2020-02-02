#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

//��С���������ģ��.���������������ͼʱ�ѷ���ȡ�����ɡ�
//�����ת���������ʱ��Ҫ��ֳ���������ߡ������μӱߡ�
const int maxn = 1010;
const int maxm = 1000200;
const int inf = 0x3f3f3f3f;

struct Edge {
    int v, cap, cost, next;
} p[maxm << 1];

int e, sumFlow, st, en;
int head[maxn], dis[maxn], pre[maxn];
bool vis[maxn];
void init() {
    e = 0;
    memset(head, -1, sizeof(head));
}

void addEdge(int u, int v, int cap, int cost) {
    p[e].v = v;
    p[e].cap = cap;
    p[e].cost = cost;
    p[e].next = head[u];
    head[u] = e++;
    p[e].v = u;
    p[e].cap = 0;
    p[e].cost = -cost;
    p[e].next = head[v];
    head[v] = e++;
}

bool spfa(int s,int t, int n) {
    int u, v;
    queue<int>q;
    memset(vis, false, sizeof(vis));
    memset(pre, -1, sizeof(pre));
    for(int i = 0; i <= n; i++)
        dis[i] = inf;
    vis[s] = true;
    dis[s] = 0;
    q.push(s);
    while(!q.empty()) {
        u = q.front();
        q.pop();
        vis[u] = false;
        for(int i = head[u]; i != -1; i = p[i].next) {
            v = p[i].v;
            if(p[i].cap && dis[v] > dis[u] + p[i].cost) {
                dis[v] = dis[u] + p[i].cost;
                pre[v] = i;
                if(!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
    }
    if(dis[t] == inf)
        return false;
    return true;
}

int MCMF(int s, int t, int n) {
    int flow = 0; // ������
    int minflow, mincost;
    mincost = 0;
    while(spfa(s, t, n)) {
        minflow = inf + 1;
        for(int i = pre[t]; i != -1; i = pre[p[i^1].v]) {
            if(p[i].cap < minflow) {
                minflow = p[i].cap;
            }
        }
        flow += minflow;
        for(int i = pre[t]; i != -1; i = pre[p[i^1].v]) {
            p[i].cap -= minflow;
            p[i^1].cap += minflow;
        }
        mincost += dis[t] * minflow;
    }
    sumFlow = flow; // �����
    return mincost;
}

int n, m, k;
int a[60][60], b[60][60], c[60][60][60];
int sup[60], need[60];

int main() {
    while(~scanf("%d %d %d", &n, &m, &k) && n && m && k) {
        memset(need, 0, sizeof(need));
        memset(sup, 0, sizeof(sup));
        int v;
        int sp = 0, tp = n+m+1;

        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= k; ++j) {
                scanf("%d", &a[i][j]); // ��ʾi����Ҫ����Ʒj����
                need[j] += a[i][j];// ��ʾ�������Ʒj����
            }
        }
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= k; ++j) {
                scanf("%d", &b[i][j]);// ��ʾ�洢�ڸù�Ӧ�ص�i����Ʒj����
                sup[j] += b[i][j];// ��ʾ��Ʒj�ܴ������
            }
        }
        for(int p = 1; p <= k; ++p) {
            for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= m; ++j) {
                    scanf("%d", &c[p][i][j]);// ��p�������һ����λ�ӵ�j����Ӧ�����͵���i������
                }
            }
        }
        int flag = 0;
        for(int i = 1; i <= k; ++i) {
            if(sup[i] < need[i]) {
                flag = 1;
                break;
            }
        }
        if(flag) {
            printf("-1\n");
            continue;
        }
        // 0 -> ��Ӧ�� -> ��� -> n+m+1
        int ans=0;
        for(int i=1; i<=k; i++) {
            init();
            for(int j=1; j<=m; j++)
                addEdge(sp,j,b[j][i],0);
            for(int j=1; j<=n; j++)
                addEdge(j+m,tp,a[j][i],0);

            for(int j=1; j<=n; j++)
                for(int l=1; l<=m; l++) {
                    addEdge(l,j+m,inf,c[i][j][l]);
                }
            ans += MCMF(0, n+m+1, n+m+1);
//            printf("%4d\n", ans);
        }

        printf("%d\n", ans);
    }
    return 0;
}
