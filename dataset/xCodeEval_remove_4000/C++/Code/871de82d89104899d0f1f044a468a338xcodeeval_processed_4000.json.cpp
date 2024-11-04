
using namespace std;

typedef long long ll;

namespace io {
	const int SIZE = (1 << 21) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
	

	
	

	inline void flush () {
		fwrite (obuf, 1, oS - obuf, stdout);
		oS = obuf;
	}
	

	inline void putc (char x) {
		*oS ++ = x;
		if (oS == oT) flush ();
	}
	

	template <class I>
	inline void gi (I &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = (x << 1) + (x << 3) + (c & 15); x *= f;
	}
	

	template <class I>
	inline void get (I &x) {
		for (c = gc(); c < 'A' || c > 'Z'; c = gc()) ;
		x = c;
	}
	

	inline void read (char *s){
		for(c = gc(); c < '1' || c > '9'; c = gc()) ;
		for(; c >= '1' && c <= '9'; c = gc()) *++s = c;
		*++s = '\0';
	}
	

	template <class I>
	inline void print (I x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
	}
	

	struct Flusher_ {~Flusher_(){flush();}}id0;
}
using io :: gi;
using io :: get;
using io :: read;
using io :: putc;
using io :: print;
const int N=1e5+5,K=55;
const ll inf=1e18;
int f[N][K];
ll g[N][K];
struct node{
	int x1,y1,x2,y2,num;
}v[N];
struct segtree{
	
	
	int col[N<<2];
	inline void build(ri x,ri l,ri r){
		col[x]=0;
		if(l==r) return;
		ri mid=l+r>>1;
		build(lc,l,mid);
		build(rc,mid+1,r);
	}
	inline void down(ri x){
		if(col[x])
			col[lc]=col[rc]=col[x],
			col[x]=0;
	}
	inline void upd(ri x,ri l,ri r,ri ql,ri qr,ri c){
		if(ql<=l&&r<=qr){
			col[x]=c;
			return;
		}
		down(x);
		ri mid=l+r>>1; 
		if(ql<=mid) upd(lc,l,mid,ql,qr,c);
		if(qr> mid) upd(rc,mid+1,r,ql,qr,c);
	}
	inline int query(ri x,ri l,ri r,ri p){
		if(l==r)
			return col[x];
		down(x);
		ri mid=l+r>>1;
		return p<=mid?query(lc,l,mid,p):query(rc,mid+1,r,p); 
	}
}seg;
struct qry{
	int x,y;
	ll t;
	int id;
}q[N];

vector<int> qL,qR,qD,qU;
int m,ansx[N],ansy[N],to[N];
inline void modifyx(ri i,ri x1,ri y1,ri x2,ri y2,ri t){


	if(t<=abs(x1-x2))
		if(x1<x2)
			ansx[i]=x1+t,
			ansy[i]=y1;
		else
			ansx[i]=x1-t,
			ansy[i]=y1;
	else
		if(y1<y2)
			ansx[i]=x2,
			ansy[i]=y1+(t-abs(x1-x2));
		else
			ansx[i]=x2,
			ansy[i]=y1-(t-abs(x1-x2));
}
inline void modifyy(ri i,ri x1,ri y1,ri x2,ri y2,ri t){
	if(t<=abs(y1-y2))
		if(y1<y2)
			ansx[i]=x1,
			ansy[i]=y1+t;
		else
			ansx[i]=x1,
			ansy[i]=y1-t;
	else
		if(x1<x2)
			ansx[i]=x1+(t-abs(y1-y2)),
			ansy[i]=y2;
		else
			ansx[i]=x1-(t-abs(y1-y2)),
			ansy[i]=y2;
}
inline void modifyL(ri i){
	ri id;
	if(v[i].x1==v[i].x2)
		if(v[i].y1<v[i].y2)
			seg.upd(1,0,m,v[i].y1,v[i].y2,i);
		else
			seg.upd(1,0,m,v[i].y2,v[i].y1,i);
	else	
		if(v[i].x1<v[i].x2)
			seg.upd(1,0,m,v[i].y1,v[i].y1,i);
		else{
			id=seg.query(1,0,m,v[i].y1);
			if(!id)
				f[v[i].num][0]=0,
				g[v[i].num][0]=v[i].x2;
			else
				f[v[i].num][0]=v[id].num,
				g[v[i].num][0]=abs(v[i].x2-v[id].x2)+abs(v[i].y2-v[id].y2); 
		}
}
inline void modifyR(ri i){
	ri id;
	if(v[i].x1==v[i].x2)
		if(v[i].y1<v[i].y2)
			seg.upd(1,0,m,v[i].y1,v[i].y2,i);
		else
			seg.upd(1,0,m,v[i].y2,v[i].y1,i);
	else
		if(v[i].x1<v[i].x2){
			id=seg.query(1,0,m,v[i].y1);
			if(!id)
				f[v[i].num][0]=0,
				g[v[i].num][0]=m-v[i].x2;
			else
				f[v[i].num][0]=v[id].num,
				g[v[i].num][0]=abs(v[i].x2-v[id].x2)+abs(v[i].y2-v[id].y2); 
		}
		else
			seg.upd(1,0,m,v[i].y1,v[i].y1,i);
}
inline void modifyD(ri i){
	ri id;
	if(v[i].x1==v[i].x2)
		if(v[i].y1<v[i].y2)
			seg.upd(1,0,m,v[i].x1,v[i].x1,i);
		else{
			id=seg.query(1,0,m,v[i].x1);
			if(!id)
				f[v[i].num][0]=0,
				g[v[i].num][0]=v[i].y2;
			else
				f[v[i].num][0]=v[id].num,
				g[v[i].num][0]=abs(v[i].x2-v[id].x2)+abs(v[i].y2-v[id].y2);
		}
	else
		if(v[i].x1<v[i].x2)
			seg.upd(1,0,m,v[i].x1,v[i].x2,i);
		else
			seg.upd(1,0,m,v[i].x2,v[i].x1,i);
}
inline void modifyU(ri i){
	ri id;
	if(v[i].x1==v[i].x2)
		if(v[i].y1<v[i].y2){
			id=seg.query(1,0,m,v[i].x1);
			if(!id)
				f[v[i].num][0]=0,
				g[v[i].num][0]=m-v[i].y2;
			else
				f[v[i].num][0]=v[id].num,
				g[v[i].num][0]=abs(v[i].x2-v[id].x2)+abs(v[i].y2-v[id].y2);
		}
		else
			seg.upd(1,0,m,v[i].x1,v[i].x1,i);
	else
		if(v[i].x1<v[i].x2)
			seg.upd(1,0,m,v[i].x1,v[i].x2,i);
		else
			seg.upd(1,0,m,v[i].x2,v[i].x1,i);
}
int main(){
	ri n,qs,i,j,k,p,id,tmp;
	register char c;
	gi(n);gi(m);
	for(i=1;i<=n;++i) gi(v[i].x1),gi(v[i].y1),gi(v[i].x2),gi(v[i].y2),v[i].num=i;
	gi(qs);
	for(i=1;i<=qs;++i){
		gi(q[i].x);gi(q[i].y);
		get(c);
		gi(q[i].t);
		q[i].id=i;
		if(c=='L')
			qL.pb(i);
		else if(c=='R')
			qR.pb(i);
		else if(c=='D')
			qD.pb(i);
		else
			qU.pb(i);
	}
	seg.build(1,0,m);
	sort(v+1,v+1+n,[&](node a,node b){ return a.x1<b.x1; });
	sort(qL.begin(),qL.end(),[&](int a,int b){ return q[a].x<q[b].x; });
	i=1;
	for(auto o:qL){
		for(;i<=n&&v[i].x1<=q[o].x;++i)
			modifyL(i);
		id=seg.query(1,0,m,q[o].y);
	

		if(!id)
			ansx[q[o].id]=max(0ll,q[o].x-q[o].t),
			ansy[q[o].id]=q[o].y;
		else{
			tmp=abs(q[o].x-v[id].x2)+abs(q[o].y-v[id].y2);
		

			if(tmp>=q[o].t)
				modifyx(q[o].id,q[o].x,q[o].y,v[id].x2,v[id].y2,q[o].t);
			else
				to[o]=v[id].num,
				q[o].t-=tmp;
		}
	}
	for(;i<=n;++i)
		modifyL(i); 
	seg.build(1,0,m);
	sort(v+1,v+1+n,[&](node a,node b){ return a.x1>b.x1; });
	sort(qR.begin(),qR.end(),[&](int a,int b){ return q[a].x>q[b].x; });
	i=1;
	for(auto o:qR){
		for(;i<=n&&v[i].x1>=q[o].x;++i)
			modifyR(i);
		id=seg.query(1,0,m,q[o].y);
		if(!id)
			ansx[q[o].id]=min((ll)m,q[o].x+q[o].t),
			ansy[q[o].id]=q[o].y;
		else{
			tmp=abs(q[o].x-v[id].x2)+abs(q[o].y-v[id].y2);
			if(tmp>=q[o].t)
				modifyx(q[o].id,q[o].x,q[o].y,v[id].x2,v[id].y2,q[o].t);
			else
				to[o]=v[id].num,
				q[o].t-=tmp;
		}
	}
	for(;i<=n;++i)
		modifyR(i);
	seg.build(1,0,m);
	sort(v+1,v+1+n,[&](node a,node b){ return a.y1<b.y1; });
	sort(qD.begin(),qD.end(),[&](int a,int b){ return q[a].y<q[b].y; });
	i=1; 
	for(auto o:qD){
		for(;i<=n&&v[i].y1<=q[o].y;++i)
			modifyD(i);
		id=seg.query(1,0,m,q[o].x);
	

		if(!id)
			ansx[q[o].id]=q[o].x,
			ansy[q[o].id]=max(0ll,q[o].y-q[o].t);
		else{
		

			tmp=abs(q[o].x-v[id].x2)+abs(q[o].y-v[id].y2);
			if(tmp>=q[o].t)
				modifyy(q[o].id,q[o].x,q[o].y,v[id].x2,v[id].y2,q[o].t);
			else
				to[o]=v[id].num,
				q[o].t-=tmp;
		}
	}
	for(;i<=n;++i)
		modifyD(i);
	seg.build(1,0,m);
	sort(v+1,v+1+n,[&](node a,node b){ return a.y1>b.y1; });
	sort(qU.begin(),qU.end(),[&](int a,int b){ return q[a].y>q[b].y; });
	i=1;
	for(auto o:qU){
		for(;i<=n&&v[i].y1>=q[o].y;++i)
			modifyU(i);
		id=seg.query(1,0,m,q[o].x);
	

		if(!id)
			ansx[q[o].id]=q[o].x,
			ansy[q[o].id]=min((ll)m,q[o].y+q[o].t);
		else{
			tmp=abs(q[o].x-v[id].x2)+abs(q[o].y-v[id].y2);
		

			if(tmp>=q[o].t)
				modifyy(q[o].id,q[o].x,q[o].y,v[id].x2,v[id].y2,q[o].t);
			else
				to[o]=v[id].num,
				q[o].t-=tmp;
		}
	}
	for(;i<=n;++i)
		modifyU(i);
	sort(v+1,v+1+n,[&](node a,node b){ return a.num<b.num; });
	for(j=1;j<=49;++j)
		for(i=1;i<=n;++i)
			f[i][j]=f[f[i][j-1]][j-1],
			g[i][j]=min(inf,g[i][j-1]+g[f[i][j-1]][j-1]);
	for(i=1;i<=qs;++i)
		if(k=to[i]){
		

			for(j=49;j>=0;--j)
				if(f[k][j]&&g[k][j]<=q[i].t)
					q[i].t-=g[k][j],
					k=f[k][j];
		

			if(p=f[k][0])
				if(v[k].x1==v[k].x2)
					modifyy(q[i].id,v[k].x2,v[k].y2,v[p].x2,v[p].y2,q[i].t);
				else
					modifyx(q[i].id,v[k].x2,v[k].y2,v[p].x2,v[p].y2,q[i].t);
			else{
			

			

				if(v[k].x1==v[k].x2)
					if(v[k].y1<v[k].y2)
						ansx[q[i].id]=v[k].x1,
						ansy[q[i].id]=min((ll)m,v[k].y2+q[i].t);
					else
						ansx[q[i].id]=v[k].x1,
						ansy[q[i].id]=max(0ll,v[k].y2-q[i].t);
				else
					if(v[k].x1<v[k].x2)
						ansx[q[i].id]=min((ll)m,v[k].x2+q[i].t),
						ansy[q[i].id]=v[k].y1;
					else
						ansx[q[i].id]=max(0ll,v[k].x2-q[i].t),
						ansy[q[i].id]=v[k].y1;
			}
		}
	for(i=1;i<=qs;++i) print(ansx[i]),putc(' '),print(ansy[i]),putc('\n');
    return 0;
}