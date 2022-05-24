#pragma once
class Parent
{
public:
	Parent();
	void Register();
	void Login();
	void Update();
	void Delete_Account();
	bool PasswordValidator(string password);
	~Parent();
};

