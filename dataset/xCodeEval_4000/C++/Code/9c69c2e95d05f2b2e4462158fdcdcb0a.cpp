
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
uint fac[N+5],nfac[N+5],inv[N+5];
inline uint C(int n,int m){ return (n<0||m<0||n<m) ? 0 : ((LL)fac[n] * nfac[m] % P * nfac[n-m] % P); }
int vis[N]; uint xsum,isum;
int n,k,Lk,bit[N+1],a[N],type[N],Hash[N];
namespace workHash{
	int v[N],lv,i; 
	inline void work(){
		for (i = k; i < 1<<n; ++i) v[++lv] = Hash[i];
		sort(v+1,v+lv+1),lv = unique(v+1,v+lv+1)-(v+1);
		for (i = k; i < 1<<n; ++i) Hash[i] = lower_bound(v+1,v+lv+1,Hash[i])-v;
	}
}
namespace LnExp{
	uint A[17],B[17],iB[17],inv[17]; int nn;
	

	

	

	

	

	

	inline void Ln(int n = nn){ 

		register int i,j; LL ans;
		for (i = 1; i <= n; ++i){
			for (ans = 0,j = 1; j < i; ++j) ans += (LL)iB[j] * A[i-j];
			ans = ans % P * inv[i] % P,ans = (A[i]<ans)?(A[i]+P-ans):(A[i]-ans),
			B[i] = ans,iB[i] = ans * i % P;
		}
	}
	inline void Exp(int n = nn){ 

		register int i,j; LL ans;
		for (i = 1; i <= n; ++i) iB[i] = (LL)B[i] * i % P;
		for (i = 1; i <= n; ++i){
			for (ans = 0,j = 1; j <= i; ++j) ans += (LL)iB[j] * A[i-j];
			A[i] = ans % P * inv[i] % P;
		}
	}
}
inline void init(){
	int nn,j,i; read(nn),read(k),read(n),Lk = 1; while ((1<<Lk) < k) ++Lk; 
	for (i = 1; i <= nn; ++i) read(j),vis[j] = 1,xsum ^= j;
	for (isum = i = 1; i <= k; ++i) isum = (LL)isum * inv[nn] % P;
}
int L2; uint invL2;
inline void FWT(uint *A){
	register int i,j,k; uint x,y;
	for (i = 1; i < L2; i <<= 1) for (j = 0; j < L2; j += i << 1) for (k = j; k < i+j; ++k)
		x = A[k],y = A[k+i],A[k] = (x+y>=P)?(x+y-P):(x+y),A[k+i] = (x<y)?(x+P-y):(x-y); 
}
inline void IFWT(uint *A){
	register int i,j,k; uint x,y;
	for (i = 1; i < L2; i <<= 1) for (j = 0; j < L2; j += i << 1) for (k = j; k < i+j; ++k)
		x = A[k],y = A[k+i],A[k] = (x+y>=P)?(x+y-P):(x+y),A[k+i] = (x<y)?(x+P-y):(x-y); 
	for (i = 0,x = invL2; i < L2; ++i) A[i] = (LL)A[i] * x % P;
}
int L1;
uint temp[19<<16],*now = temp,*F[1<<16][1<<4],sizz,*flen[1<<16],*fmul[1<<16];
uint F0[17][1<<4],F1[17][1<<4],G0[17][1<<4],G1[17][1<<4];
int Cnt[200],z[200]; bool used[200];
uint C2[20][20],pwi[20][20],C3[20][20][20];
namespace DP{
	uint f0[17][17][1<<4],f1[17][17][1<<4],g0[17][17][1<<4],g1[17][17][1<<4];
	int cnt,nows,now,l;
	inline void extend(int l1){
		register int i,j,c,t; uint v,*Q; int len;
		swap(f0,g0),swap(f1,g1),memset(f0,0,18496),memset(f1,0,18496); 
		for (i = 0; i <= k; ++i) for (j = 0; j <= l1; ++j) for (Q = C3[l][j],c = 0; c < L2; ++c){
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
	inline void G_calc(int id){
		register int i,c,j;
		cnt = Cnt[id]; used[id] = 1;
		memset(G0,0,1088),memset(G1,0,1088);
		memset(f0,0,18496),memset(f1,0,18496),nows = now = 0;
		int v,t;
		for (i = 1; i <= k; ++i){
			l = i,v = a[z[id]-i+1]; if (v > Lk) now = (1<<Lk)-1,nows = 1; else now = (1<<v)-1,nows = 0; 
			if (i == 1){
				for (j = 0; j <= cnt && j <= k; ++j){
					if (nows && (j&1)) f1[j][j][(j&1)*now] = C(cnt,j);
					else f0[j][j][(j&1)?now:0] = C(cnt,j);
				}
			}
			else extend(min(cnt,k/(i-1)));
		}
		for (i = 0; i <= k; ++i) for (c = 0; c <= k && c <= cnt; ++c) for (j = 0; j < L2; ++j)
			upd(G0[i][j],f0[i][c][j]),upd(G1[i][j],f1[i][c][j]);
		for (i = 0; i <= k; ++i) FWT(G0[i]);
		for (i = 0; i <= k; ++i) FWT(G1[i]);
	}
}

inline void FF_add(uint *A,uint *B,uint *C,uint *D,uint *E,uint *F){
	for (register int i = 0; i < L2; ++i)
		upd(E[i],((LL)A[i] * C[i] + (LL)B[i] * D[i]) % P),
		upd(F[i],((LL)A[i] * D[i] + (LL)B[i] * C[i]) % P);
}
inline void MergeFG(){
	static uint H0[17][1<<4],H1[17][1<<4]; register int k1,k2;
	memset(H0,0,1088),memset(H1,0,1088);
	for (k1 = 0; k1 <= k; ++k1) for (k2 = 0; k2 <= k-k1; ++k2)
		FF_add(F0[k1],F1[k1],G0[k2],G1[k2],H0[k1+k2],H1[k1+k2]);
	memcpy(F0,H0,1088),memcpy(F1,H1,1088);
}
uint H0[1<<4][17],H1[1<<4][17],zlen[1<<4],zmul[1<<4];
short viss[1<<16],Time;
inline void solvetype(int tp){
	register int i,j,t; int k1,k2,now,nowt,tr = 0; uint v;
	memset(F0,0,1088),memset(F1,0,1088);
	for (i = 0; i < L2; ++i) F0[0][i] = 1;
	for (i = k; i <= 1<<n; ++i) if (type[i] == tp && vis[i] && !used[Hash[i]])
		vis[i] = 0,used[Hash[i]] = 1,DP::G_calc(Hash[i]),MergeFG();
	for (i = Lk+1; i <= n; ++i) if (tp >> i & 1){ tr = (((1<<i)-1) ^ ((1<<Lk)-1)) >> Lk; break; }
	for (i = 0; i < L2; ++i){
		for (j = 0; j <= k; ++j) LnExp::A[j] = F0[j][i];
		LnExp::Ln();
		memcpy(H0[i],LnExp::B,k+1<<2);
		if (!tr) continue;
		zlen[i] = 0,zmul[i] = 1; while (!F1[zlen[i]][i]) ++zlen[i];
		for (j = 0; j <= k-zlen[i]; ++j) LnExp::A[j] = F1[j+zlen[i]][i];
		if ((v = LnExp::A[0]) ^ 1){
			zmul[i] = v,v = power(v,P-2),LnExp::A[0] = 1;
			for (j = 1; j <= k-zlen[i]; ++j) LnExp::A[j] = (LL)LnExp::A[j] * v % P;
		}
		LnExp::Ln(k-zlen[i]);
		memcpy(H1[i],LnExp::B,k+1<<2);
	}
	for (i = 0; i < L1; ++i) if (viss[i] < Time){
		if (tr){
			viss[v = i^tr] = Time;
			memcpy(F[v][0],F[i][0],sizz),memcpy(flen[v],flen[i],L2<<2),memcpy(fmul[v],fmul[i],L2<<2);
			for (j = 0; j < L2; ++j) flen[v][j] += zlen[j];
			for (j = 0; j < L2; ++j) fmul[v][j] = (LL)fmul[v][j] * zmul[j] % P;
			for (j = 0; j < L2; ++j) for (t = 1; t <= k; ++t) upd(F[v][j][t],H1[j][t]);
		}
		for (j = 0; j < L2; ++j) for (t = 1; t <= k; ++t) upd(F[i][j][t],H0[j][t]);
	}
}
uint ans[1<<16];
int main(){
	register int i,j,t; uint v;
	fac[0] = nfac[0] = inv[0] = fac[1] = nfac[1] = inv[1] = 1;
	for (i = 2; i < N+5; ++i)
		fac[i] = (LL)fac[i-1] * i % P,inv[i] = (LL)(P-P/i) * inv[P%i] % P,nfac[i] = (LL)nfac[i-1] * inv[i] % P;
	init();
	LnExp::nn = k,LnExp::A[0] = 1;
	for (i = 0; i <= 16; ++i) LnExp::inv[i] = inv[i];
	for (i = 0; i < 20; ++i) for (j = 0; j <= i; ++j) C2[i][j] = (!i||!j) ? 1 : (C2[i-1][j-1] + C2[i-1][j]);
	for (i = 0; i < 20; ++i) for (pwi[i][0] = 1,pwi[i][1] = inv[i],j = 2; j < 20; ++j)
		pwi[i][j] = (LL)pwi[i][j-1] * inv[i] % P;
	for (i = 0; i < 20; ++i) for (j = 0; j < 20; ++j) for (t = 0; t < 20; ++t) C3[i][j][t] = (LL)pwi[i][t] * C2[j][t] % P;
	for (i = 0; i <= n; ++i) bit[1<<i] = i;
	for (i = 1; i < 1<<n; ++i) a[i] = bit[1+(i^(i-1))];
	for (i = k; i < 1<<n; ++i) for (type[i] = (1<<Lk+1)-1,j = 0; j < k; ++j)
		type[i] |= 1<<a[i-j],Hash[i] += a[i-j] * (j+1) * (j+1) * (j+1) * (j+1) * (j+1) * (j+1);
	workHash::work();
	for (i = k; i < 1<<n; ++i) if (vis[i]){ if (++Cnt[Hash[i]] == 1) z[Hash[i]] = i; }
	L1 = (1<<n) >> Lk,L2 = 1<<Lk,invL2 = power(L2,P-2),sizz = (k+1) * L2 * 4;
	for (i = 0; i < L1; ++i){
		flen[i] = now,now += L2,fmul[i] = now,now += L2,viss[i] = 100;
		for (j = 0; j < L2; ++j) fmul[i][j] = 1,F[i][j] = now,now += k+1;	
	}
	viss[0] = Time = 1;
	for (i = k; i < 1<<n; ++i) if (type[i] && vis[i] && !used[Hash[i]]) ++Time,solvetype(type[i]);
	for (i = 0; i < L1; ++i) for (j = 0; j < L2; ++j)
		memcpy(LnExp::B,F[i][j],k+1<<2),LnExp::Exp(k-flen[i][j]),memcpy(F[i][j],LnExp::A,k+1<<2);
	uint tmp[16];
	for (i = 0; i < L1; ++i){
		for (j = 0; j < L2; ++j) tmp[j] = flen[i][j] <= k ? (LL)fmul[i][j] * F[i][j][k-flen[i][j]] % P : 0;
		for (IFWT(tmp),j = 0; j < L2; ++j) ans[j|(i<<Lk)] = tmp[j];
	}
	isum = (LL)isum * fac[k] % P;
	for (i = 0; i < 1<<n; ++i) write((LL)isum * ans[i^xsum] % P),putchar((i<(1<<n)-1) ? ' ' : '\n');
	return 0;
}