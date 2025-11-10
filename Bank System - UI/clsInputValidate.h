#pragma once
#include<iostream>
#include <string>
#include"ClsDate.h"
#include"ClsString.h"
using namespace std;

class clsInputValidate
{
public:
static	bool is_number_between(int n, int from, int to)
	{
		for (int i = from; i < to; i++)
		{
			if (n > from && to > n)
			{
				return true;
			}
		}
		return false;
	}
static	bool is_number_between(double n, double from, double to)
	{
		for (int i = from; i < to; i++)
		{
			if (n > from && to > n)
			{
				return true;
			}
		}
		return false;
	}
static int read_int_number(string error_message="invalid number enter numberagain")
{
	int Number;
	cout << "enter the number\n";
	while (!(cin >> Number)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << error_message <<"\n";
	}
	return Number;


}
static double read_double_number(string error_message="invalid number enter numberagain")
{
	double Number;
	cout << "enter the number\n";
	while (!(cin >> Number)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << error_message << "\n";
	}
	return Number;


}
static int read_int_number_between( int from, int to, string error_message = "invalid number enter numberagain")
{
	int n;
	n = read_int_number();
	while (n > to || n < from)
	{
		n = read_int_number();
	}
	return n;
}
static bool is_date_between(clsDate d1, clsDate d2, clsDate d3)
{
	if(clsDate::IsDate1AfterDate2(d1, d2)&&(clsDate::IsDate1BeforeDate2(d1, d3)))
	{
		return true;
	}
	return false;
}
bool is_valid_date(clsDate d)
{
	
	if (clsDate::IsValidDate(d))
	{
		return true;
	}
	return false;
}

};

