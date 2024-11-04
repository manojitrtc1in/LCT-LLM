#pragma GCC optimize("Ofast")



#include <iostream>      

#include <iomanip>       

#include <cassert>       

#include <cmath>         

#include <cstdio>        

#include <cstring>       

#include <cstdlib>       

#include <map>           

#include <set>           

#include <stack>         

#include <queue>         

#include <vector>        

#include <chrono>        

#include <algorithm>     

#include <unordered_map> 

#include <unordered_set> 


using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;


template <typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update>;





#define int long long
#define pb push_back
#define endl "\n"
#define all(CON) (CON).begin(), (CON).end()
#define F first
#define S second
#define MP make_pair
#define sz(x) (int)x.size()
#define rp(i, n) for (int i = 0; i < n; i++)
#define fr(i, n) for (int i = 1; i <= n; i++)
#define ff(i, a, b) for (int i = a; i <= b; i++)
#define fff(i, a, b) for (int i = a; i < b; i++)
#define rrp(i, n) for (int i = n - 1; i >= 0; i--)
#define rfr(i, n) for (int i = n; i >= 1; i--)
#define onlyunique(v) v.erase(unique(v.begin(), v.end()), v.end()); 


#define TRACE
#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args)
{
    const char *comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " || ";
    __f(comma + 1, args...);
}
#else
#define trace(...)
#endif

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<pair<int, int>> vpi;

const int mod = 1e9 + 7;


const long long inff = 2e18;
const int inf = 2e9;

int min(int x, int y) 

{
    return y ^ ((x ^ y) & -(x < y));
}
int max(int x, int y) 

{
    return x ^ ((x ^ y) & -(x < y));
}










int add(int a, int b) 

{
    if (b == 0)
        return a;
    int sum = a ^ b;
    int carry = (a & b) << 1;
    return add(sum, carry);
}
int Add(int a, int b) 

{
    while (b != 0)
    {
        int sum = a ^ b;
        int carry = (a & b) << 1;
        a = sum;
        b = carry;
    }
    return a;
}
int subtract(int a, int b) 

{
    if (b == 0)
        return a;
    return subtract((a ^ b), ((~a) & b) << 1);
}
int Subtract(int x, int y) 

{
    while (y != 0)
    {
        int borrow = (~x) & y;
        x = x ^ y;
        y = borrow << 1;
    }
    return x;
}


int multiply(int a, int b) 

{
    int res = 0;
    while (b)
    {
        if (b & 1)
        {
            res = res + a;
        }
        a = a << 1;
        b = b >> 1;
    }
    return res;
}
int divide(int a, int b)
{
    int sign = ((a < 0) ^ (b < 0)) ? -1 : 1;
    a = abs(a);
    b = abs(b);
    int q = 0, tmp = 0;
    for (int i = 31; i >= 0; --i)
    {
        if (tmp + (b << i) <= a)
        {
            tmp += (b << i);
            q |= (1LL << i);
        }
    }
    return sign * q;
}
int bitcount(int n) 

{
    if (n < 2)
        return n;
    return (n & 1) + bitcount(n >> 1);
}
bool ispowerof2(int n) 

{
    return (__builtin_popcountll(n) == 1);
}
int gcd(int a, int b) 

{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
int lcm(int a, int b) 

{
    return (a / gcd(a, b)) * b;
}
int binpow(int a, int b) 

{
    if (b == 0)
        return a;
    int res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}
int pow(int a, int b) 

{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
int modpow(int a, int b, int m) 

{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}
bool isprime(int x) 

{
    if (x < 2)
        return false;
    if (x < 4)
        return true;
    if (!(x & 1))
        return false;
    for (int i = 3; i * i <= x; i += 2)
        if (x % i == 0)
            return false;
    return true;
}

const int MOD = 1e9 + 7;
const int MXX = 1e5 + 69;
int fact[MXX], invfact[MXX];
int modinv(int k) 

{
    return modpow(k, MOD - 2, MOD);
}
void combinatorics()
{
    fact[0] = fact[1] = 1;
    for (int i = 2; i < MXX; i++)
    {
        fact[i] = fact[i - 1] * i;
        fact[i] %= MOD;
    }

    invfact[MXX - 1] = modinv(fact[MXX - 1]);
    for (int i = MXX - 2; i >= 0; i--)
    {
        invfact[i] = invfact[i + 1] * (i + 1);
        invfact[i] %= MOD;
    }
}
int nCr(int x, int y) 

{
    if (y > x)
        return 0;
    int num = fact[x];
    num *= invfact[y];
    num %= MOD;
    num *= invfact[x - y];
    num %= MOD;
    return num;
}


string lwr(string s)
{
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}


string upr(string s)
{
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    return s;
}


vector<int> factorize(int n)
{
    vector<int> v;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            v.push_back(i);
            if (i * i != n)
            {
                v.push_back(n / i);
            }
        }
    }
    sort(v.begin(), v.end());
    return v;
}








class DSU
{
public:
    vector<int> par, sz;
    

    DSU(int n)
    {
        n = n + 2;
        par.resize(n);
        sz.resize(n);
        for (int i = 0; i < n; i++)
            par[i] = i, sz[i] = 1;
    }
    

    int find(int x)
    {
        if (x == par[x])
            return par[x];
        else
            return (par[x] = find(par[x])); 

        

        

    }
    

    void Unite(int x, int y) 

    {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        if (sz[x] < sz[y])
            swap(x, y);
        sz[x] += sz[y];
        par[y] = x;
    }
    

    bool Same(int x, int y)
    {
        return find(x) == find(y);
    }
    

    int size(int x)
    {
        return sz[find(x)];
    }
};










class StackNode
{
public:
    int data;
    StackNode *next;
    

    StackNode *CreateNode(int val)
    {
        StackNode *snw = new StackNode();
        snw->data = val;
        snw->next = NULL;
    }
    

    int isEmpty(StackNode *root)
    {
        return (!root);
    }
    

    StackNode *push(StackNode *root, int val)
    {
        StackNode *nn = CreateNode(val);
        nn->next = root;
        root = nn;
        return root;
    }
    

    StackNode *pop(StackNode *root)
    {
        if (isEmpty(root))
            return NULL;
        StackNode *tmp = root;
        (root) = (root)->next;
        int popped = tmp->data;
        free(tmp);
        return root;
    }
    

    int peek(StackNode *root)
    {
        if (isEmpty(root))
            return -2e9;
        return root->data;
    }
    

    int size(StackNode *root)
    {
        StackNode *a = root;
        int ans = 0;
        while (a != NULL)
        {
            a = a->next;
            ans++;
        }
        return ans;
    }
};


class QNode
{
public:
    int data;
    QNode *next;
    QNode(int val)
    {
        data = val;
        next = NULL;
    }
};




class Queue
{
public:
    QNode *front;
    QNode *rear;
    Queue()
    {
        front = rear = NULL;
    }
    

    void EnQueue(int x)
    {
        QNode *tmp = new QNode(x);
        if (rear == NULL)
        {
            front = rear = tmp;
            return;
        }
        rear->next = tmp;
        rear = tmp;
    }
    

    void DeQueue()
    {
        if (front == NULL)
            return;
        QNode *tmp = front;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        delete (tmp);
    }
    

    int Front()
    {
        return front->data;
    }
    

    int Back()
    {
        return rear->data;
    }
    

    bool isEmpty()
    {
        return front == rear and front == NULL;
    }
    

    void displayQueue()
    {
        QNode *a = front;
        while (a != NULL)
        {
            cout << (a->data) << " ";
            a = a->next;
        }
        cout << endl;
    }
};


template <typename T>
void prev(vector<T> &v)
{
    for (auto t : v)
        cout << t << " ";
    cout << endl;
}


template <typename T>
void prevs(vector<T> &v)
{
    cout << v.size() << endl;
    for (auto t : v)
        cout << t << " ";
    cout << endl;
}


void prar(int a[], int n, int x)
{
    for (int i = 0 + x; i < n + x; i++)
        cout << a[i] << " ";
    cout << endl;
}
template <typename T>
std::pair<bool, int> findInVector(const std::vector<T> &vecOfElements, const T &element)
{
    std::pair<bool, int> result;
    auto it = std::find(vecOfElements.begin(), vecOfElements.end(), element);
    if (it != vecOfElements.end())
    {
        result.second = distance(vecOfElements.begin(), it);
        result.first = true;
    }
    else
    {
        result.first = false;
        result.second = -1;
    }
    return result;
}


bool isvowel(char ch)
{
    string s = "aeiouAEIOU";
    for (char c : s)
        if (c == ch)
            return true;
    return false;
}
const int infms = 2e9;
int inversions = 0;
void Merge(int a[], int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int left[n1 + 2];
    int right[n2 + 2];
    left[n1 + 1] = infms;
    right[n2 + 1] = infms;

    for (int i = 1; i <= n1; i++)
        left[i] = a[start + i - 1];

    for (int i = 1; i <= n2; i++)
        right[i] = a[mid + i];

    int x = 1, y = 1;
    for (int k = start; k <= end; k++)
        if (left[x] <= right[y])
        {
            a[k] = left[x];
            x++;
        }
        else
        {
            inversions += (1 + n1 - x);
            a[k] = right[y];
            y++;
        }
}


void MergeSort(int a[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        MergeSort(a, start, mid);
        MergeSort(a, mid + 1, end);
        Merge(a, start, mid, end);
    }
}


bool ispalindrome(string s)
{
    int n = s.length();
    if (n <= 1)
        return true;
    else if (n == 2 && s[1] == s[0])
        return true;
    else if (n == 2 && s[0] != s[1])
        return false;
    else if (s[0] != s[n - 1])
        return false;
    else
        return ispalindrome(s.substr(1, n - 2));
}


bool palindrome(string s)
{
    string t = s;
    reverse(all(t));
    return (t == s);
}


bool checkpalindrome(string s)
{
    for (int i = 0; i <= s.length(); i++)
        if (s[i] != s[s.length() - 1 - i])
            return false;
    return true;
}
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second < b.second);
}














const int NN = 1e5 + 5;
vector<pair<int, int>> adj[NN];
vi d, p;
void dijkstra(int s, vector<int> &d, vector<int> &p)
{
    int n = NN;
    d.assign(n, inf);
    p.assign(n, -1);
    d[s] = 0; 

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, s}); 

    while (!q.empty())
    {
        int v = q.top().second;  

        int d_v = q.top().first; 

        q.pop();
        if (d_v != d[v])
            continue; 

        

        for (auto edge : adj[v])
        {
            int to = edge.first;
            int len = edge.second;
            if (d[v] + len < d[to])
            {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}
void path(vi &v, int d)
{
    if (p[d] != -1)
        path(v, p[d]);
    v.pb(d);
}
int addm(int a, int b)
{
    return ((a % mod) + (b % mod) + mod) % mod;
}
int subm(int a, int b)
{
    return ((a % mod) - (b % mod) + 2 * mod) % mod;
}
int mulm(int a, int b)
{
    return ((a % mod) * (b % mod) + mod) % mod;
}
int C(int n, int r)
{
    if (r > n - r)
        r = n - r; 

    int ans = 1;
    int i;
    for (i = 1; i <= r; i++)
    {
        ans *= n - r + i;
        ans /= i;
    }
    return ans;
}
void dream();
auto clk = clock();
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    cout << setprecision(8);
    

    

    

    

    

    

    int TESTCASES = 1;
    

    for (int i = 1; i <= TESTCASES; i++)
        dream();

#ifndef ONLINE_JUDGE
    cout << endl
         << "Time elapsed: " << (double)(clock() - clk) / CLOCKS_PER_SEC << endl
         << endl;
#endif
    return 0;
}















void dream()
{
    int n;
    cin >> n;
    cout << (9 * n) << " " << (8 * n) << endl;
    

}

