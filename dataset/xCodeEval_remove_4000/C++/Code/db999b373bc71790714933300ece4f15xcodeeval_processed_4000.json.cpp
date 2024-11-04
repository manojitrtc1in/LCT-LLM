


























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
const int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

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

bool cmp(ii u, ii v)
{
    return u.fi <= v.fi;
}

void solve()
{
    int test; cin >> test;
    while (test--)
    {
        int n, m, x; cin >> n >> m >> x;
        vector <ii> a(n);
        int pos = 1;
        vi res(n+10, 0);
        vi cou(n+10, 0);

        for1 (i, 1, m) cou[i] = 0;

        for1 (i, 0, n-1)
        {
            cin >> a[i].fi;
            a[i].se = i;
        }

        if(m == 1)
        {
            cout<<"YES"<<endl;
            for (int i=0; i<n; i++){
                cout<<"1 ";
            }
            cendl();
            continue;
        }

        sort(a.rbegin(), a.rend());

        for1 (i, 0, n-1)
        {
            cou[pos] += a[i].fi;

            res[a[i].se] = pos;
            pos++;
            if (pos == m+1)
            {
                pos = 1;
            }
        }

        int minval = INF, maxval = 0;
        for1 (i, 1, m)
        {
            minval = min(cou[i], minval);
            maxval = max(maxval, cou[i]);
        }

        if (maxval - minval > x) {cout << "NO\n"; continue;}
        cout << "YES\n";

        for1 (i, 0, n-1) cout << res[i] << " ";
        cendl();
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
