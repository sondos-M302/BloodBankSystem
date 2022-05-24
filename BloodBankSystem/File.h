#pragma once
#include <vector>
#include "Recipient.h"
#include"Donor.h"
#include<iostream>
using namespace std;
class File
{
   public:
	   vector<Donor> VDonor;
	   vector<Recipient> VRecipient;
	   vector<DonationRequest>DRequst;
   public:
	   File();
	   void fill_VDonor();
	   void fill_VRecipient();
	   void fill_VDRequst();
	   void fill_DFile();
	   void fill_RFile();
	   void fill_DRequstFile();
	   ~File();
};

