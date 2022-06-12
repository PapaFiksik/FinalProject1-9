/*
регистрация пользователей - логин, пароль, имя
вход в чат по логину/паролю
отправка сообщений конкретному пользователю
обмен сообщениями между всеми пользователями чата одновременно
Дополнительно можно реализовать обработку исключений и использование шаблонов.
*/
#include "users.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "rus"); // почему не принимает русский язык? Нельзя использовать русский при вводе
	bool work = true;

	while (work) {

		cout << "1 - Вход. 2 - Регистрация. 3 - Справка. 0 - Выход." << endl;
		short userChoice;
		cin >> userChoice;

		switch (userChoice)
		{
		case 1:
			system("cls");
			cout << "Вход" << endl;
			//signIn();
			break;

		case 2:
			system("cls");
			cout << "Регистрация новго пользователя" << endl;
			signUp();
			break;

		case 3:
			system("cls");
			cout << "Справка" << endl;
			break;

		case 0:
			cout << "Выход" << endl;
			work = false;
			break;

		default:
			cout << "Введено неверное значение." << endl;
			break;
		}
	}
	return 0;
}