#pragma once
#include<iostream>
#include"ClsBankUsers.h"
#include"Global.h"
#include"ClsDate.h"
using namespace std;
class ClsScreen
{
public:
	static void _draw_screen_header(string title, string subtitle = "")
	{
		cout << "\t\t\t\t\t______________________________________\n\n";
		cout << "\t\t\t\t\t  " << title;
		if (subtitle != "")
		{
			cout << "\n\t\t\t\t\t  " << subtitle;
		}
		cout << "\n\t\t\t\t\t______________________________________\n\n";

		cout << "\t\t\t\t\t USER :" << current_user.UserName << "\n";
		cout << "\t\t\t\t\t DATE :" << clsDate::GetSystemDateString()<< "\n";
	}





	static bool check_access_rights(clsUser::enPermissions permiossion)
	{
		if (!current_user.check_access_permission(permiossion))
		{
		cout << "\t\t\t\t\t______________________________________\n\n";
		cout << "\t\t\t\t\t  ACCESS DENIED ! CONTRACT YOUR ACCESS \n";
		cout << "\n\t\t\t\t\t______________________________________\n\n";
		system("pause>0");
		return false;
		}
		else
			return true;

	}
};


