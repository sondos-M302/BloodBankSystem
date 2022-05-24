#pragma once
#include <string>
#include "User.h"
#include "DonationRequest.h"

using namespace std;

class Donor : public User
{
public:
	date Date, Date_donation;
	string disease,other_disease;
public:
	Donor();
	Donor(string id, string age, string index, string name, string mail, string password, string gender, string blood_type, date Date, date Date_donation, string disease, string other_disease);
	void Register();
	bool Login(vector<Donor> VDonor);
	vector <DonationRequest> Donation_Request(vector <DonationRequest> DRequst);
	vector<Donor> Update(vector<Donor> VDonor);
	vector<Donor> Delete_Account(vector<Donor> VDonor);
	void DisplayVec(vector<Donor> VDonor);
	bool validation(string age, date Date, date now, string desease, string other_desease);
	//bool PasswordValidator(string password);
	bool DateValidator(date Date);
	bool checkReply(string reply);
	~Donor();
};

