#pragma once
#include <iostream>
#include "clsScreen.h"
#include "ClsBankClient.h"
#include <iomanip>

class ClsDepositeScreen :protected ClsScreen
{
	static	void deposite()
	{
		int deposite;
		vector <ClsBankClient>clients = ClsBankClient::getClientList();
		cout << "enter the accont numer ";
		string account_number;
		cin >> account_number;
		while (!ClsBankClient::IsClientExist(account_number))
		{
			cout << "the account number was not found ,  choose another one : ";
			cin >> account_number;
		}
		ClsBankClient c = ClsBankClient::Find(account_number);
		for (ClsBankClient& cli : clients)
		{
			if (cli.AccountNumber() == account_number)
			{
				cout << "the account balance is : " << cli.AccountBalance << "\n";
				cout << "do you need enter deposite [Y / y] ?\n";
				char ask;
				cin >> ask;
				if (tolower(ask) == 'y')
				{
					cout << "enter the deposite \n";
					cin >> deposite;
					cli.AccountBalance += deposite;
					cout << "the balance after deposite is : " << cli.AccountBalance << "\n";
					system("pause>0");
					break;
				}
			}
		}
		ClsBankClient::_save_client_updates(clients);
	}


public:
	static void Deposite_screen()
	{
		_draw_screen_header("DEPOSITE SCREEN");
		deposite();
	}



};
