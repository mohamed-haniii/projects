#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsInputValidate.h"

class clsUpdateUserScreen :protected ClsScreen

{
private:


    static	int _read_permission()
    {
        int permission = 0;
        char Answer;
        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }
        cout << "\nshow clinet list y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            permission += clsUser::enPermissions::pListClients;
        }
        cout << "\nadd new client y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            permission += clsUser::enPermissions::pAddNewClient;
        }
        cout << "\ndelete client y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            permission += clsUser::enPermissions::pDeleteClient;
        }
        cout << "\nupdate client y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            permission += clsUser::enPermissions::pUpdateClients;
        }
        cout << "\nfind client y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            permission += clsUser::enPermissions::pFindClient;
        }
        cout << "\ntransaction y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            permission += clsUser::enPermissions::pTranactions;
        }
        cout << "\nmanage users y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            permission += clsUser::enPermissions::pManageUsers;
        }

        return permission;
    }
    static	void _read_user_info(clsUser& client)
    {
        string first, last, phone, email, password;
        double balance;
        cout << "Enter FirstName : ";
        cin >> first;
        client.set_first_name(first);
        cout << "Enter LastName : ";
        cin >> last;
        cout << "Enter Email : ";
        client.set_last_name(last);
        cin >> email;
        client.set_email(email);
        cout << "Enter Phone : ";
        cin >> phone;
        client.set_phone(phone);
        cout << "Enter PIN CODE : ";
        cin >> password;
        client.SetPassword(password);
        cout << "Enter permission: ";

        client.Permissions = _read_permission();
    }    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }

    static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';


        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {


            Permissions += clsUser::enPermissions::pListClients;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpdateClients;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pTranactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pManageUsers;
        }

        return Permissions;

    }

public:

    static void ShowUpdateUserScreen()
    {

        _draw_screen_header("\tUpdate User Screen");

        string UserName = "";
       
        cout << "\nPlease Enter User UserName: ";
        cin >> UserName;

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nAccount number is not found, choose another one: ";
            cin >> UserName;
        }

        clsUser User1 = clsUser::Find(UserName);

        _PrintUser(User1);

        cout << "\nAre you sure you want to update this User y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            cout << "\n\nUpdate User Info:";
            cout << "\n____________________\n";


            _read_user_info(User1);
            User1._read_permission();
            clsUser::enSaveResults SaveResult;

            SaveResult = User1.Save();

            switch (SaveResult)
            {
            case  clsUser::enSaveResults::svSucceeded:
            {
                cout << "\nUser Updated Successfully :-)\n";

                _PrintUser(User1);
                break;
            }
            case clsUser::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError User was not saved because it's Empty";
                break;

            }

            }

        }

    }
};

