#ifndef XYZFULLTIMEREMP_H
#define XYZFULLTIMEREMP_H

#include"XyzEmployee.H"

class XyzFullTimeEmployee:public XyzEmployee {
	private:
		unsigned int mTotalLeaves;
		unsigned int mAvailedLeaves;
	public:
		XyzFullTimeEmployee(unsigned int);
		XyzFullTimeEmployee(XyzEmployeeIf *);
		unsigned int getTotalLeaves();
		unsigned int getAvailedLeaves();
		void setTotalLeaves(unsigned int);
		void setAvailedLeaves(unsigned int);
		ostream & print(ostream &);
		ostream & print(ostream &, unsigned int);
		friend ostream& operator<<(ostream & , XyzFullTimeEmployee &);
};

#endif
