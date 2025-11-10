#pragma once
#include <iostream>
#include "clsScreen.h"
#include "ClsBankClient.h"
#include <iomanip>

class ClsFindClient :protected ClsScreen
{


public:
    static void ShowFindClientScreen()
    {
        if (!check_access_rights(clsUser::enPermissions::pFindClient))
        {
            return;// this will exit the function and it will not continue
        }

        _draw_screen_header("\tFind Client Screen");

        string AccountNumber;
        cout << "\nPlease Enter Account Number: ";
        cin >> AccountNumber;
        while (!ClsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            cin >> AccountNumber;
        }

        ClsBankClient Client1 = ClsBankClient::Find(AccountNumber);

        if (!Client1.is_empty())
        {
            cout << "\nClient Found :-)\n";
        }
        else
        {
            cout << "\nClient Was not Found :-(\n";
        }

        ClsBankClient::Print(Client1);
    }

};

