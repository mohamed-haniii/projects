#pragma once
#include<iostream>
#include<iomanip>
#include"ClsScreen.h"
#include"clsInputValidate.h"
#include"ClsListScreen.h"
#include"ClsAddNewClient.h"
#include"ClsDeleteScreen.h"
#include"ClsUpdateScreen.h"
#include"ClsFIndCLient.h"
#include"ClsTransactionScreen.h"
#include"ClsmManageUserScreen.h"
#include "Global.h"
#include "ClsShowRegisterScreen.h"
using namespace std;

class ClsMainScreen :protected ClsScreen
{
private:
    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eCurrency = 9, eExit = 10,eLoginRegister=8
    };
    static void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "\n\tPress any key to go back to Main Menue...\n";
        system("pause>0");
        ShowMainMenue();
    }

    static void _ShowAllClientsScreen()
    {

        ClsListScreen::show_clinets_list();
    }

    static void _ShowAddNewClientsScreen()
    {
        ClsAddNewClients::add_client_screen();
    }

    static void _ShowDeleteClientScreen()
    {
        ClsDeleteScreen::Delete_client_screen();
    }

    static void _ShowUpdateClientScreen()
    {
        ClsUpdateScreen::update_data_screen();
    }

    static void _ShowFindClientScreen()
    {
        ClsFindClient::ShowFindClientScreen();
    }

    static void _ShowTransactionsMenue()
    {
        ClsTransactionScreen::ShowTransactionScreen();
    }

    static void _ShowManageUsersMenue()
    {
        ClsManageUserScreen::ShowManageUser();
    }


    static void _showLoginRegister_screen()
    {
        ClsShowRegisterScreen::ShowLoginRegisterScreen();
    }

    static void _logout()
    {
        current_user = clsUser::Find("", "");
    }

    static void _perform_main_menue(enMainMenueOptions option)
    {
        switch (option)
        {
        case enMainMenueOptions::eListClients:
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
            break;

        case enMainMenueOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            break;

        case enMainMenueOptions::eLoginRegister:
            system("cls");
            _showLoginRegister_screen();
            break;


        case enMainMenueOptions::eCurrency:
            system("cls");
            _showLoginRegister_screen();
            break;

        case enMainMenueOptions::eExit:
            system("cls");
            _logout();
            //Login();

            break;
        }
    }

    public:
        static int _read_main_menue_option()
        {
            cout << "\t\t\t\t\tChoose what do you want to do [1 TO 10] ? ";
            short choice = clsInputValidate::read_int_number_between(1, 10, "enter number between 1 to 10");
            return choice;
        }

    static void ShowMainMenue()
    {
        system("cls");
        _draw_screen_header("\t\tMAIN SCREEN");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Login Regiser.\n";
        cout << setw(37) << left << "" << "\t[9] Login Regiser.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _perform_main_menue((enMainMenueOptions)_read_main_menue_option());
    }

 };

    


