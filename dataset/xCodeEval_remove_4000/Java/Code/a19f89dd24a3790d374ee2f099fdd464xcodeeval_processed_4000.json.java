import java.io.*;
import java.util.*;

public class Main
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
		new Main().soln();
	}

	int ans = 0, cost = 0, D[][];
	char ch[], ch1[];
	int hash = 29;
	TreeSet<Cell> ts;
	int x2, y2;
	HashSet<Integer>[] hs = (HashSet<Integer>[]) new HashSet[110];
	void solve()
	{
		int n = ni(), m = ni(), k = ni();
		int arr[][] = new int[MAX][4];
		int min[] = new int[MAX+10];
		Arrays.fill(min, 10000000);
		int max[] = new int[MAX+10];
		for(int i = 0; i< m; i++){
			for(int j = 0; j<4;j++) arr[i][j] = ni();
			if(arr[i][1]!=0)
			min[arr[i][1]] = min(min[arr[i][1]],arr[i][0]);
			else max[arr[i][2]] = max(max[arr[i][2]],arr[i][0]);
		}
		ArrayList<Flight>[] amp = new ArrayList[MAX+10];
		for(int i = 0; i<MAX+10;i++) amp[i] = new ArrayList<Flight>();
		TreeSet<Flight>[] ts = new TreeSet[MAX+10];
		for(int i = 0; i<n+10;i++) ts[i] = new TreeSet<Flight>();
		for(int i = 0; i< m;i++){
			amp[arr[i][0]].add(new Flight(arr[i][1],arr[i][2],arr[i][3]));
		}
		int mf = 0, ma = 1000000000;
		for(int i = 1; i<=n;i++){
			

			mf = max(mf,min[i]);
			ma = min(ma,max[i]);
		}
		

		if((ma-mf-1)<k){
			System.out.println(-1);
		}
		else{
			long cost = 0, fa = Long.MAX_VALUE;
			int y[] = new int[MAX+10];
			Arrays.fill(y, 1000000000);
			int z[] = new int[MAX+10];
			Arrays.fill(z, 1000000000);
			for(int i = 0; i<m;i++){
				if(arr[i][0]<=mf && arr[i][1]!=0){
					y[arr[i][1]] = min(y[arr[i][1]],arr[i][3]);
					

				}
				else if(arr[i][0]>(mf+k) && arr[i][1]==0){
					z[arr[i][2]] = min(z[arr[i][2]],arr[i][3]);
					ts[arr[i][2]].add(new Flight(arr[i][1],arr[i][2],arr[i][3]));
				}
			}
			for(int i = 1; i<=n;i++){
				

				cost += (y[i]+z[i]);
			}
			fa = cost;
			

			for(int j = mf+1;j<=(ma-k-1);j++){
				for(int l = 0; l<amp[j].size();l++){
					Flight f = amp[j].get(l);
					int a1 = f.f, a3 = f.c;
					if(a1!=0){
						cost-=y[a1];
						y[a1] = min(y[a1],a3);
						cost+=y[a1];
					}
				}
				for(int l = 0; l<amp[j+k].size();l++){
					Flight f = amp[j+k].get(l);
					

					int a1 = f.f, a2 = f.s;
					if(a1==0){
						cost-=z[a2];
						ts[a2].remove(f);
						z[a2] = ts[a2].first().c;
						cost+=z[a2];
					}
				}
				fa = Math.min(fa, cost);
				

			}
			System.out.println(fa);
		}
	}
	private class Flight implements Comparable<Flight>{
		int f, s,c;
		Flight(int f, int s, int c){
			this.f = f;
			this.s = s;
			this.c = c;
		}
		@Override
		public int compareTo(Flight other) {
			

			return (Long.compare(c, other.c));
		}
		public String toString()
		{
			return this.f + " " + this.s +" "+this.c;
		}
	}
	void getFactors(int n,int x){
		for(int i = 1;i*i<=n;i++){
			if(n%i==0){
				hs[x].add(i);
				hs[x].add(n/i);
			}
		}
	}
	void recur(int a, int b, int k){
		if(k==0){
			if(a==x2 && b==y2) ans++;
			return;
		}
		recur(a,b+1,k-1);
		recur(a,b-1,k-1);
		recur(a+1,b,k-1);
		recur(a-1,b,k-1);
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
			return ((u == other.u && v == other.v));
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

	long modInverse(long a, long id1) 
	{
		return power(a, id1 - 2, id1);
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

	private boolean id0(int c) 
	{
		return !(c >= 33 && c <= 126);
	}

	private int skip() 
	{
		int b;
		while ((b = readByte()) != -1 && id0(b))
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
		while (!(id0(b)))
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
		while (p < n && !(id0(b)))
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