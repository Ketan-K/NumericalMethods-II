class LPP
{
public:
  int noOfVariables, noOfConstraints;
  double *coefOfZ;
  double **X;
  LPP();
  void init(unsigned short int, unsigned short int);
  void accept();
  void display();
  void simplex();
};