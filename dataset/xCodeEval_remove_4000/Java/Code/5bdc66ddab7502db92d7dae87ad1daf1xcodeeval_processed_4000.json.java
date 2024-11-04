


import java.io.*;
import java.util.*;

public final class TaskC
{
	public static void main(String[] args)
	{
		InputReader in = new InputReader(System.in);
		PrintWriter out = new PrintWriter(System.out);
		Solver solver = new Solver(in, out);

		solver.solve();
		in.close();
		out.flush();
		out.close();
	}

	static class Solver
	{
		int n, k;
		Point[] pts;
		Q[] qs;
		InputReader in;
		PrintWriter out;

		void solve()
		{
			n = in.nextInt();
			k = in.nextInt();
			pts = new Point[n];

			for (int i = 0; i < n; i++)
				pts[i] = new Point(i, in.nextInt(), in.nextInt());

			Arrays.sort(pts, new Comparator<Point>()
			{
				@Override public int compare(Point o1, Point o2)
				{
					if (o1.l == o2.l)
						return Integer.compare(o1.r, o2.r);

					return Integer.compare(o1.l, o2.l);
				}
			});

			PriorityQueue<Integer> queue = new PriorityQueue<>();

			for (int i = 0; i < k; i++)
				queue.add(pts[i].r);

			int max = queue.peek() - pts[k - 1].l + 1;
			int ml, mr;

			ml = pts[k - 1].l;
			mr = queue.peek();

			for (int i = k; i < n; i++)
			{
				queue.poll();
				queue.add(pts[i].r);

				int curr = queue.peek() - pts[i].l + 1;

				if (curr > max)
				{
					max = curr;
					ml = pts[i].l;
					mr = queue.peek();
				}
			}

			if (max <= 0)
			{
				out.println(0);

				for (int i = 1; i <= k; i++)
					out.print(i + " ");
			}
			else
			{
				out.println(max);

				for (int i = 0; i < n && k > 0; i++)
				{
					if (pts[i].l <= ml && pts[i].r >= mr)
					{
						out.print(pts[i].id + 1 + " ");
						k--;
					}
				}
			}

			
		}

		void solve2()
		{
			n = in.nextInt();
			k = in.nextInt();
			pts = new Point[n];

			for (int i = 0; i < n; i++)
				pts[i] = new Point(i, in.nextInt(), in.nextInt());

			PriorityQueue<Integer> lefts = new PriorityQueue<>(Collections.reverseOrder());
			int ctr = 0;

			qs = new Q[2 * n];


			for (int i = 0; i < n; i++)
			{
				qs[ctr++] = new Q(i, pts[i].l, 'l', pts[i].r);
				qs[ctr++] = new Q(i, pts[i].r, 'r', pts[i].l);
			}

			Arrays.sort(qs, new Comparator<Q>()
			{
				@Override public int compare(Q o1, Q o2)
				{
					if (o1.x == o2.x)
						return Character.compare(o1.type, o2.type);

					return Integer.compare(o1.x, o2.x);
				}
			});

			int ans, ml, mr;

			ans = ml = mr = 0;

			for (int i = 0; i < n << 1; i++)
			{
				if (qs[i].type == 'l')
					lefts.add(qs[i].x);
				else
				{
					if (lefts.size() >= k && qs[i].x - lefts.peek() + 1 > ans)
					{
						ans = qs[i].x - lefts.peek() + 1;
						ml = lefts.peek();
						mr = qs[i].x;
					}

					lefts.remove(qs[i].other);
				}
			}

			List<Integer> list = new ArrayList<>(k);

			for (int i = 0; i < n; i++)
			{
				if (pts[i].l <= ml && pts[i].r >= mr)
				{
					list.add(pts[i].id);

					if (list.size() == k)
						break;
				}
			}




			if (list.size() < k)
			{
				out.println(0);

				for (int i = 1; i <= k; i++)
					out.print(i + " ");
			}
			else
			{
				out.println(ans);

				for (int x : list)
					out.print(x + 1 + " ");
			}
		}

		class Point
		{
			int id, l, r;

			public Point(int id, int l, int r)
			{
				this.id = id;
				this.l = l;
				this.r = r;
			}

			@Override public String toString()
			{
				return String.format("%d -> (%d, %d)", id, l, r);


			}

		}

		class Q
		{
			int id, x, other;
			char type;

			public Q(int id, int x, char type, int other)
			{
				this.id = id;
				this.x = x;
				this.type = type;
				this.other = other;
			}

		}



		public Solver(InputReader in, PrintWriter out)
		{
			this.in = in;
			this.out = out;
		}

	}

	static class InputReader
	{
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;

		public InputReader(InputStream stream)
		{
			this.stream = stream;
		}

		public int read()
		{
			if (numChars == -1)
				throw new InputMismatchException();

			if (curChar >= numChars)
			{
				curChar = 0;
				try
				{
					numChars = stream.read(buf);
				}
				catch (IOException e)
				{
					throw new InputMismatchException();
				}
				if (numChars <= 0)
					return -1;
			}

			return buf[curChar++];
		}

		public int nextInt()
		{
			int c = read();

			while (id2(c))
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
				res += c & 15;

				c = read();
			} while (!id2(c));

			return res * sgn;
		}

		public int[] id1(int arraySize)
		{
			int array[] = new int[arraySize];

			for (int i = 0; i < arraySize; i++)
				array[i] = nextInt();

			return array;
		}

		public long nextLong()
		{
			int c = read();

			while (id2(c))
				c = read();

			int sign = 1;

			if (c == '-')
			{
				sign = -1;

				c = read();
			}

			long result = 0;

			do
			{
				if (c < '0' || c > '9')
					throw new InputMismatchException();

				result *= 10;
				result += c & 15;

				c = read();
			} while (!id2(c));

			return result * sign;
		}

		public long[] id3(int arraySize)
		{
			long array[] = new long[arraySize];

			for (int i = 0; i < arraySize; i++)
				array[i] = nextLong();

			return array;
		}

		public float nextFloat()
		{
			float result, div;
			byte c;

			result = 0;
			div = 1;
			c = (byte) read();

			while (c <= ' ')
				c = (byte) read();

			boolean isNegative = (c == '-');

			if (isNegative)
				c = (byte) read();

			do
			{
				result = result * 10 + c - '0';
			} while ((c = (byte) read()) >= '0' && c <= '9');

			if (c == '.')
				while ((c = (byte) read()) >= '0' && c <= '9')
					result += (c - '0') / (div *= 10);

			if (isNegative)
				return -result;

			return result;
		}

		public double nextDouble()
		{
			double ret = 0, div = 1;
			byte c = (byte) read();

			while (c <= ' ')
				c = (byte) read();

			boolean neg = (c == '-');

			if (neg)
				c = (byte) read();

			do
			{
				ret = ret * 10 + c - '0';
			} while ((c = (byte) read()) >= '0' && c <= '9');

			if (c == '.')
				while ((c = (byte) read()) >= '0' && c <= '9')
					ret += (c - '0') / (div *= 10);

			if (neg)
				return -ret;

			return ret;
		}

		public String next()
		{
			int c = read();

			while (id2(c))
				c = read();

			StringBuilder res = new StringBuilder();

			do
			{
				res.appendCodePoint(c);

				c = read();
			} while (!id2(c));

			return res.toString();
		}

		public boolean id2(int c)
		{
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		public String nextLine()
		{
			int c = read();

			StringBuilder result = new StringBuilder();

			do
			{
				result.appendCodePoint(c);

				c = read();
			} while (!id0(c));

			return result.toString();
		}

		public boolean id0(int c)
		{
			return c == '\n';
		}

		public void close()
		{
			try
			{
				stream.close();
			}
			catch (IOException e)
			{
				e.printStackTrace();
			}
		}

	}

}
