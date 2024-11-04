

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
int main()
{

freopen("input.txt", "rt", stdin);





id0();





 


 





	





 


	



























 























 
















int n,x,res=0,pos=0;
char s;
cin>>n;
int *arr=new int[1000100];
fill(arr,arr+1000100,0);
while(n--){
	cin>>s>>x;
	if(s=='+'){
		pos++;
		arr[x]=1;
	}
	else{
		if(arr[x]){
			pos--;
			arr[x]=0;
		}
		else res++;
	}
	if(pos>res) res=pos;
}
cout<<res;
return 0;
}
void id0() {
   ios_base::sync_with_stdio(0);
   cin.tie(NULL), cout.tie(NULL);
}
