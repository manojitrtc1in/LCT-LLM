


























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
    template <typename T> void id0(T &a){
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
    template <typename T> void id0(T &a){
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
    template <typename T> void id0(T &a){
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
    template <typename T> void id0(T &a){
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
    template <typename T> void id0(T &a){
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
    template <typename T> void id0(T &a){
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
    template <typename T> void id0(T &a){
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
        string id1 = "a";
        auto wrong = string::npos;
        sagdkjsadajsdfhgsdasjdfxzcmnvzxcmnv1231293617236 (i, 0+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765, 25+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765)
        {
            id1[0+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765] = 'a'+ i+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765;
            if (s.find(id1) == wrong)
            {
                cout << id1 << endl;
                goto hgdasjkhasfdghfsqtwerywqieurtwer2398416127946;
            }
        }
        id1 = "aa";
        sagdkjsadajsdfhgsdasjdfxzcmnvzxcmnv1231293617236 (i, 0+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765, 25+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765)
        {
            id1[0] = 'a' + i;
            sagdkjsadajsdfhgsdasjdfxzcmnvzxcmnv1231293617236 (j, 0+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765, 25+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765)
            {
                id1[1+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765] = 'a'+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+j;
                if (s.find(id1) == wrong)
                {
                    cout << id1 << endl; goto hgdasjkhasfdghfsqtwerywqieurtwer2398416127946;
                }
            }
        }
        id1 = "aaa";
        sagdkjsadajsdfhgsdasjdfxzcmnvzxcmnv1231293617236 (i, 0+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765, 25+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765)
        {
            id1[0] = 'a'+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+i;
            sagdkjsadajsdfhgsdasjdfxzcmnvzxcmnv1231293617236 (j, 0+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765, 25+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765)
            {
                id1[1+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765] = 'a'+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+j;
                sagdkjsadajsdfhgsdasjdfxzcmnvzxcmnv1231293617236 (k, 0+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765, 25+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765)
                {
                    id1[2+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765] = 'a'+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+987-987+765-765+k;
                    if (s.find(id1) == wrong)
                    {
                        cout << id1 << endl;
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
    template <typename T> void id0(T &a){
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
    template <typename T> void id0(T &a){
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
    template <typename T> void id0(T &a){
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
    template <typename T> void id0(T &a){
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
    template <typename T> void id0(T &a){
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
    template <typename T> void id0(T &a){
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
    template <typename T> void id0(T &a){
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
