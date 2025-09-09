#ifndef XYZEMPLOYEE_H
#define XYZEMPLOYEE_H

#include"XyzEmployeeIF.H"
//#include"XyzUtils.H"


class XyzEmployee: public XyzEmployeeIf {
	// XyzEmployee class
	// Abstract class : Employee attributes, methods & virtual methods of Xyz<type>Employee
	private:
		string mName;	// fixed
		string mId;		// fixed
		string mDOB;	// fixed
		unsigned int mGender;	// fixed
		unsigned int mType;
		unsigned int mStatus;
		string mDOJ;
	public:
		//XyzEmployee(string, string, string, string);
		XyzEmployee(unsigned int, unsigned int);
		string getName();
		string getId();
		unsigned int getEmpType();
		void setEmpType(unsigned int);
		unsigned int getGender();
		unsigned int getStatus();
		void setStatus(unsigned int);
		string getDob();
		string getDoj();
		void setDoj(string);
		virtual unsigned int getTotalLeaves();
		virtual void setTotalLeaves(unsigned int);
		virtual unsigned int getAvailedLeaves();
		virtual void setAvailedLeaves(unsigned int);
		virtual string getAgencyName();
		virtual void setAgencyName(string);
		virtual string getCollegeName();
		virtual string getBranchName();
		virtual void setCollegeName(string);
		virtual void setBranchName(string);
		virtual ostream & print(ostream & out);
		friend ostream& operator<<(ostream &, XyzEmployee &);
};

#endif
