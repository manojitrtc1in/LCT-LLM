

































































































































































































































































































































































































































































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
 

int main()
{
    int t;
    cin>>t;
    for(int T=0;T<t;T++)
    {
        int n,k;
        cin>>n>>k;
        vector<int>arr1;
        vector<int>arr2;
        for(int i=1;i<=(n-k);i++)
        {
            arr1.push_back(i);
        }
        for(int i=n-k+1;i<=(n);i++)
        {
            arr2.push_back(i);
        }
        int i=0,j=0;
        if(k>=(n-k))
        {
            cout<<"-1"<<endl;
            continue;
        }
        while(i<arr1.size() || j<arr2.size())
        {
            if(i<arr1.size())
            {
                cout<<arr1[i]<<" ";
                i++;
            }
            if(j<arr2.size())
            {
                cout<<arr2[j]<<" ";
                j++;
            }
        }
        cout<<endl;
    }
}