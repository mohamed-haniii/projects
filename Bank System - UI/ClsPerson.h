#pragma once
#include<iostream>
#include <string>
using namespace std;

class ClsPerson
{
	string _first_name;
	string _last_name;
	string _email;
	string _phone;
public:
	ClsPerson(string first, string last, string email, string phone)
	{
		_first_name = first;
		_last_name = last;
		_email = email;
		_phone = phone;
	}
	void set_first_name(string first)
	{
		_first_name = first;
	}
	void set_last_name(string last)
	{
		_last_name = last;
	}
	void set_email(string email)
	{
		_email = email;
	}
	void set_phone(string phone)
	{
		_phone = phone;
	}

	string get_first_name()
	{
		return _first_name;
	}
	string get_last_name()
	{
		return _last_name;
	}

	string get_email()
	{
		return _email;
	}
	string get_phone()
	{
		return _phone;
	}
	__declspec(property(get = get_first_name, put = set_first_name)) string FirstName;
	__declspec(property(get = get_last_name, put = set_last_name)) string LastName;
	__declspec(property(get = get_email, put = set_email)) string Email;
	__declspec(property(get = get_phone, put = set_phone)) string Phone;
};

