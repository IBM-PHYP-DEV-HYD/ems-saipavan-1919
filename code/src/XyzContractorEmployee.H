#ifndef XYZCONTRACTOREMP_H
#define XYZCONTRACTOREMP_H

#include"XyzEmployee.H"

class XyzContractorEmployee:public XyzEmployee {
	private:
		string mAgencyName;
	public:
		XyzContractorEmployee(unsigned int);
		string getAgencyName();
		void setAgencyName(string);
		ostream & print(ostream &);
		ostream & print(ostream &, unsigned int);
		friend ostream& operator<<(ostream & , XyzContractorEmployee &);
};

#endif
