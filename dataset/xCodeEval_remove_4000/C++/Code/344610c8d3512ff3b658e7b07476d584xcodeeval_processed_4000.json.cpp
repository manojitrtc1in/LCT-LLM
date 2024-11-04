











using namespace std;

const int LIM = 1<<21;

inline void read(int &x) {
	x = 0;
	char c = getchar();
	while(c<'0'||c>'9') c = getchar();
	while(c>='0'&&c<='9') {
		x = (x<<3)+(x<<1)+(c^48);
		c = getchar();
	}
}

void print(int x) {
	if(x>9) print(x/10);
	putchar(x%10+'0');
}

namespace polynomial {


	struct poly {
		int t;
		int a[N];
	};
	int lg2[N],rt[N],irt[N],inv[N],rev[N];

	inline int power(int a,int t);
	inline void NTT(poly &f,int type,int lim);
	inline void print_poly(poly f);
	inline void clear(poly &f);
	inline void reverse(poly &f);
	poly inverse(poly f);
	poly log(poly f);
	inline poly integral(poly f);
	inline poly derivative(poly f);
	poly exp(poly f);
	poly divide(poly f,poly g);
	poly mod(poly f,poly g);
	poly power(poly f,int k);
	poly sqrt(poly f);
	poly sin(poly f);
	poly cos(poly f);
	poly asin(poly f);
	poly atan(poly f);
	poly EXpower(poly f,int k);
	inline int id0(int a);

	inline void swap(int &x,int &y) {
		if(x==y) return;
		x ^= y ^= x ^= y;
	}

	inline int add(int a,int b) {
		return a+b>=p?a+b-p:a+b;
	}

	inline int dec(int a,int b) {
		return a<b?a-b+p:a-b;
	}

	poly mod_power(poly f,int t,poly G) {
		poly h,g = f;
		int lim;
		t--;
		while(t) {
			if(t&1) {
				lim = 1;
				h = f;
				while(lim<=h.t+g.t) lim <<= 1;
				NTT(g,1,lim),NTT(h,1,lim);
				for(reg int i=0; i<=lim; ++i)
					g.a[i] = (ll)g.a[i]*h.a[i]%p;
				NTT(g,-1,lim);
				g.t += h.t;
				for(reg int i=g.t+1; i<=lim; ++i) g.a[i] = 0;
				g = mod(g,G);
			}
			lim = 1;
			while(lim<=(f.t<<1)) lim <<= 1;
			NTT(f,1,lim);
			for(reg int i=0; i<=lim; ++i)
				f.a[i] = (ll)f.a[i]*f.a[i]%p;
			NTT(f,-1,lim);
			f.t <<= 1;
			for(reg int i=f.t+1; i<=lim; ++i) f.a[i] = 0;
			f = mod(f,G);
			t >>= 1;
		}
		return g;
	}

	inline int id0(int a) {
		srand((ll)a*time(0)%p);
		int pw,s = p-1,t = 0;
		while(!(s&1)) {
			++t;
			s >>= 1;
		}
		int b = rand();
		while(power(b,(p-1)/2)==1) b = rand();
		int inv = power(a,p-2),x = power(a,(s+1)>>1);
		for(reg int k=0; k<t; ++k) {
			if(power((ll)x*x%p*inv%p,power(2,t-k-1))==1) continue;
			pw = (ll)s*power(2,k-1)%p;
			x = (ll)x*power(b,pw)%p;
		}
		return min(x,p-x);
	}

	inline void init() {
		inv[1] = 1;
		for(reg int i=2; i<N; ++i)
			inv[i] = (ll)(p-p/i)*inv[p%i]%p;
		for(reg int i=2; i<N; ++i) lg2[i] = lg2[i>>1]+1;
		rt[0] = irt[0] = 1;
		rt[1] = power(3,(p-1)/LIM);
		irt[1] = power(rt[1],p-2);
		for(reg int i=2; i<=LIM; ++i) {
			rt[i] = (ll)rt[i-1]*rt[1]%p;
			irt[i] = (ll)irt[i-1]*irt[1]%p;
		}
	}

	inline poly EXpower(poly f,int k) {
		int u,v,low = 0,n = f.t;
		for(reg int i=0; i<=n; ++i) {
			if(!f.a[i]) continue;
			low = i;
			break;
		}
		if(low) {
			for(reg int i=low; i<=n; ++i) {
				f.a[i-low] = f.a[i];
				f.a[i] = 0;
			}
		}
		v = f.a[0],u = power(v,p-2);
		for(reg int i=0; i<=n; ++i) f.a[i] = (ll)f.a[i]*u%p;
		f = power(f,k);
		u = power(v,k);
		for(reg int i=0; i<=n; ++i) f.a[i] = (ll)f.a[i]*u%p;
		if(low) {
			if((ll)low*k>p) low = p;
			else low *= k;
			for(reg int i=n; i>=0; --i) {
				if(i+low<=n) f.a[i+low] = f.a[i];
				f.a[i] = 0;
			}
		}
		return f;
	}

	poly atan(poly f) {
		int lim = 1,n = f.t;
		static poly g = f;
		while(lim<=(n<<1)) lim <<= 1;
		NTT(f,1,lim);
		for(reg int i=0; i<=lim; ++i)
			f.a[i] = (ll)f.a[i]*f.a[i]%p;
		NTT(f,-1,lim);
		for(reg int i=n+1; i<=lim; ++i) f.a[i] = 0;
		f.a[0] = (f.a[0]+1)%p;
		f = inverse(f),g = derivative(g);
		NTT(f,1,lim),NTT(g,1,lim);
		for(reg int i=0; i<=lim; ++i)
			f.a[i] = (ll)f.a[i]*g.a[i]%p;
		NTT(f,-1,lim);
		for(reg int i=n+1; i<=lim; ++i) f.a[i] = 0;
		return integral(f);
	}

	poly asin(poly f) {
		int lim = 1,n = f.t;
		poly g = f;
		while(lim<=(n<<1)) lim <<= 1;
		NTT(f,1,lim);
		for(reg int i=0; i<=lim; ++i)
			f.a[i] = (ll)f.a[i]*f.a[i]%p;
		NTT(f,-1,lim);
		for(reg int i=n+1; i<=lim; ++i) f.a[i] = 0;
		for(int i=0; i<=n; ++i) f.a[i] = dec(0,f.a[i]);
		f.a[0] = add(f.a[0],1);
		f = inverse(sqrt(f));
		g = derivative(g);
		NTT(f,1,lim),NTT(g,1,lim);
		for(reg int i=0; i<=lim; ++i)
			f.a[i] = (ll)f.a[i]*g.a[i]%p;
		NTT(f,-1,lim);
		for(reg int i=n+1; i<=lim; ++i) f.a[i] = 0;
		return integral(f);
	}

	poly log(poly f) {
		clear(f);
		int lim = 1,n = f.t;
		poly g = derivative(f);
		f = inverse(f);
		while(lim<=(n<<1)) lim <<= 1;
		NTT(f,1,lim),NTT(g,1,lim);
		for(reg int i=0; i<=lim; ++i)
			f.a[i] = (ll)f.a[i]*g.a[i]%p;
		NTT(f,-1,lim);
		for(reg int i=n+1; i<=lim; ++i) f.a[i] = 0;
		return integral(f);
	}

	poly cos(poly f) {
		for(reg int i=0; i<=f.t; ++i)
			f.a[i] = (ll)f.a[i]*img%p;
		poly g = exp(f);
		f = inverse(g);
		for(reg int i=0; i<=f.t; ++i) f.a[i] = add(f.a[i],g.a[i]);
		for(reg int i=0; i<=f.t; ++i)
			f.a[i] = (ll)f.a[i]*inv[2]%p;
		return f;
	}

	poly sin(poly f) {
		for(reg int i=0; i<=f.t; ++i)
			f.a[i] = (ll)f.a[i]*img%p;
		poly g = exp(f);
		f = inverse(g);
		for(reg int i=0; i<=f.t; ++i) f.a[i] = dec(g.a[i],f.a[i]);
		int w = power(img<<1,p-2);
		for(reg int i=0; i<=f.t; ++i)
			f.a[i] = (ll)f.a[i]*w%p;
		return f;
	}

	poly sqrt(poly f) {
		int n = f.t,top = 0,lim = 1;
		int s[70];
		poly g,h;
		memset(g.a,0,sizeof(g.a));
		while(n) {
			s[++top] = n;
			n >>= 1;
		}
		if(f.a[0]==1) g.a[0] = 1;
		else g.a[0] = id0(f.a[0]);
		while(top--) {
			g.t = n = s[top+1];
			while(lim<=(n<<1)) lim <<= 1;
			h = g;
			for(reg int i=0; i<=n; ++i) h.a[i] = add(h.a[i],h.a[i]);
			h = inverse(h);
			NTT(g,1,lim);
			for(reg int i=0; i!=lim; ++i)
				g.a[i] = (ll)g.a[i]*g.a[i]%p;
			NTT(g,-1,lim);
			for(reg int i=n+1; i!=lim; ++i) g.a[i] = 0;
			for(reg int i=0; i<=n; ++i) g.a[i] = add(g.a[i],f.a[i]);
			NTT(g,1,lim),NTT(h,1,lim);
			for(reg int i=0; i!=lim; ++i)
				g.a[i] = (ll)g.a[i]*h.a[i]%p;
			NTT(g,-1,lim);
			for(reg int i=n+1; i!=lim; ++i) g.a[i] = 0;
		}
		return g;
	}

	poly exp(poly f) {
		int lim = 1,n = f.t,top = 0;
		int s[70];
		poly g,h;
		memset(g.a,0,sizeof(g.a));
		while(n) {
			s[++top] = n;
			n >>= 1;
		}
		g.a[0] = 1;
		while(top--) {
			g.t = n = s[top+1];
			h = g,g = log(g);
			for(reg int i=0; i<=n; ++i) g.a[i] = dec(f.a[i],g.a[i]);
			g.a[0] = add(g.a[0],1);
			while(lim<=(n<<1)) lim <<= 1;
			NTT(h,1,lim),NTT(g,1,lim);
			for(reg int i=0; i!=lim; ++i)
				g.a[i] = (ll)g.a[i]*h.a[i]%p;
			NTT(g,-1,lim);
			for(reg int i=n+1; i<=lim; ++i) g.a[i] = 0;
		}
		return g;
	}

	poly power(poly f,int k) {
		f = log(f);
		for(int i=0; i<=f.t; ++i)
			f.a[i] = (ll)f.a[i]*k%p;
		return exp(f);
	}

	inline void clear(poly &f) {
		for(reg int i=f.t+1; i<N; ++i) f.a[i] = 0;
	}

	poly inverse(poly f) {
		int n = f.t,top = 0,lim = 1;
		int s[70];
		poly g,h,q;
		memset(g.a,0,sizeof(g.a));
		while(n) {
			s[++top] = n;
			n >>= 1;
		}
		g.a[0] = power(f.a[0],p-2);
		while(top--) {
			g.t = n = s[top+1];
			q = g,h = f;
			for(reg int i=n+1; i<=f.t; ++i) h.a[i] = 0;
			while(lim<=(n<<1)) lim <<= 1;
			NTT(g,1,lim),NTT(h,1,lim);
			for(reg int i=0; i!=lim; ++i)
				g.a[i] = (ll)g.a[i]*g.a[i]%p*h.a[i]%p;
			NTT(g,-1,lim);
			for(reg int i=n+1; i!=lim; ++i) g.a[i] = 0;
			for(reg int i=0; i<=n; ++i)
				g.a[i] = dec(add(q.a[i],q.a[i]),g.a[i]);
		}
		return g;
	}

	poly mod(poly f,poly g) {
		if(f.t<g.t) return f;
		poly q = divide(f,g);
		int n = f.t,m = g.t,lim = 1;
		while(lim<=n) lim <<= 1;
		NTT(g,1,lim),NTT(q,1,lim);
		for(reg int i=0; i!=lim; ++i) g.a[i] = (ll)g.a[i]*q.a[i]%p;
		NTT(g,-1,lim);
		f.t = m-1;
		for(reg int i=0; i<m; ++i) f.a[i] = dec(f.a[i],g.a[i]);
		for(reg int i=m; i<=n; ++i) f.a[i] = 0;
		return f;
	}

	poly divide(poly f,poly g) {
		int n = f.t,m = g.t,lim = 1;
		reverse(f),reverse(g);
		f.t = g.t = n-m;
		while(lim<=(f.t<<1)) lim <<= 1;
		for(reg int i=f.t+1; i<=n; ++i) f.a[i] = 0;
		for(reg int i=g.t+1; i<=m; ++i) g.a[i] = 0;
		g = inverse(g);
		NTT(f,1,lim),NTT(g,1,lim);
		for(reg int i=0; i!=lim; ++i) f.a[i] = (ll)f.a[i]*g.a[i]%p;
		NTT(f,-1,lim);
		for(reg int i=f.t+1; i!=lim; ++i) f.a[i] = 0;
		reverse(f);
		return f;
	}

	inline void reverse(poly &f) {
		int l = f.t>>1;
		for(reg int i=0; i<=l; ++i)
			swap(f.a[i],f.a[f.t-i]);
	}

	poly integral(poly f) {
		for(reg int i=f.t; i>=1; --i)
			f.a[i] = (ll)f.a[i-1]*inv[i]%p;
		f.a[0] = 0;
		return f;
	}

	poly derivative(poly f) {
		for(reg int i=0; i<f.t; ++i)
			f.a[i] = (ll)f.a[i+1]*(i+1)%p;
		f.a[f.t] = 0;
		return f;
	}

	inline void print_poly(poly f) {
		for(int i=0; i<=f.t; ++i) {
			print(f.a[i]);
			putchar(' ');
		}
		putchar('\n');
	}

	inline void NTT(poly &f,int type,int lim) {
		int l = lg2[lim]-1;
		for(reg int i=0; i<=lim; ++i) {
			rev[i] = (rev[i>>1]>>1)|((i&1)<<l);
			if(i>=rev[i]) continue;
			swap(f.a[i],f.a[rev[i]]);
		}
		reg int r,w,x,y;
		l = LIM>>1;
		for(reg int mid=1; mid<lim; mid<<=1) {
			r = mid<<1;
			for(reg int j=0; j<lim; j+=r) {
				for(reg int k=0; k<mid; ++k) {
					w = type==1?rt[l*k]:irt[l*k];
					x = f.a[j|k];
					y = (ll)w*f.a[j|k|mid]%p;
					f.a[j|k] = add(x,y);
					f.a[j|k|mid] = dec(x,y);
				}
			}
			l >>= 1;
		}
		if(type==1) return;
		w = inv[lim];
		for(reg int i=0; i<=lim; ++i)
			f.a[i] = (ll)f.a[i]*w%p;
	}

	inline int power(int a,int t) {
		int res = 1;
		while(t) {
			if(t&1) res = (ll)res*a%p;
			a = (ll)a*a%p;
			t >>= 1;
		}
		return res;
	}
	void mul(poly&g,poly&h) {
		int lim=1;
		while(lim<=h.t+g.t) lim <<= 1;
		NTT(g,1,lim),NTT(h,1,lim);
		for(reg int i=0; i<=lim; ++i)
			g.a[i] = (ll)g.a[i]*h.a[i]%p;
		NTT(g,-1,lim);
		g.t+=h.t;
	}


};
using namespace polynomial;
poly a,b;
int cnt[N];
int f[N],Inv[N];
inline C(int n,int m){
	return (ll)f[n]*Inv[m]%p*Inv[n-m]%p;
}
int ans[N];
int main() {
	init();
	int n,k;
	f[0]=1;
	for(int i=1;i<=N;i++){
		f[i]=(ll)f[i-1]*i%p;
	}
	Inv[N]=power(f[N],p-2);
	for(int i=N-1;i>=0;i--){
		Inv[i]=(ll)Inv[i+1]*(i+1)%p;
	}
	read(n),read(k);
	for(int i=0;i<n;i++){
		int t;
		read(t);
		cnt[t]++;
	}
	for(int i=1;i<=k;i++){
		int t;
		read(t);
		int c1=0,c2=0;
		for(int i=1;i<t;i++){
			if(cnt[i]==1)c1++;
			else if(cnt[i]>1)c2++;
		}
		a.t=c2+c2;
		b.t=c1;
		for(int i=0;i<=c2+c2;i++){
			a.a[i]=C(c2+c2,i);
		}
		for(int i=0;i<=c1;i++){
			b.a[i]=(ll)C(c1,i)*power(2,i)%p;
		}
		clear(a),clear(b);
		

		

		

		

		

		mul(a,b);
		

		

		for(int i=0;i<=a.t;i++){
			ans[i+t+1]=(0ll+ans[i+t+1]+a.a[i])%p;
		}
	}
	int q;
	read(q);
	while(q--){
		int t;
		read(t);
		print(ans[t/2]);
		putchar('\n');
	}
}