




















































































































































































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
ll ws=6;
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
























ll a[28][333333];
char s[222222];
int main(int wcr,char**AKIOI) {
	

	scanf("%s",s+1);
	for(ll i=1;s[i];i++) {
		a[s[i]-'a'][i]=1;
	}
	for(ll i=1;s[i];i++) {
		for(ll j=0;j<=26;j++) {
			a[j][i]+=a[j][i-1];
		}
	}
	ll t;
	read(t);
	while(t-->0) {
		ll l,r;
		read(l,r);
		ll num=0;
		for(ll j=0;j<=26;j++)
		num+=!!(a[j][r]^a[j][l-1]);
		if(r==l||s[l]!=s[r]||num>=3) {
			writeln("Yes");
		}
		else {
			writeln("No");
		}
	}
	return 0;
}
