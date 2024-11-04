














using namespace  std;
ll a[200005],b[100005],n,m,h,k;
map<int,int>mp;
map<int,int>::iterator it;
char s[100000];
int main()
{   char ch;
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
   cin>>t;
   while(t--)
   {
     cin>>n>>m;
     ll x=0,y=0;
     ll ans=0;
      cin>>s+1;
     for(int i=1;i<=n;i++)
     {
         if(s[i]=='*')x++;
     }
     if(x==1)
     {
         cout<<x<<endl;
         continue;
     }
     for(int i=1;i<=n;i++)
     {
         if(s[i]=='*')
         {
             x=i;
             ans++;
             break;
         }
     }
     for(int i=n;i>=1;i--)
     {
         if(s[i]=='*')
         {
             y=i;
             ans++;
             break;
         }
     }
     ll pos=0,num=0;
     ll l=x;
     ll  r=y;
    for(int i=x+1, j=1;i<y;i++, j++){
        if(s[i] == '*'){
            pos= i;
        }
        if(j == m){
            x = pos;
            ans++;
            j = i - x;
        }
    }
     cout<<ans<<endl;

   }

    return 0 ;
}
