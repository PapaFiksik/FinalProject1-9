#include "users.h"

using namespace std;


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
			userSave(login, name, password);
			cout << "����� ������������ ������� ���������������. ����� ���������� � ���, " << name << endl;
			break;
		}
		else {
			cout << "������ �� ���������. ��������� �������" << endl;
		}
	}
}

/*
users::users(string login, string name, string password) {
	userLogin = login;
	userName = name;
	userPassword = password;
}*/