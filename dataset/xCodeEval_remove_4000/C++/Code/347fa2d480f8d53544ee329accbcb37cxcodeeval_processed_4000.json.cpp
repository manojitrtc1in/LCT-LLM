


using namespace std;



void __print(int x)
{
    cerr << x;
}
void __print(long x) { cerr << x; }


void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}


    cerr << "[" << 
    _print(x)













    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);










    int test_case;    \
    cin >> test_case; \
    while (test_case--)








typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef map<int, int> mi;

int Power(int n, int x, int mod)
{
    int ans = 1;
    while (x > 0)
    {
        if (x & 1)
            ans = (ans * n) % mod;
        n = (n * n) % mod;
        x = x >> 1;
    }
    return ans;
}

bool id2(const pair<int, int> &a,
               const pair<int, int> &b)
{
    return (a.second < b.second);
}

bool isPrime(int n)
{
    

    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    

    

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

int getSum(int n)
{
    int sum = 0;
    while (n != 0)
    {
        sum = sum + n % 10;
        n = n / 10;
    }
    return sum;
}
int myceil(int n, int x)
{
    int y;
    if (n % x == 0)
    {
        y = n / x;
        return y;
    }
    else
    {
        y = n / x + 1;
        return y;
    }
}
int id3(int arr[], int n)
{
    

    unordered_map<int, int> M;

    

    

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            M[(arr[i] + arr[j])]++;

    int max_count = 0;

    

    for (auto ele : M)
        if (max_count < ele.second)
            max_count = ele.second;

    return max_count;
}

int myfloor(int num,int den)
{
if ((num >= 0 and den > 0) or ( num <= 0 and den < 0))
    return num%den == 0 ? num/den : num/den;
int ans = num / den;
return num % den == 0 ? ans : ans - 1;
}

int md = 1e9+7;
vi fact, inv;

void inverse(ll n)
{
    if (n >= inv.size())
    {
        ll size = inv.size();
        size = size == 0 ? 1 : size;
        inv.resize(n + 1);
        inv[0] = 1;
        for (ll i = size; i <= n; i++)
            inv[i] = Power(fact[i], md - 2, md);
    }
}

void factorial(ll n)
{
    if (n >= fact.size())
    {
        ll size = fact.size();
        size = size == 0 ? 1 : size;
        fact.resize(n + 1);
        fact[0] = 1;
        for (ll i = size; i <= n; i++)
            fact[i] = (fact[i - 1] * i) % md;
    }
}

ll ncr(ll n, ll r) { return (((fact[n] * inv[r]) % md) * inv[n - r]) % md; }

bool id0(const pair<int, int> &a,
                   const pair<int, int> &b)
{
    return a.second > b.second;
}












int SZ(string &v) { return v.length(); }
template <typename C>
int SZ(C &v) { return v.size(); }
template <typename C>
void UNIQUE(vector<C> &v)
{
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
}
template <typename T, typename U>
void maxa(T &a, U b) { a = max(a, b); }
template <typename T, typename U>
void mina(T &a, U b) { a = min(a, b); }
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;



void id1()
{     
    int n;
    cin>>n;
    vi a(n);
    mi mp;
    const int mod=998244353;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        mp[a[i]]++;
    }
    if(n==1)
    {
        if(mp[0]==0 && mp[1]==0)
        {
            cout<<0<<endl;
        }
        else
        {
            cout<<1<<endl;
        }
        return;
    }
    int ans=0;
    if(mp[1]>=1)
    {
        ans+=Power(2,mp[1],mod)-1;
    }
    if(mp[0]>=1)
    {
        int start=-1;
        vi v;
        for(int i=0;i<n;i++)
        {
            if(a[i]==0)
            {
                v.pb(i);
            }
        }
        for(auto x : v)
        {
            start=x;
            int i=start+1,cnt=0;
            while(i<n && a[i]==0)
            {
                cnt++;
            }
            int prev=0;
            

            while(i<n && a[i]==2)
            {
                cnt++;
                i++;
            }
            ans+=Power(2,cnt,mod)-1;
            cnt=0;
            while(i<n && (a[i]==prev || a[i]==prev+1))
            {
                cnt++;
                prev=a[i];
                i++;
            }
            while(i<n && a[i]==prev+2)
            {
                cnt++;
                i++;
            }
            ans+=Power(2,cnt,mod)-1;
        }
    }
    cout<<ans<<endl;
}

void q1()
{
    int n,k;
    cin>>n>>k;
    vi a(n);
    int sum=0;
    int mn=INT_MAX;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        sum+=a[i];
        mn=min(mn,a[i]);
    }
    if(sum<=k)
    {
        cout<<0<<endl;
        return;
    }
    sort(all(a));
    if(n==1)
    {
        cout<<sum-k<<endl;
        return;
    }
    

    

    

    

    

    

    

    

    

    

    

    

    else
    {
        debug(a);
        

        int ans=INT_MAX,cnt=1;
        for (int i = n-1; i>=1; i--)
        {
            sum-=(a[i]-mn);
            if(sum<=k)
            {
                ans=min(ans,n-i);
            }
        }
        sum=0;
        for (int i = 0; i < n; i++)
        {
            sum+=a[i];
        }
        sum-=a[0];
        int x=myfloor(k-sum,cnt);
        ans=min(ans,cnt-1+a[0]-x);
        debug(x,ans);
        for (int i = n-1; i >=1; i--)
        {
            sum-=a[i];
            cnt++;
            x=myfloor(k-sum,cnt);
            if(a[0]-x<0) ans=min(ans,cnt-1);
            else ans=min(ans,cnt-1+a[0]-x);
            debug(x,ans,i,sum,cnt);
        }
        cout<<ans<<endl;
        return;
    }   
}

void q2()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,x;
        cin>>n>>k>>x;
        string s;
        cin>>s;
        

        

        

        

        

        vi a;
        int cnt=0;
        for (int i = 0; i < n-1; i++)
        {
            if(s[i]=='*' && s[i+1]=='*')
            {
                cnt++;
            }
            else if(s[i]=='*' && s[i+1]!='*')
            {
                cnt++;
                a.pb(cnt);
                cnt=0;
            }
        }
        if(s[n-1]=='*')
        {
            a.pb(cnt+1);
        }
        

        int sum=x;
        string ans;
        x=sz(a);
        vi pref(x);
        for (int i = x-1; i >=0; i--)
        {
            a[i]=(k*a[i])+1;
            if(i+1<x)
            {
                pref[i]=a[i]*pref[i+1];
            }
            else
            {
                pref[i]=a[i];
            }
            
        }
        debug(pref);
        int y=-1;
        int i=x-1;
        while(i>=0)
        {
            if(sum<=pref[i])
            {
                debug(i);
                if(i+1==x)
                {
                    a[i]=sum;
                    i--;
                    while(i>=0)
                    {
                        a[i]=0;
                        i--;
                    }
                    break;
                }
                else
                {
                    if(sum%pref[i+1]==0)
                    {
                        a[i]=sum/pref[i+1];
                        i--;
                        while(i>=0)
                        {
                            a[i]=0;
                            i--;
                        }
                        break;
                    }
                    else
                    {
                        y=(sum/pref[i+1]);
                        sum-=y*pref[i+1];
                        a[i]=y+1;
                        debug(i,a[i]);
                        int j=i-1;
                        while(j>=0)
                        {
                            a[j]=0;
                            j--;
                        }
                        i++;
                        break;
                    }
                    
                } 
            }
            i--;
        }
        if(y!=-1)
        {
            while(i<x-1 && sum>0)
            {
                if(sum%pref[i+1]==0)
                {
                    y=(sum/pref[i+1]);
                    sum-=y*pref[i+1];
                    a[i]=y;
                    debug(i,a[i]);
                    i++;
                    break;
                }
                else
                {
                    y=(sum/pref[i+1]);
                    sum-=y*pref[i+1];
                    a[i]=y+1;
                    debug(i,a[i]);
                    i++;
                }
            }
            if(sum>0)
            {
                a[i]=sum;
                

                i++;
                while(i<=x-1)
                {
                    a[i]=0;
                    i++;
                }
            }
        }
        debug(a);
        cnt=0;
        for (int i = 0; i < n-1; i++)
        {
            if(s[i]=='*' && s[i+1]!='*')
            {
                for (int j = 1; j <= a[cnt]-1; j++)
                {
                    ans+='b';
                }
                cnt++;
            }
            else if(s[i]!='*')
            {
                ans+=s[i];
            }
        }
        if(s[n-1]!='*')
        {
            ans+=s[n-1];
        }
        else
        {
            for (int j = 1; j <= a[cnt]-1; j++)
            {
                ans+='b';
            }
        } 
        cout<<ans<<endl;
    }
}

void q3()
{
    int n;
    cin>>n;
    vi l(n),r(n),c(n);
    for (int i = 0; i < n; i++)
    {
        cin>>l[i]>>r[i]>>c[i];
    }
    vi ans(n);
    map<int,set<int>>mp,mp2;
    int left=0,right=0;
    for (int i = 0; i < n; i++)
    {
        if(left==0 && right==0)
        {
            left=l[i];
            right=r[i];
            ans[i]=c[i];
            mp[r[i]].insert(c[i]);
        }
        else
        {
            if(l[i]>=right && l[i]<r[i]) 
            {
                ans[i]=ans[i-1]+c[i];
                right=r[i];
                mp[r[i]].insert(c[i]);
            }
            else if(l[i]==right && l[i]==r[i])
            {
                ans[i]=(ans[i-1]);
            }
            else if(l[i]==left && r[i]==right)
            {
                ans[i]=min(ans[i-1],c[i]);
                mp[r[i]].insert(c[i]);
            }
            else if(l[i]<right && l[i]>left)
            {
                if(r[i]<=right)
                {
                    auto it=mp.lower_bound(l[i]-1);
                    auto it2=(*it).S.begin();
                    ans[i]=(ans[i-1]-*it2+c[i]);
                    right=r[i];
                    mp[r[i]].insert(c[i]);
                }
                else
                {
                    auto it=mp.lower_bound(l[i]-1);
                    auto it2=(*it).S.begin();
                    ans[i]=(*it2+c[i]);
                    right=r[i];
                    mp[r[i]].insert(c[i]);
                }
            }
            else if(l[i]==left)
            {
                if(r[i]<right)
                {
                    ans[i]=(ans[i-1]);
                    auto it=mp2.lower_bound(r[i]+1);
                    auto it2=(*it).S.begin();
                    ans[i]=min(ans[i],ans[i]-*it2);
                }
                else
                {
                    right=r[i];
                    ans[i]=c[i];
                    mp[r[i]].insert(c[i]);
                }
                
            }
            else if(l[i]<left)
            {
                if(r[i]<=right)
                {
                    ans[i]=(ans[i-1]+c[i]);
                    left=l[i];
                }
                else
                {
                    ans[i]=c[i];
                    left=l[i];
                    right=r[i];
                    mp[r[i]].insert(c[i]);
                }
            }
        }
        mp2[l[i]].insert(c[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout<<ans[i]<<endl;
    }

}

void q4()
{      
    int n;
    cin>>n;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    sort(all(a));
    
}

int32_t main()
{
    fast();
    int t1;
    cin>>t1;
    for(int j=1;j<=t1;j++)
    {
        

        

        

        

        

        

        

        

        

        

        

            

        

        

        

        

        

        q1();
        

        

        

    }
    return 0;
}




