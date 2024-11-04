




























using namespace std;




typedef const int cint;
typedef unsigned int uint;
typedef long long ll;
typedef const long long cll;
typedef unsigned long long ull;
typedef long double ld;
typedef const long double cld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<string> vs;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<pld> vpld;
typedef set<int> si;
typedef set<ll> sll;
typedef set<ld> sld;
typedef set<string> ss;
typedef map<int, int> mi;
typedef map<ll, ll> mll;
typedef map<int, ll> mill;
typedef map<ll, int> mlli;
typedef map<int, string> mis;
typedef map<string, int> msi;










































































































































template<class T, class U> inline void id1(T &a, U b) { a = min(a, b); }
template<class T, class U> inline void id9(T &a, U b) { a = max(a, b); }

template<typename T> inline bool updmax(T &a, const T &b){ return a < b ? a = b, 1 : 0; }
template<typename T> inline bool updmin(T &a, const T &b){ return a > b ? a = b, 1 : 0; }



template<class T, class U> istream &operator>>(istream &in, pair<T, U> &a)
{
    in >> a.first >> a.second;
    return in;
}

template<class T, class U> ostream &operator<<(ostream &out, const pair<T, U> &a)
{
    out << a.first << ' ' << a.second;
    return out;
}

template<class T> istream &operator>>(istream &in, vector<T> &a)
{
    forn(i, sz(a))
        in >> a[i];
    return in;
}

template<class T> ostream &operator<<(ostream &out, const vector<T> &a)
{
    forn(i, sz(a))
        out << a[i] << ' ';
    return out;
}



int next_int()
{
    scid(tmp);
    return tmp;
}

ll next_ll()
{
    sclld(tmp);
    return tmp;
}



ll modPow(ll a, ll b, ll MOD){
    ll ret = 1;
    for (; b; b >>= 1)
    {
        if (b & 1)
            ret = modMul(ret, a, MOD);
        a = modMul(a, a, MOD);
    }
    return ret;
}






cll id8 = 100;
cll id6 = 1000;
cll id0 = 1000 * 1000;
cll id5 = id6 * id0;



cint id11 = (int)(id8 * id6) + EXTRA_MEMORY;
cint id12 = (int)(2 * id8 * id6) + EXTRA_MEMORY;
cint id10 = (int)(3 * id8 * id6) + EXTRA_MEMORY;
cint id4 = (int)(4 * id8 * id6) + EXTRA_MEMORY;
cint id3 = (int)(5 * id8 * id6) + EXTRA_MEMORY;
cint MAXN = id10;




cint INF = (int)id5 + 7;
cint INF2 = 1 << 30;
cll INFLL = 4LL * id5 * id5 + 7;
cll id7 = 1LL << 60;



cld Pi = acos(-1.0);
cld EPS = 1e-7;

cint MOD = (int)id5 + 7;









ll gcd (ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

bool id2 (ll a, ll b, ll c, ll & x0, ll & y0, ll & g) {
    g = gcd (abs(a), abs(b), x0, y0);
    if (c % g != 0)
        return false;
    x0 *= c / g;
    y0 *= c / g;
    if (a < 0)   x0 *= -1;
    if (b < 0)   y0 *= -1;  

    return true;
}

int main()
{

    ifstream in(PREF_TASK"in"SUFF_TASK);
    ofstream out(PREF_TASK"out"SUFF_TASK);


    auto cmpg = [](ll a, ll b, ll c, ll d) {
        return a * d - b * c;
    };

    scid(t);
    forn(ttt, t) {
        sc2lld(x, y);
        sc2lld(p, q);

        if (p == 0) {
            if (x == 0) {
                prinl(0);
            } else {
                prinl(-1);
            }
            continue;
        }

        if (p == q) {
            if (x == y) {
                prinl(0);
            } else {
                prinl(-1);
            }
            continue;
        }

        ll yy = ((y + q - 1) / q) * q;


        ll l = (x * q + p - 1) / p;
        l = max(l, y);
        ll r = q * (y - x) / (q - p);
        updmax(l, r);

        ll yyy = ((l + q - 1) / q) * q;

        prllnl(yyy - y);

        continue;
















        for (yy = yy; ; yy += q) {
            if (cmpg(x, yy, p, q) <= 0 && cmpg(x + (yy - y), yy, p, q) >= 0) {
                prllnl(yy - y);
                break;
            }
        }




        continue;
















































































        ll a = q, b = -p, c = y*p - x*q;
        ll x0 = 0, y0 = 0, g = 0;
        if (id2(a, b, c, x0, y0, g)) {




            ll h = y0, s = x0;



            

            a /= g, b /= g;
            b = -b;

            if (a == b) {
                if (s > h) {
                    prinl(-1);
                    continue;
                }

                if (b == 0) {
                    if (s >= 0 && h >= s)
                        prllnl(h);
                    else
                        prinl(-1);
                    continue;
                }

                ll k = s / b;

                s -= k * b;
                h -= k * a;

                if (h >= 0 && s >= 0 && h >= s)
                    prllnl(h);
                else
                    prinl(-1);

                continue;
            }

            if (a < 0) {
                a = -a;
                b = -b;
            }




            if (h < 0) {
                if (a == 0) {
                    prinl(-1);
                    continue;
                }

                ll coef = ((abs(h) + a - 1) / a);
                h += coef * a;
                s += coef * b;
            }

            if (s < 0) {
                if (b == 0) {
                    prinl(-1);
                    continue;
                }

                ll coef = ((abs(s) + abs(b) - 1) / abs(b));

                if (b < 0) {
                    coef = -coef;
                }

                s += coef * b;
                h += coef * a;
            }

            if (s < 0 || h < 0) {
                prinl(-1);
                continue;
            }

            if (s > h) {


                ll k = (h - s) / (a - b);

                if (b > a) {
                    k = -k;
                }

                s -= k * b;
                h -= k * a;
















            }




            ll k = 0;
            if (b != 0) {
                k = s / b;
                updmin(k, (h - s) / (a - b));
            }

            h -= k * a;
            s -= k * b;

            prllnl(h);
        } else {
            prinl(-1);
        }















    }


    in.close();
    out.close();

    return 0;
}
