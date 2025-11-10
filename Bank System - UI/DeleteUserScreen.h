#pragma once
#include <iostream>
#include "clsScreen.h"
#include"ClsBankUsers.h"
#include <iomanip>

class ClsDeleteUserScreen :protected ClsScreen
{

	static void print_user_record(clsUser user)
	{
		cout << setw(8) << left << "" << "| " << setw(15) << left << user.UserName;
		cout << "| " << setw(20) << left << user.FirstName + " " + user.LastName;
		cout << "| " << setw(12) << left << user.Phone;
		cout << "| " << setw(20) << left << user.Email;
		cout << "| " << setw(10) << left << user.Password;
		cout << "| " << setw(10) << left << user.Permissions;
	}

	static	void delete_user()
	{
		if (!check_access_rights(clsUser::enPermissions::pDeleteClient))
		{
			return;
		}
		cout << "enter the user name ";
		string account_number;
		cin >> account_number;
		while (!clsUser::IsUserExist(account_number))
		{
			cout << "the account number was not found ,  choose another one : ";
			cin >> account_number;
		}
		clsUser c = clsUser::Find(account_number);
		print_user_record(c);
		char ask;
		cout << "\n\n\ndo you want delete this account [Y / y]\n";
		cin >> ask;
		if (tolower(ask) == 'y')
		{
			c.Delete();
			cout << "\nUser Deleted Successfully :-)\n";
		}
	}


public:
	static void Delete_client_screen()
	{
		_draw_screen_header("\tDELETE SCREEN");
		delete_user();
	}




};
