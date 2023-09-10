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


void writeToFile(Worker workers[], int size) {
	ofstream outputFile("workers_data.txt"); //создала файл
	if (!outputFile) //проверка создалс€ ли файл
		return;

	outputFile << size << endl;
	for (int i = 0; i < size; i++) {
		outputFile << workers[i].firstName << endl;
		outputFile << workers[i].lastName << endl;
		outputFile << workers[i].telephone << endl;
		outputFile << workers[i].salary << endl;
	}
	cout << "Success!" << endl;
}
void readFromFile(Worker workers[], int& last) {
	ifstream file("workers_data.txt");

	if (file.is_open()) {
		string line; //строка дл€ считывани€
		getline(file, line);//перва€ строка в файле-это количество работников
		int count = stoi(line);//строку в число

		for (int i = 0; i < count; i++) {
			Worker* worker = new Worker;
			getline(file, line);
			worker->firstName = line;
			getline(file, line);
			worker->lastName = line;
			getline(file, line);
			worker->telephone = line;
			getline(file, line);
			worker->salary = stod(line);//string ->double
			workers[i] = *worker;//в массив ложим того работника что сделали
		}
		last = count;
		file.close();
	}
	else {
		cout << "Ќе удалось открыть файл." << std::endl;
	}
}