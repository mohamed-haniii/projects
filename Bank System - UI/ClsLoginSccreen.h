#pragma once
#include<iostream>
#include<fstream>
#include"ClsBankUsers.h"
#include"ClsScreen.h"
#include"ClsMainScreen.h"
#include"Global.h"
#include"ClsShowRegisterScreen.h"
class ClsLoginScreen: public ClsScreen
{


	static void _login()
	{
		int trials = 3;

		bool login_faild = false;
		string user_name, password;
		do 
		{
			if (login_faild)
			{
				if (trials == 0)
				{
					cout << "you are locked afer 3 faild trails\n";
				system("pause>0");
					break;
				}
				cout << "\nInvalid password or User Name try again\n";
				system("pause>0");
				system("cls");
				_draw_screen_header("\t   LOGIN SCREEN");
				trials--;
				cout << "\nyou have [" << trials << "] to login\n";

			}

			cout << "Enter User Name\n";
			cin >> user_name;


			cout << "Enter Password\n";
			cin >> password;
			current_user=clsUser::Find(user_name, password);
			login_faild = current_user.IsEmpty();
		} while (login_faild);
		if (trials > 0)
		{
			current_user.save_register_in_file();
			ClsMainScreen::ShowMainMenue();
		}
	}

public:
	static void login_screen(){
		_draw_screen_header("\t   LOGIN SCREEN");
		_login();

	}
};

