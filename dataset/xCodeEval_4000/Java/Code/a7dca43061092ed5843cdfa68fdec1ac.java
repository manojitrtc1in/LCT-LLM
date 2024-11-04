import java.io.*;
import java.util.*;

public class tr1 {
	static PrintWriter out;
	static StringBuilder sb;
	static int inf = (int) 1e9;
	static long mod = (long) 1e9 + 7;
	static int[] si;
	static ArrayList<Integer> primes;
	static HashSet<Integer> pr;
	static int n, k, m;
	static int[] in;
	static HashMap<Integer, Integer> factors;
	static HashSet<Integer> f;
	static long[] fac, a, b;
	static int[] l, r;
	static short[][][] memo;
	static int[] numc;
	static ArrayList<Integer>[] ad;
	static HashMap<Integer, Integer> hm;
	static pair[] ed;
	static ArrayList<Integer>[] np;
	static TreeMap<pair, Integer> tm;
	static int[] ans, h1, h2;
	static char[] h;
	static pair[] mm;
	static PriorityQueue<Long> pq;
	static boolean[] vis;
	static int[][] aaa;

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		out = new PrintWriter(System.out);
	    String s=sc.nextLine();
	    int n=s.length();
	    for(int i=0;i<n;i++)
	    	if(s.charAt(i)=='m' || s.charAt(i)=='w') {
	    		System.out.println(0);
	    		return;
	    	}
	    long []f=new long [100005];
	 f[0]=1;
	    for(int i=1;i<f.length;i++) {
	    	f[i]=(i*f[i-1])%mod;
	    }
	    long ans=1;
	    for(int i=0;i<n;i++) {
	    	boolean in =false;
	    	int cu=0;
	    	while(i<n-1 && s.charAt(i)=='u' && s.charAt(i+1)=='u') {
	    		in=true;
	    		cu++;
	    		i++;
	    	}
	    	
	    	int cn=0;
	    	while(i<n-1 && s.charAt(i)=='n' && s.charAt(i+1)=='n') {
	    		in=true;
	    		cn++;
	    		i++;
	    	}
	  
	    	if(in) {
	    		if(cu>0) {
	    			if(cu==1)
	    			ans=(ans*2)%mod;
	    			else {
	    				cu++;
	    				int t=0;
	    				long mul=0;
	    				while(true) {
	    					if(cu-2*t<0)
	    						break;
	    					mul=(mul+((f[cu-t]*((inver(f[t])*inver(f[cu-2*t]))%mod))%mod))%mod;
	    					t++;
	    				}
	    				ans=(ans*mul)%mod;
	    			}
	    		}
	    		if(cn>0) {
	    			if(cn==1)
		    			ans=(ans*2)%mod;
		    			else
		    			{
		    				cn++;
		    				int t=0;
		    				long mul=0;
		    			

		    				while(true) {
		    					if(cn-2*t<0)
		    					  break;
		    					mul=((mul+(f[cn-t]*((inver(f[t])*inver(f[cn-2*t]))%mod))%mod))%mod;
		    					
		    					t++;
		    				}
		    				ans=(ans*mul)%mod;
		    			}
		    			}
	    	}
	    }
	    out.println(ans);
		out.flush();
	}
	static public class FenwickTree { 


		int n;
		int[] ft;
		
		FenwickTree(int size) { n = size; ft = new int[n+1]; }
		
		int rsq(int b) 

		{
			int sum = 0;
			while(b > 0) { sum += ft[b]; b -= b & -b;}		

			return sum;
		}
		
		int rsq(int a, int b) { return rsq(b) - rsq(a-1); }	
		
		void point_update(int k, int val)	

		{
			while(k <= n) { ft[k] += val; k += k & -k; }		

		}

		int point_query(int idx)	

		{
			int sum = ft[idx];
			if(idx > 0)
			{
				int z = idx ^ (idx & -idx);
				--idx;
				while(idx != z)
				{
					sum -= ft[idx];
					idx ^= idx & -idx;
				}
			}
			return sum;
		}
		
		void scale(int c) {	for(int i = 1; i <= n; ++i)	ft[i] *= c;	}
		
		int findIndex(int cumFreq)
		{
			int msk = n;
			while((msk & (msk - 1)) != 0)
					msk ^= msk & -msk;			

			
			int idx = 0;
			while(msk != 0)
			{
				int tIdx = idx + msk;
				if(tIdx <= n && cumFreq >= ft[tIdx])
				{
					idx = tIdx;
					cumFreq -= ft[tIdx];
				}
				msk >>= 1;
			}
			if(cumFreq != 0)
				return -1;
			return idx;
		}
	}
	
	static public class SegmentTree {		

		
		int N; 			

		long[] array, sTree, lazy;
		
		SegmentTree(long[] in)		
		{
			array = in; N = in.length - 1;
			sTree = new long[N<<1];		

			lazy = new long[N<<1];
			build(1,1,N);
		}
		
		void build(int node, int b, int e)	

		{
			if(b == e)					
				sTree[node] = array[b];
			else						
			{
				int mid = b + e >> 1;
				build(node<<1,b,mid);
				build(node<<1|1,mid+1,e);
				sTree[node] = sTree[node<<1]+sTree[node<<1|1];
			}
		}
		
		
		void update_point(int index, int val)			

		{
			index += N - 1;				
			sTree[index] += val;			
			while(index>1)				
			{
				index >>= 1;
				sTree[index] = sTree[index<<1] + sTree[index<<1|1];		
			}
		}
		
		
		void update_range(int i, int j, long val)		

		{
			update_range(1,1,N,i,j,val);
		}
		
		void update_range(int node, int b, int e, int i, int j, long val)
		{
			if(i > e || j < b)		
				return;
			if(b >= i && e <= j)		
			{
				sTree[node] += (e-b+1)*val;			
				lazy[node] += val;				
			}							
			else		
			{
				int mid = b + e >> 1;
				propagate(node, b, mid, e);
				update_range(node<<1,b,mid,i,j,val);
				update_range(node<<1|1,mid+1,e,i,j,val);
				sTree[node] = sTree[node<<1] + sTree[node<<1|1];		
			}
			
		}
		void propagate(int node, int b, int mid, int e)		
		{
			lazy[node<<1] += lazy[node];
			lazy[node<<1|1] += lazy[node];
			sTree[node<<1] += (mid-b+1)*lazy[node];		
			sTree[node<<1|1] += (e-mid)*lazy[node];		
			lazy[node] = 0;
		}
		
		long query(int i, int j)
		{
			return query(1,1,N,i,j);
		}
		
		long query(int node, int b, int e, int i, int j)	

		{
			if(i>e || j <b)
				return 0;		
			if(b>= i && e <= j)
				return sTree[node];
			int mid = b + e >> 1;
			propagate(node, b, mid, e);
			long q1 = query(node<<1,b,mid,i,j);
			long q2 = query(node<<1|1,mid+1,e,i,j);
			return q1 + q2;	
					
		}
		
		
		
	}
	

	static short dp(int i, int j, int dir) {
		if(i>=n)
			return 0;
		if (i == n - 1 && j == 1) {
			if (dir == 0 && (aaa[j][i] == 1 || aaa[j][i] == 2))
				return 1;
			else if (dir == 1 && !(aaa[j][i] == 1 || aaa[j][i] == 2))
				return 1;
			else
				return 0;
		}
	

		if(memo[j][i][dir]!=-1)
			return memo[j][i][dir];
		short ans = 0;
		if (aaa[j][i] == 1 || aaa[j][i] == 2) {
			if (dir == 0) {
				ans |= dp(i + 1, j, 0);
			} else if (dir == 1) {
				if (j == 0) {
					ans |= dp(i,  1, 1);
				}
			} else {
				if (j == 1) {
					ans |= dp(i, 0, 2);
				}
			}
		} else {
			if (dir == 0) {
				if(j==0)
				ans |= dp(i , 1, 1);
				if(j==1)
					ans |= dp(i , 0, 2);
				
			} else if (dir == 1) {
				ans |= dp(i + 1, j, 0);
			} else {
				ans |= dp(i + 1, j, 0);
			}
		}
		return memo[j][i][dir]=ans;
	}

	static long gcd(long a, long b) {

		if (b == 0) {
			return a;
		}
		return gcd(b, a % b);
	}

	static class pair implements Comparable<pair> {
		int x;
		int y;

		pair(int f, int t) {
			x = f;
			y = t;
			

		}

		public String toString() {
			return x + " " + y;
		}

		@Override
		public int compareTo(pair o) {
			return 0;
		}
	}

	public int[] merge(int[] d, int st, int e) {
		if (st > e)
			return null;
		if (e == st) {
			int[] ans = { d[e] };
			return ans;
		}
		int mid = (st + e) / 2;
		int[] ans = new int[e - st + 1];
		int[] ll = merge(d, st, mid);
		int[] rr = merge(d, mid + 1, e);
		if (ll == null)
			return rr;
		if (rr == null)
			return ll;
		int iver = 0;
		int idxl = 0;
		int idxr = 0;
		for (int i = st; i <= e; i++) {
			if (ll[idxl] < rr[idxr]) {

			}
		}
		return ans;
	}

	public static class pair1 implements Comparable<pair1> {
		int a;
		int idx;

		pair1(int a, int i) {
			this.a = a;
			idx = i;
		}

		public String toString() {
			return a + " " + idx;
		}

		@Override
		public int compareTo(pair1 o) {
			return o.a - a;
		}
	}

	public static class pair2 implements Comparable<pair2> {
		int a;
		int idx;

		pair2(int a, int i) {
			this.a = a;
			idx = i;
		}

		public String toString() {
			return a + " " + idx;
		}

		@Override
		public int compareTo(pair2 o) {
			

			return idx - o.idx;
		}
	}

	static long inver(long x) {
		int a = (int) x;
		long e = (mod - 2);
		long res = 1;
		while (e > 0) {
			if ((e & 1) == 1) {
				

				res = (int) ((1l * res * a) % mod);
			}
			a = (int) ((1l * a * a) %mod);
			e >>= 1;
		}
		

		return res % mod;
	}

	static int atMostSum(int arr[], int n, int k) {
		int sum = 0;
		int cnt = 0, maxcnt = 0;

		for (int i = 0; i < n; i++) {

			

			

			if ((sum + arr[i]) <= k) {
				sum += arr[i];
				cnt++;
			}

			

			

			else if (sum != 0) {
				sum = sum - arr[i - cnt] + arr[i];
			}

			

			maxcnt = Math.max(cnt, maxcnt);
		}
		return maxcnt;
	}

	public static int[] longestSubarray(int[] inp) {
		

		int[] p = new int[inp.length];
		p[0] = inp[0];
		for (int i = 1; i < inp.length; i++) {
			p[i] = p[i - 1] + inp[i];
		}

		

		int[] q = new int[inp.length];
		q[inp.length - 1] = p[inp.length - 1];
		for (int i = inp.length - 2; i >= 0; i--) {
			q[i] = Math.max(q[i + 1], p[i]);
		}
		int a = 0;
		int b = 0;
		int maxLen = 0;
		int curr;
		int[] res = new int[] { -1, -1 };
		while (b < inp.length) {
			curr = a > 0 ? q[b] - p[a - 1] : q[b];
			if (curr >= 0) {
				if (b - a > maxLen) {
					maxLen = b - a;
					res = new int[] { a, b };
				}
				b++;
			} else {
				a++;
			}
		}
		return res;
	}

	static void factor(int n) {
		if (si[n] == n) {
			f.add(n);
			return;
		}
		f.add(si[n]);
		factor(n / si[n]);
	}

	static void seive() {
		si = new int[1000001];
		primes = new ArrayList<>();
		int N = 1000001;
		si[1] = 1;
		for (int i = 2; i < N; i++) {
			if (si[i] == 0) {
				si[i] = i;
				primes.add(i);
			}
			for (int j = 0; j < primes.size() && primes.get(j) <= si[i] && (i * primes.get(j)) < N; j++)
				si[primes.get(j) * i] = primes.get(j);

		}
	}

	static class unionfind {
		int[] p;
		int[] size;

		unionfind(int n) {
			p = new int[n];
			size = new int[n];

			for (int i = 0; i < n; i++) {
				p[i] = i;
			}
			Arrays.fill(size, 1);
		}

		int findSet(int v) {
			if (v == p[v])
				return v;
			return p[v] = findSet(p[v]);
		}

		boolean sameSet(int a, int b) {
			a = findSet(a);
			b = findSet(b);
			if (a == b)
				return true;
			return false;
		}

		int max() {
			int max = 0;
			for (int i = 0; i < size.length; i++)
				if (size[i] > max)
					max = size[i];
			return max;
		}

		void combine(int a, int b) {
			a = findSet(a);
			b = findSet(b);
			if (a == b)
				return;
			if (size[a] > size[b]) {
				p[b] = a;
				size[a] += size[b];

			} else {
				p[a] = b;
				size[b] += size[a];
			}
		}
	}

	static class Scanner {
		StringTokenizer st;
		BufferedReader br;

		public Scanner(InputStream system) {
			br = new BufferedReader(new InputStreamReader(system));
		}

		public Scanner(String file) throws Exception {
			br = new BufferedReader(new FileReader(file));
		}

		public String next() throws IOException {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}

		public String nextLine() throws IOException {
			return br.readLine();
		}

		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		public double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}

		public char nextChar() throws IOException {
			return next().charAt(0);
		}

		public Long nextLong() throws IOException {
			return Long.parseLong(next());
		}

		public boolean ready() throws IOException {
			return br.ready();
		}

		public void waitForInput() throws InterruptedException {
			Thread.sleep(3000);
		}
	}
}