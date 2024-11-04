#include<bits/stdc++.h>
#include<map>
#include<iostream>
#include<math.h>
#include<vector>
#include <utility>
using namespace std;
#define zhalok Zhalok
#define inf 1e9+1
#define ll long long int  
#define ull unsigned long long 
#define loop(i,a,b) for(ll i=a;i<b;i++)
#define negloop(i,a,b) for(ll i=a;i>=b;i--)
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define pb push_back
#define be begin()
#define en end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define ff first
#define ss second
#define MOD 1000000007
#define sz 50001
#define ub upper_bound
#define lb lower_bound
#define all(v) v.begin(),v.end()
#define eps 1e-8
#define pi acos(-1.0)

 
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


long double find_point_dis(pii point1,pii point2)
{
	long double temp_ans;
	temp_ans=((point1.first-point2.first)*(point1.first-point2.first));
	temp_ans+=((point1.second-point2.second)*(point1.second-point2.second));
	return sqrt(temp_ans);
}

int check_sidde(pii p1,pii p2,pii p3)
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

void build_for_sum(int idx,int lo,int hi)
{
	if(lo == hi) {
		tree[idx]=v[lo];
		return ;
	}

	int mid = (lo + hi)/2;
	int left = 2*idx+1;
	int right = 2*idx+2;
	
	build_for_sum(left,lo,mid);
	build_for_sum(right,mid+1,hi);
	tree[idx]=tree[left]+tree[right];
}


void build_for_min(int idx,int lo,int hi)
{
	if(lo==hi)
	{
		tree[idx]=v[lo];
		return ;
	}

	int mid = (lo+hi)/2;
	int left = 2*idx+1;
	int right = 2*idx+2;
	build_for_min(left,lo,mid);
	build_for_min(right,mid+1,hi);
	tree[idx]=minn(tree[left],tree[right]);
}


void update_for_sum(int idx,int lo,int hi,int upidx,int val)
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
	update_for_sum(left,lo,mid,upidx,val);
	update_for_sum(right,mid+1,hi,upidx,val);

	tree[idx] = tree[left]+tree[right];

}


































	



ll query_of_sum(int idx,int lo,int hi,int qlo,int qhi)
{
	if(qlo>hi||qhi<lo) return 0;
	if(qlo<=lo&&qhi>=hi) return tree[idx];

	int mid = (lo+hi)/2;
	int left = 2*idx+1;
	int right = 2*idx+2;
	return query_of_sum(left,lo,mid,qlo,qhi) + query_of_sum(right,mid+1,hi,qlo,qhi);


}










    









	






ll query_for_kth_one(int idx,int lo,int hi,int k)
{
	if(lo==hi)
	return hi;
	
    int mid = (lo+hi)/2;
	int left = 2*idx+1;
	int right = 2*idx+2;
	
    if(tree[right]>=k) return query_for_kth_one(right,mid+1,hi,k);
	else return query_for_kth_one(left,lo,mid,k-tree[right]);
    
	return 0;

}







ll get_digit_sum(ll n)
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









   




















	













































































int dp[1005][1005][2][2];

int func(int zeros,int mismatch,bool rev,bool mid){

	if(zeros==0) return 0;

	if(dp[zeros][mismatch][rev][mid]!=-1) return dp[zeros][mismatch][rev][mid];
    
	ll ans = 100000 ;
    
    if(rev==0&&mismatch>0) ans = minn(ans,zeros-func(zeros,mismatch,1,mid));

	if(mid==0) ans = minn(ans,zeros-func(zeros-1,mismatch,0,1));

	if(mismatch>0) ans = minn(ans,zeros-func(zeros-1,mismatch-1,0,mid));

	if(zeros-mismatch>1) ans = minn(ans,zeros-func(zeros-1,mismatch+1,0,mid));

	return dp[zeros][mismatch][rev][mid]=ans;

}

int calculate_mismatch(string s)
{
	int i=0;
	int j=s.size()-1;

    int cnt=0;
	while(i<j) {

		if(s[i]!=s[j])
		cnt++;
		i++;
		j--;

	}

	return cnt;
}

int calculate_zeros(string s)
{
	int cnt=0;
	for(int i=0;i<s.size();i++)
	if(s[i]=='0') cnt++;

	return cnt;
}

void solve(int t)
{


int n;
cin>>n;
string s;
cin>>s;

int mismatch=calculate_mismatch(s);
int zeros=calculate_zeros(s);
int mid ;
if(s[(s.size()-1)/2]=='0'&&(s.size()%2==1)) mid = 0;
else mid=1;
int alice = func(zeros,mismatch,0,mid);

int bob=zeros-alice;


if(alice<bob) cout<<"ALICE"<<endl;
else if(alice==bob) cout<<"DRAW"<<endl;
else cout<<"BOB"<<endl;


}

 
 
int main()
{







memset(dp,-1,sizeof dp);
	
int t;





scanf("%d",&t);
for(int i=1;i<=t;i++)
solve(1);


 
}








