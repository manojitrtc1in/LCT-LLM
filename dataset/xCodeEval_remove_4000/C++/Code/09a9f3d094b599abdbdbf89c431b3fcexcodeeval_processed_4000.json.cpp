






















 





using namespace std;

















































































































































































































































































































































































































































































































































































































































































































































































































































































































































































int const NMAX = 1e5 + 1;




vector<ll> t;
ll n;

void init(ll nn)
{
    n = nn;
    t.assign(n, 0);
}

ll sum(ll r)
{
    ll result = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        result += t[r];
    return result;
}

void inc(ll i, ll delta)
{
    for (; i < n; i = (i | (i + 1)))
        t[i] += delta;
}

ll asum(ll l, ll r)
{
    if (r < l) return 0;
    return sum(r) - sum(l - 1);
}

void init(vector<ll> a)
{
    init((ll)a.size());
    for (unsigned i = 0; i < a.size(); i++)
        inc(i, a[i]);
}

class Solution {
public:
    void solve(std::istream& in, std::ostream& out) {
        ll t, n, i, k, q, a[NMAX], l, r;
        vector<ll> b;

        in >> n >> q >> k;
        b.reserve(n);
        rep(i, n) {
            in >> a[i];
            if (i) 
                b.PB(a[i] - a[i - 1] - 1);
        }
        b.push_back(0);
        init(b);
        rep(i, q)
        {
            in >> l >> r;
            l--, r--;
            ll ans = 0;
            if (a[r] > k) ans = 0;
            else {
                ans = 2*asum(l, r-1);
                ans += a[l] - 1 + k - a[r];
            }
            out << ans << endl;
        }

        
    }
};

void solve(std::istream& in, std::ostream& out)
{
    ios_base::sync_with_stdio(false);
    out << std::setprecision(12);
    Solution solution;
    solution.solve(in, out);
}


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    istream& in = cin;


    ostream& out = cout;

    solve(in, out);
    return 0;
}

