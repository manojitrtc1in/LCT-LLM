
















using namespace std;  










typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }


const int MAXH=1000;
const int MAXW=1000;
const int MAXB=10;
const int MAXSEG=2+9*MAXB;
const int MAXC=2*MAXH*MAXW+2;
const int id20=5;
const int MAXP=id20*MAXH*MAXW;
const int DX[]={-1,0,+1,0},DY[]={0,+1,0,-1};

int h,w,nq;
char g[MAXH][MAXW+1];
int id15;
int clen[MAXC];
int coff[MAXC+1];
int np;
int px[MAXP],py[MAXP],pd[MAXP];
int pcyc[MAXH][MAXW][id20],pcycidx[MAXH][MAXW][id20],id0[MAXH][MAXW];
int id12,id10;
int id18[MAXH][MAXW];
int id11[MAXH][MAXW][4],id2[MAXH][MAXW][4];
set<ll> common;


int normidx(int c,int idx) { while(idx<0) idx+=clen[c]; while(idx>=clen[c]) idx-=clen[c]; return idx; }
int id8(int c,int idx) { return px[coff[c]+idx]; }
int id3(int c,int idx) { return py[coff[c]+idx]; }
int id7(int c,int idx) { return pd[coff[c]+idx]; }

int id4(int sx,int sy,int sd) {
	

	int x=sx,y=sy,d=sd,c=id15++; clen[c]=0;
	while(true) {
		int p=np++; ++clen[c]; int nx,ny;
		if(sx==0&&sy==0&&sd==0&&x==h-1&&y==w-1&&d==1) d=4;
		if(sx==h-1&&sy==w-1&&sd==2&&x==0&&y==0&&d==3) d=4;
		while(d!=4) {
			nx=x+DX[d],ny=y+DY[d];
			if(0<=nx&&nx<h&&0<=ny&&ny<w&&g[nx][ny]=='.') break;
			assert(id11[x][y][d]==-1); id11[x][y][d]=c; id2[x][y][d]=p-coff[c];
			d=(d+1)%4;
		}
		px[p]=x,py[p]=y,pd[p]=d;
		

		if(d==4||nx==sx&&ny==sy) break;
		x=nx,y=ny,d=(d+3)%4;
	}
	

	coff[id15]=coff[c]+clen[c]; return c;
}
void precalc() {
	id15=0,np=0; coff[0]=0; memset(id11,-1,sizeof(id11)); memset(id2,-1,sizeof(id2)); memset(id18,-1,sizeof(id18));
	id12=id4(0,0,0);
	id10=id4(h-1,w-1,2);
	static int qx[MAXH*MAXW],qy[MAXH*MAXW],qhead,qtail; static bool reach[MAXH][MAXW]; qhead=qtail=0; memset(reach,false,sizeof(reach)); qx[qhead]=0,qy[qhead]=0,++qhead,reach[0][0]=true;
	while(qtail<qhead) {
		int x=qx[qtail],y=qy[qtail]; ++qtail;
		REP(k,4) { int nx=x+DX[k],ny=y+DY[k]; if(0<=nx&&nx<h&&0<=ny&&ny<w&&g[nx][ny]=='.'&&!reach[nx][ny]) qx[qhead]=nx,qy[qhead]=ny,++qhead,reach[nx][ny]=true; }
	}
	REP(x,h) REP(y,w) if(reach[x][y]) REP(k,4) { int nx=x+DX[k],ny=y+DY[k]; if(0<=nx&&nx<h&&0<=ny&&ny<w&&g[nx][ny]!='.'&&id11[x][y][k]==-1) id4(x,y,k); }
	REP(x,h) REP(y,w) if(g[x][y]=='.') { int c=id18[x][y]=id15++; int p=np++; px[p]=x,py[p]=y,pd[p]=4; clen[c]=1; coff[id15]=coff[c]+clen[c]; }

	

	memset(id0,0,sizeof(id0)); REP(c,id15) FOR(j,coff[c],coff[c+1]) { int x=px[j],y=py[j],d=pd[j]; int i=id0[x][y]++; pcyc[x][y][i]=c; pcycidx[x][y][i]=j-coff[c]; }
	common.clear(); REP(x,h) REP(y,w) REP(i,id0[x][y]) REP(j,id0[x][y]) if(pcyc[x][y][i]<pcyc[x][y][j]) common.insert((ll)id15*pcyc[x][y][i]+pcyc[x][y][j]); common.erase((ll)id15*id12+id10); common.erase((ll)id15*id10+id12);
	

}


typedef struct Seg { int cyc,l,r,len,nd,prv,nxt; } Seg;

int nb;
int bx[MAXB],by[MAXB];
int bcnt[MAXB],bat[MAXB],bseg[MAXB],bpos[MAXB];
int q[4*MAXB],qhead,qtail;

int shead[2];
Seg seg[MAXSEG]; int scnt;

void printpath(int s) {
	while(seg[s].prv!=-1) s=seg[s].prv;
	for(;s!=-1;s=seg[s].nxt) {
		printf("\t\t[%d,%d]",id8(seg[s].cyc,seg[s].l),id3(seg[s].cyc,seg[s].l)); if(seg[s].l!=seg[s].r) printf("-[%d,%d]",id8(seg[s].cyc,seg[s].r),id3(seg[s].cyc,seg[s].r));
		printf("<%d-%d-%d>(%d)\n",seg[s].prv,s,seg[s].nxt,seg[s].len);
	}
}
int createseg(int cyc,int l,int r,int len,int nd) { seg[scnt].cyc=cyc,seg[scnt].l=l,seg[scnt].r=r,seg[scnt].len=len,seg[scnt].nd=nd,seg[scnt].prv=seg[scnt].nxt=-1; return scnt++; }
bool id1(int x,int y,int i,int c) {
	return pcyc[x][y][i]==c;
}
int id9(int x,int y,int i,int c) {
	return pcycidx[x][y][i];
}
bool id21(int x,int y,int i,int s) {
	if(pcyc[x][y][i]==seg[s].cyc) {
		int idx=pcycidx[x][y][i];
		if(seg[s].l<=seg[s].r&&seg[s].l<=idx&&idx<=seg[s].r) return true;
		if(seg[s].l>seg[s].r&&(idx<=seg[s].r||idx>=seg[s].l)) return true;
	}
	return false;
}
int id6(int x,int y,int i,int s) {
	if(pcyc[x][y][i]==seg[s].cyc) {
		int idx=pcycidx[x][y][i];
		if(seg[s].l<=seg[s].r&&seg[s].l<=idx&&idx<=seg[s].r) return idx-seg[s].l;
		if(seg[s].l>seg[s].r&&(idx<=seg[s].r||idx>=seg[s].l)) return idx-seg[s].l+(idx<=seg[s].r?clen[seg[s].cyc]:0);
	}
	assert(false); return -1;
}
bool bonseg(int b,int i,int s) { return id21(bx[b],by[b],i,s); }
bool id17(int b,int s) {
	REP(j,id0[bx[b]][by[b]]) if(bonseg(b,j,s)) return true;
	return false;
}
int id5(int b,int i,int s) { return id6(bx[b],by[b],i,s); }
int id13(int b,int s) {
	int ret=-1; REP(j,id0[bx[b]][by[b]]) if(bonseg(b,j,s)) { assert(ret==-1); ret=id5(b,j,s); } assert(ret!=-1); return ret;
}
int id16(int c,int idx,int x,int y) {
	int ret=-1;
	

	REP(j,id0[x][y]) if(id1(x,y,j,c)) {
		int cur=id9(x,y,j,c); 

		if(ret==-1||(ret>=idx&&cur>=idx&&cur<ret||ret<idx&&(cur>=idx||cur<ret))) ret=cur;
	}
	assert(ret!=-1); return ret;
}
void id14(int s,int pos,int &x,int &y,int &d) {
	int idx=normidx(seg[s].cyc,seg[s].l+pos);
	x=id8(seg[s].cyc,idx),y=id3(seg[s].cyc,idx),d=pos==seg[s].len-1?seg[s].nd:id7(seg[s].cyc,idx);
}
void ssplit(int s,int pos,int &pseg,int &nseg) {
	while(pos<=0) { assert(seg[s].prv!=-1); s=seg[s].prv; pos+=seg[s].len; }
	while(pos>seg[s].len) { assert(seg[s].nxt!=-1); pos-=seg[s].len; s=seg[s].nxt; }
	if(pos==seg[s].len) { assert(seg[s].nxt!=-1); pseg=s,nseg=seg[s].nxt; seg[pseg].nxt=seg[nseg].prv=-1; return; }
	int nr=normidx(seg[s].cyc,seg[s].l+pos-1),nl=normidx(seg[s].cyc,seg[s].l+pos);
	nseg=createseg(seg[s].cyc,nl,seg[s].r,seg[s].len-pos,seg[s].nd); seg[nseg].nxt=seg[s].nxt; if(seg[nseg].nxt!=-1) seg[seg[nseg].nxt].prv=nseg;
	pseg=s,seg[pseg].r=nr,seg[pseg].len=pos,seg[pseg].nd=id7(seg[s].cyc,nr);
	seg[pseg].nxt=-1,seg[nseg].prv=-1;
	REP(i,nb) if(bcnt[i]==1&&bseg[i]==pseg&&bpos[i]>=pos) bseg[i]=nseg,bpos[i]-=pos;
}
void smerge(int pseg,int d,int nseg) {
	seg[pseg].nxt=nseg; seg[pseg].nd=d; seg[nseg].prv=pseg;
}
void sadd(int at,int nseg) {
	

	REP(i,nb) REP(j,id0[bx[i]][by[i]]) if(bonseg(i,j,nseg)) {
		int pos=id5(i,j,nseg);
		++bcnt[i],bat[i]=at,bseg[i]=nseg,bpos[i]=pos,q[qhead++]=i;
		

		assert(bcnt[i]==1);
	}
}
void sremove(int s) {
	while(seg[s].prv!=-1) s=seg[s].prv;
	while(s!=-1) {
		REP(i,nb) REP(j,id0[bx[i]][by[i]]) if(bonseg(i,j,s)) {
			--bcnt[i];
			

			assert(bcnt[i]==0);
		}
		s=seg[s].nxt;
	}
}
bool id19(int s,int at) {
	for(int ss=shead[at];ss!=-1;ss=seg[ss].nxt) {
		int a=seg[s].cyc,b=seg[ss].cyc;
		if(a>b) swap(a,b);
		if(a==b||common.count((ll)a*id15+b)) return true;
	}
	return false;
}
void fixprefix(int &lst,int &d,int &s) {
	REP(i,nb) if(bcnt[i]>0) REP(j,id0[bx[i]][by[i]]) if(bonseg(i,j,s)) {
		int ss=lst; while(ss!=-1&&!id17(i,ss)) ss=seg[ss].prv; if(ss==-1) continue;
		int spos=id5(i,j,s),sspos=id13(i,ss);
		int ss1,ss2; ssplit(ss,sspos,ss1,ss2); lst=ss1; d=seg[ss1].nd; sremove(ss2);
		if(spos!=0) { int s1,s2; ssplit(s,spos,s1,s2); s=s2; }
	}
}
bool fixsuffix(int &s,int &d,int &fst) {
	bool ret=false;
	REP(i,nb) if(bcnt[i]>0) REP(j,id0[bx[i]][by[i]]) if(bonseg(i,j,s)) {
		int ss=fst; while(ss!=-1&&!id17(i,ss)) ss=seg[ss].nxt; if(ss==-1) continue;
		int spos=id5(i,j,s),sspos=id13(i,ss);
		int ss1,ss2; ssplit(ss,sspos+1,ss1,ss2); fst=ss2; d=seg[ss1].nd; sremove(ss1);
		if(spos!=seg[s].len-1) { int s1,s2; ssplit(s,spos+1,s1,s2); s=s1; }
		ret=true;
	}
	if(ret) return ret;
	int vx=id8(seg[s].cyc,seg[s].r),vy=id3(seg[s].cyc,seg[s].r),wx=id8(seg[fst].cyc,seg[fst].l),wy=id3(seg[fst].cyc,seg[fst].l);
	

	if(vx==wx&&vy==wy) {
		int ss=fst,ss1,ss2; ssplit(ss,1,ss1,ss2); fst=ss2; d=seg[ss1].nd; sremove(ss1);
		ret=true;
	}
	return ret;
}

void fixinternal(int &s) {
	int mn[MAXB],mx[MAXB]; REP(i,nb) mn[i]=mx[i]=-1;
	REP(i,nb) REP(j,id0[bx[i]][by[i]]) if(bonseg(i,j,s)) {
		int cur=id5(i,j,s);
		if(mn[i]==-1||cur<mn[i]) mn[i]=cur;
		if(mx[i]==-1||cur>mx[i]) mx[i]=cur;
	}
	while(true) {
		

		int bidx=-1; REP(i,nb) if(mn[i]!=-1&&mx[i]!=-1&&mn[i]!=mx[i]&&(bidx==-1||mx[i]>mx[bidx])) bidx=i;  if(bidx==-1) return;
		REP(i,nb) if(mn[i]!=-1&&mx[i]!=-1&&mn[i]!=mx[i]) assert(mn[bidx]<=mn[i]&&mx[i]<=mx[bidx]||mx[i]<mn[bidx]);
		if(mn[bidx]==0) {
			int s3,s4; ssplit(s,mx[bidx]-mn[bidx],s3,s4);
			

			s=s4;
		} else {
			int s1,s2; ssplit(s,mn[bidx],s1,s2); int s3,s4; ssplit(s2,mx[bidx]-mn[bidx],s3,s4);
			

			smerge(s1,seg[s1].nd,s4); s=s1;
		}
		REP(i,nb) if(i!=bidx&&mn[i]!=-1&&mx[i]!=-1&&mn[i]!=mx[i]&&mx[i]>=mn[bidx]) mn[i]=mx[i]=-1; mn[bidx]=mx[bidx]=-1;
	}
}

bool solve() {
	

	

	

	qhead=qtail=scnt=0; memset(bcnt,0,sizeof(bcnt));
	int topinit=createseg(id12,0,clen[id12]-1,clen[id12],4); fixinternal(topinit); for(int s=topinit;s!=-1;s=seg[s].nxt) sadd(0,s); shead[0]=topinit; 

	int botinit=createseg(id10,0,clen[id10]-1,clen[id10],4); fixinternal(botinit); for(int s=botinit;s!=-1;s=seg[s].nxt) sadd(1,s); shead[1]=botinit; 

	while(qtail<qhead) {
		int bidx=q[qtail++],at=bat[bidx];
		if(bcnt[bidx]!=1) continue;
		

		int sseg,pseg,qseg,tseg; ssplit(bseg[bidx],bpos[bidx],sseg,pseg); ssplit(pseg,1,qseg,tseg); sremove(qseg); 

		int sx,sy,sd; id14(sseg,seg[sseg].len-1,sx,sy,sd);
		int tx,ty,td; id14(tseg,0,tx,ty,td);
		

		int cseg=sseg,cx=sx,cy=sy,cd=sd;
		if(sx==tx&&sy==ty) {
			int s1,s2; ssplit(tseg,1,s1,s2); sremove(s1); smerge(sseg,seg[s1].nd,s2);
		} else while(true) {
			if(cx+DX[cd]==bx[bidx]&&cy+DY[cd]==by[bidx]) cd=(cd+1)%4;
			

			int vx=cx+DX[cd],vy=cy+DY[cd]; assert(vx>=0&&vx<h&&vy>=0&&vy<w);
			int wx,wy,wd,nseg;
			if(g[vx][vy]=='.') {
				

				wx=vx,wy=vy,wd=(cd+3)%4;
				nseg=createseg(id18[vx][vy],0,0,1,wd);
			} else {
				

				int c=id11[cx][cy][cd],idx=id2[cx][cy][cd]; assert(c!=-1&&idx!=-1&&id8(c,idx)==cx&&id3(c,idx)==cy);
				cd=id7(c,idx); int sidx=normidx(c,idx+1);
				int tidx=id16(c,sidx,bx[bidx],by[bidx]); tidx=normidx(c,tidx-1);
				vx=id8(c,sidx),vy=id3(c,sidx),wx=id8(c,tidx),wy=id3(c,tidx),wd=id7(c,tidx);
				int len=tidx-sidx+1; if(len<=0) len+=clen[c];
				nseg=createseg(c,sidx,tidx,len,wd); 

				

			}
			if(id19(nseg,1-at)) return false;
			fixprefix(cseg,cd,nseg);
			bool done=fixsuffix(nseg,wd,tseg);
			fixinternal(nseg);
			

			for(int s=nseg;s!=-1;s=seg[s].nxt) sadd(at,s);
			smerge(cseg,cd,nseg);
			

			while(seg[nseg].nxt!=-1) nseg=seg[nseg].nxt;
			if(done) { smerge(nseg,wd,tseg); break; }
			cseg=nseg,cx=wx,cy=wy,cd=wd;
		}
		

	}
	return true;
}

void run() {
	scanf("%d%d%d",&h,&w,&nq);
	REP(x,h) scanf("%s",g[x]);
	precalc();
	REP(i,nq) {
		scanf("%d",&nb); REP(j,nb) scanf("%d%d",&bx[j],&by[j]),--bx[j],--by[j];
		bool have=solve();
		printf("%s\n",have?"YES":"NO"); fflush(stdout);
	}
}

int main() {
	run();
	return 0;
}
