


 
using namespace std;
using namespace __gnu_pbds;
 
typedef pair<int, int> node;
typedef tree<int, null_type, less<int>, 
            rb_tree_tag, tree_order_statistics_node_update> ordered_set;
          
 
 
 
 
 
 
using ll = long long int;
 
            
ll id9(ll n, ll k){


    if(n%k == 0){
    return n/k;
    }

  return n/k + 1;

 
  
}


bool isPrime(ll n){
  if(n == 1){
    return false;
  }
  for(ll i = 2; i*i<=n; i++){
    if(n%i == 0){
      return false;
    }
  }

  return true;
}



ll id4(vector<ll> A){
  ll n = A.size();
  ll s = 0;
  for(int i=0; i<n; i++){
     s += A[i];
  }

  return s;
}
ll countbits(ll n){
  return __builtin_popcountll(n);
}
ll gcd(ll a, ll b){

 
  ll u = max(a, b);
  ll v = min(a, b);
  ll s;
  while(u&&v){
    s = u;
    u = v;
    v = s%v; 
 
  }
 
  return u;
 
}
 
ll lcm(ll a, ll b){
  return (a*b)/gcd(a,b);
}

ll id5(ll n){

  if(n == 1){
    return 0;
  }
  ll l = 2;
  ll count = 0;
  while(n > 1){
    while(n%l != 0){
      l++;
    }
    
    n /= l;
    l =2;
    count++;
  }

  return count;

}
 
ll id0 (ll l, ll n, ll mod){
  ll res = 1;
  while(n){
    if( (n&1) >= 1 ){
      res = (res*l)%mod;
    }
 
    l = (l*l)%mod;
    n >>=1;
  }
 
  return res;
}
 
ll id7(ll n){
  ll pow = 1;
  while(n%pow == 0){
    pow = pow*2;
  }
 
  return pow/2;
}
 
ll powR(ll l, ll n){ 

  ll res = 1;
  while(n){
    if( (n&1) >= 1 ){
      res = res*l;
    }
 
    l = l*l;
    n >>=1;
  }
 
  return res;
    
}
vector<ll> primeList(ll n){
  vector<bool> S(n+1,false );
  vector<ll> L;
  for(ll i=2; i*i<=n; i++){  
    if(!S[i]){
     
      ll j = 2;
      while(i*j <= n){
        S[i*j] = true;
        j++;
      }
    }
  }
 
 
  for(ll i=2; i<=n; i++){
    if(!S[i]){
        L.push_back(i);
    }
  
  }
 
  return L;
}
 
ll fact_mod(ll n, ll mod){
  ll t = 1;
 
  for(int i=1; i<=n; i++){
    t = (t*i)%mod;
  }
 
  return t;
}
 
 

set<ll> id6(ll n){
  set<ll> ans;
  for(int i=1; i*i<=n; i++){
    if(n%i == 0){
      ans.insert(i);
      ans.insert(n/i);
    }
  }

  return ans;
}

 
string StrRep(string a, ll n){
 string t = "";
 
 while(n){
  t = t + a;
 
  n--;
 }
  return t;
}
 
 
void printArr(vector<ll> &A){
    for(int i=0; i<A.size(); i++){
    cout << A[i] << " ";
  }
}
 
void printPair(pair<ll, ll> A){
  cout << A.first << " " << A.second << endl;
}

void id2(vector<pair<ll, ll>> A){
  for(int i=0; i<A.size(); i++){
    cout << A[i].first << " " << A[i].second << endl;
  }
}
void printmat(vector<vector<ll>> A){
  for(int i=0; i<A.size(); i++){
    for(int j=0; j<A[i].size(); j++){
      cout <<  A[i][j] << " ";
    }
    cout << endl;
  }
}
 
bool isPar(string t){
  ll l =0;
  ll r = t.length()-1;
 
  while(l < r){
    if(t[l] != t[r]){
      return false;
    }
 
    l++;
    r--;
  }
 
 
  return true;
}
 
ll id8(ll n){
  ll s = sqrt(n);

  if(s*s == n){
    return s;
  }else if(s*s > n){
    return s -1;
  }

  return s;
}

vector<ll> KMP(string text, string pat){
  ll n = text.length();
  ll m  = pat.length();


  vector<ll> ans;
  vector<ll> LPS(m, 0);


  for(int i=1; i<m; i++){
    ll j = i-1;
    while(j >=0 && pat[LPS[j]] != pat[i]){
      j--;
    }

    if(j >=0 ){
       LPS[i] = LPS[j] + 1;
    }
  }

  ll i = 0;
  ll j = 0;

  while(i < n){
    if(text[i] == pat[j]){
        if(j == m - 1){

          ans.push_back(i - m + 1);

          j = 0;
          i++;
        }else{
          i++;
          j++;
        }
    }else{
        if(j == 0){
          i++;
        }else{
          j = LPS[j-1];
          
        }
    }
  }

  return ans;
}
 
vector<ll> factors(ll x){
  ll k = 1;
  vector<ll> T;
  for(;k*k < x; k++){
    if(x%k == 0){
      T.push_back(k);
      T.push_back(x/k);
    }
  }

  if(k*k == x){
    T.push_back(k);
  }

  return T;
}

 



















 
 

 
 
                  
 
 
class Btree{
 
  private:
  vector<ll> B;
  ll n;
 
  public:
 
  void update(ll k, ll val){   
                              
    while(k <= n){
      B[k] += val;
      k += (k&-k);
    }
  }
 
  Btree(vector<ll> A){
    n = A.size();
    for(int i=1; i<=n; i++){
    B.push_back(0);
    }
 
    for(int i=0; i<n; i++){
      update(i+1, A[i]);
    }
  }
 
  ll sum(ll k){
    ll s = 0;
 
    while(k >= 1){
      s += B[k];
      k -= (k&-k);
    }
 
    return s;
  }
 
 
 
 
 
 
};
 

 

 
 
                      
 
 
class id3{
 
private:
vector<ll> T;
ll n;
 
public:  
 
id3(vector<ll> A){
 
  n = A.size();
  for(int i=0; i<2*n; i++){
    T.push_back(0);
  }
 
  for(int i=0; i<n; i++){
    T[i + n] = A[i];
  }
 
  for(int i=n-1; i>0; i--){
    T[i] = T[i<<1] + T[i<<1|1];   
  }
 
}
 
void update(ll p, ll val){
  p = p + n;
  T[p] = val;


  while(p > 1){
    T[p>>1] = T[p] + T[p^1];
    p /= 2;
  }
 
}
 
vector<ll> Tr(){
  return T;
}
 
ll sum(ll l, ll r){    
 
 
    l += n;
    r += n;
    ll s = 0;
    for(; l < r; l = l>>1, r = r>>1){
      if(l&1){
       
         s += T[l];
         l++;
         
      }
      if(r&1){
        r--;
        s += T[r];
        
      
      }
    }
 
    return s;
}
 
 
};
 
 
class id10{
 
private:
vector<ll> T;
ll n;
ll min_start;
 
public:  
 
id10(vector<ll> A){
 
  n = A.size();
  for(int i=0; i<2*n; i++){
    T.push_back(0);
  }
 
  for(int i=0; i<n; i++){
    T[i + n] = A[i];
    min_start = max(min_start, A[i]);
  }
 
  for(int i=n-1; i>0; i--){
    T[i] = min(T[i<<1] , T[i<<1|1]);   
  }
 
}
 
void update(ll p, ll val){
 
   p = p + n;
  T[p] = val;


  while(p > 1){
    T[p>>1] = min(T[p], T[p^1]);
    p /= 2;
  }
 
}
 
vector<ll> Tr(){
  return T;
}
 
ll query(ll l, ll r){    
 
 
    l += n;
    r += n;
    ll s = 1e18;
    for(; l < r; l = l>>1, r = r>>1){
      if(l&1){
       
         s = min(s, T[l]);
         l++;
         
      }
      if(r&1){
        r--;
        s = min(s, T[r]);
        
      
      }
    }
 
    return s;
}
 
 
};
 
 
class id1{
 
private:
vector<ll> T;
ll n;
ll id12;
 
public:  
 
id1(vector<ll> A){
 
  n = A.size();
  for(int i=0; i<2*n; i++){
    T.push_back(0);
  }
 
  for(int i=0; i<n; i++){
    T[i + n] = A[i];
    id12 = min(A[i], id12);
  }
 
  for(int i=n-1; i>0; i--){
    T[i] = max(T[i<<1] , T[i<<1|1]);  
  }
 
}
 
void update(ll p, ll val){
 
   p = p + n;
  T[p] = val;


  while(p > 1){
    T[p>>1] = max(T[p], T[p^1]);
    p /= 2;
  }
 
}
 
vector<ll> Tr(){
  return T;
}
 
ll query(ll l, ll r){   
 
 
    l += n;
    r += n;
    ll s = id12 - 1;
    for(; l < r; l = l>>1, r = r>>1){
      if(l&1){
       
         s = max(s, T[l]);
         l++;
         
      }
      if(r&1){
        r--;
        s = max(s, T[r]);
        
      
      }
    }
 
    return s;
}
 
 
};

class id11{
 
private:
vector<ll> T;
ll n;

 
public:  
 
id11(vector<ll> A){
 
  n = A.size();
  for(int i=0; i<2*n; i++){
    T.push_back(0);
  }
 
  for(int i=0; i<n; i++){
    T[i + n] = A[i];
  }
 
  for(int i=n-1; i>0; i--){
    T[i] = gcd(T[i<<1] , T[i<<1|1]);  
  }
 
}
 
void update(ll p, ll val){
 
   p = p + n;
  T[p] = val;


  while(p > 1){
    T[p>>1] = gcd(T[p], T[p^1]);
    p /= 2;
  }
 
}
 
vector<ll> Tr(){
  return T;
}
 
ll query(ll l, ll r){   
 
 
    l += n;
    r += n;
    ll s =0;
    for(; l < r; l = l>>1, r = r>>1){
      if(l&1){
       
         s = gcd(s, T[l]);
         l++;
         
      }
      if(r&1){
        r--;
        s = gcd(s, T[r]);
        
      
      }
    }
 
    return s;
}
 
 
};





            

class DisjointSet{
  map<ll, ll>  parent;
  map<ll, ll> rank;
  map<ll, ll> countInSet;

  public:

  void Makeset(vector<ll> elements){
    for(int i=0; i<elements.size(); i++){
      parent[elements[i]] = elements[i];
      rank[elements[i]] = 0;
      countInSet[elements[i]] = 1;
    }
  }

  ll Find(ll x){
      if(x != parent[x]){
        return Find(parent[x]);
      }
        return x;
      
  }


  void Union(ll x, ll y){
    ll xParent = Find(x);
    ll yParent = Find(y);

    if(xParent == yParent){
      return;
    }


    if(rank[yParent] > rank[xParent]){
      countInSet[yParent] += countInSet[xParent];
      parent[xParent] = yParent;
      
      
    }else if(rank[yParent] < rank[xParent]){
          countInSet[xParent] += countInSet[yParent];
           parent[yParent] = xParent;
          
    }else{
          countInSet[yParent] += countInSet[xParent];
           parent[xParent] = yParent;
           rank[yParent]++;
           
    }
  }

  ll setCount(ll x){
    return countInSet[Find(x)];
  }




};


 



void solve(){

ll n;
cin >> n;
ll cnt = 0;


for(int a=3; a<=1e9; a+=2){
  ll b = (a*a - 1)/2;
  ll c = b + 1;
  if(c > n || b > n || a > n){
    break;
  }
  if(a <= b <= c && c*c == b*b + a*a && c == a*a  - b){
      if(a == b){
        cnt +=2;
      }else{
        cnt++;
      }
  }
}

cout << cnt << endl;


}
int main(){





ios_base::sync_with_stdio(false), cin.tie(nullptr);




Tstart1

    return 0;
}


