#include "file.h"
using namespace std;
extern bool authorisation;
#include <iostream>
/*
void userSave(string login, string name, string password) {//сохран€ем нового пользовател€ при регистрации
	ofstream logfile("logfile.txt", ios_base::app); //запись в конец файла
	logfile << login << " " << name << " " << password << endl;
	logfile.close();
}*/
/*
string userSearch(string login, string password) {//ищем пользовател€ при авторизации
	ifstream logfile("logfile.txt", ios_base::in); //открыть только дл€ чтени€
	string str, name, answer;

	if (logfile.is_open()) {
		answer = "ѕользователь не найден.\n";

		for (logfile >> str; !logfile.eof(); logfile >> str) { //считка слов из файла. Ќадо бы считывать только логин...
			if (str == login) { //если введЄнное слово есть в файле
				getline(logfile, str);
				name = str.substr(1, str.find_last_of(" ")-1);//вытаскиваем им€ пользовател€ из строки
				str.erase(0, str.find_last_of(" ") + 1); //вытаскиваем пароль пользовател€ из строки

				if (str == password) { //если пароли совпадают - заходим в систему
					answer = "ƒобро пожаловать в чат.\n";
					////////////класс создаЄтс€ и уничтожаетс€ сразу. Ќужен посто€нный. Ќадо создать его в main.
					static Users user(login, name); //создаЄм класс с авторизованным пользователем
					cout << user.getUserLogin() << " " << user.getUserName() << endl;
					////////////
					
					authorisation = true;
					break;
				}
				else {
					answer = "Ќеверный пароль.\n";
					break;
				}
			}
		}
	}
	else { //если файл не открыт
		answer = "‘айл с данными пользователей недоступен!\n"; //сообщить об этом
	}

	return answer;
}
*/
