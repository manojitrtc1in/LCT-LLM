










using namespace std;

typedef long long ll;

template<typename T, typename Q>
struct id8
{
    ll Li, Ri;

    int pt = 0;

    vector<T> ST;
    vector<int> L;
    vector<int> R;
    vector<bool> lazy;

    T query_res;
    bool query_flag, bs_flag;

    void new_node()
    {
        ST.push_back(T{});
        L.push_back(0);
        R.push_back(0);
        lazy.push_back(false);
    }

    id8()
    {

    }

    id8(ll a, ll b)
    {
        init(a,b);
    }

    void clear()
    {
        pt = 0;
        ST.clear();
        L.clear();
        R.clear();
        lazy.clear();
        new_node();
    }

    void init(ll a, ll b)
    {
        assert(a <= b);
        Li = a, Ri = b;
        clear();
    }

    void build(vector<T> &vect)
    {
        assert(Ri-Li+1 == (ll)vect.size());
        ST_build(0,Li,Ri,vect);
    }

    void insert(ll x, T nod)
    {
        ST_insert(0,Li,Ri,x,nod);
    }

    template<class F>
    bool id6(ll a, ll b, F f, T &tp)
    {
        query_res = T{};
        query_flag = false;
        bs_flag = false;
        id0(0,Li,Ri,a,b,f);
        if(bs_flag)
        {
            tp = query_res;
            return true;
        }
        else
        {
            tp = T{};
            return false;
        }
    }

    template<class F>
    bool id3(ll a, ll b, F f, T &tp)
    {
        query_res = T{};
        query_flag = false;
        bs_flag = false;
        id2(0,Li,Ri,a,b,f);
        if(bs_flag)
        {
            tp = query_res;
            return true;
        }
        else
        {
            tp = T{};
            return false;
        }
    }

    void update(ll x, Q &up)
    {
        ST_update(0,Li,Ri,x,x,up);
    }

    void update(ll a, ll b, Q &up)
    {
        ST_update(0,Li,Ri,a,b,up);
    }

    T query(ll x)
    {
        query_res = T{};
        query_flag = false;
        ST_query(0,Li,Ri,x,x);
        return query_res;
    }

    T query(ll a, ll b)
    {
        query_res = T{};
        query_flag = false;
        ST_query(0,Li,Ri,a,b);
        return query_res;
    }

    void ST_build(int node, ll l, ll r, vector<T> &vect)
    {
        if(l == r)
        {
            ST[node] = vect[l-Li];
            return;
        }
        else
        {
            L[node] = ++pt;
            new_node();
            R[node] = ++pt;
            new_node();
        }

        ll mid = (l+r)/2;

        ST_build(L[node],l,mid,vect);
        ST_build(R[node],mid+1,r,vect);

        ST[node].merge(ST[L[node]],ST[R[node]]);
    }

    void ST_insert(int node, ll l, ll r, ll x, T &nod)
    {
        if(l != r)
        {
            if(L[node] == 0)
            {
                L[node] = ++pt;
                new_node();
            }
            if(R[node] == 0)
            {
                R[node] = ++pt;
                new_node();
            }
        }

        if(lazy[node])
        {
            if(l != r)
            {
                ST[node].propagation(ST[L[node]],ST[R[node]]);
                lazy[L[node]] = true;
                lazy[R[node]] = true;
            }
            ST[node].update(l,r);
            lazy[node] = false;
        }

        if(l == r)
        {
            ST[node] = nod;
            return;
        }

        ll mid = (l+r)/2;

        if(x <= mid)ST_insert(L[node],l,mid,x,nod);
        else ST_insert(R[node],mid+1,r,x,nod);

        ST[node].merge(ST[L[node]],ST[R[node]]);
    }

    template<class F>
    void id0(int node, ll l, ll r, ll a, ll b, F &f)
    {
        if(l != r)
        {
            if(L[node] == 0)
            {
                L[node] = ++pt;
                new_node();
            }
            if(R[node] == 0)
            {
                R[node] = ++pt;
                new_node();
            }
        }

        if(lazy[node])
        {
            if(l != r)
            {
                ST[node].propagation(ST[L[node]],ST[R[node]]);
                lazy[L[node]] = true;
                lazy[R[node]] = true;
            }
            ST[node].update(l,r);
            lazy[node] = false;
        }

        if(a <= l && r <= b)
        {
            T query_temp = query_res;
            bool flag_temp = query_flag;
            if(query_flag)
            {
                T temp;
                temp.merge(query_res, ST[node]);
                query_res = temp;
            }
            else
            {
                query_res = ST[node];
                query_flag = true;
            }
            if(f(query_res))
            {
                query_res = query_temp;
                query_flag = flag_temp;
                id1(node,l,r,f);
                bs_flag = true;
            }
            return;
        }

        ll mid = (l+r)/2;

        if(a <= mid)id0(L[node],l,mid,a,b,f);
        if(bs_flag)return;
        if(b > mid)id0(R[node],mid+1,r,a,b,f);
    }

    template<class F>
    void id1(int node, ll l, ll r, F &f)
    {
        if(l != r)
        {
            if(L[node] == 0)
            {
                L[node] = ++pt;
                new_node();
            }
            if(R[node] == 0)
            {
                R[node] = ++pt;
                new_node();
            }
        }

        if(lazy[node])
        {
            if(l != r)
            {
                ST[node].propagation(ST[L[node]],ST[R[node]]);
                lazy[L[node]] = true;
                lazy[R[node]] = true;
            }
            ST[node].update(l,r);
            lazy[node] = false;
        }

        ll mid = (l+r)/2;

        if(l == r)
        {
            if(query_flag)
            {
                T temp;
                temp.merge(query_res, ST[node]);
                query_res = temp;
            }
            else
            {
                query_res = ST[node];
                query_flag = true;
            }
            return;
        }

        T query_temp = query_res;
        bool flag_temp = query_flag;
        if(query_flag)
        {
            T temp;
            temp.merge(query_res, ST[L[node]]);
            query_res = temp;
        }
        else
        {
            query_res = ST[L[node]];
            query_flag = true;
        }

        if(f(query_res))
        {
            query_res = query_temp;
            query_flag = flag_temp;
            id1(L[node],l,mid,f);
        }
        else
        {
            id1(R[node],mid+1,r,f);
        }
    }

    template<class F>
    void id2(int node, ll l, ll r, ll a, ll b, F &f)
    {
        if(l != r)
        {
            if(L[node] == 0)
            {
                L[node] = ++pt;
                new_node();
            }
            if(R[node] == 0)
            {
                R[node] = ++pt;
                new_node();
            }
        }

        if(lazy[node])
        {
            if(l != r)
            {
                ST[node].propagation(ST[L[node]],ST[R[node]]);
                lazy[L[node]] = true;
                lazy[R[node]] = true;
            }
            ST[node].update(l,r);
            lazy[node] = false;
        }

        if(a <= l && r <= b)
        {
            T query_temp = query_res;
            bool flag_temp = query_flag;
            if(query_flag)
            {
                T temp;
                temp.merge(query_res, ST[node]);
                query_res = temp;
            }
            else
            {
                query_res = ST[node];
                query_flag = true;
            }
            if(f(query_res))
            {
                query_res = query_temp;
                query_flag = flag_temp;
                id7(node,l,r,f);
                bs_flag = true;
            }
            return;
        }

        ll mid = (l+r)/2;

        if(b > mid)id2(R[node],mid+1,r,a,b,f);
        if(bs_flag)return;
        if(a <= mid)id2(L[node],l,mid,a,b,f);
    }

    template<class F>
    void id7(int node, ll l, ll r, F &f)
    {
        if(l != r)
        {
            if(L[node] == 0)
            {
                L[node] = ++pt;
                new_node();
            }
            if(R[node] == 0)
            {
                R[node] = ++pt;
                new_node();
            }
        }

        if(lazy[node])
        {
            if(l != r)
            {
                ST[node].propagation(ST[L[node]],ST[R[node]]);
                lazy[L[node]] = true;
                lazy[R[node]] = true;
            }
            ST[node].update(l,r);
            lazy[node] = false;
        }

        ll mid = (l+r)/2;

        if(l == r)
        {
            if(query_flag)
            {
                T temp;
                temp.merge(query_res, ST[node]);
                query_res = temp;
            }
            else
            {
                query_res = ST[node];
                query_flag = true;
            }
            return;
        }

        T query_temp = query_res;
        bool flag_temp = query_flag;
        if(query_flag)
        {
            T temp;
            temp.merge(query_res, ST[R[node]]);
            query_res = temp;
        }
        else
        {
            query_res = ST[R[node]];
            query_flag = true;
        }

        if(f(query_res))
        {
            query_res = query_temp;
            query_flag = flag_temp;
            id7(R[node],mid+1,r,f);
        }
        else
        {
            id7(L[node],l,mid,f);
        }
    }

    void ST_update(int node, ll l, ll r, ll a, ll b, Q &up)
    {
        if(l != r)
        {
            if(L[node] == 0)
            {
                L[node] = ++pt;
                new_node();
            }
            if(R[node] == 0)
            {
                R[node] = ++pt;
                new_node();
            }
        }

        if(lazy[node])
        {
            if(l != r)
            {
                ST[node].propagation(ST[L[node]],ST[R[node]]);
                lazy[L[node]] = true;
                lazy[R[node]] = true;
            }
            ST[node].update(l,r);
            lazy[node] = false;
        }

        if(r < a || l > b)return;

        if(a <= l && r <= b)
        {
            ST[node].push(up);
            if(l != r)
            {
                ST[node].propagation(ST[L[node]],ST[R[node]]);
                lazy[L[node]] = true;
                lazy[R[node]] = true;
            }
            ST[node].update(l,r);
            return;
        }

        ll mid = (l+r)/2;

        ST_update(L[node],l,mid,a,b,up);
        ST_update(R[node],mid+1,r,a,b,up);

        ST[node].merge(ST[L[node]],ST[R[node]]);
    }

    void ST_query(int node, ll l, ll r, ll a, ll b)
    {
        if(l != r)
        {
            if(L[node] == 0)
            {
                L[node] = ++pt;
                new_node();
            }
            if(R[node] == 0)
            {
                R[node] = ++pt;
                new_node();
            }
        }

        if(lazy[node])
        {
            if(l != r)
            {
                ST[node].propagation(ST[L[node]],ST[R[node]]);
                lazy[L[node]] = true;
                lazy[R[node]] = true;
            }
            ST[node].update(l,r);
            lazy[node] = false;
        }

        if(a <= l && r <= b)
        {
            if(query_flag)
            {
                T temp;
                temp.merge(query_res, ST[node]);
                query_res = temp;
            }
            else
            {
                query_res = ST[node];
                query_flag = true;
            }
            return;
        }

        ll mid = (l+r)/2;

        if(a <= mid)ST_query(L[node],l,mid,a,b);
        if(b > mid)ST_query(R[node],mid+1,r,a,b);
    }
};

struct QUERY
{
    ll may = 0;
    ll tp = 0;
};

struct NODE
{
    pair<int,int> may = {0,0};
    pair<int,int> id4 = {0,0};

    void merge(NODE &H1, NODE &H2)
    {
        may = max(H1.may, H2.may);
    }
    void push(QUERY &Q)
    {
        id4 = {Q.may,Q.tp};
    }
    void update(ll l, ll r)
    {
        may = max(may, id4);
        id4 = {0,0};
    }
    void propagation(NODE &H1, NODE &H2)
    {
        H1.id4 = max(H1.id4, id4);
        H2.id4 = max(H2.id4, id4);
    }
};

struct COORDINATE_COMPRESSION
{
    typedef long long ll;

    vector<ll> vect;
    bool id5 = true;

    int size()
    {
        if(!id5)compress();
        return vect.size();
    }

    void clear()
    {
        vect.clear();
        id5 = true;
    }

    void insert(ll x)
    {
        vect.push_back(x);
        id5 = false;
    }

    void compress()
    {
        sort(vect.begin(), vect.end());
        vect.resize(unique(vect.begin(), vect.end()) - vect.begin());
        id5 = true;
    }

    vector<ll> compress_offline(vector<ll> vect)
    {
        if(!vect.size())return vect;

        vector<pair<ll,int>> vvv;

        for(int i = 0 ; i < vect.size() ; i++)
        {
            vvv.push_back({vect[i],i});
        }

        sort(vvv.begin(), vvv.end());

        int cont = 0;
        ll last = vvv[0].first;

        vect[vvv[0].second] = 0;

        for(int i = 1 ; i < vvv.size() ; i++)
        {
            if(vvv[i].first != last)
            {
                cont++;
                last = vvv[i].first;
            }
            vect[vvv[i].second] = cont;
        }

        return vect;
    }

    int get(ll x)
    {
        if(!id5)compress();
        int pos = lower_bound(vect.begin(), vect.end(), x) - vect.begin();
        assert(pos != vect.size() && vect[pos] == x);
        return pos;
    }

    ll iget(int x)
    {
        if(!id5)compress();
        assert(0 <= x && x < vect.size());
        return vect[x];
    }
}mp;












const int MAXN = 3e5 + 100;

vector<pair<int,int>> arr[MAXN];

int dp[MAXN];

int best[MAXN];

int ok[MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    id8<NODE,QUERY> ST(1,2*MAXN);

    int N, M;
    cin >> N >> M;

    for(int i = 1 ; i <= M ; i++)
    {
    	int x, a, b;
    	cin >> x >> a >> b;
    	arr[x].push_back({a,b});
    	mp.insert(a);
    	mp.insert(b);
    }

    for(int i = 1 ; i <= N ; i++)
    {
    	for(int j = 0 ; j < arr[i].size() ; j++)
    	{
    		arr[i][j].first = mp.get(arr[i][j].first)+1;
    		arr[i][j].second = mp.get(arr[i][j].second)+1;
    	}
    }

    for(int i = 1 ; i <= N ; i++)
    {
    	dp[i] = 1;
    	best[i] = 0;
    	for(auto x : arr[i])
    	{
    		int may = ST.query(x.first,x.second).may.second;

    		if(dp[may]+1 > dp[i])
    		{
	    		dp[i] = dp[may]+1;
	    		best[i] = may;
    		}
    	}

    	for(auto x : arr[i])
    	{
	    	QUERY tp;

    		tp.may = dp[i];
    		tp.tp = i;

    		ST.update(x.first,x.second,tp);
    	}

    }	

    int res = -1;
    int pos = -1;

    for(int i = 1 ; i <= N ; i++)
    {
    	if(dp[i] > res)
    	{
    		res = dp[i];
    		pos = i;
    	}
    }

    while(pos)
    {
    	ok[pos] = 1;
    	pos = best[pos];
    }

    dbm(dp,1,N);
    dbm(best,1,N);

    vector<int> ans;

    for(int i = 1 ; i <= N ; i++)
    {
    	if(ok[i] == 0)
    	{
    		ans.push_back(i);
    	}
    }

    cout << ans.size() << '\n';

    for(auto x : ans)
    {
    	cout << x << " ";
    }
    cout << '\n';

    return 0;
}