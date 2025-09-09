#ifndef XYZRANDDATA_H
#define XYZRANDDATA_H

#define NUM_NAMES 3
#define NUM_GENDERS 2
#define NUM_EMPTYPES 3
#define NUM_EMPSTATUSES 3
#define NUM_AGENCY_NAMES 3
#define NUM_COLLEGES 6
#define NUM_BRANCHES 3

// names[][] -> names[0]-male, names[1]-female
//extern string first_names[2][NUM_NAMES] = {{"Hari", "Ram", "Josh"},{"Laxmi", "Vishnu", "vani"}};
//extern string last_names[2][NUM_NAMES] = {{"Krishna", "Bala", "Hagelwood"},{"Devi", "priya", "kumari"}};

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

//extern string AGENCY_NAMES[] = {"Avengers", "Justice League", "Marvel"};

//extern string COLLEGE_NAMES[] = {"IIT Delhi", "IIT Bombay", "IIT Hyderabad", "IIT Kanpur", "NIT Warangal", "NIT Tiruchi"};
//extern string BRANCH_NAMES[] = {"ECE","CSE","CSIT"};

enum EmpPrintSpecificParms {
	PRINT_FULLTIMER,
	PRINT_CONTRACTOR,
    PRINT_INTERN,
    PRINT_MALE,
	PRINT_FEMALE,
    PRINT_ACTIVE,
	PRINT_INACTIVE,
	PRINT_RESIGNED,
};

#endif  // XYZRANDDATA_H
