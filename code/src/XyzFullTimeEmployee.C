#include"XyzFullTimeEmployee.H"
#include"XyzEmpManager.H"

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
	SParm.print(out);
	return out;
}

ostream & XyzFullTimeEmployee::print(ostream & out) {
	//cout << "Print from XyzFullTimeEmployee" << endl;
	//out << (*this);
	XyzEmployee::print(out);
	if(RESIGNED == getStatus())
		return out;
	out << "Total Leaves\t: " << getTotalLeaves() << "\n";
	out << "Availed Leaves\t: " << getAvailedLeaves() << "\n";
	return out;
}

ostream & XyzFullTimeEmployee::print(ostream & out, unsigned int empDataParm) {
	//cout << "Print from XyzFullTimeEmployee" << endl;
	// uses values from SubMenuTwoChoices enum
	if(((FULLTIMER_EMPS_INFO == empDataParm) || (ALL_EMPS_INFO == empDataParm)))
		XyzEmployee::print(out, empDataParm);
	else if((EMP_GENDER_BASED_INFO/10 == empDataParm/10) && (getGender() == empDataParm%10))
		XyzEmployee::print(out, empDataParm);
	else if((EMP_STATUS_BASED_INFO/10 == empDataParm/10) && (getStatus() == empDataParm%10))
		XyzEmployee::print(out, empDataParm);
	else
		return out;
	// here print data at a position based on type of employee 
	// at other places need to left it as empty
	out << getTotalLeaves() << "\t\t|";
	out << getAvailedLeaves() << "\t\t|";
	if(ALL_EMPS_INFO == empDataParm || EMP_GENDER_BASED_INFO/10 == empDataParm/10 || EMP_STATUS_BASED_INFO/10 == empDataParm/10) {
		out << "-\t\t|"; // Agency Name
		out << "-\t\t|"; // College
		out << "-\t|";   // Branch
	}
	out << "\n";
	//out << endl;
	//out << empDataParm << endl;
	//out << CONTRACTOR_EMPS_INFO << endl;
	//if(ALL_EMPS_INFO == empDataParm)
	//	out << "All emp type : " << this->getEmpType() << endl;
	//if((FULLTIMER_EMPS_INFO == empDataParm) && (FULLTIMER_EMPS_INFO%10== this->getEmpType()))
	//	out << "I'm a Fulltimer" << endl;
	/*else if((CONTRACTOR_EMPS_INFO == empDataParm) && (CONTRACTOR_EMPS_INFO%10== this->getEmpType()))
		out << "I'm a Contractor" << endl;
	else if((INTERN_EMPS_INFO == empDataParm) && (INTERN_EMPS_INFO%10 == this->getEmpType()))
		out << "I'm a Intern" << endl;
	//out << (*this);
	*/
	return out;
}
