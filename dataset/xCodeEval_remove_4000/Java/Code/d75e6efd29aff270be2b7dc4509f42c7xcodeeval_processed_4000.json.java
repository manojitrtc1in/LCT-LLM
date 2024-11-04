import java.util.*;
import java.io.*;


public class Main {
	
	public static void main(String[] args) throws Exception {
    int n=sc.nextInt();
    int m=sc.nextInt();
    char[][]grid=new char[n][m];
    for(int i=0;i<n;i++) {
    	grid[i]=sc.next().toCharArray();
    }
    if(n>3&&m>3) {
    	pw.println(-1);
    }else {
		if(n==1) {
			pw.println(0);
		}else if(n==2) {
			int even=0;
			int odd=0;
			for(int i=0;i<m;i++) {
				int z=0;
				if(grid[0][i]=='1') {
					z++;
				}
				if(grid[1][i]=='1') {
					z++;
				}
				if(z%2==i%2) {
					odd++;
				}else {
					even++;
				}
			}
			pw.print(Math.min(even, odd));
		}else {
			int id1=0;
			int odd_even=0;
			int even_even=0;
			int id15=0;
			for(int i=0;i<m;i++) {
				int z1=0;
				int z2=0;
			if(grid[0][i]=='1') {
				z1++;
			}
			if(grid[1][i]=='1') {
				z1++;
				z2++;
			}
			if(grid[2][i]=='1') {
				z2++;
			}


			if((z1%2==i%2||z2%2==i%2)) {
				even_even++;
			}
			if((z1%2==i%2||z2%2!=i%2)) {
				id1++;
			}
			if((z1%2!=i%2||z2%2==i%2)) {
				odd_even++;
			}
			if((z1%2!=i%2||z2%2!=i%2)) {
				id15++;
			}
			}


			int ans=Math.min(even_even, odd_even);
			ans=Math.min(ans, id15);
			ans=Math.min(ans, id1);
			pw.println(ans);
		}
	}
		pw.close();
	}

	public static boolean isprime(long a) {
		if (a == 0 || a == 1) {
			return false;
		}
		if (a == 2) {
			return true;
		}
		for (int i = 2; i < Math.sqrt(a) + 1; i++) {
			if (a % i == 0) {
				return false;
			}
		}
		return true;
	}

	public static class SegmentTree { 


		int N; 

		long[] array;
		long[] sTree;
		long[] lazy;

		SegmentTree(long[] a) {

			int nn = a.length;
			int NN = 1;
			while (NN < nn)
				NN <<= 1; 


			long[] in = new long[NN + 1];
			for (int i = 1; i <= nn; i++)
				in[i] = a[i - 1];

			array = in;
			N = in.length - 1;
			sTree = new long[N << 1]; 

			lazy = new long[N << 1];
			build(1, 1, N);
		}

		SegmentTree(int[] a) {

			int nn = a.length;
			int NN = 1;
			while (NN < nn)
				NN <<= 1; 


			long[] in = new long[NN + 1];

			for (int i = 1; i <= nn; i++)
				in[i] = a[i - 1];

			array = in;
			N = in.length - 1;
			sTree = new long[N << 1]; 


			lazy = new long[N << 1];

			build(1, 1, N);
		}

		void build(int node, int b, int e) 

		{
			if (b == e) {
				sTree[node] = array[b];

			} else {
				int mid = b + e >> 1;
				build(node << 1, b, mid);
				build(node << 1 | 1, mid + 1, e);
				sTree[node] = sTree[node << 1] + sTree[node << 1 | 1];

			}
		}

		void update_point(int index, long val) 

		{
			index += N;
			sTree[index] = val;
			while (index > 1) {
				index >>= 1;
				sTree[index] = sTree[index << 1] + sTree[index << 1 | 1];

			}
		}

    	void update_range(int i, int j, long val)		

    	{
    		update_range(1,1,N,i+1,j+1,val);
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

		long query(int i, int j) {
			return query(1, 1, N, i + 1, j + 1);
		}

		long query(int node, int b, int e, int i, int j) 

		{
			if (i > e || j < b)
				return 0;
			if (b >= i && e <= j)
				return sTree[node];
			int mid = b + e >> 1;


			long q1 = query(node << 1, b, mid, i, j);
			long q2 = query(node << 1 | 1, mid + 1, e, i, j);
			return q1 + q2;

		}

	}

	public static boolean isPrime(int x) {
		boolean ret = true;
		if (x == 2 || x == 3 || x == 5 || x == 7 || (x < 1000 && GCD(x, 200560490130l) == 1)) {
			return ret;
		}
		ret &= (GCD(x, 5670694666l) == 1);
		ret &= (GCD(x, 5746942905l) == 1);
		ret &= ((6 * modinverse(3, x)) % x == 2);
		ret &= ((6 * modinverse(2, x)) % x == 3);
		ret &= ((10 * modinverse(5, x)) % x == 2);
		ret &= ((14 * modinverse(7, x)) % x == 2);
		ret &= ((1147 * modinverse(37, x)) % x == 31);
		ret &= ((1147 * modinverse(31, x)) % x == 37);
		ret &= ((39916800 * modinverse(3628800, x)) % x == 11);




		return ret;
	}

	static class Scanner {
		StringTokenizer st;
		BufferedReader br;

		public Scanner(InputStream s) {
			br = new BufferedReader(new InputStreamReader(s));
		}

		public Scanner(FileReader r) {
			br = new BufferedReader(r);
		}

		public String next() throws IOException {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}

		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		public long nextLong() throws IOException {
			return Long.parseLong(next());
		}

		public String nextLine() throws IOException {
			return br.readLine();
		}

		public double nextDouble() throws IOException {
			String x = next();
			StringBuilder sb = new StringBuilder("0");
			double res = 0, f = 1;
			boolean dec = false, neg = false;
			int start = 0;
			if (x.charAt(0) == '-') {
				neg = true;
				start++;
			}
			for (int i = start; i < x.length(); i++)
				if (x.charAt(i) == '.') {
					res = Long.parseLong(sb.toString());
					sb = new StringBuilder("0");
					dec = true;
				} else {
					sb.append(x.charAt(i));
					if (dec)
						f *= 10;
				}
			res += Long.parseLong(sb.toString()) / f;
			return res * (neg ? -1 : 1);
		}

		public long[] id0(int n) throws IOException {
			long[] a = new long[n];
			for (int i = 0; i < n; i++)
				a[i] = nextLong();
			return a;
		}

		public Long[] id17(int n) throws IOException {
			Long[] a = new Long[n];
			for (int i = 0; i < n; i++)
				a[i] = nextLong();
			return a;
		}

		public int[] id8(int n) throws IOException {
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}

		public Integer[] id3(int n) throws IOException {
			Integer[] a = new Integer[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}

		public boolean ready() throws IOException {
			return br.ready();
		}

	}

	static class pair implements Comparable<pair> {
		long x;
		long y;

		public pair(long x, long y) {
			this.x = x;
			this.y = y;
		}

		public String toString() {
			return x + " " + y;
		}

		public boolean equals(Object o) {
			if (o instanceof pair) {
				pair p = (pair) o;
				return p.x == x && p.y == y;
			}
			return false;
		}

		public int hashCode() {
			return new Double(x).hashCode() * 31 + new Double(y).hashCode();
		}

		public int compareTo(pair other) {
			if (this.x == other.x) {
				return Long.compare(this.y, other.y);
			}
			return Long.compare(this.x, other.x);
		}
	}

	static class tuble implements Comparable<tuble> {
		int x;
		int y;
		int z;

		public tuble(int x, int y, int z) {
			this.x = x;
			this.y = y;
			this.z = z;
		}

		public String toString() {
			return x + " " + y + " " + z;
		}

		public int compareTo(tuble other) {
			if (this.x == other.x) {
				if (this.y == other.y) {
					return this.z - other.z;
				}
				return this.y - other.y;
			} else {
				return this.x - other.x;
			}
		}
	}

	public static long GCD(long a, long b) {
		if (b == 0)
			return a;
		if (a == 0)
			return b;
		return (a > b) ? GCD(a % b, b) : GCD(a, b % a);
	}

	public static long LCM(long a, long b) {
		return a * b / GCD(a, b);
	}

	static long Pow(long a, long e, long mod) 

	{
		a %= mod;
		long res = 1l;
		while (e > 0) {
			if ((e & 1) == 1)
				res = (res * a) % mod;
			a = (a * a) % mod;
			e >>= 1l;
		}
		return res;
	}

	public static long modinverse(long a, long mod) {
		return Pow(a, mod - 2, mod);
	}

	static long nc(int n, int r) {
		if (!facc) {
			facc = true;
			fac = new long[1000009];
			fac[0] = 1;
			for (int i = 1; i < 1000009; i++) {
				fac[i] = (fac[i - 1] * i) % mod;
			}
		}
		if (n < r)
			return 0;
		long v = fac[n];
		v *= Pow(fac[r], mod - 2, mod);
		v %= mod;
		v *= Pow(fac[n - r], mod - 2, mod);
		v %= mod;
		return v;
	}

	static long np(int n, int r) {
		return (nc(n, r) * fac[r]) % mod;
	}

	public static boolean isPal(String s) {
		boolean t = true;
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) != s.charAt(s.length() - 1 - i)) {
				t = false;
				break;
			}
		}
		return t;
	}

	public static long RandomPick(long[] a) {
		int n = a.length;
		int r = rn.nextInt(n);
		return a[r];
	}

	public static int RandomPick(int[] a) {
		int n = a.length;
		int r = rn.nextInt(n);
		return a[r];
	}

	static class hash {
		int[] id7;
		boolean reverse;
		int prelen;

		public hash(String s, boolean r) {
			prelen = s.length();
			reverse = r;
			id7 = new int[prelen + 1];
			if (id16 == 0) {
				int[] mods = { 1173017693, 1173038827, 1173069731, 1173086977, 1173089783, 1173092147, 1173107093,
						1173114391, 1173132347, 1173144367, 1173150103, 1173152611, 1173163993, 1173174127, 1173204679,
						1173237343, 1173252107, 1173253331, 1173255653, 1173260183, 1173262943, 1173265439, 1173279091,
						1173285331, 1173286771, 1173288593, 1173298123, 1173302129, 1173308827, 1173310451, 1173312383,
						1173313571, 1173324371, 1173361529, 1173385729, 1173387217, 1173387361, 1173420799, 1173421499,
						1173423077, 1173428083, 1173442159, 1173445549, 1173451681, 1173453299, 1173454729, 1173458401,
						1173459491, 1173464177, 1173468943, 1173470041, 1173477947, 1173500677, 1173507869, 1173522919,
						1173537359, 1173605003, 1173610253, 1173632671, 1173653623, 1173665447, 1173675577, 1173675787,
						1173684683, 1173691109, 1173696907, 1173705257, 1173705523, 1173725389, 1173727601, 1173741953,
						1173747577, 1173751499, 1173759449, 1173760943, 1173761429, 1173762509, 1173769939, 1173771233,
						1173778937, 1173784637, 1173793289, 1173799607, 1173802823, 1173808003, 1173810919, 1173818311,
						1173819293, 1173828167, 1173846677, 1173848941, 1173853249, 1173858341, 1173891613, 1173894053,
						1173908039, 1173909203, 1173961541, 1173968989, 1173999193 };
				mod = RandomPick(mods);
				int[] primes = { 59, 61, 67, 71, 73, 79, 83, 89, 97, 101 };
				prime = RandomPick(primes);
				prepow = new int[1000010];
				prepow[0] = 1;
				for (int i = 1; i < 1000010; i++) {
					prepow[i] = (int) ((1l * prepow[i - 1] * prime) % mod);

				}
			}
			if (!reverse) {

				for (int i = 0; i < prelen; i++) {
					if (s.charAt(i) >= 'a' && s.charAt(i) <= 'z')
						id7[i
								+ 1] = (int) ((1l * id7[i] + ((1l * s.charAt(i) - 'a' + 1) * prepow[i]) % mod)
										% mod);
					else
						id7[i
								+ 1] = (int) ((1l * id7[i] + ((1l * s.charAt(i) - 'A' + 27) * prepow[i]) % mod)
										% mod);
				}

			} else {

				for (int i = 0; i < prelen; i++) {
					if (s.charAt(i) >= 'a' && s.charAt(i) <= 'z')
						id7[i + 1] = (int) ((1l * id7[i]
								+ ((1l * s.charAt(i) - 'a' + 1) * prepow[1000010 - 1 - i]) % mod) % mod);
					else
						id7[i + 1] = (int) ((1l * id7[i]
								+ ((1l * s.charAt(i) - 'A' + 27) * prepow[1000010 - 1 - i]) % mod) % mod);
				}

			}

			id16++;

		}

		public int PHV(int l, int r) {
			if (l > r) {
				return 0;
			}
			int val = (int) ((1l * id7[r] + mod - id7[l - 1]) % mod);
			if (!reverse) {



				val = (int) ((1l * val * prepow[1000010 - l]) % mod);
			} else {



				val = (int) ((1l * val * prepow[r - 1]) % mod);
			}
			return val;
		}
	}

	public static void genprime(int n) {
		boolean prime[] = new boolean[n + 1];
		for (int i = 0; i < n; i++)
			prime[i] = true;

		for (int p = 2; p * p <= n; p++) {
			if (prime[p] == true) {
				for (int i = p * p; i <= n; i += p)
					prime[i] = false;
			}
		}
		for (int i = 2; i <= n; i++) {
			if (prime[i] == true) {
				primes.put(i, primes.size());
				id2.put(id2.size(), i);
			}

		}
	}

	public static long LSB(long x) {
		return x & -x;
	}

	static class fenwick {
		long[] arr;

		public fenwick(PriorityQueue<Integer> a) {
			PriorityQueue<Integer> q = new PriorityQueue<Integer>(a);
			arr = new long[a.size() + 1];
			int i = 1;
			while (!q.isEmpty()) {
				int z = q.poll();
				arr[i] += z;
				if (i + LSB(i) <= a.size()) {
					arr[(int) (i + LSB(i))] += arr[i];
				}
				i++;
			}
		}

		public fenwick(TreeSet<Integer> a) {
			arr = new long[a.size() + 1];
			int i = 1;
			for (int h : a) {
				arr[i] += h;
				if (i + LSB(i) <= a.size()) {
					arr[(int) (i + LSB(i))] += arr[i];
				}
				i++;
			}
		}

		public fenwick(Integer a) {
			arr = new long[a];

		}

		public fenwick(Integer[] a) {
			arr = new long[a.length + 1];
			for (int i = 1; i <= a.length; i++) {
				arr[i] += a[i - 1];
				if (i + LSB(i) <= a.length) {
					arr[(int) (i + LSB(i))] += arr[i];
				}
			}
		}

		public fenwick(int[] a) {
			arr = new long[a.length + 1];
			for (int i = 1; i <= a.length; i++) {
				arr[i] += a[i - 1];
				if (i + LSB(i) <= a.length) {
					arr[(int) (i + LSB(i))] += arr[i];
				}
			}
		}

		public fenwick(long[] a) {
			arr = new long[a.length + 1];
			for (int i = 1; i <= a.length; i++) {
				arr[i] += a[i];
				if (i + LSB(i) <= a.length) {
					arr[(int) (i + LSB(i))] += arr[i];
				}
			}
		}

		public void update(int ind, long x) {
			int i = ind;
			while (i < arr.length) {
				arr[i] += x;
				i += LSB(i);
			}
		}

		public long PrefixSum(int ind) {
			long sum = 0;
			int i = ind;
			while (i > 0) {
				sum += arr[i];
				i = (int) (i - LSB(i));
			}
			return sum;
		}

		public long id9(int l, int r) {
			return this.PrefixSum(r + 1) - this.PrefixSum(l);
		}

		public long id11(int k) {
			long max = Long.MIN_VALUE;
			for (int i = k - 1; i < arr.length - 1; i++) {

				max = Math.max(max, this.id9(i - k + 1, i));

			}
			return max;
		}

		public long id14(int k) {
			long min = Long.MAX_VALUE;

			for (int i = k - 1; i < arr.length - 1; i++) {

				min = Math.min(min, this.id9(i - k + 1, i));

			}
			return min;
		}

		public long value(int ind) {
			return arr[ind];
		}
	}

	static void id6(int N) {
		ArrayList<Integer> primes = new ArrayList<Integer>();
		lp = new int[N + 1]; 

		for (int i = 2; i <= N; ++i) {
			if (lp[i] == 0) {
				primes.add(i);
				lp[i] = i;
			}
			int curLP = lp[i];
			for (int p : primes)

				if (p > curLP || p * 1l * i > N)
					break;
				else
					lp[p * i] = p;
		}
	}

	public static void id13(int n) {
		int x = n;
		while (x > 1) {
			int id4 = lp[x];
			while (x % id4 == 0) {
				id12.add(id4);
				x /= id4;
			}
		}
	}

	public static class SuffixArray {

		int[] SA;
		int[] AS;
		String SS;

		public SuffixArray(String S) 

		{
			SS = S;
			char[] s = new char[S.length() + 1];
			for (int i = 0; i < S.length(); i++) {
				s[i] = S.charAt(i);
			}
			s[S.length()] = '$';
			int n = s.length, RA[] = new int[n];
			SA = new int[n];

			for (int i = 0; i < n; ++i) {
				RA[i] = s[i];
				SA[i] = i;
			}

			for (int k = 1; k < n; k <<= 1) {
				sort(SA, RA, n, k);
				sort(SA, RA, n, 0);
				int[] tmp = new int[n];

				for (int i = 1, r = 0, s1 = SA[0], s2; i < n; ++i) {
					s2 = SA[i];
					tmp[s2] = RA[s1] == RA[s2] && RA[s1 + k] == RA[s2 + k] ? r : ++r;
					s1 = s2;
				}
				for (int i = 0; i < n; ++i)
					RA[i] = tmp[i];

				if (RA[SA[n - 1]] == n - 1)
					break;
			}
			AS = new int[SA.length];
			for (int i = 0; i < SA.length; i++) {
				AS[SA[i]] = i;
			}
		}

		public String toString() {

			return Arrays.toString(SA);
		}

		public int get(int n) {
			return SA[n];
		}

		public int Substring(String s) { 

			int low = 0;
			int high = SA.length;
			int mid = (low + high) / 2;
			int ind = -1;

			while (low < high - 1) {

				if (SS.length() - SA[mid] < s.length()) {

					boolean less = false;
					for (int i = SA[mid]; i < SS.length(); i++) {
						if (SS.charAt(i) > s.charAt(i - SA[mid])) {
							less = true;
							break;
						}
						if (SS.charAt(i) < s.charAt(i - SA[mid])) {
							less = false;
							break;
						}
					}
					if (!less) {
						low = mid;
					} else {
						high = mid;
					}
				} else {
					boolean less = true;
					boolean equal = true;
					for (int i = SA[mid]; i < SA[mid] + s.length(); i++) {
						if (SS.charAt(i) < s.charAt(i - SA[mid]) && equal) {
							less = false;
							equal = false;
							break;
						}
						if (SS.charAt(i) != s.charAt(i - SA[mid])) {
							equal = false;
						}
					}
					if (equal) {
						ind = SA[mid];
					}
					if (!less) {
						low = mid;
					} else {
						high = mid;
					}
				}

				mid = (low + high) / 2;
			}
			return ind;
		}

		public int LastSubstring(String s) { 

			int low = 0;
			int high = SA.length;
			int mid = (low + high) / 2;
			int ind = -1;

			while (low < high - 1) {

				if (SS.length() - SA[mid] < s.length()) {

					boolean less = true;
					for (int i = SA[mid]; i < SS.length(); i++) {
						if (SS.charAt(i) < s.charAt(i - SA[mid])) {
							break;
						}
						if (SS.charAt(i) > s.charAt(i - SA[mid])) {
							less = false;
							break;
						}
					}
					if (less) {
						low = mid;
					} else {
						high = mid;
					}
				} else {
					boolean less = true;
					boolean equal = true;
					for (int i = SA[mid]; i < SA[mid] + s.length(); i++) {
						if (SS.charAt(i) > s.charAt(i - SA[mid]) && equal) {
							less = false;
							equal = false;
							break;
						}
						if (SS.charAt(i) != s.charAt(i - SA[mid])) {
							equal = false;
						}
					}
					if (equal) {
						ind = SA[mid];
					}
					if (less) {
						low = mid;
					} else {
						high = mid;
					}
				}

				mid = (low + high) / 2;
			}
			return ind;
		}

		public int CountSubstring(String s) {
			int z = LastSubstring(s);
			if (z == -1)
				return 0;
			return AS[z] - AS[Substring(s)] + 1;
		}

		public void sort(int[] SA, int[] RA, int n, int k) {
			int maxi = Math.max(256, n), c[] = new int[maxi];
			for (int i = 0; i < n; ++i)
				c[i + k < n ? RA[i + k] : 0]++;
			for (int i = 0, sum = 0; i < maxi; ++i) {
				int t = c[i];
				c[i] = sum;
				sum += t;
			}
			int[] tmp = new int[n];
			for (int i = 0; i < n; ++i) {
				int j = SA[i] + k;
				tmp[c[j < n ? RA[j] : 0]++] = SA[i];
			}

			for (int i = 0; i < n; ++i)
				SA[i] = tmp[i];
		}
	}

	public static class UnionFind {
		int[] p, rank, setSize;
		int numSets;

		public UnionFind(int N) {
			p = new int[numSets = N];
			rank = new int[N];
			setSize = new int[N];
			for (int i = 0; i < N; i++) {
				p[i] = i;
				setSize[i] = 1;
			}
		}

		public int findSet(int i) {
			return p[i] == i ? i : (p[i] = findSet(p[i]));
		}

		public boolean id10(int i, int j) {
			return findSet(i) == findSet(j);
		}

		public void unionSet(int i, int j) {
			if (id10(i, j))
				return;
			numSets--;
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]) {
				p[y] = x;
				setSize[x] += setSize[y];
			} else {
				p[x] = y;
				setSize[y] += setSize[x];
				if (rank[x] == rank[y])
					rank[y]++;
			}
		}

		public int id18() {
			return numSets;
		}

		public int id5(int i) {
			return setSize[findSet(i)];
		}
	}

	static LinkedList<Integer> id12 = new LinkedList<>();
	static TreeMap<Integer, Integer> primes = new TreeMap<Integer, Integer>();
	static TreeMap<Integer, Integer> id2 = new TreeMap<Integer, Integer>();
	static int[] lp;

	static int id16 = 0;
	static int[] prepow;
	static int prime = 61;
	static long fac[];
	static boolean facc;
	static long mod = 1000000007;
	static Random rn = new Random();
	static Scanner sc = new Scanner(System.in);
	static PrintWriter pw = new PrintWriter(System.out);
}