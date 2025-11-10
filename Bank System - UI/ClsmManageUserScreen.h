#pragma once
#include<iostream>
#include<iomanip>
#include"ClsScreen.h"
#include"clsInputValidate.h"
#include"ClsListUserScreen.h"
#include"ClsAddUsersScreen.h"
#include"DeleteUserScreen.h"
#include"ClsUpdateUserScreen.h"
#include"ClsFIndUserScreen.h"
#include"ClsmManageUserScreen.h"
#include "Global.h"
#include "CLsTransferScreen.h"
using namespace std;


class ClsManageUserScreen :protected ClsScreen

{
private:
    static void _GoBackToManageMenue()
    {
        cout << "\n\nPress any key to go back to Transactions Menue...";
        system("pause>0");
        ShowManageUser();

    }
    enum enUserOption {
        list_user = 1, add_new_user = 2, delete_user = 3,
        update_user = 4, main_menu = 5, find_user = 6
    };
    static int _read_main_user_option()
    {
        cout << "\t\t\t\t\tChoose what do you want to do [1 TO 6] ? ";
        short choice = clsInputValidate::read_int_number_between(1, 6, "enter number between 1 to 6");
        return choice;
    }


    static void ListUsersScreen()
    {
        ClsListUsersScreen::show_users_list();
    }

    static void AddNewUser()
    {
        ClsAddNewUSer::add_user_screen();
    }


    static void DeleteUser()
    {
        ClsDeleteUserScreen::Delete_client_screen();
    }

    static void UpdateUser()
    {
        clsUpdateUserScreen::ShowUpdateUserScreen();
    }
    static void FindUser()
    {
        clsFindUserScreen::ShowFindUserScreen();
    }
    static void MainMenu()
    {

    }


    static void _perform_Transaction(enUserOption option)
    {
        if (!check_access_rights(clsUser::enPermissions::pManageUsers))
        {
            return;
        }
        switch (option)
        {
        case enUserOption::list_user:
            system("cls");
            ListUsersScreen();
            _GoBackToManageMenue();
            break;

        case enUserOption::add_new_user:
            system("cls");
            AddNewUser();
            _GoBackToManageMenue();
            break;

        case enUserOption::delete_user:
            system("cls");
            DeleteUser();
            _GoBackToManageMenue();
            break;

        case enUserOption::update_user:
            system("cls");
            UpdateUser();
            _GoBackToManageMenue();
            break;
        case enUserOption::find_user:
            system("cls");
            FindUser();
            _GoBackToManageMenue();
            break;
        case enUserOption::main_menu:
            system("cls");
            break;
        }
    }
public:
    static void ShowManageUser()
    {
        system("cls");
        _draw_screen_header("\t\MANAGE USERS Screen");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\Manage User Manu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] users list.\n";
        cout << setw(37) << left << "" << "\t[2] add user.\n";
        cout << setw(37) << left << "" << "\t[3] delete user.\n";
        cout << setw(37) << left << "" << "\t[4] update user.\n";
        cout << setw(37) << left << "" << "\t[5] find user.\n";
        cout << setw(37) << left << "" << "\t[6] Exit.\n";

        cout << setw(37) << left << "" << "===========================================\n";

        _perform_Transaction((enUserOption)_read_main_user_option());
    }

};




