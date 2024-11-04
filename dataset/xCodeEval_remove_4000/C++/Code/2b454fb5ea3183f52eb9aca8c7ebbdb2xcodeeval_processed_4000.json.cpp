



































using namespace std;


const int Maxn=100005;
const int Maxt=500005;
const int Maxk=27;
int tree[Maxk][Maxt];
char c[Maxn];
int cnt[Maxk];
int L,R;
int n,m;
void _build_tree(int l,int r,int p){
	if (l==r){
		tree[(c[l]-'a')][p]=1;
		return;
	}
	int mid=(l+r)/2;
	_build_tree(l,mid,p*2);
	_build_tree(mid+1,r,p*2+1);
	for (int letter=0;letter<26;letter++)
	tree[letter][p]=tree[letter][p*2]+tree[letter][p*2+1];
	return;
}
int query(int letter,int low,int high,int p){
	if (low>=L && high<=R){
		return tree[letter][p];
	}
	if (tree[letter][p]==0){
		return 0;
	}
	if (tree[letter][p]==(high-low+1)){
		return min(high,R)-max(low,L)+1;
	}
	int mid=(low+high)/2;
	int ans=0;
	if (L<=mid){
		ans+=query(letter,low,mid,p*2);
	} 
	if (R>mid){
		ans+=query(letter,mid+1,high,p*2+1);
	}
	return ans;
}
void range_clear(int letter,int low,int high,int p){
	if (low>=L && high<=R){
		tree[letter][p]=0;
		return;
	}
	int mid=(low+high)/2;
	int ans=0;
	if (tree[letter][p]==0){
		tree[letter][p*2]=tree[letter][p*2+1]=0;
	}
	if (tree[letter][p]==(high-low+1)){
		tree[letter][p*2]=mid-low+1;
		tree[letter][p*2+1]=high-mid;
	}
	if (L<=mid){
		range_clear(letter,low,mid,p*2);
	} 
	if (R>mid){
		range_clear(letter,mid+1,high,p*2+1);
	}
	int ll=tree[letter][p*2],rr=tree[letter][p*2+1];
	tree[letter][p]=ll+rr;
}
void modify(int letter,int low,int high,int p){
	if (low>=L && high<=R){
		tree[letter][p]=high-low+1;
		return;
	}
	int mid=(low+high)/2;
	if (tree[letter][p]==0){
		tree[letter][p*2]=tree[letter][p*2+1]=0;
	}
	if (tree[letter][p]==(high-low+1)){
		tree[letter][p*2]=mid-low+1;
		tree[letter][p*2+1]=high-mid;
	}
	if (L<=mid){
		modify(letter,low,mid,p*2);
	} 
	if (R>mid){
		modify(letter,mid+1,high,p*2+1);
	}
	int ll=tree[letter][p*2],rr=tree[letter][p*2+1];
	tree[letter][p]=ll+rr;
	return;
}
void _single_debug(){
	printf("\n");
	for (int i=1;i<=n;i++){
		for (int k=0;k<26;k++){
			L=i,R=i;
			if (query(k,1,n,1)==1){
				printf("%c",k+'a');
			}
			
		}printf(" ");
	}
	for (int i=0;i<26;i++){
		printf("%d ",tree[i][1]);
	}
	printf("\n");
}
void solve(int left,int right){
	memset(cnt,0,sizeof(cnt));
	L=left,R=right;
	int mid=(left+right)/2;
	int odd=-1,tot=0;
	for (int i=0;i<26;i++){
		cnt[i]=query(i,1,n,1);
		

		if (cnt[i]&1){
			odd=i;
			tot++;
		}
	}


	if (tot>1) {
	

		return;
	}
	for (int i=0;i<26;i++)  range_clear(i,1,n,1);
	if (odd!=-1){
		L=mid,R=mid;
		

		cnt[odd]--;
		modify(odd,1,n,1);
	

	}
	int cur=0;
	for (int i=0;i<26;i++){
		if (cnt[i]){
			int j=cnt[i]/2;
		

			L=left+cur,R=left+cur+j-1;
			

			modify(i,1,n,1);
			L=right-cur-j+1,R=right-cur;
			

			modify(i,1,n,1);
			cur+=j;
		}
	}


}
void _init(){
	for (int i=0;i<Maxk;i++){
		for (int j=0;j<Maxt;j++){
			tree[i][j]=0;
		}
	}
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	_init(); 
	scanf("%d %d",&n,&m);
	scanf("%s",c+1);
	

	_build_tree(1,n,1);


	while (m--){
		int left,right;
		scanf("%d %d",&left,&right);
		solve(left,right);
	}
	for (int i=1;i<=n;i++){
		for (int k=0;k<26;k++){
			L=i,R=i;
			if (query(k,1,n,1)!=0){
				printf("%c",k+'a');
			}
		}
	}
	return 0;
}


