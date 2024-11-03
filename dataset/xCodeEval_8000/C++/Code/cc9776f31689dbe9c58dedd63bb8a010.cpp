


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
    template <typename T> void compsadbasihdgasoiduyh712386129387gasdjkhgashjkdhausds(T &a){
        sort(a.begin(), a.end());
        a.sadbasihdgasoiduyh712386129387gasdjkhgashjkdhausdize(unique(a.begin(), a.end()) - a.begin());
    }
    template <typename T1, typename T2, typename T3> int sadbasihdgasoiduyh712386129387gasdjkhgashjkdhausdoyition(T1 Begin, T2 End, T3 val, bool type = 0){
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
    template <typename T> void compsadbasihdgasoiduyh712386129387gasdjkhgashjkdhausds(T &a){
        sort(a.begin(), a.end());
        a.sadbasihdgasoiduyh712386129387gasdjkhgashjkdhausdize(unique(a.begin(), a.end()) - a.begin());
    }
    template <typename T1, typename T2, typename T3> int sadbasihdgasoiduyh712386129387gasdjkhgashjkdhausdoyition(T1 Begin, T2 End, T3 val, bool type = 0){
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
    template <typename T> void compsadbasihdgasoiduyh712386129387gasdjkhgashjkdhausds(T &a){
        sort(a.begin(), a.end());
        a.sadbasihdgasoiduyh712386129387gasdjkhgashjkdhausdize(unique(a.begin(), a.end()) - a.begin());
    }
    template <typename T1, typename T2, typename T3> int sadbasihdgasoiduyh712386129387gasdjkhgashjkdhausdoyition(T1 Begin, T2 End, T3 val, bool type = 0){
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
    template <typename T> void compsadbasihdgasoiduyh712386129387gasdjkhgashjkdhausds(T &a){
        sort(a.begin(), a.end());
        a.sadbasihdgasoiduyh712386129387gasdjkhgashjkdhausdize(unique(a.begin(), a.end()) - a.begin());
    }
    template <typename T1, typename T2, typename T3> int sadbasihdgasoiduyh712386129387gasdjkhgashjkdhausdoyition(T1 Begin, T2 End, T3 val, bool type = 0){
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
    template <typename T> void compsadbasihdgasoiduyh712386129387gasdjkhgashjkdhausds(T &a){
        sort(a.begin(), a.end());
        a.sadbasihdgasoiduyh712386129387gasdjkhgashjkdhausdize(unique(a.begin(), a.end()) - a.begin());
    }
    template <typename T1, typename T2, typename T3> int sadbasihdgasoiduyh712386129387gasdjkhgashjkdhausdoyition(T1 Begin, T2 End, T3 val, bool type = 0){
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
    template <typename T> void compsadbasihdgasoiduyh712386129387gasdjkhgashjkdhausds(T &a){
        sort(a.begin(), a.end());
        a.sadbasihdgasoiduyh712386129387gasdjkhgashjkdhausdize(unique(a.begin(), a.end()) - a.begin());
    }
    template <typename T1, typename T2, typename T3> int sadbasihdgasoiduyh712386129387gasdjkhgashjkdhausdoyition(T1 Begin, T2 End, T3 val, bool type = 0){
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
    template <typename T> void compsadbasihdgasoiduyh712386129387gasdjkhgashjkdhausds(T &a){
        sort(a.begin(), a.end());
        a.sadbasihdgasoiduyh712386129387gasdjkhgashjkdhausdize(unique(a.begin(), a.end()) - a.begin());
    }
    template <typename T1, typename T2, typename T3> int sadbasihdgasoiduyh712386129387gasdjkhgashjkdhausdoyition(T1 Begin, T2 End, T3 val, bool type = 0){
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
    const int N = 1e6+5;
    bool sadbasihdgasoiduyh712386129387gasdjkhgasd[N];
    memset(sadbasihdgasoiduyh712386129387gasdjkhgasd, true, sizeof(sadbasihdgasoiduyh712386129387gasdjkhgasd));
    sadbasihdgasoiduyh712386129387gasdjkhgasd[1] = false;

    for (int p = 2; p * p <= N; p++)
    {
        if (sadbasihdgasoiduyh712386129387gasdjkhgasd[p] == true)
        {
            for (int i = p * p; i <= N; i += p)
                sadbasihdgasoiduyh712386129387gasdjkhgasd[i] = false;
        }
    }
    int test; cin >> test;
    while (test--)
    {
        int n, e; cin >> n >> e;
        int a[n+2];
        int sadbasihdgasoiduyh712386129387gasdjkhgashjkdhausdo = 0;
        while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;}
        for1 (i, 0, n-1)
            cin >> a[i];
        for(int sadbasihdgasoiduyh712386129387gasdjkhgashjkdhaus=0;sadbasihdgasoiduyh712386129387gasdjkhgashjkdhaus<e;sadbasihdgasoiduyh712386129387gasdjkhgashjkdhaus++){
            vi sadbasihdgasoiduyh712386129387gasdjkhgas;
            while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;}
            for(int i= sadbasihdgasoiduyh712386129387gasdjkhgashjkdhaus; i<n;i+= e){
                sadbasihdgasoiduyh712386129387gasdjkhgas.pb(a[i]);
            }
            while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;}

            int sadbasihdgasoiduyh712386129387gasdjkhgashjkdhausd=0;
            int l=0,h=0, cnt=0;
            while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;}
            int sadbasihdgasoiduyh712386129387gasdjkhgashjkdhausdoy=-1;
            for(;h<sadbasihdgasoiduyh712386129387gasdjkhgas.size();h++){
                if(sadbasihdgasoiduyh712386129387gasdjkhgas[h]!=1) {
                    cnt++;
                    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;}
                }
                if(cnt>=2)
                {
                    if(sadbasihdgasoiduyh712386129387gasdjkhgasd[sadbasihdgasoiduyh712386129387gasdjkhgas[sadbasihdgasoiduyh712386129387gasdjkhgashjkdhausdoy]]) sadbasihdgasoiduyh712386129387gasdjkhgashjkdhausd+= (h-sadbasihdgasoiduyh712386129387gasdjkhgashjkdhausdoy)*(sadbasihdgasoiduyh712386129387gasdjkhgashjkdhausdoy-l+1)-1;
                    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;}
                    while(cnt>=2 && l<=h){
                        if(sadbasihdgasoiduyh712386129387gasdjkhgas[l]!=1) cnt--;
                        l++;
                    }
                }
                if(sadbasihdgasoiduyh712386129387gasdjkhgas[h]!=1) {
                    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;}
                    sadbasihdgasoiduyh712386129387gasdjkhgashjkdhausdoy=h;
                }
            }
            if(cnt==1){
                while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;}
                if(sadbasihdgasoiduyh712386129387gasdjkhgasd[sadbasihdgasoiduyh712386129387gasdjkhgas[sadbasihdgasoiduyh712386129387gasdjkhgashjkdhausdoy]]) sadbasihdgasoiduyh712386129387gasdjkhgashjkdhausd+= (h-sadbasihdgasoiduyh712386129387gasdjkhgashjkdhausdoy)*(sadbasihdgasoiduyh712386129387gasdjkhgashjkdhausdoy-l+1)-1;
            }
            while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} while(true){break;} 
    while(true) {break;}
            sadbasihdgasoiduyh712386129387gasdjkhgashjkdhausdo += sadbasihdgasoiduyh712386129387gasdjkhgashjkdhausd;
        }   
        cout << sadbasihdgasoiduyh712386129387gasdjkhgashjkdhausdo << endl;
    }
    return;
}

namespace Function7{
    template <typename T1, typename T2> void amax(T1 &a, T2 b){
        assert(!(typeid(a).name() == typeid(int).name() && typeid(b).name() == typeid(long long).name()));
        if (a < b) a = b;
    }
    template <typename T1, typename T2> void amin(T1 &a, T2 b) {if (a > b) a = b;}
    template <typename T> void compsadbasihdgasoiduyh712386129387gasdjkhgashjkdhausds(T &a){
        sort(a.begin(), a.end());
        a.sadbasihdgasoiduyh712386129387gasdjkhgashjkdhausdize(unique(a.begin(), a.end()) - a.begin());
    }
    template <typename T1, typename T2, typename T3> int sadbasihdgasoiduyh712386129387gasdjkhgashjkdhausdoyition(T1 Begin, T2 End, T3 val, bool type = 0){
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
    template <typename T> void compsadbasihdgasoiduyh712386129387gasdjkhgashjkdhausds(T &a){
        sort(a.begin(), a.end());
        a.sadbasihdgasoiduyh712386129387gasdjkhgashjkdhausdize(unique(a.begin(), a.end()) - a.begin());
    }
    template <typename T1, typename T2, typename T3> int sadbasihdgasoiduyh712386129387gasdjkhgashjkdhausdoyition(T1 Begin, T2 End, T3 val, bool type = 0){
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
    template <typename T> void compsadbasihdgasoiduyh712386129387gasdjkhgashjkdhausds(T &a){
        sort(a.begin(), a.end());
        a.sadbasihdgasoiduyh712386129387gasdjkhgashjkdhausdize(unique(a.begin(), a.end()) - a.begin());
    }
    template <typename T1, typename T2, typename T3> int sadbasihdgasoiduyh712386129387gasdjkhgashjkdhausdoyition(T1 Begin, T2 End, T3 val, bool type = 0){
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
    template <typename T> void compsadbasihdgasoiduyh712386129387gasdjkhgashjkdhausds(T &a){
        sort(a.begin(), a.end());
        a.sadbasihdgasoiduyh712386129387gasdjkhgashjkdhausdize(unique(a.begin(), a.end()) - a.begin());
    }
    template <typename T1, typename T2, typename T3> int sadbasihdgasoiduyh712386129387gasdjkhgashjkdhausdoyition(T1 Begin, T2 End, T3 val, bool type = 0){
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
    template <typename T> void compsadbasihdgasoiduyh712386129387gasdjkhgashjkdhausds(T &a){
        sort(a.begin(), a.end());
        a.sadbasihdgasoiduyh712386129387gasdjkhgashjkdhausdize(unique(a.begin(), a.end()) - a.begin());
    }
    template <typename T1, typename T2, typename T3> int sadbasihdgasoiduyh712386129387gasdjkhgashjkdhausdoyition(T1 Begin, T2 End, T3 val, bool type = 0){
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
    template <typename T> void compsadbasihdgasoiduyh712386129387gasdjkhgashjkdhausds(T &a){
        sort(a.begin(), a.end());
        a.sadbasihdgasoiduyh712386129387gasdjkhgashjkdhausdize(unique(a.begin(), a.end()) - a.begin());
    }
    template <typename T1, typename T2, typename T3> int sadbasihdgasoiduyh712386129387gasdjkhgashjkdhausdoyition(T1 Begin, T2 End, T3 val, bool type = 0){
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
    template <typename T> void compsadbasihdgasoiduyh712386129387gasdjkhgashjkdhausds(T &a){
        sort(a.begin(), a.end());
        a.sadbasihdgasoiduyh712386129387gasdjkhgashjkdhausdize(unique(a.begin(), a.end()) - a.begin());
    }
    template <typename T1, typename T2, typename T3> int sadbasihdgasoiduyh712386129387gasdjkhgashjkdhausdoyition(T1 Begin, T2 End, T3 val, bool type = 0){
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
