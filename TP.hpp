#include<iostream>
using namespace std;
class TP{
	public:
	int NOS;
	int NOD;
	int **cost;
	int *supply,*tsupply;
	int *demands,*tdemands;
	TP();
	void init(int ,int);
	bool getInputFromUser();
	bool getInputFromFile(const std::string);
	void display();
	void makeTempSD();
	
	int total(int *);
	bool checkTotalSupplyAndDemandsAreSatisfied();
	bool checkBalance();
	int NWCM();
};
