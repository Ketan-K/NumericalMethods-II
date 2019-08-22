#include <iostream>
using namespace std;
class ODE
{
public:
    ODE();
    double function(double, double);
    double eulersMethod(double, double, double, double);
};