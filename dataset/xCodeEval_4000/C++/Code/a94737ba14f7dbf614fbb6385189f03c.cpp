
#include <bits/stdc++.h>
using namespace std;
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
#define all(x) x.begin(),x.end()
void fastInOut();
unsigned long long power(unsigned long long b,unsigned long long pow)
{
	if(b==0) return 0;
	else if(pow==1) return b;
	else if(pow%2==0) return power(b*b,pow/2);
	else return b*power(b*b,pow/2);
}
int power(int z,int i)
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
bool right(int arr[])
{
	int a[3];
	a[0]=power(arr[3]-arr[1],2)+power(arr[2]-arr[0],2);
	a[1]=power(arr[5]-arr[1],2)+power(arr[4]-arr[0],2);
	a[2]=power(arr[5]-arr[3],2)+power(arr[4]-arr[2],2);
	sort(a,a+3);
	if(a[0]+a[1]==a[2]&&(sqrt(a[0])*sqrt(a[1])*sqrt(a[2]))/2)
		return true;
	return false;
}
bool fed(int k,int f,int test){
	if(f<test) swap(f,test);
	int c=0;
	while(f){
		if((f&1)!=(test&1)) c++;
		f=f>>1;
		test=test>>1;
		if(c>k) return false;
	}
	if(c>k) return false;
	return true;
}
unsigned long long fact(long long a)
{
	unsigned long long res=1;
	for(long long i=a;i>0;i--)
		res*=i;
	return res;
}
unsigned long long comb(long long a,long long b)
{
	if((a-b)<b) b=a-b;
	if(a<=19) return fact(a)/(fact(a-b)*fact(b));
	if(a==b||b==0) return 1;
	if(b==1) return a;
	return comb(a-1,b-1)+comb(a-1,b);
}
bool palind(string s)
{
	for(unsigned int i=0,f=s.size()-1;i<s.size()/2;i++,f--)
		if(s[i]!=s[f])
			return false;
	return true;
}
int div(long long x)
{
	 double SqrtOfnumber;
	    SqrtOfnumber=sqrt(x);
	    int counter=1;
	    int i;
	    for(i=2;i<SqrtOfnumber;i++)
	    {
	        if(x%i==0)
	            counter++;
	    }
	    counter=counter*2;
	    if(i*i == x)
	    counter++;
	    return counter;
}
bool isprim(int x)
{
	for(int i=x-1;i>1;i--)
	{
		if(x%i==0)
			return false;
	}
	return true;
}
set<long long> prim(int n){
	n++;
	bool *arr=new bool[n];
	for(int i=0;i<n;i++)
		arr[i]=true;
	set<long long> se;
	for(int i=2;i*i<n;i++)
		if(arr[i])
			for(int k=i*i;k<n;k+=i)
				arr[k]=false;
	for(int i=2;i<n;i++)
		if(arr[i])
			se.insert(i);
	return se;
}
int n,m;
char arr[1010][1010];
bool pash(int x,int y){
	int s;
	s = 1;
	if (x + 1 < n && arr[x + 1][y] == 'b')
		s++;
	if (x + 1 < n && y + 1 < m && arr[x + 1][y + 1] == 'b')
		s++;
	if (y + 1 < m && arr[x][y + 1] == 'b')
		s++;
	if (s == 4)
		return true;
	s = 1;
	if (x - 1 >= 0 && arr[x - 1][y] == 'b')
		s++;
	if (x - 1 >= 0 && y + 1 < m && arr[x - 1][y + 1] == 'b')
		s++;
	if (y + 1 < m && arr[x][y + 1] == 'b')
		s++;
	if (s == 4)
		return true;
	s = 1;
	if (x - 1 >= 0 && arr[x - 1][y] == 'b')
		s++;
	if (x - 1 >= 0 && y - 1 >= 0 && arr[x - 1][y - 1] == 'b')
		s++;
	if (y - 1 >= 0 && arr[x][y - 1] == 'b')
		s++;
	if (s == 4)
		return true;
	s = 1;
	if (x + 1 < n && arr[x + 1][y] == 'b')
		s++;
	if (x + 1 < n && y - 1 >= 0 && arr[x + 1][y - 1] == 'b')
		s++;
	if (y - 1 >= 0 && arr[x][y - 1] == 'b')
		s++;
	if (s == 4)
		return true;
	return false;
}

string s;
void printt(int ind)
{
	if(ind==(int)s.size()) {
		cout << s << endl;
		return;
	}
	if(s[ind]=='?') {
		for(char i = 'a'; i<='z'; i++) {
			s[ind]=i;
			printt(ind+1);
			s[ind]='?';
		}
	}
	else {
		printt(ind+1);
	}
}
int main()
{
#ifndef ONLINE_JUDGE
freopen("input.txt", "rt", stdin);


#endif


fastInOut();





 


 





	





 


	



























 























 
















































 


 


 










 


 







	


 


 


 





 


 


 


 








































 

 



 


 


 


 








 int n,m,o=0,z=0,x,arr[1025]={0};
 cin>>n>>m;
 for(int i=0;i<m*n;i++){
	 cin>>x;
	 if(x==1||x==10) z++;
	 else if(x==11) o++;
 }
 int **y=new int*[1025];
  for(int i=0;i<1025;i++)
 	 y[i]=new int[1025];
  for(int i=0;i<1025;i++)
	  for(int k=0;k<1025;k++)
		  y[i][k]=0;


 for(int i=0;i<n;i++){

	 if(i%2)  for(int k=m-1;k>=0;k--){
		 if(o>0) {
					 y[i][k]=11;
					 o--;
				 }
				 else{
					 if(z>0){
					 if(arr[k]==0){
						 y[i][k]=10;
						 arr[k]=1;
					 }
					 else{
						 y[i][k]=1;
						 arr[k]=0;
					 }
					 z--;
				 }
				 }
 }


	 else for(int k=0;k<m;k++){
		 if(o>0) {
					 y[i][k]=11;
					 o--;
				 }
				 else{
					 if(z>0){
					 if(arr[k]==0){
						 y[i][k]=10;
						 arr[k]=1;
					 }
					 else{
						 y[i][k]=1;
						 arr[k]=0;
					 }
					 z--;
				 }
				 }
	 }
 }
 for(int i=0;i<n;i++){
	 for(int k=0;k<m;k++){
		 if(y[i][k]==1) cout<<0;
		 cout<<y[i][k];
		 if(y[i][k]==0) cout<<0;
		 if(k!=m-1) cout<<" ";
	 }
	 cout<<endl;
 }
}
void fastInOut() {
   ios_base::sync_with_stdio(0);
   cin.tie(NULL), cout.tie(NULL);
}
