#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
using namespace std;
typedef  long long LL;
const int inf = 1 << 30;
const LL maxn = 1010;

int n;
double G[maxn][maxn];
struct node {
    int x, y;
    int p;
    node(int xx, int yy, int pp) {x = xx, y = yy, p = pp;}
    node() {}
} point[maxn];

double d[maxn];
bool vst[maxn];
double maxD[maxn][maxn];   //MST�д�i->j�����Ȩֵ
int pre[maxn];          //ĳһ�㸸�ڵ�
bool mst[maxn][maxn];   //�õ��Ƿ��Ѿ���MST��
typedef pair<int, int> P;

double Prim(int s) {
    for(int i = 0; i <= n; ++i){
        d[i] = inf;
        pre[i] = s;
        vst[i] = 0;
        for(int j = 0; j <= n; ++j){
            maxD[i][j] = 0;
            mst[i][j] = 0;
        }
    }
    priority_queue<P, vector<P>, greater<P> > q;
    q.push(P(d[s] = 0, s));
    double sum = 0;
    while(!q.empty()) {
        P cur = q.top();
        q.pop();
        int k = cur.second;
        if(vst[k])
            continue;
        vst[k] = 1;
        sum += d[k];
        mst[k][pre[k]] = mst[pre[k]][k] = 1; //���뵽MST��
        for(int j = 1; j <= n; ++j) {
            if(vst[j] && j != k)
                maxD[k][j] = maxD[j][k] = max(maxD[pre[k]][j], d[k]);
            if(G[k][j] < d[j]) {
                d[j] = G[k][j];
                pre[j] = k;                     //���¸��ڵ�
                q.push(P(d[j], j));
            }
        }
    }
    return sum;
}

double getDis(int x1, int y1, int x2, int y2) {
    return sqrt((double)(x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

int main() {
    int T, x, y, z;
    scanf("%d",&T);
    while(T--) {
        scanf("%d", &n);
        for(int i = 0; i <= n; ++i){
            point[i] = node(0, 0, 0);
            for(int j = 0; j <= n; ++j)
                G[i][j] = inf;
        }
        for(int i = 1; i <= n; ++i) {
            scanf("%d%d%d", &x, &y, &z);
            point[i] = node(x, y, z);
        }
        for(int i = 1; i < n; ++i)
            for(int j = i+1; j <= n; ++j)
                G[i][j] = G[j][i] = getDis(point[i].x, point[i].y, point[j].x, point[j].y);

        //ö��ɾ��, �ҳ����ֵ
        double B = Prim(1), A, ans = -1;
        for(int i = 1; i < n; ++i)
            for(int j = i+1; j <= n; ++j){
                A = point[i].p + point[j].p;
                //������δ��MST��ʹ��, ���Լӱ߲�ɾȥ���ɻ��е����, ��ʹ����ֱ�ӱ�0
                if(mst[i][j]){
                    ans = max(ans, A/(B - G[i][j]));
                }else{
                    ans = max(ans, A/(B - maxD[i][j]));
                }
            }
        printf("%.2f\n", ans);
    }

    return 0;
}
