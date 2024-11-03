
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
bool col(vector<string> v){
	for(int i=0;i<(int)v.size()-1;i++)
		if(v[i]>v[i+1])
			return false;
	return true;
}
int fed(vector<int> v,int t,int k){
	int c=0,temp;
	for(int i=0;i<(int)v.size();i++){
		temp=t;
		int r=0;
		while(temp||v[i]){
			if((v[i]&1)!=(temp&1)) r++;
			temp>>=1;
			v[i]>>=1;
		}
		if(r<=k) c++;
	}
	return c;
}
int chil(int x){
	int c=0;
	while(x){
		if((x&1)==1) break;
		x>>=1;
		c++;
	}
	c=1<<c;
	return c;
}
void bea(string s,int i){
	if((int)s.size()>i) return;
	if((int)s.size()==i)cout<<s<<endl;
	bea(s+'1',i);
	bea(s+'2',i);
	bea(s+'3',i);
}
int rrev;
int rev(int x){
	if(x==0) return rrev;
	rrev=rrev*(10)+(x%10);
	return rev(x/10);
}
int truk(int n,int m){
	if(n<=m) return 1;
	return truk(n/2,m)+truk((n+1)/2,m);
}
string paal;
bool repal;
void pal(int s,int e){
	
	if(s>=e) return;
	if(!isalpha(paal[s])) {pal(s+1,e); return;}
	if(!isalpha(paal[e])) {pal(s,e-1); return;}
	if(tolower(paal[s])!=tolower(paal[e])) { repal=false; return;}
	pal(s+1,e-1);
}
int eas(int x){
	if(x==1) return 1;
	if(x&1) return eas(3*x+1)+1;
	else return eas(x/2)+1;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("input.txt", "rt", stdin);


#endif


fastInOut();





 


 





	





 


	



























 























 
















































 


 


 










 


 







	


 


 


 





 


 


 


 








































 

 



 


 


 


 








 


	













 


 








 




 


 


 







 


 





 







 










int n,m,x,k,y,arr[100100]={0},arrl[100100]={0},s,e;
 cin>>n>>m;
 bool ok,in[100100]={0},inl[100100]={0};
 vector<int> v;
 vector<pair<int,int>> res,l;
 while(n--){
	 cin>>x;
	 v.push_back(x);
 }
 s=0,e=0;
 ok=true;
 while(e<v.size()-1){
	 if(v[e]<=v[e+1]){
		 if(ok){
			 e++;
			 if(e==v.size()-1)
				 res.push_back({s,e});
		 }
		 else{
			 res.push_back({s,e});
			 s=e;
			 ok=true;
		 }
	 }
	 else{
		 ok=false;
		 e++;
		 if(e==v.size()-1)
		 	 res.push_back({s,e});
	 }
 }
 e=s=0;
  while(e<v.size()-1){
 	 if(v[e]>=v[e+1]){
 		 e++;
 		 if(e==v.size()-1)
 			 l.push_back({s,e});
 	 }
 	 else{
 		 if(s!=e) l.push_back({s,e});
 		 s=e;
 		 e++;
 	 }
  }
 ok=false;
 k=0;
 if(res.size()>0)
 for(int i=0;i<100100;i++){
	 if(res[k].first==i)
		 ok=1;
	 if(res[k].second==i&&ok){
		 ok=0;
		 arr[i]=k+1;
		 k++;
		 if(k==res.size())
			 break;
		 if(res[k].first==i){
			 ok=1;
			 in[i]=1;
		 }
	 }
	 if(ok) arr[i]=k+1;
 }
  ok=false;
   k=0;
   if(l.size()>0)
   for(int i=0;i<100100;i++){
  	 if(l[k].first==i)
  		 ok=1;
  	 if(l[k].second==i&&ok){
  		 ok=0;
  		 arrl[i]=k+1;
  		 k++;
  		 if(k==l.size())
  			 break;
  		 if(l[k].first==i){
  			 ok=1;
  			 inl[i]=1;
  		 }
  	 }
  	 if(ok) arrl[i]=k+1;
   }
 while(m--){
	 cin>>x>>y;
	 x--,y--;
	 if(x==y){
		 cout<<"Yes\n";
		 continue;
	 }
	 if(arr[x]&&arr[y]){
		 if(arr[x]==arr[y]){
		 cout<<"Yes\n";
		 continue;
		 }
		 else{
			 if(arr[y]-arr[x]==1&&in[y]){
				 cout<<"Yes\n";
				 continue;
			 }
		 }
	 }
	 if(arrl[x]&&arrl[y]){
	 		 if(arrl[x]==arrl[y]){
	 			 cout<<"Yes\n";
	 			  continue;
	 		 }
	 		 else{
	 			 if(arrl[y]-arrl[x]==1&&inl[y]){
	 			 				 cout<<"Yes\n";
	 			 				 continue;
	 			 			 }
	 		 }
	 	 }
	 cout<<"No\n";
 }
}
void fastInOut() {
   ios_base::sync_with_stdio(0);
   cin.tie(NULL), cout.tie(NULL);
}
