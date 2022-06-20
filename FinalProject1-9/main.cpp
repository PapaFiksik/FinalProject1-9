/*
����������� ������������� - �����, ������, ��� - ������
���� � ��� �� ������/������ - ������
�������� ��������� ����������� ������������ - ������
����� ����������� ����� ����� �������������� ���� ������������ - ������
������������� ����� ����������� ��������� ���������� � ������������� ��������.
�������� ��������� ����������, ����� ���������� ��������� ���� � user.cpp->signUp().
�������� ������ �� ����������� � ��� ��������� ������� user.cpp->signUp().
�������� ��������� ����������, ����� ���������� ��������� ��������� user.cpp->sendMessage().
�������� ��������� ����������, ����� ������������ ������ �������� ����� ��� ������� ��� ���� user.cpp->getNewMessages().
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
	char userChoice_work = 0;

	while (work) {
		cout << "--------------- ������� ���� ---------------" << endl;
		cout << "1 - ����. 2 - �����������. 3 - �������. 0 - ����� �� ���������." << endl;

		cin >> userChoice_work;
		cin.ignore(256, '\n'); // ���������� ������� ������� ��������� ����� �������.

		switch (userChoice_work) {
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
			cout << "����� ��������� ���������� � ��������� ��������� � Readme." << endl;
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
	char userChoice_chat = 0;

	while (chat) {
		cout << "---------- ����� ���������� � ������ �������, " << user.getUserName() << ". ----------" << endl;
		cout << "1 - ��� � ����� �������������. 2 - ����� ���. 0 - ����� �� ����." << endl;
		cin.clear();
		cin >> userChoice_chat;
		cin.ignore(256, '\n'); // ���������� ������� ������� ��������� ����� �������.

		switch (userChoice_chat) {
		case '1':
			system("cls");
			singleChat();
			break;

		case '2':
			system("cls");
			multipleChat();
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
	system("cls");
	cout << "---------- ����� ������������ ��� ���� ----------" << endl;
	string from, to, message;
	from = user.getUserLogin();
	to = getUsersChoise();

	if (to != "") {
		system("cls");
		cout << "---------- ��������� ��� � " << to << " ----------" << endl;
		cout << "������� ���������. Enter - ���������. 0 - ��� ������. /w15 - ������� (15) ���������� ���������" << endl;
		getNewMessages(to, "/w10"); // �������� 10 ��������� ���������

		while (message != "0") {
			cout << from << ": ";
			getline(cin, message);

			if (message.find("/w") == 0) { // ������� ��������� ������������� ���-�� ���������
				system("cls");
				cout << "---------- ��������� ��� � " << to << " ----------" << endl;
				cout << "������� ���������. Enter - ���������. 0 - ��� ������. /w15 - ������� (15) ���������� ���������" << endl;
				getNewMessages(to, message);
			}
			else if (message != "0") {
				system("cls");
				cout << "---------- ��������� ��� � " << to << " ----------" << endl;
				cout << "������� ���������. Enter - ���������. 0 - ��� ������. /w15 - ������� (15) ���������� ���������" << endl;
				sendMessage(from, to, message);
				getNewMessages(to, "/w10"); // �������� 10 ��������� ���������
			}
		}
	}
}

void multipleChat() { // ����� ���
	system("cls");
	cout << "---------- ����� ��� ----------" << endl;
	cout << "������� ���������. Enter - ���������. 0 - ��� ������. /w15 - ������� (15) ���������� ���������" << endl;
	string from, to, message;
	from = user.getUserLogin();
	to = "all";
	getNewMessages("", "/w10"); // �������� 10 ��������� ���������

	while (message != "0") {
		cout << from << ": ";
		getline(cin, message);

		if (message.find("/w") == 0) { // ������� ��������� ������������� ���-�� ���������
			system("cls");
			cout << "---------- ����� ��� ----------" << endl;
			cout << "������� ���������. Enter - ���������. 0 - ��� ������. /w15 - ������� (15) ���������� ���������" << endl;
			getNewMessages("", message);
		}
		else if (message != "0") {
			system("cls");
			cout << "---------- ����� ��� ----------" << endl;
			cout << "������� ���������. Enter - ���������. 0 - ��� ������. /w15 - ������� (15) ���������� ���������" << endl;
			sendMessage(from, to, message);
			getNewMessages("", "/w10"); // �������� 10 ��������� ���������
		}
	}
}