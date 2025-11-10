#pragma once
#include <iostream>
#include"ClsPerson.h"
#include "ClsScreen.h"
#include "ClsBankClient.h"
class CLsTransferScreen:public ClsScreen
{
static	void _transfer()
	{
		string account_number1, account_number2 ;
		cout << "\nPlease Enter Account Number to transfer from : ";
		cin >> account_number1;
		while (!ClsBankClient::IsClientExist(account_number1))
		{
			cout << "\nAccount number is not found, choose another one : ";
			cin >> account_number1;
		}
		ClsBankClient c1 = ClsBankClient::Find(account_number1);
		cout << "CLient Card:\n";
		cout << "___________________\n";
		cout << "FUll Name   : "<<c1.FirstName + " " + c1.LastName + "\n";
		cout << "Acc. Number  : "<<c1.AccountNumber() + "\n";
		cout << "Balance   : "<<c1.AccountBalance;
		cout << "\n___________________\n";
		cout << "\nPlease Enter Account Number to transfer to : ";
		cin >> account_number2;
		while (!ClsBankClient::IsClientExist(account_number2))
		{
			cout << "\nAccount number is not found, choose another one : ";
			cin >> account_number2;
		}
		ClsBankClient c2 = ClsBankClient::Find(account_number2);
		cout << "CLient Card:\n";
		cout << "___________________\n";
		cout << "FUll Name   : "<<c2.FirstName + " " + c2.LastName + "\n";
		cout << "Acc. Number  : "<<c2.AccountNumber() + "\n";
		cout << "Balance   : "<<c2.AccountBalance;
		cout << "\n___________________\n";
		float amount;
		cout<<"Enter The Amount\n";
		cin >> amount;
		while (amount > c1.AccountBalance)
		{
			cout << "Amount Exceeds the available balance enter another amuont\n";
			cin >> amount;
        }
		cout << "are you sure to perform this operation? y/n\n";
		char ask;
		cin >> ask;
		if (tolower(ask) == 'y')
		{
			vector<ClsBankClient>clients = ClsBankClient::getClientList();;
			for (ClsBankClient& C : clients)
			{
				if (C.AccountNumber() == account_number1)
				{
					C.AccountBalance -= amount;;
					break;
				}
			}
			for (ClsBankClient& C : clients)
			{
				if (C.AccountNumber() == account_number2)
				{
					C.AccountBalance += amount;;
					break;
				}
			}
			ClsBankClient::_save_client_updates(clients);
		}
		else
		{
			cout << "the operation was cancled\n";
		}

	}
public:
	static void transfer_screen()
	{
	 _draw_screen_header("TRANSFER SCREEN");
	 _transfer();

	}

};

