
 

using namespace std;

    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);





using namespace __gnu_pbds;











    for (int &a : x) \
        cin >> a;


 




 

    int x;    \
    cin >> x; \
    while (x--)
    
int n=10000;
int si[10000]={0};
void sieve()
{
    int f;
    for(int i=2;i<=n;i++)
    {
         f=0;
        for(int j=2;j<=sqrt(i);j++)
        {
            if(i%j==0)
            {
                f=1;
                break;
            }
        }
         if(f==0)
         si[i]=1;
    }
   
}
bool prime(int n)
{
    if(n==1)
    return false;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        return false;
    }
    return true;
}

int32_t main()
{
     FIO

        freopen(fi, "r", stdin);
    freopen(fo, "w", stdout);




    w(t)
    {
        int n,m,mi=0,ma=0;
        cin>>n>>m;
        vi v(n);
        for(int &a:v)
        {
            cin>>a;
            mi+=a;
            ma+=(ceil(a/(double(m))));
        }
        mi=ceil(mi/(double(m)));
        cout<<mi<<" "<<ma<<'\n';
    }
    cerr << "processor time: " << clock() / (double)CLOCKS_PER_SEC << "s    ";
}