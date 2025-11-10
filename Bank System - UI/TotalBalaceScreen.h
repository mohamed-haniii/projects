#pragma once
#include <iostream>
#include "clsScreen.h"
#include "ClsBankClient.h"
#include <iomanip>
#include"ClsUtil.h"

class ClsTotalBalanceScreen :protected ClsScreen
{
	static	int total_balance()
	{
		vector <ClsBankClient>clients = ClsBankClient::getClientList();
		return ClsBankClient::get_total_balance();
	}
static	void PrintClientRecordBalanceLine(ClsBankClient Client)
	{

		cout << "| " << setw(15) << left << Client.AccountNumber();
		cout << "| " << setw(20) << left << Client.FirstName + " " + Client.LastName;
		cout << "| " << setw(12) << left << Client.AccountBalance;

	}
static	void show_client_list_Balance()
	{
		vector<ClsBankClient>clients = ClsBankClient::getClientList();
		cout << "\t\t\t\t\tCLIENT LIST (" << clients.size() << ") CLIENT\n";
		cout << "\n________________________________________________________________________________________________________________________\n";

		cout << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Balance";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		if (clients.size() == 0)
		{
			cout << "\t\t\t\tNo Clients Available In the System!";
		}

		else

			for (ClsBankClient Client : clients)
			{

				PrintClientRecordBalanceLine(Client);
				cout << endl;
			}

		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << "\t\t\tTHE TOTAL BALANCE IS (" << ClsBankClient::get_total_balance() << ")";
		int total_balance = ClsBankClient::get_total_balance();
		cout << "\n\t( " << clsUtil::NumberToText(total_balance) << " )\n";
	}


public:
	static void TotalBalanceScreen()
	{
		_draw_screen_header("TOTAL BALANCE SCREEN");
		show_client_list_Balance();
	}



};
