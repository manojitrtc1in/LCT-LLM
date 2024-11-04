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
		String s = nextLine();
		int n = s
				.length();
		int c1 = 0;
		int c2 = 0;
		for (int i = 0; i < n; i++)
		{
			if (s.charAt(
					i) == '0')
				c1++;
			else
				c2++;
		}
		int size = c1
				- c2;
		if (size <= 0)
			pw.println(
					-1);
		else
		{
			Queue<Pair> zero = new LinkedList<>();
			Queue<Pair> one = new LinkedList<>();
			ArrayList<StringBuilder> l = new ArrayList<>();
			boolean f = true;
			for (int i = 0; i < n; i++)
			{
				if (s.charAt(
						i) == '0')
				{
					if (one.isEmpty())
					{
						StringBuilder sb = new StringBuilder();
						sb.append(
								(i + 1) + " ");
						l.add(sb);
						zero.add(
								new Pair(
										i,
										l.size() - 1));
					} else
					{
						Pair x = one
								.poll();
						StringBuilder tmp = l
								.get(x.j);
						tmp.append(
								(i + 1) + " ");
						

						zero.add(
								new Pair(
										i,
										x.j));
					}
				} else
				{
					if (zero.isEmpty())
					{
						pw.println(
								-1);
						f = false;
						break;
					} else
					{
						Pair x = zero
								.poll();
						StringBuilder tmp = l
								.get(x.j);
						tmp.append(
								(i + 1) + " ");
						one.add(new Pair(
								i,
								x.j));
					}
				}
			}
			if (!one.isEmpty()
					&& f)
			{
				pw.println(
						-1);
				

				f = false;
			}
			if (f)
			{

				pw.println(
						l.size());
				for (StringBuilder sb : l)
				{
					String[] s1 = sb
							.toString()
							.split(" ");
					pw.print(
							s1.length
									+ " ");
					pw.println(
							sb.toString());
				}

			}
		}
	}

	public class Segment
	{
		private int[] base;
		private Node[] tree;
		private boolean[] lazy;
		private int size;
		private int n;

		private class Node
		{
			private int size;
			private int[] arr;
		}

		public Segment(
				int[] arr,
				int n)
		{
			this.base = arr;
			int x = (int) (Math
					.ceil(Math
							.log(n)
							/ Math.log(
									2)));
			size = 2 * (int) Math
					.pow(2, x)
					- 1;
			tree = new Node[size];
			

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
				tree[id].size = 1;
				tree[id].arr = new int[1];
				tree[id].arr[0] = base[l];
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
				ret.size = n2.size;
				ret.arr = n2.arr
						.clone();
			} else if (n2 == null)
			{
				ret.size = n1.size;
				ret.arr = n1.arr
						.clone();
			} else
			{
				ret.size = Math
						.min(n1.size
								+ n2.size,
								60);
				ret.arr = new int[ret.size];
				int i1 = 0;
				int i2 = 0;
				int i = 0;
				while (i1 < n1.size
						&& i2 < n2.size
						&& i < ret.size)
				{
					if (n1.arr[i1] >= n2.arr[i2])
						ret.arr[i++] = n1.arr[i1++];
					else
						ret.arr[i++] = n2.arr[i2++];
				}
				while (i1 < n1.size
						&& i < ret.size)
					ret.arr[i++] = n1.arr[i1++];
				while (i2 < n2.size
						&& i < ret.size)
					ret.arr[i++] = n2.arr[i2++];
			}
			return ret;
		}

		public int[] query(
				int l,
				int r)
		{
			Node ret = queryUtil(
					l,
					r,
					0,
					0,
					n - 1);
			if (ret == null)
				return new int[] {};
			else
				return ret.arr;
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
				int colour,
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
				tree[id].arr[0] = colour;
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

		public void shift(
				int id)
		{

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