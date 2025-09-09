#include<iostream>
using namespace std;

//#include"../../generic-deque-saipavan-1919-1/code/src/common.H"
//#include"../../generic-deque-saipavan-1919-1/code/src/node_class.H"
//#include"../../generic-deque-saipavan-1919-1/code/src/deque_class.H"
//#include"ExtDeque.H"
//#include"XyzUtils.H"
//#include"XyzRandData.H"
//#include"XyzEmployee.H"
//#include"XyzFullTimeEmployee.H"
//#include"XyzContractorEmployee.H"
//#include"XyzInternEmployee.H"
//#include"EDLL.H"
//typedef XyzEmployeeIf* XyzEmpIfPtr;
#include"XyzEmpManager.H"


int main() {
	cout << "Hello world..!" << endl;
	XyzEmployee a(1,1);
	cout << a;
    XyzEmployeeIf * ptr = &a;
	cout << ptr;
	//XyzFullTimeEmployee x("a", "b", "c", "d");
	XyzFullTimeEmployee x(1);
	cout << x << endl;
	ptr = &x;
	cout << x << endl;
	XyzContractorEmployee y(2);
	cout << y << endl;
	ptr = &y;
	cout << y << endl;
	XyzInternEmployee z(3);
	cout << z << endl;
	ptr = &z;
	cout << z << endl;
	//XyzEmployee * ptr = &x;
	//cout << ptr->getTotalLeaves() << endl;
	//XyzEmployeeIf * ptr2 = &x;
	//cout << (*ptr2) << endl;
	//XyzEmployee b(1,1);
	//cout << b << endl;
	//cout << ptr2->getTotalLeaves() << endl;
	//cout << (*ptr) << endl;
	//Deque<int> d1;
	/*EDLL<int> d2(3);
	d2.fwdTraverse();
	int ind = 2;
	int val = 1;
	while(1) {
		cout << "enter index and val = " << endl;
		cin >> ind >> val;
		d2.addNodeAtInd(ind,val);
		d2.fwdTraverse();
		cout << "enter index = " << endl;
		cin >> ind;
		d2.remNodeAtInd(ind);
		d2.fwdTraverse();
	}*/
	//d2.sample(val);*/
	//ExtDeque<int> a;
	//cout << a << endl;
	//XyzFullTimeEmployee a(1);
	//XyzEmpIfPtr ptr1 = &a;
	EDLL<XyzEmpIfPtr> *ptr1 = NULL;
	ptr1 = new EDLL<XyzEmpIfPtr>;
	//cout << (*ptr1) << endl;
	ptr1->addNodeAtInd(0,&z);
	ptr1->addNodeAtInd(0,&y);
	ptr1->fwdTraverse();

	//ExtDeque<XyzEmployeeIf> ed1;
	//XyzEmployeeIf * If1 = new XyzFullTimeEmployee(1);
	//ed1.addNodeAtInd(0,If1);

	/*ExtDeque<XyzEmployeeIf *> ed1;
	XyzFullTimeEmployee x(1);
	cout << &x << endl;
	ed1.addNodeAtInd(0,&x);
	ed1.fwdTraverse(); // it is printing node addresses
	cout << ed1[0] << endl; // we are getting XyzEmployeeIf * here

	cout << *p << endl;
	*/
	//cout << (*ed1[0]) << endl;
	//XyzEmpIfPtr p = &x;
	//cout << *p << endl;

	//XyzFullTimeEmployee x(1);
	//XyzFullTimeEmployee y(2);
	//XyzEmployeeIf * mdata1 = &x;
	//cout << *mdata1 << endl;

	//Deque
	//Node<XyzEmployeeIf *> *mhead = NULL;
	//Node<XyzEmployeeIf *> *mtail = NULL;

	//Node
	//Node<XyzEmployeeIf *> * mnext = NULL;
	//Node<XyzEmployeeIf *> * mprev = NULL;
	//XyzEmployeeIf * mdata = &x;

	// ExtDeque
	//ExtDeque<XyzEmployeeIf *> ed1;
	//ed1.addNodeAtInd(0,&x);
	//ed1.addNodeAtInd(1,&y);
	//ed1.fwdTraverse();
	//cout << ed1[0] << endl;
	//cout << ed1[1] << endl;






	// above code is previous code requied to test
	unsigned int sNoOfEmps = RandEmpDataGen::getRandomNumber(4,10);
	cout << "Number of Emps : " << sNoOfEmps << endl;
	if(sNoOfEmps) {
		XyzEmployeeManager sMgr(sNoOfEmps);
		sMgr.processEmployees();
	}
	else {
		XyzEmployeeManager sMgr;
		sMgr.processEmployees();
	}
	return 0;
}
