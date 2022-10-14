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
    cout << "����������" ;
    cin >> name;
    n_app.name = name;
    cout << "�����Ա�" ;
    cin >> gender;
    n_app.gender = gender;
    cout << "�������䣺" ;
    cin >> age;
    n_app.age = age;
    cout << "����绰���룺" ;
    cin >> telephone;
    n_app.telephone = telephone;
    cout << "�����ַ��" ;
    cin >> address;
    n_app.address = address;

    return n_app;
}

void Print_All(vector<CONTACT> &members){
    vector<CONTACT>::iterator v = members.begin();
    cout << "*����������������������������������������������������������������������������*" << endl;
    while (v != members.end())
    {
        cout << "������" << v->name << "  �Ա�" << v->gender <<endl;
        cout << "���䣺" << v->age << "  �绰���룺" << v->telephone <<endl;
        cout << "��ַ��" << v->address <<endl;
        cout << "*����������������������������������������������������������������������������*" << endl;
        v++;

    }
    cout << "��ӡ��ϣ�" << endl;
    cout << "*����������������������������������������������������������������������������*" << endl;  
}

void Del_Selected(vector<CONTACT> &members){
    string key;
    int select,findnum = 0;
    cout <<  "����Ҫɾ������ϵ�˵�������";
    cin >> key;
    vector<CONTACT>::iterator v = members.begin();
    while (v != members.end())
    {
        if (v->name == key)
        {
            findnum ++;
            cout << "*����������������������������������������������������������������������������*" << endl;
            cout << "�ҵ�Ŀ����ϵ�ˣ�" << endl;
            cout << "������" << v->name << "  �Ա�" << v->gender <<endl;
            cout << "���䣺" << v->age << "  �绰���룺" << v->telephone <<endl;
            cout << "��ַ��" << v->address <<endl;
            cout << "�Ƿ�ɾ����" <<endl;
            cout << "*����������������������������������������������������������������������������*" << endl;
            cout << "1.ɾ��" << endl;
            cout << "2.����" << endl;
            cout << "*����������������������������������������������������������������������������*" << endl;
            cout << "Select:";cin >> select;
            if (select == 1)
            {
                members.erase(v);
                v = members.begin();
            }    
        }
        else{v++;}          
    }
    cout << "������ɣ�";
    if (findnum == 0)
    {
        cout << "δ�ҵ���Ӧ��ϵ��" << endl;
    }
        
}

void Search_Con(vector<CONTACT> &members){
    string key;
    int findnum = 0;
    cout <<  "����Ҫ���ҵ���ϵ�˵�������";
    cin >> key;
    vector<CONTACT>::iterator v = members.begin();
    while (v != members.end())
    {
        if (v->name == key)
        {
            findnum ++;
            cout << "*����������������������������������������������������������������������������*" << endl;
            cout << "�ҵ�Ŀ����ϵ�ˣ�" << endl;
            cout << "������" << v->name << "  �Ա�" << v->gender <<endl;
            cout << "���䣺" << v->age << "  �绰���룺" << v->telephone <<endl;
            cout << "��ַ��" << v->address <<endl;
            cout << "*����������������������������������������������������������������������������*" << endl;   
        }       
        v++;
    }
    cout << "������ɣ�";
    if (findnum == 0)
    {
        cout << "δ�ҵ���Ӧ��ϵ��" << endl;
    }
}

void Alter_Con(vector<CONTACT> &members){
    string key;
    int select,findnum = 0;
    cout <<  "����Ҫ�޸ĵ���ϵ�˵�������";
    cin >> key;
    vector<CONTACT>::iterator v = members.begin();
    while (v != members.end())
    {
        if (v->name == key)
        {
            findnum ++;
            cout << "*����������������������������������������������������������������������������*" << endl;
            cout << "�ҵ�Ŀ����ϵ�ˣ�" << endl;
            cout << "������" << v->name << "  �Ա�" << v->gender <<endl;
            cout << "���䣺" << v->age << "  �绰���룺" << v->telephone <<endl;
            cout << "��ַ��" << v->address <<endl;
            cout << "�Ƿ��޸ģ�" <<endl;
            cout << "*����������������������������������������������������������������������������*" << endl;
            cout << "1.�޸�" << endl;
            cout << "2.����" << endl;
            cout << "*����������������������������������������������������������������������������*" << endl;
            cout << "Select:";cin >> select;
            if (select == 1)
            {
                cout << "����������" ;
                cin >> v->name;
                cout << "�����Ա�" ;
                cin >> v->gender;
                cout << "�������䣺" ;
                cin >> v->age;
                cout << "����绰���룺" ;
                cin >> v->telephone;
                cout << "�����ַ��" ;
                cin >> v->address;
            }    
        }
        v++;         
    }
    cout << "������ɣ�";
    if (findnum == 0)
    {
        cout << "δ�ҵ���Ӧ��ϵ��" << endl;
    }
        
}

int main(){
    vector<CONTACT> members;
    int exitcode = 0;
    while (exitcode != 7)
    {
        cout << "*����������������������������������������������������������������������������*" << endl;
        cout << "1.APPEND CONTACT" << endl;
        cout << "2.PRINT ALL CONTACTS" << endl;
        cout << "3.DELETE SELECTED CONTACT" << endl;
        cout << "4.SEARCH CONTACT" << endl;
        cout << "5.ALTER CONTACT" << endl;
        cout << "6.CLEAR ALL CONTACTS" << endl;
        cout << "7.EXIT" << endl;
        cout << "*����������������������������������������������������������������������������*" << endl;
        cout << "Select:";
        cin >> exitcode;
        switch (exitcode)
        {
        case 1:{
            members.push_back(mem_append());
            cout << "�����ϣ�" << endl;break;
        }
        case 2:Print_All(members);break;
        case 3:Del_Selected(members);break;
        case 4:Search_Con(members);break;
        case 5:Alter_Con(members);break;
        case 6:members.clear();
               cout << "������" << endl;break;
        case 7:break;        
        default:break;
        }
        if(exitcode == 7)
            break;
        system("pause"); 
    }    
    return 0;
}