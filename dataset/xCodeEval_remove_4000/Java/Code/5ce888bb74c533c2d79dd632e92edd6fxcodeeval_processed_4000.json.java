import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.RoundingMode;
import java.util.*;
import java.util.Map.Entry;

public class Main
{
	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;
	private id5 filter;
	private PrintWriter pw;
	private long mod = 1000000000
			+ 7;

	private StringBuilder ans_sb;
	private int sum = 0;

	private void soln()
	{
		int n = nextInt();
		long[] a1 = new long[n
				+ 1];
		for (int i = 1; i <= n; i++)
			a1[i] = nextLong();
		long[] a2 = new long[n
				+ 1];
		long[] a3 = new long[n
				+ 1];
		for (int i = 1; i <= n; i++)
		{
			a2[i] = nextLong();
			a3[i] = a2[i];
			a2[i] += a2[i
					- 1];
		}
		long[] pref = new long[n
				+ 1];
		long[] na = new long[n
				+ 1];
		for (int i = 1; i <= n; i++)
		{
			int l = i
					- 1;
			int r = n;
			int ans = i
					- 1;
			long sum = 0;
			while (l <= r)
			{
				int mid = (l
						+ r)
						/ 2;
				long sum1 = a2[mid]
						- a2[i - 1];
				if (sum1 > a1[i])
				{
					r = mid - 1;
				} else
				{
					l = mid + 1;
					ans = mid;
					sum = sum1;
				}
			}
			if (ans == i
					- 1)
			{
				na[i] += a1[i];
			} else
			{
				if (ans != n)
					pref[ans + 1]--;
				pref[i]++;
				if (ans != n)
					na[ans + 1] += a1[i]
							- sum;
			}
		}
		long cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			cnt += pref[i];
			na[i] += cnt
					* a3[i];
			pw.print(
					na[i] + " ");
		}
	}

	public class Segment
	{
		private Node[] tree;
		private boolean[] lazy;
		private int size;
		private int n;

		private class Node
		{
			private int cnt;
			private long ans;
		}

		public Segment(
				int n)
		{
			

			int x = (int) (Math
					.ceil(Math
							.log(n)
							/ Math.log(
									2)));
			size = 2 * (int) Math
					.pow(2, x)
					- 1;
			tree = new Node[size];
			lazy = new boolean[size];
			this.n = n;
			

			build(0, 0,
					n - 1);
		}

		public void build(
				int id,
				int l,
				int r)
		{
			if (l == r)
			{
				tree[id] = new Node();
				tree[id].cnt = 0;
				tree[id].ans = 0;
				return;
			}
			int mid = ((l
					+ r) >> 1);
			build((id << 1)
					| 1,
					l,
					mid);
			build((id << 1)
					+ 2,
					mid + 1,
					r);
			tree[id] = merge(
					tree[(id << 1)
							| 1],
					tree[(id << 1)
							+ 2]);
			

		}

		public Node merge(
				Node n1,
				Node n2)
		{
			Node ret = new Node();
			if (n1 == null
					&& n2 == null)
				return null;
			else if (n1 == null)
			{
				ret.ans = n2.ans;
				ret.cnt = n2.cnt;
			} else if (n2 == null)
			{
				ret.ans = n1.ans;
				ret.cnt = n1.cnt;
			} else
			{
				ret.cnt = n1.cnt
						+ n2.cnt;
				ret.ans = n1.ans
						+ n2.ans;
			}
			return ret;
		}

		public long query(
				int l,
				int r,
				int f)
		{
			Node ret = queryUtil(
					l,
					r,
					0,
					0,
					n - 1);
			if (ret == null)
				return 0;
			if (f == 1)
				return ret.ans;
			else
				return ret.cnt;
		}

		private Node queryUtil(
				int x,
				int y,
				int id,
				int l,
				int r)
		{
			if (l > y
					|| x > r)
				return null;
			if (x <= l
					&& r <= y)
			{
				return tree[id];
			}
			int mid = ((l
					+ r) >> 1);
			

			Node q1 = queryUtil(
					x,
					y,
					(id << 1)
							| 1,
					l,
					mid);
			Node q2 = queryUtil(
					x,
					y,
					(id << 1)
							+ 2,
					mid + 1,
					r);
			return merge(
					q1,
					q2);
		}

		public void update(
				int x,
				int y,
				int c)
		{
			update1(x,
					y,
					c,
					0,
					0,
					n - 1);
		}

		private void update1(
				int x,
				int y,
				long colour,
				int id,
				int l,
				int r)
		{
			

			if (x > r
					|| y < l)
				return;
			if (x <= l
					&& r <= y)
			{
				tree[id].cnt++;
				tree[id].ans += colour;
				return;
			}
			int mid = ((l
					+ r) >> 1);
			

			if (y <= mid)
				update1(x,
						y,
						colour,
						(id << 1)
								| 1,
						l,
						mid);
			else if (x > mid)
				update1(x,
						y,
						colour,
						(id << 1)
								+ 2,
						mid + 1,
						r);
			else
			{
				update1(x,
						y,
						colour,
						(id << 1)
								| 1,
						l,
						mid);
				update1(x,
						y,
						colour,
						(id << 1)
								+ 2,
						mid + 1,
						r);
			}
			tree[id] = merge(
					tree[(id << 1)
							| 1],
					tree[(id << 1)
							+ 2]);

		}
	}

	class id4
	{

		static final int LOG = 6;
		static final int SIZE = 1 << LOG;
		static final int MASK = SIZE
				- 1;

		private long[] data;

		public id4(
				int n)
		{
			data = new long[(n >> LOG)
					+ 2];
		}

		void set(
				int i)
		{
			data[i >> LOG] |= 1L << (i
					& MASK);
		}

		void unset(
				int i)
		{
			data[i >> LOG] &= ~(1L << (i
					& MASK));
		}

		void flip(
				int i)
		{
			data[i >> LOG] ^= 1L << (i
					& MASK);
		}

		int get(int i)
		{
			return (int) ((data[i >> LOG] >>> (i
					& MASK))
					& 1);
		}

		void print()
		{
			for (int i = 0; i < data.length; i++)
			{
				System.out
						.print(Long
								.toString(
										data[i],
										2));
			}
			System.out
					.println();
		}

		long getWord(
				int i)
		{
			if (i <= -SIZE
					|| (i >> LOG)
							+ 1 >= data.length)
			{
				return 0;
			}
			int rem = i
					& MASK;
			int idx = i >> LOG;

			if (rem == 0)
			{
				return data[idx];
			}

			long head = idx < 0
					? 0
					: (data[idx] >>> rem);
			long tail = data[idx
					+ 1] << (SIZE
							- rem);

			return head
					| tail;
		}
	}

	int count(
			long[] bs,
			int len)
	{
		int ret = 0;
		for (int i = 0; i << 6 < len; i++)
		{
			if (((i + 1) << 6) <= len)
			{
				ret += Long
						.bitCount(
								bs[i]);
			} else
			{
				int rem = len
						& 63;
				ret += Long
						.bitCount(
								bs[i] << (64
										- rem));
			}
		}
		return ret;
	}

	private class Pair
			implements
			Comparable<Pair>
	{
		int i, j;

		public Pair(
				int b,
				int c)
		{

			i = b;
			j = c;
		}

		@Override
		public int compareTo(
				Pair arg0)
		{
			return this.i
					- arg0.i;
		}
	}

	private class Bridge
	{
		private LinkedList<Edge>[] graph;
		private LinkedList<Integer>[] tree;
		private int t;
		private boolean[] isBridge;
		private int[] cno;

		public Bridge(
				int n,
				int m)
		{
			pre(n, m);
		}

		private class Edge
		{
			int u, v,
					i;

			public Edge(
					int a,
					int b,
					int c)
			{
				u = a;
				v = b;
				i = c;
			}
		}

		private void pre(
				int n,
				int m)
		{
			graph = new LinkedList[n];
			tree = new LinkedList[n];
			for (int i = 0; i < m; i++)
			{
				int u = nextInt()
						- 1;
				int v = nextInt()
						- 1;
				Edge e = new Edge(
						u,
						v,
						i);
				graph[u].add(
						e);
				graph[v].add(
						e);
			}
			isBridge = new boolean[m];
			cno = new int[n];
			boolean[] v = new boolean[n];
			int[] arr = new int[n];
			for (int i = 0; i < n; i++)
				if (!v[i])
					dfs(i, null,
							v,
							arr);
		}

		private int dfs(
				int u,
				Edge e,
				boolean[] v,
				int[] arr)
		{
			v[u] = true;
			arr[u] = t++;
			int min = arr[u];
			Iterator<Edge> it = graph[u]
					.listIterator();
			while (it
					.hasNext())
			{
				Edge x = it
						.next();
				int w = x.u;
				if (x.u == u)
					w = x.v;
				if (!v[w])
					min = Math
							.min(min,
									dfs(w, x,
											v,
											arr));
				else if (x != e)
					min = Math
							.min(min,
									arr[w]);
			}
			if (min == arr[u]
					&& e != null)
				isBridge[e.i] = true;
			return min;
		}

		private void bfs(
				int u,
				int cmpNo,
				Queue<Integer>[] q,
				boolean[] v)
		{
			int cur = cmpNo;
			cno[cur] = cmpNo;
			q[cur].add(
					u);
			v[u] = true;
			while (!q[cur]
					.isEmpty())
			{
				int x = q[cur]
						.poll();
				Iterator<Edge> it = graph[x]
						.listIterator();
				while (it
						.hasNext())
				{
					Edge x1 = it
							.next();
					int w = x1.u;
					if (w == x)
						w = x1.v;
					if (!v[w])
					{
						if (isBridge[x1.i])
						{
							tree[cur]
									.add(0, cmpNo
											+ 1);
							tree[cmpNo
									+ 1].add(
											0,
											cur);
							bfs(w, cmpNo
									+ 1,
									q,
									v);
						} else
						{
							bfs(w, cmpNo,
									q,
									v);
						}
					}
				}
			}
		}
	}

	private String id1(
			long a,
			long b)
	{
		long x = 0,
				y = 1,
				lastx = 1,
				lasty = 0,
				temp;
		while (b != 0)
		{
			long q = a
					/ b;
			long r = a
					% b;
			a = b;
			b = r;
			temp = x;
			x = lastx
					- q * x;
			lastx = temp;
			temp = y;
			y = lasty
					- q * y;
			lasty = temp;
		}
		return lastx
				+ " "
				+ lasty;
	}

	private void debug(
			Object... o)
	{
		System.out
				.println(
						Arrays.deepToString(
								o));
	}

	private long pow(
			long a,
			long b,
			long c)
	{
		if (b == 0)
			return 1;
		long p = pow(
				a,
				b / 2,
				c);
		p = (p * p)
				% c;
		return (b
				% 2 == 0)
						? p
						: (a * p)
								% c;
	}

	private long gcd(
			long n,
			long l)
	{
		if (l == 0)
			return n;
		return gcd(
				l,
				n % l);
	}

	public static void main(
			String[] args)
			throws Exception
	{
		new Thread(
				null,
				new Runnable()
				{
					@Override
					public void run()
					{
						new Main()
								.solve();
					}
				},
				"1",
				1 << 26).start();
		

	}

	public StringBuilder solve()
	{
		InputReader(
				System.in);
		
		pw = new PrintWriter(
				System.out);
		

		soln();

		pw.close();
		

		return ans_sb;
	}

	public void InputReader(
			InputStream stream1)
	{
		stream = stream1;
	}

	private boolean isWhitespace(
			int c)
	{
		return c == ' '
				|| c == '\n'
				|| c == '\r'
				|| c == '\t'
				|| c == -1;
	}

	private boolean id3(
			int c)
	{
		return c == '\n'
				|| c == '\r'
				|| c == -1;
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
				numChars = stream
						.read(buf);
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
		while (id0(
				c))
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
			if (c < '0'
					|| c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		} while (!id0(
				c));
		return res
				* sgn;
	}

	private long nextLong()
	{
		int c = read();
		while (id0(
				c))
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
			if (c < '0'
					|| c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		} while (!id0(
				c));
		return res
				* sgn;
	}

	private String nextToken()
	{
		int c = read();
		while (id0(
				c))
			c = read();
		StringBuilder res = new StringBuilder();
		do
		{
			res.appendCodePoint(
					c);
			c = read();
		} while (!id0(
				c));
		return res
				.toString();
	}

	private String nextLine()
	{
		int c = read();
		while (id0(
				c))
			c = read();
		StringBuilder res = new StringBuilder();
		do
		{
			res.appendCodePoint(
					c);
			c = read();
		} while (!id3(
				c));
		return res
				.toString();
	}

	private int[] id2(
			int n)
	{
		int[] arr = new int[n];
		for (int i = 0; i < n; i++)
		{
			arr[i] = nextInt();
		}
		return arr;
	}

	private long[] id6(
			int n)
	{
		long[] arr = new long[n];
		for (int i = 0; i < n; i++)
		{
			arr[i] = nextLong();
		}
		return arr;
	}

	private void pArray(
			int[] arr)
	{
		for (int i = 0; i < arr.length; i++)
		{
			System.out
					.print(arr[i]
							+ " ");
		}
		System.out
				.println();
		return;
	}

	private void pArray(
			long[] arr)
	{
		for (int i = 0; i < arr.length; i++)
		{
			System.out
					.print(arr[i]
							+ " ");
		}
		System.out
				.println();
		return;
	}

	private boolean id0(
			int c)
	{
		if (filter != null)
			return filter
					.id0(
							c);
		return isWhitespace(
				c);
	}

	private char nextChar()
	{
		int c = read();
		while (id0(
				c))
			c = read();
		char c1 = (char) c;
		while (!id0(
				c))
			c = read();
		return c1;
	}

	private interface id5
	{
		public boolean id0(
				int ch);
	}
}