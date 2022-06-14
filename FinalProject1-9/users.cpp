#include "users.h"
using namespace std;
extern bool authorisation;
extern Users user;

Users::Users() {
}

Users::~Users() {
}

void Users::setUser(string login, string name) {
	userLogin = login;
	userName = name;
}

string Users::getUserLogin() const {
	return userLogin;
}

string Users::getUserName() const {
	return userName;
}






void signUp() {
	string login, name, password, passwordConfirm;

	cout << "Ведите логин" << endl;
	cin >> login;
	cout << "Ведите имя" << endl;
	cin >> name;

	for (int i = 0; i < 2; i++) {
		cout << "Ведите пароль" << endl;
		cin >> password;
		cout << "Повторите пароль" << endl;
		cin >> passwordConfirm;
		if (password == passwordConfirm) {
			ofstream logfile("logfile.txt", ios_base::app); //запись в конец файла
			logfile << login << " " << name << " " << password << endl;
			logfile.close();
			break;
		}
		else if (i == 0) {
			cout << "Пароли не совпадают. Повторите попытку" << endl;
		}
		else {
			cout << "В регистрации отказано" << endl;
		}
	}
}

void signIn() {
	string tempLogin, tempPassword;
	cout << "Ведите логин" << endl;
	cin >> tempLogin;
	cout << "Ведите пароль" << endl;
	cin >> tempPassword;

	ifstream logfile("logfile.txt", ios_base::in); //открыть только для чтения
	string str, login, name, password, answer;

	if (logfile.is_open()) {
		for (getline(logfile, str); !logfile.eof(); getline(logfile, str)) { //считываем слова построчно из файла
			login = str.substr(0, str.find(" "));
			name = str.substr(str.find(" ")+1, str.find_last_of(" ") - str.find(" ") - 1);
			password = str.substr(str.find_last_of(" ")+1);

			if (login == tempLogin) { //если логины совпадают
				if (password == tempPassword) { //если пароли совпадают - заходим в систему
					user.setUser(login, name); // заполняем класс user
					authorisation = true;
					break;
				}
				else {
					cout << "Неверный пароль." << endl;
					break;
				}
			}
		}
		if (authorisation == false) {
			cout << "Пользователь не найден." << endl;
		}
	}
	else { //если файл не открыт
		cout << "Файл с данными пользователей недоступен!" << endl; //сообщить об этом
	}

	cout << answer;
}