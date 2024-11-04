


using namespace std;

























typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t   s8;
typedef int16_t  s16;
typedef int32_t  s32;
typedef int64_t  s64;

template<class T, class Comp = std::less<T>>
class FibHeap
{
 public:

  

  class FibNode
  {
  public:
    FibNode(T k, void *pl)
      :key(std::move(k)),mark(false),p(nullptr),left(nullptr),right(nullptr),child(nullptr),degree(-1),payload(pl)
    {
    }

   
    T key;
    bool mark;
    FibNode *p;
    FibNode *left;
    FibNode *right;
    FibNode *child;
    int degree;
    void *payload;
  }; 


  FibHeap() : FibHeap(std::less<T>())
    {
    }

  FibHeap(Comp comp)
      :n(0), min(nullptr), comp(comp)
  {
  }

  
  void clear() {
      

      delete_fibnodes(min);
      min = nullptr;
      n = 0;
  }

  void delete_fibnodes(FibNode *x)
  {
    if (!x)
      return;

    FibNode *cur = x;
    while(true)
      {
	
	if (cur->left && cur->left != x)
	  {
	    

	    FibNode *tmp = cur;
	    cur = cur->left;
	    if (tmp->child)
	      delete_fibnodes(tmp->child);
	    delete tmp;
	  }
	else
	  {
	    if (cur->child)
	      delete_fibnodes(cur->child);
	    delete cur;
	    break;
	  }
      }
  }

  
  void insert(FibNode *x)
  {
    

    x->degree = 0;
    

    x->p = nullptr;
    

    x->child = nullptr;
    

    x->mark = false;
    

    if ( min == nullptr)
      {
	

	min = x->left = x->right = x;
      }
    else
      {
	

	min->left->right = x;
	x->left = min->left;
	min->left = x;
	x->right = min;
	

	if ( comp(x->key, min->key) )
	  {
	    

	    min = x;
	  }
      }
    

    ++n;
  }

  
  FibNode* minimum()
  {
    return min;
  }

  
  static FibHeap* union_fibheap(FibHeap *H1, FibHeap *H2)
  {
    

    FibHeap* H = new FibHeap();
    

    H->min = H1->min;
    

    if ( H->min != nullptr && H2->min != nullptr )
      {
	H->min->right->left = H2->min->left;
	H2->min->left->right = H->min->right;
	H->min->right = H2->min;
	H2->min->left = H->min;
      }
    

    if ( H1->min == nullptr || ( H2->min != nullptr && H1->comp(H2->min->key, H1->min->key) ) )
      {
	

	H->min = H2->min;
      }
    

    H->n = H1->n + H2->n;
    

    return H;
  }

  
  FibNode* extract_min()
  {
    FibNode *z, *x, *next;
    FibNode ** childList;

    

    z = min;
    

    if ( z != nullptr )
      {
	

	x = z->child;
	if ( x != nullptr )
	  {
	    childList = new FibNode*[z->degree];
	    next = x;
	    for ( int i = 0; i < (int)z->degree; i++ )
	      {
		childList[i] = next;
		next = next->right;
	      }
	    for ( int i = 0; i < (int)z->degree; i++ )
	      {
		x = childList[i];
		

		min->left->right = x;
		x->left = min->left;
		min->left = x;
		x->right = min;
		

		x->p = nullptr;
	      }
	    delete [] childList;
	  }
	

	z->left->right = z->right;
	z->right->left = z->left;
	

	if ( z == z->right )
	  {
	    

	    min = nullptr;
	  }
	else
	  {
	    

	    min = z->right;
	    

	    consolidate();
	  }
	

	n--;
      }
    

    return z;
  }

  
  void consolidate()
  {
    FibNode* w, * next, * x, * y, * temp;
    FibNode** A, ** rootList;
    

    int d, rootSize;
    int max_degree = static_cast<int>(floor(log(static_cast<double>(n))/log(static_cast<double>(1 + sqrt(static_cast<double>(5)))/2)));

    

    A = new FibNode*[max_degree+2]; 

    

    std::fill_n(A, max_degree+2, nullptr);
    

    w = min;
    rootSize = 0;
    next = w;
    do
      {
	rootSize++;
	next = next->right;
      } while ( next != w );
    rootList = new FibNode*[rootSize];
    for ( int i = 0; i < rootSize; i++ )
      {
	rootList[i] = next;
	next = next->right;
      }
    for ( int i = 0; i < rootSize; i++ )
      {
	w = rootList[i];
	

	x = w;
	

	d = x->degree;
	

	while ( A[d] != nullptr )
	  {
	    

	    y = A[d];
	    

	    if ( comp(y->key, x->key) )
	      {
		

		temp = x;
		x = y;
		y = temp;
	      }
	    

	    fib_heap_link(y,x);
	    

	    A[d] = nullptr;
	    

	    d++;
	  }
	

	A[d] = x;
      }
    delete [] rootList;
    

    min = nullptr;
    

    for ( int i = 0; i < max_degree+2; i++ )
      {
	

	if ( A[i] != nullptr )
	  {
	    

	    if ( min == nullptr )
	      {
		

		min = A[i]->left = A[i]->right = A[i];
	      }
	    else
	      {
		

		min->left->right = A[i];
		A[i]->left = min->left;
		min->left = A[i];
		A[i]->right = min;
		

		if ( comp(A[i]->key, min->key) )
		  {
		    

		    min = A[i];
		  }
	      }
	  }
      }
    delete [] A;
  }


  void fib_heap_link( FibNode* y, FibNode* x )
  {
    

    y->left->right = y->right;
    y->right->left = y->left;
    

    if ( x->child != nullptr )
      {
	x->child->left->right = y;
	y->left = x->child->left;
	x->child->left = y;
	y->right = x->child;
      }
    else
      {
	x->child = y;
	y->right = y;
	y->left = y;
      }
    y->p = x;
    x->degree++;
    

    y->mark = false;
  }


  
  void decrease_key( FibNode* x, T k )
  {
    FibNode* y;

    

    if ( comp(x->key, k) )
      {
	

	

	return;
      }
    

    x->key = std::move(k);
    

    y = x->p;
    

    if ( y != nullptr && comp(x->key, y->key) )
      {
	

	cut(x,y);
	

	cascading_cut(y);
      }
    

    if ( comp(x->key, min->key) )
      {
	

	min = x;
      }
  }

  
  void cut( FibNode* x, FibNode* y )
  {
    

    if ( x->right == x )
      {
	y->child = nullptr;
      }
    else
      {
	x->right->left = x->left;
	x->left->right = x->right;
	if ( y->child == x )
	  {
	    y->child = x->right;
	  }
      }
    y->degree--;
    

    min->right->left = x;
    x->right = min->right;
    min->right = x;
    x->left = min;
    

    x->p = nullptr;
    

    x->mark = false;
  }


  void cascading_cut( FibNode* y )
  {
    FibNode* z;

    

    z = y->p;
    

    if ( z != nullptr )
      {
	

	if ( y->mark == false )
	  {
	    

	    y->mark = true;
	  }
	else
	  {
	    

	    cut(y,z);
	    

	    cascading_cut(z);
	  }
      }
  }

  
  void remove_fibnode( FibNode* x )
  {
    decrease_key(x,std::numeric_limits<T>::min());
    FibNode *fn = extract_min();
    delete fn;
  }

  
  bool empty() const
  {
    return n == 0;
  }

  FibNode* topNode()
  {
    return minimum();
  }

  T& top()
  {
    return minimum()->key;
  }

  void pop()
  {
    if (empty())
      return;
    FibNode *x = extract_min();
    if (x)
      delete x;
  }

  FibNode* push(T k, void *pl)
  {
    FibNode *x = new FibNode(std::move(k),pl);
    insert(x);
    return x;
  }

  FibNode* push(T k)
  {
    return push(std::move(k),nullptr);
  }

  unsigned int size()
  {
    return (unsigned int) n;
  }

  int n;
  FibNode *min;
  Comp comp;

};



u32 n;

s64 sm_p[MAXN];

V<u32> adj[MAXN];

struct vert{
	u32 ans, w, val, par;
	vert(){
		par = ans = w = val = 0;
	}
};

FibHeap<s64> path[MAXN];

vert vertices[MAXN];

FibHeap<s64>* merge(FibHeap<s64>* a, FibHeap<s64>* b){
	FibHeap<s64> res;
	return res.union_fibheap(a, b);
}

void dfs1(u32 v, u64 sm_w){
	sm_p[v] = sm_w;
	for(auto u:adj[v]){
		dfs1(u, sm_w + vertices[u].w);
	}
}

FibHeap<s64>* dfs2(u32 v){
	vert* p = &vertices[v];
	FibHeap<s64>* b = &path[v];
	for(auto u:adj[v]){
		FibHeap<s64>* a = dfs2(u);
		b = merge(a, b);
	}
	while(!(b->empty()) && b->top() < (-sm_p[v])) b->pop();
	p->ans = b->size();
	b->push(p->val - sm_p[v]);
	return b;
}

void solve(){
	dfs1(1, 0);
	dfs2(1);
	for(int i = 1; i <= n; i++){
		cout << vertices[i].ans << ' ';
	}
	cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	u32 temp, temp2;
    cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> vertices[i].val;
	}
	for(u32 i = 2; i <= n; i++){
		cin >> vertices[i].par >> vertices[i].w;
		adj[vertices[i].par].PB(i);
	}
	solve();
	path[1].clear();
    return 0;
}
