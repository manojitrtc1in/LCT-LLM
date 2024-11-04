

using namespace std;










    int n;    \
    scanf("%d", &n)

    long long int n; \
    scanf("%lld", &n)









typedef __int64 ull;




    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
const long long Mod = 1e9 + 7;
typedef long long ll;
typedef long double ld;



typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vst;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll sum = 0, ans = 0, res = 0;



vector<string> id0(string s)
{
    s += ',';
    vector<string> res;
    while (!s.empty())
    {
        res.push_back(s.substr(0, s.find(',')));
        s = s.substr(s.find(',') + 1);
    }
    return res;
}
void debug_out(vector<string> __attribute__((unused)) args, __attribute__((unused)) int idx) { cerr << endl; }
void debug_out(
    vector<string> __attribute__((unused)) args,
    __attribute__((unused)) int idx,
    __attribute__((unused)) int LINE_NUM) { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T)
{
    if (idx > 0)
        cerr << ", ";
    else
        cerr << "Line(" << LINE_NUM << ") ";
    stringstream ss;
    ss << H;
    cerr << args[idx] << " = " << ss.str();
    debug_out(args, idx + 1, LINE_NUM, T...);
}

















template <int D, typename T>
struct Vec : public vector<Vec<D - 1, T>>
{
    static_assert(D >= 1, "Vector dimension must be greater than zero!");
    template <typename... Args>
    Vec(int n = 0, Args... args) : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...))
    {
    }
};
template <typename T>
struct Vec<1, T> : public vector<T>
{
    Vec(int n = 0, const T &val = T()) : vector<T>(n, val)
    {
    }
};

bool id1(const pair<int, int> &a,
               const pair<int, int> &b)
{
    if (a.se == b.se)
        return (a.fi < b.fi);

    return (a.se < b.se);
}




bool isPrime(ll num)
{
    bool flag = true;
    if (num == 1)
        return false;
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            flag = false;
            break;
        }
    }
    return flag;
}







ll findSum(ll a[], int l, int r)
{
    ll sum = 0;
    For(i, l, r)
    {
        sum += a[i];
    }
    return sum;
}







vector<pair<int, int>> vec1; 

void primeFactors(ll n)
{
    int c1 = 0;
    

    while (n % 2 == 0)
    {
        

        n = n / 2;
        c1++;
    }
    if (c1)
        vec1.pb(mp(2, c1));
    c1 = 0;
    

    

    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        c1 = 0;
        

        while (n % i == 0)
        {
            


            n = n / i;
            c1++;
        }
        if (c1)
            vec1.pb(mp(i, c1));
    }
    c1 = 0;
    

    

    if (n > 2)
        vec1.pb(mp(n, 1));
}






ll power(int x, unsigned int y)
{
    int temp;
    if (y == 0)
        return 1;
    temp = power(x, y / 2);
    if (y % 2 == 0)
        return temp * temp;
    else
        return x * temp * temp;
}



ll power(ll x, ll y, ll p)
{
    ll res = 1; 


    x = x % p; 

               


    if (x == 0)
        return 0; 


    while (y > 0)
    {
        

        if (y & 1)
            res = (res * x) % p;

        

        y = y >> 1; 

        x = (x * x) % p;
    }
    return res;
}




ull nCr(ll n, ll r)
{
    ull p = 1;
    ull k = 1;
    if (n - r < r)
        r = n - r;

    if (r != 0)
    {
        while (r)
        {
            p *= n;
            k *= r;
            ll m = __gcd(p, k);
            p /= m;
            k /= m; 

            n--;
            r--;
        }
    }
    else
        p = 1;

    return p;
}






ll lcm(ll a, ll b)
{
    return a / __gcd(a, b) * b;
}






unsigned int countBits(ll n, int specify)
{
    unsigned int count = 0, total = 0;
    if (n == 0)
    {
        if (specify == 1)
            return 0;
        else
            return 1;
    }
    while (n)
    {
        total += 1;
        count += n & 1;
        n >>= 1;
    }
    if (specify == 1)
        return count;
    else
        return (total - count);
}




















































































































































































































































































void scar(ll a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}




signed main()
{
    boost

    


    

    string aux1, aux2, aux3;

    ll T = 1;

    


    For(ZA, 1, T + 1)
    {

        int f = 0, fl1 = 0, fl2 = 0, u = 0, v = 0, w = 0, c1 = 0, c2 = 0, cont = 0, cnt = 0, c3 = 0, auxi = 0, auxj = 0;
        ll mi = INT_MAX;
        ll ma = INT_MIN, sol = 0;
        int n;
        cin>>n;
        string a,b;
        cin>>a>>b;
        int A=26;
        multiset<char> S,P,X;
        vector<pii> ans;
        

        

        

        

        

        

        

        

        

        

        

        

        vector<vector<int>> left(A);
        vector<int> wl;
        For(i,0, n) if (a[i] != '?')
            left[a[i] - 'a']
                .push_back(i);
        

        

        

        vector<vector<int>> right(A);
        vector<int> wr;
        For(i,0, n) if (b[i] != '?')
            right[b[i] - 'a']
                .push_back(i);
        

        vector<pair<int, int>> p;
        vector<int> cl(A), cr(A);
        For(i, 0,A)
        {
            For(j,0, min(left[i].size, right[i].size))
                ans.push_back(make_pair(left[i][j] + 1, right[i][j] + 1));
            

        }
        For(i,0,ans.size)
        {
            a[ans[i].fi-1]='~';
            b[ans[i].se-1]='~';
        }
        int q1=0,a1=0,q2=0,a2=0;
        vector<int> vec1,vec2,vec3,vec4;
        For(i,0,a.len)
        {
            if(a[i]=='?')
            {
                q1++;vec1.pb(i+1);
            }
            else if(a[i]!='~')
            {
                a1++;
                vec2.pb(i+1);
            }
            
        }
        For(i, 0, b.len)
        {
            if (b[i] == '?')
            {
                q2++;
                vec3.pb(i+1);
            }
            else if(b[i]!='~')
            {
                a2++;
                vec4.pb(i+1);
            }
        }
        debug(a,b);
        int v1,v2,v3,v4;
        v1=v2=v3=v4=0;
        if(q1>q2)
        {
            cont+=q1;
            if(a2>=q1)
            {
                a2-=q1;
                For(i,0,vec1.size)
                {
                    ans.pb(mp(vec1[i],vec4[i]));
                    v1++;v4++;

                }
            }
            else
            {
                For(i, 0, vec4.size)
                {
                    ans.pb(mp(vec1[i], vec4[i]));
                    v1++;v4++;
                    debug(vec4[i],vec1[i]);
                }
                q1-=a2;
                For(j,0,q1)
                {
                    ans.pb(mp(vec1[j + a2], vec3[j]));
                    v3++;v1++;
                    debug(vec3[j], vec1[j+a2]);
                }
                q2-=q1;
                a2 = 0;
            }
            
            q1=0;

        }
        else
        {
            cont += q2;
            if (a1 >= q2)
            {
                a1 -= q2;
                For(i, 0, vec3.size)
                {
                    ans.pb(mp(vec2[i], vec3[i]));
                            v2++;v3++;
                            debug(vec2[i], vec3[i]);
                }
            }
            else
            {
                q2-= a1;
                For(i, 0, vec2.size)
                {
                    ans.pb(mp(vec2[i], vec3[i]));
              v2++;v3++;
              debug(vec2[i], vec3[i]);
                }
                For(j,0,q2)
                {
                    ans.pb(mp(vec1[j], vec3[j + a1]));
                    v3++;
                    v1++;
                    debug(vec3[j + a1], vec1[j]);
                }
                q1 -= q2;
                a1=0;
            }
            q2 = 0;
        }
        if(q1>0)
        {
            cont+=min(a2,q1);
            For(i,0,min(a2,q1))
            {
                ans.pb(mp(vec1[i + v1], vec4[i + v4]));
                debug(vec4[i+v4], vec1[i+v1]);
            }
        }
        if(q2>0)
        {
            cont+=min(q2,a1);
            For(i, 0, min(a1, q2))
            {
                ans.pb(mp(vec2[i + v2], vec3[i + v3]));
                debug(vec3[i+v3], vec2[i+v2]);
            }
        }
        
        cout<<ans.size<<endl;
        for(auto x:ans)
        {
            cout<<x.fi<<" "<<x.se<<endl;
        }

        
    }

    return 0;
}
