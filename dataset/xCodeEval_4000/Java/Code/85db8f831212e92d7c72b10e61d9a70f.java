import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class main
{
	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;
	private SpaceCharFilter filter;
	private PrintWriter pw;
	private long mod = 1000000000 + 7;

	private StringBuilder ans_sb;
	private ArrayList<Integer> primes;
	private long ans;

	private void soln()
	{
		int n = nextInt();
		long[] arr = new long[n];
		for (int i = 0; i < n; i++)
			arr[i] = nextLong();
		Segment tree = new Segment(n, arr);
		long[] ans = new long[n];
		BigInteger fa = BigInteger.ZERO;
		HashMap<Long, Integer> map = new HashMap<>();
		for (int i = 0; i < n; i++)
		{
			ans[i] = ((long) i + 1) * arr[i] - tree.query(0, i);
			if (map.containsKey(arr[i] - 1))
			{
				long tmp = map.get(arr[i] - 1);
				ans[i] -= tmp;
			}
			if (map.containsKey(arr[i] + 1))
			{
				long tmp = map.get(arr[i] + 1);
				ans[i] += tmp;
			}

			if (!map.containsKey(arr[i]))
				map.put(arr[i], 0);
			map.put(arr[i], map.get(arr[i]) + 1);
			fa = fa.add(new BigInteger(Long.toString(ans[i])));
		}
		

		
		pw.println(fa.toString());
		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

	}

	public class Segment
	{
		private Node[] tree;
		private boolean[] lazy;
		private int size;
		private int n;
		private long[] base;

		private class Node
		{
			private int l;
			private int r;
			private long ans;
			private long ans2;
		}

		public Segment(int n, long[] arr)
		{
			this.base = arr;
			int x = (int) (Math.ceil(Math.log(n) / Math.log(2)));
			size = 2 * (int) Math.pow(2, x) - 1;
			tree = new Node[size];
			lazy = new boolean[size];
			this.n = n;
			

			build(0, 0, n - 1);
		}

		public void build(int id, int l, int r)
		{
			if (l == r)
			{
				tree[id] = new Node();
				tree[id].l = l;
				tree[id].r = r;
				tree[id].ans = base[l];
				return;
			}
			int mid = (l + r) / 2;
			build(2 * id + 1, l, mid);
			build(2 * id + 2, mid + 1, r);
			tree[id] = merge(tree[2 * id + 1], tree[2 * id + 2], l, r);
			

		}

		public Node merge(Node n1, Node n2, int l, int r)
		{
			Node ret = new Node();
			if (n1 == null && n2 == null)
				return null;
			else if (n1 == null)
			{
				ret.ans = n2.ans;
			}

			else if (n2 == null)
			{
				ret.ans = n1.ans;
			} else
			{

				ret.ans = n1.ans + n2.ans;

			}

			return ret;
		}

		public long query(int l, int r)
		{
			Node ret = queryUtil(l, r, 0, 0, n - 1);
			if (ret == null)
			{
				return 0;
			} else
				return ret.ans;
		}

		private Node queryUtil(int x, int y, int id, int l, int r)
		{
			if (l > y || x > r)
				return null;
			if (x <= l && r <= y)
			{
				return tree[id];
			}
			int mid = l + (r - l) / 2;
			

			Node q1 = queryUtil(x, y, 2 * id + 1, l, mid);
			Node q2 = queryUtil(x, y, 2 * id + 2, mid + 1, r);

			return merge(q1, q2, Math.max(l, x), Math.min(r, y));
		}

		public void update(int x, int y, int c)
		{
			update1(x, y, c, 0, 0, n - 1);
		}

		private void update1(int x, int y, int colour, int id, int l, int r)
		{
			

			if (x > r || y < l)
				return;
			if (x <= l && r <= y)
			{
				if (colour != -1)
				{
					tree[id] = new Node();
					tree[id].ans = 1;
				} else
					tree[id] = null;
				return;
			}
			int mid = l + (r - l) / 2;
			

			if (y <= mid)
				update1(x, y, colour, 2 * id + 1, l, mid);
			else if (x > mid)
				update1(x, y, colour, 2 * id + 2, mid + 1, r);
			else
			{
				update1(x, y, colour, 2 * id + 1, l, mid);
				update1(x, y, colour, 2 * id + 2, mid + 1, r);
			}
			tree[id] = merge(tree[2 * id + 1], tree[2 * id + 2], l, r);

		}

		public void print(int l, int r, int id)
		{
			if (l == r)
			{
				if (tree[id] != null)
					System.out.println(l + " " + r + " " + tree[id].l + " " + tree[id].r + " " + tree[id].ans + " "
							+ tree[id].ans2);
				return;
			}
			int mid = l + (r - l) / 2;
			print(l, mid, 2 * id + 1);
			print(mid + 1, r, 2 * id + 2);
			if (tree[id] != null)
				System.out.println(
						l + " " + r + " " + tree[id].l + " " + tree[id].r + " " + tree[id].ans + " " + tree[id].ans2);
		}

		public void shift(int id)
		{

		}
	}

	private class Node implements Comparable<Node>
	{
		int node;
		long dist;

		@Override
		public int compareTo(Node arg0)
		{
			if (this.dist != arg0.dist)
				return (int) (this.dist - arg0.dist);
			return this.node - arg0.node;
		}

		public boolean equals(Object o)
		{
			if (o instanceof Node)
			{
				Node c = (Node) o;
				return this.node == c.node && this.dist == c.dist;
			}
			return false;
		}

		public String toString()
		{
			return this.node + ", " + this.dist;
		}
	}

	private void debug(Object... o)
	{
		System.out.println(Arrays.deepToString(o));
	}

	private long pow(long a, long b, long c)
	{
		if (b == 0)
			return 1;
		long p = pow(a, b / 2, c);
		p = (p * p) % c;
		return (b % 2 == 0) ? p : (a * p) % c;
	}

	private long gcd(long n, long l)
	{
		if (l == 0)
			return n;
		return gcd(l, n % l);
	}

	public static void main(String[] args) throws Exception
	{
		new Thread(null, new Runnable()
		{
			@Override
			public void run()
			{
				new main().solve();
			}
		}, "1", 1 << 26).start();
	}

	public StringBuilder solve()
	{
		InputReader(System.in);
		
		pw = new PrintWriter(System.out);
		ans_sb = new StringBuilder();
		soln();

		pw.close();
		

		return ans_sb;
	}

	public void InputReader(InputStream stream1)
	{
		stream = stream1;
	}

	private boolean isWhitespace(int c)
	{
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	private boolean isEndOfLine(int c)
	{
		return c == '\n' || c == '\r' || c == -1;
	}

	private int read()
	{
		if (numChars == -1)
			throw new InputMismatchException();
		if (curChar >= numChars)
		{
			curChar = 0;
			try
			{
				numChars = stream.read(buf);
			} catch (IOException e)
			{
				throw new InputMismatchException();
			}
			if (numChars <= 0)
				return -1;
		}
		return buf[curChar++];
	}

	private int nextInt()
	{
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-')
		{
			sgn = -1;
			c = read();
		}
		int res = 0;
		do
		{
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		} while (!isSpaceChar(c));
		return res * sgn;
	}

	private long nextLong()
	{
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-')
		{
			sgn = -1;
			c = read();
		}
		long res = 0;
		do
		{
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		} while (!isSpaceChar(c));
		return res * sgn;
	}

	private String nextToken()
	{
		int c = read();
		while (isSpaceChar(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do
		{
			res.appendCodePoint(c);
			c = read();
		} while (!isSpaceChar(c));
		return res.toString();
	}

	private String nextLine()
	{
		int c = read();
		while (isSpaceChar(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do
		{
			res.appendCodePoint(c);
			c = read();
		} while (!isEndOfLine(c));
		return res.toString();
	}

	private int[] nextIntArray(int n)
	{
		int[] arr = new int[n];
		for (int i = 0; i < n; i++)
		{
			arr[i] = nextInt();
		}
		return arr;
	}

	private long[] nextLongArray(int n)
	{
		long[] arr = new long[n];
		for (int i = 0; i < n; i++)
		{
			arr[i] = nextLong();
		}
		return arr;
	}

	private void pArray(int[] arr)
	{
		for (int i = 0; i < arr.length; i++)
		{
			System.out.print(arr[i] + " ");
		}
		System.out.println();
		return;
	}

	private void pArray(long[] arr)
	{
		for (int i = 0; i < arr.length; i++)
		{
			System.out.print(arr[i] + " ");
		}
		System.out.println();
		return;
	}

	private boolean isSpaceChar(int c)
	{
		if (filter != null)
			return filter.isSpaceChar(c);
		return isWhitespace(c);
	}

	private char nextChar()
	{
		int c = read();
		while (isSpaceChar(c))
			c = read();
		char c1 = (char) c;
		while (!isSpaceChar(c))
			c = read();
		return c1;
	}

	private interface SpaceCharFilter
	{
		public boolean isSpaceChar(int ch);
	}
}