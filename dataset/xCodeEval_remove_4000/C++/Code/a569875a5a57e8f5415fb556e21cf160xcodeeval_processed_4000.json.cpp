




























































































































































































using namespace std;
vector<lld> fac(200009,1);
int main()
{
     ios;
     lld n;
     cin>>n;
     vector<lld> deg(n+1);
     rep(i,1,200009)
     {
         fac[i]=(fac[i-1]*i)%mod;
     }
     rep(i,1,n)
     {
         lld x,y;
         cin>>x>>y;
         deg[x]++;
         deg[y]++;
     }
     lld ans=n;
     rep(i,1,n+1)
     {
        ans=(ans*fac[deg[i]])%mod;
     }
     cout<<ans<<endl;
    return 0;
}

