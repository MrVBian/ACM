//�Ͻ�˹�����㷨
#include <iostream>
using namespace std;
#include<string>

#define MaxInt 32767                    					//��ʾ����ֵ������
#define MVNum 100                       					//��󶥵���
typedef char VerTexType;              						//���趥�����������Ϊ�ַ���
typedef int ArcType;                  						//����ߵ�Ȩֵ����Ϊ����

int *Dist=new int[MVNum];	                    			//���ڼ�¼���·�ĳ���
int *S=new int[MVNum];          							//��Ƕ����Ƿ����S����
string *Path=new string[MVNum];									//���ڼ�¼���·�����ǰ��


//------------ͼ���ڽӾ���-----------------
typedef struct AMGraph{
	VerTexType vexs[MVNum];            						//�����
	ArcType arcs[MVNum][MVNum];      						//�ڽӾ���
	int vexnum,arcnum;                						//ͼ�ĵ�ǰ�����ͱ���
}AMGraph;

int LocateVex(AMGraph G , VerTexType v){
	//ȷ����v��G�е�λ��
	for(int i = 0; i < G.vexnum; ++i)
		if(G.vexs[i] == v)
			return i;
   return -1;
}

void CreateUDN(AMGraph &G){
    //�����ڽӾ����ʾ��������������G
	int i , j , k;
	cout <<"�������ܶ��������ܱ������Կո����:";
    cin >> G.vexnum >> G.arcnum;							//�����ܶ��������ܱ���
	cout << endl;

	cout << "����������:����a" << endl;

    for(i = 0; i < G.vexnum; ++i){
		cout << "�������" << (i+1) << "���������:";
		cin >> G.vexs[i];                        			//������������Ϣ
	}
	cout << endl;
    for(i = 0; i < G.vexnum; ++i)                			//��ʼ���ڽӾ��󣬱ߵ�Ȩֵ����Ϊ����ֵMaxInt
		for(j = 0; j < G.vexnum; ++j)
			if(i==j)
				G.arcs[i][j]=0;
			else
			    G.arcs[i][j] = MaxInt;
	cout << "����������Ķ��㼰Ȩֵ����a b 7" << endl;
	for(k = 0; k < G.arcnum;++k){							//�����ڽӾ���
		VerTexType v1 , v2;
		ArcType w;
		cout << "�������" << (k + 1) << "���������Ķ��㼰Ȩֵ:";
		cin >> v1 >> v2 >> w;								//����һ���������Ķ��㼰Ȩֵ
		i = LocateVex(G, v1);  j = LocateVex(G, v2);		//ȷ��v1��v2��G�е�λ�ã�������������±�
		G.arcs[i][j] = w;									//��<v1, v2>��Ȩֵ��Ϊw
		G.arcs[j][i] = G.arcs[i][j];						//��<v1, v2>�ĶԳƱ�<v2, v1>��ȨֵΪw
	}
}
int MinEdge(AMGraph G,int *Dist){
	//����Ȩֵ��С�ĵ�
	int i;
	int index = -1;
	int min = MaxInt;
	for(i = 0 ; i < G.vexnum ; ++i){
		if(Dist[i] != 0 && min > Dist[i]){
			min = Dist[i];
			index = i;
		}
	}
	return index;
}
void ShortestPath_DIJ(AMGraph G, int v0){
    //��Dijkstra�㷨��������G��v0���㵽���ඥ������·��
	int i;
	for(i=0;i<G.vexnum;i++){
		Dist[i]=G.arcs[v0][i];
		if(Dist[i]!=MaxInt&&Dist[i]!=0)
			Path[i]=Path[i]+G.vexs[v0]+G.vexs[i];
		else
			Path[i]="";
	}
	S[0]=v0;
	Dist[v0]=0;
	int num=1;
	while(num<G.vexnum){
		int k=MinEdge(G,Dist);//��Dist�в�����СֵԪ��
		cout<<Dist[k]<<"\t"<<Path[k]<<endl;
		S[num++]=k;//�������ɵ��յ���뼯��S
		for(i=0;i<G.vexnum;i++)   //�޸�����Dsit��Path
			if(Dist[i]>Dist[k]+G.arcs[k][i]){
				Dist[i]=Dist[k]+G.arcs[k][i];
				Path[i]=Path[k]+G.vexs[i];
			}
		Dist[k]=0;   //�ö���kΪ�������յ���
	//for(i=0;i<G.vexnum;i++)//��ʱDist��ֵ
	//	cout<<Dist[i]<<"\t";
	//cout<<endl;
	}

}
void DisplyG(AMGraph G){
		//��ʾͼG
	int i,j;
	cout << "ͼG���ڽӾ������£�"<<endl;
	for(i = 0 ; i < G.vexnum ; ++i){
		for(j = 0; j < G.vexnum; ++j){
			if(j != G.vexnum - 1){
				if(G.arcs[i][j] != MaxInt)
					cout << G.arcs[i][j] << "\t";
				else
					cout << "��" << "\t";
			}
			else{
				if(G.arcs[i][j] != MaxInt)
					cout << G.arcs[i][j] <<endl;
				else
					cout << "��" <<endl;
			}
		}
	}
	cout << endl;
}
void DisplayPath(AMGraph G , string *Path,int num_destination){
	//for(int i=0;i<G.vexnum;i++)  //��ʾ��ӡ�������·��
	//cout << Path[i]<< endl;
	cout << Path[num_destination]<< endl;
}


void main()
{
	cout << "************�Ͻ�˹�����㷨**************" << endl << endl;
	AMGraph G;
	int i , j ,num_start , num_destination;
	VerTexType start , destination;
	CreateUDN(G);
	cout <<endl;
	cout << "*****������G������ɣ�*****" << endl;
	DisplyG( G);
	cout << "������������ʼ�㡢�յ����ƣ�";
	cin >> start >> destination;
	num_start = LocateVex(G , start);
	num_destination = LocateVex(G , destination);
	ShortestPath_DIJ(G , num_start);
	cout << endl <<"���·��Ϊ��";
	DisplayPath(G , Path,num_destination);
}

