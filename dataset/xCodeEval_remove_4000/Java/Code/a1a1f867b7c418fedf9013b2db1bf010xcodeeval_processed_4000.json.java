import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.Writer;
import java.math.BigInteger;
import java.util.AbstractList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.InputMismatchException;
import java.util.List;
import java.util.RandomAccess;
import java.util.TreeMap;


public class Main implements Runnable {
	private static String[] args;

	public static void main(String[] args) {
		Main.args = args;
		new Thread(null, new Main(), "MyRunThread", 1 << 26).start();
	}

	@Override
	public void run() {
		long id9 = -1;
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		if (args.length > 0 && args[0].equals("outside")) {
			id9 = System.currentTimeMillis();
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
			s.debug = new DebugWriter(s.out);
		}

		s.solve();
		s.out.close();

		if (args.length > 0 && args[0].equals("outside")) {
			s.debug.close();
			System.err.printf("*** Total time: %.3f ***\n", (System.currentTimeMillis() - id9) / 1000.0);
		}
	}
}

final class Solver {
	InputReader in;
	OutputWriter out;
	DebugWriter debug;

	public void solve() {
		long exp = in.readLong();
		int n = in.readInt();

		int[][] matrix = new int[n][n];
		for (int j = 0; j < n; ++j)
			for (int i = 0; i < n; ++i)
				matrix[j][i] = 1;

		int m = in.readInt();
		for (int i = 0; i < m; ++i) {
			char c = in.readCharacter();
			int a, b;
			if (c >= 'a' && c <= 'z') a = (c - 'a');
			else a = 26 + (c - 'A');
			c = in.readCharacter();
			if (c >= 'a' && c <= 'z') b = (c - 'a');
			else b = 26 + (c - 'A');
			matrix[a][b] = 0;
		}

		int MOD = 1000 * 1000 * 1000 + 7;

		matrix = matrixPower(matrix, exp - 1, MOD);

		int res = 0;
		for (int j = 0; j < n; ++j)
			for (int i = 0; i < n; ++i) {
				res += matrix[j][i];
				if (res >= MOD) res -= MOD;
			}

		out.printLine(res);
	}

	public static int[][] matrixPower(int[][] A, long exp, int MOD) {
		int n = A.length;
		int[][] res = new int[n][n];
		for (int i = 0; i < n; ++i)
			res[i][i] = 1;
		while (exp > 0) {
			if ((exp & 1) > 0) res = multiply(res, A, MOD);
			A = multiply(A, A, MOD);
			exp /= 2;
		}
		return res;
	}

	public static int[][] multiply(int[][] A, int[][] B, int MOD) {
		int n = A.length;
		int[][] res = new int[n][n];

		for (int j = 0; j < n; ++j)
			for (int i = 0; i < n; ++i)
				for (int k = 0; k < n; ++k) {
					res[j][i] += (long) A[j][k] * B[k][i] % MOD;
					if (res[j][i] >= MOD) res[j][i] -= MOD;
				}

		return res;
	}
}

class InputReader {
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
		while (id3(c))
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
		} while (!id3(c));
		return res * sgn;
	}

	public long readLong() {
		int c = read();
		while (id3(c))
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
		} while (!id3(c));
		return res * sgn;
	}

	public String readString() {
		int c = read();
		while (id3(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do {
			res.appendCodePoint(c);
			c = read();
		} while (!id3(c));
		return res.toString();
	}

	public static boolean id3(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	private String id1() {
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
		String s = id1();
		while (s.trim().length() == 0)
			s = id1();
		return s;
	}

	public String readLine(boolean id14) {
		if (id14)
			return readLine();
		else
			return id1();
	}

	public BigInteger id10() {
		try {
			return new BigInteger(readString());
		} catch (NumberFormatException e) {
			throw new InputMismatchException();
		}
	}

	public char readCharacter() {
		int c = read();
		while (id3(c))
			c = read();
		return (char) c;
	}

	public double readDouble() {
		int c = read();
		while (id3(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		double res = 0;
		while (!id3(c) && c != '.') {
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
			while (!id3(c)) {
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

	public boolean id2() {
		int value;
		while (id3(value = peek()) && value != -1)
			read();
		return value == -1;
	}
}

class OutputWriter {
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

class DebugWriter {
	private final OutputWriter writer;

	public DebugWriter(OutputWriter writer) {
		this.writer = writer;
	}

	private void id8() {
		writer.print("debug:\t");
	}


	public void printLine(Object... objects) {
		flush();
		id8();
		writer.printLine(objects);
		flush();
	}

	public void printFormat(String format, Object... objects) {
		flush();
		id8();
		writer.printFormat(format, objects);
		flush();
	}


	public void printLine(char[] objects) {
		flush();
		id8();
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
		id8();
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
		id8();
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
		id8();
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
		id8();
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
		id8();
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
		id8();
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

	public void close() {
		writer.close();
	}
}

abstract class ArrayWrapper<T> extends AbstractList<T> implements RandomAccess {
	public static <T> List<T> wrap(T... array) {
		return new id12<T>(array);
	}

	public static List<Integer> wrap(int... array) {
		return new id7(array);
	}

	public static List<Long> wrap(long... array) {
		return new id13(array);
	}

	public static List<Character> wrap(char... array) {
		return new id5(array);
	}

	public static List<Double> wrap(double... array) {
		return new id15(array);
	}

	public static List<Boolean> wrap(boolean... array) {
		return new id4(array);
	}

	public static List<Short> wrap(short... array) {
		return new id6(array);
	}

	public static List<Byte> wrap(byte... array) {
		return new id0(array);
	}

	public static List<Character> wrap(CharSequence sequence) {
		return new id11(sequence);
	}

	protected static class id12<T> extends ArrayWrapper<T> {
		protected final T[] array;

		protected id12(T[] array) {
			this.array = array;
		}

		public int size() {
			return array.length;
		}

		public T get(int index) {
			return array[index];
		}

		public T set(int index, T value) {
			T result = array[index];
			array[index] = value;
			return result;
		}
	}

	protected static class id7 extends ArrayWrapper<Integer> {
		protected final int[] array;

		protected id7(int[] array) {
			this.array = array;
		}

		public int size() {
			return array.length;
		}

		public Integer get(int index) {
			return array[index];
		}

		public Integer set(int index, Integer value) {
			int result = array[index];
			array[index] = value;
			return result;
		}
	}

	protected static class id13 extends ArrayWrapper<Long> {
		protected final long[] array;

		protected id13(long[] array) {
			this.array = array;
		}

		public int size() {
			return array.length;
		}

		public Long get(int index) {
			return array[index];
		}

		public Long set(int index, Long value) {
			long result = array[index];
			array[index] = value;
			return result;
		}
	}

	protected static class id5 extends ArrayWrapper<Character> {
		protected final char[] array;

		protected id5(char[] array) {
			this.array = array;
		}

		public int size() {
			return array.length;
		}

		public Character get(int index) {
			return array[index];
		}

		public Character set(int index, Character value) {
			char result = array[index];
			array[index] = value;
			return result;
		}
	}

	protected static class id15 extends ArrayWrapper<Double> {
		protected final double[] array;

		protected id15(double[] array) {
			this.array = array;
		}

		public int size() {
			return array.length;
		}

		public Double get(int index) {
			return array[index];
		}

		public Double set(int index, Double value) {
			double result = array[index];
			array[index] = value;
			return result;
		}
	}

	protected static class id4 extends ArrayWrapper<Boolean> {
		protected final boolean[] array;

		protected id4(boolean[] array) {
			this.array = array;
		}

		public int size() {
			return array.length;
		}

		public Boolean get(int index) {
			return array[index];
		}

		public Boolean set(int index, Boolean value) {
			boolean result = array[index];
			array[index] = value;
			return result;
		}
	}

	protected static class id6 extends ArrayWrapper<Short> {
		protected final short[] array;

		protected id6(short[] array) {
			this.array = array;
		}

		public int size() {
			return array.length;
		}

		public Short get(int index) {
			return array[index];
		}

		public Short set(int index, Short value) {
			short result = array[index];
			array[index] = value;
			return result;
		}
	}

	protected static class id0 extends ArrayWrapper<Byte> {
		protected final byte[] array;

		protected id0(byte[] array) {
			this.array = array;
		}

		public int size() {
			return array.length;
		}

		public Byte get(int index) {
			return array[index];
		}

		public Byte set(int index, Byte value) {
			byte result = array[index];
			array[index] = value;
			return result;
		}
	}

	protected static class id11 extends ArrayWrapper<Character> {
		protected final CharSequence sequence;

		protected id11(CharSequence sequence) {
			this.sequence = sequence;
		}

		public int size() {
			return sequence.length();
		}

		public Character get(int index) {
			return sequence.charAt(index);
		}
	}
}
