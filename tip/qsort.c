#include<stdio.h>
#include<stdlib.h>
int comp(const void*a,const void*b)//�������Ƚϵĺ�����
{
    return *(int*)a>*(int*)b;
}
int main()
{
    int a[10] = {2,4,1,5,5,3,7,4,1,5};//��������顣
    int i;
    int n=10;
    qsort(a,n,sizeof(int),comp);//����qsort����
    for(i=0;i<10;i++)//�������������
    {
        printf("%d\t",a[i]);
    }
    return 0;
}

//
//int cmp(const void *a,const void *b)
//{
//    return *(int*)a>*(int*)b;
//}
//
//int main()
//{
//    int a[10]={2,4,1,5,5,3,7,4,1,5};
//    int n=10;
//    qsort(a,n,sizeof(int),cmp);
//    int i;
//    for(i=0;i<n;i++)
//        printf("%d ",a[i]);
//    return 0;
//}
