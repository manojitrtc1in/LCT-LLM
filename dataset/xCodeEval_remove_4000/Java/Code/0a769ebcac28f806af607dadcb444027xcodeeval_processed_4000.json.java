import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.io.BufferedInputStream;
import java.util.Iterator;
import java.util.concurrent.Callable;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.NavigableSet;
import java.util.TreeSet;
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
			while (id1(c))
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
			} while (!id1(c));
			return res * sgn;
		}

		public static boolean id1(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		public void close() {

		}

	}

	static class Rational implements Comparable<Rational> {
		private long a;
		private long b;

		public Rational() {
			a = 0;
			b = 1;
		}

		public static boolean id8(long a1, long b1, long a2, long b2) {
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
			else if (!id8(a, b, o.a, o.b)) ret = 1;

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

	static class Task implements Callable<Task> {
		int n;
		long[] a;
		long re = 0;
		int testNumber;

		public void readInput(InputReader in) {
	
			n = in.nextInt();
			a = new long[n + 1];
			for (int i = 0; i < n; ++i) a[i] = in.nextInt();
		}

		public Task call() {
	
			long[] b = new long[n + 1];
			long[] s = new long[n + 1];
			long[] S = new long[n + 1];
			for (int i = 0; i < n; ++i) b[i] = (i + 1) * a[i];
			MathUtils.id5(a, s);
			MathUtils.id5(b, S);
			id12 cv = new id12();
			cv.addLine(-s[n], S[n]);
			for (int i = n - 1; i >= 0; --i) {
				cv.addLine(-s[i], S[i]);
				long temp = -MathUtils.id9(S, 0, i - 1)
						+ i * MathUtils.id9(s, 0, i - 1)
						+ cv.query(i);
				re = Math.max(re, temp);



			}

			System.err.println("Test case: " + testNumber + " done!");
			return this;
		}

		public void writeOutput(PrintWriter out) {
			out.println(re);
		}

		Task(int testNumber) {
			this.testNumber = testNumber;
		}

	}

	static class MathUtils {
		public static void id5(long[] a, long[] sum) {
			for (int i = 0; i < a.length; ++i) {
				sum[i] = a[i];
				sum[i] += (i > 0 ? sum[i - 1] : 0);
			}
		}

		public static long id9(long[] sum, int a, int b) {
			if (a > b) return 0;

			long ret = sum[b];
			ret -= (a > 0 ? sum[a - 1] : 0);
			return ret;
		}

	}

	static final class id0 {
		static long id4(String role, long x) {
			if (x < 0) {
				throw new IllegalArgumentException(role + " (" + x + ") must be >= 0");
			}
			return x;
		}

		static void id11(boolean condition) {
			if (!condition) {
				throw new ArithmeticException("overflow");
			}
		}

		private id0() {
		}

	}

	static final class LongMath {
		public static long gcd(long a, long b) {
	
			id0.id4("a", a);
			id0.id4("b", b);
			if (a == 0) {
				

				

				return b;
			} else if (b == 0) {
				return a; 

			}
    
			int id10 = Long.numberOfTrailingZeros(a);
			a >>= id10; 

			int id3 = Long.numberOfTrailingZeros(b);
			b >>= id3; 

			while (a != b) { 

				

				

				


				

				


				long delta = a - b; 


				long id6 = delta & (delta >> (Long.SIZE - 1));
				


				a = delta - id6 - id6; 

				


				b += id6; 

				a >>= Long.numberOfTrailingZeros(a); 

			}
			return a << Math.min(id10, id3);
		}

		public static long checkedAdd(long a, long b) {
			long result = a + b;
			id0.id11((a ^ b) < 0 | (a ^ result) >= 0);
			return result;
		}

		public static long checkedMultiply(long a, long b) {
			

			int leadingZeros =
					Long.numberOfLeadingZeros(a)
							+ Long.numberOfLeadingZeros(~a)
							+ Long.numberOfLeadingZeros(b)
							+ Long.numberOfLeadingZeros(~b);
    
			if (leadingZeros > Long.SIZE + 1) {
				return a * b;
			}
			id0.id11(leadingZeros >= Long.SIZE);
			id0.id11(a >= 0 | b != Long.MIN_VALUE);
			long result = a * b;
			id0.id11(a == 0 || result / a == b);
			return result;
		}

		private LongMath() {
		}

	}

	static class id2 {
		private TreeSet<id2.Line> hull = new TreeSet<>();
		private id2.Line id7;

		public id2() {

			id7 = new id2.Line(0, 0);
			id7.isQuery = true;


		}

		public void addLine(long a, long b) {
			id2.Line l = new id2.Line(a, b);
			id2.Line it = hull.ceiling(l);
			id2.Line pre, next;
			if (it != null && l.a == it.a) {
				if (it.b <= l.b) return;
				else {
					it.b = b;
					l = it;
				}
			} else {
				if ((pre = hull.lower(l)) != null
						&& (next = hull.higher(l)) != null
						&& id2.Line.bad(pre, l, next)) {
					return;
				}
				hull.add(l);
			}

			pre = null;
			next = null;
			NavigableSet<id2.Line> headSet = hull.headSet(l, false);
			Iterator<id2.Line> iter = headSet.descendingIterator();
			Iterator<id2.Line> iter2 = headSet.descendingIterator();
			id2.Line l3 = l, l2, l1;

			int cnt = 0;
			if (iter.hasNext()) {
				l2 = iter.next();
				pre = l2;


				while (iter.hasNext()) {
					l1 = iter.next();
					if (id2.Line.bad(l1, l2, l3)) {
						

						

						cnt++;
						l2 = l1;
						pre = l2;
					} else {
						break;
					}
				}
				for (int i = 0; i < cnt; ++i) {
					iter2.next();
					iter2.remove();
				}
			}

			l1 = l;

			NavigableSet<id2.Line> tailSet = hull.tailSet(l, false);
			iter = tailSet.iterator();
			iter2 = tailSet.iterator();

			if (iter.hasNext()) {
				l2 = iter.next();
				next = l2;
				cnt = 0;
				while (iter.hasNext()) {
					l3 = iter.next();

					if (id2.Line.bad(l1, l2, l3)) {
						

						cnt++;
						l2 = l3;
						next = l2;
					} else {
						break;
					}
				}
				for (int i = 0; i < cnt; ++i) {
					iter2.next();
					iter2.remove();
				}
			}

			if (pre != null) {
				l.p = id2.Line.intersect(pre, l);

			} else {
				l.p = id2._Rational.MIN_VALUE;
			}

			if (next != null) {
				next.p = id2.Line.intersect(l, next);
			}
		}

		public long query(long x) {
			id7.x = x;
			id2.Line it = hull.lower(id7);
			if (it == null) throw new RuntimeException();




			return it.calc(x);
		}

		private static class _Rational implements Comparable<id2._Rational> {
			public static final id2._Rational MIN_VALUE = new id2._Rational(Long.MIN_VALUE + 2, 1);
			long a;
			long b;

			public _Rational(long a, long b) {

				long g = LongMath.gcd(Math.abs(a), Math.abs(b));
				if (b < 0) g = -g;
				this.a = a / g;
				this.b = b / g;

			}


			public int compareTo(id2._Rational o) {
				return Long.compare((a * o.b), (b * o.a));
			}


			public String toString() {
				return "_Rational{" +
						"a=" + a +
						", b=" + b +
						'}';
			}

		}

		private static class Line implements Comparable<id2.Line> {
			long a;
			long b;
			id2._Rational p;
			boolean isQuery = false;
			long x = 0;

			public Line(long a, long b) {
				this.a = a;
				this.b = b;
			}


			public int compareTo(id2.Line o) {
				if (isQuery) {
					int ret = -1;
					if (x == o.p.a && o.p.b == 1) ret = 1;
					else if (!Rational.id8(x, 1, o.p.a, o.p.b)) ret = 1;
					return ret;
					

				} else
					return Long.compare(o.a, a);
			}

			static boolean bad(id2.Line l1, id2.Line l2, id2.Line l3) {

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

				return Rational.id8(a2, b2, a1, b1);
				

			}

			static id2._Rational intersect(id2.Line l1, id2.Line l2) {
				return new id2._Rational(l1.b - l2.b, l2.a - l1.a);
			}

			public long calc(long x) {
				return LongMath.checkedAdd(LongMath.checkedMultiply(a, x), b);
			}

		}

	}

	static class id12 extends id2 {
		public id12() {
			super();
		}


		public void addLine(long a, long b) {
			super.addLine(-a, -b);
		}


		public long query(long x) {
			return -super.query(x);
		}

	}
}

