//
//  student.hpp
//  CS project
//
//  Created by Rudra Tiwari.
//  Copyright © 2018 Rudra Tiwari. All rights reserved.
//

#ifndef student_h
#define student_h

#include <fstream>
#include <string>
#include <cstdio>

using namespace std;

class Student {
    int roll;
    string name;

    public :

    int Mark[5][6] = {
        {-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1},
    };

    Student() {
        roll = 0;
        name = "NULL";
    }

    void getDetails() {
        cout<<"\n\t Enter Roll no : ";
        cin>>roll;
        cout<<"\n\t Enter Name : ";
        cin>>name;
    }

    void getMarks(int subCode = 0) {
        int i = 0;
        cout<<"\n\t Entering marks for.... "
        <<"\n\t\t 1 -> FA 1"
        <<"\n\t\t 2 -> FA 2"
        <<"\n\t\t 3 -> FA 3"
        <<"\n\t\t 4 -> FA 4"
        <<"\n\t\t 5 -> SA 1"
        <<"\n\t\t 6 -> SA 1"
        <<"\n\t\t OR All of These......(Press any button)";
        cin>>i;

        switch (i) {
            case 1 : cout<<"\n\t\t\t Enter FA 1 marks = ";
                cin>>Mark[subCode][0];
                break;
            case 2 : cout<<"\n\t\t\t Enter FA 2 marks = ";
                cin>>Mark[subCode][1];
                break;
            case 3 : cout<<"\n\t\t\t Enter FA 3 marks = ";
                cin>>Mark[subCode][2];
                break;
            case 4 : cout<<"\n\t\t\t Enter FA 4 marks = ";
                cin>>Mark[subCode][3];
                break;
            case 5 : cout<<"\n\t\t\t Enter SA 1 marks = ";
                cin>>Mark[subCode][4];
                break;
            case 6 : cout<<"\n\t\t\t Enter SA 2 marks = ";
                cin>>Mark[subCode][5];
                break;
            default : cout<<"\n\t\t\t Enter FA 1 marks = ";
                cin>>Mark[subCode][0];
                cout<<"\n\t\t\t Enter FA 2 marks = ";
                cin>>Mark[subCode][1];
                cout<<"\n\t\t\t Enter FA 3 marks = ";
                cin>>Mark[subCode][2];
                cout<<"\n\t\t\t Enter FA 4 marks = ";
                cin>>Mark[subCode][3];
                cout<<"\n\t\t\t Enter SA 1 marks = ";
                cin>>Mark[subCode][4];
                cout<<"\n\t\t\t Enter SA 2 marks = ";
                cin>>Mark[subCode][5];
                break;

        }
    }

    void display(int subCode = 0, int mode = 1) {
        cout<<"\n\t\t\t\t\t Details Of Record :  "
            <<"\n\t\t Name : "<<name
            <<"\n\t\t Roll no : "<<roll;

        if (mode == 2) {
            cout<<"\n\t\t\t Marks in :  ";
            if (Mark[subCode][0] != -1)
                cout<<"\n\t\t FA 1 : "<<Mark[subCode][0];
            if (Mark[subCode][1] != -1)
                cout<<"\n\t\t FA 2 : "<<Mark[subCode][1];
            if (Mark[subCode][2] != -1)
                cout<<"\n\t\t FA 3 : "<<Mark[subCode][2];
            if (Mark[subCode][3] != -1)
                cout<<"\n\t\t FA 4 : "<<Mark[subCode][3];
            if (Mark[subCode][4] != -1)
                cout<<"\n\t\t SA 1 : "<<Mark[subCode][4];
            if (Mark[subCode][5] != -1)
                cout<<"\n\t\t SA 2 : "<<Mark[subCode][5];
        }
    }

    string retName() {
        return name;
    }

    int retRoll() {
        return roll;
    }
};

void searchRecord(int index, int code = 0, int mode = 1) {
    Student check;

    //string s = "Student_12.DAT";
    //s.append(to_string(cls));
    //s.append(".DAT");
    fstream f;
    f.open("Student_12.DAT", ios::in | ios::binary | ios::out);

    while(!f.eof()) {
        f.read((char*) &check, sizeof(check));
        if(index == check.retRoll()) {
            check.display(code,mode);
            break;
        }
        cout<<"\n\t\t\t\t Record Not found!";
    }

    f.close();
}

void addData(int code = 0) {

   // string s = "Student_";
   // s.append(to_string(cls));
   // s.append(".DAT");

    fstream f;
    f.open("Student_12.DAT", ios::out | ios::binary | ios::app);

    Student S;

    S.getDetails();
    S.getMarks(code);

    f.write((char*) &S, sizeof(S));

    f.close();
}

void addDet() {

    //string s = "Student_";
    //s.append(to_string(cls));
   // s.append(".DAT");

    fstream f;
    f.open("Student_12.DAT", ios::out | ios::binary | ios::app);

    Student S;

    S.getDetails();

    f.write((char*) &S, sizeof(S));

    f.close();
}

void deleteRecord(int index) {

    //string s = "Student_";
    //s.append(to_string(cls));
    //s.append(".DAT");

    fstream f,temp;
    f.open("Student_12.DAT", ios::in | ios::binary | ios::out);
    temp.open("temp.DAT", ios::out | ios::binary);

    Student S;

    while(!f.eof()) {
        f.read((char*) &S, sizeof(S));
        if(S.retRoll() != index)
            temp.read((char*) &S, sizeof(S));
    }
    f.close();
    temp.close();


    //if(remove(s.c_str()) != 0)
    if(remove("Student_12.DAT") != 0)
        cout<<"\n Error Deleting File!";
    rename("temp.DAT", "Student_12.DAT");

}

void updateRecord(int index, int code = 0, int mode = 1) {

    //string s = "Student_";
    //s.append(to_string(cls));
    //s.append(".DAT");

    fstream f;
    f.open("Student_12.DAT", ios::in | ios::out | ios::binary);

    Student check;

    if (mode == 1){
        while(!f.eof()) {
            f.read((char*) &check, sizeof(check));

            if(index == check.retRoll()) {
                    check.getDetails();
                    break;
            }
            cout<<"\n\t\t\t\t Record Not found!";
        }
    }

    else {
        while(!f.eof()) {
            f.read((char*) &check, sizeof(check));

            if(index == check.retRoll()) {

                int m[6];
                m[0] = check.Mark[code][0];
                m[1] = check.Mark[code][1];
                m[2] = check.Mark[code][2];
                m[3] = check.Mark[code][3];
                m[4] = check.Mark[code][4];
                m[5] = check.Mark[code][5];

                cout<<"\n\t\t\t Enter -5 in marks to retain old details ...";
                //check.getMarks(code);
                int i = 0;
                cout<<"\n\t Entering marks for.... "
                <<"\n\t\t 1 -> FA 1"
                <<"\n\t\t 2 -> FA 2"
                <<"\n\t\t 3 -> FA 3"
                <<"\n\t\t 4 -> FA 4"
                <<"\n\t\t 5 -> SA 1"
                <<"\n\t\t 6 -> SA 1"
                <<"\n\t\t OR All of These......(Press any button)";
                cin>>i;

                switch (i) {
                    case 1 : cout<<"\n\t\t\t Enter FA 1 marks = ";
                        cin>>m[0];
                        break;
                    case 2 : cout<<"\n\t\t\t Enter FA 2 marks = ";
                        cin>>m[1];
                        break;
                    case 3 : cout<<"\n\t\t\t Enter FA 3 marks = ";
                        cin>>m[2];
                        break;
                    case 4 : cout<<"\n\t\t\t Enter FA 4 marks = ";
                        cin>>m[3];
                        break;
                    case 5 : cout<<"\n\t\t\t Enter SA 1 marks = ";
                        cin>>m[4];
                        break;
                    case 6 : cout<<"\n\t\t\t Enter SA 2 marks = ";
                        cin>>m[5];
                        break;
                    default : cout<<"\n\t\t\t Enter FA 1 marks = ";
                        cin>>m[0];
                        cout<<"\n\t\t\t Enter FA 2 marks = ";
                        cin>>m[1];
                        cout<<"\n\t\t\t Enter FA 3 marks = ";
                        cin>>m[2];
                        cout<<"\n\t\t\t Enter FA 4 marks = ";
                        cin>>m[3];
                        cout<<"\n\t\t\t Enter SA 1 marks = ";
                        cin>>m[4];
                        cout<<"\n\t\t\t Enter SA 2 marks = ";
                        cin>>m[5];
                        break;
                }
                for(int j = 0;j < 6;j++){
                    if(m[i] != -5)
                        check.Mark[code][i] = m[i];
                }
                break;
            }
            cout<<"\n\t\t\t\t Record Not found!";
        }
    }
    f.close();
}

#endif /* student_h */
