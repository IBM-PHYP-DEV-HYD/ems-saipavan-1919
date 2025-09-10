#ifndef XYZEMPLOYEEIF_H
#define XYZEMPLOYEEIF_H

#include"XyzUtils.H"

class XyzEmployeeIf {
	// EmployeeIf class
	// interface class: pure virtual functions, no attributes
	public:
	virtual string getName()=0;
	virtual string getId()=0;
	virtual unsigned int getEmpType()=0;
	virtual void setEmpType(unsigned int)=0;
	virtual unsigned int getGender()=0;
	virtual unsigned int getStatus()=0;
	virtual void setStatus(unsigned int)=0;
	virtual string getDob()=0;
	virtual string getDoj()=0;
	virtual void setDoj(string)=0;
	virtual unsigned int getTotalLeaves()=0;
	virtual void setTotalLeaves(unsigned int)=0;
	virtual unsigned int getAvailedLeaves()=0;
	virtual void setAvailedLeaves(unsigned int)=0;
	virtual string getAgencyName()=0;
	virtual void setAgencyName(string)=0;
	virtual string getCollegeName()=0;
	virtual string getBranchName()=0;
	virtual void setCollegeName(string)=0;
	virtual void setBranchName(string)=0;
	virtual ostream & print(ostream &)=0;
	virtual ostream & print(ostream &, unsigned int)=0;
	virtual void printHeader(ostream &, unsigned int)=0;
	// need to find a way to implement opertor<< pure virtual function implementation
	//friend ostream& operator<<(ostream &, XyzEmployeeIf &);
	//friend ostream& operator<<(ostream &, XyzEmployeeIf *);
};

inline ostream & operator<<(ostream & out, XyzEmployeeIf & SParm) {
	out << "operator<< of XyzEmployeeIf reference" << endl;
	SParm.print(out);
	return out;
}

inline ostream & operator<<(ostream & out, XyzEmployeeIf * SParm) {
	out << "operator<< of XyzEmployeeIf pointer" << endl;
	SParm->print(out);
	return out;
}

#endif
