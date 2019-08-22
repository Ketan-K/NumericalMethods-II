#include <iostream>
#include "ODE.hpp"
using namespace std;
int main()
{
    double x0, y0, h, x;
    class ODE deq1;
    cout << "Enter Initial Condition : (x0,y0) :: ";
    cin >> x0 >> y0;
    cout << "\nEnter step size (h) :: ";
    cin >> h;
    cout << "\nEnter x to find y(x) :: ";
    cin >> x;
    cout << "\n\tResult :: y( " << x << " ) =  " << deq1.eulersMethod(x0, y0, h, x) << endl;
}