#include "Workers.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;




string check(string title) {
	string buff = "";
	while (true) {
		cout << "Enter worker " << title << ": ";
		getline(cin >> ws, buff);

		if (buff.empty()) {
			cout << "Wrong input! Cannot be empty \n";
		}
		else
			break;
	}
	return buff;
}


double checkSalary() {
	double value = 0;
	while (true) {
		cout << "Enter salary "
			<< ": ";
		cin >> value;
		if (value < 0) {
			cout << "Wrong input!";
		}
		else
			break;
	}
	return value;
}

string checkPhone() {
	string buff = "";
	while (true) {
		cout << "Enter phone number " << ": ";
		getline(cin >> ws, buff);

		if (buff.empty()) {
			cout << "Wrong input! Cannot be empty \n";
		}
		else if (
			buff[0] != '(' || buff[4] != ')'
			|| buff.length() != 12
			|| !isdigit(buff[1])
			|| !isdigit(buff[2])
			|| !isdigit(buff[3])
			|| !isdigit(buff[5])
			|| !isdigit(buff[6])
			|| !isdigit(buff[7])
			|| !isdigit(buff[8])
			|| !isdigit(buff[9])
			|| !isdigit(buff[10])
			|| !isdigit(buff[11])
			)
		{
			cout << "Wrong number format! Expected format (xxx)xxxxxxx\n";
		}
		else {
			break;
		}
	}
	return buff;
}

void inputNewWorker(Worker* worker) {
	worker->firstName = check("first name");
	worker->lastName = check("last name");
	worker->telephone = checkPhone();
	worker->salary = checkSalary();
}
Worker* addWorker(Worker workers[], int& last) {
	Worker* worker = new Worker;
	inputNewWorker(worker);
	workers[last] = *worker;
	last++;
	return worker;
}


void printWorker(Worker worker) {
	cout << "  First name: " << worker.firstName << endl;
	cout << "  Last name:  " << worker.lastName << endl;
	cout << "  Telephone:  " << worker.telephone << endl;
	cout << "  Salary:     " << worker.salary << endl;
	cout << endl;
}

void printAllWorkers(Worker workers[], int N) {
	cout << endl << "Workers list:" << endl;
	for (int i = 0; i < N; i++) {
		cout << "  N:          " << i + 1 << endl;
		printWorker(workers[i]);
	}
}
