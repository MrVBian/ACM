#include<iostream>
#include<fstream>
#include<sstream>

//ios::in         ��һ���ɶ�ȡ�ļ�
//ios::out        ��һ����д���ļ�
//ios::app        ��д����������ݽ���׷�ӵ��ļ���ĩβ���˷�ʽʹ��ios::out
//ios::ate        ��д����������ݽ���׷�ӵ��ļ���ĩβ���˷�ʽ��ʹ��ios::out
//ios::trunk      ɾ���ļ�ԭ���Ѵ��ڵ����ݣ�����ļ���
//ios::nocreate   ���Ҫ�򿪵��ļ��������ڣ���ô�Դ˲�������open()�������޷����С�
//ios::noreplace  ���Ҫ�򿪵��ļ��Ѵ��ڣ���ͼ��open()������ʱ������һ������
//ios::binary     �Զ����Ƶ���ʽ��һ���ļ���

using namespace std;

//int main()
//{
//    ios::sync_with_stdio(false);
//    ifstream in("./test.txt");
//    string s;
//    int a[100];
//    int k=0;;
//    while(getline(in,s)){
//        stringstream stream(s);
//        while(stream>>a[k++])
//            ;
//        k--;
//    }
//    for(int i=0;i<k;i++)
//        cout<<a[i]<<' ';
//    ofstream out("./test.txt",ios::app);
//    out<<"\n���\n";
//    in.close();
//    out.close();
//}

//ios::beg ���� �ɽ����ƶ����ļ��׶�
//ios::end ���� �ɽ����ƶ����ļ�ĩ��
//
//���ߣ�������趨��ǰ�������ת���ַ��������磬�����Ҫ��λ����ǰλ�õ�5���ַ���ǰ����Ӧ��д��
//File.seekg(-5);
//��������������40���ַ�����Ӧ��д��
//File.seekg(40);
//ͬʱ���ұ���ָ��������seekg()�Ǳ����صģ���Ҳ���Դ�������������һ���汾�������ӵģ�
//File.seekg(-5,ios::end);


//  ios::beg�� �ļ���ͷ
//  ios::cur�� �ļ���ǰλ��
//  ios::end�� �ļ���β
//  ����������һ�����ڶ������ļ�����Ϊ�ı��ļ�����Ϊϵͳ���ַ��Ľ��Ͷ�������Ԥ���ֵ��ͬ��
//  ����
//  file1.seekg(1234,ios::cur);//���ļ��Ķ�ָ��ӵ�ǰλ�������1234���ֽ�
//  file2.seekp(1234,ios::beg);//���ļ���дָ����ļ���ͷ�����1234���ֽ�


int main()
{
    ifstream in("test.txt");
    if(!in.is_open())
        cout<<"δ�ɹ������ļ�"<<endl;
    ofstream out("test.txt");
    if(in.is_open())
        cout<<"�ɹ������ļ�"<<endl;

    //fstream file("test.txt",ios::in | ios::out);
    fstream file("test.txt",ios::in | ios::app);
    file<<"Helloworld!";

    string s;
    file.seekg(ios::beg);
    file>>s;
    cout<<s;

    cout<<endl;
    file.seekg(4);
    file>>s;
    cout<<s;
    cout<<endl<<"˳�����";
    file>>s;
    cout<<s;

    cout<<endl;
    file.seekg(ios::end);
    if(!file.eof())
        cout<<"δ���ļ�ĩβ"<<endl;
    else
        cout<<"�����ļ�ĩβ"<<endl;

    in.close();
    out.close();
    file.close();


//    ofstream out("test.txt");
//    fstream File("test.txt",ios::in | ios::out);
//
//    File << "Hi!"; //����Hi!��д���ļ�
//    static char str[10]; //��ʹ��staticʱ��������Զ�����ʼ��
//               //���Ǳ����Ϊ��
//
//
//    File.seekg(ios::beg); // �ص��ļ��ײ�
//                  // �˺������ں������
//    File >> str;
//    cout << str << endl;
//
//    out.close();
//    File.close();
}
