#include "Parent.h"
#include <iostream>
#include<string>
#include <fstream>
#include "assert.h"
using namespace std;

Parent::Parent() {
}
void Parent::Register() {
	cout << "WELCOME TO REGISTER PAGE " << endl;
	int id, age;
	string name, mail, password, gender, blood_type;


	cout << "Enter Your ID : " << endl;         cin >> id;
	cout << "Enter Your Age : " << endl;        cin >> age;
	cout << "Enter Your Name : " << endl;       cin >> name;
	cout << "Enter Your Mail : " << endl;       cin >> mail;
	cout << "Enter Your Password : " << endl;   cin >> password;
	// check password 
	while (!PasswordValidator(password))
	{
		cout << "Invalid Password" << endl;
		cout << "Enter valid Password : " << endl;   cin >> password;
	}
	if (PasswordValidator(password))
		cout << "Valid Password" << endl;

	cout << "Enter Your Gender : " << endl;     cin >> gender;
	cout << "Enter Your BLood type : " << endl; cin >> blood_type;

	fstream file;
	file.open("data.txt", ios::app);
	//file.is_open();
	file << id << " , " << " , " << age << " , " << name << " , " << mail << " , " << password << " , " << gender << " , ";
	file << blood_type << endl ;

	file.close();
}
void Parent::Login() {

}
void Parent::Update() {

}
void Parent::Delete_Account() {

}
bool Parent::PasswordValidator(string password) {

	if (!((password.length() >= 3) &&
		(password.length() <= 10)))
		return false;

	if (password.find(" ") !=
		std::string::npos)
		return false;

	else
		return true;


}
Parent::~Parent() {
}