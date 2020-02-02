#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

const int maxn = 10010;
int par[maxn];

struct node{
    int v;
    int t;
}arr[maxn];

void init(){
    for(int i = 0; i <= maxn; ++i)
        par[i] = i;
}

int Find(int x){
    if(par[x] == x)
        return x;
    return par[x] = Find(par[x]);
}

bool cmp(node a, node b){
    return a.v > b.v;
}

int main(){
    int n;
    while(cin>>n){
        int ans = 0;
        init();
        for(int i = 0; i < n; ++i){
            cin>>arr[i].v>>arr[i].t;
        }
        sort(arr, arr+n, cmp);
        for(int i = 0; i < n; ++i){
            int k = Find(arr[i].t);
            if(k){//k==0 ʱ��ʾ [1,arr[i].t]��������
                ans += arr[i].v;
                par[k] = k - 1;//��ǰ����һ��
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
