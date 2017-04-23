#ifndef  mec104 

#include <iostream>

/** Manufacturing Engineering module
*containing 3 equations for Material Removal Rate,
*surface cutting speed and milling power
* + varients of these equations
*
* @author Luke Herron <b00641161> <herron-l1@email.ulster.ac.uk>
* https://github.com/luke959/mec104/ for README.md
*/

class mec104
{
private:
	double	feedRate, MRR, depthOfCut, widthOfCut, diameter, spindleSpeed, UPF, SCS, MP, unitPowerFactor;
	double	pi = 3.14159;
	int		mrr_varient, scs_varient, mp_varient, equationselection;
	char tempchar;
	char yn;
public:
	void mrr_equation_variant();
	void scs_equation_variant();
	void mp_equation_variant();
	void equation_selection();
	double calculate_mrr(double feed, double depth, double width);
	void get_mrr_variables();
	void get_feedrate_variables();
	double calculate_feedrate(double feed, double depth, double width);
	double calculate_spindlespeed(double scs, double pi, double dia);
	double calculate_scs(double pi, double dia, double spindle);
	double calculate_mp(double upf, double mrr);
	double calculate_upf(double mp, double mrr);
	double calculate_mp_mrr(double upf, double mp);
};
#endif