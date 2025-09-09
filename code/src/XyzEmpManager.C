#include"XyzEmpManager.H"


XyzEmployeeManager::XyzEmployeeManager() {
    cout << "I'm XyzEmployeeManager constructor" << endl;
    mActInactEmpDeuque = new EDLL<XyzEmpIfPtr>;
    mResignedEmpDeuque = new EDLL<XyzEmpIfPtr>;
    mEmpIdVal = 1;
}

XyzEmployeeManager::XyzEmployeeManager(unsigned int noOfEmpsParm) {
    cout << "I'm XyzEmployeeManager constructor with num of employees :" << noOfEmpsParm << endl;
    mActInactEmpDeuque = new EDLL<XyzEmpIfPtr>;
    mResignedEmpDeuque = new EDLL<XyzEmpIfPtr>;
    mEmpIdVal = 1;
    unsigned int sEmpType;
    while(noOfEmpsParm) {
        sEmpType = RandEmpDataGen::getRandomEmpType();
        if(sEmpType == FULLTIMER)
            addFullTimeEmployee();
        else if(sEmpType == CONTRACTOR)
            addContractorEmployee();
        else if(sEmpType == INTERN)
            addInternEmployee();
        noOfEmpsParm--;
    }
}

void XyzEmployeeManager::addFullTimeEmployee() {
    // this function creates and adds full time employee (XyzFullTimeEmployee) to the EDLL
    XyzEmpIfPtr sNewEmp = new XyzFullTimeEmployee(mEmpIdVal);
    unsigned int sEmpStatus = sNewEmp->getStatus();
    if(sEmpStatus == ACTIVE || sEmpStatus == INACTIVE)
        mActInactEmpDeuque->pushBack(sNewEmp);
    else
        mResignedEmpDeuque->pushBack(sNewEmp);
    mEmpIdVal++;
}

void XyzEmployeeManager::addContractorEmployee() {
    // this function creates and adds contractor employee (XyzContractorEmployee) to the EDLL
    XyzEmpIfPtr sNewEmp = new XyzContractorEmployee(mEmpIdVal);
    unsigned int sEmpStatus = sNewEmp->getStatus();
    if(sEmpStatus == ACTIVE || sEmpStatus == INACTIVE)
        mActInactEmpDeuque->pushBack(sNewEmp);
    else
        mResignedEmpDeuque->pushBack(sNewEmp);
    mEmpIdVal++;
}

void XyzEmployeeManager::addInternEmployee() {
    // this function creates and adds Intern employee (XyzInternEmployee) to the EDLL
    XyzEmpIfPtr sNewEmp = new XyzInternEmployee(mEmpIdVal);
    unsigned int sEmpStatus = sNewEmp->getStatus();
    if(sEmpStatus == ACTIVE || sEmpStatus == INACTIVE)
        mActInactEmpDeuque->pushBack(sNewEmp);
    else
        mResignedEmpDeuque->pushBack(sNewEmp);
    mEmpIdVal++;
}

EDLL<XyzEmpIfPtr> * XyzEmployeeManager::getActInactEmpDeque() {
    return mActInactEmpDeuque;
}

EDLL<XyzEmpIfPtr> * XyzEmployeeManager::getResignedEmpDeque() {
    return mResignedEmpDeuque;
}

void XyzEmployeeManager::printEmpInfoBasedOnType(unsigned int empTypeParm) {
    // this function prints employee info based on their type (F/C/I)
    Node<XyzEmpIfPtr> * sEmpNode = NULL;
    XyzEmpIfPtr sEmpIf = NULL;
    sEmpNode = mActInactEmpDeuque->getHeadNode();
    sEmpIf = sEmpNode->getNodeData();
    while(sEmpNode) {
        if(sEmpIf->getEmpType() == empTypeParm)
            cout << sEmpIf << endl;
        //sEmpIf->print(cout,empTypeParm);
        sEmpNode = sEmpNode->getNextNode();
        if(sEmpNode)
            sEmpIf = sEmpNode->getNodeData();
    }
    sEmpNode = mResignedEmpDeuque->getHeadNode();
    sEmpIf = sEmpNode->getNodeData();
    while(sEmpNode) {
        if(sEmpIf->getEmpType() == empTypeParm)
            cout << sEmpIf << endl;
        sEmpNode = sEmpNode->getNextNode();
        if(sEmpNode)
            sEmpIf = sEmpNode->getNodeData();
    }
}

void XyzEmployeeManager::printEmpInfoBasedOnGender(unsigned int empGenderParm) {
    // this function prints employee info based on their gender (male/female)
    Node<XyzEmpIfPtr> * sEmpNode = NULL;
    XyzEmpIfPtr sEmpIf = NULL;
    sEmpNode = mActInactEmpDeuque->getHeadNode();
    sEmpIf = sEmpNode->getNodeData();
    while(sEmpNode) {
        if(sEmpIf->getGender() == empGenderParm)
            cout << sEmpIf << endl;
        //sEmpIf->print(cout,empTypeParm);
        sEmpNode = sEmpNode->getNextNode();
        if(sEmpNode)
            sEmpIf = sEmpNode->getNodeData();
    }
    sEmpNode = mResignedEmpDeuque->getHeadNode();
    sEmpIf = sEmpNode->getNodeData();
    while(sEmpNode) {
        if(sEmpIf->getGender() == empGenderParm)
            cout << sEmpIf << endl;
        sEmpNode = sEmpNode->getNextNode();
        if(sEmpNode)
            sEmpIf = sEmpNode->getNodeData();
    }
}

void XyzEmployeeManager::printEmpInfoBasedOnStatus(unsigned int empStatusParm) {
    // this function prints employee info based on their gender (male/female)
    Node<XyzEmpIfPtr> * sEmpNode = NULL;
    XyzEmpIfPtr sEmpIf = NULL;
    sEmpNode = mActInactEmpDeuque->getHeadNode();
    sEmpIf = sEmpNode->getNodeData();
    while(sEmpNode) {
        if(sEmpIf->getStatus() == empStatusParm)
            cout << sEmpIf << endl;
        //sEmpIf->print(cout,empTypeParm);
        sEmpNode = sEmpNode->getNextNode();
        if(sEmpNode)
            sEmpIf = sEmpNode->getNodeData();
    }
    sEmpNode = mResignedEmpDeuque->getHeadNode();
    sEmpIf = sEmpNode->getNodeData();
    while(sEmpNode) {
        if(sEmpIf->getStatus() == empStatusParm)
            cout << sEmpIf << endl;
        sEmpNode = sEmpNode->getNextNode();
        if(sEmpNode)
            sEmpIf = sEmpNode->getNodeData();
    }
}

void XyzEmployeeManager::printEmpInfoBasedOnId(unsigned int empIdParm) {
    // this function prints employee info based on their gender (male/female)
    Node<XyzEmpIfPtr> * sEmpNode = NULL;
    XyzEmpIfPtr sEmpIf = NULL;
    sEmpNode = mActInactEmpDeuque->getHeadNode();
    sEmpIf = sEmpNode->getNodeData();
    while(sEmpNode) {
        if(fetchEmpIdVal(sEmpIf->getId()) == empIdParm) {
            cout << sEmpIf << endl;
            return;
        }
        //sEmpIf->print(cout,empTypeParm);
        sEmpNode = sEmpNode->getNextNode();
        if(sEmpNode)
            sEmpIf = sEmpNode->getNodeData();
    }
    sEmpNode = mResignedEmpDeuque->getHeadNode();
    sEmpIf = sEmpNode->getNodeData();
    while(sEmpNode) {
        if(fetchEmpIdVal(sEmpIf->getId()) == empIdParm) {
            cout << sEmpIf << endl;
            return;
        }
        sEmpNode = sEmpNode->getNextNode();
        if(sEmpNode)
            sEmpIf = sEmpNode->getNodeData();
    }
}


void XyzEmployeeManager::processEmployees() {
    unsigned int sMainMenuChoice;
    unsigned int sSubMenuOneChoice;
    unsigned int sSubMenuTwoChoice;
    unsigned int sSubMenuThreeChoices;
    unsigned int sEmpID;
    while(1) {
        sMainMenuChoice = XyzEmpManagerMenus::chooseMainMenuChoice();
        if(sMainMenuChoice == ADD_EMP) {
            sSubMenuOneChoice = XyzEmpManagerMenus::chooseSubMenuOneChoice();
            switch (sSubMenuOneChoice)
            {
                case ADD_FULLTIMER:
                    addFullTimeEmployee();
                    break;
                case ADD_CONTRACTOR:
                    addContractorEmployee();
                    break;
                case ADD_INTERN:
                    addInternEmployee();
                    break;
                default:
                    break;
            }
        }
        else if(sMainMenuChoice == EMP_DETAILS) {
            sSubMenuTwoChoice = XyzEmpManagerMenus::chooseSubMenuTwoChoice();
            switch(sSubMenuTwoChoice) {
                case ALL_EMPS_INFO:
                    cout << "All employee details : " << endl;
                    mActInactEmpDeuque->fwdTraverse();
                    mResignedEmpDeuque->fwdTraverse();
                    break;
                case FULLTIMER_EMPS_INFO:
                    cout << "Fulltime Employee details : " << endl;
                    printEmpInfoBasedOnType(FULLTIMER);
                    break;
                case CONTRACTOR_EMPS_INFO:
                    cout << "Contractors Employee details : " << endl;
                    printEmpInfoBasedOnType(CONTRACTOR);
                    break;
                case INTERN_EMPS_INFO:
                    cout << "Interns Employee details : " << endl;
                    printEmpInfoBasedOnType(INTERN);
                    break;
                case MALE_EMPS_INFO:
                    cout << "Male Employee details : " << endl;
                    printEmpInfoBasedOnGender(MALE);
                    break;
                case FEMALE_EMPS_INFO:
                    cout << "Female Employee details : " << endl;
                    printEmpInfoBasedOnGender(FEMALE);
                    break;
                case ACTIVE_EMPS_INFO:
                    cout << "Active Employee details : " << endl;
                    printEmpInfoBasedOnStatus(ACTIVE);
                    break;
                case INACTIVE_EMPS_INFO:
                    cout << "Active Employee details : " << endl;
                    printEmpInfoBasedOnStatus(INACTIVE);
                    break;
                case RESIGNED_EMPS_INFO:
                    cout << "Active Employee details : " << endl;
                    printEmpInfoBasedOnStatus(RESIGNED);
                    break;
                case EMP_ID_BASED_INFO:
                    cout << "Enter employee ID : ";
                    cin >> sEmpID;
                    printEmpInfoBasedOnId(sEmpID);
            }
        }
    }
}


namespace XyzEmpManagerMenus {
    unsigned int chooseMainMenuChoice() {
        unsigned int sChoice;
        cout << "Choose from Main Menu Options :" << endl;
        cout << "1) Add an Employee" << endl;
        cout << "2) Remove an Employee" << endl;
        cout << "3) Employee Details" << endl;
        cout << "4) others" << endl;
        cin >> sChoice;
        if(checkFixCinErr())
		    return chooseMainMenuChoice();
        return sChoice;
    }

    unsigned int chooseSubMenuOneChoice() {
        unsigned int sChoice;
        cout << "Choose from Sub Menu one options :" << endl;
        cout << "1) Add an Employee at Random " << endl;
        cout << "2) Add an Employee(F/C/I) " << endl;
        cout << "Choose options : ";
        cin >> sChoice;
        if(checkFixCinErr())
		    return chooseSubMenuOneChoice();
        if(sChoice == ADD_RAND_EMP)
            return RandEmpDataGen::getRandomEmpType();
        else {
            cout << "Choose Employee Type : " << endl;
            cout << "1) FullTimer" << endl;
            cout << "2) Contractor" << endl;
            cout << "3) Intern" << endl;
            cin >> sChoice;
            if(checkFixCinErr())
		        return chooseSubMenuOneChoice();
            return sChoice+1;
        }
        return 0;
    }

    unsigned int chooseSubMenuTwoChoice() {
        unsigned int sChoice;
        cout << "Choose from Sub Menu Two options :" << endl;
        cout << "1) All Employees Summary " << endl;
        cout << "2) Employees Summary(F/C/I) " << endl;
        cout << "3) Employees Summary(M/F) " << endl;
        cout << "4) Employees Summary(A/I/R) " << endl;
        cout << "5) Display Employee Details (EmpID) " << endl;
        cout << "Choose options : ";
        cin >> sChoice;
        if(checkFixCinErr())
		    return chooseSubMenuOneChoice();
        switch(sChoice) {
            case ALL_EMPS_INFO:
                return ALL_EMPS_INFO;
                break;
            case EMP_TYPE_BASED_INFO:
                cout << "1) FullTimers info" << endl;
                cout << "2) Contractors info" << endl;
                cout << "3) Interns info" << endl;
                cout << "Choose Employee Type : ";
                cin >> sChoice;
                if(checkFixCinErr())
		            return chooseSubMenuOneChoice();
                return sChoice+EMP_TYPE_BASED_INFO;
            case EMP_GENDER_BASED_INFO-3:
            //case 3:
                cout << "1) Male Emps Info" << endl;
                cout << "2) Female Emps Info" << endl;
                cout << "Choose Employee gender : ";
                cin >> sChoice;
                if(checkFixCinErr())
		            return chooseSubMenuOneChoice();
                return sChoice+EMP_GENDER_BASED_INFO;
            case EMP_STATUS_BASED_INFO-5:
                cout << "1) Active Emps Info" << endl;
                cout << "2) Inactive Emps Info" << endl;
                cout << "3) Resigned Emps Info" << endl;
                cout << "Choose employee status : ";
                cin >> sChoice;
                if(checkFixCinErr())
		            return chooseSubMenuOneChoice();
                return sChoice+EMP_STATUS_BASED_INFO;
            case EMP_ID_BASED_INFO-8:
                return EMP_ID_BASED_INFO;
        }
        return 0;
    }
}