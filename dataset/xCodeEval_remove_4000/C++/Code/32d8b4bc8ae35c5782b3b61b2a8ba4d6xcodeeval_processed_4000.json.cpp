




using namespace std;






using namespace std;




template <class T>
class DLList;


template <class T>
class Pair
{
public:
	Pair();
	~Pair();
	void SetValues(T &v1, T &v2);
	T    GetValue1();
	T    GetValue2();
	void Print();
private:
	T value1, value2;

};

template <class T>
Pair<T>::Pair()  {}

template <class T>
Pair<T>::~Pair(){}

template <class T>
void Pair<T>::SetValues(T &v1, T &v2)
{
	value1 = v1;
	value2 = v2;
}

template <class T>
T    Pair<T>::GetValue1()
{
	return value1;
}

template <class T>
T    Pair<T>::GetValue2()
{
	return value2;
}


template <class T>
void    Pair<T>::Print()
{
	cout << "(" << value1 << "," << value2 << ")";
}


template <class T>
class DLLNode
{
public:
	DLLNode(T& val, DLLNode* next, DLLNode* prev);
	~DLLNode();

	T GetVal();
	DLLNode* GetNext();
	DLLNode* GetPrev();
	friend ostream & operator << (ostream &, const DLLNode);
private:
	T val;
	DLLNode* next;
	DLLNode* prev;
	friend class DLList<T>;
};

template <class T>
class DLList
{
public:
	DLList();
	~DLList();

	bool IsEmpty(void);
	void AddToHead(T& val);
	void AddToTail(T& val);
	void DeleteHead(void);
	void DeleteTail(void);
	bool DeleteNode(T& val);
	bool Search(T& val);
	void InsertInOrder(T& val);
	T GetHead(void);
	T GetTail(void);
	DLLNode<T>* GetHeadNode(void);
	DLLNode<T>* GetTailNode(void);
	void Clear(void);
	void Append(DLList<T>& otherList);
	void MergeInOrder(DLList<T>& otherList);
	void Print();
	void Shift(int m);
	void InsertAtMiddle(T& val)
	{
		if (this->IsEmpty())
		{
			AddToTail(val);
			return;
		}

		if (head == tail)
		{
			AddToTail(val);
			return;
		}

		int count = 0, loc;
		DLLNode<T> * p, *newnode;

		for (p = head; p != NULL; p = p->next)
			count++;

		loc = count / 2;

		for (p = head, count = 0; p != NULL; p = p->next)
		{
			count++;
			if (count == loc)
				break;
		}

		newnode = new DLLNode<T>(val, p->next, p);

		p->next = newnode;
		newnode->next->prev = newnode;

	}
	int CountRange(T& val1, T &val2);
	bool CopySublist(int position, int length, DLList<T>& resultList);
	bool CutSublist(int position, int length, DLList<T>& resultList);
	bool operator==(DLList<T> &);
	void GetListofPairs(DLList<Pair<T>> & result);
	void Sort();
	float  ListAverage();
	void PrintSubList(int startLoc, int m);
	void DuplicateTragetItems(DLList<T>& targetItems);
	void SplitTwoParts(DLList<T> & firsthalf, DLList<T> & secondhalf);
	void DeleteFromTo(unsigned long from, unsigned long to, T & value);
	int freq[1000] ;
private:
	DLLNode<T> *head, *tail;
	
	void ListSwap(DLLNode<T> *, DLLNode<T> *);
};


template <class T>
DLLNode<T>::DLLNode(T& val_,
	DLLNode<T>* next_,
	DLLNode<T>* prev_)
{
	val = val_;
	next = next_;
	prev = prev_;
}

template <class T>
DLLNode<T>::~DLLNode()
{
}

template <class T>
T DLLNode<T>::GetVal()
{
	return val;
}

template <class T>
DLLNode<T>* DLLNode<T>::GetNext()
{
	return next;
}

template <class T>
DLLNode<T>* DLLNode<T>::GetPrev()
{
	return prev;
}


template <class T>
DLList<T>::DLList(void)
{
	head = tail = NULL;

	for (int i = 0; i < 1000; i++)
		freq[i] = 0;
}

template <class T>
DLList<T>::~DLList()
{
	Clear();
}

template <class T>
void DLList<T>::Clear()
{
	DLLNode<T> *tmp, *delNode;

	for (tmp = head; tmp != NULL;)
	{
		delNode = tmp;
		tmp = tmp->next;
		delete delNode;
	}
	head = tail = NULL;
}

template <class T>
bool DLList<T>::IsEmpty(void)
{
	return head == NULL;
}

template <class T>
void DLList<T>::AddToHead(T& val)
{
	DLLNode<T>* newNode = new DLLNode<T>(val, head, NULL);

	if (head != NULL)
		head->prev = newNode;
	head = newNode;
	if (tail == NULL)
		tail = newNode;
}

template <class T>
void DLList<T>::AddToTail(T& val)
{
	DLLNode<T>* newNode = new DLLNode<T>(val, NULL, tail);

	if (tail != NULL) 

		tail->next = newNode;

	tail = newNode;
	if (head == NULL)
		head = newNode;
}

template <class T>
void DLList<T>::DeleteHead(void)
{
	DLLNode<T>* delNode = head;

	if (IsEmpty() == true)
		return;

	if (head == tail) 

		head = tail = NULL;
	else
	{
		head = delNode->next;
		head->prev = NULL;
	}
	delete delNode;
}

template <class T>
void DLList<T>::DeleteTail(void)
{
	DLLNode<T>* delNode = tail;

	if (IsEmpty() == true)
		return;

	if (head == tail) 

		head = tail = NULL;
	else
	{
		tail = delNode->prev;
		tail->next = NULL;
	}
	delete delNode;
}

template <class T>
bool DLList<T>::DeleteNode(T& val)
{
	bool found = false;

	if (IsEmpty() == true)
		return false;

	if (val == head->val)
	{
		DeleteHead();
		return true;
	}

	if (val == tail->val)
	{
		DeleteTail();
		return true;
	}

	DLLNode<T> *node, *predNode, *succNode;
	node = predNode = succNode = NULL;

	

	for (node = head->next; node != NULL; node = node->next)
	{
		if (node->val == val)
		{
			found = true;
			break;
		}
	}
	if (found == true)
	{
		

		predNode = node->prev;
		succNode = node->next;
		predNode->next = node->next;
		succNode->prev = node->prev;
		delete node;
	}
	return found;
}

template <class T>
bool DLList<T>::Search(T& val)
{
	DLLNode<T>* tmp;

	for (tmp = head; tmp != NULL; tmp = tmp->next)
	{
		if (tmp->val == val)
			return true;
	}
	return false;
}



template <class T>
void DLList<T>::InsertInOrder(T& val)
{
	DLLNode<T> *newNode, *pred, *succ, *crnt;

	if (IsEmpty() == true)
	{
		AddToHead(val);
		return;
	}
	if (val <= head->val) 

	{
		AddToHead(val);
		return;
	}
	if (val >= tail->val) 

	{
		AddToTail(val);
		return;
	}

	

	


	newNode = new DLLNode<T>(val, NULL, NULL);
	succ = pred = NULL;

	

	for (crnt = head; crnt != NULL; crnt = crnt->next)
	{
		if (crnt->val >= val)
		{
			succ = crnt;
			pred = crnt->prev;
			break;
		}
	}

	

	newNode->next = succ;
	newNode->prev = pred;
	succ->prev = newNode;
	pred->next = newNode;
}

template <class T>
T DLList<T>::GetHead(void)
{
	return head->val;
}

template <class T>
T DLList<T>::GetTail(void)
{
	return tail->val;
}

template <class T>
DLLNode<T>* DLList<T>::GetHeadNode(void)
{
	return head;
}

template <class T>
DLLNode<T>* DLList<T>::GetTailNode(void)
{
	return tail;
}

template <class T>
void DLList<T>::Append(DLList<T>& otherList)
{
	DLLNode<T>* ptr;

	for (ptr = otherList.head; ptr != NULL; ptr = ptr->next)
		AddToTail(ptr->val);

}

template <class T>
void DLList<T>::DeleteFromTo(unsigned long from, unsigned long to, T & value)
{


	DLLNode<T> * p, *DN;

	unsigned long c = 1;
	for (p = head; p != NULL && c < from; p = p->next)
		c++;

	if (p == NULL)
		return;

	while (c <= to)
	{
		if (p->val == value)
		{
			if (p == head)
			{
				this->DeleteHead();
				p = head;
			}
			else if (p == tail)
			{
				this->DeleteTail();
				freq[value] = freq[value] - 1;
				return;
			}

			else
			{
				DN = p;
				p->prev->next = p->next;
				p->next->prev = p->prev;
				p = p->next;
				
				

				delete DN;				

			}

			freq[value] = freq[value] - 1;
			if (freq[value] == 0)
				return;
			c++;

		}
		else

		{
			p = p->next;
			c++;
		}

	}

}
template <class T>
void DLList<T>::MergeInOrder(DLList<T>& otherList)
{
	if (otherList.IsEmpty() == true)
		return;
	if (IsEmpty() == true)
	{
		Append(otherList);
		return;
	}

	DLList<T> newList;

	DLLNode<T> *thisPtr, *otherPtr;

	for (thisPtr = this->head, otherPtr = otherList.head;
		thisPtr != NULL || otherPtr != NULL;)
	{
		if (otherPtr == NULL)
		{
			newList.AddToTail(thisPtr->val);
			thisPtr = thisPtr->next;
		}
		else if (thisPtr == NULL)
		{
			newList.AddToTail(otherPtr->val);
			otherPtr = otherPtr->next;
		}
		else if (thisPtr->val <= otherPtr->val)
		{
			newList.AddToTail(thisPtr->val);
			thisPtr = thisPtr->next;
		}
		else
		{
			newList.AddToTail(otherPtr->val);
			otherPtr = otherPtr->next;
		}
	}
	Clear();
	Append(newList);
}

template <class T>
void DLList<T>::Print()
{
	DLLNode<T> * node;

	for (node = head; node != NULL; node = node->next)
	{
		cout << node->val ;
	}
	


}

template <class T>
void DLList<T>::Shift(int m)
{

	for (int i = 1; i <= m; i++)
	{
		this->AddToHead(tail->val);
		this->DeleteTail();
	}
}
template <class T>
void DLList<T>::ListSwap(DLLNode<T> * node1, DLLNode<T> * node2)
{
	T temp;
	temp = node1->val;
	node1->val = node2->val;
	node2->val = temp;
}


template <class T>
void DLList<T>::Sort()
{

	if ((head == NULL) || (head == tail))
		return;


	DLLNode <T> * pi, *pj, *pleast;


	for (pi = head; pi != tail; pi = pi->next)
	{
		for (pj = pi->next, pleast = pi; pj != NULL; pj = pj->next)
			if (pj->val < pleast->val)
				pleast = pj;

		ListSwap(pleast, pi);
	}


}
template <class T>
float DLList<T>::ListAverage()
{
	DLLNode<T> * p = head;

	float sum = 0;
	float count = 0;

	while (p != NULL)
	{
		count++;
		sum += p->val;
		p = p->next;
	}


	if (count >0)
		return sum / count;
	else return 0;


}

template <class T>
int DLList<T>::CountRange(T& val1, T &val2)
{
	DLLNode<T> * p;
	int c = 0;

	for (p = head; p != NULL; p = p->next)
		if (p->val >= val1 && p->val <= val2)
			c++;


	return c;
}


template <class T>
bool DLList<T>::CopySublist(int position, int length, DLList<T>& resultList)
{
	resultList.Clear();

	if (position < 0 || length <1 || IsEmpty())
		return false;

	int start = 0;

	DLLNode<T> * p = head;

	while (p != NULL && start != position)
	{
		p = p->next;
		start++;
	}

	if (p == NULL)
		return false;

	while (length != 0 && p != NULL)
	{
		resultList.AddToTail(p->val);
		p = p->next;
		length--;
	}

	return true;
}


template <class T>
bool DLList<T>::CutSublist(int position, int length, DLList<T>& resultList)
{

	resultList.Clear();

	if (position < 0 || length <1 || IsEmpty())
		return false;

	int start = 0;

	DLLNode<T> * p = head, *from, *to;

	while (p != NULL && start != position)
	{
		p = p->next;
		start++;
	}

	if (p == NULL)
		return false;

	from = p;

	while (length != 0 && p != NULL)
	{
		resultList.AddToTail(p->val);
		to = p;
		p = p->next;
		length--;
	}


	resultList.head = from;
	resultList.tail = to;

	if (from == head)
	{
		head = to->next;

	}

	else if (p == NULL || to->next == NULL)
	{
		from->prev->next = NULL;
	}
	else
	{
		from->prev->next = p;
		p->prev = from->prev;
	}

	from->prev = NULL;
	to->next = NULL;

	return true;

}

template <class T>
bool DLList<T>::operator==(DLList<T> & otherlist)
{

	DLLNode<T> * p1, *p2;

	for (p1 = head, p2 = otherlist.head; p1 != NULL && p2 != NULL; p1 = p1->next, p2 = p2->next)
		if (p1->val != p2->val)
			return false;

	return  p1 == NULL && p2 == NULL;

}

template <class T>
void DLList<T>::GetListofPairs(DLList<Pair<T>> & result)
{
	result.Clear();

	if (head == tail)
		return;

	DLLNode<T> * p;

	for (p = head; p != tail; p = p->next)
	{
		Pair<T> pair;
		pair.SetValues(p->val, p->next->val);

		result.AddToTail(pair);
	}


}

template <class T>
void DLList<T>::PrintSubList(int startLoc, int m)
{
	if (head == NULL || startLoc<0)
		return;

	DLLNode<T> * p;

	int c = 0;

	for (p = head; c < startLoc && p != NULL; p = p->next, c++);

	if (p == NULL)
		return;

	while (p != NULL &&  m > 0)
	{
		cout << p->val << " ";
		p = p->next;
		m--;
	}

	cout << endl;

}

template <class T>
void DLList<T>::DuplicateTragetItems(DLList<T>& targetItems)
{
	if (IsEmpty()) return;

	DLLNode<T> * newNode, *p1, *p2;

	for (p1 = head; p1 != tail;)
	{
		if (targetItems.Search(p1->val))
		{
			newNode = new DLLNode<T>(p1->val, p1->next, p1);
			p1->next->prev = newNode;
			p1->next = newNode;
			p1 = newNode->next;
		}
		else
			p1 = p1->next;
	}

	if (targetItems.Search(tail->val))
		AddToTail(tail->val);

}





























































template <class T>
void DLList<T>::SplitTwoParts(DLList<T> & firsthalf, DLList<T> & secondhalf)
{
	if (IsEmpty())
		return;

	int c = 0;
	DLLNode<T> * p;

	for (p = head; p != NULL; p = p->next)
		c++;

	c = c / 2;

	for (p = head; c != 0; p = p->next)
		c--;

	firsthalf.head = head;
	firsthalf.tail = p->prev;

	secondhalf.head = p;
	secondhalf.tail = tail;

	head = tail = NULL;
	firsthalf.tail->next = NULL;
	secondhalf.head->prev = NULL;


}
template <class T>
ostream & operator << (ostream & output, const DLLNode<T> node)
{
	output << " [" << node.val << "] ";
	return output;
}












void ShiftLeft(char a[], unsigned long from, unsigned long to, unsigned long r, char c, unsigned long &count);
	char value[200011],c;
	DLList<char> a;
	bool b[200011] = { false };
int main()
{
	unsigned  long n, m,l,r,i,j,count;

	
	

	cin >> n >> m;

	cin >> value;

	for (int i = 0; i < n; i++)
	{
		a.AddToTail(value[i]);
		a.freq[value[i]] = a.freq[value[i]] + 1;
	}



	for (i = 0; i < m; i++)
	{
		cin >> l >> r >> c;

		if (a.freq[c] == 0)
			continue;
		a.DeleteFromTo(l, r, c);

	

			
			

		

		

	



	}

	a.Print();
	

	return 0;


}

void ShiftLeft(char a[], unsigned long from, unsigned long to, unsigned long r, char c, unsigned long &count)
{ 

	
	


	count = 0;
	unsigned long p,k=0,copyfrom,i;
	bool flag = false;
	for (i = from, copyfrom = from + 1; i < r;)
	{
		flag = false;
		while (a[i] == c && copyfrom<=r+1)
		{
			flag = true;
			a[i] = a[copyfrom++];
			count++;
		}		
	
		if (!flag)
			copyfrom++;

		if (!flag)
			a[i] = a[copyfrom++];
		i++;
	}
	
	for (i = r-count+1; i < to;i++)
		a[i] = a[i+count];

}