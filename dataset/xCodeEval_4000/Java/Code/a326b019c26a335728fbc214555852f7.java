import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class E3 {

	static int N;
	static int adj[][];
	static long res[];
	static int sz[];
	static int dep[];
	static long bank[];
	static long curHave[];
	static boolean blocked[];
	static FFT fft = new FFT();
	public static void main(String[] args) {
		

		JS in = new JS();
		N = in.nextInt();
		adj = new int[N][];
		int cnt[] = new int[N];
		int input[] = new int[2*N];
		for(int i = 0; i < N-1; i++) {
			int v1 = in.nextInt()-1;
			int v2 = in.nextInt()-1;
			cnt[v1]++;
			cnt[v2]++;
			input[2*i]=v1;
			input[2*i+1]=v2;
		}
		for(int i = 0; i < N; i++) adj[i] = new int[cnt[i]];
		for(int i = 0; i < N-1; i++) {
			int v1 = input[2*i];
			int v2 = input[2*i+1];
			adj[v1][--cnt[v1]]=v2;
			adj[v2][--cnt[v2]]=v1;
		}
		blocked = new boolean[N];
		sz = new int[N];
		res = new long[N+1];
		solve(0,-1);
		long finalRes = 0;
		for(int i = 0; i <= N; i++) {
			long pathLen = i/2;
			if(i%2==1)pathLen++;
			finalRes += pathLen*res[i];
		}
		System.out.println(finalRes);
	}

	static void solve(int root, int par) {
		

		dfs(root,par);
		

		int centroid = getCentroid(root,sz[root]);
		blocked[centroid]=true; 

		


		ArrayList<data> list = new ArrayList<data>();
		int maxDep = 0;
		for(int ii : adj[centroid]) {
			if(ii!=par && !blocked[ii]) {
				data dd = new data(ii,getDep(ii,centroid));
				list.add(dd);
				maxDep = Math.max(maxDep, dd.dep);
			}
		}
		Collections.sort(list);
		bank = new long[maxDep+1]; 

		int bankSize = 0; 

		for(data d : list) {
			curHave = new long[d.dep+1];
			addToHave(d.node,centroid,1); 

			long m[] = fft.multiply(curHave, Arrays.copyOf(bank, bankSize+1));
			for(int i = 0; i <= d.dep; i++) {
				res[i]+=curHave[i]; 

				bank[i]+=curHave[i];
			}
			for(int i = 0; i < m.length; i++)res[i]+=m[i];
			bankSize = d.dep;
		}
		
		for(int ii : adj[centroid]) if(ii!=par&&!blocked[ii]) {
			solve(ii, centroid);	
		}
	}
	static void addToHave(int node, int par, int dep) {
		curHave[dep]++;
		for(int ii : adj[node]) {
			if(ii!=par&&!blocked[ii])addToHave(ii,node,dep+1);
		}
	}
	static int getDep(int node, int par) {
		int dep = 1;
		for(int ii : adj[node]) {
			if(ii!=par && !blocked[ii]) dep = Math.max(dep, 1+getDep(ii,node));
		}
		return dep;
	}
	static int getCentroid(int n, int size) {
		int maxId = -1;
		int maxSz = -1;
		for(int ii : adj[n]) {
			if(blocked[ii])continue;
			if(sz[ii] > maxSz) {
				maxSz=sz[ii];
				maxId=ii;
			}
		}
		if(maxSz <= size/2) return n;
		sz[n] = size-maxSz;
		return getCentroid(maxId,size);
	}
	static void dfs(int node, int p) {
		sz[node]=1;
		for(int ii : adj[node]) {
			if(ii != p && !blocked[ii]) {
				dfs(ii,node);
				sz[node]+=sz[ii];
			}
		}
	}
	
	

	static class FFT {
	    static final int maxk = 21, maxn = (1 << maxk) + 1;
	    

	    

	    static double[] wR = new double[maxn],
	            wI = new double[maxn],
	            rR = new double[maxn],
	            rI = new double[maxn],
	            aR  = new double[maxn],
	            aI  = new double[maxn]; 

	    static int n, k, lastk = -1, dp[] = new int[maxn];

	    static void fft(boolean inv) {
	        if (lastk != k) {
	            lastk = k;  dp[0] = 0;
	            for (int i = 1, g = -1; i < n; i++) {
	                if ((i & (i - 1)) == 0) g++;
	                dp[i] = dp[i ^ (1 << g)] ^ (1 << (k - 1 - g));
	            }
	            wR[1] = 1;
	            wI[1] = 0;
	            for (int t = 0; t < k - 1; t++) {
	                double a = Math.PI / n * (1 << (k - 1 - t));
	                double curR = Math.cos(a), curI = Math.sin(a);
	                int p2 = (1 << t), p3 = p2 * 2;
	                for (int j = p2, k = j * 2; j < p3; j++, k += 2) {
	                    wR[k] = wR[j];
	                    wI[k] = wI[j];
	                    wR[k + 1] = wR[j] * curR - wI[j] * curI;
	                    wI[k + 1] = wR[j] * curI + wI[j] * curR;
	                }
	            }
	        }
	        for (int i = 0; i < n; i++) {
	            int d = dp[i];
	            if (i < d) {
	                double tmp = aR[i];
	                aR[i] = aR[d];
	                aR[d] = tmp;
	                tmp = aI[i];
	                aI[i] = aI[d];
	                aI[d] = tmp;
	            }
	        }
	        if (inv) for (int i = 0; i < n; i++) aI[i] = -aI[i];
	        for (int len = 1; len < n; len <<= 1) {
	            for (int i = 0; i < n; i += len) {
	                int wit = len;
	                for (int it = 0, j = i + len; it < len; it++, i++, j++) {
	                    double tmpR = aR[j] * wR[wit] - aI[j] * wI[wit];
	                    double tmpI = aR[j] * wI[wit] + aI[j] * wR[wit];
	                    wit++;
	                    aR[j] = aR[i] - tmpR;
	                    aI[j] = aI[i] - tmpI;
	                    aR[i] += tmpR;
	                    aI[i] += tmpI;
	                }
	            }
	        }
	    }

	    static long[] multiply(long[] a, long[] b) {
	        int na = a.length, nb = b.length;
	        for (k = 0, n = 1; n < na + nb - 1; n <<= 1, k++) {}
	        for (int i = 0; i < n; ++i) {
	            aR[i] = i < na ? a[i] : 0;
	            aI[i] = i < nb ? b[i] : 0;
	        }
	        fft(false);
	        aR[n] = aR[0];
	        aI[n] = aI[0];
	        double q = -1.0 / n / 4.0;
	        for (int i = 0; i <= n - i; ++i) {
	            double tmpR = aR[i] * aR[i] - aI[i] * aI[i];
	            double tmpI = aR[i] * aI[i] * 2;
	            tmpR -= aR[n - i] * aR[n - i] - aI[n - i] * aI[n - i];
	            tmpI -= aR[n - i] * aI[n - i] * -2;
	            aR[i] = -tmpI * q;
	            aI[i] = tmpR * q;
	            aR[n - i] = aR[i];
	            aI[n - i] = -aI[i];
	        }
	        fft(true);
	        long[] ans = new long[n = na + nb - 1]; 

	        for (int i = 0; i < n; i++) ans[i] = Math.round(aR[i]);
	        return ans;
	    }
	    static void fft2(double[][] xr, double[][] xi, boolean inv) {
	        n = xr[0].length;
	        k = Integer.numberOfTrailingZeros(n);
	        for (int i = 0; i < xr.length; i++) {
	            for (int j = 0; j < n; j++) { aR[j] = xr[i][j];  aI[j] = xi[i][j]; }
	            fft(inv);
	            for (int j=0;j<n;j++){xr[i][j] = aR[j] / (inv ? n : 1);  xi[i][j] = aI[j] / (inv ? -n : 1);}
	        }
	        n = xr.length;
	        k = Integer.numberOfTrailingZeros(n);
	        for (int j = 0; j < xr[0].length; j++) {
	            for (int i = 0; i < n; i++) { aR[i] = xr[i][j];  aI[i] = xi[i][j]; }
	            fft(inv);
	            for (int i=0;i<n;i++){xr[i][j] = aR[i] / (inv ? n : 1);  xi[i][j] = aI[i] / (inv ? -n : 1);}
	        }
	    }
	    static long[][] multiply2(long[][] a, long[][] b) {
	        int n1, n2;
	        for (n1 = 1; n1 < a.length + b.length - 1; n1 <<= 1) {}
	        for (n2 = 1; n2 < a[0].length + b[0].length - 1; n2 <<= 1) {}
	        double[][] ar = new double[n1][n2], ai = new double[n1][n2];
	        double[][] br = new double[n1][n2], bi = new double[n1][n2];
	        for (int i = 0; i < a.length; i++) for(int j=0;j<a[i].length;j++) ar[i][j] = a[i][j];
	        for (int i = 0; i < b.length; i++) for(int j=0;j<b[i].length;j++) br[i][j] = b[i][j];
	        fft2(ar,ai,false); fft2(br,bi,false);
	        for (int i = 0; i < n1; i++) {
	            for(int j = 0; j < n2; j++) {
	                double r1 = ar[i][j], r2 = br[i][j];
	                double i1 = ai[i][j], i2 = bi[i][j];
	                double real = r1 * r2 - i1 * i2;
	                ai[i][j] = i1 * r2+ i2*r1;
	                ar[i][j] = real;
	            }
	        }
	        fft2(ar,ai,true);  long[][] result = new long[n1=a.length+b.length-1][n2=a[0].length+b[0].length-1];
	        for (int i = 0; i < n1; i++)
	            for(int j = 0; j < n2; j++) result[i][j] = Math.round(ar[i][j]);
	        return result;
	    }
	    





































	    

	    

	    static long[] multiplyOr(long[] eq1, long[] eq2) {
	        int n = Math.max(eq1.length, eq2.length);
	        if((n & (n-1)) != 0)
	            n = Integer.highestOneBit(n)*2;
	        eq1 = fftOr(eq1, n, false);
	        eq2 = fftOr(eq2, n, false);
	        for(int i=0;i<eq1.length;i++)
	            eq1[i] *= eq2[i];
	        eq1 = fftOr(eq1, n, true);
	        return eq1;
	    }
	    

	    

	    static long[] fftOr(long[] arr, int n, boolean invert) {
	        long[] ans = Arrays.copyOf(arr, n);
	        for (int b = 1; b < n; b <<= 1)
	            for (int i = 0; i < n; i++) {
	                if ((i & b) != 0) continue;
	                ans[i + b] += invert ? -ans[i] : ans[i];
	            }
	        return ans;
	    }
	    static long[] fftXor(long[] arr, int n, boolean invert) {
	        long[] ans = Arrays.copyOf(arr, n);
	        for (int b = 1; b < n; b <<= 1)
	            for (int i = 0; i < n; i++) {
	                if((i & b) != 0) continue;
	                long u = ans[i], v = ans[i+b];
	                ans[i] = u + v;  ans[i + b] = u - v;
	            }
	        if (invert) for (int i = 0; i < n; i++) ans[i] /= n;
	        return ans;
	    }
	}

	static class data implements Comparable<data>{
		int node, dep;
		public data(int nn, int dd) {
			node=nn;
			dep=dd;
		}
		@Override
		public int compareTo(data o) {
			return this.dep-o.dep;
		}
	}
	static class JS{
		public int BS = 1<<16;
		public char NC = (char)0;
		byte[] buf = new byte[BS];
		int bId = 0, size = 0;
		char c = NC;
		double num = 1;
		BufferedInputStream in;
		
		public JS() {
			in = new BufferedInputStream(System.in, BS);
		}
		
		public JS(String s) throws FileNotFoundException {
			in = new BufferedInputStream(new FileInputStream(new File(s)), BS);
		}
		
		public char nextChar(){
			while(bId==size) {
				try {
					size = in.read(buf);
				}catch(Exception e) {
					return NC;
				}				
				if(size==-1)return NC;
				bId=0;
			}
			return (char)buf[bId++];
		}
		
		public int nextInt() {
			return (int)nextLong();
		}
		
		public long nextLong() {
			num=1;
			boolean neg = false;
			if(c==NC)c=nextChar();
			for(;(c<'0' || c>'9'); c = nextChar()) {
				if(c=='-')neg=true;
			}
			long res = 0;
			for(; c>='0' && c <='9'; c=nextChar()) {
				res = (res<<3)+(res<<1)+c-'0';
				num*=10;
			}
			return neg?-res:res;
		}
		
		public double nextDouble() {
		    while(c!='.'&&c!='-'&&(c <'0' || c>'9')) c = nextChar();
		    boolean neg = c=='-';
		    if(neg)c=nextChar();
		    boolean fl = c=='.';
		    double cur = nextLong();
		    if(fl) return neg ? -cur/num : cur/num;
		    if(c == '.') {
			double next = nextLong();
			return neg ? -cur-next/num : cur+next/num;
		    }
		    else return neg ? -cur : cur;
		}
		
		public String next() {
			StringBuilder res = new StringBuilder();
			while(c<=32)c=nextChar();
			while(c>32) {
				res.append(c);
				c=nextChar();
			}
			return res.toString();
		}
		
		public String nextLine() {
			StringBuilder res = new StringBuilder();
			while(c<=32)c=nextChar();
			while(c!='\n') {
				res.append(c);
				c=nextChar();
			}
			return res.toString();
		}

		public boolean hasNext() {
			if(c>32)return true;
			while(true) {
				c=nextChar();
				if(c==NC)return false;
				else if(c>32)return true;
			}
		}
	}
	
}
