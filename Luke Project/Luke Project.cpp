/**
*@author Luke Herron <b00641161> <herron-l1@email.ulster.ac.uk>
*/

// Luke.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;

class mec104
{
private:
	double	feedRate, MRR, depthOfCut, widthOfCut, diameter, spindleSpeed, UPF, SCS, MP, unitPowerFactor;
	double	pi = 3.14159;
	int		equationselection, mrr_varient, scs_varient, mp_varient;
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


void mec104::equation_selection()
{
	do
	{
		cout << "Enter operator. 1 for MRR, 2 for SCS or 3 for MP: ";
		cin >> equationselection;

		switch (equationselection)
		{
		case 1:
			mrr_equation_variant(); //get MRR varient
			switch (mrr_varient)
			{
			case 1:
				calculate_mrr();
				break;
			case 2:
				calculate_feedrate();
				break;
			}
			break;

		case 2:
			scs_equation_variant();  //get SCS varient
			switch (scs_varient)
			{
			case 1:

				cout << "Enter diameter in mm: ";
				cin >> diameter;

				cout << "Enter spindle speed in RPM: ";
				cin >> spindleSpeed;

				cout << "Result is: " << pi * diameter * spindleSpeed << "(mm/min)" << endl;
				break;

			case 2:
				cout << "Enter SCS in mm/min: ";
				cin >> SCS;

				cout << "Enter diameter in mm: ";
				cin >> diameter;

				cout << "Result is: " << SCS / (diameter * spindleSpeed) << "(RPM)" << endl;
				break;
			}
			break;

		case 3:
			mp_equation_variant(); //get the mp equation varient
			switch (mp_varient)
			{
			case 1:
				cout << "Enter unit power factor: ";
				cin >> unitPowerFactor;

				cout << "Enter material removal rate: ";
				cin >> MRR;

				cout << "Result is: " << unitPowerFactor * MRR << "Watts" << endl;
				break;

			case 2:
				cout << "Enter material removal rate: ";
				cin >> MRR;

				cout << "Enter milling power: ";
				cin >> MP;

				cout << "Result is: " << MP / MRR << endl;
				break;

			case 3:
				cout << "Enter unit power factor: ";
				cin >> UPF;

				cout << "Enter milling power: ";
				cin >> MP;

				cout << "Result is: " << MP / UPF << endl;
				break;
			}
			break;

		default:
			cout << "Error! operator is not correct" << endl;
			break;
		}
		cout << "Run again? [Y/N]: " << flush;


	} while (cin >> yn && (yn == 'Y' || yn == 'y'));

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

void mec104::calculate_feedrate()
{
	cout << "Enter feed rate in mm/rev: ";
	cin >> feedRate;

	cout << "Enter depth of cut in mm: ";
	cin >> depthOfCut;

	cout << "Enter width of cut in mm: ";
	cin >> widthOfCut;

	cout << "Result is: " << feedRate * depthOfCut * widthOfCut << "cc/min" << endl;
}

void mec104::calculate_mp()
{
	cout << "Enter MRR in cc/min: ";
	cin >> MRR;

	cout << "Enter depth of cut in mm: ";
	cin >> depthOfCut;

	cout << "Enter width of cut in mm: ";
	cin >> widthOfCut;

	cout << "Result is: " << MRR / (depthOfCut * widthOfCut) << "mm/rev" << endl;
}

void mec104::calculate_mrr()
{
	cout << "Enter feed rate in mm/rev: ";
	cin >> feedRate;

	cout << "Enter depth of cut in mm: ";
	cin >> depthOfCut;

	cout << "Enter width of cut in mm: ";
	cin >> widthOfCut;

	cout << "Result is: " << feedRate * depthOfCut * widthOfCut << "cc/min" << endl;
}

int main(void)
{
	mec104 m;
	m.equation_selection();
	return(0);
}


