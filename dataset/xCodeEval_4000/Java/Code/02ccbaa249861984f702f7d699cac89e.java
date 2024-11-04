import java.io.*;
import java.util.*;
	
	public class CODEFORCES
	{
		private InputStream is;
		private PrintWriter out;
		int time = 0, DP[], start[], end[], dist[], black[], MOD = (int) (1e9 + 7),
				arr[], weight[][], x[], y[], parent[];
		int MAX = 1000000, N, K;
		long red[];
		ArrayList<Character>[] amp;
		ArrayList<Pair>[][] pmp;
		boolean b[], boo[][];
		Pair prr[];
		HashMap<Pair, Integer> hm = new HashMap();
		long Dp[][][][] = new long[110][110][12][12];
	
		void soln()
		{
			is = System.in;
			out = new PrintWriter(System.out);
			long s = System.currentTimeMillis();
			solve();
			

			out.flush();
			

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
			new CODEFORCES().soln();
		}
	
		int ans = 0, cost = 0, D[][];
		char ch[], ch1[];
		

		int hash = 29;
		

		

		

		

		

		TreeSet<Cell> ts;
		int prime[] = new int[100000];
		void solve()
		{
			String s = ns();
			char ch[] = s.toCharArray();
			int n = ch.length;
			if(n<=2){
				System.out.println(s);
				return;
			}
			StringBuilder sb = new StringBuilder();
			boolean b[] = new boolean[100*n];
			for(char c = 'a';c<='z';c++){
			    if(!isCons(c)) continue;
				for(int i = 0; i<n;i++){
					int cnt = 0;
					int temp = i;
					while(i<n && ch[i]==c){
						i++;
						cnt++;
					}
					if(cnt>2){
						if(temp>0 && isCons(ch[temp-1]))
						b[temp] = true;
						if(i<n && isCons(ch[i])) b[i] = true;
					}
				}
			}
			for(int i = 0; i< n; i++){
				if(b[i]) sb.append(' ');
				sb.append(ch[i]);
			}
			

			char ch2[] = sb.toString().toCharArray();
			sb = new StringBuilder();
			sb.append(ch2[0]);sb.append(ch2[1]);
			for(int i = 2; i<ch2.length;i++){
				if(isCons(ch2[i]) && isCons(sb.charAt(sb.length()-1)) && isCons(sb.charAt(sb.length()-2)) && (ch2[i]!=sb.charAt(sb.length()-1)||ch2[i]!=sb.charAt(sb.length()-2))){
					sb.append(' ');
				}
				sb.append(ch2[i]);
			}
			
			System.out.println(sb);
		}
		boolean isCons(char ch){
			if(ch!='a' && ch!='e' && ch!='i' && ch!='o' && ch!='u' && ch!=' ') return true;
			return false; 
		}
		int dp[][] = new int[1000][1000];
		
		void seive(int x){
			b = new boolean[x+1];
			for(int i = 2;i*i<=x;i++){
				if(!b[i]){
					for(int j = 2*i;j<=x;j+=i) b[j] = true;
				}
			}
		}
		long[][] matMul(long a[][] , long b[][], int n)
		{
			long res[][] = new long[n][n];
			for(int i = 0;i<n;i++){
				for(int j = 0;j<n;j++){
					long sum = 0;
					for(int k = 0;k<n;k++){
						sum += (a[i][k]*1l*b[k][j]);
						sum %= MOD;
					}
					res[i][j] = sum;
				}
			}
			return res;
		}
		int min(int a, int b)
		{
			return (a<b)?a:b;
		}
		private class Cell implements Comparable<Cell>
		{
			int u, v, s;
			public Cell(int u, int v, int s) 
			{
				this.u = u;
				this.v = v;
				this.s = s;
			}
			public int hashCode() 
			{
				return Objects.hash();
			}
			public int compareTo(Cell other) 
			{
				return (Long.compare(s, other.s) != 0 ? (Long.compare(s, other.s)):(Long.compare(v, other.v)!=0?Long.compare(v, other.v):Long.compare(u, other.u)))
						&((Long.compare(s, other.s) != 0 ? (Long.compare(s, other.s)):(Long.compare(u, other.v)!=0?Long.compare(u, other.v):Long.compare(v, other.u))));
			}
			public String toString()
			{
				return this.u + " " + this.v;
			}
		}
	
		class Pair implements Comparable<Pair>
		{
			int u, v, i;
	
			Pair(int u, int v) 
			{
				this.u = u;
				this.v = v;
			}
	
			Pair() 
			{
	
			}
	
			Pair(int u, int v, int i) 
			{
				this.u = u;
				this.v = v;
				this.i = i;
			}
	
			public int hashCode()
			{
				return Objects.hash();
			}
	
			public boolean equals(Object o)
			{
				Pair other = (Pair) o;
				return ((u == other.u && v == other.v) | ((u == other.v && v == other.u)));
			}
	
			public int compareTo(Pair other)
			{
				

				return Long.compare(u, other.u) != 0 ? (Long.compare(u, other.u)): (Long.compare(v, other.v));
						

			}
	
			public String toString()
			{
				return this.u + " " + this.v;
			}
		}
	
		int max(int a, int b) 
		{
			if (a > b)
				return a;
			return b;
		}
	
		public static class FenwickTree 
		{
	
			int[] array; 

							

							

	
			public FenwickTree(int size) 
			{
				array = new int[size + 1];
			}
	
			public int rsq(int ind)
			{
				assert ind > 0;
				int sum = 0;
				while (ind > 0)
				{
					sum += array[ind];
					

					

					

					ind -= ind & (-ind);
				}
				return sum;
			}
	
			public int rsq(int a, int b) 
			{
				assert b >= a && a > 0 && b > 0;
				return rsq(b) - rsq(a - 1);
			}
	
			public void update(int ind, int value)
			{
				assert ind > 0;
				while (ind < array.length) 
				{
					array[ind] += value;
					

					

					

					ind += ind & (-ind);
				}
			}
	
			public int size() 
			{
				return array.length - 1;
			}
		}
	
		void buildGraph(int n) 
		{
			for (int i = 0; i < n; i++) 
			{
				int x1 = ni() - 1, y1 = ni() - 1, z = ni();
				ts.add(new Cell(x1,y1,z));
				hm.put(new Pair(x1,y1), z);
				ans += z;
			}
		}
	
		long modInverse(long a, long mOD2) 
		{
			return power(a, mOD2 - 2, mOD2);
		}
	
		long power(long x, long y, long m) 
		{
			if (y == 0)
				return 1;
			long p = power(x, y / 2, m) % m;
			p = (p * p) % m;
	
			return (y % 2 == 0) ? p : (x * p) % m;
		}
	
		public long gcd(long a, long b) 
		{
			if (b == 0)
				return a;
			return gcd(b, a % b);
		}
	
		static class ST1 
		{
			int arr[], st[], size;
	
			
			ST1(int a[]) 
			{
				arr = a.clone();
				size = 10 * arr.length;
				st = new int[size];
				build(0, arr.length - 1, 1);
			}
	
			void build(int ss, int se, int si) 
			{
				if (ss == se)
				{
					st[si] = arr[ss];
					return;
				}
				int mid = (ss + se) / 2;
				int val = 2 * si;
				build(ss, mid, val);
				build(mid + 1, se, val + 1);
				st[si] = Math.min(st[val], st[val + 1]);
			}
	
			int get(int ss, int se, int l, int r, int si) 
			{
				if (l > se || r < ss || l > r)
					return Integer.MAX_VALUE;
				if (l <= ss && r >= se)
					return st[si];
				int mid = (ss + se) / 2;
				int val = 2 * si;
				return Math.min(get(ss, mid, l, r, val),
						get(mid + 1, se, l, r, val + 1));
			}
		}
	
		static class ST 
		{
			int arr[], lazy[], n;
	
			ST(int a) 
			{
				n = a;
				arr = new int[10 * n];
				lazy = new int[10 * n];
			}
	
			void up(int l, int r, int val)
			{
				update(0, n - 1, 0, l, r, val);
			}
	
			void update(int l, int r, int c, int x, int y, int val)
			{
				if (lazy[c] != 0) {
					lazy[2 * c + 1] += lazy[c];
					lazy[2 * c + 2] += lazy[c];
					if (l == r)
						arr[c] += lazy[c];
					lazy[c] = 0;
				}
				if (l > r || x > y || l > y || x > r)
					return;
				if (x <= l && y >= r) 
				
				{
					lazy[c] += val;
					return;
				}
				int mid = l + r >> 1;
				update(l, mid, 2 * c + 1, x, y, val);
				update(mid + 1, r, 2 * c + 2, x, y, val);
				arr[c] = Math.max(arr[2 * c + 1], arr[2 * c + 2]);
			}
	
			int an(int ind) 
			{
				return ans(0, n - 1, 0, ind);
			}
	
			int ans(int l, int r, int c, int ind) 
			{
				if (lazy[c] != 0) 
				{
					lazy[2 * c + 1] += lazy[c];
					lazy[2 * c + 2] += lazy[c];
					if (l == r)
						arr[c] += lazy[c];
					lazy[c] = 0;
				}
				if (l == r)
					return arr[c];
				int mid = l + r >> 1;
				if (mid >= ind)
					return ans(l, mid, 2 * c + 1, ind);
				return ans(mid + 1, r, 2 * c + 2, ind);
			}
		}
	
		public static int[] shuffle(int[] a, Random gen)
		{
			for (int i = 0, n = a.length; i < n; i++)
			{
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
			while (y > 0) 
			{
				if (y % 2 == 0) 
				{
					x = (x * x) % mod;
					y /= 2;
				} else 
				{
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
			if (ptrbuf >= lenbuf) 
			{
				ptrbuf = 0;
				try 
				{
					lenbuf = is.read(inbuf);
				} catch (IOException e)
				{
					throw new InputMismatchException();
				}
				if (lenbuf <= 0)
					return -1;
			}
			return inbuf[ptrbuf++];
		}
	
		private boolean isSpaceChar(int c) 
		{
			return !(c >= 33 && c <= 126);
		}
	
		private int skip() 
		{
			int b;
			while ((b = readByte()) != -1 && isSpaceChar(b))
				;
			return b;
		}
	
		private double nd() 
		{
			return Double.parseDouble(ns());
		}
	
		private char nc() 
		{
			return (char) skip();
		}
	
		private String ns()
		{
			int b = skip();
			StringBuilder sb = new StringBuilder();
			while (!(isSpaceChar(b)))
			{ 

										

				sb.appendCodePoint(b);
				b = readByte();
			}
			return sb.toString();
		}
	
		private char[] ns(int n) 
		{
			char[] buf = new char[n];
			int b = skip(), p = 0;
			while (p < n && !(isSpaceChar(b)))
			{
				buf[p++] = (char) b;
				b = readByte();
			}
			return n == p ? buf : Arrays.copyOf(buf, p);
		}
	
		private char[][] nm(int n, int m)
		{
			char[][] map = new char[n][];
			for (int i = 0; i < n; i++)
				map[i] = ns(m);
			return map;
		}
	
		private int[] na(int n)
		{
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = ni();
			return a;
		}
	
		private int ni() 
		{
			int num = 0, b;
			boolean minus = false;
			while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'))
				;
			if (b == '-')
			{
				minus = true;
				b = readByte();
			}
	
			while (true) 
			{
				if (b >= '0' && b <= '9') 
				{
					num = num * 10 + (b - '0');
				} else 
				{
					return minus ? -num : num;
				}
				b = readByte();
			}
		}
	
		private long nl() 
		{
			long num = 0;
			int b;
			boolean minus = false;
			while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'))
				;
			if (b == '-') 
			{
				minus = true;
				b = readByte();
			}
	
			while (true) 
			{
				if (b >= '0' && b <= '9') 
				{
					num = num * 10 + (b - '0');
				} else 
				{
					return minus ? -num : num;
				}
				b = readByte();
			}
		}
	
		private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	
		private void tr(Object... o) 
		{
			if (!oj)
				System.out.println(Arrays.deepToString(o));
		}
	}