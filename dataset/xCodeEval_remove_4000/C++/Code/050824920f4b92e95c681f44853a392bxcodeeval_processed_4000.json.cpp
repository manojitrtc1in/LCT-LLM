








template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }


















using namespace std;

template<class A, class B>
ostream &operator<<(ostream &os, const pair<A,B> &p){return os<<"("<<p.fi<<","<<p.se<<")";}
template<class A, class B>
istream &operator>>(istream &is, pair<A,B> &p){return is>>p.fi>>p.se;}

template<class T>
vector<T> make_vec(size_t a){
	return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
	return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}







template <class T, class E=T>
class Treap
{
public:
    struct Node {
        Node *child[2];
        T val,sum;
        bool rev;
        uint32_t pri;
        int weight;
        Node(){}
        Node(T val, uint32_t pri):val(val),sum(val),pri(pri){
            child[0]=child[1]=nullptr;
            rev = 0; weight=1;
        }
    };
    using np = Node*;
private:
    

    inline T f(T x, T y){return x+y;}
    

    


    int n,ptr;
    vector<Node> buf;

    uint32_t xorshift(){
        static uint32_t x = 123456789;
        static uint32_t y = 362436069;
        static uint32_t z = 521288629;
        static uint32_t w = 88675123;
        uint32_t t;
        t = x ^ (x<<11);
        x = y; y = z; z = w;
        w ^= t ^ (t>>8) ^ (w>>19);
        return w;
    }

    inline np make_node(const T &val, uint32_t pri, bool dummy){
        assert(ptr<n);
        np ret = &(buf[ptr]=Node(val,pri));
        if (!dummy) ptr++;
        return ret;
    }
    inline T sum(np t){return t ? t->sum : 0;}
    inline np update(np t){
        t->weight = weight(t->child[0])+weight(t->child[1])+1;
        t->sum = f(f(sum(t->child[0]),t->val),sum(t->child[1]));
        return t;
    }
    inline void push(np t){
        

        if (t->rev){
            swap(t->child[0], t->child[1]);
            if (t->child[0]) t->child[0]->rev=true;
            if (t->child[1]) t->child[1]->rev=true;
            t->rev = false;
        }
    }
    inline np rotate(np t, int dir){
        np s = t->child[dir];
        t->child[dir] = s->child[1-dir];
        s->child[1-dir] = t;
        update(t); update(s);
        return s;
    }
    np insert(np t, int k, const T &val, uint32_t pri, bool dummy=false){
        if (!t) return make_node(val,pri,dummy);
        push(t);
        int c=weight(t->child[0]), dir=k>c;
        t->child[dir] = insert(t->child[dir],k-dir*(c+1),val,pri,dummy);
        update(t);
        if (t->pri >= t->child[dir]->pri) t = rotate(t,dir);
        return t;
    }
    np _erase(np t, int k, bool rot){
        if (!t) return nullptr;
        push(t);
        int w0=weight(t->child[0]);
        rot = rot||w0==k;
        int dir = k>w0;
        if (rot){
            if (!t->child[0]) return t->child[1];
            if (!t->child[1]) return t->child[0];
            dir = (t->child[0]->pri)<(t->child[1]->pri);
            push(t->child[1-dir]);
            t = rotate(t,1-dir);
            w0=weight(t->child[0]);
        }
        t->child[dir] = _erase(t->child[dir],k-dir*(w0+1),rot);
        update(t);
        return t;
    }
public:
    Treap(int n):n(n),buf(n),ptr(0){};
    inline int weight(np t){return t ? t->weight : 0;}
    void insert(np &t, int k, const T &val){ t = insert(t,k,val,xorshift());}
    void erase(np &t, int k){ t = _erase(t,k,false);}
    void push_back(np &t, const T &val){ t = insert(t,weight(t),val,xorshift());}

    pair<np,np> split(np t, int k){
        t = insert(t,k,0,0,true);
        return make_pair(t->child[0], t->child[1]);
    }
    np merge(np left, np right){
        np t = make_node(0,0,true);
        t->child[0] = left; t->child[1] = right;
        update(t);
        return _erase(t,weight(t->child[0]),true);
    }
    void reverse(np &t, int a, int b){
        auto p = split(t,a);
        auto q = split(p.second,b-a);
        q.first->rev = true;
        t = merge(merge(p.first,q.first),q.second);
    }
    void rotate(np &t, int a, int b, int c){
        auto p = split(t,a);
        auto q = split(p.second,c-a);
        auto r = split(q.first,b-a);
        t = merge(merge(merge(p.first,r.second),r.first),q.second);
    }
    T query(np &t, int a, int b){
        auto p = split(t,a);
        auto q = split(p.second,b-a);
        T ret = sum(q.first);
        t = merge(p.first,merge(q.first,q.second));
        return ret;
    }
    void assign(np t, int k, T x){
        assert(t); push(t);
        int c=weight(t->child[0]), dir=k>c;
        if (c==k){
            t->val = x; update(t);
            return;
        }
        assign(t->child[dir],k-dir*(c+1),x);
        update(t);
    }
    T get(np t, int k){
        assert(t); push(t);
        int c=weight(t->child[0]), dir=k>c;
        if (c==k) return t->val;
        return get(t->child[dir],k-dir*(c+1));
    }
};







template <class T>
class id0
{
protected:
    struct Node {
        Node *child[2];
        T key,sum;
        uint32_t pri;
        int weight;
        Node(){}
        Node(T key, uint32_t pri):key(key),sum(key),pri(pri),weight(1){
            child[0]=child[1]=nullptr;
        }
    };
    using np = Node*;
    using F = function<T(T,T)>;

    np root;
    int n,ptr;
    vector<Node> buf;
    const T e; const F f;

    uint32_t xorshift(){
        static uint32_t x = 123456789;
        static uint32_t y = 362436069;
        static uint32_t z = 521288629;
        static uint32_t w = 88675123;
        uint32_t t;
        t = x ^ (x<<11);
        x = y; y = z; z = w;
        w ^= t ^ (t>>8) ^ (w>>19);
        return w;
    }

    inline np make_node(const T &key, uint32_t pri, bool dummy){
        assert(ptr<n);
        np ret = &(buf[ptr]=Node(key,pri));
        if (!dummy) ptr++;
        return ret;
    }

    inline int weight(np t){return t ? t->weight : 0;}
    inline T sum(np t){return t ? t->sum : e;}
    inline np update(np t){
        t->weight = weight(t->child[0])+weight(t->child[1])+1;
        t->sum = f(f(sum(t->child[0]),t->key),sum(t->child[1]));
        return t;
    }
    np rotate(np t, int dir){
        np s = t->child[dir];
        t->child[dir] = s->child[1-dir];
        s->child[1-dir] = t;
        update(t); update(s);
        return s;
    }
    np insert(np t, int k, const T &key, uint32_t pri, bool dummy=false){
        if (empty()) return root = make_node(key,pri,dummy);
        if (!t) return make_node(key,pri,dummy);
        int c=weight(t->child[0]), dir=k>c;
        t->child[dir] = insert(t->child[dir], k-dir*(c+1), key, pri, dummy);
        update(t);
        if (t->pri >= t->child[dir]->pri) t = rotate(t,dir);
        return t;
    }
    np erase(np t, const T &key){
        if (!t) return nullptr;
        bool rot = (key==t->key);
        int dir = key > t->key;;
        if (rot){
            if (!t->child[0]) return t->child[1];
            if (!t->child[1]) return t->child[0];
            dir = (t->child[0]->pri)<(t->child[1]->pri);
            t = rotate(t,1-dir);
        }
        t->child[dir] = erase(t->child[dir],key);
        update(t);
        return t;
    }
    pair<np,np> split(np t, int k){
        t = insert(t,k,e,0,true);
        return make_pair(t->child[0], t->child[1]);
    }
    np merge(np left, np right){
        np t = make_node(e,0,true);
        t->child[0] = left; t->child[1] = right;
        update(t);
        return erase(t,e);
    }
    int lower_bound(np t, const T &key){
        if (!t) return 0;
        if (key <= t->key) return lower_bound(t->child[0],key);
        return lower_bound(t->child[1],key)+weight(t->child[0])+1;
    }
    int upper_bound(np t, const T &key){
        if (!t) return 0;
        if (key < t->key) return upper_bound(t->child[0],key);
        return upper_bound(t->child[1],key)+weight(t->child[0])+1;
    }
    T get(np t, int k){
        assert(t);
        int c=weight(t->child[0]), dir=k>c;
        if (c==k) return t->key;
        return get(t->child[dir], k-dir*(c+1));
    }
public:
    id0(int n,F f=[](T a,T b){return a+b;},T e=0):n(n),buf(n),ptr(0),root(nullptr),f(f),e(e){}
    inline bool empty(){return !root;}
    inline int size(){return weight(root);}
    inline int lower_bound(const T &key){return lower_bound(root,key);}
    inline int upper_bound(const T &key){return upper_bound(root,key);}

    int count(const T &key){return upper_bound(root,key)-lower_bound(root,key);}
    void insert(const T &key){root = insert(root,lower_bound(root,key),key,xorshift());}
    void erase(const T &key){root = erase(root,key);}
    T query(int a, int b){
        auto p = split(root,a);
        auto q = split(p.second,b-a);
        T ret = sum(q.first);
        root = merge(p.first, merge(q.first, q.second));
        return ret;
    }
    inline T operator[](int k){return get(root,k);}
};

template <class T>
class RichSet : public id0<T>
{
public:
    using id0<T>::id0;
	using id0<T>::count;
	using id0<T>::root;
    using id0<T>::insert;
    using id0<T>::xorshift;
    using id0<T>::lower_bound;
    void insert(const T &key){
        if (count(key)) return;
        root = insert(root,lower_bound(root,key),key,xorshift());
    }
};




int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
	int N,Q; cin>>N>>Q;
	vi a(N);
	rep(i,N) cin>>a[i];

	RichSet<int> sep(6*Q+N);
	Treap<ll> treap(6*Q+N);
	Treap<ll>::np sum = NULL;
	sep.ins(0);
	{
		int l=0;
		rep(i,N-1){
			if (a[i]>a[i+1]){
				ll sz = i-l+1;
				sep.ins(i+1);
				treap.push_back(sum, sz*(sz+1)/2);
				l = i+1;
			}
		}
		ll sz = N-l;
		sep.ins(N);
		treap.push_back(sum, sz*(sz+1)/2);
	}

	

	

	


	while(Q--){
		int type; cin>>type;
		if (type==1){
			ll x,y; cin>>x>>y; x--;
			
			a[x] = y;

			if (x+1<N && sep.count(x+1)){
				int idx = sep.lower_bound(x+1) - 1;
				ll val = sep[idx+2] - sep[idx];
				sep.erase(x+1);
				treap.erase(sum, idx);
				treap.assign(sum, idx, val*(val+1)/2);
			}
			if (x>0 && sep.count(x)){
				int idx = sep.lower_bound(x) - 1;
				ll val = sep[idx+2] - sep[idx];
				sep.erase(x);
				treap.erase(sum, idx);
				treap.assign(sum, idx, val*(val+1)/2);
			}

			if (x>0 && a[x-1]>a[x]){
				int idx = sep.lower_bound(x) - 1;
				ll l_val = x - sep[idx];
				ll r_val = sep[idx+1] - x;
				sep.ins(x);
				treap.assign(sum, idx, r_val*(r_val+1)/2);
				treap.ins(sum, idx, l_val*(l_val+1)/2);
			}
			if (x<N-1 && a[x]>a[x+1]){
				int idx = sep.lower_bound(x+1) - 1;
				ll l_val = (x+1) - sep[idx];
				ll r_val = sep[idx+1] - (x+1);
				sep.ins(x+1);
				treap.assign(sum, idx, r_val*(r_val+1)/2);
				treap.ins(sum, idx, l_val*(l_val+1)/2);
			}
			
			

			

			

		}else{
			int l,r; cin>>l>>r; l--;
			int left = sep.lower_bound(l);
			int right = sep.upper_bound(r) - 1;
			ll ans=0;
			if (left < right) ans += treap.query(sum, left, right);
			if (left > right){
				ll sz = r-l;
				ans += sz*(sz+1)/2;
			}else{
				{
					ll sz = sep[left]-l;
					ans += sz*(sz+1)/2;
				}
				{
					ll sz = r-sep[right];
					ans += sz*(sz+1)/2;
				}
			}
			cout<<ans<<"\n";
		}
	}
    return 0;
}
