/*
����������� ������������� - �����, ������, ��� - ������
���� � ��� �� ������/������ - ������
�������� ��������� ����������� ������������
����� ����������� ����� ����� �������������� ���� ������������
������������� ����� ����������� ��������� ���������� � ������������� ��������.
*/
#include "users.h"
#include <windows.h>

using namespace std;

bool work = true;
bool authorisation = false;
Users user;

void chat();

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	short userChoice;

	while (work) {
		cout << "--------------- ������� ���� ---------------" << endl << "1 - ����. 2 - �����������. 3 - �������. 0 - �����." << endl;

		cin >> userChoice;

		switch (userChoice) {
		case 1:
			system("cls");
			cout << "---------- ���� ----------" << endl;
			signIn();
			if (authorisation) {
				chat();
			}

			break;

		case 2:
			system("cls");
			cout << "---------- ����������� ����� ������������ ----------" << endl;
			signUp();
			if (authorisation) {
				cout << "����� ������������ ������� ���������������. ";
				chat();
			}
			break;

		case 3:
			system("cls");
			cout << "---------- ������� ----------" << endl;
			break;

		case 0:
			cout << "---------- ����� ----------" << endl;
			work = false;
			break;

		default:
			cout << "������� �������� ��������." << endl;
			break;
		}
	}

	return 0;
}

void chat() {
	bool chat = true;
	short userChoice;

	while (chat) {
		system("cls");
		cout << "---------- ����� ���������� � ���, " << user.getUserName() << ". ----------" << endl;
		cout << "1 - ��� � ����� �������������. 2 - ����� ���. 3 - ��������� ����� ���������. 0 - �����." << endl;
		cin >> userChoice;

		switch (userChoice) {
		case 1:

			break;

		case 2:

			break;

		case 3:

			break;

		case 0:
			cout << "---------- ����� ----------" << endl;
			chat = false;
			break;

		default:
			cout << "������� �������� ��������." << endl;
			break;
		}
	}
}