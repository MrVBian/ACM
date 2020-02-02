#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<windows.h>

#define _for(i,a,b) for(int i=(a);i<(b);i++)
#define _ref(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

int main()
{
//empty() ��ջΪ���򷵻���
//pop() �Ƴ�ջ��Ԫ��
//push() ��ջ������Ԫ��
//size() ����ջ��Ԫ����Ŀ
//top() ����ջ��Ԫ��
//clear() ��յ�ǰ��vector

    stack<int> s;
    _for(i,0,10)
        s.push(i);

    if(!s.empty())
        cout<<"ջs���ǿյ�"<<endl;
    cout<<"ջs��Ԫ�صĸ���Ϊ��"<<s.size()<<endl;
    while(!s.empty()){
        cout<<" "<<s.top();
        s.pop();
    }
    cout<<endl;
    if(s.empty())
        cout<<"ջs����Ϊ��"<<endl;

    system("pause");

//empty() �ж϶����Ƿ�Ϊ�գ���������Ϊbool
//size() ���ض�����Ԫ�صĸ���
//front() ���ض��ж���Ԫ��
//back() ���ض��ж�βԪ��
//push(ele) ��Ԫ��ele���뵽��β
//pop ����Ԫ�س���

    queue<int> q;
    _for(i,0,10)
        q.push(i);
    if(!q.empty())
        cout<<"���в��ǿյ�"<<endl;
    cout<<"����q�ĳ���Ϊ��"<<q.size()<<endl;
    cout<<"����q�����һ��Ԫ�أ�"<<q.back()<<endl;
    _for(i,0,10){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    if(q.empty())
        cout<<"�����ǿյ�"<<endl;

    system("pause");

//c.clear() �Ƴ��������������ݡ�
//c.empty() �ж������Ƿ�Ϊ�ա�
//c.erase(pos) ɾ��posλ�õ�����
//c.erase(beg,end) ɾ��[beg,end)���������
//c.front() ���ص�һ�����ݡ�
//c.insert(pos,elem) ��posλ�ò���һ��elem����
//c.pop_back() ɾ�����һ�����ݡ�
//c.push_back(elem) ��β������һ�����ݡ�
//c.resize(num) �������ø������Ĵ�С
//c.size() ��������ʵ�����ݵĸ�����
//c.begin() ����ָ��������һ��Ԫ�صĵ�����
//c.end() ����ָ���������һ��Ԫ�صĵ�����

    vector<int> v;
    _for(i,0,10)
        v.push_back(i);
    _for(i,0,v.size())
        cout<<v[i]<<" ";
    cout<<endl;
    cout<<"ʹ�õ�������ȡ����"<<endl;
    vector<int>::iterator it;
    for(it=v.begin();it!=v.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    for(vector<int>::iterator it=v.begin();it!=v.end();)
        v.erase(it);
    if(v.empty())
        cout<<"����vΪ��"<<endl;
    return 0;

}
