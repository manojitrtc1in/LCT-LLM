





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




 
ll mod_exp(ll a,ll n,ll mod)
{
	if(n==0) return 1;
	if(n%2==0){
		ll temp=mod_exp(a,n/2,mod);
		return (temp%mod*temp%mod)%mod;
	}
	else {
		ll temp1=a;
		ll temp2=mod_exp(a,n-1,mod);
		return (temp1%mod*temp2%mod)%mod;
	}
	
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


long double id5(pii point1,pii point2)
{
	long double temp_ans;
	temp_ans=((point1.first-point2.first)*(point1.first-point2.first));
	temp_ans+=((point1.second-point2.second)*(point1.second-point2.second));
	return sqrt(temp_ans);
}

int id6(pii p1,pii p2,pii p3)
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



























        
	



















































	




	







	

































	





























































































 
 






	


    	




    	


	










	








    








	


	


   








    


    
		
	


 
 
 








	


    	




    	


	










	








    








 




	












 




    



    


 
	






	




	
	




	








    








	


	


	








    


 
	
 	
 	



int n,q;
vll v;
ll tree[4*sz];

void id7(int idx,int lo,int hi)
{
	if(lo == hi) {
		tree[idx]=v[lo];
		return ;
	}

	int mid = (lo + hi)/2;
	int left = 2*idx+1;
	int right = 2*idx+2;
	
	id7(left,lo,mid);
	id7(right,mid+1,hi);
	tree[idx]=tree[left]+tree[right];
}


void id1(int idx,int lo,int hi)
{
	if(lo==hi)
	{
		tree[idx]=v[lo];
		return ;
	}

	int mid = (lo+hi)/2;
	int left = 2*idx+1;
	int right = 2*idx+2;
	id1(left,lo,mid);
	id1(right,mid+1,hi);
	tree[idx]=minn(tree[left],tree[right]);
}


void id4(int idx,int lo,int hi,int upidx,int val)
{
	if(lo>upidx||hi<upidx) return ;
	if(lo == hi)
	{
		

		tree[idx]+=val;
		return ;
	}

	int mid = (lo+hi)/2;
	int left = 2*idx+1;
	int right = 2*idx+2;
	id4(left,lo,mid,upidx,val);
	id4(right,mid+1,hi,upidx,val);

	tree[idx] = tree[left]+tree[right];

}


































	



ll id3(int idx,int lo,int hi,int qlo,int qhi)
{
	if(qlo>hi||qhi<lo) return 0;
	if(qlo<=lo&&qhi>=hi) return tree[idx];

	int mid = (lo+hi)/2;
	int left = 2*idx+1;
	int right = 2*idx+2;
	return id3(left,lo,mid,qlo,qhi) + id3(right,mid+1,hi,qlo,qhi);


}










    









	






ll id2(int idx,int lo,int hi,int k)
{
	if(lo==hi)
	return hi;
	
    int mid = (lo+hi)/2;
	int left = 2*idx+1;
	int right = 2*idx+2;
	
    if(tree[right]>=k) return id2(right,mid+1,hi,k);
	else return id2(left,lo,mid,k-tree[right]);
    
	return 0;

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









   




















	

















































































vll fact ;

void id8()
{
	fact.push_back(1);
	ll factor=1;
	for(int i=1;i<=200000;i++)
	{
		factor*=i;
		factor%=MOD;
		fact.push_back(factor);
	}
}

void solve(int t)
{

int n;
cin>>n;
vll v;


for(int i=0;i<n;i++)
{
	ll x;
	cin>>x;
	
	v.push_back(x);
	
}

sort(all(v));

ll mn = v[0];

ll cnt = 0;


for(auto x:v) { if(x==mn) cnt++;

if((x&mn)!=mn) {
	cout<<"0"<<endl;
	return ;
}

}



if(cnt==1) cout<<0<<endl;
else {
	ll ans = 1;
	ans*=cnt;
	ans%=MOD;
	ans*=(ans-1);
	ans%=MOD;
	ans*=fact[n-2];
	ans%=MOD;
	cout<<ans<<endl;
}





}

 
 
int main()
{








	
int t;

id8();

scanf("%d",&t);
for(int i=1;i<=t;i++)
solve(1);


 
}








