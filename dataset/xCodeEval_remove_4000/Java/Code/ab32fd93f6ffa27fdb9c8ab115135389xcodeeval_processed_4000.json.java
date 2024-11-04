import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.StringTokenizer;


public class pprac
{
	FastScanner in;
	PrintWriter out;

	static int countc = 0;
	static int minm = countc;

	static ArrayList[] adj;
	static ArrayList[] aadj;
	static int last;
	static int n;
	static int m;

	static int[] dp1;
	static int[] dp2;
	static int color[];
	static int visited[];
	static int[] arr;
	static long[] brr;
	static double ans;
	static int array[];
	static int start[];
	static int finish[];
	static int pref[];
	static int tree[];
	static int maxval = 32;

	static int ttt[];
	static int sum = 0;
	static String s;

	static int cc = 0;
	static long min = Long.MAX_VALUE;

	static ArrayList<Integer> segt[];

	

	static int dir[][] =
	{
			{ 1, 0 },
			{ 0, 1 },
			{ 0, -1 },
			{ -1, 0 } };

	static int[] seg;
	static long count = 1;
	static long mod = (long) 1e9 + 7;

	static int parent[];
	static int size[];

	static int[] l;
	static int[] r;
	static int[] next;
	static int[] cnt;
	static int[] block;

	static int bblock = 1001;

	static HashSet<String> set;
	static HashSet<String> set2;

	static int low[];
	static int disc[];
	static int time;
	static int acn[];

	static HashMap<Long, Integer> map;

	static class Pair implements Comparable<Pair>
	{
		int x;
		int y;
		int i;

		Pair(int l, int m, int i)
		{

			this.x = l;
			this.y = m;
			this.i = i;

		}

		public int compareTo(Pair p)
		{

			if (this.x / bblock == p.x / bblock)
			{
				return (int) (this.y - p.y);
			}
			return (int) (this.x / bblock - p.x / bblock);
		}

		public String toString()
		{
			return x + " " + y;
		}

		public boolean equals(Object o)
		{
			if (o instanceof Pair)
			{
				Pair a = (Pair) o;

				return this.x == a.x;
			}

			return false;
		}

		public int hashCode()
		{
			return new Long(x).hashCode() * 31 + new Long(y).hashCode();
		}

	}

	public static int gcd(int a, int b)
	{
		if (b == 0)
			return a;
		return gcd(b, a % b);
	}

	void build(int n)
	{ 

		for (int i = n - 1; i > 0; --i)
			seg[i] = Math.min(seg[i << 1], seg[i << 1 | 1]);
	}

	public static void modify(int p, int val, int n)
	{ 

		

		for (seg[p += n] = val; p > 1; p >>= 1)
			seg[p >> 1] = Math.min(seg[p], seg[p ^ 1]);
	}

	int query(int l, int r, int n)
	{ 

		int res = Integer.MAX_VALUE;

		if (l > r)
		{
			return res;
		}

		for (l += n, r += n; l < r; l >>= 1, r >>= 1)
		{
			if ((l & 1) == 1)
				res = Math.min(res, seg[l++]);
			if ((r & 1) == 1)
				res = Math.min(res, seg[--r]);
		}
		return res;
	}

	

	

	

	

	

	


	public static int read(int idx)
	{
		int sum = 0;

		while (idx >= 0)
		{
			sum += tree[idx];
			idx -= (idx & (-idx));
		}

		return sum;
	}

	public static int find(int i)
	{
		if (parent[i] != i)
		{
			return find(parent[i]);
		}

		return i;
	}

	public static void union(int a, int b)
	{
		int x = find(a);
		int y = find(b);

		if (x != y)
		{
			if (size[x] > size[y])
			{
				size[x] += size[y];
				parent[y] = x;
			} else
			{
				size[y] += size[x];
				parent[x] = y;
			}
		}
	}

			 void solve() throws NumberFormatException, InputMismatchException, IOException
	{

		


		int n = in.nextInt();

		String a[] = new String[n];
		String b[] = new String[n];
		String c[] = new String[n];
		String d[] = new String[n];

		for (int i = 0; i < n; i++)
		{
			a[i] = in.next();
		}
		for (int i = 0; i < n; i++)
		{
			b[i] = in.next();
		}
		for (int i = 0; i < n; i++)
		{
			c[i] = in.next();
		}
		for (int i = 0; i < n; i++)
		{
			d[i] = in.next();
		}

		int max = Integer.MAX_VALUE;

		for (int i = 1; i <= 4; i++)
		{

			for (int j = 1; j <= 4; j++)
			{
				if (i == j)
				{
					continue;
				}

				for (int k = 1; k <= 4; k++)
				{
					if (k == j || k == i)
					{
						continue;
					}

					for (int r = 1; r <= 4; r++)
					{
						if (r == i || r == j || r == k)
						{
							continue;
						}

						char arr[][] = new char[2 * n][2 * n];

						if (i == 1)
						{
							for (int ii = 0; ii < n; ii++)
							{
								for (int jj = 0; jj < n; jj++)
								{
									arr[ii][jj] = a[ii].charAt(jj);
								}
							}
						} else if (i == 2)
						{
							for (int ii = 0; ii < n; ii++)
							{
								for (int jj = 0; jj < n; jj++)
								{
									arr[ii][jj + n] = a[ii].charAt(jj);
								}
							}
						} else if (i == 3)
						{
							for (int ii = 0; ii < n; ii++)
							{
								for (int jj = 0; jj < n; jj++)
								{
									arr[ii + n][jj] = a[ii].charAt(jj);
								}
							}
						} else if (i == 4)
						{
							for (int ii = 0; ii < n; ii++)
							{
								for (int jj = 0; jj < n; jj++)
								{
									arr[ii + n][jj + n] = a[ii].charAt(jj);
								}
							}
						}

						

						if (j == 1)
						{
							for (int ii = 0; ii < n; ii++)
							{
								for (int jj = 0; jj < n; jj++)
								{
									arr[ii][jj] = b[ii].charAt(jj);
								}
							}
						} else if (j == 2)
						{
							for (int ii = 0; ii < n; ii++)
							{
								for (int jj = 0; jj < n; jj++)
								{
									arr[ii][jj + n] = b[ii].charAt(jj);
								}
							}
						} else if (j == 3)
						{
							for (int ii = 0; ii < n; ii++)
							{
								for (int jj = 0; jj < n; jj++)
								{
									arr[ii + n][jj] = b[ii].charAt(jj);
								}
							}
						} else if (j == 4)
						{
							for (int ii = 0; ii < n; ii++)
							{
								for (int jj = 0; jj < n; jj++)
								{
									arr[ii + n][jj + n] = b[ii].charAt(jj);
								}
							}
						}

						

						if (k == 1)
						{
							for (int ii = 0; ii < n; ii++)
							{
								for (int jj = 0; jj < n; jj++)
								{
									arr[ii][jj] = c[ii].charAt(jj);
								}
							}
						} else if (k == 2)
						{
							for (int ii = 0; ii < n; ii++)
							{
								for (int jj = 0; jj < n; jj++)
								{
									arr[ii][jj + n] = c[ii].charAt(jj);
								}
							}
						} else if (k == 3)
						{
							for (int ii = 0; ii < n; ii++)
							{
								for (int jj = 0; jj < n; jj++)
								{
									arr[ii + n][jj] = c[ii].charAt(jj);
								}
							}
						} else if (k == 4)
						{
							for (int ii = 0; ii < n; ii++)
							{
								for (int jj = 0; jj < n; jj++)
								{
									arr[ii + n][jj + n] = c[ii].charAt(jj);
								}
							}
						}

						

						if (r == 1)
						{
							for (int ii = 0; ii < n; ii++)
							{
								for (int jj = 0; jj < n; jj++)
								{
									arr[ii][jj] = d[ii].charAt(jj);
								}
							}
						} else if (r == 2)
						{
							for (int ii = 0; ii < n; ii++)
							{
								for (int jj = 0; jj < n; jj++)
								{
									arr[ii][jj + n] = d[ii].charAt(jj);
								}
							}
						} else if (r == 3)
						{
							for (int ii = 0; ii < n; ii++)
							{
								for (int jj = 0; jj < n; jj++)
								{
									arr[ii + n][jj] = d[ii].charAt(jj);
								}
							}
						} else if (r == 4)
						{
							for (int ii = 0; ii < n; ii++)
							{
								for (int jj = 0; jj < n; jj++)
								{
									arr[ii + n][jj + n] = d[ii].charAt(jj);
								}
							}
						}

						int cc = call(arr);

						max = Math.min(cc, max);
					}
				}
			}
		}

		out.println(max);

	}

	public static int call(char arr[][])
	{
		int cc = 0;

		char temp[][] = new char[arr.length][arr.length];

		char c = '0';

		for (int i = 0; i < arr.length; i++)
		{
			c = (c == '0') ? '1' : '0';
			for (int j = 0; j < arr.length; j++)
			{
				temp[i][j] = c;
				c = (c == '0') ? '1' : '0';
			

			}
			

		}

		int n = arr.length;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (arr[i][j] != temp[i][j])
				{
					cc++;
				}
			}
		}

		int dd = cc;

		cc = 0;

		c = '1';

		for (int i = 0; i < arr.length; i++)
		{
			c = (c == '0') ? '1' : '0';
			for (int j = 0; j < arr.length; j++)
			{
				temp[i][j] = c;
				c = (c == '0') ? '1' : '0';
			}
		}

		n = arr.length;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (arr[i][j] != temp[i][j])
				{
					cc++;
				}
			}
		}

		return Math.min(cc, dd);

	}

	public static HashSet<Integer> call(int a)
	{

		HashSet<Integer> list = new HashSet();

		while (a % 2 == 0)
		{
			list.add(2);
			a /= 2;
		}
		int n = a;
		for (int i = 3; i <= n; i += 2)
		{
			while (a % i == 0)
			{
				list.add(i);
				a = a / i;
			}
		}

		if (a > 2)
		{
			list.add(a);
		}

		return list;
	}

	public static String reverse(String s)
	{

		String ans = "";

		for (int i = s.length() - 1; i >= 0; i--)
		{
			ans += s.charAt(i);
		}

		return ans;

	}

	public static long sum(long x)
	{
		return x < 10 ? x : x % 10 + sum(x / 10);
	}

	public static long gcd(long x, long y)
	{
		if (x == 0)
			return y;
		else
			return gcd(y % x, x);
	}

	static long inv(long x, long mod)
	{
		long r, y;
		for (r = 1, y = mod - 2; y != 0; x = x * x % mod, y >>= 1)
		{
			if ((y & 1) == 1)
				r = r * x % mod;

		}
		return r;
	}

	public static long pow(long x, long y, long n)
	{
		if (y == 0)
			return 1 % n;
		if (y % 2 == 0)
		{
			long z = pow(x, y / 2, n);
			return (z * z) % n;
		}
		return ((x % n) * pow(x, y - 1, n)) % n;
	}

	public static boolean isPrime(long a)
	{
		

		if (a <= 1)
			return false;
		if (a <= 3)
			return true;

		

		

		if (a % 2 == 0 || a % 3 == 0)
			return false;

		for (long i = 5; i * i <= a; i = i + 6)
			if (a % i == 0 || a % (i + 2) == 0)
				return false;

		return true;
	}

	void run() throws NumberFormatException, InputMismatchException, IOException
	{
		in = new FastScanner();
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	class FastScanner
	{
		BufferedReader br;
		StringTokenizer st;

		public FastScanner()
		{
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next()
		{
			while (st == null || !st.hasMoreTokens())
			{
				try
				{
					st = new StringTokenizer(in.br.readLine());
				} catch (IOException e)
				{
					

					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt()
		{
			return Integer.parseInt(next());
		}

		long nextLong()
		{
			return Long.parseLong(next());
		}

		double nextDouble()
		{
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) throws NumberFormatException, InputMismatchException, IOException
	{
		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		


		new pprac().run();
	}

}

class Node
{
	int a;
	int b;

	public Node(int i, int j)
	{
		this.a = i;
		this.b = j;

	}

}

class MyComp implements Comparator<String>
{

	int c = 0;

	MyComp(int d)
	{
		c = d;
	}

	@Override
	public int compare(String a, String b)
	{

		


		String arr[] = a.split(" ");
		String brr[] = b.split(" ");

		return arr[c].compareTo(brr[c]);

	}

}

class id0 implements Comparator<Node>
{

	@Override
	public int compare(Node a, Node b)
	{

		


		if (a.b > b.b)
		{
			return -1;
		} else
		{
			return 1;
		}

	}

}