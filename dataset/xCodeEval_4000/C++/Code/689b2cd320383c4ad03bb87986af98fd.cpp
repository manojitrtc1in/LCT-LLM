#include<bits/stdc++.h>
#define int long long
#define bro(x) (((x)->ftr->lc == (x)) ? ((x)->ftr->rc) : ((x)->ftr->lc))
#define islc(x) ((x) != NULL && (x)->ftr->lc == (x))
#define isrc(x) ((x) != NULL && (x)->ftr->rc == (x))

template<typename T>
class redblacktree {
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
#ifdef __REDBLACK_DEBUG
		void checkconnect(Node*);
		void previs(Node*, int);
		void invis(Node*, int);
		void postvis(Node*, int);
#endif

	public:

		struct iterator;

		redblacktree() : _root(NULL), _hot(NULL) {}

		int get_rank(T);
		iterator insert(T);
		bool remove(T);
		int size();
        bool empty();
		iterator kth(int);
		iterator lower_bound(T);
		iterator upper_bound(T);
#ifdef __REDBLACK_DEBUG
		void vis();
		void correctlyconnected();
#endif
};
template <typename T>
struct redblacktree<T>::Node {
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
struct redblacktree<T>::iterator {
	private:

		Node* _real__node;

	public:

		iterator& operator++() {
			_real__node = _real__node->right_node();
			return *this;
		}

		iterator& operator--() {
			_real__node = _real__node->left_node();
			return *this;
		}

		T operator*() {
			return _real__node->val;
		}

		iterator(Node* node_nn = NULL) : _real__node(node_nn) {}
		iterator(T const& val_vv) : _real__node(rfind(val_vv, 0)) {}
		iterator(iterator const& iter) : _real__node(iter._real__node) {}

};
template <typename T>
typename
redblacktree<T>::iterator redblacktree<T>::insert(T v) {
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
void redblacktree<T>::init(T v) {
	_root = new Node(v, false, NULL, NULL, NULL, 1);
#ifdef __REDBLACK_DEBUG
	++blackheight;
#endif
}
template <typename T>
typename
redblacktree<T>::Node* redblacktree<T>::find(T v, const int op) {
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
redblacktree<T>::Node* redblacktree<T>::rfind(T v, const int op) {
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
void redblacktree<T>::SolveDoubleRed(Node* nn) {
	while((!(nn->ftr)) || nn->ftr->RBc) {
		if(nn == _root) {
			_root->RBc = false;
#ifdef __REDBLACK_DEBUG
			++blackheight;
#endif
			return;
		}
		Node* pftr = nn->ftr;
		if(!(pftr->RBc)) return;			

		Node* uncle = bro(nn->ftr);
		Node* grdftr = nn->ftr->ftr;
		if(uncle != NULL && uncle->RBc) {	

			grdftr->RBc = true;
			uncle->RBc = false;
			pftr->RBc = false;
			nn = grdftr;
		} else {							

			if(islc(pftr)) {
				if(islc(nn)) {
					pftr->ftr = grdftr->ftr;
					if(grdftr == _root) _root = pftr;
					else if(grdftr->ftr->lc == grdftr) grdftr->ftr->lc = pftr;
					else grdftr->ftr->rc = pftr;
					connect34(pftr, nn, grdftr, nn->lc, nn->rc, pftr->rc, uncle);
					pftr->RBc = false;
					grdftr->RBc = true;
				} else {
					nn->ftr = grdftr->ftr;
					if(grdftr == _root) _root = nn;
					else if(grdftr->ftr->lc == grdftr) grdftr->ftr->lc = nn;
					else grdftr->ftr->rc = nn;
					connect34(nn, pftr, grdftr, pftr->lc, nn->lc, nn->rc, uncle);
					nn->RBc = false;
					grdftr->RBc = true;
				}
			} else {
				if(islc(nn)) {
					nn->ftr = grdftr->ftr;
					if(grdftr == _root) _root = nn;
					else if(grdftr->ftr->lc == grdftr) grdftr->ftr->lc = nn;
					else grdftr->ftr->rc = nn;
					connect34(nn, grdftr, pftr, uncle, nn->lc, nn->rc, pftr->rc);
					nn->RBc = false;
					grdftr->RBc = true;
				} else {
					pftr->ftr = grdftr->ftr;
					if(grdftr == _root) _root = pftr;
					else if(grdftr->ftr->lc == grdftr) grdftr->ftr->lc = pftr;
					else grdftr->ftr->rc = pftr;
					connect34(pftr, grdftr, nn, uncle, pftr->lc, nn->lc, nn->rc);
					pftr->RBc = false;
					grdftr->RBc = true;
				}
			}
			return;
		}
	}
}
template <typename T>
void redblacktree<T>::connect34(	Node* nroot,	Node* nlc,		Node* nrc,
                                    Node* ntree1,	Node* ntree2,	Node* ntree3,	Node* ntree4) {
	nlc->lc = ntree1;
	if(ntree1 != NULL) ntree1->ftr = nlc;
	nlc->rc = ntree2;
	if(ntree2 != NULL) ntree2->ftr = nlc;
	nrc->lc = ntree3;
	if(ntree3 != NULL) ntree3->ftr = nrc;
	nrc->rc = ntree4;
	if(ntree4 != NULL) ntree4->ftr = nrc;
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
redblacktree<T>::iterator redblacktree<T>::lower_bound(T v) {
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
redblacktree<T>::iterator redblacktree<T>::upper_bound(T v) {
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
redblacktree<T>::iterator redblacktree<T>::kth(int rank) {
	return iterator(findkth(rank, _root));
}

template <typename T>
typename
redblacktree<T>::Node* redblacktree<T>::findkth(int rank, Node* ptn) {
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
int redblacktree<T>::get_rank(T v) {
	return find_rank(v, _root);
}

template <typename T>
int redblacktree<T>::find_rank(T v, Node* ptn) {
	if(!ptn) return 1;
	else if(ptn->val >= v) return find_rank(v, ptn->lc);
	else return (1 + ((ptn->lc) ? (ptn->lc->s) : 0) + find_rank(v, ptn->rc));
}
using namespace std;
int n,q,t,k;
const int ddddddddddddddddddddddddddddddddddddddddddddddd=1e9+7,eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee=3e6+20;
int qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq[eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee],xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx[eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee],iqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq[eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee],ppppppppppppppppppppppppppppppppppppppppp,f[eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee],g[eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee],h[eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee];
inline int qpow(int a,int b){
	int ans=1;for(;b;b>>=1,a=a*a%ddddddddddddddddddddddddddddddddddddddddddddddd)if(b&1)ans=ans*a%ddddddddddddddddddddddddddddddddddddddddddddddd;return ans;
}
signed main(){
	scanf("%lld%lld",&n,&q);
	qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq[0]=1,ppppppppppppppppppppppppppppppppppppppppp=3*n+5;
	for(int i=1;i<=ppppppppppppppppppppppppppppppppppppppppp;++i)qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq[i]=(qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq[i-1]*i)%ddddddddddddddddddddddddddddddddddddddddddddddd;
	xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx[0]=1,xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx[1]=1;iqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq[ppppppppppppppppppppppppppppppppppppppppp]=qpow(qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq[ppppppppppppppppppppppppppppppppppppppppp],ddddddddddddddddddddddddddddddddddddddddddddddd-2);
	for(int i=2;i<=ppppppppppppppppppppppppppppppppppppppppp;++i)xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx[i]=xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx[ddddddddddddddddddddddddddddddddddddddddddddddd%i]*(ddddddddddddddddddddddddddddddddddddddddddddddd-ddddddddddddddddddddddddddddddddddddddddddddddd/i)%ddddddddddddddddddddddddddddddddddddddddddddddd;
	for(int i=ppppppppppppppppppppppppppppppppppppppppp-1;~i;--i)iqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq[i]=iqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq[i+1]*(i+1)%ddddddddddddddddddddddddddddddddddddddddddddddd;
	f[1]=(3*n-1)*n%ddddddddddddddddddddddddddddddddddddddddddddddd*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx[2]%ddddddddddddddddddddddddddddddddddddddddddddddd;
	g[1]=(3*n+1)*n%ddddddddddddddddddddddddddddddddddddddddddddddd*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx[2]%ddddddddddddddddddddddddddddddddddddddddddddddd;
	h[1]=(3*n+3)*n%ddddddddddddddddddddddddddddddddddddddddddddddd*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx[2]%ddddddddddddddddddddddddddddddddddddddddddddddd;
	for(int i=2;i<=ppppppppppppppppppppppppppppppppppppppppp;++i){
		int x=i*f[i-1]%ddddddddddddddddddddddddddddddddddddddddddddddd,y=i*g[i-1]%ddddddddddddddddddddddddddddddddddddddddddddddd,z=qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq[3*n+1]*iqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq[3*n-i]%ddddddddddddddddddddddddddddddddddddddddddddddd*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx[i+1]%ddddddddddddddddddddddddddddddddddddddddddddddd;
		int xx=z+ddddddddddddddddddddddddddddddddddddddddddddddd-(x*2+y)%ddddddddddddddddddddddddddddddddddddddddddddddd;
		(xx*=xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx[3])%=ddddddddddddddddddddddddddddddddddddddddddddddd;
		f[i]=xx,g[i]=(f[i]+x)%ddddddddddddddddddddddddddddddddddddddddddddddd,h[i]=(f[i]+x+y)%ddddddddddddddddddddddddddddddddddddddddddddddd;
	}
	while(q--)scanf("%lld",&t),printf("%lld\n",h[t]*iqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq[t]%ddddddddddddddddddddddddddddddddddddddddddddddd);
	return 0;
}