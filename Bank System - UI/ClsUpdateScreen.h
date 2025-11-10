#pragma once
#include <iostream>
#include "clsScreen.h"
#include "ClsBankClient.h"
#include <iomanip>

class ClsUpdateScreen :protected ClsScreen
{
	static	void _Update_user(ClsBankClient user)
	{
		if (!check_access_rights(clsUser::enPermissions::pUpdateClients))
		{
			return;
		}
		string first, last, phone, email, password;
		double balance;
		cout << "Enter FirstName : ";
		cin >> first;
		user.set_first_name(first);
		cout << "Enter LastName : ";
		cin >> last;
		cout << "Enter Email : ";
		user.set_last_name(last);
		cin >> email;
		user.set_email(email);
		cout << "Enter Phone : ";
		cin >> phone;
		user.set_phone(phone);
		cin >> password;
		cout << "Enter PIN CODE : ";
		user.PinCode= password;
		cout << "Enter Balance : ";
		cin >> balance;
		user.SetAccountBalance(balance);

}
public:
static	void update_data_screen()
	{
	_draw_screen_header("\tUPDATE CLIENT SCREEN");
	vector<ClsBankClient>clients;
	clients = ClsBankClient::getClientList();
	cout << "enter the accont numer ";
	string account_number;
	cin >> account_number;
	while (!ClsBankClient::IsClientExist(account_number))
	{
		cout << "the account number was not found ,  choose another one : ";
		cin >> account_number;
	}
	ClsBankClient c = ClsBankClient::Find(account_number);
	c.Print();
	char ask;
	cout << "\n\n\ndo you want update this account [Y / y]\n";
	cin >> ask;
	if (tolower(ask) == 'y')
	{
		_Update_user(c);
		for (ClsBankClient& C : clients)
		{
			if (C.AccountNumber() == account_number)
			{
				C = c;
				break;
			}
		}
		ClsBankClient::_save_client_updates(clients);
	}
	}
};


