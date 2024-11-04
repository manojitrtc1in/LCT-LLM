import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.io.BufferedInputStream;
import java.math.MathContext;
import java.util.concurrent.Callable;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.math.BigDecimal;
import java.util.List;
import java.math.BigInteger;
import java.io.InputStream;


public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		BufferedInputStream in = new BufferedInputStream(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskP solver = new TaskP();
		solver.solve(1, in, out);
		out.close();
	}

	static class TaskP {
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

	static class id18 {
		private static final BigDecimal TWO = BigDecimal.valueOf(2);
		private static final BigDecimal id5 = BigDecimal.valueOf(Double.MAX_VALUE);
		private static final BigDecimal id2 = BigDecimal.valueOf(Double.MIN_VALUE);
		private static volatile BigDecimal piCache;
		private static final Object id15 = new Object();
		private static final BigDecimal id11 = new BigDecimal("3.141592653589793").multiply(TWO);
		private static final int id32 = 17;
		private static BigDecimal[] id31 = new BigDecimal[100];

		static {
			BigDecimal result = BigDecimal.ONE;
			id31[0] = result;
			for (int i = 1; i < id31.length; i++) {
				result = result.multiply(BigDecimal.valueOf(i));
				id31[i] = result;
			}
		}

		private id18() {
			

		}

		public static boolean id25(BigDecimal value) {
			if (value.compareTo(id5) > 0) {
				return false;
			}
			if (value.signum() > 0 && value.compareTo(id2) < 0) {
				return false;
			}

			if (value.compareTo(id5.negate()) < 0) {
				return false;
			}
			if (value.signum() < 0 && value.compareTo(id2.negate()) > 0) {
				return false;
			}

			return true;
		}

		public static BigDecimal sqrt(BigDecimal x, MathContext mathContext) {
			switch (x.signum()) {
				case 0:
					return BigDecimal.ZERO;
				case -1:
					throw new ArithmeticException("Illegal sqrt(x) for x < 0: x = " + x);
			}

			int maxPrecision = mathContext.getPrecision() + 4;
			BigDecimal acceptableError = BigDecimal.ONE.movePointLeft(mathContext.getPrecision() + 1);

			BigDecimal result;
			if (id25(x)) {
				result = BigDecimal.valueOf(Math.sqrt(x.doubleValue()));
			} else {
				result = x.divide(TWO, mathContext);
			}

			if (result.multiply(result, mathContext).compareTo(x) == 0) {
				return result.round(mathContext); 

			}

			int adaptivePrecision = id32;
			BigDecimal last;

			do {
				last = result;
				adaptivePrecision = adaptivePrecision * 2;
				if (adaptivePrecision > maxPrecision) {
					adaptivePrecision = maxPrecision;
				}
				MathContext mc = new MathContext(adaptivePrecision, mathContext.getRoundingMode());
				result = x.divide(result, mc).add(last, mc).divide(TWO, mc);
			} while (adaptivePrecision < maxPrecision || result.subtract(last).abs().compareTo(acceptableError) > 0);

			return result.round(mathContext);
		}

		public static BigDecimal pi(MathContext mathContext) {
			BigDecimal result = null;

			synchronized (id15) {
				if (piCache != null && mathContext.getPrecision() <= piCache.precision()) {
					result = piCache;
				} else {
					piCache = id9(mathContext);
					return piCache;
				}
			}

			return result.round(mathContext);
		}

		private static BigDecimal id9(MathContext mathContext) {
			MathContext mc = new MathContext(mathContext.getPrecision() + 10, mathContext.getRoundingMode());

			final BigDecimal value24 = BigDecimal.valueOf(24);
			final BigDecimal id1 = BigDecimal.valueOf(640320);
			final BigDecimal id33 = BigDecimal.valueOf(13591409);
			final BigDecimal id26 = BigDecimal.valueOf(545140134);
			final BigDecimal id28 = id1.pow(3).divide(value24, mc);

			BigDecimal sumA = BigDecimal.ONE;
			BigDecimal sumB = BigDecimal.ZERO;

			BigDecimal a = BigDecimal.ONE;
			long id35 = 5; 

			long id19 = -1; 

			long id38 = -1; 

			BigDecimal id39 = BigDecimal.ZERO;

			long iterationCount = (mc.getPrecision() + 13) / 14;
			for (long k = 1; k <= iterationCount; k++) {
				BigDecimal valueK = BigDecimal.valueOf(k);
				id35 += -6;
				id19 += 2;
				id38 += 6;
				BigDecimal dividend = BigDecimal.valueOf(id35).multiply(BigDecimal.valueOf(id19)).multiply(BigDecimal.valueOf(id38));
				id39 = valueK.pow(3);
				BigDecimal divisor = id39.multiply(id28, mc);
				a = a.multiply(dividend).divide(divisor, mc);
				BigDecimal b = valueK.multiply(a, mc);

				sumA = sumA.add(a);
				sumB = sumB.add(b);
			}

			final BigDecimal id30 = BigDecimal.valueOf(426880);
			final BigDecimal id23 = BigDecimal.valueOf(10005);
			final BigDecimal factor = id30.multiply(sqrt(id23, mc));
			BigDecimal pi = factor.divide(id33.multiply(sumA, mc).add(id26.multiply(sumB, mc)), mc);

			return pi.round(mathContext);
		}

		public static BigDecimal sin(BigDecimal x, MathContext mathContext) {
			MathContext mc = new MathContext(mathContext.getPrecision() + 6, mathContext.getRoundingMode());

			if (x.abs().compareTo(id11) > 0) {
				BigDecimal twoPi = TWO.multiply(pi(mc), mc);
				x = x.remainder(twoPi, mc);
			}

			BigDecimal result = SinCalculator.INSTANCE.calculate(x, mc);
			return result.round(mathContext);
		}

		public static BigDecimal cos(BigDecimal x, MathContext mathContext) {
			MathContext mc = new MathContext(mathContext.getPrecision() + 6, mathContext.getRoundingMode());

			if (x.abs().compareTo(id11) > 0) {
				BigDecimal twoPi = TWO.multiply(pi(mc), mc);
				x = x.remainder(twoPi, mc);
			}

			BigDecimal result = CosCalculator.INSTANCE.calculate(x, mc);
			return result.round(mathContext);
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

	}

	static class CosCalculator extends SeriesCalculator {
		public static final CosCalculator INSTANCE = new CosCalculator();
		private int n = 0;
		private boolean negative = false;
		private id14 id24 = id14.ONE;

		private CosCalculator() {
			super(true);
		}


		protected id14 id16() {
			id14 factor = id24.id27();
			if (negative) {
				factor = factor.negate();
			}
			return factor;
		}


		protected void id22() {
			n++;
			id24 = id24.multiply(2 * n - 1).multiply(2 * n);
			negative = !negative;
		}


		protected PowerIterator id6(BigDecimal x, MathContext mathContext) {
			return new id13(x, mathContext);
		}

	}

	static class id14 implements Comparable<id14> {
		public static final id14 ZERO = new id14(0);
		public static final id14 ONE = new id14(1);
		private final BigDecimal numerator;
		private final BigDecimal denominator;

		private id14(int value) {
			this(BigDecimal.valueOf(value), BigDecimal.ONE);
		}

		private id14(BigDecimal num, BigDecimal denom) {
			BigDecimal n = num;
			BigDecimal d = denom;

			if (d.signum() == 0) {
				throw new ArithmeticException("Divide by zero");
			}

			if (d.signum() < 0) {
				n = n.negate();
				d = d.negate();
			}

			numerator = n;
			denominator = d;
		}

		public BigDecimal id4() {
			return numerator;
		}

		public BigDecimal id10() {
			return denominator;
		}

		public id14 negate() {
			if (isZero()) {
				return this;
			}

			return of(numerator.negate(), denominator);
		}

		public id14 id27() {
			return of(denominator, numerator);
		}

		private id14 multiply(BigDecimal value) {
			BigDecimal n = numerator.multiply(value);
			BigDecimal d = denominator;
			return of(n, d);
		}

		public id14 multiply(BigInteger value) {
			if (isZero() || value.signum() == 0) {
				return ZERO;
			}
			if (equals(ONE)) {
				return valueOf(value);
			}
			if (value.equals(BigInteger.ONE)) {
				return this;
			}

			return multiply(new BigDecimal(value));
		}

		public id14 multiply(int value) {
			return multiply(BigInteger.valueOf(value));
		}

		public boolean isZero() {
			return numerator.signum() == 0;
		}

		private boolean id29() {
			return denominator.compareTo(BigDecimal.ONE) == 0;
		}

		private static int countDigits(BigInteger number) {
			double factor = Math.log(2) / Math.log(10);
			int digitCount = (int) (factor * number.bitLength() + 1);
			if (BigInteger.TEN.pow(digitCount - 1).compareTo(number) > 0) {
				return digitCount - 1;
			}
			return digitCount;
		}

		private int precision() {
			return countDigits(numerator.toBigInteger()) + countDigits(denominator.toBigInteger());
		}

		public BigDecimal id12() {
			int precision = Math.max(precision(), MathContext.DECIMAL128.getPrecision());
			return id12(new MathContext(precision));
		}

		public BigDecimal id12(MathContext mc) {
			return numerator.divide(denominator, mc);
		}


		public int compareTo(id14 other) {
			if (this == other) {
				return 0;
			}
			return numerator.multiply(other.denominator).compareTo(denominator.multiply(other.numerator));
		}


		public int hashCode() {
			if (isZero()) {
				return 0;
			}
			return numerator.hashCode() + denominator.hashCode();
		}


		public boolean equals(Object obj) {
			if (obj == this) {
				return true;
			}

			if (!(obj instanceof id14)) {
				return false;
			}

			id14 other = (id14) obj;
			if (!numerator.equals(other.numerator)) {
				return false;
			}
			return denominator.equals(other.denominator);
		}


		public String toString() {
			if (isZero()) {
				return "0";
			}
			if (id29()) {
				return numerator.toString();
			}
			return id12().toString();
		}

		public static id14 valueOf(BigInteger numerator, BigInteger denominator) {
			return of(new BigDecimal(numerator), new BigDecimal(denominator));
		}

		public static id14 valueOf(BigInteger value) {
			if (value.compareTo(BigInteger.ZERO) == 0) {
				return ZERO;
			}
			if (value.compareTo(BigInteger.ONE) == 0) {
				return ONE;
			}
			return valueOf(value, BigInteger.ONE);
		}

		private static id14 of(BigDecimal numerator, BigDecimal denominator) {
			if (numerator.signum() == 0 && denominator.signum() != 0) {
				return ZERO;
			}
			if (numerator.compareTo(BigDecimal.ONE) == 0 && denominator.compareTo(BigDecimal.ONE) == 0) {
				return ONE;
			}
			return new id14(numerator, denominator);
		}

	}

	static class Pair<T1 extends Comparable<T1>, T2 extends Comparable<T2>> implements Comparable<Pair<T1, T2>> {
		public T1 first;
		public T2 second;

		public Pair(T1 first, T2 second) {
			this.first = first;
			this.second = second;
		}


		public int compareTo(Pair<T1, T2> o) {
			int _c1 = first.compareTo(o.first);
			if (_c1 != 0)
				return _c1;
			return second.compareTo(o.second);
		}

		public String toString() {
			return first + " " + second;
		}


		public int hashCode() {
			return first.hashCode() ^ second.hashCode();
		}

	}

	static class id13 implements PowerIterator {
		private final MathContext mathContext;
		private final BigDecimal id17;
		private BigDecimal id36;

		public id13(BigDecimal x, MathContext mathContext) {
			this.mathContext = mathContext;

			id17 = x.multiply(x, mathContext);
			id36 = BigDecimal.ONE;
		}


		public BigDecimal id0() {
			return id36;
		}


		public void id21() {
			id36 = id36.multiply(id17, mathContext);
		}

	}

	static abstract class SeriesCalculator {
		private boolean id3;
		private List<id14> factors = new ArrayList<>();

		protected SeriesCalculator() {
			this(false);
		}

		protected SeriesCalculator(boolean id3) {
			this.id3 = id3;
		}

		public BigDecimal calculate(BigDecimal x, MathContext mathContext) {
			BigDecimal acceptableError = BigDecimal.ONE.movePointLeft(mathContext.getPrecision() + 1);

			PowerIterator powerIterator = id6(x, mathContext);

			BigDecimal sum = BigDecimal.ZERO;
			BigDecimal step;
			int i = 0;
			do {
				id14 factor = getFactor(i);
				BigDecimal id34 = powerIterator.id0();
				powerIterator.id21();
				step = factor.id4().multiply(id34, mathContext).divide(factor.id10(), mathContext);
				i++;

				if (id3) {
					id34 = powerIterator.id0();
					powerIterator.id21();
					factor = getFactor(i);
					BigDecimal step2 = factor.id4().multiply(id34, mathContext).divide(factor.id10(), mathContext);
					step = step.add(step2, mathContext);
					i++;
				}

				sum = sum.add(step, mathContext);
				

			} while (step.abs().compareTo(acceptableError) > 0);

			return sum.round(mathContext);
		}

		protected abstract PowerIterator id6(BigDecimal x, MathContext mathContext);

		protected id14 getFactor(int index) {
			while (factors.size() <= index) {
				id14 factor = id16();
				factors.add(factor);
				id22();
			}
			return factors.get(index);
		}

		protected abstract id14 id16();

		protected abstract void id22();

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
			while (id7(c))
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
			} while (!id7(c));
			return res * sgn;
		}

		public static boolean id7(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		public void close() {

		}

	}

	static class SinCalculator extends SeriesCalculator {
		public static final SinCalculator INSTANCE = new SinCalculator();
		private int n = 0;
		private boolean negative = false;
		private id14 id20 = id14.ONE;

		private SinCalculator() {
			super(true);
		}


		protected id14 id16() {
			id14 factor = id20.id27();
			if (negative) {
				factor = factor.negate();
			}
			return factor;
		}


		protected void id22() {
			n++;
			id20 = id20.multiply(2 * n);
			id20 = id20.multiply(2 * n + 1);
			negative = !negative;
		}


		protected PowerIterator id6(BigDecimal x, MathContext mathContext) {
			return new id40(x, mathContext);
		}

	}

	static interface PowerIterator {
		BigDecimal id0();

		void id21();

	}

	static class Task implements Callable<Task> {
		int n;
		int r;
		BigDecimal TWO = BigDecimal.valueOf(2);
		BigDecimal N = null;
		BigDecimal R = null;
		MathContext mc = new MathContext(150);
		BigDecimal PI = id18.pi(mc);
		BigDecimal RE = null;
		int testNumber;

		Pair<BigDecimal, BigDecimal> id8(int i) {
			BigDecimal a = id18.pi(mc).divide(N, mc).multiply(BigDecimal.valueOf(i)).multiply(TWO);
			return new Pair<>(R.multiply(id18.cos(a, mc)), R.multiply(id18.sin(a, mc)));
		}

		Pair<BigDecimal, BigDecimal> id37() {
			Pair<BigDecimal, BigDecimal> p0 = id8(0);
			Pair<BigDecimal, BigDecimal> p1 = id8(1);
			Pair<BigDecimal, BigDecimal> pp0 = id8(n / 2);
			Pair<BigDecimal, BigDecimal> pp1 = id8(n / 2 + 2);
			Triple<BigDecimal, BigDecimal, BigDecimal> l1 = toLine(p0, pp0),
					l2 = toLine(p1, pp1);

			BigDecimal d = l2.first.multiply(l1.second).subtract(l1.first.multiply(l2.second));
			BigDecimal x = l2.second.multiply(l1.third).subtract(l1.second.multiply(l2.third)).divide(d, mc);
			BigDecimal y = l2.first.multiply(l1.third).subtract(l1.first.multiply(l2.third)).divide(d, mc);
			return new Pair<>(x, y);
		}

		Triple<BigDecimal, BigDecimal, BigDecimal> toLine(Pair<BigDecimal, BigDecimal> p1, Pair<BigDecimal, BigDecimal> p2) {
			BigDecimal a = BigDecimal.ZERO.subtract(p1.second.subtract(p2.second));
			BigDecimal b = p1.first.subtract(p2.first);
			BigDecimal c = BigDecimal.ZERO.subtract(a.multiply(p1.first).add(b.multiply(p1.second)));
			return new Triple<>(a, b, c);

		}

		public void readInput(InputReader in) {
	
			n = in.nextInt();
			r = in.nextInt();
			N = BigDecimal.valueOf(n);
			R = BigDecimal.valueOf(r);

		}

		public Task call() {
	















			Pair<BigDecimal, BigDecimal> x = id37();
			BigDecimal s = R.multiply(TWO).multiply(id18.sin(PI.divide(N, mc), mc));
			BigDecimal a1 = id18.sqrt(x.first.multiply(x.first).add(x.second.multiply(x.second)), mc);
			BigDecimal ar = a1.multiply(s).divide(TWO, mc);
			RE = N.multiply(ar);
			System.err.println("Test case: " + testNumber + " done!");
			return this;
		}

		public void writeOutput(PrintWriter out) {
			out.println(RE);
		}

		Task(int testNumber) {
			this.testNumber = testNumber;
		}

	}

	static class id40 implements PowerIterator {
		private final MathContext mathContext;
		private final BigDecimal id17;
		private BigDecimal id36;

		public id40(BigDecimal x, MathContext mathContext) {
			this.mathContext = mathContext;

			id17 = x.multiply(x, mathContext);
			id36 = x;
		}


		public BigDecimal id0() {
			return id36;
		}


		public void id21() {
			id36 = id36.multiply(id17, mathContext);
		}

	}
}

