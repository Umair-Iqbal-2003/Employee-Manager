#include "Employee.h"
#include "Manager.h"
#include <iostream>
#include <string>
#include <iomanip> // Include the header for formatting output

int main()
{
    using namespace std;

    cout << "Enter number of managers: ";
    int manager_no;
    cin >> manager_no;

    Manager *ptr[manager_no];
    int i;

    for (i = 0; i < manager_no; i++)
    {
        string name;
        double wage, hours, avg_pay = 0;
        int bonus;

        cout << "Enter manager " << i << " name: ";
        cin.ignore();
        getline(cin, name, '\n');
        cout << "Enter manager " << i << " hourly wage: ";
        cin >> wage;
        cout << "Enter manager " << i << " hours worked: ";
        cin >> hours;
        cout << "Enter manager " << i << " bonus: ";
        cin >> bonus;

        ptr[i] = new Manager(name, wage, hours, bonus);
    }

    double maxPay = 0;
    double totalPay = 0;
    int maxPayIndex = -1;

    for (int i = 0; i < manager_no; i++)
    {
        double pay = ptr[i]->calcPay();
        totalPay += pay;

        if (pay > maxPay)
        {
            maxPay = pay;
            maxPayIndex = i;
        }
    }

    if (maxPayIndex != -1)
    {
        cout << "Max paid is $" << fixed << setprecision(2) << maxPay << " for " << ptr[maxPayIndex]->getName() << endl;
    }

    if (manager_no > 0)
    {
        double averagePay = totalPay / manager_no;
        cout << "Average pay for all managers: $" << fixed << setprecision(2) << averagePay << endl;
    }
    else
    {
        cout << "No managers to calculate the average pay." << endl;
    }

    for (int i = 0; i < manager_no; i++)
    {
        delete ptr[i];
    }

    return 0;
}
