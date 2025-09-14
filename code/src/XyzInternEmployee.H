#ifndef XYZINTERNEMP_H
#define XYZINTERNEMP_H

#include"XyzEmployee.H"

class XyzInternEmployee:public XyzEmployee {
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
		ostream & print(ostream &, unsigned int);
		friend ostream& operator<<(ostream & , XyzInternEmployee &);
};

#endif
