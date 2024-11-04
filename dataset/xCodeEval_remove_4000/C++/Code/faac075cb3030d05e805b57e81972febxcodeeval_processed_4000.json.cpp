

































































































































































































































































































































































































































































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
string id0(ll n)
{
    

    

    string s = bitset<64> (n).to_string();
     
    

    

    const auto loc1 = s.find('1');
     
    if(loc1 != string::npos)
        return s.substr(loc1);
     
    return "0";
}
 
int main()
{
    IttouShura;
    ll T;
    cin>>T;
    for(ll t=0;t<T;t++)
    {
        
        ll h,w;
        cin>>h>>w;
        

        {
            for(ll i=0;i<h;i++)
            {
                if(i==0||i==h-1)
                    {
                    for(ll j=0;j<w;j++)
                    {
                        

                       

                    }
                    

                    }
                else if(i%2==0)
                {
                    
                    

                    {
                        for(ll j=0;j<w;j++)
                    {
                      

                      

                    }
                    cout<<"\n";
                    }

                }
                else
                {
                    for(ll j=0;j<w;j++)
                    {
                      

                    }
                    cout<<"\n";
                }
            }
            
        ll mt[h+4][w+4];
        for(ll i=0;i<h;i++)
        {
            for(ll j=0;j<w;j++)
            mt[i][j]=0;
        }
        for(ll i=0;i<w;i+=2)
        {
            mt[0][i]=1;
        }
        if(h%2==1){
        for(ll i=2;i<h-2;i+=2)
        {
            mt[i][0]=1;
            mt[i][w-1]=1;
        }
        }
        else
        {
            for(ll i=2;i<h-2;i+=2)
        {
            mt[i][0]=1;
            mt[i][w-1]=1;
        }
        }
        if(h>2)
        {
            for(ll i=0;i<w;i+=2)
 
            {
                mt[h-1][i]=1;
            }
        }
        for(ll i=0;i<h;i++)
        {
            for(ll j=0;j<w;j++)cout<<mt[i][j];
            cout<<"\n";
        }
 
cout<<"\n";
        }
        

       

       

        

                
       

        

        
        cout<<"\n";
        
        
    }
    
    return 0;
}