





using namespace std;
typedef vector<long long> vi;
typedef pair<long long,long long> pi;


















vector<string>v2;

void solve(){
ll i,n,k,t,p=0,l,t1,t2=-1;
cin>>n>>k;
ll a[n];
for(i=0;i<n;i++)
{
cin>>a[i];

}
while(p!=n-1&&k!=0){
           if(a[p]==0)
           p++;
           else{
               a[p]--;
               a[n-1]++;
               k--;
           }
       }
       for(i=0;i<n;i++)
       cout<<a[i]<<" ";
       cout<<"\n";
}


int main()
{ long long a;
cin>>a;
while(a--)
solve();


return 0;
}
 
 











































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































