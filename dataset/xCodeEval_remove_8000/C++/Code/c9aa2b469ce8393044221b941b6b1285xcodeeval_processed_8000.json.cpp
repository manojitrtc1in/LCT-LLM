
























































































































using namespace std;
typedef unsigned long long ll;
typedef unsigned long long ull;
typedef long double ld;















ll gcd(ll a, ll b)
{ 
    if (a == 0) 
        return b;  
    return gcd(b % a, a);
}  

ll id0(ll a, ll b)  
 {  
    return (a*b)/gcd(a, b);  
 }  

int gcd(int a, int b)
{ 
    if (a == 0) 
        return b;  
    return gcd(b % a, a);
}  

int id0(int a, int b)  
 {  
    return (a*b)/gcd(a, b);  
 }  



 






int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	

    

	

	
	ll t;
	cin>>t;
	int testcase=1;
	ll sum[70]={0};
	ll elements[70]={0};
	for(int i=1;i<70;i++)
	{
		sum[i]=sum[i-1]*2+i;
		elements[i]=elements[i-1]*2+1;
	}
	while(t--)
	{
		ll n;
		cin>>n;
		ll rem = n;
		ll ans=0;
		while(rem)
		{
			int idx=1;
			for(int i=1;i<70;i++)
			{
				if(elements[i]>rem)
				{
					idx=i-1;
					ans = ans+(idx+1);
					rem--;
					break;
				}
				if(elements[i]==rem)
				{
					idx = i;
					break;
				}
			}
			ans = ans+sum[idx];
			rem = rem - elements[idx];
		}
		cout<<ans<<endl;
	}
    return(0);	
}



























































































































