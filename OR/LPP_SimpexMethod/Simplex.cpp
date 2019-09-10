#include <iostream>
#include "Simplex.hpp"
using namespace std;
LPP::LPP()
{
}
void LPP::init(unsigned short int noOfVariables, unsigned short int noOfConstraints)
{
    this->noOfVariables = noOfVariables;
    this->noOfConstraints = noOfConstraints;
    this->coefOfZ = new double[noOfVariables];
    this->X = new double *[noOfConstraints];
    for (int i = 0; i <= noOfConstraints; i++)
    {
        this->X[i] = new double[noOfVariables];
    }
}
void LPP::accept()
{
    cout << "How many variables : ";
    cin >> this->noOfVariables;
    cout << "How many constraints : ";
    cin >> this->noOfConstraints;

    this->init(noOfVariables, noOfConstraints);
    cout << "Enter coefficients of (Maximize) Z (Cj) : ";
    for (int i = 0; i < noOfVariables; i++)
        cin >> coefOfZ[i];

    cout << "\nEnter Constraints (Equalities): ";
    for (int i = 0; i < noOfConstraints; i++)
    {
        cout << "\n Constraint | " << i + 1 << " | : ";
        for (int j = 0; j <= noOfVariables; j++)
            cin >> X[i][j];
    }
}

void LPP::display()
{
    cout << "\n Coefficients of Z : \n\t";
    for (int i = 0; i < noOfVariables; i++)
        cout << "  " << coefOfZ[i];
    cout << "\n Constraints : \n\t";
    for (int i = 0; i < noOfConstraints; i++)
    {
        cout << "\n Constraint | " << i + 1 << " | : \t";
        for (int j = 0; j <= noOfVariables; j++)
            cout << "  " << X[i][j];
    }
    cout << endl;
}
void printArray()
{
}
void LPP::simplex()
{
    unsigned short int *coefOfBasicVariables, *basicVaiables;
    coefOfBasicVariables = new unsigned short int[noOfConstraints]();
    basicVaiables = new unsigned short int[noOfConstraints]();
}