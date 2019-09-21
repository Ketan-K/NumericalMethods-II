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
bool TP::getInputFromFile(const std::string filename)
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
	for (int i = 0; i < this->NOS; i++)
	{
		for (int j = 0; j < this->NOD; j++)
		{
			cout << "\t" << cost[i][j];
		}
		cout << endl;
	}
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

bool TP::checkBalance()
{
	if(total(supply)==total(demands))
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

int TP::total(int *array)
{
	int sum=0;
		for (int i = 0; i < this->NOS; i++)
		Ssum+=supply[i];
}
	

bool TP::checkTotalSupplyAndDemandsAreSatisfied()
{
	if()
}


int TP::NWCM(){
	if(!this->checkBalance())
	{
		cerr<<"Unbalanced Transportation problem !";
		exit(0);
	}
	makeTempSD();
	while(!checkTotalSupplyAndDemandsAreSatisfied())
	{
		
	}
	
	
	
}


	
