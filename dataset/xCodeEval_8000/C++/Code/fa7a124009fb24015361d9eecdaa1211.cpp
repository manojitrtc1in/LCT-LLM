
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define LL unsigned long long
#define uint unsigned
using namespace std;
template <typename T> void read(T &x){
	static char ch; x = 0,ch = getchar();
	while (!isdigit(ch)) ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0',ch = getchar();
}
inline void write(int x){if (x > 9) write(x/10); putchar(x%10+'0'); }
const int N = 1<<16,P = 998244353;
inline uint power(uint x,int y){
	static uint r; r = 1; while (y){ if (y&1) r = (LL)r * x % P; x = (LL)x * x % P,y >>= 1; } return r;
}
inline void upd(uint &x,uint y){ x = (x+y>=P)?(x+y-P):(x+y); }
int n,k,type[N],bit[N+1],a[N],Hash[N]; uint fac[N+5],nfac[N+5]; uint xsum,isum;
inline uint C(int n,int m){ return (n<0||m<0||n<m) ? 0 : ((LL)fac[n] * nfac[m] % P * nfac[n-m] % P); }
namespace workHash{
	int v[N],lv,i;
	inline void work(){
		for (i = k; i < 1<<n; ++i) if (type[i]) v[++lv] = Hash[i];
		sort(v+1,v+lv+1),lv = unique(v+1,v+lv+1)-(v+1);
		for (i = k; i < 1<<n; ++i) Hash[i] = lower_bound(v+1,v+lv+1,Hash[i])-v;
	}
}
namespace LnExp{
	int nn; uint inv[17],A[17],B[17],iB[17]; LL ans;
	inline void Ln(){
		register int i,j;
		for (i = 1; i <= nn; ++i){
			for (ans = 0,j = 1; j < i; ++j) ans += (LL)iB[j] * A[i-j];
			ans = ans % P * inv[i] % P,ans = (A[i]<ans)?(A[i]+P-ans):(A[i]-ans),
			B[i] = ans,iB[i] = ans * i % P;
		}
	}
	inline void Exp(){
		register int i,j;
		for (i = 1; i <= nn; ++i){
			B[i] = (LL)B[i] * i % P;
			for (ans = 0,j = 1; j <= i; ++j) ans += (LL)B[j] * A[i-j];
			A[i] = ans % P * inv[i] % P;
		}
	}
	inline void Ln(int n){
		register int i,j;
		for (i = 1; i <= n; ++i){
			for (ans = 0,j = 1; j < i; ++j) ans += (LL)iB[j] * A[i-j];
			ans = ans % P * inv[i] % P,ans = (A[i]<ans)?(A[i]+P-ans):(A[i]-ans),
			B[i] = ans,iB[i] = ans * i % P;
		}
	}
	inline void Exp(int n){
		register int i,j;
		for (i = 1; i <= n; ++i){
			B[i] = (LL)B[i] * i % P;
			for (ans = 0,j = 1; j <= i; ++j) ans += (LL)B[j] * A[i-j];
			A[i] = ans % P * inv[i] % P;
		}
	}
}
using LnExp::inv;
using LnExp::A;
using LnExp::B;
using LnExp::Ln;
using LnExp::Exp;
inline void init(){
	int nn,i,j; read(nn),read(k),read(n); 

	for (i = 1; i <= nn; ++i) read(j),type[j] = 1,xsum ^= j;
	for (isum = i = 1; i <= k; ++i) isum = (LL)isum * nn % P;
	isum = power(isum,P-2);
}
inline void FWT(uint *A){
	uint x;
	x = A[0],A[0] = (x+A[1]>=P)?(x+A[1]-P):(x+A[1]),A[1] = (x<A[1])?(x+P-A[1]):(x-A[1]),x = A[2],A[2] = (x+A[3]>=P)?(x+A[3]-P):(x+A[3]),A[3] = (x<A[3])?(x+P-A[3]):(x-A[3]),x = A[4],A[4] = (x+A[5]>=P)?(x+A[5]-P):(x+A[5]),A[5] = (x<A[5])?(x+P-A[5]):(x-A[5]),x = A[6],A[6] = (x+A[7]>=P)?(x+A[7]-P):(x+A[7]),A[7] = (x<A[7])?(x+P-A[7]):(x-A[7]),x = A[8],A[8] = (x+A[9]>=P)?(x+A[9]-P):(x+A[9]),A[9] = (x<A[9])?(x+P-A[9]):(x-A[9]),x = A[10],A[10] = (x+A[11]>=P)?(x+A[11]-P):(x+A[11]),A[11] = (x<A[11])?(x+P-A[11]):(x-A[11]),x = A[12],A[12] = (x+A[13]>=P)?(x+A[13]-P):(x+A[13]),A[13] = (x<A[13])?(x+P-A[13]):(x-A[13]),x = A[14],A[14] = (x+A[15]>=P)?(x+A[15]-P):(x+A[15]),A[15] = (x<A[15])?(x+P-A[15]):(x-A[15]),x = A[0],A[0] = (x+A[2]>=P)?(x+A[2]-P):(x+A[2]),A[2] = (x<A[2])?(x+P-A[2]):(x-A[2]),x = A[1],A[1] = (x+A[3]>=P)?(x+A[3]-P):(x+A[3]),A[3] = (x<A[3])?(x+P-A[3]):(x-A[3]),x = A[4],A[4] = (x+A[6]>=P)?(x+A[6]-P):(x+A[6]),A[6] = (x<A[6])?(x+P-A[6]):(x-A[6]),x = A[5],A[5] = (x+A[7]>=P)?(x+A[7]-P):(x+A[7]),A[7] = (x<A[7])?(x+P-A[7]):(x-A[7]),x = A[8],A[8] = (x+A[10]>=P)?(x+A[10]-P):(x+A[10]),A[10] = (x<A[10])?(x+P-A[10]):(x-A[10]),x = A[9],A[9] = (x+A[11]>=P)?(x+A[11]-P):(x+A[11]),A[11] = (x<A[11])?(x+P-A[11]):(x-A[11]),x = A[12],A[12] = (x+A[14]>=P)?(x+A[14]-P):(x+A[14]),A[14] = (x<A[14])?(x+P-A[14]):(x-A[14]),x = A[13],A[13] = (x+A[15]>=P)?(x+A[15]-P):(x+A[15]),A[15] = (x<A[15])?(x+P-A[15]):(x-A[15]),x = A[0],A[0] = (x+A[4]>=P)?(x+A[4]-P):(x+A[4]),A[4] = (x<A[4])?(x+P-A[4]):(x-A[4]),x = A[1],A[1] = (x+A[5]>=P)?(x+A[5]-P):(x+A[5]),A[5] = (x<A[5])?(x+P-A[5]):(x-A[5]),x = A[2],A[2] = (x+A[6]>=P)?(x+A[6]-P):(x+A[6]),A[6] = (x<A[6])?(x+P-A[6]):(x-A[6]),x = A[3],A[3] = (x+A[7]>=P)?(x+A[7]-P):(x+A[7]),A[7] = (x<A[7])?(x+P-A[7]):(x-A[7]),x = A[8],A[8] = (x+A[12]>=P)?(x+A[12]-P):(x+A[12]),A[12] = (x<A[12])?(x+P-A[12]):(x-A[12]),x = A[9],A[9] = (x+A[13]>=P)?(x+A[13]-P):(x+A[13]),A[13] = (x<A[13])?(x+P-A[13]):(x-A[13]),x = A[10],A[10] = (x+A[14]>=P)?(x+A[14]-P):(x+A[14]),A[14] = (x<A[14])?(x+P-A[14]):(x-A[14]),x = A[11],A[11] = (x+A[15]>=P)?(x+A[15]-P):(x+A[15]),A[15] = (x<A[15])?(x+P-A[15]):(x-A[15]),x = A[0],A[0] = (x+A[8]>=P)?(x+A[8]-P):(x+A[8]),A[8] = (x<A[8])?(x+P-A[8]):(x-A[8]),x = A[1],A[1] = (x+A[9]>=P)?(x+A[9]-P):(x+A[9]),A[9] = (x<A[9])?(x+P-A[9]):(x-A[9]),x = A[2],A[2] = (x+A[10]>=P)?(x+A[10]-P):(x+A[10]),A[10] = (x<A[10])?(x+P-A[10]):(x-A[10]),x = A[3],A[3] = (x+A[11]>=P)?(x+A[11]-P):(x+A[11]),A[11] = (x<A[11])?(x+P-A[11]):(x-A[11]),x = A[4],A[4] = (x+A[12]>=P)?(x+A[12]-P):(x+A[12]),A[12] = (x<A[12])?(x+P-A[12]):(x-A[12]),x = A[5],A[5] = (x+A[13]>=P)?(x+A[13]-P):(x+A[13]),A[13] = (x<A[13])?(x+P-A[13]):(x-A[13]),x = A[6],A[6] = (x+A[14]>=P)?(x+A[14]-P):(x+A[14]),A[14] = (x<A[14])?(x+P-A[14]):(x-A[14]),x = A[7],A[7] = (x+A[15]>=P)?(x+A[15]-P):(x+A[15]),A[15] = (x<A[15])?(x+P-A[15]):(x-A[15]);
}
const LL iL = 935854081ull;
inline void IFWT(uint *A){
	uint x;
	x = A[0],A[0] = (x+A[1]>=P)?(x+A[1]-P):(x+A[1]),A[1] = (x<A[1])?(x+P-A[1]):(x-A[1]),x = A[2],A[2] = (x+A[3]>=P)?(x+A[3]-P):(x+A[3]),A[3] = (x<A[3])?(x+P-A[3]):(x-A[3]),x = A[4],A[4] = (x+A[5]>=P)?(x+A[5]-P):(x+A[5]),A[5] = (x<A[5])?(x+P-A[5]):(x-A[5]),x = A[6],A[6] = (x+A[7]>=P)?(x+A[7]-P):(x+A[7]),A[7] = (x<A[7])?(x+P-A[7]):(x-A[7]),x = A[8],A[8] = (x+A[9]>=P)?(x+A[9]-P):(x+A[9]),A[9] = (x<A[9])?(x+P-A[9]):(x-A[9]),x = A[10],A[10] = (x+A[11]>=P)?(x+A[11]-P):(x+A[11]),A[11] = (x<A[11])?(x+P-A[11]):(x-A[11]),x = A[12],A[12] = (x+A[13]>=P)?(x+A[13]-P):(x+A[13]),A[13] = (x<A[13])?(x+P-A[13]):(x-A[13]),x = A[14],A[14] = (x+A[15]>=P)?(x+A[15]-P):(x+A[15]),A[15] = (x<A[15])?(x+P-A[15]):(x-A[15]),x = A[0],A[0] = (x+A[2]>=P)?(x+A[2]-P):(x+A[2]),A[2] = (x<A[2])?(x+P-A[2]):(x-A[2]),x = A[1],A[1] = (x+A[3]>=P)?(x+A[3]-P):(x+A[3]),A[3] = (x<A[3])?(x+P-A[3]):(x-A[3]),x = A[4],A[4] = (x+A[6]>=P)?(x+A[6]-P):(x+A[6]),A[6] = (x<A[6])?(x+P-A[6]):(x-A[6]),x = A[5],A[5] = (x+A[7]>=P)?(x+A[7]-P):(x+A[7]),A[7] = (x<A[7])?(x+P-A[7]):(x-A[7]),x = A[8],A[8] = (x+A[10]>=P)?(x+A[10]-P):(x+A[10]),A[10] = (x<A[10])?(x+P-A[10]):(x-A[10]),x = A[9],A[9] = (x+A[11]>=P)?(x+A[11]-P):(x+A[11]),A[11] = (x<A[11])?(x+P-A[11]):(x-A[11]),x = A[12],A[12] = (x+A[14]>=P)?(x+A[14]-P):(x+A[14]),A[14] = (x<A[14])?(x+P-A[14]):(x-A[14]),x = A[13],A[13] = (x+A[15]>=P)?(x+A[15]-P):(x+A[15]),A[15] = (x<A[15])?(x+P-A[15]):(x-A[15]),x = A[0],A[0] = (x+A[4]>=P)?(x+A[4]-P):(x+A[4]),A[4] = (x<A[4])?(x+P-A[4]):(x-A[4]),x = A[1],A[1] = (x+A[5]>=P)?(x+A[5]-P):(x+A[5]),A[5] = (x<A[5])?(x+P-A[5]):(x-A[5]),x = A[2],A[2] = (x+A[6]>=P)?(x+A[6]-P):(x+A[6]),A[6] = (x<A[6])?(x+P-A[6]):(x-A[6]),x = A[3],A[3] = (x+A[7]>=P)?(x+A[7]-P):(x+A[7]),A[7] = (x<A[7])?(x+P-A[7]):(x-A[7]),x = A[8],A[8] = (x+A[12]>=P)?(x+A[12]-P):(x+A[12]),A[12] = (x<A[12])?(x+P-A[12]):(x-A[12]),x = A[9],A[9] = (x+A[13]>=P)?(x+A[13]-P):(x+A[13]),A[13] = (x<A[13])?(x+P-A[13]):(x-A[13]),x = A[10],A[10] = (x+A[14]>=P)?(x+A[14]-P):(x+A[14]),A[14] = (x<A[14])?(x+P-A[14]):(x-A[14]),x = A[11],A[11] = (x+A[15]>=P)?(x+A[15]-P):(x+A[15]),A[15] = (x<A[15])?(x+P-A[15]):(x-A[15]),x = A[0],A[0] = (x+A[8]>=P)?(x+A[8]-P):(x+A[8]),A[8] = (x<A[8])?(x+P-A[8]):(x-A[8]),x = A[1],A[1] = (x+A[9]>=P)?(x+A[9]-P):(x+A[9]),A[9] = (x<A[9])?(x+P-A[9]):(x-A[9]),x = A[2],A[2] = (x+A[10]>=P)?(x+A[10]-P):(x+A[10]),A[10] = (x<A[10])?(x+P-A[10]):(x-A[10]),x = A[3],A[3] = (x+A[11]>=P)?(x+A[11]-P):(x+A[11]),A[11] = (x<A[11])?(x+P-A[11]):(x-A[11]),x = A[4],A[4] = (x+A[12]>=P)?(x+A[12]-P):(x+A[12]),A[12] = (x<A[12])?(x+P-A[12]):(x-A[12]),x = A[5],A[5] = (x+A[13]>=P)?(x+A[13]-P):(x+A[13]),A[13] = (x<A[13])?(x+P-A[13]):(x-A[13]),x = A[6],A[6] = (x+A[14]>=P)?(x+A[14]-P):(x+A[14]),A[14] = (x<A[14])?(x+P-A[14]):(x-A[14]),x = A[7],A[7] = (x+A[15]>=P)?(x+A[15]-P):(x+A[15]),A[15] = (x<A[15])?(x+P-A[15]):(x-A[15]);	A[0] = (LL)A[0] * iL % P,A[1] = (LL)A[1] * iL % P,A[2] = (LL)A[2] * iL % P,A[3] = (LL)A[3] * iL % P,A[4] = (LL)A[4] * iL % P,A[5] = (LL)A[5] * iL % P,A[6] = (LL)A[6] * iL % P,
	A[7] = (LL)A[7] * iL % P,A[8] = (LL)A[8] * iL % P,A[9] = (LL)A[9] * iL % P,A[10] = (LL)A[10] * iL % P,A[11] = (LL)A[11] * iL % P,
	A[12] = (LL)A[12] * iL % P,A[13] = (LL)A[13] * iL % P,A[14] = (LL)A[14] * iL % P,A[15] = (LL)A[15] * iL % P;
}
int L1;
uint temp[19<<16],*now = temp,*F[1<<12][1<<4],sizz,*flen[1<<12],*fmul[1<<12];
uint F0[17][1<<4],F1[17][1<<4],G0[17][1<<4],G1[17][1<<4];
int Cnt[200],z[200]; bool used[200];
uint C2[17][17],pwi[17][17],C3[17][17][17];
namespace DP{
	uint f0[17][17][1<<4],f1[17][17][1<<4],g0[17][17][1<<4],g1[17][17][1<<4];
	int nows,now,l;
	inline void extend(int l1){
		register int i,j,c,t,len; uint v,*Q;
		swap(f0,g0),swap(f1,g1),memset(f0,0,18496),memset(f1,0,18496); 
		for (i = 0; i <= k; ++i) for (j = 0; j <= l1; ++j) for (Q = C3[l][j],c = 0; c < 16; ++c){
			len = min(j,k-i);
			if (v = g0[i][j][c]){
				for (t = 0; t <= len; t += 2) upd(f0[i+t][t][c],(LL)v * Q[t] % P);
				if (nows) for (t = 1; t <= len; t += 2) upd(f1[i+t][t][c^now],(LL)v * Q[t] % P);
				else for (t = 1; t <= len; t += 2) upd(f0[i+t][t][c^now],(LL)v * Q[t] % P);
			}
			if (v = g1[i][j][c]){
				for (t = 0; t <= len; t += 2) upd(f1[i+t][t][c],(LL)v * Q[t] % P);
				if (nows) for (t = 1; t <= len; t += 2) upd(f0[i+t][t][c^now],(LL)v * Q[t] % P);
				else for (t = 1; t <= len; t += 2) upd(f1[i+t][t][c^now],(LL)v * Q[t] % P);
			}
		}
	}
	int cnt;
	inline void G_calc(int id){
		register int i,c,j; int v,t;
		cnt = Cnt[id],memset(f0,0,18496),memset(f1,0,18496),nows = now = 0;
		for (i = 1; i <= k; ++i){
			l = i; if ((v = a[z[id]-i+1]) > 4) now = 15,nows = 1; else now = (1<<v)-1,nows = 0; 
			if (i == 1){
				for (j = 0; j <= cnt && j <= k; ++j)
					if (nows && (j&1)) f1[j][j][(j&1)?now:0] = C(cnt,j);
					else f0[j][j][(j&1)?now:0] = C(cnt,j);
			}
			else extend(min(cnt,k/(i-1)));
		}
		memset(G0,0,1088),memset(G1,0,1088),cnt = min(cnt,k);
		for (i = 0; i <= k; ++i){
			for (j = 0; j < 16; ++j) for (c = 0; c <= cnt; ++c) upd(G0[i][j],f0[i][c][j]),upd(G1[i][j],f1[i][c][j]);
			FWT(G0[i]),FWT(G1[i]);
		}
	}
}
inline void FF_add(uint *A,uint *B,uint *C,uint *D,uint *E,uint *F){
	for (register int i = 0; i < 16; ++i)
		upd(E[i],((LL)A[i] * C[i] + (LL)B[i] * D[i]) % P),
		upd(F[i],((LL)A[i] * D[i] + (LL)B[i] * C[i]) % P);
}
inline void MergeFG(){
	static uint H0[17][1<<4],H1[17][1<<4]; register int k1,k2;
	memset(H0,0,1088),memset(H1,0,1088);
	for (k1 = 0; k1 <= k; ++k1) for (k2 = 0; k2 <= k-k1; ++k2) FF_add(F0[k1],F1[k1],G0[k2],G1[k2],H0[k1+k2],H1[k1+k2]);
	memcpy(F0,H0,1088),memcpy(F1,H1,1088);
}
uint H0[1<<4][17],H1[1<<4][17],zlen[1<<4],zmul[1<<4];
short viss[1<<16],Time;
inline void solvetype(int tp){
	register int i,j,t; int tr = 0; uint v;
	memset(F0,0,1088),memset(F1,0,1088);
	for (i = 0; i < 16; ++i) F0[0][i] = 1;
	for (i = k; i <= 1<<n; ++i) if (type[i] == tp && !used[Hash[i]])
		used[Hash[i]] = 1,DP::G_calc(Hash[i]),MergeFG();
	for (i = 5; i <= n; ++i) if (tp >> i & 1){ tr = (((1<<i)-1) ^ 15) >> 4; break; }
	for (i = 0; i < 16; ++i){
		for (j = 0; j <= k; ++j) A[j] = F0[j][i];
		Ln(),memcpy(H0[i],B,k+1<<2);
		if (tr){
			zlen[i] = 0,zmul[i] = 1; while (!F1[zlen[i]][i]) ++zlen[i];
			for (j = 1; j <= k-zlen[i]; ++j) A[j] = F1[j+zlen[i]][i];
			if ((v = F1[zlen[i]][i]) ^ 1)
				for (zmul[i] = v,v = power(v,P-2),j = 1; j <= k-zlen[i]; ++j) A[j] = (LL)A[j] * v % P;
			Ln(k-zlen[i]),memcpy(H1[i],B,k+1<<2);
		}
	}
	if (tr){
		for (i = 0; i < L1; ++i) if (viss[i] < Time){
			viss[v = i^tr] = Time,memcpy(flen[v],flen[i],sizz);
			for (j = 0; j < 16; ++j) flen[v][j] += zlen[j];
			for (j = 0; j < 16; ++j) fmul[v][j] = (LL)fmul[v][j] * zmul[j] % P;
			for (j = 0; j < 16; ++j) for (t = 1; t <= k; ++t) upd(F[v][j][t],H1[j][t]);
			for (j = 0; j < 16; ++j) for (t = 1; t <= k; ++t) upd(F[i][j][t],H0[j][t]);
		}
	}
	else{
		for (i = 0; i < L1; ++i) if (viss[i] < Time)
		for (j = 0; j < 16; ++j) for (t = 1; t <= k; ++t) upd(F[i][j][t],H0[j][t]);
	}
	
}
uint ans[1<<16],pw6[17];
int main(){


	register int i,j,t; uint v;
	fac[0] = nfac[0] = fac[1] = nfac[1] = 1; for (i = 2; i < N+5; ++i) fac[i] = (LL)fac[i-1] * i % P;
	nfac[N+4] = power(fac[N+4],P-2); for (i = N+3; i >= 0; --i) nfac[i] = (LL)nfac[i+1] * (i+1) % P;
	init();
	LnExp::nn = k,A[0] = 1; for (inv[0] = inv[1] = 1,i = 2; i <= 16; ++i) inv[i] = (LL)(P-P/i) * inv[P%i] % P;
	for (i = 0; i <= 16; ++i) for (j = 0; j <= i; ++j) C2[i][j] = (!i||!j) ? 1 : (C2[i-1][j-1] + C2[i-1][j]);
	for (i = 0; i <= 16; ++i) for (pwi[i][0] = 1,pwi[i][1] = inv[i],j = 2; j <= 16; ++j)
		pwi[i][j] = (LL)pwi[i][j-1] * inv[i] % P;
	for (i = 0; i <= 16; ++i) for (j = 0; j <= 16; ++j) for (t = 0; t <= 16; ++t) C3[i][j][t] = (LL)pwi[i][t] * C2[j][t] % P;
	for (i = 0; i <= n; ++i) bit[1<<i] = i;
	for (i = 0; i <= 16; ++i) pw6[i] = i * i * i * i * i * i;
	for (i = 1; i < k; ++i) a[i] = bit[1+(i^(i-1))];
	for (i = k; i < 1<<n; ++i){
		a[i] = bit[1+(i^(i-1))];
		if (type[i])
			for (type[i] = 31,j = 0; j < k; ++j)
				type[i] |= 1<<a[i-j],Hash[i] += a[i-j] * pw6[j+1];
	}
	workHash::work();
	for (i = k; i < 1<<n; ++i) if (type[i] && ++Cnt[Hash[i]] == 1) z[Hash[i]] = i;
	L1 = max(1,(1<<n)>>4),sizz = (k+1) * 16 * 4 + (16 * 8);
	for (i = 0; i < L1; ++i){
		flen[i] = now,now += 16,fmul[i] = now,now += 16,viss[i] = 100;
		for (j = 0; j < 16; ++j) F[i][j] = now,now += k+1;	
	}
	for (i = 0; i < 16; ++i) fmul[0][i] = 1;
	viss[0] = Time = 1;
	for (i = k; i < 1<<n; ++i) if (type[i] && !used[Hash[i]]) ++Time,solvetype(type[i]);
	for (i = 0; i < L1; ++i) for (j = 0; j < 16; ++j)
		memcpy(B,F[i][j],k+1<<2),Exp(k-flen[i][j]),memcpy(F[i][j],A,k+1<<2);
	uint tmp[16];
	for (i = 0; i < L1; ++i){
		for (j = 0; j < 16; ++j) tmp[j] = flen[i][j] <= k ? (LL)fmul[i][j] * F[i][j][k-flen[i][j]] % P : 0;
		for (IFWT(tmp),j = 0; j < 16; ++j) ans[j|(i<<4)] = tmp[j];
	}
	isum = (LL)isum * fac[k] % P;
	for (i = 0; i < 1<<n; ++i) write((LL)isum * ans[i^xsum] % P),putchar((i<(1<<n)-1) ? ' ' : '\n');
	return 0;
}