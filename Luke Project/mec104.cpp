/**
*@author Luke Herron <b00641161> <herron-l1@email.ulster.ac.uk>
*
* Manufacturing processes module
*
*@author Luke Herron <b00641161> <herron-l1@email.ulster.ac.uk>
* https://github.com/luke959/mec104/ for README.md
*
*Part of a larger project which enables you to select an equation you wish
*to calculate from the manufacturing processes module
*and varients of that equation depending on values that are given to you.
*/
// Luke.cpp : Defines the entry point for the console application.

#include <iostream>
#include "mec104.h"

using namespace std;
mec104 m;

/**
*Gives cases 1, 2, 3 of which are equations
*
*@param select a case number for equation selection
*@return A selected 'equation'
*/

void mec104::equation_selection()
{
	do
	{
		cout << "Enter operator. 1 for MRR, 2 for SCS or 3 for MP: ";
		cin >> m.equationselection;

		switch (equationselection)
		{
		case 1:
			m.mrr_equation_variant(); //get MRR varient
			switch (m.mrr_varient)
			{
			case 1:
				m.get_mrr_variables();
				m.calculate_mrr(m.feedRate, m.depthOfCut, m.widthOfCut);
				break;
			case 2:
				m.get_feedrate_variables();
				m.calculate_feedrate(m.feedRate, m.depthOfCut, m.widthOfCut);
				break;
			}
/**
*Gives cases of which are varients of the selected equation
*
*@param select a case number for equation varient selection
*@return A selected 'equation varient'
*/
			break;

		case 2:
			m.scs_equation_variant();  //get SCS varient
			switch (m.scs_varient)
			{
			case 1:

				cout << "Enter diameter in mm: ";
				cin >> m.diameter;

				cout << "Enter spindle speed in RPM: ";
				cin >> m.spindleSpeed;

				m.calculate_scs(m.pi, m.diameter, m.spindleSpeed);
				break;

			case 2:
				cout << "Enter SCS in mm/min: ";
				cin >> m.SCS;

				cout << "Enter diameter in mm: ";
				cin >> m.diameter;

				m.calculate_spindlespeed(m.SCS, m.pi, m.diameter);
				break;
			}
			break;

		case 3:
			m.mp_equation_variant(); //get the mp equation varient
			switch (m.mp_varient)
			{
			case 1:
				cout << "Enter unit power factor: ";
				cin >> m.unitPowerFactor;

				cout << "Enter material removal rate: ";
				cin >> m.MRR;

				m.calculate_mp(m.unitPowerFactor, m.MRR);
				break;

			case 2:
				cout << "Enter material removal rate: ";
				cin >> m.MRR;

				cout << "Enter milling power: ";
				cin >> m.MP;

				m.calculate_upf(m.MP, m.MRR);
				break;

			case 3:
				cout << "Enter unit power factor: ";
				cin >> m.UPF;

				cout << "Enter milling power: ";
				cin >> m.MP;

				m.calculate_mp_mrr(m.UPF, m.MP);
				break;
			}
			break;

		default:
			cout << "Error! operator is not correct" << endl;
			break;
		}
		cout << "Run again? [Y/N]: " << flush;


	} while (cin >> m.yn && (m.yn == 'Y' || m.yn == 'y'));

}

void mec104::mrr_equation_variant()
{
	cout << "You have selected MRR" << endl;
	cout << "please select the equation variant" << endl;
	cout << "1. MRR= Feed rate x depth x width" << endl;
	cout << "2. Feed rate= MRR / (Depth x width)" << endl;
	cin >> mrr_varient;
}

void mec104::scs_equation_variant()
{
	cout << "You have selected SCS" << endl;
	cout << "please select the equation variant" << endl;
	cout << "1.SCS= pi x diameter x spindle speed" << endl;
	cout << "2.Spindle Speed= SCS / pi x diameter" << endl;
	cin >> scs_varient;
}

void mec104::mp_equation_variant()
{
	cout << "You have selected MP" << endl;
	cout << "please select the equation variant" << endl;
	cout << "1.MP= UPF x MRR" << endl;
	cout << "2.UPF= MP / MRR" << endl;
	cout << "3.MRR= MP / UPF" << endl;
	cin >> mp_varient;
}

double mec104::calculate_feedrate(double feed, double depth, double width)
{
	cout << "Result is: " << feed * depth * width << "cc/min" << endl;
	return feed * depth * width;
}

double mec104::calculate_mrr(double feed, double depth, double width)
{
	cout << "Result is: " << feed * depth * width << "cc/min" << endl;
	return (feed * depth * width);
}

double mec104::calculate_scs(double pi, double dia, double spindle)
{
	cout << "Result is: " << pi * dia * spindle << "cc/min" << endl;
	return (pi * dia * spindle);
}

double mec104::calculate_spindlespeed(double scs, double pi, double dia)
{
	cout << "Result is: " << scs / (pi * dia) << "cc/min" << endl;
	return scs / (pi * dia);
}

void mec104::get_mrr_variables()
{
	cout << "Enter feed rate in mm/rev: ";
	cin >> feedRate;

	cout << "Enter depth of cut in mm: ";
	cin >> depthOfCut;

	cout << "Enter width of cut in mm: ";
	cin >> widthOfCut;
}

void mec104::get_feedrate_variables()
{
	cout << "Enter feed rate in mm/rev: ";
	cin >> feedRate;

	cout << "Enter depth of cut in mm: ";
	cin >> depthOfCut;

	cout << "Enter width of cut in mm: ";
	cin >> widthOfCut;
}

double mec104::calculate_mp(double upf, double mrr)
{
	cout << "Result is: " << upf * mrr << "Watts" << endl;
	return upf * mrr;
}

double mec104::calculate_upf(double mp, double mrr)
{
	cout << "Result is: " << mp / mrr << endl;
	return mp / mrr;
}

double mec104::calculate_mp_mrr(double upf, double mp)
{
	cout << "Result is: " << mp / upf << endl;
	return mp / upf;
}

int main(void)	
{	
	m.equation_selection();
	return(0);
}


