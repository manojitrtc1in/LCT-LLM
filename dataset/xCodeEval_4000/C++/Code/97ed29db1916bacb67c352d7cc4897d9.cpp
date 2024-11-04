





#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
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

#define int long long
#define ll long long
#define dl double long
#define cendl() cout << endl
#define ull unsigned long long

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

using namespace __gnu_pbds;

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

    _input()
    {
        int n; while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} cin >> n; while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;}
        int A[n+2]; while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;}
        priority_queue<int> haskljdhaslkdahsjdlkjashdlaksjdha9781263198236192378, haskljdhaslkdahsjdlkjashdlaksjdha97812631982361923781; while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;}
        map<int, int> haskljdhaslkdahsjdlkjashdlaksjdha978126319823619237; while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;}
        int sum = 0; while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;}
          for1 (i, 0, n-1) {
            cin>>A[i]; while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;}
            haskljdhaslkdahsjdlkjashdlaksjdha97812631982361923781.push(A[i]); while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;}
            sum += A[i]; while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;}
          }
  haskljdhaslkdahsjdlkjashdlaksjdha9781263198236192378.push(sum); while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;}
  while(!haskljdhaslkdahsjdlkjashdlaksjdha9781263198236192378.empty()){
    int cur = haskljdhaslkdahsjdlkjashdlaksjdha9781263198236192378.top(); while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} haskljdhaslkdahsjdlkjashdlaksjdha9781263198236192378.pop(); while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;}
    int num = haskljdhaslkdahsjdlkjashdlaksjdha97812631982361923781.top(); while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;}
    if (cur == num){
      haskljdhaslkdahsjdlkjashdlaksjdha97812631982361923781.pop(); while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;}
      continue; while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;}
    }
    if (cur < num){
      break; while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;}
    }
      if (cur % 2){
        haskljdhaslkdahsjdlkjashdlaksjdha9781263198236192378.push(cur/2 + 1); while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} haskljdhaslkdahsjdlkjashdlaksjdha9781263198236192378.push(cur/2); while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;}
      }
      else{
        haskljdhaslkdahsjdlkjashdlaksjdha9781263198236192378.push(cur/2); while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} haskljdhaslkdahsjdlkjashdlaksjdha9781263198236192378.push(cur/2); while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;}
      }
  }
  if (haskljdhaslkdahsjdlkjashdlaksjdha97812631982361923781.size()){
    cout<<"NO"; while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;}
  }
  else cout<<"YES"; while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;}
  cout << endl; while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;}

gg:     continue;
    }

    exit(0);
}
