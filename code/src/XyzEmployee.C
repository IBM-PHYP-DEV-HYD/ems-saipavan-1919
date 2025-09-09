#include"XyzEmployee.H"

XyzEmployee::XyzEmployee(unsigned int idParm, unsigned int typeParm) {
	// XyzEmployee constructor
	// ID val should come from Employee Manger (as it is sequential)
	cout << "I'm XyzEmployee Constructor" << endl;
	mType = typeParm;
	//mType = RandEmpDataGen::getRandomEmpType();
	mId = RandEmpDataGen::getRandomEmpId(idParm, mType);
	mGender = RandEmpDataGen::getRandomEmpGender();
	mName = RandEmpDataGen::getRandomEmpName(mGender);
	mStatus = RandEmpDataGen::getRandomEmpStatus();
	mDOB = RandEmpDataGen::getRandomEmpDob();
	mDOJ = RandEmpDataGen::getRandomEmpDoj(mDOB);
}

string XyzEmployee::getName() {
	return mName;
}

string XyzEmployee::getId() {
	return mId;
}

unsigned int XyzEmployee::getEmpType() {
	return mType;
}

void XyzEmployee::setEmpType(unsigned int EmpTypeParm) {
	mType = EmpTypeParm;
} 

unsigned int XyzEmployee::getGender() {
	return mGender;
}

unsigned int XyzEmployee::getStatus() {
	return mStatus;
}

void XyzEmployee::setStatus(unsigned int StatusParm) {
	//if(StatusParm > 0 && StatusParm < NUM_STATUSES)
	mStatus = StatusParm;
}

string XyzEmployee::getDob() {
	return mDOB;
}

string XyzEmployee::getDoj() {
	return mDOJ;
}

void XyzEmployee::setDoj(string DojParm) {
	mDOJ = DojParm;
}

ostream& operator<<(ostream & out, XyzEmployee & SParm) {
	// << operator overloading function
	//out << "Employee details:" << endl;
	out << endl;
	out << "Name\t\t|ID\t\t|Gender\t|Type\t\t|Status\t\t|DOB\t\t|";
	unsigned int sEmpType = SParm.getEmpType();
	unsigned int sStatus = SParm.getStatus();
	if(FULLTIMER == sEmpType && RESIGNED != sStatus)
		out << "Total Leaves\t|" << "Availed Leaves\t|";
	else if(CONTRACTOR == sEmpType && RESIGNED != sStatus)
		out << "Agency Name\t|";
	else if(INTERN == sEmpType && RESIGNED != sStatus)
		out << "College\t|" << "Branch\t|";
	out << endl;
	out << SParm.getName() << "\t|";
	out << SParm.getId() << "\t\t|";
	unsigned int sEmpGender = SParm.getGender();
	if(sEmpGender == MALE)
		out << "Male  " << "\t|";
	else if(sEmpGender == FEMALE)
		out << "Female" << "\t|";
	if(sEmpType == FULLTIMER)
		out << "Full-Timer" << "\t|";
	else if(sEmpType == CONTRACTOR)
		out << "Contractor" << "\t|";
	else if(sEmpType == INTERN)
		out << "Intern    " << "\t|";
	if(sStatus == ACTIVE)
		out << "ACTIVE  " << "\t|";
	else if(sStatus == INACTIVE)
		out << "INACTIVE" << "\t|";
	else if(sStatus == RESIGNED)
		out << "RESIGNED" << "\t|";
	out << SParm.getDob() << "\t|";
	return out;
}
// Below are virtual functions relate to XyzEmployee class
// start of virtual functions
unsigned int XyzEmployee::getTotalLeaves() {
	return 0;
}
unsigned int XyzEmployee::getAvailedLeaves() {
	return 0;
}
void XyzEmployee::setTotalLeaves(unsigned int totalLeavesParm) {
	;
}
void XyzEmployee::setAvailedLeaves(unsigned int availedLeavesParm) {
	;
}
string XyzEmployee::getAgencyName() {
	return "";
}
void XyzEmployee::setAgencyName(string agencyNameParm) {
	;
}
string XyzEmployee::getCollegeName() {
	return "";
}
string XyzEmployee::getBranchName() {
	return "";
}
void XyzEmployee::setBranchName(string branchNameParm) {
	;
}
void XyzEmployee::setCollegeName(string collegeNameParm) {
	;
}
ostream & XyzEmployee::print(ostream & out) {
	//cout << "Print from XyzEmployee" << endl;
	out << (*this);
	return out;
}
// end of virtual functions
