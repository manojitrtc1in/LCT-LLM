
























using namespace std;


typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <double, double> pdd;
typedef vector <int> vi;
typedef vector <double> vd;
typedef vector <string> vs;
typedef map <string, int> mpsi;
typedef map <double, int> mpdi;
typedef map <int, int> mpii;

const double pi = acos(0.0) * 2.0;
const double eps = 1e-12;
const int step[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

template <class T> inline T abs1(T a) {return a < 0 ? -a : a;}
template <class T> inline T max1(T a, T b, T c = -1234567, T d = -1234567) {
	T ans =  a > b ? a : b;
	if(c != -1234567) ans = max1(ans, c);
	if(d != -1234567) ans = max1(ans, d);
	return ans;
}
template <class T> inline T min1(T a, T b, T c = -1234567, T d = -1234567) {
	T ans = a < b ? a : b;
	if(c != -1234567) ans = min(ans, c);
	if(d != -1234567) ans = min(ans, d);
	return ans;
}
template <class T> inline T id0(T a, T b) {
	if(a < b) swap(a, b);
	if(a % b == 0) return b;
	return id0(b, a % b);
}
template <class T> inline T lb(T num) {return num & (-num); }
inline int jud(double a, double b){
	if(abs1(a - b) < eps) return 0;
	if(a < b) return -1;
	return 1;
}
template <typename it, typename t1>
inline int find(t1 val, it a, int na, bool f_small = 1, bool f_lb = 1){
	if(na == 1) return 0;
	int be = 0, en = na - 1;
	if(*a <= *(a + na - 1)){
		if(f_lb == 0) while(be < en){
			int mid = (be + en + 1) / 2;
			if(jud(*(a + mid), val) != 1) be = mid;
			else en = mid - 1;
		}else while(be < en){
			int mid = (be + en) / 2;
			if(jud(*(a + mid), val) != -1) en = mid;
			else be = mid + 1;
		}
		if(f_small && jud(*(a + be), val) == 1 && be != 0) be--;
		if(!f_small && jud(*(a + be), val) == -1 && be != na - 1) be++;
	} else {
		if(f_lb) while(be < en){
			int mid = (be + en + 1) / 2;
			if(jud(*(a + mid), val) != -1) be = mid;
			else en = mid - 1;
		}else while(be < en){
			int mid = (be + en) / 2;
			if(jud(*(a + mid), val) != 1) en = mid;
			else be = mid + 1;
		}
		if(!f_small && jud(*(a + be), val) == -1 && be != 0) be--;
		if(f_small && jud(*(a + be), val) == 1 && be != na - 1) be++;
	}
	return be;
}
inline int bitnum(ull nValue){
    nValue = ((0xaaaaaaaaaaaaaaaaull & nValue)>>1) + (0x5555555555555555ull & nValue);
    nValue = ((0xccccccccccccccccull & nValue)>>2) + (0x3333333333333333ull & nValue);
    nValue = ((0xf0f0f0f0f0f0f0f0ull & nValue)>>4) + (0x0f0f0f0f0f0f0f0full & nValue);
    nValue = ((0xff00ff00ff00ff00ull & nValue)>>8) + (0x00ff00ff00ff00ffull & nValue);
    nValue = ((0xffff0000ffff0000ull & nValue)>>16) + (0x0000ffff0000ffffull & nValue);
    nValue = ((0xffffffff00000000ull & nValue)>>32) + (0x00000000ffffffffull & nValue);
	return nValue;
}
long long pow(long long n, long long m, long long mod = 0){
	long long ans = 1;
	long long k = n;
	while(m){
		if(m & 1) {
			ans *= k;
			if(mod) ans %= mod;
		}
		k *= k;
		if(mod) k %= mod;
		m >>= 1;
	}
	return ans;
}






const int MAXN = 1013300;

int sa[MAXN],height[MAXN],rank[MAXN];
int wa[MAXN],wb[MAXN],wc[MAXN],wd[MAXN];

namespace SA
{

    bool cmp(int *r,int a,int b,int l,int n)
    {
        int la = r[a],lb = r[b],ra,rb;
        ra = a+l < n? r[a+l] : -1;
        rb = b+l < n? r[b+l] : -1;
        return (la == lb) && (ra == rb);
    }

    void makesa(int *r,int *sa,int n,int m)
    {
        int *x = wa,*y = wb;
        for (int i = 0;i < m;++i)
            wc[i] = 0;
        for (int i = 0;i < n;++i)
            ++wc[x[i] = r[i]];
        for (int i = 1;i < m;++i)
            wc[i] += wc[i-1];
        for (int i = n-1;i >= 0;--i)
            sa[--wc[x[i]]] = i;
        for (int tot = 0,p = 1;tot+1 < n;p <<= 1,m = tot+1)
        {
            tot = 0;
            for (int i = n-p;i < n;++i)
                y[tot++] = i;
            for (int i = 0;i < n;++i)
                if (sa[i] >= p)
                    y[tot++] = sa[i] - p;
            for (int i = 0;i < n;++i)
                wd[i] = x[y[i]];
            for (int i = 0;i < m;++i)
                wc[i] = 0;
            for (int i = 0;i < n;++i)
                ++wc[wd[i]];
            for (int i = 1;i < m;++i)
                wc[i] += wc[i-1];
            for (int i = n-1;i >= 0;--i)
                sa[--wc[wd[i]]] = y[i];
            int *t = x; x = y; y = t;
            x[sa[0]] = tot = 0;
            for (int i = 1;i < n;++i)
                x[sa[i]] = cmp(y,sa[i-1],sa[i],p,n) ? tot : ++tot;
        }
    }

    void makeheight(char *r,int *sa,int *height,int n)
    {
        for (int i = 0;i < n;++i)
            rank[sa[i]] = i;
        height[0] = 0;
        for (int i = 0;i < n;++i)
        {
            if (!rank[i])
                continue;
            if (!i)
                height[rank[i]] = 0;
            else
                height[rank[i]] = height[rank[i-1]] - 1;
            if (height[rank[i]] < 0)
                height[rank[i]] = 0;
            for (;r[i+height[rank[i]]] == r[sa[rank[i]-1] + height[rank[i]]];++height[rank[i]]);
        }
    }
};
void calheight(int *r, int *sa, int*rank, int*height,int n)
{
     int i,j,k=0;
     for(i=0; i<n;i++) rank[sa[i]]=i;
     for(i=0;i<n;i++){
    	 if(rank[i] == 0) continue;
	     for(k?k--:0,j=sa[rank[i]-1]; i + k < n && j + k < n && r[i+k]==r[j+k];k++);
	     height[rank[i] - 1]=k;
     }
     return;
}

const int maxn = MAXN;
int d[20];
int st[maxn][22];
char orig[maxn];
int h[maxn], str[maxn], ll[maxn];
int n;
pii yue[maxn], range[maxn];
int sum[10][maxn];

inline int max(const int &arg1, const int &arg2){
return arg1 > arg2 ? arg1 : arg2;
}
void id1(const int &n){
	int i, j;
	for( d[0]=1, i=1; i < 21; ++i ) d[i] = 2*d[i-1];
	for( i=0; i < n; ++i ) st[i][0] = h[i];
	int k = int( log(double(n))/log(2) ) + 1;
	for( j=1; j < k; ++j )
		for( i=0; i < n; ++i ){
			if( i+d[j-1]-1 < n ){
				st[i][j] = min(st[i][j-1],
						st[i+d[j-1]][j-1]);
			}
			else break; 

		}
}
inline int que(int x, int y){
	int k = int( log(double(y-x+1))/log(2.0) );
	return min(st[x][k], st[y-d[k]+1][k]);
}

int main(){


	scanf("%s", orig);
	scanf("%d", &n);

	int l = strlen(orig);
	ll[0] = l;
	for(int i = 0; i < n; i++){
		l = strlen(orig);
		orig[l] = 1 + 28 + i;
		l++;
		scanf("%s", orig + l);
		scanf("%d%d", &yue[i].first, &yue[i].second);
		range[i].first = l; range[i].second = strlen(orig);
		ll[i + 1] = strlen(orig);
	}
	l = strlen(orig);
	for(int i = 0; i < l; i++) if(orig[i] < 0) {
		cout << i << endl;
	}
	for(int i = 0; i < l; i++) str[i] = orig[i], assert(str[i] > 0);
	SA::makesa(str, sa, l, 200);
	calheight(str, sa, rank, h, l);

	id1(l);
	for(int i = 0; i < n; i++) if(sa[0] > ll[i] && sa[0] < ll[i + 1]) sum[i][0] = 1;
	for(int i = 1; i < l; i++)  {
		for(int j = 0; j < n; j++) {
			sum[j][i] = sum[j][i - 1];
			if(sa[i] > ll[j] && sa[i] < ll[j + 1]) sum[j][i]++;
		}
	}

	if(n == 0) {
		int last = -1;
		long long ans = 0;
		for(int i = 0; i < l; i++) if(sa[i] < ll[0]){
			if(last == -1) ans += ll[0] - sa[i];
			else ans += ll[0] - sa[i] - que(last, i - 1);
			last = i;

		}
		cout << ans << endl;
		return 0;
	}

	long long ans = 0, last = -1;
	for(int i = 0; i < l; i++) if(sa[i] < ll[0]) {
		int be = 1, en = ll[0] - sa[i];
		bool flag = 1, flag1 = 0;
		while(be < en) {
			int mid = (be + en) / 2;


			int be1 = 0, en1 = i - 1;
			while(be1 < en1) {
				int mid1 = (be1 + en1) / 2;
				if(que(mid1, i - 1) < mid) be1 = mid1 + 1;
				else en1 = mid1;
			}
			if(que(be1, i - 1) < mid) be1++;
			int from = min1(be1, i);
			be1 = i; en1 = l - 1;
			while(be1 < en1) {
				int mid1 = (be1 + en1 + 1) / 2;
				if(que(i, mid1) < mid) en1 = mid1 - 1;
				else be1 = mid1;
			}
			if(que(i, be1) < mid) be1--;
			int to = max1(be1 + 1, i);
	

			int fff = 0;
			for(int j = 0; j < n; j++) {
				int ransum = 0;
				if(from == 0) ransum = sum[j][to];
				else ransum = sum[j][to] - sum[j][from - 1];
				if(ransum > yue[j].second) fff |= 2;
				if(ransum < yue[j].first) fff |= 1;
			}
			if(fff == 3) {
				flag = 0;
				break;
			}
			if(fff == 1) en = mid - 1;
			else if(fff == 2) be = mid + 1;
			else if(fff == 0) en = mid, flag1 = 1;
		}

		int mid = be;
		int be1 = 0, en1 = i - 1;
		while(be1 < en1) {
			int mid1 = (be1 + en1) / 2;
			if(que(mid1, i - 1) < mid) be1 = mid1 + 1;
			else en1 = mid1;
		}
		if(que(be1, i - 1) < mid) be1++;
		int from = min1(be1, i);
		be1 = i; en1 = l - 1;
		while(be1 < en1) {
			int mid1 = (be1 + en1 + 1) / 2;
			if(que(i, mid1) < mid) en1 = mid1 - 1;
			else be1 = mid1;
		}
		if(que(i, be1) < mid) be1--;
		int to = max1(be1 + 1, i);
		int fff = 0;
		for(int j = 0; j < n; j++) {
			int ransum = 0;
			if(from == 0) ransum = sum[j][to];
			else ransum = sum[j][to] - sum[j][from - 1];
			if(ransum > yue[j].second) fff |= 2;
			if(ransum < yue[j].first) fff |= 1;
		}

		if(flag && fff == 0) {
			int biao = be;
			int be1 = be, en1 = ll[0] - sa[i];
			bool flag = 1, flag1 = 0;
			while(be1 < en1) {
				int mid = (be1 + en1 + 1) / 2;
				int be11 = 0, en11 = i - 1;
				while(be11 < en11) {
					int mid1 = (be11 + en11) / 2;
					if(que(mid1, i - 1) < mid) be11 = mid1 + 1;
					else en11 = mid1;
				}
				if(que(be11, i - 1) < mid) be11++;
				int from = min1(be11, i);
				be11 = i; en11 = l - 1;
				while(be11 < en11) {
					int mid1 = (be11 + en11 + 1) / 2;
					if(que(i, mid1) < mid) en11 = mid1 - 1;
					else be11 = mid1;
				}
				if(que(i, be11) < mid) be11--;
				int to = max1(be11 + 1, i);
				int fff = 0;
				for(int j = 0; j < n; j++) {
					int ransum = 0;
					if(from == 0) ransum = sum[j][to];
					else ransum = sum[j][to] - sum[j][from - 1];
					if(ransum > yue[j].second) fff |= 2;
					if(ransum < yue[j].first) fff |= 1;
				}
				if(fff == 3) {
					flag = 0;
					break;
				}
				if(fff == 1) en1 = mid - 1;
				if(fff == 2) be1 = mid + 1;
				if(fff == 0) be1 = mid, flag1 = 1;
			}
			long long rans = (be1 - biao + 1);
			if(last != -1) rans -= max1(que(last, i - 1) - biao + 1, 0);
			ans += max(rans, 0);
			last = i;
		}
	}
	cout << ans << endl;

	return 0;
}



