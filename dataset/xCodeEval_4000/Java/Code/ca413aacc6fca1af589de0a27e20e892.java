import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.Writer;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.TreeSet;


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
		n = in.readInt();
		int q = in.readInt();

		set = new SplayTreeSet<>();


		leftID = new HashMap<>();
		rightID = new HashMap<>();
		size = new HashMap<>();
		startIndex = new HashMap<>();
		goodSize = new HashMap<>();

		left = 0;
		length = -1;
		right = -1;

		while (q-- > 0) {
			int t = in.readInt();
			int ID = in.readInt();
			if (t == 1) {
				out.printLine(add(ID));
			} else {
				remove(ID);
			}


		}
	}

	int n;
	HashMap<Integer, Integer> leftID, rightID, size, startIndex, goodSize;


	SplayTreeSet<ComparablePair<ComparablePair<Integer, Integer>, Integer>> set;
	int left;
	int length;
	int right;

	int add(int ID) {
		if (set.size() == 0) {
			left = ID;
			startIndex.put(ID, 0);
			size.put(ID, n);
			goodSize.put(ID, -(size.get(ID) - 2));
			set.add(new ComparablePair<>(new ComparablePair<>(goodSize.get(ID),startIndex.get(ID)), ID));
		} else {
			int newID = set.first().second;

			int pos;

			int len;

			if (!rightID.containsKey(newID)) {
				pos = size.get(newID) - 1;
			} else {
				len = size.get(newID) - 1;
				pos = (len + 1) / 2;
			}

			len = -set.first().first.first;

			if (left == -1 && len <= length - 1) {
				left = ID;
				startIndex.put(ID, 0);
				size.put(ID, length);
				rightID.put(ID, right);
				leftID.put(right, ID);
				int good = (size.get(ID) - 2) / 2;
				if (size.get(ID) == 1) good = -(1 << 20);


				goodSize.put(ID, -good);
				set.add(new ComparablePair<>(new ComparablePair<>(goodSize.get(ID), startIndex.get(ID)), ID));

			} else {
				set.remove(set.first());

				if (rightID.containsKey(newID)) { 

					leftID.put(rightID.get(newID), ID);
					rightID.put(ID, rightID.get(newID));
				}
				rightID.put(newID, ID);
				leftID.put(ID, newID);



				startIndex.put(ID, startIndex.get(newID) + pos);
				size.put(ID, startIndex.get(newID) + size.get(newID) - startIndex.get(ID));
				size.put(newID, size.get(newID) - size.get(ID));

				int good = (size.get(ID) - 2) / 2;
				if (!rightID.containsKey(ID))
					good = size.get(ID) - 2;
				if (size.get(ID) == 1) good = -(1 << 20);



				goodSize.put(ID, -good);
				set.add(new ComparablePair<>(new ComparablePair<>(goodSize.get(ID), startIndex.get(ID)), ID));


				goodSize.put(newID, -((size.get(newID) - 2) / 2));
				if (size.get(newID) == 1) goodSize.put(newID, (1 << 20));
				set.add(new ComparablePair<>(new ComparablePair<>(goodSize.get(newID), startIndex.get(newID)), newID));
			}
		}

		return startIndex.get(ID) + 1;
	}

	void remove(int ID) {
		if (set.size() == 1) {
			set.clear();
			leftID.clear();
			rightID.clear();
			size.clear();
			startIndex.clear();
			goodSize.clear();
		} else {
			set.remove(new ComparablePair<>(new ComparablePair<>(goodSize.get(ID), startIndex.get(ID)), ID));




			if (leftID.containsKey(ID))
				set.remove(new ComparablePair<>(new ComparablePair<>(goodSize.get(leftID.get(ID)), startIndex.get(leftID.get(ID))), leftID.get(ID)));

			if (!leftID.containsKey(ID)) {
				if (left != -1) {
					left = -1;
					length = size.get(ID);
					right = rightID.get(ID);
				} else {
					length += size.get(ID);
					right = rightID.get(ID);
				}
				leftID.remove(rightID.get(ID));

			} else if(!rightID.containsKey(ID)) {
				rightID.remove(leftID.get(ID));
				size.put(leftID.get(ID), size.get(leftID.get(ID)) + size.get(ID));
			} else {
				leftID.put(rightID.get(ID), leftID.get(ID));
				rightID.put(leftID.get(ID), rightID.get(ID));
				size.put(leftID.get(ID), size.get(leftID.get(ID)) + size.get(ID));
			}

			if (leftID.containsKey(ID)) {
				int newID = leftID.get(ID);
				if (rightID.containsKey(newID))
					goodSize.put(newID, -((size.get(newID) - 2) / 2));
				else goodSize.put(newID, -(size.get(newID) - 2));

				if (size.get(newID) == 1) goodSize.put(newID, (1 << 20));
				set.add(new ComparablePair<>(new ComparablePair<>(goodSize.get(newID), startIndex.get(newID)), newID));
			}


			leftID.remove(ID);
			rightID.remove(ID);
			size.remove(ID);
			startIndex.remove(ID);
			goodSize.remove(ID);
		}
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

class ComparablePair<U extends Comparable<U>, V extends Comparable<V>> implements Comparable<ComparablePair<U, V>> {
	public U first;
	public V second;

	public ComparablePair(U first, V second) {
		this.first = first;
		this.second = second;
	}

	@Override
	public int compareTo(ComparablePair<U, V> o) {
		int value = first.compareTo(o.first);
		if (value != 0) return value;
		return second.compareTo(o.second);
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

		ComparablePair pair = (ComparablePair) o;

		return (first != null ? first.equals(pair.first) : pair.first == null) &&
				(second != null ? second.equals(pair.second) : pair.second == null);
	}

	@Override
	protected Object clone() throws CloneNotSupportedException {
		return new ComparablePair<U, V>(first, second);
	}

	@Override
	public String toString() {
		return "(" + first + ", " + second + ")";
	}
}

final class SplayTreeSet<V extends Comparable<V>> {
	private final class Node {
		Node left = null;
		Node right = null;
		V key;

		Node(V key) {
			this.key = key;
		}
	}

	private Node root = null;
	private Node buffer = new Node(null);
	private int size = 0;

	

	private void rotateLeft(Node x, Node p) {
		p.right = x.left;
		x.left = p;
	}

	

	private void rotateRight(Node x, Node p) {
		p.left = x.right;
		x.right = p;
	}

	private Node splay(Node x, V key) {
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

	

	private Pair<Node, Node> split(Node x, V key) {
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

	public void add(V key) {
		if (root == null) {
			root = new Node(key);
			++size;
		} else {
			root = splay(root, key);
			if (!root.key.equals(key)) {
				++size;
				Pair<Node, Node> pair = split(root, key);
				root = new Node(key);
				root.left = pair.first;
				root.right = pair.second;
			}
		}
	}

	public boolean contains(V key) {
		if (root == null) return false;
		root = splay(root, key);
		return root.key.equals(key);
	}

	public void remove(V key) {
		if (root == null) return;
		root = splay(root, key);
		if (root.key.equals(key)) {
			root = join(root.left, root.right);
			--size;
		}
	}

	public V first() {
		if (root == null) throw new RuntimeException();
		Node v = root;
		while (v.left != null) v = v.left;
		root = splay(root, v.key);
		return root.key;
	}

	public V last() {
		if (root == null) throw new RuntimeException();
		Node v = root;
		while (v.right != null) v = v.right;
		root = splay(root, v.key);
		return root.key;
	}

	public void clear() {
		root = null;
		size = 0;
	}

	


	private ArrayList<V> getKeys() {
		ArrayList<V> list = new ArrayList<V>();
		dfs(root, list);
		return list;
	}

	private void dfs(Node v, ArrayList<V> list) {
		if (v == null) return;
		dfs(v.left, list);
		list.add(v.key);
		dfs(v.right, list);
	}

	@Override
	public String toString() {
		return getKeys().toString();
	}
}

class Pair<U, V> {
	public U first;
	public V second;

	public Pair(U first, V second) {
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
		return new Pair<U, V>(first, second);
	}

	@Override
	public String toString() {
		return "(" + first + ", " + second + ")";
	}
}