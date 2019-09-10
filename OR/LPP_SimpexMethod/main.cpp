#include <iostream>
#include "Simplex.hpp"
using namespace std;
int main()
{
    cout << "\n\tLPP \n";
    LPP problem;
    problem.accept();
    problem.display();
    return 1;
}