#include <iostream>
using namespace std;
class TP
{
public:
	int NOS;
	int NOD;
	int **cost;
	int *supply, *tsupply;
	int *demands, *tdemands;
	int **Allocations;
	TP();
	void init(int, int);
	bool getInputFromUser();
	bool getInputFromFile(const char *);
	void display();

	void makeTempSD();

	int total(int *, int);
	bool checkTotalSupplyAndDemandsAreSatisfied();
	bool checkBalance();
	void allocate(int i, int j, int c);
	int calCost();
	int **NWCM();

	int **LCM();

	int findMinCostCell(int *, int *);

	int MatrixMinimaMethod();
	int checkOptimize();
};

void dispMatrix(int **, int, int);
