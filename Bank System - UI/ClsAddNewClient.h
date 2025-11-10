#pragma once
#include <iostream>
#include "clsScreen.h"
#include "ClsBankClient.h"
#include <iomanip>

class ClsAddNewClients :protected ClsScreen
{
	static	void _read_client_info(ClsBankClient& client)
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
		client.SetPinCode(password);
		cout << "Enter Balance: ";
		cin >> balance;
		client.SetAccountBalance(balance);
	}

public:
	static void print_client_record(ClsBankClient Client)
	{
		cout << setw(8) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
		cout << "\n| " << setw(20) << left << Client.FirstName + " " + Client.LastName;
		cout << "\n| " << setw(12) << left << Client.Phone;
		cout << "\n| " << setw(20) << left << Client.Email;
		cout << "\n| " << setw(10) << left << Client.PinCode;
		cout << "\n| " << setw(12) << left << Client.AccountBalance;
	}

	static	void AddNewCLient()
	{
		if (!check_access_rights(clsUser::enPermissions::pAddNewClient))
		{
			return;
		}
		cout << "enter the accont numer ";
		string account_number;
		cin >> account_number;
		while (ClsBankClient::IsClientExist(account_number))
		{
			cout << "the account number is already used ,  choose another one : ";
			cin >> account_number;
		}
		ClsBankClient new_client = ClsBankClient::add_client(account_number);
		_read_client_info(new_client);

		ClsBankClient::enSaveResult saver;
		saver = new_client.save();
		switch (saver)
		{
		case ClsBankClient::enSaveResult::svSuceeded:
			cout << "client added succesfully";
			print_client_record(new_client);
			break;

		case ClsBankClient::enSaveResult::svFildEmptyObject:
			cout << "faild becouse it is empty\n";
			break;

		case ClsBankClient::enSaveResult::svFaildAccountNumberExists:
		{
			cout << "\nError account was not saved because account number is used!\n";
			break;

		}
		}

	}

		static void add_client_screen()
		{
			_draw_screen_header("ADD CLIENT SCREEN");
			AddNewCLient();
		}
};