#include "users.h"

using namespace std;
extern bool authorisation;
extern Users user;

Users::Users() {
}

Users::~Users() {
}

void Users::setUser(string login, string name) {
	userLogin = login;
	userName = name;
}

string Users::getUserLogin() const {
	return userLogin;
}

string Users::getUserName() const {
	return userName;
}






void signUp() {
	string tempLogin, tempName, tempPassword, tempPasswordConfirm;

	cout << "������ �����" << endl;
	cin >> tempLogin;
	cin.ignore(256, '\n');

	ifstream logfile(("logfile.txt"), ios_base::in); // ��������� ���� � �������� ������ ��� ������.

	if (logfile.is_open()) {
		string str, login;
		int count = 1, userChoise;

		while (getline(logfile, str)) { // ��������� �� ������� �������������
			login = str.substr(0, str.find(" "));
			if (login == tempLogin) { // ���� ����� ��������������� - ����� � �����������
				cout << "������ ����� ��� ��������������� � �������!" << endl;
				return;
				logfile.close();
			}

		}
	}
	else { // ���� ���� �� ������, �� �������� �� ����.
		cout << "���� � �������������� ����������!" << endl;
		return;
	}

	cout << "������ ���" << endl;
	cin >> tempName;
	cin.ignore(256, '\n');
	try {
		for (int i = 0; i < 2; i++) {
			cout << "������ ������" << endl;
			cin >> tempPassword;
			cin.ignore(256, '\n');
			cout << "��������� ������" << endl;
			cin >> tempPasswordConfirm;
			cin.ignore(256, '\n');
			if (tempPassword == tempPasswordConfirm) {
				ofstream logfile("logfile1.txt", ios_base::app); // ��������� ���� � ������� � ����� �����.
				if (logfile) {
					logfile << tempLogin << " " << tempName << " " << tempPassword << endl;
					logfile.close();
					user.setUser(tempLogin, tempName);
					authorisation = true;
					break;
				}
				else {
					throw fileErrors();
				}
			}
			else if (i == 0) {
				cout << "������ �� ���������. ��������� �������" << endl;
			}
			else {
				cout << "������ �� ���������. � ����������� ��������" << endl;
			}
		}
	}
	catch (exception& excep)
	{
		cout << excep.what() << endl;
	}
}

void signIn() {
	string tempLogin, tempPassword;
	cout << "������ �����" << endl;
	cin >> tempLogin;
	cin.ignore(256, '\n');
	cout << "������ ������" << endl;
	cin >> tempPassword;
	cin.ignore(256, '\n');

	ifstream logfile("logfile.txt", ios_base::in); // ��������� ���� � �������������� ������ ��� ������.
	string str, login, name, password;

	if (logfile.is_open()) {
		for (getline(logfile, str); !logfile.eof(); getline(logfile, str)) { // ��������� ����� �� ����� ���������.
			login = str.substr(0, str.find(" "));
			name = str.substr(str.find(" ")+1, str.find_last_of(" ") - str.find(" ") - 1);
			password = str.substr(str.find_last_of(" ")+1);

			if (login == tempLogin) { // ���� ������ ��������� - ��������� ������.
				if (password == tempPassword) { // ���� ������ ��������� - ������� � �������.
					user.setUser(login, name); // ��������� ����� user.
					authorisation = true;
					break;
				}
				else {
					cout << "�������� ������." << endl;
					break;
				}
			}
		}
		if (logfile.eof()) {
			cout << "������������ �� ������." << endl;
		}

		logfile.close();
	}
	else { // ���� ���� �� ������, �� �������� �� ����.
		cout << "���� � ������� ������������� ����������!" << endl;
	}
}



string getUsersChoise() {
	ifstream logfile(("logfile.txt"), ios_base::in); // ��������� ���� � �������� ������ ��� ������.

	if (logfile.is_open()) {
		string str, login;
		int count = 1, userChoise;

		while (getline(logfile, str)) { // ������� ������ �������������
			login = str.substr(0, str.find(" "));
			if (login == user.getUserLogin()) { // �� ������� ����� ��������������� ������������
				continue;
			}
			cout << count++ << " " << login << endl;
		}
		
		logfile.clear(); // ��������� ������� � ������ �����.
		logfile.seekg(0, std::ios::beg);

		cout << "�������� ������������ (������� �����). 0 - ��� ������." << endl;
		cin >> userChoise;
		cin.ignore(256, '\n');
		cin.clear();
		if (userChoise > 0 && userChoise < count) {
			count = 1;
			string to;
			while (getline(logfile, str)) {
				if (str.substr(0, str.find(" ")) == user.getUserLogin()) { // �� ������ ������ � �������������� �������������
					continue;
				}
				else if (count == userChoise) {
					to = str.substr(0, str.find(" "));
					break;
				}
				count++;
			}


			logfile.close();
			return to;
		}
		else if (userChoise == 0) {
			logfile.close();
			return "";
		}
		else {
			logfile.close();
			cout << "������� �������� ��������." << endl;
			return "";
		}
	}
	else { // ���� ���� �� ������, �� �������� �� ����.
		cout << "���� � �������������� ����������!";
		return "";
	}
}

void sendMessage(string from, string to, string message) {
	ofstream messagesfile;
	try {
		if (to == "all") {
			messagesfile.open("messagesGlobal.txt", ios_base::app); // ������ � ����� �����.
		}
		else {
			if (from > to) {
				messagesfile.open("messages" + from + to + ".txt", ios_base::app); // ������ � ����� �����.
			}
			else {
				messagesfile.open("messages" + to + from + ".txt", ios_base::app); // ������ � ����� �����.
			}
		}
		if (messagesfile) {
			messagesfile << from << ": " << message << endl;
			messagesfile.close();
		}
		else {
			throw fileErrors();
		}
	}
	catch (exception& excep)
	{
		cout << excep.what() << endl;
	}
}

void getNewMessages(string to, string message) {
	string numberOfMessages;
	if (message.size() <= 2 || message.size() >= 6) { // �������� ������������ �������
		cout << "������� ������� �������!" << endl;
		return;
	}

	for (int i = 2; i < message.size(); ++i) { // ����� ������� ��������� ���� ���������.
		if (message[i] >= '0' && message[i] <= '9') {
			numberOfMessages += message[i];
		}
		else { // ������� �� ������� ���� ���� ������ � �������.
			cout << "������� ������� �������!" << endl;
			return;
		}
	}

	int num = stoi(numberOfMessages); // ��������� ����� � ��������� ������.
	
	ifstream messagesfile;
	if (to == "") {  // ��������� ����� ��� ��������� ����?
		messagesfile.open("messagesGlobal.txt", ios_base::in); // ��������� ���� � ����������� ������ ��� ������.
	}
	else {
		string from = user.getUserLogin();
		if (from > to) {
			messagesfile.open("messages" + from + to + ".txt", ios_base::app); // ������ � ����� �����.
		}
		else {
			messagesfile.open("messages" + to + from + ".txt", ios_base::app); // ������ � ����� �����.
		}
	}

	if (messagesfile.is_open()) {
		string str;
		int allLines = 0, startLine = 0;

		while (getline(messagesfile, str)) { // ������� ������� ����� ����� � �����.
			allLines++;
		}
		startLine = allLines - num;
		startLine >= 0 ? startLine : startLine = 0; // ������� � ����� ������ ������ �������� ���������.

		messagesfile.clear(); // ��������� ������� � ������ �����.
		messagesfile.seekg(0, std::ios::beg);

		for (int i = 0; i < allLines; i++) { // ������� ������ ���-�� ���������.
			getline(messagesfile, str);
			if (i == startLine) {
				cout << str << endl;
				startLine++;
			}
		}
		
		messagesfile.close();
	}
	else { // ���� ���� �� ������, �� �������� �� ����.
		cout << "���� � ����������� ����������!" << endl;
	}
}