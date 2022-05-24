#pragma once
#include <string>
#include "User.h"
#include "Donor.h"
#include "Recipient.h"

using namespace std;

class Admin : public User
{
  public:
	string name="Admin", password="6543", blood_type;
	Donor D = Donor();
	Recipient R = Recipient();
	int  age;
	Admin();
	bool Login();// Admin1

	void insert_donor(vector<Donor> VDonor);
	void insert_recipient(vector<Recipient> VRecipient);
	void update_donor(vector<Donor> VDonor);
	void update_recipient(vector<Recipient> VRecipient);
	void delete_donor(vector<Donor> VDonor);
	void delete_recipient(vector<Recipient> VRecipient);
	void display_donor(vector<Donor> VDonor);
	void display_recipient(vector<Recipient> VRecipient);
	void insert_blood_data(vector <DonationRequest> DRequst, vector<Donor> VDonor);
	void update_blood_data(vector <DonationRequest> DRequst, vector<Donor> VDonor);
	void delete_blood_data(vector <DonationRequest> DRequst);
};
 
