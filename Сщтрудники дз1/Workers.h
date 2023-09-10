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

void printAllWorkers(Worker[], int);
void printWorker(Worker);

void writeToFile(Worker[], int);
void readFromFile(Worker[], int&);

int searchByLastName(Worker[], int, string);
void printByLastName(Worker[], int);

void searchBySalaryRange(Worker[], int, int, int);
