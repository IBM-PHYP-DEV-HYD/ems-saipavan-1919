#include<iostream>
using namespace std;

#include"XyzEmpManager.H"


int main() {
	// main function initializes the XyzEmmployeeManager object
	unsigned int sNoOfEmps = RandEmpDataGen::getRandomNumber(4,10);
	cout << "Number of Emps : " << sNoOfEmps << endl;
	if(sNoOfEmps) {
		XyzEmployeeManager sMgr(sNoOfEmps);
		sMgr.processEmployees();
	}
	else {
		XyzEmployeeManager sMgr;
		sMgr.processEmployees();
	}
	return 0;
}
