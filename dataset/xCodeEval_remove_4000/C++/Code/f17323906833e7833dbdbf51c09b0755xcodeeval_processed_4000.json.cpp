






































const ll INF = 1ll<<60;


using namespace std;




int main(){

	ll n;
	cin>>n;
	ll k=0;
	ll i=1;
	while(i!=n)
	{
		k+=1;
		i*=2;
	}
	ll x12,x13,a12,a13,a23;
	cout<<"XOR 1 2"<<endl;
	cin>>x12;
	cout<<"XOR 1 3"<<endl;
	cin>>x13;
	cout<<"AND 1 2"<<endl;
	cin>>a12;
	cout<<"AND 1 3"<<endl;
	cin>>a13;
	cout<<"AND 2 3"<<endl;
	cin>>a23;
	vi a(n+1);
	ll ans,ans1,ans2,ans3,ans4,ans5,ans6;
	for(i=0;i<k;i++)
	{
		ll cb=x12&(1<<i);
		if(!cb)
		{
			 ans5=a12&(1<<i);
			if(ans5)
			{
				a[1]+=(1<<i);
				a[2]+=(1<<i);
				 ans6=x13&(1<<i);
				if(ans6==0)
				{
					a[3]+=(1<<i);
				}
			}
			else
			{
				 ans4=x13&(1<<i);
				if(ans4!=0)
				{
					a[3]+=(1<<i);
				}
			}
		}
		else
		{
			

			 ans=x13&(1<<i);
			if(ans==0)
			{
				 ans2=a13&(1<<i);
				if(ans2)
				{
					a[1]+=(1<<i);
					a[3]+=(1<<i);
				}
				else
				{
					

					a[2]+=(1<<i);
				}
			}
			else
			{
				 ans3=a23&(1<<i);
				if(ans3)
				{
					a[2]+=(1<<i);
					a[3]+=(1<<i);
				}
				else
				{
					a[1]+=(1<<i);
				}
			}
		}
	}
	ll val;
	repi(4,n+1)
	{
		cout<<"XOR 1 "<<i<<endl;
		cin>>val;
		a[i]=val^a[1];
	}
	cout<<"!"<<" ";
	for(i=1;i<n+1;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;

  return 0;
}
