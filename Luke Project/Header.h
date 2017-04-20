//#indef mec104 
#define mec104 

#include <iostream>

class mec104
{
private:
	double	feedRate, MRR, depthOfCut, widthOfCut, diameter, spindleSpeed, unitPowerFactor;
	double	pi = 3.14159;
	int		equationselection, mmr_varient, scs_varient, mp_varient;
	char tempchar;
	char yn;

public:

	void equation_selection();
	void mrr_equation_variant();
	void scs_equation_variant();
	void mp_equation_variant();
	void calculate_mrr();
	void calculate_feedrate();
	void calculate_mp();
};
//#endif