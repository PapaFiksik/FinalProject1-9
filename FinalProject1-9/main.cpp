/*
����������� ������������� - �����, ������, ��� - ������
���� � ��� �� ������/������ - �������� ������
�������� ��������� ����������� ������������
����� ����������� ����� ����� �������������� ���� ������������
������������� ����� ����������� ��������� ���������� � ������������� ��������.
*/
#include "users.h"
#include <windows.h>

using namespace std;

bool work = true;
bool authorisation = false;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (work) {
		cout << "1 - ����. 2 - �����������. 3 - �������. 0 - �����." << endl;
		short userChoice;
		cin >> userChoice;

		switch (userChoice) {
		case 1:
			system("cls");
			cout << "����" << endl;
			signIn();
			if (authorisation) {
				//cout << user.getUserLogin() << " " << user.getUserName() << endl;
				//chat();
			}
			break;

		case 2:
			system("cls");
			cout << "����������� ����� ������������" << endl;
			signUp();
			break;

		case 3:
			system("cls");
			cout << "�������" << endl;
			break;

		case 0:
			cout << "�����" << endl;
			work = false;
			break;

		default:
			cout << "������� �������� ��������." << endl;
			break;
		}
	}

	return 0;
}