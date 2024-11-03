



using namespace std;






int main()
{
    fast;
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,j;
        cin>>n;
        map<ll,ll> mp;
        ll a=0;
        for(int i=0;i<n;i++)
        {
            ll x;
            cin>>x;
            x-=i;
            if(mp.count(x))
                a+=mp[x];
            mp[x]++;
        }

        cout<<a<<endl;

    }


    return 0;
}

		   	 	  		 			 		 	    			 	