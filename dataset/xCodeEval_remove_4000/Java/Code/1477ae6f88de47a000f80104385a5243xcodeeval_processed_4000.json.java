import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.NoSuchElementException;
import java.io.Writer;
import java.math.BigInteger;
import java.io.InputStream;


public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int N = in.readInt();
        char[][] grid = IOUtils.readTable(in, N, N);

        boolean[] badCol = new boolean[N];
        boolean[] badRow = new boolean[N];

        ArrayList<String> ans = new ArrayList<String>();
        boolean[] done = new boolean[N];
        for (int i = 0; i < N; i++) {
            int count = 0;
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 'E')
                    count++;
                else {
                    if (done[j])
                        continue;
                    if (grid[i][j] == '.') {
                        ans.add((i + 1) + " " + (j + 1));
                        done[j] = true;
                    }
                }
            }
            if (count == N) {
                badRow[i] = true;
            }
        }

        if (ans.size() != N) {
            ans.clear();
            done = new boolean[N];
        }
        for (int j = 0; j < N; j++) {
            int count = 0;
            for (int i = 0; i < N; i++) {
                if (grid[i][j] == 'E')
                    count++;
                else {
                    if (done[i])
                        continue;
                    if (grid[i][j] == '.') {
                        ans.add((i + 1) + " " + (j + 1));
                        done[i] = true;
                    }
                }
            }
            if (count == N) {
                badCol[j] = true;
            }
        }

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (badCol[i] && badRow[j]) {
                    out.println(-1);
                    return;
                }

        for (String a : ans)
            out.println(a);
    }
}

class InputReader {
	private boolean finished = false;

	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;
	private id22 filter;

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
		while (id8(c))
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
		} while (!id8(c));
		return res * sgn;
	}

	public long readLong() {
		int c = read();
		while (id8(c))
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
		} while (!id8(c));
		return res * sgn;
	}

	public String readString() {
		int c = read();
		while (id8(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do {
			res.appendCodePoint(c);
			c = read();
		} while (!id8(c));
		return res.toString();
	}

	public boolean id8(int c) {
		if (filter != null)
			return filter.id8(c);
		return isWhitespace(c);
	}

	public static boolean isWhitespace(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	private String id5() {
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
		String s = id5();
		while (s.trim().length() == 0)
			s = id5();
		return s;
	}

	public String readLine(boolean id20) {
		if (id20)
			return readLine();
		else
			return id5();
	}

	public BigInteger id15() {
		try {
			return new BigInteger(readString());
		} catch (NumberFormatException e) {
			throw new InputMismatchException();
		}
	}

	public char readCharacter() {
		int c = read();
		while (id8(c))
			c = read();
		return (char) c;
	}

	public double readDouble() {
		int c = read();
		while (id8(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		double res = 0;
		while (!id8(c) && c != '.') {
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
			while (!id8(c)) {
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

	public boolean id7() {
		int value;
		while (id8(value = peek()) && value != -1)
			read();
		return value == -1;
	}

	public String next() {
		return readString();
	}

	public id22 getFilter() {
		return filter;
	}

	public void setFilter(id22 filter) {
		this.filter = filter;
	}

	public interface id22 {
		public boolean id8(int ch);
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

	public void print(Object...objects) {
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

    public void print(IntCollection collection) {
		boolean first = true;
		for (IntIterator iterator = collection.iterator(); iterator.isValid(); iterator.advance()) {
			if (first)
				first = false;
			else
				writer.print(' ');
			writer.print(iterator.value());
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

    public void printLine(IntCollection collection) {
		print(collection);
		writer.println();
	}

	public void printLine() {
		writer.println();
	}

    public void println(Object... objects) {
        printLine(objects);
    }

    public void printLine(Object...objects) {
		print(objects);
		writer.println();
	}

	public void print(char i) {
		writer.print(i);
	}

	public void printLine(char[] array) {
		writer.println(array);
	}

	public void printFormat(String format, Object...objects) {
		writer.printf(format, objects);
	}

	public void close() {
		writer.close();
	}

	public void flush() {
		writer.flush();
	}
}

class IOUtils {
	public static Pair<Integer, Integer> id10(InputReader in) {
		int first = in.readInt();
		int second = in.readInt();
		return Pair.makePair(first, second);
	}

	public static Pair<Long, Long> id13(InputReader in) {
		long first = in.readLong();
		long second = in.readLong();
		return Pair.makePair(first, second);
	}

	public static int[] id2(InputReader in, int size) {
		int[] array = new int[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readInt();
		return array;
	}

	public static long[] id11(InputReader in, int size) {
		long[] array = new long[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readLong();
		return array;
	}

	public static double[] id4(InputReader in, int size) {
		double[] array = new double[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readDouble();
		return array;
	}

	public static String[] id21(InputReader in, int size) {
		String[] array = new String[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readString();
		return array;
	}

	public static char[] id6(InputReader in, int size) {
		char[] array = new char[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readCharacter();
		return array;
	}

	public static Pair<Integer, Integer>[] id12(InputReader in, int size) {
		@SuppressWarnings({"unchecked"})
		Pair<Integer, Integer>[] result = new Pair[size];
		for (int i = 0; i < size; i++)
			result[i] = id10(in);
		return result;
	}

	public static Pair<Long, Long>[] id0(InputReader in, int size) {
		@SuppressWarnings({"unchecked"})
		Pair<Long, Long>[] result = new Pair[size];
		for (int i = 0; i < size; i++)
			result[i] = id13(in);
		return result;
	}

	public static void id14(InputReader in, int[]... arrays) {
		for (int i = 0; i < arrays[0].length; i++) {
			for (int j = 0; j < arrays.length; j++)
				arrays[j][i] = in.readInt();
		}
	}

	public static void id16(InputReader in, long[]... arrays) {
		for (int i = 0; i < arrays[0].length; i++) {
			for (int j = 0; j < arrays.length; j++)
				arrays[j][i] = in.readLong();
		}
	}

	public static void id18(InputReader in, double[]...arrays) {
		for (int i = 0; i < arrays[0].length; i++) {
			for (int j = 0; j < arrays.length; j++)
				arrays[j][i] = in.readDouble();
		}
	}

	public static char[][] readTable(InputReader in, int rowCount, int columnCount) {
		char[][] table = new char[rowCount][];
		for (int i = 0; i < rowCount; i++)
			table[i] = id6(in, columnCount);
		return table;
	}

	public static int[][] id9(InputReader in, int rowCount, int columnCount) {
		int[][] table = new int[rowCount][];
		for (int i = 0; i < rowCount; i++)
			table[i] = id2(in, columnCount);
		return table;
	}

	public static double[][] id1(InputReader in, int rowCount, int columnCount) {
		double[][] table = new double[rowCount][];
		for (int i = 0; i < rowCount; i++)
			table[i] = id4(in, columnCount);
		return table;
	}

	public static long[][] id3(InputReader in, int rowCount, int columnCount) {
		long[][] table = new long[rowCount][];
		for (int i = 0; i < rowCount; i++)
			table[i] = id11(in, columnCount);
		return table;
	}

	public static String[][] id19(InputReader in, int rowCount, int columnCount) {
		String[][] table = new String[rowCount][];
		for (int i = 0; i < rowCount; i++)
			table[i] = id21(in, columnCount);
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

	public static void id17(InputReader in, String[]... arrays) {
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

abstract class IntCollection {
	public abstract IntIterator iterator();
	public abstract int size();
	public abstract void add(int value);
	public abstract void remove(int value);

	public void forEach(IntTask task) {
		for (IntIterator iterator = iterator(); iterator.isValid(); iterator.advance())
			task.process(iterator.value());
	}

	public boolean contains(int value) {
		for (IntIterator iterator = iterator(); iterator.isValid(); iterator.advance()) {
			if (iterator.value() == value)
				return true;
		}
		return false;
	}

	public int count(int value) {
		int result = 0;
		for (IntIterator iterator = iterator(); iterator.isValid(); iterator.advance()) {
			if (iterator.value() == value)
				result++;
		}
		return result;
	}

	public int min() {
		if (size() == 0)
			throw new NoSuchElementException();
		int result = Integer.MAX_VALUE;
		for (IntIterator iterator = iterator(); iterator.isValid(); iterator.advance())
			result = Math.min(result, iterator.value());
		return result;
	}

	public int max() {
		if (size() == 0)
			throw new NoSuchElementException();
		int result = Integer.MIN_VALUE;
		for (IntIterator iterator = iterator(); iterator.isValid(); iterator.advance())
			result = Math.max(result, iterator.value());
		return result;
	}

	public IntCollection union(final IntCollection other) {
		return new IntCollection() {
			@Override
			public IntIterator iterator() {
				return new IntIterator() {
					private IntIterator first = IntCollection.this.iterator();
					private IntIterator second;

					public int value() throws NoSuchElementException {
						if (first.isValid())
							return first.value();
						return second.value();
					}

					public void advance() throws NoSuchElementException {
						if (first.isValid()) {
							first.advance();
							if (!first.isValid())
								second = other.iterator();
						} else
							second.advance();
					}

					public boolean isValid() {
						return first.isValid() || second.isValid();
					}
				};
			}

			@Override
			public int size() {
				return IntCollection.this.size() + other.size();
			}

			@Override
			public void add(int value) {
				throw new UnsupportedOperationException();
			}

			@Override
			public void remove(int value) {
				throw new UnsupportedOperationException();
			}
		};
	}

	public IntCollection map(final IntFunction function) {
		return new IntCollection() {
			@Override
			public IntIterator iterator() {
				return new IntIterator() {
					private IntIterator iterator = IntCollection.this.iterator();

					public int value() throws NoSuchElementException {
						return function.value(iterator.value());
					}

					public void advance() throws NoSuchElementException {
						iterator().advance();
					}

					public boolean isValid() {
						return iterator().isValid();
					}
				};
			}

			@Override
			public int size() {
				return IntCollection.this.size();
			}

			@Override
			public void add(int value) {
				throw new UnsupportedOperationException();
			}

			@Override
			public void remove(int value) {
				throw new UnsupportedOperationException();
			}
		};
	}

	public int[] toArray() {
		int size = size();
		int[] array = new int[size];
		int i = 0;
		for (IntIterator iterator = iterator(); iterator.isValid(); iterator.advance())
			array[i++] = iterator.value();
		return array;
	}

	public long sum() {
		long result = 0;
		for (IntIterator iterator = iterator(); iterator.isValid(); iterator.advance())
			result += iterator.value();
		return result;
	}

	public void addAll(IntCollection values) {
		for (IntIterator it = values.iterator(); it.isValid(); it.advance()) {
			add(it.value());
		}
	}

	public void removeAll(IntCollection values) {
		for (IntIterator it = values.iterator(); it.isValid(); it.advance()) {
			remove(it.value());
		}
	}

	public void retainAll(IntCollection values) {
		for (IntIterator it = iterator(); it.isValid(); it.advance()) {
			if (!values.contains(it.value())) {
				remove(it.value());
			}
		}
	}
}

interface IntIterator {
	public int value() throws NoSuchElementException;
	
	public void advance() throws NoSuchElementException;
	public boolean isValid();
}

class Pair<U, V> implements Comparable<Pair<U, V>> {
	public final U first;
	public final V second;

	public static<U, V> Pair<U, V> makePair(U first, V second) {
		return new Pair<U, V>(first, second);
	}

	private Pair(U first, V second) {
		this.first = first;
		this.second = second;
	}

	@Override
	public boolean equals(Object o) {
		if (this == o) return true;
		if (o == null || getClass() != o.getClass()) return false;

		Pair pair = (Pair) o;

		return !(first != null ? !first.equals(pair.first) : pair.first != null) && !(second != null ? !second.equals(pair.second) : pair.second != null);

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

	@SuppressWarnings({"unchecked"})
	public int compareTo(Pair<U, V> o) {
		int value = ((Comparable<U>)first).compareTo(o.first);
		if (value != 0)
			return value;
		return ((Comparable<V>)second).compareTo(o.second);
	}
}

interface IntTask {
	public void process(int value);
}

interface IntFunction {
	public int value(int key);
}
