#include<bits/stdc++.h>
#include<cstring>
using namespace std;
#define _for(i,a,b) for(int i=(a);i<(b);i++)
#define _ref(i,a,b) for(int i=(a);i<=(b);i++)
#define ms(a, b) memset(a, b, sizeof(a))
#define fill(a,v,n) memset((a),(v),sizeof(a[0])*(n))
#define sc(x) scanf("%d", &x)
#define pr(x) printf("%d", (x))
#define IOS ios::sync_with_stdio(0);cin.tie(0);
typedef double db;
typedef long long ll;
typedef unsigned long long ull;

#define MOD 1000000007
void _max(int &a, int b){a = max(a,b);}
void _min(int &a, int b){a = min(a,b);}

ll pw(ll a, ll b){ll res(1);while(b){if(b&1)res=res*a%MOD;a=a*a%MOD;b>>=1;}return res;}
ll gcd(ll a, ll b){ll t;while(b){t=a%b;a=b;b=t;}return a;}
const int infi = 2147483647;
const ll infl = 9223372036854775807ll;
const db PI = 3.14159265358979323846;

inline void rd(int &x)
{
    x = 0;
    char c = getchar();
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9')x=x*10+(c&15),c=getchar();
}

const int vertex=100010;
const int arcNum=500010;
struct node{
    int u,v;;
    ll w;
};
node edge[arcNum];
ll parent[vertex];

bool cmp(node a,node b){
    return a.w<b.w;
}
int find(int v){
    if(parent[v]==-1)   return v;
    return parent[v]=find(parent[v]);
    //return parent[v]=parent[v]==-1?v:find(parent[v]);
}

ll Kruskal(int ver)
{
    ms(parent,-1);
    int n=0;
    ll sum=0;
    int vex1,vex2;
    _for(i,0,ver){
        vex1=edge[i].u;
        vex2=edge[i].v;
        vex1=find(vex1);
        vex2=find(vex2);
        if(vex1!=vex2){
            parent[vex2]=vex1;
            n++;
            sum+=edge[i].w;
        }
        if(n==ver-1)
            return sum;
    }
    return sum;
}


int main(){
    int n,m,u,v,w;
    rd(n);rd(m);
    _for(i,0,m){
        rd(u);rd(v);rd(w);
        //parent[i]=i;
        edge[i].u=u;
        edge[i].v=v;
        edge[i].w=w;
    }
    sort(edge,edge+m,cmp);
//    _for(i,0,m){
//        printf("%d  %d  %lld\n",edge[i],edge[i].v,edge[i].w);
//    }
    ll ans=Kruskal(m);
    printf("%lld",ans);
}

//���ӣ�https://www.nowcoder.com/acm/contest/136/H
//��Դ��ţ����
//���ӳ�����HAʵ���սʿ��������CS������CS�ĵ�ͼ��һЩ�ݵ���ɣ����ں��ӳ��Ѿ�ռ����n���ݵ㣬Ϊ�˷��㣬�����Ǳ��Ϊ1-n��Ϊ�����Σ����ӳ�����սʿ����ÿ���ݵ����һ���ӣ���սʿ�Ƕ��ڿ��������Ҫ������������֮�䴫����Ϣ��������֮������ڳ�����һ��ͨ·�����ڹ���һ�����鷳�Ĳ��£����Ժ��ӳ�ϣ���ڳ������������ٵĹ���ʹ�����������ݵ�֮��������һ��ͨ·��˳�㣬�����ܵġ�d[i][j]ʹ��С������d[i][j]Ϊ�ݵ�i��j�ľ��룩��
//��������:
//��һ����2��������n��m��m��ʾ�ɹ��ڵĹ�����
//������m�У�ÿ��3����a,b,v��ÿ������һ���ɹ��ڵĹ����ù�����ʹa��b��ͨ������Ϊv��
//�������:
//���һ�У�һ������������ʾҪʹ�����������ݵ�֮����һ��ͨ·��������Ҫ�ڳ��Ĺ��������ݱ�֤�н⣩
//ʾ��1
//����
//2 2
//1 2 1
//1 2 3
//���
//1
//ʾ��2
//����
//3 3
//1 2 3
//2 3 4
//1 3 5
//���
//7
//��ע:
//����100%�Ĳ������ݣ�
//1 �� n �� 100000
//1 �� m �� 500000
//1 �� v �� 10000
//
