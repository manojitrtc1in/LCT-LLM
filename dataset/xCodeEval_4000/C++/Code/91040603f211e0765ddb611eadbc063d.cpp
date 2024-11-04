#include<bits/stdc++.h>
#define pii pair <int,int>
#define tii pair <int,pii>
#define i1 first
#define i2 second
using namespace std;

const int MAXN=1e5+5;

int N, M, K;
int X, Y, Z, T;
bool dbg;

int Xi, Xa, Xl, Xr;
int Yi, Ya, Yl, Yr;
int Zi, Za, Zl, Zr;

int XP[MAXN], YP[MAXN], ZP[MAXN];
bool vis[MAXN];

struct rusuk {
	vector <pii> isi;
	int size;
	
	void add(int x,int y) {
		isi.push_back({x,y});
		return;
	}
	
	void build() {
		if (isi.empty()) {
			return;
		}
		
		sort(isi.begin(),isi.end());
		
		for (pii x : isi) {
			if (size==0) {
				size++;
				continue;
			}
			
			if (x.i2<isi[size-1].i2) {
				isi[size]=x;
				size++;
			}
		}
		
		return;
	}
	
	bool query(int x,int y) {
		if (size==0) {
			return 0;
		}
		
		if (x<isi[0].i1) {
			return 0;
		}
		
		int awa, akh, res;
		awa=1;
		akh=size-1;
		res=0;
		
		for (int cen=(awa+akh)/2;awa<=akh;cen=(awa+akh)/2) {
			if (x>=isi[cen].i1) {
				res=cen;
				awa=cen+1;
			}
			else {
				akh=cen-1;
			}
		}
		
		if (y>=isi[res].i2) {
			return 1;
		}
		
		return 0;
	}
	
	void merge(rusuk *lain) {
		int left;
		left=lain->size;
		
		for (pii x : lain->isi) {
			if (left==0) {
				break;
			}
			
			left--;
			add(x.i1,x.i2);
		}
		
		return;
	}
	
	void debug() {
		for (int i=0;i<size;i++) {
			cout<<isi[i].i1<<'-'<<isi[i].i2<<' ';
		}
		
		cout<<'\n';
		
		return;
	}
	
}
pojok[3][2][2], emp;

struct sudut {
	vector <int> id;
	vector <tii> simpan;
	vector <rusuk> isi;
	int size, init;
	
	void add(int x,int y,int z) {
		simpan.push_back({x,{y,z}});
		return;
	}
	
	void build() {
		if (simpan.empty()) {
			return;
		}
		
		sort(simpan.begin(),simpan.end());
		
		for (tii x : simpan) {
			if (size==0) {
				id.push_back(x.i1);
				isi.push_back(emp);
				size++;
				init++;
			}
			
			if (id[size-1]!=x.i1) {
				id.push_back(x.i1);
				isi.push_back(emp);
				size++;
				
				if ((init<<1)<=size) {
					init=init<<1;
				}
			}
			
			isi[size-1].add(x.i2.i1,x.i2.i2);
		}
		
		for (int i=0;i<size;i++) {
			isi[i].build();
			
			int lsb;
			i++;
			lsb=i&(-i);
			i--;
			
			if (i+lsb<size) {
				isi[i+lsb].merge(&isi[i]);
			}
		}
		
		return;
	}
	
	bool query(int x,int y,int z) {
		if (size==0) {
			return 0;
		}
		
		int now;
		now=0;
		
		for (int i=init;i;i=i>>1) {
			if (now+i>size) {
				continue;
			}
			
			if (id[now+i-1]>x) {
				continue;
			}
			
			now+=i;
			
			if (isi[now-1].query(y,z)) {
				return 1;
			}
		}
		
		return 0;
	}
	
	void debug() {
		for (int i=0;i<size;i++) {
			cout<<id[i]<<' ';
			
			isi[i].debug();
		}
		
		return;
	}
	
}
data[2][2][2];

bool keluar3() {
	if (T!=0) {
		return 0;
	}
	
	int p, q, r;
	bool a, b, c;
	
	if (X<Xl) {
		p=Xl-X;
		a=1;
	}
	else if (X>Xr) {
		p=X-Xr;
		a=0;
	}
	else {
		p=0;
	}
	
	if (Y<Yl) {
		q=Yl-Y;
		b=1;
	}
	else if (Y>Yr) {
		q=Y-Yr;
		b=0;
	}
	else {
		q=0;
	}
	
	if (Z<Zl) {
		r=Zl-Z;
		c=1;
	}
	else if (Z>Zr) {
		r=Z-Zr;
		c=0;
	}
	else {
		r=0;
	}
	
	if (dbg) {
		cout<<p<<' '<<q<<' '<<r<<'\n';
	}
	
	if (data[a][b][c].query(p,q,r)) {
		return 1;
	}
	
	return 0;
}

bool keluar2() {
	if (T==2) {
		return 0;
	}
	
	int p, q, r;
	bool a, b, c;
	
	if (X<Xl) {
		p=Xl-X;
		a=1;
	}
	else if (X>Xr) {
		p=X-Xr;
		a=0;
	}
	else {
		p=0;
	}
	
	if (Y<Yl) {
		q=Yl-Y;
		b=1;
	}
	else if (Y>Yr) {
		q=Y-Yr;
		b=0;
	}
	else {
		q=0;
	}
	
	if (Z<Zl) {
		r=Zl-Z;
		c=1;
	}
	else if (Z>Zr) {
		r=Z-Zr;
		c=0;
	}
	else {
		r=0;
	}
	
	if (q!=0&&r!=0) {
		if (pojok[0][b][c].query(q,r)) {
			return 1;
		}
	}
	
	if (r!=0&&p!=0) {
		if (pojok[1][c][a].query(r,p)) {
			return 1;
		}
	}
	
	if (p!=0&&q!=0) {
		if (pojok[2][a][b].query(p,q)) {
			return 1;
		}
	}
	
	return 0;
}

bool keluar1() {
	if (X<=Xi||X>=Xa) {
		return 1;
	}
	
	if (Y<=Yi||Y>=Ya) {
		return 1;
	}
	
	if (Z<=Zi||Z>=Za) {
		return 1;
	}
	
	return 0;
}

bool masuk() {
	T=0;
	
	if (X>=Xl&&X<=Xr) {
		T++;
	}
	
	if (Y>=Yl&&Y<=Yr) {
		T++;
	}
	
	if (Z>=Zl&&Z<=Zr) {
		T++;
	}
	
	if (T==3) {
		return 1;
	}
	
	return 0;
}

void cek() {
	int a, b, c;
	a=0;
	b=0;
	c=0;
	
	if (X<Xl) {
		swap(X,Xl);
		a=-1;
	}
	
	if (X>Xr) {
		swap(X,Xr);
		a=1;
	}
	
	if (Y<Yl) {
		swap(Y,Yl);
		b=-1;
	}
	
	if (Y>Yr) {
		swap(Y,Yr);
		b=1;
	}
	
	if (Z<Zl) {
		swap(Z,Zl);
		c=-1;
	}
	
	if (Z>Zr) {
		swap(Z,Zr);
		c=1;
	}
	
	for (int i=0;i<M;i++) {
		if (XP[i]<Xl||XP[i]>Xr) {
			continue;
		}
		
		if (YP[i]<Yl||YP[i]>Yr) {
			continue;
		}
		
		if (ZP[i]<Zl||ZP[i]>Zr) {
			continue;
		}
		
		cout<<i<<' '<<XP[i]<<' '<<YP[i]<<' '<<ZP[i]<<'\n';
	}
	
	if (a==-1) {
		swap(X,Xl);
	}
	
	if (a==1) {
		swap(X,Xr);
	}
	
	if (b==-1) {
		swap(Y,Yl);
	}
	
	if (b==1) {
		swap(Y,Yr);
	}
	
	if (c==-1) {
		swap(Z,Zl);
	}
	
	if (c==1) {
		swap(Z,Zr);
	}
	
	return;
}

void soal() {
	cout<<"CORRECT\n";
	
	for (int i=0;i<K;i++) {
		cin>>X>>Y>>Z;
		
		if (dbg) {
			cek();
		}
		
		if (masuk()) {
			cout<<"OPEN\n";
			continue;
		}
		
		if (keluar1()) {
			cout<<"CLOSED\n";
			continue;
		}
		
		if (keluar2()) {
			cout<<"CLOSED\n";
			continue;
		}
		
		if (keluar3()) {
			cout<<"CLOSED\n";
			continue;
		}
		
		cout<<"UNKNOWN\n";
	}
	
	return;
}

void build3() {
	for (int i=0;i<2;i++) {
		for (int j=0;j<2;j++) {
			for (int k=0;k<2;k++) {
				data[i][j][k].build();
			}
		}
	}
	
	return;
}

void update3() {
	for (int i=0;i<M;i++) {
		if (vis[i]) {
			continue;
		}
		
		int p, q, r;
		bool a, b, c;
		
		if (XP[i]<Xl) {
			p=Xl-XP[i];
			a=1;
		}
		else {
			p=XP[i]-Xr;
			a=0;
		}
		
		if (YP[i]<Yl) {
			q=Yl-YP[i];
			b=1;
		}
		else {
			q=YP[i]-Yr;
			b=0;
		}
		
		if (ZP[i]<Zl) {
			r=Zl-ZP[i];
			c=1;
		}
		else {
			r=ZP[i]-Zr;
			c=0;
		}
		
		data[a][b][c].add(p,q,r);
	}
	
	return;
}

void prune2() {
	for (int i=0;i<M;i++) {
		if (vis[i]) {
			continue;
		}
		
		int p, q;
		bool a, b;
		
		if (YP[i]<Yl) {
			p=Yl-YP[i];
			a=1;
		}
		else {
			p=YP[i]-Yr;
			a=0;
		}
		
		if (ZP[i]<Zl) {
			q=Zl-ZP[i];
			b=1;
		}
		else {
			q=ZP[i]-Zr;
			b=0;
		}
		
		if (pojok[0][a][b].query(p,q)) {
			vis[i]=1;
			continue;
		}
		
		if (ZP[i]<Zl) {
			p=Zl-ZP[i];
			a=1;
		}
		else {
			p=ZP[i]-Zr;
			a=0;
		}
		
		if (XP[i]<Xl) {
			q=Xl-XP[i];
			b=1;
		}
		else {
			q=XP[i]-Xr;
			b=0;
		}
		
		if (pojok[1][a][b].query(p,q)) {
			vis[i]=1;
			continue;
		}
		
		if (XP[i]<Xl) {
			p=Xl-XP[i];
			a=1;
		}
		else {
			p=XP[i]-Xr;
			a=0;
		}
		
		if (YP[i]<Yl) {
			q=Yl-YP[i];
			b=1;
		}
		else {
			q=YP[i]-Yr;
			b=0;
		}
		
		if (pojok[2][a][b].query(p,q)) {
			vis[i]=1;
			continue;
		}
	}
	
	return;
}

void build2() {
	for (int i=0;i<3;i++) {
		for (int j=0;j<2;j++) {
			for (int k=0;k<2;k++) {
				pojok[i][j][k].build();
			}
		}
	}
	
	return;
}

void update2() {
	for (int i=0;i<M;i++) {
		if (vis[i]) {
			continue;
		}
		
		int p, q;
		bool a, b;
		
		if (XP[i]>=Xl&&XP[i]<=Xr) {
			if (YP[i]<Yl) {
				p=Yl-YP[i];
				a=1;
			}
			else {
				p=YP[i]-Yr;
				a=0;
			}
			
			if (ZP[i]<Zl) {
				q=Zl-ZP[i];
				b=1;
			}
			else {
				q=ZP[i]-Zr;
				b=0;
			}
			
			pojok[0][a][b].add(p,q);
			vis[i]=1;
		}
		
		if (YP[i]>=Yl&&YP[i]<=Yr) {
			if (ZP[i]<Zl) {
				p=Zl-ZP[i];
				a=1;
			}
			else {
				p=ZP[i]-Zr;
				a=0;
			}
			
			if (XP[i]<Xl) {
				q=Xl-XP[i];
				b=1;
			}
			else {
				q=XP[i]-Xr;
				b=0;
			}
			
			pojok[1][a][b].add(p,q);
			vis[i]=1;
		}
		
		if (ZP[i]>=Zl&&ZP[i]<=Zr) {
			if (XP[i]<Xl) {
				p=Xl-XP[i];
				a=1;
			}
			else {
				p=XP[i]-Xr;
				a=0;
			}
			
			if (YP[i]<Yl) {
				q=Yl-YP[i];
				b=1;
			}
			else {
				q=YP[i]-Yr;
				b=0;
			}
			
			pojok[2][a][b].add(p,q);
			vis[i]=1;
		}
	}
	
	return;
}

void prune1() {
	for (int i=0;i<M;i++) {
		if (vis[i]) {
			continue;
		}
		
		if (XP[i]<=Xi||XP[i]>=Xa) {
			vis[i]=1;
		}
		
		if (YP[i]<=Yi||YP[i]>=Ya) {
			vis[i]=1;
		}
		
		if (ZP[i]<=Zi||ZP[i]>=Za) {
			vis[i]=1;
		}
	}
	
	return;
}

void update1() {
	for (int i=0;i<M;i++) {
		if (XP[i]>=Xl&&XP[i]<=Xr)
		if (YP[i]>=Yl&&YP[i]<=Yr) {
			if (ZP[i]<Zl) {
				Zi=max(Zi,ZP[i]);
			}
			else {
				Za=min(Za,ZP[i]);
			}
			
			vis[i]=1;
		}
		
		if (ZP[i]>=Zl&&ZP[i]<=Zr)
		if (XP[i]>=Xl&&XP[i]<=Xr) {
			if (YP[i]<Yl) {
				Yi=max(Yi,YP[i]);
			}
			else {
				Ya=min(Ya,YP[i]);
			}
			
			vis[i]=1;
		}
		
		if (YP[i]>=Yl&&YP[i]<=Yr)
		if (ZP[i]>=Zl&&ZP[i]<=Zr) {
			if (XP[i]<Xl) {
				Xi=max(Xi,XP[i]);
			}
			else {
				Xa=min(Xa,XP[i]);
			}
			
			vis[i]=1;
		}
	}
	
	return;
}

void proc() {
	update1();
	prune1();
	update2();
	build2();
	prune2();
	update3();
	build3();
	
	return;
}

void inputM() {
	for (int i=0;i<M;i++) {
		cin>>XP[i]>>YP[i]>>ZP[i];
		
		if (XP[i]>=Xl&&XP[i]<=Xr)
		if (YP[i]>=Yl&&YP[i]<=Yr)
		if (ZP[i]>=Zl&&ZP[i]<=Zr) {
			cout<<"INCORRECT\n";
			exit(0);
		}
	}
	
	return;
}

void inputN() {
	for (int i=0;i<N;i++) {
		cin>>XP[i]>>YP[i]>>ZP[i];
		
		if (i) {
			Xl=min(Xl,XP[i]);
			Yl=min(Yl,YP[i]);
			Zl=min(Zl,ZP[i]);
			
			Xr=max(Xr,XP[i]);
			Yr=max(Yr,YP[i]);
			Zr=max(Zr,ZP[i]);
		}
		
		else {
			Xl=XP[i];
			Yl=YP[i];
			Zl=ZP[i];
			
			Xr=XP[i];
			Yr=YP[i];
			Zr=ZP[i];
		}
	}
	
	return;
}

void init() {
	cin>>Xa>>Ya>>Za;
	cin>>N>>M>>K;
	
	Xa++;
	Ya++;
	Za++;
	
	return;
}

void debug() {
	dbg=1;
	
	data[0][1][0].debug();
	
	cout<<Xi<<' '<<Xl<<' '<<Xr<<' '<<Xa<<'\n';
	cout<<Yi<<' '<<Yl<<' '<<Yr<<' '<<Ya<<'\n';
	cout<<Zi<<' '<<Zl<<' '<<Zr<<' '<<Za<<'\n';
	
	return;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	

	
	init();
	inputN();
	inputM();
	proc();
	

	soal();
	
	return 0;
}
