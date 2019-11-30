#include<iostream>
#include"ODE.hpp"
using namespace std;

int main()
{
	ODE ode;
	int op;
	double x_ini,y_ini,h,x_find,ans;
	/*cout<<"Enter the intial value x and y : ";
	cin>>x_ini>>y_ini;
	cout<<"Enter step size (h) : ";
	cin>>h;
	cout<<"Enter value to find : ";
	cin>>x_find;*/
	x_ini=0;
	y_ini=1;
	h=1;
	x_find=3;
	
	
	cout<<"\n\tY("<<x_ini<<")="<<y_ini<<endl;
	cout<<"\tY("<<x_find<<")=?"<<endl;
	
	do{
	cout<<"\n\n**********MENU**********\n\n Second Order Methods :  \n\t1)Improved Tangent Method\n\t2)Euler's Cauchy Method\n Third Order Methods : \n\t3)Euler's Method\n\t4)Classical RK Method\n\t5)Heun Method\n\t6)Nystorm Method\n Fourth Order Methods : \n\t7)Runge Kutta Method\n\t8)Classical Method\n Enter your choice : ";
	cin>>op;
	
	switch(op)
	{
		case 1 :
			ans=ode.improvedTangent(x_ini,y_ini,x_find,h);
			break;
		case 2 :
			ans=ode.eulersCauchy(x_ini,y_ini,x_find,h);
			break;
		case 3 :
			ans=ode.Euler(x_ini,y_ini,x_find,h);
			break;
		case 4 :
			ans=ode.classicalRungeKuttaMethod(x_ini,y_ini,x_find,h);
			break;
		case 5 : 
			ans=ode.Heun(x_ini,y_ini,x_find,h);
			break;
		case 6 :
			ans=ode.NystormMethod(x_ini,y_ini,x_find,h);
			break;
		case 7 :
			ans=ode.RungeKutta(x_ini,y_ini,x_find,h);
			break;
		case 8 :
			ans=ode.classicalMethod(x_ini,y_ini,x_find,h);
			break;
		default : 
			cerr<<"You Choose Wrong Option"<<endl;
            return 0;
	}
    cout<<"\n\tResult :: Y(" <<x_find<< ") = "<<ans<<endl;			
	}while(op!=0);
	return 0;
}
