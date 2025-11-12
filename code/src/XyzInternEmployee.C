#include"XyzInternEmployee.H"
#include"XyzEmpManager.H"

XyzInternEmployee::XyzInternEmployee(unsigned int idParm):XyzEmployee(idParm, INTERN) {
	// XyzInternEmployee constructor
	// generates and assigns random college and branch deatails to Interns
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
	SParm.print(out);
	return out;
}

ostream & XyzInternEmployee::print(ostream & out) {
	// prints Intern Employee details in Key: Valye Pair format
	XyzEmployee::print(out);
	if(RESIGNED == getStatus())
		return out;
	out << "College Name\t\t: " << getCollegeName() << "\n";
	out << "Branch Name\t\t: " << getBranchName() << "\n";
	return out;
}

ostream & XyzInternEmployee::print(ostream & out,unsigned int empDataParm) {
	// prints common employee details + Intern specific details
	// is used during the summary of employees (prints in table format).
	// also prints empty spaces where required (at other type employee details)
	// uses values from SubMenuTwoChoices enum
	if(((INTERN_EMPS_INFO == empDataParm) || (ALL_EMPS_INFO == empDataParm)))
		XyzEmployee::print(out, empDataParm);
	else if((EMP_GENDER_BASED_INFO/10 == empDataParm/10) && (getGender() == empDataParm%10))
		XyzEmployee::print(out, empDataParm);
	else if((EMP_STATUS_BASED_INFO/10 == empDataParm/10) && (getStatus() == empDataParm%10))
		XyzEmployee::print(out, empDataParm);
	else
		return out;
	if(ALL_EMPS_INFO == empDataParm || EMP_GENDER_BASED_INFO/10 == empDataParm/10 || EMP_STATUS_BASED_INFO/10 == empDataParm/10) {
		out << "-\t\t|"; // Total Leaves
		out << "-\t\t|"; // Availed Leaves
		out << "-\t\t|"; // Agency name
	}
	out << getCollegeName() << "\t|";
	out << getBranchName()  << "\t|";
	out << "\n";
	return out;
}