
#include <bits/stdc++.h>
using namespace std;
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
#define all(x) x.begin(),x.end()
void fastInOut();
int maxXor(int l, int r) {
int a=l,b=l,c,max=-1;
while(true){
	if(b>r) { a++; b=a;}
	if(a>r&&b>r) break;
	c=a^b;
	if(c>max)
	max=c;
	b++;
}
return max;
}
long long magi;
vector<long long> magg;
void magic(string s)
{
	stringstream(s)>>magi;
	magg.push_back(magi);
	if(s.size()>=11)
		return;
	magic(s+'1');
	magic(s+"14");
	magic(s+"144");
}
int mood;
void print(int n,int l)
{
	if(!l) return;
	print(n>>1,l-1);
	cout<<(n&1)<<endl;
}
unsigned long long power(unsigned long long b,unsigned long long pow)
{
	if(b==0) return 0;
	else if(pow==1) return b;
	else if(pow%2==0) return power(b*b,pow/2);
	else return b*power(b*b,pow/2);
}
string final;
int dp[100][100],res;
vector<int> v;
int summ(int i,int sum)
{
	if(sum==res) {final="YES"; return 1;}
	if(i==(int)v.size()) return 0;
	if(dp[i][sum]!=-1) {cout<<dp[i][sum]<<endl;   return dp[i][sum];}
	return dp[i][sum]=max(summ(i+1,sum+v[i]),summ(i+1,sum));
}
char check(vector<int> vl,vector<int> vr)
{
	int suml=accumulate(vl.begin(),vl.end(),0);
	int sumr=accumulate(vr.begin(),vr.end(),0);
	if(suml%2&&sumr%2) return 'o';
	if(suml%2==0&&sumr%2==0) return 'e';
	else return 'n';
}
bool gigaa(int x)
{
	while(x>0)
	{
		if(x%10==8) return true;
		x/=10;
	}
	return false;
}
vector<long long> vcode;
long long xxx;
void luky(string s)
{
	stringstream(s)>>xxx;
	vcode.push_back(xxx);
	if(s.size()>=4) return;
	for(char i=48;i<58;i++)
	{
		luky(s+i);
	}
}
int dr(string s)
{
	hell :int d=0;
	for(int i=0;i<(int)s.size();i++)
		d+=(s[i]-48);
	if(d<10) return d;
	else{
		stringstream ss;
		ss<<d;
		s=ss.str();
		goto hell;
	}
}
string pluss(string s)
{
	for(int i=s.size()-1;i>=0;i--)
	{
		if(s[i]=='9')
			s[i]=48;
		else{
			s[i]++;
			break;
		}
	}
	return s;
}
bool prim(int x)
{
	for(int i=x-1;i>1;i--)
	{
		if(x%i==0)
			return false;
	}
	return true;
}
int sam(int x)
{
	int samm=0;
	while(x>0)
	{
		samm+=x%10;
		x/=10;
	}
	return samm;
}
int powerr(double z,int i)
{
int zz=1;
for(int k=0;k<i;k++)
{
zz*=z;
}
return zz;
}
long long power(long long x,long long y)
{
	long long z=1;
	for(long long i=0;i<y;i++)
		z*=x;
	return z;
}
bool pal(string s)
{
	for(int i=0,k=s.size()-1;i<(int)(s.size()/2);i++,k--)
		if(s[i]!=s[k])
			return false;
	return true;
}
int y[60][60],n,m,ci,ck;
void paint(int ri,int rk)
{
	for(int i=min(ri,ci);i<=max(ri,ci);i++)
		for(int k=min(rk,ck);k<=max(rk,ck);k++)
			if(y[i][k]==1||y[i][k]==2) y[i][k]=2;
			else y[i][k]=-1;
}
bool check()
{
	for(int i=0;i<n;i++)
		for(int k=0;k<m;k++)
			if(y[i][k]==-1||y[i][k]==2);
			else return true;
	return false;
}
int checkc(int i,int k)
{
	int rr[]={0,n-1,0,n-1},cc[]={0,0,m-1,m-1},c=0,res=0;
	for(int f=0;f<4;f++)
	{
		c=0;
		for(int ii=min(i,rr[f]);ii<=max(i,rr[f]);ii++)
			for(int kk=min(k,cc[f]);kk<=max(k,cc[f]);kk++)
				if(y[ii][kk]==0||y[ii][kk]==1)
					c++;
		if(c>res) {res=c; ci=rr[f]; ck=cc[f];}
	}
	return res;
}
int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt", "rt", stdin);
#endif
fastInOut();


 


  





  


  


 


 


  


 








  


 


 




 


 


  


  


 


  





 


  





 





 


  


 





 


 





  





 


  


 


  


 





 








 


 


 


 


 


 








  





 


 








 


  


  








 


 


  





 


 





 


 


 





 


  


 


	


 




 

 


 











  

















 




 




  




  









  









 




 




 





  
  

 


  
  	

	
 

  
	

	








 


	


 string arr[3],s,q,res;
 int i;
 for(i=0;i<3;i++)
	 cin>>arr[i];
 for(i=0;i<3;i++){
	 s="";
	 for(int k=0;k<arr[i].size();k++)
		 if((arr[i][k]>=65&&arr[i][k]<=90)||(arr[i][k]>=97&&arr[i][k]<=122))
			 s+=arr[i][k];
	 for(auto& m:s)
		 m=tolower(m);
	 arr[i]=s;
 }
 cin>>n;
 while(n--){
	 cin>>s;
	 q="";
	 for(int k=0;k<s.size();k++)
	 		 if((s[k]>=65&&s[k]<=90)||(s[k]>=97&&s[k]<=122))
	 			 q+=s[k];
	 for(auto& m:q)
	 		 m=tolower(m);
	 sort(arr,arr+3);
	 res="WA";
	 if(q.size()!=arr[0].size()+arr[1].size()+arr[2].size())
		 res="WA";
	 else do{
		if(q==arr[0]+arr[1]+arr[2])
			{res="ACC";
			break;
			}
	}while(next_permutation(arr,arr+3));
	 cout<<res<<endl;
 }
return 0;
}
void fastInOut() {
   ios_base::sync_with_stdio(0);
   cin.tie(NULL), cout.tie(NULL);
}
