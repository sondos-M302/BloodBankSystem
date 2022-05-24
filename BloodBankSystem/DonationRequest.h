#pragma once
#include <iostream>
#include<string>
#include <fstream>
#include "User.h"

using namespace std;

class DonationRequest
{
public:
	string type,donor;
	string Quantity;
	date received_date,expiry_date;
	DonationRequest();
	DonationRequest(string t, string Q, date received_date, date expiry_date, string donor);
};

