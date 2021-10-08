//
//  main.cpp
//  CS project - New
//
//  Created by Rudra Tiwari.
//  Copyright © 2019 Rudra Tiwari. All rights reserved.
//

#include <iostream>
#include <string>

//Use this header only in Windows device
//#include <windows.h>

#include "login.hpp"

string heading={"\t\t<<<-----Student Database Management System  v_1_.3 ----->>>\n\n\n"};
string help1={"\n\t\t\t <1> Admin Login \n\t\t\t <2> Teacher Login\n\t\t\n\t\t\t <3>Teacher Signup \n\t\t\t <4> Exit \n\t\t\t Choice :"};
/*char Enc_head[26]={"\t\t\t\\ENCRYPTION MODE\\"};
char Dec_head[26]={"\t\t\t\\DECRYPTION MODE\\"};
*/



void typeout(string input, char time_type, int time_in_ms)
/*
time_type:
	i : individual
	t : total
*/
{
	int delay = 0;
	switch( time_type )
	{
		case 'i':
			delay = time_in_ms;	// if type is 'i', each letter will take that much time to print
			break;
		case 't':
			delay = time_in_ms / input.length();	// if type is 't', whole word is printed in that much time
			break;
	}

	//Sleep( delay );
	for(int i=0; i<input.length(); i++)
	{
		cout << input[i];
		//Sleep( delay );
	}

	return;
}

void show_heading(int animation) {
	system("cls");
			typeout(heading, 't', 1000);
			typeout(help1,'t',600);
			//typeout(version, 't', 300);
			//Sleep(500);
}



int main() {

    int c = 0;

    do {
        //cout<<"\n\t\t<-----Student Database Managment System  v_1_.3 ----->\n"
        //  <<"\n\t\t\t <1> Admin Login \n\t\t\t <2> Teacher Login\n\t\t "
        //  <<"\n\t\t\t <3>Teacher Signup \n\t\t\t <4> Exit \n\t\t\t Choice : ";
        system("cls");
        show_heading(1);
        cin>>c;
        if (c == 1)
            adminLogin();
        else if (c == 2)
            login();
        else if (c == 3)
            signUp();
        else if (c == 4)
            break;
        else
            cout<<"\n\t\t\t\t Wrong Option Choose Again!!";
    }
    while (c != 4);

    return 0;
}
