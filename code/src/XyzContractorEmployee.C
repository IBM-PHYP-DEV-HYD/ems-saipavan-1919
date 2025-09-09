#include"XyzContractorEmployee.H"

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
	out << static_cast<XyzEmployee&>(SParm);
	out << SParm.getAgencyName() << "\t|";
	return out;
}

ostream & XyzContractorEmployee::print(ostream & out) {
	//cout << "Print from XyzContractorEmployee" << endl;
	out << (*this);
	return out;
}

