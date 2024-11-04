

































































































































































































































































































































































































































































using namespace std;



ll min(ll a,ll b)
{
    if(a<b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
ll max(ll a,ll b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
    
}
bool sumCube(ll n) 
{ 
    unordered_map<ll,ll> s; 
    for (ll i=1;i*i*i<=n;++i) 
    { 
        s[i*i*i] = 1; 
        if (s.find(n-i*i*i) != s.end()) 
        { 
            return true; 
        } 
    } 
    return false; 
}
void pairsort(ll a[],ll b[],ll n) 
{ 
    pair<ll, ll> pairt[n]; 
    for (ll i=0;i<n;i++)  
    { 
        pairt[i].first=a[i]; 
        pairt[i].second=b[i]; 
    } 
    sort(pairt,pairt+n);  
    for (ll i=0;i<n;i++)  
    { 
        a[i] = pairt[i].first; 
        b[i] = pairt[i].second; 
    } 
} 
bool isPrime(ll n)
{
 
    if (n <= 1)
        return false;
 
    

    for (ll i = 2; i < n; i++)
        if (n % i == 0)
            return false;
 
    return true;
} 
ll binarySearch(ll arr[],ll l,ll r,ll x)
{
    if(r>=l) 
    {
        ll mid=l+(r-l)/2;
        if (arr[mid]==x)
        {
            return mid;
        }    
        if (arr[mid]>x)
        {
            return binarySearch(arr,l,mid-1,x);
        }    
        return binarySearch(arr,mid+1,r,x);
    }
    return -1;
}
int main()
{
    IttouShura;
    ll T;
    cin>>T;
    for(ll t=0;t<T;t++)
    {
        
        ll n,k;
        cin>>n>>k;
        ll x=k;
        

        

        

        

        

        char arr[n][n];
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<n;j++)
            {
                if((i==j)&&(i%2==0))
                {
                   if(k>0){ arr[i][j]='R'; k--;}
                   else arr[i][j]='.';
                }
                else arr[i][j]='.';
            }
        }
        if((n+1)/2>=x)
        {
            for(ll i=0;i<n;i++)
            {
                for(ll j=0;j<n;j++)
                {
                    cout<<arr[i][j];
                }
                cout<<"\n";
            }
            

        }
        else
        {
            cout<<"-1\n";        
            
        }
        
    }
    
    return 0;
}