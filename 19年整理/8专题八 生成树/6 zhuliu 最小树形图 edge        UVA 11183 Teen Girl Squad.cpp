#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 1010;
int mp[maxn][maxn];
int pre[maxn], belong[maxn], vst[maxn], in[maxn];

struct Edge {
    int from, to, val;
}edge[40010];

int zhuliu(int root, int n, int m) {
    int ret = 0, u, v;
    while(1) {
        // 1����С���
        for(int i=0; i<n; i++) in[i] = inf;
        for(int i=0; i<m; i++)
            if(edge[i].from != edge[i].to && edge[i].val < in[edge[i].to]) {
                pre[edge[i].to] = edge[i].from;
                in[edge[i].to] = edge[i].val;
            }
        for(int i = 0; i < n; ++i){
            if(i == root)
                continue;
            if(in[i] == inf)
                return inf;// ͼ����ͨ������������ͼ
        }
        // 2�һ�
        int cnt = 0;// �����ڵ����
        memset(belong, -1, sizeof belong);
        memset(vst, -1, sizeof vst);
        in[root] = 0;
        for(int i=0; i < n; ++i) {// �ȸ����ϵĵ���
            ret += in[i];//ע�⣺retֻ��zhuliu��ʼʱ���һ�Σ������������ж����ۼӵ�
            v = i;
            while(vst[v] != i && belong[v] == -1 && v != root) {// ���û�л�������Ϊv == root���������л�ʱv��ָ�򻷵����
                vst[v] = i;
                v = pre[v];
            }
            // ��֮ǰ�ĵ�ɸ���ǿ�ǰ�Ƶ����ڵ㣬��֮��ĵ�ɸ���ǿ�ǰ�Ƶ���һ����
            if(v != root && belong[v] == -1) {
                for(int u = pre[v]; u != v; u = pre[u])
                    belong[u] = cnt;
                belong[v] = cnt ++;
            }
        }
        if(cnt == 0)// û�л��ˣ� �ҵ���С����ͼ��
            break;

        // 3���㣬���±��
        for(int i = 0; i < n; ++i)
            if(belong[i] == -1)
                belong[i] = cnt++;
        for(int i = 0; i < m; ) {
            v = edge[i].to;
            edge[i].from = belong[edge[i].from];
            edge[i].to = belong[edge[i].to];
            // ���ڵ��㵽���㣬���������Ȩֵ����Ϊ�Ѿ����һ���ʱ���ۼӹ���������ô�����Ȩֵ����0��ǡ�÷���Ҫ�󡪡���Ȼ���ظ������
            // ���ڵ��㵽�������߻���������Ϊ�õ��һ������Ѿ�ȷ������ֻ����һ��������Ȩֵ=ԭ����Ȩֵ��ȥ�ڻ��ϵ���ߵ�Ȩֵ
            // �����һ���������������ϵ���ߵ�Ȩֵһ��С�ڻ�����ߵ�Ȩֵ��������Ȼ�������in��������󻷵�ʱ�򣬸���������������Ϊ�ǻ�
            if(edge[i].from != edge[i].to) edge[i++].val -= in[v];
            else swap(edge[i], edge[--m]);
        }
        n = cnt;
        root = belong[root];
    }
    return ret;
}

int main() {
    int x, y, z, T, n, m;
    scanf("%d", &T);
    for(int Case = 1; Case <= T; ++Case) {
        memset(mp, inf, sizeof(mp));
        scanf("%d%d", &n, &m);
        for(int i = 0; i < m; ++i) {
            scanf("%d%d%d", &x, &y, &z);
            mp[x][y] = min(mp[x][y], z);// ȥ��
        }
        int top = 0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                if(mp[i][j] != inf) {
                    edge[top].from = i;
                    edge[top].to = j;
                    edge[top++].val = mp[i][j];
                }
        int ans = zhuliu(0, n, m);
        printf("Case #%d: ", Case);
        if(ans == inf) printf("Possums!\n");
        else printf("%d\n", ans);
    }
    return 0;
}
