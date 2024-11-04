



using namespace std;









const int MOD = 998244353;

struct id0
{
    typedef long long ll;

    ll MOD;

    ll sz;

    vector<ll> _fact, _inum, _ifact, _pw2;

    vector<vector<ll>> _dp, id3, id1, _pascal;

    id0(ll m)
    {
        MOD = m;
        sz = 1;
        _fact = {1,1};
        _inum = {0,1};
        _ifact = {1,1};
        _pw2 = {1};
        _dp = {{1}};
        id3 = {{1}};
        id1 = {{1}};
        _pascal = {{1}};
    }

    ll qpow(ll a, ll b)
    {
    	a %= MOD;
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

    void update_summation(int n, int k)
    {
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
            ll pw = _pw2[n-1];
            

            

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

    ll summation_dp(ll n, int k)
    {
        if(n <= 0)return 0;
        update_summation(__lg(n), k);
        ll res = 0, pos = 0;
        for(int j = __lg(n) ; j >= 0 ; j--)
        {
            if(n&(1ll<<j))
            {
                ll x = 1;
                ll pw = pos;
                

                

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

    void update_stirling1(int n, int k)
    {
        int tn = id3.size(), tk = id3[0].size();
        n = max(n, tn-1), k = max(k, tk-1);
        function<void(int,int)> f = [&](int n, int k)
        {
            id3[n][k] = (id3[n-1][k-1]+id3[n-1][k]*(n-1))%MOD;
        };
        if(tk <= k)
        {
            id3[0].resize(k+1);
            for(int i = 1 ; i < tn ; i++)
            {
                id3[i].resize(k+1);
                for(int j = tk ; j <= k ; j++)
                {
                    f(i,j);
                }
            }
        }
        for(int i = tn ; i <= n ; i++)
        {
            id3.emplace_back();
            id3.back().resize(k+1);
            for(int j = 1 ; j <= k ; j++)
            {
                f(i,j);
            }
        }
    }

    ll stirling1_dp(int n, int k)
    {
        update_stirling1(n,k);
        return id3[n][k];
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
        

        x %= MOD;
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
        for(ll i = n ; i > n-k ; i--)res = res*i%MOD;
        return res*_ifact[k]%MOD;
    }
}math(MOD);

const int MAXN = 2e5 + 100;

vector<int> L[MAXN];
vector<int> I[MAXN];

int dp[MAXN][30][2];
bool mk[MAXN][30][2];

struct qu
{
	int a, b, c;
};

int D[MAXN][2];

vector<pair<int,int>> LLL[MAXN][2];

int ddd[MAXN][2];
bool kkk[MAXN][2];

int fff(int ttt)
{
	int id2 = 0;
    int pw = 1;

    for(int i = 1 ; i <= ttt ; i++)
    {
    	id2 = (id2 + pw)%MOD;
    	pw = pw*2%MOD;
    }

    return id2;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0 ; i < MAXN ; i++)
    {
    	D[i][0] = D[i][1] = 1e18;
    	ddd[i][0] = ddd[i][1] = 1e18;
    	for(int j = 0 ; j < 30 ; j++)
    	{
    		dp[i][j][0] = dp[i][j][1] = 1e18;
    	}
    }

    int N, M;
    cin >> N >> M;

    for(int i = 1 ; i <= M ; i++)
    {
    	int a, b;
    	cin >> a >> b;

    	L[a].push_back(b);
    	I[b].push_back(a);
    }

    queue<qu> Q;

    dp[1][0][0] = 0;
    mk[1][0][0] = true;

    Q.push({1,0,0});

    while(Q.size())
    {
    	qu nodo = Q.front();
    	Q.pop();

    	if(nodo.c == 0)
    	{
	    	for(auto v : L[nodo.a])
	    	{
	    		if(!mk[v][nodo.b][0])
	    		{
	    			mk[v][nodo.b][0] = true;
	    			dp[v][nodo.b][0] = dp[nodo.a][nodo.b][0] + 1;
	    			Q.push({v,nodo.b,0});
	    		}
	    	}

	    	if(nodo.b+1 < 30)
	    	{
				for(auto v : I[nodo.a])
		    	{
		    		if(!mk[v][nodo.b+1][1])
		    		{
		    			mk[v][nodo.b+1][1] = true;
		    			dp[v][nodo.b+1][1] = dp[nodo.a][nodo.b][0] + 1;
		    			Q.push({v,nodo.b+1,1});
		    		}
		    	}
	    	}
    	}
    	else	
    	{
    		for(auto v : I[nodo.a])
	    	{
	    		if(!mk[v][nodo.b][1])
	    		{
	    			mk[v][nodo.b][1] = true;
	    			dp[v][nodo.b][1] = dp[nodo.a][nodo.b][1] + 1;
	    			Q.push({v,nodo.b,1});
	    		}
	    	}

	    	if(nodo.b+1 < 30)
	    	{
				for(auto v : L[nodo.a])
		    	{
		    		if(!mk[v][nodo.b+1][0])
		    		{
		    			mk[v][nodo.b+1][0] = true;
		    			dp[v][nodo.b+1][0] = dp[nodo.a][nodo.b][1] + 1;
		    			Q.push({v,nodo.b+1,0});
		    		}
		    	}
	    	}
    	}
    }

    bool flag = false;

    int res = 1e18;

    int id2 = 0;
    int pw = 1;

    for(int i = 0 ; i < 30 ; i++)
    {
    	if(mk[N][i][0])
    	{
    		flag = true;
    		res = min(res, dp[N][i][0] + id2);
    	}
    	if(mk[N][i][1])
    	{
    		flag = true;
    		res = min(res, dp[N][i][1] + id2);
    	}

    	id2 += pw;
    	pw *= 2;
    }

    if(flag)
    {
    	cout << res << '\n';
    	return 0;
    }

    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> PQ;

    D[1][0] = 0;
    PQ.push({0,{1,0}});

    while(PQ.size())
    {
    	pair<int,int> nodo = PQ.top().second;
    	PQ.pop();

    	if(nodo.second == 0)
    	{
    		for(auto v : L[nodo.first])
    		{
    			if(D[nodo.first][0] + 0 < D[v][0])
    			{
    				D[v][0] = D[nodo.first][0] + 0;
    				PQ.push({D[v][0], {v, 0} });
    			}
    		}
    		for(auto v : I[nodo.first])
    		{
    			if(D[nodo.first][0] + 1 < D[v][1])
    			{
    				D[v][1] = D[nodo.first][0] + 1;
    				PQ.push({D[v][1], {v, 1} });
    			}
    		}
    	}
    	else
    	{
			for(auto v : I[nodo.first])
    		{
    			if(D[nodo.first][1] + 0 < D[v][1])
    			{
    				D[v][1] = D[nodo.first][1] + 0;
    				PQ.push({D[v][1], {v, 1} });
    			}
    		}
    		for(auto v : L[nodo.first])
    		{
    			if(D[nodo.first][1] + 1 < D[v][0])
    			{
    				D[v][0] = D[nodo.first][1] + 1;
    				PQ.push({D[v][0], {v, 0} });
    			}
    		}
    	}
    }

    for(int nodo = 1 ; nodo <= N ; nodo++)
    {
    	for(auto v : L[nodo])
    	{
    		if(D[nodo][0] + 0 <= D[v][0])
    		{
    			LLL[nodo][0].push_back({v,0});
    		}
    	}
    	for(auto v : I[nodo])
    	{
    		if(D[nodo][1] + 0 <= D[v][1])
    		{
    			LLL[nodo][1].push_back({v,1});
    		}
    	}
    	for(auto v : I[nodo])
    	{
    		if(D[nodo][0] + 1 <= D[v][1])
    		{
    			LLL[nodo][0].push_back({v,1});
    		}
    	}
    	for(auto v : L[nodo])
    	{
    		if(D[nodo][1] + 1 <= D[v][0])
    		{
    			LLL[nodo][1].push_back({v,0});
    		}
    	}
    }

    queue<pair<int,int>> QQQ;
    QQQ.push({1,0});
    ddd[1][0] = 0;
    kkk[1][0] = true;

    while(QQQ.size())
    {
    	pair<int,int> nodo = QQQ.front();
    	QQQ.pop();

    	for(auto v : LLL[nodo.first][nodo.second])
    	{
    		if(!kkk[v.first][v.second])
    		{
    			kkk[v.first][v.second] = true;
    			ddd[v.first][v.second] = ddd[nodo.first][nodo.second] + 1;
    			QQQ.push({v.first, v.second});
    		}
    	}
    }

    int ans;

   	if(D[N][0] < D[N][1])
   	{
   		ans = fff(D[N][0]) + ddd[N][0];
   	}
   	else
   	{
   		ans = fff(D[N][1]) + ddd[N][1];
   	}

   	ans %= MOD;

   	cout << ans << '\n';

    return 0;
}