#include "file.h"
using namespace std;

void userSave(string login, string name, string password) {//сохраняем нового пользователя при регистрации
	ofstream logfile("logfile.txt", ios_base::app); //запись в конец файла
	logfile << login << " " << name << " " << password << endl;
	logfile.close();
}

string userSearch(string login, string password) {//ищем пользователя при авторизации
	ifstream logfile("logfile.txt", ios_base::in); //открыть только для чтения
	string str, answer;

	if (logfile.is_open()) {
		answer = "Пользователь не найден.\n";

		for (logfile >> str; !logfile.eof(); logfile >> str) { //считка слов из файла. Надо бы считывать только логин...
			if (str == login) { //если введённое слово есть в файле
				getline(logfile, str);
				str.erase(0, str.find_last_of(" ")+1); //вытаскиваем пароль пользователя из файла
				
				if (str == password) { //если пароли совпадают - заходим в систему
					answer = "Добро пожаловать в чат.\n";
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
		answer = "Файл с данными пользователй недоступен!\n"; //сообщить об этом
	}

	return answer;


}






/*string userSearch(string login, string password) {
	ifstream logfile("logfile.txt", ios_base::in); //открыть только для чтения
	string tempLogin, tempPassword, line, answer;

	if (logfile.is_open()) {
		answer = "Пользователь не найден.\n";
		while (!logfile.eof()) {
			logfile >> tempLogin;

			if (tempLogin == login)	{
				logfile >> tempPassword;
				//if (tempPassword == password) {
					answer = "Добро пожаловать в чат.\n";
					break;
				//}
				//else {
				//	answer = "Неверный пароль.\n";
				//  break;
				//}
			}
			tempLogin.clear();
			tempPassword.clear();
		}

		logfile.close();
	}
	else { // если файл не открыт
		answer = "Файл не может быть открыт!\n"; // сообщить об этом
	}

	return answer;
}*/