




using namespace std;
const int N=100100;
inline int read(){
	int x=0,c=getchar();
	for(;c>'9'||c<'0';c=getchar());
	for(;c>='0'&&c<='9';c=getchar())
	x=(x<<1)+(x<<3)+c-'0';return x;
}
inline void write(int x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int n,Q,blo,s[N],a[N],f[N],b[N],sb,mx;
int q1[N],q2[N],v[N],l1,l2,r1,r2,ans[N];
struct cqz{int l,r,i;}q[N];
inline bool operator<(cqz i,cqz j){
	if(i.l/blo==j.l/blo)return i.r<j.r;
	return i.l<j.l;
}
inline void add(int i,int k){
	i=a[i];f[s[i]]--;s[i]+=k;f[s[i]]++;
}
inline int get(){
	if((l2>r2)||(l1<=r1&&q1[l1]<q2[l2]))
	return q1[l1++];return q2[l2++];
}
inline int fuck(){
	int i,lst=0,res=0,k;l1=1,l2=1,r1=0,r2=0;
	for(i=1;i<=sb;i++)if(s[b[i]]>blo)q1[++r1]=s[b[i]];
	sort(q1+1,q1+r1+1);
	for(i=1;i<=blo;i++)v[i]=f[i];
	for(i=1;i<=blo;i++)if(v[i]){
		if(lst){
			k=i+lst;res+=k;v[i]--;lst=0;
			if(k>blo)q2[++r2]=k;else v[k]++;
		}if(v[i]&1)v[i]--,lst=i;
		res+=v[i]*i;k=i<<1;
		if(k>blo)for(;v[i];v[i]-=2)q2[++r2]=k;
		else v[k]+=v[i]>>1;
	}k=r1+r2;if(!k)return res;
	if(lst)k++,q2[--l2]=lst;
	for(k--;k--;){
		i=get()+get();
		res+=i;q2[++r2]=i;
	}return res;
}
int main(){
	int i,l,r;
	n=read();blo=sqrt(n);
	for(i=1;i<=n;i++){
		s[a[i]=read()]++;
		if(a[i]>mx)mx=a[i];
	}Q=read();for(i=1;i<=Q;i++)q[i]=(cqz){read(),read(),i};
	sort(q+1,q+Q+1);l=r=q[1].l;r--;
	for(i=1;i<=mx;i++){if(s[i]>blo)b[++sb]=i;s[i]=0;}
	for(i=1;i<=Q;i++){
		while(l>q[i].l)add(--l,1);
		while(r<q[i].r)add(++r,1);
		while(l<q[i].l)add(l++,-1);
		while(r>q[i].r)add(r--,-1);
		ans[q[i].i]=fuck();
	}for(i=1;i<=Q;i++)write(ans[i]),putchar('\n');
	return 0;
}