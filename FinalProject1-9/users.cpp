#include "users.h"
using namespace std;
extern bool authorisation;

Users::Users(string login, string name) {
	userLogin = login;
	userName = name;
	cout << "����������� ������" << endl;
}

Users::~Users()
{
	cout << "���������� ������" << endl;
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

	while (1) {
		cout << "������ ������" << endl;
		cin >> password;
		cout << "��������� ������" << endl;
		cin >> passwordConfirm;
		if (password == passwordConfirm) {
			ofstream logfile("logfile.txt", ios_base::app); //������ � ����� �����
			logfile << login << " " << name << " " << password << endl;
			logfile.close();
			cout << "����� ������������ ������� ���������������. ����� ���������� � ���, " << name << endl;
			break;
		}
		else {
			cout << "������ �� ���������. ��������� �������" << endl;
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
		answer = "������������ �� ������.\n";

		for (getline(logfile, str); !logfile.eof(); getline(logfile, str)) { //��������� ����� ��������� �� �����
			login = str.substr(0, str.find(" "));
			name = str.substr(str.find(" ")+1, str.find_last_of(" ") - str.find(" ") - 1);
			password = str.substr(str.find_last_of(" ")+1);
			cout << login << " " << name << " " << password << " " << endl;
			if (login == tempLogin) { //���� ������ ���������
				if (password == tempPassword) { //���� ������ ��������� - ������� � �������
					answer = "����� ���������� � ���, " + name + ".\n";
					////////////����� �������� � ������������ �����. ����� ����������. ���� ������� ��� � main? ��� ������?
					static Users user(login, name); //������ ����� � �������������� �������������
					cout << user.getUserLogin() << " " << user.getUserName() << endl;
					////////////

					authorisation = true;
					break;
				}
				else {
					answer = "�������� ������.\n";
					break;
				}
			}
		}
	}
	else { //���� ���� �� ������
		answer = "���� � ������� ������������� ����������!\n"; //�������� �� ����
	}

	cout << answer;
}