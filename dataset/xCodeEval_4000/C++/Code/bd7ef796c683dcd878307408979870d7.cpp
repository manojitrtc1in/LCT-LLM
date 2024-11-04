





#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#define for1(i,a,b) for (int i = a; i <= b; i++)
#define for2(i,a,b) for (int i = a; i >= b; i--)
#define loga(a,b) log(b) / log(a)

#define int long long
#define ll long long
#define dl double long
#define cendl() cout << endl
#define ull unsigned long long

#define ALL(x) (x).begin(), (x).end()
#define pb push_back
#define ins insert
#define _sz(a) (int)a.size()

#define fi first
#define se second
#define mp make_pair
#define lb lower_bound 

#define ub upper_bound 


#define _max *max_element
#define _min *min_element

#define _input() int test; cin >> test; while (test--)

using namespace __gnu_pbds;
using namespace std;

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

template<class T> struct Seg 
{
  int n; vector<T> seg;
  const T ID{}; T comb(T a, T b) { return a+b; } 
  void init(int _n) { 

    n = _n;
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;}
    seg.assign(2*n,ID); }
  void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); 
  while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;}}
  void upd(int p, T val) {
    seg[p += n] = val; 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;}for (p /= 2; p; p /= 2) pull(p); }
  T query(int l, int r) {
    T ra = ID, rb = ID;
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;}
    for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
      if (l&1) ra = comb(ra,seg[l++]);
      if (r&1) rb = comb(seg[--r],rb);
    }
    return comb(ra,rb);
  }
};

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



Seg<int> djasdhgqiweyt12837613, tree2;
int n, q;

signed main()
{
    



    

    





    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    _input()
    {
        cin>>n>>q;
      string str;
      cin>>str;
      djasdhgqiweyt12837613.init(4*n);
      for1 (i, 0, n-1)
      {
            if (i & 1)
            {
                djasdhgqiweyt12837613.upd(i+1, str[i] == '+' ? -1 : 1);
            }
            else djasdhgqiweyt12837613.upd(i+1, str[i] == '+' ? 1 : -1);
      }
      for1 (i, 1, q)
      {
        int l, r; cin>>l>>r;
        int eruiweyhirwueyrwer7263094 = abs(djasdhgqiweyt12837613.query(l, r));
        if (eruiweyhirwueyrwer7263094 & 1) eruiweyhirwueyrwer7263094 = 1;
        else if (eruiweyhirwueyrwer7263094 != 0) eruiweyhirwueyrwer7263094 = 2;
        cout << eruiweyhirwueyrwer7263094 << endl;
      }

gg:     continue;
    }

    exit(0);
}
