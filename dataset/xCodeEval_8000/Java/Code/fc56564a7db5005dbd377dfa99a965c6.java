import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		Task solver = new Task();
		solver.solve(1, in, out);
		out.close();
	}
}

class Task {
	
	long[] powers;
	
	public void solve(int testNumber, InputReader in, OutputWriter out) {




































		int n=in.readInt(), m=in.readInt(), mod=1000000007, base=257;
		Set<Long> set=new TreeSet<Long>();
		powers=IntegerUtils.generatePowers(base, 600001, mod);
		while (n-->0) set.add(hashCode(in.readString().toCharArray(), base, mod));
		while (m-->0) {
			char[] str=in.readString().toCharArray();
			long hash=hashCode(str, base, mod);
			boolean ret=false;
			for (int i=0; i<str.length; i++) for (int j='a'; j<'d'; j++) if (j!=str[i])
				ret|=set.contains((hash+powers[str.length-i-1]*(j-str[i])%mod+mod)%mod);
			out.printLine(ret?"YES":"NO");
		}		
	}
	
	long hashCode(char[] str, int base, int mod) {
		long ret=0;
		for (int i=0; i<str.length; i++) {
			ret=ret*base+str[i];
			ret%=mod;
		}
		return ret;
	}
}

class InputReader {
	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;
	private SpaceCharFilter filter;

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
			if (Character.isValidCodePoint(c))
				res.appendCodePoint(c);
			c = read();
		} while (!isSpaceChar(c));
		return res.toString();
	}

	public boolean isSpaceChar(int c) {
		if (filter != null)
			return filter.isSpaceChar(c);
		return isWhitespace(c);
	}

	public static boolean isWhitespace(int c) {
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

	public String next() {
		return readString();
	}

	public SpaceCharFilter getFilter() {
		return filter;
	}

	public void setFilter(SpaceCharFilter filter) {
		this.filter = filter;
	}

	public interface SpaceCharFilter {
		public boolean isSpaceChar(int ch);
	}
}

class OutputWriter {
	private final PrintWriter writer;

	public OutputWriter(OutputStream outputStream) {
		writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(
				outputStream)));
	}

	public OutputWriter(Writer writer) {
		this.writer = new PrintWriter(writer);
	}

	public void print(char[] array) {
		writer.print(array);
	}

	public void print(Object... objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void print(int[] array) {
		for (int i = 0; i < array.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(array[i]);
		}
	}

	public void print(long[] array) {
		for (int i = 0; i < array.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(array[i]);
		}
	}

	public void printLine(int[] array) {
		print(array);
		writer.println();
	}

	public void printLine(long[] array) {
		print(array);
		writer.println();
	}

	public void printLine() {
		writer.println();
	}

	public void printLine(Object... objects) {
		print(objects);
		writer.println();
	}

	public void print(char i) {
		writer.print(i);
	}

	public void printLine(char i) {
		writer.println(i);
	}

	public void printLine(char[] array) {
		writer.println(array);
	}

	public void printFormat(String format, Object... objects) {
		writer.printf(format, objects);
	}

	public void close() {
		writer.close();
	}

	public void flush() {
		writer.flush();
	}

	public void print(long i) {
		writer.print(i);
	}

	public void printLine(long i) {
		writer.println(i);
	}

	public void print(int i) {
		writer.print(i);
	}

	public void printLine(int i) {
		writer.println(i);
	}
}

class IOUtils {

	public static int[] readIntArray(InputReader in, int size) {
		int[] array = new int[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readInt();
		return array;
	}

	public static long[] readLongArray(InputReader in, int size) {
		long[] array = new long[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readLong();
		return array;
	}

	public static double[] readDoubleArray(InputReader in, int size) {
		double[] array = new double[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readDouble();
		return array;
	}

	public static String[] readStringArray(InputReader in, int size) {
		String[] array = new String[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readString();
		return array;
	}

	public static char[] readCharArray(InputReader in, int size) {
		char[] array = new char[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readCharacter();
		return array;
	}

	public static void readIntArrays(InputReader in, int[]... arrays) {
		for (int i = 0; i < arrays[0].length; i++) {
			for (int j = 0; j < arrays.length; j++)
				arrays[j][i] = in.readInt();
		}
	}

	public static void readLongArrays(InputReader in, long[]... arrays) {
		for (int i = 0; i < arrays[0].length; i++) {
			for (int j = 0; j < arrays.length; j++)
				arrays[j][i] = in.readLong();
		}
	}

	public static void readDoubleArrays(InputReader in, double[]... arrays) {
		for (int i = 0; i < arrays[0].length; i++) {
			for (int j = 0; j < arrays.length; j++)
				arrays[j][i] = in.readDouble();
		}
	}

	public static char[][] readTable(InputReader in, int rowCount,
			int columnCount) {
		char[][] table = new char[rowCount][];
		for (int i = 0; i < rowCount; i++)
			table[i] = readCharArray(in, columnCount);
		return table;
	}

	public static int[][] readIntTable(InputReader in, int rowCount,
			int columnCount) {
		int[][] table = new int[rowCount][];
		for (int i = 0; i < rowCount; i++)
			table[i] = readIntArray(in, columnCount);
		return table;
	}

	public static double[][] readDoubleTable(InputReader in, int rowCount,
			int columnCount) {
		double[][] table = new double[rowCount][];
		for (int i = 0; i < rowCount; i++)
			table[i] = readDoubleArray(in, columnCount);
		return table;
	}

	public static long[][] readLongTable(InputReader in, int rowCount,
			int columnCount) {
		long[][] table = new long[rowCount][];
		for (int i = 0; i < rowCount; i++)
			table[i] = readLongArray(in, columnCount);
		return table;
	}

	public static String[][] readStringTable(InputReader in, int rowCount,
			int columnCount) {
		String[][] table = new String[rowCount][];
		for (int i = 0; i < rowCount; i++)
			table[i] = readStringArray(in, columnCount);
		return table;
	}

	public static String readText(InputReader in) {
		StringBuilder result = new StringBuilder();
		while (true) {
			int character = in.read();
			if (character == '\r')
				continue;
			if (character == -1)
				break;
			result.append((char) character);
		}
		return result.toString();
	}

	public static void readStringArrays(InputReader in, String[]... arrays) {
		for (int i = 0; i < arrays[0].length; i++) {
			for (int j = 0; j < arrays.length; j++)
				arrays[j][i] = in.readString();
		}
	}

	public static void printTable(OutputWriter out, char[][] table) {
		for (char[] row : table)
			out.printLine(new String(row));
	}
}

class SumIntervalTree extends LongIntervalTree {
	public SumIntervalTree(int size) {
		super(size);
	}

	@Override
	protected long joinValue(long left, long right) {
		return left + right;
	}

	@Override
	protected long joinDelta(long was, long delta) {
		return was + delta;
	}

	@Override
	protected long accumulate(long value, long delta, int length) {
		return value + delta * length;
	}

	@Override
	protected long neutralValue() {
		return 0;
	}

	@Override
	protected long neutralDelta() {
		return 0;
	}
}

abstract class IntervalTree {
	protected int size;

	protected IntervalTree(int size) {
		this(size, true);
	}

	public IntervalTree(int size, boolean shouldInit) {
		this.size = size;
		int nodeCount = Math.max(1, Integer.highestOneBit(size) << 2);
		initData(size, nodeCount);
		if (shouldInit)
			init();
	}

	protected abstract void initData(int size, int nodeCount);

	protected abstract void initAfter(int root, int left, int right, int middle);

	protected abstract void initBefore(int root, int left, int right, int middle);

	protected abstract void initLeaf(int root, int index);

	protected abstract void updatePostProcess(int root, int left, int right,
			int from, int to, long delta, int middle);

	protected abstract void updatePreProcess(int root, int left, int right,
			int from, int to, long delta, int middle);

	protected abstract void updateFull(int root, int left, int right, int from,
			int to, long delta);

	protected abstract long queryPostProcess(int root, int left, int right,
			int from, int to, int middle, long leftResult, long rightResult);

	protected abstract void queryPreProcess(int root, int left, int right,
			int from, int to, int middle);

	protected abstract long queryFull(int root, int left, int right, int from,
			int to);

	protected abstract long emptySegmentResult();

	public void init() {
		if (size == 0)
			return;
		init(0, 0, size - 1);
	}

	private void init(int root, int left, int right) {
		if (left == right) {
			initLeaf(root, left);
		} else {
			int middle = (left + right) >> 1;
			initBefore(root, left, right, middle);
			init(2 * root + 1, left, middle);
			init(2 * root + 2, middle + 1, right);
			initAfter(root, left, right, middle);
		}
	}

	public void update(int from, int to, long delta) {
		update(0, 0, size - 1, from, to, delta);
	}

	protected void update(int root, int left, int right, int from, int to,
			long delta) {
		if (left > to || right < from)
			return;
		if (left >= from && right <= to) {
			updateFull(root, left, right, from, to, delta);
			return;
		}
		int middle = (left + right) >> 1;
		updatePreProcess(root, left, right, from, to, delta, middle);
		update(2 * root + 1, left, middle, from, to, delta);
		update(2 * root + 2, middle + 1, right, from, to, delta);
		updatePostProcess(root, left, right, from, to, delta, middle);
	}

	public long query(int from, int to) {
		return query(0, 0, size - 1, from, to);
	}

	protected long query(int root, int left, int right, int from, int to) {
		if (left > to || right < from)
			return emptySegmentResult();
		if (left >= from && right <= to)
			return queryFull(root, left, right, from, to);
		int middle = (left + right) >> 1;
		queryPreProcess(root, left, right, from, to, middle);
		long leftResult = query(2 * root + 1, left, middle, from, to);
		long rightResult = query(2 * root + 2, middle + 1, right, from, to);
		return queryPostProcess(root, left, right, from, to, middle,
				leftResult, rightResult);
	}
}

abstract class LongIntervalTree extends IntervalTree {
	protected long[] value;
	protected long[] delta;

	protected LongIntervalTree(int size) {
		this(size, true);
	}

	public LongIntervalTree(int size, boolean shouldInit) {
		super(size, shouldInit);
	}

	@Override
	protected void initData(int size, int nodeCount) {
		value = new long[nodeCount];
		delta = new long[nodeCount];
	}

	protected abstract long joinValue(long left, long right);

	protected abstract long joinDelta(long was, long delta);

	protected abstract long accumulate(long value, long delta, int length);

	protected abstract long neutralValue();

	protected abstract long neutralDelta();

	protected long initValue(int index) {
		return neutralValue();
	}

	@Override
	protected void initAfter(int root, int left, int right, int middle) {
		value[root] = joinValue(value[2 * root + 1], value[2 * root + 2]);
		delta[root] = neutralDelta();
	}

	@Override
	protected void initBefore(int root, int left, int right, int middle) {
	}

	@Override
	protected void initLeaf(int root, int index) {
		value[root] = initValue(index);
		delta[root] = neutralDelta();
	}

	@Override
	protected void updatePostProcess(int root, int left, int right, int from,
			int to, long delta, int middle) {
		value[root] = joinValue(value[2 * root + 1], value[2 * root + 2]);
	}

	@Override
	protected void updatePreProcess(int root, int left, int right, int from,
			int to, long delta, int middle) {
		pushDown(root, left, middle, right);
	}

	protected void pushDown(int root, int left, int middle, int right) {
		value[2 * root + 1] = accumulate(value[2 * root + 1], delta[root],
				middle - left + 1);
		value[2 * root + 2] = accumulate(value[2 * root + 2], delta[root],
				right - middle);
		delta[2 * root + 1] = joinDelta(delta[2 * root + 1], delta[root]);
		delta[2 * root + 2] = joinDelta(delta[2 * root + 2], delta[root]);
		delta[root] = neutralDelta();
	}

	@Override
	protected void updateFull(int root, int left, int right, int from, int to,
			long delta) {
		value[root] = accumulate(value[root], delta, right - left + 1);
		this.delta[root] = joinDelta(this.delta[root], delta);
	}

	@Override
	protected long queryPostProcess(int root, int left, int right, int from,
			int to, int middle, long leftResult, long rightResult) {
		return joinValue(leftResult, rightResult);
	}

	@Override
	protected void queryPreProcess(int root, int left, int right, int from,
			int to, int middle) {
		pushDown(root, left, middle, right);
	}

	@Override
	protected long queryFull(int root, int left, int right, int from, int to) {
		return value[root];
	}

	@Override
	protected long emptySegmentResult() {
		return neutralValue();
	}
}

class IntPair implements Comparable<IntPair> {
	public final int first, second;

	public IntPair(int first, int second) {
		this.first = first;
		this.second = second;
	}

	@Override
	public String toString() {
		return "(" + first + "," + second + ")";
	}

	@Override
	public boolean equals(Object o) {
		if (this == o)
			return true;
		if (o == null || getClass() != o.getClass())
			return false;

		IntPair intPair = (IntPair) o;

		return first == intPair.first && second == intPair.second;

	}

	@Override
	public int hashCode() {
		int result = first;
		result = 31 * result + second;
		return result;
	}

	public int compareTo(IntPair o) {
		if (first < o.first)
			return -1;
		if (first > o.first)
			return 1;
		if (second < o.second)
			return -1;
		if (second > o.second)
			return 1;
		return 0;
	}
}

class Matrix {
	public static long mod = Long.MAX_VALUE;
	public final long[][] data;
	public final int rowCount;
	public final int columnCount;

	public Matrix(int rowCount, int columnCount) {
		this.rowCount = rowCount;
		this.columnCount = columnCount;
		this.data = new long[rowCount][columnCount];
	}

	public Matrix(long[][] data) {
		this.rowCount = data.length;
		this.columnCount = data[0].length;
		this.data = data;
	}

	public static Matrix add(Matrix first, Matrix second) {
		Matrix result = new Matrix(first.rowCount, first.columnCount);
		for (int i = 0; i < result.rowCount; i++) {
			for (int j = 0; j < result.columnCount; j++) {
				result.data[i][j] = first.data[i][j] + second.data[i][j];
				if (result.data[i][j] >= mod)
					result.data[i][j] -= mod;
			}
		}
		return result;
	}

	public static Matrix multiply(Matrix first, Matrix second) {
		Matrix result = new Matrix(first.rowCount, second.columnCount);
		for (int i = 0; i < first.rowCount; i++) {
			for (int j = 0; j < second.rowCount; j++) {
				for (int k = 0; k < second.columnCount; k++)
					result.data[i][k] = (result.data[i][k] + first.data[i][j]
							* second.data[j][k])
							% mod;
			}
		}
		return result;
	}

	public static Matrix fastMultiply(Matrix first, Matrix second) {
		Matrix result = new Matrix(first.rowCount, second.columnCount);
		for (int i = 0; i < first.rowCount; i++) {
			for (int j = 0; j < second.rowCount; j++) {
				for (int k = 0; k < second.columnCount; k++)
					result.data[i][k] += first.data[i][j] * second.data[j][k];
			}
		}
		for (int i = 0; i < first.rowCount; i++) {
			for (int j = 0; j < second.columnCount; j++)
				result.data[i][j] %= mod;
		}
		return result;
	}

	public static Matrix identityMatrix(int size) {
		Matrix result = new Matrix(size, size);
		for (int i = 0; i < size; i++)
			result.data[i][i] = 1;
		return result;
	}

	public static long[] convert(long[][] matrix) {
		long[] result = new long[matrix.length * matrix.length];
		for (int i = 0; i < matrix.length; i++) {
			for (int j = 0; j < matrix.length; j++)
				result[i * matrix.length + j] = matrix[i][j];
		}
		return result;
	}

	public static long[] sumPowers(long[] matrix, long exponent, long mod,
			int side) {
		long[] result = new long[matrix.length];
		long[] power = new long[matrix.length];
		long[] temp = new long[matrix.length];
		long[] temp2 = new long[matrix.length];
		sumPowers(matrix, result, power, temp, temp2, exponent + 1, mod, side);
		return result;
	}

	private static void sumPowers(long[] matrix, long[] result, long[] power,
			long[] temp, long[] temp2, long exponent, long mod, int side) {
		if (exponent == 0) {
			for (int i = 0; i < matrix.length; i += side + 1)
				power[i] = 1 % mod;
			return;
		}
		if ((exponent & 1) == 0) {
			sumPowers(matrix, result, temp, power, temp2, exponent >> 1, mod,
					side);
			multiply(temp2, result, temp, mod, side);
			add(result, temp2, mod, side);
			multiply(power, temp, temp, mod, side);
		} else {
			sumPowers(matrix, result, temp, power, temp2, exponent - 1, mod,
					side);
			add(result, temp, mod, side);
			multiply(power, temp, matrix, mod, side);
		}
	}

	public static long[][] convert(long[] matrix, int side) {
		long[][] result = new long[side][side];
		for (int i = 0; i < side; i++) {
			for (int j = 0; j < side; j++)
				result[i][j] = matrix[i * side + j];
		}
		return result;
	}

	public static long[] power(long[] matrix, long exponent, long mod, int side) {
		long[] result = new long[matrix.length];
		long[] temp = new long[result.length];
		power(matrix, result, temp, exponent, mod, side);
		return result;
	}

	private static void power(long[] matrix, long[] result, long[] temp,
			long exponent, long mod, int side) {
		if (exponent == 0) {
			for (int i = 0; i < matrix.length; i += side + 1)
				result[i] = 1 % mod;
			return;
		}
		if ((exponent & 1) == 0) {
			power(matrix, temp, result, exponent >> 1, mod, side);
			multiply(result, temp, temp, mod, side);
		} else {
			power(matrix, temp, result, exponent - 1, mod, side);
			multiply(result, temp, matrix, mod, side);
		}
	}

	public static void multiply(long[] c, long[] a, long[] b, long mod, int side) {
		Arrays.fill(c, 0);
		for (int i = 0; i < side; i++) {
			for (int j = 0; j < side; j++) {
				for (int k = 0; k < side; k++) {
					c[i * side + k] += a[i * side + j] * b[j * side + k];
					if ((j & 3) == 3) {
						c[i * side + k] %= mod;
					}
				}
			}
		}
		for (int i = 0; i < c.length; i++)
			c[i] %= mod;
	}

	public static void add(long[] c, long[] a, long mod, int side) {
		for (int i = 0; i < side; i++) {
			for (int j = 0; j < side; j++) {
				c[i * side + j] += a[i * side + j];
				if (c[i * side + j] >= mod)
					c[i * side + j] -= mod;
			}
		}
	}

	public static long[] fastPower(long[] matrix, long exponent, long mod,
			int side) {
		long[] result = new long[matrix.length];
		long[] temp = new long[result.length];
		fastPower(matrix, result, temp, exponent, mod, side);
		return result;
	}

	private static void fastPower(long[] matrix, long[] result, long[] temp,
			long exponent, long mod, int side) {
		if (exponent == 0) {
			for (int i = 0; i < matrix.length; i += side + 1)
				result[i] = 1;
			return;
		}
		if ((exponent & 1) == 0) {
			fastPower(matrix, temp, result, exponent >> 1, mod, side);
			fastMultiply(result, temp, temp, mod, side);
		} else {
			power(matrix, temp, result, exponent - 1, mod, side);
			fastMultiply(result, temp, matrix, mod, side);
		}
	}

	public static void fastMultiply(long[] c, long[] a, long[] b, long mod,
			int side) {
		Arrays.fill(c, 0);
		for (int i = 0; i < side; i++) {
			for (int j = 0; j < side; j++) {
				for (int k = 0; k < side; k++)
					c[i * side + k] += a[i * side + j] * b[j * side + k];
			}
		}
		for (int i = 0; i < c.length; i++)
			c[i] %= mod;
	}

	public Matrix power(long exponent) {
		if (exponent == 0)
			return identityMatrix(rowCount);
		if (exponent == 1)
			return this;
		Matrix result = power(exponent >> 1);
		result = multiply(result, result);
		if ((exponent & 1) == 1)
			result = multiply(result, this);
		return result;
	}

	public Matrix fastPower(long exponent) {
		if (exponent == 0)
			return identityMatrix(rowCount);
		if (exponent == 1)
			return this;
		Matrix result = power(exponent >> 1);
		result = fastMultiply(result, result);
		if ((exponent & 1) == 1)
			result = fastMultiply(result, this);
		return result;
	}
}

class MiscUtils {
	public static final int[] DX4 = { 1, 0, -1, 0 };
	public static final int[] DY4 = { 0, -1, 0, 1 };
	public static final int[] DX8 = { 1, 1, 1, 0, -1, -1, -1, 0 };
	public static final int[] DY8 = { -1, 0, 1, 1, 1, 0, -1, -1 };
	public static final int[] DX_KNIGHT = { 2, 1, -1, -2, -2, -1, 1, 2 };
	public static final int[] DY_KNIGHT = { 1, 2, 2, 1, -1, -2, -2, -1 };

	private static final String[] ROMAN_TOKENS = { "M", "CM", "D", "CD", "C",
			"XC", "L", "XL", "X", "IX", "V", "IV", "I" };
	private static final int[] ROMAN_VALUES = { 1000, 900, 500, 400, 100, 90,
			50, 40, 10, 9, 5, 4, 1 };

	public static long josephProblem(long n, int k) {
		if (n == 1)
			return 0;
		if (k == 1)
			return n - 1;
		if (k > n)
			return (josephProblem(n - 1, k) + k) % n;
		long count = n / k;
		long result = josephProblem(n - count, k);
		result -= n % k;
		if (result < 0)
			result += n;
		else
			result += result / (k - 1);
		return result;
	}

	public static boolean isValidCell(int row, int column, int rowCount,
			int columnCount) {
		return row >= 0 && row < rowCount && column >= 0
				&& column < columnCount;
	}

	public static long maximalRectangleSum(long[][] array) {
		int n = array.length;
		int m = array[0].length;
		long[][] partialSums = new long[n + 1][m + 1];
		for (int i = 0; i < n; i++) {
			long rowSum = 0;
			for (int j = 0; j < m; j++) {
				rowSum += array[i][j];
				partialSums[i + 1][j + 1] = partialSums[i][j + 1] + rowSum;
			}
		}
		long result = Long.MIN_VALUE;
		for (int i = 0; i < m; i++) {
			for (int j = i; j < m; j++) {
				long minPartialSum = 0;
				for (int k = 1; k <= n; k++) {
					long current = partialSums[k][j + 1] - partialSums[k][i];
					result = Math.max(result, current - minPartialSum);
					minPartialSum = Math.min(minPartialSum, current);
				}
			}
		}
		return result;
	}

	public static int parseIP(String ip) {
		String[] components = ip.split("[.]");
		int result = 0;
		for (int i = 0; i < 4; i++)
			result += (1 << (24 - 8 * i)) * Integer.parseInt(components[i]);
		return result;
	}

	public static String buildIP(int mask) {
		StringBuilder result = new StringBuilder();
		for (int i = 0; i < 4; i++) {
			if (i != 0)
				result.append('.');
			result.append(mask >> (24 - 8 * i) & 255);
		}
		return result.toString();
	}

	public static <T> boolean equals(T first, T second) {
		return first == null && second == null || first != null
				&& first.equals(second);
	}

	public static boolean isVowel(char ch) {
		ch = Character.toUpperCase(ch);
		return ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'
				|| ch == 'Y';
	}

	public static boolean isStrictVowel(char ch) {
		ch = Character.toUpperCase(ch);
		return ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
	}

	public static String convertToRoman(int number) {
		StringBuilder result = new StringBuilder();
		for (int i = 0; i < ROMAN_TOKENS.length; i++) {
			while (number >= ROMAN_VALUES[i]) {
				number -= ROMAN_VALUES[i];
				result.append(ROMAN_TOKENS[i]);
			}
		}
		return result.toString();
	}

	public static int convertFromRoman(String number) {
		int result = 0;
		for (int i = 0; i < ROMAN_TOKENS.length; i++) {
			while (number.startsWith(ROMAN_TOKENS[i])) {
				number = number.substring(ROMAN_TOKENS[i].length());
				result += ROMAN_VALUES[i];
			}
		}
		return result;
	}

	public static int distance(int x1, int y1, int x2, int y2) {
		int dx = x1 - x2;
		int dy = y1 - y2;
		return dx * dx + dy * dy;
	}

	public static <T extends Comparable<T>> T min(T first, T second) {
		if (first.compareTo(second) <= 0)
			return first;
		return second;
	}

	public static <T extends Comparable<T>> T max(T first, T second) {
		if (first.compareTo(second) <= 0)
			return second;
		return first;
	}

	public static void decreaseByOne(int[]... arrays) {
		for (int[] array : arrays) {
			for (int i = 0; i < array.length; i++)
				array[i]--;
		}
	}

	public static int[] getIntArray(String s) {
		String[] tokens = s.split(" ");
		int[] result = new int[tokens.length];
		for (int i = 0; i < result.length; i++)
			result[i] = Integer.parseInt(tokens[i]);
		return result;
	}
}

class Graph {
	public static final int REMOVED_BIT = 0;

	protected int vertexCount;
	protected int edgeCount;

	private int[] firstOutbound;
	private int[] firstInbound;

	private Edge[] edges;
	private int[] nextInbound;
	private int[] nextOutbound;
	private int[] from;
	private int[] to;
	private long[] weight;
	public long[] capacity;
	private int[] reverseEdge;
	private int[] flags;

	public Graph(int vertexCount) {
		this(vertexCount, vertexCount);
	}

	public Graph(int vertexCount, int edgeCapacity) {
		this.vertexCount = vertexCount;
		firstOutbound = new int[vertexCount];
		Arrays.fill(firstOutbound, -1);

		from = new int[edgeCapacity];
		to = new int[edgeCapacity];
		nextOutbound = new int[edgeCapacity];
		flags = new int[edgeCapacity];
	}

	public static Graph createGraph(int vertexCount, int[] from, int[] to) {
		Graph graph = new Graph(vertexCount, from.length);
		for (int i = 0; i < from.length; i++)
			graph.addSimpleEdge(from[i], to[i]);
		return graph;
	}

	public static Graph createWeightedGraph(int vertexCount, int[] from,
			int[] to, long[] weight) {
		Graph graph = new Graph(vertexCount, from.length);
		for (int i = 0; i < from.length; i++)
			graph.addWeightedEdge(from[i], to[i], weight[i]);
		return graph;
	}

	public static Graph createFlowGraph(int vertexCount, int[] from, int[] to,
			long[] capacity) {
		Graph graph = new Graph(vertexCount, from.length * 2);
		for (int i = 0; i < from.length; i++)
			graph.addFlowEdge(from[i], to[i], capacity[i]);
		return graph;
	}

	public static Graph createFlowWeightedGraph(int vertexCount, int[] from,
			int[] to, long[] weight, long[] capacity) {
		Graph graph = new Graph(vertexCount, from.length * 2);
		for (int i = 0; i < from.length; i++)
			graph.addFlowWeightedEdge(from[i], to[i], weight[i], capacity[i]);
		return graph;
	}

	public static Graph createTree(int[] parent) {
		Graph graph = new Graph(parent.length + 1, parent.length);
		for (int i = 0; i < parent.length; i++)
			graph.addSimpleEdge(parent[i], i + 1);
		return graph;
	}

	public int addEdge(int fromID, int toID, long weight, long capacity,
			int reverseEdge) {
		ensureEdgeCapacity(edgeCount + 1);
		if (firstOutbound[fromID] != -1)
			nextOutbound[edgeCount] = firstOutbound[fromID];
		else
			nextOutbound[edgeCount] = -1;
		firstOutbound[fromID] = edgeCount;
		if (firstInbound != null) {
			if (firstInbound[toID] != -1)
				nextInbound[edgeCount] = firstInbound[toID];
			else
				nextInbound[edgeCount] = -1;
			firstInbound[toID] = edgeCount;
		}
		this.from[edgeCount] = fromID;
		this.to[edgeCount] = toID;
		if (capacity != 0) {
			if (this.capacity == null)
				this.capacity = new long[from.length];
			this.capacity[edgeCount] = capacity;
		}
		if (weight != 0) {
			if (this.weight == null)
				this.weight = new long[from.length];
			this.weight[edgeCount] = weight;
		}
		if (reverseEdge != -1) {
			if (this.reverseEdge == null) {
				this.reverseEdge = new int[from.length];
				Arrays.fill(this.reverseEdge, 0, edgeCount, -1);
			}
			this.reverseEdge[edgeCount] = reverseEdge;
		}
		if (edges != null)
			edges[edgeCount] = createEdge(edgeCount);
		return edgeCount++;
	}

	protected final GraphEdge createEdge(int id) {
		return new GraphEdge(id);
	}

	public final int addFlowWeightedEdge(int from, int to, long weight,
			long capacity) {
		if (capacity == 0) {
			return addEdge(from, to, weight, 0, -1);
		} else {
			int lastEdgeCount = edgeCount;
			addEdge(to, from, -weight, 0, lastEdgeCount + entriesPerEdge());
			return addEdge(from, to, weight, capacity, lastEdgeCount);
		}
	}

	protected int entriesPerEdge() {
		return 1;
	}

	public final int addFlowEdge(int from, int to, long capacity) {
		return addFlowWeightedEdge(from, to, 0, capacity);
	}

	public final int addWeightedEdge(int from, int to, long weight) {
		return addFlowWeightedEdge(from, to, weight, 0);
	}

	public final int addSimpleEdge(int from, int to) {
		return addWeightedEdge(from, to, 0);
	}

	public final int vertexCount() {
		return vertexCount;
	}

	public final int edgeCount() {
		return edgeCount;
	}

	protected final int edgeCapacity() {
		return from.length;
	}

	public final Edge edge(int id) {
		initEdges();
		return edges[id];
	}

	public final int firstOutbound(int vertex) {
		int id = firstOutbound[vertex];
		while (id != -1 && isRemoved(id))
			id = nextOutbound[id];
		return id;
	}

	public final int nextOutbound(int id) {
		id = nextOutbound[id];
		while (id != -1 && isRemoved(id))
			id = nextOutbound[id];
		return id;
	}

	public final int firstInbound(int vertex) {
		initInbound();
		int id = firstInbound[vertex];
		while (id != -1 && isRemoved(id))
			id = nextInbound[id];
		return id;
	}

	public final int nextInbound(int id) {
		initInbound();
		id = nextInbound[id];
		while (id != -1 && isRemoved(id))
			id = nextInbound[id];
		return id;
	}

	public final int source(int id) {
		return from[id];
	}

	public final int destination(int id) {
		return to[id];
	}

	public final long weight(int id) {
		if (weight == null)
			return 0;
		return weight[id];
	}

	public final long capacity(int id) {
		if (capacity == null)
			return 0;
		return capacity[id];
	}

	public final long flow(int id) {
		if (reverseEdge == null)
			return 0;
		return capacity[reverseEdge[id]];
	}

	public final void pushFlow(int id, long flow) {
		if (flow == 0)
			return;
		if (flow > 0) {
			if (capacity(id) < flow)
				throw new IllegalArgumentException("Not enough capacity");
		} else {
			if (flow(id) < -flow)
				throw new IllegalArgumentException("Not enough capacity");
		}
		capacity[id] -= flow;
		capacity[reverseEdge[id]] += flow;
	}

	public int transposed(int id) {
		return -1;
	}

	public final int reverse(int id) {
		if (reverseEdge == null)
			return -1;
		return reverseEdge[id];
	}

	public final void addVertices(int count) {
		ensureVertexCapacity(vertexCount + count);
		Arrays.fill(firstOutbound, vertexCount, vertexCount + count, -1);
		if (firstInbound != null)
			Arrays.fill(firstInbound, vertexCount, vertexCount + count, -1);
		vertexCount += count;
	}

	protected final void initEdges() {
		if (edges == null) {
			edges = new Edge[from.length];
			for (int i = 0; i < edgeCount; i++)
				edges[i] = createEdge(i);
		}
	}

	public final void removeVertex(int vertex) {
		int id = firstOutbound[vertex];
		while (id != -1) {
			removeEdge(id);
			id = nextOutbound[id];
		}
		initInbound();
		id = firstInbound[vertex];
		while (id != -1) {
			removeEdge(id);
			id = nextInbound[id];
		}
	}

	private void initInbound() {
		if (firstInbound == null) {
			firstInbound = new int[firstOutbound.length];
			Arrays.fill(firstInbound, 0, vertexCount, -1);
			nextInbound = new int[from.length];
			for (int i = 0; i < edgeCount; i++) {
				nextInbound[i] = firstInbound[to[i]];
				firstInbound[to[i]] = i;
			}
		}
	}

	public final boolean flag(int id, int bit) {
		return (flags[id] >> bit & 1) != 0;
	}

	public final void setFlag(int id, int bit) {
		flags[id] |= 1 << bit;
	}

	public final void removeFlag(int id, int bit) {
		flags[id] &= -1 - (1 << bit);
	}

	public final void removeEdge(int id) {
		setFlag(id, REMOVED_BIT);
	}

	public final void restoreEdge(int id) {
		removeFlag(id, REMOVED_BIT);
	}

	public final boolean isRemoved(int id) {
		return flag(id, REMOVED_BIT);
	}

	public final Iterable<Edge> outbound(final int id) {
		initEdges();
		return new Iterable<Edge>() {
			public Iterator<Edge> iterator() {
				return new EdgeIterator(id, firstOutbound, nextOutbound);
			}
		};
	}

	public final Iterable<Edge> inbound(final int id) {
		initEdges();
		initInbound();
		return new Iterable<Edge>() {
			public Iterator<Edge> iterator() {
				return new EdgeIterator(id, firstInbound, nextInbound);
			}
		};
	}

	protected void ensureEdgeCapacity(int size) {
		if (from.length < size) {
			int newSize = Math.max(size, 2 * from.length);
			if (edges != null)
				edges = resize(edges, newSize);
			from = resize(from, newSize);
			to = resize(to, newSize);
			nextOutbound = resize(nextOutbound, newSize);
			if (nextInbound != null)
				nextInbound = resize(nextInbound, newSize);
			if (weight != null)
				weight = resize(weight, newSize);
			if (capacity != null)
				capacity = resize(capacity, newSize);
			if (reverseEdge != null)
				reverseEdge = resize(reverseEdge, newSize);
			flags = resize(flags, newSize);
		}
	}

	private void ensureVertexCapacity(int size) {
		if (firstOutbound.length < size) {
			int newSize = Math.max(size, 2 * from.length);
			firstOutbound = resize(firstOutbound, newSize);
			if (firstInbound != null)
				firstInbound = resize(firstInbound, newSize);
		}
	}

	protected final int[] resize(int[] array, int size) {
		int[] newArray = new int[size];
		System.arraycopy(array, 0, newArray, 0, array.length);
		return newArray;
	}

	private long[] resize(long[] array, int size) {
		long[] newArray = new long[size];
		System.arraycopy(array, 0, newArray, 0, array.length);
		return newArray;
	}

	private Edge[] resize(Edge[] array, int size) {
		Edge[] newArray = new Edge[size];
		System.arraycopy(array, 0, newArray, 0, array.length);
		return newArray;
	}

	public final boolean isSparse() {
		return vertexCount == 0 || edgeCount * 20 / vertexCount <= vertexCount;
	}

	protected class GraphEdge implements Edge {
		protected int id;

		protected GraphEdge(int id) {
			this.id = id;
		}

		public int getSource() {
			return source(id);
		}

		public int getDestination() {
			return destination(id);
		}

		public long getWeight() {
			return weight(id);
		}

		public long getCapacity() {
			return capacity(id);
		}

		public long getFlow() {
			return flow(id);
		}

		public void pushFlow(long flow) {
			Graph.this.pushFlow(id, flow);
		}

		public boolean getFlag(int bit) {
			return flag(id, bit);
		}

		public void setFlag(int bit) {
			Graph.this.setFlag(id, bit);
		}

		public void removeFlag(int bit) {
			Graph.this.removeFlag(id, bit);
		}

		public int getTransposedID() {
			return transposed(id);
		}

		public Edge getTransposedEdge() {
			int reverseID = getTransposedID();
			if (reverseID == -1)
				return null;
			initEdges();
			return edge(reverseID);
		}

		public int getReverseID() {
			return reverse(id);
		}

		public Edge getReverseEdge() {
			int reverseID = getReverseID();
			if (reverseID == -1)
				return null;
			initEdges();
			return edge(reverseID);
		}

		public int getID() {
			return id;
		}

		public void remove() {
			removeEdge(id);
		}

		public void restore() {
			restoreEdge(id);
		}
	}

	public class EdgeIterator implements Iterator<Edge> {
		private int edgeID;
		private final int[] next;
		private int lastID = -1;

		public EdgeIterator(int id, int[] first, int[] next) {
			this.next = next;
			edgeID = nextEdge(first[id]);
		}

		private int nextEdge(int id) {
			while (id != -1 && isRemoved(id))
				id = next[id];
			return id;
		}

		public boolean hasNext() {
			return edgeID != -1;
		}

		public Edge next() {
			if (edgeID == -1)
				throw new NoSuchElementException();
			lastID = edgeID;
			edgeID = nextEdge(next[lastID]);
			return edges[lastID];
		}

		public void remove() {
			if (lastID == -1)
				throw new IllegalStateException();
			removeEdge(lastID);
			lastID = -1;
		}
	}

}

class MaxFlow {
	private final Graph graph;
	private int source;
	private int destination;
	private int[] queue;
	private int[] distance;
	private int[] nextEdge;

	private MaxFlow(Graph graph, int source, int destination) {
		this.graph = graph;
		this.source = source;
		this.destination = destination;
		int vertexCount = graph.vertexCount();
		queue = new int[vertexCount];
		distance = new int[vertexCount];
		nextEdge = new int[vertexCount];
	}

	public static long dinic(Graph graph, int source, int destination) {
		return new MaxFlow(graph, source, destination).dinic();
	}

	private long dinic() {
		long totalFlow = 0;
		while (true) {
			edgeDistances();
			if (distance[destination] == -1)
				break;
			Arrays.fill(nextEdge, -2);
			totalFlow += dinicImpl(source, Long.MAX_VALUE);
		}
		return totalFlow;
	}

	private void edgeDistances() {
		Arrays.fill(distance, -1);
		distance[source] = 0;
		int size = 1;
		queue[0] = source;
		for (int i = 0; i < size; i++) {
			int current = queue[i];
			int id = graph.firstOutbound(current);
			while (id != -1) {
				if (graph.capacity(id) != 0) {
					int next = graph.destination(id);
					if (distance[next] == -1) {
						distance[next] = distance[current] + 1;
						queue[size++] = next;
					}
				}
				id = graph.nextOutbound(id);
			}
		}
	}

	private long dinicImpl(int source, long flow) {
		if (source == destination)
			return flow;
		if (flow == 0 || distance[source] == distance[destination])
			return 0;
		int id = nextEdge[source];
		if (id == -2)
			nextEdge[source] = id = graph.firstOutbound(source);
		long totalPushed = 0;
		while (id != -1) {
			int nextDestinationID = graph.destination(id);
			if (graph.capacity(id) != 0
					&& distance[nextDestinationID] == distance[source] + 1) {
				long pushed = dinicImpl(nextDestinationID,
						Math.min(flow, graph.capacity(id)));
				if (pushed != 0) {
					graph.pushFlow(id, pushed);
					flow -= pushed;
					totalPushed += pushed;
					if (flow == 0)
						return totalPushed;
				}
			}
			nextEdge[source] = id = graph.nextOutbound(id);
		}
		return totalPushed;
	}
}

interface Edge {
	public int getSource();

	public int getDestination();

	public long getWeight();

	public long getCapacity();

	public long getFlow();

	public void pushFlow(long flow);

	public boolean getFlag(int bit);

	public void setFlag(int bit);

	public void removeFlag(int bit);

	public int getTransposedID();

	public Edge getTransposedEdge();

	public int getReverseID();

	public Edge getReverseEdge();

	public int getID();

	public void remove();

	public void restore();
}

class Point {
	public static final Point ORIGIN = new Point(0, 0);
	public final double x;
	public final double y;

	@Override
	public String toString() {
		return "(" + x + ", " + y + ")";
	}

	public Point(double x, double y) {
		this.x = x;
		this.y = y;
	}

	public Line line(Point other) {
		if (equals(other))
			return null;
		double a = other.y - y;
		double b = x - other.x;
		double c = -a * x - b * y;
		return new Line(a, b, c);
	}

	@Override
	public boolean equals(Object o) {
		if (this == o)
			return true;
		if (o == null || getClass() != o.getClass())
			return false;

		Point point = (Point) o;

		return Math.abs(x - point.x) <= GeometryUtils.epsilon
				&& Math.abs(y - point.y) <= GeometryUtils.epsilon;
	}

	@Override
	public int hashCode() {
		int result;
		long temp;
		temp = x != +0.0d ? Double.doubleToLongBits(x) : 0L;
		result = (int) (temp ^ (temp >>> 32));
		temp = y != +0.0d ? Double.doubleToLongBits(y) : 0L;
		result = 31 * result + (int) (temp ^ (temp >>> 32));
		return result;
	}

	public double distance(Point other) {
		return GeometryUtils.fastHypot(x - other.x, y - other.y);
	}

	public double distance(Line line) {
		return Math.abs(line.a * x + line.b * y + line.c);
	}

	public double value() {
		return GeometryUtils.fastHypot(x, y);
	}

	public double angle() {
		return Math.atan2(y, x);
	}

	public static Point readPoint(InputReader in) {
		double x = in.readDouble();
		double y = in.readDouble();
		return new Point(x, y);
	}

	public Point rotate(double angle) {
		double nx = x * Math.cos(angle) - y * Math.sin(angle);
		double ny = y * Math.cos(angle) + x * Math.sin(angle);
		return new Point(nx, ny);
	}
}

class Line {
	public final double a;
	public final double b;
	public final double c;

	public Line(Point p, double angle) {
		a = Math.sin(angle);
		b = -Math.cos(angle);
		c = -p.x * a - p.y * b;
	}

	public Line(double a, double b, double c) {
		double h = GeometryUtils.fastHypot(a, b);
		this.a = a / h;
		this.b = b / h;
		this.c = c / h;
	}

	public Point intersect(Line other) {
		if (parallel(other))
			return null;
		double determinant = b * other.a - a * other.b;
		double x = (c * other.b - b * other.c) / determinant;
		double y = (a * other.c - c * other.a) / determinant;
		return new Point(x, y);
	}

	public boolean parallel(Line other) {
		return Math.abs(a * other.b - b * other.a) < GeometryUtils.epsilon;
	}

	public boolean contains(Point point) {
		return Math.abs(value(point)) < GeometryUtils.epsilon;
	}

	public Line perpendicular(Point point) {
		return new Line(-b, a, b * point.x - a * point.y);
	}

	public double value(Point point) {
		return a * point.x + b * point.y + c;
	}

	public double distance(Point center) {
		return Math.abs(value(center));
	}

	@Override
	public boolean equals(Object o) {
		if (this == o)
			return true;
		if (o == null || getClass() != o.getClass())
			return false;

		Line line = (Line) o;

		if (!parallel(line))
			return false;
		if (Math.abs(a * line.c - c * line.a) > GeometryUtils.epsilon
				|| Math.abs(b * line.c - c * line.b) > GeometryUtils.epsilon)
			return false;

		return true;
	}
}

class GeometryUtils {
	public static double epsilon = 1e-8;

	public static double fastHypot(double... x) {
		if (x.length == 0)
			return 0;
		else if (x.length == 1)
			return Math.abs(x[0]);
		else {
			double sumSquares = 0;
			for (double value : x)
				sumSquares += value * value;
			return Math.sqrt(sumSquares);
		}
	}

	public static double fastHypot(double x, double y) {
		return Math.sqrt(x * x + y * y);
	}

	public static double fastHypot(double[] x, double[] y) {
		if (x.length == 0)
			return 0;
		else if (x.length == 1)
			return Math.abs(x[0] - y[0]);
		else {
			double sumSquares = 0;
			for (int i = 0; i < x.length; i++) {
				double diff = x[i] - y[i];
				sumSquares += diff * diff;
			}
			return Math.sqrt(sumSquares);
		}
	}

	public static double fastHypot(int[] x, int[] y) {
		if (x.length == 0)
			return 0;
		else if (x.length == 1)
			return Math.abs(x[0] - y[0]);
		else {
			double sumSquares = 0;
			for (int i = 0; i < x.length; i++) {
				double diff = x[i] - y[i];
				sumSquares += diff * diff;
			}
			return Math.sqrt(sumSquares);
		}
	}

	public static double missileTrajectoryLength(double v, double angle,
			double g) {
		return (v * v * Math.sin(2 * angle)) / g;
	}

	public static double sphereVolume(double radius) {
		return 4 * Math.PI * radius * radius * radius / 3;
	}

	public static double triangleSquare(double first, double second,
			double third) {
		double p = (first + second + third) / 2;
		return Math.sqrt(p * (p - first) * (p - second) * (p - third));
	}

	public static double canonicalAngle(double angle) {
		while (angle > Math.PI)
			angle -= 2 * Math.PI;
		while (angle < -Math.PI)
			angle += 2 * Math.PI;
		return angle;
	}

	public static double positiveAngle(double angle) {
		while (angle > 2 * Math.PI - GeometryUtils.epsilon)
			angle -= 2 * Math.PI;
		while (angle < -GeometryUtils.epsilon)
			angle += 2 * Math.PI;
		return angle;
	}
}

class IntegerUtils {
	public static long gcd(long a, long b) {
		a = Math.abs(a);
		b = Math.abs(b);
		while (b != 0) {
			long temp = a % b;
			a = b;
			b = temp;
		}
		return a;
	}

	public static int gcd(int a, int b) {
		a = Math.abs(a);
		b = Math.abs(b);
		while (b != 0) {
			int temp = a % b;
			a = b;
			b = temp;
		}
		return a;
	}

	public static boolean[] generatePrimalityTable(int upTo) {
		boolean[] isPrime = new boolean[upTo];
		if (upTo < 2)
			return isPrime;
		Arrays.fill(isPrime, true);
		isPrime[0] = isPrime[1] = false;
		for (int i = 2; i * i < upTo; i++) {
			if (isPrime[i]) {
				for (int j = i * i; j < upTo; j += i)
					isPrime[j] = false;
			}
		}
		return isPrime;
	}

	public static int[] generateBitPrimalityTable(int upTo) {
		int[] isPrime = new int[(upTo + 31) >> 5];
		if (upTo < 2)
			return isPrime;
		Arrays.fill(isPrime, -1);
		isPrime[0] &= -4;
		for (int i = 2; i * i < upTo; i++) {
			if ((isPrime[i >> 5] >>> (i & 31) & 1) == 1) {
				for (int j = i * i; j < upTo; j += i)
					isPrime[j >> 5] &= -1 - (1 << (j & 31));
			}
		}
		return isPrime;
	}

	public static int[] generateDivisorTable(int upTo) {
		int[] divisor = new int[upTo];
		for (int i = 1; i < upTo; i++)
			divisor[i] = i;
		for (int i = 2; i * i < upTo; i++) {
			if (divisor[i] == i) {
				for (int j = i * i; j < upTo; j += i)
					divisor[j] = i;
			}
		}
		return divisor;
	}

	public static long powerInFactorial(long n, long p) {
		long result = 0;
		while (n != 0) {
			result += n /= p;
		}
		return result;
	}

	public static int sumDigits(CharSequence number) {
		int result = 0;
		for (int i = number.length() - 1; i >= 0; i--)
			result += digitValue(number.charAt(i));
		return result;
	}

	public static int digitValue(char digit) {
		if (Character.isDigit(digit))
			return digit - '0';
		if (Character.isUpperCase(digit))
			return digit + 10 - 'A';
		return digit + 10 - 'a';
	}

	public static int longCompare(long a, long b) {
		if (a < b)
			return -1;
		if (a > b)
			return 1;
		return 0;
	}

	public static long[][] generateBinomialCoefficients(int n) {
		long[][] result = new long[n + 1][n + 1];
		for (int i = 0; i <= n; i++) {
			result[i][0] = 1;
			for (int j = 1; j <= i; j++)
				result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
		}
		return result;
	}

	public static long[][] generateBinomialCoefficients(int n, long module) {
		long[][] result = new long[n + 1][n + 1];
		if (module == 1)
			return result;
		for (int i = 0; i <= n; i++) {
			result[i][0] = 1;
			for (int j = 1; j <= i; j++) {
				result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
				if (result[i][j] >= module)
					result[i][j] -= module;
			}
		}
		return result;
	}

	public static long[] generateBinomialRow(int n, long module) {
		long[] result = generateReverse(n + 1, module);
		result[0] = 1;
		for (int i = 1; i <= n; i++)
			result[i] = result[i - 1] * (n - i + 1) % module * result[i]
					% module;
		return result;
	}

	public static int[] representationInBase(long number, int base) {
		long basePower = base;
		int exponent = 1;
		while (number >= basePower) {
			basePower *= base;
			exponent++;
		}
		int[] representation = new int[exponent];
		for (int i = 0; i < exponent; i++) {
			basePower /= base;
			representation[i] = (int) (number / basePower);
			number %= basePower;
		}
		return representation;
	}

	public static int trueDivide(int a, int b) {
		return (a - trueMod(a, b)) / b;
	}

	public static long trueDivide(long a, long b) {
		return (a - trueMod(a, b)) / b;
	}

	public static int trueMod(int a, int b) {
		a %= b;
		a += b;
		a %= b;
		return a;
	}

	public static long trueMod(long a, long b) {
		a %= b;
		a += b;
		a %= b;
		return a;
	}

	public static long factorial(int n) {
		long result = 1;
		for (int i = 2; i <= n; i++)
			result *= i;
		return result;
	}

	public static long factorial(int n, long mod) {
		long result = 1;
		for (int i = 2; i <= n; i++)
			result = result * i % mod;
		return result % mod;
	}

	public static long power(long base, long exponent) {
		if (exponent == 0)
			return 1;
		long result = power(base, exponent >> 1);
		result = result * result;
		if ((exponent & 1) != 0)
			result = result * base;
		return result;
	}

	public static long power(long base, long exponent, long mod) {
		if (base >= mod)
			base %= mod;
		if (exponent == 0)
			return 1 % mod;
		long result = power(base, exponent >> 1, mod);
		result = result * result % mod;
		if ((exponent & 1) != 0)
			result = result * base % mod;
		return result;
	}

	public static long lcm(long a, long b) {
		return a / gcd(a, b) * b;
	}

	public static long[] generateFibonacci(long upTo) {
		int count = 0;
		long last = 0;
		long current = 1;
		while (current <= upTo) {
			long next = last + current;
			last = current;
			current = next;
			count++;
		}
		return generateFibonacci(count, -1);
	}

	public static long[] generateFibonacci(int count, long module) {
		long[] result = new long[count];
		if (module == -1) {
			if (count != 0)
				result[0] = 1;
			if (count > 1)
				result[1] = 1;
			for (int i = 2; i < count; i++)
				result[i] = result[i - 1] + result[i - 2];
		} else {
			if (count != 0)
				result[0] = 1 % module;
			if (count > 1)
				result[1] = 1 % module;
			for (int i = 2; i < count; i++)
				result[i] = (result[i - 1] + result[i - 2]) % module;
		}
		return result;
	}

	public static long[] generateHappy(int digits) {
		long[] happy = new long[(1 << (digits + 1)) - 2];
		happy[0] = 4;
		happy[1] = 7;
		int first = 0;
		int last = 2;
		for (int i = 2; i <= digits; i++) {
			for (int j = 0; j < last - first; j++) {
				happy[last + 2 * j] = 10 * happy[first + j] + 4;
				happy[last + 2 * j + 1] = 10 * happy[first + j] + 7;
			}
			int next = last + 2 * (last - first);
			first = last;
			last = next;
		}
		return happy;
	}

	public static long[] generateFactorial(int count, long module) {
		long[] result = new long[count];
		if (module == -1) {
			if (count != 0)
				result[0] = 1;
			for (int i = 1; i < count; i++)
				result[i] = result[i - 1] * i;
		} else {
			if (count != 0)
				result[0] = 1 % module;
			for (int i = 1; i < count; i++)
				result[i] = (result[i - 1] * i) % module;
		}
		return result;
	}

	public static long reverse(long number, long module) {
		return power(number, module - 2, module);
	}

	public static boolean isPrime(long number) {
		if (number < 2)
			return false;
		for (long i = 2; i * i <= number; i++) {
			if (number % i == 0)
				return false;
		}
		return true;
	}

	public static long[] generateReverse(int upTo, long module) {
		long[] result = new long[upTo];
		if (upTo > 1)
			result[1] = 1;
		for (int i = 2; i < upTo; i++)
			result[i] = (module - module / i * result[((int) (module % i))]
					% module)
					% module;
		return result;
	}

	public static long[] generateReverseFactorials(int upTo, long module) {
		long[] result = generateReverse(upTo, module);
		if (upTo > 0)
			result[0] = 1;
		for (int i = 1; i < upTo; i++)
			result[i] = result[i] * result[i - 1] % module;
		return result;
	}

	public static long[] generatePowers(long base, int count, long mod) {
		long[] result = new long[count];
		if (count != 0)
			result[0] = 1 % mod;
		for (int i = 1; i < count; i++)
			result[i] = result[i - 1] * base % mod;
		return result;
	}

	public static long nextPrime(long from) {
		if (from <= 2)
			return 2;
		from += 1 - (from & 1);
		while (!isPrime(from))
			from += 2;
		return from;
	}

	public static long binomialCoefficient(int n, int m, long mod) {
		if (m < 0 || m > n)
			return 0;
		if (2 * m > n)
			m = n - m;
		long result = 1;
		for (int i = n - m + 1; i <= n; i++)
			result = result * i % mod;
		return result
				* BigInteger.valueOf(factorial(m, mod))
						.modInverse(BigInteger.valueOf(mod)).longValue() % mod;
	}

	public static boolean isSquare(long number) {
		long sqrt = Math.round(Math.sqrt(number));
		return sqrt * sqrt == number;
	}

	public static long findCommon(long aRemainder, long aMod, long bRemainder,
			long bMod) {
		long modGCD = gcd(aMod, bMod);
		long gcdRemainder = aRemainder % modGCD;
		if (gcdRemainder != bRemainder % modGCD)
			return -1;
		aMod /= modGCD;
		aRemainder /= modGCD;
		bMod /= modGCD;
		bRemainder /= modGCD;
		long aReverse = BigInteger.valueOf(aMod)
				.modInverse(BigInteger.valueOf(bMod)).longValue();
		long bReverse = BigInteger.valueOf(bMod)
				.modInverse(BigInteger.valueOf(aMod)).longValue();
		long mod = aMod * bMod;
		return BigInteger
				.valueOf(bReverse * aRemainder % mod)
				.multiply(BigInteger.valueOf(bMod))
				.add(BigInteger.valueOf(aReverse * bRemainder % mod).multiply(
						BigInteger.valueOf(aMod))).mod(BigInteger.valueOf(mod))
				.longValue()
				* modGCD + gcdRemainder;
	}

	public static long[] generatePowers(long base, long maxValue) {
		if (maxValue <= 0)
			return new long[0];
		int size = 1;
		long current = 1;
		while (maxValue / base >= current) {
			current *= base;
			size++;
		}
		return generatePowers(base, size, Long.MAX_VALUE);
	}
}

class GraphAlgorithms {
	public static int[] topologicalSort(Graph graph) {
		int count = graph.vertexCount();
		int[] queue = new int[count];
		int[] degree = new int[count];
		int size = 0;
		for (int i = 0; i < graph.edgeCount(); i++) {
			if (!graph.isRemoved(i))
				degree[graph.destination(i)]++;
		}
		for (int i = 0; i < count; i++) {
			if (degree[i] == 0)
				queue[size++] = i;
		}
		for (int i = 0; i < size; i++) {
			int current = queue[i];
			for (int j = graph.firstOutbound(current); j != -1; j = graph
					.nextOutbound(j)) {
				int next = graph.destination(j);
				if (--degree[next] == 0)
					queue[size++] = next;
			}
		}
		if (size != count)
			return null;
		return queue;
	}
}

class SCCKosaraju {

	public static List<List<Integer>> scc(List<Integer>[] graph) {
		int n = graph.length;
		boolean[] used = new boolean[n];
		List<Integer> order = new ArrayList<>();
		for (int i = 0; i < n; i++)
			if (!used[i])
				dfs(graph, used, order, i);

		List<Integer>[] reverseGraph = new List[n];
		for (int i = 0; i < n; i++)
			reverseGraph[i] = new ArrayList<>();
		for (int i = 0; i < n; i++)
			for (int j : graph[i])
				reverseGraph[j].add(i);

		List<List<Integer>> components = new ArrayList<>();
		Arrays.fill(used, false);
		Collections.reverse(order);

		for (int u : order)
			if (!used[u]) {
				List<Integer> component = new ArrayList<>();
				dfs(reverseGraph, used, component, u);
				components.add(component);
			}

		return components;
	}

	static void dfs(List<Integer>[] graph, boolean[] used, List<Integer> res,
			int u) {
		used[u] = true;
		for (int v : graph[u])
			if (!used[v])
				dfs(graph, used, res, v);
		res.add(u);
	}

	

	public static void main(String[] args) {
		List<Integer>[] g = new List[3];
		for (int i = 0; i < g.length; i++)
			g[i] = new ArrayList<>();

		g[2].add(0);
		g[2].add(1);
		g[0].add(1);
		g[1].add(0);

		List<List<Integer>> components = scc(g);
		System.out.println(components);
	}
}

class Pair<U, V> implements Comparable<Pair<U, V>> {
	public final U first;
	public final V second;

	public static <U, V> Pair<U, V> makePair(U first, V second) {
		return new Pair<U, V>(first, second);
	}

	private Pair(U first, V second) {
		this.first = first;
		this.second = second;
	}

	@Override
	public boolean equals(Object o) {
		if (this == o)
			return true;
		if (o == null || getClass() != o.getClass())
			return false;

		Pair<U, V> pair = (Pair<U, V>) o;

		return !(first != null ? !first.equals(pair.first) : pair.first != null)
				&& !(second != null ? !second.equals(pair.second)
						: pair.second != null);

	}

	@Override
	public int hashCode() {
		int result = first != null ? first.hashCode() : 0;
		result = 31 * result + (second != null ? second.hashCode() : 0);
		return result;
	}

	public Pair<V, U> swap() {
		return makePair(second, first);
	}

	@Override
	public String toString() {
		return "(" + first + "," + second + ")";
	}

	@SuppressWarnings({ "unchecked" })
	public int compareTo(Pair<U, V> o) {
		int value = ((Comparable<U>) first).compareTo(o.first);
		if (value != 0)
			return value;
		return ((Comparable<V>) second).compareTo(o.second);
	}
}