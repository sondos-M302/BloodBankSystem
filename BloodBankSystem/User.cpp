#include "User.h"
#include "Donor.h"
#include "Recipient.h"

using namespace std;

User::User() {

}
User::User(string id, string age, string index,string name, string mail, string password, string gender, string blood_type) {
      this->id = id;
	  this->age = age;
	  this->index= index;
	  this->name = name;
	  this->mail = mail;
	  this->password = password;
	  this->gender = gender; 
	  this->blood_type= blood_type;
}
void User::Register() {
	cout << "WELCOME TO REGISTER PAGE " << endl;

	cout << "Enter Your ID : " << endl;          cin >> id;
	cout << "Enter Your Age : " << endl;         cin >> age;
	//check age is valid
	while (!AgeValidator(age))
	{
		cout << "Invalid Age" << endl;
		cout << "Enter valid Age : " << endl;   cin >> age;
	}
	if (AgeValidator(age))
	{
		cout << "Valid Age" << endl;
	}

	cout << "Enter Your Name : " << endl;        cin >> name;
	//check name valid
	while (!NameValidator(name))
	{
		cout  << "Enter a name with characters only.\n " << endl;
		cout << "Enter valid name : " << endl;   cin >> name;

	}
	if (NameValidator(name)) {
		cout << name << " : "
			<< " is valid" << endl;
	}

	cout << "Enter Your Mail : " << endl;        cin >> mail;
	// check mail is valid 
	while (!MailValidator(mail))
	 {
		cout << mail << " : "<< "invalid" << endl;
		cout << "Enter valid mail : " << endl;   cin >> mail;

	}
	if(MailValidator(mail)) {
		cout << mail << " : "
			<< "valid" << endl;
	}

	cout << "Enter Your Password : " << endl;    cin >> password;
	// check password is valid
	while (!PasswordValidator(password))
	{
		cout << "Invalid Password" << endl;
		cout << "Enter valid Password : " << endl;   cin >> password;
	}
	if (PasswordValidator(password))
	{
		cout << "Valid Password" << endl;
	}


	cout << "Enter Your Gender : " << endl;      cin >> gender;
	// check gender is valid
	while (!GenderValidator(gender))
	{
		cout << "Invalid gender" << endl;
		cout << "Enter valid gender : " << endl;   cin >> gender;
	}
	if (GenderValidator(gender))
	{
		cout << "Valid gender" << endl;
	}


	cout << "Enter Your BLood type : " << endl;  cin >> blood_type;
	//check blood type
	while (!BloodtypeValid(blood_type))
	{
		cout << blood_type << " : "<< "invalid" << endl;
		cout << "Enter valid blood type : " << endl;   cin >> blood_type;

	}
	if (BloodtypeValid(blood_type))
	{
		cout << blood_type << " : "
			<< "valid" << endl;
	}
}

bool User::Login(string Umail, string Upassword) {
	
	return true;
}

void User::Update() {
}

void User::Delete_Account() {

}

User::~User() {

}

bool User::PasswordValidator(string password) {

	if (!((password.length() >= 3) &&
		(password.length() <= 10)))
		return false;

	if (password.find(" ") !=
		std::string::npos)
		return false;

	else
		return true;
}

bool User::AgeValidator(string  age)
{
	if (!(stoi(age) > 17) && (stoi(age) < 60))
		return false;
	else
		return true;
}

bool User::MailValidator(string mail)
{
	while (true)
	{
		// Regular expression definition
		const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
		// Match the string pattern
		// with regular expressio
		return regex_match(mail, pattern);
	}
	

}

bool User::GenderValidator(string gender)
{
	if ((gender == "M"|| gender == "m")||( gender == "F"|| gender == "f"))
		return true;
	else
		return false;
	
}

bool User::BloodtypeValid(string blood_type)
{
	//blood_type = toupper(blood_type);
	if ((blood_type == "A+") || (blood_type == "A-")
		|| (blood_type == "B+") || (blood_type == "B-")
		|| (blood_type == "AB+") || (blood_type == "AB-")
		|| (blood_type == "O+") || (blood_type == "O-"))
		return true;
	else
		return false;
}

bool User::NameValidator(string name)
{
	int nameLength = name.length();
	for (int i = 0; i < nameLength; i++)
	{
		if (isalpha(name[i]))
		{
			return true;
		}
		else
			return false;
	}
}
