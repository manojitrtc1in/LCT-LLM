






























































































































using namespace std;
int modulo = 1e9+7;
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }
bool sorta(const pii &a, const pii &b) { return (a.second < b.second); }
bool sortd(const pii &a, const pii &b) { return (a.second > b.second); }
string id8(int n) {
    string s = "" ;
    int i = 0;
    while (n > 0) {
        s = to_string(n % 2) + s;
        n = n / 2;
        i++;
    }
    return s;
}
ll id3(string n) {
    string num = n;
    ll dec_value = 0;
    int base = 1;
    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1') dec_value += base;
        base = base * 2;
    }
    return dec_value;
}
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}
bool id1(int n) {
    if (n == 0) return false;
    return (ceil(log2(n)) == floor(log2(n)));
}
bool id5(ll x) {
    if (x >= 0) {
        ll sr = sqrt(x);
        return (sr * sr == x);
    }
    return false;
}
  long long id6(long long a, long long b, long long mod)
  {
      long long res = 0;
      a %= mod;
  
      while (b)
      {
  
          if (b & 1)
              res = (res + a) % mod;
  
          a = (2 * a) % mod;
  
          b >>= 1; 

      }
  
      return res;
  }
ll id2(ll x, ll y, ll p) {
    ll res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0) {
        if (y & 1) res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}


ll id0(ll x)
{
    ll left = 0, right = 2000000123;
    while (right > left)
    {
        ll mid = (left + right) / 2;

        if (mid * mid > x)
            right = mid;
        else
            left = mid + 1;
    }
    return left - 1;
}


  
  ll id7(ll n, ll mod)
  {
      return id2(n, mod - 2, mod);
  }
  
  ll nCr(ll n, ll r, ll p)
  {
      

      if (n < r)
          return 0;
      

      if (r == 0)
          return 1;
  
      

      

      

      unsigned long long fac[n + 1];
      fac[0] = 1;
      for (int i = 1; i <= n; i++)
          fac[i] = (fac[i - 1] * i) % p;
  
      return (fac[n] * id7(fac[r], p) % p * id7(fac[n - r], p) % p) % p;
  }




vector<int> factors(int n){
    vector<int>ans;
    ans.pb(1);
    ans.pb(n);
    int sz=sqrt(n);
    for(int i=2;i<=sz;i++){
        if(n%i ==0){
            ans.pb(i);
            ans.pb(n/i);
        }
    }
    return ans;
}


  int ps(int i,vector<vector<int>>&v){

    


    int x=gcd(v[i][0],v[i][1]);
    


    vector<int>fac=factors(x);
    sort(fac.begin(),fac.end(),[](int&a,int &b){
        return a>b;
    });










    for(auto &itr:fac){

        int D=(v[i][0]) / itr;
        int K=(v[i][1])/itr;
        int partition=D+K;
        int index=partition;
        bool check=true;
        while(index<=i){
            int temp_d= v[index][0]-v[index-partition][0];
            int temp_k=v[index][1]-v[index-partition][1];

            if(temp_d!=D || temp_k!=K){
                check=false;
                break;
            }


            index+=partition;
        }

        if(check){
            return (itr);

        }

        


    }

    return 1;
  


  }
  
int main() {
    Meyank Garg id4;
    ll t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        string s;
        cin>>s;
        

        int D=0;
        int K=0;
        vector<vector<int>>v;
        v.pb({0,0});
        for(int i=0;i<n;i++){
            if(s[i]=='D'){
                D++;
            }else{
                K++;
            }
            v.push_back({D,K});
        }
        map<double,int>h;
        for(int i=1;i<=n;i++){

            

            if(v[i][0]==0 || v[i][1]==0){
                cout<<v[i][0]+v[i][1]<<" ";
                continue;
            }
            double temp=(double)v[i][0]/v[i][1];

            h[temp]++;
            

            

            cout<<h[temp]<<" ";

        }
        cout<<endl;

       

    }
    return 0;
}