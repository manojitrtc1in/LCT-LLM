





template<typename T>
class id2 {
	protected:
		struct Node;

		Node* _root;	

		Node* _hot;	


		void init(T);
		void connect34(Node*, Node*, Node*, Node*, Node*, Node*, Node*);
		void SolveDoubleRed(Node*);	

		void SolveDoubleBlack(Node*);	

		Node* find(T, const int);	

		Node* rfind(T, const int);	

		Node* findkth(int, Node*);
		int find_rank(T, Node*);

		void checkconnect(Node*);
		void previs(Node*, int);
		void invis(Node*, int);
		void postvis(Node*, int);


	public:

		struct iterator;

		id2() : _root(NULL), _hot(NULL) {}

		int get_rank(T);
		iterator insert(T);
		bool remove(T);
		int size();
        bool empty();
		iterator kth(int);
		iterator lower_bound(T);
		iterator upper_bound(T);

		void vis();
		void correctlyconnected();

};
template <typename T>
struct id2<T>::Node {
	T val;	

	bool RBc;	

	Node* ftr;	

	Node* lc;	

	Node* rc;	

	int s;		


	Node(	T v = T(), bool RB = true,
	        Node* f = NULL, Node* l = NULL, Node* r = NULL ,int ss = 1	)
		: val(v), RBc(RB), ftr(f), lc(l), rc(r), s(ss) {}

	Node* succ() {		

		Node* ptn = rc;
		while(ptn->lc != NULL) {
			--(ptn->s);
			ptn = ptn->lc;
		}
		return ptn;
	}

	Node* left_node() {		

		Node* ptn = this;
		if(!lc) {
			while(ptn->ftr && ptn->ftr->lc == ptn)
				ptn = ptn->ftr;
			ptn = ptn->ftr;
		} else {
			ptn = ptn->lc;
			while(ptn->rc) {
				ptn = ptn->rc;
			}
		}
		return ptn;
	}

	Node* right_node() {	

		Node* ptn = this;
		if(!rc) {
			while(ptn->ftr && ptn->ftr->rc == ptn)
				ptn = ptn->ftr;
			ptn = ptn->ftr;
		} else {
			ptn = ptn->rc;
			while(ptn->lc) {
				ptn = ptn->lc;
			}
		}
		return ptn;
	}

	void maintain() {	

		s = 1;
		if(lc) s += lc->s;
		if(rc) s += rc->s;
	}
};
template <typename T>
struct id2<T>::iterator {
	private:

		Node* id9;

	public:

		iterator& operator++() {
			id9 = id9->right_node();
			return *this;
		}

		iterator& operator--() {
			id9 = id9->left_node();
			return *this;
		}

		T operator*() {
			return id9->val;
		}

		iterator(Node* node_nn = NULL) : id9(node_nn) {}
		iterator(T const& id8) : id9(rfind(id8, 0)) {}
		iterator(iterator const& iter) : id9(iter.id9) {}

};
template <typename T>
typename
id2<T>::iterator id2<T>::insert(T v) {
	Node* ptn = find(v, 1);
	if(_hot == NULL) {
		init(v);
		return iterator(_root);
	}
	ptn = new Node(v, true, _hot, NULL, NULL, 1);
	if(	_hot->val <= v	)
		_hot->rc = ptn;
	else
		_hot->lc = ptn;
	SolveDoubleRed(ptn);
	return iterator(ptn);
}

template <typename T>
void id2<T>::init(T v) {
	_root = new Node(v, false, NULL, NULL, NULL, 1);

	++blackheight;

}
template <typename T>
typename
id2<T>::Node* id2<T>::find(T v, const int op) {
	Node* ptn = _root;	

	_hot = NULL;	

	while(ptn != NULL) {
		_hot = ptn;
		ptn->s += op;
		if(ptn->val > v)
			ptn = ptn->lc;
		else
			ptn = ptn->rc;
	}
	return ptn;
}

template <typename T>
typename
id2<T>::Node* id2<T>::rfind(T v, const int op) {
	Node* ptn = _root;
	_hot = NULL;
	while(ptn != NULL && ptn->val != v) {
		_hot = ptn;
		ptn->s += op;
		if(ptn->val > v)
			ptn = ptn->lc;
		else
			ptn = ptn->rc;
	}
	return ptn;
}
template <typename T>
void id2<T>::SolveDoubleRed(Node* nn) {
	while((!(nn->ftr)) || nn->ftr->RBc) {
		if(nn == _root) {
			_root->RBc = false;

			++blackheight;

			return;
		}
		Node* pftr = nn->ftr;
		if(!(pftr->RBc)) return;			

		Node* uncle = bro(nn->ftr);
		Node* id7 = nn->ftr->ftr;
		if(uncle != NULL && uncle->RBc) {	

			id7->RBc = true;
			uncle->RBc = false;
			pftr->RBc = false;
			nn = id7;
		} else {							

			if(islc(pftr)) {
				if(islc(nn)) {
					pftr->ftr = id7->ftr;
					if(id7 == _root) _root = pftr;
					else if(id7->ftr->lc == id7) id7->ftr->lc = pftr;
					else id7->ftr->rc = pftr;
					connect34(pftr, nn, id7, nn->lc, nn->rc, pftr->rc, uncle);
					pftr->RBc = false;
					id7->RBc = true;
				} else {
					nn->ftr = id7->ftr;
					if(id7 == _root) _root = nn;
					else if(id7->ftr->lc == id7) id7->ftr->lc = nn;
					else id7->ftr->rc = nn;
					connect34(nn, pftr, id7, pftr->lc, nn->lc, nn->rc, uncle);
					nn->RBc = false;
					id7->RBc = true;
				}
			} else {
				if(islc(nn)) {
					nn->ftr = id7->ftr;
					if(id7 == _root) _root = nn;
					else if(id7->ftr->lc == id7) id7->ftr->lc = nn;
					else id7->ftr->rc = nn;
					connect34(nn, id7, pftr, uncle, nn->lc, nn->rc, pftr->rc);
					nn->RBc = false;
					id7->RBc = true;
				} else {
					pftr->ftr = id7->ftr;
					if(id7 == _root) _root = pftr;
					else if(id7->ftr->lc == id7) id7->ftr->lc = pftr;
					else id7->ftr->rc = pftr;
					connect34(pftr, id7, nn, uncle, pftr->lc, nn->lc, nn->rc);
					pftr->RBc = false;
					id7->RBc = true;
				}
			}
			return;
		}
	}
}
template <typename T>
void id2<T>::connect34(	Node* nroot,	Node* nlc,		Node* nrc,
                                    Node* id5,	Node* id10,	Node* id0,	Node* id6) {
	nlc->lc = id5;
	if(id5 != NULL) id5->ftr = nlc;
	nlc->rc = id10;
	if(id10 != NULL) id10->ftr = nlc;
	nrc->lc = id0;
	if(id0 != NULL) id0->ftr = nrc;
	nrc->rc = id6;
	if(id6 != NULL) id6->ftr = nrc;
	nroot->lc = nlc;
	nlc->ftr = nroot;
	nroot->rc = nrc;
	nrc->ftr = nroot;
	nlc->maintain();
	nrc->maintain();
	nroot->maintain();
}
template <typename T>
typename
id2<T>::iterator id2<T>::lower_bound(T v) {
	Node* ptn = _root;
	while(ptn) {
		_hot = ptn;
		if(ptn->val < v) {
			ptn = ptn->rc;
		} else {
			ptn = ptn->lc;
		}
	}
	if(_hot->val < v) {
		ptn = _hot;
	} else {
		ptn = _hot->left_node();
	}
	return iterator(ptn);
}

template <typename T>
typename
id2<T>::iterator id2<T>::upper_bound(T v) {
	Node* ptn = _root;
	while(ptn) {
		_hot = ptn;
		if(ptn->val > v) {
			ptn = ptn->lc;
		} else {
			ptn = ptn->rc;
		}
	}
	if(_hot->val > v) {
		ptn = _hot;
	} else {
		ptn = _hot->right_node();
	}
	return iterator(ptn);
}
template <typename T>
typename
id2<T>::iterator id2<T>::kth(int rank) {
	return iterator(findkth(rank, _root));
}

template <typename T>
typename
id2<T>::Node* id2<T>::findkth(int rank, Node* ptn) {
	if(!(ptn->lc)) {
		if(rank == 1) {
			return ptn;
		} else {
			return findkth(rank - 1, ptn->rc);
		}
	} else {
		if(ptn->lc->s == rank - 1) return ptn;
		else if(ptn->lc->s >= rank) return findkth(rank, ptn->lc);
		else return findkth(rank - (ptn->lc->s) - 1, ptn->rc);
	}
}
template <typename T>
int id2<T>::get_rank(T v) {
	return find_rank(v, _root);
}

template <typename T>
int id2<T>::find_rank(T v, Node* ptn) {
	if(!ptn) return 1;
	else if(ptn->val >= v) return find_rank(v, ptn->lc);
	else return (1 + ((ptn->lc) ? (ptn->lc->s) : 0) + find_rank(v, ptn->rc));
}
using namespace std;
int n,q,t,k;
const int id1=1e9+7,id4=3e6+20;
int qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq[id4],xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx[id4],iqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq[id4],id3,f[id4],g[id4],h[id4];
inline int qpow(int a,int b){
	int ans=1;for(;b;b>>=1,a=a*a%id1)if(b&1)ans=ans*a%id1;return ans;
}
signed main(){
	scanf("%lld%lld",&n,&q);
	qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq[0]=1,id3=3*n+5;
	for(int i=1;i<=id3;++i)qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq[i]=(qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq[i-1]*i)%id1;
	xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx[0]=1,xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx[1]=1;iqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq[id3]=qpow(qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq[id3],id1-2);
	for(int i=2;i<=id3;++i)xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx[i]=xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx[id1%i]*(id1-id1/i)%id1;
	for(int i=id3-1;~i;--i)iqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq[i]=iqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq[i+1]*(i+1)%id1;
	f[1]=(3*n-1)*n%id1*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx[2]%id1;
	g[1]=(3*n+1)*n%id1*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx[2]%id1;
	h[1]=(3*n+3)*n%id1*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx[2]%id1;
	for(int i=2;i<=id3;++i){
		int x=i*f[i-1]%id1,y=i*g[i-1]%id1,z=qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq[3*n+1]*iqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq[3*n-i]%id1*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx[i+1]%id1;
		int xx=z+id1-(x*2+y)%id1;
		(xx*=xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx[3])%=id1;
		f[i]=xx,g[i]=(f[i]+x)%id1,h[i]=(f[i]+x+y)%id1;
	}
	while(q--)scanf("%lld",&t),printf("%lld\n",h[t]*iqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq[t]%id1);
	return 0;
}