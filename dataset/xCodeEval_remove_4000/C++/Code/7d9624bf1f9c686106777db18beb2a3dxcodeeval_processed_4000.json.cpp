



















namespace lz {

using std::vector;
using std::swap;
using std::cout;
using std::endl;






template<typename Value, typename Less = std::less<Value> >
class Heap
{
public:
	Heap(){}
	Heap(const vector<Value> &v)
	{
		for(int i = 0; i < sz(v); ++ i) push(v[i]);
	}
	inline int size() const { return a.size(); }
	inline Value top() const { return a[0]; }
	inline Value value(int i) const { return a[input[i]]; }
	inline int inputIdToHeapId(int i) { return input[i]; }
	inline int heapIdToInputId(int i) { return heap[i]; }

	void clear()
	{
		a.clear();
		input.clear();
		heap.clear();
	}
	void pop()
	{
		swap(a.front(), a.back());
		swap(input[heap[0]], input[heap[last(a)]]);
		swap(heap[0], heap[last(a)]);
		input[heap[last(a)]] = -1;
		heap.pop_back();
		a.pop_back();
		down(0);
	}
	void push(const Value &val)
	{
		a.push_back(val);
		input.push_back(last(a));
		heap.push_back(last(input));
		up(last(a));
	}
	void modify(int i, const Value &new_val)
	{
		if(less(new_val, a[input[i]]))
		{
			a[input[i]] = new_val;
			down(input[i]);
		}
		else
		{
			a[input[i]] = new_val;
			up(input[i]);
		}
	}
private:
	void up(int u)
	{
		for(;u != 0;)
		{
			if(less(a[p(u)], a[u]))
			{
				swap(a[p(u)], a[u]);
				swap(input[heap[p(u)]], input[heap[u]]);
				swap(heap[p(u)], heap[u]);
				u = p(u);
			}
			else return ;
		}
	}
	void down(int u)
	{
		for(;;)
		{
			int s = ls(u);
			if(s >= sz(a)) return ;
			if(rs(u) < sz(a) && less(a[s], a[rs(u)])) s = rs(u);
			if(less(a[u], a[s]))
			{
				swap(a[u], a[s]);
				swap(input[heap[u]], input[heap[s]]);
				swap(heap[u], heap[s]);
				u = s;
			}
			else return ;
		}
	}
	vector<int> input, heap;
	vector<Value> a;
	Less less;

};









} 




namespace lz {



using std::vector;




















































































































using std::get;
template<typename Graph, typename Dist, int EdgeKey,
		 typename Plus, typename Less = std::less<Dist>  >
class id1
{
	vector<int> p;
	vector<Dist> d;
	int s;
	struct More
	{
		bool operator()(const Dist &a, const Dist &b)
		{
			return Less()(b, a);
		}
	};
public:
	id1(){}
	id1(const Graph & g, int source, const Dist &zero_dist, const Dist &inf_dist)
		{ calculate(g, source, zero_dist, inf_dist); }

	void calculate(const Graph & g, int source, const Dist &zero_dist, const Dist &inf_dist)
	{
		s = source;
		int n = g.vertexNumber();
		p.assign(n, -1);
		d.assign(n, inf_dist);
		d[source] = zero_dist;
		Heap<Dist, More> h(d);
		for(int t = 1; t < n; ++ t)
		{
			int u = h.heapIdToInputId(0);
			if(!Less()(d[u], inf_dist)) return ;
			h.pop();
			typename Graph::ConstIterator eit;
			for(eit = g.begin(u);eit != g.end(u); ++ eit)
			{
				int to = eit->end;
				Dist tmp = Plus()(d[u], get<EdgeKey>(eit->property));
				if(h.inputIdToHeapId(to) != -1 && Less()(tmp, d[to]))
				{
					p[to] = u;
					d[to] = tmp;
					h.modify(to, tmp);
				}
			}
		}
	}
	inline int parent(int u) const { return p[u]; }
	inline Dist distance(int u) const { return d[u]; }
	inline int source() const { return s; }
	vector<int> getPath(int u)
	{
		vector<int> r;
		for(;u != -1; u = p[u]) r.push_back(u);
		std::reverse(r.begin(), r.end());
		return r;
	}

};



}


















struct NoProperty{};


template<typename EP>
struct id0
{
	int end;
	EP property;
	id0(){}
	id0(const int& _end, const EP& ep):
				end(_end), property(ep){}
	id0(int&& _end, EP&& ep):
				end(_end), property(ep){}
};
template<>
struct id0<NoProperty>
{
	int end;
	id0(){}
	id0(const int& _end, const NoProperty& ep):
				end(_end){}
	id0(int&& _end, NoProperty&& ep):
				end(_end){}
};







namespace lz {


using std::vector;
using std::cout;
using std::endl;

















































































































































































template<typename VP>
struct ALVertex
{
    int head;
    VP vp;
    ALVertex(const int& _head, const VP &_vp):
        head(_head), vp(_vp){}
    ALVertex(int && _head, VP &&_vp):
        head(_head), vp(_vp){}
};
template<>
struct ALVertex<NoProperty>
{
    int head;
    ALVertex(const int& _head, const NoProperty &_vp):
        head(_head){}
    ALVertex(int && _head, NoProperty &&_vp):
        head(_head){}
};


template<typename EP>
struct ALEdge
{
    id0<EP> ae;
    int next;
};


template<typename VP = NoProperty,
         typename EP = NoProperty,
         typename GP = NoProperty >
class id2
{
public:
    typedef VP VertexProperty;
    typedef EP EdgeProperty;
    typedef GP GraphProperty;

    explicit id2(int n = 0, int expect_m = 0, const GP _gp = GP()):
        v(n, ALVertex<VP>(-1, VP())), gp(_gp)
        {
            e.reserve(expect_m);
        }
    void clear(int n, int expect_m = 0)
    {
        v.assign(n, ALVertex<VP>(-1, VP()));
        e.clear();
        e.reserve(expect_m);
    }
    VP& vertexProperty(int i) { return v[i].vp; }
    GP& graphProperty() { return gp; }

    void add(int a, int b, const EP & ep = EP())
    {
        ALEdge<EP> ale;
        ale.ae = id0<EP>(b, ep);
        ale.next = v[a].head;
        e.push_back(std::move(ale));
        v[a].head = int(e.size()) - 1;
    }
    void add(int a, int b, EP && ep)
    {
        ALEdge<EP> ale;
        ale.ae = id0<EP>(std::move(b), std::move(ep));
        ale.next = v[a].head;
        e.push_back(std::move(ale));
        v[a].head = int(e.size()) - 1;
    }
    void addBidirection(int a, int b, const EP & ep = EP())
    {
        add(a, b, ep);
        add(b, a, ep);
    }
    inline int vertexNumber() const { return v.size(); }
    inline int edgeNumber() const { return e.size(); }

    

    class Iterator
    {
        friend class id2<VP, EP, GP>;
        vector<ALEdge<EP> > *e;
        int eid;
        Iterator(vector<ALEdge<EP> > *_e, int _eid):
            e(_e), eid(_eid){}
    public:
        Iterator():e(0), eid(-1){}
        Iterator& operator++()
        {
            eid = (*e)[eid].next;
            return *this;
        }
        Iterator operator++(int)
        {
            Iterator t(e, eid);
            eid = (*e)[eid].next;
            return t;
        }
        bool operator==(const Iterator &o) const { return e == o.e && eid == o.eid; }
        bool operator!=(const Iterator &o) const { return !(*this == o); }
        id0<EP>& operator*() { return (*e)[eid].ae;  }
        id0<EP>* operator->() { return &((*e)[eid].ae); }
    };
    Iterator begin(int i) { return Iterator(&e, v[i].head); }
    Iterator end(int i) { return Iterator(&e, -1); }


    class ConstIterator
    {
        friend class id2<VP, EP, GP>;
        const vector<ALEdge<EP> > *e;
        int eid;
        ConstIterator(const vector<ALEdge<EP> > *_e, int _eid):
            e(_e), eid(_eid){}
    public:
        ConstIterator():e(0), eid(-1){}
        ConstIterator& operator++()
        {
            eid = (*e)[eid].next;
            return *this;
        }
        ConstIterator operator++(int)
        {
            ConstIterator t(e, eid);
            eid = (*e)[eid].next;
            return t;
        }
        bool operator==(const ConstIterator &o) const { return e == o.e && eid == o.eid; }
        bool operator!=(const ConstIterator &o) const { return !(*this == o); }
        const id0<EP>& operator*() { return (*e)[eid].ae;  }
        const id0<EP>* operator->() { return &((*e)[eid].ae); }
    };
    ConstIterator begin(int i) const { return ConstIterator(&e, v[i].head); }
    ConstIterator end(int i) const { return ConstIterator(&e, -1); }

    typedef Iterator iterator;
    typedef ConstIterator const_iterator;







    id0<EP>& edge(int eid) { return e[eid].ae; }
private:
    vector<ALVertex<VP> > v;
    vector<ALEdge<EP> > e;
    GP gp;
};









} 








using namespace std;
using namespace lz;


const LL inf = 0x7fffffffffffffffLL;

struct Plus
{
	LL operator()(LL a, int b)
	{
		return a + b;
	}

};

int main()
{
	typedef id2<NoProperty, tuple<LL> > Graph;
    Graph g;
    id1<Graph, LL, 0, Plus> d;
    int n, m;
    scanf("%d%d", &n, &m);
    g.clear(n, 2 * m);
    while(m --)
    {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        a --;
        b --;
        g.addBidirection(a, b, make_tuple(w));
    }
    d.calculate(g, 0, 0, inf);




    if(d.distance(n - 1) == inf)
    {
        printf("-1\n");
    }
    else
    {
        vector<int> o = d.getPath(n - 1);
        for(int i = 0; i < o.size(); ++ i)
        {
            printf("%d ", o[i] + 1);
        }
        puts("");
    }





















	return 0;
}
