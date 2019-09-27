#include<iostream>

#include"TP.hpp"
using namespace std;

int main(int argc,char *argv[])
{
	if(argc!=2){
		cerr<<"Please Enter Input File Name ."<<endl;
                  return 0;
	}
	TP problem1;
	problem1.getInputFromFile(argv[1]);
	problem1.display();
         int **mat=problem1.NWCM();
       //  dispMatrix(mat,problem1.NOS,problem1.NOD);
}



	