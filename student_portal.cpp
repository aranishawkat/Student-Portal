#include <bits/stdc++.h>
using namespace std;

struct info
{
    string name,id,phone,address,parent_name,cgpa;
    struct info *next;
}*head;

struct node
{
    string name;
    string cg;
} calc[10000001];

bool cmp(node p,node q)
{
    return p.cg>q.cg;
}

typedef struct info item;

void inserts3(){
    item *temp1,*temp2,*temp3;
    temp1 = new item;
    temp1->next=NULL;
    temp2 = new item;
    temp2->next=NULL;
    temp3 = new item;
    temp3->next=NULL;

    temp1->name="Imranul Ashrafi";
    temp1->id="1611656042";
    temp1->parent_name="MD. Mokbul Hossain";
    temp1->address="Uttara, Dhaka";
    temp1->phone="N/A";
    temp1->cgpa="N/A";

    temp2->name="Arani Shawkat";
    temp2->id="1610150642";
    temp2->parent_name="Shawkat Osman Rochi";
    temp2->address="Mirpur, Dhaka";
    temp2->phone="N/A";
    temp2->cgpa="N/A";

    temp3->name="Shohaib Islam";
    temp3->id="1611237042";
    temp3->parent_name="Tohidul Islam";
    temp3->address="Bashundhara R/A, Dhaka";
    temp3->phone="N/A";
    temp3->cgpa="N/A";

    head=temp1;
    temp1->next=temp2;
    temp2->next=temp3;
}

void option()
{
    system("cls");
    cout<<"STUDENT PORTAL"<<endl<<endl;
    cout<< "1: Insert data"<<endl;
    cout<< "2: Update data"<<endl;
    cout<< "3: Delete data"<<endl;
    cout<< "4: Search data"<<endl;
    cout<< "5: Show student name according to their cgpa"<<endl;
    cout<< "6: Show every data"<<endl;
    cout<< "7: Quit program"<<endl;
    cout<<endl<< "Choose your option: ";
}

void show_data(item *root)//done
{
    cout<< "Student name: "<<root->name<<endl;
    cout<< "Id          : "<<root->id<<endl;
    cout<< "Parent name : "<<root->parent_name<<endl;
    cout<< "Address     : "<<root->address<<endl;
    cout<< "Phone No    : "<<root->phone<<endl;
    cout<< "CGPA        : "<<root->cgpa<<endl;
}

void show_all()
{
    system("cls");
    item* temp=head;
    if(head==NULL)
    {
        cout<< "No data found!"<<endl;
        cout<<endl<<"Press enter to continue..";
        getchar();
        return;
    }
    int tc=1;
    while(temp!=NULL)
    {
        cout<< "Data "<<tc++<< ":"<<endl<<endl;
        show_data(temp);
        cout << endl;
        temp=temp->next;
    }
    cout<<endl<<"Press enter to continue..";
    getchar();
}

void inserting()
{
    system("cls");
    item *temp;
    temp = new item;
    temp->next=NULL;
    cout<< "Student name: ";
    getline(cin,temp->name);
    cout<< "ID          : ";
    cin>>temp->id;
    cout<< "Father name : ";
    getchar();
    getline(cin,temp->parent_name);
    cout<< "Phone No    : ";
    cin>>temp->phone;
    cout<< "Address     : ";
    getchar();
    getline(cin,temp->address);
    cout<< "CGPA        : ";
    getline(cin,temp->cgpa);
    item *tmp=head;
    while(tmp->next!=NULL){
        tmp=tmp->next;
    }
    tmp->next=temp;

    cout<<endl<<"Press enter to continue..";
    getchar();
}

void deleting()
{
    system("cls");
    int x;
    if(head==NULL){
        cout<<"No data found!"<<endl;
        cout<<endl<<"Press enter to continue..";
        getchar();
        return;
    }
    cout<< "1 : Delete by student name."<<endl;
    cout<< "2 : Delete by student id."<<endl;
    cout<<endl<< "Choose type : ";
    cin>>x;

    item *temp,*pre;
    temp = new item;
    pre = head;
    temp = pre->next;
    if(x==1)
    {
        string nm;
        cout<<endl<< "Input student name according to the database: ";
        getchar();
        getline(cin,nm);
        if(head->name==nm)
        {
            head=head->next;
            cout<<endl<< "Successfully deleted!"<<endl;
            cout<<endl<<"Press enter to continue..";
            getchar();
            return;
        }
        else
        {
            while(temp!=NULL)
            {
            if(temp->name==nm){
                pre->next=temp->next;
                cout<<"Successfully Deleted!"<<endl;
                cout<<endl<<"Press enter to continue..";
                getchar();
                return;
            }
            else{
                pre=pre->next;
                temp=temp->next;
            }

            }
            cout<< "No name matched! Try again!"<<endl;
            cout<<endl<<"Press enter to continue..";
            getchar();
        }
    }
    else
    {

        string nm;
        cout<<endl<< "Input student id according to the database: ";
        getchar();
        getline(cin,nm);
        if(head->id==nm)
        {
            head=head->next;
            cout<< "Successfully deleted!"<<endl;
            cout<<endl<<"Press enter to continue..";
            getchar();
            return;
        }
        else
        {
            while(temp!=NULL)
            {
            if(temp->id==nm){
                pre->next=temp->next;
                cout<<"Successfully Deleted!"<<endl;
                cout<<endl<<"Press enter to continue..";
                getchar();
                return;
            }
            else{
                pre=pre->next;
                temp=temp->next;
            }

            }
            cout << "No ID matched! Try again!"<<endl;
            cout<<endl<<"Press enter to continue..";
            getchar();
        }
    }
}

void updating()
{

    system("cls");
    if(head==NULL){
        cout<<"No data found!"<<endl;
        cout<<endl<<"Press enter to continue..";
        getchar();
        return;
    }
    string x;
    cout<< "Input the id of the student you want to update : ";
    cin>>x;
    item *root = head;
    while(root!=NULL)
    {
        if(root->id!=x)
            root=root->next;
        else break;
    }
    if(root==NULL){
        cout<<"No id matched! Try again!"<<endl;
        cout<<endl<<"Press enter to continue..";
        getchar();
        getchar();
        return;
    }
        cout<<endl;
        show_data(root);
        cout<<endl;
        cout<< "UPDATE here -->"<<endl<<endl;
        getchar();
        cout<< "Student name: ";
        getline(cin,x),root->name=x;
        cout<< "Id          : ";
        getline(cin,x),root->id=x;
        cout<< "Parent name : ";
        getline(cin,x),root->parent_name=x;
        cout<< "Address     : ";
        getline(cin,x),root->address=x;
        cout<< "Phone No    : ";
        getline(cin,x),root->phone=x;
        cout<< "CGPA        : ";
        getline(cin,x),root->cgpa=x;

        cout<<endl<<"Press enter to continue..";
        getchar();
}

void searching()
{
    system("cls");
   if(head==NULL){
        cout<<"No data found!"<<endl;
        cout<<endl<<"Press enter to continue..";
        getchar();
        return;
    }
    string x;
    cout<< "Input the name you want to search: ";
    getline(cin,x);
    item *temp=head;

    while(temp!=NULL)
    {
        if(temp->name!=x)
            temp=temp->next;
        else break;
    }
    if(temp==NULL)
        cout<< "No name matched! Try again!"<<endl;
    else{
        cout << endl;
        show_data(temp);
    }

    cout<<endl<<"Press enter to continue..";
    getchar();
}

void show_cgpa()
{

    system("cls");
    if(head==NULL){
        cout<<"No data found!"<<endl;
        cout<<endl<<"Press enter to continue..";
        getchar();
        return;
    }
    int pos=0;
    item *temp=head;
    while(temp!=NULL)
    {
        calc[pos].name = temp->name;
        calc[pos++].cg = temp->cgpa;
        temp=temp->next;
    }
    sort(calc,calc+pos,cmp);
    for(int i=0; i<pos; i++)
        cout<< "Name : "<<calc[i].name<< " -> CGPA : "<<calc[i].cg<<endl;

    cout<<endl<<"Press enter to continue..";
    getchar();
}

int main()
{
    inserts3();
    int x;
    while(1)
    {
        option();
        cin>>x;
        getchar();
        if(x==7)return 0;
        else if(x==1)inserting();
        else if(x==2)updating();
        else if(x==3)deleting();
        else if(x==4)searching();
        else if(x==6)show_all();
        else if(x==5)show_cgpa();
        else{
            cout<<endl<< "Invalid input! Please enter a valid option!"<<endl;
            cout<<endl<<"Press enter to continue..";
            getchar();
        }
        cout<<endl<<endl;
    }
    return 0;
}
