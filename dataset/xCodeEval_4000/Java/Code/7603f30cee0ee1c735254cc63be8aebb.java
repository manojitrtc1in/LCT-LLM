import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class MainA {
	private static InputStream stream;
	private static byte[] buf = new byte[1024];
	private static int curChar;
	private static int numChars;
	private static SpaceCharFilter filter;
	private static PrintWriter pw;
	private static long mod = 1000000000 + 7;
	static long count=0;
	static int flag=-1;
	static int d[];
	static int ans[][];
	static int d2[];
	static int ans2[][];
	public static int[] dfs( int v, int vis[], ArrayList<Integer> arr[],int k ,int r[])
	{
		vis[v]=1;
		for(int i=0;i<k;i++)ans[v][i]=d[i]+1;
		ans[v][r[v]]=0;
		for(int i=0;i<arr[v].size();i++)
		{
			int x=arr[v].get(i);
		
			if(vis[x]==0)
			{
				
				int a[]=dfs(x,vis,arr,k,r);	
				for(int j=0;j<k;j++)
				{
					ans[v][j]=Math.min(ans[v][j],a[j]+1);
				}
				d=ans[v];
			}
		}
		return ans[v];
	}
	
	public static int[] dfs2( int v, int vis[], ArrayList<Integer> arr[],int k ,int r[])
	{
		vis[v]=1;
		for(int i=0;i<k;i++)ans2[v][i]=d2[i]+1;
		ans2[v][r[v]]=0;
		for(int i=arr[v].size()-1;i>=0;i--)
		{
			int x=arr[v].get(i);
		
			if(vis[x]==0)
			{
				
				int a[]=dfs(x,vis,arr,k,r);	
				for(int j=0;j<k;j++)
				{
					ans2[v][j]=Math.min(ans2[v][j],a[j]+1);
				}
				d2=ans2[v];
			}
		}
		return ans2[v];
	}
	private static void soln() 
	{
	
		int n=nextInt();




































		int a[]=new int[n];
		HashMap<Integer,Integer> hm=new HashMap();
		for(int i=0;i<n;i++)
		{
			a[i]=nextInt();
			hm.put(a[i],i+1);
		}
		int count=0;
		for(int i=1;i<=n;i++)
		{
			int c=hm.get(i);
			if(c==i)continue;
			int va=a[i-1];
			hm.put(va,c);a[c-1]=va;
			hm.put(i,i);a[i-1]=i;
			count++;
		}
		
		if(count%2==(3*n)%2 )
		{
			pw.println("Petr");
			
		}
		else
		{
			pw.println("Um_nik");
		}
	}
	
	private static long pow(long a, long b) {
		if (b == 0)
			return 1;
		long p = pow(a, b / 2);
		p = (p * p) ;
		return (b % 2 == 0) ? p : (a * p) ;
	}
	public static int biSearch(long div[],long n)
	{
		int low=0;int high=div.length-1;int res=-1;
		while(low<=high)
		{
			int mid=(low+high)/2;
			if(div[mid]<n)
			{
				res=mid;
				low=mid+1;
			}
			else high=mid-1;
		}
		return res;
	}
	public static void sieve(int prime[],int k,long div[],long co[])
	{
		for(int i=0;i<=k;i++)prime[i]=i;
		
		for(int i=2;i*i<=k;i++)
		{
			if(prime[i]==i)
			{
				for(int j=2*i;j<=k;j+=i)
				{
					prime[j]=i;
				}
			}
		}
		

		div[1]=1;
		for(int i=2;i<=k;i++)
		{
			int key=i;int prev=0;long count=0;long ans=1;
			while(key>1)
			{
				int p=prime[key];
				key/=p;
				if(prev!=p)
				{
					ans=ans*(count+1);
					count=0;
				}
				count++;
				prev=p;	
			}
			
			div[i]=ans*(count+1);
		}
		for(int i=1;i<=k;i++)co[i]=(div[i]);
		Arrays.sort(div);
	}
	
	public static double dist(int x, int y,int a[], int b[])
	{
		return Math.sqrt(Math.pow(a[x]-a[y],2)+Math.pow(b[x]- b[y],2));
	}
	public static double bSearch(int a[],int b[],int n,long p)
	{
		double l=0;double r=(double)1e15;
		for(int i=0;i<200;i++)
		{
			double mid=(l+r)/2;
			

			if(f(mid,a,b,p,n))
			{
				l=mid;
				
				

			}
			else r=mid;
			

		}
		return l;
	}
	
	public static boolean f(double t,int a[],int b[],long p,int n)
	{
		double totalCons=0;
		for(int i=0;i<n;i++)
		{
			double total=a[i]*t-b[i];
			

			if(total>0)
			{
				totalCons+=total;
			}
		}
		

		if(totalCons<=p*t)return true;
		else return false;
	}
	public static int check(String s[],int x, int y,int n,int m)
	{
		int dx[]= {-1,0,1,1,1,0,-1,-1};
		int dy[]= {-1,-1,-1,0,1,1,1,0};
		int count=0;
		for(int i=0;i<8;i++)
		{
			int vx=x+dx[i];
			int vy=y+dy[i];
			if(vx<0 || vx>=n ||vy<0 || vy>=m)
			{
				
			}
			else
			{
				if(s[vx].charAt(vy)=='*')count++;
			}
		}
		return count;
	}

	public static class Pair implements Comparable<Pair>
	{
		long x;
		long y;int i;
		Pair(long a,long b,int c)
		{
			x=a;y=b;i=c;
		}
		
		@Override
		public int compareTo(Pair o)
		{
			if(x==o.x)return Long.compare(y,o.y);
			else return Long.compare(x, o.x);
		}
	}
	public static class Segment {
		private int[] tree;
		private boolean[] lazy;
		private int size;
		private int n;

		private class node {
			private int a;
			private int b;
			private int c;

			public node(int x, int y, int z) {
				a = x;
				b = y;
				c = z;
			}
		}

		public Segment(int n) {
			

			int x = (int) (Math.ceil(Math.log(n) / Math.log(2)));
			size = 2 * (int) Math.pow(2, x) - 1;
			tree = new int[size];
			lazy = new boolean[size];
			this.n = n;
			build(0, 0, n - 1);
		}

		public void build(int id, int l, int r) {
			if (l == r) {
				return;
			}
			int mid = (l + r) / 2;
			build(2 * id + 1, l, mid);
			build(2 * id + 2, mid + 1, r);
			tree[id] = tree[2 * id + 1] + tree[2 * id + 2];
		}

		public int query(int l, int r) {
			return queryUtil(l, r, 0, 0, n - 1);
		}

		private int queryUtil(int x, int y, int id, int l, int r) {
			if (l > y || x > r)
				return 0;
			if (x <= l && r <= y) {
				

				return tree[id];
				

				

			}
			int mid = l + (r - l) / 2;
			shift(id);
			return queryUtil(x, y, 2 * id + 1, l, mid) + queryUtil(x, y, 2 * id + 2, mid + 1, r);
		}

		public void update(int x, int y, int colour, int id, int l, int r) {
			

			if (x > r || y < l)
				return;
			if (x <= l && r <= y) {

				return;
			}
			int mid = l + (r - l) / 2;
			shift(id);
			update(x, y, colour, 2 * id + 1, l, mid);
			update(x, y, colour, 2 * id + 2, mid + 1, r);
			tree[id] = tree[2 * id + 1] + tree[2 * id + 2];
		}

		public void shift(int id) {

		}
	}

	public static void fft(double[] a, double[] b, boolean invert) {
		int count = a.length;
		for (int i = 1, j = 0; i < count; i++) {
			int bit = count >> 1;
			for (; j >= bit; bit >>= 1)
				j -= bit;
			j += bit;
			if (i < j) {
				double temp = a[i];
				a[i] = a[j];
				a[j] = temp;
				temp = b[i];
				b[i] = b[j];
				b[j] = temp;
			}
		}
		for (int len = 2; len <= count; len <<= 1) {
			int halfLen = len >> 1;
			double angle = 2 * Math.PI / len;
			if (invert)
				angle = -angle;
			double wLenA = Math.cos(angle), wLenB = Math.sin(angle);
			for (int i = 0; i < count; i += len) {
				double wA = 1, wB = 0;
				for (int j = 0; j < halfLen; j++) {
					double uA = a[i + j], uB = b[i + j];
					double vA = a[i + j + halfLen] * wA - b[i + j + halfLen] * wB;
					double vB = a[i + j + halfLen] * wB + b[i + j + halfLen] * wA;
					a[i + j] = uA + vA;
					b[i + j] = uB + vB;
					a[i + j + halfLen] = uA - vA;
					b[i + j + halfLen] = uB - vB;
					double nextWA = wA * wLenA - wB * wLenB;
					wB = wA * wLenB + wB * wLenA;
					wA = nextWA;
				}
			}
		}
		if (invert) {
			for (int i = 0; i < count; i++) {
				a[i] /= count;
				b[i] /= count;
			}
		}
	}

	static void multiply(long[][] a, long[][] b, long m) {
		int n = a.length;
		long[][] mul = new long[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				mul[i][j] = 0;
				for (int k = 0; k < n; k++)
					mul[i][j] = (mul[i][j] + (a[i][k] * b[k][j]) % m) % m;
			}
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				a[i][j] = mul[i][j];
	}

	private static long pow(long a, long b, long c) {
		if (b == 0)
			return 1;
		long p = pow(a, b / 2, c);
		p = (p * p) % c;
		return (b % 2 == 0) ? p : (a * p) % c;
	}

	private static long gcd(long n, long l) {
		if (l == 0)
			return n;
		return gcd(l, n % l);
	}

	public static void main(String[] args) throws Exception {
		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		


		
		InputReader(System.in);
		pw = new PrintWriter(System.out);
		
		soln();
		pw.close();
	}

	public static void InputReader(InputStream stream1) {
		stream = stream1;
	}

	private static boolean isWhitespace(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	private static boolean isEndOfLine(int c) {
		return c == '\n' || c == '\r' || c == -1;
	}

	private static int read() {
		if (numChars == -1)
			throw new InputMismatchException();
		if (curChar >= numChars) {
			curChar = 0;
			try {
				numChars = stream.read(buf);
			} catch (IOException e) {
				throw new InputMismatchException();
			}
			if (numChars <= 0)
				return -1;
		}
		return buf[curChar++];
	}

	private static int nextInt() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		int res = 0;
		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		} while (!isSpaceChar(c));
		return res * sgn;
	}

	private static long nextLong() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		long res = 0;
		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		} while (!isSpaceChar(c));
		return res * sgn;
	}

	private static String nextToken() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do {
			res.appendCodePoint(c);
			c = read();
		} while (!isSpaceChar(c));
		return res.toString();
	}

	private static String nextLine() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do {
			res.appendCodePoint(c);
			c = read();
		} while (!isEndOfLine(c));
		return res.toString();
	}

	private static int[] nextIntArray(int n) {
		int[] arr = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = nextInt();
		}
		return arr;
	}

	private static long[] nextLongArray(int n) {
		long[] arr = new long[n];
		for (int i = 0; i < n; i++) {
			arr[i] = nextLong();
		}
		return arr;
	}

	private static void pArray(int[] arr) {
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();
		return;
	}

	private static void pArray(long[] arr) {
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();
		return;
	}

	private static boolean isSpaceChar(int c) {
		if (filter != null)
			return filter.isSpaceChar(c);
		return isWhitespace(c);
	}

	private static char nextChar() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		char c1 = (char) c;
		while (!isSpaceChar(c))
			c = read();
		return c1;
	}

	private interface SpaceCharFilter {
		public boolean isSpaceChar(int ch);
	}
}