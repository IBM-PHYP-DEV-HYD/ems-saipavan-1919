#include<iostream>
using namespace std;

#include"../../generic-deque-saipavan-1919-1/code/src/common.H"
#include"../../generic-deque-saipavan-1919-1/code/src/node_class.H"
#include"../../generic-deque-saipavan-1919-1/code/src/deque_class.H"
#include"ExtDeque.H"


int main() {
	cout << "Hello world..!" << endl;
	//Deque<int> d1;
	ExtDeque<int> d2(3);
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
	}
	//d2.sample(val);
	return 0;
}
