
#include <bits/stdc++.h>
using namespace std;
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
	for(int i=0;i<s.size();i++)
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
int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt", "rt", stdin);
#endif
 


  





  


  


 


 


  


 








  


 


 




 


 


  


  


 


  





 


  





 





 


  


 





 


 





  


int k,d;
cin>>k>>d;
string f="1",l="9";
if(k==1) f="0";
bool end=false;
if(d==0&&k>1) goto hell;
for(int i=1;i<k;i++)
{
	f+=48;
	l+=57;
}
for(;end==false;)
{

	if(dr(f)==d)
	{
		cout<<f;
		return 0;
	}
	if(f==l) end=true;
	f=pluss(f);
}
hell :cout<<"No solution";
return 0;
 }
void fastInOut() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
}
