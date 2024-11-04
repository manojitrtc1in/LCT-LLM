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
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.List;
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
		N = in.readInt();
		K = 2 * 3 * 5 * 7;
		dp = new int[N + 1][K];
		ArrayFiller.fill(dp, -1);
		if (rec(0, 0) == 0) out.printLine(-1);
		else dfs(0, 0);
	}

	int N;
	int K;
	int[][] dp;

	int rec(int n, int r) {
		if (dp[n][r] != -1) return dp[n][r];
		if (n == N) return dp[n][r] = (r == 0 ? 1 : 0);
		for (int i = 0; i < 10; ++i)
			if (n > 0 || i > 0)
				if (rec(n + 1, (r * 10 + i) % K) == 1) return dp[n][r] = 1;

		return dp[n][r] = 0;
	}

	void dfs(int n, int r) {
		if (n == N) {
			out.printLine();
			return;
		}
		for (int i = 0; i < 10; ++i)
			if (n > 0 || i > 0)
				if (rec(n + 1, (r * 10 + i) % K) == 1) {
					out.print(i);
					dfs(n + 1, (r * 10 + i) % K);
					return;
				}
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
