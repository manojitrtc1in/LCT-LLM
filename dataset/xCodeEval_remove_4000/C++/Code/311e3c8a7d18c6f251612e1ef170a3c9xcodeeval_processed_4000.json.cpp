















using namespace std;

const int id6 = 256;
ll countDigit(ll n)
{
    return floor(log10(n) + 1);
}
ll ipow(ll base, ll exp)
{
    ll result = 1;
    for (;;)
    {
        if (exp & 1)
            result= (result*base)%mod;
        exp >>= 1;
        if (!exp)
            break;
        base= (base*base)%mod;
    }

    return result;
}
ll poweri(ll x,ll y)
{  ll p=1000000007;
    ll res = 1;

    x = x % p;
    if (x == 0) return 0;

    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

ll divi(ll n)
{  ll r;
     if(n%2==0)
     {
         return 2;
     }
     if(n%3==0)
     {
         return 3;
     }
     

    else
{   r=floor(sqrt(n));
    ll d=5;
    while ((n%d) && (d<n/d)) d+=2;
    if(n%d==0)
        return d;
    else
       return n;
}
}

int id3(int a[], int size)
{
    int id5 = INT_MIN, id1 = 0,
       start =0, end = 0, s=0;

    for (int i=0; i< size; i++ )
    {
        id1 += a[i];

        if (id5 < id1)
        {
            id5 = id1;
            start = s;
            end = i;
        }

        if (id1 < 0)
        {
            id1 = 0;
            s = i + 1;
        }
    }
        cout<< id5 << endl;
    cout << "Starting index "<< start
        << endl << "Ending index "<< end << endl;
}

string evenlength(string n)
{
    string res = n;
    for (int j = n.length() - 1; j >= 0; --j)
        res += n[j];

    return res;
}
ll id4(vec arr, ll n)
{

    sort(arr.begin(), arr.end());
    ll max_count = 1, res = arr[0], curr_count = 1;
    for (ll i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1])
            curr_count++;
        else {
            if (curr_count > max_count) {
                max_count = curr_count;
                res = arr[i - 1];
            }
            curr_count = 1;
        }
    }

    if (curr_count > max_count)
    {
        max_count = curr_count;
        res = arr[n - 1];
    }

    return res;
}
bool ck(int N)
    {
        if ((sqrt(N) - floor(sqrt(N))) != 0)
            return false;
        return true;
    }
 ll gcs(ll N)
    {
        if (ck(N))
        {

            return N;
        }
        ll aboveN = -1, belowN = -1;
        ll n1;
        n1 = N + 1;
        while (true) {
            if (ck(n1)) {
                aboveN = n1;
                break;
            }
            else
                n1++;
        }


  return aboveN;

}
bool is_prime(ll n) {
    if (n == 1) {
        return false;
    }
    ll i = 2;
    while (i*i <= n) {
        if (n % i == 0) {
            return false;
        }
        i += 1;
    }
    return true;
}
ll id11(ll n)
{
    vector<int> least_prime(n+1, 0);
    least_prime[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        if (least_prime[i] == 0)
        {
            least_prime[i] = i;

            for (int j = 2*i; j <= n; j += i)
                if (least_prime[j] == 0)
                   least_prime[j] = i;
        }
    }

   return least_prime[n];
}
ll id10(ll n)
{
    if (n % 2 == 0)
        return 2;
    for (ll i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return i;
    }

    return n;
}
ll countDistinct(ll arr[], ll n)
{
    unordered_set<int> s;
    ll res = 0;
    for (ll i = 0; i < n; i++) {
        if (s.find(arr[i]) == s.end()) {
            s.insert(arr[i]);
            res++;
        }
    }

    return res;
}
void countFreq(ll arr[], ll n)
{   vec v;
    vector<bool> visited(n, false);
    for (ll i = 0; i < n; i++) {
        if (visited[i] == true)
            continue;

        ll c = 1;
        for (ll j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                visited[j] = true;
                c++;
            }
        }
       v.push_back(c);
    }
    ll f=0;
    f(i,0,v.size())
    {  cout<<v[i]<<" ";
        if(v[i]<3)
        {
            f=1;
        }
    }

    if(f==1)
    {
        cout<<"No"<<endl;
    }
    else
    {
    cout<<"Yes"<<endl;
    }
}
ll mcm(ll p[], ll n)
{
    ll m[n][n];

    ll  j, k, q;
    f(i,1,n)
        {
            m[i][i] = 0;
        }
    f(L,2,n)
    {
        f(i,1,n - L + 1)
        {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++)
            {
                q = m[i][k] + m[k + 1][j] +
                    p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    return m[1][n - 1];
}
ll lis(ll a[],ll n)
{
    int lis[n];
    lis[0]=1;
    for(int i=1;i<n;i++)
    {  lis[i]=1;
        for(int j=0;j<i;j++)
        {
            if(a[i]>=a[j] && lis[i]<lis[j]+1)
            {
                lis[i]=lis[j]+1;
            }
        }
    }

     sort(lis,lis+n);

}
bool id2(long double x)
{
  long double sr = sqrt(x);
  return ((sr - floor(sr)) == 0);
}
ll id9(string str)
{
    int n = str.length();
    int dist_count = 0;
    bool visited[id6] = { false };
    for (int i = 0; i < n; i++) {
        if (visited[str[i]] == false) {
            visited[str[i]] = true;
            dist_count++;
        }
    }
    int start = 0, start_index = -1, min_len = INT_MAX;

    int c = 0;
    int curr_count[id6] = { 0 };
    for (int j = 0; j < n; j++) {
        curr_count[str[j]]++;
        if (curr_count[str[j]] == 1)
            c++;
        if (c == dist_count) {
            while (curr_count[str[start]] > 1) {
                if (curr_count[str[start]] > 1)
                    curr_count[str[start]]--;
                start++;
            }
            int len_window = j - start + 1;
            if (min_len > len_window) {
                min_len = len_window;
                start_index = start;
            }
        }
    }
    return str.substr(start_index, min_len).length();
}
int bs(ll arr[], ll l, ll r, ll x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == x)
            return m;
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}
void cutrod(int n,int a[],int s)
{

        int i;

	   

	    int dp[n+1] ;
	    for(i=0;i<n+1;i++){
	        dp[i] = INT_MIN ;
	    }
	    dp[0] = 0 ;
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=0;j<s;j++)
	            if(a[j]<=i)
	                dp[i]=max(dp[i],dp[i-a[j]]+1);
	    }
	    cout << dp[n] << endl ;
}

ll solve(ll n,ll k, ll a[])
{
     omap m;
    ll mat[n][n]={0};
        f(i,0,n)
        {
            m.clear();
            f(j,i,n)
            {  if(j==0)
                  {
                     mat[i][j]=0;
                  }
                else
                {
                    mat[i][j]=mat[i][j-1];
                }
                if(m.count(a[j]))
                {if(m[a[j]]==1)
                    {
                         mat[i][j]++;
                    }mat[i][j]++;
                }m[a[j]]++;
            }
        }
ll s=INT_MAX,c=100, dp[101][1001]={0};
    f(i,0,n+1)
        {
            dp[1][i]=mat[0][i-1];
        }
   f(i,2,c+1)
    {
        dp[i][1]=0;
    }
    f(i,2,c+1)
    {
        f(j,2,n+1)
        {
            ll x=1e18;
            f(p,1,j)
            {
                x=min(x,dp[i-1][p]+mat[p][j-1]);
            }
            dp[i][j]=x;
        }
    }
    f(c,1,101)
    {
        s=min(c*k+dp[c][n],s);
    }
    return s;
}
bool ckpal(string s,ll n)
{
    for(ll i=0;i <n ;i++){
        if(s[i] != s[n-i-1]){
            return false;
            break;}


          }
          return true;
    }
    bool is_reverse(string s1,string s2, ll m)
{
    ll l1 = m;
    ll l2 = m;
    ll index =0;
    if (index > l1-1)
        return true;

    if (l1 != l2 || s1[index] != s2[l2-index-1])
        return false;

    ++index;
    return is_reverse(s1, s2,index);
}


ull ceil(ull n,ull i){
    if(n==0)
        return 0;
    return (n-1)/i+1;
}
ll id7(ll n)
{
    ll s=0;
    while(n!=0)
    {
        s+=n%10;
        n/=10;
    }
    return s;
}
ll mio(vec v,ll n)
{   ll c=0;
    f(i,0,n)
    {
        if(v[i]!=-1)
        {
            c++;
        }
    }
    return c;
}
int c( int n )
{  int m=3;
   int S[2]={1,2};
    int table[n+1];
    memset(table, 0, sizeof(table));
    table[0] = 1;
    for(int i=0; i<m; i++)
        for(int j=S[i]; j<=n; j++)
            table[j] += table[j-S[i]];

    return table[n];
}

ll maxHist(ll row[],ll C)
{
    stack<ll> result;
    ll top_val;
    ll max_area = 0;
    ll area = 0;
    ll i = 0;
    while (i < C) {
        if (result.empty() || row[result.top()] <= row[i])
            result.push(i++);

        else {
            top_val = row[result.top()];
            result.pop();
            area = top_val * i;

            if (!result.empty())
                area = top_val * (i - result.top() - 1);
            max_area = max(area, max_area);
        }
    }
    while (!result.empty()) {
        top_val = row[result.top()];
        result.pop();
        area = top_val * i;
        if (!result.empty())
            area = top_val * (i - result.top() - 1);

        max_area = max(area, max_area);
    }
    return max_area;
}

ll binarySearch( ll arr[] , ll x , ll low , ll high )
{
    ll mid;
    while( low < high ) {
        mid = ( high + low ) / 2;
        if( arr[mid]== x ) {
            break;
        }
        else if( arr[mid] > x ) {
            high=mid-1;
        }
        else {
            low= mid+1;
        }
    }
    mid = ( high + low ) / 2;
    if (x>=arr[mid])
        return mid;
    else
        return mid+1;
}
bool solve()
{
    ll n;
    cin>>n;
    ll a[n];
    f(i,0,n)
    {
        cin>>a[i];
    }
    if(n==1)
    {
        return true;
    }
    else{
        ll i=0;
        while(1)
        {
            if(a[i]<a[i+1])
            {
                i++;
            }
            else if(a[i]==a[i+1] && a[i]!=0 && a[i-1]!=a[i]-1)
            {
                a[i]--;
                i++;
                break;
            }
            else
            {
                break;
            }
        }
        while (i<n-1)
        {
            if(a[i]<=0)
            {
                return false;
            }
            if(a[i]<=a[i+1])
            {
                a[i+1]=a[i]-1;
                i++;
            }
            else
            {
                i++;
            }
        }
       return true;
    }


}
int cpk(ll n)
{
    for(ll i=sqrt(n);i>=2;i--)
    {
        if(n%(i*i)==0)
        {
            return 0;
        }
    }
    return 1;
}
ll slv(ll c)
{
    ll s=0;
     if(c%4==0)
            {
                s+=6+1;
            }
             if(c%4==1)
            {
                s+=2+3;
            }
             if(c%4==2)
            {
                s+=4+9;
            }
             if(c%4==3)
            {
                s+=8+7;
            }
            return s;
}
ll getSum(ll n)
    {
    ll sum = 0;
    while (n != 0)
    {
     sum = sum + n % 10;
     n = n/10;
    }
 return sum;
 }


bool comp(ll a,ll b)
{
    if((a+b)%2==1 && a>b)
    {
        return true;
    }
    return false;
}
ll lcm(ll a, ll b)
   {

return a / __gcd(a, b) * b;
   }
int lis(int arr[], int n )
{
    int lis[n];

    lis[0] = 1;
    for (int i = 1; i < n; i++ )
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++ )
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
    }

    

    return *max_element(lis, lis+n);
}
ll prn(ll n)
{
    f(i,1,n/2 +1)
        {
            f(j,1,n/2 +1)
            {
                ll x=__gcd(i,j);
                if(x+(i*j)/x==n)
                {
                    cout<<i<<" "<<j<<endl;
                    return 0;
                }
            }
        }
}
ll get(ll x)
{
    long double p=sqrtl(1ul+4*(x));
    p=p-1.0;
    p=p/2.0;
    ll r=p;
    return r;
}
struct pair1{
  int edge;
  double time;
  pair1(int c,double t)
  {
      edge=c;
      time=t;
  }
};
int bfs(vector<vector<pair1>> & adjency,unordered_map<int,int> & visited,queue<pair1> &Q)
{
    int count1=0;
    while(!Q.empty())
    {
        pair1 x=Q.front();
        Q.pop();
        for(int j=0;j<adjency[x.edge].size();j++)
            if(visited.count(adjency[x.edge][j].edge)==0)
           {
             if(x.time<(adjency[x.edge][j].time))
             {
                 visited[adjency[x.edge][j].edge]++;
                 Q.push(adjency[x.edge][j]);
                 count1++;
             }
           }
    }
    return count1;
}
int maxn=16;
vector<int> precompute()
{
    vector<int> dp(maxn, -1);
    dp[0] = 0;

    for (int i = 1; i < maxn; ++i) {
        for (auto j : vector<int>{ 4, 6, 9 }) {
            if (i >= j && dp[i - j] != -1) {
                dp[i] = max(dp[i], dp[i - j] + 1);
            }
        }
    }

    return dp;
}
int id0(vector<int> dp, int n)
{
    if (n < maxn)
        return dp[n];

    else {
        int t = (n - maxn) / 4 + 1;
        return t + dp[n - 4 * t];
    }
}
bool id8(string str1, string str2)
{

   if (str1.length() != str2.length())
        return false;

   string temp = str1 + str1;
  return (temp.find(str2) != string::npos);
}
ll yup(ll n)
{
    f(i,2,sqrt(n)+1)
    {
        if(n%i==0)
        {
            return i;
        }
    }

}
void printd(char a[],ll n)
{
    if(n==1)
    {
        cout<<a[0];
        return ;
    }
    cout<<a[n-1];
    printd(a,n-1);
}
ll apartment(ll n)
{
    f(i,0,n/3 +1)
    {
        f(j,0,n/5 +1)
        {
            ll p=(n-i*3 - j*5);
            if(p%7 ==0)
            {
                cout<<i<<" "<<j<<" "<<p/7<<endl;
                return 0;
            }
        }
    }
    cout<<-1<<endl;
    return 0;
}
char a[300005];
ll n;
void solve2()
{
     ll p,c=0,m=0,z=0;

            int x=0;
            f(i,0,n){
              if(a[i]=='-'){
                c++;
              }
            }
            if(c==0){x=0;}
           else x=c+1;
            for(int i=0;i<n;i++){
              if(a[i]=='>' || a[i]=='-'){
                m++;
              }
            }
          f(i,0,n)
            {
              if(a[i]=='<' || a[i]=='-'){
                z++;
              }
            }
            if(z==n ||  m==n){
              x=n;
            }



          cout<<x<<endl;
}

int main()
{ ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

int t;
cin>>t;


while(t--)
    {
        string s;
        ll n;
        cin>>n;
        cin>>s;
        ll a=0,b=0,c=0;
        f(i,0,n)
        {
            if(s[i]=='-')
            {
                a++;
            }
            else if(s[i]=='>')
            {
                b++;
            }
            else if(s[i]=='<')
            {
                c++;
            }

        }
        if(a==n || b==n || c==n ||(a+b)==n || (a+c)==n)
        {
            cout<<n<<endl;
        }
        else if(b+c==n)
        {
            cout<<0<<endl;
        }
        else
        {  ll vis[n]={0};
            f(i,0,n)
            {

                if(s[i]=='-')
                {
                    vis[i]=1;
                    vis[(i+1)%n]=1;
                }
            }

            ll x=0;
            f(i,0,n)
            {
                x+=vis[i];
            }
            cout<<x<<endl;
        }

	}


    return 0;
}

