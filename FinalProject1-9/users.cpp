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
	string tempLogin, tempName, tempPassword, tempPasswordConfirm;

	cout << "Ведите логин" << endl;
	cin >> tempLogin;
	cin.ignore(256, '\n');

	ifstream logfile(("logfile.txt"), ios_base::in); // Открываем файл с логинами только для чтения.

	if (logfile.is_open()) {
		string str, login;
		int count = 1, userChoise;

		while (getline(logfile, str)) { // Пробегаем по логинам пользователей
			login = str.substr(0, str.find(" "));
			if (login == tempLogin) { // Если логин зарегистрирован - отказ в регистрации
				cout << "Данный логин уже зарегистрирован в системе!" << endl;
				return;
				logfile.close();
			}

		}
	}
	else { // Если файл не открыт, то сообщаем об этом.
		cout << "Файл с пользователями недоступен!" << endl;
		return;
	}

	cout << "Ведите имя" << endl;
	cin >> tempName;
	cin.ignore(256, '\n');
	try {
		for (int i = 0; i < 2; i++) {
			cout << "Ведите пароль" << endl;
			cin >> tempPassword;
			cin.ignore(256, '\n');
			cout << "Повторите пароль" << endl;
			cin >> tempPasswordConfirm;
			cin.ignore(256, '\n');
			if (tempPassword == tempPasswordConfirm) {
				ofstream logfile("logfile1.txt", ios_base::app); // Открываем файл с записью в конец файла.
				if (logfile) {
					logfile << tempLogin << " " << tempName << " " << tempPassword << endl;
					logfile.close();
					user.setUser(tempLogin, tempName);
					authorisation = true;
					break;
				}
				else {
					throw fileErrors();
				}
			}
			else if (i == 0) {
				cout << "Пароли не совпадают. Повторите попытку" << endl;
			}
			else {
				cout << "Пароли не совпадают. В регистрации отказано" << endl;
			}
		}
	}
	catch (exception& excep)
	{
		cout << excep.what() << endl;
	}
}

void signIn() {
	string tempLogin, tempPassword;
	cout << "Ведите логин" << endl;
	cin >> tempLogin;
	cin.ignore(256, '\n');
	cout << "Ведите пароль" << endl;
	cin >> tempPassword;
	cin.ignore(256, '\n');

	ifstream logfile("logfile.txt", ios_base::in); // Открываем файл с пользователями только для чтения.
	string str, login, name, password;

	if (logfile.is_open()) {
		for (getline(logfile, str); !logfile.eof(); getline(logfile, str)) { // Считываем слова из файла построчно.
			login = str.substr(0, str.find(" "));
			name = str.substr(str.find(" ")+1, str.find_last_of(" ") - str.find(" ") - 1);
			password = str.substr(str.find_last_of(" ")+1);

			if (login == tempLogin) { // Если логины совпадают - проверяем пароли.
				if (password == tempPassword) { // Если пароли совпадают - заходим в систему.
					user.setUser(login, name); // Заполняем класс user.
					authorisation = true;
					break;
				}
				else {
					cout << "Неверный пароль." << endl;
					break;
				}
			}
		}
		if (logfile.eof()) {
			cout << "Пользователь не найден." << endl;
		}

		logfile.close();
	}
	else { // Если файл не открыт, то сообщаем об этом.
		cout << "Файл с данными пользователей недоступен!" << endl;
	}
}



string getUsersChoise() {
	ifstream logfile(("logfile.txt"), ios_base::in); // Открываем файл с логинами только для чтения.

	if (logfile.is_open()) {
		string str, login;
		int count = 1, userChoise;

		while (getline(logfile, str)) { // Выводим логины пользователей
			login = str.substr(0, str.find(" "));
			if (login == user.getUserLogin()) { // Не выводим логин авторизованного пользователя
				continue;
			}
			cout << count++ << " " << login << endl;
		}
		
		logfile.clear(); // Переводим каретку в начало файла.
		logfile.seekg(0, std::ios::beg);

		cout << "Выберите пользователя (Введите число). 0 - для выхода." << endl;
		cin >> userChoise;
		cin.ignore(256, '\n');
		cin.clear();
		if (userChoise > 0 && userChoise < count) {
			count = 1;
			string to;
			while (getline(logfile, str)) {
				if (str.substr(0, str.find(" ")) == user.getUserLogin()) { // Не считем строку с авторизованным пользователем
					continue;
				}
				else if (count == userChoise) {
					to = str.substr(0, str.find(" "));
					break;
				}
				count++;
			}


			logfile.close();
			return to;
		}
		else if (userChoise == 0) {
			logfile.close();
			return "";
		}
		else {
			logfile.close();
			cout << "Введено неверное значение." << endl;
			return "";
		}
	}
	else { // Если файл не открыт, то сообщаем об этом.
		cout << "Файл с пользователями недоступен!";
		return "";
	}
}

void sendMessage(string from, string to, string message) {
	ofstream messagesfile;
	try {
		if (to == "all") {
			messagesfile.open("messagesGlobal.txt", ios_base::app); // Запись в конец файла.
		}
		else {
			if (from > to) {
				messagesfile.open("messages" + from + to + ".txt", ios_base::app); // Запись в конец файла.
			}
			else {
				messagesfile.open("messages" + to + from + ".txt", ios_base::app); // Запись в конец файла.
			}
		}
		if (messagesfile) {
			messagesfile << from << ": " << message << endl;
			messagesfile.close();
		}
		else {
			throw fileErrors();
		}
	}
	catch (exception& excep)
	{
		cout << excep.what() << endl;
	}
}

void getNewMessages(string to, string message) {
	string numberOfMessages;
	if (message.size() <= 2 || message.size() >= 6) { // Проверка корректности команды
		cout << "Команда введена неверно!" << endl;
		return;
	}

	for (int i = 2; i < message.size(); ++i) { // Узнаём сколько сообщений надо прочитать.
		if (message[i] >= '0' && message[i] <= '9') {
			numberOfMessages += message[i];
		}
		else { // Выходим из функции если есть ошибка в команде.
			cout << "Команда введена неверно!" << endl;
			return;
		}
	}

	int num = stoi(numberOfMessages); // Переводим число в численный формат.
	
	ifstream messagesfile;
	if (to == "") {  // Открывать общий или приватный файл?
		messagesfile.open("messagesGlobal.txt", ios_base::in); // Открываем файл с сообщениями только для чтения.
	}
	else {
		string from = user.getUserLogin();
		if (from > to) {
			messagesfile.open("messages" + from + to + ".txt", ios_base::app); // Запись в конец файла.
		}
		else {
			messagesfile.open("messages" + to + from + ".txt", ios_base::app); // Запись в конец файла.
		}
	}

	if (messagesfile.is_open()) {
		string str;
		int allLines = 0, startLine = 0;

		while (getline(messagesfile, str)) { // Считаем сколько всего строк в файле.
			allLines++;
		}
		startLine = allLines - num;
		startLine >= 0 ? startLine : startLine = 0; // Считаем с какой строки начать выводить сообщения.

		messagesfile.clear(); // Переводим каретку в начало файла.
		messagesfile.seekg(0, std::ios::beg);

		for (int i = 0; i < allLines; i++) { // Выводим нужное кол-во сообщений.
			getline(messagesfile, str);
			if (i == startLine) {
				cout << str << endl;
				startLine++;
			}
		}
		
		messagesfile.close();
	}
	else { // Если файл не открыт, то сообщаем об этом.
		cout << "Файл с сообщениями недоступен!" << endl;
	}
}