#ifndef XYZEMPLOYEEMGR_H
#define XYZEMPLOYEEMGR_H

//#include"XyzUtils.H"

//#include"XyzRandData.H"
//#include"XyzEmployeeIF.H"
//#include"XyzEmployee.H"
#include"XyzFullTimeEmployee.H"
#include"XyzContractorEmployee.H"
#include"XyzInternEmployee.H"
#include"EDLL.H"
typedef XyzEmployeeIf* XyzEmpIfPtr;

enum MainMenuChoices {
    ADD_EMP=1,
    REM_EMP,
    EMP_DETAILS,
    OTHERS,
};

enum SubMenuOneChoices {
    ADD_RAND_EMP=1,
    ADD_FULLTIMER,
    ADD_CONTRACTOR,
    ADD_INTERN,
};

enum SubMenuTwoChoices {
    ALL_EMPS_INFO=10,
    EMP_TYPE_BASED_INFO=20,
    FULLTIMER_EMPS_INFO=21,
    CONTRACTOR_EMPS_INFO=22,
    INTERN_EMPS_INFO=23,
    EMP_GENDER_BASED_INFO=30,
    MALE_EMPS_INFO=31,
    FEMALE_EMPS_INFO=32,
    EMP_STATUS_BASED_INFO=40,
    ACTIVE_EMPS_INFO=41,
    INACTIVE_EMPS_INFO=42,
    RESIGNED_EMPS_INFO=43,
    EMP_ID_BASED_INFO=50,
};

enum SubMenuThreeChoices {
    ADD_LEAVES_FULLTIMERS,
    CONVERT_INTERN_FULLTIME,
    SEARCH_EMP_ID,
    SEARCH_EMP_NAME,
};

namespace XyzEmpManagerMenus {
    unsigned int chooseMainMenuChoice();
    unsigned int chooseSubMenuOneChoice();
    unsigned int chooseSubMenuTwoChoice();
    unsigned int chooseSubMenuThreeChoices();

}


class XyzEmployeeManager {
    // XyzEmployeeManager class
    // maintains and managers XyzEmployees
    private:
        //EDLL<XyzEmployeeIf *> * mActInactiEmpDeuque;
        EDLL<XyzEmpIfPtr> * mActInactEmpDeuque;
        EDLL<XyzEmpIfPtr> * mResignedEmpDeuque;
        unsigned int mEmpIdVal;
    public:
        XyzEmployeeManager();
        XyzEmployeeManager(unsigned int);
        void processEmployees();
    private:
        void addFullTimeEmployee();
        void addContractorEmployee();
        void addInternEmployee();
        void removeEmp(unsigned int);
        void printEmpInfo(unsigned int);
        void printEmpInfoBasedOnId(unsigned int);
        XyzEmpIfPtr fetchEmpBasedOnId(unsigned int, unsigned int *);
        EDLL<XyzEmpIfPtr> * getActInactEmpDeque();
        EDLL<XyzEmpIfPtr> * getResignedEmpDeque();
};

#endif
