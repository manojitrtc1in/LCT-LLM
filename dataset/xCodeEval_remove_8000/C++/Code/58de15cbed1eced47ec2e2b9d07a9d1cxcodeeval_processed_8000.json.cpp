

using namespace std;


void id0();
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
	 double id1;
	    id1=sqrt(x);
	    int counter=1;
	    int i;
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
	for(int i=0;i<v.size()-1;i++)
		if(v[i]>v[i+1])
			return false;
	return true;
}
int fed(vector<int> v,int t,int k){
	int c=0,temp;
	for(int i=0;i<v.size();i++){
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
int main()
{

freopen("input.txt", "rt", stdin);





id0();





 


 





	





 


	



























 























 
















































 


 


 










 


 







	


 


 


 





 


 


 


 








































 

 



 


 


 


 








 


	













 


 








 int lim,sum,summ,one=0;
 cin>>sum>>lim;
 summ=sum;
 vector<int> res;
set<pair<int,int>> se;
set<pair<int,int>>::reverse_iterator rit;
set<pair<int,int>>::iterator it;
 for(int i=1;i<=lim;i++)
 {
	 se.insert({chil(i),i});
	 if(chil(i)==1) one++;
 }

 for(rit=se.rbegin();rit!=se.rend();rit++){
	 if(sum<=one) break;
		 if(sum>=(*rit).first){
			 res.push_back((*rit).second);
			 sum-=(*rit).first;
			 if((*rit).first==1) one--;
		 }
 }
 if(sum<=one)for(auto i:se){
 	 if(sum==0) break;
 	if(i.first==1){ res.push_back(i.second);
 	 sum--;}
  }
 if(sum>0) {cout<<-1; return 0;}
 cout<<res.size()<<endl;
 for(int i=0;i<res.size();i++){
	 cout<<res[i];
	 if(i!=res.size()-1) cout<<" ";
 }
}
void id0() {
   ios_base::sync_with_stdio(0);
   cin.tie(NULL), cout.tie(NULL);
}
