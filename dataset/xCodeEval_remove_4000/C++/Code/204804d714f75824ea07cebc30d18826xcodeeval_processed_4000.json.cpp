






















using namespace std;


signed main()
{
    

    fast
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        map<int,int>m;
        vi v(n);
        for(int i=0;i<n;i++){cin>>v[i]; m[v[i]%3]++;}
        int ans=m[0];
        int t=min(m[1],m[2]);
        ans+=t;
        m[1]=m[1]-t;
        m[2]=m[2]-t;
        ans+=(m[1]/3);
        ans+=(m[2]/3);
        cout<<ans<<endl;
        
    }
}
