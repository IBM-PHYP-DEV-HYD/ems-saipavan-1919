#include"XyzInternEmployee.H"

XyzInternEmployee::XyzInternEmployee(unsigned int idParm):XyzEmployee(idParm, INTERN) {
	cout << "I'm XyzInternEmployee constructor" << endl;
	mCollegeName = RandEmpDataGen::getRandomEmpCollege();
	mBranchName = RandEmpDataGen::getRandomEmpBranch();
}

string XyzInternEmployee::getCollegeName() {
	return mCollegeName;
}

string XyzInternEmployee::getBranchName() {
	return mBranchName;
}

void XyzInternEmployee::setCollegeName(string collegeNameParm) {
	mCollegeName = collegeNameParm;
}

void XyzInternEmployee::setBranchName(string branchNameParm) {
	mBranchName = branchNameParm;
}

ostream & operator<<(ostream & out, XyzInternEmployee & SParm) {
	// static_cast is a type casting operator converts expression to specified type
	// static_cast<type>(expression), useful for derived -> base up casting
	out << static_cast<XyzEmployee&>(SParm);
	out << SParm.getCollegeName() << "\t|";
	out << SParm.getBranchName() << "\t|";
	return out;
}

ostream & XyzInternEmployee::print(ostream & out) {
	//cout << "Print from XyzInternEmployee" << endl;
	out << (*this);
	return out;
}