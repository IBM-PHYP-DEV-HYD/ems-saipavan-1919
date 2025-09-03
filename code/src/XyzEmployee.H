#include"XyzEmployeeIF.H"
class XyzEmployee: public XyzEmployeeIf {
	// XyzEmployee class
	// Abstract class : Employee attributes, methods & virtual methods of Xyz<type>Employee
	private:
		string mName;	// fixed
		string mId;		// fixed
		string mDOB;	// fixed
		unsigned int mGender;	// fixed
		unsigned int mType;
		unsigned int mStatus;
		string mDOJ;
	public:
		//XyzEmployee(string, string, string, string);
		XyzEmployee(unsigned int, unsigned int);
		string getName();
		string getId();
		unsigned int getEmpType();
		void setEmpType(unsigned int);
		unsigned int getGender();
		unsigned int getStatus();
		void setStatus(unsigned int);
		string getDob();
		string getDoj();
		void setDoj(string);
		virtual unsigned int getTotalLeaves();
		virtual void setTotalLeaves(unsigned int);
		virtual unsigned int getAvailedLeaves();
		virtual void setAvailedLeaves(unsigned int);
		virtual string getAgencyName();
		virtual void setAgencyName(string);
		virtual string getCollegeName();
		virtual string getBranchName();
		virtual void setCollegeName(string);
		virtual void setBranchName(string);
		virtual ostream & print(ostream & out);
		friend ostream& operator<<(ostream &, XyzEmployee &);
};

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



class XyzFullTimeEmployee:public XyzEmployee {
	// XyzFullTimeEmployee class
	private:
		unsigned int mTotalLeaves;
		unsigned int mAvailedLeaves;
	public:
		//XyzFullTimeEmployee(string, string, string, string);
		XyzFullTimeEmployee(unsigned int);
		unsigned int getTotalLeaves();
		unsigned int getAvailedLeaves();
		void setTotalLeaves(unsigned int);
		void setAvailedLeaves(unsigned int);
		ostream & print(ostream &);
		friend ostream& operator<<(ostream & , XyzFullTimeEmployee &);
};

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




class XyzContractorEmployee:public XyzEmployee {
	// XyzContractorEmployee class
	private:
		string mAgencyName;
	public:
		XyzContractorEmployee(unsigned int);
		string getAgencyName();
		void setAgencyName(string);
		ostream & print(ostream &);
		friend ostream& operator<<(ostream & , XyzContractorEmployee &);
};

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



class XyzInternEmployee:public XyzEmployee {
	// XyzInterneEmployee class
	private:
		string mCollegeName;
		string mBranchName;
	public:
		XyzInternEmployee(unsigned int);
		string getCollegeName();
		void setCollegeName(string);
		string getBranchName();
		void setBranchName(string);
		ostream & print(ostream &);
		friend ostream& operator<<(ostream & , XyzInternEmployee &);
};

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