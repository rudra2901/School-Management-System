//
//  login.hpp
//  CS project
//
//  Created by Rudra Tiwari.
//  Copyright © 2018 Rudra Tiwari. All rights reserved.
//

#ifndef login_h
#define login_h

#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <conio.h>

#include "student.hpp"

using namespace std;

const string ADMIN_PASS = "commonPassword";

string getpass() {
  const char BACKSPACE=8;
  const char RETURN=13;

  string password;

  unsigned char ch=0;

  while((ch=getch())!=RETURN)
    {
       if(ch==BACKSPACE)
         {
            if(password.length()!=0)
              {
                 cout <<"\b \b";
                 password.resize(password.length()-1);
              }
         }
       else if(ch==0 || ch==224) // handle escape sequences
         {
             getch(); // ignore non printable chars
             continue;
         }
       else
         {
             password+=ch;
             cout <<'*';
         }
    }
  cout <<endl;
  return password;
}

class account {
    int Id;
    int Class;
    string userName;
    string passWord;
    int subject;

public:
    account() {
        Id = -1;
        Class = 12;
    }

    void getdetails() {
        cout<<"\n Enter Username : ";
        cin>>userName;
        cout<<"\n Enter Password : ";
        //cin>>passWord;
        passWord = getpass();
        cout<<"\n Enter Subject Code : ";
        cin>>subject;
        cout<<"\n Enter Class : ";
        cin>>Class;
    }

    void assignID(int x) {
        Id = x;
    }

    int returnId() {
        return Id;
    }

    int returnClass() {
        return Class;
    }

    int returnSub() {
        return subject;
    }

    string returnPass() {
        return passWord;
    }

    string returnName() {
        return userName;
    }

};

int checkPass (account Current) {
    fstream f;
    f.open("Accounts.DAT", ios::in | ios::binary);

    int flag = 1;
    account A;

    while(!f.eof()) {
        f.read((char*) &A, sizeof(A));

        if(Current.returnName().compare(A.returnName()) == 0) {
            if(Current.returnPass().compare(A.returnPass()) == 0) {
                flag = 1;
                //Current.assignID(A.returnId());
                Current = A;
                //Current.Classes = A.Classes;
                break;
            }
            else
                flag = -1;
        }
    }

    f.close();
    return flag;
}

int createID(int sub) {
    int ID = -1;
    //cout<<ID;
    if(sub == 42)
        ID = 0;
    else if(sub == 43)
        ID = 1;
    else if(sub == 41 || sub == 44)
        ID = 2;
    else if(sub == 83 || sub == 84)
        ID = 3;
    else if(sub == 301)
        ID = 4;
    else
        cout<<"\n Wrong Subject!";

    return ID;
}

/*
 void createFiles(account New) {
 long size = New.Classes.size();
 string s = to_string(New.returnId());
 s.append("_");

 for(int i = 0; i < size; i++) {
 string str = s;
 str.append(to_string(New.Classes[i]));
 str.append(".DAT");

 fstream f;
 f.open(str, ios::out | ios::binary);
 f.close();
 }

 }
 */

int chooseOption(int mode = 2) {

    int choice = 0;
    if( mode == 2) {
        cout<<"\n Choose your Action"
        ///<"\n\t\t///<> Add A New Record"
            <<"\n\t\t 1 -> Delete A Record"
            <<"\n\t\t 2 -> Update A Record"
            <<"\n\t\t 3 -> Search for Record"
            <<"\n\t\t-1 -> Logout \n\n\t\t\t\t : ";
    }
    else {
         cout<<"\n Choose your Action"
            <<"\n\t\t 1 -> Add A New Record"
            <<"\n\t\t 2 -> Delete A Record"
            <<"\n\t\t 3 -> Update A Record"
            <<"\n\t\t 4 -> Search for Record"
            <<"\n\t\t-1 -> Logout \n\n\t\t\t\t : ";
    }
    cin>>choice;

    return choice;
}

void openFile(account Current) {
    //string s = to_string(Current.returnId());
    //s.append("_");

    int b;
        do {
            b = chooseOption(2);

            switch (b) {
                    //case 1 : addData(Current.returnId(),Current.returnClass());
                    //         break;

                case 1 : int ind;
                    cout<<"Enter Roll no to be deleted : ";
                    cin>>ind;
                    deleteRecord(ind);
                    break;

                case 2 : cout<<"Enter Roll no to be updated : ";
                    cin>>ind;
                    updateRecord(ind,Current.returnId(),2);
                    break;

                case 3 : cout<<"Enter Roll no to be searched : ";
                    cin>>ind;
                    searchRecord(ind,Current.returnId(),2);
                    break;

                case -1 : cout<<"\n\t\t Exiting Program!";
                    break;

                default : cout<<"\n\t\t\t Wrong Option !! Choose Again...";

            }
        }
        while(b != -1);
    }

void openAdminFile () {
    int b = 0;
    do {
            b = chooseOption(1);

            switch (b) {
                case 1 : addDet();
                    break;

                case 2 : int ind;
                    cout<<"Enter Roll no to be deleted : ";
                    cin>>ind;
                    deleteRecord(ind);
                    break;

                case 3 : cout<<"Enter Roll no to be updated : ";
                    cin>>ind;
                    updateRecord(ind,1);
                    break;

                case 4 : cout<<"Enter Roll no to be searched : ";
                    cin>>ind;
                    searchRecord(ind,0,1);
                    break;

                case -1 : cout<<"\n\t\t Exiting Program!";
                    break;

                default : cout<<"\n\t\t\t Wrong Option !! Choose Again...";

            }
        }
        while(b != -1);
}

void login() {
    account Input;
    Input.getdetails();

    if(checkPass(Input) == 1)
        openFile(Input);
    else
        cout<<"\n\t\t\t Wrong Password!";

}

void adminLogin(){
    //int i = 12;
    //cout<<"\n Enter Class = ";
    //cin>>i;
    string s;
    int x = 0;
        do{
        cout<<"\n Enter Password : ";
        s = getpass();
        if(s.compare(ADMIN_PASS) == 0) {
            //int inp = 1;
            openAdminFile();
            x = 0;
            /*
            do{
                addDet();
                cout<<"\n Enter 1 to continue!\n\t\t\t\t";
                cin>>inp;
            }
            while(inp == 1);
            */
        }
        else {
            cout<<"\n Wrong Password !";
            x = -1;
        }
    }
    while(x == -1);
}

void signUp() {

    // ToDo : create new user account and files
    fstream f;
    f.open("Accounts.DAT", ios::out | ios::binary | ios::app);

    account New;
    New.getdetails();
    New.assignID(createID(New.returnSub()));

    f.write((char*) &New, sizeof(New));

    cout<<"\n Your ID has been created, Please login again with same credentials...";

    f.close();
}

#endif /* login_h */
