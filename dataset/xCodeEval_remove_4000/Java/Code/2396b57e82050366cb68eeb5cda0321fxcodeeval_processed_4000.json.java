import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.io.BufferedInputStream;
import java.math.MathContext;
import java.util.concurrent.Callable;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.math.BigDecimal;
import java.util.List;
import java.util.StringTokenizer;
import java.math.BigInteger;
import java.io.BufferedReader;


public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		BufferedInputStream in = new BufferedInputStream(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}

	static class TaskD {
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

	static class id13 extends SeriesCalculator {
		public static final id13 INSTANCE = new id13();
		private int n = 0;
		private id14 id22 = id14.ONE;
		private id14 id6 = id14.ONE;
		private id14 id10 = id14.ONE;

		private id13() {
		}


		protected id14 id16() {
			id14 factor = id22.divide(id10.multiply(id6).multiply(id6).multiply(2 * n + 1));
			return factor;
		}


		protected void id21() {
			n++;
			id22 = id22.multiply(2 * n - 1).multiply(2 * n);
			id6 = id6.multiply(n);
			id10 = id10.multiply(4);
		}


		protected PowerIterator id7(BigDecimal x, MathContext mathContext) {
			return new id38(x, mathContext);
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

			PowerIterator powerIterator = id7(x, mathContext);

			BigDecimal sum = BigDecimal.ZERO;
			BigDecimal step;
			int i = 0;
			do {
				id14 factor = getFactor(i);
				BigDecimal id32 = powerIterator.id0();
				powerIterator.id20();
				step = factor.id4().multiply(id32, mathContext).divide(factor.id9(), mathContext);
				i++;

				if (id3) {
					id32 = powerIterator.id0();
					powerIterator.id20();
					factor = getFactor(i);
					BigDecimal step2 = factor.id4().multiply(id32, mathContext).divide(factor.id9(), mathContext);
					step = step.add(step2, mathContext);
					i++;
				}

				sum = sum.add(step, mathContext);
				

			} while (step.abs().compareTo(acceptableError) > 0);

			return sum.round(mathContext);
		}

		protected abstract PowerIterator id7(BigDecimal x, MathContext mathContext);

		protected id14 getFactor(int index) {
			while (factors.size() <= index) {
				id14 factor = id16();
				factors.add(factor);
				id21();
			}
			return factors.get(index);
		}

		protected abstract id14 id16();

		protected abstract void id21();

	}

	static class InputReader {
		public BufferedReader reader;
		public StringTokenizer tokenizer;

		public InputReader(BufferedInputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream), 32768);
			tokenizer = null;
		}

		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public void close() {
			try {
				if (reader != null)
					reader.close();
			} catch (Exception ex) {
				throw new RuntimeException(ex);
			}
		}

	}

	static class Task implements Callable<Task> {
		long x1;
		long y1;
		long r1;
		long x2;
		long y2;
		long r2;
		MathContext mc = new MathContext(150);
		BigDecimal intersectionArea = BigDecimal.ZERO;
		int testNumber;

		public void readInput(InputReader in) {
	
			x1 = in.nextInt();
			y1 = in.nextInt();
			r1 = in.nextInt();

			x2 = in.nextInt();
			y2 = in.nextInt();
			r2 = in.nextInt();

		}

		public Task call() {
	


			if (r2 < r1) {
				long temp = r1;
				r1 = r2;
				r2 = temp;
			}

			double r = r1;
			double R = r2;
			double d = Math.sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
			long d2 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);


			if (d2 >= r1 * r1 + 2 * r1 * r2 + r2 * r2) {

			} else if (d2 == 0) {
				intersectionArea = id18.pi(mc).multiply(BigDecimal.valueOf(r)).multiply(BigDecimal.valueOf(r));
			} else if (R >= d + r) {
				intersectionArea = id18.pi(mc).multiply(BigDecimal.valueOf(r)).multiply(BigDecimal.valueOf(r));
			} else {
				BigDecimal br = new BigDecimal(r, MathContext.DECIMAL128);
				BigDecimal bR = new BigDecimal(R, MathContext.DECIMAL128);
				BigDecimal b2 = new BigDecimal(2, MathContext.DECIMAL128);
				BigDecimal bd = (id18.sqrt(BigDecimal.valueOf(d2), MathContext.DECIMAL128));


				BigDecimal part1 = br.multiply(br).multiply(id18.acos((bd.multiply(bd).add(br.multiply(br)).subtract(bR.multiply(bR))).divide(b2.multiply(bd).multiply(br), mc), mc));
				BigDecimal part2 = bR.multiply(bR).multiply(id18.acos((bd.multiply(bd).add(bR.multiply(bR)).subtract(br.multiply(br))).divide(b2.multiply(bd).multiply(bR), mc), mc));

				BigDecimal s1 = br.add(bR).subtract(bd);
				BigDecimal s2 = bd.add(br).subtract(bR);
				BigDecimal s3 = bd.add(bR).subtract(br);
				BigDecimal s4 = bd.add(bR).add(br);

				BigDecimal part3 = id18.sqrt(s1.multiply(s2).multiply(s3).multiply(s4), mc).divide(b2, mc);

				

				


				intersectionArea = part1.add(part2).subtract(part3);


			}

			System.err.println("Test case: " + testNumber + " done!");
			return this;
		}

		public void writeOutput(PrintWriter out) {

			

			out.println(intersectionArea);

		}

		Task(int testNumber) {
			this.testNumber = testNumber;
		}

	}

	static class id18 {
		private static final BigDecimal TWO = BigDecimal.valueOf(2);
		private static final BigDecimal id11 = BigDecimal.valueOf(-1);
		private static final BigDecimal id5 = BigDecimal.valueOf(Double.MAX_VALUE);
		private static final BigDecimal id2 = BigDecimal.valueOf(Double.MIN_VALUE);
		private static volatile BigDecimal piCache;
		private static final Object id15 = new Object();
		private static final int id30 = 17;
		private static BigDecimal[] id29 = new BigDecimal[100];

		static {
			BigDecimal result = BigDecimal.ONE;
			id29[0] = result;
			for (int i = 1; i < id29.length; i++) {
				result = result.multiply(BigDecimal.valueOf(i));
				id29[i] = result;
			}
		}

		private id18() {
			

		}

		public static boolean id24(BigDecimal value) {
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
			if (id24(x)) {
				result = BigDecimal.valueOf(Math.sqrt(x.doubleValue()));
			} else {
				result = x.divide(TWO, mathContext);
			}

			if (result.multiply(result, mathContext).compareTo(x) == 0) {
				return result.round(mathContext); 

			}

			int adaptivePrecision = id30;
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
					piCache = id8(mathContext);
					return piCache;
				}
			}

			return result.round(mathContext);
		}

		private static BigDecimal id8(MathContext mathContext) {
			MathContext mc = new MathContext(mathContext.getPrecision() + 10, mathContext.getRoundingMode());

			final BigDecimal value24 = BigDecimal.valueOf(24);
			final BigDecimal id1 = BigDecimal.valueOf(640320);
			final BigDecimal id31 = BigDecimal.valueOf(13591409);
			final BigDecimal id25 = BigDecimal.valueOf(545140134);
			final BigDecimal id26 = id1.pow(3).divide(value24, mc);

			BigDecimal sumA = BigDecimal.ONE;
			BigDecimal sumB = BigDecimal.ZERO;

			BigDecimal a = BigDecimal.ONE;
			long id33 = 5; 

			long id19 = -1; 

			long id36 = -1; 

			BigDecimal id37 = BigDecimal.ZERO;

			long iterationCount = (mc.getPrecision() + 13) / 14;
			for (long k = 1; k <= iterationCount; k++) {
				BigDecimal valueK = BigDecimal.valueOf(k);
				id33 += -6;
				id19 += 2;
				id36 += 6;
				BigDecimal dividend = BigDecimal.valueOf(id33).multiply(BigDecimal.valueOf(id19)).multiply(BigDecimal.valueOf(id36));
				id37 = valueK.pow(3);
				BigDecimal divisor = id37.multiply(id26, mc);
				a = a.multiply(dividend).divide(divisor, mc);
				BigDecimal b = valueK.multiply(a, mc);

				sumA = sumA.add(a);
				sumB = sumB.add(b);
			}

			final BigDecimal id28 = BigDecimal.valueOf(426880);
			final BigDecimal id23 = BigDecimal.valueOf(10005);
			final BigDecimal factor = id28.multiply(sqrt(id23, mc));
			BigDecimal pi = factor.divide(id31.multiply(sumA, mc).add(id25.multiply(sumB, mc)), mc);

			return pi.round(mathContext);
		}

		public static BigDecimal asin(BigDecimal x, MathContext mathContext) {
			if (x.compareTo(BigDecimal.ONE) > 0) {
				throw new ArithmeticException("Illegal asin(x) for x > 1: x = " + x);
			}
			if (x.compareTo(id11) < 0) {
				throw new ArithmeticException("Illegal asin(x) for x < -1: x = " + x);
			}

			if (x.signum() == -1) {
				return asin(x.negate(), mathContext).negate();
			}

			MathContext mc = new MathContext(mathContext.getPrecision() + 6, mathContext.getRoundingMode());

			if (x.compareTo(BigDecimal.valueOf(0.707107)) >= 0) {
				BigDecimal id34 = sqrt(BigDecimal.ONE.subtract(x.multiply(x, mc), mc), mc);
				return acos(id34, mathContext);
			}

			BigDecimal result = id13.INSTANCE.calculate(x, mc);
			return result.round(mathContext);
		}

		public static BigDecimal acos(BigDecimal x, MathContext mathContext) {
			if (x.compareTo(BigDecimal.ONE) > 0) {
				throw new ArithmeticException("Illegal acos(x) for x > 1: x = " + x);
			}
			if (x.compareTo(id11) < 0) {
				throw new ArithmeticException("Illegal acos(x) for x < -1: x = " + x);
			}

			MathContext mc = new MathContext(mathContext.getPrecision() + 6, mathContext.getRoundingMode());

			BigDecimal result = pi(mc).divide(TWO, mc).subtract(asin(x, mc), mc);
			return result.round(mathContext);
		}

	}

	static class id38 implements PowerIterator {
		private final MathContext mathContext;
		private final BigDecimal id17;
		private BigDecimal id35;

		public id38(BigDecimal x, MathContext mathContext) {
			this.mathContext = mathContext;

			id17 = x.multiply(x, mathContext);
			id35 = x;
		}


		public BigDecimal id0() {
			return id35;
		}


		public void id20() {
			id35 = id35.multiply(id17, mathContext);
		}

	}

	static interface PowerIterator {
		BigDecimal id0();

		void id20();

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

		public BigDecimal id9() {
			return denominator;
		}

		public id14 multiply(id14 value) {
			if (isZero() || value.isZero()) {
				return ZERO;
			}
			if (equals(ONE)) {
				return value;
			}
			if (value.equals(ONE)) {
				return this;
			}

			BigDecimal n = numerator.multiply(value.numerator);
			BigDecimal d = denominator.multiply(value.denominator);
			return of(n, d);
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

		public id14 divide(id14 value) {
			if (value.equals(ONE)) {
				return this;
			}

			BigDecimal n = numerator.multiply(value.denominator);
			BigDecimal d = denominator.multiply(value.numerator);
			return of(n, d);
		}

		public boolean isZero() {
			return numerator.signum() == 0;
		}

		private boolean id27() {
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
			if (id27()) {
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
}

