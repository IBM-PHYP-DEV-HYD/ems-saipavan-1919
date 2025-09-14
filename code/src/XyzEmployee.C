#include"XyzEmployee.H"
#include"XyzEmpManager.H"

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

XyzEmployee::XyzEmployee(XyzEmployeeIf * empIfPtrParm) {
	// copy constructor
	// useful when converting one type of employee to other (Intern -> FullTimer)
	cout << "I'm XyzEmployee copy constructor" << endl;
	mType = empIfPtrParm->getEmpType();
	mId = empIfPtrParm->getId();
	mGender = empIfPtrParm->getGender();
	mName = empIfPtrParm->getName();
	mStatus = empIfPtrParm->getStatus();
	mDOB = empIfPtrParm->getDob();
	// DOJ need to be discussed whether to keep it same or update it.
	mDOJ = empIfPtrParm->getDoj();
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
	SParm.print(out);
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
	// prints Common Employee details in Key: Value Format
	// called by Xyz<FUlltime/Contractor/Intern>Employee objects using statis_cast
	// uses values from SubMenuTwoChoices enum
	out << "print function of XyzEmployee" << endl;
	out << "Name\t\t: " << mName << endl;
	out << "ID\t\t: " << mId << endl;
	if(mType == FULLTIMER)
		out << "Type\t\t: " << "FULLTIMER" << endl;
	else if(mType == CONTRACTOR)
		out << "Type\t\t: " << "CONTRACTOR" << endl;
	else if(mType == INTERN)
		out << "Type\t\t: " << "INTERN" << endl;
	if(mStatus == ACTIVE)
		out << "Status\t\t: ACTIVE" << endl;
	else if(mStatus == INACTIVE)
		out << "Status\t\t: INACTIVE" << endl;
	else if(mStatus == RESIGNED)
		out << "Status\t\t: RESIGNED" << endl;
	if(mGender == MALE)
		out << "Gender\t\t: MALE" << endl;
	else if(mGender == FEMALE)
		out << "Gender\t\t: FEMALE" << endl;
	out << "DOB\t\t: " << mDOB << endl;
	out << "DOJ\t\t: " << mDOJ << endl;
	return out;
}

void XyzEmployee::printHeader(ostream & out, unsigned int empDataParm) {
	// prints Header while printing Employee summary
	out << "\nName\t\t\t|ID\t\t|Gender\t\t|Type\t\t|Status\t\t|DOB\t\t|DOJ\t\t|";
	if ((ALL_EMPS_INFO == empDataParm) || (EMP_GENDER_BASED_INFO/10 == empDataParm/10) || (EMP_STATUS_BASED_INFO/10 == empDataParm/10)) {
		out << "Total Leaves\t|" << "Availed Leaves\t|" << "Agency Name\t|";
		out << "College\t|" << "Branch\t|";
	}
	else if(FULLTIMER_EMPS_INFO == empDataParm)
		out << "Total Leaves\t|" << "Availed Leaves\t|";
	else if(CONTRACTOR_EMPS_INFO == empDataParm)
		out << "Agency Name\t|";
	else if(INTERN_EMPS_INFO == empDataParm)
		out << "College\t|" << "Branch\t|";
	out << endl;
}

ostream & XyzEmployee::print(ostream & out, unsigned int empDataParm) {
	// prints common employee details in table format
	// uses values from SubMenuTwoChoices enum
	if(ALL_EMPS_INFO == empDataParm);
	else if(((EMP_TYPE_BASED_INFO/10 == empDataParm/10)&&(mType == empDataParm%10)));
	else if(((EMP_GENDER_BASED_INFO/10 == empDataParm/10)&&(mGender == empDataParm%10)));
	else if(((EMP_STATUS_BASED_INFO/10 == empDataParm/10)&&(mStatus == empDataParm%10)));
	else
		return out;
	out << getName() << "\t\t|";
	out << getId() << "\t\t|";
	unsigned int sEmpGender = getGender();
	if(sEmpGender == MALE)
		out << "Male  " << "\t\t|";
	else if(sEmpGender == FEMALE)
		out << "Female" << "\t\t|";
	unsigned int sEmpType = getEmpType();
	if(sEmpType == FULLTIMER)
		out << "Full-Timer" << "\t|";
	else if(sEmpType == CONTRACTOR)
		out << "Contractor" << "\t|";
	else if(sEmpType == INTERN)
		out << "Intern    " << "\t|";
	unsigned int sStatus = getStatus();
	if(sStatus == ACTIVE)
		out << "ACTIVE  " << "\t|";
	else if(sStatus == INACTIVE)
		out << "INACTIVE" << "\t|";
	else if(sStatus == RESIGNED)
		out << "RESIGNED" << "\t|";
	out << getDob() << "\t|";
	out << getDoj() << "\t|";
	//out << (*this);*/
	return out;
}

// end of virtual functions
