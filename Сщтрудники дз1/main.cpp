#include "workers.h"
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