
using namespace std;

















































void id0()
{
    ll f, k = 0, i, n = 5, max = 0, m, sum1 = 0, sum2 = 0;        

    ll a[999];
    string s, s2;
    cin >> s;
    for(int i = 0 ; i < s.size() ; i++)
    {
        for(int j = i ; j < s.size() - 1 ; j ++)
        {
            if(s[i] == s[j + 1])
            {
                s[j + 1] -= s[j + 1];
            }
        }
    }
}
void q()
{
    int k = 0;
    string l, v;
    cin >> l >> v;
    reverse(l.begin(), l.end());
    for(int i = 0 ; i < v.size() ; i++)
    {
        if(v[i] != l[i])
        {
            k ++;
        }
    }
    cout << k;
}
void w()
{
    int n;
    cin >> n;
    cout << ((n + 3) % 7) + 1;
}
void e()
{
    int a, b; cin >> a >> b;
    if(b % a != 0)
    {
        cout << b / a + 1 << " " << b - ((b / a) * a);
    }
    else
    {
        cout << b / a << " " << a;
    }
}
void r()
{
    long long n;
    cin >> n;
    long long a[n + 1937];
    for(int i = 0 ; i < n ; i ++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    reverse(a, a + n);
    int t = unique(a, a + n) - a; 

    for(int i = 0 ; i < t ; i++)
    {
        cout << a[i] << " ";
    }
}
void t()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin >> n >> x;
        long long a[n];
        long long mn = 0,mx = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            mn += a[i];
            mx += (a[i] + x - 1) / x;
        }
        mn = (mn + x - 1) / x;
        cout << mn << " " << mx << "\n";
    }
}
void y()
{
    long long t, f, a, b, mx = -1e9, k = 0;
    cin >> t >> f;
    for(int i = 1 ; i <= t ; i++)
    {
        cin >> a >> b;
        if(b > f)
        {
            mx = max(mx, (a - (b - f)));
        }
        else
        {
            mx = max(mx, a);
        }
    }
    cout << mx;
    n1
}
void u()
{
    int n, j = 0, k = 0;

    cin >> n;

    for( ; ; )
    {
        if(j == n)
        {
            break;
        }
        else
        {
            k ++;
        }
        j = 0;
        for(int i = 1 ; i <=  n ; i++)
        {
            if(k % i == 0)
            {
                j ++;
            }
        }
    }
    cout << k;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a >= d && b >= c)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    n1
}
void klop()
{
    int k, l;
    string a, b, p, j;
    cin >> a >> b;
    for(int i = 0 ; i <= a.size(); i++)
    {
        if(int(a[i]) < 97)
        {
            a[i] += 32;
            p += a[i];
        }
    }
    for(int i = 0 ; i <= b.size() ; i++)
    {
        if(int(b[i]) < 97)
        {
            b[i] += 32;
            j += b[i];
        }
    }
    if(a < b)
    {
        cout << -1;
    }
    else if(a > b)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
}
signed int main()
{
    

    
    
    
    
    
    
    
    
    
    


    
    
    
    
    
    
    

    
    
    
    int a, b, c;
    int t;
    cin >> t;
    for(int i = 1 ; i <= t ; i++)
    {
        cin >> a >> b >> c;
        int k = 1;
 int a1 = a , b1 = b , c1 = c;
        if(a1 % 2 == 0)
        {
            while(a1 % 2 != 1)
            {
                a1 = a1 / 2;
                k *= 2;
            }
        }
        if(b1 % 2 == 0)
        {
            while(b1 % 2 != 1)
            {
                b1 = b1 / 2;
                k *= 2;
            }
        }
         if(k >= c){
            YES;
         }else{
         NO;
         }
        }
    }








