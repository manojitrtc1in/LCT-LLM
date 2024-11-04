





using namespace std;


























 
ll minn(ll a,ll b)
{
	return a<b?a:b;
}
 
ll maxx(ll a,ll b)
{
	return a>b?a:b;
}



ll cill(ll a,ll b)
{
	if(a%b==0)
	return a/b;
	return a/b+1;
}




ll abss(ll a)
{
	if(a>=0) return a;
	else return -1*(a);
}



long double get_angle(pii a,pii b,pii c)
{
     int x1=a.first;
	 int y1=a.second;
	 int x2=b.first;
	 int y2=b.second;
	 int x3=c.first;
	 int y3=c.second;
     long double len1=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	 long double len2=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	 long double val=((x1-x2)*(x3-x2)+(y1-y2)*(y3-y2))/(len1*len2);
	 return acos(val);

}


long double id1(pii point1,pii point2)
{
	long double temp_ans;
	temp_ans=((point1.first-point2.first)*(point1.first-point2.first));
	temp_ans+=((point1.second-point2.second)*(point1.second-point2.second));
	return sqrt(temp_ans);
}

int id2(pii p1,pii p2,pii p3)
{
	int x1=p1.first;
	int y1=p1.second;
	int x2=p2.first;
	int y2=p2.second;
	int x3=p3.first;
	int y3=p3.second;

    ll ans=(x3-x1)*(y1-y2)-(y3-y1)*(x1-x2);
	if(ans>=0) return 1;
	else return -1;

}

ll cnt_div(ll n,ll k)
{
	ll cnt=0;
	while(n%k==0)
	{
		cnt++;
		n/=k;
	}
	return cnt;
}

ll gcd(ll a,ll b)
{
	if(a%b==0) return b;
	return gcd(b,a%b);
}

ll lcm(ll a,ll b)
{
	ll g=gcd(a,b);
	return (a*b)/g;
}



























        
	



















































	




	







	

































	





























































































 
 






	


    	




    	


	










	








    








	


	


   








    


    
		
	


 
 
 








	


    	




    	


	










	








    








 




	












 




    



    


 
	






	




	
	




	








    








	


	


	








    


 
	
 	
 	





























	































































ll n;

ll dp[1001][1001][2];

ll get_ans(int i,int k,bool b)
{
	if(i==0||i==n+1||k==1) return 0;
	if(dp[i][k][b]!=-1) return dp[i][k][b];
	if(b==0)
	return dp[i][k][b]=(1+get_ans(i-1,k,0)%MOD+get_ans(i+1,k-1,1)%MOD)%MOD;
	else 
	return dp[i][k][b]=(1+get_ans(i+1,k,1)%MOD+get_ans(i-1,k-1,0)%MOD)%MOD;

}

ll id0(ll n)
{
	ll sum =0 ;
	while(n)
	{
		sum+=(n%10);
		n/=10;
	}
	return sum;
}

ll count_digits(ll n)
{
	ll ans=0;
	while(n)
	{
      ans++;
	  n/=10;
	}
	return ans;
}


void solve(int t)
{


int n,m;
cin>>n>>m;
vector<vi>v;
map<ll,ll>counter;
for(int i=0;i<m;i++)
{
	int k;
	cin>>k;
	vi temp;
	for(int j=0;j<k;j++)
	{
		int x;
	    cin>>x;
        temp.push_back(x);
		counter[x]++;
	}
	sort(all(temp));
	v.push_back(temp);
}

for(int i=1;i<=n;i++)
counter[i]=minn(counter[i],cill(m,2));





ll sum = 0;
for(int i=1;i<=n;i++)
sum+=counter[i];

if(sum<m) {
	cout<<"NO"<<endl;
	return ;
}

counter.clear();


vpii temporder;
for(int i=0;i<v.size();i++)
temporder.push_back({v[i].size(),i});

sort(all(temporder));

vi order;
for(auto x:temporder)
order.push_back(x.second);





vi ansv(m,0);

for(int i=0;i<m;i++)
{
	int idx = order[i];
	bool flag=false;
	for(int j=0;j<v[idx].size();j++)
	if(counter[v[idx][j]]<cill(m,2))
	{
		ansv[idx]=v[idx][j];
		counter[v[idx][j]]++;
		flag=true;
		break;
	}

	if(flag==false)
	{
		cout<<"NO"<<endl;
		return ;
	} 
      
	
}

cout<<"YES"<<endl;
for(auto x:ansv)
cout<<x<<" ";
cout<<endl;



}

 
 
int main()
{





	




int t;

scanf("%d",&t);
for(int i=1;i<=t;i++)
solve(1);


 
}









