

using namespace std;











typedef long long ll;
typedef unsigned long long ull;
ll mod = (ll) 1e9 + 7;






void _print(int a) {cerr << a;}
void _print(bool a) {cerr << a;}
void _print(ull a) {cerr << a;}
void _print(ll a) {cerr << a;}
void _print(double a) {cerr << a;}
void _print(string s) {cerr << s;}



template <class T> void _print(std::vector<T> v) {cerr << "[ "; for (T i  : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(std::set<T>s) {cerr << "[ "; for (T i  : s) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(std::multiset<T>s) {cerr << "[ "; for (T i  : s) {_print(i); cerr << " ";} cerr << "]";}


ll mod_add(ll a, ll b, ll M) {a = a % M; b = b % M; return (((a + b) % M) + M) % M;}
ll mod_mul(ll a, ll b, ll mod) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}
ll mod_sub(ll a, ll b, ll M) {a = a % M; b = b % M; return (((a - b) % M) + M) % M;}

























ll ceil2(ll a, ll b) {
    ll c = a / b;
    if (c * b < a) c++;
    return c;
}

ll id9(ll n)
{

    

    

    

    ll k = (ll)(log2(n));

    

    

    

    return  k;
}
bool pow2(ll n)
{
    if (n == 0)
        return false;

    return (ceil(log2(n)) == floor(log2(n)));
}

ll  id13(ll  n)
{
    ll  p = 1;
    if (n && !(n & (n - 1)))
        return n;

    while (p < n)
        p <<= 1;

    return p;
}



ll binpow(ll a, ll b, ll m) {
    if (b == 0)
        return 1;
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;  

    }
    return res;
}

ll fact(ll n);

ll nCr(ll n, ll r)
{
    return fact(n) / (fact(r) * fact(n - r));
}



ll fact(ll n)
{

    ll res = 1;
    for (ll i = 2; i <= n; i++)
        res = (res * i) % mod;
    return res;
}

struct neal {
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const
    {
        static const uint64_t id5 = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + id5);
    }
};


long long gcd(long long int a, long long int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}



long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}


bool isPrime(ll n)
{
    

    if (n <= 1)
        return false;

    

    for (ll i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;

    return true;
}






























vector<ll>primef;
void primeFactors(ll n)
{
    while (n % 2 == 0)
    {
        

        primef.push_back(2);
        n = n / 2;
    }

    for (ll i = 3; i <= (ll)sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            

            primef.push_back(i);
            n = n / i;
        }
    }

    if (n > 2) {
        primef.push_back(n);
    }
}


vector<ll>proper_d;
void id0(ll num)
{
    ll result = 0;
    if (num == 1) {
        proper_d.push_back(result);
        return ;
    }
    for (ll i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            if (i == (num / i))
                proper_d.push_back(i);
            else {
                proper_d.push_back(i);
                proper_d.push_back(num / i);
            }
        }
    }

    proper_d.push_back(1);
    return;
}




ll id10(string n)
{
    string num = n;
    ll dec_value = 0;

    

    ll base = 1;

    ll len = num.length();
    for (ll i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }

    return dec_value;
}

ll findMean(vector<ll>a, ll n)
{
    ll sum = 0;
    for (ll i = 0; i < n; i++)
        sum += a[i];

    return (ll)sum / (ll)n;
}

vector<ll>med;


void findMedian( vector<ll>a, ll n)
{
    

    sort(all(a));

    

    if (n % 2 != 0) {
        med.push_back(a[n / 2]);
        return ;
    }
    med.push_back(a[(n - 1) / 2]);
    med.push_back((a[n / 2]));

    return ;
}


ll powerTow(ll a) {
    ll x = 1;
    fo(i, a) {
        x *= 2;
    }
    return x;
}


bool isComposite(ll  i)
{
    for ( ll  j = 2; j < i; j++)
    {
        if (i % j == 0)
        {   return true;    }
    }
    return false;
}











ll evenSum(ll n)
{
    

    return (n * (n + 1)) ;
}

bool isPalindrome(string S)
{
    

    

    string P = S;

    

    reverse(P.begin(), P.end());

    

    if (S == P) {
        

        return 1;
    }
    

    else {
        

        return 0;
    }
}





bool sort1(const pair<int, int> &a,
           const pair<int, int> &b)
{
    if (a.first == b.first)
    {
        return b.second < a.second;
    }

    return a.first < b.first;
}

const ll limit = 2e5 + 10;





void dfs(int v, vector<int> adj[], vector<bool> &vis)
{
    vis[v] = true;

    for (auto it : adj[v])
    {
        if (vis[it] == false)
            dfs(it, adj, vis);

    }
}


int id6(int n, vector<int> adj[] )
{
    int cnt = 0;

    vector<bool>vis(n + 1, 0);

    for (int i = 0; i <= n; i++)
        vis[i] = false;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i] )
        {
            dfs(i, adj, vis);
            cnt++;
        }
    }

    return cnt;
}
ll p(ll n, ll ket)
{
    ll ans = 1;

    for (int i = 1; i <= ket; i++)
        ans = (ans * n) % mod;

    return ans;

}


int id11( long long x)
{
    static const unsigned long long t[6] = {
        0xFFFFFFFF00000000ull,
        0x00000000FFFF0000ull,
        0x000000000000FF00ull,
        0x00000000000000F0ull,
        0x000000000000000Cull,
        0x0000000000000002ull
    };

    int y = (((x & (x - 1)) == 0) ? 0 : 1);
    int j = 32;
    int i;

    for (i = 0; i < 6; i++) {
        int k = (((x & t[i]) == 0) ? 0 : j);
        y += k;
        x >>= k;
        j >>= 1;
    }

    return y;
}







ll  factorial(ll  n)
{
    if (n == 0)
        return 1;
    ll ans = 1;
    for (ll i = 1; i <= n; i++)
        ans = ans * i;
    return ans;

}

bool id12(const pair<int, int> &a,
               const pair<int, int> &b)
{
    return (a.second < b.second);
}





bool dfsCycle(int i, vector<bool> &vis, vector<vector<int>> &id3)
{
    if (vis[i] == 1)
        return true;

    vis[i] = 1;
    for (int j = 0; j < id3[i].size(); j++)
    {
        if (vis[id3[i][j]] == 0)
            dfsCycle(i, vis, id3);
        else
            return true;
    }

    return false;
}


struct node {
    int data;
    struct node * left, * right;
};



vector<vector<int>>ans;
void get_children(node * n1, vector<int>& res,  node * parent) {

    if (n1 == NULL)
        return;

    if (n1->data > parent->data)
    {
        res.push_back(n1->data);
    }

    get_children(n1->left, res, parent);

    get_children(n1->right, res, parent);


}

void id4(node * curr, vector < int > & inOrder) {
    if (curr == NULL)
        return;

    vector<int>temp;



    get_children(curr->left, temp, curr);


    get_children(curr->right, temp, curr);
    ans.push_back(temp);

    id4(curr -> left, inOrder);

    inOrder.push_back(curr -> data);

    id4(curr -> right, inOrder);
}

struct node * newNode(int data) {
    struct node * node = (struct node * ) malloc(sizeof(struct node));
    node -> data = data;
    node -> left = NULL;
    node -> right = NULL;

    return (node);
}





ll id1(vector<ll>a, ll size)
{
    ll id7 = INT_MIN, id2 = 0;

    for (ll i = 0; i < size; i++)
    {
        id2 = id2 + a[i];
        if (id7 < id2)
            id7 = id2;

        if (id2 < 0)
            id2 = 0;
    }
    return id7;
}

ll id8(vector<ll>v , ll n, ll k)
{

    ll res = 0;

    for (ll i = 0; i < k; i++)
        res += v[i];

    ll curr_sum = res;

    for (ll i = k; i < n; i++)
    {
        curr_sum += v[i] - v[i - k];

        res = max(res, curr_sum);
    }
    return res;

}


void solve()
{

    


    ll n;
    cin >> n;
    string s;
    cin >> s;

    int cnt = 0;
    vector<int>one, t;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
            one.push_back(i);
        else if (s[i] == '2')
            t.push_back(i);
    }
    debug(t)
    debug(one)
    if (t.size() <= 2 && t.size() > 0)
    {
        cout << "NO" << "\n";
        return;
    }

    cout << "YES" << "\n";

    char ans[n][n] ;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans[i][j] = 'L';

        }
    }
    int k = 0;
    if (one.size() > 0)
        for (int i = 0; i < n; i++)
        {
            if (one[k] == i && k < one.size())
            {
                for (int j = 0; j < n; j++)
                {
                    ans[i][j] =  '=';

                }
                k++;
                if (k == one.size())
                    break;
            }
        }

    if (t.size() > 0)
        rotate(t.begin(), t.begin() + 1, t.end());

    debug(t)
    debug(one)
    k = 0;
    int k1 = 0;

    for (int i = 0; i < n; i++)
    {
        int f = 0;
        if (k < one.size() && one[k] == i)
        {
            k++;

            continue;

        }
        else
        {

            for (int j = 0; j < n; j++)
            {
                if (k1 < t.size() && t[k1] == j && f == 0 && ans[i][j] == 'L')
                {
                    ans[i][j] = '+';
                    ans[j][i] = '-';
                    k1++;
                    f = 1;
                }
                else if (ans[i][j] == 'L')
                {
                    ans[i][j] = '=';

                }
            }

        }
    }

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                ans[i][j] = 'X';
            }
            cout << ans[i][j];
        }
        cout << "\n";
    }




}

int  main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fixed;
    cout << setprecision(10);

    

    

    

    

    





    ll t = 1;

    cin >> t;

    while (t-- > 0)
    {


        

        solve();
        


    }

}