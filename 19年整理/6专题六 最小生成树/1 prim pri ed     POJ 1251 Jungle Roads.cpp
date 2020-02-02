//ͨ������prime���
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<vector>
#include<cstring>
#define Max 0x3f3f3f3f
using namespace std;
const int maxn = 30;
int mp[maxn][maxn];
bool vis[maxn];
vector<int> P[maxn];//P[i]��ʾi���Ե�����Щ�ڵ�

typedef struct node {
    int s, e;
    int w;//���,�յ�,Ȩ��
} node;

bool operator < (const node& a, const node &b) {
    return a.w > b.w;
}


bool Prim(int s,int n,int& ans) { //��ʼ�ڵ�Ϊs��ͨ��Prime�㷨ʵ��
    ans = 0;
    priority_queue<node> Q;
    memset(vis, 0, sizeof(vis));
    int Vcnt = 1;
    vis[s] = 1;
    node nn;
    while (Vcnt < n) { //��ʾvis����е�ĸ���
        //��s��Ӧ�ı߷���Q����
        for (int i = 0; i < P[s].size(); i++) {
            if (!vis[P[s][i]]) { //��һ������Ŀǰû���ڼ�����
                nn.s = s;
                nn.e = P[s][i];
                nn.w = mp[nn.s][nn.e];
                Q.push(nn);
            }
        }
        //�����ȶ�������ѡһ��Ǳ�ڵĵ�
        while (!Q.empty() && vis[Q.top().e])
            Q.pop();
        if (Q.empty()) {
            ans = -1;
            return false;
        }
        //��ʱ�Ķ����ײ��ı��Ѿ���Ҫ�ӵ���С��������
        nn = Q.top();
        Q.pop();
        //����������С������
        vis[nn.e] = 1;
        Vcnt++;
        ans += nn.w;
        s = nn.e;//λ�µıߵķ�����׼��
    }

    return true;
}


int main() {
    int n;
    while (cin >> n&&n) {
        //ͼ�ĳ�ʼ��
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mp[i][j] = (i==j)?0:Max;
            }
            P[i].clear();
        }
        string s0,s1;
        int k, w;
        for (int i = 0; i < n - 1; i++) {
            cin >> s0 >> k;
            while(k--) {
                cin >> s1 >> w;
                int x = s0[0] - 'A';
                int y = s1[0] - 'A';
                //ʹ�õ����޷����
                mp[x][y] = min(w,mp[x][y]);//��ֹ���ݳ�������
                P[x].push_back(y);
                mp[y][x] = min(w, mp[y][x]);//��ֹ���ݳ�������
                P[y].push_back(x);
            }
        }

        int ans = 0;
        if (Prim(0, n, ans)) {
            cout << ans << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
