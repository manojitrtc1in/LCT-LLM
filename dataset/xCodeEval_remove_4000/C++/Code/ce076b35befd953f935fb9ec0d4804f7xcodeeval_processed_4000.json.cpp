

using namespace std;













const int mod = 1000000007;
const int MAX = 1000001;
void debug(string s){
	cout<<s<<"\n";
}
bool prime[MAX];
int spf[MAX];



void sieve(){
	memset(prime,true,sizeof(prime));
	fl(i,2,MAX-1,2){
		spf[i] = 2;
		if(i!=2){
			prime[i]=false;
		}
	}
	fl(i,3,MAX-1,2){
		if (prime[i]){
			spf[i] = i;
			for (ll j = i; (j*i) < MAX; j += 2){
				if (prime[j*i]){
					prime[j*i] = false;
					spf[j*i] = i;
				}
			}
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



ll power(ll a,ll b){
	ll ans=1;
	while(b!=0){
		if(b%2==1)
			ans*=a;
		a*=a;
		b=b>>1;
	}
	return ans;
}



long long id0(string s){
	long long x=0;
	fl(i,0,(int)s.size()-1,1){
		x=x*10+s[i]-'0';
	}
	return x;
}



string id9(int x){
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
 


int id4(struct node* root){
	if(root==NULL){
		return 0;
	}else{
		int lh=heightTree(root->left);
		int rh=heightTree(root->right);
		int ldd=id4(root->left);
		int rdd=id4(root->right);
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
 


bool id7(struct node* root,int sum){
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
			ans=ans||id7(root->left,remSum);
		}
		if(root->right){
			ans=ans||id7(root->right,remSum);
		}
		return ans;
	}
}
 
int maxSum=0;
int id6(struct node* root){
	if(!root){
		return 0;
	}else{
		int lsum=id6(root->left);
		int rsum=id6(root->right);
		int id1=max(max(lsum,rsum)+root->data,root->data);	
		int pura=max(id1,lsum+rsum+root->data);
		maxSum=max(maxSum,pura);
		return id1;
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

bool id2(string s,int n){
	if(n==0){
		if(id0(s)>id0(tt)){
			return 1;
		}else{
			return 0;
		}
	}
	int z=id0(s);
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
		ans=ans||(id2(a,n-1)||id2(b,n-1)||id2(c,n-1)||id2(d,n-1));
	}
	else{
		ans=ans&&(id2(a,n-1)&&id2(b,n-1)&&id2(c,n-1)&&id2(d,n-1));	
	}
	dp2d[z][n]=ans;
	return ans;
	
}
vector<string> vs;
void id5(int n,string s){
	if((int)s.size()==n){
		vs.pb(s);
		return;
	}
	if(s.size()==0){
		id5(n,s+'1');
		id5(n,s+'0');
	}
	if(s.back()=='0'){
		id5(n,s+'1');
		id5(n,s+'0');
	}else{
		id5(n,s+'0');
	}
}
void id3(int op,int cl,int pos,int n){
	static char s[100];
	if(cl==n){
		cout<<s<<"\n";
		return;
	}
	if(op>cl){
		s[pos]=')';
		id3(op,cl+1,pos+1,n);
	}
	if(op<n){
		s[pos]='(';
		id3(op+1,cl,pos+1,n);
	}
}


int id8(vector<int> &v,int n,int sum){
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
		return dp2d[n][sum]=id8(v,n,sum-v[n-1])+id8(v,n-1,sum);
	else
		return dp2d[n][sum]=id8(v,n-1,sum);
}

int main(){
	fast_io;
	

	int t;
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		char s[MAX];
		for(ll i=0;i<n;i++){
			cin>>s[i];
		}
		ll zidx=-1,oidx=-1;
		for(ll i=0;i<n;i++){
			if(s[i]=='1'){
				oidx=i;
				break;
			}
		}
		for(ll i=max((ll)0,oidx);i<n;i++){
			if(s[i]=='0'){
				zidx=i;
				break;
			}
		}
		while(k>0){
			if(zidx==-1||oidx==-1){
				break;
			}
			if(zidx-oidx<=k){
				s[zidx]='1';
				s[oidx]='0';
				k=k-(zidx-oidx);
				oidx++;
				if(oidx==(n-1)){
					break;
				}
			}

			else{
				

				ll idx=zidx;
				for(ll i=zidx-1,cnt=0;i>=0&&cnt<k;i--,cnt++){
					if(s[i]=='1'){
						idx=i;
					}
				}
				s[idx]='0';
				s[zidx]='1';
				break;
			}
			if(zidx==(n-1)){
				break;
			}
			bool say=false;
			for(ll i=zidx;i<n;i++){
				if(s[i]=='0'){
					say=true;
					zidx=i;
					break;
				}
			}
			if(say==false){
				break;
			}
		}
		for(ll i=0;i<n;i++){
			cout<<s[i];
		}
		cout<<"\n";
	}
	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	       

	

	

	

	

	

	

	

	

	

	
	

	

	

	

	

	

	

		

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

		

	

	

	

	

	

	

	

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

		

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	
	

	

	

	
	

	

		

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

















































































































































































































	

	

	

	

	

	

	

	

	

	

		
	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

				
	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

		
	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

			
	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	return 0;
}













































	


