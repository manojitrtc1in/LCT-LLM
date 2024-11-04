
 



#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long
#define elif else if
#define pb push_back
#define mp make_pair
#define nl '\n'
#define forr(i,b,e) for(int i=b;i<=e;i++)
#define forrv(i,b,e) for(int i=b;i>=e;i--)
#define fors(i,x) for(auto i=x.begin(); i!=x.end(); i++)
#define F first
#define S second
#define mset0(x) memset(x, 0, sizeof x);
#define mset1(x) memset(x, -1, sizeof x);
#define all(x) x.begin(),x.end()
#define pqmin(x) priority_queue<x, vector<x>, greater<x> >
#define pqmax(x) priority_queue<x>
#define sortdsc(xbeg,xend) sort(xbeg, xend); reverse(xbeg, xend)
#define pii pair<int,int>
#define mpii map<int,int>
#define pi 3.14159265358979323846D
#define p_inf 9223372034707259391LL
#define n_inf -9223372034707259392LL
#define gcd(x,y) __gcd(x,y)
#define lcm(x,y) (x*(y/__gcd(x,y)))
#define chkbit(x,p) ((x&(1LL<<p))?1:0)
#define setbit(x,p) x|=(1LL<<p)
#define clrbit(x,p) x=x&(~(1LL<<p))
#define revbit(x,p) (chkbit(x,p)?clrbit(x,p):setbit(x,p))
#define runtime() cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"
#define power(nn,pp) pow_mod(nn, pp, (1LL<<62))
ll pow_mod(ll nn, ll pp, ll mm) { ll res = 1; while(pp > 0) { if(pp&1) res = (res * nn) % mm; pp = pp >> 1; nn = (nn * nn) % mm; } return res; }

inline int next_int() {int x;scanf(" %d", &x);return x;}
inline ll next_ll() {ll x;scanf(" %lld", &x);return x;}
inline char next_char() {char x;scanf(" %c", &x);return x;}
inline string next_string() {char x[1000100];scanf(" %s", x);return x;}
inline string next_line() {char x[1000100];fgets(x,1000010,stdin);return x;}
inline double next_double() {double x; scanf(" %lf", &x); return x;}
inline float next_float() {float x; scanf(" %f", &x); return x;}
#define nxint next_int()
#define nxll next_ll()
#define nxchar next_char()
#define nxstring next_string()
#define nxline next_line()
#define nxdouble next_double()
#define nxfloat next_float()

#ifdef oliumPC
template<typename T>void showSTL(T H);template<typename T,typename V>void showSTL(pair<T,V> H);
template<typename T>void showSTL(priority_queue<T> H);template<typename T>void showSTL(stack<T> H);
template<typename T,typename V>void showSTL(map<T,V> H);
template<typename T,typename V>void showSTL(multimap<T,V> H);template<typename T>void showSTL(vector<T> H);
template<typename T>void showSTL(set<T> H);template<typename T>void showSTL(multiset<T> H);
template<typename T>void showSTL(list<T> H);void showSTL(char *H);
template<typename T>void showSTL(deque<T> H);template<typename T>void showSTL(queue<T> H);
template<typename T>void showSTL(T H){stringstream ss;ss<<H;cerr<<ss.str();}
template<typename T,typename V>void showSTL(pair<T,V> H){cerr<<"(";showSTL(H.first);cerr<<"=>";showSTL(H.second);cerr<<")";}
template<typename T>void showSTL(priority_queue<T> H){cerr<<endl;while(!H.empty()){cerr<<H.top()<<endl;H.pop();}cerr<<endl;}
template<typename T>void showSTL(stack<T> H){cerr<<endl;while(!H.empty()){cerr<<H.top()<<endl;H.pop();}}
template<typename T,typename V>void showSTL(map<T,V> H){cerr<<"[ ";for(auto val:H){showSTL(val);cerr<<" ";}cerr<<"]";}
template<typename T,typename V>void showSTL(multimap<T,V> H){cerr<<"[ ";for(auto val:H){showSTL(val);cerr<<" ";}cerr<<"]";}
template<typename T>void showSTL(vector<T> H){cerr<<"[ ";for(auto val : H){showSTL(val);cerr<<' ';}cerr<<"]";}
template<typename T>void showSTL(set<T> H){cerr<<"[ ";for(auto val : H){showSTL(val);cerr<<' ';}cerr<<"]";}
template<typename T>void showSTL(multiset<T> H){cerr<<"[ ";for(auto val : H){showSTL(val);cerr<<' ';}cerr<<"]";}
template<typename T>void showSTL(list<T> H){cerr<<"[ ";for(auto val : H){showSTL(val);cerr<<' ';}cerr<<"]";}
void showSTL(char *H){for(int i=0;i<strlen(H);i++){showSTL(H[i]);};}
template<typename T>void showSTL(deque<T> H){cerr<<"[ ";for(auto val : H){showSTL(val);cerr<<' ';}cerr<<"]";}
template<typename T>void showSTL(queue<T> H){cerr<<"[ ";while(!H.empty()){showSTL(H.front());cerr<<' ';H.pop();}cerr<<"]";}
vector<string>vec_spltr(string s){s+=',';vector<string>res;while(!s.empty())
res.push_back(s.substr(0, s.find(','))),s=s.substr(s.find(',')+1);return res;}
void dbg_out(vector<string>__attribute__((unused))args,__attribute__((unused))int idx,__attribute__((unused))int LINE_NUM)
{cerr<<endl;}template<typename Head,typename... Tail>
void dbg_out ( vector <string> args, int idx, int LINE_NUM, Head H, Tail... T)
{if(idx>0)cerr<<", ";else cerr << "Line(" << LINE_NUM << "):";
cerr<<"\n"<<args[idx]<<" = ";showSTL(H);dbg_out(args,idx+1,LINE_NUM, T...);}
#define debug(...) dbg_out(vec_spltr(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#define in_file freopen("input.c", "r", stdin)
#define out_file freopen("output.c", "w", stdout)
#define fast_io 0
#else
#define debug(...) 0
#define in_file 0
#define out_file 0
#define fast_io ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#endif




#define MOD 10000007
#define MAX 100010
void olium();

int main()
{
    in_file;
    

    fast_io;
    int t = 1;
    cin >> t;
    forr(i,1,t)
    {
        

        olium();
    }
    return 0;
}

void olium()
{
    int n;
    cin >> n;
    ll ase[35] = {0};
    forr(i,1,n)
    {
    	ll tmp;
    	cin >> tmp;
    	if(tmp == 0) setbit(tmp,40);
    	int mxdx = -1;
    	forr(j,0,60)
    	{
    		if(chkbit(tmp,j)) mxdx = j;
    	}
    	if(mxdx != -1) ase[mxdx]++;
    }
    ll ans = 0;
    forr(i,0,34)
    {
    	ans += ((ase[i] * (ase[i]-1)))/2;
    }
    cout << ans << nl;
}