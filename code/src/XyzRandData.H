#ifndef XYZRANDDATA_H
#define XYZRANDDATA_H

// names[][] -> names[0]-male, names[1]-female
//extern string first_names[2][NUM_NAMES] = {{"Hari", "Ram", "Josh"},{"Laxmi", "Vishnu", "vani"}};
//extern string last_names[2][NUM_NAMES] = {{"Krishna", "Bala", "Hagelwood"},{"Devi", "priya", "kumari"}};

//string EmpTypes[] = {"Full-Timer", "Contractor", "Intern"};
enum EmpTypes {
	FULLTIMER=1,
	CONTRACTOR,
	INTERN,
};

enum EmpGender {
	MALE=1,
	FEMALE,
};

enum EmpStatus {
	ACTIVE=1,
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
