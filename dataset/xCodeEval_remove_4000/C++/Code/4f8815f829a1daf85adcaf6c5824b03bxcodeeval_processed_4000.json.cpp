

 


















using namespace std;

typedef long long LL;
   bool isPrime(int n)
{
    

    if (n <= 1)  return false;
    if (n <= 3)  return true;

    

    

    if (n%2 == 0 || n%3 == 0) return false;

    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;

    return true;
}




































































const long long MAX_SIZE = 1000001;











vector<long long >isprime(MAX_SIZE , true);
vector<long long >prime;
vector<long long >SPF(MAX_SIZE);



void id0(int N)
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

ll power(ll x,ll y,ll p)
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
    return res%p;
}

int main()
{
    fastio;
    

    

    ll i,j,n,m,b,t,k,a,c,d;

    cin>>t;

    while(t--)
    {
        cin>>n;

        ll p[6] = {6,10,14,15,18,21};

        ll flag = 0;
        for(i=0;i<5;i++)
        {
            a = p[i];
            b = p[i+1];
            for(j = i+2;j < 6;j++)
            {
                c = p[j];

                d = n -(a+b+c);

                

                if(d > 0 && d != a && d != b && d != c)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
            {
                break;
            }
        }

        if(flag == 1)
        {
            cout<<"YES\n";
            cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
        }
        else
        {
            cout<<"NO\n";
        }

    }
    return 0;
}

