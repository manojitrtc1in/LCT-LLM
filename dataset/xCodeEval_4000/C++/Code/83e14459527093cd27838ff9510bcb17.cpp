#pragma GCC target ("sse4.2")
#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define PB push_back
#define ln "\n"
#define forn(i,e) for(ll i=0; i<e; i++)
#define forsn(i,s,e) for(ll i=s; i<e; i++)
#define rforn(i,e) for(ll i=e; i>=0; i--)
#define rforsn(i,e,s) for(ll i=e; i>=s; i--)
#define vasort(v)         sort(v.begin(), v.end());
#define vdsort(v)         sort(v.begin(), v.end(),greater<ll>());
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define     mem(a,b)        memset(a,b,sizeof(a))
#define     sz(x)           ((int)size(x))
#define     EB              emplace_back
#define     flush           fflush(stdout)
#define out1(x1) cout << x1 << ln
#define out2(x1,x2) cout << x1 << " " << x2 << endl
#define out3(x1,x2,x3) cout << x1 << " " << x2 << " " << x3 << endl
#define out4(x1,x2,x3,x4) cout << x1 << " " << x2 << " " << x3 << " " << x4 << ln
#define all(d) d.begin(), d.end()
#define unordered_set(T) unordered_set<T, custom_hash>
#define unordered_map(T1, T2) unordered_map<T1, T2, custom_hash>

#define in1(x1) cin >> x1
#define in2(x1,x2) cin >> x1 >> x2
#define in3(x1,x2,x3) cin >> x1 >> x2 >> x3
#define in4(x1,x2,x3,x4) cin >> x1 >> x2 >> x3 >> x4

#define arrin(a, n) forn(i, n) cin >> a[i];
#define arrout(a,n) forn(i,n) {cout << a[i] << " ";} cout << ln;





namespace IO
{
    const int BUFFER_SIZE = 1 << 15;
    char input_buffer[BUFFER_SIZE];
    int input_pos = 0, input_len = 0;
    char output_buffer[BUFFER_SIZE];
    int output_pos = 0;
    char number_buffer[100];
    uint8_t lookup[100];
    void _update_input_buffer()
    {
        input_len = fread(input_buffer, sizeof(char), BUFFER_SIZE, stdin);
        input_pos = 0;
        if (input_len == 0)
            input_buffer[0] = EOF;
    }
    inline char next_char(bool advance = true)
    {
        if (input_pos >= input_len)
            _update_input_buffer();

        return input_buffer[advance ? input_pos++ : input_pos];
    }

    template <typename T>
    inline void read_int(T &number)
    {
        bool negative = false;
        number = 0;

        while (!isdigit(next_char(false)))
            if (next_char() == '-')
                negative = true;

        do
        {
            number = 10 * number + (next_char() - '0');
        } while (isdigit(next_char(false)));

        if (negative)
            number = -number;
    }

    template <typename T, typename... Args>
    inline void read_int(T &number, Args &... args)
    {
        read_int(number);
        read_int(args...);
    }

    void _flush_output()
    {
        fwrite(output_buffer, sizeof(char), output_pos, stdout);
        output_pos = 0;
    }

    inline void write_char(char c)
    {
        if (output_pos == BUFFER_SIZE)
            _flush_output();

        output_buffer[output_pos++] = c;
    }

    template <typename T>
    inline void write_int(T number, char after = '\0')
    {
        if (number < 0)
        {
            write_char('-');
            number = -number;
        }
        int length = 0;
        while (number >= 10)
        {
            uint8_t lookup_value = lookup[number % 100];
            number /= 100;
            number_buffer[length++] = (lookup_value & 15) + '0';
            number_buffer[length++] = (lookup_value >> 4) + '0';
        }
        if (number != 0 || length == 0)
            write_char(number + '0');
        for (int i = length - 1; i >= 0; i--)
            write_char(number_buffer[i]);
        if (after)
            write_char(after);
    }
    void IOinit()
    {
        

        bool exit_success = atexit(_flush_output) == 0;
        assert(exit_success);
        for (int i = 0; i < 100; i++)
            lookup[i] = (i / 10 << 4) + i % 10;
    }
} 


using namespace IO;




typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());




int dr[] = {0,1,-1,0,1,-1,1,-1};
int dc[] = {1,0,0,-1,1,-1,-1,1};
int drr[] = {-2,-1,0,1,2};
int dcc[] = {-2,-1,0,1,2};
bool chk(int a, int b, int n, int m) {
        return 0 <= a && a < n && 0 <= b && b < m;
}

ll exp(ll n, ll m, ll md){
        ll a = 1;
        while (m > 0){
                if (m&1) a = (a * n%md) % md;
                m /= 2;
                n = (n*n) % md;
        }
        return a % md;
}

ll expm(ll n, ll m){
    ll a = 1;
    while (m > 0){
        if(a < 0 or a >= (1e18 + n-1)/n) {
            return -1;
        }
        if (m&1) a = (a * n);
        m /= 2;
        n = (n*n);
    }
    return a;
}

void disp(vi v){
        for(auto u:v)
                cout<<u<<" ";
        cout<<"\n";
}
void disp(vll v){
    for(auto u:v)
        cout<<u<<" ";
    cout<<endl;
}

int getSqr(int x){
        if(x < 0)
                return -1;
        int l = sqrt(x);
        for (int i = -2; i <= 2; ++i)
                if (l + i >= 0 && (l + i) * (l + i) == x)
                        return l;
        return -1;
}

const int NPRR = 1e7;
vi lp;
vector<int> prr;
void prfac(int n = NPRR){
        assert(n <= NPRR);
        lp.assign(n+1, 0);
        int i;
        for (i = 2;i <= n;++i) {
                if (lp[i] == 0) {
                        lp[i] = i;
                        prr.push_back(i);
                }
                for (int u: prr) {
                        if(i * u > n || u > lp[i]) break;
                        lp[i * u] = u;
                }
        }
}


bool check_composite_for_prime_function(ll n, ll a, ll d, int s){
        ll x = exp(a, d, n);
        if (x == 1 || x == n-1) return false;
        for(int r = 1;r < s;++r){
                x = x * x%n;
                x %= n;
                if(x == n-1) return false;
        }
        return true;
}
bool prime(ll n){
        if(n < 4) return n == 2 || n == 3;
        if (!(n&1)) return false;
        int s = 0;
        ll d = n-1;
        while(!(d&1)){
                d >>= 1;
                s++;
        }
        for(int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){
                if(n == a) return true;
                if(check_composite_for_prime_function(n, a, d, s)) return false;
        }
        return true;
}

ll binomialCoeff(ll n, ll k)
{
    ll res = 1;

    

    if (k > n - k)
        k = n - k;

    

    

    for (ll i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
            

            x += 0x9e3779b97f4a7c15;
            x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
            x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
            return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
            static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
            return splitmix64(x + FIXED_RANDOM);
    }
};


inline void read(int &x)
{
    scanf("%d", &x);
}




const ll MAXn=1e5 + 33,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);



void shift(ll &x, ll& y, ll cnt, ll a, ll b) {
    x += cnt * b;
    y -= cnt * a;
}
ll gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
bool give_range(ll a, ll b, ll c, ll mina, ll maxa, ll minb, ll maxb, ll &lx, ll &rx) {
    ll x, y;
    ll g = gcd(a, b, x, y);
    if(c % g != 0) return false;


    x *= c/g;
    y *= c/g;


    a /= g;
    b /= g;
    if(a == 0 || b == 0) {
        if(x >= mina && x <= maxa && y >= minb && y <= maxb) {
            lx = x;
            rx = x;
            return true;
        }
        return false;
    }
    ll sign_a = (a > 0 ? 1 : -1);
    ll sign_b = (b > 0 ? 1 : -1);
    ll lx1, lx2, rx1, rx2;
    {
        ll cnt = (mina - x)/b;
        shift(x, y, cnt, a, b);
        if(x < 0) shift(x, y, sign_a, a, b);
        if(x > maxa) {
            return false;
        }



        lx1 = x;
    }
    {
        ll cnt = (maxa - x)/b;
        shift(x, y, cnt, a, b);


        rx1 = x;
    }
    {
        ll cnt = -(minb - y)/a;
        shift(x,y, cnt, a, b);
        if(y < 0) shift(x,y,-sign_b, a, b);
        if(y > maxb) {
            return false;
        }



        lx2 = x;
    }
    {
        ll cnt = -(maxb - y)/a;
        shift(x, y, cnt, a, b);



        rx2 = x;
    }
    if(lx2 > rx2) swap(lx2, rx2);



    ll lxx = max(lx1, lx2);
    ll rxx = min(rx1, rx2);
    if(lxx > rxx) {
        return false;
    }
    lx = lxx;
    rx = rxx;
    return true;
}





void go1() {
    ll n;cin >> n;
    ll a[n];
    ll b[n-1];
    forn(i, n) {
        cin >>a[i];
        if(i > 0) b[i-1] = a[i] - a[i-1];
    }
    ll ah = 0, bh = 0;
    forn(i, n-1) {
        if(a[i] < a[i+1]) ah += a[i+1] - a[i];
        else bh += a[i] - a[i+1];
    }
    if(n == 1) {
        if(a[0] < 0) cout << a[0] / 2 << ln;
        else cout << (a[0] + 1) / 2 << ln;
        ll q;cin >>  q;
        forn(i, q) {
            ll l ,r ,x;
            in3(l, r, x);
            l--;r--;
            a[0] += x;
            if(0 == ceil((ld)(a[0]) / 2.0)) cout << 0 << ln;
            else cout << ceil((ld)(a[0]) / 2.0) << ln;
        }
        return;
    }

    ll ans =  ceil((ld)(a[0] + ah) / 2.0);
    if(ans == 0) cout << 0 << ln;
    else cout << ans << ln;
    ll q;cin >>  q;
    forn(i, q) {
        ll l ,r ,x;
        in3(l, r, x);
        l--;r--;
        if(l == 0) a[0] += x;
        if(l > 0) {
            if(b[l-1] > 0) ah -= b[l-1];
            else bh -= -b[l-1];
            b[l-1] += x;
            if(b[l-1] > 0) ah += b[l-1];
            else bh += -b[l-1];

        }
        if(r < n-1) {
            if(b[r] > 0) ah -= b[r];
            else bh -= -b[r];
            b[r] -= x;
            if(b[r] > 0) ah += b[r];
            else bh += -b[r];
        }
        if(ceil((ld)(a[0] + ah) / 2.0) == 0) cout << 0 << ln;
        else cout << ceil((ld)(a[0] + ah) / 2.0) << ln;

    }
}


ll md = 1e9 + 7;
void go2() {
    int n;
    cin >> n;
    int a[n], ca[n+1], b[n], cb[n+1];
    forn(i, n+1) {
        ca[i] = 0;
        cb[i] = 0;
    }
    forn(i, n) {
        cin >> a[i];
        ca[a[i]]++;
    }
    forn(i, n) {
        cin >> b[i];
        cb[b[i]]++;
    }
    forn(i, n+1) {
        if(ca[i] + cb[i] > n) {
            cout << "No" << ln;
            return;
        }
    }
    cout << "Yes" << ln;
    int ans[n];forn(i, n) ans[i] = -1;
    int i = 0, j = 0;
    set<int> un;
    forsn(p,1, n+1) {
        while(a[i%n] == p) i++;
        while(j < i) {
            un.insert(j%n);j++;
        }
        while(cb[p] > 0) {
            cb[p]--;
            if(ans[j%n] < 0) {
                ans[j%n] = p;
            } else {
                ans[*un.begin()] = p;
                un.erase(un.begin());
            }
            j++;
        }
    }
    forn(i, n)cout << ans[i] << " ";

}


int main(){
    fio;
    fflush(stdout);
    cout<<fixed<<setprecision(0);
    cerr<<fixed<<setprecision(10);

    


    ll tt = 1;


    


    auto start  = std::chrono::high_resolution_clock::now();

    while(tt--){
        

        go1();
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    

    return 0;
}


