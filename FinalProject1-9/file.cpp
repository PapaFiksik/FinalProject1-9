#include "file.h"
using namespace std;

void userSave(string login, string name, string password)
{
	ofstream logfile;
	logfile.open("logfile.txt", ios_base::app);
	logfile << login << " " << name << " " << password << endl;
	logfile.close();
}