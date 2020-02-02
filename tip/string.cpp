#include<iostream>
#include<string>
#include<windows.h>
//#pragma GCC diagnostic error "-std=c++11"
using namespace std;

int main()
{

    string s = "asdssfghjkl";
    char a1;
    string::iterator it;
    string::const_iterator cit;
    string::size_type n;

    s.append("zxcv");  //s="asdssfghjklzxcv",��������Ϊstring���� ����Ϊchar��
    s.assign("qwert"); //s="qwert"���൱�ڸ�ֵ������������ֵ ����������Ϊchar��
    a1 = s.at(0);      //a1='q' �±����
    a1 = s.back();     //a1='t'   �������һ���ַ�
    it = s.begin();    //�����ַ�����ʼλ�õĵ�������cit = s.begin(); ��ȷ
    a1=it[0];          //s ="qwert"�� a1='q'��a=cit[0]; ��ȷ
    it[3] = 'f';       //s ="qweft"��cit[3] = 'f';  ����

    n = s.capacity();       //s="qwert" n=15(win64 vs2013)
    /*
     ���ַ��������ڴ��ʱ�򣬲������ж�󳤶ȷ�����ٵģ����ǵ�append�Ȳ�
     ����һ�η����ڴ��Ǳȸ������ַ������ȶ�ġ�������append��ʱ�򣬾Ͳ���
     ÿ�ζ������ڴ��ˡ�����appendʱ���ѷ����ڴ治���ˣ����ٴ�׷��һ���ڴ�
     ���䡣��ǰ�Ѿ�������ڴ��С������capacity���ַ���ʵ�ʴ�С������
     size����������Ϊ������ַ�������Ч�ʡ�capacity���������ǿɴ���ַ�
     �ĸ�����size�Ǵ�С���ǵ�ǰ�Ѵ���ַ��ĸ�����capacity >= size�� ��
     ��capcacity����٣������stl��ʵ�־�����capacity�ǿ�����ģ������
     ǰsize����Ҫ������ַ���������capacity��capacity��Ҫ����һ�㷭��
     ����������ȡ����ʵ�֡�
    */

    cit=s.cbegin();    //s="qweft"�������ַ�����ʼλ�õ�const�͵�����
    a1 = cit[1];       // a1='w'
    /*
    1.iterator,const_iterator���ã����������ڵ�Ԫ�أ���������ЩԪ�ص�
    ֵ��iterator���Ը�Ԫ��ֵ,��const_iterator���ɸġ���C��ָ���е���
    2.const_iterator �����������const vector ��� const vector,��
    �����ֵ���Ը�(����ָ������Ԫ��),�����ܸ�д��ָ���Ԫ��ֵ. �� cit[1]
    = 'o' ����
    */

    cit = s.cend();   //cit = " "�������ַ���ĩβ�� const�͵�����
    s.clear();        //ɾ���ַ�����������ַ�

    s = "asdfg";
    int n1=s.compare("asdfg");     //n1=0  �ַ����Ƚ�
    int n2 = s.compare("sdfg");    //n1=-1
    int n3 = s.compare("ab");      //n1=1

    char* sdest;
    n=s.copy(sdest,1,0);    //�ᱨunsafe������
    /*
    size_type copy( CharT* dest,  size_type count,  size_type
    pos = 0);
    ����:
    dest  pointer to the destination character string
    pos  position of the first character to include
    count  length of the substring
    ����ֵ:
    copy���ַ�����
    ��string���Ͷ��������ิ��count���ַ����ַ�ָ��destָ��Ŀռ��С�Ĭ
    �ϴ����ַ���ʼ������Ҳ����ָ������ʼ��λ�ã���ס��0��ʼ�������������Ӷ�
    ���и��Ƶ��ַ����û�Ҫȷ��pָ��Ŀռ��㹻����n���ַ���
    */


    string::const_reverse_iterator it2;
    it2=s.crbegin();  /*����const��ת����������s�ȷ�ת����ȡ��begin��
    it2[2] = 'g';����it2=" "���൱��ȡ��s�����һ��Ԫ�� ++����s��ǰ
    ��ȡ��*/

    a1 = it2[0];      //a1='g'
    a1 = it2[1];      //a1='f'
    it2 = s.crend();  /*����const��ת����������s�ȷ�ת����ȡ��end��
    it2 = "asdfg"; char a3 = it2[0]; char a4 = it2[1]; ���������
    �൱��ȡ��s�ĵ�һ��Ԫ��ǰһ������cbegin cend �෴��*/

    const char* s1;
    s1=s.c_str();   /*s1="asdgf"��c_str()���ص���һ����ʱָ�룬����
    ������в�����s���ַ�ɾ��s1Ҳ��û�ˣ�s1��c�ַ�����ĩβ׷��\0��*/
    /*
    const char* c;
    string s="1234";
    c = s.c_str();
    cout<<c<<endl; //�����1234
    s="abcd";
    cout<<c<<endl; //�����abcd
    c_str()����һ���ͻ�����ɶ����ɸĵ�ָ���ַ������ָ�룬����Ҫ�ֶ��ͷ�
    ��ɾ�����ָ�롣*/

    s1=s.data();  /*s1="asdfg"����c_str()���ƣ����Ƿ��ص����鲻�Կ�
    �ַ���ֹ��*/

    bool flag = s.empty();  //flag=false������bool�ͣ�Ϊ�շ���true
    it=s.end();     //it=" "�����ص�����ָ��sĩβ��

    s.erase(2,2);   //s="asg"�����±�2��ʼɾ��2����s = "asdfg";
    s.erase(s.begin(), s.begin() + 3);  //s="fg"��s = "asdfg";
    s.erase(4);   //s="asdf"��ɾ���±�4��ֵ��s = "asdfg";
    s.erase(s.begin() + 4);   //s="asdf"��ɾ���±�4��ֵ��
    s.erase(s.begin(), s.end());  //s=" "��s.end()��ĩβԪ����һ��
    /*
    (1)erase(pos,n);
    ɾ����pos��ʼ��n���ַ�������erase(0,1)����ɾ����һ���ַ�
    ��2��erase(position);
    ɾ��position����һ���ַ�(position�Ǹ�string���͵ĵ�����)
    ��3��erase(first,last);
    ɾ����first��last֮����ַ���first��last���ǵ�������
    �����±�0��1��2...�͵�����s.begin(),s.begin()+1....A��Ӧ��
    */



    s = "asdfg";
    n = s.find("asdfg");  //n=0 ���� ȫƥ��
    n=s.find(100);        //n=2����100תΪ�ַ����ң�d��ascii��Ϊ100
    n=s.find("dfg");      //n=4
    n = s.find("dfg");    //n=2
    n=s.find("dhh");      //n=string::npos=4294967295
    n = s.find("wer");    //n=string::npos=4294967295
    n=s.find('f');        //n=3
    n = s.find("f");      //n=3
    string as = "dfg";      //as='g'

    n = s.find_first_of("asdfg");  //n=0�����Ұ����Ӵ��е��κ��ַ��� ���ص�һ��λ��
    n = s.find_first_of(3);        //n=string::npos=4294967295
    n = s.find_first_of("dfg");    //n=4
    n = s.find_first_of("dfg");    //n=2
    n = s.find_first_of("dhh");    //n=2
    n = s.find_first_of("wer");    //n=string::npos=4294967295
    n = s.find_first_of('f');      //n=3����pos��ʼ�����ַ���һ�γ��ֵ�λ��
    n = s.find_first_of("f");      //n=3

    n = s.find_last_of("asdfg"); //n=4�����Ұ����Ӵ��е��κ��ַ����������һ��λ��
    n = s.find_last_of(3);         //n=string::npos=4294967295
    n = s.find_last_of("dfg");     //n=4
    n = s.find_last_of("dfg");     //n=4
    n = s.find_last_of("dhh");     //n=2
    n = s.find_last_of("wer");     //n=string::npos=4294967295
    n = s.find_last_of('f');       //n=3
    n = s.find_last_of("f");       //n=3

    n = s.find_first_not_of("asdfg");//n=string::npos=4294967295�����Ҳ������Ӵ��е��κ��ַ������ص�һ��λ�á��ӵ�ǰ���в��ҵ�һ�����ڲ������е��ַ����ֵ�λ��
    n=s.find_first_not_of(3);      //n=0
    n=s.find_first_not_of("dfg");  //n=0
    n = s.find_first_not_of("dfg");//n=0
    n=s.find_first_not_of("dhh");  //n=0
    n = s.find_first_not_of("wer");//n=0
    n=s.find_first_not_of('f');    //n=0
    n = s.find_first_not_of("f");  //n=0

    n = s.find_last_not_of("asdfg");//n=string::npos=4294967295�����Ҳ������Ӵ��е��κ��ַ����������һ��λ��
    n=s.find_last_not_of(3);          //n=4
    n=s.find_last_not_of("dfg");      //n=3
    n = s.find_last_not_of("dfg");    //n=1
    n=s.find_last_not_of("dhh");      //n=4
    n = s.find_last_not_of("wer");    //n=4
    n=s.find_last_not_of('f');        //n=4
    n = s.find_last_not_of("f");      //n=4

    n = s.rfind("asdfg");  //n=0��������ң���pos��ʼ�Ӻ���ǰ�����ַ�c�ڵ�ǰ���е�λ��
    n=s.rfind(3);          //n=string::npos=4294967295
    n=s.rfind("dfg");      //n=4
    n = s.rfind("dfg");    //n=2
    n=s.rfind("dhh");      //n=string::npos=4294967295
    n = s.rfind("wer");    //n=string::npos=4294967295
    n=s.rfind('f');        //n=3
    n = s.rfind("f");      //n=3

    /*���ϲ��Һ�������������4�Σ�
    size_type find(const basic_string& s, size_type pos = 0)
     //��pos��ʼ�����ַ���s�ڵ�ǰ���е�λ��
    size_type find(const charT* s, size_type pos, size_type n)
     //��pos��ʼ�����ַ���s��ǰn���ַ��ڵ�ǰ���е�λ��
    size_type find(const charT* s, size_type pos = 0)
     //��pos��ʼ�����ַ���s�ڵ�ǰ���е�λ��
    size_type find(charT c, size_type pos = 0)
     //��pos��ʼ�����ַ�c�ڵ�ǰ�ַ�����λ��
    ���еĲ��Һ���������һ��size_type���ͣ��������ֵһ�㶼�����ҵ��ַ���
    ��λ�ã����û���ҵ����򷵻�string::npos��
    ��һ����Ҫ�ر�ע�⣬���к�string::npos�ıȽ�һ��Ҫ��
    string::size_type��ʹ�ã���Ҫֱ��ʹ��int ����unsigned int����
    �͡���ʵstring::npos��ʾ����-1��
    */


    a1=s.front();//a1='a'���������ַ�������ֵΪchar/const char������string�������
    string::allocator_type aa=s.get_allocator();  //���ر��ַ�����������

    s.insert(2,"z");              //s="aszdfg"
    s.insert(2, "qwegt", 3);      //s="asqwezdfg"��
    /*const string a1 = "zxc";  s.insert(2,a1);  //����*/
    s.insert(2, "zxcv", 2, 2);    //s="ascvqwezdfg"
    /*
    string &insert(int p0, const char *s);
    string &insert(int p0, const char *s, int n);
    string &insert(int p0, const string &s);
    string &insert(int p0, const string &s, int pos, int n);
    //ǰ4��������p0λ�ò����ַ���s��pos��ʼ��ǰn���ַ�

    string &insert(int p0, int n, char c);
    //�˺�����p0������n���ַ�c
    iterator insert(iterator it, char c);
    //��it�������ַ�c�����ز�����������λ��
    void insert(iterator it, const_iterator first, const_iterator last);
    //��it������[first��last��֮����ַ�
    void insert(iterator it, int n, char c);
    //��it������n���ַ�c
    */


    n = s.length();    //n=11,s="ascvqwezdfg",�����ַ������ȡ�
    n = s.max_size();  //s="ascvqwezdfg",n=4294967294,����ֵ��string��֧����󳤶ȣ�һ��Ҳ�����õ���ô�����ַ�����
    n=s.npos;  //n=4294967295

    string s11 = "qwe";
    string s22 = "asd";
    string ss = s11 + s22;    //ss=""qweasd""
    ss += "dfr";              //ss=""qweasddfr""
    //s11+=s22;               //����
    //s11 = s22;              //����   string ���ܵ�const char*
    a1 = s[3];                //a1='v'

    s.pop_back();             //s="ascvqwezdf",ɾ�����һλ

    a1 = 'm';
    s.push_back(a1);  //s=""ascvqwezdfm""    ����Ϊchar��


    string::reverse_iterator rit;
    string::const_reverse_iterator crit;

    rit=s.rbegin(); //s="ascvqwezdfm"��ĩβΪstart����ʼΪend���������Ӻ���ǰ����
    a1=rit[3];      //s="ascvqwezdfm"  a1='z'
    rit[3] = 'n';   //rit=""  s="ascvqwendfm"    �Ӻ���ǰ�±�Ϊ���ı����n
    crit = s.rbegin();  //crit=""   s="ascvqwendfm"
    a1 = crit[4];       //a1='e'    s="ascvqwendfm"
    //crit[3] = 'n';    //���� ���ܸı�const������ָ���ֵ


    rit = s.rend();     //s="ascvqwendfm"   ĩβΪstart  ��ʼΪend   rit=""
    //a1 = rit[3];      //���� ���
    // rit[3] = 'n';    //���� ���
    crit = s.rend();    //crit=""   s="ascvqwendfm"
    //a1 = crit[4];     //���� ���
    //crit[3] = 'n';    //���� ���ܸı�const������ָ���ֵ

    string s33 = "mnbvcx";      //s="ascvqwendfm"
    const char * s44= "asdfg";  //s="ascvqwendfm"
    s.replace(2,3,s33); //s="asmnbvcxwendfm"���滻ԭ�ַ����±�2��ʼ����3���ַ�
    s.replace(2, 3, s44);       //s="asasdfgvcxwendfm"
    s.replace(s.begin()+2,s.end()-2, s33);     //s="asmnbvcxfm"
    s.replace(s.begin() + 2, s.end() - 2, s44);//s="asasdfgfm"
    s.replace(2, 3, s33, 2, 3);    //s="asbvcfgfm"
    s.replace(2, 3, s44, 2, 3);    // s="asdfgfgfm"
    s.replace(2, 3, s44, 2);       // s="asasfgfm"
    s.replace(s.begin() + 2, s.end() - 2, s44,4);  //s="asasdffm"
    s.replace(2, 3, 4, 'c'); //s="asccccffm"
    s.replace(s.begin() + 2, s.end() - 2, 4, 'f');  //s="asfffffm"
    /*
    �÷�һ��
      ��str�滻ָ���ַ�������ʼλ��pos��ʼ����Ϊlen���ַ�
      string& replace (size_t pos, size_t len, const string&
      str);

    �÷�����
      ��str�滻 ��������ʼλ�� �� ����λ�� ���ַ�
      string& replace (const_iterator i1, const_iterator i2,
      const string& str);

    �÷�����
      ��substr��ָ���Ӵ���������ʼλ�úͳ��ȣ��滻��ָ��λ���ϵ��ַ���
      string& replace (size_t pos, size_t len, const string&
      str, size_t subpos, size_t sublen);

    �÷��ģ�
      stringתchar*ʱ���������ܻᱨ�����棬����������������str�滻��ָ��
      λ��0��ʼ����Ϊ5���ַ�����
      string& replace(size_t pos, size_t len, const char* s);

    �÷��壺
      stringתchar*ʱ���������ܻᱨ�����棬����������������str�滻��ָ��
      ������λ�õ��ַ���
      string& replace (const_iterator i1, const_iterator i2,
      const char* s);

    �÷�����
      stringתchar*ʱ���������ܻᱨ�����棬����������������s��ǰn���ַ�
      �滻�ӿ�ʼλ��pos����Ϊlen���ַ���
      string& replace(size_t pos, size_t len, const char* s,
      size_t n);

    �÷��ߣ�
      stringתchar*ʱ���������ܻᱨ�����棬����������������s��ǰn���ַ�
      �滻ָ��������λ��(��i1��i2)���ַ���
      string& replace (const_iterator i1, const_iterator i2,
      const char* s, size_t n);

    �÷��ˣ�
      ���ظ�n�ε�c�ַ��滻��ָ��λ��pos����Ϊlen������
      string& replace (size_t pos, size_t len, size_t n, char
      c);

    �÷��ţ�
      ���ظ�n�ε�c�ַ��滻��ָ��������λ�ã���i1��ʼ��������������
      string& replace (const_iterator i1, const_iterator i2,
      size_t n, char c);
   */


    n = s.size();     //n=8   s="asfffffm"
    s.reserve(2);  //ָ�� ���� �ܴ洢���ݵĸ���
    s.resize(3);    //���� ָ�� ��ЧԪ�صĸ��� s="asf"
    n=s.size();     //n=3
    /*
    size() ָĿǰ���ڵ�Ԫ������            Ԫ�ظ���
    capacity() ָ�����ܴ洢 ���ݵĸ���      ��������
    reserve()  ָ�������ܴ洢���ݵĸ���
    resize()   ����ָ����ЧԪ�صĸ��� ��������reserve()ָ�������Ĵ�С
    ������������ʱ������(capacity)Ϊ 0;������ʱ������ԭ������ 1/2 ����
    ������ ���ܴ��ڲ���  vs2010�������ģ�mingw�� ����ԭ���� ��--������
    vector���� Ԫ�������洢�������� ��Ϊlist��ͬ��capacity һ�����
    size��ԭ����Ϊ�˱��� ÿ����������ʱ��Ҫ���·����ڴ棬����һ��� ����һ
    ���ϴ�Ŀռ䣬�Ա��������ݲ��롣
    */

    s = "asdfgh";
    n=s.rfind("sdf",2);         //n=1
    n = s.rfind("serr");        //n=4294967295
    n = s.rfind("serr",2);      //n=4294967295
    n = s.rfind("serr", 2);     //n=4294967295
    n = s.rfind('s', 2);        //n=1
    n = s.rfind('s');           //n=1
    n = s.rfind("serr", 2,3);   //n=4294967295
    n = s.rfind("sdf", 2,2);    //n=1

    /*
    rfindȫ��reversefind,��find�ࡣ

    size_type rfind( const basic_string &str, size_type index
    );
    //�������һ����str�е�ĳ���ַ�ƥ����ַ�����index��ʼ���ҡ����û��
    ���ͷ���string::npos��

    size_type rfind( const char *str, size_type index );
    //�������һ����str�е�ĳ���ַ�ƥ����ַ�����index��ʼ���ҡ����û��
    ���ͷ���string::npos��

    size_type rfind( char ch, size_type index );
    //�������һ����chƥ����ַ�����index��ʼ���ҡ����û�ҵ��ͷ���
    string::npos��

    ����Ҫע����find��ͬ�ĵط���rfind�Ǵ���������index��λ�ã�������Ϊ��
    ׼index��Ȼ������￪ʼ����������������һ�γ���Ŀ���λ�á�
    find���ڻ�׼index������������
    */


    s.shrink_to_fit();  //�޷���ֵ
    /*
    erase �ı���size������û�иı�capacity����δ�����ͷſռ�
    clear�� size==0��capacity���䣬��δ�����ͷſռ䡣
    vector<int>(vec).swap(vec) ʹ��vec��capacity()==size()������
    �ͷ��˿ռ䡣
    C++11���Ѿ�ʵ����shink_to_fit���� ���swap�����ø�������ܻ�����һ
    ���ڴ��ط��䣬�������size����Ӱ�죬ʹ��capacity()==size()��
    */



    ss = s.substr(3);    //s="asdfgh"��ss="fgh"����s���±�3 ��λ�ÿ�ʼȡ��ĩβ
    ss = s.substr(3,4);  //ss="fgh"
    ss = s.substr(1, 4); //ss="sdfg"  ���±�1��ʼȡ4��
    /*
    basic_string substr( size_type index, size_type num = npos
    );�±�ǵ�����
    substr()���ر��ַ�����һ���Ӵ�����index��ʼ����num���ַ���
    ���û��ָ��������Ĭ��ֵ string::npos��������substr()�������򵥵ķ�
    �ش�index��ʼ��ʣ����ַ�����
    */

    s.swap(s);  //s="asdfgh"   ������������string��ֵ �޷���ֵ
    s.swap(ss); //s="sdfg"   ss="asdfgh"
    system("pause");
}
