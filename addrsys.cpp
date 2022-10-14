#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct addr
{
    string name;
    string gender;
    string age;
    string telephone;
    string address;
}CONTACT;

CONTACT mem_append(){
    CONTACT n_app;
    string name,gender,telephone,address,age;
    cout << "输入姓名：" ;
    cin >> name;
    n_app.name = name;
    cout << "输入性别：" ;
    cin >> gender;
    n_app.gender = gender;
    cout << "输入年龄：" ;
    cin >> age;
    n_app.age = age;
    cout << "输入电话号码：" ;
    cin >> telephone;
    n_app.telephone = telephone;
    cout << "输入地址：" ;
    cin >> address;
    n_app.address = address;

    return n_app;
}

void Print_All(vector<CONTACT> &members){
    vector<CONTACT>::iterator v = members.begin();
    cout << "*——————————————————————————————————————*" << endl;
    while (v != members.end())
    {
        cout << "姓名：" << v->name << "  性别：" << v->gender <<endl;
        cout << "年龄：" << v->age << "  电话号码：" << v->telephone <<endl;
        cout << "地址：" << v->address <<endl;
        cout << "*——————————————————————————————————————*" << endl;
        v++;

    }
    cout << "打印完毕！" << endl;
    cout << "*——————————————————————————————————————*" << endl;  
}

void Del_Selected(vector<CONTACT> &members){
    string key;
    int select,findnum = 0;
    cout <<  "输入要删除的联系人的姓名：";
    cin >> key;
    vector<CONTACT>::iterator v = members.begin();
    while (v != members.end())
    {
        if (v->name == key)
        {
            findnum ++;
            cout << "*——————————————————————————————————————*" << endl;
            cout << "找到目标联系人：" << endl;
            cout << "姓名：" << v->name << "  性别：" << v->gender <<endl;
            cout << "年龄：" << v->age << "  电话号码：" << v->telephone <<endl;
            cout << "地址：" << v->address <<endl;
            cout << "是否删除？" <<endl;
            cout << "*——————————————————————————————————————*" << endl;
            cout << "1.删除" << endl;
            cout << "2.保留" << endl;
            cout << "*——————————————————————————————————————*" << endl;
            cout << "Select:";cin >> select;
            if (select == 1)
            {
                members.erase(v);
                v = members.begin();
            }    
        }
        else{v++;}          
    }
    cout << "检索完成，";
    if (findnum == 0)
    {
        cout << "未找到相应联系人" << endl;
    }
        
}

void Search_Con(vector<CONTACT> &members){
    string key;
    int findnum = 0;
    cout <<  "输入要查找的联系人的姓名：";
    cin >> key;
    vector<CONTACT>::iterator v = members.begin();
    while (v != members.end())
    {
        if (v->name == key)
        {
            findnum ++;
            cout << "*——————————————————————————————————————*" << endl;
            cout << "找到目标联系人：" << endl;
            cout << "姓名：" << v->name << "  性别：" << v->gender <<endl;
            cout << "年龄：" << v->age << "  电话号码：" << v->telephone <<endl;
            cout << "地址：" << v->address <<endl;
            cout << "*——————————————————————————————————————*" << endl;   
        }       
        v++;
    }
    cout << "检索完成，";
    if (findnum == 0)
    {
        cout << "未找到相应联系人" << endl;
    }
}

void Alter_Con(vector<CONTACT> &members){
    string key;
    int select,findnum = 0;
    cout <<  "输入要修改的联系人的姓名：";
    cin >> key;
    vector<CONTACT>::iterator v = members.begin();
    while (v != members.end())
    {
        if (v->name == key)
        {
            findnum ++;
            cout << "*——————————————————————————————————————*" << endl;
            cout << "找到目标联系人：" << endl;
            cout << "姓名：" << v->name << "  性别：" << v->gender <<endl;
            cout << "年龄：" << v->age << "  电话号码：" << v->telephone <<endl;
            cout << "地址：" << v->address <<endl;
            cout << "是否修改？" <<endl;
            cout << "*——————————————————————————————————————*" << endl;
            cout << "1.修改" << endl;
            cout << "2.保留" << endl;
            cout << "*——————————————————————————————————————*" << endl;
            cout << "Select:";cin >> select;
            if (select == 1)
            {
                cout << "输入姓名：" ;
                cin >> v->name;
                cout << "输入性别：" ;
                cin >> v->gender;
                cout << "输入年龄：" ;
                cin >> v->age;
                cout << "输入电话号码：" ;
                cin >> v->telephone;
                cout << "输入地址：" ;
                cin >> v->address;
            }    
        }
        v++;         
    }
    cout << "检索完成，";
    if (findnum == 0)
    {
        cout << "未找到相应联系人" << endl;
    }
        
}

int main(){
    vector<CONTACT> members;
    int exitcode = 0;
    while (exitcode != 7)
    {
        cout << "*——————————————————————————————————————*" << endl;
        cout << "1.APPEND CONTACT" << endl;
        cout << "2.PRINT ALL CONTACTS" << endl;
        cout << "3.DELETE SELECTED CONTACT" << endl;
        cout << "4.SEARCH CONTACT" << endl;
        cout << "5.ALTER CONTACT" << endl;
        cout << "6.CLEAR ALL CONTACTS" << endl;
        cout << "7.EXIT" << endl;
        cout << "*——————————————————————————————————————*" << endl;
        cout << "Select:";
        cin >> exitcode;
        switch (exitcode)
        {
        case 1:{
            members.push_back(mem_append());
            cout << "添加完毕！" << endl;break;
        }
        case 2:Print_All(members);break;
        case 3:Del_Selected(members);break;
        case 4:Search_Con(members);break;
        case 5:Alter_Con(members);break;
        case 6:members.clear();
               cout << "清空完毕" << endl;break;
        case 7:break;        
        default:break;
        }
        if(exitcode == 7)
            break;
        system("pause"); 
    }    
    return 0;
}