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
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.InputMismatchException;
import java.util.List;
import java.util.NoSuchElementException;
import java.util.RandomAccess;


public class Main implements Runnable {
	private static String[] args;

	public static void main(String[] args) {
		Main.args = args;
		new Thread(null, new Main(), "MyRunThread", 1 << 26).start();
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
			s.debug = new DebugWriter(s.out);
		}

		s.solve();
		s.out.close();

		if (args.length > 0 && args[0].equals("outside")) {
			s.debug.close();
			System.err.printf("*** Total time: %.3f ***\n", (System.currentTimeMillis() - time_beg) / 1000.0);
		}
	}
}

final class Solver {
	InputReader in;
	OutputWriter out;
	DebugWriter debug;

	public void solve() {
		int n = in.readInt();
		int x = in.readInt();
		m1 = new int[n];
		for (int i = 0; i < n; ++i)
			m1[i] = in.readInt();
		m2 = new int[n];
		for (int i = 0; i < n; ++i)
			m2[i] = in.readInt();
		Collections.shuffle(ArrayWrapper.wrap(m2));
		Arrays.sort(m2);
		int b1 = -1;
		int b2 = -1;
		for (int i = 0; i < n; ++i) {
			int v = bs(x - m1[i]);
			if (v != -1 && (b1 == -1 || m1[i] + m2[v] < m1[b1] + m2[b2])) {
				b1 = i;
				b2 = v;
			}
		}

		x = m1[b1] + m2[b2];
		SplayTreeMap<Integer, Integer> q = new SplayTreeMap<>();
		for (int i = 0; i < n; ++i)
			if (i != b2) {
				if (!q.contains(m2[i]))
					q.put(m2[i], 1);
				else q.put(m2[i], q.get(m2[i]) + 1);
			}
		int res = 1;
		for (int i = 0; i < n; ++i)
			if (i != b1) {
				Integer z = q.lowerBound(x - m1[i]);
				if (z == null) z = q.first();
				else ++res;
				q.put(z, q.get(z) - 1);

				if (q.get(z) == 0) q.remove(z);
			}
		out.printLine(1 + " " + res);
	}

	int[] m1;
	int[] m2;

	int bs(int x) {
		int lo = 0;
		int hi = m2.length - 1;
		while (lo < hi) {
			int m = lo + (hi - lo) / 2;
			if (m2[m] >= x) hi = m;
			else lo = m + 1;
		}
		if (m2[lo] >= x) return lo;
		return -1;
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

	private void printDebugMessage() {
		writer.print("debug:\t");
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

	public void close() {
		writer.close();
	}
}

abstract class ArrayWrapper<T> extends AbstractList<T> implements RandomAccess {
	public static <T> List<T> wrap(T... array) {
		return new ReferenceArrayWrapper<T>(array);
	}

	public static List<Integer> wrap(int... array) {
		return new IntArrayWrapper(array);
	}

	public static List<Long> wrap(long... array) {
		return new LongArrayWrapper(array);
	}

	public static List<Character> wrap(char... array) {
		return new CharArrayWrapper(array);
	}

	public static List<Double> wrap(double... array) {
		return new DoubleArrayWrapper(array);
	}

	public static List<Boolean> wrap(boolean... array) {
		return new BooleanArrayWrapper(array);
	}

	public static List<Short> wrap(short... array) {
		return new ShortArrayWrapper(array);
	}

	public static List<Byte> wrap(byte... array) {
		return new ByteArrayWrapper(array);
	}

	public static List<Character> wrap(CharSequence sequence) {
		return new CharSequenceWrapper(sequence);
	}

	protected static class ReferenceArrayWrapper<T> extends ArrayWrapper<T> {
		protected final T[] array;

		protected ReferenceArrayWrapper(T[] array) {
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

	protected static class IntArrayWrapper extends ArrayWrapper<Integer> {
		protected final int[] array;

		protected IntArrayWrapper(int[] array) {
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

	protected static class LongArrayWrapper extends ArrayWrapper<Long> {
		protected final long[] array;

		protected LongArrayWrapper(long[] array) {
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

	protected static class CharArrayWrapper extends ArrayWrapper<Character> {
		protected final char[] array;

		protected CharArrayWrapper(char[] array) {
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

	protected static class DoubleArrayWrapper extends ArrayWrapper<Double> {
		protected final double[] array;

		protected DoubleArrayWrapper(double[] array) {
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

	protected static class BooleanArrayWrapper extends ArrayWrapper<Boolean> {
		protected final boolean[] array;

		protected BooleanArrayWrapper(boolean[] array) {
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

	protected static class ShortArrayWrapper extends ArrayWrapper<Short> {
		protected final short[] array;

		protected ShortArrayWrapper(short[] array) {
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

	protected static class ByteArrayWrapper extends ArrayWrapper<Byte> {
		protected final byte[] array;

		protected ByteArrayWrapper(byte[] array) {
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

	protected static class CharSequenceWrapper extends ArrayWrapper<Character> {
		protected final CharSequence sequence;

		protected CharSequenceWrapper(CharSequence sequence) {
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

class SplayTreeMap<K extends Comparable<K>, V> {
	private class Node {
		Node left = null;
		Node right = null;
		K key;
		V value;

		Node(K key, V value) {
			this.key = key;
			this.value = value;
		}
	}

	private Node root = null;
	private Node buffer = new Node(null, null);
	private int size = 0;

	

	private void rotateLeft(Node x, Node p) {
		p.right = x.left;
		x.left = p;
	}

	

	private void rotateRight(Node x, Node p) {
		p.left = x.right;
		x.right = p;
	}

	private Node splay(Node x, K key) {
		if (x == null) return null;
		Node left = buffer;
		Node right = buffer;

		while (true) {
			if (key.compareTo(x.key) < 0) {
				Node y = x.left;
				if (y == null) break;
				if (key.compareTo(y.key) < 0) { 

					rotateRight(y, x);
					x = y;
					if (x.left == null) break;
				}
				

				right.left = x;
				right = x;
				

				x = x.left;
			} else if (key.compareTo(x.key) > 0) {
				Node y = x.right;
				if (y == null) break;
				if (key.compareTo(y.key) > 0) { 

					rotateLeft(y, x);
					x = y;
					if (x.right == null) break;
				}
				

				left.right = x;
				left = x;
				

				x = x.right;
			} else break;
		}

		left.right = x.left;
		right.left = x.right;
		x.left = buffer.right;
		x.right = buffer.left;
		return x;
	}

	private Node join(Node left, Node right) {
		if (left == null) return right;
		if (right == null) return left;
		left = splay(left, right.key);
		left.right = right;
		return left;
	}

	

	private Pair<Node, Node> split(Node x, K key) {
		if (x == null) throw new RuntimeException();
		x = splay(x, key);
		if (x.key.compareTo(key) <= 0) { 

			Node right = x.right;
			x.right = null;
			return new Pair<Node, Node>(x, right);
		} else { 

			Node left = x.left;
			x.left = null;
			return new Pair<Node, Node>(left, x);
		}
	}

	


	public int size() {
		return size;
	}

	public void put(K key, V value) {
		if (key == null) throw new IllegalArgumentException();
		if (root == null) {
			root = new Node(key, value);
			++size;
		} else {
			root = splay(root, key);
			if (root.key.equals(key)) {
				root.value = value;
			} else {
				++size;
				Pair<Node, Node> pair = split(root, key);
				root = new Node(key, value);
				root.left = pair.first;
				root.right = pair.second;
			}
		}
	}

	public V get(K key) {
		if (key == null) throw new IllegalArgumentException();
		if (root == null) throw new NoSuchElementException();
		root = splay(root, key);
		if (root.key.equals(key))
			return root.value;
		else throw new NoSuchElementException();
	}

	public boolean contains(K key) {
		if (key == null) throw new IllegalArgumentException();
		if (root == null) return false;
		root = splay(root, key);
		return root.key.equals(key);
	}

	public void remove(K key) {
		if (key == null) throw new IllegalArgumentException();
		if (root == null) return;
		root = splay(root, key);
		if (root.key.equals(key)) {
			root = join(root.left, root.right);
			--size;
		}
	}

	public K first() {
		if (root == null) return null;
		Node v = root;
		while (v.left != null) v = v.left;
		root = splay(root, v.key);
		return root.key;
	}

	public K last() {
		if (root == null) return null;
		Node v = root;
		while (v.right != null) v = v.right;
		root = splay(root, v.key);
		return root.key;
	}

	

	public K lowerBound(K key) {
		if (key == null) throw new IllegalArgumentException();
		Pair<Node, Node> pair = split(root, key);
		K res = null;

		if (pair.first != null && key.equals(pair.first.key)) res = key;
		else if (pair.second != null) {
			pair.second = splay(pair.second, key);
			res = pair.second.key;
		}

		root = join(pair.first, pair.second);
		return res;
	}

	

	public K upperBound(K key) {
		if (key == null) throw new IllegalArgumentException();
		Pair<Node, Node> pair = split(root, key);
		K res = null;

		if (pair.second != null) {
			pair.second = splay(pair.second, key);
			res = pair.second.key;
		}

		root = join(pair.first, pair.second);
		return res;
	}

	public void clear() {
		root = null;
		size = 0;
	}

	


	public ArrayList<Pair<K, V>> getEntries() {
		ArrayList<Pair<K, V>> list = new ArrayList<Pair<K, V>>();
		dfs(root, list);
		return list;
	}

	private void dfs(Node v, ArrayList<Pair<K, V>> list) {
		if (v == null) return;
		dfs(v.left, list);
		list.add(new Pair<K, V>(v.key, v.value));
		dfs(v.right, list);
	}

	@Override
	public String toString() {
		return getEntries().toString();
	}
}

class Pair<F, S> {
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
