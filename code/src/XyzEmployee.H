class XyzEmployee {
	// XyzEmployee class
	// Abstract class : Employee attributes, methods & virtual methods of Xyz<type>Employee
	private:
		string mName;	// fixed
		string mId;		// fixed
		string mDOB;	// fixed
		unsigned int mGender;	// fixed
		unsigned int mType;
	public:
		//XyzEmployee(string, string, string, string);
		XyzEmployee(unsigned int);
		string getName();
		string getId();
		unsigned int getEmpType();
		unsigned int getGender();
		friend ostream& operator<<(ostream &, XyzEmployee &);
};

XyzEmployee::XyzEmployee(unsigned int idParm) {
	// XyzEmployee constructor
	// ID val should come from Employee Manger (as it is sequential)
	mType = getRandomEmpType();
	mId = getRandomEmpId(idParm, mType);
	mGender = getRandomGender();
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

unsigned int XyzEmployee::getGender() {
	return mGender;
}

ostream& operator<<(ostream & out, XyzEmployee & SParm) {
	// << operator overloading function
	out << "Employee details:" << endl;
	out << "Name\t\t|ID\t\t|Gender\t|Type\t" << endl;
	out << SParm.getName() << "\t|";
	out << SParm.getId() << "\t|";
	unsigned int sEmpGender = SParm.getGender();
	if(sEmpGender == MALE)
		out << "Male" << "\t|";
	else if(sEmpGender == FEMALE)
		out << "Female" << "\t|";
	unsigned int sEmpType = SParm.getEmpType();
	if(sEmpType == FULLTIMER)
		out << "Full-Timer" << "\t|";
	else if(sEmpType == CONTRACTOR)
		out << "Contractor" << "\t|";
	else if(sEmpType == INTERN)
		out << "Intern" << "\t|";
	out << endl;
	return out;
}



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
		friend ostream& operator<<(ostream & , XyzFullTimeEmployee &);
};

//XyzFullTimeEmployee::XyzFullTimeEmployee(string nameParm, string idParm, string dobParm, string genderParm):XyzEmployee(nameParm, idParm, dobParm, genderParm) {
XyzFullTimeEmployee::XyzFullTimeEmployee(unsigned int idParm):XyzEmployee(idParm) {
	cout << "I'm XyzFullTimeEmployee constructor" << endl;
	mTotalLeaves = 10;
	mAvailedLeaves = 5;
}

unsigned int XyzFullTimeEmployee::getTotalLeaves() {
	return mTotalLeaves;
}

unsigned int XyzFullTimeEmployee::getAvailedLeaves() {
	return mAvailedLeaves;
}

ostream & operator<<(ostream & out, XyzFullTimeEmployee & SParm) {
	// static_cast is a type casting operator converts expression to specified type
	// static_cast<type>(expression), useful for derived -> base up casting
	out << static_cast<XyzEmployee&>(SParm);
	out << "Total Leaves : " << SParm.getTotalLeaves() << endl;
	out << "Availed Leaves : " << SParm.getAvailedLeaves() << endl;
	return out;
}
