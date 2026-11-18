#include <iostream>
#include <iomanip>
using namespace std;

// N = P(1 + B)(1 - D)
double calculateNewPopulation(double previous, double birthRate, double deathRate)
{
    return previous * (1 + birthRate) * (1 - deathRate);
}

int main()
{
    double startingPop, birthRate, deathRate;
    int years;

    cout << "Enter the starting population size (minimum 2): ";
    cin >> startingPop;
    while (startingPop < 2)
    {
        cout << "Starting population must be at least 2. Try again: ";
        cin >> startingPop;
    }

    cout << "Enter the annual birth rate (as a decimal, e.g. .032): ";
    cin >> birthRate;
    while (birthRate < 0)
    {
        cout << "Birth rate cannot be negative. Try again: ";
        cin >> birthRate;
    }

    cout << "Enter the annual death rate (as a decimal, e.g. .026): ";
    cin >> deathRate;
    while (deathRate < 0)
    {
        cout << "Death rate cannot be negative. Try again: ";
        cin >> deathRate;
    }

    cout << "Enter the number of years to display (minimum 1): ";
    cin >> years;
    while (years < 1)
    {
        cout << "Years must be at least 1. Try again: ";
        cin >> years;
    }

    cout << fixed << setprecision(2);
    cout << "\nStarting population: " << startingPop << endl;
    cout << "\nYear\tProjected Population" << endl;
    cout << "-----------------------------" << endl;

    double population = startingPop;
    for (int year = 1; year <= years; year++)
    {
        population = calculateNewPopulation(population, birthRate, deathRate);
        cout << year << "\t" << population << endl;
    }

    return 0;
}