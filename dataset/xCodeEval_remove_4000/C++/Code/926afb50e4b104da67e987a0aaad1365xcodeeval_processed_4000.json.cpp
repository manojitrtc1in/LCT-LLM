







using namespace std;

int prime_factor(int number)
{
	int count = 0;
	for (int i = 2; i * i <= number; i++)
	{
		while (number % i == 0)
		{
			count++;
			number /= i;
		}
	}
	if (number != 1)
		count++;
	return count;
}

 

ll const N=2e6;
ll a[N],b[N];
vector<ll>v;
void print(ll x)
{
    if(x>4444477777 )return;
    v.push_back(x);
    print(x*10+4);
    print(x*10+7);
}

int main()
{
  int tc;cin>>tc;
  while(tc--)
  {
      int n;cin>>n;
      bool can=0;
      ll s=0;
      priority_queue<ll>pq1,pq2,pq3;
      for(int i=0;i<n;i++)
      {
          cin>>a[i];
          s+=a[i];
          pq1.push(a[i]);
      }
      pq2.push(s);
      while(!pq1.empty()|| !pq2.empty())
      {
          if(pq2.top()==pq1.top())
          {
              pq2.pop();pq1.pop();
          }
          else if(pq2.top()<pq1.top()){
            break;
          }
          else{
            ll x=pq2.top();
            if(x%2==0)
            {
                x/=2;
                pq2.pop();
                pq2.push(x);pq2.push(x);
            }
            else{
                ll y=(x+1)/2;
                x=(x-1)/2;
                pq2.pop();
                pq2.push(x);pq2.push(y);
            }
          }
          if(pq2.empty()|| pq1.empty())
          {
              can=1;
              break;
          }
      }
      if(can)cout<<"YES"<<el;
      else cout<<"NO"<<el;
  }
}

			     	  	 		    	 			    		