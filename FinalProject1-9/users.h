#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

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
};



void signUp();
void signIn();
int* getAllUsers();
void sendMessage(string from, string to, string message);
void getNewMessages(string message);