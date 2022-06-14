/*
регистрация пользователей - логин, пароль, имя - ГОТОВО
вход в чат по логину/паролю - ГОТОВО
отправка сообщений конкретному пользователю
обмен сообщениями между всеми пользователями чата одновременно
Дополнительно можно реализовать обработку исключений и использование шаблонов.
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
		cout << "--------------- Главное меню ---------------" << endl << "1 - Вход. 2 - Регистрация. 3 - Справка. 0 - Выход." << endl;

		cin >> userChoice;

		switch (userChoice) {
		case 1:
			system("cls");
			cout << "---------- Вход ----------" << endl;
			signIn();
			if (authorisation) {
				chat();
			}

			break;

		case 2:
			system("cls");
			cout << "---------- Регистрация новго пользователя ----------" << endl;
			signUp();
			if (authorisation) {
				cout << "Новый пользователь успешно зарегистрирован. ";
				chat();
			}
			break;

		case 3:
			system("cls");
			cout << "---------- Справка ----------" << endl;
			break;

		case 0:
			cout << "---------- Выход ----------" << endl;
			work = false;
			break;

		default:
			cout << "Введено неверное значение." << endl;
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
		cout << "---------- Добро пожаловать в чат, " << user.getUserName() << ". ----------" << endl;
		cout << "1 - Чат с одним пользователем. 2 - Общий чат. 3 - Прочитать новые сообщения. 0 - Выход." << endl;
		cin >> userChoice;

		switch (userChoice) {
		case 1:

			break;

		case 2:

			break;

		case 3:

			break;

		case 0:
			cout << "---------- Выход ----------" << endl;
			chat = false;
			break;

		default:
			cout << "Введено неверное значение." << endl;
			break;
		}
	}
}