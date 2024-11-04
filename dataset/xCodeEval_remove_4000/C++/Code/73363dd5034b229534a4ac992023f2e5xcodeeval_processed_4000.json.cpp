


using namespace std;













typedef long long LL;
LL MOD = 1000000007;
char tmp[400999];

class suffixArray
{
public:
	suffixArray(char ss[], int n){
		N = n;
		POS = (int *)calloc(N+1, sizeof(int));
		SA  = (int *)calloc(N+1, sizeof(int));
		LCP = (int *)calloc(N+1, sizeof(int));
		str = (char *)calloc(N+1, sizeof(char));
		for(int i=0;i<=n;++i) str[i] = ss[i];
		SuffixArray(N, str, SA, POS);
	}
	~suffixArray(){
		free(POS);
		free(SA);
		free(LCP);
		free(str);
	}

	void getSuffixArray(int a[]){
		for(int i=1;i<=N;++i)
			a[i] = SA[i-1]+1;
		return ;
	}

	void getPosArray(int a[]){
		for(int i=1;i<=N;++i)
			a[i] = POS[i-1]+1;
		return ;
	}

	void getLCPArray(int a[]){
		buildLCP();
		for(int i=2;i<=N;++i)
			a[i] = LCP[i-2];
		a[1] = 0;
		return ;
	}

private:
	int * POS, * SA, *LCP , N;
	char * str;

	inline bool leq(int a1,int a2,int b1,int b2)
	{
		return (a1<b1 || a1==b1 && a2<=b2);
	}
	inline bool leq(int a1,int a2,int a3,int b1,int b2,int b3)
	{
		return (a1<b1 || a1==b1 && leq(a2,a3,b2,b3)); 
	}
	void RadixPass(int *a,int *b,int *r,int n,int K) 
	{
		int *cnt=new int[K+1];
		memset(cnt,0,(K+1)*sizeof(int));
		for (int i=0;i<n;i++) cnt[r[a[i]]]++;
		for (int i=1;i<=K;i++) cnt[i]+=cnt[i-1];
		for (int i=n-1;i>=0;i--) b[--cnt[r[a[i]]]]=a[i];
		delete[] cnt;
	}
	void GetSuffixArray(int *s,int *SA,int n,int K)
	{
		if (n<=8)
		{
			bool c[8][8];
			for (int i=n-1;i>=0;i--) for (int j=i+1;j<n;j++)
			{
				if (s[i]==s[j]) c[i][j]=(j+1<n && c[i+1][j+1]);
				else c[i][j]=(s[i]<s[j]);
				c[j][i]=!c[i][j];
			}
			for (int i=0;i<n;i++) SA[i]=i;
			for (int i=0;i<n;i++) for (int j=i+1;j<n;j++) if (c[SA[j]][SA[i]]) swap(SA[i],SA[j]);
			return;
		}
		int n0=(n+2)/3,n1=(n+1)/3,n2=n/3,n02=n0+n2;
		int *s12=new int[n02+3];
		s12[n02]=s12[n02+1]=s12[n02+2]=0; 
		int *SA12=new int[n02+3];
		SA12[n02]=SA12[n02+1]=SA12[n02+2]=0;
		int *s0=new int[n0];
		int *SA0=new int[n0];
		for (int i=0,j=0;i<n+(n0-n1);i++) if (i%3!=0) s12[j++]=i;
		RadixPass(s12,SA12,s+2,n02,K);
		RadixPass(SA12,s12,s+1,n02,K);  
		RadixPass(s12,SA12,s,n02,K);
		int name=0,c0=-1,c1=-1,c2=-1;
		for (int i=0;i<n02;i++)
		{
			if (s[SA12[i]]!=c0 || s[SA12[i]+1]!=c1 || s[SA12[i]+2]!=c2)
				name++,c0=s[SA12[i]],c1=s[SA12[i]+1],c2=s[SA12[i]+2];
			if (SA12[i]%3==1)
				s12[SA12[i]/3]=name;
			else 
				s12[SA12[i]/3+n0]=name;
		}
		if (name<n02)
		{
			GetSuffixArray(s12,SA12,n02,name);
			for (int i=0;i<n02;i++) s12[SA12[i]]=i+1;
		}
		else
		{
			for (int i=0;i<n02;i++) SA12[s12[i]-1]=i; 
		}
		for (int i=0,j=0;i<n02;i++) if (SA12[i]<n0) s0[j++]=3*SA12[i];
		RadixPass(s0,SA0,s,n0,K);
		for (int p=0,t=n0-n1,k=0;k<n;k++)
		{
			int i=(SA12[t]<n0?SA12[t]*3+1:(SA12[t]-n0)*3+2);
			int j=SA0[p];
			if (SA12[t]<n0?leq(s[i],s12[SA12[t]+n0],s[j],s12[j/3]):
				           leq(s[i],s[i+1],s12[SA12[t]-n0+1],s[j],s[j+1],s12[j/3+n0]))
			{
				SA[k]=i;
				if ((++t)==n02) for (k++;p<n0;p++,k++) SA[k]=SA0[p];
			}
			else
			{ 
				SA[k]=j;
				if ((++p)==n0) for (k++;t<n02;t++,k++) SA[k]=(SA12[t]<n0?SA12[t]*3+1:(SA12[t]-n0)*3+2); 
			}
		}
		delete[] s12;
		delete[] SA12;
		delete[] s0;
		delete[] SA0;
	}
	void SuffixArray(int n,char *s,int *SA,int *Rank)
	{
		int *A=new int[n+3];
		for (int i=0;i<n;i++) A[i]=(int)((unsigned char)s[i]);
		A[n]=A[n+1]=A[n+2]=0;
		GetSuffixArray(A,SA,n,256);
		for (int i=0;i<n;i++) Rank[SA[i]]=i;
	}
	void SuffixArray(int n,int *s,int *SA,int *Rank)
	{
		int maxs=0;
		for (int i=0;i<n;i++) if (s[i]>maxs) maxs=s[i];
		maxs++;
		int *A=new int[n+3];
		A[n]=A[n+1]=A[n+2]=0;
		if (maxs<(1<<16))
		{
			for (int i=0;i<n;i++) A[i]=s[i];
			GetSuffixArray(A,SA,n,maxs);
		}
		else
		{
			int *C=new int[1<<16];
			int *t=new int[n];
			memset(C,0,(1<<16)*sizeof(int));
			for (int i=0;i<n;i++) C[s[i]&65535]++;
			for (int i=1;i<(1<<16);i++) C[i]+=C[i-1];
			for (int i=n-1;i>=0;i--) A[--C[s[i]&65535]]=i;
			memset(C,0,(1<<16)*sizeof(int));
			for (int i=0;i<n;i++) C[s[i]>>16]++;
			for (int i=1;i<(1<<16);i++) C[i]+=C[i-1];
			for (int i=n-1;i>=0;i--) t[--C[s[A[i]]>>16]]=A[i];
			for (int d=0,i=0;i<n;i++) A[t[i]]=(i>0 && s[t[i]]!=s[t[i-1]])?(++d):d;
			GetSuffixArray(A,SA,n,n);
			delete[] C;
			delete[] t;
		}
		for (int i=0;i<n;i++) Rank[SA[i]]=i;
	}
	void PrepareD(int *s,int *SA,int *Rank,int *D,int n)
	{
		for (int k=0,i=0;i<n;i++)
			if (Rank[i]==n-1)
				D[n-1]=k=0;
			else
			{
				if (k>0) k--;
				int t=SA[Rank[i]+1];
				for (;i+k<n && i+k<n && s[i+k]==s[t+k];k++);
				D[Rank[i]]=k;
			}
	}
	void PrepareD(char *s,int *SA,int *Rank,int *D,int n)
	{
		for (int k=0,i=0;i<n;i++)
			if (Rank[i]==n-1)
				D[n-1]=k=0;
			else
			{
				if (k>0) k--;
				int t=SA[Rank[i]+1];
				for (;i+k<n && i+k<n && s[i+k]==s[t+k];k++);
				D[Rank[i]]=k;
			}
	}

	void buildLCP(){
		int k = 0;
		for(int i=0;i<N;++i) if(POS[i] != N-1){
			

			

			for(int j = SA[POS[i]+1] ; str[j + k] == str[i + k] ; )
				k = k + 1;
			LCP[POS[i]] = k;
			if(k > 0) k = k - 1;
		}
		POS[N-1] = 0; 

		return ;
	}

};

class RMQ
{
public:
	RMQ(int A[], int n){
		RMQ::init();
		H = ceil(log2(n));
		N = n;
		M.resize(N+1);
		for(int i=0;i<=N;++i)
			M[i].resize(H+1);

		for(int i=0;i<=H;++i){
			int jump = ((1<<i)>>1);
			for(int j=1;j<=N;++j)
			{
				if(i == 0) M[j][i] = A[j-1];
				else if(j+jump <= N) M[j][i] = min(M[j][i-1], M[j+jump][i-1]);
				else  M[j][i] = M[j][i-1];
			}
		}
	}

	~RMQ(){
		for(int i=0;i<=N;++i) M[i].clear();
		M.clear();
	}

	int findMin(int l, int r){
		if(l>r) return 0;
		int d = A[r-l+1];
		r = r - (1<<d) + 1;
		return min(M[l][d], M[r][d]);
	}

private:
	int H, N;
	vector<vector<int> > M;
	int A[2000001];

	void init(){
		memset(A, -1, sizeof A);
		for(int i=0; (1<<i)<=2000000; ++i){
			A[(1<<i)] = i;
		}
		for(int i=1;i<=2000000;++i){
			if(A[i] != -1) continue;
			A[i] = A[i-1];
		}
		return;
	}
	
};


int SA[411111];
int LCP[411111];
int POS[411111];

vector<int> List[411111];
vector<int> bank[411111];

struct query{
	int l, r, most, least;
} Q[500000];

int N;

inline void update(int idx){
	while(idx <= N){
		POS[idx] += 1;
		idx += (idx & -idx);
	}
}
inline int query(int idx){
	int ans = 0;
	while(idx > 0){
		ans += POS[idx];
		idx -= (idx & -idx);
	}
	return ans;
}

inline int query1(int idx, int v){
	int i = lower_bound(List[idx].begin(), List[idx].end(), v) - List[idx].begin();
	assert(i < List[idx].size());
	return bank[idx][i];
}

int main()
{
	int n, q;
	scanf("%d %d", &n, &q);
	vector<int> st(n);
	vector<int> len(n);
	string str;
	rep(i, n){
		scanf("%s", tmp);
		st[i] = str.length();
		len[i] = strlen(tmp);
		str += tmp;
		str += '$';
	}
	N = str.length();
	rep(i, N) tmp[i] = str[i];
	tmp[N] = 0;

	suffixArray mySA(tmp, N);
	mySA.getSuffixArray(SA);
	mySA.getPosArray(POS);
	mySA.getLCPArray(LCP);

	


	

	

	


	RMQ rmq(LCP + 1, N);

	rep(i, q){
		int l, r, k;
		scanf("%d %d %d",&l, &r, &k);
		int least, most;
		least = st[l-1] + 1;
		most = st[r-1] + len[r-1] + 1;
		k -= 1;
		int leng = len[k];
		k = st[k];
		

		most -= leng;
		k += 1;
		k = POS[k]; 

		int left = 2, right = k, mid, L, R;

		if(LCP[k] < leng) L = k;
		else{
			while(right - left > 1){
				mid = (left + right) / 2;
				int mn = rmq.findMin(mid, k);
				if(mn >= leng) right = mid;
				else left = mid;
			}
			if(rmq.findMin(left, k) >= leng) L = left;
			else L = right;

			L -= 1;
		}
		
		if(k == N || LCP[k+1] < leng) R = k;
		else {
			left = k+1, right = N;
			while(right - left > 1){
				mid = (left + right) / 2;
				int mn = rmq.findMin(k+1, mid);
				if(mn >= leng) left = mid;
				else right = mid;
			}
			if(rmq.findMin(k+1, right) >= leng) R = right;
			else R = left;
		}
		assert(L <= R);
		if(most < least || most < 1) most = least = 0;
		if(least < 2) least = 0;
		Q[i] = {L, R, most, least};
		List[R].push_back(most);
		List[R].push_back(least - 1);
		List[L-1].push_back(most);
		List[L-1].push_back(least - 1);
	}
	for(int i = 0; i <= N; ++i){
		if(List[i].size() == 0) continue;
		sort(List[i].begin(), List[i].end());
		int j = 0;
		LCP[j++] = List[i][0];
		for(int jj = 1; jj < List[i].size(); ++jj){
			if(List[i][jj] != List[i][jj-1]) LCP[j++] = List[i][jj];
		}
		List[i].resize(j);
		bank[i].resize(j);
		for(int jj = 0; jj < j; ++jj) List[i][jj] = LCP[jj];
	}
	memset(POS, 0, sizeof POS);
	for(int& xx : bank[0]) xx = 0;
	for(int i = 1; i <= N; ++i){
		update(SA[i]);
		for(int j = 0; j < List[i].size(); ++j){
			bank[i][j] = query(List[i][j]);
		}
	}
	rep(i, q){
		int ans = query1(Q[i].r, Q[i].most) - query1(Q[i].l - 1, Q[i].most);
		ans -= query1(Q[i].r, Q[i].least-1) - query1(Q[i].l - 1, Q[i].least - 1);
		printf("%d\n",ans);
	}
	return 0;
}
