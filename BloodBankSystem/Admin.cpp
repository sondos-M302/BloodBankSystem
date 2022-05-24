#include "Admin.h"
#include "Donor.h"
#include "assert.h"
#include<string.h>
#include <iostream>
#include <fstream>
#include <iostream>
#include <ctime>

using namespace std;

Admin::Admin() {}

bool Admin::Login() {
	string Name, Password;
	while (true)
	{
		cout << "WELCOME TO LOGIN PAGE " << endl;
		cout << "Enter your name : " << endl;
		cin >> Name;
		cout << "Enter your Password" << endl;
		cin >> Password;
		if (Name == name && Password == password) {
			cout << "WELCOME ADMIN " << endl;
			break;
		}
	}
	return true;
	
}

void Admin::insert_donor(vector<Donor> VDonor) {
	D.Register();
}

void Admin::update_donor(vector<Donor> VDonor) {
	D.Login(VDonor);
	D.Update(VDonor);
}

void Admin::delete_donor(vector<Donor> VDonor) {
	D.Login(VDonor);
	D.Delete_Account(VDonor);
}

void Admin::display_donor(vector<Donor> VDonor) {
	
	D.DisplayVec(VDonor);
}

void Admin::insert_recipient(vector<Recipient> VRecipient) {
	R.Register();
}

void Admin::update_recipient(vector<Recipient> VRecipient) {
	R.Login(VRecipient);
	R.Update(VRecipient);
}

void Admin::delete_recipient(vector<Recipient> VRecipient) {
	R.Login(VRecipient);
	R.Delete_Account(VRecipient);
}

void Admin::display_recipient(vector<Recipient> VRecipient) {
	
	R.DisplayVec(VRecipient);
}

void Admin::insert_blood_data(vector <DonationRequest> DRequst, vector<Donor> VDonor){
	D.Login(VDonor);
	D.Donation_Request(DRequst);
}

void Admin::update_blood_data(vector <DonationRequest> DRequst, vector<Donor> VDonor){
	D.Login(VDonor);
	int new_Quantity;
	for (int i = 0; i < DRequst.size(); i++)
	{
		if (VDonor[stoi(D.index)].name == DRequst[i].donor) {
			cout << "Enter new Quantity"<<endl;
			cin >> new_Quantity;
			DRequst[i].Quantity = new_Quantity;
		}
	}
}

//void Admin::delete_blood_data(vector <DonationRequest> DRequst){
//	time_t now = time(0);
//	tm* ltm = localtime(&now);
//	
//	for (int i = 0; i < DRequst.size(); i++)
//	{
//		if (1900 + ltm->tm_year == DRequst[i].expiry_date.year) {
//			if (1 + ltm->tm_mon == DRequst[i].expiry_date.month) {
//				if (ltm->tm_mday >= DRequst[i].expiry_date.day)
//					DRequst.erase(DRequst.begin() + i);
//			}
//			else if (1 + ltm->tm_mon > DRequst[i].expiry_date.month) {
//				DRequst.erase(DRequst.begin() + i);
//			}
//		}
//		else if (1900 + ltm->tm_year > DRequst[i].expiry_date.year) {
//			DRequst.erase(DRequst.begin() + i);
//		}
//	}
//}


