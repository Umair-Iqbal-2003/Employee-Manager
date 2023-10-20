//Umair Iqbal
//This program uses Employee class which inherits Manager class and calculate bonus pay


#include "Employee.h"    // Include the Employee class header file
#include "Manager.h"     // Include the Manager class header file
#include <iostream>      // Include the standard input/output stream library
#include <string>        // Include the string library for string manipulation

int main()
{
    using namespace std;  // Allow the use of symbols from the std namespace without explicitly qualifying them

    cout << "Enter number of managers: ";
    int manager_no;        // Declare a variable to store the number of managers
    cin >> manager_no;     // Read the number of managers from the user

    Manager *ptr[manager_no];  // Declare an array of pointers to Manager objects to store manager data
    int i;

    for (i = 0; i < manager_no; i++)
    {
        string name;
        double wage, hours, avg_pay = 0;
        int bonus;

        cout << "Enter manager " << i << " name: ";
        cin.ignore(); // Consume the newline character left in the input buffer
        getline(cin, name, '\n');  // Read the manager's name with spaces

        cout << "Enter manager " << i << " hourly wage: ";
        cin >> wage;   // Read the manager's hourly wage

        cout << "Enter manager " << i << " hours worked: ";
        cin >> hours;  // Read the number of hours worked by the manager

        cout << "Enter manager " << i << " bonus: ";
        cin >> bonus;  // Read the bonus amount for the manager

        ptr[i] = new Manager(name, wage, hours, bonus);  // Create a new Manager object and store its address in the array
    }

    double maxPay = 0;  // Variable to store the maximum pay
    double totalPay = 0;  // To calculate the total pay of all managers
    int maxPayIndex = -1;  // Index of the manager with the maximum pay

    for (int i = 0; i < manager_no; i++)
    {
        double pay = ptr[i]->calcPay();  // Calculate the pay for the manager
        totalPay += pay;  // Add the manager's pay to the total pay

        if (pay > maxPay)
        {
            maxPay = pay;  // Update the maximum pay if the current manager's pay is higher
            maxPayIndex = i;  // Update the index of the manager with the maximum pay
        }
    }

    if (maxPayIndex != -1)
    {
        cout << "Max paid is " << maxPay << " for " << ptr[maxPayIndex]->getName() << endl;  // Print the manager with the maximum pay
    }

    // Calculate and print the average pay
    if (manager_no > 0)
    {
        double averagePay = totalPay / manager_no;  // Calculate the average pay
        cout << "Average pay for all managers: " << averagePay << endl;  // Print the average pay
    }
    else
    {
        cout << "No managers to calculate the average pay." << endl;
    }

    // Deallocate memory for the Manager objects
    for (int i = 0; i < manager_no; i++)
    {
        delete ptr[i];  // Free the memory allocated for each Manager object
    }

    return 0;  // Return 0 to indicate successful execution
}
