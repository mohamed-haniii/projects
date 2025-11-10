#pragma once
#include <iostream>
#include"ClsPerson.h"
#include "ClsScreen.h"
#include "ClsBankUsers.h"
#include "clsInputValidate.h"
using namespace std;
class clsFindUserScreen :protected ClsPerson
{

private:
    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUserName    : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }

public:

    static void ShowFindUserScreen()
    {

        ClsScreen::_draw_screen_header("FIND USER SCREEN");
        string UserName;
        cout << "\nPlease Enter UserName: ";
        cin >> UserName;
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser is not found, choose another one: ";
            cin >> UserName;
        }

        clsUser User1 = clsUser::Find(UserName);

        if (!User1.IsEmpty())
        {
            cout << "\nUser Found :-)\n";
        }
        else
        {
            cout << "\nUser Was not Found :-(\n";
        }

        _PrintUser(User1);

    }

};

