












































const int N=212;
using namespace std;
map<ll,ll>mp;
int main(){


for(ll i=1;i<=10000;i++)
	{
	    mp[i*i*i]=1;
			
	}
int t;
scanf("%d",&t);

while(t--){
	ll n;
	scanf("%lld",&n);
	int flag=0;
for(ll i=1;i<=10000;i++)
{
	

	

		if(mp[n-i*i*i]==1)
	{
		flag=1;
		break;
	}
	
}
	if(flag==1)
	printf("YES\n");
	else
	printf("NO\n");
}

return 0;
}





		



  	   	     	 		 	 	  	  				 	