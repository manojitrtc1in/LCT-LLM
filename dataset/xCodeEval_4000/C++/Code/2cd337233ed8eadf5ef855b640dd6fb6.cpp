





#include <bits/stdc++.h>
using namespace std;

#define for1(i,a,b) for (int i = a; i <= b; i++)
#define for2(i,a,b) for (int i = a; i >= b; i--)
#define loga(a,b) log(b) / log(a)

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define ALL(x) (x).begin(), (x).end()
#define pb push_back
#define ins insert
#define sz(a) (int)a.size()

#define fi first
#define se second
#define mp make_pair
#define lb lower_bound 

#define ub upper_bound 


#define _max *max_element
#define _min *min_element

#define _input() int test; cin >> test; while (test--)

typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <int> vi;

const int PI = 3.1415926535897932384626433832795;
const int INF = 8000000000000000000;
const int mod = 1000000007;
const int MOD = 1000000007;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};





namespace Output
{
    void print(int x) {cout << x << "\n";}
    void print(unsigned int x) {cout << x << "\n";}
    void print(float x) {cout << x << "\n";}
    void print(double x) {cout << x << "\n";}
    void print(long double x) {cout << x << "\n";}
    void print(char x) {cout << x << "\n";}
    void print(char* x) {cout << x << "\n";}
    void print(unsigned char x) {cout << x << "\n";}
    void print(const char* x) {cout << x << "\n";}
    void print(string x) {cout << x << "\n";}
    void print(bool x) {cout << x << "\n";}

    template <class T, class... Ts> void print(T t, Ts... ts){
        cout << t << " ";
        print(ts...);
    }

    template <typename T1, typename T2> void print(pair <T1, T2> a) {print(a.first, a.second);}
    template <typename T> void print(T a){
        for(int it : a){
            print(it);
        }
    }

    template <class T, class... Ts> void prine(T t, Ts... ts){
        print(t, ts...);
        exit(0);
    }
}

namespace Output1
{
    void print(int x) {cout << x << "\n";}
    void print(unsigned int x) {cout << x << "\n";}
    void print(float x) {cout << x << "\n";}
    void print(double x) {cout << x << "\n";}
    void print(long double x) {cout << x << "\n";}
    void print(char x) {cout << x << "\n";}
    void print(char* x) {cout << x << "\n";}
    void print(unsigned char x) {cout << x << "\n";}
    void print(const char* x) {cout << x << "\n";}
    void print(string x) {cout << x << "\n";}
    void print(bool x) {cout << x << "\n";}

    template <class T, class... Ts> void print(T t, Ts... ts){
        cout << t << " ";
        print(ts...);
    }

    template <typename T1, typename T2> void print(pair <T1, T2> a) {print(a.first, a.second);}
    template <typename T> void print(T a){
        for(int it : a){
            print(it);
        }
    }

    template <class T, class... Ts> void prine(T t, Ts... ts){
        print(t, ts...);
        exit(0);
    }
}

using namespace Output;




bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
}

int power(int x, int n) 
{
    int res = 1;
    
    while (n > 0) {
        
        if (n & 1) res = (res * x) % MOD;
        x = (x * x) % MOD;
        n >>= 1;

    }
    
    return res;
}

int gcd(int a, int b) 
{    
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}























namespace Output2
{
    void print(int x) {cout << x << "\n";}
    void print(unsigned int x) {cout << x << "\n";}
    void print(float x) {cout << x << "\n";}
    void print(double x) {cout << x << "\n";}
    void print(long double x) {cout << x << "\n";}
    void print(char x) {cout << x << "\n";}
    void print(char* x) {cout << x << "\n";}
    void print(unsigned char x) {cout << x << "\n";}
    void print(const char* x) {cout << x << "\n";}
    void print(string x) {cout << x << "\n";}
    void print(bool x) {cout << x << "\n";}

    template <class T, class... Ts> void print(T t, Ts... ts){
        cout << t << " ";
        print(ts...);
    }

    template <typename T1, typename T2> void print(pair <T1, T2> a) {print(a.first, a.second);}
    template <typename T> void print(T a){
        for(int it : a){
            print(it);
        }
    }

    template <class T, class... Ts> void prine(T t, Ts... ts){
        print(t, ts...);
        exit(0);
    }
}

namespace Output5
{
    void print(int x) {cout << x << "\n";}
    void print(unsigned int x) {cout << x << "\n";}
    void print(float x) {cout << x << "\n";}
    void print(double x) {cout << x << "\n";}
    void print(long double x) {cout << x << "\n";}
    void print(char x) {cout << x << "\n";}
    void print(char* x) {cout << x << "\n";}
    void print(unsigned char x) {cout << x << "\n";}
    void print(const char* x) {cout << x << "\n";}
    void print(string x) {cout << x << "\n";}
    void print(bool x) {cout << x << "\n";}

    template <class T, class... Ts> void print(T t, Ts... ts){
        cout << t << " ";
        print(ts...);
    }

    template <typename T1, typename T2> void print(pair <T1, T2> a) {print(a.first, a.second);}
    template <typename T> void print(T a){
        for(int it : a){
            print(it);
        }
    }

    template <class T, class... Ts> void prine(T t, Ts... ts){
        print(t, ts...);
        exit(0);
    }
}


namespace Output3
{
    void print(int x) {cout << x << "\n";}
    void print(unsigned int x) {cout << x << "\n";}
    void print(float x) {cout << x << "\n";}
    void print(double x) {cout << x << "\n";}
    void print(long double x) {cout << x << "\n";}
    void print(char x) {cout << x << "\n";}
    void print(char* x) {cout << x << "\n";}
    void print(unsigned char x) {cout << x << "\n";}
    void print(const char* x) {cout << x << "\n";}
    void print(string x) {cout << x << "\n";}
    void print(bool x) {cout << x << "\n";}

    template <class T, class... Ts> void print(T t, Ts... ts){
        cout << t << " ";
        print(ts...);
    }

    template <typename T1, typename T2> void print(pair <T1, T2> a) {print(a.first, a.second);}
    template <typename T> void print(T a){
        for(int it : a){
            print(it);
        }
    }

    template <class T, class... Ts> void prine(T t, Ts... ts){
        print(t, ts...);
        exit(0);
    }
}


namespace Output4
{
    void print(int x) {cout << x << "\n";}
    void print(unsigned int x) {cout << x << "\n";}
    void print(float x) {cout << x << "\n";}
    void print(double x) {cout << x << "\n";}
    void print(long double x) {cout << x << "\n";}
    void print(char x) {cout << x << "\n";}
    void print(char* x) {cout << x << "\n";}
    void print(unsigned char x) {cout << x << "\n";}
    void print(const char* x) {cout << x << "\n";}
    void print(string x) {cout << x << "\n";}
    void print(bool x) {cout << x << "\n";}

    template <class T, class... Ts> void print(T t, Ts... ts){
        cout << t << " ";
        print(ts...);
    }

    template <typename T1, typename T2> void print(pair <T1, T2> a) {print(a.first, a.second);}
    template <typename T> void print(T a){
        for(int it : a){
            print(it);
        }
    }

    template <class T, class... Ts> void prine(T t, Ts... ts){
        print(t, ts...);
        exit(0);
    }
}

clock_t startTime;
double getCurrentTime() 
{
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

namespace Output121312312
{
    void print(int x) {cout << x << "\n";}
    void print(unsigned int x) {cout << x << "\n";}
    void print(float x) {cout << x << "\n";}
    void print(double x) {cout << x << "\n";}
    void print(long double x) {cout << x << "\n";}
    void print(char x) {cout << x << "\n";}
    void print(char* x) {cout << x << "\n";}
    void print(unsigned char x) {cout << x << "\n";}
    void print(const char* x) {cout << x << "\n";}
    void print(string x) {cout << x << "\n";}
    void print(bool x) {cout << x << "\n";}

    template <class T, class... Ts> void print(T t, Ts... ts){
        cout << t << " ";
        print(ts...);
    }

    template <typename T1, typename T2> void print(pair <T1, T2> a) {print(a.first, a.second);}
    template <typename T> void print(T a){
        for(int it : a){
            print(it);
        }
    }

    template <class T, class... Ts> void prine(T t, Ts... ts){
        print(t, ts...);
        exit(0);
    }
}

namespace Output1wqeqwesd
{
    void print(int x) {cout << x << "\n";}
    void print(unsigned int x) {cout << x << "\n";}
    void print(float x) {cout << x << "\n";}
    void print(double x) {cout << x << "\n";}
    void print(long double x) {cout << x << "\n";}
    void print(char x) {cout << x << "\n";}
    void print(char* x) {cout << x << "\n";}
    void print(unsigned char x) {cout << x << "\n";}
    void print(const char* x) {cout << x << "\n";}
    void print(string x) {cout << x << "\n";}
    void print(bool x) {cout << x << "\n";}

    template <class T, class... Ts> void print(T t, Ts... ts){
        cout << t << " ";
        print(ts...);
    }

    template <typename T1, typename T2> void print(pair <T1, T2> a) {print(a.first, a.second);}
    template <typename T> void print(T a){
        for(int it : a){
            print(it);
        }
    }

    template <class T, class... Ts> void prine(T t, Ts... ts){
        print(t, ts...);
        exit(0);
    }
}

signed main()
{
    



    

    





    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    int test_check;

    for1 (run, 1, test)
    {
        int n, k; cin >> n >> k;
        int p[n+5];
        ii height[n+5];
        bool is_leaf[n+5];
        int child[n+5]; memset(child, 0, sizeof child);

        p[1] = 1; is_leaf[1] = 0;
        for1 (i, 2, n) {
            cin >> p[i];
            child[p[i]]++;
            is_leaf[i] = 1;
        }

        

        

        

        

        

        

        

        

        
        for1 (i, 1, n) {
            is_leaf[p[i]] = 0;
        }
        
        vi leaf;
        for1 (i, 1, n) {
            if (is_leaf[i]) leaf.pb(i);
        }

        int l = 1, r = n, res = n;

        while (l <= r) {
            int h = (l+r) / 2;
            int cnt[n+5]; memset(cnt, 0, sizeof cnt);
            for1 (i, 1, n) height[i] = {0, 0};
            for (int i : leaf) {
                while (1) {
                    if (p[i] == 1) {
                        height[1].se += height[i].se;
                        break;
                    }
                    int val = height[p[i]].fi;
                    height[p[i]].fi = max(height[p[i]].fi, height[i].fi+1);
                    height[p[i]].se += height[i].se;
                    if (height[p[i]].fi == h) {
                        height[p[i]].fi = val;
                        height[p[i]].se++;
                    }
                    cnt[p[i]]++;
                    if (cnt[p[i]] == child[p[i]]) i = p[i];
                    else break;
                }
            }
            if (height[1].se <= k) {
                res = min(res, h);
                r = h-1;
            }
            else l = h+1;
        }
        cout << res << endl;

gg:     continue;
    }

    exit(0);
}
