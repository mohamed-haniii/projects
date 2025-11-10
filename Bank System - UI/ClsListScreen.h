#pragma once

#include <iostream>
#include "clsScreen.h"
#include "ClsBankClient.h"
#include <iomanip>

class ClsListScreen :protected ClsScreen
{

    static void print_client_record(ClsBankClient Client)
    {
        cout << setw(8) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(20) << left << Client.FirstName + " " + Client.LastName;
        cout << "| " << setw(12) << left << Client.Phone;
        cout << "| " << setw(20) << left << Client.Email;
        cout << "| " << setw(10) << left << Client.PinCode;
        cout << "| " << setw(12) << left << Client.AccountBalance;
    }
public:


    static void show_clinets_list()
    {
        if (!check_access_rights(clsUser::enPermissions::pListClients))
        {
            return;
        }
        vector <ClsBankClient> vClients = ClsBankClient::getClientList();
        string Title = "\t  Client List Screen";
        string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";

        _draw_screen_header(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (ClsBankClient Client : vClients)
            {

                print_client_record(Client);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }

};