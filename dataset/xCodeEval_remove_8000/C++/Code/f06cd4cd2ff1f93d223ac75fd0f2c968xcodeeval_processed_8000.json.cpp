

using namespace std;


{\
	ios::sync_with_stdio(false);\
	cin.tie(0);\
	cout.tie(0);\
}




typedef long long ll;



typedef bool ColorType;
const bool COLOR_RED = true;
const bool COLOR_BLACK = false;

template <class T>
struct TreeNode
{
	TreeNode() : parent(0), left(0), right(0), tot(1)
	{
		
	}
	
	TreeNode(const T &x) : parent(0), left(0), right(0), value(x), tot(1)
	{
		
	}
	
	void recalSize()
	{
		tot = 1;
		if (left)
		{
			tot += left->tot;
		}
		if (right)
		{
			tot += right->tot;
		}
	}
	
	TreeNode<T> *parent;
	TreeNode<T> *left;
	TreeNode<T> *right;
	ColorType color;
	size_t tot;
	T value;
};

template<class T, class Compare, class Alloc> class RBTree;

template <class T, class Reference = T&, class ValuePointer = T*>
struct id0
{
	template<class Value, class Compare, class Alloc> 
	friend class RBTree;
	
	typedef id0<T, T&, T*> Iterator;
	typedef id0<T, const T&, const T*> ConstIterator;
	typedef id0<T, Reference, ValuePointer> Self;
	typedef TreeNode<T> *Pointer;
	
	friend  Iterator;
	friend  ConstIterator;
public:
	id0(){}
	id0(Pointer ptr) : node(ptr) {}
	id0(const Iterator &other) : node(other.node) {}
	
	Reference operator*()
	{
		return node->value;
	}
	
	ValuePointer operator->()
	{
		return &(operator*());
	}
	
	Self& operator++()
	{
		if (node->right)
		{
			node = node->right;
			while (node->left)
			{
				node = node->left;
			}
		}
		else
		{
			Pointer parent = node->parent;
			
			while (node == parent->right)
			{
				node = parent;
				parent = node->parent;
			}
			
			if (node->right != parent)
			{
				node = parent;
			}
		}
		
		return *this;
	}
	
	Self operator++(int)
	{
		Self tmp(*this);
		++(*this);
		return tmp;
	}
	
	Self& operator--()
	{
		if (node->color == COLOR_RED && node->parent->parent == node)
		{
			node = node->right;
		}
		else if (node->left)
		{
			node = node->left;
			while (node->right)
			{
				node = node->right;
			}
		}
		else
		{
			Pointer parent = node->parent;
			while (node == parent->left)
			{
				node = parent;
				parent = node->parent;
			}
			
			node = parent;
		}
		
		return *this;
	}
	
	Self operator--(int)
	{
		Self tmp(*this);
		--(*this);
		return tmp;
	}
	
	bool operator==(const Self &other) const
	{
		return node == other.node;
	}
	
	bool operator!=(const Self &other) const
	{
		return node != other.node;
	}
	
	size_t rank() const
	{	
		return rank(node);
	}
	

private:
	TreeNode<T> *node;
	bool isRoot(Pointer p) const
	{
		return p->parent->parent == p;
	}
	
	size_t rank(Pointer p) const
	{
		if (isRoot(p))
		{
			return p->left ? p->left->tot : 0;
		}
		else if (p == p->parent->left)
		{
			return p->right ? rank(p->parent) - 1 - p->right->tot : rank(p->parent) - 1;
		}
		else
		{
			return p->left ? rank(p->parent) + 1 + p->left->tot : rank(p->parent) + 1;
		}
		
		return 0;
	}
};


template <class T>
class SimpleAllocator
{
public:
	static T* allocate()
	{
		return new T;
	}
	
	static void deallocate(T *p)
	{
		delete p;
	}
	
	template <class T1>
	struct Rebind
	{
		typedef SimpleAllocator<T1> other;
	};
};

template <class T, int BUF_SIZE>
class StackAllocator
{
public:
	static T* allocate()
	{
		if (!pBuf)
		{
			pBuf = new T[BUF_SIZE];
			S = new T*[BUF_SIZE];
			for (top = 0; top < BUF_SIZE; top++)
			{
				S[top] = pBuf + top;
			}
		}
		
		return S[--top];
	}
	
	static void deallocate(T *p)
	{
		S[top++] = p;
	}
	
	template <class T1>
	struct Rebind
	{
		typedef StackAllocator<T1, BUF_SIZE> other;
	};
	
private:
	static int top;
	static T* pBuf;
	static T **S;
};

template <class T, int N>
T ** StackAllocator<T, N>::S = 0;

template <class T, int N>
T * StackAllocator<T, N>::pBuf = 0;

template <class T, int N>
int StackAllocator<T, N>::top = 0;


template <class T, class KeyCompare = less<T>, class _Alloc = SimpleAllocator<T> >
class RBTree
{
	typedef typename _Alloc::template Rebind<TreeNode<T> >::other Alloc;
	typedef TreeNode<T>* Pointer;
	typedef TreeNode<T> Node;
public:
	
	typedef id0<T> Iterator;
	typedef id0<T, const T&, const T*> ConstIterator;
	
	RBTree(const KeyCompare &cmp = KeyCompare()) : keyComp(cmp), treeSize(0)
	{
		head = getNode();
		head->left = head->right = head;
		head->parent = 0;
		head->color = COLOR_RED;
	}
	
	RBTree(const RBTree<T, KeyCompare, _Alloc> &other)
	{
		
		head = getNode();
		head->left = head->right = head;
		head->parent = 0;
		head->color = COLOR_RED;
		
		if (other.root())
		{
			root() = treeCopy(other.root(), head);
			leftMost() = minNode(root());
			rightMost() = maxNode(root());
		}
		
		treeSize = other.treeSize;
	}
	
	~RBTree()
	{
		clear();
	}
	
	void clear()
	{
		if (root())
		{
			eraseNode(root());
			leftMost() = rightMost() = head;
			root() = 0;
			treeSize = 0;
		}
	}
	
	Iterator begin()
	{
		return leftMost();
	}
	
	ConstIterator begin() const
	{
		return leftMost();
	}
	
	Iterator end()
	{
		return head;
	}
	
	ConstIterator end() const
	{
		return head;
	}
	
	bool empty() const
	{
		return treeSize == 0;
	}
	
	size_t size() const
	{
		return treeSize;
	}
	
	void swap(RBTree<T, KeyCompare, _Alloc> &other)
	{
		std::swap(head, other.head);
		std::swap(treeSize, other.treeSize);
		std::swap(keyComp, other.keyComp);
	}
	
	RBTree<T, KeyCompare, _Alloc>& operator = (const RBTree<T, KeyCompare, _Alloc> &other);
	
	pair<Iterator, bool> insertUnique(const T &x);
	Iterator insertEqual(const T &x);
	
	size_t erase(const T &x);
	void erase(Iterator pos)
	{
		deleteRebalance(pos.node, root(), leftMost(), rightMost());
		putNode(pos.node);
		--treeSize;
	}	
		
	pair<Iterator, Iterator> equalRange(const T &value)
	{
		return {lowerBound(value), upperBound(value)};
	}
	
	pair<ConstIterator, ConstIterator> equalRange(const T &value) const
	{
		return {lowerBound(value), upperBound(value)};
	}
	
	Iterator find(const T &value)
	{
		Pointer x;
		x = root();
		while (x)
		{

			if (keyComp(value, x->value))
			{
				x = x->left;
			}
			else if (keyComp(x->value, value))
			{
				x = x->right;
			}
			else
			{
				return Iterator(x);
			}
		}
		
		return end();
	}
	
	Iterator find(const T &value) const
	{
		Pointer x;
		x = root();
		while (x)
		{

			if (keyComp(value, x->value))
			{
				x = x->left;
			}
			else if (keyComp(x->value, value))
			{
				x = x->right;
			}
			else
			{
				return ConstIterator(x);
			}
		}
		
		return end();
	}
	
	size_t count(const T &value) const
	{
		auto tmp = equalRange(value);
		
		size_t res = 0;
		for (auto iter = tmp.first; iter != tmp.second; ++iter)
		{
			res++;
		}
		
		return res;
	}
	
	Iterator lowerBound(const T &value) 
	{
		Pointer y, x;
		y = head;
		x = root();
		while (x)
		{
			if (!keyComp(x->value, value))
			{
				y = x;
				x = x->left;
			}
			else
			{
				x = x->right;
			}
		}
		
		return Iterator(y);
	}
	
	ConstIterator lowerBound(const T &value) const
	{
		Pointer y, x;
		y = head;
		x = root();
		while (x)
		{
			if (!keyComp(x->value, value))
			{
				y = x;
				x = x->left;
			}
			else
			{
				x = x->right;
			}
		}
		
		return ConstIterator(y);
	}
	
	Iterator upperBound(const T &value)
	{
		Pointer y, x;
		y = head;
		x = root();
		while (x)
		{
			if (keyComp(value, x->value))
			{
				y = x;
				x = x->left;
			}
			else
			{
				x = x->right;
			}
		}
		
		return Iterator(y);
	}
	
	ConstIterator upperBound(const T &value) const
	{
		Pointer y, x;
		y = head;
		x = root();
		while (x)
		{
			if (keyComp(value, x->value))
			{
				y = x;
				x = x->left;
			}
			else
			{
				x = x->right;
			}
		}
		
		return ConstIterator(y);
	}
	
	bool verify() 
	{
		if (begin() == end() || treeSize == 0)
		{
			return treeSize == 0 && begin() == end() && leftMost() == head && rightMost() == head && root() == 0;
		}
		
		int cnt = blackCount(leftMost());
		
		for (auto iter = begin(); iter != end(); iter++)
		{
			Pointer x = iter.node;
			if (x->color == COLOR_RED)
			{
				if (x->left && x->left->color == COLOR_RED ||
					x->right && x->right->color == COLOR_RED)
				{
					return false;	
				}
			}
			
			if (x->left && keyComp(x->value, x->left->value))
			{
				return false;
			}
			
			if (x->right && keyComp(x->right->value, x->value))
			{
				return false;
			}
			
			if ((!x->left || !x->right) && blackCount(x) != cnt)
			{
				return false;
			}
			
			size_t tot = 1;
			if (x->left)
			{
				tot += x->left->tot;
			}
			if (x->right)
			{
				tot += x->right->tot;
			}
			if (tot != x->tot)
			{
				return false;
			}
		}
		
		if (leftMost() != minNode(root()))
		{
			return false;
		}
		if (rightMost() != maxNode(root()))
		{
			return false;
		}
		
		return true;
	}
	
	int blackCount(Pointer x) 
	{
		if (x == head)
		{
			return 0;
		}
		
		if (x->color == COLOR_RED)
		{
			return x == root() ? 0 : blackCount(x->parent);
		}
		else
		{
			return x == root() ? 1 : blackCount(x->parent);
		}
		
		return 0;
	}
	
private:
	
	
	Pointer head;
	size_t treeSize;
	KeyCompare keyComp;
	
	void eraseNode(Pointer p);
	void insertRebalance(Pointer x, Pointer &root);
	void deleteRebalance(Pointer z, Pointer &root, Pointer &leftMost, Pointer &rightMost);
	Iterator insert(Pointer y, const T &v);
	
	Pointer minNode(Pointer x)
	{
		while (x->left)
		{
			x = x->left;
		}
		
		return x;
	}
	
	Pointer maxNode(Pointer x)
	{
		while (x->right)
		{
			x = x->right;
		}
		return x;
	}
	
	Pointer treeCopy(Pointer x, Pointer parent)
	{
		Pointer p = cloneNode(x);
		p->parent = parent;
		if (x->left)
		{
			p->left = treeCopy(x->left, p);
		}
		
		if (x->right)
		{
			p->right = treeCopy(x->right, p);
		}
		
		return p;
	}

	Pointer createNode(const T& x)
	{
		Pointer p = getNode();
		

		new (&p->value) T(x);
		p->left = p->right = 0;
		return p;
	}
	
	Pointer cloneNode(Pointer other)
	{
		Pointer p = getNode();
		p->color = other->color;
		p->left = p->right = p->parent = 0;
		

		new (&p->value) T(other->value);
		p->tot = other->tot;
		
		return p;
	}
	
	Pointer getNode()
	{
		return Alloc::allocate();
	}
	
	void putNode(Pointer p)
	{
		Alloc::deallocate(p);
	}
	
	const Pointer& root() const
	{
		return head->parent;
	}
	
	Pointer& root()
	{
		return head->parent;
	}
	
	Pointer& leftMost()
	{
		return head->left;
	}
	
	const Pointer& leftMost() const
	{
		return head->left;
	}
	
	Pointer& rightMost() 
	{
		return head->right;
	}
	
	const Pointer& rightMost() const
	{
		return head->right;
	}
	
	void leftRotate(Pointer x, Pointer &root);
	void rightRotate(Pointer x, Pointer &root);
	void transplant(Pointer x, Pointer y, Pointer &root);

};


template <class T, class KeyCompare, class _Alloc>
RBTree<T, KeyCompare, _Alloc>& RBTree<T, KeyCompare, _Alloc>::operator = (const RBTree<T, KeyCompare, _Alloc> &other)
{
	if (this != &other)
	{
		clear();
		treeSize = other.treeSize;
		keyComp = other.keyComp;
		
		if (other.root())
		{
			head->parent = treeCopy(other.root(), head);
			leftMost() = minNode(root());
			rightMost() = maxNode(root());
		}
		
	}
	
	return *this;
}

template <class T, class KeyCompare, class _Alloc>
typename RBTree<T, KeyCompare, _Alloc>::Iterator RBTree<T, KeyCompare, _Alloc>::insert(Pointer y, const T &value)
{
	Pointer x = createNode(value);
	x->parent = y;
	x->color = COLOR_RED;
	
	if (y == head)
	{
		root() = x;
		leftMost() = rightMost() = x;
	}
	else if (keyComp(value, y->value))
	{
		y->left = x;
		if (y == leftMost())
		{
			leftMost() = x;
		}
	}
	else
	{
		y->right = x;
		if (y == rightMost())
		{
			rightMost() = x;
		}
	}
	
	insertRebalance(x, root());
	++treeSize;
	
	return Iterator(x);
}


template <class T, class KeyCompare, class _Alloc>
pair<typename RBTree<T, KeyCompare, _Alloc>::Iterator, bool> RBTree<T, KeyCompare, _Alloc>::insertUnique(const T &value)
{
	Pointer x, y;
	y = head;
	x = root();
	while (x)
	{
		y = x;
		if (keyComp(value, x->value))
		{
			x = x->left;
		}
		else if (keyComp(x->value, value))
		{
			x = x->right;
		}
		else
		{
			return {Iterator(x), false};
		}
	}
	
	return {insert(y, value), true};
}

template <class T, class KeyCompare, class _Alloc>
typename RBTree<T, KeyCompare, _Alloc>::Iterator RBTree<T, KeyCompare, _Alloc>::insertEqual(const T &value)
{
	Pointer x, y;
	y = head;
	x = root();
	
	while (x)
	{
		y = x;
		x = keyComp(value, x->value) ? x->left : x->right;
	}
	
	return insert(y, value);
}

template <class T, class KeyCompare, class _Alloc>
size_t RBTree<T, KeyCompare, _Alloc>::erase(const T &x)
{
	pair<Iterator, Iterator> tmp = equalRange(x);
	
	size_t res = 0;
	for (auto iter = tmp.first; iter != tmp.second;)
	{
		erase(iter++);
		res++;
	}
	
	return res;
}

template <class T, class KeyCompare, class _Alloc>
void RBTree<T, KeyCompare, _Alloc>::eraseNode(Pointer p)
{
	if (p->left)
	{
		eraseNode(p->left);
	}
	if (p->right)
	{
		eraseNode(p->right);
	}
	
	putNode(p);
}

template <class T, class KeyCompare, class _Alloc>
void RBTree<T, KeyCompare, _Alloc>::transplant(Pointer x, Pointer y, Pointer &root)
{
	if (x == root)
	{
		root = y;
	}
	else if (x == x->parent->left)
	{
		x->parent->left = y;
	}
	else
	{
		x->parent->right = y;
	}
	
	if (y)
	{
		y->parent = x->parent;
	}
	
}

template <class T, class KeyCompare, class _Alloc>
void RBTree<T, KeyCompare, _Alloc>::leftRotate(Pointer x, Pointer &root)
{
	Pointer y = x->right;
	
	x->right = y->left;
	if (x->right)
	{
		x->right->parent = x;
	}
	
	y->parent = x->parent;
	if (x == root)
	{
		root = y;
	}
	else if (x == x->parent->left)
	{
		x->parent->left = y;
	}
	else
	{
		x->parent->right = y;
	}
	
	x->parent = y;
	y->left = x;
}


template <class T, class KeyCompare, class _Alloc>
void RBTree<T, KeyCompare, _Alloc>::rightRotate(Pointer x, Pointer &root)
{
	Pointer y = x->left;
	
	x->left = y->right;
	if (x->left)
	{
		x->left->parent = x;
	}
	
	y->parent = x->parent;
	if (x == root)
	{
		root = y;
	}
	else if (x == x->parent->left)
	{
		x->parent->left = y;
	}
	else
	{
		x->parent->right = y;
	}
	
	x->parent = y;
	y->right = x;
}

template <class T, class KeyCompare, class _Alloc>
void RBTree<T, KeyCompare, _Alloc>::insertRebalance(Pointer x, Pointer &root)
{
	Pointer y, z;

	while (x != root && x->parent->color == COLOR_RED)
	{
		x->recalSize();
		if (x->parent == x->parent->parent->left)
		{
			y = x->parent->parent->right;
			if (y && y->color == COLOR_RED)
			{
				y->color = x->parent->color = COLOR_BLACK;
				x->parent->parent->color = COLOR_RED;
				x->parent->recalSize();
				x = x->parent->parent;
			}
			else
			{
				if (x == x->parent->right)
				{
					x = x->parent;
					leftRotate(x, root);
					x->recalSize();
				}
				x->parent->color = COLOR_BLACK;
				x->parent->parent->color = COLOR_RED;
				z = x->parent->parent;
				rightRotate(x->parent->parent, root);
				z->recalSize();
			}
		}
		else
		{
			y = x->parent->parent->left;
			if (y && y->color == COLOR_RED)
			{
				y->color = x->parent->color = COLOR_BLACK;
				x->parent->parent->color = COLOR_RED;
				x->parent->recalSize();
				x = x->parent->parent;
			}
			else
			{
				if (x == x->parent->left)
				{
					x = x->parent;
					rightRotate(x, root);
					x->recalSize();
				}
				x->parent->color = COLOR_BLACK;
				x->parent->parent->color = COLOR_RED;
				z = x->parent->parent;
				leftRotate(x->parent->parent, root);
				z->recalSize();
			}
		}
	}
	
	while (x != head)
	{
		x->recalSize();
		x = x->parent;
	}
	
	root->color = COLOR_BLACK;
}

template <class T, class KeyCompare, class _Alloc>
void RBTree<T, KeyCompare, _Alloc>::deleteRebalance(Pointer z, Pointer &root, Pointer &leftMost, Pointer &rightMost)
{
	Iterator iter;
	if (rightMost == z)
	{
		if (rightMost == leftMost)
		{
			rightMost = root->parent;
		}
		else
		{
			iter = z;
			--iter;
			rightMost = iter.node;
		}
	}
	if (leftMost == z)
	{
		iter = z;
		++iter;
		leftMost = iter.node;
	}

	Pointer x, y, xParent;
	y = z;
	ColorType orgColor = y->color;
	if (!z->left)
	{
		x = z->right;
		xParent = z->parent;
		transplant(y, x, root);
	}
	else if (!z->right)
	{
		x = z->left;
		xParent = z->parent;
		transplant(y, x, root);
	}
	else
	{
		y = z->right;
		while (y->left)
		{
			y = y->left;
		}
		
		orgColor = y->color;
		x = y->right;
		xParent = y->parent == z ? y : y->parent;
		
		transplant(y, x, root);
		y->left = z->left;
		y->left->parent = y;
		y->right = z->right;
		if (y->right)
		{
			y->right->parent = y;
		}
		y->color = z->color;
		transplant(z, y, root);
	}
	
	

	if (orgColor == COLOR_BLACK)
	{
		Pointer w;
		while (x != root && (x == 0 || x->color == COLOR_BLACK))
		{
			if (x == xParent->left)
			{
				w = xParent->right;
				
				if (w->color == COLOR_RED)
				{
					w->color = COLOR_BLACK;
					xParent->color = COLOR_RED;
					leftRotate(xParent, root);
					w = xParent->right;
				}
				
				if ((w->left == 0 || w->left->color == COLOR_BLACK) && (w->right == 0 || w->right->color == COLOR_BLACK))
				{
					w->color = COLOR_RED;
					x = xParent;
					xParent->recalSize();
					xParent = x->parent;
				}
				else
				{
					if (w->left != 0 && w->left->color == COLOR_RED)
					{
						w->left->color = COLOR_BLACK;
						w->color = COLOR_RED;
						rightRotate(w, root);
						w->recalSize();
						w = xParent->right;
						w->recalSize();
					}
					
					w->right->color = COLOR_BLACK;
					w->color = xParent->color;
					xParent->color = COLOR_BLACK;
					leftRotate(xParent, root);
					break;
				}
			}
			else
			{
				w = xParent->left;
				
				if (w->color == COLOR_RED)
				{
					w->color = COLOR_BLACK;
					xParent->color = COLOR_RED;
					rightRotate(xParent, root);
					w = xParent->left;
				}
				
				if ((w->left == 0 || w->left->color == COLOR_BLACK) && (w->right == 0 || w->right->color == COLOR_BLACK))
				{
					w->color = COLOR_RED;
					x = xParent;
					xParent->recalSize();
					xParent = x->parent;
				}
				else
				{
					if (w->right != 0 && w->right->color == COLOR_RED)
					{
						w->right->color = COLOR_BLACK;
						w->color = COLOR_RED;
						leftRotate(w, root);
						w->recalSize();
						w = xParent->left;
						w->recalSize();
					}
					
					w->left->color = COLOR_BLACK;
					w->color = xParent->color;
					xParent->color = COLOR_BLACK;
					rightRotate(xParent, root);
					break;
				}
			}
		}
		
		if (x)
		{
			x->color = COLOR_BLACK;
		}	
	}
	
	while (xParent != head)
	{
		xParent->recalSize();
		xParent = xParent->parent;
	}
}

template <class T, class KeyCompare = less<T>, class Alloc = SimpleAllocator<T> >
class Set
{
	typedef RBTree<T, KeyCompare, Alloc> TreeType;
	typedef typename TreeType::Iterator TreeIterator;
	TreeType tr;
	
public:

	typedef typename TreeType::ConstIterator Iterator;
	typedef typename TreeType::ConstIterator ConstIterator;

	explicit Set(const KeyCompare &cmp = KeyCompare()) : tr(cmp) {}
	Set(const Set<T, KeyCompare, Alloc> &other) : tr(other.tr) {}
	
	Set<T, KeyCompare, Alloc>& operator=(const Set<T, KeyCompare, Alloc> &other)
	{
		tr = other.tr;
		return *this;
	}
	
	Iterator begin() const 
	{
		return tr.begin();
	}
	
	Iterator end() const
	{
		return tr.end();
	}
	
	bool empty() const
	{
		return tr.empty();
	}
	
	size_t size() const
	{
		return tr.size();
	}
	
	void swap(const Set<T, KeyCompare, Alloc> &other)
	{
		tr.swap(other.tr);
	}
	
	pair<Iterator, bool> insert(const T &x)
	{
		pair<typename TreeType::Iterator, bool> ret = tr.insertUnique(x);
		return {(ConstIterator)ret.first, ret.second};
	}
	
	void erase(Iterator pos)
	{
		tr.erase((TreeIterator&)pos);
	}
	
	size_t erase(const T &x)
	{
		return tr.erase(x);
	}
	
	void clear()
	{
		tr.clear();
	}
	
	Iterator find(const T &x) const
	{
		return tr.find(x);
	}
	
	Iterator lowerBound(const T &x) const
	{
		return tr.lowerBound(x);
	}
	
	Iterator upperBound(const T &x) const
	{
		return tr.upperBound(x);
	}
	
	size_t count(const T &x) const
	{
		return tr.count(x);
	}
	
	pair<Iterator, Iterator> equalRange(const T &x) const
	{
		return tr.equalRange(x);
	}
	
	size_t rank(Iterator pos) const
	{
		if (pos == end())
		{
			return size();
		}
		
		return pos.rank();
	}
};


template <class T, class KeyCompare = less<T>, class Alloc = SimpleAllocator<T> >
class MultiSet
{
	typedef RBTree<T, KeyCompare, Alloc> TreeType;
	typedef typename TreeType::Iterator TreeIterator;
	TreeType tr;
	
public:

	typedef typename TreeType::ConstIterator Iterator;
	typedef typename TreeType::ConstIterator ConstIterator;

	explicit MultiSet(const KeyCompare &cmp = KeyCompare()) : tr(cmp) {}
	MultiSet(const MultiSet<T, KeyCompare, Alloc> &other) : tr(other.tr) {}
	
	MultiSet<T, KeyCompare, Alloc>& operator=(const MultiSet<T, KeyCompare, Alloc> &other)
	{
		tr = other.tr;
		return *this;
	}
	
	Iterator begin() const 
	{
		return tr.begin();
	}
	
	Iterator end() const
	{
		return tr.end();
	}
	
	bool empty() const
	{
		return tr.empty();
	}
	
	size_t size() const
	{
		return tr.size();
	}
	
	void swap(const MultiSet<T, KeyCompare, Alloc> &other)
	{
		tr.swap(other.tr);
	}
	
	Iterator insert(const T &x)
	{
		typename TreeType::Iterator ret = tr.insertEqual(x);
		return (ConstIterator)ret;
	}
	
	void erase(Iterator pos)
	{
		tr.erase((TreeIterator&)pos);
	}
	
	size_t erase(const T &x)
	{
		return tr.erase(x);
	}
	
	void clear()
	{
		tr.clear();
	}
	
	Iterator find(const T &x) const
	{
		return tr.find(x);
	}
	
	Iterator lowerBound(const T &x) const
	{
		return tr.lowerBound(x);
	}
	
	Iterator upperBound(const T &x) const
	{
		return tr.upperBound(x);
	}
	
	size_t count(const T &x) const
	{
		return tr.count(x);
	}
	
	pair<Iterator, Iterator> equalRange(const T &x) const
	{
		return tr.equalRange(x);
	}
	
	size_t rank(Iterator pos) const
	{
		if (pos == end())
		{
			return size();
		}
		
		return pos.rank();
	}
};

template <class KeyType, class ValueType, class KeyCompare = less<KeyType>, class Alloc = SimpleAllocator<int> >
class Map
{	
	typedef pair<const KeyType, ValueType> T;

	class Compare
	{
		KeyCompare cmpObj;
	public:
		Compare(const KeyCompare &obj) : cmpObj(obj) {}
		bool operator()(const T &a, const T &b) const
		{
			return cmpObj(a.first, b.first);
		}
	};
	
	
	typedef RBTree<T, Compare, Alloc> TreeType;
	typedef Map<KeyType, ValueType, Compare, Alloc> Self;
	TreeType tr;
	
public:
	typedef typename TreeType::Iterator Iterator;
	typedef typename TreeType::ConstIterator ConstIterator;
	
	explicit Map(const KeyCompare &cmp = KeyCompare()) : tr(Compare(cmp)) {}
	Map(const Self &other) : tr(other.tr) {}
	
	Self& operator=(const Self &other)
	{
		tr = other.tr;
		return *this;
	}
	
	Iterator begin()
	{
		return tr.begin();
	}
	
	ConstIterator begin() const
	{
		return tr.begin();
	}
	
	Iterator end()
	{
		return tr.end();
	}
	
	ConstIterator end() const
	{
		return tr.end();
	}
	
	bool empty() const
	{
		return tr.empty();
	}
	
	size_t size() const
	{
		return tr.size();
	}
	
	ValueType& operator[](const KeyType &key)
	{
		Iterator iter = tr.find({key, ValueType()});
		if (iter == tr.end())
		{
			iter = tr.insertUnique({key, ValueType()}).first;
		}
		
		return iter->second;
	}
	
	pair<Iterator, bool> insert(const T &x)
	{
		return tr.insertUnique(x);
	}
	
	void erase(Iterator pos)
	{
		tr.erase(pos);
	}
	
	size_t erase(const KeyType &key)
	{
		return tr.erase({key, ValueType()});
	}
	
	void swap(Self &other)
	{
		tr.swap(other.tr);
	}
	
	void clear()
	{
		tr.clear();
	}
	
	Iterator find(const KeyType &key)
	{
		return tr.find({key, ValueType()});
	}
	
	ConstIterator find(const KeyType &key) const
	{
		return tr.find({key, ValueType()});
	}

	Iterator lowerBound(const KeyType key)
	{
		return tr.lowerBound({key, ValueType()});
	}
	
	
	ConstIterator lowerBound(const KeyType key) const
	{
		return tr.lowerBound({key, ValueType()});
	}
	
	
	Iterator upperBound(const KeyType key)
	{
		return tr.upperBound({key, ValueType()});
	}
	
	ConstIterator upperBound(const KeyType key) const
	{
		return tr.upperBound({key, ValueType()});
	}
	
	size_t rank(ConstIterator pos) const
	{
		if (pos == end())
		{
			return size();
		}
		
		return pos.rank();
	}
};



const int N = 2e5 + 100;

typedef MultiSet<ll, less<ll>, StackAllocator<ll, 2*N> > SetType;

vector<pii> son[N];
int parent[N];
int a[N];
int ans[N];
ll h[N];
SetType setList[N];
int idx [N];

void dfs(int u)
{
	idx[u] = u;
	for (auto e : son[u])
	{
		int v = e.first;
		int w = e.second;
		h[v] = h[u] + w;
		dfs(v);
		
		if (setList[idx[u]].size() < setList[idx[v]].size())
		{
			swap(idx[u], idx[v]);
		}
		
		

		while (!setList[idx[v]].empty())
		{
			auto iter = setList[idx[v]].begin();
			setList[idx[u]].insert(*iter);
			setList[idx[v]].erase(iter);
		}
	}
	SetType &S = setList[idx[u]];
	auto iter = S.upperBound(h[u]);
	ans[u] = S.rank(iter);
		
	S.insert(h[u] - a[u]);
}

int main()
{
	

	int n, u, v, i, w;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	for (i = 2; i <= n; i++)
	{
		scanf("%d%d", &u, &w);
		parent[i] = u;
		son[u].push_back({i, w});
	}
	
	dfs(1);
	
	for (i = 1; i <= n; i++)
	{
		printf("%d ", ans[i]);
	}
	printf("\n");
	
	return 0;
}