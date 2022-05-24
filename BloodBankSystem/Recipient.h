#pragma once
#include <string>
#include "User.h"
#include "DonationRequest.h"
using namespace std;

class Recipient : public User
{
public:
	string  hospital, case_doctor;
public:
	Recipient();
	Recipient(string id, string age, string index, string name, string mail, string password, string gender, string blood_type, string hospital, string case_doctor);
	void Register();
	bool Login(vector<Recipient> VRecipient);
	vector<Recipient> Update(vector<Recipient> VRecipient);
	vector<Recipient> Delete_Account(vector<Recipient> VRecipient);
	bool Search(string search, vector<DonationRequest>DRequst);
	void DisplayBloodType(vector <DonationRequest> DRequst);
	void DisplayVec(vector<Recipient> VRecipient);
	void Request(vector <DonationRequest> DRequst);
	int check_Quantity(vector<DonationRequest>DRequst, int Quantity, int i);
	bool CheckHospital(string hospital);
	bool CheckDoctor(string case_doctor);

	~Recipient();
};

