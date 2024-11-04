












using namespace std;













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





























int dy[] = {0, 0, 1, -1};




































const int big = INT_MAX;
const int smol = INT_MIN;
const long long mod = 1e9 + 7;
const int INT5 = 1e5 + 5;
const int INT6 = 1e6 + 6;
const int INT7 = 1e7 + 7;
const int INT8 = 1e8 + 8;
const long long INT9 = 1e9 + 9;
const long long INT12 = 1e12 + 12;

bool id11(ll n)
{
  while (n)
  {
    if (n % 2)
      return true;
    n /= 2;
  }
  return false;
}

void depth(ll src, bool vis[], vector<ll> *adjacency_lst)
{
  vis[src] = 1;
  for (auto i : adjacency_lst[src])
  {
    if (!vis[i])
      depth(i, vis, adjacency_lst);
  }
}

bool id3(int n)
{
  if (n <= 0)
    return false;
  return !(n & (n - 1));
}
int dx[] = {1, -1, 0, 0};
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

void insert(Node **tree, int dam)
{
  Node *sexy = NULL;
  if (!(*tree))
  {
    sexy = new Node(dam);
    *tree = sexy;
    return;
  }

  if (dam < (*tree)->data)
  {
    insert(&(*tree)->left, dam);
  }
  else if (dam > (*tree)->data)
  {
    insert(&(*tree)->right, dam);
  }
}
const int n = 3e3 + 10;
int id10(Node *root, int l, int h)
{

  if (!root)
    return 0;
  if (root->data == h && root->data == l)
    return 1;

  if (root->data <= h && root->data >= l)
    return 1 + id10(root->left, l, h) +
           id10(root->right, l, h);

  else if (root->data < l)
    return id10(root->right, l, h);

  else
    return id10(root->left, l, h);
}
int getMin(vector<int> a)
{
  int n = a.size();
  int max_index = INT_MAX;
  for (int i = 1; i < n; i++)
  {
    if (a[i] < a[max_index])
      max_index = i;
  }
  return max_index;
}

int getMax(vector<int> a)
{
  int n = a.size();
  int max_index = 0;
  for (int i = 1; i < n; i++)
  {
    if (a[i] > a[max_index])
      max_index = i;
  }
  return max_index;
}

int id2(int a, int chodani)
{
  return (a < chodani) ? a : chodani;
}

void id4(vi &amount)
{
  int max_credit = getMax(amount);
  int id5 = getMin(amount);
  if (amount[max_credit] == 0 && amount[id5] == 0)
    return;
  int minn = id2(-amount[id5], amount[max_credit]);
  amount[max_credit] -= minn;
  amount[id5] += minn;

  cout << "Person " << id5 << " pay " << minn << "to person " << max_credit << '\n';
  id4(amount);
}

void id8(vector<vector<int>> &graph)
{
  vector<int> amount(graph.size(), 0);
  for (int uber = 0; uber < graph.size(); uber++)
  {
    for (int q = 0; q < graph[0].size(); q++)
    {
      amount[uber] += (graph[q][uber] - graph[uber][q]);
    }
  }
  id4(amount);
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
bool id18(vector<vector<char>> &board, int i, int j, string &word)
{
  if (!word.size())
    return true;
  if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[0])
    return false;
  char c = board[i][j];
  board[i][j] = '*';
  string s = word.substr(1);
  bool ret = id18(board, i - 1, j, s) || id18(board, i + 1, j, s) || id18(board, i, j - 1, s) || id18(board, i, j + 1, s);
  board[i][j] = c;
  return ret;
}
bool id7(vector<vector<char>> &board, string word)
{
  for (int i = 0; i < board.size(); i++)
    for (int j = 0; j < board[0].size(); j++)
      if (id18(board, i, j, word))
        return true;
  return false;
}



int id15(string const &s)
{
  int n = s.size();

  const int uber = 31;
  const int id12 = 1e9 + 9;
  vector<ll> p_pow(n);
  p_pow[0] = 1;
  for (int i = 1; i < n; i++)
    p_pow[i] = (p_pow[i - 1] * uber) % id12;

  vector<ll> h(n + 1, 0);
  for (int i = 0; i < n; i++)
    h[i + 1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % id12;
  int bah = 0;
  for (int l = 1; l <= n; l++)
  {
    set<ll> hs;
    for (int i = 0; i <= n - l; i++)
    {
      ll cur_h = (h[i + l] + id12 - h[i]) % id12;
      cur_h = (cur_h * p_pow[n - i - 1]) % id12;
      hs.insert(cur_h);
    }
    bah += hs.size();
  }
  return bah;
}
ll power(ll x, ll y)
{
  if (y == 0)
  {
    return 1;
  }
  ll small = power(x, y / 2);
  small = (small * small) % mod;
  if (y % 2)
    small = (x * small) % mod;
  return small;
}

void id19()
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
void depth(vector<vector<int>> &graph, int des = 0)
{
  google.push_back(des);
  if (des == target)
    hum.push_back(google);
  else
  {
    for (int node : graph[des])
      depth(graph, node);
  }
  google.pop_back();
}
































































































class Solution
{
public:
  int kthmissing(vector<int> &v, int id1)
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
      if (bah == id1)
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

void id6(vector<int> &a, int lo, int hi)
{
  if (lo < hi)
  {
    int piv = partition(a, lo, hi);
    id6(a, lo, piv - 1);
    id6(a, piv + 1, hi);
  }
}

int id17(int n)
{
  int dig = 0;
  while (n)
  {
    dig++;
    n /= 10;
  }
  return dig;
}

void id14(int n, int k)
{
}

void problem3()
{
  ll n, k;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  set<ll> st;
  for (auto it : a)
    st.insert(it);
  if (st.size() == 0)
  {
    cout << 0 << endl;
    return;
  }
  if (is_sorted(a.begin(), a.end()))
  {
    cout << 1 << endl;
    return;
  }
  int cnt = 0;
  f(i, 1, n - 1)
  {
    cnt += (a[i - 1] > a[i] && a[i + 1] > a[i]);
    cnt += (a[i - 1] < a[i] && a[i + 1] < a[i]);
  }
  cout << cnt << endl;
}

void id13()
{
  ll n, r, c, sr, sc;
  cin >> n >> r >> c >> sr >> sc;
  string s;
  cin >> s;
  char grid[r][c];
  bool vis[r][c];

  f(i, 0, r)
  {
    f(j, 0, c)
    {
      vis[i][j] = false;
    }
  }

  f(i, 0, r)
  {
    f(j, 0, c)
    {
      grid[i][j] = '0';
    }
  }
  grid[sr][sc] = '1';
  int res1 = sr, res2 = sc;
  
  int me = -1, mw = -1, mn = -1, ms = -1;
  int ce = 0, cw = 0, cn = 0, cs = 0;
  f(i, 0, n)
  {
    if (s[i] == 'E')
    {
      ce++;
      sc++;
    }
    else
    {
      me = max(ce, me);
      ce = 0;
    }
    if (s[i] == 'W')
    {
      cw++;
      sc--;
    }
    else
    {
      mw = max(cw, mw);
      cw = 0;
    }
    if (s[i] == 'N')
    {
      cn++;
      sr--;
    }
    else
    {
      mn = max(cn, mn);
      cn = 0;
    }
    if (s[i] == 'S')
    {
      sr++;
      cs++;
    }
    else
    {
      ms = max(cs, ms);
      cs = 0;
    }
  }
  cout << sr << " " << sc << endl;
}

void CEO()
{
  int r, c;
  cin >> r >> c;
  vector<string> vec;
  for (int i = 0; i < r; i++)
  {
    string s;
    cin >> s;
    vec.push_back(s);
  }
  bool check = 1;
  if (r == 1)
  {
    for (int i = 0; i < c; i++)
    {
      if (vec[0][i] == '^')
        check = 0;
    }
  }
  if (c == 1)
  {
    for (int i = 0; i < c; i++)
    {
      if (vec[i][0] == '^')
        check = 0;
    }
  }
  if (check)
  {
    cout << "Possible" << endl;
    if (r == 1 || c == 1)
    {
      for (int i = 0; i < r; i++)
      {
        cout << vec[i] << endl;
      }
    }
    else
    {
      for (int i = 0; i < r; i++)
      {
        for (int j = 0; j < c; j++)
        {
          cout << '^';
        }
        cout << endl;
      }
    }
  }
  else
  {
    cout << "Impossible" << endl;
  }
}

void getIndex(vector<int> v, int K)
{
  auto it = find(v.begin(), v.end(), K);

  if (it != v.end())
  {
    int index = it - v.begin();
    cout << index << endl;
  }
  else
  {
    cout << "-1" << endl;
  }
}

bool id16(char ch)
{
  if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y')
    return true;
  return false;
}

bool isupper(char ch)
{
  return ch >= 'A' && ch <= 'Z';
}

ll id20(vector<ll> a, ll n) 



{
  ll cnt[n] = {0}, sum = 0;
  f(i, 0, n) sum += a[i];
  if (sum % 3 != 0)
    return 0;
  sum /= 3;
  ll ss = 0;
  for (ll i = n - 1; i >= 0; i--)
  {
    ss += a[i];
    if (ss == sum)
      cnt[i] = 1;
  }
  for (ll i = n - 2; i >= 0; i--)
    cnt[i] += cnt[i + 1];
  ll ans = 0;
  ss = 0;
  for (ll i = 0; i + 2 < n; i++)
  {
    ss += a[i];
    if (ss == sum)
      ans += cnt[i + 2];
  }
  return ans;
}


































































































































void id9()
{
ll n;
cin>>n;
vll a(n);
f(i, 0, n) cin>>a[i];
vector<int> dp(n+1, 0);
 for (int i = n - 1 ; i >= 0 ; i--) {
    dp[i] = a[i];
    int j = i + a[i];
    if (j < n) {
      dp[i] += dp[j];
    }
}
  cout << *max_element(dp.begin(), dp.end()) << endl;
}
main()
{
  ll t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    

    id9();
    

  }
}