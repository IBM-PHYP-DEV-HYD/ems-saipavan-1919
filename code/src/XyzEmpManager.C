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

void XyzEmployeeManager::removeEmp(unsigned int idParm) {
    // fetch emp idParm node index
    // use the EDDL rem node at index method to remove it
    unsigned int sEmpNodeIndex = 0;
    XyzEmpIfPtr sEmpIf = fetchEmpBasedOnId(idParm, &sEmpNodeIndex);
    if(sEmpNodeIndex != -1) {
        sEmpIf->setStatus(RESIGNED);
        mResignedEmpDeuque->pushBack(sEmpIf);
        mActInactEmpDeuque->remNodeAtInd(sEmpNodeIndex);
    }
    else {
        cout << "Unable to find the employee with EMP ID : " << idParm;
        cout << " in active/inactive employee list" << endl;
    }
}

EDLL<XyzEmpIfPtr> * XyzEmployeeManager::getActInactEmpDeque() {
    return mActInactEmpDeuque;
}

EDLL<XyzEmpIfPtr> * XyzEmployeeManager::getResignedEmpDeque() {
    return mResignedEmpDeuque;
}

void XyzEmployeeManager::printEmpInfo(unsigned int empTypeParm) {
    // this function prints employee info based on their type (F/C/I)
    Node<XyzEmpIfPtr> * sEmpNode = NULL;
    XyzEmpIfPtr sEmpIf = NULL;
    sEmpNode = mActInactEmpDeuque->getHeadNode();
    sEmpIf = sEmpNode->getNodeData();
    sEmpIf->printHeader(cout,empTypeParm);
    while(sEmpNode) {
        //if(sEmpIf->getEmpType() == empTypeParm)
        //    cout << sEmpIf << endl;
        sEmpIf->print(cout,empTypeParm);
        sEmpNode = sEmpNode->getNextNode();
        if(sEmpNode)
            sEmpIf = sEmpNode->getNodeData();
    }
    sEmpNode = mResignedEmpDeuque->getHeadNode();
    sEmpIf = sEmpNode->getNodeData();
    while(sEmpNode) {
        //if(sEmpIf->getEmpType() == empTypeParm)
        //    cout << sEmpIf << endl;
        sEmpIf->print(cout,empTypeParm);
        sEmpNode = sEmpNode->getNextNode();
        if(sEmpNode)
            sEmpIf = sEmpNode->getNodeData();
    }
}

XyzEmpIfPtr XyzEmployeeManager::fetchEmpBasedOnId(unsigned int empIdParm, unsigned int *indexParm=NULL) {
    // if we pass unsigned int * indexParm as parameter then this function stores index of Node matching with
    // empIdParm in it (only from mActInactEmpDeuque)
    // this is useful when removing employee using ID
    Node<XyzEmpIfPtr> * sEmpNode = NULL;
    XyzEmpIfPtr sEmpIf = NULL;
    sEmpNode = mActInactEmpDeuque->getHeadNode();
    sEmpIf = sEmpNode->getNodeData();
    unsigned int sEmpNodeIndex = 0;
    while(sEmpNode) {
        if(fetchEmpIdVal(sEmpIf->getId()) == empIdParm) {
            //cout << "Printing Employee info" << endl;
            //cout << sEmpIf << endl;
            //sEmpIf->print(cout);
            if(empIdParm)
                 *indexParm = sEmpNodeIndex;
            return sEmpIf;
        }
        //sEmpIf->print(cout,empTypeParm);
        sEmpNode = sEmpNode->getNextNode();
        sEmpNodeIndex++;
        if(sEmpNode)
            sEmpIf = sEmpNode->getNodeData();
    }
    if(empIdParm)
        *indexParm = -1;
    sEmpNode = mResignedEmpDeuque->getHeadNode();
    sEmpIf = sEmpNode->getNodeData();
    while(sEmpNode) {
        if(fetchEmpIdVal(sEmpIf->getId()) == empIdParm) {
            //sEmpIf->print(cout);
            //cout << sEmpIf << endl;
            return sEmpIf;
        }
        sEmpNode = sEmpNode->getNextNode();
        if(sEmpNode)
            sEmpIf = sEmpNode->getNodeData();
    }
    return NULL;
}

void XyzEmployeeManager::printEmpInfoBasedOnId(unsigned int empIdParm) {
    // this function prints employee info based on their gender (male/female)
    XyzEmpIfPtr sEmpIf = fetchEmpBasedOnId(empIdParm);
    if(sEmpIf != NULL)
    {
        if(RESIGNED == sEmpIf->getStatus()) {
            cout << "Employee is already removed and is in RESIGNED employee list" << endl;
            return;
        }
    }
    else {
        cout << "Could not find Employee with ID : " << empIdParm << endl;
    }
    return;
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
        else if(sMainMenuChoice == REM_EMP) {
            cout << "Enter employee ID : ";
            cin >> sEmpID;
            removeEmp(sEmpID);
        }
        else if(sMainMenuChoice == EMP_DETAILS) {
            sSubMenuTwoChoice = XyzEmpManagerMenus::chooseSubMenuTwoChoice();
            if(sSubMenuTwoChoice != EMP_ID_BASED_INFO)
                printEmpInfo(sSubMenuTwoChoice);
            else {
                cout << "Enter employee ID : ";
                cin >> sEmpID;
                printEmpInfoBasedOnId(sEmpID);
            }
        }
        else if(sMainMenuChoice == OTHERS) {
            sSubMenuThreeChoices = XyzEmpManagerMenus::chooseSubMenuThreeChoice();
            if(sSubMenuThreeChoices == ADD_LEAVES_FULLTIMERS) {
                ;
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
        cout << "1) All Employees Summary " << endl;    // ALL_EMPS_INFO
        cout << "2) Employees Summary(F/C/I) " << endl; // EMP_TYPE_BASED_INFO
        cout << "3) Employees Summary(M/F) " << endl;   // EMP_GENDER_BASED_INFO
        cout << "4) Employees Summary(A/I/R) " << endl; // EMP_STATUS_BASED_INFO
        cout << "5) Display Employee Details (EmpID) " << endl; // EMP_ID_BASED_INFO
        cout << "Choose options : ";
        cin >> sChoice;
        if(checkFixCinErr())
		    return chooseSubMenuOneChoice();
        switch(sChoice) {
            case ALL_EMPS_INFO/10:
                return ALL_EMPS_INFO;
                break;
            case EMP_TYPE_BASED_INFO/10:
                cout << "1) FullTimers info" << endl;
                cout << "2) Contractors info" << endl;
                cout << "3) Interns info" << endl;
                cout << "Choose Employee Type : ";
                cin >> sChoice;
                if(checkFixCinErr())
		            return chooseSubMenuOneChoice();
                return sChoice+EMP_TYPE_BASED_INFO;
            case EMP_GENDER_BASED_INFO/10:
            //case 3:
                cout << "1) Male Emps Info" << endl;
                cout << "2) Female Emps Info" << endl;
                cout << "Choose Employee gender : ";
                cin >> sChoice;
                if(checkFixCinErr())
		            return chooseSubMenuOneChoice();
                return sChoice+EMP_GENDER_BASED_INFO;
            case EMP_STATUS_BASED_INFO/10:
                cout << "1) Active Emps Info" << endl;
                cout << "2) Inactive Emps Info" << endl;
                cout << "3) Resigned Emps Info" << endl;
                cout << "Choose employee status : ";
                cin >> sChoice;
                if(checkFixCinErr())
		            return chooseSubMenuOneChoice();
                return sChoice+EMP_STATUS_BASED_INFO;
            case EMP_ID_BASED_INFO/10:
                return EMP_ID_BASED_INFO;
        }
        return 0;
    }

    unsigned int chooseSubMenuThreeChoice() {
        unsigned int sChoice;
        cout << "Choose from Sub Menu Three options :" << endl;
        cout << "1) Add n number of leaves to all Full-Time employees." << endl;
        cout << "2) Convert an Intern to Full-Time employee" << endl;
        cout << "3) Search an Employee ID" << endl;
        cout << "4) Search an Employee by Name" << endl;
        cin >> sChoice;
        return sChoice;
    }
}