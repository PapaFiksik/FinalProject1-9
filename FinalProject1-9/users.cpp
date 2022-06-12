#include "users.h"
using namespace std;


void signUp() {
	string login, name, password, passwordConfirm;

	cout << "Ведите логин" << endl;
	cin >> login;
	cout << "Ведите имя" << endl;
	cin >> name;

	while (1) {
		cout << "Ведите пароль" << endl;
		cin >> password;
		cout << "Повторите пароль" << endl;
		cin >> passwordConfirm;
		if (password == passwordConfirm) {
			userSave(login, name, password);
			cout << "Новый пользователь успешно зарегистрирован. Добро пожаловать в чат, " << name << endl;
			break;
		}
		else {
			cout << "Пароли не совпадают. Повторите попытку" << endl;
		}
	}
}

void signIn() {
	string login, password;
	cout << "Ведите логин" << endl;
	cin >> login;
	cout << "Ведите пароль" << endl;
	cin >> password;
	cout << userSearch(login, password);
}