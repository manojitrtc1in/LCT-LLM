
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
vector<int> vg,resg;
int sg;
void coin(int i,vector<int> vgg,int sum)
{
	if(sum>=sg&&(*min_element(all(vgg)))>sum-sg)
			{if(vgg.size()>resg.size())
			resg=vgg;
			return;}
		if(i==(int)vg.size())
		 return;
		vgg.push_back(vg[i]);
		coin(i+1,vgg,sum+vg[i]);
		if(!vgg.empty()) vgg.pop_back();
		coin(i+1,vgg,sum);
}
int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt", "rt", stdin);
#endif


fastInOut();


 


  





  


  


 


 


  


 








  


 


 




 


 


  


  


 


  





 


  





 





 


  


 





 


 





  





 


  


 


  


 





 








 


 


 


 


 


 








  





 


 








 


  


  








 


 


  





 


 





 


 


 





 


  


 


	


 




 

 


 











  

















 




 




  




  









  









 




 




 





  
  

 


  
  	

	
 

  
	

	








 


	


 







 


 


 





 





 





 





 


 





 int n,r,x;
 vector<int> v,vv;
 multimap<int,int> m;
 cin>>n;
 while(n--){
	 cin>>x;
	 v.push_back(x);
 }
 vv=v;
 if(count(all(v),v[0])==v.size()){
	 cout<<"Exemplary pages.";
	 return 0;
 }
 int mm=0;
 for(int i=0;i<v.size();i++){
	 sort(all(v));
	 if(count(all(v),v[0])==v.size())
		 break;
	 r=(v[v.size()-1]-v[0]);
	 if(r%2||mm>0){
		 goto hell;
	 }
	 if(r==0) break;
	 r/=2;
	 if(r) m.insert({v[v.size()-1],v[0]});
	 v[0]+=r;
	 v[v.size()-1]-=r;
	 mm++;
 }
 int f,t;
 if(count(all(v),v[0])==v.size()){
	 for(auto i:m){
		for(int k=0;k<vv.size();k++){
			if(vv[k]==i.first)
				t=k+1;
			if(vv[k]==i.second)
				f=k+1;
		}
		 cout<<(i.first-i.second)/2<<" ml. from cup #"<<f<<" to cup #"<<t<<".\n";
	 }
	 }
 else{
	 hell: cout<<"Unrecoverable configuration.";
 }
return 0;
}
void fastInOut() {
   ios_base::sync_with_stdio(0);
   cin.tie(NULL), cout.tie(NULL);
}
