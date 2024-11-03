
#include<bits/stdc++.h>
using namespace std;
#define fast_io   ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ll	long long
#define ull	unsigned long long
#define pb push_back
#define popb pop_back
#define pf push_front
#define popf pop_front
#define fl(i,st,en,in)	for(auto i=st;i<=en;i+=in)
#define rfl(i,st,en,de)	for(auto i=st;i>e=n;i-=de)
#define mp   make_pair
#define FF   first
#define SS   second
#define all(something)   something.begin(),something.end()
const int mod = 1000000007;
const int MAX = 1000001;
void debug(string s){
	cout<<s<<"\n";
}



const int SVE=1000000;
vector<bool> primes(SVE,true);
vector<ll> spf(SVE,0);
void smallest_prime_factors(){
	primes[2]=true;
	spf[2]=2;
	for(ll i=2;i<SVE;i+=2){
		if(i!=2){
			primes[i]=false;
			spf[i]=2;
		}
	}
	for(ll i=3;i<SVE;i+=2){
		if(primes[i]==false)continue;
		spf[i]=i;
		for(ll j=i*i;j<SVE;j+=i){
			if(primes[j]==false){
				continue;
			}
			spf[j]=i;
			primes[j]=false;
		}
	}
}





ll GCD(ll a,ll b){
	ll c=a%b;
	while(c!=0){
		a=b;
		b=c;
		c=a%b;
	}
	return b;
}



ll power(ll a,ll b,ll m){
	ll ans=1;
	while(b!=0){
		if(b%2==1)
			ans=(ans*a)%m;
		a=(a*a)%m;
		b=b>>1;
	}
	return ans%m;
}



long long string_to_int(string s){
	long long x=0;
	fl(i,0,(int)s.size()-1,1){
		x=x*10+s[i]-'0';
	}
	return x;
}



string int_to_string(int x){
	string s="";
	while(x){
		s=char(x%10+'0')+s;
		x=x/10;
	}
	return s;
}



int root(int x,int par[]){
	while(x!=par[x]){
		x=par[x];
		par[x]=par[par[x]];
	}
	return x;
}



void uni(int x,int y,int par[],int size[]){
	int rx=root(x,par);
	int ry=root(y,par);
	if(rx==ry){
		return;
	}
	else{
		if(size[rx]>=size[ry]){
			size[rx]+=size[ry];
			size[ry]=0;
			par[ry]=rx;
		}
		else{
			size[ry]+=size[rx];
			size[rx]=0;
			par[rx]=ry;
		}
	}
}



struct node{
	int data;
	struct node* left;
	struct node* right;
};



struct node* newNode(int data){
	struct node* temp=new node();
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}



void inOrder(struct node* root){
	if(root){
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
	
}



void preOrder(struct node* root){
	if(root){
		cout<<root->data<<" ";
		preOrder(root->left);
		
		preOrder(root->right);
	}
	
}



void postOrder(struct node* root){
	if(root){
		postOrder(root->left);
		
		postOrder(root->right);
		cout<<root->data<<" ";
	}
	
}



void insert(int x,struct node* root){
	if(root){
		if(x<root->data){
			if(root->left==NULL){
				cout<<"Inserted "<<x<<" at left of "<<root->data<<"\n";
				root->left=newNode(x);
				return;
			}
			insert(x,root->left);
		}else if(x>=root->data){
			if(root->right==NULL){
				cout<<"Inserted "<<x<<" at right of "<<root->data<<"\n";
				root->right=newNode(x);
				return;
			}
			insert(x,root->right);
		}
	}
}



int heightTree(struct node* root){
	if(root==NULL){
		return 0;
	}else{
		return 1+max(heightTree(root->left),heightTree(root->right));
	}
}
 


int diameterTree(struct node* root){
	if(root==NULL){
		return 0;
	}else{
		int lh=heightTree(root->left);
		int rh=heightTree(root->right);
		int ldd=diameterTree(root->left);
		int rdd=diameterTree(root->right);
		return max(lh+rh+1,max(ldd,rdd));
	}
}



int treeSum(struct node* root){
	if(root->left==NULL&&root->right==NULL){
		return root->data;
	}
 
	root->data=root->data+((root->left)?treeSum(root->left):0)+((root->right)?treeSum(root->right):0);
	return root->data;
}
 


bool hasPathWithGivenSum(struct node* root,int sum){
	if(root==NULL){
		if(sum==0){
			return true;
		}else{
			return false;
		}
	}else{
		bool ans=false;
		int remSum=sum-root->data;
		if(remSum==0&&root->left==NULL&&root->right==NULL){
			return true;
		}
		if(root->left){
			ans=ans||hasPathWithGivenSum(root->left,remSum);
		}
		if(root->right){
			ans=ans||hasPathWithGivenSum(root->right,remSum);
		}
		return ans;
	}
}
 
int maxSum=0;
int maximumSumPath(struct node* root){
	if(!root){
		return 0;
	}else{
		int lsum=maximumSumPath(root->left);
		int rsum=maximumSumPath(root->right);
		int ekrasta=max(max(lsum,rsum)+root->data,root->data);	
		int pura=max(ekrasta,lsum+rsum+root->data);
		maxSum=max(maxSum,pura);
		return ekrasta;
	}
}
 


int lca(struct node* root,int a,int b){
	if(root==NULL){
		return 0;
	}else{
		if(root->data==a||root->data==b){
			return root->data;
		}
		int l=lca(root->left,a,b);
		int r=lca(root->right,a,b);
		if(l!=0&&r!=0){
			return root->data;
		}
		if(l==0&&r==0){
			return 0;
		}
		if(l==0){
			return r;
		}
		else{
			return l;
		}
	}
}
map<int,int> m;
void verticalSum(struct node* root,int hd){
	if(root==NULL){
		return;
	}
	else{
		m[hd]+=root->data;
		verticalSum(root->left,hd-1);
		
		verticalSum(root->right,hd+1);
	}
}
 
bool check(ll x,ll a[],ll n,ll k){
	fl(i,n/2,n-1,1){
		if(a[i]<x){
			k=k-(x-a[i]);
		}
	}
	if(k>=0){
		return true;
	}
	return false;
}
int togglebit(int n) 
{ 
	if (n == 0) 
		return 1;
	int i = n;
	n |= n >> 1;
	n |= n >> 2; 
	n |= n >> 4; 
	n |= n >> 8; 
	n |= n >> 16; 
	

 
	return i ^ n; 
}
int xnor(int num1, int num2) 
{ 
	if (num1 < num2) 
		swap(num1, num2); 
	num1 = togglebit(num1); 
	return num1 ^ num2; 
}

int dp2d[9999][101]; 
string tt;

bool solvve(string s,int n){
	if(n==0){
		if(string_to_int(s)>string_to_int(tt)){
			return 1;
		}else{
			return 0;
		}
	}
	int z=string_to_int(s);
	if(dp2d[z][n]!=-1){
		return dp2d[z][n];
	}
	bool ans=0;
	if(n%2==1){
		ans=1;
	}
	string ss=s;
	string a=ss,b=ss,c=ss,d=ss;
	a[0]=a[0]+1;b[1]=b[1]+1;c[2]=c[2]+1;d[3]=d[3]+1;
	if(ss[0]=='9')a[0]=0;
	if(ss[1]=='9')b[1]=0;
	if(ss[2]=='9')c[2]=0;
	if(ss[3]=='9')d[3]=0;
	if(n%2==0){
		ans=ans||(solvve(a,n-1)||solvve(b,n-1)||solvve(c,n-1)||solvve(d,n-1));
	}
	else{
		ans=ans&&(solvve(a,n-1)&&solvve(b,n-1)&&solvve(c,n-1)&&solvve(d,n-1));	
	}
	dp2d[z][n]=ans;
	return ans;
	
}
vector<string> vs;



void number_of_binary_strings(int n,string s){
	if((int)s.size()==n){
		vs.pb(s);
		return;
	}
	if(s.size()==0){
		number_of_binary_strings(n,s+'1');
		number_of_binary_strings(n,s+'0');
	}
	if(s.back()=='0'){
		number_of_binary_strings(n,s+'1');
		number_of_binary_strings(n,s+'0');
	}else{
		number_of_binary_strings(n,s+'0');
	}
}



void genbrackets(int op,int cl,int pos,int n){
	static char s[100];
	if(cl==n){
		cout<<s<<"\n";
		return;
	}
	if(op>cl){
		s[pos]=')';
		genbrackets(op,cl+1,pos+1,n);
	}
	if(op<n){
		s[pos]='(';
		genbrackets(op+1,cl,pos+1,n);
	}
}


int coinsways_recursion(vector<int> &v,int n,int sum){
	if(sum==0){
		return dp2d[n][sum]=1;
	}
	if(n==0){
		return dp2d[n][sum]=0;
	}
	if(dp2d[n][sum]!=-1){
		return dp2d[n][sum];
	}
	if(sum>=v[n-1])
		return dp2d[n][sum]=coinsways_recursion(v,n,sum-v[n-1])+coinsways_recursion(v,n-1,sum);
	else
		return dp2d[n][sum]=coinsways_recursion(v,n-1,sum);
}



int max_diff(int a[],int n){
	int mm=a[0];
	int ans=0;
	for(int i=0;i<n;i++){
		mm=min(mm,a[i]);
		ans=max(ans,a[i]-mm);
		cout<<a[i]-mm<<" ";
	}
	cout<<"\n";
	return ans;
}
vector<int> KMP(string s,string t){
	int n1=s.size();
	int n2=t.size();

	

	int lps[n2];
	lps[0]=0;
	int i=0,j=1;
	while(j<n2){
		if(s[j]==s[i]){
			i++;
			lps[j++]=i;
		}else{
			if(i>0){
				i=lps[i-1];
			}else{
				lps[j++]=0	;
			}
		}
	}

	

	vector<int> indexes;
	for(int i=0,j=0;i<n1;){
		if(s[i]==t[j]){
			i++;
			j++;
		}
		if(j==n2){
			indexes.pb(i-n2);
			cout<<i-n2<<" ";
			j=lps[j-1];
		}else if(i<n1&&t[j]!=s[i]){
			if(j>0){
				j=lps[j-1];
			}else{
				i++;
			}
		}
	}
	return indexes;

}
int main(){
	fast_io;
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	string t;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		t+=s[i%k];
		v[i]=s[i]-'0';
	}
	if(t<s){
		

		v[k-1]++;
	}
	for(int i=k-1;i>0;i--){
		if(v[i]>9){
			v[i]=0;
			v[i-1]++;
			

		}else{
			break;
		}
	}
	

	

	

	

	

	

	cout<<n<<"\n";
	for(int i=0;i<n;i++){
		cout<<v[i%k];
	}
	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	
	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

		
	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	       

	

	

	

	

	

	

	

	

	

	
	

	

	

	

	

	

	

		

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

		

	

	

	

	

	

	

	

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

		

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	
	

	

	

	
	

	

		

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

















































































































































































































	

	

	

	

	

	

	

	

	

	

		
	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

				
	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

		
	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

			
	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	return 0;
}













































	






 


 




 
























 


























	
	
	
















	


























		


		
		




			










				






			


















	







