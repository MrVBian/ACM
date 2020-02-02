#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool mp[5][6];
int x,y,num;
int step[2][8]={ {1,1,2,2,-1,-1,-2,-2 } ,{ 2,-2,1,-1,2,-2,1,-1 } };

void Sea(int lx,int ly)
{
    int cur_x,cur_y;
    for(int i=0;i<8;i++){
        cur_x=lx+step[0][i];
        cur_y=ly+step[1][i];
        if(cur_x==x&&cur_y==y){
            num++;

        }
        else if(cur_x>=1&&cur_x<=4&&cur_y>=1&&cur_y<=5&& !mp[cur_x][cur_y]){
            mp[cur_x][cur_y]=1;
            Sea(cur_x,cur_y);
            mp[cur_x][cur_y]=0;
        }
    }
}

int main()
{
    cin>>x>>y;
    if(x<1||x>4||y<1||y>5){
        cout<<"ERROR";return 0;
    }
    memset(mp,0,sizeof(mp));
    mp[x][y]=1;
    num=0;
    Sea(x,y);
    cout<<num;
}


//Problem Description
//��һ��4*5�������ϣ���ĳ�ʼλ�����꣨�� �ᣩλ���ɼ������룬�����ܷ��س�ʼλ�õ����в�ͬ�߷������������߹���λ�ò����ظ������ߡ��ա��֣��������ĳ�ʼλ�����곬�����̵ı߽磬�����ERROR�������ʼλ��Ϊ4 6�������ERROR��
//Input
//��������ֻ��һ�У��������ÿո�ֿ�����������ʾ�����ڵĳ�ʼλ�����ꡣ��������λ�ñ��Ϊ��1 1����
//Output
//���һ�У�ֻ��һ����������ʾ���ܷ��س�ʼλ�õ����в�ͬ�߷���������
//
//����������ĳ�ʼλ�ó������̱߽磬�����ERROR��
//Sample Input
//2 2
//Sample Output
//4596
