#include <string>
using namespace std;


struct Worker { //����������� ����
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

void printAllWorkers(Worker[], int);
void printWorker(Worker);