#include "Recipient.h"
#include <iostream>
#include<string>
#include <fstream>
#include "assert.h"
using namespace std;

Recipient::Recipient() {
}

Recipient::Recipient(string id, string age, string index, string name, string mail, string password, string gender, string blood_type, string hospital, string case_doctor) {
	User(id, age, index, name, mail, password, gender, blood_type);
	this->hospital = hospital;
	this->case_doctor = case_doctor;
}

void Recipient::Register() {
	User::Register();
	cout << "Enter Name of Hospital : " << endl; cin >> hospital;
	// check hospital name
	while (!CheckHospital(hospital))
	{
		cout << "Enter a name with characters only.\n " << endl;
		cout << "Enter valid hospital name : " << endl;   cin >> hospital;

	}
	if (CheckHospital(hospital))
	{
		cout << hospital << " : "
			<< " is valid name" << endl;
	}

	cout << "Enter Your Name of Your Doctor : " << endl; cin >> case_doctor;
	// check for dactor name is valid
	while (!CheckDoctor( case_doctor))
	{
		cout << "Enter a name with characters only.\n " << endl;
		cout << "Enter valid Doctor name : " << endl;   cin >> case_doctor;

	}
	if (CheckDoctor( case_doctor))
	{
		cout << case_doctor << " : "
			<< " is valid name" << endl;
	}
	cout << " Regester is Done " << endl;
	fstream Rfile;
	
	Rfile.open("recdata.txt", ios::app);
		Rfile <<mail << '|' <<password << '|' << name << '|' << id << '|' << age << '|' << gender << '|'
		    << blood_type << '|' << hospital << '|' << case_doctor<<'|' << '\n';
	
	Rfile.close();
	
	
}

bool Recipient::Login(vector<Recipient> VRecipient) {
	cout << "WELCOME TO LOGIN PAGE " << endl;
	string Umail, Upassword;
	cout << "Enter your mail : " << endl;
	cin >> Umail;
	cout << "Enter your Password" << endl;
	cin >> Upassword;
	for (int i = 0; i <VRecipient.size(); i++)
	{
		if (VRecipient[i].mail == Umail && VRecipient[i].password == Upassword) {
			cout << "wlecome " << VRecipient[i].name << endl;
			mail = VRecipient[i].mail;
			password = VRecipient[i].password;
			name = VRecipient[i].name;
			index =to_string(i);

			return true;
		}
	}
	return false;
}

vector<Recipient> Recipient::Update(vector<Recipient> VRecipient) {
	string new_mail, new_password, new_bloodType, new_hospital,new_caseDoctor;
	int new_age;
	cout << "Enter what want to UPDATE :\n1.mail\n2.password\n3.age\n4.blood type\n" <<
		"5.hospital\n6.doctor\n";
	int x;
	cin >> x;
	switch (x) {
	case 1://mail
	{
		cout << "Enter your new mail\n";
		cin >> new_mail;
		while (!MailValidator(new_mail))
		{
			cout << new_mail << " : " << "invalid" << endl;
			cout << "Enter valid mail : " << endl;  cin >> new_mail;
		}
		if (MailValidator(new_mail)) {
			cout << new_mail << " : " << "valid" << endl;
			VRecipient[stoi(index)].mail = new_mail;
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
			VRecipient[stoi(index)].password = new_password;
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
			VRecipient[stoi(index)].age = new_age;
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
			VRecipient[stoi(index)].blood_type = new_bloodType;
		}

		break;
	}
	case 5://hospital
	{
		cout << "Enter Name of Hospital : " << endl;
		cin >> new_hospital;
		while (!CheckHospital(new_hospital))
		{
			cout << "Enter a name with characters only.\n " << endl;
			cout << "Enter valid hospital name : " << endl;   cin >> new_hospital;

		}
		if (CheckHospital(new_hospital))
		{
			cout << new_hospital << " : "
				<< " is valid name" << endl;
			VRecipient[stoi(index)].hospital = new_hospital;
		}

		
		
		
		break;
	}
	case 6://case_doctor
	{
		cout << "Enter Your Name of Your Doctor : " << endl;
		cin >> new_caseDoctor;
		while (!CheckDoctor(new_caseDoctor))
		{
			cout << "Enter a name with characters only.\n " << endl;
			cout << "Enter valid Doctor name : " << endl;   cin >> new_caseDoctor;

		}
		if (CheckDoctor(new_caseDoctor))
		{
			cout << case_doctor << " : "
				<< " is valid name" << endl;
			VRecipient[stoi(index)].case_doctor = new_caseDoctor;
		}
		
		break;
	}
	default:
	{
		cout << "Invalid choice!\n";
		break;
	}

	}
	return VRecipient;
}

vector<Recipient> Recipient::Delete_Account(vector<Recipient> VRecipient) {
	if (VRecipient.empty())
	{
		cout << "You don't have any text yet!\n";
	}
	else
	{
		VRecipient.erase(VRecipient.begin() + stoi(index));
		return VRecipient;
	}
}

bool Recipient::Search(string search, vector<DonationRequest>DRequst) {
	//int maxrow = 100;
	//string bloodType[100] = {};//add here the values from data structure or file or maniual.

	cout << "Current Records" << endl;
	cout << "=================================" << endl;
	//int count = 0;
	for (int i = 0; i < DRequst.size(); i++) {

		if (DRequst[i].type == search) {
		//	count++;
			cout << "it's available...";
			cout << " founded types: " << DRequst[i].type;
			break;
		}
		cout << "No Record found!" << endl;
		return false;
	}
	
	cout << "================================================" << endl;
	return false;
}

void Recipient::DisplayBloodType(vector <DonationRequest> DRequst) {
	if (DRequst.size() != 0) {
		for (int i = 0; i < DRequst.size() - 1; i++)
		{
			cout << (i + 1) << DRequst[i].donor << '|' << DRequst[i].type << '|' << DRequst[i].Quantity<< '|' 
				<< DRequst[i].received_date.day<<'-' 
				<< DRequst[i].received_date.month << '-'
				<< DRequst[i].received_date.year << '|' 
				<<DRequst[i].expiry_date.day << '-' 
				 << DRequst[i].expiry_date.month << '-'
				<< DRequst[i].expiry_date.year << '|' << endl;
		}
	}
	else
		cout << "You did not enter any text yet!\n";
}

void Recipient::DisplayVec(vector<Recipient> VRecipient) {
	if (VRecipient.size() != 0) {
		for (int i = 0; i < VRecipient.size() - 1; i++)
		{
			cout << (i + 1) <<" "<< VRecipient[i].mail << '|' << VRecipient[i].password << '|' << VRecipient[i].name << '|' << VRecipient[i].id << '|' << VRecipient[i].age << '|' << VRecipient[i].gender << '|'
				<< VRecipient[i].blood_type << '|' << VRecipient[i].hospital << '|' << VRecipient[i].case_doctor << endl;

		}
	}
	else
		cout << "You did not enter any text yet!\n";
}

void Recipient::Request(vector <DonationRequest> DRequst) {
	int Quantity, original_quantity;//10
	cout << "How many bags do you want from the blood type you entered" << endl;
	cin >> original_quantity;
	Quantity = original_quantity;

	if (blood_type == "A+") {
		//cout << "You can receive blood from the following types :" << "A+" << "A-" << "O+" << "O-" << endl;
		for (int i = 0; i < DRequst.size(); i++)
		{ //10 // 5-> A+  //5 -> O-
			if (DRequst[i].type == "A+"|| DRequst[i].type == "A-"|| DRequst[i].type == "O+"|| DRequst[i].type == "O-") {
				Quantity = check_Quantity(DRequst, Quantity, i);
				if (Quantity == 0) {
					break;
				}
			}
		}
	}
	else if (blood_type == "A-") {
		//cout << "You can receive blood from the following types :" << "A-" << "O-" << endl;
		for (int i = 0; i < DRequst.size(); i++)
		{
			if (DRequst[i].type == "A-"|| DRequst[i].type == "O-") {
				Quantity = check_Quantity(DRequst, Quantity, i);
				if (Quantity == 0) {
					break;
				}
			}
		}
	}
	else if (blood_type == "B+") {
		//cout << "You can receive blood from the following types :" << "B-" << "O-" << endl;
		for (int i = 0; i < DRequst.size(); i++)
		{
			if (DRequst[i].type == "B-"|| DRequst[i].type == "O-") {
				Quantity = check_Quantity(DRequst, Quantity, i);
				if (Quantity == 0) {
					break;
				}
			}
		}
	}
	else if (blood_type == "B-") {
		for (int i = 0; i < DRequst.size(); i++)
		{
			if (DRequst[i].type == "B-" || DRequst[i].type == "O-") {
				Quantity = check_Quantity(DRequst, Quantity, i);
				if (Quantity == 0) {
					break;
				}
			}
		}
	}
	else if (blood_type == "O+") {
		//cout << "You can receive blood from the following types :" << "O+" << "O-" << endl;
		for (int i = 0; i < DRequst.size(); i++)
		{
			if (DRequst[i].type == "O+"|| DRequst[i].type == "O-") {
				Quantity = check_Quantity(DRequst, Quantity, i);
				if (Quantity == 0) {
					break;
				}
			}
		}
	}
	else if (blood_type == "O-") {
		//cout << "You can receive blood from the following types :" << "O-" << endl;
		for (int i = 0; i < DRequst.size(); i++)
		{
			if (DRequst[i].type == "O-") {
				Quantity = check_Quantity(DRequst, Quantity, i);
				if (Quantity) {
					break;
				}
			}
		}
	}
	else if (blood_type == "AB+") {
		//cout << "You can receive blood from all blood types :" << endl;
		for (int i = 0; i < DRequst.size(); i++)
		{
			Quantity = check_Quantity(DRequst, Quantity, i);
			if (Quantity == 0)
			{
				break;
			}
		}
	}
	else if (blood_type == "AB-") {
		//cout << "You can receive blood from the following types :" << "B-" << "A-" << "O-" << "AB-" << endl;
		for (int i = 0; i < DRequst.size(); i++)
		{
			if (DRequst[i].type == "A-"|| DRequst[i].type == "O-"|| DRequst[i].type == "B-"|| DRequst[i].type == "AB-") {
				Quantity = check_Quantity(DRequst, Quantity, i);
				if (Quantity == 0) {
					break;
				}
			}
		}
	}

	if (Quantity == 0)
	{
		cout << "Successfully completed, the request will be sent to the hospital" << endl;
	}
	else {
		cout << "We could not provide the necessary quantity, but we were able to provide "
			<< original_quantity - Quantity << " of the quantity , the request will be sent to the hospital" << endl;
	          //  10 - 2 =8      
	}
}

int Recipient::check_Quantity(vector<DonationRequest>DRequst, int Quantity, int i) {
	//             10          5
	if (stoi(DRequst[i].Quantity) > Quantity) {

		DRequst[i].Quantity = stoi(DRequst[i].Quantity) - Quantity;

		return 0; //return Quantity =0
	}//              5              10
	else if (stoi(DRequst[i].Quantity) < Quantity) {

		Quantity = Quantity - stoi(DRequst[i].Quantity);
		//delete DRequst[i]
		DRequst.erase(DRequst.begin() + i);
		return Quantity;
	}
	else // 5 == 5
	{
		//delete DRequst[i]
		DRequst.erase(DRequst.begin() + i);
		return 0;//return Quantity =0
	}
}

Recipient::~Recipient() {

}

bool Recipient::CheckHospital(string hospital)
{
	
		int nameLength = hospital.length();
		for (int i = 0; i < nameLength; i++)
		{
			if (isalpha(hospital[i]))
			{
				return true;
			}
			else
				return false;
		}
	

}

bool Recipient::CheckDoctor(string case_doctor)
{

	int nameLength = case_doctor.length();
	for (int i = 0; i < nameLength; i++)
	{
		if (isalpha(case_doctor[i]))
		{
			return true;
		}
		else
			return false;
	}


}