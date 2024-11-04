import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.MathContext;
import java.math.RoundingMode;
import java.util.StringTokenizer;


public class B
{
	static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
	static MyScanner sc = new MyScanner(System.in);
	static StringBuilder result = new StringBuilder();
	static final double EPSILON = 0.000001;
	
	public static void main(String... args)
	{
		int n = sc.nextInt();
		Fraction r = new Fraction(sc.nextInt(), sc.nextInt());
		int[] xs = new int[n];
		
		for (int i = 0; i < n; i++)
		{
			xs[i] = sc.nextInt();
		}
		
		int x = sc.nextInt();
		int y = sc.nextInt();
		
		double minT = Double.MAX_VALUE;
		int stop = 0;
		for (int i = 1; i < n; i++)
		{
			double time = xs[i] / (r).doubleValue() + Math.pow((double)y * y + (double)(xs[i] - x) * (xs[i] - x), 0.5);




			if (time < minT)
			{
				minT = time;
				stop = i;
			}
			else if (time == minT)
			{
				minT = time;
				stop = i;
			}
			if (xs[i] > x)
			{
				break;
			}
		}
		
		System.out.println(stop + 1);
	}
	
	
	static final class MathUtil 
	{
		private MathUtil()
		{
			
		}
		
		private enum Key
		{
			KEY;
		}
		
		public static BigInteger BigIntegerOf(String expression, Object... args)
		{
			expression = String.format(expression, args);
			expression = expression.replaceAll(" ", "");
			
			int bracketEnd;
			bracketEnd = expression.indexOf(")");
			while (bracketEnd != -1)
			{
				int bracketStart = expression.substring(0, bracketEnd)
						.lastIndexOf("(");
				
				expression = expression.substring(0, bracketStart)
						+ bigIntegerOf(expression.substring(bracketStart + 1, bracketEnd), Key.KEY)
						+ expression.substring(bracketEnd + 1);
				
				bracketEnd = expression.indexOf(")");
			}
			
			return bigIntegerOf(expression, Key.KEY);
		}
		
		private static BigInteger bigIntegerOf(String expression, Key key)
		{
			

			return null;
		}

		public static int gcd(int... vals)
		{
			int result = 0;
			
			for (int val : vals)
			{
				result = gcd(result, val, Key.KEY);
			}
			
			return result;
		}

		public static int lcm(int... vals)
		{
			int result = 1;
			
			for (int val : vals)
			{
				result = lcm(result, val, Key.KEY);
			}
			
			return result;
		}
		
		private static int lcm(int val0, int val1, Key key)
		{
			if (val0 == 0 || val1 == 0)
			{
				return 0;
			}
			
			return val0 / gcd(val0, val1, Key.KEY) * val1;
		}

		private static int gcd(int val0, int val1, Key key)
		{
			while(val1 != 0)
			{
				int temp = val0 % val1;
				val0 = val1;
				val1 = temp;
			}
			return val0;
		}
		
		
	}

	
	
	static class Fraction extends Number implements Comparable<Fraction>
	{
		
		private static final long serialVersionUID = -2235415717210095016L;

		

		
		private int integer = 0;
		
		private int numerator = 0;
		
		private int denominator = 1;
		
		

		
		public static final Fraction ONE = new Fraction(1);
		
		public static final Fraction TEN = new Fraction(10);
		
		public static final Fraction ZERO = new Fraction();
		
		public static final int MAX_SAFE_PRECISION = (int) (Math.sqrt(Integer.MAX_VALUE));
		
		

		public Fraction()
		{
			
		}
		
		public Fraction(int integer)
		{
			this.integer = integer;
		}
		
		public Fraction(int numerator, int denominator)
		{
			this.numerator = numerator;
			this.denominator = denominator;
			reduce();
		}
		
		public Fraction(int integer, int numerator, int denominator)
		{
			this.integer = integer;
			this.numerator = numerator;
			this.denominator = denominator;
			reduce();
		}
		
		public Fraction(String val)
		{
			String[] intSplit = val.split(" ", 2);
			String[] fracSplit;
			switch(intSplit.length)
			{
				case 1:
					fracSplit = val.split("/", 2);
					switch(fracSplit.length)
					{
						case 1:
							integer = Integer.parseInt(val);
							break;
						case 2:
							numerator = Integer.parseInt(fracSplit[0]);
							denominator = Integer.parseInt(fracSplit[1]);
							reduce();
							break;
					}
					break;
				case 2:
					integer = Integer.parseInt(intSplit[0]);
					fracSplit = intSplit[1].split("/", 2);
					switch(fracSplit.length)
					{
						case 1:
							throw new NumberFormatException(String.format("Invalid Fraction format: %s", val));
						case 2:
							numerator = Integer.parseInt(fracSplit[0]);
							denominator = Integer.parseInt(fracSplit[1]);
							reduce();
							break;
					}
					break;
			}
		}
		
		public Fraction(String val, int radix)
		{
			String[] intSplit = val.split(" ", 2);
			String[] fracSplit;
			switch(intSplit.length)
			{
				case 1:
					fracSplit = val.split("/", 2);
					switch(fracSplit.length)
					{
						case 1:
							integer = Integer.parseInt(val, radix);
							break;
						case 2:
							numerator = Integer.parseInt(fracSplit[0], radix);
							denominator = Integer.parseInt(fracSplit[1], radix);
							reduce();
							break;
					}
					break;
				case 2:
					integer = Integer.parseInt(intSplit[0], radix);
					fracSplit = intSplit[1].split("/", 2);
					switch(fracSplit.length)
					{
						case 1:
							throw new NumberFormatException(String.format("Invalid Fraction format: %s", val));
						case 2:
							numerator = Integer.parseInt(fracSplit[0], radix);
							denominator = Integer.parseInt(fracSplit[1], radix);
							reduce();
							break;
					}
					break;
			}
		}
		
		private void reduce()
		{
			reduceFraction();
			simplifyNumerator();
			simplifySign();
		}

		private void simplifyNumerator()
		{
			integer += numerator / denominator;
			numerator %= denominator;
			
		}

		private void simplifySign()
		{
			numerator *= Integer.signum(denominator);
			denominator = Math.abs(denominator);
			
			if (integer != 0 && numerator != 0 && Integer.signum(integer) != Integer.signum(numerator))
			{
				boolean negated = false;
				if (integer < 0)
				{
					negated = true;
					integer *= -1;
					numerator *= -1;
				}
				
				integer--;
				numerator += denominator;
				
				if (negated)
				{
					integer *= -1;
					numerator *= -1;
				}
			}
		}

		private void reduceFraction()
		{
			int gcd = MathUtil.gcd(numerator, denominator);
			numerator /= gcd;
			denominator /= gcd;
		}

		


		public Fraction abs()
		{
			return new Fraction(Math.abs(integer), Math.abs(numerator), denominator);
		}
		
		public Fraction add(Fraction augend)
		{
			int integer = this.integer + augend.integer;
			int denominator = MathUtil.lcm(this.denominator, augend.denominator);
			int numerator = this.numerator * (denominator / this.denominator)
					+ augend.numerator * (denominator / augend.denominator);
			return new Fraction(integer, numerator, denominator);
		}

		@Override
		public int compareTo(Fraction val)
		{
			return Double.compare(this.doubleValue(), val.doubleValue());
		}
		
		public Fraction divide(Fraction divisor)
		{
			return this.multiply(divisor.reciprocal());
		}
		
		public int divideToIntegralValue(Fraction divisor)
		{
			return this.divide(divisor).integer;
		}
		
		@Override
		public double doubleValue()
		{
			return integer + (double) numerator / denominator;
		}
		
		@Override
		public boolean equals(Object x)
		{
			if (x instanceof Fraction)
			{
				Fraction f = (Fraction) x;
				return this.integer == f.integer && this.numerator == f.numerator && this.denominator == f.denominator;
			}
			if (x instanceof Number)
			{
				return this.doubleValue() == ((Number) x).doubleValue();
			}
			return super.equals(x);
		}
		
		@Override
		public float floatValue()
		{
			return integer + (float) numerator / denominator;
		}
		
		public int getDenominator()
		{
			return denominator;
		}
		
		public int getInteger()
		{
			return integer;
		}
		
		public int getNumerator()
		{
			return numerator;
		}
		
		@Override
		public int hashCode()
		{
			return ((Double)this.doubleValue()).hashCode();
		}
		
		@Override
		public int intValue()
		{
			return integer;
		}

		@Override
		public long longValue()
		{
			return integer;
		}
		
		public Fraction max(Fraction val)
		{
			if (this.compareTo(val) >= 0)
			{
				return this;
			}
			else
			{
				return val;
			}
		}
		
		public Fraction mediant(Fraction val)
		{
			int numerator = this.integer * this.denominator + this.numerator + 
					val.integer * val.denominator + val.numerator;
			int denominator = this.denominator + val.denominator;
			
			return new Fraction(numerator, denominator);
		}
		
		public Fraction min(Fraction val)
		{
			if (this.compareTo(val) <= 0)
			{
				return this;
			}
			else
			{
				return val;
			}
		}
		
		public Fraction multiply(Fraction multiplicand)
		{
			int integer = this.integer * multiplicand.integer;
			
			int gcd1 = MathUtil.gcd(this.integer, multiplicand.denominator);
			int gcd2 = MathUtil.gcd(multiplicand.integer, this.denominator);
			
			Fraction f1 = new Fraction(this.integer / gcd1 * multiplicand.numerator, multiplicand.denominator / gcd1);
			Fraction f2 = new Fraction(multiplicand.integer / gcd2 * this.numerator, this.denominator / gcd2);
			
			int gcdf1 = MathUtil.gcd(this.numerator, multiplicand.denominator);
			int gcdf2 = MathUtil.gcd(multiplicand.numerator, this.denominator);
			
			Fraction ff = new Fraction((this.numerator / gcdf1) * (multiplicand.numerator / gcdf2), (this.denominator / gcdf2) * (multiplicand.denominator / gcdf1));
			
			return new Fraction(integer).add(f1).add(f2).add(ff);
		}
		
		public Fraction negate()
		{
			return new Fraction(-integer, -numerator, denominator);		
		}
		
		public Fraction plus()
		{
			return this;		
		}
		
		public Fraction pow(int n)
		{
			if (n == 0)
			{
				return Fraction.ONE;
			}		
			Fraction base = this;
			if (n < 0)
			{
				base = this.reciprocal();
				n *= -1;
			}
			if (n % 2 == 0)
			{
				return this.multiply(base).pow(n / 2);
			}
			else
			{
				return base.multiply(base.multiply(base).pow(n / 2));		
			}
		}

		public Fraction reciprocal()
		{
			return new Fraction(denominator, numerator + integer * denominator);
		}

		public Fraction remainder(Fraction divisor)
		{
			return this.subtract(new Fraction(this.divideToIntegralValue(divisor)).multiply(divisor));		
		}
		
		public Fraction round(Fraction unit)
		{
			return this.round(unit, RoundingMode.HALF_UP);
		}
		
		public Fraction round(RoundingMode rm)
		{
			return this.round(Fraction.ONE, rm);
		}
		
		public Fraction round(Fraction unit, RoundingMode rm)
		{
			unit = unit.abs();
			if (this.remainder(unit).equals(Fraction.ZERO))
			{
				return this;
			}
			switch(rm)
			{
				case CEILING:
					if (this.signum() >= 0)
					{
						return this.round(unit, RoundingMode.UP);
					}
					else
					{
						return this.round(unit, RoundingMode.DOWN);
					}
				case DOWN:
					return new Fraction(this.divideToIntegralValue(unit)).multiply(unit);
				case FLOOR:
					if (this.signum() >= 0)
					{
						return this.round(unit, RoundingMode.DOWN);
					}
					else
					{
						return this.round(unit, RoundingMode.UP);
					}
				case HALF_DOWN:
					if (this.abs().remainder(unit).divide(unit).compareTo(new Fraction(1, 2)) > 0)
					{
						return this.round(unit, RoundingMode.UP);
					}
					else
					{
						return this.round(unit, RoundingMode.DOWN);					
					}
				case HALF_EVEN:
					if (this.abs().remainder(unit).divide(unit).compareTo(new Fraction(1, 2)) > 0)
					{
						return this.round(unit, RoundingMode.UP);
					}
					else if (this.abs().remainder(unit).divide(unit).compareTo(new Fraction(1, 2)) < 0)
					{
						return this.round(unit, RoundingMode.DOWN);					
					}
					else if (this.divideToIntegralValue(unit) % 2 == 0)
					{
						return this.round(unit, RoundingMode.DOWN);					
					}
					else
					{
						return this.round(unit, RoundingMode.UP);
					}
				case HALF_UP:
					if (this.abs().remainder(unit).divide(unit).compareTo(new Fraction(1, 2)) >= 0)
					{
						return this.round(unit, RoundingMode.UP);
					}
					else
					{
						return this.round(unit, RoundingMode.DOWN);					
					}
				case UNNECESSARY:
					throw new ArithmeticException("Rounding necessary");
				case UP:
					if (this.signum() >= 0)
					{
						return this.round(unit, RoundingMode.DOWN).add(unit);
					}
					else
					{
						return this.round(unit, RoundingMode.DOWN).subtract(unit);
					}
			}
			throw new UnsupportedOperationException("Rounding mode unsupported");
		}

		public int signum()
		{
			if (Integer.signum(integer) == 0)
			{
				return Integer.signum(numerator);
			}
			else
			{
				return Integer.signum(integer);		
			}
		}
		
		public Fraction simplify()
		{
			if (denominator > MAX_SAFE_PRECISION)
			{
				return valueOf(this.doubleValue(), MAX_SAFE_PRECISION);
			}
			return this;
		}
		
		public Fraction subtract(Fraction subtrahend)
		{
			return this.add(subtrahend.negate());		
		}
		
		public BigDecimal toBigDecimal()
		{
			BigDecimal integer = new BigDecimal(this.integer);
			BigDecimal numerator = new BigDecimal(this.numerator);
			BigDecimal denominator = new BigDecimal(this.denominator);
			
			return integer.add(numerator.divide(denominator));		
		}
		
		public BigDecimal toBigDecimal(MathContext mc)
		{
			BigDecimal integer = new BigDecimal(this.integer);
			BigDecimal numerator = new BigDecimal(this.numerator);
			BigDecimal denominator = new BigDecimal(this.denominator);
			
			return integer.add(numerator.divide(denominator), mc);		
		}
		
		public String toString()
		{
			if (numerator == 0)
			{
				return Integer.toString(integer);
			}
			if (integer == 0)
			{
				return String.format("%d/%d", numerator, denominator);		
			}
			return String.format("%d %d/%d", integer, numerator, denominator);		
		}
		
		public String toImproperString()
		{
			return String.format("%d/%d", (long)integer * denominator + numerator, denominator);		
		}
		
		public static Fraction valueOf(double val, Fraction unit)
		{
			double quotient = val / unit.doubleValue();
			int units = (int) quotient;
			
			return unit.multiply(new Fraction(units));
		}
		
		public static Fraction valueOf(double val, int precision)
		{
			if (precision < 0 || precision * 2 < 0)
			{
				throw new ArithmeticException("Invalid Operation");
			}
			if (precision == 0)
			{
				precision = Integer.MAX_VALUE / 2;
			}
			
			double abs = Math.abs(val);
			boolean negative = Math.signum(val) < 0;
			
			int integer = (int) abs;
			double fraction = abs - integer;
			
			Fraction lower = ZERO;
			Fraction higher = ONE;
			
			for (int i = precision; i > precision / 2; i--)
			{
				Fraction unit = new Fraction(1, i);
				Fraction lGuess = valueOf(fraction, unit);
				
				if (lGuess.doubleValue() == fraction)
				{
					Fraction absResult = lGuess.add(new Fraction(integer));
					return negative ? absResult.negate() : absResult;
				}
				
				Fraction hGuess = lGuess.add(unit);
				lower = lower.max(lGuess);
				higher = higher.min(hGuess);
			}
			
			Fraction mediant = lower.mediant(higher);
			double mediantD = mediant.doubleValue();
			if (fraction > mediantD)
			{
				Fraction absResult = higher.add(new Fraction(integer));
				return negative ? absResult.negate() : absResult;
			}
			else if (fraction < mediantD)
			{
				Fraction absResult = lower.add(new Fraction(integer));
				return negative ? absResult.negate() : absResult;			
			}
			else
			{
				Fraction absResult = mediant.add(new Fraction(integer));
				return negative ? absResult.negate() : absResult;			
			}
		}
		
		public static Fraction valueOf(long val)
		{
			return new Fraction((int) val);		
		}
	}

	
	
	private static class MyScanner
	{
		BufferedReader br;
		StringTokenizer st;
		
		MyScanner(InputStream in)
		{
			this.br = new BufferedReader(new InputStreamReader(in));
		}
		
		String next()
		{
			while (this.st == null || !this.st.hasMoreElements())
			{
				try
				{
					this.st = new StringTokenizer(this.br.readLine());
				}
				catch (IOException e)
				{
					e.printStackTrace();
				}
			}
			return this.st.nextToken();
		}
		
		int nextInt()
		{
			return Integer.parseInt(this.next());
		}
		
		long nextLong()
		{
			return Long.parseLong(this.next());
		}
		
		double nextDouble()
		{
			return Double.parseDouble(this.next());
		}
		
		String nextLine()
		{
			String str = "";
			try
			{
				str = this.br.readLine();
			}
			catch (IOException e)
			{
				e.printStackTrace();
			}
			return str;
		}
		
	}
}
