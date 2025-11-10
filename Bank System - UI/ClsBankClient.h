#pragma once
#include<iostream>
#include <string>
#include"ClsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include "ClsBankUsers.h"

using namespace std;
class ClsBankClient:public ClsPerson
{
	string _account_number;
	string _pin_code;
	double _account_balance;
	bool _mark_to_delete = false;
	enum enmode  { empty_mode = 0, update_mode = 1 ,add_mode=2};
	enmode  _mode;
	static ClsBankClient _conver_line_to_client_object(string line, string delim = "#//#")
	{
		vector<string>vclient_data;
		vclient_data = ClsString::splite(line, delim);
		return ClsBankClient(enmode::update_mode, vclient_data[0], vclient_data[1], vclient_data[2], vclient_data[3], vclient_data[4], vclient_data[5], stod(vclient_data[6]));
	}
	string _PrepareTransferLogRecord(float Amount, ClsBankClient DestinationClient,string UserName, string Seperator = "#//#")
	{
		string TransferLogRecord = "";
		TransferLogRecord += clsDate::GetSystemDateTimeString() + Seperator;
		TransferLogRecord += AccountNumber() + Seperator;
		TransferLogRecord += DestinationClient.AccountNumber() + Seperator;
		TransferLogRecord += to_string(Amount) + Seperator;
		TransferLogRecord += to_string(AccountBalance) + Seperator;
		TransferLogRecord += to_string(DestinationClient.AccountBalance) + Seperator;
		TransferLogRecord += UserName;
		return TransferLogRecord;
	}

	void _RegisterTransferLog(float Amount, ClsBankClient DestinationClient, string UserName)
	{

		string stDataLine = _PrepareTransferLogRecord(Amount, DestinationClient, UserName);

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}

	static string _convert_client_to_line(ClsBankClient Client, string Seperator = "#//#")
	{
		
		string stClientRecord = "";
		stClientRecord += Client.FirstName + Seperator;
		stClientRecord += Client.LastName + Seperator;
		stClientRecord += Client.Email + Seperator;
		stClientRecord += Client.Phone + Seperator;
		stClientRecord += Client.AccountNumber() + Seperator;
		stClientRecord += Client.PinCode + Seperator;
		stClientRecord += to_string(Client.AccountBalance);

		return stClientRecord;




	}

	static ClsBankClient _get_empty_client()
	{
		return ClsBankClient(enmode::empty_mode, "", "", "", "","", "", 0);
	}
	static vector<ClsBankClient> load_client_data_from_file()
	{
		vector<ClsBankClient>vclient;
		fstream myfile;
		myfile.open("Clients.txt", ios::in);
		if (myfile.is_open())
		{
			string line;
			while (getline(myfile, line))
			{
				ClsBankClient c= _conver_line_to_client_object(line);
				vclient.push_back(c);
			}
			myfile.close();
		}
		return vclient;
	}


	void _update()
	{
		vector<ClsBankClient>clients;
		clients=load_client_data_from_file();
		for (ClsBankClient& c : clients)
		{
			if (c.AccountNumber() == AccountNumber())
			{
				c = *this;
				break;
			}
		}
		_save_client_updates(clients);
	}
	void _add_data_line_to_file(string object)
	{
		fstream myfile;
		myfile.open("clients.txt", ios::out|ios::app);
		if (myfile.is_open())
		{
			myfile << object << "\n";
			myfile.close();
		}
	}
	void _add_new()
	{
		_add_data_line_to_file(_convert_client_to_line(*this));
	}
public:
	static void _save_client_updates(vector<ClsBankClient>& clients)
	{
		fstream myfile;
		string line;
		myfile.open("Clients.txt", ios::out);
		if (myfile.is_open())
		{
			for (ClsBankClient& c : clients)
			{
				if (c._mark_to_delete == false)
				{
					line = _convert_client_to_line(c);
					myfile << line << "\n";
				}
			}
		}
		myfile.close();
	}

	ClsBankClient(enmode mode,string first,string last,string email,string phone,string account_number, string pin_code, double balance) : ClsPerson(first,last,email,phone)
	{
		_mode = mode;
		_account_number = account_number;
		_pin_code = pin_code;
		_account_balance = balance;
	}

	bool is_empty()
	{
		return (_mode == enmode::empty_mode);
	}
	string AccountNumber()
	{
		return _account_number;
	}

	void SetPinCode(string PinCode)
	{
		_pin_code = PinCode;
	}

	string GetPinCode()
	{
		return _pin_code;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(float AccountBalance)
	{
		_account_balance = AccountBalance;
	}

	float GetAccountBalance()
	{
		return _account_balance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance))float AccountBalance;
	void Print()
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << FirstName;
		cout << "\nLastName    : " << LastName;
		cout << "\nFull Name   : " << FirstName+" "+LastName;
		cout << "\nEmail       : " << Email;
		cout << "\nPhone       : " << Phone;
		cout << "\nAcc. Number : " << _account_number;
		cout << "\nPassword    : " << _pin_code;
		cout << "\nBalance     : " << _account_balance;
		cout << "\n___________________\n";
	}
static	void Print(ClsBankClient c)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << c.FirstName;
		cout << "\nLastName    : " << c.LastName;
		cout << "\nFull Name   : " << c.FirstName + " " + c.LastName;
		cout << "\nEmail       : " << c.Email;
		cout << "\nPhone       : " << c.Phone;
		cout << "\nAcc. Number : " << c._account_number;
		cout << "\nPassword    : " << c._pin_code;
		cout << "\nBalance     : " << c._account_balance;
		cout << "\n___________________\n";
	}

static ClsBankClient Find(string AccountNumber)
{
	fstream MyFile;
	MyFile.open("Clients.txt", ios::in);//read Mode

		string Line;
	if (MyFile.is_open())
	{
		while (getline(MyFile, Line))
		{
			ClsBankClient Client = _conver_line_to_client_object(Line);
			if (Client.AccountNumber() == AccountNumber)
			{
				return Client;
				MyFile.close();
			}
		}

		MyFile.close();

	}

	return _get_empty_client();
}
static ClsBankClient Find(string account_number,string pincode)
	{
		vector<ClsBankClient>clients;
		clients = load_client_data_from_file();
		for (ClsBankClient& c : clients)
		{
			if (c.AccountNumber() == account_number && c.PinCode==pincode)
			{
				return c;
			}
		}
		return _get_empty_client();
	}
	static bool IsClientExist(string AccountNumber)
	{

		ClsBankClient Client1 = ClsBankClient::Find(AccountNumber);
		return (!Client1.is_empty());
	}
	enum enSaveResult{svSuceeded=1,svFildEmptyObject=0,svFaildAccountNumberExists=2};
	enSaveResult save()
	{
		switch(_mode)
		{
		case ClsBankClient::empty_mode:
		{
			return enSaveResult::svFildEmptyObject;
		}

		case ClsBankClient::update_mode:
		{
			_update();
			return enSaveResult::svSuceeded;
			break;
		}
		case enmode::add_mode:
		{
			if (IsClientExist(_account_number))
			{
				return enSaveResult::svFaildAccountNumberExists;
			}
			else
			{
				_add_new();
				_mode = update_mode;
				return enSaveResult::svSuceeded;
			}
			break;
		}
		}
	}

	static ClsBankClient add_client(string account_number)
	{
		return ClsBankClient(enmode::add_mode, " ",  " ", " ", " ", account_number, "", 0);
	}
 // void delete_client()
	//{
	//vector<ClsBankClient>clients;
	//clients = load_client_data_from_file();
	//for (ClsBankClient& c : clients)
	//{
	//	if (c.AccountNumber() == _account_number)
	//	{
	//		c._mark_to_delete = true;
	//		break;
	//	}
	//}
	//_save_client_updates(clients);
	//*this = _get_empty_client();
	//}
  static void delete_client(string account_number)
  {
	
	  vector<ClsBankClient>clients;
	  clients = load_client_data_from_file();
	  for (ClsBankClient& c : clients)
	  {
		  if (c.AccountNumber() == account_number)
		  {
			  c._mark_to_delete = true;
			  break;
		  }
	  }
	  _save_client_updates(clients);
  }


 static vector<ClsBankClient>getClientList()
 {
	 return load_client_data_from_file();
 }
 static float get_total_balance()
 {
	 float total_balance=0;
	 vector<ClsBankClient>clients = getClientList();
	 for (ClsBankClient c : clients)
	 {
		 total_balance += c.AccountBalance;
	 }
	 return total_balance;
 }

 bool transfer(float amount, ClsBankClient& reciver, string user_name)
 {

	 if (amount > AccountBalance)                                   
	 {
		 return false;
	 }
	 AccountBalance -= amount;
	 reciver.AccountBalance += amount;
	 _RegisterTransferLog(amount, reciver, user_name);
	 return true;
 }


};

