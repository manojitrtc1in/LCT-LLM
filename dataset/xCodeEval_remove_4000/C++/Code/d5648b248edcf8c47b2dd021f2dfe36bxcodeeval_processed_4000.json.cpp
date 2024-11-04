













using namespace std;
const int NN=100001;
const int mod=1000000007;
const int id1=-1;
const int id0=199999991;
vector<int> graph[1000000];
int height[1000000];
int visited[1000000];
int order[1000000];
int val[1000000];
int N;
int X,k=0;
ll commDiv(ll n)
{
    ll ans=0;
    while(n%2==0)
    {
        n=n/2;
        ans++;
    }
    for(ll i=3;i*i<=n;i+=2)
    {
        while(n%i==0)
        {
            n=n/i;
            ans++;
        }
    }
    if(n>1)
    ans++;
    return ans;
}
int main(){
         ios_base::sync_with_stdio(false);
         cin.tie(0);
         cout.tie(0);
         ll t;
         cin>>t;
         while(t--){
             ll a,b,k;
             cin>>a>>b>>k;
             if(max(a,b)<k){
                 cout<<"NO\n";
                 continue;
             }
             if(k==1 && (a==b || (a%b!=0 && b%a!=0))){
                 cout<<"NO\n";
                 continue;
             }
             ll t1=0,t2=0,d=a;
              t1=commDiv(a);
              t2=commDiv(b);
             

             if(k>t1+t2){
                 cout<<"NO\n";
             }
             else cout<<"YES\n"; 
         }
  return 0;
}