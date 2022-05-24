#include <iostream>
#include "File.h"
#include"Donor.h"
#include"Admin.h"
#include"Recipient.h"
#include<string>
#include <fstream>
#include <vector>
using namespace std;


int main()
{
    Donor D = Donor();
    Recipient R = Recipient();
    Admin A = Admin();
    File F = File();

    int choiseUser, RegOrLog, choiseFun;
    char _Continue;
    cout << "Choose The Type Of User :\n1.Donor\n2.Recipient\n3.Admin\n";
    cin >> choiseUser;

    if (choiseUser == 1) {
        cout << "**************************Welcome to Page Donor**************************\n";
       
        F.fill_VDRequst();
        cout << "Enter 1 to Regester or 2 to login" << endl;
        cin >> RegOrLog;
        if (RegOrLog == 1) {
            D.Register();
            F.fill_VDonor();
            D.DisplayVec(F.VDonor);
        }
        else if (RegOrLog == 2) {
            F.fill_VDonor();
            D.DisplayVec(F.VDonor);
            D.Login(F.VDonor);
        }
        do
        {
            // if (islogin == true) {
            cout << "1.Donation Request \n2.Update\n3.Delete Account\n";
            cout << "Enter your choice : ";
            cin >> choiseFun;
            switch (choiseFun)
            {
            case 1://Donation Request
            {
                F.DRequst = D.Donation_Request(F.DRequst);
                break;
            }
            case 2://Update
            {
                F.VDonor = D.Update(F.VDonor);
                D.DisplayVec(F.VDonor);
                break;
            }
            case 3://Delete Account
            {
                F.VDonor = D.Delete_Account(F.VDonor);
                break;
            }
            default:
            {
                cout << "Invalid choice!\n";
                break;
            }


            }

            cout << "If you want to continue press (y) else press any key : ";
            cin >> _Continue;
            cout << "**************************************************************" << endl;
        } while (_Continue == 'y');
        F.fill_DFile();
        F.fill_DRequstFile();
        return 0;
    }
    else if (choiseUser == 2) {
        cout << "**************************Welcome to Page Recipient**************************\n";
       
        do
        { 
           
            cout << "Enter 1 to Regester or 2 to login" << endl;
            cin >> RegOrLog;
            if (RegOrLog == 1) {
                R.Register();
                F.fill_VRecipient();
                R.DisplayVec(F.VRecipient);
            }
            else if (RegOrLog == 2) {
                
                F.fill_VRecipient();
               // R.DisplayVec(F.VRecipient);
                R.Login(F.VRecipient);

            }
            cout << "Enter your choice :\n ";
            
            cout << "1.Update \n2.Delete Account \n"
                << "3.Search For Availablity Of Blood Type \n4.Display All Blood Data \n"
                << "5.Request The Blood Type And Quantity\n ";
            cin >> choiseFun;
            switch (choiseFun)
            {
            case 1://Update
            {
                F.VRecipient = R.Update(F.VRecipient);
                R.DisplayVec(F.VRecipient);
                break;
            }
            case 2://Delete Account
            {
                F.VRecipient = R.Delete_Account(F.VRecipient);
                break;
            }
            case 3://Search For Availablity Of Blood Type
            {
                string search;
                cin >> search;
                R.Search(search,F.DRequst);
                break;
            }
            case 4://Display All Blood Data
            {
                R.DisplayBloodType(F.DRequst);
                break;
            }
            case 5://Request The Blood Type And Quantity
            {
                R.Request(F.DRequst);
                break;
            }
            default:
            {
                cout << "Invalid choice!\n";
                break;
            }
            }
            cout << "If you want to continue press (y) else press any key : ";
            cin >> _Continue;
            cout << "**************************************************************" << endl;
        } while (_Continue == 'y');
        F.fill_RFile();
        return 0;
    }
    else if (choiseUser == 3)
    {
        cout << "**************************Welcome to Page Admin**************************\n";
        cout << "login" << endl;
        
            A.Login();

            do
            {
                cout << "Enter your choice :\n ";

                cout << "1.insert_donor \n2.delete_donor \n"
                    << "3.insert_recipien\n4.display_recipient \n"
                    << "5.display_donor\n ";
                cin >> choiseFun;
                switch (choiseFun)
                {
                case 1://Update
                {
                    F.fill_VDonor();
                    A.insert_donor(F.VDonor);
                    
                    break;
                }
                case 2://Delete Account
                {
                    A.delete_donor(F.VDonor);
                        break;
                }
                case 3:
                {
                    F.fill_VRecipient();

                    A.insert_recipient(F.VRecipient);
                    break;
                    
                }
                case 4://Display All Blood Data
                {
                    F.fill_VRecipient();
                    A.display_recipient(F.VRecipient);
                    break;
                }
                case 5://Request The Blood Type And Quantity
                {
                    F.fill_VDonor();
                    A.display_donor(F.VDonor);
                    break;
                }
                default:
                {
                    cout << "Invalid choice!\n";
                    break;
                }
                }
                cout << "If you want to continue press (y) else press any key : ";
                cin >> _Continue;
                cout << "**************************************************************" << endl;
            } while (_Continue == 'y');
            F.fill_RFile();
            return 0;
    }
 
}



