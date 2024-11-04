#pragma GCC target ("avx2")
#include<bits/stdc++.h>







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





#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define er "\n"

#define rep(i, x, y)  for(int i = x; i < y; ++i)
#define Rep(i, x, y)  for(int i = x; i <= y; ++i)
#define sRep(i, x, y) for(int i = x; i >= y; --i)
#define ite(it,s) for(auto it = s.begin(); it!=s.end(); ++it)
	
#define getBit(x,i) (x&(1<<i))
#define setBit(x,i) (x|(1<<i))
#define mid(L,R) ((L+R)/2)
#define mem(A,N) memset(A,N,sizeof(A))
#define sz(x) ((int)(x).size())

#define all(v) v.begin(),v.end()
#define rev(v) reverse(v.begin(),v.end())
#define Sort(x) sort(x.begin(),x.end());



#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front



#define mp make_pair
#define fi first
#define se second



#define srep(i, x, y) for(int i = x; i > y; --i)
#define rep2(i, x, y)  for(int i = x; i < y; i+=2)
#define Rep2(i, x, y)  for(int i = x; i <= y; i+=2)
#define sRep2(i, x, y) for(int i = x; i >= y; i-=2)
#define srep2(i, x, y) for(int i = x; i > y; i-=2)

#define sumsTo(s) ((int)((-1+sqrt(1+8*s))/2))
#define inBounds(x,y) (x >= 0 && x < n && y >= 0 && y < m)
#define isInt(x) ((int) floor(x)==x)

#define yes() (cout << "yes\n");
#define no() (cout << "no\n");
#define Yes() (cout << "YES\n");
#define No() (cout << "NO\n");
#define yes2() (cout << "Yes\n");
#define no2() (cout << "No\n");

#define linf 1000000000000000001LL
#define inf 1000000001
#define mod 1000000007
#define eps 1e-9
#define Pi 3.14159265358979323846



#ifndef ONLINE_JUDGE
#define dump(x)  cerr << #x << "=" << (x) << endl;
#define write(x) cerr << #x << "=" << (x) << ", ";
#define writeSet(s) cerr << #s << "= "; for(auto it = s.begin(); it!=s.end(); it++) (it==s.begin())? cerr << *it : cerr << ' ' << *it;
#define dumpSet(s) cerr << #s << "= "; for(auto it = s.begin(); it!=s.end(); it++) (it==s.begin())? cerr << *it : cerr << ' ' << *it; cerr << endl;
#define writeMap(s) cerr << #s << "= "; for(auto it = s.begin(); it!=s.end(); it++) (it==s.begin())? cerr << it->first << ',' << it->second : cerr << ' ' << it->first << ',' << it->second;
#define dumpMap(s) cerr << #s << "= "; for(auto it = s.begin(); it!=s.end(); it++) (it==s.begin())? cerr << it->first << ',' << it->second : cerr << ' ' << it->first << ',' << it->second; cerr << endl;



#define writei cerr << "i = " << i << ".. ";
#define dumpi cerr << "i = " << i << endl;
#define writej cerr << "j = " << j << ".. ";
#define dumpj cerr << "j = " << j << endl;
#define writek cerr << "k = " << k << ".. ";
#define dumpk cerr << "k = " << k << endl;
#define writep cerr << "p = " << p << ".. ";
#define dumpp cerr << "p = " << p << endl;
#endif

void __print(int x) {cerr << x;}                           string __strprint(int x) {return to_string(x);}                              
void __print(long x) {cerr << x;}                          string __strprint(long x) {return to_string(x);}
void __print(long long x) {cerr << x;}                     string __strprint(long long x) {return to_string(x);}
void __print(unsigned x) {cerr << x;}                      string __strprint(unsigned x) {return to_string(x);}
void __print(unsigned long x) {cerr << x;}                 string __strprint(unsigned long x) {return to_string(x);}
void __print(unsigned long long x) {cerr << x;}            string __strprint(unsigned long long x) {return to_string(x);}
void __print(float x) {cerr << x;}                         string __strprint(float x) {return to_string(x);}
void __print(double x) {cerr << x;}                        string __strprint(double x) {return to_string(x);}
void __print(long double x) {cerr << x;}                   string __strprint(long double x) {return to_string(x);}
void __print(char x) {cerr << '\'' << x << '\'';}          string ___strprint(char x) {return "\'" + string(1,x) + "\'";}
void __print(const char *x) {cerr << '\"' << x << '\"';}   string __strprint(const char *x) {return "\"" + string(x) + "\"";} 
void __print(const string &x) {cerr << '\"' << x << '\"';} string __strprint(const string &x) {return "\"" + x + "\"";} 
void __print(bool x) {cerr << (x ? "true" : "false");}     string ___strprint(bool x) {return (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

template<typename T, typename V>
string __strprint(const pair<T, V> &x) {string build="{"; build+=__strprint(x.first); build+=","; build+=__strprint(x.second); return build+"}";}
template<typename T>
string __strprint(const T &x) {int f = 0; string build="{"; for (auto &i: x) build+=(f++ ? "," : ""), build+=__strprint(i); return build+"}";}
string _strprint() {return "]";}
template <typename T, typename... V>
string _strprint (T t, V... v) {string build=__strprint(t); if (sizeof...(v)) build+=", "; return build+_strprint(v...);}

ostream& operator << (ostream& os, const ii& p) { return (os << '(' << p.first << ',' << p.second << ')'); }
template<typename T, typename V> pair<T, V> operator + (const pair<T, V>& p1, const pair<T, V>& p2) { return make_pair(p1.first+p2.first,p1.second+p2.second); }
template<typename T, typename V> pair<T, V> operator - (const pair<T, V>& p1, const pair<T, V>& p2) { return make_pair(p1.first-p2.first,p1.second-p2.second); }
template<typename T, typename V> pair<T, V> operator * (const pair<T, V>& p1, const pair<T, V>& p2) { return make_pair(p1.first*p2.first,p1.second*p2.second); }
template<typename T> typename T::iterator min_map_element(T& m) { return min_element(m.begin(), m.end(), [](typename T::value_type& l, typename T::value_type& r) -> bool { return l.second < r.second; }); }
template<typename T> typename T::iterator max_map_element(T& m) { return max_element(m.begin(), m.end(), [](typename T::value_type& l, typename T::value_type& r) -> bool { return l.second < r.second; }); }

inline constexpr uint32_t operator "" ui(unsigned long long arg) noexcept { return static_cast<uint32_t>(arg); }



#define printArray(a,x,y)  for(auto it = (a)+(x);      it != (a)+(y);   it++) (it==(a)+(x))     ? cout << *it : cout << ' ' << *it; cout << '\n';
#define PrintArray(a,x,y)  for(auto it = (a)+(x);      it != (a)+(y)+1; it++) (it==(a)+(x))     ? cout << *it : cout << ' ' << *it; cout << '\n';
#define sPrintArray(a,x,y) for(auto it = (a)+(x);      it != (a)+(y)-1; it--) (it==(a)+(x))     ? cout << *it : cout << ' ' << *it; cout << '\n';
#define printVector(x)     for(auto it = (x).begin();  it!=(x).end();   it++) (it==(x).begin()) ? cout << *it : cout << ' ' << *it; cout << '\n';
#define sprintVector(x)    for(auto it = (x).rbegin(); it!=(x).rend();  it++) (it==(x).rbegin())? cout << *it : cout << ' ' << *it; cout << '\n';
#define sPrintVector(x)    for(auto it = (x).rbegin(); it!=(x).rend();  it++) (it==(x).rbegin())? cout << *it : cout << ' ' << *it; cout << '\n'; 

#define printSet(s)        for(auto it = s.begin();    it!=s.end();     it++) (it==(s).begin()) ? cout << *it : cout << ' ' << *it; cout << '\n';
#define sprintSet(s)       for(auto it = s.rbegin();   it!=s.rend();    it++) (it==(s).rbegin())? cout << *it : cout << ' ' << *it; cout << '\n';
#define printPairset(s)    for(auto it = (s).begin();  it!=(s).end();   it++) (it==(s).begin()) ? cout << '(' << it->first << ',' << it->second << ')' : cout << " {" << it->first << ',' << it->second << '}'; cout << '\n';
#define sprintPairset(s)   for(auto it = (s).rbegin(); it!=(s).rend();  it++) (it==(s).rbegin())? cout << '(' << it->first << ',' << it->second << ')' : cout << " {" << it->first << ',' << it->second << '}'; cout << '\n';

#define printArrayln(a,x,y) for(auto it = (a)+(x);     it != (a)+(y);   it++) (it==(a)+(x))      ? cout << *it : cout << '\n' << *it; cout << '\n';
#define PrintArrayln(a,x,y) for(auto it = (a)+(x);     it != (a)+(y)+1; it++) (it==(a)+(x))      ? cout << *it : cout << '\n' << *it; cout << '\n';
#define sPrintArrayln(a,x,y)  for(auto it = (a)+(x);     it != (a)+(y)-1; it++) (it==(a)+(x))      ? cout << *it : cout << '\n' << *it; cout << '\n';
#define printVectorln(x)    for(auto it = (x).begin();  it!=(x).end();   it++) (it==(x).begin()) ? cout << *it : cout << '\n' << *it; cout << '\n';
#define sprintVectorln(x)   for(auto it = (x).rbegin(); it!=(x).rend();  it++) (it==(x).rbegin())? cout << *it : cout << '\n' << *it; cout << '\n';
#define sPrintVectorln(x)   for(auto it = (x).rbegin(); it!=(x).rend();  it++) (it==(x).rbegin())? cout << *it : cout << '\n' << *it; cout << '\n'; 

#define printSetln(s)       for(auto it = s.begin();    it!=s.end();     it++) (it==(s).begin()) ? cout << *it : cout << '\n' << *it; cout << '\n';
#define sprintSetln(s)      for(auto it = s.rbegin();   it!=s.rend();    it++) (it==(s).rbegin())? cout << *it : cout << '\n' << *it; cout << '\n';
#define printPairsetln(s)   for(auto it = (s).begin();  it!=(s).end();   it++) (it==(s).begin()) ? cout << '(' << it->first << ',' << it->second << ')' : cout << "\n{" << it->first << ',' << it->second << '}'; cout << '\n';
#define sprintPairsetln(s)  for(auto it = (s).rbegin(); it!=(s).rend();  it++) (it==(s).rbegin())? cout << '(' << it->first << ',' << it->second << ')' : cout << "\n{" << it->first << ',' << it->second << '}'; cout << '\n';



#define sprintArray(a,x,y) for(auto it = (a)+(x);      it != (a)+(y);   it--) (it==(a)+(x))     ? cout << *it : cout << ' ' << *it; cout << '\n';
#define sprintArrayln(a,x,y) for(auto it = (a)+(x);      it != (a)+(y);   it--) (it==(a)+(x))    ? cout << *it : cout << '\n' << *it; cout << '\n';

ostringstream debug_sstr; string debug_str; vector<string> debug_strvec;
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#define sdebug(x...) (debug_sstr<<"["<<#x<<"]=["<<_strprint(x),debug_str=debug_sstr.str(),debug_sstr=ostringstream(),debug_str)
#define sDebugVector(v,a,x,y) for(auto it = (a)+(x); it != (a)+(y)+1; it++) (it==(a)+(x)) ? debug_sstr << *it : debug_sstr << ' ' << *it; (debug_str=debug_sstr.str(),debug_sstr=ostringstream(),(v).push_back(debug_str))
#define sDebugVector2(v,a,x,y) debug_strvec = vector<string>(); for(auto it = (a)+(x); it != (a)+(y)+1; it++) debug_strvec.push_back(to_string(*it)); v.push_back(debug_strvec);
#else
#define debug(x...)
#endif




int n, d;
ll c;
ll rem;
int a [200000];
ll pre [200000];

int binarySearch2(int lo, int hi) {
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
	ll daysMultiples = c / sum;
	ll days = daysMultiples * (k + 1);
	rem = c % sum;
	if (!rem) {
		days -= (k + 1);
		days += idx + 1;
		return days <= d;
	}
	int res = binarySearch2(0, (int) min(n - 1LL, k));
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
