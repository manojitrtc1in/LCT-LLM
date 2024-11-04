
















using namespace std;  










typedef long long ll;  
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MOD=998244353;
const int INV2 = (MOD + 1) / 2;
const int MAXN=1000000;

int n;

int inv[MAXN+1];
int fac[MAXN+1];
int ifac[MAXN+1];

int solve() {
	inv[1]=1; FORE(i,2,n) inv[i]=(ll)(MOD-MOD/i)*inv[MOD%i]%MOD;
	fac[0]=1; FORE(i,1,n) fac[i]=(ll)fac[i-1]*i%MOD;
	ifac[0]=1; FORE(i,1,n) ifac[i]=(ll)ifac[i-1]*inv[i]%MOD;
	
	int ret=0;
	FORE(k,1,n) {
		int mlt = (ll)fac[n] * ifac[n - k] % MOD;
		ret = (ret + mlt) % MOD;
	}
	FORE(k, 1, n) {
		int cur = (fac[n] + MOD - (ll)fac[n] * ifac[n - k] % MOD) % MOD;
		ret = (ret + cur) % MOD;
	}
	FORE(k, 3, n) {
		

		int mlt = (ll)fac[n] * ifac[k] % MOD;
		int ways = (ll)(n + k - 1) * (n + k) % MOD * INV2 % MOD; 

		ret = (ret + (ll)mlt * ways) % MOD;
	}
	FORE(k, 4, n) {
		

		int mlt = (ll)(k - 3) * fac[n] % MOD * ifac[k] % MOD;
		int ways = (ll)(n + k - 2) * (n + k - 1) % MOD * INV2 % MOD; 

		ret = (ret + (ll)mlt * ways) % MOD;
	}
	FORE(k, 4, n) {
		

		int mlt = (ll)(k - 4) * fac[n] % MOD * ifac[k] % MOD;
		int ways = k - 1; 

		ret = (ret + (ll)mlt * ways) % MOD;
	}
	FORE(k, 3, n) {
		

		int mlt = (ll)fac[n] * ifac[k] % MOD;
		int ways = (ll)(n + k - 2) * (n + k - 1) % MOD * INV2 % MOD; 

		if (k == 3) ways = (ways + MOD - (ll)(k - 2) * (k - 1) % MOD * INV2 % MOD) % MOD;  

		ret = (ret + (ll)mlt * ways) % MOD;
	}
	FORE(k, 4, n) {
		

		int mlt = (ll)fac[n] * ifac[k] % MOD;
		int ways = k - 1;
		ret = (ret + (ll)mlt * ways) % MOD;
	}
	FORE(ndesc, 2, n) {
		if (ndesc < n) {
			

			int mlt = (ll)fac[n] * ifac[ndesc + 1] % MOD;
			int ylim = ndesc == 2 ? n + 1 : n - (ndesc - 2);
			int ways = ((ll)(n + 1 + n - (ylim - 1) + 1) * ylim % MOD * INV2 + MOD - 1) % MOD; 

			

			ret = (ret + (ll)mlt * ways) % MOD;
		}
		if (ndesc < n) {
			

			int mlt = (ll)(ndesc - 1) * fac[n] % MOD * ifac[ndesc + 1] % MOD;
			int ylim = n - (ndesc - 1);
			int ways = ((ll)(n + 1 + n - (ylim - 1) + 1) * ylim % MOD * INV2 + MOD - 1) % MOD; 

			

			ret = (ret + (ll)mlt * ways) % MOD;
		}
		if (ndesc == n) {
			

			int mlt = 1;
			int ylim = 2;
			int ways = ((ll)(n + 1 + n - (ylim - 1) + 1) * ylim % MOD * INV2 + MOD - 1) % MOD; 

			

			ret = (ret + (ll)mlt * ways) % MOD;
		}
	}
	{
		int len = (ll)n * fac[n] % MOD;
		int cnt = (len + MOD - 2 * n) % MOD;
		int cur = (ll)cnt * (cnt + 1) % MOD * INV2 % MOD;
		ret = (ret + cur) % MOD;
	}
	return ret;
}

void run() {
	scanf("%d",&n);
	printf("%d\n",solve());
}



bool getprev(const vector<int> &p,vector<int> &res) {
	int n=SZ(p);
	for(int i=n-2;i>=0;--i) if(p[i]>p[i+1]) {
		int j=i+1; while(j+1<n&&p[i]>p[j+1]) ++j;
		res=p; swap(res[i],res[j]); reverse(res.begin()+i+1,res.end()); return true;
	}
	return false;
}
bool getnext(const vector<int> &p,vector<int> &res) {
	int n=SZ(p);
	for(int i=n-2;i>=0;--i) if(p[i]<p[i+1]) {
		int j=i+1; while(j+1<n&&p[i]<p[j+1]) ++j;
		res=p; swap(res[i],res[j]); reverse(res.begin()+i+1,res.end()); return true;
	}
	return false;
}

void gen(const vector<int> &pcur,int lpref,int hpref,int nmid,int lsuff,int hsuff,vector<string> &have,char id) {
	int n=SZ(pcur);
	vector<int> pbef; assert(getprev(pcur,pbef));
	vector<int> id2; bool id0=getprev(pbef,id2);
	vector<int> pnxt; bool havenxt=getnext(pcur,pnxt);
	

	for(int pref=lpref;pref+nmid<=2*n&&pref<=hpref;++pref) for(int suff=lsuff;pref+nmid+suff<=2*n&&suff<=hsuff;++suff) {
		

		string t(pref+nmid+suff,'?');
		id1(i,t) {
			int idx=i-pref;
			if(idx>=0&&idx<n) t[i]='0'+pcur[idx];
			else if(idx+n>=0&&idx+n<n) t[i]='0'+pbef[idx+n];
			else if(idx+2*n>=0&&idx+2*n<n) t[i]='0'+(id0?id2[idx+2*n]:0);
			else if(idx-n>=0&&idx-n<n) t[i]='0'+(havenxt?pnxt[idx-n]:0);
			else assert(false);
		}
		bool ok=true; id1(i,t) if(t[i]=='0') ok=false; if(!ok) continue;
		have.PB(t);
		

	}
}
void gen(const vector<int> &pcur,int lpref,int nmid,int lsuff,vector<string> &have,char id) { gen(pcur,lpref,2*SZ(pcur),nmid,lsuff,2*SZ(pcur),have,id); }


















void research() {
	int n=3;
	string s;
	vector<int> p(n); REP(i,n) p[i]=i+1;
	do {
		id1(i,p) s+=string(1,'0'+p[i]);
	} while(next_permutation(p.begin(),p.end()));
	printf("SZ(s)=%d\n",SZ(s));
	if(SZ(s)<=1000) printf("s:%s\n",s.c_str());
	vector<string> want;
	id1(i, s) {
		vector<bool> seen(n, false); bool ok = false;
		id3(j, i, s) {
			int len = j - i + 1;
			if (len > 2 * n) break;
			int x = s[j] - '1'; if (seen[x]) ok = true; else seen[x] = true;
			if (ok && len <= 2 * n) want.PB(s.substr(i, j - i + 1));
			

			

		}
	}
	sort(want.begin(),want.end());
	want.erase(unique(want.begin(),want.end()),want.end());
	printf("SZ(want)=%d\n",SZ(want));
	

	
	vector<int> fac(n+1); fac[0]=1; FORE(i,1,n) fac[i]=fac[i-1]*i;
	int guess=0;
	FORE(k,1,n) {
		int cur=fac[n]-fac[n]/fac[n-k];
		guess+=cur;
	}
	FORE(k,3,n) {
		

		int mlt=fac[n]/fac[k];
		int ways=(n+k-1)*(n+k)/2; 

		guess+=mlt*ways;
	}
	FORE(k,4,n) {
		

		int mlt=(k-3)*fac[n]/fac[k];
		int ways=(n+k-2)*(n+k-1)/2; 

		guess+=mlt*ways;
	}
	FORE(k,4,n) {
		

		int mlt=(k-4)*fac[n]/fac[k];
		int ways=k-1; 

		guess+=mlt*ways;
	}
	FORE(k,3,n) {
		

		int mlt=fac[n]/fac[k];
		int ways=(n+k-2)*(n+k-1)/2; 

		if(k==3) ways-=(k-2)*(k-1)/2;  

		guess+=mlt*ways;
	}
	FORE(k,4,n) {
		

		int mlt=fac[n]/fac[k];
		int ways=k-1;
		guess+=mlt*ways;
	}
	FORE(ndesc,2,n) {
		if(ndesc<n) {
			

			int mlt=fac[n]/fac[ndesc+1];
			int ylim=ndesc==2?n+1:n-(ndesc-2);
			int ways=(n+1+n-(ylim-1)+1)*ylim/2-1; 

			

			guess+=mlt*ways;
		}
		if(ndesc<n) {
			

			int mlt=(ndesc-1)*fac[n]/fac[ndesc+1];
			int ylim=n-(ndesc-1);
			int ways=(n+1+n-(ylim-1)+1)*ylim/2-1; 

			

			guess+=mlt*ways;
		}
		if(ndesc==n) {
			

			int mlt=1;
			int ylim=2;
			int ways=(n+1+n-(ylim-1)+1)*ylim/2-1; 

			

			guess+=mlt*ways;
		}
	}
	
	vector<string> have;
	REP(midmask,1<<n) {
		vector<int> mid,oth; REP(i,n) if(midmask&(1<<i)) mid.PB(i+1); else oth.PB(i+1);
		int k=SZ(oth);
		if(k==2) do {
			vector<int> pcur(n); id1(i,mid) pcur[i]=mid[i]; pcur[SZ(mid)]=oth[1]; pcur[SZ(mid)+1]=oth[0];
			int ridx=n-2; while(ridx>=0&&pcur[ridx]>pcur[ridx+1]) --ridx;
			int hpref=n,hsuff=ridx<0?2:pcur[ridx]<pcur[ridx+2]?2+ridx:ridx<n-3?2+ridx+1:n+1;
			

			gen(pcur,1,hpref,SZ(mid),1,hsuff,have,'A');
		} while(next_permutation(mid.begin(),mid.end()));
		if(k>=3) do {
			vector<int> pcur(n); id1(i,mid) pcur[i]=mid[i]; pcur[SZ(mid)]=oth[1]; pcur[SZ(mid)+1]=oth[0]; id3(i,2,oth) pcur[SZ(mid)+i]=oth[i];
			gen(pcur,1,SZ(mid),1,have,'B');
		} while(next_permutation(mid.begin(),mid.end()));
		if(k>=3) do {
			vector<int> pcur(n); id1(i,mid) pcur[i]=mid[i]; pcur[SZ(mid)]=oth[2]; pcur[SZ(mid)+1]=oth[0]; pcur[SZ(mid)+2]=oth[1]; id3(i,3,oth) pcur[SZ(mid)+i]=oth[i];
			int hpref=k==3?n:2*n;
			gen(pcur,1,hpref,SZ(mid),2,2*n,have,'C');
			gen(pcur,n+1,hpref,SZ(mid),1,1,have,'D');
		} while(next_permutation(mid.begin(),mid.end()));
		if(k>=4) id3(pos,3,oth) do {
			vector<int> pcur(n); id1(i,mid) pcur[i]=mid[i]; pcur[SZ(mid)]=oth[pos]; id3(i,1,oth) pcur[SZ(mid)+i]=oth[i<=pos?i-1:i];
			gen(pcur,1,SZ(mid),2,have,'E');
			int hsuff=SZ(mid)+pos<n-1?2*n:n;
			gen(pcur,n+1,hsuff,SZ(mid),1,1,have,'F');
		} while(next_permutation(mid.begin(),mid.end()));
		if(k>=1) do {
			bool ok=false; id3(i,1,mid) if(mid[i-1]<mid[i]) ok=true; if(!ok) continue;
			do {
				string t(SZ(oth)+SZ(mid)+SZ(oth),'?');
				id1(i,oth) t[i]=t[n+i]='0'+oth[i]; id1(i,mid) t[SZ(oth)+i]='0'+mid[i];
				have.PB(t);
			} while(next_permutation(oth.begin(),oth.end()));
		} while(next_permutation(mid.begin(),mid.end()));
	}
	
	
	printf("SZ(have)=%d guess=%d\n",SZ(have),guess);
	sort(have.begin(),have.end());
	id3(i,1,have) if(have[i]==have[i-1]) printf("double: %s\n",have[i].c_str());
	

	

	have.erase(unique(have.begin(),have.end()),have.end());
	
	
	
	
}







int main() {
	

	run();
	return 0;
}
