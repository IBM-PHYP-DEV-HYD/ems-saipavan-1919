#ifndef XYZUTILS_H
#define XYZUTILS_H
#include<iostream>
#include<string>
using namespace std;

#include<random>
#include"XyzRandData.H"

#define NUM_NAMES 3
#define NUM_GENDERS 2
#define NUM_EMPTYPES 3
#define NUM_EMPSTATUSES 3
#define NUM_AGENCY_NAMES 3
#define NUM_COLLEGES 6
#define NUM_BRANCHES 3

string * string_split(string, char, int *);
unsigned int fetchEmpIdVal(string);
unsigned int getNumOfEmps();
int checkFixCinErr();

namespace RandEmpDataGen {
	// namespace contains methods to generate random data
	int getRandomNumber(int startNumParm, int endNumParm);
	string getRandomEmpName(unsigned int GenderParm);
	unsigned int getRandomEmpGender();
	unsigned int getRandomEmpType();
	string getRandomEmpId(unsigned int idParm, unsigned int empTypeParm);
	unsigned int getRandomEmpStatus();
	string getRandomEmpDob();
	string getRandomEmpDoj(string DobParm);
	unsigned int getRanomEmpAvailedLeaves(unsigned int totalLeavesParm);
	string getRanomEmpAgency();
	string getRandomEmpCollege();
	string getRandomEmpBranch();
}
#endif
