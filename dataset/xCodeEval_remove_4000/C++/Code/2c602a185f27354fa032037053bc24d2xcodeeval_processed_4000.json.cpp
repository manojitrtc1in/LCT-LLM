


using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

































































    for (lld i = 0; i < v.size(); i++) \
    {                                  \
        cin >> v[i];                   \
    }


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
node *id2()
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
lld id3(lld n)
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

string id1(lld n)
{
    string s = bitset<64>(n).to_string();
    const auto loc1 = s.find('1');

    if (loc1 != string::npos)
        return s.substr(loc1);

    return "0";
}
string id0(lld n)
{
    string s = bitset<32>(n).to_string();
    return s;
}
string id4(lld n)
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

lld id5(lld n, lld k)
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
    lld id6 = sqrt(n);
    return id6 * id6 == n;
}
lld issq(double n)
{
    lld id6 = sqrt(n);
    return id6 * id6 == n;
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
const lld a3 = 3*1e5 + 100;
bitset<a3> dp;
void init()
{
    dp[1] = 0;
    for (lld i = 2; i < a3; i++)
    {
        lld id6 = sqrt(i) + 1;
        for (lld j = 2; j < id6; j++)
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
    if (n<a3)
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

    cerr << "Time: " << duration.count() / 1000.0 << endl;
    cout << duration.count() / 1000.0 << endl;

}