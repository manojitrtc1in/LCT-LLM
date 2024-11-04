










using namespace std;












typedef long long ll;

template<typename T, typename Q>
struct id6
{
    ll Li, Ri;

    int pt = 0;

    vector<T> ST;
    vector<int> L;
    vector<int> R;
    vector<bool> lazy;

    T query_res;
    bool query_flag, bs_flag;
    ll bs_pos;

    void new_node()
    {
        ST.push_back(T{});
        L.push_back(0);
        R.push_back(0);
        lazy.push_back(false);
    }

    id6()
    {

    }

    id6(ll a, ll b)
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
    ll id4(ll a, ll b, F f, T &tp)
    {
        query_res = T{};
        query_flag = false;
        bs_flag = false;
        bs_pos = b+1;
        id0(0,Li,Ri,a,b,f);
        if(bs_flag)
        {
            tp = query_res;
            return bs_pos;
        }
        else
        {
            tp = T{};
            return bs_pos;
        }
    }

    template<class F>
    ll id3(ll a, ll b, F f, T &tp)
    {
        query_res = T{};
        query_flag = false;
        bs_flag = false;
        bs_pos = a-1;
        id2(0,Li,Ri,a,b,f);
        if(bs_flag)
        {
            tp = query_res;
            return bs_pos;
        }
        else
        {
            tp = T{};
            return bs_pos;
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

        ll mid = l+(r-l)/2;

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

        if(x < l || r < x)return;

        if(l == r)
        {
            ST[node] = nod;
            return;
        }

        ll mid = l+(r-l)/2;

        ST_insert(L[node],l,mid,x,nod);
        ST_insert(R[node],mid+1,r,x,nod);

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

        ll mid = l+(r-l)/2;

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

        ll mid = l+(r-l)/2;

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
            bs_pos = l;
            return;
        }

        if(l != mid)
        {
            if(L[L[node]] == 0)
            {
                L[L[node]] = ++pt;
                new_node();
            }
            if(R[L[node]] == 0)
            {
                R[L[node]] = ++pt;
                new_node();
            }
        }

        if(lazy[L[node]])
        {
            if(l != mid)
            {
                ST[L[node]].propagation(ST[L[L[node]]],ST[R[L[node]]]);
                lazy[L[L[node]]] = true;
                lazy[R[L[node]]] = true;
            }
            ST[L[node]].update(l,mid);
            lazy[L[node]] = false;
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
                temp.merge(ST[node], query_res);
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
                id5(node,l,r,f);
                bs_flag = true;
            }
            return;
        }

        ll mid = l+(r-l)/2;

        if(b > mid)id2(R[node],mid+1,r,a,b,f);
        if(bs_flag)return;
        if(a <= mid)id2(L[node],l,mid,a,b,f);
    }

    template<class F>
    void id5(int node, ll l, ll r, F &f)
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

        ll mid = l+(r-l)/2;

        if(l == r)
        {
            if(query_flag)
            {
                T temp;
                temp.merge(ST[node], query_res);
                query_res = temp;
            }
            else
            {
                query_res = ST[node];
                query_flag = true;
            }
            bs_pos = l;
            return;
        }

        if(mid+1 != r)
        {
            if(L[R[node]] == 0)
            {
                L[R[node]] = ++pt;
                new_node();
            }
            if(R[R[node]] == 0)
            {
                R[R[node]] = ++pt;
                new_node();
            }
        }

        if(lazy[R[node]])
        {
            if(mid+1 != r)
            {
                ST[R[node]].propagation(ST[L[R[node]]],ST[R[R[node]]]);
                lazy[L[R[node]]] = true;
                lazy[R[R[node]]] = true;
            }
            ST[R[node]].update(mid+1,r);
            lazy[R[node]] = false;
        }

        T query_temp = query_res;
        bool flag_temp = query_flag;
        if(query_flag)
        {
            T temp;
            temp.merge(ST[R[node]], query_res);
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
            id5(R[node],mid+1,r,f);
        }
        else
        {
            id5(L[node],l,mid,f);
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

        ll mid = l+(r-l)/2;

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

        ll mid = l+(r-l)/2;

        if(a <= mid)ST_query(L[node],l,mid,a,b);
        if(b > mid)ST_query(R[node],mid+1,r,a,b);
    }
};

struct QUERY
{
    ll sum = 0;
};

struct NODE
{
    ll may = -1e18;
    void merge(NODE &H1, NODE &H2)
    {
        may = max(H1.may, H2.may);
    }
    void push(QUERY &Q)
    {
    }
    void update(ll l, ll r)
    {
    }
    void propagation(NODE &H1, NODE &H2)
    {
    }
};

const int MAXN = 5e4 + 100;

int A[MAXN];

int T[MAXN];

int arr[MAXN];

int dp[MAXN];

int last[MAXN];

int pos[MAXN];

template<typename T, class F = less<T>>
struct RMQ
{
    vector<vector<T>> A;
    RMQ(const vector<T> &arr)
    {
        A.resize(arr.size());
        for(int i = 0 ; i < A.size() ; i++)A[i].resize(31-__builtin_clz(arr.size())+1), A[i][0] = arr[i];
        for(int j = 1 ; j <= 31-__builtin_clz(arr.size()) ; j++)
            for(int i = 0 ; i+(1<<j)-1 < A.size() ; i++)
                if(F()(A[i][j-1],A[i+(1<<(j-1))][j-1]))A[i][j] = A[i][j-1];
                else A[i][j] = A[i+(1<<(j-1))][j-1];
    }
    T query(int a, int b)
    {
        if(a > b)swap(a,b);
        int k = 31-__builtin_clz(b-a+1);
        if(F()(A[a][k],A[b-(1<<k)+1][k]))return A[a][k];
        else return A[b-(1<<k)+1][k];
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;

    while(tc--)
    {
        int N;
        cin >> N;

        id6<NODE,QUERY> ST(-N,N);

        for(int i = 1 ; i <= N ; i++)
        {
            cin >> A[i];
        }

        int X;
        cin >> X;

        for(int i = 1 ; i <= N ; i++)
        {
            T[i] = T[i-1] + A[i];
        }

        for(int i = 1 ; i <= N ; i++)
        {
            arr[i] = T[i] - i*X;
        }

        for(int i = 1 ; i <= N ; i++)
        {
            if(arr[i-1] <= arr[i])
            {
                last[i] = last[i-1];
            }
            else
            {
                last[i] = i;
            }
        }

        vector<int> lll(N+1);

        for(int i = 1 ; i <= N ; i++)
        {
            lll[i] = arr[i];
        }

        RMQ<int,greater<int>> QQQ(lll);

        for(int i = 1 ; i <= N ; i++)
        {
            if(i == 1)
            {
                pos[i] = 1;
            }
            else
            {
                int a = 0, b = i-2, res = i-1;

                while(a <= b)
                {
                    int mid = (a+b)/2;

                    if(QQQ.query(mid,i-2) <= arr[i])
                    {
                        res = mid;
                        b = mid-1;
                    }
                    else
                    {
                        a = mid+1;
                    }
                }

                pos[i] = res+1;
            }
        }

        


        

        

        

        

        

        

        

        

        

        

        


        vector<int> vect(N+1);

        for(int i = 1 ; i <= N ; i++)
        {
            vect[i] = pos[i];
        }

        NODE tp;
        tp.may = 0;
        ST.insert(0,tp);
        tp.may = 1;
        ST.insert(-1,tp);

        RMQ<int,greater<int>> Q(vect);

        for(int i = 1 ; i <= N ; i++)
        {
            int a = 1, b = i, res = i;

            while(a <= b)
            {
                int mid = (a+b)/2;

                if(Q.query(mid,i) <= mid)
                {
                    res = mid;
                    b = mid-1;
                }
                else
                {
                    a = mid+1;
                }
            }

            dbl(i,res);

            dp[i] = i + ST.query(res-2,i-2).may - 1;
            


            NODE tp;
            tp.may = dp[i] - i;

            ST.insert(i,tp);
        }

        

        

        dbm(pos,0,N);
        dbm(dp,0,N);
        


        int res = 0;

        for(int i = 1 ; i <= N ; i++)
        {
            res = max(res, dp[i]);
        }

        cout << res << '\n';
    }

    return 0;
}