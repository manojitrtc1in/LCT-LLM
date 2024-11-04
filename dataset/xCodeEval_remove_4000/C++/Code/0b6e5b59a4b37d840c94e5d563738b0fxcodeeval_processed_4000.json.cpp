



using namespace std;




void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
void sample()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

}
long long int* read(long long int n)
{
    long long int* arr=new long long int[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    return arr;
}




void solve()
{
    long long int n,i,j,k,ans,m,o;

    cin>>n;

    


    


    


    cin>>k;

    long long int ar[n+2],cr[k],sub[k],subnow=0,sum=0,cap[100005]={0};

    for(i=1;i<=n;i++)
    {
        cin>>ar[i];
        sum+=ar[i];
    }

    ar[0]=ar[n];
    ar[n+1]=ar[1];

    ans=0;

    for(i=0;i<k;i++)
    {
        cin>>cr[i];
        cap[cr[i]]++;

        if(cr[i]==n)
            cap[0]++;
        if(cr[i]==1)
            cap[n+1]++;

        j=(ar[cr[i]]*(sum-ar[cr[i]]));
        

        ans=ans+j;
        sum-=ar[cr[i]];
    }

    for(i=1;i<=n;i++)
    {
        if(cap[i]==0 && cap[i+1]==0)
            ans=ans+(ar[i]*ar[i+1]);
    }

    cout<<ans;
    

    

    return ;
    

    


}





int main()
{
    fast();
    

    long long int i, j, k, n, m, a, b, c, d, p, q, r, l, t = 1;
    long long int sum, count = 0, ans = 0;

    

    while (t--)
    {
        solve();

    }

    return 0;
}
