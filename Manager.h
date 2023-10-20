#include <string>

#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h" // Include the Employee class header

// Define the Manager class, which is derived from the Employee class
class Manager : public Employee
{
public:
    // Constructor to initialize a Manager object with a name, wage, hours, and bonus
    Manager(string theName, double theWage, double theHours, int bonus);

    // Getter function to retrieve the bonus of the manager
    int get_bonus() const;

    // Calculate the pay for the manager, including both regular wage and bonus
    double calcPay() const;

private:
    int bonus_manager; // Private member variable to store the bonus for the manager
};

#endif
