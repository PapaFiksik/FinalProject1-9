#include "file.h"
using namespace std;

void userSave(string login, string name, string password) {//��������� ������ ������������ ��� �����������
	ofstream logfile("logfile.txt", ios_base::app); //������ � ����� �����
	logfile << login << " " << name << " " << password << endl;
	logfile.close();
}

string userSearch(string login, string password) {//���� ������������ ��� �����������
	ifstream logfile("logfile.txt", ios_base::in); //������� ������ ��� ������
	string str, answer;

	if (logfile.is_open()) {
		answer = "������������ �� ������.\n";

		for (logfile >> str; !logfile.eof(); logfile >> str) { //������ ���� �� �����. ���� �� ��������� ������ �����...
			if (str == login) { //���� �������� ����� ���� � �����
				getline(logfile, str);
				str.erase(0, str.find_last_of(" ")+1); //����������� ������ ������������ �� �����
				
				if (str == password) { //���� ������ ��������� - ������� � �������
					answer = "����� ���������� � ���.\n";
					break;
				}
				else {
					answer = "�������� ������.\n";
					break;
				}
			}
		}
	}
	else { //���� ���� �� ������
		answer = "���� � ������� ������������ ����������!\n"; //�������� �� ����
	}

	return answer;
}