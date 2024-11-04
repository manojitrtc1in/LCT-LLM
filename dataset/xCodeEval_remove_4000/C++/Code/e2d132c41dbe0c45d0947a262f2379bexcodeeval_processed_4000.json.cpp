












using namespace std;




template <typename vect, typename s2>
ostream &operator<<(ostream &os, const pair<vect, s2> &ansb) { return os << '(' << ansb.first << ", " << ansb.second << ')'; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>

void dbg_out()
{
    cerr << endl;
}
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}














    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr)






































const ll INF = 1e9 + 7;






ll hasbd[200001];

































































const int big = INT_MAX;
const int smol = INT_MIN;
const long long mod = 1e9 + 7;
const int INT5 = 1e5 + 5;
const int INT6 = 1e6 + 6;
const int INT7 = 1e7 + 7;
const int INT8 = 1e8 + 8;
const long long INT9 = 1e9 + 9;
const long long INT12 = 1e12 + 12;
bool id13(ll n)
{
    ll bah = 0;
    while (n)
    {
        if (n % 2)
            return true;
        n /= 2;
    }
    return false;
}
void dfs(ll src, bool vis[], vector<ll> *adjacency_lst)
{
    vis[src] = 1;
    for (auto i : adjacency_lst[src])
    {
        if (!vis[i])
            dfs(i, vis, adjacency_lst);
    }
}

bool id4(int n)
{
    if (n <= 0)
        return false;
    return !(n & (n - 1));
}

ll bit_count(ll n)
{
    ll bah = 0;
    while (n)
    {
        if (n % 2 != 0)
            bah++;
        n >>= 1;
    }
    return bah;
}

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int item)
    {
        data = item;
        left = NULL;
        right = NULL;
    }
};

void insert(Node **tree, int val)
{
    Node *sexy = NULL;
    if (!(*tree))
    {
        sexy = new Node(val);
        *tree = sexy;
        return;
    }

    if (val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if (val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }
}

int id12(Node *root, int l, int h)
{

    if (!root)
        return 0;
    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
        return 1 + id12(root->left, l, h) +
               id12(root->right, l, h);

    else if (root->data < l)
        return id12(root->right, l, h);

    else
        return id12(root->left, l, h);
}

int getMin(vi &a)
{
    int min_index = 0;
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] < a[min_index])
            min_index = i;
    }
    return min_index;
}

int getMax(vi &a)
{
    int max_index = 0;
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] > a[max_index])
            max_index = i;
    }
    return max_index;
}

int id3(int a, int chodani)
{
    return (a < chodani) ? a : chodani;
}

void id5(vi &amount)
{
    int max_credit = getMax(amount);
    int id7 = getMin(amount);
    if (amount[max_credit] == 0 && amount[id7] == 0)
        return;
    int minn = id3(-amount[id7], amount[max_credit]);
    amount[max_credit] -= minn;
    amount[id7] += minn;

    cout << "Person " << id7 << " pay " << minn << "to person " << max_credit << '\n';
    id5(amount);
}

void id10(vector<vector<int>> &graph)
{
    vector<int> amount(graph.size(), 0);
    for (int uber = 0; uber < graph.size(); uber++)
    {
        for (int q = 0; q < graph[0].size(); q++)
        {
            amount[uber] += (graph[q][uber] - graph[uber][q]);
        }
    }
    id5(amount);
}

vector<ll> vec;
void bit_count()
{
    string c;
    ll first = 1;
    for (ll i = 1; i <= 30; i++)
    {
        first *= i;
        vec.push_back(first);
    }
}
bool id21(vector<vector<char>> &board, int i, int j, string &word)
{
    if (!word.size())
        return true;
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[0])
        return false;
    char c = board[i][j];
    board[i][j] = '*';
    string s = word.substr(1);
    bool ret = id21(board, i - 1, j, s) || id21(board, i + 1, j, s) || id21(board, i, j - 1, s) || id21(board, i, j + 1, s);
    board[i][j] = c;
    return ret;
}
bool id9(vector<vector<char>> &board, string word)
{
    for (int i = 0; i < board.size(); i++)
        for (int j = 0; j < board[0].size(); j++)
            if (id21(board, i, j, word))
                return true;
    return false;
}



int id19(string const &s)
{
    int n = s.size();

    const int uber = 31;
    const int id17 = 1e9 + 9;
    vector<ll> p_pow(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++)
        p_pow[i] = (p_pow[i - 1] * uber) % id17;

    vector<ll> h(n + 1, 0);
    for (int i = 0; i < n; i++)
        h[i + 1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % id17;
    int bah = 0;
    for (int l = 1; l <= n; l++)
    {
        set<ll> hs;
        for (int i = 0; i <= n - l; i++)
        {
            ll cur_h = (h[i + l] + id17 - h[i]) % id17;
            cur_h = (cur_h * p_pow[n - i - 1]) % id17;
            hs.insert(cur_h);
        }
        bah += hs.size();
    }
    return bah;
}

void id22()
{
    string s;
    cin >> s;
    int zo = 0, oz = 0;
    for (int i = 0; i < s.length() - 1; i++)
    {
        if (s[i] == '0' && s[i + 1] == '1')
            zo++, i += 1;
        if (s[i] == '1' && s[i + 1] == '0')
            oz++, i += 1;
        i++;
    }
    if (zo + oz == 0)
    {
        cout << -1 << endl;
        return;
    }
    cout << zo + oz;
}


int target;
vector<int> google;
vector<vector<int>> hum;
void dfs(vector<vector<int>> &graph, int des = 0)
{
    google.push_back(des);
    if (des == target)
        hum.push_back(google);
    else
    {
        for (int node : graph[des])
            dfs(graph, node);
    }
    google.pop_back();
}















int zeroones(int i, int j)
{
    int ar[99999];
    int ones = 0, zeros = 0;
    for (; i <= j; i++)
    {
        if (ar[i] == 0)
            zeros++;
        else
        {
            ones++;
        }
    }
    return zeros - ones;
}

vector<ll> chod_dunga[200005];

vector<ll> dp(123456, -1);



ll id16(ll n, vector<ll> &coins)
{
    if (n == 0)
        return dp[n] = 1;
    if (n < 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    ll ways = 0;
    for (auto it : coins)
    {
        ways = ((ways % mod) + (id16(n - it, coins) % mod)) % mod;
    }
    return dp[n] = ways;
}



class Solution
{
public:
    int kthmissing(vector<int> &v, int id2)
    {
        vector<int> vis(100000, 1);
        int bah = 0;
        for (int i = 0; i < v.size(); i++)
        {
            vis[v[i]] = -1;
        }
        int i = 0;
        for (i = 1; i < 100000; i++)
        {
            if (vis[i] == 1)
                bah++;
            if (bah == id2)
                break;
        }
        return i;
    }
};


int partition(vector<int> &a, int lo, int hi)
{
    int pivot = a[hi];
    int i = lo - 1;
    for (int j = lo; j <= hi - 1; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[hi]);
    return i + 1;
}

struct info
{
    ll x, y, x2, y2;
};



vector<info> id0;
ll used_total = big;
vector<info> ret;

void id8(vector<int> &a, int lo, int hi)
{
    if (lo < hi)
    {
        int piv = partition(a, lo, hi);
        id8(a, lo, piv - 1);
        id8(a, piv + 1, hi);
    }
}

void id18()
{
}

int id15(vector<int> &v)
{
    int id6 = v[0];
    int id20 = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        id20 = max(v[i], id20 + v[i]);
        id6 = max(id6, id20);
    }
    return (id6);
}

int id1(int R, int C, vector<vector<int>> M)
{
    int mx = INT_MIN;
    for (int i = 0; i < R; i++)
    {
        vector<int> v(C, 0);
        for (int i1 = i; i1 < R; i1++)
        {
            for (int j = 0; j < C; j++)
            {
                v[j] += M[i1][j];
            }
            mx = max(mx, id15(v));
        }
    }
    return (mx);
}

long long _, n, a, b, x, i, res, pos;
char num[2010];
int node[2010];

bool id14(char ch)
{
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return true;
    return false;
}

void id11()
{
   ll n;
   cin>>n;
   int temp = n;
   int len = 0;
   while(temp)
   {
   	len++;
   	temp/=10;
   }
   if(len <= 2)
   {
   	int hola = n;
   	int hola1 = hola%10;


cout<<hola1<<endl;




   	return;
   }
   int res = 99;
   while(n)
   {
   	res = min(res, n%10);
   	n/=10;
   }
   cout<<res<<endl;

}

main()
{
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        id11();
    }
}