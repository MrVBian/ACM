#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;

const int maxn=3;
const int maxm=3;
int n,k,p;

struct Matrix{
    int n,m;
    ll a[maxn][maxm];
    void clear(){
        n=m=0;
        memset(a,0,sizeof(a));
    }
    Matrix operator *(const Matrix &b) const{
        Matrix tmp;
        tmp.clear();
        tmp.n=n;tmp.m=b.m;
        for(int i=0;i<n;i++)
            for(int j=0;j<b.m;j++)
                for(int k=0;k<m;k++)
                    tmp.a[i][j]+=(a[i][k])*(b.a[k][j]);
        return tmp;
    }
};
//f[n] sum[n-1]  p
//
//k   1    0
//
//0   1    0
//
//1   0    1
//
//f[n+1]   sum[n]  p

int Pow(int a1,int a2){

    Matrix s;
    s.clear();
    s.n=s.m=3;
    s.a[0][0]=1;s.a[0][1]=1;s.a[0][2]=1;
    s.a[1][1]=1;s.a[2][0]=1;

    Matrix ans;
    ans.clear();
    ans.n=1;
    ans.m=3;
    ans.a[0][0]=a2;
    ans.a[0][1]=a1;
    ans.a[0][2]=a1;

    while(m){
        if(m&1)
            ans=ans*s;
        s=s*s;
        m>>=1;
    }
    return ans.a[0][1];
}

int main()
{
    cin>>n>>k>>p;
    if(n<2)
        cout<<1<<endl;
    else
        Pow(n-1);
}


���ӣ�https://www.nowcoder.com/acm/contest/136/J
��Դ��ţ����

//��Ŀ����
//    �����һ�ֽ������ϣ����������Ŵ�߲㽨�����ֳƣ�ˮ�ࡢ��������
//    WHZ�кܶ�����������ε���ҿ飬�������Щ������ǰ���һ���Ĺ��ɷŵ��ڳ�һ�ŵ�n����������е�i�����ӷ�����������������ǰһ�����ӵ�k���ٶ�p��������أ���һ���������1����
//    WHZ��֪������n������������Ҫ����������ǡ�
//��������:
//��һ����3��������n��k��p��
//�������:
//���һ�У�һ������������ʾ����Ҫ������n��������Ҫ����������ǣ�����������ݹ�����ֻ��Ҫ�����ģ1000000007(1e9+7)��Ľ�����ɡ�
//ʾ��1
//����
//����
//3 1 1
//���
//����
//6
//˵��
//��������̷���1 2 3���ܼ�6��
//ʾ��2
//����
//����
//3 2 2
//���
//����
//15
//˵��
//��������̷���1 4 10���ܼ�15��
//ʾ��3
//����
//����
//3 3 3
//���
//����
//28
//˵��
//��������̷���1 6 21���ܼ�28��
//��ע:
//����100%�Ĳ������ݣ�
//1 �� n �� 1000000000
//1 �� k,p �� 1000
