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
	string login, name, password, passwordConfirm;

	cout << "������ �����" << endl;
	cin >> login;
	cout << "������ ���" << endl;
	cin >> name;

	for (int i = 0; i < 2; i++) {
		cout << "������ ������" << endl;
		cin >> password;
		cout << "��������� ������" << endl;
		cin >> passwordConfirm;
		if (password == passwordConfirm) {
			ofstream logfile("logfile.txt", ios_base::app); //������ � ����� �����
			logfile << login << " " << name << " " << password << endl;
			logfile.close();
			break;
		}
		else if (i == 0) {
			cout << "������ �� ���������. ��������� �������" << endl;
		}
		else {
			cout << "� ����������� ��������" << endl;
		}
	}
}

void signIn() {
	string tempLogin, tempPassword;
	cout << "������ �����" << endl;
	cin >> tempLogin;
	cout << "������ ������" << endl;
	cin >> tempPassword;

	ifstream logfile("logfile.txt", ios_base::in); //������� ������ ��� ������
	string str, login, name, password, answer;

	if (logfile.is_open()) {
		for (getline(logfile, str); !logfile.eof(); getline(logfile, str)) { //��������� ����� ��������� �� �����
			login = str.substr(0, str.find(" "));
			name = str.substr(str.find(" ")+1, str.find_last_of(" ") - str.find(" ") - 1);
			password = str.substr(str.find_last_of(" ")+1);

			if (login == tempLogin) { //���� ������ ���������
				if (password == tempPassword) { //���� ������ ��������� - ������� � �������
					user.setUser(login, name); // ��������� ����� user
					authorisation = true;
					break;
				}
				else {
					cout << "�������� ������." << endl;
					break;
				}
			}
		}
		if (authorisation == false) {
			cout << "������������ �� ������." << endl;
		}
	}
	else { //���� ���� �� ������
		cout << "���� � ������� ������������� ����������!" << endl; //�������� �� ����
	}

	cout << answer;
}