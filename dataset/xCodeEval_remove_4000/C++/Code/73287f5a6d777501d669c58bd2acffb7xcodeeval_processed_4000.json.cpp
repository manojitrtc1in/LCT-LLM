












ZCH AK IOI;




inline int read(){
	int _=0,__=1;char ___=getchar();
	while(___>'9'||___<'0'){if(___=='-') __=-1;___=getchar();}
	while(___>='0'&&___<='9'){_=(_<<3)+(_<<1)+___-'0';___=getchar();}
	return __==1?_:-_;
}

inline void write(int _){
	if(!_) return ;
	write(_/10);
	putchar(_%10+'0');
}























struct T{int fath,son;}e[N];
int head[N],hop,fa[N],p[N],rnk[N],w[N],n,t,root;
signed main(){
	t=read();while(t--){
		n=read();rnk[0]=1;bool flag=1;
		for(int i=1;i<=n;i++){fa[i]=read();e[i].fath=fa[i],e[i].son=i;}
		for(int i=1;i<=n;i++){p[i]=read();rnk[p[i]]=i;}
		for(int i=1;i<=n;i++) if(rnk[e[i].son]-rnk[e[i].fath]<0){puts("-1");flag=0;break;}
		if(flag){
			for(int i=1;i<=n;i++) printf("%lld ",rnk[e[i].son]-rnk[e[i].fath]);
			puts("");
		}
	}
	return Strelitzia_H;
}


