#pragma once
#include <iostream>
#include<string.h>
#include "assert.h"
#include <fstream>
#include <regex>
//#include "File.h"
using namespace std;
static struct date {
public :
	string day, month, year;
	date() {}
	date(string d, string m, string y) {
		day = d;
		month = m;
		year = y;
	}

};
class User
{
   public:
	string id, age,index;
	string name, mail, password, gender, blood_type;
	
   public:
	   User();
	   User(string id, string age, string index, string name, string mail, string password, string gender, string blood_type);
	   void Register();
	   bool Login(string Umail, string Upassword);
	   void Update();
	   void Delete_Account();
	   bool PasswordValidator(string password);
	   bool AgeValidator(string age);
	   bool MailValidator(string mail);
	   bool GenderValidator(string gender);
	   bool BloodtypeValid(string blood_type);
	   bool NameValidator(string name);
	   ~User();
};

