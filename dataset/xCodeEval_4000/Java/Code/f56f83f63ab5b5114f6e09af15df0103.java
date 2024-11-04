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
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.Random;


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
		int q = in.readInt();

		size = 1;
		while (size < n) size *= 2;
		tree = new int[size * 2];

		int[] mas = new int[n];
		for (int i = 0; i < n; ++i)
			mas[i] = in.readInt();

		int[] closest = new int[n];
		int[] nth = new int[n];
		for (int i = 0; i < n; ++i)
			closest[i] = nth[i] = n;

		HashMap<Integer, Integer> last = new HashMap<>();
		for (int i = 0; i < n; ++i) {
			if (last.containsKey(mas[i]))
				closest[last.get(mas[i])] = i;
			last.put(mas[i], i);
		}

		last.clear();

		HashSet<Integer> was = new HashSet<>();

		for (int i = 0; i < n; ++i)
			if (!was.contains(mas[i])) {
				was.add(mas[i]);
				last.put(mas[i], i);
				int id = i;
				int value = 1;
				while (id < n && value < mas[i]) {
					++value;
					id = closest[id];
				}

				if (id < n && value == mas[i]) {
					nth[i] = id;
					update(id, 1);
					if (closest[id] < n)
						update(closest[id], -1);
				}
			} else if (nth[last.get(mas[i])] < n) {
				int id = closest[nth[last.get(mas[i])]];
				if (id < n) nth[i] = id;
				last.put(mas[i], i);
			}





		



		int[] ans = new int[q];

		ArrayList<ComparablePair<ComparablePair<Integer, Integer>, Integer>> qq = new ArrayList<>();

		for (int i = 0; i < q; ++i)
			qq.add(new ComparablePair<>(new ComparablePair<>(in.readInt() - 1, in.readInt() - 1), i));

		Collections.shuffle(qq);
		Collections.sort(qq);

		int id = 0;
		for (int i = 0; i < q; ++i) {
			while (id < qq.get(i).first.first) {
				if (nth[id] < n) {
					if (sum(nth[id], nth[id]) != 1) throw new RuntimeException();
					update(nth[id], 0);
					if (closest[nth[id]] < n) {
						if (sum(closest[nth[id]], closest[nth[id]]) != -1) throw new RuntimeException();
						update(closest[nth[id]], 1);
						if (closest[closest[nth[id]]] < n) {
							if (sum(closest[closest[nth[id]]], closest[closest[nth[id]]]) != 0) throw new RuntimeException();
							update(closest[closest[nth[id]]], -1);
						}
					}
				}
				++id;
			}
			ans[qq.get(i).second] = sum(qq.get(i).first.first, qq.get(i).first.second);
		}

		for (int x : ans)
			out.printLine(x);
		

	}

	int[] tree;
	int size;

	void update(int v, int value) {
		v += size;
		tree[v] = value;
		v /= 2;
		while (v > 0) {
			tree[v] = tree[v * 2] + tree[v * 2 + 1];
			v /= 2;
		}
	}

	int sum(int left, int right) {
		left += size;
		right += size;

		int res = 0;
		for (; left <= right; left /= 2, right /= 2) {
			if ((left & 1) == 1) res += tree[left];
			if ((right & 1) == 0) res += tree[right];
			++left;
			--right;
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


class ComparablePair<F extends Comparable<F>, S extends Comparable<S>> implements Comparable<ComparablePair<F, S>> {
	public F first;
	public S second;

	public ComparablePair(F first, S second) {
		this.first = first;
		this.second = second;
	}

	@Override
	public int compareTo(ComparablePair<F, S> o) {
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
		return new ComparablePair<F, S>(first, second);
	}

	@Override
	public String toString() {
		return "(" + first + ", " + second + ")";
	}
}