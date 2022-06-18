/*
регистрация пользователей - логин, пароль, имя - ГОТОВО
вход в чат по логину/паролю - ГОТОВО
отправка сообщений конкретному пользователю
обмен сообщениями между всеми пользователями чата одновременно
Дополнительно можно реализовать обработку исключений и использование шаблонов.
Добавить обработку исключения невозможности сохранить файл в user.cpp->signUp().
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


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char userChoice = 0;

	while (work) {
		cout << "--------------- Главное меню ---------------" << endl << "1 - Вход. 2 - Регистрация. 3 - Справка. 0 - Выход из программы." << endl;

		cin >> userChoice;
		cin.ignore(256, '\n'); //игнорирем символы, которые находятся после пробела

		switch (userChoice) {
		case '1':
			system("cls");
			cout << "---------- Вход в личный кабинет ----------" << endl;
			signIn();
			if (authorisation) {
				userAuthorized();
			}

			break;

		case '2':
			system("cls");
			cout << "---------- Регистрация новго пользователя (Символы после пробела - игнорируются) ----------" << endl;
			signUp();
			if (authorisation) {
				cout << "Новый пользователь успешно зарегистрирован. ";
				userAuthorized();
			}
			break;

		case '3':
			system("cls");
			cout << "---------- Справка ----------" << endl;
			break;

		case '0':
			system("cls");
			cout << "---------- Выход из программы ----------" << endl;
			work = false;
			break;

		default:
			cout << "Введено неверное значение." << endl;
			break;
		}
	}

	return 0;
}

void userAuthorized() {
	system("cls");
	bool chat = true;
	char userChoice1 = 0;

	while (chat) {
		cout << "---------- Добро пожаловать в личный кабинет, " << user.getUserName() << ". ----------" << endl;
		cout << "1 - Чат с одним пользователем. 2 - Общий чат. 3 - Вывести новые личные сообщения. 0 - Выход из чата." << endl;
		cin >> userChoice1;
		cin.ignore(256, '\n');

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
			cout << "---------- Выход из личного кабинета ----------" << endl;
			authorisation = false;
			chat = false;
			break;

		default:
			cout << "Введено неверное значение." << endl;
			break;
		}
	}
}

void singleChat() {
	cout << "Выберите пользователя" << endl;
	getAllUsers();
}

void multipleChat() {
	string from, to, message;
	from = user.getUserName();
	to = "all";
	cout << "---------- Общий чат ----------" << endl;
	cout << "Введите сообщение. Enter - отправить. Введите 0 для выхода." << endl;

	while (message != "0") {
		getline(cin, message);

		if (message != "0") {
			sendMessage(from, to, message);
		}
	}
}