#include <iostream>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <string>
#include <random>
#include <sstream>
#include <fstream>
using namespace std;
string operator_num;
string s1,s2,rootid="admin",rootpwd="123456";
void welcome();
void adminlogin();
void users(string s);
string rand_num();
string time_gets();
void usersetting(string s);
void sold(string s);
void buytime(string s);
float deal(string s,float m,string sd);
void del_deal(string s);

struct user{
    string id;
    string username;
    string pwd;
    string number;
    string address;
    float wallet;
}userdata[10005];

struct books{//flag: 1.������ 0.���¼� 2.���۳�
    string id;
    string bookname;
    float price{};
    string tim;
    int flag{};
    string dis;
    string sold_id;
    string buy_id;
    string dealtim;
}book[10005];

void adminlogin()
{
    cout<<"===================================================================================="<<endl;
    cout<<"1.�鿴������Ʒ 2.������Ʒ 3.�鿴���ж��� 4.�鿴�����û� 5.ɾ���û� 6.�¼���Ʒ 7.ע��"<<endl;
    cout<<"===================================================================================="<<endl;
    cout<<"��������Ĳ�����:";
    cin>>operator_num;
    if(operator_num=="7")
    {
        cout<<"ȷ���˳���¼��(y/n):";
        cin>>s1;
        if(s1=="y")
        {
            cout<<"***���ڷ���������...***"<<endl;
            welcome();
        }
        else if(s1=="n")
        {
            cout<<"***���ع���Ա����ҳ...***"<<endl;
            adminlogin();
        }
        else
        {
            cout<<"******�Ƿ��ַ�����ǿ�Ʒ���******"<<endl;
            adminlogin();
        }
    }
    else if(operator_num=="2")
    {
        cout<<"������Ҫ��������Ʒ����: ";
        cin>>s1;
        string filename = R"(C:\Users\86188\Desktop\prc2023\demo01)";
        ifstream fin;
        fin.open("databook.txt");
        int cnt = 0;
        while(fin>>book[cnt].id>>book[cnt].bookname>>book[cnt].price>>book[cnt].tim>>book[cnt].flag>>book[cnt].dis>>book[cnt].sold_id>>book[cnt].buy_id>>book[cnt].dealtim)
        {
            cnt++;
        }
        fin.close();
        int flag=0,vis[10005];
        int k=0;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<cnt;i++)
        {
            stringstream ss;
            ss<<book[i].bookname;
            if(ss.str().find(s1)!=string::npos)
            {
                flag++;
                vis[k]=i;
                k++;
            }
        }
        if(flag==0)
        {
            cout<<"******!!!û���ҵ��κ���Ʒ......******"<<endl;
            adminlogin();
        }
        else if(flag>0)
        {
            cout<<"~~Ϊ���ҵ���"<<flag<<"�����......"<<endl;
            cout<<"****************************************************************************************"<<endl;
            cout<<left<<setw(25)<<"��Ʒid"<<setw(30)<<"��Ʒ����"<<setw(25)<<"��Ʒ�۸�"<<setw(25)<<"��Ʒ״̬"<<endl;
            for(int i=0;i<k;i++)
            {
                if(book[vis[i]].flag==1)
                {
                    cout<<left<<setw(25)<<book[vis[i]].id<<setw(30)<<book[vis[i]].bookname<<setw(25)<<book[vis[i]].price<<setw(25)<<"������"<<endl;
                }
                else if(book[vis[i]].flag==0)
                {
                    cout<<left<<setw(25)<<book[vis[i]].id<<setw(30)<<book[vis[i]].bookname<<setw(25)<<book[vis[i]].price<<setw(25)<<"���¼�"<<endl;
                }
                else if(book[vis[i]].flag==2)
                {
                    cout<<left<<setw(25)<<book[vis[i]].id<<setw(30)<<book[vis[i]].bookname<<setw(25)<<book[vis[i]].price<<setw(25)<<"���۳�"<<endl;
                }
            }
            cout<<"****************************************************************************************"<<endl;
            adminlogin();
        }
    }
    else if(operator_num=="2")
    {
        string filename = R"(C:\Users\86188\Desktop\prc2023\demo01)";
        ifstream fin;
        fin.open("databook.txt");
        int cnt = 0;
        while(fin>>book[cnt].id>>book[cnt].bookname>>book[cnt].price>>book[cnt].tim>>book[cnt].flag>>book[cnt].dis>>book[cnt].sold_id>>book[cnt].buy_id>>book[cnt].dealtim)
        {
            cnt++;
        }
        fin.close();
        cout<<setiosflags(ios::fixed)<<setprecision(1);
        cout<<"************************************************************************************************************************"<<endl;
        cout<<left<<setw(20)<<"��Ʒid"<<setw(30)<<"��Ʒ����"<<setw(30)<<"�۸�"<<setw(30)<<"�ϼ�ʱ��"<<setw(20)<<"��Ʒ״̬"<<endl;
        for(int i=0;i<cnt;i++)
        {
            if(book[i].flag==1)
            {
                cout<<left<<setw(20)<<book[i].id<<setw(30)<<book[i].bookname<<setw(30)<<book[i].price<<setw(30)<<book[i].tim<<setw(20)<<"������"<<endl;
            }
            else if(book[i].flag==0)
            {
                cout<<left<<setw(20)<<book[i].id<<setw(30)<<book[i].bookname<<setw(30)<<book[i].price<<setw(30)<<book[i].tim<<setw(20)<<"���¼�"<<endl;
            }
            else if(book[i].flag==2)
            {
                cout<<left<<setw(20)<<book[i].id<<setw(30)<<book[i].bookname<<setw(30)<<book[i].price<<setw(30)<<book[i].tim<<setw(20)<<"���۳�"<<endl;
            }
        }
        cout<<"************************************************************************************************************************"<<endl;
        adminlogin();
    }
    else if(operator_num=="6")
    {
        string filename = R"(C:\Users\86188\Desktop\prc2023\demo01)";
        ifstream fin;
        fin.open("databook.txt");
        int cnt=0;
        while(fin>>book[cnt].id>>book[cnt].bookname>>book[cnt].price>>book[cnt].tim>>book[cnt].flag>>book[cnt].dis>>book[cnt].sold_id>>book[cnt].buy_id>>book[cnt].dealtim)
        {
            cnt++;
        }
        fin.close();
        int k = 0;
        for (int i = 0; i < cnt; i++)
        {
            if (book[i].flag==1)
            {
                k++;
            }
        }
        if (k==0)
        {
            cout << "******û�������۳�����Ʒ���������ز���ҳ...******" << endl;
            adminlogin();
        }
        else
        {
            cout<< "!!!��ǰ������" << k << "����Ʒ!!!"<<endl;
            cout<< "***************************"<<endl;
            cout<<"����������Ҫ�¼ܵ���Ʒid:";
            cin >> s1;
            int flag = 0,m=0;
            for (int i = 0; i < cnt; i++)
            {
                if (book[i].id == s1&&book[i].flag==1)
                {
                    flag = 1;
                    m=i;
                    break;
                }
            }
            if(flag==0)
            {
                cout << "******ɾ��ʧ�ܣ�û���й���Ʒ��******" << endl;
                flag=0,m=0;
                adminlogin();
            }
            else if(flag==1)
            {
                cout << "*********��ȷ����Ʒ��Ϣ������*********" << endl;
                cout << "��Ʒid:" << book[m].id << endl;
                cout << "��Ʒ����:" << book[m].bookname << endl;
                cout << "**********************************" << endl;
                cout << "�Ƿ��¼�?(y/n):";
                cin >> s2;
                if (s2 == "n")
                {
                    cout << "��ȡ���˸ò���!" << endl;
                    adminlogin();
                }
                else if (s2 == "y")
                {
                    book[m].flag = 0;
                    ofstream fout;
                    fout.open("databook.txt");
                    for (int i = 0; i < cnt; i++)
                    {
                        fout<<book[i].id<< " "<<book[i].bookname<<" "<<book[i].price<<" "<<book[i].tim<<" "<<book[i].flag<<" "<<book[i].dis<<" "<<book[i].sold_id<<" "<<book[i].buy_id<<" "<<book[i].dealtim<<endl;
                    }
                    fout.close();
                    cout << "******�����ɹ����������ز���ҳ...******" << endl;
                    adminlogin();
                }
                else
                {
                    cout<<"******�Ƿ��ַ�����ǿ�Ʒ���......******"<<endl;
                }
            }
        }
    }
    else if(operator_num=="3")
    {
        string filename=R"(C:\Users\86188\Desktop\prc2023\demo01\databook.txt)";
        ifstream fin;
        fin.open("databook.txt");
        int cnt=0;
        while(fin>>book[cnt].id>>book[cnt].bookname>>book[cnt].price>>book[cnt].tim>>book[cnt].flag>>book[cnt].dis>>book[cnt].sold_id>>book[cnt].buy_id>>book[cnt].dealtim)
        {
            cnt++;
        }
        fin.close();
        int k=0;
        for(int i=0;i<cnt;i++)
        {
            if(book[i].flag==2)
            {
                k++;
            }
        }
        if(k==0)
        {
            cout<<"******���ݿ������κν��׳ɹ���¼��******"<<endl;
            adminlogin();
        }
        else
        {
            cout<<setiosflags(ios::fixed)<<setprecision(1);
            cout<<"***************************************************************************************************************************************************"<<endl;
            cout<<left<<setw(25)<<"��Ʒid"<<setw(25)<<"��Ʒ����"<<setw(25)<<"�ɽ��۸�"<<setw(25)<<"����ʱ��"<<setw(25)<<"����id"<<setw(25)<<"���id"<<endl;
            for(int i=0;i<cnt;i++)
            {
                if(book[i].flag==2)
                {
                    cout<<left<<setw(25)<<book[i].id<<setw(25)<<book[i].bookname<<setw(25)<<book[i].price<<setw(25)<<book[i].dealtim<<setw(25)<<book[i].sold_id<<setw(25)<<book[i].buy_id<<endl;
                }
            }
            cout<<"***************************************************************************************************************************************************"<<endl;
        }
        adminlogin();
    }
    else if(operator_num=="4")
    {
        string filename=R"(C:\Users\86188\Desktop\prc2023\demo01\loginuser.txt)";
        ifstream fin;
        fin.open("loginuser.txt");
        int cnr=0;
        while(fin>>userdata[cnr].id>>userdata[cnr].username>>userdata[cnr].pwd>>userdata[cnr].number>>userdata[cnr].address>>userdata[cnr].wallet)
        {
            cnr++;
        }
        fin.close();
        cout<<setiosflags(ios::fixed)<<setprecision(1);
        cout<<"*****************************************************************************************"<<endl;
        cout<<left<<setw(20)<<"�û�id"<<setw(20)<<"�û���"<<setw(20)<<"��ϵ��ʽ"<<setw(20)<<"��ַ"<<setw(20)<<"Ǯ�����"<<endl;
        for(int i=0;i<cnr;i++)
        {
            cout<<left<<setw(20)<<userdata[i].id<<setw(20)<<userdata[i].username<<setw(20)<<userdata[i].number<<setw(20)<<userdata[i].address<<setw(20)<<userdata[i].wallet<<endl;
        }
        cout<<"*****************************************************************************************"<<endl;
        adminlogin();
    }
    else if(operator_num=="5")
    {
        string filename=R"(C:\Users\86188\Desktop\prc2023\demo01\loginuser.txt)";
        ifstream fin;
        fin.open("loginuser.txt");
        int cnr=0;
        while(fin>>userdata[cnr].id>>userdata[cnr].username>>userdata[cnr].pwd>>userdata[cnr].number>>userdata[cnr].address>>userdata[cnr].wallet)
        {
            cnr++;
        }
        fin.close();
        cout<<"������Ҫɾ�����˻�Uid:";
        string dels;
        cin>>dels;
        int flag=0,k=0;
        for(int i=0;i<cnr;i++)
        {
            if(userdata[i].id==dels)
            {
                flag=1;
                k=i;
                break;
            }
        }
        if(flag==1)
        {
            cout<<"��Ҫɾ�����û���Ϣ:"<<endl;
            cout<<"*********************"<<endl;
            cout<<"�û�id:"<<userdata[k].id<<endl;
            cout<<"�û���:"<<userdata[k].username<<endl;
            cout<<"��ϵ��ʽ:"<<userdata[k].number<<endl;
            cout<<"*********************"<<endl;
            cout<<"�Ƿ�ɾ��?(y/n):";
            cin>>s1;
            string st=userdata[k].id;
            if(s1=="y")
            {
                userdata[k].id="DEX";
                ofstream fout;
                fout.open("loginuser.txt");
                for(int i=0;i<cnr;i++)
                {
                    if(userdata[i].id!="DEX")
                    {
                        fout<<userdata[i].id<<" "<<userdata[i].username<<" "<<userdata[i].pwd<<" "<<userdata[i].number<<" "<<userdata[i].address<<" "<<userdata[i].wallet<<endl;
                    }
                }
                fout.close();
                del_deal(st);
                cout<<"ɾ���ɹ����������ع���Ա����ҳ......"<<endl;
                adminlogin();
            }
            else if(s1=="n")
            {
                cout<<"���Ѿ�ȡ��������"<<endl;
                adminlogin();
            }
            else
            {
                cout<<"******�Ƿ��ַ�����ǿ�Ʒ���.....******"<<endl;
            }
        }
        else
        {
            cout<<"******ɾ��ʧ�ܣ����ݿ��в����ڸ��û���******"<<endl;
            adminlogin();
        }
    }
    else
    {
        cout<<"!!!��������ȷ������!!!"<<endl;
        adminlogin();
    }
}

void welcome()
{
    cout<<"============================================="<<endl;
    cout<<"1.�û���¼ 2.�û�ע�� 3.����Ա��¼ 4.�˳�����"<<endl;
    cout<<"============================================="<<endl;
    cout<<"�������:";
    cin>>operator_num;
    if(operator_num=="4")
    {
        return ;
    }
    else if(operator_num=="3")
    {
        cout<<"���������Ա�˺�:";
        cin>>s1;
        cout<<"����������:";
        cin>>s2;
        if(s1==rootid&&s2==rootpwd)
        {
            cout<<"*****��¼�ɹ�!��ӭ,"<<rootid<<"*****"<<endl;
            adminlogin();
        }
        else
        {
            cout<<"***����Ա�˺Ż�������󣬼����������˵�...***"<<endl;
            welcome();
        }
    }
    else if(operator_num=="1")
    {
        cout<<"�������û���:";
        cin>>s1;
        cout<<"����������:";
        cin>>s2;
        int cnr=0;
        int flx=0;
        int k=0;
        string filename=R"(C:\Users\86188\Desktop\prc2023\demo01\loginuser.txt)";
        ifstream fin;
        fin.open("loginuser.txt");
        while(fin>>userdata[cnr].id>>userdata[cnr].username>>userdata[cnr].pwd>>userdata[cnr].number>>userdata[cnr].address>>userdata[cnr].wallet)
        {
            cnr++;
        }
        fin.close();
        for(int i=0;i<cnr;i++)
        {
            if(s1==userdata[i].username&&s2==userdata[i].pwd)
            {
                flx=1;
                k=i;
                break;
            }
        }
        string tmp=userdata[k].id;
        if(flx==1)
        {
            cout << "******��¼�ɹ�,��ӭ" << s1 << "******" << endl;
            users(tmp);
        }
        else
        {
            cout<<"����˺Ż���������뷵�����������µ�¼��ע��......"<<endl;
            welcome();
        }
    }
    else if(operator_num=="2")
    {
        cout<<"*****��ӭע��*****"<<endl;
        cout<<"�������û���:";
        cin>>s1;
        cout<<"����������:";
        cin>>s2;
        int cnt=0;
        int flag=0;
        string filename=R"(C:\Users\86188\Desktop\prc2023\demo01\loginuser.txt)";
        ifstream fin;
        fin.open("loginuser.txt");
        while(fin>>userdata[cnt].id>>userdata[cnt].username>>userdata[cnt].pwd>>userdata[cnt].number>>userdata[cnt].address>>userdata[cnt].wallet)
        {
            cnt++;
        }
        fin.close();
        for(int i=0;i<cnt;i++)//����û����Ƿ��ظ�
        {
            if(s1==userdata[i].username)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            cout<<"���û����Ѵ��ڣ�����������..."<<endl;
            welcome();
        }
        else
        {
            cout<<"**********�밴�������������Ϣ**********"<<endl;
            cout<<"���������ϵ��ʽ:";
            string pho,adds;
            float a=0.00;
            cin>>pho;
            cout<<"��������ĵ�ַ:";
            cin>>adds;
            userdata[cnt].wallet=a;
            userdata[cnt].id="U"+rand_num();
            string str=userdata[cnt].id;
            userdata[cnt].number=pho;
            userdata[cnt].address=adds;
            userdata[cnt].username=s1;
            userdata[cnt].pwd=s2;
            ofstream fout;
            fout.open("loginuser.txt");
            for(int i=0;i<=cnt;i++)
            {
                fout<<userdata[i].id<<" "<<userdata[i].username<<" "<<userdata[i].pwd<<" "<<userdata[i].number<<" "<<userdata[i].address<<" "<<userdata[i].wallet<<endl;
            }
            cout<<"**********ע��ɹ�!**********"<<endl;
            users(str);
        }
    }
    else
    {
        cout<<"�벻Ҫ����Ƿ��ַ���"<<endl;
        welcome();
    }
}

void users(string s)
{
    cout<<"======================================="<<endl;
    cout<<"1.�˳���¼ 2.��Ҫ�� 3.��Ҫ�� 4.�ҵ���Ϣ"<<endl;
    cout<<"======================================="<<endl;
    cout<<"�������:";
    cin>>operator_num;
    if(operator_num=="1")
    {
        cout<<"ȷ���˳���?(y/n):";
        string opt;
        cin>>opt;
        if(opt=="y")
        {
            cout<<"******!!!����������......******"<<endl;
            welcome();
        }
        else if(opt=="n")
        {
            users(s);
        }
        else
        {
            cout<<"******�Ƿ��ַ�����ǿ�Ʒ���......******"<<endl;
            users(s);
        }
    }
    else if(operator_num=="4")
    {
        usersetting(s);
    }
    else if(operator_num=="3")
    {
        sold(s);
    }
    else if(operator_num=="2")
    {
        cout<<"~~��ӭ����xianyu����ƽ̨,�������ֽ����йع�����!!"<<endl;
        buytime(s);
    }
    else
    {
        cout<<"!!!��������ȷ������!!!"<<endl;
        users(s);
    }
}

void usersetting(string s)
{
    cout<<"=============================================="<<endl;
    cout<<"1.�����û������� 2.�޸���Ϣ 3.�鿴��Ϣ 4.��ֵ"<<endl;
    cout<<"=============================================="<<endl;
    cout<<"�������:";
    cin>>operator_num;
    if(operator_num=="1")
    {
        users(s);
    }
    else if(operator_num=="2")
    {
        string num;
        cout<<"������Ҫ�޸ĵ��������ֱ��(1.�û��� 2.��ϵ��ʽ 3.��ַ):";
        cin>>num;
        string filename=R"(C:\Users\86188\Desktop\prc2023\demo01\loginuser.txt)";
        ifstream fin;
        fin.open("loginuser.txt");
        int cnr=0;
        while(fin>>userdata[cnr].id>>userdata[cnr].username>>userdata[cnr].pwd>>userdata[cnr].number>>userdata[cnr].address>>userdata[cnr].wallet)
        {
            cnr++;
        }
        fin.close();
        int k=0;
        for(int i=0;i<cnr;i++)
        {
            if(userdata[i].id==s)
            {
                k=i;
                break;
            }
        }
        if(num=="1")
        {
            cout<<"�������޸ĺ���û���:";
            cin>>s1;
            userdata[k].username=s1;
        }
        else if(num=="2")
        {
            cout<<"������Ҫ�޸ĵ���ϵ��ʽ:";
            cin>>s1;
            userdata[k].number=s1;
        }
        else if(num=="3")
        {
            cout<<"������Ҫ�޸ĵĵ�ַ:";
            cin>>s1;
            userdata[k].address=s1;
        }
        else
        {
            cout<<"!!!��������ȷ������!!!"<<endl;
            usersetting(s);
        }
        ofstream fout;
        fout.open("loginuser.txt");
        for(int i=0;i<cnr;i++)
        {
            fout<<userdata[i].id<<" "<<userdata[i].username<<" "<<userdata[i].pwd<<" "<<userdata[i].number<<" "<<userdata[i].address<<" "<<userdata[i].wallet<<endl;
        }
        fout.close();
        cout<<"�޸ĳɹ�!�����ص�������Ϣ����ҳ..."<<endl;
        usersetting(s);
    }
    else if(operator_num=="3")
    {
        string filename=R"(C:\Users\86188\Desktop\prc2023\demo01\loginuser.txt)";
        ifstream fin;
        int cnr=0;
        fin.open("loginuser.txt");
        while(fin>>userdata[cnr].id>>userdata[cnr].username>>userdata[cnr].pwd>>userdata[cnr].number>>userdata[cnr].address>>userdata[cnr].wallet)
        {
            cnr++;
        }
        fin.close();
        int k=0;
        for(int i=0;i<cnr;i++)
        {
            if(userdata[i].id==s)
            {
                k=i;
                break;
            }
        }
        cout<<setiosflags(ios::fixed)<<setprecision(1);
        cout<<"****************************"<<endl;
        cout<<"�û���:"<<userdata[k].username<<endl;
        cout<<"��ϵ��ʽ:"<<userdata[k].number<<endl;
        cout<<"��ַ:"<<userdata[k].address<<endl;
        cout<<"��ǰǮ�����:"<<userdata[k].wallet<<endl;
        cout<<"****************************"<<endl;
        usersetting(s);
    }
    else if(operator_num=="4")
    {
        string filename=R"(C:\Users\86188\Desktop\prc2023\demo01\loginuser.txt)";
        ifstream fin;
        fin.open("loginuser.txt");
        int cnr=0;
        while(fin>>userdata[cnr].id>>userdata[cnr].username>>userdata[cnr].pwd>>userdata[cnr].number>>userdata[cnr].address>>userdata[cnr].wallet)
        {
            cnr++;
        }
        fin.close();
        int k=0;
        float m;
        for(int i=0;i<cnr;i++)
        {
            string st=userdata[i].id;
            if(st==s)
            {
                k=i;
                break;
            }
        }
        cout<<"�������ֵ���:";
        cin>>m;
        userdata[k].wallet+=m;
        float b=userdata[k].wallet;
        ofstream fout;
        fout.open("loginuser.txt");
        for(int i=0;i<cnr;i++)
        {
            fout<<userdata[i].id<<" "<<userdata[i].username<<" "<<userdata[i].pwd<<" "<<userdata[i].number<<" "<<userdata[i].address<<" "<<userdata[i].wallet<<endl;
        }
        fout.close();
        cout<<setiosflags(ios::fixed)<<setprecision(1);
        cout<<"��ֵ�ɹ�!��ǰ���Ϊ:"<<b<<endl;
        cout<<"�������ظ�����Ϣ����ҳ......"<<endl;
        usersetting(s);
    }
    else
    {
        cout<<"!!!��������ȷ������!!!"<<endl;
        usersetting(s);
    }
}

int main()
{
    welcome();
    return 0;
}

string rand_num()//�������id
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(10000,99999);
    int num =dis(gen);
    string sk= to_string(num);
    return sk;
}

string time_gets()//��ȡʱ��
{
    std::time_t now = std::time(nullptr);
    std::stringstream ss;
    ss<<std::put_time(std::localtime(&now),"%Y-%m-%d");
    std::string s=ss.str();
    return s;
}

void sold(string s)
{
    cout<<"==================================================================================="<<endl;
    cout<<"1.������Ʒ 2.�鿴������Ʒ 3.�޸���Ʒ��Ϣ 4.�¼���Ʒ 5.�鿴������ʷ 6.�����û�������"<<endl;
    cout<<"==================================================================================="<<endl;
    cout<<"�������:";
    cin>>operator_num;
    if(operator_num=="6")
    {
        users(s);
    }
    else if(operator_num=="1")
    {
        string nme,dep;
        float a=0.00;
        cout<<"��������Ʒ����:";
        cin>>nme;
        cout<<"��������Ʒ���:";
        cin>>a;
        cout<<"��������Ʒ����:";
        cin>>dep;
        cout<<"**********��ȷ����Ʒ��Ϣ!**********"<<endl;
        cout<<"��Ʒ����:"<<nme<<endl;
        cout<<"��Ʒ�۸�:"<<a<<endl;
        cout<<"��Ʒ����:"<<dep<<endl;
        cout<<"********************************"<<endl;
        cout<<"ȷ�Ϸ�������Ʒ��?(y/n):";
        cin>>s1;
        if(s1=="y")
        {
            string filename=R"(C:\Users\86188\Desktop\prc2023\demo01\databook.txt)";
            ifstream fin;
            fin.open("databook.txt");
            int cnt=0;
            while(fin>>book[cnt].id>>book[cnt].bookname>>book[cnt].price>>book[cnt].tim>>book[cnt].flag>>book[cnt].dis>>book[cnt].sold_id>>book[cnt].buy_id>>book[cnt].dealtim)
            {
                cnt++;
            }
            fin.close();
            book[cnt].flag=1;
            book[cnt].price=a;
            book[cnt].id="M"+rand_num();
            book[cnt].tim=time_gets();
            book[cnt].dis=dep;
            book[cnt].bookname=nme;
            book[cnt].buy_id="��";
            book[cnt].dealtim="nan";
            book[cnt].sold_id=s;
            ofstream fout;
            fout.open("databook.txt");
            for(int i=0;i<=cnt;i++)
            {
                fout<<book[i].id<<" "<<book[i].bookname<<" "<<book[i].price<<" "<<book[i].tim<<" "<<book[i].flag<<" "<<book[i].dis<<" "<<book[i].sold_id<<" "<<book[i].buy_id<<" "<<book[i].dealtim<<endl;
            }
            fout.close();
            cout<<"*****�����ɹ�!������������ҳ...*****"<<endl;
            sold(s);
        }
        else if(s1=="n")
        {
            cout<<"��ȡ���˷���......"<<endl;
            sold(s);
        }
        else
        {
            cout<<"******�Ƿ��ַ�����ǿ�Ʒ���......******"<<endl;
            sold(s);
        }
    }
    else if(operator_num=="2")
    {
        string filename=R"(C:\Users\86188\Desktop\prc2023\demo01\databook.txt)";
        ifstream fin;
        fin.open("databook.txt");
        int cnt=0;
        while(fin>>book[cnt].id>>book[cnt].bookname>>book[cnt].price>>book[cnt].tim>>book[cnt].flag>>book[cnt].dis>>book[cnt].sold_id>>book[cnt].buy_id>>book[cnt].dealtim)
        {
            cnt++;
        }
        fin.close();
        cout<<setiosflags(ios::fixed)<<setprecision(1);
        cout<<"*************************************************************************************************************"<<endl;
        cout<<left<<setw(25)<<"��Ʒid"<<setw(25)<<"��Ʒ����"<<setw(25)<<"�۸�"<<setw(25)<<"�ϼ�ʱ��"<<setw(25)<<"��Ʒ״̬"<<endl;
        for(int i=0;i<cnt;i++)
        {
            if(book[i].flag==1&&book[i].sold_id==s)
            {
                cout<<left<<setw(25)<<book[i].id<<setw(25)<<book[i].bookname<<setw(25)<<book[i].price<<setw(25)<<book[i].tim<<setw(25)<<"������"<<endl;
            }
            else if(book[i].flag==0&&book[i].sold_id==s)
            {
                cout<<left<<setw(25)<<book[i].id<<setw(25)<<book[i].bookname<<setw(25)<<book[i].price<<setw(25)<<book[i].tim<<setw(25)<<"���¼�"<<endl;
            }
            else if(book[i].flag==2&&book[i].sold_id==s)
            {
                cout<<left<<setw(25)<<book[i].id<<setw(25)<<book[i].bookname<<setw(25)<<book[i].price<<setw(25)<<book[i].tim<<setw(25)<<"���۳�"<<endl;
            }
        }
        cout<<"*************************************************************************************************************"<<endl;
        sold(s);
    }
    else if(operator_num=="3")
    {
        cout<<"=============================================="<<endl;
        cout<<"������Ҫ���ĵ���Ʒid:";
        cin>>s1;
        string filename=R"(C:\Users\86188\Desktop\prc2023\demo01\databook.txt)";
        ifstream fin;
        fin.open("databook.txt");
        int cnt=0;
        while(fin>>book[cnt].id>>book[cnt].bookname>>book[cnt].price>>book[cnt].tim>>book[cnt].flag>>book[cnt].dis>>book[cnt].sold_id>>book[cnt].buy_id>>book[cnt].dealtim)
        {
            cnt++;
        }
        fin.close();
        int flag=0;
        int k=0;
        for(int i=0;i<cnt;i++)
        {
            if(book[i].sold_id==s&&book[i].id==s1)
            {
                flag=1;
                k=i;
                break;
            }
        }
        if(flag==0)
        {
            cout<<"*****û���ҵ�����Ʒ!�����������Ҳ���ҳ...*****"<<endl;
            sold(s);
        }
        else
        {
            cout<<"������Ҫ���ĵ���Ʒ���Ա��(1.�۸� 2.����):";
            cin>>s2;
            if(s2=="1")
            {
                cout<<"������ĺ�ļ۸�:";
                float a;
                cin>>a;
                book[k].price=a;
                cout<<"*****���ĳɹ�!���ڷ������Ҳ���ҳ...*****"<<endl;
            }
            else if(s2=="2")
            {
                cout<<"������ĺ������:";
                string st;
                cin>>st;
                book[k].dis=st;
                cout<<"*****���ĳɹ�!���ڷ������Ҳ���ҳ...*****"<<endl;
            }
            else
            {
                cout<<"�޸�ʧ�ܣ�������Ϸ����ַ���"<<endl;
            }
        }
        cout<<"=============================================="<<endl;
        ofstream fout;
        fout.open("databook.txt");
        cout<<setiosflags(ios::fixed)<<setprecision(1);
        for(int i=0;i<cnt;i++)
        {
            fout<<book[i].id<<" "<<book[i].bookname<<" "<<book[i].price<<" "<<book[i].tim<<" "<<book[i].flag<<" "<<book[i].dis<<" "<<book[i].sold_id<<" "<<book[i].buy_id<<" "<<book[i].dealtim<<endl;
        }
        fout.close();
        sold(s);
    }
    else if(operator_num=="4")
    {
        cout<<"***************************"<<endl;
        cout<<"����������Ҫ�¼ܵ���Ʒid:";
        cin>>s1;
        string filename=R"(C:\Users\86188\Desktop\prc2023\demo01\databook.txt)";
        ifstream fin;
        fin.open("databook.txt");
        int cnt=0;
        while(fin>>book[cnt].id>>book[cnt].bookname>>book[cnt].price>>book[cnt].tim>>book[cnt].flag>>book[cnt].dis>>book[cnt].sold_id>>book[cnt].buy_id>>book[cnt].dealtim)
        {
            cnt++;
        }
        fin.close();
        int k=0,flag=0;
        for(int i=0;i<cnt;i++)
        {
            if(s1==book[i].id)
            {
                k=i;
                flag=1;
                break;
            }
        }
        if(flag==0&&book[k].flag!=0)
        {
            cout<<"******û���ҵ�����Ʒ�������������Ҳ���ҳ...******"<<endl;
            sold(s);
        }
        else if((flag!=0&&book[k].flag==2)||(flag!=0&&book[k].flag==0))
        {
            cout<<"����Ʒ�Ѿ������¼ܻ�����ȥ����"<<endl;
            sold(s);
        }
        else if(flag!=0&&book[k].flag==1)
        {
            cout<<"*********��ȷ����Ʒ��Ϣ������*********"<<endl;
            cout<<"��Ʒid:"<<book[k].id<<endl;
            cout<<"��Ʒ����:"<<book[k].bookname<<endl;
            cout<<"**********************************"<<endl;
            cout<<"��Ʒ�¼ܽ����ɸ��Ĳ����浽��������,�Ƿ�ɾ��?(y/n):";
            cin>>s2;
            if(s2=="n")
            {
                cout<<"��ȡ���˸ò���!"<<endl;
                sold(s);
            }
            else if(s2=="y")
            {
                book[k].flag=0;
                ofstream fout;
                fout.open("databook.txt");
                cout<<setiosflags(ios::fixed)<<setprecision(1);
                for(int i=0;i<cnt;i++)
                {
                    fout<<book[i].id<<" "<<book[i].bookname<<" "<<book[i].price<<" "<<book[i].tim<<" "<<book[i].flag<<" "<<book[i].dis<<" "<<book[i].sold_id<<" "<<book[i].buy_id<<" "<<book[i].dealtim<<endl;
                }
                cout<<"******�����ɹ���������������ҳ...******"<<endl;
                fout.close();
                sold(s);
            }
            else
            {
                cout<<"******�Ƿ��ַ�����ǿ�Ʒ���......******"<<endl;
                sold(s);
            }
        }
    }
    else if(operator_num=="5")
    {
        string filename=R"(C:\Users\86188\Desktop\prc2023\demo01\databook.txt)";
        ifstream fin;
        fin.open("databook.txt");
        int cnt=0;
        while(fin>>book[cnt].id>>book[cnt].bookname>>book[cnt].price>>book[cnt].tim>>book[cnt].flag>>book[cnt].dis>>book[cnt].sold_id>>book[cnt].buy_id>>book[cnt].dealtim)
        {
            cnt++;
        }
        fin.close();
        int k=0;
        for(int i=0;i<cnt;i++)
        {
            if(book[i].sold_id==s)
            {
                k++;
            }
        }
        if(k==0)
        {
            cout<<endl<<"                                                  ~TAT �㻹û������ȥ�Ķ�����......"<<endl;
            sold(s);
        }
        else
        {
            cout<<setiosflags(ios::fixed)<<setprecision(1);
            cout<<"***************************************************************************************************************************************************"<<endl;
            cout<<left<<setw(25)<<"��Ʒid"<<setw(25)<<"��Ʒ����"<<setw(25)<<"�ɽ��۸�"<<setw(25)<<"����ʱ��"<<setw(25)<<"���id"<<endl;
            for(int i=0;i<cnt;i++)
            {
                if(book[i].flag==2&&book[i].sold_id==s)
                {
                    cout<<left<<setw(25)<<book[i].id<<setw(25)<<book[i].bookname<<setw(25)<<book[i].price<<setw(25)<<book[i].dealtim<<setw(25)<<book[i].buy_id<<endl;
                }
            }
            cout<<"***************************************************************************************************************************************************"<<endl;
            sold(s);
        }
    }
    else
    {
        cout<<"!!!��������ȷ������!!!"<<endl;
        sold(s);
    }
}

void buytime(string s)
{
    cout<<"======================================================================================="<<endl;
    cout<<"1.�鿴��Ʒ�б� 2.������Ʒ 3.������Ʒ 4.�鿴��ʷ���� 5.�鿴��Ʒ��ϸ��Ϣ 6.�����û�������"<<endl;
    cout<<"======================================================================================="<<endl;
    cout<<"�����������:";
    cin>>operator_num;
    if(operator_num=="1")
    {
        string filename = R"(C:\Users\86188\Desktop\prc2023\demo01)";
        ifstream fin;
        fin.open("databook.txt");
        int cnt = 0;
        while(fin>>book[cnt].id>>book[cnt].bookname>>book[cnt].price>>book[cnt].tim>>book[cnt].flag>>book[cnt].dis>>book[cnt].sold_id>>book[cnt].buy_id>>book[cnt].dealtim)
        {
            cnt++;
        }
        fin.close();
        int k=0;
        for(int i=0;i<cnt;i++)
        {
            if(book[i].flag==1)
            {
                k++;
            }
        }
        cout<<setiosflags(ios::fixed)<<setprecision(1);
        if(k==0)
        {
            cout<<"~~~~~~~~~~��Ȼһ����Ʒ��û��!�ȵ�������......~~~~~~~~~~\n";
            buytime(s);
        }
        else
        {
            cout<<setiosflags(ios::fixed)<<setprecision(1);
            cout<<"*************************************************************************************************************"<<endl;
            cout<<left<<setw(20)<<"��Ʒid"<<setw(30)<<"��Ʒ����"<<setw(30)<<"�۸�"<<setw(20)<<"�ϼ�ʱ��"<<setw(20)<<"����id"<<endl;
            for(int i=0;i<cnt;i++)
            {
                if(book[i].flag==1&&book[i].sold_id!=s)
                {
                    cout<<left<<setw(20)<<book[i].id<<setw(30)<<book[i].bookname<<setw(30)<<book[i].price<<setw(20)<<book[i].tim<<setw(20)<<book[i].sold_id<<endl;
                }
            }
            cout<<"*************************************************************************************************************"<<endl;
            buytime(s);
        }
    }
    else if(operator_num=="2")
    {
        cout<<"��������Ҫ�����Ʒid(������������水1�鿴������Ʒ):";
        cin>>s1;
        string filename = R"(C:\Users\86188\Desktop\prc2023\demo01)";
        ifstream fin;
        fin.open("databook.txt");
        int cnt=0;
        while(fin>>book[cnt].id>>book[cnt].bookname>>book[cnt].price>>book[cnt].tim>>book[cnt].flag>>book[cnt].dis>>book[cnt].sold_id>>book[cnt].buy_id>>book[cnt].dealtim)
        {
            cnt++;
        }
        fin.close();
        int flag=0,k=0;
        for(int i=0;i<cnt;i++)
        {
            if(s1==book[i].id&&book[i].flag==1)
            {
                flag=1;
                k=i;
                break;
            }
        }
        if(flag==0)
        {
            cout<<"*******�������������id����,��������������******"<<endl;
            buytime(s);
        }
        else if(flag==1)
        {
            cout<<">>>>>|ȷ��Ҫ����:   "<<book[k].bookname<<"   ��?(y/n)|<<<<<";
            cin>>s2;
            if(s2=="n")
            {
                cout<<"*****���Ѿ�ȡ���˶���!*****"<<endl;
                buytime(s);
            }
            else if(s2=="y")
            {
                string sa=book[k].sold_id;
                float x=deal(s,book[k].price,sa);
                if(x<0)
                {
                    cout<<endl;
                    cout<<"          *******!!!����ʧ�ܣ�������㣬�뵽�û�������->��ֵ��������*******";
                    cout<<endl;
                    buytime(s);
                }
                else
                {
                    string st=time_gets();
                    book[k].buy_id=s;
                    book[k].dealtim=st;
                    book[k].flag=2;
                    cout<<setiosflags(ios::fixed)<<setprecision(1);
                    cout<<"***************��������!!!**************"<<endl;
                    cout<<"��Ʒid: "<<book[k].id<<endl;
                    cout<<"��Ʒ����: "<<book[k].bookname<<endl;
                    cout<<"�ɽ��۸�: "<<book[k].price<<endl;
                    cout<<"����ʱ��: "<<st<<endl;
                    cout<<"ʣ�����: "<<x<<endl;
                    cout<<"***************************************"<<endl;
                    ofstream fout;
                    fout.open("databook.txt");
                    for (int i = 0; i < cnt; i++)
                    {
                        fout<<book[i].id<< " "<<book[i].bookname<<" "<<book[i].price<<" "<<book[i].tim<<" "<<book[i].flag<<" "<<book[i].dis<<" "<<book[i].sold_id<<" "<<book[i].buy_id<<" "<<book[i].dealtim<<endl;
                    }
                    fout.close();
                    buytime(s);
                }
            }
        }
    }
    else if(operator_num=="4")
    {
        string filename = R"(C:\Users\86188\Desktop\prc2023\demo01)";
        ifstream fin;
        fin.open("databook.txt");
        int cnt = 0;
        while(fin>>book[cnt].id>>book[cnt].bookname>>book[cnt].price>>book[cnt].tim>>book[cnt].flag>>book[cnt].dis>>book[cnt].sold_id>>book[cnt].buy_id>>book[cnt].dealtim)
        {
            cnt++;
        }
        fin.close();
        int k=0;
        for(int i=0;i<cnt;i++)
        {
            if(book[i].flag==2&&book[i].dealtim!="nan"&&book[i].buy_id!="��")
            {
                k++;
            }
        }
        cout<<setiosflags(ios::fixed)<<setprecision(1);
        if(k==0)
        {
            cout<<"~~~~~~~~~~��һ����Ʒ��û��!��ȥ�����ö���......~~~~~~~~~~\n";
            buytime(s);
        }
        else
        {
            cout<<setiosflags(ios::fixed)<<setprecision(1);
            cout<<"*************************************************************************************************************"<<endl;
            cout<<left<<setw(20)<<"��Ʒid"<<setw(30)<<"��Ʒ����"<<setw(30)<<"�ɽ��۸�"<<setw(20)<<"����ʱ��"<<setw(20)<<"����id"<<endl;
            for(int i=0;i<cnt;i++)
            {
                if(book[i].flag==2&&book[i].buy_id==s)
                {
                    cout<<left<<setw(20)<<book[i].id<<setw(30)<<book[i].bookname<<setw(30)<<book[i].price<<setw(20)<<book[i].dealtim<<setw(20)<<book[i].sold_id<<endl;
                }
            }
            cout<<"*************************************************************************************************************"<<endl;
            buytime(s);
        }
    }
    else if(operator_num=="5")
    {
        cout<<"�������ѯ����Ʒid:";
        cin>>s1;
        string filename = R"(C:\Users\86188\Desktop\prc2023\demo01)";
        ifstream fin;
        fin.open("databook.txt");
        int cnt = 0;
        while(fin>>book[cnt].id>>book[cnt].bookname>>book[cnt].price>>book[cnt].tim>>book[cnt].flag>>book[cnt].dis>>book[cnt].sold_id>>book[cnt].buy_id>>book[cnt].dealtim)
        {
            cnt++;
        }
        fin.close();
        int k=0,flag=0;
        for(int i=0;i<cnt;i++)
        {
            if(book[i].id==s1)
            {
                flag=1;
                k=i;
                break;
            }
        }
        if(flag==0)
        {
            cout<<"******û���ҵ�����Ʒ!�����������ҳ...******"<<endl;
            buytime(s);
        }
        else if(flag==1)
        {
            cout<<"*************************************"<<endl;
            cout<<"��Ʒ����: "<<book[k].bookname<<endl;
            cout<<"��Ʒ����: "<<book[k].dis<<endl;
            cout<<"����id:  "<<book[k].sold_id<<endl;
            cout<<"�ϼ�ʱ��: "<<book[k].tim<<endl;
            cout<<"��Ʒ�۸�: "<<book[k].price<<endl;
            if(book[k].flag==1)
            {
                cout<<"��Ʒ״̬: "<<"������"<<endl;
            }
            else if(book[k].flag==0)
            {
                cout<<"��Ʒ״̬: "<<"���¼�"<<endl;
            }
            else if(book[k].flag==2)
            {
                cout<<"��Ʒ״̬: "<<"���۳�"<<endl;
            }
            cout<<"*************************************"<<endl;
            buytime(s);
        }
    }
    else if(operator_num=="3")
    {
        cout<<"������Ҫ��������Ʒ����: ";
        cin>>s1;
        string filename = R"(C:\Users\86188\Desktop\prc2023\demo01)";
        ifstream fin;
        fin.open("databook.txt");
        int cnt = 0;
        while(fin>>book[cnt].id>>book[cnt].bookname>>book[cnt].price>>book[cnt].tim>>book[cnt].flag>>book[cnt].dis>>book[cnt].sold_id>>book[cnt].buy_id>>book[cnt].dealtim)
        {
            cnt++;
        }
        fin.close();
        int flag=0,vis[10005];
        int k=0;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<cnt;i++)
        {
            stringstream ss;
            ss<<book[i].bookname;
            if(ss.str().find(s1)!=string::npos&&book[i].flag==1)
            {
                flag++;
                vis[k]=i;
                k++;
            }
        }
        if(flag==0)
        {
            cout<<"******!!!û���ҵ��κ���Ʒ......******"<<endl;
            buytime(s);
        }
        else if(flag>0)
        {
            cout<<"Ϊ���ҵ���"<<flag<<"�����......"<<endl;
            cout<<"*******************************************************************"<<endl;
            cout<<left<<setw(25)<<"��Ʒid"<<setw(30)<<"��Ʒ����"<<setw(25)<<"��Ʒ�۸�"<<endl;
            for(int i=0;i<k;i++)
            {
                cout<<left<<setw(25)<<book[vis[i]].id<<setw(30)<<book[vis[i]].bookname<<setw(25)<<book[vis[i]].price<<endl;
            }
            cout<<"*******************************************************************"<<endl;
            buytime(s);
        }
    }
    else if(operator_num=="6")
    {
        users(s);
    }
    else
    {
        cout<<"!!!��������ȷ������!!!"<<endl;
        buytime(s);
    }
}

float deal(string s,float m,string sd)//�ж��Ƿ����������
{
    string filename=R"(C:\Users\86188\Desktop\prc2023\demo01\loginuser.txt)";
    ifstream fin;
    fin.open("loginuser.txt");
    int cnr=0;
    while(fin>>userdata[cnr].id>>userdata[cnr].username>>userdata[cnr].pwd>>userdata[cnr].number>>userdata[cnr].address>>userdata[cnr].wallet)
    {
        cnr++;
    }
    fin.close();
    float a=0.0;
    int k=0,q=0;
    for(int i=0;i<cnr;i++)
    {
        if(userdata[i].id==s)
        {
            a=userdata[i].wallet;
            k=i;
            break;
        }
    }
    for(int i=0;i<cnr;i++)
    {
        if(userdata[i].id==sd)
        {
            q=i;
            break;
        }
    }
    if(a-m<0)
    {
        return -1.0;
    }
    else
    {
        userdata[k].wallet=a-m;
        userdata[q].wallet+=m;
        ofstream fout;
        fout.open("loginuser.txt");
        for(int i=0;i<cnr;i++)
        {
                fout<<userdata[i].id<<" "<<userdata[i].username<<" "<<userdata[i].pwd<<" "<<userdata[i].number<<" "<<userdata[i].address<<" "<<userdata[i].wallet<<endl;
        }
        fout.close();
        return a-m;
    }
}

void del_deal(string s)//����ɾ���˺ŵ��û������䷢��û�����Ķ���ȫ���¼�,ֻ�ж�����ʾ�˺���ɾ��
{
    string filename = R"(C:\Users\86188\Desktop\prc2023\demo01)";
    ifstream fin;
    fin.open("databook.txt");
    int cnt = 0;
    while(fin>>book[cnt].id>>book[cnt].bookname>>book[cnt].price>>book[cnt].tim>>book[cnt].flag>>book[cnt].dis>>book[cnt].sold_id>>book[cnt].buy_id>>book[cnt].dealtim)
    {
        cnt++;
    }
    fin.close();
    for(int i=0;i<cnt;i++)
    {
        if(book[i].sold_id==s)
        {
            book[i].sold_id="�˺���ɾ��";
            if(book[i].flag==1)
            {
                book[i].flag=0;
            }
        }
    }
    for(int i=0;i<cnt;i++)
    {
        if(book[i].buy_id==s)
        {
            book[i].buy_id="�˺���ɾ��";
        }
    }
    ofstream fout;
    fout.open("databook.txt");
    for (int i = 0; i < cnt; i++)
    {
        fout<<book[i].id<< " "<<book[i].bookname<<" "<<book[i].price<<" "<<book[i].tim<<" "<<book[i].flag<<" "<<book[i].dis<<" "<<book[i].sold_id<<" "<<book[i].buy_id<<" "<<book[i].dealtim<<endl;
    }
    fout.close();
}
