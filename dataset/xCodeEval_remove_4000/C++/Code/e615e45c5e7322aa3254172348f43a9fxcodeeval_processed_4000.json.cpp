



using namespace std;

struct LCA
{
    vector<int> height, euler, first;
    vector<bool> visited;
    int n;

    int id3;
    static const int bits = 30;
    vector<int> mask, rmq;

    int op(int x, int y)
    {
        return height[euler[x]] < height[euler[y]] ? x : y;
    }
    int msb(int x)
    {
        return __builtin_clz(1)-__builtin_clz(x);
    }
    int small(int r, int sz = bits)
    {
        return r-msb(mask[r]&((1<<sz)-1));
    }
    void RMQ()
    {
        id3 = euler.size(), mask.resize(id3), rmq.resize(id3);
        for(int i = 0, at = 0 ; i < id3 ; mask[i++] = at |= 1)
        {
            at = (at<<1)&((1<<bits)-1);
            while(at and op(i, i-msb(at&-at)) == i)at ^= at&-at;
        }
        for(int i = 0 ; i < id3/bits ; i++)rmq[i] = small(bits*i+bits-1);
        for(int j = 1 ; (1<<j) <= id3/bits ; j++)for(int i = 0 ; i+(1<<j) <= id3/bits ; i++)
                rmq[id3/bits*j+i] = op(rmq[id3/bits*(j-1)+i], rmq[id3/bits*(j-1)+i+(1<<(j-1))]);
    }
    int query(int l, int r)
    {
        l = first[l], r = first[r];
        if(l > r)swap(l, r);
        if(r-l+1 <= bits)return euler[small(r, r-l+1)];
        int ans = op(small(l+bits-1), small(r));
        int x = l/bits+1, y = r/bits-1;
        if(x <= y)
        {
            int j = msb(y-x+1);
            ans = op(ans, op(rmq[id3/bits*j+x], rmq[id3/bits*j+y-(1<<j)+1]));
        }
        return euler[ans];
    }
    LCA(const vector<vector<int>> &adj, int root = 0)
    {
        n = adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(n*2);
        visited.assign(n,false);
        DFS(adj,root);
        RMQ();
    }
    void DFS(const vector<vector<int>> &adj, int nodo)
    {
        visited[nodo] = true;
        first[nodo] = euler.size();
        euler.push_back(nodo);
        for(auto v : adj[nodo])
        {
            if(!visited[v])
            {
                height[v] = height[nodo]+1;
                DFS(adj,v);
                euler.push_back(nodo);
            }
        }
    }
};

const int MOD = 1e9 + 7;

struct id0
{
    typedef long long ll;

    ll MOD;

    ll sz;

    vector<ll> _fact, _inum, _ifact, _pw2;

    vector<vector<ll>> _dp, id5, id1, _pascal;

    ll id4;
    bool id2;

    id0(ll m)
    {
        MOD = m;
        sz = 1;
        _fact = {1,1};
        _inum = {0,1};
        _ifact = {1,1};
        _pw2 = {1};
        _dp = {{1}};
        id5 = {{1}};
        id1 = {{1}};
        _pascal = {{1}};
        id2 = false;
        id4 = 0;
    }

    ll mod(ll x)
    {
        x %= MOD;
        if(x < 0)x += MOD;
        return x;
    }

    ll qpow(ll a, ll b)
    {
        a = mod(a);
        ll res = 1;
        while(b)
        {
            if(b&1)res = res*a%MOD;
            a = a*a%MOD;
            b >>= 1;
        }
        return res;
    }

    ll inv(ll x)
    {
        x = mod(x);
        if(x <= sz)return _inum[x];
        return qpow(x, MOD-2);
    }

    ll fact(int x)
    {
        update(x);
        return _fact[x];
    }

    ll inum(int x)
    {
        update(x);
        return _inum[x];
    }

    ll ifact(int x)
    {
        update(x);
        return _ifact[x];
    }

    void update(int n)
    {
        while(sz < n)
        {
            sz++;
            _fact.push_back(_fact.back()*sz%MOD);
            _inum.push_back((MOD-MOD/sz)*_inum[MOD%sz]%MOD);
            _ifact.push_back(_ifact.back()*_inum.back()%MOD);
        }
    }

    ll summation(ll n, int k)
    {
        if(n <= 0)return 0;
        vector<ll> sum(k+1), sum2(k+1);
        n = (n-1)%MOD;
        sum[0] = n+1;
        for(int i = 1 ; i <= k ; i++)
        {
            for(int j = 0 ; j < i-1 ; j++)
            {
                sum[i] = (sum[i]+(sum2[j]+MOD-sum[j])*comb(i,j))%MOD;
            }
            sum[i] = ((sum[i]+(sum[i-1]*(ll)i%MOD)*n)%MOD)*inum(i+1)%MOD;
            sum2[i-1] = (sum[i-1]*(n+1)+MOD-sum[i])%MOD;
        }
        return sum[k];
    }

    void update_summation(int n, int k, int a = 0, int b = 1)
    {
        a = mod(a), b = mod(b);
        if(!id2)
        {
            id2 = true;
            id4 = b;
        }
        else
        {
            if(id4 != b)
            {
                id4 = b;
                _dp = {{1}};
            }
        }
        int tn = _dp.size(), tk = _dp[0].size();
        n = max(n, tn-1), k = max(k, tk-1);
        while((int)_pw2.size() <= n)
        {
            _pw2.push_back(_pw2.back()*2ll%MOD);
        }
        function<void(int,int)> f = [&](int n, int k)
        {
            _dp[n][k] = _dp[n-1][k];
            ll x = 1;
            ll pw = (b*_pw2[n-1])%MOD;
            for(int i = 0 ; i <= k ; i++)
            {
                _dp[n][k] = (_dp[n][k]+(comb(k,i)*x%MOD)*_dp[n-1][k-i])%MOD;
                x = (x*pw)%MOD;
            }
        };
        if(tk <= k)
        {
            _dp[0].resize(k+1);
            for(int i = 1 ; i < tn ; i++)
            {
                _dp[i].resize(k+1);
                for(int j = tk ; j <= k ; j++)
                {
                    f(i,j);
                }
            }
        }
        for(int i = tn ; i <= n ; i++)
        {
            _dp.emplace_back();
            _dp.back().resize(k+1);
            for(int j = 0 ; j <= k ; j++)
            {
                f(i,j);
            }
        }
    }

    ll summation_dp(ll n, int k, int a = 0, int b = 1)
    {
        

        if(n <= 0)return 0;
        a = mod(a), b = mod(b);
        update_summation(__lg(n), k, a, b);
        ll res = 0, pos = 0;
        for(int j = __lg(n) ; j >= 0 ; j--)
        {
            if(n&(1ll<<j))
            {
                ll x = 1;
                ll pw = (a+b*pos)%MOD;
                for(int i = 0 ; i <= k ; i++)
                {
                    res = (res+(comb(k,i)*x%MOD)*_dp[j][k-i])%MOD;
                    x = (x*pw)%MOD;
                }
                pos = (pos+_pw2[j])%MOD;
            }
        }
        return res;
    }

    ll stirling1(ll n, ll k)
    {
        int k2 = n-k;
        ll res = 0;
        for(int i = 0 ; i <= 2*k2 ; i++)
        {
            int tot = 0;
            for(int j = 0 ; j <= i ; j++)
            {
                if(i-j-k2 < 0)break;
                if(j&1)tot = mod(tot - comb(i,j)*stirling1_dp(i-j,i-j-k2));
                else tot = mod(tot + comb(i,j)*stirling1_dp(i-j,i-j-k2));
            }
            res = mod(res + tot*comb2(n,i));
        }
        return res;
    }

    vector<ll> stirling1_fast(ll n, ll k)
    {
        vector<ll> ans;
        int k2 = n-k;
        if(k2 < 0)return ans;
        vector<ll> dp(k2+1);
        vector<ll> iv(k2+1);
        for(int i = 1 ; i <= k2 ; i++)iv[i] = inum(i);
        dp[0] = 1;
        ll pt = 0;
        for(int i = __lg(n) ; i >= 0 ; i--)
        {
            vector<ll> big(k2+1), pw(k2+1), tmp(k2+1);
            pw[0] = 1;
            for(int j = 1 ; j <= k2 ; j++)pw[j] = (pt%MOD)*pw[j-1]%MOD;

            int sz = min(k2,pt)+1;

            vector<vector<ll>> ncr(sz,vector<ll>(sz));

            for(int j = 0 ; j < sz ; j++)
            {
                ncr[j][0] = 1;
                for(int l = 1 ; l < sz ; l++)
                {
                    ncr[j][l] = (pt-j-l+1)%MOD*ncr[j][l-1]%MOD*iv[l]%MOD;
                }
            }

            for(int j = 0 ; j <= min(k2,pt) ; j++)
            {
                for(int l = 0 ; l <= j ; l++)
                {
                    big[j] = (big[j] + ncr[l][j-l]*pw[j-l]%MOD*dp[l])%MOD;
                }
            }

            for(int j = 0 ; j <= k2 ; j++)
            {
                for(int l = 0 ; l <= j ; l++)
                {
                    tmp[j] = (tmp[j] + dp[l]*big[j-l])%MOD;
                }
            }

            dp = tmp;
            pt *= 2;

            if(n&(1ll<<i))
            {
                tmp.assign(k2+1,0);
                tmp[0] = 1;
                for(int j = 1 ; j <= k2 ; j++)
                {
                    tmp[j] = (dp[j] + (pt%MOD)*dp[j-1])%MOD;
                }
                dp = tmp;
                pt++;
            }
        }
        ans = dp;
        return ans;
    }

    void update_stirling1(int n, int k)
    {
        int tn = id5.size(), tk = id5[0].size();
        n = max(n, tn-1), k = max(k, tk-1);
        function<void(int,int)> f = [&](int n, int k)
        {
            id5[n][k] = (id5[n-1][k-1]+id5[n-1][k]*(n-1))%MOD;
        };
        if(tk <= k)
        {
            id5[0].resize(k+1);
            for(int i = 1 ; i < tn ; i++)
            {
                id5[i].resize(k+1);
                for(int j = tk ; j <= k ; j++)
                {
                    f(i,j);
                }
            }
        }
        for(int i = tn ; i <= n ; i++)
        {
            id5.emplace_back();
            id5.back().resize(k+1);
            for(int j = 1 ; j <= k ; j++)
            {
                f(i,j);
            }
        }
    }

    ll stirling1_dp(int n, int k)
    {
        update_stirling1(n,k);
        return id5[n][k];
    }

    ll stirling2(ll n, int k)
    {
        ll res = 0;
        for(int i = 0 ; i <= k ; i++)
        {
            if(i&1)res = (res + MOD - comb(k,i)*qpow(k-i,n)%MOD)%MOD;
            else res = (res + comb(k,i)*qpow(k-i,n))%MOD;
        }
        return res*ifact(k)%MOD;
    }

    void update_stirling2(int n, int k)
    {
        int tn = id1.size(), tk = id1[0].size();
        n = max(n, tn-1), k = max(k, tk-1);
        function<void(int,int)> f = [&](int n, int k)
        {
            id1[n][k] = (id1[n-1][k-1]+id1[n-1][k]*k)%MOD;
        };
        if(tk <= k)
        {
            id1[0].resize(k+1);
            for(int i = 1 ; i < tn ; i++)
            {
                id1[i].resize(k+1);
                for(int j = tk ; j <= k ; j++)
                {
                    f(i,j);
                }
            }
        }
        for(int i = tn ; i <= n ; i++)
        {
            id1.emplace_back();
            id1.back().resize(k+1);
            for(int j = 1 ; j <= k ; j++)
            {
                f(i,j);
            }
        }
    }

    ll stirling2_dp(int n, int k)
    {
        update_stirling2(n,k);
        return id1[n][k];
    }

    void update_pascal(int n, int k)
    {
        int tn = _pascal.size(), tk = _pascal[0].size();
        n = max(n, tn-1), k = max(k, tk-1);
        function<void(int,int)> f = [&](int n, int k)
        {
            _pascal[n][k] = (_pascal[n-1][k]+_pascal[n-1][k-1])%MOD;
        };
        if(tk <= k)
        {
            _pascal[0].resize(k+1);
            for(int i = 1 ; i < tn ; i++)
            {
                _pascal[i].resize(k+1);
                for(int j = tk ; j <= k ; j++)
                {
                    f(i,j);
                }
            }
        }
        for(int i = tn ; i <= n ; i++)
        {
            _pascal.emplace_back();
            _pascal.back().resize(k+1);
            _pascal.back()[0] = 1;
            for(int j = 1 ; j <= k ; j++)
            {
                f(i,j);
            }
        }
    }

    ll comb_dp(int n, int k)
    {
        update_pascal(n,k);
        return _pascal[n][k];
    }

    ll extended_binomial(ll n, ll x, int k)
    {
        

        x = mod(x);
        if(x == 0 && k == 0)return 1;
        x = (inv(x)+1ll)%MOD;
        ll val = inv(x), res = 0, pw = 1;
        for(int i = 0 ; i <= k ; i++)
        {
            res = (res + stirling2_dp(k,i)*pw)%MOD;
            pw = (pw*(n-i)%MOD)*val%MOD;
        }
        res = res*qpow(x*inv((x+MOD-1)%MOD)%MOD,n)%MOD;
        return res;
    }

    ll lagrange_interpolation_arithmetic(const vector<ll> &y, ll T, ll a = 0, ll d = 1)
    {
        T = mod(T), a = mod(a), d = mod(d);

        int N = (int)y.size()-1;
        if(a == 0 && d == 1 && T <= N)return y[T];

        vector<ll> dp(N+1, 1), pd(N+1, 1);
        for(int i = 0 ; i < N ; i++)dp[i+1] = dp[i]*(T+MOD-(a+d*i)%MOD)%MOD;
        for(int i = N ; i > 0 ; i--)pd[i-1] = pd[i]*(T+MOD-(a+d*i)%MOD)%MOD;

        vector<ll> fact(N+1, 1), finv(N+1, 1);

        for(int i = 1 ; i <= N ; i++)fact[i] = fact[i-1]*d%MOD*i%MOD;
        finv[N] = finv[N]*inv(fact[N])%MOD;
        for(int i = N ; i >= 1 ; i--)finv[i-1] = finv[i]*d%MOD*i%MOD;

        ll ret = 0;

        for(int i = 0 ; i <= N ; i++)
        {
            ll tmp = y[i]*dp[i]%MOD*pd[i]%MOD*finv[i]%MOD*finv[N-i]%MOD;
            if((N-i)&1)ret = (ret+MOD-tmp)%MOD;
            else ret = (ret+tmp)%MOD;
        }

        return ret;
    }

    ll lagrange_interpolation(vector<pair<ll,ll>> p, ll z)
    {
        int n = p.size();
        ll l, val = 0;

        for(int i = 0 ; i < n ; i++)
        {
            p[i].first = mod(p[i].first);
            p[i].second = mod(p[i].second);
        }

        z = mod(z);

        for(int i = 0 ; i < n ; i++)
        {
            l = p[i].second;
            for(int j = 0 ; j < n ; j++)
            {
                if(i != j)
                {
                    l = l*(z+MOD-p[j].first)%MOD*inv(p[i].first+MOD-p[j].first)%MOD;
                }
            }
            val = (val+l)%MOD;
        }
        return val;
    }

    

    

    ll intersection_value(ll N, ll K)
    {
        if(N < K)return 0;
        if(K == 0)
        {
            if(N == 0)return 1;
            return 0;
        }
        if((N-K)&1)return mod(-comb(N-1,K-1));
        return comb(N-1,K-1);
    }

    ll catalan(int n)
    {
        return comb(2*n,n)*inum(n+1)%MOD;
    }

    ll comb(int n, int k)
    {
        if(n < k)return 0;
        update(n);
        return (_fact[n]*_ifact[n-k]%MOD)*_ifact[k]%MOD;
    }

    ll comb2(ll n, int k)
    {
        if(n < k)return 0;
        update(k);
        ll res = 1;
        for(ll i = n ; i > n-k ; i--)res = i%MOD*res%MOD;
        return res*_ifact[k]%MOD;
    }
}math(MOD);

const int MAXN = 210;

int dp[MAXN][MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<vector<int>> L(N+1);

    for(int i = 1 ; i <= N-1 ; i++)
    {
    	int a, b;
    	cin >> a >> b;
    	L[a].push_back(b);
    	L[b].push_back(a);
    }

    for(int i = 1 ; i <= N ; i++)
    {
    	dp[0][i] = 0;
    	dp[i][0] = 1;
    }

    for(int i = 1 ; i <= N ; i++)
    {
    	for(int j = 1 ; j <= N ; j++)
    	{
    		dp[i][j] = (dp[i][j-1]+dp[i-1][j])*math.inv(2)%MOD;
    	}
    }

    int res = 0;

    for(int root = 1 ; root <= N ; root++)
    {
    	LCA lca(L,root);

    	for(int A = 1 ; A <= N ; A++)
    	{
    		for(int B = 1 ; B <= N ; B++)
    		{
    			if(A >= B)continue;

    			int G = lca.query(A,B);

    			int D1 = lca.height[A]-lca.height[G];
    			int D2 = lca.height[B]-lca.height[G];

    			res += dp[D1][D2];
    			res %= MOD;
    		}
    	}
    }

    res = res*math.inv(N)%MOD;

    cout << res << '\n';

    return 0;
}