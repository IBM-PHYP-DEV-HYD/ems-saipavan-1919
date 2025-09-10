#include"XyzContractorEmployee.H"
#include"XyzEmpManager.H"

XyzContractorEmployee::XyzContractorEmployee(unsigned int idParm):XyzEmployee(idParm, CONTRACTOR) {
	cout << "I'm XyzContractorEmployee constructor" << endl;
	mAgencyName = RandEmpDataGen::getRanomEmpAgency();
}

string XyzContractorEmployee::getAgencyName() {
	return mAgencyName;
}

void XyzContractorEmployee::setAgencyName(string agencyNameParm) {
	mAgencyName = agencyNameParm;
}

ostream & operator<<(ostream & out, XyzContractorEmployee & SParm) {
	// static_cast is a type casting operator converts expression to specified type
	// static_cast<type>(expression), useful for derived -> base up casting
	SParm.print(out);
	return out;
}

ostream & XyzContractorEmployee::print(ostream & out) {
	//cout << "Print from XyzContractorEmployee" << endl;
	XyzEmployee::print(out);
	if(RESIGNED == getStatus())
		return out;
	out << "Agency Name\t: " << getAgencyName() << "\n";
	return out;
}


ostream & XyzContractorEmployee::print(ostream & out, unsigned int empDataParm) {
	//cout << "Print from XyzFullTimeEmployee" << endl;
	// uses values from SubMenuTwoChoices enum
	if(((CONTRACTOR_EMPS_INFO == empDataParm) || (ALL_EMPS_INFO == empDataParm)))
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
	}
	out << getAgencyName() << "\t|";
	if(ALL_EMPS_INFO == empDataParm || EMP_GENDER_BASED_INFO/10 == empDataParm/10 || EMP_STATUS_BASED_INFO/10 == empDataParm/10) {
		out << "-\t\t|"; // College
		out << "-\t|"; // Branch
	}
	out << "\n";
	// here print data at a position based on type of employee 
	// at other places need to left it as empty
	return out;
}
