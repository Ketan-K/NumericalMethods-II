#include <iostream>
#include "ODE.hpp"
using namespace std;
ODE::ODE()
{
}
double ODE::function(double x, double y)
{
    return x + y + (x * y);
}

double ODE::eulersMethod(double x0, double y0, double h, double x)
{
    while (x0 < x)
    {
        y0 = y0 + h * function(x0, y0);
        x0 += h;
    }
    return y0;
}