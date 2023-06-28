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

struct books{//flag: 1.出售中 0.已下架 2.已售出
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
    cout<<"1.查看所有商品 2.搜索商品 3.查看所有订单 4.查看所有用户 5.删除用户 6.下架商品 7.注销"<<endl;
    cout<<"===================================================================================="<<endl;
    cout<<"请输入你的操作数:";
    cin>>operator_num;
    if(operator_num=="7")
    {
        cout<<"确定退出登录吗(y/n):";
        cin>>s1;
        if(s1=="y")
        {
            cout<<"***正在返回主界面...***"<<endl;
            welcome();
        }
        else if(s1=="n")
        {
            cout<<"***返回管理员操作页...***"<<endl;
            adminlogin();
        }
        else
        {
            cout<<"******非法字符！已强制返回******"<<endl;
            adminlogin();
        }
    }
    else if(operator_num=="2")
    {
        cout<<"请输入要搜索的商品名称: ";
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
            cout<<"******!!!没有找到任何商品......******"<<endl;
            adminlogin();
        }
        else if(flag>0)
        {
            cout<<"~~为你找到了"<<flag<<"条结果......"<<endl;
            cout<<"****************************************************************************************"<<endl;
            cout<<left<<setw(25)<<"商品id"<<setw(30)<<"商品名称"<<setw(25)<<"商品价格"<<setw(25)<<"商品状态"<<endl;
            for(int i=0;i<k;i++)
            {
                if(book[vis[i]].flag==1)
                {
                    cout<<left<<setw(25)<<book[vis[i]].id<<setw(30)<<book[vis[i]].bookname<<setw(25)<<book[vis[i]].price<<setw(25)<<"出售中"<<endl;
                }
                else if(book[vis[i]].flag==0)
                {
                    cout<<left<<setw(25)<<book[vis[i]].id<<setw(30)<<book[vis[i]].bookname<<setw(25)<<book[vis[i]].price<<setw(25)<<"已下架"<<endl;
                }
                else if(book[vis[i]].flag==2)
                {
                    cout<<left<<setw(25)<<book[vis[i]].id<<setw(30)<<book[vis[i]].bookname<<setw(25)<<book[vis[i]].price<<setw(25)<<"以售出"<<endl;
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
        cout<<left<<setw(20)<<"商品id"<<setw(30)<<"商品名称"<<setw(30)<<"价格"<<setw(30)<<"上架时间"<<setw(20)<<"商品状态"<<endl;
        for(int i=0;i<cnt;i++)
        {
            if(book[i].flag==1)
            {
                cout<<left<<setw(20)<<book[i].id<<setw(30)<<book[i].bookname<<setw(30)<<book[i].price<<setw(30)<<book[i].tim<<setw(20)<<"出售中"<<endl;
            }
            else if(book[i].flag==0)
            {
                cout<<left<<setw(20)<<book[i].id<<setw(30)<<book[i].bookname<<setw(30)<<book[i].price<<setw(30)<<book[i].tim<<setw(20)<<"已下架"<<endl;
            }
            else if(book[i].flag==2)
            {
                cout<<left<<setw(20)<<book[i].id<<setw(30)<<book[i].bookname<<setw(30)<<book[i].price<<setw(30)<<book[i].tim<<setw(20)<<"已售出"<<endl;
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
            cout << "******没有正在售出的商品！即将返回操作页...******" << endl;
            adminlogin();
        }
        else
        {
            cout<< "!!!当前售卖着" << k << "件商品!!!"<<endl;
            cout<< "***************************"<<endl;
            cout<<"请输入你想要下架的商品id:";
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
                cout << "******删除失败！没有有关商品！******" << endl;
                flag=0,m=0;
                adminlogin();
            }
            else if(flag==1)
            {
                cout << "*********请确认商品信息！！！*********" << endl;
                cout << "商品id:" << book[m].id << endl;
                cout << "商品名称:" << book[m].bookname << endl;
                cout << "**********************************" << endl;
                cout << "是否下架?(y/n):";
                cin >> s2;
                if (s2 == "n")
                {
                    cout << "你取消了该操作!" << endl;
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
                    cout << "******操作成功！即将返回操作页...******" << endl;
                    adminlogin();
                }
                else
                {
                    cout<<"******非法字符！已强制返回......******"<<endl;
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
            cout<<"******数据库中无任何交易成功记录！******"<<endl;
            adminlogin();
        }
        else
        {
            cout<<setiosflags(ios::fixed)<<setprecision(1);
            cout<<"***************************************************************************************************************************************************"<<endl;
            cout<<left<<setw(25)<<"商品id"<<setw(25)<<"商品名称"<<setw(25)<<"成交价格"<<setw(25)<<"交易时间"<<setw(25)<<"卖家id"<<setw(25)<<"买家id"<<endl;
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
        cout<<left<<setw(20)<<"用户id"<<setw(20)<<"用户名"<<setw(20)<<"联系方式"<<setw(20)<<"地址"<<setw(20)<<"钱包余额"<<endl;
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
        cout<<"请输入要删除的账户Uid:";
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
            cout<<"将要删除的用户信息:"<<endl;
            cout<<"*********************"<<endl;
            cout<<"用户id:"<<userdata[k].id<<endl;
            cout<<"用户名:"<<userdata[k].username<<endl;
            cout<<"联系方式:"<<userdata[k].number<<endl;
            cout<<"*********************"<<endl;
            cout<<"是否删除?(y/n):";
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
                cout<<"删除成功！即将返回管理员操作页......"<<endl;
                adminlogin();
            }
            else if(s1=="n")
            {
                cout<<"你已经取消操作！"<<endl;
                adminlogin();
            }
            else
            {
                cout<<"******非法字符！已强制返回.....******"<<endl;
            }
        }
        else
        {
            cout<<"******删除失败！数据库中不存在该用户！******"<<endl;
            adminlogin();
        }
    }
    else
    {
        cout<<"!!!请输入正确的数字!!!"<<endl;
        adminlogin();
    }
}

void welcome()
{
    cout<<"============================================="<<endl;
    cout<<"1.用户登录 2.用户注册 3.管理员登录 4.退出程序"<<endl;
    cout<<"============================================="<<endl;
    cout<<"输入操作:";
    cin>>operator_num;
    if(operator_num=="4")
    {
        return ;
    }
    else if(operator_num=="3")
    {
        cout<<"请输入管理员账号:";
        cin>>s1;
        cout<<"请输入密码:";
        cin>>s2;
        if(s1==rootid&&s2==rootpwd)
        {
            cout<<"*****登录成功!欢迎,"<<rootid<<"*****"<<endl;
            adminlogin();
        }
        else
        {
            cout<<"***管理员账号或密码错误，即将返回主菜单...***"<<endl;
            welcome();
        }
    }
    else if(operator_num=="1")
    {
        cout<<"请输入用户名:";
        cin>>s1;
        cout<<"请输入密码:";
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
            cout << "******登录成功,欢迎" << s1 << "******" << endl;
            users(tmp);
        }
        else
        {
            cout<<"你的账号或密码错误，请返回主界面重新登录或注册......"<<endl;
            welcome();
        }
    }
    else if(operator_num=="2")
    {
        cout<<"*****欢迎注册*****"<<endl;
        cout<<"请输入用户名:";
        cin>>s1;
        cout<<"请输入密码:";
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
        for(int i=0;i<cnt;i++)//检查用户名是否重复
        {
            if(s1==userdata[i].username)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            cout<<"该用户名已存在！返回主界面..."<<endl;
            welcome();
        }
        else
        {
            cout<<"**********请按操作完善你的信息**********"<<endl;
            cout<<"输入你的联系方式:";
            string pho,adds;
            float a=0.00;
            cin>>pho;
            cout<<"请输入你的地址:";
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
            cout<<"**********注册成功!**********"<<endl;
            users(str);
        }
    }
    else
    {
        cout<<"请不要输入非法字符！"<<endl;
        welcome();
    }
}

void users(string s)
{
    cout<<"======================================="<<endl;
    cout<<"1.退出登录 2.我要买 3.我要卖 4.我的信息"<<endl;
    cout<<"======================================="<<endl;
    cout<<"输入操作:";
    cin>>operator_num;
    if(operator_num=="1")
    {
        cout<<"确定退出吗?(y/n):";
        string opt;
        cin>>opt;
        if(opt=="y")
        {
            cout<<"******!!!返回主界面......******"<<endl;
            welcome();
        }
        else if(opt=="n")
        {
            users(s);
        }
        else
        {
            cout<<"******非法字符！已强制返回......******"<<endl;
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
        cout<<"~~欢迎来到xianyu交易平台,输入数字进入有关功能区!!"<<endl;
        buytime(s);
    }
    else
    {
        cout<<"!!!请输入正确的数字!!!"<<endl;
        users(s);
    }
}

void usersetting(string s)
{
    cout<<"=============================================="<<endl;
    cout<<"1.返回用户主界面 2.修改信息 3.查看信息 4.充值"<<endl;
    cout<<"=============================================="<<endl;
    cout<<"输入操作:";
    cin>>operator_num;
    if(operator_num=="1")
    {
        users(s);
    }
    else if(operator_num=="2")
    {
        string num;
        cout<<"请输入要修改的属性数字标号(1.用户名 2.联系方式 3.地址):";
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
            cout<<"请输入修改后的用户名:";
            cin>>s1;
            userdata[k].username=s1;
        }
        else if(num=="2")
        {
            cout<<"请输入要修改的联系方式:";
            cin>>s1;
            userdata[k].number=s1;
        }
        else if(num=="3")
        {
            cout<<"请输入要修改的地址:";
            cin>>s1;
            userdata[k].address=s1;
        }
        else
        {
            cout<<"!!!请输入正确的数字!!!"<<endl;
            usersetting(s);
        }
        ofstream fout;
        fout.open("loginuser.txt");
        for(int i=0;i<cnr;i++)
        {
            fout<<userdata[i].id<<" "<<userdata[i].username<<" "<<userdata[i].pwd<<" "<<userdata[i].number<<" "<<userdata[i].address<<" "<<userdata[i].wallet<<endl;
        }
        fout.close();
        cout<<"修改成功!即将回到个人信息管理页..."<<endl;
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
        cout<<"用户名:"<<userdata[k].username<<endl;
        cout<<"联系方式:"<<userdata[k].number<<endl;
        cout<<"地址:"<<userdata[k].address<<endl;
        cout<<"当前钱包余额:"<<userdata[k].wallet<<endl;
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
        cout<<"请输入充值金额:";
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
        cout<<"充值成功!当前余额为:"<<b<<endl;
        cout<<"即将返回个人信息管理页......"<<endl;
        usersetting(s);
    }
    else
    {
        cout<<"!!!请输入正确的数字!!!"<<endl;
        usersetting(s);
    }
}

int main()
{
    welcome();
    return 0;
}

string rand_num()//生成随机id
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(10000,99999);
    int num =dis(gen);
    string sk= to_string(num);
    return sk;
}

string time_gets()//获取时间
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
    cout<<"1.发布商品 2.查看发布商品 3.修改商品信息 4.下架商品 5.查看订单历史 6.返回用户主界面"<<endl;
    cout<<"==================================================================================="<<endl;
    cout<<"输入操作:";
    cin>>operator_num;
    if(operator_num=="6")
    {
        users(s);
    }
    else if(operator_num=="1")
    {
        string nme,dep;
        float a=0.00;
        cout<<"请输入商品名称:";
        cin>>nme;
        cout<<"请输入商品金额:";
        cin>>a;
        cout<<"请输入商品描述:";
        cin>>dep;
        cout<<"**********请确认商品信息!**********"<<endl;
        cout<<"商品名称:"<<nme<<endl;
        cout<<"商品价格:"<<a<<endl;
        cout<<"商品描述:"<<dep<<endl;
        cout<<"********************************"<<endl;
        cout<<"确认发布该商品吗?(y/n):";
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
            book[cnt].buy_id="无";
            book[cnt].dealtim="nan";
            book[cnt].sold_id=s;
            ofstream fout;
            fout.open("databook.txt");
            for(int i=0;i<=cnt;i++)
            {
                fout<<book[i].id<<" "<<book[i].bookname<<" "<<book[i].price<<" "<<book[i].tim<<" "<<book[i].flag<<" "<<book[i].dis<<" "<<book[i].sold_id<<" "<<book[i].buy_id<<" "<<book[i].dealtim<<endl;
            }
            fout.close();
            cout<<"*****发布成功!即将返回卖家页...*****"<<endl;
            sold(s);
        }
        else if(s1=="n")
        {
            cout<<"你取消了发布......"<<endl;
            sold(s);
        }
        else
        {
            cout<<"******非法字符！已强制返回......******"<<endl;
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
        cout<<left<<setw(25)<<"商品id"<<setw(25)<<"商品名称"<<setw(25)<<"价格"<<setw(25)<<"上架时间"<<setw(25)<<"商品状态"<<endl;
        for(int i=0;i<cnt;i++)
        {
            if(book[i].flag==1&&book[i].sold_id==s)
            {
                cout<<left<<setw(25)<<book[i].id<<setw(25)<<book[i].bookname<<setw(25)<<book[i].price<<setw(25)<<book[i].tim<<setw(25)<<"出售中"<<endl;
            }
            else if(book[i].flag==0&&book[i].sold_id==s)
            {
                cout<<left<<setw(25)<<book[i].id<<setw(25)<<book[i].bookname<<setw(25)<<book[i].price<<setw(25)<<book[i].tim<<setw(25)<<"已下架"<<endl;
            }
            else if(book[i].flag==2&&book[i].sold_id==s)
            {
                cout<<left<<setw(25)<<book[i].id<<setw(25)<<book[i].bookname<<setw(25)<<book[i].price<<setw(25)<<book[i].tim<<setw(25)<<"已售出"<<endl;
            }
        }
        cout<<"*************************************************************************************************************"<<endl;
        sold(s);
    }
    else if(operator_num=="3")
    {
        cout<<"=============================================="<<endl;
        cout<<"请输入要更改的商品id:";
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
            cout<<"*****没有找到该商品!即将返回卖家操作页...*****"<<endl;
            sold(s);
        }
        else
        {
            cout<<"请输入要更改的商品属性标号(1.价格 2.描述):";
            cin>>s2;
            if(s2=="1")
            {
                cout<<"输入更改后的价格:";
                float a;
                cin>>a;
                book[k].price=a;
                cout<<"*****更改成功!正在返回卖家操作页...*****"<<endl;
            }
            else if(s2=="2")
            {
                cout<<"输入更改后的描述:";
                string st;
                cin>>st;
                book[k].dis=st;
                cout<<"*****更改成功!正在返回卖家操作页...*****"<<endl;
            }
            else
            {
                cout<<"修改失败！请输入合法的字符！"<<endl;
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
        cout<<"请输入你想要下架的商品id:";
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
            cout<<"******没有找到该商品！即将返回卖家操作页...******"<<endl;
            sold(s);
        }
        else if((flag!=0&&book[k].flag==2)||(flag!=0&&book[k].flag==0))
        {
            cout<<"该商品已经被你下架或卖出去啦！"<<endl;
            sold(s);
        }
        else if(flag!=0&&book[k].flag==1)
        {
            cout<<"*********请确认商品信息！！！*********"<<endl;
            cout<<"商品id:"<<book[k].id<<endl;
            cout<<"商品名称:"<<book[k].bookname<<endl;
            cout<<"**********************************"<<endl;
            cout<<"商品下架将不可更改并保存到订单当中,是否删除?(y/n):";
            cin>>s2;
            if(s2=="n")
            {
                cout<<"你取消了该操作!"<<endl;
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
                cout<<"******操作成功！即将返回卖家页...******"<<endl;
                fout.close();
                sold(s);
            }
            else
            {
                cout<<"******非法字符！已强制返回......******"<<endl;
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
            cout<<endl<<"                                                  ~TAT 你还没有卖出去的东西啊......"<<endl;
            sold(s);
        }
        else
        {
            cout<<setiosflags(ios::fixed)<<setprecision(1);
            cout<<"***************************************************************************************************************************************************"<<endl;
            cout<<left<<setw(25)<<"商品id"<<setw(25)<<"商品名称"<<setw(25)<<"成交价格"<<setw(25)<<"交易时间"<<setw(25)<<"买家id"<<endl;
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
        cout<<"!!!请输入正确的数字!!!"<<endl;
        sold(s);
    }
}

void buytime(string s)
{
    cout<<"======================================================================================="<<endl;
    cout<<"1.查看商品列表 2.购买商品 3.搜索商品 4.查看历史订单 5.查看商品详细信息 6.返回用户主界面"<<endl;
    cout<<"======================================================================================="<<endl;
    cout<<"请输入操作数:";
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
            cout<<"~~~~~~~~~~竟然一个商品都没有!等等再来吧......~~~~~~~~~~\n";
            buytime(s);
        }
        else
        {
            cout<<setiosflags(ios::fixed)<<setprecision(1);
            cout<<"*************************************************************************************************************"<<endl;
            cout<<left<<setw(20)<<"商品id"<<setw(30)<<"商品名称"<<setw(30)<<"价格"<<setw(20)<<"上架时间"<<setw(20)<<"卖家id"<<endl;
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
        cout<<"请输入你要买的商品id(你可以再主界面按1查看出售商品):";
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
            cout<<"*******！！！你输入的id有误,即将返回主界面******"<<endl;
            buytime(s);
        }
        else if(flag==1)
        {
            cout<<">>>>>|确定要买下:   "<<book[k].bookname<<"   吗?(y/n)|<<<<<";
            cin>>s2;
            if(s2=="n")
            {
                cout<<"*****你已经取消了订单!*****"<<endl;
                buytime(s);
            }
            else if(s2=="y")
            {
                string sa=book[k].sold_id;
                float x=deal(s,book[k].price,sa);
                if(x<0)
                {
                    cout<<endl;
                    cout<<"          *******!!!购买失败，你的余额不足，请到用户主界面->充值补充余额吧*******";
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
                    cout<<"***************交易提醒!!!**************"<<endl;
                    cout<<"商品id: "<<book[k].id<<endl;
                    cout<<"商品名称: "<<book[k].bookname<<endl;
                    cout<<"成交价格: "<<book[k].price<<endl;
                    cout<<"交易时间: "<<st<<endl;
                    cout<<"剩余余额: "<<x<<endl;
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
            if(book[i].flag==2&&book[i].dealtim!="nan"&&book[i].buy_id!="无")
            {
                k++;
            }
        }
        cout<<setiosflags(ios::fixed)<<setprecision(1);
        if(k==0)
        {
            cout<<"~~~~~~~~~~你一个商品都没买!快去看看好东西......~~~~~~~~~~\n";
            buytime(s);
        }
        else
        {
            cout<<setiosflags(ios::fixed)<<setprecision(1);
            cout<<"*************************************************************************************************************"<<endl;
            cout<<left<<setw(20)<<"商品id"<<setw(30)<<"商品名称"<<setw(30)<<"成交价格"<<setw(20)<<"交易时间"<<setw(20)<<"卖家id"<<endl;
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
        cout<<"请输入查询的商品id:";
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
            cout<<"******没有找到该商品!即将返回买家页...******"<<endl;
            buytime(s);
        }
        else if(flag==1)
        {
            cout<<"*************************************"<<endl;
            cout<<"商品名称: "<<book[k].bookname<<endl;
            cout<<"商品描述: "<<book[k].dis<<endl;
            cout<<"卖家id:  "<<book[k].sold_id<<endl;
            cout<<"上架时间: "<<book[k].tim<<endl;
            cout<<"商品价格: "<<book[k].price<<endl;
            if(book[k].flag==1)
            {
                cout<<"商品状态: "<<"出售中"<<endl;
            }
            else if(book[k].flag==0)
            {
                cout<<"商品状态: "<<"已下架"<<endl;
            }
            else if(book[k].flag==2)
            {
                cout<<"商品状态: "<<"已售出"<<endl;
            }
            cout<<"*************************************"<<endl;
            buytime(s);
        }
    }
    else if(operator_num=="3")
    {
        cout<<"请输入要搜索的商品名称: ";
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
            cout<<"******!!!没有找到任何商品......******"<<endl;
            buytime(s);
        }
        else if(flag>0)
        {
            cout<<"为你找到了"<<flag<<"条结果......"<<endl;
            cout<<"*******************************************************************"<<endl;
            cout<<left<<setw(25)<<"商品id"<<setw(30)<<"商品名称"<<setw(25)<<"商品价格"<<endl;
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
        cout<<"!!!请输入正确的数字!!!"<<endl;
        buytime(s);
    }
}

float deal(string s,float m,string sd)//判断是否可以买下来
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

void del_deal(string s)//对于删除账号的用户，将其发布没卖出的订单全部下架,只有订单显示账号已删除
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
            book[i].sold_id="账号已删除";
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
            book[i].buy_id="账号已删除";
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
