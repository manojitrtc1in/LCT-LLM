
using namespace std;


bool id11(string s)
{
  for(int i=0;i<s.length()/2;i++)
  {
    if(s[i]!=s[s.length()-i-1])
      return false;
  }
  return true;
}
void id4(string s){
    for(int i=0;i<3;i++)
    {
        string res="";
        cout<<s[i]<<endl;
        for(int j=i+1;j<3;j++)
            {res=s.substr(i,j+1);
        cout<<res<<endl;
    }
}
}



 bool id3(string str1, string str2)
{
   
   if (str1.length() != str2.length())
        return false;
  
   string temp = str1 + str1; 
  return (temp.find(str2) != string::npos);
  
}
ll id2(string n)
{
    string num = n;
    ll dec_value = 0;
 
    

    ll base = 1;
 
    ll len = num.length();
    for (ll i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
 
    return dec_value;
}
string id7(ll n)
{
    

    

    string s = bitset<64> (n).to_string();
     
    

    

    const auto loc1 = s.find('1');
     
    if(loc1 != string::npos)
        return s.substr(loc1);
     
    return "0";
}
bool issort(pair<ll,ll>a,pair<ll,ll>b)
{
    if(a.first==b.first)
        return a.second<b.second;
    else
  return a.first>b.first;
}
ll gcd(ll a,ll b)
{
    

  if(b==0)
  return a;
  else
  return gcd(b,a%b);
}


ll id9(vector<ll>arr, ll n)
{
    ll result = arr[0];
    for (ll i = 1; i < n; i++)
    {
        result = gcd(arr[i], result);
 
        if(result == 1)
        {
           return 1;
        }
    }
    return result;
}
ll id12(ll x, ll y)
{
    ll s = gcd(x, y);
 
    ll ans = (x * y) / (s * s);
 
    return ans;
}
void id0(ll n)
{
  ll flag=0;
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (ll p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (ll i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (ll p = n/2; p <= n; p++)
        if (prime[p]&&p>1)
            flag++;
          cout<<flag+1<<endl;
          

}
 void  is(ll n)
 {
  vector<ll>v;
  set<ll>s;
  ll temp=0,curr=0,run=0,i;
  for( i=1;i*i<=n;i++)
  {
   

     

      if(n%i==0&&s.find(i)==s.end()&&i!=n)
      {
        v.push_back(i);
        s.insert(i);
 

      }
    }
    for( i=sqrt(n);i>=1;i--)
  {
   

     

    if(n%i==0&&n/i!=n)
    { 
      if(s.find(n/i)==s.end())
     {
        v.push_back(n/i);
      s.insert(n/i);
   

    }
}
}
cout<<v.size()<<endl;










 }
 bool isprime(ll n)
{
    

    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
  
    

    

    if (n % 2 == 0 || n % 3 == 0)
        return false;
  
    for (ll i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
  
    return true;
}


void nextmini(ll a[],ll n)
 
{
  ll i,flag=0;
  stack<ll> s;
 
    
    s.push(a[0]);
 
    

    for ( i = 1; i < n; i++) {
 
        if (s.empty()) {
            s.push(a[i]);
            continue;
        }
 
        while (s.empty() == false && s.top() > a[i]) {
            flag++;
            s.pop();
        }
        s.push(a[i]);
    }
 
    while (s.empty() == false) {
        s.pop();
    }
cout<<flag<<endl;
}
int countFreq(string &pat, string &txt)
{
    int M = pat.length();
    int N = txt.length();
    int res = 0;
   
    
    for (int i = 0; i <= N - M; )
    {
        
        if(txt.substr(i,M)==pat)
        {
            res++;
            i+=M;
        }
        else
            i++;
}
return res;
}


string X,Y;
ll lcs(ll i, ll j, ll count)
{
 
    if (i == 0 || j == 0)
        return count;
 
    if (X[i - 1] == Y[j - 1]) {
        count = lcs(i - 1, j - 1, count + 1);
    }
    count = max(count,
                max(lcs(i, j - 1, 0),
                    lcs(i - 1, j, 0)));
    return count;
}


ll id6(ll a[], ll size,ll k,ll m)
{
    ll id5 = INT_MIN, id8 = 0;
 
    for (ll i = 0; i < size; i++)
    {
        if(i==k-1)
        a[i]=m;
        id8 = id8 + a[i];
        if (id5 < id8)
            id5 = id8;
 
        if (id8 < 0)
            id8 = 0;
    }
    return id5;
} 
ll fact2(ll n)
{
    ll fact1=1,i;
    if(n==1)
        return 1;
    for(i=1;i<=n;i++)
        fact1=fact1*i;
    return fact1;
}
ll countOdd(ll L, ll R){
 
    ll N = (R - L) / 2;
 
    

    if (R % 2 != 0 || L % 2 != 0)
        N += 1;
 
    return N;
}
 bool id10 ( ll num )
{
    if ( ( num & ( num - 1 ) ) == 0 )
        return 1;
    return 0;   
}
ll id1(ll arr[],
                     ll n, ll k)
{
    

    set<ll> multiples;
 
    

    for (ll i = 0; i < n; ++i) {
 
        

        

        if (multiples.find(arr[i])
            == multiples.end()) {
 
            

            

            for (ll j = 1;
                 j <= k / arr[i]; j++) {
                multiples.insert(arr[i] * j);
            }
        }
    }
 
    

    

    

    return k - multiples.size();
}






































ll countValues(ll arr[], ll N,
                ll L, ll R)
{
    

    

    return id1(arr, N, R);
         
}




void solve()
    {
    string s;
    cin>>s;
    ll i,a=0,b=0,c=0,temp=0;
    for(i=0;i<s.length();i++)
    {
        if(s[i]=='A')
            a++;
        else if(s[i]=='B')
            b++;
        else if(s[i]=='C')
            c++;
    }
     if(a==0&&(b==c))
        cout<<"YES"<<endl;
    else if(c==0&&(a==b))
        cout<<"YES"<<endl;
    else if(b==a+c)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    

}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);
  
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
   ll t;
  cin>>t;
   

    while(t--)
    {
      solve();
    }
    

    

    

    













    

    

    

    

    













    

















    

    

    

    

   

   



  

     

    

  return 0;
}