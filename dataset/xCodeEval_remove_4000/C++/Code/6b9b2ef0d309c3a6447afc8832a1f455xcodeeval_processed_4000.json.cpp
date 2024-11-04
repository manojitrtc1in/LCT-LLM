















using namespace std;



ll mod=998244353;


    int firstdigit(int n){

            int digits = (int)log10(n);

            n = (int)(n/pow(10,digits));
        

        return n;
    }


    int countDigit(long long n)
     {
        if (n==0)
        {
            return 1;
        }
        
        else{
            return floor(log10(n) + 1);
        }
    }


ll isPrime(ll n){
    int flag=0;
    for (int i = 2; i*i<=n; i++)
    {
        if (n%i==0)
        {
            flag=1;
        }
        
    }
    if (flag==0)
    {
        return true;
    }
    else{
        return false;
    }
}



ll power(ll x, unsigned ll y, ll p)
{
    ll res = 1;      

    x = x % p;  

                

    while (y > 0)
    {
        

        if (y & 1)
            res = (res*x) % p;
 
        

        y = y>>1; 

        x = (x*x) % p;
    }
    return res;
}
 










bool id6(ll d, ll n)
{
    

    

    ll a = 2 + rand() % (n - 4);
 
    

    ll x = power(a, d, n);
 
    if (x == 1  || x == n-1)
       return true;
 
    

    

    

    

    

    while (d != n-1)
    {
        x = (x * x) % n;
        d *= 2;
 
        if (x == 1)      return false;
        if (x == n-1)    return true;
    }
 
    

    return false;
}
 






bool id3(ll n, ll k)
{
    

    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;
 
    

    ll d = n - 1;
    while (d % 2 == 0)
        d /= 2;
 
    

    for (int i = 0; i < k; i++)
         if (!id6(d, n))
              return false;
 
    return true;
}


int id0(int n){
    int sum=0,l=countDigit(n);
    for (int j = 1; j <=l; j++)
    {
        sum=sum+(n%10);
        n=n/10;
    }
    return sum;
}


int factorial(int n){
    if (n==0)
    {
       return 1;
    }
    return n*factorial(n-1);
}


ll binarySearch(ll arr[], ll l, ll r, ll x)
{
    while (l <= r) {
        ll m = l + (r - l) / 2;

         if (arr[m] == x)
            return m;
 
        if (arr[m] < x)
            l = m + 1;
         else
            r = m - 1;
    }
    return -1;
}


ll id7(vector<ll> v, ll To_Find)
{
    int lo = 0, hi = v.size() - 1;
    int mid;
    

    

    while (hi - lo > 1) {
        int mid = (hi + lo) / 2;
        if (v[mid] < To_Find) {
            lo = mid + 1;
        }
        else {
            hi = mid;
        }
    }
    if (v[lo] == To_Find) {
        

        

        return lo;
    }
    else if (v[hi] == To_Find) {
        

        

        return hi;
    }
    else {
        return -1;
    }
}



bool id4(long long n)
{
    return (n != 0) && ((n & (n - 1)) == 0);
}


long long id2(long long N)
{
    

    if (!(N & (N - 1)))
        return N;
    

    return 0x8000000000000000 >> (__builtin_clzll(N));
}


int id5(ll n, ll k)
{
    if (n & (1 << (k - 1)))
    {
        return 1;
    }
        

    else{
        return 0;
    }
        

}


ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);   
}


ll isPalindrome(vector<char> str)
{
    

    ll l = 0;
    ll h = str.size() - 1;
 
    

    while (h > l)
    {
        if (str[l++] != str[h--])
        {
            

            return 0;
        }
    }
    return 1;
}

ll isPalindrome(char str[])
{
    

    int l = 0;
    int h = strlen(str) - 1;
 
    

    while (h > l)
    {
        if (str[l++] != str[h--])
        {
            

            return 0;
        }
    }
    

    return 1;
}


bool id1(long double x)
{
    

    

    if (x >= 0) {
 
        long long sr = sqrt(x);
         
        

        

        

        return (sr * sr == x);
    }
    

    return false;
}






int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    
    



    
    

    


    


    

    

    

    

    
    

 
    

 
    

    

    

    
    

    

    

    

    

    

    

    

    

    

    

    
    

    

    

    

    


    


    


    
    

    


    

    

    

    


    


    


    

    

    

    

    

    

    

    


    

    

    

    

    

    

    

            
    

    

    

    

    

    

    

    

    

    
    
    

    


    

    

    

    


    

    

    

    


    

    

    

    

    

    


    

    

    

    

    

    

    

    

        
    

    

    

    

        
    

    

    

    

        
    

    


    
    

    


    

    

    

    


    


    

    

    

    

        
    

    

    

    

    

        
    

    

    

    

    

    

    

    

    

    

    

    

    

                    
    

    

    

    

    

    

    

    

    

    

    

            
            
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

            
    

    

    


    

    


    

    

    

    

    

    

    

    

    

    

            
    

    

    

    
    
    
    

    


    

    

    

    


    


    

    

    

    

    

        
    

    

    

    

    

    

    

    

    

    

    

    

    

                    
    

    

    

    

                    
    

    

    

    

    

    

                
    

            
    

    

    

    

    

    

    

    

    

    

    
    

    


    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

        
    

    

    

    

    


    
    

    


    

    

    

    


    


    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

        
        
    

    

    

    

    

    

    

    

    

    

    


    

            
    

    

    

    

    

    

                
    

    

    

    

    

            
    

    

    

    

    

    

    

    

                    
    

    

    

    

    

    

                    
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    
    
    ll t;
    cin>>t;

    while (t--)
    {
        ll n;
        cin>>n;

        ll a[n],mx=-1;

        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
            if (a[i]>mx)
            {
                mx=a[i];
            }
            
        }
        
        ll x=log2(mx)+1;

        ll b[x];
        for (int i = 0; i < x; i++)
        {
            b[i]=0;
        }
        

        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j <=x; j++)
            {
                if (id5(a[i],j))
                {
                    b[j-1]+=1;
                }
                
            }
            
        }
        
        ll k=b[0];
        for (int i = 1; i < x; i++)
        {
            k=gcd(k,b[i]);
        }
        
        if (k==0)
        {
            for (int i = 0; i < n; i++)
            {
                cout<<i+1<<" ";
            }
            cout<<endl;
        }
        else{
            set<ll> ans;
            for (int i = 2; i <=k; i++)
            {
                if (k%i==0)
                {
                    ans.insert(i);
                    

                }
                
            }
            

            cout<<1<<" ";
            for(auto& ele:ans)
            {
                cout<<ele<<" ";
            }
            cout<<endl;
        }
    }
    








    


    return 0;
}