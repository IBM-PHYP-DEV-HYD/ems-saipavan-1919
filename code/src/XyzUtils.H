#ifndef XYZUTILS_H
#define XYZUTILS_H
#include<iostream>
#include<string>
using namespace std;

#include<random>
#include"XyzRandData.H"
//#include"../../generic-deque-saipavan-1919-1/code/src/common.H"

string * string_split(string, char, int *);
unsigned int fetchEmpIdVal(string);
unsigned int getNumOfEmps();
int checkFixCinErr();

namespace RandEmpDataGen {
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
