#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void signUp();
void signIn();

class Users
{
public:
	Users();
	~Users();

	void setUser(string login, string name);

	string getUserLogin() const;
	string getUserName() const;

private:
	
	string userLogin;
	string userName;
	//Динамическое выделение памяти
	//string* userLogin = new string;
	//string* userName = new string;
};