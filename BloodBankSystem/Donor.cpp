#include "Donor.h"
#include "User.h"
#include "File.h"
#include <iostream>
#include <ctime>
#include<string.h>
#include "assert.h"
#include <fstream>
#include <queue>
#include "DonationRequest.h"

using namespace std;
Donor::Donor() {}

Donor::Donor(string id, string age, string index, string name, string mail, string password, string gender, string blood_type,date Date, date Date_donation, string disease, string other_disease){
	User(id,age,index,name,mail,password,gender,blood_type);
	this->Date = Date;
	this->Date_donation = Date_donation;
	this->disease = disease;
	this->other_disease = other_disease;
}

void Donor::Register() {
	
	User::Register();
	
	cout << "Enter the date of last Donation (Day Month Year) : \n";cin >> Date.day >> Date.month >> Date.year;
	//checck date is valid
	while (!DateValidator(Date))
	{
		cout<< "invalid DAte" << endl;
		cout << "Enter valid Date (Day month year) : " << endl;   cin >> Date.day>> Date.month>> Date.year;

	}
	if (DateValidator(Date))
	{
		cout << "valid DAte of Donation" << endl;
	}

	cout << "Do You suffer from any disease"<<endl<<" (blood pressure disorders, thyroid, disease, \n diabetes, cancer, heart disorders, hepatitis) "<<endl
		<<" Please answer with yes or no " << endl; cin >> disease;
	//check on answer
	while (!checkReply(disease))
	{
		cout << "please Enter yes or no "; cin >> disease;
	}
	
	
	cout << "do you suffer from any other disease or take any medicine" << endl; cin >> other_disease;
	//check on reply
	while (!checkReply(other_disease))
	{
		cout << "please Enter yes or no "; cin >>other_disease;
	}
	

	cout << " Regester is Done " << endl;

	int m = stoi(Date.month) + 3, y = stoi(Date.year);
	if (m > 12) {
		y++;
		m = m % 12;
	}
	Date_donation.day= Date.day;
	Date_donation.month = m;
	Date_donation.year = y;
	cout<< "Date_next_donation =" << Date_donation.day<<'-' << Date_donation.month<<'-' << Date_donation.year << endl;
	cout << "mail =" << mail << endl;

	fstream file;
	file.open("data.txt", ios::app);
		file <<mail << '|' <<password << '|' <<name << '|' << id << '|' << age << '|' <<gender << '|' <<blood_type << '|'
			<<Date.day << '-' << Date.month << '-' <<Date.year << '|'
			<<Date_donation.day << '-' << Date_donation.month << '-' << Date_donation.year<<'|' << disease << '|' << other_disease << '|';
		file << endl;
	file.close();
	
}

bool Donor::Login(vector<Donor> VDonor){
	string Umail, Upassword;
	//User::Login(Umail,Upassword);
	cout << "WELCOME TO LOGIN PAGE " << endl;
	cout << "Enter your mail : " << endl;
	cin >> Umail;
	cout << "Enter your Password" << endl;
	cin >> Upassword;
		for (int i = 0; i <VDonor.size(); i++)
		{
			if (VDonor[i].mail._Equal( Umail) && VDonor[i].password._Equal(Upassword)) {
				cout << "wlecome " <<VDonor[i].name << endl;
				mail = VDonor[i].mail;
				password = VDonor[i].password;
				name = VDonor[i].name;
				age = VDonor[i].age;
				id = VDonor[i].id;
				Date.day = VDonor[i].Date.day;
				Date.month = VDonor[i].Date.month;
				Date.year = VDonor[i].Date.year;
				disease=  VDonor[i].disease;
				other_disease = VDonor[i].other_disease;


				index = to_string(i);


				return true;
			}
		}
		return false;
}

vector <DonationRequest> Donor::Donation_Request(vector <DonationRequest> DRequst) {
	string blood_quantity;
	cout << "Great!!\n welcome to Donation Request page \n  ";
	cout << "Enter Your BLood quantity : " << endl; cin >> blood_quantity;

	cout << "Enter date now " << endl;
	date date_now;
	cin >> date_now.day >> date_now.month >> date_now.year;
	while (!DateValidator(date_now))
	{
		cout << "invalid DAte" << endl;
		cout << "Enter valid Date (Day month year) : " << endl;   cin >> date_now.day >> date_now.month >> date_now.year;

	}
	if (DateValidator(date_now))
	{
		cout << "valid DAte of Donation" << endl;
	}
	// bounas
	// Date -> last Donation
	// Date+3 month -> valid

	bool b = validation(age, Date, date_now, disease, other_disease);
	//add DonationRequest in  vector

	//time_t now = time(0);
	//tm* ltm = localtime(&now);
	// time now -> received
	if (b == true) {
		date received = date(date_now.day, date_now.month, date_now.year);
		// time now+ 3 month -> expry
		int m = stoi(received.month) + 1, y = stoi(received.year);
		if (m > 12) {
			y++;
			m = m % 12;
		}
		date expiry = date(received.day, to_string(m), to_string(y));
		DonationRequest dor = DonationRequest(blood_type, blood_quantity, received, expiry, name);
		DRequst.push_back(dor);
		cout << "valid donation request\n";
	
	}
	else {
		cout << "Invalid donation request\n";
	}
	
	return DRequst;
}

bool Donor::validation(string age,date Date, date now, string desease, string other_desease) {
	
	if (!AgeValidator(age))
		return false;  // user can't donate
	
	if (desease == "yes") {
		// user can't donate
		return false;
	}
	if (other_desease == "yes") {
		// user can't donate
		return false;
	}

	
	
	if (now.year == Date_donation.year) {
		if (now.month == Date_donation.month) {
			if (now.day >= Date_donation.day)
				return true;
		}
		else if (now.month> Date_donation.month) {
			return true;
		}
	}
	else if (now.year > Date_donation.year) {
		return true;
	}

	// user can't donate
	return false;
}

vector<Donor>Donor::Update(vector<Donor> VDonor) {
	string new_mail, new_password, new_bloodType, new_day, new_month, new_year, new_disease, new_other_disease;
	int new_age;
	cout << "Enter what want to UPDATE :\n1.mail\n2.password\n3.age\n4.blood type\n" <<
		"5.DAte of Donation\n6.disease\n7.other disease\n";
	int x;
	cin >> x;
	switch (x) {
	case 1://mail
	{
		cout << "Enter your new mail\n";
		cin >> new_mail;
		while(!MailValidator(new_mail))
		{
			cout << new_mail << " : " << "invalid" << endl;
			cout << "Enter valid mail : " << endl;  cin >> new_mail;
		}
		if (MailValidator(new_mail)) {
			cout << new_mail << " : "	<< "valid" << endl;
			VDonor[stoi(index)].mail = new_mail;
		}
		break;
	}
	case 2://password
	{
		cout << "Enter your new password\n";
		cin >> new_password;
		// check password is valid
		while (!PasswordValidator(new_password))
		{
			cout << "Invalid Password" << endl;
			cout << "Enter valid Password : " << endl;   cin >> new_password;
		}
		if (PasswordValidator(new_password))
		{
			VDonor[stoi(index)].password = new_password;
			cout << "Valid Password" << endl;
		}
		
		break;
	}
	case 3://age
	{
		cout << "Enter Your Age : " << endl;
		cin >> new_age;
		while (!AgeValidator(to_string(new_age)))
		{
			cout << "Invalid Age" << endl;
			cout << "Enter valid Age : " << endl;   cin >> new_age;
		}
		if (AgeValidator(to_string(new_age)))
		{
			cout << "Valid Age" << endl;
			VDonor[stoi(index)].age = new_age;
		}
		
		break;
	}
	case 4://blood type
	{
		cout << "Enter Your BLood type : " << endl;
		cin >> new_bloodType;
		while (!BloodtypeValid(new_bloodType))
		{
			cout << blood_type << " : " << "invalid" << endl;
			cout << "Enter valid blood type : " << endl;   cin >> new_bloodType;

		}
		if (BloodtypeValid(blood_type))
		{
			cout << blood_type << " : "
				<< "valid" << endl;
			VDonor[stoi(index)].blood_type = new_bloodType;
		}
		
		break;
	}
	case 5://DAte of Donation
	{
		/*cout << "Enter the date of last Donation (Day Month Year) : \n";
		cin >> new_day >> new_month >> new_year;
		while (!DateValidator(new_day , new_month , new_year))
		{
			cout << "invalid DAte" << endl;
			cout << "Enter valid Date (Day month year) : " << endl;   cin >> new_day >> new_month >> new_year;

		}
		if (DateValidator(new_day, new_month, new_year))
		{
			cout << "valid DAte of Donation" << endl;
			VDonor[index].day = new_day;
			VDonor[index].month = new_month;
			VDonor[index].year = new_year;
		}
		*/
		break;
	}
	case 6://disease
	{
		cout << "Do You suffer from any disease\n"
			<< " (blood pressure disorders, thyroid, disease, diabetes, cancer, heart disorders, hepatitis)\n"
			<< " Please answer with yes or no \n";
		cin >> new_disease;
		checkReply(new_disease);
		VDonor[stoi(index)].disease = new_disease;
		break;
	}
	case 7://other disease
	{
		cout << "do you suffer from any other disease or take any medicine" << endl;
		cin >> new_other_disease;
		checkReply(new_other_disease);
		VDonor[stoi(index)].other_disease = new_other_disease;
		break;

	}
	default:
	{
		cout << "Invalid choice!\n";
		break;
	}
	
	}
	return VDonor;
}

vector<Donor> Donor::Delete_Account(vector<Donor> VDonor){
	if (VDonor.empty())
	{
		cout << "You don't have any text yet!\n";
	}
	else
	{
		VDonor.erase(VDonor.begin() + stoi(index)-1);
		return VDonor;
	}
}

void Donor::DisplayVec(vector<Donor> VDonor) {
	if (VDonor.size() != 0){
		for (int i = 0; i < VDonor.size() - 1; i++)
		{
			cout << (i + 1) << " "<<VDonor[i].mail << '|' << VDonor[i].password << '|' << VDonor[i].name << '|' << VDonor[i].id << '|' << VDonor[i].age << '|' << VDonor[i].gender << '|'
				<< VDonor[i].blood_type << '|' << VDonor[i].Date.day << '-' << VDonor[i].Date.month << '-' << VDonor[i].Date.year << '|' << VDonor[i].disease << '|' << VDonor[i].other_disease << endl;

		}
    }
	else
		cout << "You did not enter any text yet!\n";

}

bool Donor::DateValidator(date Date)
{
	
		if (1960 <=stoi( Date.year) <= 2022)
		{
			if ((Date.month == "1" || Date.month == "2"|| Date.month == "3 "|| Date.month == "4"
				|| Date.month == "5"|| Date.month == "6" || Date.month ==" 7" || Date.month == "8"
				|| Date.month == "9"|| Date.month == "10" || Date.month == "11" || Date.month == "12")
				&& Date.day > "0" && Date.day <= "31")

				return true;
			
					
		}
		else
			return false;
		
	
}


bool Donor::checkReply(string reply)
{
	if (reply == "yes" || reply == "no" || reply == "YES" || reply == "NO")
		return true;
	else
		return false;
}

Donor::~Donor() {

}