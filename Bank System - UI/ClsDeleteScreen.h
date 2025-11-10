#pragma once
#include <iostream>
#include "clsScreen.h"
#include "ClsBankClient.h"
#include <iomanip>

class ClsDeleteScreen :protected ClsScreen
{
static	void delete_client()
	{
	if (!check_access_rights(clsUser::enPermissions::pDeleteClient))
	{
		return;
	}
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
	cout << "\n\n\ndo you want delete this account [Y / y]\n";
	cin >> ask;
	if (tolower(ask) == 'y')
	{
		ClsBankClient::delete_client(account_number);
	}
	}


public:
	static void Delete_client_screen()
	{
		_draw_screen_header("\tDELETE SCREEN");
		delete_client();
	}




};
