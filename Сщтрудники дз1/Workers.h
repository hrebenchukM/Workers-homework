#include <string>
using namespace std;


struct Worker { //перечисляем поля
	string firstName;
	string lastName;
	string telephone;
	double salary;
};
double checkSalary();
string check(string);
string checkPhone();
Worker* addWorker(Worker[], int&);
void inputNewWorker(Worker* );