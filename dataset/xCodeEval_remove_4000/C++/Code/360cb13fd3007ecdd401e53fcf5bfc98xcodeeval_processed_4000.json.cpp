
 




using namespace std;






























ll pow_mod(ll nn, ll pp, ll mm) { ll res = 1; while(pp > 0) { if(pp&1) res = (res * nn) % mm; pp = pp >> 1; nn = (nn * nn) % mm; } return res; }

inline int next_int() {int x;scanf(" %d", &x);return x;}
inline ll next_ll() {ll x;scanf(" %lld", &x);return x;}
inline char next_char() {char x;scanf(" %c", &x);return x;}
inline string next_string() {char x[1000100];scanf(" %s", x);return x;}
inline string next_line() {char x[1000100];fgets(x,1000010,stdin);return x;}
inline double next_double() {double x; scanf(" %lf", &x); return x;}
inline float next_float() {float x; scanf(" %f", &x); return x;}









template<typename T>void id0(T H);template<typename T,typename V>void id0(pair<T,V> H);
template<typename T>void id0(priority_queue<T> H);template<typename T>void id0(stack<T> H);
template<typename T,typename V>void id0(map<T,V> H);
template<typename T,typename V>void id0(multimap<T,V> H);template<typename T>void id0(vector<T> H);
template<typename T>void id0(set<T> H);template<typename T>void id0(multiset<T> H);
template<typename T>void id0(list<T> H);template<typename T>void id0(T *H);
template<typename T>void id0(deque<T> H);template<typename T>void id0(queue<T> H);
template<typename T>void id0(T H){stringstream ss;ss<<H;cerr<<ss.str();}
template<typename T,typename V>void id0(pair<T,V> H){cerr<<"(";id0(H.first);cerr<<"=>";id0(H.second);cerr<<")";}
template<typename T>void id0(priority_queue<T> H){cerr<<endl;while(!H.empty()){cerr<<H.top()<<endl;H.pop();}cerr<<endl;}
template<typename T>void id0(stack<T> H){cerr<<endl;while(!H.empty()){cerr<<H.top()<<endl;H.pop();}}
template<typename T,typename V>void id0(map<T,V> H){cerr<<"[ ";for(auto val : H){id0(val);cerr<<" ";}cerr<<"]";}
template<typename T,typename V>void id0(multimap<T,V> H){cerr<<"[ ";for(auto val : H){id0(val);cerr<<" ";}cerr<<"]";}
template<typename T>void id0(vector<T> H){cerr<<"[ ";for(auto val : H){id0(val);cerr<<' ';}cerr<<"]";}
template<typename T>void id0(set<T> H){cerr<<"[ ";for(auto val : H){id0(val);cerr<<' ';}cerr<<"]";}
template<typename T>void id0(multiset<T> H){cerr<<"[ ";for(auto val : H){id0(val);cerr<<' ';}cerr<<"]";}
template<typename T>void id0(list<T> H){cerr<<"[ ";for(auto val : H){id0(val);cerr<<' ';}cerr<<"]";}
template<typename T>void id0(T *H){cerr<<"[ ";for(auto val : H){id0(val);cerr<<' ';}cerr<<"]";}
template<typename T>void id0(deque<T> H){cerr<<"[ ";for(auto val : H){id0(val);cerr<<' ';}cerr<<"]";}
template<typename T>void id0(queue<T> H){cerr<<"[ ";while(!H.empty()){id0(H.front());cerr<<' ';H.pop();}cerr<<"]";}
vector<string>id1(string s){s+=',';vector<string>res;while(!s.empty())
res.push_back(s.substr(0, s.find(','))),s=s.substr(s.find(',')+1);return res;}
void dbg_out(vector<string>__attribute__((unused))args,__attribute__((unused))int idx,__attribute__((unused))int LINE_NUM)
{cerr<<endl;}template<typename Head,typename... Tail>
void dbg_out ( vector <string> args, int idx, int LINE_NUM, Head H, Tail... T)
{if(idx>0)cerr<<", ";else cerr << "Line(" << LINE_NUM << "):";
cerr<<"\n"<<args[idx]<<" = ";id0(H);dbg_out(args,idx+1,LINE_NUM, T...);}
















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
    ll a[n+1];
    vector<ll> negs, poss;
    forr(i,1,n)
    {
    	cin >> a[i];
    	if(a[i] < 0) negs.pb(a[i]);
    	else poss.pb(a[i]);
    }
    sort(all(negs));
    sort(all(poss));
    reverse(all(poss));
    reverse(all(negs));
    ll neg[6], pos[6];
    forr(i,0,5)
    {
    	neg[i] = pos[i] = LONG_MAX;
    }
    neg[0] = pos[0] = 1;

    if(negs.size() >= 1) neg[1] = negs[0];
    if(negs.size() >= 3) neg[3] = negs[0] * negs[1] * negs[2];
    if(negs.size() >= 5) neg[5] = negs[0] * negs[1] * negs[2] * negs[3] * negs[4];
    reverse(all(negs));
    if(negs.size() >= 2) neg[2] = negs[0] * negs[1];
    if(negs.size() >= 4) neg[4] = negs[0] * negs[1] * negs[2] * negs[3];

    if(poss.size() >= 1) pos[1] = poss[0];
    if(poss.size() >= 3) pos[3] = poss[0]*poss[1]*poss[2];
    if(poss.size() >= 5) pos[5] = poss[0]*poss[1]*poss[2]*poss[3]*poss[4];
    reverse(all(poss));
    if(poss.size() >= 2) pos[2] = poss[0]*poss[1];
    if(poss.size() >= 4) pos[4] = poss[0]*poss[1]*poss[2]*poss[3];

    ll ans = n_inf;
    forr(i,0,5)
    {
    	

    	if(neg[i] == LONG_MAX || pos[5-i] == LONG_MAX) continue;
    	ans = max(neg[i] * pos[5-i], ans);
    }
    cout << ans << nl;
}