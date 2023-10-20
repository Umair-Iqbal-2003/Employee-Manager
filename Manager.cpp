#include "Manager.h"
#include <string>
using namespace std;

// Constructor for the Manager class
Manager::Manager(string theName, double theWage, double theHours, int bonus) : Employee(theName, theWage, theHours)
{
    bonus_manager = bonus;
}

// Getter function to retrieve the bonus of the manager
int Manager::get_bonus() const
{
    return bonus_manager;
}

// Calculate the pay for the manager, including both regular wage and bonus
double Manager::calcPay() const
{
    double Manager_pay = (wage * hours) + bonus_manager; // Calculate the total pay for the manager
    return Manager_pay; // Return the calculated pay
}
