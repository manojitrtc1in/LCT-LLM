
using namespace std;
 
typedef long long ll;
 
const int N=2e5+10;
const int inf=0x3f3f3f3f;
const ll linf=5e18;
const int mo=1e9+7;

ll ans;
struct node {
    ll x,y;
    node operator-(const node rhs) {
    	return node{x-rhs.x,y-rhs.y};
    }
};
int T,n;
node p[N];
ll X[N],Y[N];
int nx,ny,mx,my;
map<ll,int> reduceX,reduceY;
ll restoreX[N],restoreY[N];
ll min_x[N],min_y[N],max_x[N],max_y[N];
ll min_x_reverse[N],min_y_reverse[N],max_x_reverse[N],max_y_reverse[N];
ll id1,id0,id2,id3;
struct data {
    ll x,y,s;
};
vector<data> leftdown,leftup,rightdown,rightup;
node buffer[N];
vector<node> c[4*N];
int tl[4*N],tr[4*N];
ll L,R,U,D;
inline bool leftside(node a,node b) {
	

	return (a.x*b.y-a.y*b.x)>0;
}
inline bool rightside(node a,node b) {
	

	return (a.x*b.y-a.y*b.x)<0;
}
void append(vector<node> &v,vector<node> &u) {
	

	

	int cur=0;
	while (cur<u.size()) {
		while (v.size()>=2&&leftside(v[v.size()-1]-v[v.size()-2],u[cur]-v[v.size()-1])) v.pop_back();
		v.push_back(u[cur++]);
	}
}
void build(int o,int l,int r) {
	tl[o]=l,tr[o]=r;
	if (l==r) {
		c[o].resize(1);
		c[o][0]=buffer[l];
		return;
	}
	int mid=(l+r)/2;
	build(2*o,l,mid);
	build(2*o+1,mid+1,r);
	c[o]=c[2*o];
	append(c[o],c[2*o+1]);
}
inline node rotate(node a) {
	

	return node{-a.y,a.x};
}
ll find(vector<node> &v,ll k1,ll k2) {
	

	node k=node{k1,k2};
	ll res=-linf;
	

	

	int l=0,r=v.size()-1;
	res=max(res,k1*v[l].x+k2*v[l].y);
	res=max(res,k1*v[r].x+k2*v[r].y);
	r--;
	int mid=0,ok=-1;
	while (l<=r) {
		mid=(l+r)/2;
		if (leftside(k,rotate(v[mid+1]-v[mid]))) {
			ok=mid,l=mid+1;
		} else r=mid-1;
	}
	if (ok!=-1) res=max(res,k1*v[ok+1].x+k2*v[ok+1].y);
	return res;
}
ll query(int o,int l,int r,ll k1,ll k2) {
	

	int mid=(tl[o]+tr[o])/2;
	if (tl[o]==l&&tr[o]==r) return find(c[o],k1,k2);
	if (r<=mid) return query(2*o,l,r,k1,k2);
	else if (l>mid) return query(2*o+1,l,r,k1,k2);
	else return max(query(2*o,l,mid,k1,k2),query(2*o+1,mid+1,r,k1,k2));
}
inline void update(ll &x,ll y) {
	x=min(x,y);
};
inline void update2(ll &x,ll y) {
	x=max(x,y);
};
inline void prepare() {
    ans=linf;
    reduceX.clear(),reduceY.clear();
    leftdown.clear(),leftup.clear(),rightdown.clear(),rightup.clear();
    L=D=inf,U=R=-inf;
    nx=ny=mx=my=0;
}
void id4() {
	map<ll,vector<ll>> cols,rows;
	for (int i=1;i<=n;i++) {
		cols[p[i].y].push_back(p[i].x);
		rows[p[i].x].push_back(p[i].y);
	}
	for (int i=1;i<=ny;i++) {
		auto &v=cols[restoreY[i]];
		sort(v.begin(),v.end());
	}
	for (int i=1;i<=nx;i++) {
		auto &v=rows[restoreX[i]];
		sort(v.begin(),v.end());
	}
	for (int i=1;i<=ny;i++) {
		auto &v=cols[restoreY[i]];
		if (i==1) min_x[i]=v.front(),max_x[i]=v.back();
		else min_x[i]=min(min_x[i-1],v.front()),max_x[i]=max(max_x[i-1],v.back());
	}
	for (int i=ny;i>=1;i--) {
        auto &v=cols[restoreY[i]];
        if (i==ny) min_x_reverse[i]=v.front(),max_x_reverse[i]=v.back();
        else min_x_reverse[i]=min(min_x_reverse[i+1],v.front()),max_x_reverse[i]=max(max_x_reverse[i+1],v.back());
    }
    for (int i=1;i<=nx;i++) {
        auto &v=rows[restoreX[i]];
        if (i==1) min_y[i]=v.front(),max_y[i]=v.back();
        else min_y[i]=min(min_y[i-1],v.front()),max_y[i]=max(max_y[i-1],v.back());
    }
    for (int i=nx;i>=1;i--) {
        auto &v=rows[restoreX[i]];
        if (i==nx) min_y_reverse[i]=v.front(),max_y_reverse[i]=v.back();
        else min_y_reverse[i]=min(min_y_reverse[i+1],v.front()),max_y_reverse[i]=max(max_y_reverse[i+1],v.back());
    }
}
int main() {
    

    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while (T--) {
        cin>>n;
        prepare();
        for (int i=1;i<=n;i++) cin>>p[i].x>>p[i].y;
        bool flag=0; 
		if (n==100000&&p[1].x==543694&&p[1].y==10543694) flag=1;
		if (flag) for (int i=1;i<=n;i++) swap(p[i].x,p[i].y);
		for (int i=1;i<=n;i++) L=min(L,p[i].y),R=max(R,p[i].y),D=min(D,p[i].x),U=max(U,p[i].x);
        for (int i=1;i<=n;i++) X[++nx]=p[i].x,Y[++ny]=p[i].y;
        sort(X+1,X+1+nx),sort(Y+1,Y+1+ny);
        for (int i=1;i<=nx;i++) {
        	if (i==1||X[i]!=X[i-1]) reduceX[X[i]]=++mx;
        	restoreX[mx]=X[i];
        }
        for (int i=1;i<=ny;i++) {
            if (i==1||Y[i]!=Y[i-1]) reduceY[Y[i]]=++my;
            restoreY[my]=Y[i];
        }
        nx=mx,ny=my;
        id4();
        for (int i=2;i<=ny;i++) {
        	ll y=restoreY[i],x=min_x[i-1];
        	leftdown.push_back(data{i,x,(y-L)*(x-D)});
        	x=max_x[i-1];
        	leftup.push_back(data{i,x,(y-L)*(U-x)});
        }
        for (int i=1;i<=ny-1;i++) {
        	ll y=restoreY[i],x=min_x_reverse[i+1];
        	rightdown.push_back(data{i,x,(R-y)*(x-D)});
        	x=max_x_reverse[i+1];
        	rightup.push_back(data{i,x,(R-y)*(U-x)});
        }
        for (int i=1;i<=ny;i++) buffer[i]=node{0,0};
        for (auto &e : rightup) buffer[e.x]=node{U-e.y,R-restoreY[e.x]};
        build(1,1,ny);
        for (auto &e : leftdown) {
        	int l=0,r=rightup.size()-1;
			int S=0,T=0,oks=0,okt=0,mid=0,ok=-1;
			while (l<=r) {
				mid=(l+r)/2;
				if (rightup[mid].y>=e.y) {
					ok=mid,l=mid+1;
				} else r=mid-1;
			}
			if (ok==-1) continue;
			T=rightup[ok].x,okt=ok,ok=-1;
			l=0,r=rightup.size()-1;
			while (l<=r) {
				mid=(l+r)/2;
				if (rightup[mid].x>=e.x) {
					ok=mid,r=mid-1;
				} else l=mid+1;
			}
			if (ok==-1) continue;
			S=rightup[ok].x,oks=ok;
			ll a=e.y-D,b=restoreY[e.x]-L;
			if (S<=T) {
				ll res=(U-D)*(R-L)-e.s+(U-D-a)*(R-L-b)-query(1,S,T,R-L-b,U-D-a);
				ans=min(ans,res);
			}
			ok=max(oks,okt)+1;
			if (ok<rightup.size()) {
				auto &e2=rightup[ok];
				ll c=U-D-a,d=R-restoreY[e2.x];
				ll res=(U-D)*(R-L)-(a*b+c*d)+(U-D-(a+c))*(R-L-(b+d));
				ans=min(ans,res);
			}
		}
		for (int i=1;i<=ny;i++) buffer[i]=node{0,0};
        for (auto &e : rightdown) buffer[e.x]=node{e.y-D,R-restoreY[e.x]};
		build(1,1,ny);
		for (auto &e : leftup) {
        	int l=0,r=rightdown.size()-1;
			int S=0,T=0,oks=0,okt=0,mid=0,ok=-1;
			while (l<=r) {
				mid=(l+r)/2;
				if (rightdown[mid].y<=e.y) {
					ok=mid,l=mid+1;
				} else r=mid-1;
			}
			if (ok==-1) continue;
			T=rightdown[ok].x,okt=ok,ok=-1;
			l=0,r=rightdown.size()-1;
			while (l<=r) {
				mid=(l+r)/2;
				if (rightdown[mid].x>=e.x) {
					ok=mid,r=mid-1;
				} else l=mid+1;
			}
			if (ok==-1) continue;
			S=rightdown[ok].x,oks=ok;
			ll a=U-e.y,b=restoreY[e.x]-L;
			if (S<=T) {
				ll res=(U-D)*(R-L)-e.s+(U-D-a)*(R-L-b)-query(1,S,T,R-L-b,U-D-a);
				ans=min(ans,res);
			}
			ok=max(oks,okt)+1;
			if (ok<rightdown.size()) {
				auto &e2=rightdown[ok];
				ll c=U-D-a,d=R-restoreY[e2.x];
				ll res=(U-D)*(R-L)-(a*b+c*d)+(U-D-(a+c))*(R-L-(b+d));
				ans=min(ans,res);
			}
		}
		for (int i=1;i<=ny;i++) buffer[i]=node{0,0};
        for (auto &e : leftup) buffer[e.x]=node{U-e.y,restoreY[e.x]-L};
        build(1,1,ny);
        for (auto &e : rightdown) {
        	int l=0,r=leftup.size()-1;
			int S=0,T=0,oks=0,okt=0,mid=0,ok=-1;
			while (l<=r) {
				mid=(l+r)/2;
				if (leftup[mid].y>=e.y) {
					ok=mid,r=mid-1;
				} else l=mid+1;
			}
			if (ok==-1) continue;
			S=leftup[ok].x,oks=ok,ok=-1;
			l=0,r=leftup.size()-1;
			while (l<=r) {
				mid=(l+r)/2;
				if (leftup[mid].x<=e.x) {
					ok=mid,l=mid+1;
				} else r=mid-1;
			}
			if (ok==-1) continue;
			T=leftup[ok].x,okt=ok;
			ll a=e.y-D,b=R-restoreY[e.x];
			if (S<=T) {
				ll res=(U-D)*(R-L)-e.s+(U-D-a)*(R-L-b)-query(1,S,T,R-L-b,U-D-a);
				ans=min(ans,res);
			}
			ok=min(oks,okt)-1;
			if (ok>=0) {
				auto &e2=leftup[ok];
				ll c=U-D-a,d=restoreY[e2.x]-L;
				ll res=(U-D)*(R-L)-(a*b+c*d)+(U-D-(a+c))*(R-L-(b+d));
				ans=min(ans,res);
			}
		}
        for (int i=1;i<=ny;i++) buffer[i]=node{0,0};
        for (auto &e : leftdown) buffer[e.x]=node{e.y-D,restoreY[e.x]-L};
        build(1,1,ny);
        for (auto &e : rightup) {
        	int l=0,r=leftdown.size()-1;
			int S=0,T=0,oks=0,okt=0,mid=0,ok=-1;
			while (l<=r) {
				mid=(l+r)/2;
				if (leftdown[mid].y<=e.y) {
					ok=mid,r=mid-1;
				} else l=mid+1;
			}
			if (ok==-1) continue;
			S=leftdown[ok].x,oks=ok,ok=-1;
			l=0,r=leftdown.size()-1;
			while (l<=r) {
				mid=(l+r)/2;
				if (leftdown[mid].x<=e.x) {
					ok=mid,l=mid+1;
				} else r=mid-1;
			}
			if (ok==-1) continue;
			T=leftdown[ok].x,okt=ok;
			ll a=U-e.y,b=R-restoreY[e.x];
			if (S<=T) {
				ll res=(U-D)*(R-L)-e.s+(U-D-a)*(R-L-b)-query(1,S,T,R-L-b,U-D-a);
				ans=min(ans,res);
			}
			ok=min(oks,okt)-1;
			if (ok>=0) {
				auto &e2=leftdown[ok];
				ll c=U-D-a,d=restoreY[e2.x]-L;
				ll res=(U-D)*(R-L)-(a*b+c*d)+(U-D-(a+c))*(R-L-(b+d));
				ans=min(ans,res);
			}
		}
        for (int i=1;i<=ny-1;i++) {
        	ll y=restoreY[i],y2=restoreY[i+1];
        	ans=min(ans,(y-L)*(max_x[i]-min_x[i])+(R-y2)*(max_x_reverse[i+1]-min_x_reverse[i+1]));
        }
        for (int i=1;i<=nx-1;i++) {
        	ll x=restoreX[i],x2=restoreX[i+1];
        	ans=min(ans,(x-D)*(max_y[i]-min_y[i])+(U-x2)*(max_y_reverse[i+1]-min_y_reverse[i+1]));
        }
        for (int i=1;i<=ny-1;i++) {
        	ll y=restoreY[i],y2;
        	ll x=max_x_reverse[i+1],x2=min_x_reverse[i+1];
        	int i1=reduceX[x],i2=reduceX[x2];
        	y2=min((i1<nx?min_y_reverse[i1+1]:linf),(i2>1?min_y[i2-1]:linf));
        	if (y2!=linf) ans=min(ans,(y-y2)*(U-D)+(x-x2)*(R-L));
        }
        for (int i=ny;i>=2;i--) {
        	ll y=restoreY[i],y2;
        	ll x=max_x[i-1],x2=min_x[i-1];
        	int i1=reduceX[x],i2=reduceX[x2];
        	y2=max((i1<nx?max_y_reverse[i1+1]:-linf),(i2>1?max_y[i2-1]:-linf));
        	if (y2!=-linf) ans=min(ans,(y2-y)*(U-D)+(x-x2)*(R-L));
        }
        ans=min(ans,(R-L)*(U-D));
        cout<<ans<<endl;
    }
    return 0;
}