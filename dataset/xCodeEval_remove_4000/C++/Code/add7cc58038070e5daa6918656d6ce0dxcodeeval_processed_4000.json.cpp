

never think too much about some thing except questions ;



















                                cin>>u>>v; \
                                a[u]push_back(v);}




 cout<<endl; }}

 cout<<endl; }
 
 
 
 






using namespace std;







int spf[MAXN];







void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)

        

        

        spf[i] = i;

    

    

    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;

    for (int i=3; i*i<MAXN; i++)
    {
        

        if (spf[i] == i)
        {
            

            for (int j=i*i; j<MAXN; j+=i)

                

                

                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}





set<ll> id4(ll x)
{
    set<ll> ret;
    while (x != 1)
    {
        ret.insert(spf[x]);
        x = x / spf[x];
    }
    return ret;
}








struct hash_pair
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1> {}(p.first);
        auto hash2 = hash<T2> {}(p.second);
        return hash1 ^ hash2;
    }
};
ll mod=1000000007;
ll power(ll a, ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1)ans = (ans*a)%mod;
        a = (a*a)%mod;
        b>>=1;
    }
    return ans;
}
ll power1(ll a, ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1)ans = (ans*a);
        a = (a*a);
        b>>=1;
    }
    return ans;
}
const long long MAX_SIZE = 1000001;
ll id6(ll n)
{
    ll temp  = 0 ;
    

    for (ll i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            

            if (n/i == i)
                temp++;

            else 

                temp+=1;
        }
    }
    return temp ;
}
vector<ll> Get_bits(ll k)  

{
    ll kk = 0 ;
    vector<ll>vec1(20);
    ll k1 = k;
    while(k1)
    {
        ll sum1 = 0 ;
        if(((k+1)%power1(2, kk+1))>power1(2, kk))sum1 = ((k+1)%power1(2, kk+1))%power1(2,kk);

        vec1[kk] = power1(2, kk)*((k+1)/power1(2,kk+1)) +sum1;
        kk+=1;
        k1>>=1;


    }
    return vec1;
}
vector<long long >isprime(MAX_SIZE, true);
vector<long long >prime;
vector<long long >SPF(MAX_SIZE);

ll power(ll,ll);
void id7(ll N = 36123 )
{

    isprime[0] = isprime[1] = false ;


    for (long long int i=2; i<N ; i++)
    {
        if (isprime[i])
        {
            prime.push_back(i);
            SPF[i] = i;
        }
        for (long long int j=0;
                j < (int)prime.size() &&
                i*prime[j] < N && prime[j] <= SPF[i];
                j++)
        {
            isprime[i*prime[j]]=false;
            SPF[i*prime[j]] = prime[j] ;
        }
    }
}




ll id10(int x)
{
    ll g = 1 ;
    


    while (x != 1)
    {

        x = x / SPF[x];

    }
    return g;
}





ll countWays(ll n)
{

    ll count = 0;


    for (ll i = 1; i * i < n; i++)
        if (n % i == 0)
            count++;


    return count;
}

ll gcd(ll i,ll m)
{
    ll k = __gcd(i, m);
    cout<<"k:"<<k<<endl;
    if( k == 1&&i !=1)return 0;
    else if( k == 1&&i==1)return 1;
    else if(i/k == m)return 1;
    else return gcd(i/k,m);

}

vector<ll>weight;
vector<vector<ll>>adj_list;
void id2(ll k, string &p)
{
    if(k == 0 )
    {
        p='0'+p;
        ll k1 = p.length();
        while(k1 != 30)
        {
            p = '0'+p;
            k1++;

        }
        return  ;
    }
    else if(k%2==0)
    {
        p='0'+p;
    }
    else p='1'+p;
    id2(k>>1,p);




}
ll  id3(ll  &k, string lk )
{
    for(auto i = 0 ; i< lk.length(); i++)
    {
        if(lk[i]=='1')k+=power1(2, lk.length()-1-i);

        

    }
    return 0 ;
}  ;


string desired_string ;
ll id0(string & t, string & z)
{
    for(auto i = 0 ;  i < max(t.length(), z.length()) ; i++)
    {
        if(desired_string[i] == '1')
        {
            if(t[i]=='1')z[i]= '0';
            else z[i] = '1' ;
        }
        else
        {
            if(t[i]=='1')z[i]= '1';
            else z[i] = '0' ;

        }
    }
    

    return 0 ;

}




ll p;
vector<pair<ll,ll>>freq;
ll k1;
ll check(ll i )  

{


}











vector<vector<char >>matrix;
vector<vector<ll>>viber;


ll id5(ll k )
{
    vector<ll>dp;
    if (k < 0 )
    {
        return  0  ;
    }
    else return !dp[k] ;
}
ll helper(int i,  int mask, int n)
{
    vector<vector<ll>>dp ;
    

    

    

    ll answer = 0 ;
    if(i == n)
    {
        return   1 ;
    }
    if(dp[i][mask] != -1)
    {
        return dp[i][mask];
    }
    else
    {
        for( auto j = 0 ; j < n  ; j++)
        {
            

            if(viber[i][j] && mask&(1<<j))
            {
                answer=(answer%mod + helper(i+1,mask^ (1<<j), n)%mod);
            }

        }
        return  dp[i][mask] =  answer;



    }

}
ll dfs_temp(ll node,ll parent)
{
    vector<ll>dp;
    cout<<"called"<<endl ;
    ll id9 = 1;
    for(auto i : viber[node])
    {
        if(i!= parent)
            id9*=(dfs_temp(i, node)+1) ;
    }
    dp[node] = id9;
    for(auto i :viber[node])
    {
        if(i!= parent)        dp[i] += (id9/(dp[i]+1)+1);

    }
    return id9;

}

void add_self(ll &a, ll b )
{
    a = (a%mod+b%mod)%mod;



}
ll id1(ll a, ll b )
{
    return (a%mod+b%mod)%mod;



}

ll n ;
ll  mul(ll  a, ll b)
{
    return  ((a%mod)* (b%mod))%mod;

}
vector<pair<ll, ll>>boo;
struct M
{
    vector<vector<ll>>t;

    M()
    {
        t.assign (n+1, vector<ll>(n+1));
    }
    M operator *(M const &b)const
    {
        M c =  M();
        for(int i = 1; i <= n ; i++)
        {
            for(int j = 1 ; j <= n ; j++)
            {
                for(int k = 1 ; k <=  n ; k++)
                {

                    add_self(c.t[i][k], mul(t[i][j], b.t[j][k]) );

                }
            }

        }


        return c ;
    }

};
bool bitchecker(

    ll i)
{
    ll count  = 0 ;
    while(i!= 0)
    {
        if(i%2)count++;
        i>>=1;

    }

    if(count%2 == 0)return true;
    else return false ;

}

ll inverse(ll num)
{
    ll h = num ;
    num =  (num ^ (n - 1));
    if(num)return num;
    else return h;
}



vector<ll>  solver(ll n)
{
    vector<ll>vec;
    for(auto i = 2 ; i<= sqrt(n) ; i++)
    {
        if(n%i == 0)
        {

            if(n/i != i)
            {
                vec.push_back(i) ;
                vec.push_back(n/i) ;
            }
            else vec.push_back(i) ;

        }


    }
    return vec;


}
map<ll,ll>fact ;
vector<ll>vect;
ll precompute()
{
    fact[0] = 1 ;


    ll temp = 1;
    ll fact1  = 1;
    ll count  =1;

    while(count <= 1000)
    {
        fact1 = mul(fact1, temp) ;

        fact[count] = fact1 ;
        temp++;
        count++;




    } 


    return  0 ;
}
vector<pair<ll,ll>>vecin;
ll subset()
{
    ll n = vect.size();
    ll t =1ll<<n;
    for(auto i = 0 ; i< t ; i++)
    {
        ll sum = 0 ;
        for(auto j  = 0 ; j< n ; j++)
        {
            if(1ll<<j & i)
            {
                sum+=vect[j];
            }
        }
        ll     k = i;
        ll count  = 0 ;
        while(k)
        {
            if(k%2)count++;
            k>>=1;


        }
        vecin.push_back(make_pair(sum,count ));


    }
    

    return 0 ;
}


unsigned long long power(unsigned long long x,
                         int y, int p)
{
    unsigned long long res = 1; 


    x = x % p; 

    


    while (y > 0)
    {

        

        if (y & 1)
            res = (res * x) % p;

        

        y = y >> 1; 

        x = (x * x) % p;
    }
    return res;
}



unsigned long long modInverse(unsigned long long n,
                              int p)
{
    return power(n, p - 2, p);
}





unsigned long long id8(  long long n,
                                   ll r, int p = mod)
{
    

    if (n < r)
        return 0;
    

    if (r == 0)
        return 1;

    

    

    

    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;

    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p)
           % p;
}


ll solve( )
{


    ll   r,l, j,m,q,  d,  n1,m1,k, x,  a1;
    string str1;
    string str2;
    cin>>n ;
    vector<ll>vec(n); bhag(n, 0)cin>>vec[i] ;
     vector<ll>vec1(n); bhag(n, 0) vec1[i] = i+1;
   vector<ll>bhakt(n , 0 );
    for(auto i = n-1 ; i >= 0 ; i-- ){
                   bhakt[i] =  0 ;
                    while(vec[i] != vec1[i]){
                              ll index = 0;
                              for( j = 0 ;  j <= i-1 ; j++ )
                                    if(vec[j] ==   vec1[i])index  = j;
                            index++;
                            rotate(vec.begin() , vec.begin()+index ,vec.end()) ;
                             bhakt[i] =  index;
                    }
                    vec.pop_back();




    }
    for(auto i : bhakt)cout<<i<<" ";
    cout<<"\n";


    

    return  0 ;


}


int  main()
{










    ll t= 1;
    cin>>t;
    



    while(t--)
    {
        


        

        solve();
        

    }



    return 0;
}












