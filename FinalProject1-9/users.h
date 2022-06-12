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
	Users(string login, string name);
	~Users();

	string getUserLogin() const;
	string getUserName() const;

private:
	
	string userLogin;
	string userName;
	//Динамическое выделение памяти
	//string* userLogin = new string;
	//string* userName = new string;
};