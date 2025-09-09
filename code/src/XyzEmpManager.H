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
    ALL_EMPS_INFO=1,
    EMP_TYPE_BASED_INFO,
    FULLTIMER_EMPS_INFO,
    CONTRACTOR_EMPS_INFO,
    INTERN_EMPS_INFO,
    EMP_GENDER_BASED_INFO,
    MALE_EMPS_INFO,
    FEMALE_EMPS_INFO,
    EMP_STATUS_BASED_INFO,
    ACTIVE_EMPS_INFO,
    INACTIVE_EMPS_INFO,
    RESIGNED_EMPS_INFO,
    EMP_ID_BASED_INFO,
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
        void printEmpInfoBasedOnType(unsigned int);
        void printEmpInfoBasedOnGender(unsigned int);
        void printEmpInfoBasedOnStatus(unsigned int);
        void printEmpInfoBasedOnId(unsigned int);
        EDLL<XyzEmpIfPtr> * getActInactEmpDeque();
        EDLL<XyzEmpIfPtr> * getResignedEmpDeque();
};

#endif
