#include<iostream>
#include<stack>
#include<cstring>
#include<climits>
using namespace std;
int a[1001];
int dp[1001];
int pre[1001];
stack<int> v;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];dp[i]=1;
    }

    memset(pre,-1,sizeof(pre));
    int k=-1;
    int Max=0;
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            if(a[i]<a[j]&&dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
                pre[i]=j;
            }
        }
        if(Max<dp[i]){
            Max=dp[i];
            k=i;
        }
    }

    while(k!=-1){
        v.push(a[k]);
        k=pre[k];
    }

    cout<<v.top();
    v.pop();
    while(!v.empty()){
        cout<<' '<<v.top();
        v.pop();
    }
}




//����һ���������У����������ݼ���ע�ⲻ�ǡ����������������С�
//
//����������У���һ�а���һ��������N��N<=1000������ʾ������������еĳ��ȡ��ڶ��а����ÿո�ָ�����N��������������Χ����Ϊ[-30000,30000]��
//
//���Ϊһ�У���ݼ������еĽ�������ּ��ÿո�ָ�������case��ֻ����һ����ݼ������У���
//
//��������
//8
//9 4 3 2 5 4 3 2
//�������
//9 5 4 3 2



//#include <iostream>
//#include <cstdio>
//#include <algorithm>
//#include <stack>
//#include <cstring>
//using namespace std;
//int num[1005];
//int dp[1005];
//int pre[1005];
//int main(){
//    int n,i,j;
//    while(scanf("%d",&n)!=EOF){
//        memset(dp,1,sizeof(dp));
//        memset(pre,-1,sizeof(pre));
//        for ( i = 0; i < n; ++i)
//        {
//            scanf("%d",&num[i]);
//        }
//        for ( i = 1; i < n; ++i)
//        {
//            for ( j = 0; j < i; ++j)
//            {
//                if(num[i]<num[j]&&dp[j]+1>dp[i]){
//                    dp[i]=dp[j]+1;
//                    pre[i]=j;
//                }
//            }
//        }
//        int maxlen=0;
//        for ( i = 0; i < n; ++i)
//        {
//            if (maxlen<dp[i])
//            {
//                maxlen=dp[i];
//                j=i;
//            }
//        }
//        stack<int> v;
//        while(j!=-1){
//            v.push(num[j]);
//            j=pre[j];
//        }
//        printf("%d", v.top());
//        v.pop();
//        while(!v.empty()){
//            printf(" %d", v.top());
//            v.pop();
//        }
//        printf("\n");
//
//    }
//    return 0;
//}

