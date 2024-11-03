


#include <bits/stdc++.h>

#define for1(i,a,b) for (int i = a; i <= b; i++)
#define for2(i,a,b) for (int i = a; i >= b; i--)
#define loga(a,b) log(b) / log(a)

#define int long long
#define ll long long
#define dl double long
#define cendl() cout << endl
#define ull unsigned long long
#define cendl() cout << endl

#define ins insert
#define ALL(x) (x).begin(), (x).end()
#define pb push_back
#define sz(a) (int)a.size()
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define fi first
#define se second



using namespace std;

typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <int> vi;

const int INF = 8000000000000000000;
const int mod = 998244353 ;
const int MOD = 998244353 ;

namespace IO
{
    void setIn(string s) {freopen(s.c_str(), "r", stdin);}
    void setOut(string s) {freopen(s.c_str(), "w", stdout);}
    void setIO(string s = ""){
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);
        #ifndef ONLINE_JUDGE
            cin.exceptions(cin.failbit);
        #endif 

        if (s.size()){
            setIn(s+".inp");
            setOut(s+".out");
        } else{
            #ifndef ONLINE_JUDGE
                freopen("input.txt", "r", stdin);
            #endif 

        }
    }
}

const int N = 70;
int inv[N+5], f[N+5], g[N+5];
void init() {
    int i; while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;}
    inv[1] = 1; while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;}
    for (i = 2; i <= N; i++) inv[i] = inv[mod % i] * (mod - mod / i) % mod; while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;}
    f[0] = g[0] = 1; while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;}
    for (i = 1;  i <= N;  i++) {
        f[i] = f[i - 1] * i % mod; while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;}
        g[i] = g[i - 1] * inv[i] % mod; while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;}
    }
}

int C(int k, int n) {
    if (k < 0 || k > n) return 0; while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;}
    return f[n] * g[k] % mod * g[n - k] % mod; while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;}
}

namespace Function{
    template <typename T1, typename T2> void amax(T1 &a, T2 b){
        assert(!(typeid(a).name() == typeid(int).name() && typeid(b).name() == typeid(long long).name()));
        if (a < b) a = b;
    }
    template <typename T1, typename T2> void amin(T1 &a, T2 b) {if (a > b) a = b;}
    template <typename T> void compress(T &a){
        sort(a.begin(), a.end());
        a.resize(unique(a.begin(), a.end()) - a.begin());
    }
    template <typename T1, typename T2, typename T3> int position(T1 Begin, T2 End, T3 val, bool type = 0){
        if (type == 0){
            return lower_bound(Begin, End, val) - Begin;
        }
        return upper_bound(Begin, End, val) - Begin;
    }
    template <typename T> long long sqr(T x) {return 1LL*x*x;}
    template <typename T1, typename T2> long long GCD(T1 a, T2 b) {return b == 0 ? a : GCD(b, a%b);}
    template <typename T1, typename T2> long long LCM(T1 a, T2 b) {return 1LL*a/GCD(a, b)*b;}
}

namespace Function1{
    template <typename T1, typename T2> void amax(T1 &a, T2 b){
        assert(!(typeid(a).name() == typeid(int).name() && typeid(b).name() == typeid(long long).name()));
        if (a < b) a = b;
    }
    template <typename T1, typename T2> void amin(T1 &a, T2 b) {if (a > b) a = b;}
    template <typename T> void compress(T &a){
        sort(a.begin(), a.end());
        a.resize(unique(a.begin(), a.end()) - a.begin());
    }
    template <typename T1, typename T2, typename T3> int position(T1 Begin, T2 End, T3 val, bool type = 0){
        if (type == 0){
            return lower_bound(Begin, End, val) - Begin;
        }
        return upper_bound(Begin, End, val) - Begin;
    }
    template <typename T> long long sqr(T x) {return 1LL*x*x;}
    template <typename T1, typename T2> long long GCD(T1 a, T2 b) {return b == 0 ? a : GCD(b, a%b);}
    template <typename T1, typename T2> long long LCM(T1 a, T2 b) {return 1LL*a/GCD(a, b)*b;}
}

namespace Function2{
    template <typename T1, typename T2> void amax(T1 &a, T2 b){
        assert(!(typeid(a).name() == typeid(int).name() && typeid(b).name() == typeid(long long).name()));
        if (a < b) a = b;
    }
    template <typename T1, typename T2> void amin(T1 &a, T2 b) {if (a > b) a = b;}
    template <typename T> void compress(T &a){
        sort(a.begin(), a.end());
        a.resize(unique(a.begin(), a.end()) - a.begin());
    }
    template <typename T1, typename T2, typename T3> int position(T1 Begin, T2 End, T3 val, bool type = 0){
        if (type == 0){
            return lower_bound(Begin, End, val) - Begin;
        }
        return upper_bound(Begin, End, val) - Begin;
    }
    template <typename T> long long sqr(T x) {return 1LL*x*x;}
    template <typename T1, typename T2> long long GCD(T1 a, T2 b) {return b == 0 ? a : GCD(b, a%b);}
    template <typename T1, typename T2> long long LCM(T1 a, T2 b) {return 1LL*a/GCD(a, b)*b;}
}

namespace Function3{
    template <typename T1, typename T2> void amax(T1 &a, T2 b){
        assert(!(typeid(a).name() == typeid(int).name() && typeid(b).name() == typeid(long long).name()));
        if (a < b) a = b;
    }
    template <typename T1, typename T2> void amin(T1 &a, T2 b) {if (a > b) a = b;}
    template <typename T> void compress(T &a){
        sort(a.begin(), a.end());
        a.resize(unique(a.begin(), a.end()) - a.begin());
    }
    template <typename T1, typename T2, typename T3> int position(T1 Begin, T2 End, T3 val, bool type = 0){
        if (type == 0){
            return lower_bound(Begin, End, val) - Begin;
        }
        return upper_bound(Begin, End, val) - Begin;
    }
    template <typename T> long long sqr(T x) {return 1LL*x*x;}
    template <typename T1, typename T2> long long GCD(T1 a, T2 b) {return b == 0 ? a : GCD(b, a%b);}
    template <typename T1, typename T2> long long LCM(T1 a, T2 b) {return 1LL*a/GCD(a, b)*b;}
}

namespace Function4{
    template <typename T1, typename T2> void amax(T1 &a, T2 b){
        assert(!(typeid(a).name() == typeid(int).name() && typeid(b).name() == typeid(long long).name()));
        if (a < b) a = b;
    }
    template <typename T1, typename T2> void amin(T1 &a, T2 b) {if (a > b) a = b;}
    template <typename T> void compress(T &a){
        sort(a.begin(), a.end());
        a.resize(unique(a.begin(), a.end()) - a.begin());
    }
    template <typename T1, typename T2, typename T3> int position(T1 Begin, T2 End, T3 val, bool type = 0){
        if (type == 0){
            return lower_bound(Begin, End, val) - Begin;
        }
        return upper_bound(Begin, End, val) - Begin;
    }
    template <typename T> long long sqr(T x) {return 1LL*x*x;}
    template <typename T1, typename T2> long long GCD(T1 a, T2 b) {return b == 0 ? a : GCD(b, a%b);}
    template <typename T1, typename T2> long long LCM(T1 a, T2 b) {return 1LL*a/GCD(a, b)*b;}
}

namespace Function5{
    template <typename T1, typename T2> void amax(T1 &a, T2 b){
        assert(!(typeid(a).name() == typeid(int).name() && typeid(b).name() == typeid(long long).name()));
        if (a < b) a = b;
    }
    template <typename T1, typename T2> void amin(T1 &a, T2 b) {if (a > b) a = b;}
    template <typename T> void compress(T &a){
        sort(a.begin(), a.end());
        a.resize(unique(a.begin(), a.end()) - a.begin());
    }
    template <typename T1, typename T2, typename T3> int position(T1 Begin, T2 End, T3 val, bool type = 0){
        if (type == 0){
            return lower_bound(Begin, End, val) - Begin;
        }
        return upper_bound(Begin, End, val) - Begin;
    }
    template <typename T> long long sqr(T x) {return 1LL*x*x;}
    template <typename T1, typename T2> long long GCD(T1 a, T2 b) {return b == 0 ? a : GCD(b, a%b);}
    template <typename T1, typename T2> long long LCM(T1 a, T2 b) {return 1LL*a/GCD(a, b)*b;}
}

namespace Function6{
    template <typename T1, typename T2> void amax(T1 &a, T2 b){
        assert(!(typeid(a).name() == typeid(int).name() && typeid(b).name() == typeid(long long).name()));
        if (a < b) a = b;
    }
    template <typename T1, typename T2> void amin(T1 &a, T2 b) {if (a > b) a = b;}
    template <typename T> void compress(T &a){
        sort(a.begin(), a.end());
        a.resize(unique(a.begin(), a.end()) - a.begin());
    }
    template <typename T1, typename T2, typename T3> int position(T1 Begin, T2 End, T3 val, bool type = 0){
        if (type == 0){
            return lower_bound(Begin, End, val) - Begin;
        }
        return upper_bound(Begin, End, val) - Begin;
    }
    template <typename T> long long sqr(T x) {return 1LL*x*x;}
    template <typename T1, typename T2> long long GCD(T1 a, T2 b) {return b == 0 ? a : GCD(b, a%b);}
    template <typename T1, typename T2> long long LCM(T1 a, T2 b) {return 1LL*a/GCD(a, b)*b;}
}

void solve()
{
    int test; cin >> test;
    init();
    while (test--)
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
        int ashdgashkjdgasdkjhagsdjkasdgajkshdgasjkdhagsdhkjasgd12753612873512387123518273513ahsdjasgdhasdgkjasdgaasdhgahsdkjasgdashdgasdasdjgajsgdasdasdadasdjhasdkhasdasdasdasdasdasdhasgdajksdgasjkdagsjdkgasddsdsdsdsdsdxsasdsaddfdfsadasdasdbvnvbnvbnasdsfsdfasdcvaasdasdasdasdxxcxvassdfsdfsdfcxvxcvxcvsdfwerjkljkljklsdfdsfsdfsdfsdrtyrtyrty = C(n/2-1, n-1); while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;}
        for (int i = 3; i <= n/2; i += 2) {
            ashdgashkjdgasdkjhagsdjkasdgajkshdgasjkdhagsdhkjasgd12753612873512387123518273513ahsdjasgdhasdgkjasdgaasdhgahsdkjasgdashdgasdasdjgajsgdasdasdadasdjhasdkhasdasdasdasdasdasdhasgdajksdgasjkdagsjdkgasddsdsdsdsdsdxsasdsaddfdfsadasdasdbvnvbnvbnasdsfsdfasdcvaasdasdasdasdxxcxvassdfsdfsdfcxvxcvxcvsdfwerjkljkljklsdfdsfsdfsdfsdrtyrtyrty += C(n/2-i, n-i*2+1); while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;}
            ashdgashkjdgasdkjhagsdjkasdgajkshdgasjkdhagsdhkjasgd12753612873512387123518273513ahsdjasgdhasdgkjasdgaasdhgahsdkjasgdashdgasdasdjgajsgdasdasdadasdjhasdkhasdasdasdasdasdasdhasgdajksdgasjkdagsjdkgasddsdsdsdsdsdxsasdsaddfdfsadasdasdbvnvbnvbnasdsfsdfasdcvaasdasdasdasdxxcxvassdfsdfsdfcxvxcvxcvsdfwerjkljkljklsdfdsfsdfsdfsdrtyrtyrty += C(n/2-i, n-i*2+2); while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;}
        }
        int ashdgashkjdgasdkjhagsdjkasdgajkshdgasjkdhagsdhkjasgd12753612873512387123518273513ahsdjasgdhasdgkjasdgaasdhgahsdkjasgdashdgasdasdjgajsgdasdasdadasdjhasdkhasdasdasdasdasdasdhasgdajksdgasjkdagsjdkgasddsdsdsdsdsdxsasdsaddfdfsadasdasdbvnvbnvbnasdsfsdfasdcvaasdasdasdasdxxcxvassdfsdfsdfcxvxcvxcvsdfwerjkljkljklsdfdsfsdfsdfsdrtyrtyrtysdfsdf = C(n/2, n); while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;}
        while (ashdgashkjdgasdkjhagsdjkasdgajkshdgasjkdhagsdhkjasgd12753612873512387123518273513ahsdjasgdhasdgkjasdgaasdhgahsdkjasgdashdgasdasdjgajsgdasdasdadasdjhasdkhasdasdasdasdasdasdhasgdajksdgasjkdagsjdkgasddsdsdsdsdsdxsasdsaddfdfsadasdasdbvnvbnvbnasdsfsdfasdcvaasdasdasdasdxxcxvassdfsdfsdfcxvxcvxcvsdfwerjkljkljklsdfdsfsdfsdfsdrtyrtyrtysdfsdf < ashdgashkjdgasdkjhagsdjkasdgajkshdgasjkdhagsdhkjasgd12753612873512387123518273513ahsdjasgdhasdgkjasdgaasdhgahsdkjasgdashdgasdasdjgajsgdasdasdadasdjhasdkhasdasdasdasdasdasdhasgdajksdgasjkdagsjdkgasddsdsdsdsdsdxsasdsaddfdfsadasdasdbvnvbnvbnasdsfsdfasdcvaasdasdasdasdxxcxvassdfsdfsdfcxvxcvxcvsdfwerjkljkljklsdfdsfsdfsdfsdrtyrtyrty+1) ashdgashkjdgasdkjhagsdjkasdgajkshdgasjkdhagsdhkjasgd12753612873512387123518273513ahsdjasgdhasdgkjasdgaasdhgahsdkjasgdashdgasdasdjgajsgdasdasdadasdjhasdkhasdasdasdasdasdasdhasgdajksdgasjkdagsjdkgasddsdsdsdsdsdxsasdsaddfdfsadasdasdbvnvbnvbnasdsfsdfasdcvaasdasdasdasdxxcxvassdfsdfsdfcxvxcvxcvsdfwerjkljkljklsdfdsfsdfsdfsdrtyrtyrtysdfsdf += mod; while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;}
        cout << ashdgashkjdgasdkjhagsdjkasdgajkshdgasjkdhagsdhkjasgd12753612873512387123518273513ahsdjasgdhasdgkjasdgaasdhgahsdkjasgdashdgasdasdjgajsgdasdasdadasdjhasdkhasdasdasdasdasdasdhasgdajksdgasjkdagsjdkgasddsdsdsdsdsdxsasdsaddfdfsadasdasdbvnvbnvbnasdsfsdfasdcvaasdasdasdasdxxcxvassdfsdfsdfcxvxcvxcvsdfwerjkljkljklsdfdsfsdfsdfsdrtyrtyrty % mod << " " << (ashdgashkjdgasdkjhagsdjkasdgajkshdgasjkdhagsdhkjasgd12753612873512387123518273513ahsdjasgdhasdgkjasdgaasdhgahsdkjasgdashdgasdasdjgajsgdasdasdadasdjhasdkhasdasdasdasdasdasdhasgdajksdgasjkdagsjdkgasddsdsdsdsdsdxsasdsaddfdfsadasdasdbvnvbnvbnasdsfsdfasdcvaasdasdasdasdxxcxvassdfsdfsdfcxvxcvxcvsdfwerjkljkljklsdfdsfsdfsdfsdrtyrtyrtysdfsdf-ashdgashkjdgasdkjhagsdjkasdgajkshdgasjkdhagsdhkjasgd12753612873512387123518273513ahsdjasgdhasdgkjasdgaasdhgahsdkjasgdashdgasdasdjgajsgdasdasdadasdjhasdkhasdasdasdasdasdasdhasgdajksdgasjkdagsjdkgasddsdsdsdsdsdxsasdsaddfdfsadasdasdbvnvbnvbnasdsfsdfasdcvaasdasdasdasdxxcxvassdfsdfsdfcxvxcvxcvsdfwerjkljkljklsdfdsfsdfsdfsdrtyrtyrty-1) % mod << " 1\n"; while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;}
    }
    return;
}

namespace Function7{
    template <typename T1, typename T2> void amax(T1 &a, T2 b){
        assert(!(typeid(a).name() == typeid(int).name() && typeid(b).name() == typeid(long long).name()));
        if (a < b) a = b;
    }
    template <typename T1, typename T2> void amin(T1 &a, T2 b) {if (a > b) a = b;}
    template <typename T> void compress(T &a){
        sort(a.begin(), a.end());
        a.resize(unique(a.begin(), a.end()) - a.begin());
    }
    template <typename T1, typename T2, typename T3> int position(T1 Begin, T2 End, T3 val, bool type = 0){
        if (type == 0){
            return lower_bound(Begin, End, val) - Begin;
        }
        return upper_bound(Begin, End, val) - Begin;
    }
    template <typename T> long long sqr(T x) {return 1LL*x*x;}
    template <typename T1, typename T2> long long GCD(T1 a, T2 b) {return b == 0 ? a : GCD(b, a%b);}
    template <typename T1, typename T2> long long LCM(T1 a, T2 b) {return 1LL*a/GCD(a, b)*b;}
}

namespace Function8{
    template <typename T1, typename T2> void amax(T1 &a, T2 b){
        assert(!(typeid(a).name() == typeid(int).name() && typeid(b).name() == typeid(long long).name()));
        if (a < b) a = b;
    }
    template <typename T1, typename T2> void amin(T1 &a, T2 b) {if (a > b) a = b;}
    template <typename T> void compress(T &a){
        sort(a.begin(), a.end());
        a.resize(unique(a.begin(), a.end()) - a.begin());
    }
    template <typename T1, typename T2, typename T3> int position(T1 Begin, T2 End, T3 val, bool type = 0){
        if (type == 0){
            return lower_bound(Begin, End, val) - Begin;
        }
        return upper_bound(Begin, End, val) - Begin;
    }
    template <typename T> long long sqr(T x) {return 1LL*x*x;}
    template <typename T1, typename T2> long long GCD(T1 a, T2 b) {return b == 0 ? a : GCD(b, a%b);}
    template <typename T1, typename T2> long long LCM(T1 a, T2 b) {return 1LL*a/GCD(a, b)*b;}
}

namespace Funct12213123ion8{
    template <typename T1, typename T2> void amax(T1 &a, T2 b){
        assert(!(typeid(a).name() == typeid(int).name() && typeid(b).name() == typeid(long long).name()));
        if (a < b) a = b;
    }
    template <typename T1, typename T2> void amin(T1 &a, T2 b) {if (a > b) a = b;}
    template <typename T> void compress(T &a){
        sort(a.begin(), a.end());
        a.resize(unique(a.begin(), a.end()) - a.begin());
    }
    template <typename T1, typename T2, typename T3> int position(T1 Begin, T2 End, T3 val, bool type = 0){
        if (type == 0){
            return lower_bound(Begin, End, val) - Begin;
        }
        return upper_bound(Begin, End, val) - Begin;
    }
    template <typename T> long long sqr(T x) {return 1LL*x*x;}
    template <typename T1, typename T2> long long GCD(T1 a, T2 b) {return b == 0 ? a : GCD(b, a%b);}
    template <typename T1, typename T2> long long LCM(T1 a, T2 b) {return 1LL*a/GCD(a, b)*b;}
}

namespace Functsdasdasdion8{
    template <typename T1, typename T2> void amax(T1 &a, T2 b){
        assert(!(typeid(a).name() == typeid(int).name() && typeid(b).name() == typeid(long long).name()));
        if (a < b) a = b;
    }
    template <typename T1, typename T2> void amin(T1 &a, T2 b) {if (a > b) a = b;}
    template <typename T> void compress(T &a){
        sort(a.begin(), a.end());
        a.resize(unique(a.begin(), a.end()) - a.begin());
    }
    template <typename T1, typename T2, typename T3> int position(T1 Begin, T2 End, T3 val, bool type = 0){
        if (type == 0){
            return lower_bound(Begin, End, val) - Begin;
        }
        return upper_bound(Begin, End, val) - Begin;
    }
    template <typename T> long long sqr(T x) {return 1LL*x*x;}
    template <typename T1, typename T2> long long GCD(T1 a, T2 b) {return b == 0 ? a : GCD(b, a%b);}
    template <typename T1, typename T2> long long LCM(T1 a, T2 b) {return 1LL*a/GCD(a, b)*b;}
}

namespace Functdasdasdasdion8{
    template <typename T1, typename T2> void amax(T1 &a, T2 b){
        assert(!(typeid(a).name() == typeid(int).name() && typeid(b).name() == typeid(long long).name()));
        if (a < b) a = b;
    }
    template <typename T1, typename T2> void amin(T1 &a, T2 b) {if (a > b) a = b;}
    template <typename T> void compress(T &a){
        sort(a.begin(), a.end());
        a.resize(unique(a.begin(), a.end()) - a.begin());
    }
    template <typename T1, typename T2, typename T3> int position(T1 Begin, T2 End, T3 val, bool type = 0){
        if (type == 0){
            return lower_bound(Begin, End, val) - Begin;
        }
        return upper_bound(Begin, End, val) - Begin;
    }
    template <typename T> long long sqr(T x) {return 1LL*x*x;}
    template <typename T1, typename T2> long long GCD(T1 a, T2 b) {return b == 0 ? a : GCD(b, a%b);}
    template <typename T1, typename T2> long long LCM(T1 a, T2 b) {return 1LL*a/GCD(a, b)*b;}
}

namespace Funqweqweqwesdaction8{
    template <typename T1, typename T2> void amax(T1 &a, T2 b){
        assert(!(typeid(a).name() == typeid(int).name() && typeid(b).name() == typeid(long long).name()));
        if (a < b) a = b;
    }
    template <typename T1, typename T2> void amin(T1 &a, T2 b) {if (a > b) a = b;}
    template <typename T> void compress(T &a){
        sort(a.begin(), a.end());
        a.resize(unique(a.begin(), a.end()) - a.begin());
    }
    template <typename T1, typename T2, typename T3> int position(T1 Begin, T2 End, T3 val, bool type = 0){
        if (type == 0){
            return lower_bound(Begin, End, val) - Begin;
        }
        return upper_bound(Begin, End, val) - Begin;
    }
    template <typename T> long long sqr(T x) {return 1LL*x*x;}
    template <typename T1, typename T2> long long GCD(T1 a, T2 b) {return b == 0 ? a : GCD(b, a%b);}
    template <typename T1, typename T2> long long LCM(T1 a, T2 b) {return 1LL*a/GCD(a, b)*b;}
}

namespace Funcsdasdasdaweation8{
    template <typename T1, typename T2> void amax(T1 &a, T2 b){
        assert(!(typeid(a).name() == typeid(int).name() && typeid(b).name() == typeid(long long).name()));
        if (a < b) a = b;
    }
    template <typename T1, typename T2> void amin(T1 &a, T2 b) {if (a > b) a = b;}
    template <typename T> void compress(T &a){
        sort(a.begin(), a.end());
        a.resize(unique(a.begin(), a.end()) - a.begin());
    }
    template <typename T1, typename T2, typename T3> int position(T1 Begin, T2 End, T3 val, bool type = 0){
        if (type == 0){
            return lower_bound(Begin, End, val) - Begin;
        }
        return upper_bound(Begin, End, val) - Begin;
    }
    template <typename T> long long sqr(T x) {return 1LL*x*x;}
    template <typename T1, typename T2> long long GCD(T1 a, T2 b) {return b == 0 ? a : GCD(b, a%b);}
    template <typename T1, typename T2> long long LCM(T1 a, T2 b) {return 1LL*a/GCD(a, b)*b;}
}

signed main()
{
    fastio;
    solve();

    exit(0);
}
