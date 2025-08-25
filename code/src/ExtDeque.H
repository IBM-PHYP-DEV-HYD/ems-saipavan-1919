template <class type>
class ExtDeque: public Deque<type> {
	// ExtDeque class : derived class from Deque class
	// contains methods to add and remove nodes at a index position
	public:
		ExtDeque();
		ExtDeque(int);
		~ExtDeque();
		void addNodeAtInd(int, type);
		void remNodeAtInd(int);
};
template <class type>
ExtDeque<type>::ExtDeque() {
	// constructor
	cout << "ExtDeque constructor" << endl;
}

template <class type>
ExtDeque<type>::ExtDeque(int sNoOfNodesParm):Deque<type>(sNoOfNodesParm) {
	// constructor : to create n number of nodes
	cout << "ExtDeque constructor with n nodes" << endl;
}

template <class type>
ExtDeque<type>:: ~ExtDeque() {
	// destructor
	cout << "ExtDeque Destructor" << endl;
}


template <class type>
void ExtDeque<type>::addNodeAtInd(int indexParm, type DataParm) {
	// this function adds a node in deque at a given index.
	cout << "Adding node at index pos : " << indexParm << endl;
	if(indexParm > this->getDequeSize()) {
		cout << "Index is out of range can't add node" << endl;
		cout << "Given Index : " << indexParm << " ";
		cout << "Size of Deque : " << this->getDequeSize() << endl;
		return;
	}
	Node<type> * sIndNode = this->operator[](indexParm-1);
	Node<type> * sNewNode = new Node<type>;
	sNewNode->setNodeData(DataParm);
	Node<type> * sNextNode = NULL;
	if(indexParm == 0)
		this->pushFront(DataParm);
	else if(sIndNode == NULL || sIndNode->getNextNode() == NULL)
		this->pushBack(DataParm);
	else {
		sNewNode->setNextNode(sIndNode->getNextNode());
		sNewNode->setPrevNode(sIndNode);
		sIndNode->setNextNode(sNewNode);
		sNextNode = sNewNode->getNextNode();
		sNextNode->setPrevNode(sNewNode);
		this->pIncrDequeSize();
	}
	//sNodePtr = this->operator[](indexParm);
	//std::cout << sNodePtr << endl;
}

template <class type>
void ExtDeque<type>::remNodeAtInd(int indexParm) {
	// this function removes a node in deque at a given index.
	cout << "Removing node at index pos : " << indexParm << endl;
	if(indexParm > this->getDequeSize()-1) {
		cout << "Index is out of range can't remove node" << endl;
		cout << "Given Index : " << indexParm << " ";
		cout << "Size of Deque : " << this->getDequeSize() << endl;
		return;
	}
	Node<type> * sIndNode = this->operator[](indexParm);
	Node<type> * sPrevNode = sIndNode->getPrevNode();
	Node<type> * sNextNode = sIndNode->getNextNode();
	if(indexParm == 0)
		this->popFront();
	else if(indexParm == (this->getDequeSize()-1))
		this->popBack();
	else {
		sPrevNode->setNextNode(sNextNode);
		sNextNode->setPrevNode(sPrevNode);
		delete sIndNode;
		this->pDecrDequeSize();
	}
}
