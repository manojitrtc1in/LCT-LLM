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

	static class AsinCalculator extends SeriesCalculator {
		public static final AsinCalculator INSTANCE = new AsinCalculator();
		private int n = 0;
		private BigRational factorial2n = BigRational.ONE;
		private BigRational factorialN = BigRational.ONE;
		private BigRational fourPowerN = BigRational.ONE;

		private AsinCalculator() {
		}


		protected BigRational getCurrentFactor() {
			BigRational factor = factorial2n.divide(fourPowerN.multiply(factorialN).multiply(factorialN).multiply(2 * n + 1));
			return factor;
		}


		protected void calculateNextFactor() {
			n++;
			factorial2n = factorial2n.multiply(2 * n - 1).multiply(2 * n);
			factorialN = factorialN.multiply(n);
			fourPowerN = fourPowerN.multiply(4);
		}


		protected PowerIterator createPowerIterator(BigDecimal x, MathContext mathContext) {
			return new PowerTwoNPlusOneIterator(x, mathContext);
		}

	}

	static abstract class SeriesCalculator {
		private boolean calculateInPairs;
		private List<BigRational> factors = new ArrayList<>();

		protected SeriesCalculator() {
			this(false);
		}

		protected SeriesCalculator(boolean calculateInPairs) {
			this.calculateInPairs = calculateInPairs;
		}

		public BigDecimal calculate(BigDecimal x, MathContext mathContext) {
			BigDecimal acceptableError = BigDecimal.ONE.movePointLeft(mathContext.getPrecision() + 1);

			PowerIterator powerIterator = createPowerIterator(x, mathContext);

			BigDecimal sum = BigDecimal.ZERO;
			BigDecimal step;
			int i = 0;
			do {
				BigRational factor = getFactor(i);
				BigDecimal xToThePower = powerIterator.getCurrentPower();
				powerIterator.calculateNextPower();
				step = factor.getNumerator().multiply(xToThePower, mathContext).divide(factor.getDenominator(), mathContext);
				i++;

				if (calculateInPairs) {
					xToThePower = powerIterator.getCurrentPower();
					powerIterator.calculateNextPower();
					factor = getFactor(i);
					BigDecimal step2 = factor.getNumerator().multiply(xToThePower, mathContext).divide(factor.getDenominator(), mathContext);
					step = step.add(step2, mathContext);
					i++;
				}

				sum = sum.add(step, mathContext);
				

			} while (step.abs().compareTo(acceptableError) > 0);

			return sum.round(mathContext);
		}

		protected abstract PowerIterator createPowerIterator(BigDecimal x, MathContext mathContext);

		protected BigRational getFactor(int index) {
			while (factors.size() <= index) {
				BigRational factor = getCurrentFactor();
				factors.add(factor);
				calculateNextFactor();
			}
			return factors.get(index);
		}

		protected abstract BigRational getCurrentFactor();

		protected abstract void calculateNextFactor();

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
				intersectionArea = BigDecimalMath.pi(mc).multiply(BigDecimal.valueOf(r)).multiply(BigDecimal.valueOf(r));
			} else if (R >= d + r) {
				intersectionArea = BigDecimalMath.pi(mc).multiply(BigDecimal.valueOf(r)).multiply(BigDecimal.valueOf(r));
			} else {
				BigDecimal br = new BigDecimal(r, MathContext.DECIMAL128);
				BigDecimal bR = new BigDecimal(R, MathContext.DECIMAL128);
				BigDecimal b2 = new BigDecimal(2, MathContext.DECIMAL128);
				BigDecimal bd = (BigDecimalMath.sqrt(BigDecimal.valueOf(d2), MathContext.DECIMAL128));


				BigDecimal part1 = br.multiply(br).multiply(BigDecimalMath.acos((bd.multiply(bd).add(br.multiply(br)).subtract(bR.multiply(bR))).divide(b2.multiply(bd).multiply(br), mc), mc));
				BigDecimal part2 = bR.multiply(bR).multiply(BigDecimalMath.acos((bd.multiply(bd).add(bR.multiply(bR)).subtract(br.multiply(br))).divide(b2.multiply(bd).multiply(bR), mc), mc));

				BigDecimal s1 = br.add(bR).subtract(bd);
				BigDecimal s2 = bd.add(br).subtract(bR);
				BigDecimal s3 = bd.add(bR).subtract(br);
				BigDecimal s4 = bd.add(bR).add(br);

				BigDecimal part3 = BigDecimalMath.sqrt(s1.multiply(s2).multiply(s3).multiply(s4), mc).divide(b2, mc);

				

				


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

	static class BigDecimalMath {
		private static final BigDecimal TWO = BigDecimal.valueOf(2);
		private static final BigDecimal MINUS_ONE = BigDecimal.valueOf(-1);
		private static final BigDecimal DOUBLE_MAX_VALUE = BigDecimal.valueOf(Double.MAX_VALUE);
		private static final BigDecimal DOUBLE_MIN_VALUE = BigDecimal.valueOf(Double.MIN_VALUE);
		private static volatile BigDecimal piCache;
		private static final Object piCacheLock = new Object();
		private static final int EXPECTED_INITIAL_PRECISION = 17;
		private static BigDecimal[] factorialCache = new BigDecimal[100];

		static {
			BigDecimal result = BigDecimal.ONE;
			factorialCache[0] = result;
			for (int i = 1; i < factorialCache.length; i++) {
				result = result.multiply(BigDecimal.valueOf(i));
				factorialCache[i] = result;
			}
		}

		private BigDecimalMath() {
			

		}

		public static boolean isDoubleValue(BigDecimal value) {
			if (value.compareTo(DOUBLE_MAX_VALUE) > 0) {
				return false;
			}
			if (value.signum() > 0 && value.compareTo(DOUBLE_MIN_VALUE) < 0) {
				return false;
			}

			if (value.compareTo(DOUBLE_MAX_VALUE.negate()) < 0) {
				return false;
			}
			if (value.signum() < 0 && value.compareTo(DOUBLE_MIN_VALUE.negate()) > 0) {
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
			if (isDoubleValue(x)) {
				result = BigDecimal.valueOf(Math.sqrt(x.doubleValue()));
			} else {
				result = x.divide(TWO, mathContext);
			}

			if (result.multiply(result, mathContext).compareTo(x) == 0) {
				return result.round(mathContext); 

			}

			int adaptivePrecision = EXPECTED_INITIAL_PRECISION;
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

			synchronized (piCacheLock) {
				if (piCache != null && mathContext.getPrecision() <= piCache.precision()) {
					result = piCache;
				} else {
					piCache = piChudnovski(mathContext);
					return piCache;
				}
			}

			return result.round(mathContext);
		}

		private static BigDecimal piChudnovski(MathContext mathContext) {
			MathContext mc = new MathContext(mathContext.getPrecision() + 10, mathContext.getRoundingMode());

			final BigDecimal value24 = BigDecimal.valueOf(24);
			final BigDecimal value640320 = BigDecimal.valueOf(640320);
			final BigDecimal value13591409 = BigDecimal.valueOf(13591409);
			final BigDecimal value545140134 = BigDecimal.valueOf(545140134);
			final BigDecimal valueDivisor = value640320.pow(3).divide(value24, mc);

			BigDecimal sumA = BigDecimal.ONE;
			BigDecimal sumB = BigDecimal.ZERO;

			BigDecimal a = BigDecimal.ONE;
			long dividendTerm1 = 5; 

			long dividendTerm2 = -1; 

			long dividendTerm3 = -1; 

			BigDecimal kPower3 = BigDecimal.ZERO;

			long iterationCount = (mc.getPrecision() + 13) / 14;
			for (long k = 1; k <= iterationCount; k++) {
				BigDecimal valueK = BigDecimal.valueOf(k);
				dividendTerm1 += -6;
				dividendTerm2 += 2;
				dividendTerm3 += 6;
				BigDecimal dividend = BigDecimal.valueOf(dividendTerm1).multiply(BigDecimal.valueOf(dividendTerm2)).multiply(BigDecimal.valueOf(dividendTerm3));
				kPower3 = valueK.pow(3);
				BigDecimal divisor = kPower3.multiply(valueDivisor, mc);
				a = a.multiply(dividend).divide(divisor, mc);
				BigDecimal b = valueK.multiply(a, mc);

				sumA = sumA.add(a);
				sumB = sumB.add(b);
			}

			final BigDecimal value426880 = BigDecimal.valueOf(426880);
			final BigDecimal value10005 = BigDecimal.valueOf(10005);
			final BigDecimal factor = value426880.multiply(sqrt(value10005, mc));
			BigDecimal pi = factor.divide(value13591409.multiply(sumA, mc).add(value545140134.multiply(sumB, mc)), mc);

			return pi.round(mathContext);
		}

		public static BigDecimal asin(BigDecimal x, MathContext mathContext) {
			if (x.compareTo(BigDecimal.ONE) > 0) {
				throw new ArithmeticException("Illegal asin(x) for x > 1: x = " + x);
			}
			if (x.compareTo(MINUS_ONE) < 0) {
				throw new ArithmeticException("Illegal asin(x) for x < -1: x = " + x);
			}

			if (x.signum() == -1) {
				return asin(x.negate(), mathContext).negate();
			}

			MathContext mc = new MathContext(mathContext.getPrecision() + 6, mathContext.getRoundingMode());

			if (x.compareTo(BigDecimal.valueOf(0.707107)) >= 0) {
				BigDecimal xTransformed = sqrt(BigDecimal.ONE.subtract(x.multiply(x, mc), mc), mc);
				return acos(xTransformed, mathContext);
			}

			BigDecimal result = AsinCalculator.INSTANCE.calculate(x, mc);
			return result.round(mathContext);
		}

		public static BigDecimal acos(BigDecimal x, MathContext mathContext) {
			if (x.compareTo(BigDecimal.ONE) > 0) {
				throw new ArithmeticException("Illegal acos(x) for x > 1: x = " + x);
			}
			if (x.compareTo(MINUS_ONE) < 0) {
				throw new ArithmeticException("Illegal acos(x) for x < -1: x = " + x);
			}

			MathContext mc = new MathContext(mathContext.getPrecision() + 6, mathContext.getRoundingMode());

			BigDecimal result = pi(mc).divide(TWO, mc).subtract(asin(x, mc), mc);
			return result.round(mathContext);
		}

	}

	static class PowerTwoNPlusOneIterator implements PowerIterator {
		private final MathContext mathContext;
		private final BigDecimal xPowerTwo;
		private BigDecimal powerOfX;

		public PowerTwoNPlusOneIterator(BigDecimal x, MathContext mathContext) {
			this.mathContext = mathContext;

			xPowerTwo = x.multiply(x, mathContext);
			powerOfX = x;
		}


		public BigDecimal getCurrentPower() {
			return powerOfX;
		}


		public void calculateNextPower() {
			powerOfX = powerOfX.multiply(xPowerTwo, mathContext);
		}

	}

	static interface PowerIterator {
		BigDecimal getCurrentPower();

		void calculateNextPower();

	}

	static class BigRational implements Comparable<BigRational> {
		public static final BigRational ZERO = new BigRational(0);
		public static final BigRational ONE = new BigRational(1);
		private final BigDecimal numerator;
		private final BigDecimal denominator;

		private BigRational(int value) {
			this(BigDecimal.valueOf(value), BigDecimal.ONE);
		}

		private BigRational(BigDecimal num, BigDecimal denom) {
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

		public BigDecimal getNumerator() {
			return numerator;
		}

		public BigDecimal getDenominator() {
			return denominator;
		}

		public BigRational multiply(BigRational value) {
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

		private BigRational multiply(BigDecimal value) {
			BigDecimal n = numerator.multiply(value);
			BigDecimal d = denominator;
			return of(n, d);
		}

		public BigRational multiply(BigInteger value) {
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

		public BigRational multiply(int value) {
			return multiply(BigInteger.valueOf(value));
		}

		public BigRational divide(BigRational value) {
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

		private boolean isIntegerInternal() {
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

		public BigDecimal toBigDecimal() {
			int precision = Math.max(precision(), MathContext.DECIMAL128.getPrecision());
			return toBigDecimal(new MathContext(precision));
		}

		public BigDecimal toBigDecimal(MathContext mc) {
			return numerator.divide(denominator, mc);
		}


		public int compareTo(BigRational other) {
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

			if (!(obj instanceof BigRational)) {
				return false;
			}

			BigRational other = (BigRational) obj;
			if (!numerator.equals(other.numerator)) {
				return false;
			}
			return denominator.equals(other.denominator);
		}


		public String toString() {
			if (isZero()) {
				return "0";
			}
			if (isIntegerInternal()) {
				return numerator.toString();
			}
			return toBigDecimal().toString();
		}

		public static BigRational valueOf(BigInteger numerator, BigInteger denominator) {
			return of(new BigDecimal(numerator), new BigDecimal(denominator));
		}

		public static BigRational valueOf(BigInteger value) {
			if (value.compareTo(BigInteger.ZERO) == 0) {
				return ZERO;
			}
			if (value.compareTo(BigInteger.ONE) == 0) {
				return ONE;
			}
			return valueOf(value, BigInteger.ONE);
		}

		private static BigRational of(BigDecimal numerator, BigDecimal denominator) {
			if (numerator.signum() == 0 && denominator.signum() != 0) {
				return ZERO;
			}
			if (numerator.compareTo(BigDecimal.ONE) == 0 && denominator.compareTo(BigDecimal.ONE) == 0) {
				return ONE;
			}
			return new BigRational(numerator, denominator);
		}

	}
}

