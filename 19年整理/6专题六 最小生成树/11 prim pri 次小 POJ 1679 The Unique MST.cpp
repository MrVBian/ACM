#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 110;

int n, m, G[maxn][maxn];
int d[maxn];
bool vst[maxn];
int maxD[maxn][maxn];   //MST�д�i->j�����Ȩֵ
int pre[maxn];          //ĳһ�㸸�ڵ�
bool mst[maxn][maxn];   //�õ��Ƿ��Ѿ���MST��
typedef pair<int, int> P;

int Prim(int s) {
    for(int i = 0; i <= n; ++i){
        d[i] = inf;
        vst[i] = 0;
        pre[i] = s;
        for(int j = 0; j <= n; ++j){
            mst[i][j] = 0;
            maxD[i][j] = 0;
        }
    }
    priority_queue<P, vector<P>, greater<P> > q;
    q.push(P(d[s]=0, s));
    int sum = 0;
    while(!q.empty()) {
        P cur = q.top();
        q.pop();
        int k = cur.second;
        if(vst[k]) continue;
        vst[k] = 1;
        sum += d[k];
        mst[k][pre[k]] = mst[pre[k]][k] = true; //���뵽MST��
        for(int j = 1; j <= n; ++j) {
            if(vst[k] && G[k][j] < inf)          //ֻ����MST�е�
                maxD[k][j] = maxD[j][k] = max(maxD[pre[k]][k], d[k]);
            if(G[k][j] < d[j]) {
                d[j] = G[k][j];
                pre[j] = k;                     //���¸��ڵ�
                q.push(P(d[j], j));
            }
        }
    }
    return sum;
}

int main() {
    int T, x, y, z;
    scanf("%d", &T);
    while(T--) {
        memset(G, inf, sizeof(G));
        scanf("%d%d", &n, &m);
        while(m--) {
            scanf("%d%d%d", &x, &y, &z);
            G[x][y] = G[y][x] = z;
        }
        int ans = Prim(1);
        bool flag = false;  // ��С�������Ƿ������С������
        for(int u = 1; u <= n && !flag; ++u) {
            for(int v = 1; v <= n; ++v) {
                if(mst[u][v] || G[u][v]==inf)// ö������δʹ�õı�, �жϸñ�<i, j> Ȩֵ�Ƿ����maxd[i][j]
                    continue;
                if(G[u][v] == maxD[u][v]) {// ��<i, j> Ȩֵ����maxd[i][j]˵����Ψһ
                    flag = true;
                    break;
                }
            }
        }
        if(flag)
            printf("Not Unique!\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}
