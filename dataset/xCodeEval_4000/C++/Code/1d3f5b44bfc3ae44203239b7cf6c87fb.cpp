#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl "\n"
#define int long long
#define lld long long
#define p(x) cout << x << endl;
#define p2(x, y) cout << x << " " << y << endl;
#define p3(x, y, z) cout << x << " " << y << " " << z << endl;
#define p4(x, y, z, a) cout << x << " " << y << " " << z << " " << a << endl;
#define p5(x, y, z, a, b) cout << x << " " << y << " " << z << " " << a << " " << b << endl;
#define p6(x, y, z, a, b, c) cout << x << " " << y << " " << z << " " << a << " " << b << " " << c << endl;
#define p7(x, y, z, a, b, c, d) cout << x << " " << y << " " << z << " " << a << " " << b << " " << c << " " << d << endl;
#define p8(x, y, z, a, b, c, d, e) cout << x << " " << y << " " << z << " " << a << " " << b << " " << c << " " << d << " " << e << endl;
#define ps(x) cout << x << " ";
#define ps2(x, y) cout << x << " " << y << " ";
#define ps3(x, y, z) cout << x << " " << y << " " << z << " ";
#define ps4(x, y, z, a) cout << x << " " << y << " " << z << " " << a << " ";
#define ps5(x, y, z, a, b) cout << x << " " << y << " " << z << " " << a << " " << b << " ";
#define ps6(x, y, z, a, b, c) cout << x << " " << y << " " << z << " " << a << " " << b << " " << c << " ";
#define ps7(x, y, z, a, b, c, d) cout << x << " " << y << " " << z << " " << a << " " << b << " " << c << " " << d << " ";
#define ps8(x, y, z, a, b, c, d, e) cout << x << " " << y << " " << z << " " << a << " " << b << " " << c << " " << d << " " << e << " ";
#define pns(x) cout << x;
#define pns2(x, y) cout << x << y;
#define pns3(x, y, z) cout << x << y << z;
#define pns4(x, y, z, a) cout << x << y << z << a;
#define pns5(x, y, z, a, b) cout << x << y << z << a << b;
#define pns6(x, y, z, a, b, c) cout << x << y << z << a << b << c;
#define pns7(x, y, z, a, b, c, d) cout << x << y << z << a << b << c << d;
#define pns8(x, y, z, a, b, c, d, e) cout << x << y << z << a << b << c << d << e;
#define setbits(x) __builtin_popcountll(x)
#define msb(x) (64 - __builtin_clzll(x))
#define rb(n) (n & (-n))
#define rbm(n) (n & (n - 1))
#define all(x) x.begin(), x.end()
#define dll(x) x.begin(), x.end(), greater<lld>()
#define vect(x, n) vector<lld> x(n, 0);
#define vl vector<lld>
#define umll unordered_map<lld, lld>
#define usl unordered_set<lld>
#define mll map<lld, lld>
#define sorta(x) sort(all(x));
#define sortd(x) sort(all(x), greater<lld>());
#define matrix(x, n, m) vector<vector<lld>> x(n, vector<lld>(m, 0));
#define matrixval(x, n, m, val) vector<vector<lld>> x(n, vector<lld>(m, val));
#define matrixs(x, n, m, o) vector<vector<vector<lld>>> x(n, vector<vector<lld>>(m, vector<lld>(o, 0)));
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define max3(a, b, c) max(max((a), (b)), (c))
#define max4(a, b, c, d) max(max((a), (b)), max((c), (d)))
#define min3(a, b, c) min(min((a), (b)), (c))
#define min4(a, b, c, d) min(min((a), (b)), min((c), (d)))
#define lb lower_bound
#define ub upper_bound
#define pb(x) push_back(x);
#define pf(x) push_front(x);
#define mkp(x, y) make_pair(x, y)
#define f(i, a, b) for (lld i = (a); i < (b); i++)
#define fn(i, n) for (lld i = (0); i < (n); i++)
#define fr(i, a, b) for (lld i = (b); i > a; i--)
#define inf 1e18
#define pinf LLONG_MAX
#define ninf LLONG_MIN
#define pll pair<lld, lld>
#define ppll pair<pll, lld>
#define ff first
#define ss second
#define inp(v)                         \
    for (lld i = 0; i < v.size(); i++) \
    {                                  \
        cin >> v[i];                   \
    }
#define MOD 1000000007
#define mod 1000000007
template <typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename T2>
using omap = tree<T, T2, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using omulti_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;







template <typename T>
struct reversion_wrapper
{
    T &iterable;
};

template <typename T>
auto begin(reversion_wrapper<T> w) { return std::rbegin(w.iterable); }

template <typename T>
auto end(reversion_wrapper<T> w) { return std::rend(w.iterable); }

template <typename T>
reversion_wrapper<T> reverse(T &&iterable) { return {iterable}; }

void addedge(unordered_map<lld, set<lld>> &adj, lld u, lld v)
{
    adj[u].insert(v);
    adj[v].insert(u);
}

struct cmpfunc
{
    bool operator()(const long &a, const long &b) const
    {
        return a > b;
    }
};
typedef struct node
{
    lld val;
    struct node *left;
    struct node *right;
}(node);
void print(node *newnode)
{
    if (newnode)
    {
        p(newnode->val);
        print(newnode->left);
        print(newnode->right);
    }
}
node *get_newnode()
{
    node *newnode = new node;
    newnode->val = 0;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
lld pow(lld x, lld y, lld p)
{
    lld res = 1; 

    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;

        y = y >> 1; 

        x = (x * x) % p;
    }
    return res;
}
lld pow(lld x, lld y)
{
    lld res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = ((res) * (x));
        y = y >> 1;
        x = ((x) * (x));
    }
    return res;
}
string bin(lld n)
{
    

    string answer = "";
    while (n)
    {
        if (n % 2 == 1)
        {
            answer += '1';
        }
        else
        {
            answer += '0';
        }
        n /= 2;
    }
    reverse(all(answer));
    return answer;
}
lld bintodec(lld n)
{
    lld num = n;
    lld dec_value = 0;
    lld base = 1;

    lld temp = num;
    while (temp)
    {
        lld last_digit = temp % 10;
        temp = temp / 10;

        dec_value += last_digit * base;

        base = base * 2;
    }

    return dec_value;
}

string dectobin(lld n)
{
    string s = bitset<64>(n).to_string();
    const auto loc1 = s.find('1');

    if (loc1 != string::npos)
        return s.substr(loc1);

    return "0";
}
string binary32bit(lld n)
{
    string s = bitset<32>(n).to_string();
    return s;
}
string binary64bit(lld n)
{
    string s = bitset<64>(n).to_string();
    return s;
}
void print(lld arr[], lld size)
{
    for (lld i = 0; i < size; i++)
    {
        ps(arr[i]);
    }
    p("");
}

void print(vl &v)
{
    for (lld i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
void print(vector<vl> &v)
{
    for (lld i = 0; i < v.size(); i++)
    {
        for (lld j = 0; j < v[i].size(); j++)
        {
            ps(v[i][j]);
        }
        p("");
    }
}
void print(vector<string> &v)
{
    for (lld i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
void print(vector<pll> &v)
{
    for (lld i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " " << v[i].second << " ";
    }
    cout << endl;
}
void prints(vl &v)
{

    for (lld i = 1; i != v.size(); i++)
    {
        ps(v[i]);
    }
}
void print(set<pll> &seta)
{

    for (auto i : seta)
    {
        ps2(i.first, i.second);
    }
    p("");
}
void print(map<lld, lld> &mapa)
{
    for (auto i : mapa)
    {
        ps4("{", i.first, i.second, "}");
    }
    p("");
}
void print(multimap<lld, lld> &multi)
{
    for (auto i : multi)
    {
        ps4('{', i.first, i.second, '}');
    }
    p("");
}
void print(map<lld, lld, greater<lld>> &mapa)
{

    for (auto i : mapa)
    {
        ps4("{", i.first, i.second, "}");
    }
    p("");
}
void print(set<lld> &seta)
{
    for (auto i : seta)
    {
        ps(i);
    }
    p("");
}
void print(map<pll, pll> &mapa)
{
    for (auto i = mapa.begin(); i != mapa.end(); i++)
    {
        ps4(i->first.first, i->first.second, i->second.first, i->second.second);
    }
}
void print(map<pll, lld> &mapa)
{

    for (auto i = mapa.begin(); i != mapa.end(); i++)
    {
        ps5("{", i->first.first, i->first.second, i->second, "}");
    }
    p("");
}
void print(pll &tuple)
{

    p2(tuple.first, tuple.second);
}
void print(set<lld, greater<lld>> &s)
{
    for (auto i : s)
    {
        p(i);
    }
}
void print(unordered_set<lld> &seta)
{
    for (auto i : seta)
    {
        ps(i);
    }
    p("");
}
void print(map<lld, set<lld, greater<lld>>, greater<lld>> &m)
{
    for (auto i : m)
    {
        for (auto j : i.second)
        {
            ps(j);
        }
    }
    p("");
}
void print(multiset<lld> &s)
{
    for (auto j : s)
    {
        ps(j);
    }
    p("");
}
void print(map<lld, set<lld>> &m)
{
    for (auto i : m)
    {
        ps2(i.first, " => ");
        for (auto j : i.second)
        {
            ps(j);
        }
        p("");
    }
}
void print(unordered_map<lld, lld> &um)
{
    for (auto i : um)
    {
        p4("{", i.first, "->", i.second);
    }
    p("");
}
lld sum(multimap<lld, lld> &m)
{
    lld suma = 0;
    for (auto i : m)
    {
        suma += i.first;
    }
    return suma;
}

lld kth_no_not_divisible_by_n(lld n, lld k)
{
    return k + (k - 1) / (n - 1);
}
lld ceil(lld a, lld n)
{

    return (a + n - 1) / n;
}
lld get_mod(lld a, lld b)
{
    lld answer = a % b;
    if (answer < 0)
    {
        return answer + b;
    }
    return answer;
}

string nc = "NO";
string ns = "No";
string yc = "YES";
string ys = "Yes";

void yesno(lld a)
{
    if (a)
    {
        p(yc);
    }
    else
    {
        p(nc);
    }
}
void alice(lld a)
{
    p((a ? "Alice" : "Bob"));
}
void reduce(map<lld, lld> &m, lld value)
{
    if (m[value] <= 1)
    {
        m.erase(value);
    }
    else
    {
        m[value]--;
    }
}

lld issq(lld n)
{
    lld sqrta = sqrt(n);
    return sqrta * sqrta == n;
}
lld issq(double n)
{
    lld sqrta = sqrt(n);
    return sqrta * sqrta == n;
}

lld primeFactors(int n)
{
    lld count = 0;
    while (n % 2 == 0)
    {
        

        count += 1;
        n = n / 2;
    }

    

    

    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        

        while (n % i == 0)
        {
            

            count += 1;
            n = n / i;
        }
    }
    if (n > 2)
    {

        

        count += 1;
    }
    return count;
}
const lld a3 = 1e5 + 100;
bitset<a3> dp;
void init()
{
    dp[1] = 0;
    for (lld i = 2; i < a3; i++)
    {
        lld sqrta = sqrt(i) + 1;
        for (lld j = 2; j < sqrta; j++)
        {
            if (i % j == 0)
            {
                if (!dp[i - j])
                {
                    dp[i] = 1;
                    break;
                }
                lld fac2=i/j;
                if (!dp[i - fac2])
                {
                    dp[i] = 1;
                    break;
                }
            }
        }
    }
}
void fun()
{
    lld n;
    cin >> n;
    if (n<1e5)
    {
        alice(dp[n]);
    }
    else
    {
        lld theta = n & (n - 1);
        if (n % 2 == 1)
        {
            alice(0);
        }
        else if ((n & (n - 1)) == 0)
        {
            lld counter = 0;
            while (n % 2 == 0)
            {
                n = n / 2;
                counter++;
            }
            alice(counter % 2 == 0);
        }
        else
        {
            alice(1);
        }
    }
}
signed main()
{
    fastio;
    auto start1 = high_resolution_clock::now();

    lld t;
    t = 1;
    cin >> t;
    init();
    while (t--)
    {
        fun();
    }

    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
    cerr << "Time: " << duration.count() / 1000.0 << endl;
    cout << duration.count() / 1000.0 << endl;
#endif
}