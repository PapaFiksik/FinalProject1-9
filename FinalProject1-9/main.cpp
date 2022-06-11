#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "");
	bool work = true;

	while (work) {
		cout << "1- Вход. 2 - Регистрация. 3 - Справка. 0 - Выход." << endl;
		short userChoice;
		cin >> userChoice;

		switch (userChoice)
		{
		case 1:
			system("cls");
			cout << "Вход" << endl;
			break;

		case 2:
			system("cls");
			cout << "Регистрация" << endl;
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