#include<bits/stdc++.h>
using namespace std;
int n;
int D[1001];
int dp[1001];

int MIS()
{
    for(int i=1;i<=n;i++){
        dp[i]=1;
        for(int j=1;j<i;j++){
            if(D[i]>D[j])
                dp[i]=dp[j]+1;
        }
    }
    int Max=-1;
    for(int i=1;i<=n;i++)
        if(Max<dp[i])
            Max=dp[i];
    return Max;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&D[i]);
    cout<<MIS();
}

//Problem Description
//һ����������bi����b1 < b2 < ... < bS��ʱ�����ǳ���������������ġ����ڸ�����һ������(a1, a2, ..., aN)�����ǿ��Եõ�һЩ������������(ai1, ai2, ..., aiK)������1<= i1 < i2 < ... < iK <= N�����磬��������(1, 7, 3, 5, 9, 4, 8)��������һЩ���������У���(1, 7), (3, 4, 8)�ȵȡ���Щ����������ĳ�����4������������(1, 3, 5, 8)��
//
//������񣬾��Ƕ��ڸ��������У��������������еĳ��ȡ�
//Input
//����ĵ�һ�������еĳ���N (1 <= N <= 1000)���ڶ��и��������е�N����������Щ������ȡֵ��Χ����0��10000��
//Output
//����������еĳ��ȡ�
//Sample Input
//7
//1 7 3 5 9 4 8
//Sample Output
//4
