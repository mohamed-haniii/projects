#pragma once
#include<iostream>
#include<iomanip>
#include"ClsScreen.h"
#include"ClsDepositeScreen.h"
#include"ClsWithDrowScreen.h"
#include"TotalBalaceScreen.h"
#include"CLsTransferScreen.h"
using namespace std;


    class ClsTransactionScreen :protected ClsScreen
        
{
private:
    static void _GoBackToTransactionsMenue()
    {
        cout << "\n\nPress any key to go back to Transactions Menue...";
        system("pause>0");
        ShowTransactionScreen();

    }
    enum enTransactionOption {
        deposite = 1, withdraw = 2, TotalBalance = 3,
        transfer=4,eExit = 5
    };
    static int _read_main_transaction_option()
    {
        cout << "\t\t\t\t\tChoose what do you want to do [1 TO 5] ? ";
        short choice = clsInputValidate::read_int_number_between(1, 5, "enter number between 1 to 5");
        return choice;
    }
 

    static void DepositeScreen()
    {
        ClsDepositeScreen::Deposite_screen();
        _GoBackToTransactionsMenue();
    }

    static void WithDrowScreen()
    {
        ClsWithDrowScreen::Deposite_screen();
        _GoBackToTransactionsMenue();
    }


    static void TotalBalanceScreen()
    {
        ClsTotalBalanceScreen::TotalBalanceScreen();
        _GoBackToTransactionsMenue();
    }
    static void TransferScreen()
    {
        CLsTransferScreen::transfer_screen();
        _GoBackToTransactionsMenue();
    }

    static void exit()
    {
    }


    static void _perform_Transaction(enTransactionOption option)
    {
        switch (option)
        {
            if (!check_access_rights(clsUser::enPermissions::pTranactions))
            {
                break;
            }
        case enTransactionOption::deposite:
            system("cls");
            DepositeScreen();
            break;

        case enTransactionOption::withdraw:
            system("cls");
            WithDrowScreen();
            break;

        case enTransactionOption::TotalBalance:
            system("cls");
            TotalBalanceScreen();
            break;
        case enTransactionOption::transfer:
            system("cls");
            TransferScreen();
            break;

        case enTransactionOption::eExit:
            break;


            break;
        }
    }
public:
    static void ShowTransactionScreen()
    {
        system("cls");
        _draw_screen_header("\t\tTransaction Screen");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\Transaction Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposite.\n";
        cout << setw(37) << left << "" << "\t[2] Withdrow.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balance.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Exit.\n";
        
        cout << setw(37) << left << "" << "===========================================\n";

        _perform_Transaction((enTransactionOption)_read_main_transaction_option());
    }

};




