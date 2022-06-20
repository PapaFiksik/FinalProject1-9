/*
регистрация пользователей - логин, пароль, имя - ГОТОВО
вход в чат по логину/паролю - ГОТОВО
отправка сообщений конкретному пользователю - ГОТОВО
обмен сообщениями между всеми пользователями чата одновременно - ГОТОВО
Дополнительно можно реализовать обработку исключений и использование шаблонов.
ДОБАВИТЬ ОБРАБОТКУ ИСКЛЮЧЕНИЯ, когда невозможно сохранить файл в user.cpp->signUp().
ДОБАВИТЬ ЗАПРЕТ НА РЕГИСТРАЦИЮ с уже имеющимся логином user.cpp->signUp().
ДОБАВИТЬ ОБРАБОТКУ ИСКЛЮЧЕНИЯ, когда невозможно отправить сообщение user.cpp->sendMessage().
ДОБАВИТЬ ОБРАБОТКУ ИСКЛЮЧЕНИЯ, когда пользователь вводит огромное число или команду без цифр user.cpp->getNewMessages().
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


int main() { // ГЛАВНОЕ МЕНЮ
	SetConsoleCP(1251); // Русская локализация.
	SetConsoleOutputCP(1251); // Русская локализация.
	char userChoice_work = 0;

	while (work) {
		cout << "--------------- Главное меню ---------------" << endl;
		cout << "1 - Вход. 2 - Регистрация. 3 - Справка. 0 - Выход из программы." << endl;

		cin >> userChoice_work;
		cin.ignore(256, '\n'); // Игнорируем символы которые находятся после пробела.

		switch (userChoice_work) {
		case '1':
			system("cls");
			cout << "---------- Вход в личный кабинет ----------" << endl;
			signIn();
			if (authorisation) { // Если авторизация прошла успешно - переходим в личный кабинет.
				userAuthorized();
			}
			break;

		case '2':
			system("cls");
			cout << "---------- Регистрация новго пользователя (Символы после пробела - игнорируются) ----------" << endl;
			signUp();
			if (authorisation) { // Если регистрация прошла успешно - переходим в личный кабинет.
				cout << "Новый пользователь успешно зарегистрирован. ";
				userAuthorized();
			}
			break;

		case '3':
			system("cls");
			cout << "---------- Справка ----------" << endl;
			cout << "Проект подготовлен специально для SkillFactory." << endl;
			cout << "Проект сделал Григорий Прозоров, поток: CPLUS_19, курс: Разработчик на С++, школа: SkillFactory." << endl << endl;
			cout << "Более подробная информация о программе находится в Readme." << endl;
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

void userAuthorized() { // ЛИЧНЫЙ КАБИНЕТ ПОЛЬЗОВАТЕЛЯ
	system("cls");
	bool chat = true;
	char userChoice_chat = 0;

	while (chat) {
		cout << "---------- Добро пожаловать в личный кабинет, " << user.getUserName() << ". ----------" << endl;
		cout << "1 - Чат с одним пользователем. 2 - Общий чат. 0 - Выход из чата." << endl;
		cin.clear();
		cin >> userChoice_chat;
		cin.ignore(256, '\n'); // Игнорируем символы которые находятся после пробела.

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

void singleChat() { // ПРИВАТНЫЙ ЧАТ
	system("cls");
	cout << "---------- Выбор пользователя для чата ----------" << endl;
	string from, to, message;
	from = user.getUserLogin();
	to = getUsersChoise();

	if (to != "") {
		system("cls");
		cout << "---------- Приватный чат с " << to << " ----------" << endl;
		cout << "Введите сообщение. Enter - отправить. 0 - для выхода. /w15 - вывести (15) предыдущих сообщений" << endl;
		getNewMessages(to, "/w10"); // Получаем 10 последних сообщений

		while (message != "0") {
			cout << from << ": ";
			getline(cin, message);

			if (message.find("/w") == 0) { // Выводим указанное пользователем кол-во сообщений
				system("cls");
				cout << "---------- Приватный чат с " << to << " ----------" << endl;
				cout << "Введите сообщение. Enter - отправить. 0 - для выхода. /w15 - вывести (15) предыдущих сообщений" << endl;
				getNewMessages(to, message);
			}
			else if (message != "0") {
				system("cls");
				cout << "---------- Приватный чат с " << to << " ----------" << endl;
				cout << "Введите сообщение. Enter - отправить. 0 - для выхода. /w15 - вывести (15) предыдущих сообщений" << endl;
				sendMessage(from, to, message);
				getNewMessages(to, "/w10"); // Получаем 10 последних сообщений
			}
		}
	}
}

void multipleChat() { // ОБЩИЙ ЧАТ
	system("cls");
	cout << "---------- Общий чат ----------" << endl;
	cout << "Введите сообщение. Enter - отправить. 0 - для выхода. /w15 - вывести (15) предыдущих сообщений" << endl;
	string from, to, message;
	from = user.getUserLogin();
	to = "all";
	getNewMessages("", "/w10"); // Получаем 10 последних сообщений

	while (message != "0") {
		cout << from << ": ";
		getline(cin, message);

		if (message.find("/w") == 0) { // Выводим указанное пользователем кол-во сообщений
			system("cls");
			cout << "---------- Общий чат ----------" << endl;
			cout << "Введите сообщение. Enter - отправить. 0 - для выхода. /w15 - вывести (15) предыдущих сообщений" << endl;
			getNewMessages("", message);
		}
		else if (message != "0") {
			system("cls");
			cout << "---------- Общий чат ----------" << endl;
			cout << "Введите сообщение. Enter - отправить. 0 - для выхода. /w15 - вывести (15) предыдущих сообщений" << endl;
			sendMessage(from, to, message);
			getNewMessages("", "/w10"); // Получаем 10 последних сообщений
		}
	}
}