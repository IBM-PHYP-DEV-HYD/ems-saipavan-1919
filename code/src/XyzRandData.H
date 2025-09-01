#define NUM_NAMES 3
#define NUM_GENDERS 2
#define NUM_EMPTYPES 3
#define NUM_EMPSTATUSES 3
#define NUM_AGENCY_NAMES 3
#define NUM_COLLEGES 6
#define NUM_BRANCHES 3

// names[][] -> names[0]-male, names[1]-female
string first_names[2][NUM_NAMES] = {{"Hari", "Ram", "Josh"},{"Laxmi", "Vishnu", "vani"}};
string last_names[2][NUM_NAMES] = {{"Krishna", "Bala", "Hagelwood"},{"Devi", "priya", "kumari"}};

//string EmpTypes[] = {"Full-Timer", "Contractor", "Intern"};
enum EmpTypes {
	FULLTIMER,
	CONTRACTOR,
	INTERN,
};

enum EmpGender {
	MALE,
	FEMALE,
};

enum EmpStatus {
	ACTIVE,
	INACTIVE,
	RESIGNED,
};

#define EMP_CURYEAR 2025
#define EMP_TOTAL_LEAVES 22

string AGENCY_NAMES[] = {"Avengers", "Justice League", "Marvel"};

string COLLEGE_NAMES[] = {"IIT Delhi", "IIT Bombay", "IIT Hyderabad", "IIT Kanpur", "NIT Warangal", "NIT Tiruchi"};
string BRANCH_NAMES[] = {"ECE","CSE","CSIT"};