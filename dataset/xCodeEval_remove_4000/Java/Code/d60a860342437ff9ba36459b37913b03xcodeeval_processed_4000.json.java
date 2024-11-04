	import java.io.*;
	import java.math.BigInteger;
	import java.util.*;
	
	import javax.sound.midi.Synthesizer;
import javax.swing.plaf.synth.SynthSpinnerUI;

	
	
	public class Main
	{
		private InputStream is;
		private PrintWriter out;
		int time = 0, freq[], start[], end[], dist[], black[], MOD = (int) (1e9 + 7), arr[], weight[][], x[], y[], parent[];
		int MAX = 1000001, N, K;
		long red[];
		int ans = 0;
	
		ArrayList<Integer>[] amp;
		ArrayList<Pair>[] pmp;
		boolean b[];
		boolean boo[][], b1[];
		Pair prr[];
		HashMap<Pair, Integer> hm = new HashMap();
		int Dp[][] = new int[1100][1100];
	
		void soln() 
		{
			is = System.in;
			out = new PrintWriter(System.out);
			long s = System.currentTimeMillis();
			solve();
			

			
			out.flush();
			

		}
		
		 class ST1 

		{
			int arr[], st[];
			int size;
			
			ST1(int a[]) {
				arr = a.clone();
				size = 10 * arr.length;
				st = new int[size];
				build(0, arr.length - 1, 1);
			}
	
			void build(int ss, int se, int si) {
				if (ss == se) {
					st[si] = arr[ss];
					return;
				}
				int mid = (ss + se) / 2;
				int val = 2 * si;
				build(ss, mid, val);
				build(mid + 1, se, val + 1);
				st[si] = gcd(st[val], st[val + 1]);
			}
	
			
	
			int get(int ss, int se, int l, int r, int si) {
				if (l > se || r < ss || l > r)
					return 0;
				if (l <= ss && r >= se)
					return st[si];
				int mid = (ss + se) / 2;
				int val = 2 * si;
				return gcd(get(ss, mid, l, r, val), get(mid + 1, se, l, r, val + 1));
			}
		}
	
		public static void main(String[] args) throws Exception
		{
			new Thread(null, new Runnable() 
			{
				public void run() 
				{
					try 
					{
						

					} catch (Exception e) 
					{
						System.out.println(e);
					}
				}
			}, "1", 1 << 26).start();
			new Main().soln();
		}
	
		int D[][];
		char ch[][], ch1[];
		int hash = 29;
		int x2, y2;
		HashSet<Integer>[] hs = (HashSet<Integer>[]) new HashSet[110];
		cell[] c;
		 boolean ar[] = new boolean[1000];
		Pair[] p = new Pair[4];
		 int a1[] = new int[7];
		 int a2[] = new int[7];
		 int a3[] = new int[7];
		 int a4[] = new int[7];
		 private static class Comp implements Comparable<Comp>{
				int ind;
				BigInteger v;

				@Override
				public int compareTo(Comp arg0) {
					if(v==arg0.v)
						return this.ind-arg0.ind;
					return this.v.compareTo(arg0.v);
				}
			}
		 private static class Comp1 implements Comparable<Comp1>{
				int ind;
				String v;

				@Override
				public int compareTo(Comp1 arg0) {
					if(v.equals(arg0.v))
						return this.ind-arg0.ind;
					return this.v.compareTo(arg0.v);
				}
			}
		 int n1, n2;
		 int max = 9000000;
		 void solve()
		 {
			 int n = ni();
			 int arr[] = new int[n+1];
			 for(int i = 1;i<=n;i++) arr[i] = ni();
			 int cnt = 0;
			 int j = 1;
			 while(j<=n) {
				 while(arr[j]!=j) {
					 int temp = arr[j];
					 arr[j] = arr[temp];
					 arr[temp] = temp;
					 cnt++;
				 }
				 j++;
			 }
			 

			 if(n%2 == cnt%2) System.out.println("Petr");
			 else System.out.println("Um_nik");
		 }
		 void seive() {
			 b = new boolean[5000000];
			 for(int i = 2;i<5000000;i++) {
				 if(!b[i]) {
					 for(int j = 2*i;j<5000000;j+=i) {
					 b[j] = true;
				 }
				 }
			 }
		 }
		 void time(int x) {
			 if((n2-x)<0) {
				 n1--;
				 n2 = (n2-x+60)%60;
			 }
			 else {
				 n2 -= x;
			 }
			 n1 = (n1+24)%24;
		 }
		 boolean check(int x, int y) {
			 if(Integer.toString(x).contains("7") || Integer.toString(y).contains("7")) return true;
			 return false;
		 }
		 void dfs(int x, int dis) {
			 Queue<Integer> q = new LinkedList<Integer>();
			 b[x] = true;
			 dist[x] = dis;
			 q.add(x);
			 while(!q.isEmpty()) {
				 x = q.poll();
			 for(int i : amp[x]) {
				 	dist[i] = min(dist[i],dist[x]+1);
				 	if(!b[i]) {
				 		b[i] = true;
				 		q.add(i);
				 	}
			 	}
			 }
		 }
		 String check(String[] s) {
			 char ch[] = new char[] {'a','a','a','a'};
			 boolean b = false;
			 for(int i = 0;i<4;i++) {
				 if(i>0) {
					 if(ch[i]=='a') continue;
				 }
				 for(int j = i+1;j<4;j++) {
					 if(!s[i].equals(s[j])) {
						 if(ch[i] == 'a' && ch[j]=='a') ch[j] = 'b';
						 else if(ch[j]=='a') continue;
						 else {
							 System.out.println("NO");
							 System.exit(0);
						 }
					 }
					 else b = true;
				 }
			 }
			 return new String(ch);
		 }
		 boolean id1(char c) {
			 if(c=='a' || c=='e' ||c=='i' ||c=='o' ||c=='u' ) return true;
					 return false;
		 }
		 void id2(int[] a1, int[] a2) {
			 for(int i = 1; i< 7;i++) {
				 for(int j = 1; j< 7;j++) {
					 ar[a1[i]*10+a2[j]] = true;
					 ar[a2[j]*10+a1[i]] = true;
				 }
			 }
		 }
		boolean binaryS(int a, int b, int c, int d) {
			double l = 0, r = 90;
			for(int count = 0;count<=300;count++)
			{
				double mid = (l + r) / 2;
				double temp = mid * Math.PI / 180;
				double x1 = Math.cos(temp) * c;
				double x2 = Math.sin(temp) * c;
				temp = Math.PI / 2 - temp;
				double y1 = Math.cos(temp) * d;
				double y2 = Math.sin(temp) * d;
				if ((x1 + y1 <= a) && (x2 + y2 <= b)) return true;
				else if (x1 + y1 > a) l = mid;
				else r = mid;
			}
			return false;
		}
		
		boolean check(String s, String s1) {
			char ch1[] = s.toCharArray(), ch2[] = s1.toCharArray();
			int arr[] = new int[10];
			for(char c : ch1) {
				arr[c-'0']++;
			}
			int ans = 0;
			for(char c:ch2) {
				arr[c-'0']--;
			}
			
			for(int i:arr) ans += ((i>0)?i:0);
			return ans==3;
		}
		void seive(int n)
		{
			start = new int[n];
			for(int i = 2;i<n;i++) {
				if(start[i]==0) {
					for(int j = 2*i;j<n;j+=i) {
						start[j] = i;
					}
				}
			}
		}
		void print(int[][] arr) 
		{
			int seed = 110, n = arr.length - 220;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					System.out.print(arr[i + seed][j + seed] + " ");
				}
				System.out.println();
			}
			System.out.println();
		}
	
		 class cell implements Comparable<cell>
		 {
			int s, d, p, i;
	
			cell(int t, int d, int p, int i) {
				this.s = t;
				this.p = p;
				this.d = d;
				this.i = i;
			}
	
			public int compareTo(cell other) {
				

				return Long.compare(d, other.d) != 0 ? (Long.compare(d, other.d)): (Long.compare(i,other.i));
												

												

				

				

			}
	
			public String toString() {
				return this.d + " " + this.s +" "+this.p+" "+this.i;
			}
		}
	
		int abs(int x)
		{
			return ((x > 0) ? x : -x);
		}
	
		long ret(int p) 
		{
			if (p >= 0)
				return 0;
			else
				return 1;
		}
	
		long val(int p, int a, int b) 
		{
			if (p >= 0) {
				return (a * 1l * p);
			}
			return (b * 1l * p);
		}
	
		
	
	
		public int getParent(int x) 
		{
			while (parent[x] != x) {
				parent[x] = parent[parent[x]];
				x = parent[x];
			}
			return x;
		}
	
		void getFactors(int n, int x)
		{
			for (int i = 1; i * i <= n; i++) {
				if (n % i == 0) {
					hs[x].add(i);
					hs[x].add(n / i);
				}
			}
		}
	
		void recur(int a, int b, int k) 
		{
			if (k == 0) {
				if (a == x2 && b == y2)
					ans++;
				return;
			}
			recur(a, b + 1, k - 1);
			recur(a, b - 1, k - 1);
			recur(a + 1, b, k - 1);
			recur(a - 1, b, k - 1);
		}
	
		int min(int a, int b) 
		{
			return (a < b) ? a : b;
		}
	
		

		
		class Pair implements Comparable<Pair>
		{
			int u ,v,i;
	
			Pair(int u, int v) {
				this.u = u;
				this.i = v;
			}
	
			Pair(int u, int v, int i) {
				this.u = u;
				this.v = v;
				this.i = i;
			}
	
			public int hashCode() {
				return Objects.hash();
			}
	
			public boolean equals(Object o) {
				Pair other = (Pair) o;
				return ((u == other.u && v == other.v));
			}
	
			public int compareTo(Pair other) {
				

				return Long.compare(u, other.u) != 0 ? (Long.compare(u, other.u)) : (Long.compare(i, other.i));

			
			}									
			public String toString() {
				return this.u + " " + this.v +" "+this.i;
			}
		}
	
		int max(int a, int b) 
		{
			if (a > b)
				return a;
			return b;
		}
	
		static class id4 
		{
	
			int[] array; 

							

							

	
			public id4(int size) {
				array = new int[size + 1];
			}
	
			public int rsq(int ind) {
				assert ind > 0;
				int sum = 0;
				while (ind > 0) {
					sum += array[ind];
					

					

					

					ind -= ind & (-ind);
				}
				return sum;
			}
	
			public int rsq(int a, int b) {
				assert b >= a && a > 0 && b > 0;
				return rsq(b) - rsq(a - 1);
			}
	
			public void update(int ind, int value) {
				assert ind > 0;
				while (ind < array.length) {
					array[ind] += value;
					

					

					

					ind += ind & (-ind);
				}
			}
	
			public int size() {
				return array.length - 1;
			}
		}
		void buildGraph(int n)
		{
			for (int i = 0; i < n; i++) {
				int x1 = ni(), y1 = ni();
				amp[x1-1].add(y1-1);
				amp[y1-1].add(x1-1);
			}
		}
		long modInverse(long a, long id3)
		{
			return power(a, id3 - 2, id3);
		}
	
		long power(long x, long y, long m) 
		{
			if (y == 0)
				return 1;
			long p = power(x, y / 2, m) % m;
			p = (p * p) % m;
	
			return (y % 2 == 0) ? p : (x * p) % m;
		}
	
		public int gcd(int a, int b)
		{
			if (b == 0)
				return a;
			return gcd(b, a % b);
		}
	
		
	
		public static int[] shuffle(int[] a, Random gen)
		{
			for (int i = 0, n = a.length; i < n; i++) {
				int ind = gen.nextInt(n - i) + i;
				int d = a[i];
				a[i] = a[ind];
				a[ind] = d;
			}
			return a;
		}
	
		long power(long x, long y, int mod)
		{
			long ans = 1;
			while (y > 0) {
				if (y % 2 == 0) {
					x = (x * x) % mod;
					y /= 2;
				} else {
					ans = (x * ans) % mod;
					y--;
				}
			}
			return ans;
		}
	
		

		

		private byte[] inbuf = new byte[1024];
		public int lenbuf = 0, ptrbuf = 0;
	
		private int readByte() 
		{
			if (lenbuf == -1)
				throw new InputMismatchException();
			if (ptrbuf >= lenbuf) {
				ptrbuf = 0;
				try {
					lenbuf = is.read(inbuf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (lenbuf <= 0)
					return -1;
			}
			return inbuf[ptrbuf++];
		}
	
		private boolean id0(int c) {
			return !(c >= 33 && c <= 126);
		}
	
		private int skip() {
			int b;
			while ((b = readByte()) != -1 && id0(b))
				;
			return b;
		}
	
		private double nd() {
			return Double.parseDouble(ns());
		}
	
		private char nc() {
			return (char) skip();
		}
	
	
		private String ns()
		{
			int b = skip();
			StringBuilder sb = new StringBuilder();
			while (!(id0(b)))
			{ 

										

				sb.appendCodePoint(b);
				b = readByte();
			}
			return sb.toString();
		}
		
		private char[] ns(int n) {
			char[] buf = new char[n];
			int b = skip(), p = 0;
			while (p < n && !(id0(b))) {
				buf[p++] = (char) b;
				b = readByte();
			}
			return n == p ? buf : Arrays.copyOf(buf, p);
		}
	
		private char[][] nm(int n, int m) {
			char[][] map = new char[n][];
			for (int i = 0; i < n; i++)
				map[i] = ns(m);
			return map;
		}
	
		private int[] na(int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = ni();
			return a;
		}
	
		private int ni() {
			int num = 0, b;
			boolean minus = false;
			while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'))
				;
			if (b == '-') {
				minus = true;
				b = readByte();
			}
	
			while (true) {
				if (b >= '0' && b <= '9') {
					num = num * 10 + (b - '0');
				} else {
					return minus ? -num : num;
				}
				b = readByte();
			}
		}
	
		private long nl() {
			long num = 0;
			int b;
			boolean minus = false;
			while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'))
				;
			if (b == '-') {
				minus = true;
				b = readByte();
			}
	
			while (true) {
				if (b >= '0' && b <= '9') {
					num = num * 10 + (b - '0');
				} else {
					return minus ? -num : num;
				}
				b = readByte();
			}
		}
	
		private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	
		private void tr(Object... o) {
			if (!oj)
				System.out.println(Arrays.deepToString(o));
		}
	}