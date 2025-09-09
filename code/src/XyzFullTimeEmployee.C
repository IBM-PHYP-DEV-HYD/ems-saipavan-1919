#include"XyzFullTimeEmployee.H"

//XyzFullTimeEmployee::XyzFullTimeEmployee(string nameParm, string idParm, string dobParm, string genderParm):XyzEmployee(nameParm, idParm, dobParm, genderParm) {
XyzFullTimeEmployee::XyzFullTimeEmployee(unsigned int idParm):XyzEmployee(idParm, FULLTIMER) {
	cout << "I'm XyzFullTimeEmployee constructor" << endl;
	mTotalLeaves = 22; // EMP_TOTAL_LEAVES macro
	mAvailedLeaves = RandEmpDataGen::getRanomEmpAvailedLeaves(mTotalLeaves);
}

unsigned int XyzFullTimeEmployee::getTotalLeaves() {
	return mTotalLeaves;
}

void XyzFullTimeEmployee::setTotalLeaves(unsigned int totalLeavesParm) {
	mTotalLeaves = totalLeavesParm;
}

unsigned int XyzFullTimeEmployee::getAvailedLeaves() {
	return mAvailedLeaves;
}

void XyzFullTimeEmployee::setAvailedLeaves(unsigned int availedLeavesParm) {
	mAvailedLeaves = availedLeavesParm;
}

ostream & operator<<(ostream & out, XyzFullTimeEmployee & SParm) {
	// static_cast is a type casting operator converts expression to specified type
	// static_cast<type>(expression), useful for derived -> base up casting
	out << static_cast<XyzEmployee&>(SParm);
	out << SParm.getTotalLeaves() << "\t\t|";
	out << SParm.getAvailedLeaves() << "\t\t|";
	return out;
}

ostream & XyzFullTimeEmployee::print(ostream & out) {
	//cout << "Print from XyzFullTimeEmployee" << endl;
	out << (*this);
	return out;
}