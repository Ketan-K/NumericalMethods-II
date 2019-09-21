#include<iostream>
#include"TP.hpp"
using namespace std;

int main(int argc,char *argv[])
{
	if(argc!=2){
		cerr<<"Please Enter Input File Name ."<<endl;
		exit(0);
	}
	TP problem1;
	problem1.getInputFromFile(argv[1]);
	problem1.display();
}
