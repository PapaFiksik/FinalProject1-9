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

void signIn() {
	string login, password;
	cout << "������ �����" << endl;
	cin >> login;
	cout << "������ ������" << endl;
	cin >> password;
	cout << userSearch(login, password);
}