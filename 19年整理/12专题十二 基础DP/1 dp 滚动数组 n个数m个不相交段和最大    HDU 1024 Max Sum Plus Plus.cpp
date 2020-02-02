#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int maxn = 1e6+10;
const int inf = 0x3f3f3f3f;

int dp[maxn];
int pre[maxn];
int a[maxn];

int main(){
    int n, m;
    while(~scanf("%d%d", &n, &m)){
        for(int i = 0; i <= m; ++i)
            dp[i] = pre[i] = 0;
        for(int i = 1; i <= m; ++i)
            scanf("%d", &a[i]);
        // pre��һ���dp
        // dp[i][j] = max(dp[i][j-1], dp[i-1][k]) + a[j]
        // dp[i][t] = max(dp[i][t-1], dp[i-1][k]) + a[j]
        // dp[t] = max(dp[t-1], dp[i-1][k]) + a[j]
        // dp[i-1][k]���ؼ�¼  ��¼dp[i-1][t]���� ��dp[t]����һ��dp[t-1]
        // dp[t] = max(dp[t-1], pre[t-1]) + a[j]
        int tmp;
        for(int i = 1; i <= n; ++i){
            tmp = -inf;
            for(int j = i; j <= m; ++j){
                dp[j] = max(dp[j-1], pre[j-1]) + a[j];
                pre[j-1] = tmp;
                tmp = max(pre[j-1], dp[j]);// �Ƿ�ȡa[j]
            }
        }
        printf("%d\n", tmp);
    }
    return 0;
}
