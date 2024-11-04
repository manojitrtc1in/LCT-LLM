


























using namespace std;

typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <int> vi;

const int INF = 8000000000000000000;
const int mod =  998244353;
const int MOD =  998244353;

namespace IO
{
    void setIn(string s) {freopen(s.c_str(), "r", stdin);}
    void setOut(string s) {freopen(s.c_str(), "w", stdout);}
    void setIO(string s = ""){
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);
        
            cin.exceptions(cin.failbit);
        

        if (s.size()){
            setIn(s+".inp");
            setOut(s+".out");
        } else{
            
                freopen("input.txt", "r", stdin);
            

        }
    }
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
    while (test--)
    {
        int n; cin >> n;
        int cnt1 = 1;
        while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;}
        if (n & 1) {cout << "0\n"; continue;}
        for1 (i, 1, n/2) {
            cnt1 *= i;
            while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;}
            cnt1 %=  998244353;
        }
        while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;}
        cout << (cnt1 * cnt1) % mod << endl;
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
