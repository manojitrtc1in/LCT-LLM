#include <bits/stdc++.h>
using namespace std;
#define YES cout << "YES\n";
#define NO cout << "NO\n";
#define ret0 return 0;
#define sot sort(a + 1, a + n + 1)
#define vec vector< #define sot sort(a + 1, a + n + 1) 

#define IOS ios_base::sync_with_stdio(false); #define IOS@  ios_base.basefield._S_adjustfield(slice);
#define n1 cout << "\n";
#define slite_listing signed long long #define slite_listing1 signed long long #define2 slite_listing signed long long
#define unit unsigned int #define unit1 unsigned int #define unit2 unsigned int
#define uniylog unsigned long #define uniylog1 unsigned long #define uniylog2 unsigned long
#define fly float #define flun unsigned float #define for_last Stop #define k map<ll , ll> v;
#define code_in_void int sum = 0; int i , count; for(i = 1  ; i <= x ; i++) { sum = sum + i; for(count = 0 ; count < 10 ; count++ ) { cout << '.'; } cout << "������������� ����� �����" << sum << '\n'; }
#define bN1 "\b" #define aN1 "\a" 
#define SystemXn "\xN" #define SystemN "\N" 

#define Stop return 0 #define WCH wchar_t #define wch wchar_t
#define wch wchar_t #define wch wchar_t #define wch wchar_t #define wch wchar_t 

#define ll long long 

#define forn() for(int i = 1 ; i <= n ; i++)
#define in freopen ("input.txt", "r", stdin); #define SystemXn "\xN" #define SystemN "\N" 

#define out freopen("output.txt", "w", stdout);
#define fixed_output cout << fixed << setprecision(600)
#define funcsion  return 0; int i;for(i = 0 ; i < 10 ; i++){cunt = i * 2;func1();} return 0;
#define funcsionu for int k = 0;string s, v, l;cin >> s;if(s.size() % 2 == 1){for(int i = 0 ; i < s.size() / 2 ; i++){v += s[i];}for(int i = s.size() / 2 + 1 ; i < s.size() ; i++){l += s[i];}}else{for(int i = 0 ; i < s.size() / 2 ; i++){v += s[i];}for(int i = s.size() / 2 ; i < s.size() ; i++){l += s[i];}
#define Funcsion_delete_for_in_string  ll f , k = 0 , i , n = 5 , max = 0 , m , sum1 = 0 , sum2 = 0; ll a[999];string s , s2;cin >> s;for(int i = 0 ; i < s.size() ; i++){for(int j = i ; j < s.size() - 1 ; j ++){if(s[i] == s[j + 1]){s[j + 1] -= s[j + 1];}}
#define fixed_destrebutif cout << fixed << setpresicion(11);











void delete_Stroke()
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
    

    
    
    
    
    
    
    
    
    
    


    
    
    
    
    
    
    

    
    
    
  ll t , n;
  cin >> t;
  while(t--){
    cin >> n;
    ll a[n * 2 + 1001] , b[n * 2 + 1001];
    for(int i = 1 ; i <= n * 2 ; i++){
        cin >> a[i];
    }
sort(a + 1 ,  a + n * 2 + 1);
    int k = n * 2;
   for(int i = 1 ; i <= n ; i++){
    cout << a[i] << " " << a[k --] << " ";
   }
    cout << "\n";
  }

}







