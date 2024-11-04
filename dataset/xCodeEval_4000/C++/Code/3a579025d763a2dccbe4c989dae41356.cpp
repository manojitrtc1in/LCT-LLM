

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define pb push_back
#define pf push_front
#define F first
#define S second
#define mpp make_pair
#define vll vector<ll>
#define pll pair<ll, ll>
#define all(x) x.begin(), x.end()
#define f(s, e, v) for(ll i = s; i < e; i+=v)
#define fr(s, e, v) for(ll i = s; i >= e; i-=v)
#define lol ios_base::sync_with_stdio(0); cin.tie(0);

const ll INF = 1e18 + 10;
const int inf = 1e9 + 10;

ll gcd(ll a, ll b) { if (b > a) { return gcd(b, a); } if (b == 0) { return a; } return gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
ll powm(ll a, ll b, ll mod) { ll res = 1; while (b > 0) { if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1; } return res; }  


bool compare(ll a, ll b){
  return a > b;
}

bool poss(vll arr, ll s, ll c, ll d){
  ll sum = 0;
  ll n = arr.size();
  ll x = min(n, s);

  f(0,x,1) sum+=arr[i];

  ll curr = (d/s)*sum;
  x = min(d%s, n);

  f(0,x,1) curr += arr[i];

  if(curr >= c) return true;
  return false;
}

void solve(ll t){
  ll n, c, d; cin>>n>>c>>d;
  vll arr(n);
  f(0,n,1) cin>>arr[i];

  sort(all(arr), compare);

  f(0,n,1){
    if(arr[i] >= c){
      cout<<"Infinity\n";
      return;
    }
  }
  
  ll s = 0, e = INF;
  ll ans = -1;
  while(s < e){
    ll mid = (s+e+1)/2;
    if(poss(arr, mid, c, d)){
      ans = mid;
      s = mid;
    }
    else{
      e = mid - 1;
    }
  }

  if(ans == -1){
    cout<<"Impossible\n";
    return;
  }
  if(ans == INF){
    cout<<"Infinity\n";
    return;
  }
  cout<<ans-1<<"\n";
}

int main(){
  lol
  ll t;
  cin>>t;
  ll i = 1;
  while(i <= t){
      solve(i);
      i++;
  }
  

  return 0;
}