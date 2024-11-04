









using namespace std;
void fd()
{
    int n, k;
    cin >> n >> k;
    int coun = 0;
    multiset<ll> mset;
    multiset<ll>::iterator x, y;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mset.insert(x % k);
    }

    while ((!mset.empty()))
    {

        x = mset.begin();

        int val = *x;
        mset.erase(x);
        if (val == 0)
        {
            y = mset.find(0);
        }
        else
        {
            y = mset.find(k - val);
        }
        if (y != mset.end())
        {
            coun++;
            mset.erase(y);
        }
    }
}
void for_map()
{
    int maxx;
    map<long double, int> mp;
    map<long double, int>::iterator itr;
    for (itr = mp.begin(); itr != mp.end(); ++itr)
    {
        

        maxx = max(maxx, (itr->second));
    }
}
void two_pointer()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int i = 0, j = 0;
    int coun = 1;
    int maxx = 1;
    while (true)
    {

        if (j == n - 1)
            break;
        

        if (a[j + 1] - a[i] <= 5)
        {
            coun++;
            j++;
        }
        else if (i == j && a[j + 1] - a[i] > 5)
        {
            i++;
            j++;
        }
        else
        {
            i++;
            coun--;
        }
        maxx = max(maxx, coun);
        if (j == n - 1)
            break;
    }

    cout << maxx;
}
void sort(vector<int> &v, int M)
{
    int n = v.size();
    if (M == 0)
        return;
    multiset<int> mset;
    multiset<int>::iterator itr;
    for (int i = 0; i < n; i++)
    {
        mset.insert(v[i]);
    }
    itr = mset.begin();
    int i = 0;
    while (itr != mset.end())

    {

        v[i] = (*itr);
        itr++;
        i++;
    }
}
int kkk()
{

    int n;
    cin >> n;
    int a[n][n];
    int b[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> b[i][j];
        }
    }
    bool flag = true, flag2 = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != b[n - 1 - i][j])
                flag = false;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != b[i][n - 1 - j])
                flag2 = false;
        }
    }

    if (flag2 || flag)
        cout << "1";
    else
        cout << "0";
    return 0;
}

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        

        

        if (arr[mid] == x)
            return mid;

        

        

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        

        

        return binarySearch(arr, mid + 1, r, x);
    }

    

    

    return -1;
}

int id2(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        

        

        if (arr[mid] == x)
            return mid;

        

        

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        

        

        return binarySearch(arr, mid + 1, r, x);
    }

    

    

    return -1;
}

struct Triple
{
    int color[3];
};
ll gcd(ll a, ll b) 

{
    return b == 0 ? a : gcd(b, a % b);
}

int turn_off(int a[], int i, int n);
int id1(int a[], int i, int n);
int turn_on(int a[], int i, int n);

int id1(int a[], int i, int n)
{

    int coun = 0;
    for (i; i < n; i++)
    {
        coun += turn_off(a, i, n);
    }

    return coun;
}
int turn_on(int a[], int i, int n)
{
    if (i == n - 1)
    {
        if (a[i] == 0)
        {
            a[i] = 1;
            return 1;
        }
        return 0;
    }
    if (a[i] == 1)
    {
        return 0 + id1(a, i + 1, n);
    }
    a[i] = 1;
    return turn_on(a, i + 1, n) + 1 + id1(a, i + 2, n);
}
int turn_off(int a[], int i, int n)
{
    if (i == n - 1)
    {
        if (a[i] == 1)
        {
            a[i] = 0;
            return 1;
        }
        return 0;
    }
    if (a[i] == 0)
    {
        return 0;
    }
    a[i] = 0;

    return 1 + turn_on(a, i + 1, n) + id1(a, i + 2, n);
}
int counter = 0;
int gggg()
{

    int n;
    string s;

    cin >> s;
    n = s.length();
    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = s[i] - '0';
    }

    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            if (a[i] == 0)
                counter += 0;
            else
                counter++;
        }
        else
        {

            if (a[i] == 0)
                counter += 0;
            else
                counter += turn_off(a, i, n);
        }
    }

    cout << counter;
}

int song[110][110];
int kk(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = 0;
    }
}

ld calculation(pair<ll, ll> a[], int n, ll x)
{

    ld sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].f <= x && a[i].s >= x)
            continue;
        sum += min(fabs(a[i].f - x), fabs(a[i].s - x));
    }
    return sum;
}
set<string> queee;
void fun(int n, int i, int num_op, int id5, string s2)
{
    if (i == 2 * n)
        queee.insert(s2);
    if (id5 < (n) && num_op > id5)
        fun(n, i + 1, num_op, id5 + 1, s2 + ')');
    if (num_op < (n))
        fun(n, i + 1, num_op + 1, id5, s2 + '(');
}
int cccc = 0;
bool id13(const pair<int, int> &a,
               const pair<int, int> &b)
{
    return (a.f - a.s < b.f - b.s);
}
bool id3(const pair<int, int> &a,
                const pair<int, int> &b)
{
    if ((a.f - a.s) == (b.f - b.s))
        return a.f < b.f;
    return (a.f - a.s < b.f - b.s);
}
bool vis[105][105];
bool arr[105][105];
int n, m;
bool cheek(int i, int j)
{
    if (i >= 0 && j >= 0 && i < n && j < m)
        return 1;
    return 0;
}
pair<pair<int, int>, pair<int, int> > funn(int i, int j, int lift, int right, int up, int down)
{
    int clift = n;
    int cright = -1;
    int cup = n;
    int cdown = -1;

    if (cheek(i + 1, j) && !vis[i + 1][j] && arr[i + 1][j])
    {
        vis[i + 1][j] = 1;
        pair<pair<int, int>, pair<int, int> > p = funn(i + 1, j, min(lift, j), max(right, j), min(up, i + 1), max(down, i + 1));
        clift = min(p.f.f, lift);
        cright = max(p.f.s, right);
        cup = min(p.s.f, up);
        cdown = max(p.s.s, down);
    }
    if (cheek(i - 1, j) && !vis[i - 1][j] && arr[i - 1][j])
    {
        vis[i - 1][j] = 1;
        pair<pair<int, int>, pair<int, int> > p = funn(i - 1, j, min(lift, j), max(right, j), min(up, i - 1), max(down, i - 1));
        clift = min(p.f.f, lift);
        cright = max(p.f.s, right);
        cup = min(p.s.f, up);
        cdown = max(p.s.s, down);
    }

    if (cheek(i, j + 1) && !vis[i][j + 1] && arr[i][j + 1])
    {
        vis[i][j + 1] = 1;
        pair<pair<int, int>, pair<int, int> > p = funn(i, j + 1, min(lift, j + 1), max(right, j + 1), min(up, i), max(down, i));
        clift = min(p.f.f, lift);
        cright = max(p.f.s, right);
        cup = min(p.s.f, up);
        cdown = max(p.s.s, down);
    }
    if (cheek(i, j - 1) && !vis[i][j - 1] && arr[i][j - 1])
    {
        vis[i][j - 1] = 1;
        pair<pair<int, int>, pair<int, int> > p = funn(i, j - 1, min(lift, j - 1), max(right, j - 1), min(up, i), max(down, i));
        clift = min(p.f.f, lift);
        cright = max(p.f.s, right);
        cup = min(p.s.f, up);
        cdown = max(p.s.s, down);
    }

    return make_pair(make_pair(lift, right), make_pair(up, down));
}


ll id11(ll n)
{
    

    ll minn = 1e10;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            

            if (n / i == i)
                printf("%d ", i);

            else
                

                printf("%d %lld ", i, n / i);
        }
    }
}






const long long MAX_SIZE = 1000001;











vector<long long> isprime(MAX_SIZE, true);
vector<long long> prime;
vector<long long> SPF(MAX_SIZE);



ll id12(ll N)
{
    

    isprime[0] = isprime[1] = false;

    

    for (long long int i = 2; i < N; i++)
    {
        

        

        if (isprime[i])
        {
            

            prime.push_back(i);
            if (N % i == 0)
                return i;

            

            

            SPF[i] = i;
        }

        

        

        

        

        

        

        for (long long int j = 0;
             j < (int)prime.size() &&
             i * prime[j] < N && prime[j] <= SPF[i];
             j++)
        {
            isprime[i * prime[j]] = false;

            

            SPF[i * prime[j]] = prime[j];
        }
    }
}

ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}


vector<int> id0(ll n)
{
    vector<int> dividors;
    ll i;
    for (i = 1; i * i < n; i++)
    {
        if (n % i == 0)
        {
            dividors.push_back(i);
            dividors.push_back(n / i);
        }
    }
    if (i * i == n)
        dividors.push_back(i);
    return dividors;
}



vector<int> factorize(ll n)
{
    vector<int> factors;
    for (ll i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
            factors.push_back(i), n /= i;
    }
    if (n > 1)
        factors.push_back(n);
    return factors;
}
vector<vector<int> > v(200005);
vector<int> d;
vector<bool> visited(2000005);
set<int> s;
queue<int> q;

void dfs(int node)
{
    visited[node] = 1;
    for (int i = 0; i < (int)v[node].size(); i++)
    {
        if (!visited[v[node][i]])
        { 

            dfs(v[node][i]);
        }
    }
}
void connected_components()

{
    int counter = 1, node;
    set<int>::iterator t = s.begin();
    while (t != s.end())
    {
        node = *t;
        if (visited[node] != 1)
        {
            counter++;
            dfs(node);
        }
        t++;
    }
    cout << " connected components=" << counter << endl;
}

vector<pair<int, int> > bfs(int node, int D)
{
    int fir_node = node;
    vector<pair<int, int> > ans;
    visited[node] = 1;
    int i = 0, x;
    q.push(node);

    while (!q.empty())
    {
        x = q.front();
        q.pop();

        visited[x] = 1;
        if (x != fir_node)
            for (int i = 0; i < (int)v[x].size(); i++)
            {
                if (!visited[v[x][i]])
                {
                    

                    ans.push_back(make_pair(x, v[x][i]));
                    q.push(v[x][i]);
                    visited[v[x][i]] = 1;
                }
            }
        else
        {
            for (int i = 0; i < D; i++)
            {
                if (!visited[v[x][i]])
                {
                    

                    ans.push_back(make_pair(x, v[x][i]));
                    q.push(v[x][i]);
                    visited[v[x][i]] = 1;
                }
            }
        }
    }
    return ans;
}



















































int solve(int num,std::vector<int> vv){
    vector<int>::iterator upper1;

 upper1 = upper_bound(vv.begin(),vv.end(),num);
 
 return  (upper1 - vv.begin()) - 1;
}
ll solve2(string s2,vector< string > vv){
    int n1,n2,d,a,m;
    ll minn = 1e9;
    for (int k=0;k<vv.size();k++){
        string s1 = vv[k];
        int i=0,j=0;
        while(j!= s2.length() && i != s1.length()){
            if (s1[i]==s2[j]){
                i++;
            }
            j++;
        }
        n1 = s1.length();
        n2 = s2.length();
        m = i;
        d = n2 - m;
        a = n1 - m;
        ll ans = a + d;
        minn = min(ans,minn);
    }
    return minn;
}
bool checkk(int i ,int j, int n , int m){
    return (i<m && i>=0 && j<n && j>=0);
}
void id6(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    

    

}

bool checkdp(int i , int j , int n , int m){
    return (i<n && i>=0 && j<m && j>=0);
}

int arry[2][100005];



int id8(int i,int j,int i2,int j2,int n,int m,bool ismax){
    


    int couna= 0;

    if ( (i2 == n-1 && j2 == m-1) || (i == n-1 && j == m-1 && !ismax)){
        return 0;
    }
    int x1,x2;
    if (ismax){
        x1=-1e9,x2=-1e9;
    }else{
        x1=1e9,x2=1e9;
    }
    if (ismax){ 

        if (checkdp(i2+1,j2,n,m)){
            x1 = ( (i == (i2 + 1) && j == j2) ? 0 : arry[i2 + 1][j2] ) + id8(i,j,i2+1,j2,n,m,false);
        }
        if (checkdp(i2,j2+1,n,m)){
            x2 = ( (i == i2 && j == (j2+1)) ? 0 : arry[i2][j2 + 1] ) + id8(i,j,i2,j2+1,n,m,false);
        }
    }else{ 

        if (checkdp(i+1,j,n,m)){
            x1 = id8(i+1,j,i2,j2,n,m,true);
        }
        if (checkdp(i,j+1,n,m)){
            x2 = id8(i,j+1,i2,j2,n,m,true);
        }
    }
    cout<<"x1="<<x1<<" ,i1="<<i2+1<<", j2="<<j2<<" "<<endl;
    cout<<"x2="<<x2<<" ,i1="<<i2<<", j2="<<j2+1<<" "<<endl;
    if (ismax){

        couna = max(x1,x2);
    }else{ 

        couna = min(x1,x2);
    }

    return couna;

}
int id9(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        

        

        if (arr[mid] == x)
            return mid;

        

        

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        

        

        return binarySearch(arr, mid + 1, r, x);
    }

    

    

    return -1;
}
bool id10(const pair<int, int> &a,
               const pair<int, int> &b)
{
    if (a.f == b.f){
        return (a.s>b.s);
    }
    return (a.f<b.f);
}
bool id4(const pair<ll, ll> &a,
               const pair<ll, ll> &b)
{
    ll x = (a.f)|(b.s);
    return (a.f <= x );
}
int main()
{
    

    ll t;
    cin>>t;
    while (t--)
    {
    ll n; cin>>n;
    ll a[n];
    ll b[n];
    ll minn = 1e16;
    ll prefixa=0,id7 = 0;
    for (int i=0;i<n;i++){
        cin>>a[i];
        prefixa += a[i];
    }
    for (int i=0;i<n;i++){
        cin>>b[i];
    }
    for (int i=0;i<n;i++){
        prefixa -=a[i];
        id7 += (i-1)>=0 ? b[i-1] : 0;
        minn = min(minn,max(prefixa,id7));
    }
    cout <<minn<<endl;
        
    }

    return 0;
}