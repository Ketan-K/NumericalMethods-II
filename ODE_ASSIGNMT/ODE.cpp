#include<iostream>
#include"ODE.hpp"
using namespace std;

double ODE :: improvedTangent(double x_ini,double y_ini,double x_find,double h)
{
	double y_prev=y_ini,x_prev=x_ini,y_curr,k1,k2,k3;
	for(double i=x_ini+h;i<=x_find;i+=h)
	{
		k1=h*functionY(x_prev,y_prev);
		k2=h*functionY(x_prev+0.5*h,y_prev+0.5*k1);
		y_curr=y_prev+k2;
		y_prev=y_curr;
		x_prev=i;
	}
	return y_curr;
}


double ODE :: eulersCauchy(double x_ini,double y_ini,double x_find,double h)
{
	double y_prev=y_ini,x_prev=x_ini,y_curr,k1,k2,k3;
	for(double i=x_ini+h;i<=x_find;i+=h)
	{
		k1=h*functionY(x_prev,y_prev);
		k2=h*functionY(x_prev+h,y_prev+k1);
		y_curr=y_prev+(k1+k2)/2;
		y_prev=y_curr;
		x_prev=i;
	}
	return y_curr;
}



double ODE :: Euler(double x_ini,double y_ini,double x_find,double h)
{
	double y_prev=y_ini,y_curr;
	for(double i=x_ini+h;i<=x_find;i+=h)
	{
		y_curr=y_prev+h*functionY(i-h,y_prev);
		y_prev=y_curr;
	}
	return y_curr;
}

double ODE :: classicalRungeKuttaMethod(double x_ini,double y_ini,double x_find,double h)
{
	double y_prev=y_ini, y_curr,k1,k2,k3;
	for(double i=x_ini+h;i<=x_find;i+=h)
	{
		k1=h*functionY(i-h,y_prev);
		k2=h*functionY(((i-h)+(0.5*h)),(y_prev+(0.5*k1)));
		k3=h*functionY(i,y_prev-k1+2*k2);
		y_curr=y_prev+(k1+4*k2+k3)/6;
		y_prev=y_curr;
	}
	return y_curr;
}

double ODE :: Heun(double x_ini,double y_ini,double x_find,double h)
{
	double y_prev=y_ini, y_curr,k1,k2,k3;
	for(double i=x_ini+h;i<=x_find;i+=h)
	{
		k1=h*functionY(i-h,y_prev);
		k2=h*functionY(((i-h)+((1/3)*h)),(y_prev+((1/3)*k1)));
		k3=h*functionY((i-h+(2/3)*h),(y_prev+(2/3)*k2));
		y_curr=y_prev+(k1+3*k3)/4;
		y_prev=y_curr;
	}
	return y_curr;
}

double ODE :: NystormMethod(double x_ini,double y_ini,double x_find,double h)
{
	double y_prev=y_ini, y_curr,k1,k2,k3;
	for(double i=x_ini+h;i<=x_find;i+=h)
	{
		k1=h*functionY(i-h,y_prev);
		k2=h*functionY(((i-h)+((2/3)*h)),(y_prev+((2/3)*k1)));
		k3=h*functionY((i-h+(2/3)*h),(y_prev+(2/3)*k2));
		y_curr=y_prev+(2*k1+3*k2+3*k3)/8;
		y_prev=y_curr;
	}
	return y_curr;
}

double ODE :: RungeKutta(double x_ini,double y_ini,double x_find,double h)
{
	double y_prev=y_ini,y_curr,k1,k2,k3,k4;
	for(double i=x_ini+h;i<=x_find;i+=h)
	{
		k1=h*functionY(i-h,y_prev);
		k2=h*functionY(((i-h)+((1/3)*h)),(y_prev+((1/3)*k1)));
		k3=h*functionY((i-h+(2/3)*h),(y_prev-(1/3)*k1+k2));
		k4=h*functionY(i,y_prev+k1-k2+k3);
		y_curr=y_prev+(k1+3*k2+3*k3+k4)/8;
		y_prev=y_curr;
	}
	return y_curr;
}


double ODE :: classicalMethod(double x_ini,double y_ini,double x_find,double h)
{
	double y_prev=y_ini,y_curr,k1,k2,k3,k4;
	for(double i=x_ini+h;i<=x_find;i+=h)
	{
		k1=h*functionY(i-h,y_prev);
		k2=h*functionY(((i-h)+((1/2)*h)),(y_prev+((1/2)*k1)));
		k3=h*functionY((i-h+(1/2)*h),(y_prev+(1/2)*k2));
		k4=h*functionY(i,y_prev+k3);
		y_curr=y_prev+(k1+2*k2+2*k3+k4)/6;
		y_prev=y_curr;
	}
	return y_curr;
}

double ODE :: functionY(double x,double y)
{
	return (x-y)/2; //return the value of equation
}
