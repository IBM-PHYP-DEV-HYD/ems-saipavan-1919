#include"XyzFullTimeEmployee.H"
#include"XyzEmpManager.H"


XyzFullTimeEmployee::XyzFullTimeEmployee(unsigned int idParm):XyzEmployee(idParm, FULLTIMER) {
	// XyzFullTimeEmployee constructor
	// generates and assigns random number of leaves to employee
	cout << "I'm XyzFullTimeEmployee constructor" << endl;
	mTotalLeaves = EMP_TOTAL_LEAVES;
	mAvailedLeaves = RandEmpDataGen::getRanomEmpAvailedLeaves(mTotalLeaves);
}

XyzFullTimeEmployee::XyzFullTimeEmployee(XyzEmployeeIf * empPtrParm):XyzEmployee(empPtrParm) {
	// copy constructor
	// useful when we want to convert one type of employee to other (Intern -> FullTimer)
	cout << "I'm Fulltime employee copy constructor" << endl;
	this->setEmpType(FULLTIMER);
	mTotalLeaves = EMP_TOTAL_LEAVES;
	mAvailedLeaves = 0; // as we are converting some other type to full time
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
	// prints FullTimeEmployee details in key: Value pair format
	XyzEmployee::print(out);
	if(RESIGNED == getStatus())
		return out;
	out << "Total Leaves\t: " << getTotalLeaves() << "\n";
	out << "Availed Leaves\t: " << getAvailedLeaves() << "\n";
	return out;
}

ostream & XyzFullTimeEmployee::print(ostream & out, unsigned int empDataParm) {
	// prints common employee details + fulltimer specific details
	// is used during the summary of employees (prints in table format).
	// also prints empty spaces where required (at other type employee details)
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
	return out;
}
