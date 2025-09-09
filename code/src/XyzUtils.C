#include"XyzUtils.H"

static string first_names[2][NUM_NAMES] = {{"Hari", "Ram", "Josh"},{"Laxmi", "Vishnu", "vani"}};
static string last_names[2][NUM_NAMES] = {{"Krishna", "Bala", "Hagelwood"},{"Devi", "priya", "kumari"}};
static string AGENCY_NAMES[] = {"Avengers", "Justice League", "Marvel"};
static string COLLEGE_NAMES[] = {"IIT Delhi", "IIT Bombay", "IIT Hyderabad", "IIT Kanpur", "NIT Warangal", "NIT Tiruchi"};
static string BRANCH_NAMES[] = {"ECE","CSE","CSIT"};

int checkFixCinErr() {
	// this function checks and fixes if there are any issues with cin input
	// returns 1 if there is any error, 0 if no error
	if(cin.fail()) {
		cout << "cin failed" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		return 1;
	}
	return 0;
}

string * string_split(string strParm, char delimiterParm, int * noOfOccurancePtrParm=NULL) {
	// this function splits a given string with the delimiterParm and returns list of strings
	unsigned int sOccurance = 0;
	for(int i=0;strParm[i]!='\0';i++) {
		if(strParm[i] == delimiterParm)
			sOccurance++;
	}
	if(!sOccurance)
		return NULL;
	if(noOfOccurancePtrParm!=NULL) // returns no.of strings using a pointer
		*noOfOccurancePtrParm = sOccurance;
	string * sSplitStrsPtr = new string[sOccurance];
	unsigned int strsIndex = 0;
	sSplitStrsPtr[0] = "";
	for(int i=0;strParm[i]!='\0';i++) {
		if((strParm[i] == delimiterParm) && (i > 0)) {
			sSplitStrsPtr[strsIndex] += '\0';
			strsIndex++;
			sSplitStrsPtr[strsIndex] = "";
			continue;
		}
		sSplitStrsPtr[strsIndex] += strParm[i];
	}
	return sSplitStrsPtr;
}


unsigned int getNumOfEmps() {
	// this function asks user input for number of employees and returns its value
	unsigned int sNumEmps;
	cout << "Enter number of Employees : ";
	cin >> sNumEmps;
	if(checkFixCinErr())
		return getNumOfEmps();
	return sNumEmps;
}

unsigned int fetchEmpIdVal(string empIdParm) {
	// this function fetches only ID value from the employee id string
	string sIdVal;
	for(int i=0;empIdParm[i]!='\0';i++) {
		if(empIdParm[i]>'0' && empIdParm[i]<='9') {
			sIdVal += empIdParm[i];
		}
		//sIdVal += '\0';
	}
	cout << sIdVal << endl;
    return stoi(sIdVal);
}

namespace RandEmpDataGen {
	int getRandomNumber(int startNumParm,
						int endNumParm)
	{
		endNumParm -= 1;
		std::random_device sRandomDevice;
		std::mt19937 sRandomNumberGenerator(sRandomDevice());
		std::uniform_int_distribution<int> sGenerate(startNumParm, endNumParm);
		int sRandomNumber = sGenerate(sRandomNumberGenerator);
		return sRandomNumber;
	}

	string getRandomEmpName(unsigned int GenderParm) {
		// this function generates random name and returns it
		// based on the gender of employee, the name will be picked from predefined lists
		string sName = first_names[GenderParm][getRandomNumber(0,NUM_NAMES)];
		sName += " ";
		sName += last_names[GenderParm][getRandomNumber(0,NUM_NAMES)];
		return sName;
	}

	unsigned int getRandomEmpGender() {
		return getRandomNumber(0,NUM_GENDERS);
	}

	unsigned int getRandomEmpType() {
		return getRandomNumber(0,NUM_EMPTYPES);
	}

	string getRandomEmpId(unsigned int idParm, unsigned int empTypeParm) {
		string sType = "\0";
		if(empTypeParm == FULLTIMER)
			sType = "F";
		else if(empTypeParm == CONTRACTOR)
			sType = "C";
		else if(empTypeParm == INTERN)
			sType = "I";
		return "Xyz" + to_string(idParm) + sType;
	}

	unsigned int getRandomEmpStatus() {
		return getRandomNumber(0,NUM_EMPSTATUSES);
	}

	string getRandomEmpDob() {
		// this function generates a random DOB for employee
		// generation will depends on few parameters like age of employee should be more than 21 years
		unsigned int sEmpDobEndYear = EMP_CURYEAR - 21;
		unsigned int sEmpDobStartYear = sEmpDobEndYear - 39; // considering 60 years as retirement age
		unsigned int sDobYear = getRandomNumber(sEmpDobStartYear, sEmpDobEndYear);
		unsigned int sDobMonth = getRandomNumber(1,13);
		unsigned int sDobDate = getRandomNumber(1,28);
		return to_string(sDobDate) + "/" + to_string(sDobMonth) + "/" + to_string(sDobYear);
	}

	string getRandomEmpDoj(string DobParm) {
		// this function generates DOJ of a employee based on his date of birth
		string * dobList = string_split(DobParm, '/');
		if(!dobList)
			return "";
		//cout << dobList[0] + " " + dobList[1] + " " + dobList[2];
		unsigned int sYear = stoi(dobList[2]);
		unsigned int sMonth = stoi(dobList[1]);
		unsigned int sDate = stoi(dobList[0]);
		delete []dobList;
		dobList = NULL;
		sYear = getRandomNumber(sYear, EMP_CURYEAR-21);
		sMonth = getRandomNumber(1,13);
		sDate = getRandomNumber(1,28);
		//cout << to_string(sDate) + "/" + to_string(sMonth) + "/" + to_string(sYear) << endl;
		return to_string(sDate) + "/" + to_string(sMonth) + "/" + to_string(sYear);
	}

	unsigned int getRanomEmpAvailedLeaves(unsigned int totalLeavesParm) {
		return getRandomNumber(0, totalLeavesParm);
	}

	string getRanomEmpAgency() {
		return AGENCY_NAMES[getRandomNumber(0,NUM_AGENCY_NAMES)];
	}

	string getRandomEmpCollege() {
		return COLLEGE_NAMES[getRandomNumber(0, NUM_COLLEGES)];
	}

	string getRandomEmpBranch() {
		return BRANCH_NAMES[getRandomNumber(0, NUM_BRANCHES)];
	}
}// end of namespace
