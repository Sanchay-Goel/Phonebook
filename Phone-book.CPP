#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
using namespace std;
int add(void);
int delete_rec(char *ch);
int modify_rec(char *ch);
int search_rec(char *ch);
int display(void);
void sortph();
class phone
{
    char name[30];
    char mobile[15];
    char telephone[15];
    char email[40];
public:
    void getdata();
    void putdata();
    void modify();
    char *getname();
}ph;
void phone::getdata()
{
    cout<<"Enter Name :";
    cin.getline(name,30);
    cout<<"Enter Mobile Number :";
    cin.getline(mobile,12);
    cout<<"Enter Telephone Number :";
    cin.getline(telephone,12);
    cout<<"Enter E-Mail ID :";
    cin.getline(email,40);

}
void phone::putdata()
{
    cout<<"Name : "<<name<<endl;
    cout<<"Mobile No. : "<<mobile<<endl;
    cout<<"Telephone No. : "<<telephone<<endl;
    cout<<"Email-id : "<<email<<endl;
}
void phone::modify()
{
    cout<<"Name : "<<name<<endl;
    cout<<"Mobile No. : "<<mobile<<endl;
    cout<<"Telephone No. : "<<telephone<<endl;
    cout<<"Email-id : "<<email<<endl;
    cout<<endl<<"Enter New Details :"<<endl<<endl;
    char eml[40],nme[30],mob[15],tl[15];
    cout<<"New Name :(Enter '!' to retain old one) "<<endl;
    cin.getline(nme,30);
    cout<<"New Mobile No. :(Enter '!' to retain old one) "<<endl;
    cin.getline(mob,12);
    cout<<"New Telephone No. :(Enter '!' to retain old one) "<<endl;
    cin.getline(tl,12);
    cout<<"New Email-ID :(Enter '!' to retain old one) "<<endl;
    cin.getline(eml,40);
    if (strcmp(eml,"!")!=0)
        strcpy(email,eml);
    if (strcmp(nme,"!")!=0)
        strcpy(name,nme);
    if (strcmp(mob,"!")!=0)
        strcpy(mobile,mob);
    if (strcmp(tl,"!")!=0)
        strcpy(telephone,tl);

}
char *phone::getname()
{
    return name;
}

int main()
{
    start:
    system("cls");
  int b,c;
  cout<<endl<<"                         ..........PHONEBOOK...........";
  cout<<endl<<endl<<endl;
  cout<<"    1. ADD CONTACT"<<endl;
  cout<<"    2. SEARCH CONTACT"<<endl;
  cout<<"    3. DELETE CONTACT"<<endl;
  cout<<"    4. MODIFY CONTACT"<<endl;
  cout<<"    5. DISPLAY ALL CONTACT"<<endl;
  cout<<"    6. EXIT"<<endl<<endl;
  cout<<"    Enter Choice :";
  cin>>b;
  cin.ignore();
  switch (b)
  {
  case 1: int a;
            a=add();
            if (a==1)
                goto start;
            else exit(0);
  case 2:   system("cls");
            char ch[30];
            cout<<endl<<endl<<endl;
            cout<<"Enter Name to be searched for :";
            cin.getline(ch,30);
            c=strlen(ch);
            a=search_rec(ch);
            if (a==1)
                goto start;
            else exit(0);
            break;
  case 3:   system("cls");
            cout<<endl<<endl<<endl;
            cout<<"Enter Name to be Deleted :";
            cin.getline(ch,30);
            c=strlen(ch);
            a=delete_rec(ch);
            if (a==1)
                goto start;
            else exit(0);
            break;
  case 4:  system("cls");
            cout<<endl<<endl<<endl;
            cout<<"Enter Name to be Modified :";
            cin.getline(ch,30);
            c=strlen(ch);
            a=modify_rec(ch);
            if (a==1)
                goto start;
            else exit(0);
            break;
            break;
  case 5:  a=display();
            if (a==1)
                goto start;
            else exit(0);
  case 6: system("cls");
            cout<<endl<<endl<<endl;
            cout<<endl<<"                         ##**GOOD BYE **##"<<endl<<endl;
            cout<<endl<<endl<<endl<<endl<<endl<<endl;
            exit(0);

  default: break;

  };



};
int add()
{
    system("cls");
    int a;
    cout<<endl<<endl<<endl;
    fstream fin("Phonebook.txt",ios::in|ios::out|ios::app|ios::binary);
    ph.getdata();
    fin.write((char*)&ph,sizeof(ph));
    fin.close();
    cout<<endl<<endl<<"Press 1 for returning to Main Menu."<<endl;
    cout<<"Press any other key for EXIT.";
    cin>>a;
    return a;

}
int display()
{
    system("cls");
    int a;
    cout<<endl<<endl<<endl;
    fstream fin("Phonebook.txt",ios::in|ios::out|ios::app|ios::binary);
    while(!fin.eof())
    {
        fin.read((char*)&ph,sizeof(ph));
        if(fin.eof())
            break;
        ph.putdata();
        cout<<endl<<endl;
    }
    fin.close();
    cout<<endl<<endl<<"Press 1 for returning to Main Menu."<<endl;
    cout<<"Press any other key for EXIT.";
    cin>>a;
    return a;
}

int search_rec(char *ch)
{
    system("cls");
    int a=0;
    char nme[20];
    cout<<endl<<endl<<endl;
    fstream fin("Phonebook.txt",ios::in|ios::out|ios::app|ios::binary);
    while(!fin.eof())
    {
        fin.read((char*)&ph,sizeof(ph));
        if(fin.eof())
            break;
        strcpy(nme,ph.getname());
        int comp=strcmp(ch,nme);
        if(!comp)
           {
                ph.putdata();
                a+=1;
           }

    }
    if(!a)
        cout<<"NOT FOUND !!";
    fin.close();
    cout<<endl<<endl<<"Press 1 for returning to Main Menu."<<endl;
    cout<<"Press any other key for EXIT.";
    cin>>a;
    return a;
}

int delete_rec(char *ch)
{
    system("cls");
    int a=0;
    char nme[20],confirm='n';
    cout<<endl<<endl<<endl;
    fstream fin("Phonebook.txt",ios::in|ios::out|ios::app|ios::binary);
    fstream del("Phonebook2.txt",ios::in|ios::out|ios::app|ios::binary);
    while(!fin.eof())
    {
        fin.read((char*)&ph,sizeof(ph));
        if(fin.eof())
            break;
        strcpy(nme,ph.getname());
        int comp=strcmp(ch,nme);
        if(!comp)
           {
                ph.putdata();
                a+=1;
                cout<<"Are you sure you want to delete this Contact :";
                cin>>confirm;
                if(confirm=='n')
                    del.write((char*)&ph,sizeof(ph));
                    cout<<endl;
           }
        else
            del.write((char*)&ph,sizeof(ph));

    }
    if(!a)
        cout<<"NOT FOUND !!";
    else cout<<"Contact Deleted !!";
    fin.close();
    del.close();
    remove("Phonebook.txt");
    rename("Phonebook2.txt","Phonebook.txt");
    cout<<endl<<endl<<"Press 1 for returning to Main Menu."<<endl;
    cout<<"Press any other key for EXIT.";
    cin>>a;
    return a;
}

int modify_rec(char *ch)
{
    system("cls");
    int a=0;
    char nme[20];
    long pos;
    cout<<endl<<endl<<endl;
    fstream fin("Phonebook.txt",ios::in|ios::out|ios::app|ios::binary);
    fstream del("Phonebook2.txt",ios::in|ios::out|ios::app|ios::binary);
    while(!fin.eof())
    {
        fin.read((char*)&ph,sizeof(ph));
        if(fin.eof())
            break;
        strcpy(nme,ph.getname());
        int comp=strcmp(ch,nme);
        if(!comp)
           {
                ph.modify();
                cout<<endl<<endl<<"New Information "<<endl;
                ph.putdata();
                del.write((char*)&ph,sizeof(ph));
                a+=1;
                cout<<endl;
           }
        else
            del.write((char*)&ph,sizeof(ph));

    }
    if(!a)
        cout<<"CONTACT NOT FOUND !!";
    fin.close();
    del.close();
    remove("Phonebook.txt");
    rename("Phonebook2.txt","Phonebook.txt");
    cout<<endl<<endl<<"Press 1 for returning to Main Menu."<<endl;
    cout<<"Press any other key for EXIT.";
    cin>>a;
    return a;
}


