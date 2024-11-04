

using namespace std;
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
long long fact(int a)
{
	long long res=1;
	for(int i=a;i>0;i--)
		res*=i;
	return res;
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
	for(int i=0,f=s.size()-1;i<s.size()/2;i++,f--)
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
int id0(int d,int v)
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
	 double id1;
	    id1=sqrt(x);
	    int counter=1,i;
	    for(i=2;i<id1;i++)
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
	if(s.size()==n){
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
int fn(int n,int c)
{
	if(n==1) return c+1;
	if(n%2==0) fn(n/2,++c);
	else fn(3*n+1,++c);
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
	if(ind==s.size()) {
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
	for(int i=0;(int)i<s.size()-1;i++)
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
	if(s.size()==n)
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
int main()
{


freopen("in.txt", "rt", stdin);



  


 


  


  


 


  


 


  


  


 


 


  


 


  





  


  



  


  


  


 


  


 








 


 


 


 


 


  


  


  


 


 


 


  


  


 





  


 


  





  


  


  


 



 

 
 


  
 
  
  
 
  

  
  
    

 
  

 

 

 



 


 









 








  


 


 


  


  


 


  


 int n,k,t,i=0;
 vector <int> v;
 vector <int>::iterator tt;
 cin>>n>>k;
 while(n--){
	 cin>>t;
	 v.push_back(t);
 }
 while(k--)
 {
	 if(v[i]<0){
		 v[i]*=-1;
		 i++;
	 }
	 else{
		 if(i-1>-1){
			 n=min(v[i],v[i-1]);
			 if(n==v[i])
				 v[i]*=-1;
			 else{
				 v[i-1]*=-1;
				 i--;
			 }
		 }
		 else{
			 v[i]*=-1;
		 }

	 }
 }
 cout<<accumulate(v.begin(),v.end(),0);
 return 0;
}
