import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.util.Arrays;
import java.io.BufferedInputStream;
import java.util.concurrent.Callable;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Collections;
import java.io.InputStream;

public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		BufferedInputStream in = new BufferedInputStream(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskF solver = new TaskF();
		solver.solve(1, in, out);
		out.close();
	}

	static class TaskF {
		public void solve(int testNumber, BufferedInputStream _in, PrintWriter out) {

			InputReader in = new InputReader(_in);
			long startTime = System.currentTimeMillis();
			int nt = 1;
			Task t = new Task(1);
			t.readInput(in);
			t.call();
			t.writeOutput(out);
			in.close();
			System.err.println("Time: " + (System.currentTimeMillis() - startTime) + " miliseconds");
		}

	}

	static class StaticConvexHullTrickMaxAscent {
		ArrayList<StaticConvexHullTrickMaxAscent.Li> hull;
		StaticConvexHullTrickMaxAscent.Li queryLine;

		public StaticConvexHullTrickMaxAscent() {

			hull = new ArrayList<>();
			queryLine = new StaticConvexHullTrickMaxAscent.Li(0, 0, 0, 0);

		}

		void intersect(StaticConvexHullTrickMaxAscent.Li l1, StaticConvexHullTrickMaxAscent.Li l2, StaticConvexHullTrickMaxAscent.Li ret) {
			ret.ax = (l1.b - l2.b);
			ret.bx = (l2.a - l1.a);
			if (DynamicConvexHullTrickMin.CHECK_OVERFLOW) {
				

				long g = LongMath.gcd(Math.abs(ret.ax), Math.abs(ret.bx));
				if (ret.bx < 0) g = -g;
				ret.ax /= g;
				ret.bx /= g;
			} else {
				if (ret.bx < 0) {
					ret.ax = -ret.ax;
					ret.bx = -ret.bx;
				}
			}
		}

		public long query(long xx) {

			if (hull.size() == 0) throw new RuntimeException();
			queryLine.x = xx;
			int low = MathUtils.lowerBound(hull, 0, hull.size(), queryLine, (o1, o2) -> {

				if (DynamicConvexHullTrickMin.CHECK_OVERFLOW) {
					int ret = -1;
					if (o1.x == o2.ax && o2.bx == 1) ret = 1;
					else if (!Rational.checkLessRational(o1.x, 1, o2.ax, o2.bx)) ret = 1;
					return ret;
				} else {
					return Long.compare((o1.x * o2.bx), o2.ax);
				}

			}) - 1;
			return hull.get(low).calc(xx);
		}

		public static class Li {
			long a;
			long b;
			long ax;
			long bx;
			long x;

			public Li(long a, long b, long ax, long bx) {
				this.a = a;
				this.b = b;
				this.ax = ax;
				this.bx = bx;
			}

			long calc(long x) {
				return a * x + b;
			}

		}

	}

	static class MathUtils {
		public static <T> int lowerBound(ArrayList<T> a, int first, int last, T key, Comparator<T> cmp) {
			int count = last - first, step;
			int it;
			while (count > 0) {
				it = first;
				step = count / 2;
				it += step;
				

				int _cmp = -cmp.compare(key, a.get(it));
				if (_cmp < 0) {
					first = ++it;
					count -= step + 1;
				} else
					count = step;
			}
			return first;
		}

	}

	static class StaticConvexHullTrickMinDescent extends StaticConvexHullTrickMaxAscent {
		public StaticConvexHullTrickMinDescent() {
			super();
		}

		boolean bad(StaticConvexHullTrickMaxAscent.Li l1, StaticConvexHullTrickMaxAscent.Li l2, StaticConvexHullTrickMaxAscent.Li l3) {
			if (DynamicConvexHullTrickMin.CHECK_OVERFLOW) {
				long a1 = l2.b - l1.b;
				long b1 = l1.a - l2.a;

				long a2 = l3.b - l1.b;
				long b2 = l1.a - l3.a;


				long g = LongMath.gcd(Math.abs(a1), Math.abs(b1));
				if (b1 < 0) g = -g;
				a1 /= g;
				b1 /= g;

				g = LongMath.gcd(Math.abs(a2), Math.abs(b2));
				if (b2 < 0) g = -g;
				a2 /= g;
				b2 /= g;

				if (a1 == a2 && b1 == b2) return true;
				return Rational.checkLessRational(a2, b2, a1, b1);
			} else {
				return ((l3.b - l1.b) * (l1.a - l2.a)) <= ((l2.b - l1.b) * (l1.a - l3.a));
			}

		}

		void addLine(long a, long b) {
			int sz = hull.size();
			if (sz > 0 && a == hull.get(sz - 1).a) {
				if (b == hull.get(sz - 1).b) return;
				if (b > hull.get(sz - 1).b) return;
				hull.remove(sz - 1);
				sz--;
			}
			StaticConvexHullTrickMaxAscent.Li line = new StaticConvexHullTrickMaxAscent.Li(a, b, Long.MIN_VALUE + 2, 1);

			while (sz >= 2 && bad(hull.get(sz - 2), hull.get(sz - 1), line)) {
				hull.remove(sz - 1);
				sz--;
			}
			hull.add(line);
			sz++;
			if (sz > 1) {
				intersect(hull.get(sz - 1), hull.get(sz - 2), hull.get(sz - 1));
			}

		}

	}

	static class Rational implements Comparable<Rational> {
		private long a;
		private long b;

		public long getA() {
			return a;
		}

		public long getB() {
			return b;
		}

		public Rational() {
			a = 0;
			b = 1;
		}

		public static boolean checkLessRational(long a1, long b1, long a2, long b2) {
			long tsn = a1;
			long tsd = b1;
			long tsq = a1 / b1;
			long tsr = a1 % b1;

			long rsn = a2;
			long rsd = b2;
			long rsq = a2 / b2;
			long rsr = a2 % b2;

			int reverse = 0;


			while (tsr < 0) {
				tsr += tsd;
				--tsq;
			}
			while (rsr < 0) {
				rsr += rsd;
				--rsq;
			}

			

			for (; ; ) {
				

				

				

				if (tsq != rsq) {
					

					

					

					return reverse != 0 ? tsq > rsq : tsq < rsq;
				}

				

				reverse ^= 1;

				if ((tsr == 0) || (rsr == 0)) {
					

					break;
				}

				tsn = tsd;
				tsd = tsr;
				tsq = tsn / tsd;
				tsr = tsn % tsd;
				rsn = rsd;
				rsd = rsr;
				rsq = rsn / rsd;
				rsr = rsn % rsd;
			}

			

			if (tsr == rsr) {
				

				

				

				return false;
			} else {

				

				

				

				

				return (tsr != 0) != (reverse != 0);

			}
		}

		public Rational(long a, long b) {
			this.a = a;
			this.b = b;
			if (b == 0) throw new RuntimeException();
			reduce();
		}

		public void reduce() {
			long g = LongMath.gcd(Math.abs(a), Math.abs(b));
			if (b < 0) g = -g;
			this.a /= g;
			this.b /= g;
		}


		public int compareTo(Rational o) {
			int ret = -1;
			if (a == o.a && b == o.b) ret = 0;
			else if (!checkLessRational(a, b, o.a, o.b)) ret = 1;

			return ret;
			

		}


		public String toString() {
			return +a + "/" + b;
		}


		public int hashCode() {
			return Long.hashCode(a) ^ Long.hashCode(b);
		}

		public boolean equals(Object obj) {
			if (obj instanceof Rational) {
				return this.compareTo((Rational) obj) == 0;
			}
			return false;
		}

	}

	static final class MathPreconditions {
		static long checkNonNegative(String role, long x) {
			if (x < 0) {
				throw new IllegalArgumentException(role + " (" + x + ") must be >= 0");
			}
			return x;
		}

		private MathPreconditions() {
		}

	}

	static class SegmentData {
		int a;
		int b;
		StaticConvexHullTrickMinDescent cv = new StaticConvexHullTrickMinDescent();

		public SegmentData(int a, int b) {
			this.a = a;
			this.b = b;
		}

	}

	static class DynamicConvexHullTrickMin {
		public static final boolean CHECK_OVERFLOW = false;
		private DynamicConvexHullTrickMin.Line forQueryLine;

		public DynamicConvexHullTrickMin() {
			forQueryLine = new DynamicConvexHullTrickMin.Line(0, 0);
			forQueryLine.isQuery = true;
		}

		static class Line implements Comparable<DynamicConvexHullTrickMin.Line> {
			long a;
			long b;
			Rational p;
			boolean isQuery = false;
			long x = 0;

			public Line(long a, long b) {
				this.a = a;
				this.b = b;
			}


			public int compareTo(DynamicConvexHullTrickMin.Line o) {
				if (isQuery) {
					if (CHECK_OVERFLOW) {
						int ret = -1;
						if (x == o.p.getA() && o.p.getB() == 1) ret = 1;
						else if (!Rational.checkLessRational(x, 1, o.p.getA(), o.p.getB())) ret = 1;
						return ret;
					} else {
						return Long.compare((x * o.p.getB()), o.p.getA());
					}
				} else {
					return Long.compare(o.a, a);

				}
			}


			public String toString() {
				return "Line{" +
						"a=" + a +
						", b=" + b +
						'}';
			}

		}

	}

	static class Task implements Callable<Task> {
		ArrayList<Triple<Integer, Integer, Integer>> listLine = new ArrayList<>();
		int[] end;
		int[] type;
		int[] q;
		int n;
		int testNumber;

		public void readInput(InputReader in) {
	
			n = in.nextInt();
			end = new int[n];
			q = new int[n];
			type = new int[n];
			Arrays.fill(end, n);

			for (int i = 0; i < n; ++i) {
				type[i] = in.nextInt();


				switch (type[i]) {
					case 1: {
						Triple<Integer, Integer, Integer> li = new Triple<>(-in.nextInt(), -in.nextInt(), i);
						listLine.add(li);
					}
					break;
					case 2: {
						q[i] = in.nextInt() - 1;
						end[q[i]] = i;

					}
					break;

					case 3: {
						q[i] = in.nextInt();

					}
					break;
				}
			}
		}

		public Task call() {
	

			return this;
		}

		public void writeOutput(PrintWriter out) {

			SegmentTree st = new SegmentTree(n);
			Collections.sort(listLine, Comparator.reverseOrder());
			for (Triple<Integer, Integer, Integer> trip : listLine) {
				st.update(1, 0, st.sz - 1, trip.third, end[trip.third], trip.first.longValue(), trip.second.longValue());
			}

			for (int i = 0; i < n; ++i)
				if (type[i] == 3) {
					long ret = st.query(1, 0, st.sz - 1, i, i, q[i]);
					if (ret == Long.MIN_VALUE) out.println("EMPTY SET");
					else out.println(ret);
				}
			System.err.println("Test case: " + testNumber + " done!");

			

		}

		Task(int testNumber) {
			this.testNumber = testNumber;
		}

	}

	static final class LongMath {
		public static long gcd(long a, long b) {
	
			MathPreconditions.checkNonNegative("a", a);
			MathPreconditions.checkNonNegative("b", b);
			if (a == 0) {
				

				

				return b;
			} else if (b == 0) {
				return a; 

			}
    
			int aTwos = Long.numberOfTrailingZeros(a);
			a >>= aTwos; 

			int bTwos = Long.numberOfTrailingZeros(b);
			b >>= bTwos; 

			while (a != b) { 

				

				

				


				

				


				long delta = a - b; 


				long minDeltaOrZero = delta & (delta >> (Long.SIZE - 1));
				


				a = delta - minDeltaOrZero - minDeltaOrZero; 

				


				b += minDeltaOrZero; 

				a >>= Long.numberOfTrailingZeros(a); 

			}
			return a << Math.min(aTwos, bTwos);
		}

		private LongMath() {
		}

	}

	static class Triple<T1 extends Comparable<T1>, T2 extends Comparable<T2>, T3 extends Comparable<T3>> implements Comparable<Triple<T1, T2, T3>> {
		public T1 first;
		public T2 second;
		public T3 third;

		public Triple(T1 first, T2 second, T3 third) {
			this.first = first;
			this.second = second;
			this.third = third;
		}


		public String toString() {
			return first + " " + second + " " + third;
		}


		public int compareTo(Triple<T1, T2, T3> o) {
			int t = first.compareTo(o.first);
			if (t != 0) return t;
			t = second.compareTo(o.second);
			if (t != 0) return t;
			return third.compareTo(o.third);
		}


		public int hashCode() {
			return first.hashCode() ^ second.hashCode() ^ third.hashCode();
		}

		public boolean equals(Object obj) {
			if (obj instanceof Triple) {
				Triple p = (Triple) obj;
				return first.equals(p.first) && second.equals(p.second) && third.equals(p.third);
			}
			return false;
		}

	}

	static class SegmentTree {
		SegmentData[] data;
		int sz;

		SegmentTree(int n) {
			for (sz = 1; sz < n; sz <<= 1) ;
			data = new SegmentData[2 * sz];
			init(1, 0, sz - 1);

		}

		public void init(int node, int b, int e) {
			if (e > b) {
				init(2 * node, b, (b + e) / 2);
				init(2 * node + 1, (b + e) / 2 + 1, e);
			}
			data[node] = new SegmentData(b, e);
		}

		public void update(int node, int b, int e, int ii, int jj, long la, long lb) {
			if (ii > e || jj < b) {
				return;
			}

			if (b >= ii && e <= jj) {
				data[node].cv.addLine(la, lb);
				return;
			}

			int left = 2 * node;
			int right = left + 1;


			update(left, b, (b + e) / 2, ii, jj, la, lb);
			update(right, (b + e) / 2 + 1, e, ii, jj, la, lb);
		}

		public long query(int node, int b, int e, int ii, int jj, long x) {
			if (ii > e || jj < b) {
				return Long.MIN_VALUE;
			}

			if (b >= ii && e <= jj) {
				if (data[node].cv.hull.size() > 0) return -data[node].cv.query(x);
				return Long.MIN_VALUE;
			}

			int left = 2 * node;
			int right = left + 1;
			long temp = Long.MIN_VALUE;
			if (data[node].cv.hull.size() > 0)
				temp = -data[node].cv.query(x);

			return Math.max(temp, Math.max(query(left, b, (b + e) / 2, ii, jj, x), query(right, (b + e) / 2 + 1, e, ii, jj, x)));
		}

	}

	static class InputReader {
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;

		public InputReader(InputStream stream) {
			this.stream = stream;
		}

		public int read() {
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

		public int nextInt() {
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
		public static boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		public void close() {

		}

	}
}