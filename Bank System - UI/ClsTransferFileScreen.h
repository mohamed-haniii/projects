#pragma once
#include <iostream>
#include <fstream>
#include "clsScreen.h"
#include "ClsBankClient.h"
#include "Global.h"
class ClsTransferFileScreen :public ClsScreen
{

    static void _print_client(ClsBankClient c)
    {
        cout << "\nClient Card:";
        cout << "\n___________________\n";
        cout << "\nFull Name   : " << c.FirstName + " " + c.LastName;
        cout << "\nAcc. Number : " << c.AccountNumber();
        cout << "\nBalance     : " << c.AccountBalance;
        cout << "\n___________________\n";
    }
    static string _ReadAccountNumber()
    {
        string AccountNumber;
        cout << "\nPlease Enter Account Number to Transfer : ";
        cin >> AccountNumber;
        while (!ClsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            cin >> AccountNumber;
        }
        return AccountNumber;
    }

    static float read_amount(ClsBankClient c1)
    {
        cout << "enter the amount \n";
        float amount;
        cin >> amount;
        if (c1.AccountBalance < amount)
        {
            cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
            cin >> amount;
        }
        return amount;
    }
public:
    static void show_transfer_screen()
    {
        _draw_screen_header("TRANSFER SCREEN");
        ClsBankClient sender = ClsBankClient::Find(_ReadAccountNumber());
        _print_client(sender);
        ClsBankClient reciver = ClsBankClient::Find(_ReadAccountNumber());
        _print_client(reciver);
        float Amount = read_amount(sender);


        cout << "\nAre you sure you want to perform this operation? y/n? ";
        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            if (sender.transfer(Amount, reciver, current_user.UserName))
            {
                cout << "\nTransfer done successfully\n";
            }
            else
            {
                cout << "\nTransfer Faild \n";
            }
        }

        _print_client(sender);
        _print_client(reciver);


    }


};

