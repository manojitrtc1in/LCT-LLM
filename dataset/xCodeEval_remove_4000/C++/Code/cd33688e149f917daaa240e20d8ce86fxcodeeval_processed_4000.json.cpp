




















































































































































































freopen(
freopen(








for(ll error_

for(ll error_







checkdy(1);
id0(joincheck1,short,signed,long long,long,unsigned short,unsigned,unsigned long,unsigned long long);

char ccc=0;
template<typename T>
void reads(checksy(1)&_) {
	checksy(1) x=0,w=1;
	for(;ccc<'0'||ccc>'9';(ccc^'-')||(w=-w),ccc=getchar());
	for(;ccc>='0'&&ccc<='9';x=(x<<1)+(x<<3)+(ccc^48),ccc=getchar());
	

	_=x*w;
	return;
}
template<typename T>
void writes(checksy(1)_) {
	if(_<0)putchar('-'),_=-_;
	if(_<10)putchar(_^48);
	else writes<checksy(1)>(_/10),putchar((_%10)^48);
	return;
}

checkdy(2);
id0(joincheck2,char,unsigned char);
template<typename T>
void reads(checksy(2)&_) {
	for(;ccc<33||ccc>126;ccc=getchar());
	

	_=ccc;
	ccc=getchar();
	return;
}
template<typename T>

void writes(checksy(2)_) {
	if(_)
	putchar(_);
	return;
}
template<typename T>
void reads(checksy(2)*_) {
	for(;ccc<33||ccc>126;ccc=getchar());
	

	ll a=1;_[0]=ccc;
	ccc=getchar();
	for(;ccc>=33&&ccc<=126;_[a]=ccc,a++,ccc=getchar());
	_[a]=0;
	return;
}
template<typename T>
void writes(checksy(2)*_) {
	ll a=0;
	while(_[a])putchar(_[a]),a++;
	return;
}
template<typename T>
void writes(const checksy(2)*_) {
	ll a=0;
	while(_[a])putchar(_[a]),a++;
	return;
}

checkdy(3);
id0(joincheck3,double,long double);
template<typename T>
void reads(checksy(3)&_) {
	checksy(3) x=0;
	int w=1;
	for(;ccc<'0'||ccc>'9';(ccc^'-')||(w=-w),ccc=getchar());
	for(;ccc>='0'&&ccc<='9';x=x*10+int(ccc^48),ccc=getchar());
	if(ccc^'.') {
		

		

		_=x*w;
		return;
	}
	ccc=getchar();
	checksy(3) m=0.1;
	for(;ccc>='0'&&ccc<='9';x+=int(ccc^48)*m,ccc=getchar(),m/=10);
	

	_=x*w;
	return;
}
ll ws=9;
template<typename T>
void writes(checksy(3)_) {
	if(_<0)putchar('-'),_=-_;
	ll m=1;
	for(ll i=1;i<=ws;i++)m*=10;
	writes<long long>((long long)(_*m+0.5)/m);
	if(ws==0)return;
	putchar('.');
	ll l_=(long long)((_-(long long)_)*m+0.5);
	m/=10;
	for(ll i=1;i<=ws;i++,m/=10){
		putchar((l_/m%10)^48);
	}
	return;
}
template<typename T> 
void reads_(T&x) {reads<T>(x);}
template<typename T> 
void reads_(T*x) {reads<T>(x);}


template<typename T> 
void writes_(T x) {writes<T>(x);}
template<typename T> 
void writes_(T*x) {writes<T>(x);}
template<typename T> 
void writes_(const T*x) {writes<T>(x);}
























char s[4022],ans[4202];
ll liantong[404][404],to[1020],used[303],du[303],head[303],next[1020],cnt;
void add(ll x,ll y) {
	if(liantong[x][y])return;
	

	if(x<=0||y<=0)return;
	++cnt;
	to[cnt]=y;
	du[x]++;
	liantong[x][y]=1;
	next[cnt]=head[x];
	head[x]=cnt;
}
ll p,anstop;
void bl(ll u) {
	if(u<=0)return;
	used[u]=1;
	ans[++anstop]=u+('a'-1);
	for(ll i=head[u];i;i=next[i]) {
		if(to[i]>0&&!used[to[i]])bl(to[i]);
	}
}
int main(int wcr,char**AKIOI) {
	

	ll t;
	read(t);
	while(t--) {
		cnt=0;
		anstop=-1;
		for(ll i=0;i<=260;i++)head[i]=used[i]=du[i]=ans[i-1]=0;
		for(ll i=0;i<=27;i++)
		for(ll j=0;j<=27;j++)liantong[i][j]=0;
		scanf("%s",s);
		ll n=strlen(s);
		for(ll i=1;i<n;i++) {
			add(s[i-1]-('a'-1),s[i]-('a'-1));
			add(s[i]-('a'-1),s[i-1]-('a'-1));
		}
		p=1;
		for(ll i=1;i<=26;i++) {
			if(du[i]>2) {
				p=0;
			

				break;
			}
		}
		if(p==0) {
			printf("NO\n");
			continue;
		}
		for(ll i=1;i<=26;i++) {
			if(du[i]==1&&!used[i])bl(i);
		}
			

		for(ll i=1;i<=26;i++) {
			if(!du[i]) {
				ans[++anstop]=i+('a'-1);
			}
			if(du[i]&&!used[i]) {
				p=0;
				break;
			}
		}
		if(p==0) {
			printf("NO\n");
			continue;
		}
		ans[++anstop]=0;
		if(anstop>10)
		printf("YES\n%s\n",ans);
		else
		printf("NO\n");
	}
	return 0;
}
