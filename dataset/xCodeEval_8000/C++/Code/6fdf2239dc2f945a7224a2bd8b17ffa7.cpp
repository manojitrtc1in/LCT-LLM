


#include <bits/stdc++.h>

#define sagdkjsadajsdfhgsdasjdfxzcmnvzxcmnv1231293617236(i,a,b) for (int i = a; i <= b; i++)
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
#define _sz(a) (int)a.size()
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define fi first
#define se second



using namespace std;

typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <int> vi;

const int INF = 8000000000000000000;
const int mod = 1000000007;
const int MOD = 1000000007;

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

namespace Function{
    template <typename T1, typename T2> void amax(T1 &a, T2 b){
        assert(!(typeid(a).name() == typeid(int).name() && typeid(b).name() == typeid(long long).name()));
        if (a < b) a = b;
    }
    template <typename T1, typename T2> void amin(T1 &a, T2 b) {if (a > b) a = b;}
    template <typename T> void compuyoereuyworywerioyhsdfkljsdhf2467928364927834s(T &a){
        sort(a.begin(), a.end());
        a.uyoereuyworywerioyhsdfkljsdhf2467928364927834ize(unique(a.begin(), a.end()) - a.begin());
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
    template <typename T> void compuyoereuyworywerioyhsdfkljsdhf2467928364927834s(T &a){
        sort(a.begin(), a.end());
        a.uyoereuyworywerioyhsdfkljsdhf2467928364927834ize(unique(a.begin(), a.end()) - a.begin());
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
    template <typename T> void compuyoereuyworywerioyhsdfkljsdhf2467928364927834s(T &a){
        sort(a.begin(), a.end());
        a.uyoereuyworywerioyhsdfkljsdhf2467928364927834ize(unique(a.begin(), a.end()) - a.begin());
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
    template <typename T> void compuyoereuyworywerioyhsdfkljsdhf2467928364927834s(T &a){
        sort(a.begin(), a.end());
        a.uyoereuyworywerioyhsdfkljsdhf2467928364927834ize(unique(a.begin(), a.end()) - a.begin());
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
    template <typename T> void compuyoereuyworywerioyhsdfkljsdhf2467928364927834s(T &a){
        sort(a.begin(), a.end());
        a.uyoereuyworywerioyhsdfkljsdhf2467928364927834ize(unique(a.begin(), a.end()) - a.begin());
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
    template <typename T> void compuyoereuyworywerioyhsdfkljsdhf2467928364927834s(T &a){
        sort(a.begin(), a.end());
        a.uyoereuyworywerioyhsdfkljsdhf2467928364927834ize(unique(a.begin(), a.end()) - a.begin());
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
    template <typename T> void compuyoereuyworywerioyhsdfkljsdhf2467928364927834s(T &a){
        sort(a.begin(), a.end());
        a.uyoereuyworywerioyhsdfkljsdhf2467928364927834ize(unique(a.begin(), a.end()) - a.begin());
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
        string s; cin >> s;
        string ahskdjasgfhjksagdfusdyaikftgwyiuetrqweuirt239462374986 = "a";
        auto wrong = string::npos;
        sagdkjsadajsdfhgsdasjdfxzcmnvzxcmnv1231293617236 (i, 0+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765, 25+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765)
        {
            ahskdjasgfhjksagdfusdyaikftgwyiuetrqweuirt239462374986[0+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765] = 'a'+ i+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765;
            if (s.find(ahskdjasgfhjksagdfusdyaikftgwyiuetrqweuirt239462374986) == wrong)
            {
                cout << ahskdjasgfhjksagdfusdyaikftgwyiuetrqweuirt239462374986 << endl;
                goto hgdasjkhasfdghfsqtwerywqieurtwer2398416127946;
            }
        }
        ahskdjasgfhjksagdfusdyaikftgwyiuetrqweuirt239462374986 = "aa";
        sagdkjsadajsdfhgsdasjdfxzcmnvzxcmnv1231293617236 (i, 0+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765, 25+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765)
        {
            ahskdjasgfhjksagdfusdyaikftgwyiuetrqweuirt239462374986[0] = 'a' + i;
            sagdkjsadajsdfhgsdasjdfxzcmnvzxcmnv1231293617236 (j, 0+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765, 25+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765)
            {
                ahskdjasgfhjksagdfusdyaikftgwyiuetrqweuirt239462374986[1+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765] = 'a'+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+j;
                if (s.find(ahskdjasgfhjksagdfusdyaikftgwyiuetrqweuirt239462374986) == wrong)
                {
                    cout << ahskdjasgfhjksagdfusdyaikftgwyiuetrqweuirt239462374986 << endl; goto hgdasjkhasfdghfsqtwerywqieurtwer2398416127946;
                }
            }
        }
        ahskdjasgfhjksagdfusdyaikftgwyiuetrqweuirt239462374986 = "aaa";
        sagdkjsadajsdfhgsdasjdfxzcmnvzxcmnv1231293617236 (i, 0+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765, 25+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765)
        {
            ahskdjasgfhjksagdfusdyaikftgwyiuetrqweuirt239462374986[0] = 'a'+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+i;
            sagdkjsadajsdfhgsdasjdfxzcmnvzxcmnv1231293617236 (j, 0+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765, 25+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765)
            {
                ahskdjasgfhjksagdfusdyaikftgwyiuetrqweuirt239462374986[1+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765] = 'a'+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+j;
                sagdkjsadajsdfhgsdasjdfxzcmnvzxcmnv1231293617236 (k, 0+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765, 25+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765)
                {
                    ahskdjasgfhjksagdfusdyaikftgwyiuetrqweuirt239462374986[2+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765] = 'a'+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+k;
                    if (s.find(ahskdjasgfhjksagdfusdyaikftgwyiuetrqweuirt239462374986) == wrong)
                    {
                        cout << ahskdjasgfhjksagdfusdyaikftgwyiuetrqweuirt239462374986 << endl;
                        goto hgdasjkhasfdghfsqtwerywqieurtwer2398416127946;
                    }
                }
            }
        }

hgdasjkhasfdghfsqtwerywqieurtwer2398416127946:     continue;
}

    return;
}

namespace Function7{
    template <typename T1, typename T2> void amax(T1 &a, T2 b){
        assert(!(typeid(a).name() == typeid(int).name() && typeid(b).name() == typeid(long long).name()));
        if (a < b) a = b;
    }
    template <typename T1, typename T2> void amin(T1 &a, T2 b) {if (a > b) a = b;}
    template <typename T> void compuyoereuyworywerioyhsdfkljsdhf2467928364927834s(T &a){
        sort(a.begin(), a.end());
        a.uyoereuyworywerioyhsdfkljsdhf2467928364927834ize(unique(a.begin(), a.end()) - a.begin());
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
    template <typename T> void compuyoereuyworywerioyhsdfkljsdhf2467928364927834s(T &a){
        sort(a.begin(), a.end());
        a.uyoereuyworywerioyhsdfkljsdhf2467928364927834ize(unique(a.begin(), a.end()) - a.begin());
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
    template <typename T> void compuyoereuyworywerioyhsdfkljsdhf2467928364927834s(T &a){
        sort(a.begin(), a.end());
        a.uyoereuyworywerioyhsdfkljsdhf2467928364927834ize(unique(a.begin(), a.end()) - a.begin());
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
    template <typename T> void compuyoereuyworywerioyhsdfkljsdhf2467928364927834s(T &a){
        sort(a.begin(), a.end());
        a.uyoereuyworywerioyhsdfkljsdhf2467928364927834ize(unique(a.begin(), a.end()) - a.begin());
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
    template <typename T> void compuyoereuyworywerioyhsdfkljsdhf2467928364927834s(T &a){
        sort(a.begin(), a.end());
        a.uyoereuyworywerioyhsdfkljsdhf2467928364927834ize(unique(a.begin(), a.end()) - a.begin());
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
    template <typename T> void compuyoereuyworywerioyhsdfkljsdhf2467928364927834s(T &a){
        sort(a.begin(), a.end());
        a.uyoereuyworywerioyhsdfkljsdhf2467928364927834ize(unique(a.begin(), a.end()) - a.begin());
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
    template <typename T> void compuyoereuyworywerioyhsdfkljsdhf2467928364927834s(T &a){
        sort(a.begin(), a.end());
        a.uyoereuyworywerioyhsdfkljsdhf2467928364927834ize(unique(a.begin(), a.end()) - a.begin());
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