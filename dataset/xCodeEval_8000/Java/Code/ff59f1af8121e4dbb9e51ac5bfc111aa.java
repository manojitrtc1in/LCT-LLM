import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.Writer;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.Random;


final public class Main implements Runnable {
	private static String[] args;

	public static void main(String[] args) {
		Main.args = args;
		new Thread(null, new Main(), "MyRunThread", 1 << 27).start();
	}

	@Override
	public void run() {
		long time_beg = -1;
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		if (args.length > 0 && args[0].equals("outside")) {
			time_beg = System.currentTimeMillis();
			try {
				inputStream = new FileInputStream("IO/in.txt");


			} catch (Exception e) {
				System.err.println(e);
				System.exit(1);
			}
		} else {
			try {




			} catch (Exception e) {
				System.err.println(e);
				System.exit(1);
			}
		}

		Solver s = new Solver();
		s.in = new InputReader(inputStream);
		s.out = new OutputWriter(outputStream);
		if (args.length > 0 && args[0].equals("outside")) {
			s.dout = new DebugWriter(s.out);
		}

		s.solve();

		if (args.length > 0 && args[0].equals("outside")) {
			s.dout.printFormat("*** Total time: %.3f ***\n", (System.currentTimeMillis() - time_beg) / 1000.0);
		}

		s.out.close();
	}
}

final class Solver {
	InputReader in;
	OutputWriter out;
	DebugWriter dout;

	public void solve() {
		String s = in.readString();

		boolean[] good = new boolean[26];
		String ss = in.readString();
		for (int i = 0; i < 26; ++i)
			good[i] = ss.charAt(i) == '1' ? true : false;

		int k = in.readInt();

		HashSet<Long> set = new HashSet<Long>();

		int n = s.length();



		StringHashGenerator sg = new StringHashGenerator(26);
		StringHash hash = new StringHash(sg, s);

		for (int j = 0; j < n; ++j) {
			int count = 0;
			for (int i = j; i < n; ++i) {
				if (!good[s.charAt(i) - 'a']) ++count;
				if (count > k) break;
				set.add(hash.getHash(j, i));
			}
		}

		out.printLine(set.size());
	}
}


final class InputReader {
	private boolean finished = false;

	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;

	public InputReader(InputStream stream) {
		this.stream = stream;
	}

	private int read() {
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

	public int peek() {
		if (numChars == -1)
			return -1;
		if (curChar >= numChars) {
			curChar = 0;
			try {
				numChars = stream.read(buf);
			} catch (IOException e) {
				return -1;
			}
			if (numChars <= 0)
				return -1;
		}
		return buf[curChar];
	}

	public int readInt() {
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

	public long readLong() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		long res = 0;
		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		} while (!isSpaceChar(c));
		return res * sgn;
	}

	public String readString() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do {
			res.appendCodePoint(c);
			c = read();
		} while (!isSpaceChar(c));
		return res.toString();
	}

	public static boolean isSpaceChar(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	private String readLine0() {
		StringBuilder buf = new StringBuilder();
		int c = read();
		while (c != '\n' && c != -1) {
			if (c != '\r')
				buf.appendCodePoint(c);
			c = read();
		}
		return buf.toString();
	}

	public String readLine() {
		String s = readLine0();
		while (s.trim().length() == 0)
			s = readLine0();
		return s;
	}

	public String readLine(boolean ignoreEmptyLines) {
		if (ignoreEmptyLines)
			return readLine();
		else
			return readLine0();
	}

	public BigInteger readBigInteger() {
		try {
			return new BigInteger(readString());
		} catch (NumberFormatException e) {
			throw new InputMismatchException();
		}
	}

	public char readCharacter() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		return (char) c;
	}

	public double readDouble() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		double res = 0;
		while (!isSpaceChar(c) && c != '.') {
			if (c == 'e' || c == 'E')
				return res * Math.pow(10, readInt());
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		}
		if (c == '.') {
			c = read();
			double m = 1;
			while (!isSpaceChar(c)) {
				if (c == 'e' || c == 'E')
					return res * Math.pow(10, readInt());
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				m /= 10;
				res += (c - '0') * m;
				c = read();
			}
		}
		return res * sgn;
	}

	public boolean isExhausted() {
		int value;
		while (isSpaceChar(value = peek()) && value != -1)
			read();
		return value == -1;
	}
}

final class OutputWriter {
	private final PrintWriter writer;

	public OutputWriter(OutputStream outputStream) {
		writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
	}

	public OutputWriter(Writer writer) {
		this.writer = new PrintWriter(writer);
	}


	public void print(Object... objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void printLine(Object... objects) {
		print(objects);
		writer.println();
	}

	public void printFormat(String format, Object... objects) {
		writer.printf(format, objects);
	}


	public void print(char[] objects) {
		writer.print(objects);
	}

	public void printLine(char[] objects) {
		writer.println(objects);
	}

	public void printLine(char[][] objects) {
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
	}


	public void print(int[] objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void printLine(int[] objects) {
		print(objects);
		writer.println();
	}

	public void printLine(int[][] objects) {
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
	}


	public void print(short[] objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void printLine(short[] objects) {
		print(objects);
		writer.println();
	}

	public void printLine(short[][] objects) {
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
	}


	public void print(long[] objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void printLine(long[] objects) {
		print(objects);
		writer.println();
	}

	public void printLine(long[][] objects) {
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
	}


	public void print(double[] objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void printLine(double[] objects) {
		print(objects);
		writer.println();
	}

	public void printLine(double[][] objects) {
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
	}


	public void print(byte[] objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void printLine(byte[] objects) {
		print(objects);
		writer.println();
	}

	public void printLine(byte[][] objects) {
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
	}


	public void print(boolean[] objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void printLine(boolean[] objects) {
		print(objects);
		writer.println();
	}

	public void printLine(boolean[][] objects) {
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
	}


	public void close() {
		writer.close();
	}

	public void flush() {
		writer.flush();
	}
}

final class DebugWriter {
	private final OutputWriter writer;

	public DebugWriter(OutputWriter writer) {
		this.writer = writer;
	}

	private void printDebugMessage() {
		writer.print("DEBUG:\t");
	}


	public void printLine(Object... objects) {
		flush();
		printDebugMessage();
		writer.printLine(objects);
		flush();
	}

	public void printFormat(String format, Object... objects) {
		flush();
		printDebugMessage();
		writer.printFormat(format, objects);
		flush();
	}


	public void printLine(char[] objects) {
		flush();
		printDebugMessage();
		writer.printLine(objects);
		flush();
	}

	public void printLine(char[][] objects) {
		flush();
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
		flush();
	}


	public void printLine(double[] objects) {
		flush();
		printDebugMessage();
		writer.printLine(objects);
		flush();
	}

	public void printLine(double[][] objects) {
		flush();
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
		flush();
	}


	public void printLine(int[] objects) {
		flush();
		printDebugMessage();
		writer.printLine(objects);
		flush();
	}

	public void printLine(int[][] objects) {
		flush();
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
		flush();
	}


	public void printLine(short[] objects) {
		flush();
		printDebugMessage();
		writer.printLine(objects);
		flush();
	}

	public void printLine(short[][] objects) {
		flush();
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
		flush();
	}


	public void printLine(long[] objects) {
		flush();
		printDebugMessage();
		writer.printLine(objects);
		flush();
	}

	public void printLine(long[][] objects) {
		flush();
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
		flush();
	}


	public void printLine(byte[] objects) {
		flush();
		printDebugMessage();
		writer.printLine(objects);
		flush();
	}

	public void printLine(byte[][] objects) {
		flush();
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
		flush();
	}


	public void printLine(boolean[] objects) {
		flush();
		printDebugMessage();
		writer.printLine(objects);
		flush();
	}

	public void printLine(boolean[][] objects) {
		flush();
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
		flush();
	}


	public void flush() {
		writer.flush();
	}
}


abstract class IntegerUtils {
	public final static boolean isPrime(long value) {
		if (value < 2) return false;
		for (long divisor = 2; divisor * divisor <= value; ++divisor)
			if (value % divisor == 0)
				return false;
		return true;
	}

	public final static long nextPrime(long from) {
		if (from < 2) return 2;
		from += 1 - (from & 1);
		while (!isPrime(from))
			from += 2;
		return from;
	}

	public final static long power(long value, long exponent, final long MOD) {
		long res = 1;
		while (exponent > 0) {
			if ((exponent & 1) == 1)
				res = (res * value) % MOD;
			exponent /= 2;
			value = (value * value) % MOD;
		}
		return res;
	}

	public final static long power(long value, long exponent) {
		long res = 1;
		while (exponent > 0) {
			if ((exponent & 1) == 1)
				res *= value;
			exponent /= 2;
			value *= value;
		}
		return res;
	}

	public final static double power(double value, long exponent) {
		double res = 1.0;
		while (exponent > 0) {
			if ((exponent & 1) == 1)
				res *= value;
			exponent /= 2;
			value *= value;
		}
		return res;
	}

	public final static long gcd(long a, long b) {
		while (b > 0) {
			a %= b;
			long tmp = a;
			a = b;
			b = tmp;
		}
		return a;
	}

	public final static long lcm(long a, long b) {
		return a / gcd(a, b) * b;
	}

	
	public final static long gcd(long a, long b, long[] X) {
		if (b == 0) {
			X[0] = 1;
			X[1] = 0;
			return a;
		}

		long[] nextX = new long[2];
		long g = gcd(b, a % b, nextX);

		X[0] = nextX[1];
		X[1] = nextX[0] - a / b * nextX[1];

		return g;
	}

	public final static long inverse(long value, final long MOD) {
		long[] X = new long[2];
		long g = gcd(value, MOD, X);

		if (g != 1) return -1;
		X[0] %= MOD;
		if (X[0] < 0) X[0] += MOD;
		return X[0];
	}

	public final static Pair<Long[], Integer[]> factorize(long value) {
		ArrayList<Long> prime = new ArrayList<Long>();
		ArrayList<Integer> power = new ArrayList<Integer>();

		for (long divisor = 2; divisor * divisor <= value; ++divisor)
			if (value % divisor == 0) {
				int p = 0;
				while (value % divisor == 0) {
					++p;
					value /= divisor;
				}

				prime.add(divisor);
				power.add(p);
			}

		if (value > 1) {
			prime.add(value);
			power.add(1);
		}

		return new Pair<Long[], Integer[]>(prime.toArray(new Long[1]), power.toArray(new Integer[1]));
	}

	public final static Pair<Long[], Integer[]> factorize(int value, int[] sieve) {
		if (value >= sieve.length) throw new IllegalArgumentException();
		ArrayList<Long> prime = new ArrayList<Long>();
		ArrayList<Integer> power = new ArrayList<Integer>();

		while (value > 1) {
			int pow = 0;
			int divisor = sieve[value];
			while (sieve[value] == divisor) {
				++pow;
				value /= sieve[value];
			}
			prime.add(Long.valueOf(divisor));
			power.add(pow);
		}
		return new Pair<Long[], Integer[]>(prime.toArray(new Long[1]), power.toArray(new Integer[1]));
	}

	public final static long eulerFunction(long value) {
		long phi = value;
		for (long divisor = 2; divisor * divisor <= value; ++divisor)
			if (value % divisor == 0) {
				while (value % divisor == 0) value /= divisor;
				phi -= phi / divisor;
			}

		if (value > 1) {
			phi -= phi / value;
		}

		return phi;
	}

	public final static long eulerFunction(long value, long[] factors) {
		long phi = value;

		for (long x : factors)
			phi -= phi / x;

		return phi;
	}

	public final static long eulerFunction(long value, int[] sieve) {
		if (value >= sieve.length) throw new IllegalArgumentException();

		long phi = value;

		while (value != 1) {
			int p = sieve[(int) value];
			phi -= phi / p;
			while (sieve[(int) value] == p) value /= p;
		}

		return phi;
	}

	public final static boolean[] sieve(int length) {
		boolean[] sieve = new boolean[length];

		ArrayFiller.fill(sieve, true);
		sieve[0] = sieve[1] = false;

		for (int prime = 2; prime * prime < length; ++prime)
			if (sieve[prime])
				for (int divisor = prime * prime; divisor < length; divisor += prime)
					sieve[divisor] = false;

		return sieve;
	}

	public final static int[] sieveWithSmallestPrimes(int length) {
		int[] sieve = new int[length];

		for (int i = 0; i < length; ++i)
			sieve[i] = i;

		for (int prime = 2; prime * prime < length; ++prime)
			if (sieve[prime] == prime)
				for (int divisor = prime * prime; divisor < length; divisor += prime)
					if (sieve[divisor] == divisor)
						sieve[divisor] = prime;

		return sieve;
	}

	public final static int[] sieveWithBiggestPrimes(int length) {
		int[] sieve = new int[length];

		for (int i = 0; i < length; ++i)
			sieve[i] = i;

		for (int prime = 2; prime * prime < length; ++prime)
			if (sieve[prime] == prime)
				for (int divisor = prime * prime; divisor < length; divisor += prime)
					sieve[divisor] = prime;

		return sieve;
	}
}


abstract class ArrayFiller {
	

	public final static void fill(int[] array, int value) {
		for (int i = 0; i < array.length; ++i)
			array[i] = value;
	}

	public final static void fill(int[][] array, int value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public final static void fill(int[][][] array, int value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public final static void fill(int[][][][] array, int value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public final static void fill(int[][][][][] array, int value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public final static void fill(int[][][][][][] array, int value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public final static void fill(int[][][][][][][] array, int value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	

	public final static void fill(short[] array, short value) {
		for (int i = 0; i < array.length; ++i)
			array[i] = value;
	}

	public final static void fill(short[][] array, short value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public final static void fill(short[][][] array, short value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public final static void fill(short[][][][] array, short value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public final static void fill(short[][][][][] array, short value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public final static void fill(short[][][][][][] array, short value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public final static void fill(short[][][][][][][] array, short value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	

	public final static void fill(long[] array, long value) {
		for (int i = 0; i < array.length; ++i)
			array[i] = value;
	}

	public final static void fill(long[][] array, long value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public final static void fill(long[][][] array, long value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public final static void fill(long[][][][] array, long value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public final static void fill(long[][][][][] array, long value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public final static void fill(long[][][][][][] array, long value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public final static void fill(long[][][][][][][] array, long value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	

	public final static void fill(double[] array, double value) {
		for (int i = 0; i < array.length; ++i)
			array[i] = value;
	}

	public final static void fill(double[][] array, double value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public final static void fill(double[][][] array, double value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public final static void fill(double[][][][] array, double value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public final static void fill(double[][][][][] array, double value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public final static void fill(double[][][][][][] array, double value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public final static void fill(double[][][][][][][] array, double value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	

	public final static void fill(boolean[] array, boolean value) {
		for (int i = 0; i < array.length; ++i)
			array[i] = value;
	}

	public final static void fill(boolean[][] array, boolean value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public final static void fill(boolean[][][] array, boolean value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public final static void fill(boolean[][][][] array, boolean value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public final static void fill(boolean[][][][][] array, boolean value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public final static void fill(boolean[][][][][][] array, boolean value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public final static void fill(boolean[][][][][][][] array, boolean value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	

	public final static void fill(byte[] array, byte value) {
		for (int i = 0; i < array.length; ++i)
			array[i] = value;
	}

	public final static void fill(byte[][] array, byte value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public final static void fill(byte[][][] array, byte value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public final static void fill(byte[][][][] array, byte value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public final static void fill(byte[][][][][] array, byte value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public final static void fill(byte[][][][][][] array, byte value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public final static void fill(byte[][][][][][][] array, byte value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	

	public final static void fill(char[] array, char value) {
		for (int i = 0; i < array.length; ++i)
			array[i] = value;
	}

	public final static void fill(char[][] array, char value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public final static void fill(char[][][] array, char value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public final static void fill(char[][][][] array, char value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public final static void fill(char[][][][][] array, char value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public final static void fill(char[][][][][][] array, char value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public final static void fill(char[][][][][][][] array, char value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	

	public final static void fill(String[] array, String value) {
		for (int i = 0; i < array.length; ++i)
			array[i] = value;
	}

	public final static void fill(String[][] array, String value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public final static void fill(String[][][] array, String value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public final static void fill(String[][][][] array, String value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public final static void fill(String[][][][][] array, String value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public final static void fill(String[][][][][][] array, String value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}

	public final static void fill(String[][][][][][][] array, String value) {
		for (int i = 0; i < array.length; ++i)
			fill(array[i], value);
	}
}

final class Pair<F, S> {
	public F first;
	public S second;

	public Pair(F first, S second) {
		this.first = first;
		this.second = second;
	}

	@Override
	public int hashCode() {
		int hFirst = first != null ? first.hashCode() : 0;
		int hSecond = second != null ? second.hashCode() : 0;
		return 31 * hFirst + hSecond;
	}

	@Override
	public boolean equals(Object o) {
		if (this == o) return true;
		if (o == null || getClass() != o.getClass()) return false;

		Pair pair = (Pair) o;

		return (first != null ? first.equals(pair.first) : pair.first == null) &&
				(second != null ? second.equals(pair.second) : pair.second == null);
	}

	@Override
	protected Object clone() throws CloneNotSupportedException {
		return new Pair<F, S>(first, second);
	}

	@Override
	public String toString() {
		return "(" + first + ", " + second + ")";
	}
}

final class StringHashGenerator {
	int[] firstReversePower;
	int[] secondReversePower;

	long FIRST_MOD;
	long SECOND_MOD;

	long multiplier;
	long firstReverseMultiplier;
	long secondReverseMultiplier;

	public StringHashGenerator(int alphabetLength) {
		Random rnd = new Random(System.nanoTime());
		FIRST_MOD = IntegerUtils.nextPrime(1000000000 + rnd.nextInt(1000000000));
		SECOND_MOD = IntegerUtils.nextPrime(1000000000 + rnd.nextInt(1000000000));

		multiplier = IntegerUtils.nextPrime(alphabetLength + 1);
		firstReverseMultiplier = IntegerUtils.inverse(multiplier, FIRST_MOD);
		secondReverseMultiplier = IntegerUtils.inverse(multiplier, SECOND_MOD);

		firstReversePower = new int[1];
		secondReversePower = new int[1];

		firstReversePower[0] = 1;
		secondReversePower[0] = 1;
	}

	public void ensureCapacity(int length) {
		if (firstReversePower.length >= length) return;
		int[] oldFirst = firstReversePower;
		int[] oldSecond = secondReversePower;
		firstReversePower = new int[length];
		secondReversePower = new int[length];
		for (int i = 0; i < oldFirst.length; ++i) {
			firstReversePower[i] = oldFirst[i];
			secondReversePower[i] = oldSecond[i];
		}
		for (int i = oldFirst.length; i < length; ++i) {
			firstReversePower[i] = (int) (firstReversePower[i - 1] * firstReverseMultiplier % FIRST_MOD);
			secondReversePower[i] = (int) (secondReversePower[i - 1] * secondReverseMultiplier % SECOND_MOD);
		}
	}
}

final class StringHash {
	private int[] firstHash;
	private int[] secondHash;

	StringHashGenerator generator;

	public StringHash(StringHashGenerator generator, CharSequence string) {
		this.generator = generator;
		generator.ensureCapacity(string.length());

		firstHash = new int[string.length()];
		secondHash = new int[string.length()];

		firstHash[0] = string.charAt(0) + 1;
		secondHash[0] = string.charAt(0) + 1;

		long firstMultiplier = generator.multiplier;
		long secondMultiplier = generator.multiplier;

		for (int i = 1; i < string.length(); ++i) {
			firstHash[i] = (int) ((firstHash[i - 1] + (string.charAt(i) + 1) * firstMultiplier) % generator.FIRST_MOD);
			firstMultiplier = firstMultiplier * generator.multiplier % generator.FIRST_MOD;

			secondHash[i] = (int) ((secondHash[i - 1] + (string.charAt(i) + 1) * secondMultiplier) % generator.SECOND_MOD);
			secondMultiplier = secondMultiplier * generator.multiplier % generator.SECOND_MOD;
		}
	}

	public long getHash() {
		return getHash(0, firstHash.length - 1);
	}

	public long getHash(int startIndex, int endIndex) {
		long hash1 = firstHash[endIndex];
		long hash2 = secondHash[endIndex];

		if (startIndex > 0) {
			hash1 += -firstHash[startIndex - 1] + generator.FIRST_MOD;
			hash1 = hash1 * generator.firstReversePower[startIndex] % generator.FIRST_MOD;

			hash2 += -secondHash[startIndex - 1] + generator.SECOND_MOD;
			hash2 = hash2 * generator.secondReversePower[startIndex] % generator.SECOND_MOD;
		}

		return (hash1 << 32) | hash2;
	}
}
