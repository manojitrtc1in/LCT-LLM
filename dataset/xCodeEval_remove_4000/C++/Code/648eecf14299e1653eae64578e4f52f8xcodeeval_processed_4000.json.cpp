








using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef unsigned int uint;
typedef unsigned long long ull;












	






































































void __print(int x) {cerr << x;}                           string id6(int x) {return to_string(x);}                              
void __print(long x) {cerr << x;}                          string id6(long x) {return to_string(x);}
void __print(long long x) {cerr << x;}                     string id6(long long x) {return to_string(x);}
void __print(unsigned x) {cerr << x;}                      string id6(unsigned x) {return to_string(x);}
void __print(unsigned long x) {cerr << x;}                 string id6(unsigned long x) {return to_string(x);}
void __print(unsigned long long x) {cerr << x;}            string id6(unsigned long long x) {return to_string(x);}
void __print(float x) {cerr << x;}                         string id6(float x) {return to_string(x);}
void __print(double x) {cerr << x;}                        string id6(double x) {return to_string(x);}
void __print(long double x) {cerr << x;}                   string id6(long double x) {return to_string(x);}
void __print(char x) {cerr << '\'' << x << '\'';}          string id3(char x) {return "\'" + string(1,x) + "\'";}
void __print(const char *x) {cerr << '\"' << x << '\"';}   string id6(const char *x) {return "\"" + string(x) + "\"";} 
void __print(const string &x) {cerr << '\"' << x << '\"';} string id6(const string &x) {return "\"" + x + "\"";} 
void __print(bool x) {cerr << (x ? "true" : "false");}     string id3(bool x) {return (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

template<typename T, typename V>
string id6(const pair<T, V> &x) {string build="{"; build+=id6(x.first); build+=","; build+=id6(x.second); return build+"}";}
template<typename T>
string id6(const T &x) {int f = 0; string build="{"; for (auto &i: x) build+=(f++ ? "," : ""), build+=id6(i); return build+"}";}
string _strprint() {return "]";}
template <typename T, typename... V>
string _strprint (T t, V... v) {string build=id6(t); if (sizeof...(v)) build+=", "; return build+_strprint(v...);}

ostream& operator << (ostream& os, const ii& p) { return (os << '(' << p.first << ',' << p.second << ')'); }
template<typename T, typename V> pair<T, V> operator + (const pair<T, V>& p1, const pair<T, V>& p2) { return make_pair(p1.first+p2.first,p1.second+p2.second); }
template<typename T, typename V> pair<T, V> operator - (const pair<T, V>& p1, const pair<T, V>& p2) { return make_pair(p1.first-p2.first,p1.second-p2.second); }
template<typename T, typename V> pair<T, V> operator * (const pair<T, V>& p1, const pair<T, V>& p2) { return make_pair(p1.first*p2.first,p1.second*p2.second); }
template<typename T> typename T::iterator id5(T& m) { return min_element(m.begin(), m.end(), [](typename T::value_type& l, typename T::value_type& r) -> bool { return l.second < r.second; }); }
template<typename T> typename T::iterator id7(T& m) { return max_element(m.begin(), m.end(), [](typename T::value_type& l, typename T::value_type& r) -> bool { return l.second < r.second; }); }

inline constexpr uint32_t operator "" ui(unsigned long long arg) noexcept { return static_cast<uint32_t>(arg); }
































ostringstream id1; string debug_str; vector<string> id4;












int n, d;
ll c;
ll rem;
int a [200000];
ll pre [200000];

int id0(int lo, int hi) {
	int mid, hi_ = hi;
	while(lo <= hi) {
		mid = (lo + hi) >> 1;
		if(pre[mid] >= rem)
			hi = mid - 1;
		else
			lo = mid + 1;
	}
	if (lo <= hi_ && pre[lo] >= rem)
		return lo;
	return -1;
}

bool f(ll k) {
	int idx = (int) min(n - 1LL, k);
	ll sum = pre[idx];
	ll id2 = c / sum;
	ll days = id2 * (k + 1);
	rem = c % sum;
	if (!rem) {
		days -= (k + 1);
		days += idx + 1;
		return days <= d;
	}
	int res = id0(0, (int) min(n - 1LL, k));
	days += (res + 1);
	return days <= d;
}

long long binarySearch(long long lo, long long hi) {
	long long mid, lo_ = lo;
	while(lo <= hi) {
		mid = (lo + hi) >> 1LL;
		if(f(mid))
			lo = mid + 1;
		else
			hi = mid - 1;
	}
	if (lo - 1 >= lo_ && f(lo - 1))
		return lo - 1;
	return -1;
}

int main() {
	fastio;
	int tc; cin >> tc;
	while(tc--) {
		cin >> n >> c >> d;
		rep(i,0,n) cin >> a[i];
		sort(a, a+n, greater<int>());
		pre[0] = a[0];
		rep(i,1,n) pre[i] = pre[i-1] + a[i];
		if (pre[min(n - 1, d - 1)] >= c) {
			cout << "Infinity\n";
		} else {
			ll res = binarySearch(0, d);
			if (res == -1) {
			cout << "Impossible\n";
			} else {
				cout << res << '\n';
			}
		}
	}
	return 0;
}
