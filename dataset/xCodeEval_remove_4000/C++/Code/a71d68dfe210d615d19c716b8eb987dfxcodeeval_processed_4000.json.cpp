















































































	using ll = long long;
	using ld = long double;
	using ull = unsigned long long;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	




using namespace std;
using namespace __gnu_pbds;














multiset<ll> LIS(vector<ll> A)
{
	ll a = A.size();
	multiset<ll> S;
	multiset<ll>::iterator it;
	FOR(i, 0, a - 1)
	{
		S.insert(A[i]);
		it = S.upper_bound(A[i]);
		if (it != S.end()) S.erase(it);
	}
	return S;
}

multiset<ll> LSIS(vector<ll> A) 

{
	ll a = A.size();
	multiset<ll> S;
	multiset<ll>::iterator it;
	FOR(i, 0, a - 1)
	{
		S.insert(A[i]);
		it = S.lower_bound(A[i]);
		it++;
		if (it != S.end()) S.erase(it);
	}
	return S;
}

ll gcd(ll a, ll b) {if (a == 0) return(b); return(gcd(b % a, a));}

ll id0(ll a, ll b, ll& x, ll& y) 

{
	if(a==0)
	{
		x=0;y=1;
		return(b);
	}
	ll a1, b1, c, x1, y1, rst;
	a1 = b % a; b1 = a; c = b / a;
	rst = id0(a1, b1, x1, y1);
	x = y1 - c * x1; y = x1;
	return(rst);
}

ll id1(ll a, ll b, ll m)
{
	if (b == 0) return 1;
	ull k = id1(a, b / 2, m);
	k = k * k;
	k %= m;
	if (b & 1) k = (k * a) % m;
	return k;
}




bool isPrime(ull n, int iter = 5) 
{
    if (n < 4) return n == 2 || n == 3;
	if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 0; i < iter; i++) 
	{
        ull a = 2 + rand() % (n - 3);
        if (id1(a, n - 1, n) != 1) return false;
    }
    return true;
}




struct Mint
{
	ll MOD = 1e9 + 7;
	ll val;
	bool operator==(const Mint& other) {return val == other.val;}
	Mint operator+(const Mint& other) {ll res = val + other.val; while(res >= MOD) res -= MOD; while(res < 0) res += MOD; return Mint(res);}
	Mint operator-(const Mint& other) {ll res = val - other.val; while(res >= MOD) res -= MOD; while(res < 0) res += MOD; return Mint(res);}
	Mint operator*(const Mint& other) {return Mint((val * 1ll * other.val) % MOD);}
	Mint operator+=(const Mint& other) {val += other.val; while(val >= MOD) val -= MOD; while(val < 0) val += MOD; return val;}
	Mint operator-=(const Mint& other) {val -= other.val; while(val >= MOD) val -= MOD; while(val < 0) val += MOD; return val;}
	Mint operator*=(const Mint& other) {return val = (val * 1ll * other.val) % MOD;}
	Mint pow(ll y) {Mint z(1); Mint x(val); while(y > 0) {if(y % 2 == 1) z = z * x; x = x * x; y /= 2;} return z;}
	Mint operator/(const Mint& other) {return Mint(val) * Mint(other.val).pow(MOD - 2);}
	Mint() {val = 0;};
	Mint(ll x) {x %= MOD; while(x < 0) x += MOD; val = x;};
};

ostream& operator<<(ostream& out, const Mint& x) {return out << x.val;}







template<typename T>struct Matrix 
{
    vector< vector<T> > x;
    Matrix() {x.clear();}
    Matrix(int n) {x.resize(n); FOR(i, 0, n - 1) x[i].clear();}
    Matrix(int m, int n) {x.resize(m); FOR(i, 0, m - 1) {x[i].resize(n); FOR(j, 0, n - 1) x[i][j] = 0;}}
    int size() {return (ll)x.size();}
	void clear() {x.clear();}
	void push_back(vector<T> &other) {x.push_back(other);}
	void pop_back() {x.pop_back();}
	void resize(int a, int b) {x.resize(a); for (auto &o : x) o.resize(b);}
	void resize(int a) {x.resize(a);}
	void erase(typename vector<vector<T> >::iterator &it) {x.erase(it);}
	vector<T> &front() {return x.front();}
	vector<T> &back() {return x.back();}
    const vector<T>& operator [] (size_t i) const {return x[i];}
    vector<T>& operator [] (size_t i){return x[i];}
    Matrix<T>& operator = (const Matrix<T> &other) {x = other.x; return 1;}
	Matrix<T>& operator == (const Matrix<ll> &other) {return x == other.x;}
	typename vector<vector<T> >::iterator &begin() {return x.begin();}
	typename vector<vector<T> >::iterator &end() {return x.end();}
	typename vector<vector<T> >::reverse_iterator &rbegin() {return x.rbegin();}
	typename vector<vector<T> >::reverse_iterator &rend() {return x.rend();}
    void print() {FOR(i, 0, (ll)x.size() - 1){ FOR(j, 0, (ll)x[i].size() - 1) cout << x[i][j] << ' '; cout << '\n';}}
    Matrix transpose() const {int nRow = SZ(x); int nCol = SZ(x[0]); Matrix res(nCol, nRow); FOR(i, 0, nCol - 1) FOR(j, 0, nRow - 1) {res.x[i][j] = x[j][i];} return res;}
    void fill(T a) {for (auto &y : x) {for (auto &k : y) {k = a;}}}
	void gauss() 
	{
        int n = SZ(x);
        if (n == 0) return;

        int m = SZ(x[0]);

        vector<int> where(m, -1);
        for (int col = 0, row = 0; col < m && row < n; ++col) 
		{
            int sel = row;
            for (int i = row; i < n; ++i) 
			{
                if (abs(x[i][col]) > abs(x[sel][col]))
                    sel = i;
            }
            if (abs(x[sel][col]) < 1e-9)   

                continue;

            for (int i = col; i < m; ++i)
                swap(x[sel][i], x[row][i]);
            where[col] = row;

            for (int i = 0; i < n; ++i)
                if (i != row) {
                    T c = x[i][col] / x[row][col];  

                    for (int j = col; j < m; ++j)
                        x[i][j] -= x[row][j] * c;
                }

            T coef = x[row][col];
            if (coef > 1e-9) {
                for (int j = 0; j < m; ++j)
                    x[row][j] /= coef;
            }
            ++row;
        }
    }
    
	Matrix<T> identity(int n) 
	{
		Matrix<T> res(n, n);
	    FOR(i, 0, n - 1) res.x[i][i] = 1;
	    return res;
	}
    
	Matrix<T> power(Matrix<T> &a, int k) 
	{
	    assert(SZ(a.x) == SZ(a.x[0]));
	
	    Matrix<T> res = identity(a.x.size());
	
	    while (k > 0) 
		{
	        if (k & 1) res = res * a;
	        a = a * a;
	        k >>= 1;
	    }
	    return res;
	}

};

template<typename T> Matrix<T> operator * (const Matrix<T> &a, const Matrix<T> &b) {
    if (SZ(a.x) == 0 || SZ(b.x) == 0) return Matrix<T>(); 


    Matrix<T> c(SZ(a.x), SZ(b[0]));
    FOR(i, 0, SZ(c.x) - 1) FOR(j, 0, SZ(c[0]) - 1)
    {
        FOR(k, 0, SZ(a[0]) - 1)
            c[i][j] += a[i][k] * b[k][j];
    }
    return c;
}

template<typename T> Matrix<T> inverse(Matrix<T> a) 
{
    assert(SZ(a.x) == SZ(a[0]));
    int n = SZ(a.x);

    FOR(i, 0, n - 1)
	{
        vector<T> tmp(n);
        tmp[i] = 1;
        a[i].insert(a[i].end(), tmp.begin(), tmp.end());
    }

    a.gauss();

    Matrix<T> inv(n, n);
    FOR(i, 0, n - 1) FOR(j, 0, n - 1)
	{
        inv[i][j] = a[i][j+n];
    }
    return inv;
}







template<typename T> void getVector(T &a) {for (auto &x : a) cin >> x;}
template<typename T> void printVector(T &a) {for (auto &x: a) cout << x << ' ';}
template<typename T> void revrs(T &a) {reverse(a.begin(), a.end());}
template<typename T> void SORT(T &a) {sort(a.begin(), a.end());}
template<typename T> void SORTD(T &a) {sort(a.rbegin(), a.rend());}

template<typename T> T maxOf(T &a) {return max_element(a.begin(), a.end()) - a.begin();}
template<typename T> T minOf(T &a) {return min_element(a.begin(), a.end()) - a.begin();}
template<typename T> T Merge(T &a, T &b) {T c; merge(all(a), all(b), c.begin()); return c;}
template<typename T> void Fill(vector<T> &a, T k) {fill(a.begin(), a.end(), k);}
template<typename T> void Fill(deque<T> &a, T k) {fill(a.begin(), a.end(), k);}
template<typename T> void tlw(T &a) {for(int i=0; i<(sizeof(a)/sizeof(a[0])); i++) a[i] = tolower(a[i]);}
template<typename T> void tup(T &a) {for(int i=0; i<(sizeof(a)/sizeof(a[0])); i++) a[i] = toupper(a[i]);}
template<typename T> void Unique(T &a) {a.erase(unique(a.begin(), a.end()), a.end());}
template<typename T1, typename T2> ostream& operator<<(ostream& out, const p<T1, T2>& x) {return out << x.f << ' ' << x.s;}
template<typename T1, typename T2> istream& operator>>(istream& in, p<T1, T2>& x) {return in >> x.f >> x.s;}
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};
template<typename T> istream& operator>>(istream& in, deque<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, deque<T>& a) {for(auto &x : a) out << x << ' '; return out;};
template<typename T> using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
template<typename T> using ordered_multiset = tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
template<typename T> using pq = priority_queue<T>;
template<typename T> using reverse_pq = priority_queue<T, vector<T>, greater<T> >;












ld PI = 3.14159265358979323846;

ld eps = 1e-6;

ll M = 998244353;















bool id2(ll x)
{
	if (x < 2) return false;
	if (x == 2) return true;
	if (x % 2 == 0) return false;
	if (x == 3) return true;
	if (x % 3 == 0) return false;
	ll t = 1;
	for (ll i = 5; i * i <= x; i += 2 * (1 + t))
	{
		if (x % i == 0) return false;
		t = 1 - t;
	}
	return true;
}

ll fact[50005];
	string s;
	ll n, k;

void Ready()
{
	fact[0] = 1;
	FOR(i, 1, 50002)
	{
		fact[i] = (fact[i - 1] * i) % M;
	}
}

ll A(ll n, ll k)
{
	if (n < k) return 0;
	return fact[n] * id1(fact[n - k], M - 2, M) % M;
}

ll C(ll n, ll k)
{
	if (n < k) return 0;
	return A(n, k) * id1(fact[k], M - 2, M) % M;
}

void Process()
{
	cin >> n >> k;
	cin >> s;
	cin >> n >> k >> s;
    if (count(all(s), '1') < k || k == 0)
    {
    	cout << 1 << '\n';
    	return;
	}
	Ready();
	ll cnt = 0, l = 0, r = -1;
    while (r+1 < n && cnt + (s[r+1] == '1') <= k)
        cnt += s[++r] == '1';

    ll ans = C(r-l+1, k); 
    while (r != n - 1) {
        while (r+1 < n && cnt <= k)
            cnt += s[++r] == '1';
        ll m = r;
        while (r+1 < n && s[r+1] == '0')
            r++;
        while (s[l] == '0') l++; cnt--; l++;
        ans += C(r-l+1, k); ans %= M;
        ans += M - C(m-l, k-1); ans %= M;
    }
    cout << ans << '\n';
}

signed main() 
{
	faster();


		Process();
}















