/*
����������� ������������� - �����, ������, ��� - ������
���� � ��� �� ������/������ - ������
�������� ��������� ����������� ������������
����� ����������� ����� ����� �������������� ���� ������������ - ������
������������� ����� ����������� ��������� ���������� � ������������� ��������.
�������� ��������� ����������, ����� ���������� ��������� ���� � user.cpp->signUp().
�������� ��������� ����������, ����� ���������� ��������� ��������� user.cpp->sendMessage().
�������� ��������� ����������, ����� ������������ ������ �������� ����� user.cpp->getNewMessages().
*/
#include "users.h"
#include <windows.h>

using namespace std;

bool work = true;
bool authorisation = false;
Users user;

void userAuthorized();
void singleChat();
void multipleChat();


int main() { // ������� ����
	SetConsoleCP(1251); // ������� �����������.
	SetConsoleOutputCP(1251); // ������� �����������.
	char userChoice = 0;

	while (work) {
		cout << "--------------- ������� ���� ---------------" << endl;
		cout << "1 - ����. 2 - �����������. 3 - �������. 0 - ����� �� ���������." << endl;

		cin >> userChoice;
		cin.ignore(256, '\n'); // ���������� ������� ������� ��������� ����� �������.

		switch (userChoice) {
		case '1':
			system("cls");
			cout << "---------- ���� � ������ ������� ----------" << endl;
			signIn();
			if (authorisation) { // ���� ����������� ������ ������� - ��������� � ������ �������.
				userAuthorized();
			}
			break;

		case '2':
			system("cls");
			cout << "---------- ����������� ����� ������������ (������� ����� ������� - ������������) ----------" << endl;
			signUp();
			if (authorisation) { // ���� ����������� ������ ������� - ��������� � ������ �������.
				cout << "����� ������������ ������� ���������������. ";
				userAuthorized();
			}
			break;

		case '3':
			system("cls");
			cout << "---------- ������� ----------" << endl;
			cout << "������ ����������� ���������� ��� SkillFactory." << endl;
			cout << "������ ������ �������� ��������, �����: CPLUS_19, ����: ����������� �� �++, �����: SkillFactory." << endl << endl;
			cout << "���������� �� ������������� ��������� ��������� � ReadMe." << endl;
			break;

		case '0':
			system("cls");
			cout << "---------- ����� �� ��������� ----------" << endl;
			work = false;
			break;

		default:
			cout << "������� �������� ��������." << endl;
			break;
		}
	}

	return 0;
}

void userAuthorized() { // ������ ������� ������������
	system("cls");
	bool chat = true;
	char userChoice1 = 0;

	while (chat) {
		cout << "---------- ����� ���������� � ������ �������, " << user.getUserName() << ". ----------" << endl;
		cout << "1 - ��� � ����� �������������. 2 - ����� ���. 3 - ������� ����� ������ ���������. 0 - ����� �� ����." << endl;
		cin >> userChoice1;
		cin.ignore(256, '\n'); // ���������� ������� ������� ��������� ����� �������.

		switch (userChoice1) {
		case '1':
			system("cls");
			singleChat();
			break;

		case '2':
			system("cls");
			multipleChat();
			break;

		case '3':
			system("cls");

			break;

		case '0':
			system("cls");
			cout << "---------- ����� �� ������� �������� ----------" << endl;
			authorisation = false;
			chat = false;
			break;

		default:
			cout << "������� �������� ��������." << endl;
			break;
		}
	}
}

void singleChat() { // ��������� ���
	cout << "�������� ������������" << endl;
	getAllUsers();
}

void multipleChat() { // ����� ���
	system("cls");
	cout << "---------- ����� ��� ----------" << endl;
	cout << "������� ���������. Enter - ���������. 0 - ��� ������. /w15 - ������� (15) ���������� ���������" << endl;
	string from, to, message;
	from = user.getUserName();
	to = "all";
	getNewMessages("/w10"); // �������� 10 ��������� ���������

	while (message != "0") {
		cout << from << ": ";
		getline(cin, message);

		if (message.find("/w") == 0) { // ������� ��������� ������������� ���-�� ���������
			system("cls");
			cout << "---------- ����� ��� ----------" << endl;
			cout << "������� ���������. Enter - ���������. 0 - ��� ������. /w15 - ������� (15) ���������� ���������" << endl;
			getNewMessages(message);
		}
		else if (message != "0") {
			system("cls");
			cout << "---------- ����� ��� ----------" << endl;
			cout << "������� ���������. Enter - ���������. 0 - ��� ������. /w15 - ������� (15) ���������� ���������" << endl;
			sendMessage(from, to, message);
			getNewMessages("/w10"); // �������� 10 ��������� ���������
		}
	}
}