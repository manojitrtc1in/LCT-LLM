import java.io.*;
import java.util.*;

public class CODEFORCES
{
	@SuppressWarnings("rawtypes")
	static InputReader in;
	static PrintWriter out;

	static int mx = Integer.MAX_VALUE - 1000000;

	public static class SegmentTree
	{
		int n;
		int arr[], lazy[];

		SegmentTree(int n)
		{
			this.n = n;
			arr = new int[n << 2];
			Arrays.fill(arr, mx);
			lazy = new int[n << 2];
		}

		SegmentTree(int a[])
		{
			this.n = a.length;
			arr = new int[n << 2];
			lazy = new int[n << 2];
			build(0, n - 1, 0, a);
		}

		void build(int l, int r, int c, int a[])
		{
			if (l == r)
			{
				arr[c] = a[l];
				return;
			}
			int mid = l + r >> 1;
			build(l, mid, (c << 1) + 1, a);
			build(mid + 1, r, (c << 1) + 2, a);
			arr[c] = merge(arr[(c << 1) + 1], arr[(c << 1) + 2]);
		}

		int merge(int a, int b)
		{
			return Math.min(a, b);
		}

		int lazymerge(int a, int b)
		{
			return b;
		}

		boolean getInitialValue(long a)
		{
			return !(a == 0);
		}

		void check(int c, int l, int r)
		{
			if (getInitialValue(lazy[c]))
			{
				arr[c] = lazymerge(arr[c], lazy[c]);
				if (l != r)
				{
					lazy[(c << 1) + 1] = lazymerge(lazy[(c << 1) + 1], lazy[c]);
					lazy[(c << 1) + 2] = lazymerge(lazy[(c << 1) + 2], lazy[c]);
				}
				lazy[c] = 0;
			}
		}

		void update(int l, int r, int c, int x, int y, int val)
		{
			check(c, l, r);
			if (l > r || x > y || l > y || x > r)
				return;
			if (x <= l && y >= r)
			{
				arr[c] = lazymerge(arr[c], val);
				if (l != r)
				{
					lazy[(c << 1) + 1] = lazymerge(lazy[(c << 1) + 1], val);
					lazy[(c << 1) + 2] = lazymerge(lazy[(c << 1) + 2], val);
				}
				return;
			}
			int mid = l + r >> 1;
			update(l, mid, (c << 1) + 1, x, y, val);
			update(mid + 1, r, (c << 1) + 2, x, y, val);
			arr[c] = merge(arr[(c << 1) + 1], arr[(c << 1) + 2]);
		}

		void up(int x, int y, int val)
		{
			update(0, n - 1, 0, x, y, val);
		}

		int get(int l, int r, int c, int x, int y)
		{
			check(c, l, r);
			if (l > r || x > y || l > y || x > r) 

				return mx;
			else if (x <= l && y >= r)
				return arr[c];
			int mid = l + r >> 1;
			return merge(get(l, mid, (c << 1) + 1, x, y), get(mid + 1, r, (c << 1) + 2, x, y));
		}

		int ans(int x, int y)
		{
			return get(0, n - 1, 0, x, y);
		}
	}

	public static class SegmentTree2
	{
		int n;
		int arr[], lazy[];

		SegmentTree2(int n)
		{
			this.n = n;
			arr = new int[n << 2];
			lazy = new int[n << 2];
		}

		SegmentTree2(int a[])
		{
			this.n = a.length;
			arr = new int[n << 2];
			lazy = new int[n << 2];
			build(0, n - 1, 0, a);
		}

		void build(int l, int r, int c, int a[])
		{
			if (l == r)
			{
				arr[c] = a[l];
				return;
			}
			int mid = l + r >> 1;
			build(l, mid, (c << 1) + 1, a);
			build(mid + 1, r, (c << 1) + 2, a);
			arr[c] = merge(arr[(c << 1) + 1], arr[(c << 1) + 2]);
		}

		int merge(int a, int b)
		{
			return Math.max(a, b);
		}

		int lazymerge(int a, int b)
		{
			return b;
		}

		boolean getInitialValue(long a)
		{
			return !(a == 0);
		}

		void check(int c, int l, int r)
		{
			if (getInitialValue(lazy[c]))
			{
				arr[c] = lazymerge(arr[c], lazy[c]);
				if (l != r)
				{
					lazy[(c << 1) + 1] = lazymerge(lazy[(c << 1) + 1], lazy[c]);
					lazy[(c << 1) + 2] = lazymerge(lazy[(c << 1) + 2], lazy[c]);
				}
				lazy[c] = 0;
			}
		}

		void update(int l, int r, int c, int x, int y, int val)
		{
			check(c, l, r);
			if (l > r || x > y || l > y || x > r)
				return;
			if (x <= l && y >= r)
			{
				arr[c] = lazymerge(arr[c], val);
				if (l != r)
				{
					lazy[(c << 1) + 1] = lazymerge(lazy[(c << 1) + 1], val);
					lazy[(c << 1) + 2] = lazymerge(lazy[(c << 1) + 2], val);
				}
				return;
			}
			int mid = l + r >> 1;
			update(l, mid, (c << 1) + 1, x, y, val);
			update(mid + 1, r, (c << 1) + 2, x, y, val);
			arr[c] = merge(arr[(c << 1) + 1], arr[(c << 1) + 2]);
		}

		void up(int x, int y, int val)
		{
			update(0, n - 1, 0, x, y, val);
		}

		int get(int l, int r, int c, int x, int y)
		{
			check(c, l, r);
			if (l > r || x > y || l > y || x > r) 

				return 0;
			else if (x <= l && y >= r)
				return arr[c];
			int mid = l + r >> 1;
			return merge(get(l, mid, (c << 1) + 1, x, y), get(mid + 1, r, (c << 1) + 2, x, y));
		}

		int ans(int x, int y)
		{
			return get(0, n - 1, 0, x, y);
		}
	}

	

	static void solve()
	{
		int n = in.ni();
		int arr[] = new int[n + 1];
		int tmp[] = new int[3 * n];
		int cnt = 0;
		HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
		Pair p[] = new Pair[n];
		for (int i = 1; i <= n; i++)
		{
			arr[i] = in.ni();
			p[i - 1] = new Pair(arr[i], i);
			tmp[cnt++] = arr[i] - 1;
			tmp[cnt++] = arr[i];
			tmp[cnt++] = arr[i] + 1;
		}
		Arrays.parallelSort(tmp);
		Arrays.parallelSort(p);
		SegmentTree seg = new SegmentTree(n + 10);
		SegmentTree2 seg2 = new SegmentTree2(n + 10);
		int cnt2 = 0;
		int ans = mx;
		int nm = 0, ans2 = 0;
		for (int i = 0; i < cnt; i++)
		{
			while (cnt2 < n && p[cnt2].u < tmp[i])
			{
				

				int ind = (int) p[cnt2].v;
				int min = ind;
				int max = ind;
				min = Math.min(seg.ans(ind - 1, ind - 1), min);
				max = Math.max(max, seg2.ans(ind + 1, ind + 1));
				if (min != ind && max != ind)
				{
					int length = max - min + 1;
					map.put(ind - min, map.get(ind - min) - 1);
					if (map.get(ind - min) == 0)
						map.remove(ind - min);
					map.put(max - ind, map.get(max - ind) - 1);
					if (map.get(max - ind) == 0)
						map.remove(max - ind);
					if (map.containsKey(length))
						map.put(length, map.get(length) + 1);
					else
						map.put(length, 1);
					seg.up(min, max, min);
					seg2.up(min, max, max);
					nm--;
				} else if (min != ind)
				{
					int length = ind - min + 1;
					map.put(ind - min, map.get(ind - min) - 1);
					if (map.get(ind - min) == 0)
						map.remove(ind - min);
					if (map.containsKey(length))
						map.put(length, map.get(length) + 1);
					else
						map.put(length, 1);
					seg.up(min, ind, min);
					seg2.up(min, ind, ind);
					

				} else if (max != ind)
				{
					int length = max - ind + 1;
					map.put(max - ind, map.get(max - ind) - 1);
					if (map.get(max - ind) == 0)
						map.remove(max - ind);
					if (map.containsKey(length))
						map.put(length, map.get(length) + 1);
					else
						map.put(length, 1);
					seg.up(ind, max, ind);
					seg2.up(ind, max, max);
					

				} else
				{
					int length = max - min + 1;
					if (map.containsKey(length))
						map.put(length, map.get(length) + 1);
					else
						map.put(length, 1);
					seg.up(min, max, min);
					seg2.up(min, max, max);
					nm++;
					

				}
				cnt2++;
			}
			if (map.size() == 1)
			{
				if (ans2 < nm)
				{
					ans = tmp[i];
					ans2 = nm;
				}
			}
		}
		out.println(ans);
	}

	public static class Pair implements Comparable<Pair>
	{
		long u;
		long v;

		public Pair(long u, long v)
		{
			this.u = u;
			this.v = v;
		}

		public int hashCode()
		{
			int hu = (int) (u ^ (u >>> 32));
			int hv = (int) (v ^ (v >>> 32));
			return 31 * hu + hv;
		}

		public boolean equals(Object o)
		{
			Pair other = (Pair) o;
			return u == other.u && v == other.v;
		}

		public int compareTo(Pair other)
		{
			return Long.compare(u, other.u) != 0 ? Long.compare(u, other.u) : Long.compare(v, other.v);
		}

		public String toString()
		{
			return u + " " + v;
		}
	}

	static int[][] graph(int from[], int to[], int n, int cn)
	{
		int g[][] = new int[n][];
		int cnt[] = new int[n];
		for (int i = 0; i < cn; i++)
		{
			cnt[from[i]]++;
			

		}
		for (int i = 0; i < n; i++)
			g[i] = new int[cnt[i]];
		Arrays.fill(cnt, 0);
		for (int i = 0; i < cn; i++)
		{
			g[from[i]][cnt[from[i]]++] = to[i];
			

		}
		return g;
	}

	@SuppressWarnings("rawtypes")
	static void soln()
	{
		in = new InputReader(System.in);
		out = new PrintWriter(System.out);
		solve();
		out.flush();
	}

	static void debug(Object... o)
	{
		System.out.println(Arrays.deepToString(o));
	}

	public static void main(String[] args)
	{
		new Thread(null, new Runnable()
		{
			public void run()
			{
				try
				{
					soln();
				} catch (Exception e)
				{
					e.printStackTrace();
				}
			}
		}, "1", 1 << 26).start();
	}

	

	

	static class InputReader<SpaceCharFilter>
	{

		private final InputStream stream;
		private final byte[] buf = new byte[8192];
		private int curChar, snumChars;
		private SpaceCharFilter filter;

		public InputReader(InputStream stream)
		{
			this.stream = stream;
		}

		public int snext()
		{
			if (snumChars == -1)
				throw new InputMismatchException();
			if (curChar >= snumChars)
			{
				curChar = 0;
				try
				{
					snumChars = stream.read(buf);
				} catch (IOException e)
				{
					throw new InputMismatchException();
				}
				if (snumChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		public int ni()
		{
			int c = snext();
			while (isSpaceChar(c))
			{
				c = snext();
			}
			int sgn = 1;
			if (c == '-')
			{
				sgn = -1;
				c = snext();
			}
			int res = 0;
			do
			{
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public long nl()
		{
			int c = snext();
			while (isSpaceChar(c))
			{
				c = snext();
			}
			int sgn = 1;
			if (c == '-')
			{
				sgn = -1;
				c = snext();
			}
			long res = 0;
			do
			{
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public int[] nextIntArray(int n)
		{
			int a[] = new int[n];
			for (int i = 0; i < n; i++)
			{
				a[i] = ni();
			}
			return a;
		}

		public long[] nextLongArray(int n)
		{
			long a[] = new long[n];
			for (int i = 0; i < n; i++)
			{
				a[i] = nl();
			}
			return a;
		}

		public String readString()
		{
			int c = snext();
			while (isSpaceChar(c))
			{
				c = snext();
			}
			StringBuilder res = new StringBuilder();
			do
			{
				res.appendCodePoint(c);
				c = snext();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		public String nextLine()
		{
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			StringBuilder res = new StringBuilder();
			do
			{
				res.appendCodePoint(c);
				c = snext();
			} while (!isEndOfLine(c));
			return res.toString();
		}

		public boolean isSpaceChar(int c)
		{
			if (filter != null)
				return filter.isSpaceChar(c);
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		private boolean isEndOfLine(int c)
		{
			return c == '\n' || c == '\r' || c == -1;
		}

		public interface SpaceCharFilter
		{
			public boolean isSpaceChar(int ch);
		}

	}
}