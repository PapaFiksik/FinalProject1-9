#include "users.h"
using namespace std;
extern bool authorisation;

Users::Users(string login, string name) {
	userLogin = login;
	userName = name;
	cout << "Конструктор вызван" << endl;
}

Users::~Users()
{
	cout << "Деструктор вызван" << endl;
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

	while (1) {
		cout << "Ведите пароль" << endl;
		cin >> password;
		cout << "Повторите пароль" << endl;
		cin >> passwordConfirm;
		if (password == passwordConfirm) {
			ofstream logfile("logfile.txt", ios_base::app); //запись в конец файла
			logfile << login << " " << name << " " << password << endl;
			logfile.close();
			cout << "Новый пользователь успешно зарегистрирован. Добро пожаловать в чат, " << name << endl;
			break;
		}
		else {
			cout << "Пароли не совпадают. Повторите попытку" << endl;
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
		answer = "Пользователь не найден.\n";

		for (getline(logfile, str); !logfile.eof(); getline(logfile, str)) { //считываем слова построчно из файла
			login = str.substr(0, str.find(" "));
			name = str.substr(str.find(" ")+1, str.find_last_of(" ") - str.find(" ") - 1);
			password = str.substr(str.find_last_of(" ")+1);
			cout << login << " " << name << " " << password << " " << endl;
			if (login == tempLogin) { //если логины совпадают
				if (password == tempPassword) { //если пароли совпадают - заходим в систему
					answer = "Добро пожаловать в чат, " + name + ".\n";
					////////////класс создаётся и уничтожается сразу. Нужен постоянный. Надо создать его в main? или статик?
					static Users user(login, name); //создаём класс с авторизованным пользователем
					cout << user.getUserLogin() << " " << user.getUserName() << endl;
					////////////

					authorisation = true;
					break;
				}
				else {
					answer = "Неверный пароль.\n";
					break;
				}
			}
		}
	}
	else { //если файл не открыт
		answer = "Файл с данными пользователей недоступен!\n"; //сообщить об этом
	}

	cout << answer;
}