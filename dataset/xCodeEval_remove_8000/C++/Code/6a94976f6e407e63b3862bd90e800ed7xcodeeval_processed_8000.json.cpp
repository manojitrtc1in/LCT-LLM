






















































































using namespace std;
inline void cmax(int &a,int b){
	a=max(a,b);
}
inline void cmin(int &a,int b){
	a=min(a,b);
}
const int Maxn=100005;
bitset<100005> bs[26];
char c[Maxn],ch[Maxn];
int main(){
	scanf("%s",c);
	int n=strlen(c);
	for (int i=0;i<n;i++){
		bs[c[i]-'a'][i]=1;
	}
	int q;
	scanf("%d",&q);
	for (int i=0;i<q;i++){
		int tp;
		scanf("%d",&tp);
		if (tp==1){
			int pos;
			char cc;
			scanf("%d %c",&pos,&cc);
			pos--;
			bs[c[pos]-'a'][pos]=0;
			c[pos]=cc;
			bs[c[pos]-'a'][pos]=1;
		}
		else{
			int l,r;
			scanf("%d %d",&l,&r);
			l--;
			scanf("%s",ch);
			int len=strlen(ch);
			if (r-l+1<len){
				printf("0\n");continue;
			}
			r-=len;
			r++;
			bitset<Maxn> ans;
			ans=~ans;
			for (int i=0;i<len;i++){
				ans&=(bs[ch[i]-'a']>>i);
			}
			printf("%d\n",(ans>>l).count()-(ans>>r).count());
		}
	}
} 
