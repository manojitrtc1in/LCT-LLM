




























































































































































































































































































































































































































































































































































































































































































































































































































































    for (auto i : A)      \
        cout << i << " "; \
    cout << '\n';


clock_t startTime = clock();









using namespace std;

typedef vector<vector<long long>> vvint;

void fast()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    

    

    

    

    

}
double PI = 4 * atan(1);
int mod = 1e9 + 7, mxn = 3e5 + 5;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
void deb(vector<int> v)
{
    for (auto t : v)
        cerr << t << " ";
    cerr << "\n";
}
int mul(int a, int b, int mod)
{
    a %= mod;
    b %= mod;
    a *= b;
    a += mod;
    return a % mod;
}

bool id0(const pair<int, int> &a,
                   const pair<int, int> &b)
{
    return a.second > b.second;
}
string id3(int n)
{
    string s = "";
    int i = 0;
    while (n > 0)
    {
        s = to_string(n % 2) + s;
        n = n / 2;
        i++;
    }
    return s;
}
vint fact(2e5 + 5, 1);
int binPow(int a, int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    int ret = binPow(a, b / 2);
    if (b % 2 == 0)
        return (ret * ret) % mod;
    return ((ret * ret) % mod * a) % mod;
}
int inv(int a)
{
    return (binPow(a, mod - 2) % mod + mod) % mod;
}
int binom(int a, int b)
{
    

    

    if (b < 0 or a < 0)
        return 0;
    return (((fact[a] * inv(fact[b])) % mod * inv(fact[a - b])) % mod + mod) % mod;
}




vector<int> id2(int N)
{
    bool primes[N + 1];
    memset(primes, true, sizeof(primes));
    vector<int> arr;

    for (int i = 2; i * i <= N; i++)
        if (primes[i] == true)
        {
            for (int j = i * i; j <= N; j += i)
                primes[j] = false;
        }

    for (int i = 2; i <= N; i++)
        if (primes[i])
            arr.emplace_back(i);

    return arr;
}
vector<int> primeFactors(int n)
{
    vector<int> f;
    for (int x = 2; x * x <= n; x++)
    {
        while (n % x == 0)
        {
            f.push_back(x);
            n /= x;
        }
    }
    if (n > 1)
        f.push_back(n);
    return f;
}

bool isPrime(int n)
{
    if (n < 2)
        return false;
    for (int x = 2; x * x <= n; x++)
    {
        if (n % x == 0)
            return false;
    }
    return true;
}

bool id1(int n)
{
    return n && (!(n & (n - 1)));
}






























vll v;
const int N = 4e5 + 4;
class segTree
{
public:
    vll a, seg;
    segTree()
    {
        

        

        

        seg.resize(4 * N + 14, 0);
        

    }

    void build(ll si, ll ss, ll se)
    {
        if (ss == se)
        {
            seg[si] = 0;
            return;
        }
        ll mid = (ss + se) / 2;

        build(2 * si, ss, mid);
        build(2 * si + 1, mid + 1, se);

        seg[si] = (seg[2 * si] + seg[2 * si + 1]);
    }

    

    

    

    

    

    

    

    

    


    

    

    

    


    

    

    

    void update(int ind, int l, int r, int pos, int val)
    {
        

        if (pos < l || pos > r)
        {
            return;
        }
        if (l == r)
        {
            

            seg[ind] = val;
            return;
        }
        int mid = l + (r - l) / 2;
        update(2 * ind, l, mid, pos, val);
        update(2 * ind + 1, mid + 1, r, pos, val);
        seg[ind] = seg[2 * ind] + seg[2 * ind + 1];
    }
    int query(int ind, int l, int r, int lq, int rq)
    {
        

        if (lq > r || rq < l)
        {
            return 0;
        }
        

        

        

        

        if (lq <= l && r <= rq)
        {

            return seg[ind];
        }
        int mid = l + (r - l) / 2;
        return query(2 * ind, l, mid, lq, rq) + query(2 * ind + 1, mid + 1, r, lq, rq);
    }
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    


    

    

    

};































































































































void solve()
{
    

    

    

    

    

    

    

    

    


    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    int n, q;
    cin >> n >> q;
    vll rows, cols;
    rows.assign(n + 1, 0);
    cols.assign(n + 1, 0);
    segTree rt, ct; 

    

    

    

    

    

    

    for (ll i = 0; i < q; i++)
    {
        int ch;
        cin >> ch;
        

        

        if (ch == 1)
        {
            int x, y;
            cin >> x >> y;
            

            rows[x]++;
            cols[y]++;
            


            if (rows[x] == 1)
            {
                rt.update(1, 1, N, x, 1);
            }
            if (cols[y] == 1)
            {
                ct.update(1, 1, N, y, 1);
            }
        }
        else if (ch == 2)
        {
            int x, y;
            cin >> x >> y;
            rows[x]--;
            cols[y]--;
            if (rows[x] == 0)
            {
                rt.update(1, 1, N, x, 0);
            }
            if (cols[y] == 0)
            {
                ct.update(1, 1, N, y, 0);
            }
        }
        else
        {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            

            

            

            if (rt.query(1, 1, N, x1, x2) == (x2 - x1 + 1))
            {
                cout << "YES" << endl;
                continue;
            }
            

            if (ct.query(1, 1, N, y1, y2) == (y2 - y1 + 1))
            {
                

                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
}
signed main()
{
    fast();
    

    int t = 1;
    

    while (t--)
    {
        v.clear();
        solve();
    }
    


    


    

    return 0;
}