



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


long long po(long long n){
    long long z=1;
    while(n){
        n--;
        z*=2;
    }
    return z;
}


void solve()
{
    long long int n,i,j,k,ans,m,o;

    

    cin>>n;

    


    


    


    cin>>m;

    long long int ar[n][m],col[m]={0},colw[m]={0},roww[n]={0},row[n]={0};
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>ar[i][j];
        }
    }

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(ar[j][i]==1)
                col[i]++;
            else
                colw[i]++;
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(ar[i][j]==1)
                row[i]++;
            else
                roww[i]++;
        }
    }

    ans=0;

    for(i=0;i<m;i++)
    {
        ans+=(po(col[i]))-1;
        ans+=(po(colw[i]))-1;
        

    }

    

    ans-=(n*m);

    for(i=0;i<n;i++)
    {
        ans+=(po(row[i]))-1;
        ans+=(po((roww[i])))-1;
        

    }

    


    


    cout<<ans<<endl;



    return;



    






}





int main()
{
    fast();
    sample();
    long long int i, j, k, n, m, a, b, c, d, p, q, r, l, t = 1;
    long long int sum, count = 0, ans = 0;

    

    while (t--)
    {
        solve();

    }

    return 0;
}
