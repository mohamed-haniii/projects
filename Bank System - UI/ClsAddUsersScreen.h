#pragma once
#include <iostream>
#include "clsScreen.h"
#include "ClsBankUsers.h"
#include <iomanip>

class ClsAddNewUSer :protected ClsScreen
{
static	int _read_permission()
	{
		int permission = 0;
		char Answer;
		cout << "\nDo you want to give full access? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			return -1;
		}
		cout << "\nshow clinet list y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			permission += clsUser::enPermissions::pListClients;
		}
		cout << "\nadd new client y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			permission += clsUser::enPermissions::pAddNewClient;
		}
		cout << "\ndelete client y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			permission += clsUser::enPermissions::pDeleteClient;
		}
		cout << "\nupdate client y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			permission += clsUser::enPermissions::pUpdateClients;
		}
		cout << "\nfind client y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			permission += clsUser::enPermissions::pFindClient;
		}
		cout << "\ntransaction y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			permission += clsUser::enPermissions::pTranactions;
		}
		cout << "\nmanage users y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			permission += clsUser::enPermissions::pManageUsers;
		}

		return permission;
	}
	static	void _read_client_info(clsUser& client)
	{
		string first, last, phone, email, password;
		double balance;
		cout << "Enter FirstName : ";
		cin >> first;
		client.set_first_name(first);
		cout << "Enter LastName : ";
		cin >> last;
		cout << "Enter Email : ";
		client.set_last_name(last);
		cin >> email;
		client.set_email(email);
		cout << "Enter Phone : ";
		cin >> phone;
		client.set_phone(phone);
		cout << "Enter PIN CODE : ";
		cin >> password;
		client.SetPassword(password);
		cout << "Enter permission: ";
	
		client.Permissions = _read_permission();
	}

public:

	static void _PrintUser(clsUser User)
	{
		cout << "\nUser Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << User.FirstName;
		cout << "\nLastName    : " << User.LastName;
		cout << "\nFull Name   : " << User.FirstName+" "+User.LastName;
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUser Name   : " << User.UserName;
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermissions : " << User.Permissions;
		cout << "\n___________________\n";

	}


	static	void AddNewUser()
	{
		cout << "enter the user name ";
		string account_number;
		cin >> account_number;
		while (clsUser::IsUserExist(account_number))
		{
			cout << "the account number is already used ,  choose another one : ";
			cin >> account_number;
		}
		clsUser new_client = clsUser::GetAddNewUserObject(account_number);
		_read_client_info(new_client);

		clsUser::enSaveResults saver;
		saver = new_client.Save();
		switch (saver)
		{
		case clsUser::enSaveResults::svSucceeded:
			cout << "user added succesfully";
			_PrintUser(new_client);
			break;

		case clsUser::enSaveResults::svFaildEmptyObject:
			cout << "faild becouse it is empty\n";
			break;

		case clsUser::enSaveResults::svFaildUserExists:
		{
			cout << "\nError account was not saved because user name is used!\n";
			break;

		}
		}

	}

	static void add_user_screen()
	{
		_draw_screen_header("ADD USER SCREEN");
		AddNewUser();
	}
};