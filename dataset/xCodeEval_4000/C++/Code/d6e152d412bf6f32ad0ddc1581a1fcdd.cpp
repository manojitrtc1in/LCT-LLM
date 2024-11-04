
#include <bits/stdc++.h>
using namespace std;
void ox90()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
long long min(long long x[3])
{
	int min,z=0;
	if(x[0]>0) min=0;
	else if(x[1]>0) min=1;
	else if(x[2]>0) min=2;
	while(z++<3)
		if(x[z-1]<x[min]&&x[z-1]>0)
			min=z-1;
	return x[min];
}
void swap(int *x,int *y)
{
	int t=*x;
	*x=*y;
	*y=t;
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
void longsorting(long long y[],int n)
{
	int min;
	for(int i=0;i<n;i++)
	 {
		 min=i;
		 for(int k=i+1;k<n;k++)
			 if(y[k]<y[min])
				 min=k;
		 swap(y[i],y[min]);
	 }
}
void sorting(int y[],int n)
{
	int min;
	for(int i=0;i<n;i++)
	 {
		 min=i;
		 for(int k=i+1;k<n;k++)
			 if(y[k]<y[min])
				 min=k;
		 swap(y[i],y[min]);
	 }
}
void swap(unsigned int *x,unsigned int *y)
{
	unsigned int t=*x;
	*x=*y;
	*y=t;
}
int cake(char y[][11],int r,int c,int m)
{
	int d=0;
	for(int i=0;i<r;i++)
	{
		int count=0;
		for(int k=0;k<c;k++)
		{
		 if(!m){	if(y[i][k]!='S') count++;
			else break;}
		 else {
			 if(y[k][i]!='S') count++;
			else break;
		      }
		}
		if(count==c){
			for(int k=0;k<c;k++)
			{
				if(!m){if(y[i][k]!='e')
				{d++; y[i][k]='e';}}
				else{
					if(y[k][i]!='e')
					{d++; y[k][i]='e';}
			        }

		    }
		}
    }
	return d;
}
bool palind(string s)
{
	for(unsigned int i=0,f=s.size()-1;i<s.size()/2;i++,f--)
		if(s[i]!=s[f])
			return false;
	return true;
}
string reverse(string s)
{
	string d;
	for(int f=s.size()-1;f>=0;f--)
		d+=s[f];
	return d;
}
int gcd(int y,int z){
	if(z>y) swap(&z,&y);
	if(y==z) return y;
    for(int i=z;i>1;i--)
    {
        if(y%i==0&&z%i==0) return i;
    }
    return 1;
}
int fastgcd(int d,int v)
{
	int r;
	d=abs(d),v=abs(v);
	  if(d<v) swap(&d,&v);
	  for(int i=0;v>0;i++)
	  {
		  r=d%v;
		  d=v;
		  v=r;
	  }
	  return d;
}
unsigned long long div(unsigned long long x)
{
	 double SqrtOfnumber;
	    SqrtOfnumber=sqrt(x);
	    unsigned int counter=1,i;
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
void bea(string s,int n)
{
	if((int)s.size()==n){
		cout<<s<<endl;
		return;
	}
	bea(s+'1',n);
	bea(s+'2',n);
	bea(s+'3',n);
}
void num(int x,int i)
{
	if(i>x) return;
	cout<<"The number = "<<i<<endl;
	num(x,i+1);
}
void tri(int n)
{
	if(n<1) return;
	for(int i=0;i<n;i++)
		cout<<"*";
	cout<<endl;
	tri(n-1);
}

void prinum(int n)
{
	if(n<1) return;
	prinum(n/10);
	cout<<n%10;
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
int track(int num,int level)
{
	if(num<=level) return 1;
	return track((num+1)/2,level)+track(num/2,level);
}
int facto(int n)
{
	if(n<1) return 1;
	return n*facto(n-1);
}
int check(string s)
{
	for(unsigned int i=0;i<s.size()-1;i++)
		if(s[i]==s[i+1])
			return i;
	return -1;
}
int pos(string s,int bad,char d)
{
	int start,inc;
	if(d=='l'){ start=0; inc=1;}
	else{ start=s.size()-1; inc=-1;}
	for(int i=start;i!=bad;i+=inc)
	{
		if(s[i]!=s[bad])
		return i;
	}
	return -1;
}
void permit(string s,int n)
{
	if((int)s.size()==n)
	{
		cout<<s<<endl;
		return;
	}
	for(char i=97;i<=97+n;i++)
		permit(s+i,n);
}
int sum(vector<int> v,int n)
{
	if(!n) return v[0];
	return v[n]+sum(v,n-1);
}
bool search(vector<int> v,int x,int n)
{
	if(n<0) {return false;}
	if(v[n]==x) {return true;}
	return search(v,x,n-1);
}
int two=2;
unsigned long long power2(unsigned long long x)
{
	unsigned long long res=1,i;
	for(i=0;i<x;i++)
		{res*=2;
		res%=1000003;
		}
	return res;
}
unsigned long long binary(string s)
{
	unsigned long long res=0;
	for(int i=(int)s.size()-1,k=0;i>=0;i--,k++)
	{
		if(s[i]==48) continue;
		res+=(power2(k)%1000003);
		res%=1000003;
	}
	return res;
}
int cra(int c,int l)
{
	if(c<=l) return 1;
    return cra(c/2,l)+cra((c+1)/2,l);
}

int comdiv(int x,int y)
{
	int g=__gcd(x,y);
	int s=sqrt(g),c=0;
	for(int i=1;i<=s;i++)
	{
		if(g%i==0)
			c+=2;
		if(i*i==g)
			c--;
	}
	return c;
}
void ham(string s,int n,int h,int x)
{
	if((int)s.size()==n){
		if(x==h)
			cout<<s<<endl;
		return;
	}
	ham(s+'0',n,h,x);
	ham(s+'1',n,h,x+1);
}
bool check(int x)
{
	while(x>0){
		if(x%10==7||x%10==4)
			x/=10;
		else return false;
	}
	return true;
}


int main()
{

#ifndef ONLINE_JUDGE
freopen("in.txt", "rt", stdin);
#endif


  


 


  


  


 


  


 


  


  


 


 


  


 


  





  


  



  


  


  


 


  


 








 


 


 


 


 


  


  


  


 


 


 


  


  


 





  


 


  





  


  


  


 



 

 
 


  
 
  
 
  

  
  
    

 
  

 

 

 



 


 









 








  


 


 


  


  


 


  


 


 


  





 


  


  


 


 


 
 

  


 


 


 


 


  



 





 


 





 


 


 




  


  


 


 


  


 








  


  


 





 


  


 


 


 


  


 


 


  


 





 


 





 





 


  


 int i,n,k,l,r,sll,sk;
 vector<int> v,vv;
 cin>>n>>k>>l>>r>>sll>>sk;
 if(sk/k==r)
	 for(i=0;i<k;i++)
		 v.push_back(r);
 else{
	 if(sk%k==0)
	 for(i=0;i<k;i++)
	    v.push_back(sk/k);
	 else{
		 for(i=0;i<k;i++)
			 v.push_back(sk/k);
		 for(i=0;;i++)
		 {
			 if(accumulate(v.begin(),v.end(),0)==sk)
				 break;
			 v[i]++;
			 if(i==k-1) i=-1;

		 }
	 }
 }
 k=n-k,sk=sll-sk;
 if(k>0){
 if(sk/k==r)
 	 for(i=0;i<k;i++)
 		 vv.push_back(r);
  else{
 	 if(sk%k==0)
 	 for(i=0;i<k;i++)
 	    vv.push_back(sk/k);
 	 else{
 		 for(i=0;i<k;i++)
 			 vv.push_back(sk/k);
 		 for(i=0;;i++)
 		 {
 			 if(accumulate(vv.begin(),vv.end(),0)==sk)
 				 break;
 			 vv[i]++;
 			 if(i==k-1) i=-1;

 		 }
 	 }
  }}
 for(i=0;i<v.size();i++)
	 cout<<v[i]<<" ";
 for(i=0;i<vv.size();i++)
 {
	 cout<<vv[i];
	 if(i!=vv.size()-1) cout<<" ";
 }
 return 0;
}
