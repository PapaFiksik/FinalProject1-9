/*
����������� ������������� - �����, ������, ��� - ������
���� � ��� �� ������/������ - �������� ������
�������� ��������� ����������� ������������
����� ����������� ����� ����� �������������� ���� ������������
������������� ����� ����������� ��������� ���������� � ������������� ��������.
*/
#include <windows.h>
#include "users.h"
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	bool work = true;

	while (work) {
		cout << "1 - ����. 2 - �����������. 3 - �������. 0 - �����." << endl;
		short userChoice;
		cin >> userChoice;

		switch (userChoice) {
		case 1:
			system("cls");
			cout << "����" << endl;
			signIn();
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