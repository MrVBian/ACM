#include<bits/stdc++.h>
using namespace std;

#define INF 19260817

int n,m;
int ans;

int dp[50001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    dp[0]=1;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        for(int j=x;j<=m;j++){
            dp[j]+=dp[j-x];
            if(dp[j]>=INF)
                dp[j]-=INF;
        }
    }
    for(int i=1;i<=m;i++)
        (ans+=dp[i])%=INF;
    cout<<ans;
}


//��Ŀ����
//Сk��һ�����֣���������װ105��С�Ķ���
//Сk��n����Ʒ����Ҫ׼����̯��
//ÿ����Ʒ���Ϊvi������105��
//����ճ�1~m��������ܷ�����
//������ܻ�ܴ���Դ�����19260817ȡģ
//��������:
//��һ����������n,m��
//������n�У�ÿ��һ��������vi
//�������:
//һ����ans��ʾ�ܷ�����
//ʾ��1
//����
//2 8
//1
//3
//���
//17
//˵��
//��1~m����ķ������ֱ�Ϊ��
//1
//1
//2
//2
//2
//3
//3
//3
//��ע:
//��Ҫ����ȡģ������
//n,m,vi <= 50000

