#pragma once
#include <iostream>
#include <fstream>
#include "clsScreen.h"
#include "ClsBankUsers.h"
#include "Global.h"
class ClsShowRegisterScreen:public ClsScreen
{


    static void PrintLoginRegisterRecordLine(clsUser::login_data LoginRegisterRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(35) << left << LoginRegisterRecord.date;
        cout << "| " << setw(20) << left << LoginRegisterRecord.user_name;
        cout << "| " << setw(20) << left << LoginRegisterRecord.password;
        cout << "| " << setw(10) << left << LoginRegisterRecord.permission;
    }

public:

    static void ShowLoginRegisterScreen()
    {
        if (!check_access_rights(clsUser::enPermissions::pLoginRegister))
        {
            return;
        }

        vector <clsUser::login_data> vLoginRegisterRecord = clsUser::GetLoginRegisterList();

        string Title = "\tLogin Register List Screen";
        string SubTitle = "\t\t(" + to_string(vLoginRegisterRecord.size()) + ") Record(s).";

        _draw_screen_header(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
        cout << "| " << left << setw(20) << "UserName";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(10) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vLoginRegisterRecord.size() == 0)
            cout << "\t\t\t\tNo Logins Available In the System!";
        else

            for (clsUser::login_data Record : vLoginRegisterRecord)
            {

                PrintLoginRegisterRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }

};





