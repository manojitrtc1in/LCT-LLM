


#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <list>
#include <numeric>
#include <stack>
#include <map>
#include <sstream>
#define ll long long
#define ul unsigned long long
#define modu 1000000007
#define f(i,j, n) for (ll i = j; i < n; ++i)
#define fo(i, j, n) for (ll i = j; i >=n; --i)
#define print(x) cout << x << endl
#define gi(x) scanf("%lld",&x)
#define gc(x) scanf("%s",&x)
#define ac(arr) accumulate(arr.begin(),arr.end(),0)
#define pb push_back
#define all(o) (o).begin(), (o).end()
#define ff first
#define ss second
#define mp make_pair
using namespace std;

template<class t1, class t2> using pi = pair<t1, t2>;
template<class t> using vi = vector<t>;
template<class t> using vvi = vi<vi<t>>;
template<class t1, class t2> using um = unordered_map<t1, t2>;
template<typename T>
void printv(vi<T>arr) {
    f(i, 0, arr.size())cout << arr[i] << " ";
    cout << "\n";
    

}
template<class T> inline void amin(T &x, const T &y) { if (y < x) x = y; }
template<class T> inline void amax(T &x, const T &y) { if (x < y) x = y; }





































struct jutsu {
    int  a, b, c;
};

bool jutsu_compare(jutsu s1, jutsu s2) {

    

    


    if (s1.a == s2.a) {
        if (s1.b < s2.b)return true;
        else return false;
    }
    else {
        if (s1.a > s2.a)return true;
        else return false;
    }
}

ll ncr(ll n, ll k)
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

vector<ll>prime(1000005, true);
vi<int>primev;




void seive(void) {
    prime[1] = prime[0] = false;
    for (ll i = 2; i < 1000005; i++) {
        if (prime[i]) {
            

            primev.pb(i) ;
            for (ll j = i * 2; j < 1000005; j += i) {
                prime[j] = 0;
            }
        }
    }
}

ll max(ll a, ll b)
{
    return (a > b) ? a : b;
}
ll min(ll a, ll b)
{
    return (a < b) ? a : b;
}


unsigned long long power(unsigned long long x, int y, int p)
{
    unsigned long long res = 1;
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


unsigned long long modInverse(unsigned long long n,  int p)
{
    return power(n, p - 2, p);
}

unsigned long long nCrModPFermat(unsigned long long n, int r, int p)
{
    if (n < r)
        return 0;
    if (r == 0)
        return 1;
    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;

    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p)
           % p;
}




void swap(ll &a, ll &b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}
ll index(vector<ll>arr, ll val) {
    auto it = find(all(arr), val);
    if (it != arr.end()) {
        ll ind = it - arr.begin();
        return ind;
    }
    else return -1;
}

ll fact(ll x) {
    if (x == 1 || x == 0)return 1;
    return (x * (fact(x - 1)));
}
bool binarySearch(vector<ll>arr, ll val, ll i, ll j) {
    if (i > j)return 0;
    if (arr[i + ((j - i) / 2)] == val)return 1;
    if (arr[i + ((j - i) / 2)] < val)return binarySearch(arr, val, i + ((j - i) / 2) + 1, j);
    return binarySearch(arr, val, i, i + ((j - i) / 2) - 1);
}



const int N = 2e5 + 5;
int tree[4 * N];
void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
}
void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        tree[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, new_val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
}

int sum(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        return tree[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v * 2, tl, tm, l, min(r, tm))
           + sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

void readSentence(void) {
    string s, t;
    getline(cin, s);
    stringstream sent(s);
    while (getline(sent, t, ' ')) {
        cout << t << " ";
    }
}

ll query(ll v, ll tl, ll tr, ll l, ll r, ll &to) {
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        to = min(to, tree[v]);
        return tree[v];
    }
    ll tm = (tl + tr) / 2;
    return (query(v * 2, tl, tm, l, min(r, tm), to)
            + query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, to));
}
void rangebuild(ll a[], ll v, ll tl, ll tr) {
    if (tl == tr) {
        tree[v] = a[tr];
    } else {
        ll tm = (tl + tr) / 2;
        rangebuild(a, v * 2, tl, tm);
        rangebuild(a, v * 2 + 1, tm + 1, tr);
        tree[v] = 0;
    }
}

void rangeupdate(ll v, ll tl, ll tr, ll l, ll r, ll add) {
    if (l > r)
        return ;
    if (l == tl && r == tr) {
        tree[v] += (add);
    } else {
        ll tm = (tl + tr) / 2;
        rangeupdate(v * 2, tl, tm, l, min(r, tm), add);
        rangeupdate(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, add);
    }
}

ll rangeget(ll v, ll tl, ll tr, ll pos) {
    if (tl == tr)
        return tree[v];
    ll tm = (tl + tr) / 2;
    if (pos <= tm)
        return tree[v] + rangeget(v * 2, tl, tm, pos);
    else
        return tree[v] + rangeget(v * 2 + 1, tm + 1, tr, pos);
}



void bitsetoperation(ll n) {
    string binary = bitset<14>(n).to_string();
    ll decimal = bitset<14>(binary).to_ulong();
}


int isSubstring(string s2, string s1)
{
    int M = s1.length();
    int N = s2.length();

    
    for (int i = 0; i <= N - M; i++) {
        int j;

        
        for (j = 0; j < M; j++)
            if (s2[i + j] != s1[j])
                break;

        if (j == M)
            return i;
    }

    return 0;
}



vi<ll>visited(200005, 0);
map<ll, ll>mppdfs;
string b, a;
vi<ll>adj[200005];
set<set<ll>>ss;
map <pi< ll, ll>, ll>mpp;
void dfs(ll u) {
    visited[u] = 1;
    for (auto x : adj[u]) {
        if (!visited[x])
            dfs(x);
    }
}



void hinataVSsakura(void);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    

    freopen("input.txt", "r", stdin);

    

    freopen("output.txt", "w", stdout);
#endif
    long long T = 1;
    cin >> T;
    

    ll k = 1;
    while (T--) {
        

        hinataVSsakura();
        


    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec\n";
#endif
    return 0;
}
bool flg = 1;
struct sNode {
    char data;
    struct sNode* next;
};



int pop(struct sNode** top_ref)
{
    char res;
    struct sNode* top;

    

    if (*top_ref == NULL) {
        flg = false;
        return 0;
        

        

    }
    else {
        top = *top_ref;
        res = top->data;
        *top_ref = top->next;
        free(top);
        return res;
    }
}

void push(struct sNode** top_ref, int new_data)
{
    if (!flg) {
        print("NO");
        return;
    }
    

    struct sNode* new_node = (struct sNode*)malloc(sizeof(struct sNode));

    if (new_node == NULL) {
        print("NO");
        return;
    }

    

    new_node->data = new_data;

    

    new_node->next = (*top_ref);

    

    (*top_ref) = new_node;
}
bool isMatchingPair(char character1, char character2)
{   if (!flg) {
        print("NO");
        return false;
    }
    if (character1 == '(' && character2 == ')')
        return 1;
    else
        return 0;
}



bool areBracketsBalanced(string exp)
{   if (!flg) {
        print("NO");
        return false;
    }
    int i = 0;

    

    struct sNode* stack = NULL;

    

    

    while (exp[i])
    {
        

        

        if ( exp[i] == '(' )
            push(&stack, exp[i]);

        

        

        

        if ( exp[i] == ')') {

            

            

            if (stack == NULL)
                return 0;

            

            

            

            

            else if (!isMatchingPair(pop(&stack), exp[i]))
                return 0;
        }
        i++;
    }

    

    

    

    if (stack == NULL)
        return 1; 

    else
        return 0; 

}
bool isBalancedExp(string exp) {
    stack<char> stk;
    char x;
    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
            stk.push(exp[i]);
            continue;
        }
        if (stk.empty())
            return false;
        switch (exp[i]) {
        case ')':
            x = stk.top();
            stk.pop();
            if (x == '{' || x == '[')
                return false;
            break;
        case '}':
            x = stk.top();
            stk.pop();
            if (x == '(' || x == '[')
                return false;
            break;
        case ']':
            x = stk.top();
            stk.pop();
            if (x == '(' || x == '{')
                return false;
            break;
        }
    }
    return (stk.empty());
}
void hinataVSsakura(void)
{
    flg = 1;
    ll n;
    cin >> n;
    string s;
    cin >> s;
    string a = "", b = "";
    ll o1 = 0, o2 = 0;
    f(i, 0, s.size()) {
        if (s[i] == '1') {
            if (i == 0) {
                a += '(';
                b += '(';
                

                

            }
            else if (i == n - 1) {
                a += ')';
                b += ')';
                

                

            }
            else {
                o1++;
                if (o1 & 1)a += '(', b += '(';
                else a += ')', b += ')';
            }
        }
        else {

            o2++;
            if (o2 & 1)a += ')', b += '(';
            else a += '(', b += ')';

        }
    }
    

    

    if (!flg ) {
        print("NO");
        return;
    }
    if (isBalancedExp(a) and isBalancedExp(b)) {
        print("YES");
        print(a);
        print(b);
    }
    else {
        print("NO");
    }
}


