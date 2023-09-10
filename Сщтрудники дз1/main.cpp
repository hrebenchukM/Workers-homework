#include "Workers.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;


int menu() {
    cout << endl;
    cout << "1.Add new worker:" << endl;
    cout << "2.Print Workers:" << endl;

    cout << "3.Write to file:" << endl;
    cout << "4.Read from file:" << endl;
    cout << "5.Find by last name:" << endl;
    cout << "6.Find by salary range:" << endl;
    cout << "7.Sort by last name:" << endl;
    cout << "8.Delete worker:" << endl;
    cout << "9.EXIT:" << endl;

    int choice;
    do {
        cout << "Enter your choice:";
        cin >> choice;
    } while (choice < 1 || choice > 9);
    return choice;
}


void doMenu(Worker workers[], int& last) {
    int choice;
    int minSalary, maxSalary;
    int userNumber;
    int userAnswer;

    do {
        choice = menu();
        switch (choice) {
        case 1:
            addWorker(workers, last);
            break;
        case 2:
            printAllWorkers(workers, last);
            break;
        case 3:
            writeToFile(workers, last);
            break;
        case 4:
            readFromFile(workers, last);
            break;
        case 5:
            printByLastName(workers, last);
            break;
        case 6:
            cout << "Write minSalary:";
            cin >> minSalary;
            cout << "Write maxSalary:";
            cin >> maxSalary;
            searchBySalaryRange(workers, last, minSalary, maxSalary);
            break;
        case 7:
            SortbyLastName(workers, last);
            printAllWorkers(workers, last);
            break;
        case 8:

            do {
                cout << "Iput number of worker to delete";
                cin >> userNumber;
            } while (userNumber <= 0);

            printWorker(workers[userNumber - 1]);
            cout << "Are you sure that you want to delete this worker?(1=Yes,0=No):" << endl;
            cin >> userAnswer;
            if (userAnswer == 1)
            {
                deleteWorker(workers, last, userNumber);
            }
            else {
                cout << "Okay (-_-)" << endl;
            }

            break;
        case 9:
            cout << "Bye!" << endl;
            break;
        }
    } while (choice != 9);
}



int main() {
    int N = 5;
    int last = 0;
    Worker workers[N];
    doMenu(workers, last);
}