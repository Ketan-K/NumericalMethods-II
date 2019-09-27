#include<iostream>
#include<fstream>
#include"TP.hpp"
using namespace std;
TP::TP()
{
	init(0,0);
}
void TP::init(int NOS,int NOD)
{
	this->NOS=NOS;
	this->NOD=NOD;
	this->cost=new int*[NOS];
	for(int i=0;i<NOS;i++)
	{
		cost[i]=new int[NOD];
	}
          Allocations=new int*[NOS];
	for(int i=0;i<NOS;i++)
	{
		Allocations[i]=new int[NOD];
                for(int j=0;j<NOD;j++)
                        Allocations[i][j]=-1;
	}
	supply=new int [NOS];
	demands=new int [NOD];
	tsupply=new int [NOS];
	tdemands=new int [NOD];
}

bool TP::getInputFromUser()
{
	cout<<"\nTotal";
	return true;
}
bool TP::getInputFromFile(const char* filename)
{
	ifstream file;
	file.open(filename);
	if (!file)
		return false;
	unsigned short int NOS, NOD;
	file >> NOS;
	file >> NOD;
	init(NOS, NOD);
	for (int i = 0; i < NOS; i++)
	{
		for (int j = 0; j < NOD; j++)
		{
			file >> this->cost[i][j];
		}
	}
	for (int i = 0; i < NOS; i++)
	file>>this->supply[i];
	
	for (int i = 0; i < NOD; i++)
	file>>this->demands[i];
	return true;
}

void TP::display()
{
	cout << "\nTransportation Problem : \n";
	cout << "No Of Sources(Supply) : " << NOS << "\t NO Of Destinations(Demands): " << NOD<<endl;
	cout << "\tCost Matrix "<<endl;
        dispMatrix(cost,NOS,NOD);
	cout<<"Supply :: ";
	for(int i=0;i<NOS;i++)
	{
		cout<<"\t"<<supply[i];
	}
	cout<<endl<<"Demands :: ";
	
	for(int i=0;i<NOD;i++)
	{
		cout<<"\t"<<demands[i];
	}cout<<endl;
}
void dispMatrix(int **mat,int row,int cols)
{
        for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << "\t" << mat[i][j];
		}
		cout << endl;
	}
}
bool TP::checkBalance()
{
	if(total(supply,NOS)==total(demands,NOD))
		return true;
	return false;
}

void TP::makeTempSD()
{
	for (int i = 0; i < this->NOS; i++)
		tsupply[i]=supply[i];
	for (int i = 0; i < this->NOD; i++)
		tdemands[i]=demands[i];
}

int TP::total(int *array,int N)
{
	int sum=0;
	for (int i = 0; i < N; i++)
		sum+=array[i];
         return sum;
}
	

bool TP::checkTotalSupplyAndDemandsAreSatisfied()
{
	return (total(tsupply,NOS)==0 && total(tdemands,NOD)==0);
}

void TP::allocate(int i,int j,int c)
{
	 Allocations[i][j]=c;
     tdemands[j]-=c;
     tsupply[i]-=c;
}


int** TP::NWCM(){
	if(!this->checkBalance())
	{
		cerr<<"Unbalanced Transportation problem !";
		return Allocations;
	}
	makeTempSD();
	int i=0,j=0;
	while(!checkTotalSupplyAndDemandsAreSatisfied() && (i<NOS || j<NOD))
	  // for(int i=0,j=0;i<NOS || j<NOD;)
	{    
                  if(tsupply[i]<tdemands[j])
                  {
                    allocate(i,j,tsupply[i]);
                     i++;
                  }
                  else
                  {
                     allocate(i,j,tdemands[j]);
                     j++;
	          }
        }
        if(checkTotalSupplyAndDemandsAreSatisfied())
        {
                cout<<"\nAll Demands and Supply are Satisfied .";
                cout<<"\n Allocations Matrix :: "<<endl;
                for(int i=0;i<NOS;i++,cout<<endl)
                for(int j=0;j<NOD;j++)
                       cout<<"\t"<<Allocations[i][j];
                cout<<"\nTotal Transporatation Cost is :: "<<calCost()<<endl; 
						       cout<<"Check : "<<checkTotalSupplyAndDemandsAreSatisfied();

                return Allocations;
        }
	return Allocations;
}
/*
int** TP::LCM(){
	if(!this->checkBalance())
	{
		cerr<<"Unbalanced Transportation problem !";
		return NULL;
	}
	makeTempSD();
	while(!checkTotalSupplyAndDemandsAreSatisfied())
	{
		findMinCostCell(&minI,&minJ)
	}


}
*/
int TP::calCost()
{
         int tcost=0;
         for(int i=0;i<NOS;i++)
             for(int j=0;j<NOD;j++)
                  if(Allocations[i][j]>0)
                  tcost+=Allocations[i][j]*cost[i][j];
         return tcost;
}
	
