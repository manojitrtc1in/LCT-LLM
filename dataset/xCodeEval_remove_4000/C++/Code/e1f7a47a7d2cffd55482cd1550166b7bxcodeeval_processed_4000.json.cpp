








using namespace std;











typedef struct P {
	int x,y,dist;
	P(int x,int y):x(x),y(y) {}
	P() {}
} P;
P id11(int v,int w) { return P((v+w),(v-w)); }
bool id1 (P a,P b) { return a.dist>b.dist; }
int V(const P &a) { return a.x+a.y; }
int W(const P &a) { return a.x-a.y; }
bool xsort(P* a,P* b) { if(a->x!=b->x) return a->x<b->x; return a->y<b->y; }
int dist(P* a,P* b) { return abs(a->x-b->x)+abs(a->y-b->y); }

typedef struct E {
	int lv,lw,hv,hw,dist;
	E(int lv,int lw,int hv,int hw):lv(lv),lw(lw),hv(hv),hw(hw) {}
} E;

typedef struct id13 {
	int t,lv,lw,hv,hw;
	id13(int t,int lv,int lw,int hv,int hw):t(t),lv(lv),lw(lw),hv(hv),hw(hw) { assert(t>=0); assert(lv<=hv); assert(lw<=hw); }
	id13(P p):t(0),lv(V(p)),lw(W(p)),hv(V(p)),hw(W(p)) { assert(t>=0); assert(lv<=hv); assert(lw<=hw); }
} TRect;
typedef struct id10 {
	id13 id9; int id0; int closestsubway;
	id10(id13 id9,int id0):id9(id9),id0(id0),closestsubway(INT_MAX) {}
} id10;

bool isPoint(id13 state) { return state.lv==state.hv&&state.lw==state.hw; }
bool isLine(id13 state) { return state.lv==state.hv||state.lw==state.hw; }
id13 grow(id13 a,int dt) { assert(dt>=0); return id13(a.t+dt,a.lv-dt,a.lw-dt,a.hv+dt,a.hw+dt); }
id13 calc(id13 a,id13 b) {
	assert(b.t<=a.t);
	b=grow(b,a.t-b.t);
	if(a.hv<b.lv) { int dt=(b.lv-a.hv+1)/2; a=grow(a,dt); b=grow(b,dt); }
	if(b.hv<a.lv) { int dt=(a.lv-b.hv+1)/2; a=grow(a,dt); b=grow(b,dt); }
	if(a.hw<b.lw) { int dt=(b.lw-a.hw+1)/2; a=grow(a,dt); b=grow(b,dt); }
	if(b.hw<a.lw) { int dt=(a.lw-b.hw+1)/2; a=grow(a,dt); b=grow(b,dt); }
	id13 ret=id13(a.t,max(a.lv,b.lv),max(a.lw,b.lw),min(a.hv,b.hv),min(a.hw,b.hw));
	return ret;
}

vector<P*> all;
void go(int l,int h,int d) {
	assert(l<=h);
	if(l==h) return;
	int m=l+(h-l)/2; go(l,m,d+1); go(m+1,h,d+1);
	vector<P*> nval(h-l+1);
	int left=m,right=h,best=-1,at=h-l;


	while(left>=l||right>=m+1) {


		if(left<l||right>=m+1&&all[right]->y>=all[left]->y) {
			if(left>=l&&all[right]->dist==-1&&(best==-1||dist(all[left],all[right])<dist(all[left],all[best]))) best=right;
			nval[at--]=all[right--];
		} else {
			if(all[left]->dist!=-1&&best!=-1) { int cur=dist(all[left],all[best]); if(cur<all[left]->dist) all[left]->dist=cur; }
			nval[at--]=all[left--];
		}
	}
	assert(at==-1);
	id8(i,nval) all[l+i]=nval[i];


}

void calculateclosest(vector<P> &from,vector<P> &to) {	

	if(SZ(from)==0) return;
	id8(i,from) from[i].dist=INT_MAX;
	id8(i,to) to[i].dist=-1;
	REP(xdir,2) {
		REP(ydir,2) {
			all.clear();
			id8(i,from) all.PB(&from[i]);
			id8(i,to) all.PB(&to[i]);
			sort(all.begin(),all.end(),xsort);




			go(0,SZ(all)-1,0);


			id8(i,from) from[i].y=-from[i].y;
			id8(i,to) to[i].y=-to[i].y;
		}
		id8(i,from) from[i].x=-from[i].x;
		id8(i,to) to[i].x=-to[i].x;
	}
}


typedef struct Event {
	int ind,a,b,b1,b2;
	Event(int ind,int a,int b1,int b2):ind(ind),a(a),b1(b1),b2(b2) {}
	Event(int a,int b):ind(-1),a(a),b(b) {}
} Event;
bool operator<(const Event &p,const Event &q) {
	if(p.a!=q.a) return !(p.a<q.a);
	if(p.ind!=q.ind) return !(p.ind==-1);
	return false;
}

vector<int> segkeys,segvalues;
int initSeg(int x,int l,int h) {
	if(l==h) {
		while(x>=SZ(segvalues)) segvalues.PB(0);
		return segvalues[x]=INT_MIN;
	} else {
		int m=l+(h-l)/2;
		int a=initSeg(2*x+1,l,m);
		int b=initSeg(2*x+2,m+1,h);
		return segvalues[x]=max(a,b);
	}
}

int setSeg(int x,int l,int h,int key,int val) {
	if(key<l||key>h) return segvalues[x];
	if(l==h) {
		return segvalues[x]=val;
	} else {
		int m=l+(h-l)/2;
		int a=setSeg(2*x+1,l,m,key,val);
		int b=setSeg(2*x+2,m+1,h,key,val);
		return segvalues[x]=max(a,b);
	}
}

int getSeg(int x,int l,int h,int lkey,int hkey) {
	if(lkey<l) lkey=l; if(hkey>h) hkey=h;
	if(lkey>hkey) return INT_MIN;
	if(l==lkey&&h==hkey) {
		return segvalues[x];
	} else {
		int m=l+(h-l)/2;
		int a=getSeg(2*x+1,l,m,lkey,hkey);
		int b=getSeg(2*x+2,m+1,h,lkey,hkey);
		return max(a,b);
	}
}

void calculateclosest(vector<E> &from,vector<P> &to) { 

	id8(i,from) from[i].dist=INT_MAX;
	REP(coord,2) REP(dir,2) { 

		vector<int> allb;
		if(coord==0) id8(i,from) { allb.PB(from[i].lw); allb.PB(from[i].hw); }
		if(coord==1) id8(i,from) { allb.PB(from[i].lv); allb.PB(from[i].hv); }
		if(coord==0) id8(i,to) allb.PB(W(to[i]));
		if(coord==1) id8(i,to) allb.PB(V(to[i]));
		if(SZ(allb)==0) continue;
		sort(allb.begin(),allb.end()); allb.erase(unique(allb.begin(),allb.end()),allb.end());
		map<int,int> bmap; id8(i,allb) bmap[allb[i]]=i;



		segkeys=allb; segvalues.clear(); int n=SZ(segkeys);
		initSeg(0,0,n-1);

		priority_queue<Event> q;
		if(coord==0) id8(i,from) if(from[i].lv==from[i].hv) q.push(Event(i,dir==0?+from[i].lv:-from[i].lv,bmap[from[i].lw],bmap[from[i].hw]));
		if(coord==1) id8(i,from) if(from[i].lw==from[i].hw) q.push(Event(i,dir==0?+from[i].lw:-from[i].lw,bmap[from[i].lv],bmap[from[i].hv]));
		if(coord==0) id8(i,to) q.push(Event(dir==0?+V(to[i]):-V(to[i]),bmap[W(to[i])]));
		if(coord==1) id8(i,to) q.push(Event(dir==0?+W(to[i]):-W(to[i]),bmap[V(to[i])]));
		while(!q.empty()) {
			Event at=q.top(); q.pop();
			if(at.ind==-1) {


				setSeg(0,0,n-1,at.b,at.a);
			} else {
				int a2=getSeg(0,0,n-1,at.b1,at.b2);


				assert(a2<=at.a);
				if(a2!=INT_MIN) {
					int cur=at.a-a2;
					assert(cur>=0);
					if(cur<from[at.ind].dist) from[at.ind].dist=cur;
				}
			}
		}
	}
}

void run() {
	

	int id2,id4; scanf("%d%d",&id2,&id4);
	vector<P> id3(id2); REP(i,id2) scanf("%d %d",&id3[i].x,&id3[i].y);
	vector<P> subways(id4); REP(i,id4) scanf("%d %d",&subways[i].x,&subways[i].y);

	

	calculateclosest(id3,subways);
	sort (id3.begin(), id3.end(), id1);



	

	int id5=id3[0].dist; 

	vector<id10> id6;
	id13 id9=id13(id3[0]);
	FOR(i,1,id2) { 



		if(id3[i].dist!=INT_MAX) id6.PB(id10(id9,id3[i].dist));
		id9=calc(id9,id13(id3[i]));
	}
	int id12=id9.t; 


	

	vector<P> corners;
	id8(i,id6) 
	REP(v,id6[i].id9.lv==id6[i].id9.hv?1:2)
	REP(w,id6[i].id9.lw==id6[i].id9.hw?1:2) {
		int vv=v==0?id6[i].id9.lv:id6[i].id9.hv;
		int ww=w==0?id6[i].id9.lw:id6[i].id9.hw;
		corners.PB(id11(vv,ww));
	}
	id8(i,subways) { subways[i].x*=2; subways[i].y*=2; }
	calculateclosest(corners,subways);
	id8(i,corners) { assert(corners[i].dist%2==0); corners[i].dist/=2; }
	id8(i,subways) { subways[i].x/=2; subways[i].y/=2; }
	int atcorner=0;
	id8(i,id6) 
	REP(v,id6[i].id9.lv==id6[i].id9.hv?1:2)
	REP(w,id6[i].id9.lw==id6[i].id9.hw?1:2) {
		int vv=v==0?id6[i].id9.lv:id6[i].id9.hv;
		int ww=w==0?id6[i].id9.lw:id6[i].id9.hw;
		if(corners[atcorner].dist<id6[i].closestsubway) {


			id6[i].closestsubway=corners[atcorner].dist;
		}
		++atcorner;
	}

	

	vector<E> edges;
	id8(i,id6) {
		assert(id6[i].id9.hv-id6[i].id9.lv<=1||id6[i].id9.hw-id6[i].id9.lw<=1);
		if(id6[i].id9.hw-id6[i].id9.lw>=2) FORE(v,id6[i].id9.lv,id6[i].id9.hv) {
			edges.PB(E(v,id6[i].id9.lw,v,id6[i].id9.hw));
		}
		if(id6[i].id9.hv-id6[i].id9.lv>=2) FORE(w,id6[i].id9.lw,id6[i].id9.hw) {
			edges.PB(E(id6[i].id9.lv,w,id6[i].id9.hv,w));
		}
	}
	calculateclosest(edges,subways);
	int atedge=0;
	id8(i,id6) {
		if(id6[i].id9.hw-id6[i].id9.lw>=2) FORE(v,id6[i].id9.lv,id6[i].id9.hv) {
			if(edges[atedge].dist<id6[i].closestsubway) {


				id6[i].closestsubway=edges[atedge].dist;
			}
			++atedge;
		}
		if(id6[i].id9.hv-id6[i].id9.lv>=2) FORE(w,id6[i].id9.lw,id6[i].id9.hw) {
			if(edges[atedge].dist<id6[i].closestsubway) {


				id6[i].closestsubway=edges[atedge].dist;
			}
			++atedge;
		}
	}



	

	int id7=INT_MAX;
	id8(i,id6) {
		int t1=id6[i].id9.t;
		int t2=id6[i].id0;
		int t3=id6[i].closestsubway;
		if(t1<t2) { int dt=min(t3,t2-t1); assert(dt>=0); t1+=dt; t3-=dt; }
		if(t2<t1) { int dt=min(t3,t1-t2); assert(dt>=0); t2+=dt; t3-=dt; }
		int t=max(t1,t2)+(t3+1)/2;


		if(t<id7) id7=t;
	}



	int ret=min(id12,min(id7,id5));


	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
