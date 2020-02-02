#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

// �����滻
#define max(a,b) (a>b)?a:b
#define min(a,b) (a>b)?b:a
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
#define LL long long
const int maxn = 100100;

int lazy[maxn<<2];
int sum[maxn<<2];

void PushUp(int rt) { //�����ӡ��Һ������ϸ��¸��ڵ�
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
void PushDown(int rt,int m) { //���¸���
    if (lazy[rt]) { //������
        lazy[rt<<1] = lazy[rt<<1|1] = lazy[rt];
        sum[rt<<1] = (m - (m >> 1)) * lazy[rt];
        sum[rt<<1|1] = ((m >> 1)) * lazy[rt];
        lazy[rt] = 0;
    }
}
void build(int l,int r,int rt) { //����
    lazy[rt] = 0;
    if (l== r) {
        sum[rt] = 1;
        return ;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    PushUp(rt);
}
void update(int L,int R,int c,int l,int r,int rt) { //����
    if (L <= l && r <= R) {
        lazy[rt] = c;
        sum[rt] = c * (r - l + 1);
        return ;
    }
    PushDown(rt, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) update(L, R, c, lson);
    if (R > m) update(L, R, c, rson);
    PushUp(rt);
}
LL query(int L,int R,int l,int r,int rt) {
    if (L <= l && r <= R) {
        return sum[rt];
    }
    PushDown(rt, r - l + 1);
    int m = (l + r) >> 1;
    LL ret = 0;
    if (L <= m) ret += query(L, R, lson);
    if (m < R) ret += query(L, R, rson);
    return ret;
}
int main() {
    int  n, m, t, T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        scanf("%d%d", &n, &m);
        build(1, n, 1);
        while (m--) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            update(a, b, c, 1, n, 1);
        }
        printf("Case %d: The total value of the hook is %d.\n", t, query(1, n, 1, n, 1));
    }
    return 0;
}
