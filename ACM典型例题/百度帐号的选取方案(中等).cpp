#include <bits/stdc++.h>
using namespace std;
#define N 1005
#define LL long long
LL a[N][N], b[N][N], s[N][N];
int nxt[1000005];
void getnxt(string s){
    int i=0,j=-1;
    nxt[0]=-1;
    int len=s.length();
    while(i<len){
        if(s[i]==s[j]||j==-1){
            i++;
            j++;
            nxt[i]=j;
        }
        else
            j=nxt[j];
    }
}
int getnum(string s){
    int len=s.length();
    getnxt(s);
    if(len%(len-nxt[len])==0)
        return len/(len-nxt[len]);
    return 1;
}
string str;
int main(){
    while(cin >> str){
        int len = str.length();
        LL ans = 0;
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(s, 0, sizeof(s));
        for(int i = 0;i < len;i++)
            for(int j = i;j < len;j++){
                a[i][j] = getnum(str.substr(i, j-i+1));
                //��������Ż�һ�£�ʹ�ø��Ӷ���������O(N^2)
                b[i][a[i][j]]++;
            }
        for(int i = len-1;i >= 0;i--){
            for(int j = 0;j < len;j++){
                if(i == len-1) s[i][j] = b[i][j];
                else s[i][j] = s[i+1][j] + b[i][j];
            }
        }
        for(int i = 0;i < len-1;i++)
            for(int j = i;j < len-1;j++){
                int p = a[i][j];
                ans += s[j+1][p];
            }
        printf("%lld\n", ans);
    }
}


//��ע��ٶ��ʺŵ�ʱ�������ʺ������޴󣬳��������˻�����ͻ����������ϣ�����õ��û��������� jsk���Ѿ���ռ�ã���ô�ͻὫ��ʼ���û����ظ�һ�飨��ʱ�û���Ϊ jskjsk�����ټ�� jskjsk �Ƿ�ռ�ã������ռ��������ظ�һ���ʼ���û�������Ϊ jskjskjsk����ֱ��û�г�ͻΪֹ��
//ÿ���û�������һ������ֵ
//PP
//P����Ӧ�û���������ͻ�������������һ�����ַ���ѡ���������ཻ���Ӵ��ֱ������û���������ϣ�������û���������ֵ��ȡ������һ���ж����ַ���Ҫ���ѡȡ������ע�⣬��ԭ����λ�ò�ͬ��ֵ��ȵ��ַ�������Ϊ�ǲ�ͬ���ַ���������ÿ�������������û���û���Ⱥ�˳��
//�����ʽ
//����Ϊһ�У�����һ������Ϊ
//len(len��1)len(len \geq 1)
//len(len��1) ��ֻ����Сд��ĸa-z���ַ���
//SS
//S��
//���ڼ򵥰汾��
//len��50len \leq 50
//len��50��
//�����еȰ汾��
//len��1000len \leq 1000
//len��1000��
//�������Ѱ汾��
//len��100000len \leq 100000
//len��100000��
//�����ʽ
//���һ�У����һ����������ʾ�ɴӴ�
//SS
//S ��ѡ�����ٶ�����ֵ��ͬ�Ĳ��ཻ�Ӵ���
//��������1
//aaaa
//�������1
//7
//��������2
//abcd
//�������2
//15
