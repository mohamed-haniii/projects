#pragma once

#include <iostream>
#include "clsScreen.h"
#include"ClsBankUsers.h"
#include <iomanip>

class ClsListUsersScreen :protected ClsScreen
{

public:

    static void print_user_record(clsUser user)
    {
        cout << setw(8) << left << "" << "| " << setw(15) << left << user.UserName;
        cout << "| " << setw(20) << left << user.FirstName + " " + user.LastName;
        cout << "| " << setw(12) << left << user.Phone;
        cout << "| " << setw(20) << left << user.Email;
        cout << "| " << setw(10) << left << user.Password;
        cout << "| " << setw(10) << left << user.Permissions;
    }

    static void show_users_list()
    {
        vector <clsUser> vClients = clsUser::GetUsersList();
        string Title = "\t  USERS List Screen";
        string SubTitle = "\t    (" + to_string(vClients.size()) + ") USERS(s).";

        _draw_screen_header(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(15) << "USER NAME";
        cout << "| " << left << setw(20) << "Name";
        cout << "| " << left << setw(12) << "PHONE";
        cout << "| " << left << setw(20) << "EMAIL";
        cout << "| " << left << setw(10) << "PASSWORD";
        cout << "| " << left << setw(12) << "PERMISSION";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo USERS Available In the System!";
        else

            for (clsUser Client : vClients)
            {

                print_user_record(Client);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
    

};