
























using namespace std;






void build(int v, int vl, int vr)
{
}


















































bool Ans(long long a)
{
    vector<bool> used(10);
    while (a)
    {
        if (a % 10 == 2 || a % 10 == 0 || used[a % 10]) return false;
        used[a % 10] = true;
        a /= 10;
    }
    return true;
}
int mc = -1;
float dist(pair<int, int> a)
{
    return (a.first) * (a.first) + (a.second - mc) * (a.second - mc);
}










vector<pair<int, int>> st = { { 0,1 }, { 0,-1 },  { 1,0 }, { 1,1 }, { 1,-1 }, { -1,0 }, { -1,-1 }, { -1,1 } };
int gcd(int a, int b)
{
    int t = max(a, b);
    b = min(a, b);
    a = t;
    if (b == 0) return a;
    else return gcd(b, a % b);
}

void disp(vector<vector<char>>& a)
{
    loopi(a.size())
    {
        loopj(a[i].size())
        {
            cout << a[i][j];
        }
        cout << endl;
    }
}

int conv(char s)
{
    if (isdigit(s))
    {
        return s - '0';
    }
    else return s - 'A' + 10;
}

bool check(int a, int b, int c, int d)
{
    int cu = 0, w = 0;
    vector<int> used1(10);
    vector<int> used2(10);
    while (a > 0)
    {
        if (a % 10 == b % 10) { cu++; }
        else
        {
            used1[a % 10]++;
            used2[b % 10]++;
        }
        a /= 10;
        b /= 10;
    }
    loopi(10)
    {
        w += min(used1[i], used2[i]);
    }
    return (c == cu && d == w);
}
int ask(int a, int b)
{
    cout << "? " << a + 1 << " " << b + 1 << endl;
    cout.flush();
    int t;
    cin >> t;
    return t;
}
int bs(vector<int>& a, int l, int r, int f)
{
    if (l == r - 1) return (a.size() > r ? r + 1 : -1e9 - 2);
    int m = (l + r) / 2;
    if (a[m] > f) return bs(a, m, r, f);
    else return bs(a, l, m, f);
}
int sc_prod(pair<int, int> a, pair<int, int> b)
{
    return b.second * a.second + b.first * a.first;
}

vector<vector<int>> g;
vector<pair<int, vector<int>>> d;
vector<int> li;
vector<bool> used;
int Max;
int maxPos;
int id1;


























































int go(vector<vector<int>>& d, vector<vector<pair<vector<int>, vector<int>>>>& g, int p, int l, bool& flag, int x2, int y2)
{
    if (l == x2 && p == y2) {
        flag = true; return g[l][p].first[0];
    }
    else flag = false;
    if (d[l][p] == 0) d[l][p] = g[l][p].first[0];
    else return d[l][p];
    int mx = -1;
    bool f = false;
    for (auto e : g[l][p].second)
    {
        int temo = go(d, g, e, l + 1, flag, x2, y2);
        if (flag) { mx = temo; f = true; }
        flag = f;
    }
    if (mx == -1) return mx;
    d[l][p] += mx;
    return d[l][p];
}
bool comp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first) return a.second > b.second;
    return a.first >= b.first;
}
bool comp2(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second) return a.first > b.first;
    return a.second >= b.second;
}
double dist(int x1, int y)
{
    return sqrt((double)x1 * x1 + y * y);
}
int sc_pr(int x1, int x2, int y1, int y2)
{
    return x1 * x2 + y1 * y2;
}










































int mask(string s)
{
    int a = 0;
    loopi(s.size())
        a += (1 << s[i] - 'a');
    return a;
}
int mask(char s)
{
    return 1 << s - 'a';
}
int color(vector<int>& ans, vector<vector<int>>& g,  int v)
{
    if (ans[v] != -1) return ans[v];
    ans[v] = v;
    int n = g[v].size();
    loopi(n)
    {
        if (g[i][v] == g[v][i] && g[v][i] == 1) ans[v] = color(ans, g, i);
        else color(ans, g, i);
    }
    return ans[v];
}
int dp(vector<vector<int>>& d, char b, int i, int j, int n, vector<vector<char>>& a) {
    if (d[i][j]) return d[i][j];
    d[i][j] = -1;
    if (i + 1 < n && (a[i + 1][j] == b|| a[i + 1][j]=='F')) d[i][j] = max(d[i][j], dp(d, b, i + 1, j, n, a));
    if (j+1 < n && (a[i][j+1] == b|| a[i][j + 1] == 'F')) d[i][j] = max(d[i][j], dp(d, b, i, j+1, n, a));
    return d[i][j];
}
void solve()
{
    int t;
    cin >> t;
    loop(p,0,t)
    {
        int n;
        cin >> n;
        vector<vector<char>> a(n, vector<char>(n));
        loopi(n)
        {
            string tmp;
            cin >> tmp;
            loopj(n)
            {
                a[i][j] = tmp[j];
            }
        }
        
        
        vector<pair<int, int>> st{ {0,1},{1,0},{n - 1,n - 2},{n - 2,n - 1} };
        vector<vector<int>> d(n, vector<int>(n));
        d[n - 1][n - 1] = 1;
        if (a[0][1] == '0') dp(d, '0', 0, 1, n, a);
        else dp(d, '1', 0, 1, n, a);
        if (a[1][0] == '0') dp(d, '0', 1, 0, n, a);
        else dp(d, '1', 1, 0, n, a);
        if (d[0][1] == -1 && d[1][0] == -1)
        {
            cout << 0 << endl;
            continue;
        }
        bool f = false;
        loopi(4)
        {
            vector<vector<int>> d(n, vector<int>(n));
            a[st[i].first][st[i].second] = (a[st[i].first][st[i].second] - '0') ^ 1 + '0';
            d[n - 1][n - 1] = 1;
            if (a[0][1] == '0') dp(d, '0', 0, 1, n, a);
            else dp(d, '1', 0, 1, n, a);
            if (a[1][0] == '0') dp(d, '0', 1, 0, n, a);
            else dp(d, '1', 1, 0, n, a);
            
            if (d[0][1] == -1 && d[1][0] == -1)
            {
                cout << 1 << endl;
                cout << st[i].first + 1 << " " << st[i].second + 1 << endl;
                f = true;
                break;

            }
            a[st[i].first][st[i].second] = (a[st[i].first][st[i].second] - '0') ^ 1 + '0';
        }
        if (f) continue;
        loopi(4)
        {
            a[st[i].first][st[i].second] = (a[st[i].first][st[i].second] - '0') ^ 1+'0';
            bool f = false;
            loop(j, i + 1, 4)
            {
                if (i == 2 && j == 3)
                {
                    int t;
                }
                vector<vector<int>> d(n, vector<int>(n));
                d[n - 1][n - 1] = 1;
                a[st[j].first][st[j].second] = (a[st[j].first][st[j].second] - '0') ^ 1+'0';
                if (a[0][1] == '0') dp(d, '0', 0, 1, n, a);
                else dp(d, '1', 0, 1, n, a);
                if (a[1][0] == '0') dp(d, '0', 1, 0, n, a);
                else dp(d, '1', 1, 0, n, a);
                if (d[0][1] == -1 && d[1][0] == -1)
                {
                    cout << 2 << endl;
                    cout << st[i].first+1 << " " << st[i].second + 1 << endl;
                    cout<< st[j].first + 1 << " " << st[j].second + 1 << endl;
                    f = true;
                    break;

                }
                
                a[st[j].first][st[j].second] = (a[st[j].first][st[j].second] - '0') ^ 1 + '0';
            }
            if (f) break;
            a[st[i].first][st[i].second] = (a[st[i].first][st[i].second] - '0') ^ 1 + '0';
        }

    }
    
}





const int sze = 1e5 + 100;
struct node {
    bool term;
    map<char, int> child;
    node()
    {
        term = false;
    }
};
node trie[sze];
int dp[sze];
int cnt = 0;
int j = 0;
int curlen = 5e6;
bool fnd(string s)
{
    int i = 0, idx = 0, sz = s.size();
    while (i != sz + 1)
    {
        char ch;
        ch = s[i];
        int ce = trie[idx].child[ch];
        if (ce == 0)
        {
            return false;
        }
        else idx = ce;
        i++;
    }
    return trie[idx].term;
}
void insert(string s)
{
    int i = 0, idx = 0, sz = s.size();
    dp[0]++;
    while (i != sz)
    {
        char ch;
        ch = s[i];
        int ce = trie[idx].child[ch];
        if (ce == 0)
        {
            trie[idx].child[ch] = ++j;
            idx = j;
        }
        else idx = ce;
        i++;
        dp[idx]++;
    }
    if (!trie[idx].term) cnt++;
    trie[idx].term = true;
}
int find(int k, int idx, int l)
{
    if (trie[idx].child.find((k >> l) % 2 + '0') == trie[idx].child.end())
    {
        return 0;
    }
    if (dp[trie[idx].child[(k >> l) % 2 + '0']] != 1 << l)
        return ((k >> l) % 2) * (1 << l) + find(k, trie[idx].child[((k >> l) % 2) + '0'], l - 1);
    return (((k >> l) % 2) ^ 1) * (1 << l) + find(k, trie[idx].child[((k >> l) % 2) ^ 1 + '0'], l - 1);
}
string tobin(int a)
{
    string s = "";
    loopi(2)
    {
        s = to_string(a % 2) + s;
        a /= 2;
    }
    return s;

}
void solve() {
    
    int n, max = 0;
    cin >> n;
    vector<int> a(n);
    loopi(n)
    {
        cin >> a[i];
        if (a[i] > max) max = a[i];
    }
    int c = 0;
    loopi(n)
    {
        if (a[i] == max) c++;
    }
    cout << c;
    
}


int main() {

    auto id0 = std::chrono::system_clock::now();

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);


    freopen(FILE__".in", "r", stdin);
    freopen(FILE__".out", "w", stdout);

    solve();

    cout << endl << "Time elansed: " << chrono::duration_cast<chrono::milliseconds>(std::chrono::system_clock::now() - id0).count() << " ms" << endl;

    return 0;
}