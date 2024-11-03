import java.util.NavigableSet;
import java.util.Map;
import java.util.Collections;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.math.BigInteger;
import java.util.*;
import java.util.Collection;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.List;
import java.util.Comparator;
import java.io.*;
import java.util.Iterator;
import java.util.Arrays;
import java.util.NoSuchElementException;
import java.util.Queue;


public class Main {
	public static void main(String[] args) {
		InputReader in = new StreamInputReader(System.in);
		PrintWriter out = new PrintWriter(System.out);
		run(in, out);
	}

	public static void run(InputReader in, PrintWriter out) {
		Solver solver = new TaskD();
		solver.solve(1, in, out);
		Exit.exit(in, out);
	}
}

abstract class InputReader {
	private boolean finished = false;

	public abstract int read();

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
		StringBuffer res = new StringBuffer();
		do {
			res.appendCodePoint(c);
			c = read();
		} while (!isSpaceChar(c));
		return res.toString();
	}

	private boolean isSpaceChar(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	private String readLine0() {
		StringBuffer buf = new StringBuffer();
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

	public boolean isFinished() {
		return finished;
	}

	public void setFinished(boolean finished) {
		this.finished = finished;
	}

	public abstract void close();
}

class StreamInputReader extends InputReader {
	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar, numChars;

	public StreamInputReader(InputStream stream) {
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

	@Override
	public void close() {
		try {
			stream.close();
		} catch (IOException ignored) {
		}
	}
}

class Exit {
	private Exit() {
	}

	public static void exit(InputReader in, PrintWriter out) {
		in.setFinished(true);
		in.close();
		out.close();
	}
}

interface Solver {
	public void solve(int testNumber, InputReader in, PrintWriter out);
}

class ArrayUtils {
	public static Integer[] generateOrder(int size) {
		Integer[] order = new Integer[size];
		for (int i = 0; i < size; i++)
			order[i] = i;
		return order;
	}

	public static void fill(long[][] array, long value) {
		for (long[] row : array)
			Arrays.fill(row, value);
	}

	public static void fillColumn(long[][] array, int index, long value) {
		for (long[] row : array)
			row[index] = value;
	}

	public static void fillColumn(int[][] array, int index, int value) {
		for (int[] row : array)
			row[index] = value;
	}

	public static void fill(int[][] array, int value) {
		for (int[] row : array)
			Arrays.fill(row, value);
	}

	public static void fill(boolean[][] array, boolean value) {
		for (boolean[] row : array)
			Arrays.fill(row, value);
	}

	public static long sumArray(int[] array) {
		long result = 0;
		for (int element : array)
			result += element;
		return result;
	}

	public static int[] range(int from, int to) {
		int[] result = new int[Math.max(from, to) - Math.min(from, to) + 1];
		int index = 0;
		if (to > from) {
			for (int i = from; i <= to; i++)
				result[index++] = i;
		} else {
			for (int i = from; i >= to; i--)
				result[index++] = i;
		}
		return result;
	}

	public static void fill(int[][][] array, int value) {
		for (int[][] subArray : array)
			fill(subArray, value);
	}

	public static Integer[] order(int size, Comparator<Integer> comparator) {
		Integer[] order = generateOrder(size);
		Arrays.sort(order, comparator);
		return order;
	}
}

interface Filter<T> {
	public boolean accept(T value);
}

interface Function<A, V> {
	public abstract V value(A argument);
}

class CollectionUtils {
	public static int[] toArray(Collection<Integer> collection) {
		int[] array = new int[collection.size()];
		int index = 0;
		for (int element : collection)
			array[index++] = element;
		return array;
	}

	public static List<Integer> range(int from, int to) {
		List<Integer> result = new ArrayList<Integer>(Math.max(from, to) - Math.min(from, to) + 1);
		if (to > from) {
			for (int i = from; i <= to; i++)
				result.add(i);
		} else {
			for (int i = from; i >= to; i--)
				result.add(i);
		}
		return result;
	}

	public static void rotate(List<Integer> list) {
		list.add(list.remove(0));
	}

	public static<T extends Comparable<T>> T minElement(Iterable<T> collection) {
		T result = null;
		for (T element : collection) {
			if (result == null || result.compareTo(element) > 0)
				result = element;
		}
		return result;
	}

	public static<T extends Comparable<T>> T maxElement(Iterable<T> collection) {
		T result = null;
		for (T element : collection) {
			if (result == null || result.compareTo(element) < 0)
				result = element;
		}
		return result;
	}

	public static<T> T minElement(Iterable<T> collection, Comparator<T> comparator) {
		T result = null;
		for (T element : collection) {
			if (result == null || comparator.compare(result, element) > 0)
				result = element;
		}
		return result;
	}

	public static<T> T maxElement(Iterable<T> collection, Comparator<T> comparator) {
		T result = null;
		for (T element : collection) {
			if (result == null || comparator.compare(result, element) < 0)
				result = element;
		}
		return result;
	}

	public static<T> List<T> asList(Iterable<T> iterable) {
		List<T> list = new ArrayList<T>();
		for (T element : iterable)
			list.add(element);
		return list;
	}

	public static<T> int count(Iterable<T> array, T sample) {
		int result = 0;
		for (T element : array) {
			if (element.equals(sample))
				result++;
		}
		return result;
	}

	public static<T> int count(Iterable<T> array, Filter<T> filter) {
		int result = 0;
		for (T element : array) {
			if (filter.accept(element))
				result++;
		}
		return result;
	}

	public static<T> List<T> filter(Iterable<T> sequence, Filter<T> filter) {
		List<T> result = new ArrayList<T>();
		for (T element : sequence) {
			if (filter.accept(element))
				result.add(element);
		}
		return result;
	}

	public static<A, V> List<V> apply(Iterable<A> sequence, Function<A, V> function) {
		List<V> result = new ArrayList<V>();
		for (A element : sequence)
			result.add(function.value(element));
		return result;
	}
}

class Pair<U, V> {
	public static class Comparator<U extends Comparable<U>, V extends Comparable<V>> implements java.util.Comparator<Pair<U, V>> {
		public int compare(Pair<U, V> o1, Pair<U, V> o2) {
			int result = o1.first.compareTo(o2.first);
			if (result != 0)
				return result;
			return o1.second.compareTo(o2.second);
		}
	}

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
}

abstract class ReadOnlyIterator<T> implements Iterator<T>  {
	public final void remove() {
		throw new UnsupportedOperationException();
	}
}

class IOUtils {
	public static void printArray(int[] array, PrintWriter out) {
		if (array.length == 0) {
			out.println();
			return;
		}
		out.print(array[0]);
		for (int i = 1; i < array.length; i++)
			out.print(" " + array[i]);
		out.println();
	}

	public static<T> void printCollection(Iterable<T> collection, PrintWriter out) {
		printCollection(collection, out, " ");
	}

	public static<T> void printCollection(Iterable<T> collection, PrintWriter out, String delimiter) {
		boolean isFirst = true;
		for (T element : collection) {
			if (isFirst)
				isFirst = false;
			else
				out.print(delimiter);
			out.print(element);
		}
		out.println();
	}

	public static Pair<Integer, Integer> readIntPair(InputReader in) {
		int first = in.readInt();
		int second = in.readInt();
		return Pair.makePair(first, second);
	}

	public static Pair<Long, Long> readLongPair(InputReader in) {
		long first = in.readLong();
		long second = in.readLong();
		return Pair.makePair(first, second);
	}

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

	public static Pair<Integer, Integer>[] readIntPairArray(InputReader in, int size) {
		@SuppressWarnings({"unchecked"})
		Pair<Integer, Integer>[] result = new Pair[size];
		for (int i = 0; i < size; i++)
			result[i] = readIntPair(in);
		return result;
	}

	public static Pair<Long, Long>[] readLongPairArray(InputReader in, int size) {
		@SuppressWarnings({"unchecked"})
		Pair<Long, Long>[] result = new Pair[size];
		for (int i = 0; i < size; i++)
			result[i] = readLongPair(in);
		return result;
	}

	public static void readIntArrays(InputReader in, int[]... arrays) {
		for (int i = 0; i < arrays[0].length; i++) {
			for (int j = 0; j < arrays.length; j++)
				arrays[j][i] = in.readInt();
		}
	}

	public static void readDoubleArrays(InputReader in, double[]...arrays) {
		for (int i = 0; i < arrays[0].length; i++) {
			for (int j = 0; j < arrays.length; j++)
				arrays[j][i] = in.readDouble();
		}
	}

	public static char[][] readTable(InputReader in, int rowCount, int columnCount) {
		char[][] table = new char[rowCount][];
		for (int i = 0; i < rowCount; i++)
			table[i] = readCharArray(in, columnCount);
		return table;
	}

	public static int[][] readIntTable(InputReader in, int rowCount, int columnCount) {
		int[][] table = new int[rowCount][];
		for (int i = 0; i < rowCount; i++)
			table[i] = readIntArray(in, columnCount);
		return table;
	}

	public static long[][] readLongTable(InputReader in, int rowCount, int columnCount) {
		long[][] table = new long[rowCount][];
		for (int i = 0; i < rowCount; i++)
			table[i] = readLongArray(in, columnCount);
		return table;
	}

	public static String[][] readStringTable(InputReader in, int rowCount, int columnCount) {
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

}

abstract class AbstractSequence<T> implements Sequence<T> {
	public Sequence<T> subSequence(int from) {
		return subSequence(from, size());
	}

	public Sequence<T> subSequence(int from, int to) {
		int size = size();
		if (from < 0)
			from += size;
		if (to < 0)
			to += size;
		checkIndices(from, to, size);
		return new SubSequence(from, to);
	}

	public boolean isEmpty() {
		return size() == 0;
	}

	protected void checkIndices(int from, int to, int size) {
		if (from < 0 || to < 0 || from >= size || to >= size || from > to)
			throw new IndexOutOfBoundsException();
	}

	public Iterator<T> iterator() {
		return new ReadOnlyIterator<T>() {
			private int index = 0;

			public boolean hasNext() {
				return index != size();
			}

			public T next() {
				if (!hasNext())
					throw new NoSuchElementException();
				return get(index++);
			}
		};
	}

	@Override
	public String toString() {
		StringWriter writer = new StringWriter();
		IOUtils.printCollection(this, new PrintWriter(writer), ",");
		return "[" + writer.toString().substring(0, writer.toString().length() - 1) + "]";
	}

	protected class SubSequence implements Sequence<T> {
		protected final int from;
		protected final int to;

		public SubSequence(int from, int to) {
			this.from = from;
			this.to = to;
		}

		public Sequence<T> subSequence(int from) {
			return subSequence(from, to);
		}

		public Sequence<T> subSequence(int from, int to) {
			int size = size();
			if (from < 0)
				from += size;
			if (to < 0)
				to += size;
			checkIndices(from, to, size);
			return new SubSequence(from + this.from, to + this.from);
		}

		public int size() {
			return to - from;
		}

		public boolean isEmpty() {
			return size() == 0;
		}

		public T get(int index) {
			if (index < 0 || index >= size())
				throw new IndexOutOfBoundsException();
			return AbstractSequence.this.get(from + index);
		}

		public Iterator<T> iterator() {
			return new ReadOnlyIterator<T>() {
				private int index = from;

				public boolean hasNext() {
					return index != to;
				}

				public T next() {
					if (index == to)
						throw new NoSuchElementException();
					return AbstractSequence.this.get(index++);
				}
			};
		}
	}
}

abstract class AbstractWritableSequence<T> extends AbstractSequence<T> implements WritableSequence<T> {
	@Override
	public WritableSequence<T> subSequence(int from) {
		return subSequence(from, size());
	}

	@Override
	public WritableSequence<T> subSequence(int from, int to) {
		int size = size();
		if (from < 0)
			from += size;
		if (to < 0)
			to += size;
		checkIndices(from, to, size);
		return new WritableSubSequence(from, to);
	}

	protected class WritableSubSequence extends SubSequence implements WritableSequence<T>{
		public WritableSubSequence(int from, int to) {
			super(from, to);
		}

		public void set(int index, T value) {
			if (index < 0 || index >= size())
				throw new IndexOutOfBoundsException();
			AbstractWritableSequence.this.set(from + index, value);
		}

		public WritableSequence<T> subSequence(int from) {
			return subSequence(from, to);
		}

		public WritableSequence<T> subSequence(int from, int to) {
			int size = size();
			if (from < 0)
				from += size;
			if (to < 0)
				to += size;
			checkIndices(from, to, size);
			return new WritableSubSequence(from + this.from, to + this.from);
		}
	}
}

abstract class ArrayWrapper<T> extends AbstractWritableSequence<T> {
	public static<T> ArrayWrapper<T> wrap(T...array) {
		return new ReferenceArrayWrapper<T>(array);
	}

	public static WritableSequence<Integer> wrap(int...array) {
		return new IntArrayWrapper(array);
	}

	public static WritableSequence<Long> wrap(long...array) {
		return new LongArrayWrapper(array);
	}

	public static WritableSequence<Character> wrap(char...array) {
		return new CharArrayWrapper(array);
	}

	public static WritableSequence<Double> wrap(double...array) {
		return new DoubleArrayWrapper(array);
	}

	public static WritableSequence<Boolean> wrap(boolean...array) {
		return new BooleanArrayWrapper(array);
	}

	public static WritableSequence<Short> wrap(short...array) {
		return new ShortArrayWrapper(array);
	}

	public static WritableSequence<Byte> wrap(byte...array) {
		return new ByteArrayWrapper(array);
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

		public void set(int index, T value) {
			array[index] = value;
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

		public void set(int index, Integer value) {
			array[index] = value;
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

		public void set(int index, Long value) {
			array[index] = value;
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

		public void set(int index, Character value) {
			array[index] = value;
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

		public void set(int index, Double value) {
			array[index] = value;
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

		public void set(int index, Boolean value) {
			array[index] = value;
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

		public void set(int index, Short value) {
			array[index] = value;
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

		public void set(int index, Byte value) {
			array[index] = value;
		}
	}
}

class ListWrapper<T> extends AbstractWritableSequence<T> {
	private final List<T> list;

	public static<T> WritableSequence<T> wrap(List<T> list) {
		return new ListWrapper<T>(list);
	}

	private ListWrapper(List<T> list) {
		this.list = list;
	}

	public void set(int index, T value) {
		list.set(index, value);
	}

	public int size() {
		return list.size();
	}

	public T get(int index) {
		return list.get(index);
	}
}

interface Sequence<T> extends Iterable<T> {
	public Sequence<T> subSequence(int from);
	public Sequence<T> subSequence(int from, int to);
	public int size();
	public boolean isEmpty();
	public T get(int index);
}

class MultiSet<K> implements Iterable<K> {
	private final Map<K, Integer> map;
	private int size = 0;

	public MultiSet() {
		this(new HashMap<K, Integer>());
	}

	public MultiSet(Map<K, Integer> underlying) {
		map = underlying;
	}

	public int size() {
		return size;
	}

	public int entryCount() {
		return map.size();
	}

	public boolean isEmpty() {
		return size == 0;
	}

	public boolean contains(K key) {
		return map.containsKey(key);
	}

	public int add(K key) {
		Integer value = map.get(key);
		if (value == null)
			value = 0;
		value++;
		size++;
		map.put(key, value);
		return value;
	}

	public int remove(K key) {
		Integer value = map.get(key);
		if (value == null)
			return 0;
		value--;
		size--;
		if (value == 0)
			map.remove(key);
		else
			map.put(key, value);
		return value + 1;
	}

	public int removeAll(K key) {
		int value = map.remove(key);
		size -= value;
		return value;
	}

	public int get(K key) {
		Integer value = map.get(key);
		if (value == null)
			value = 0;
		return value;
	}

	public void clear() {
		map.clear();
		size = 0;
	}

	@Override
	public boolean equals(Object o) {
		if (this == o)
			return true;
		if (o == null || getClass() != o.getClass())
			return false;

		MultiSet multiSet = (MultiSet) o;

		return !(map != null ? !map.equals(multiSet.map) : multiSet.map != null);

	}

	@Override
	public int hashCode() {
		return map.hashCode();
	}

	public Iterator<K> iterator() {
		return map.keySet().iterator();
	}
}

interface PersistentSet<K> extends NavigableSet<K> {
	public void markState(Object marker);
	public PersistentSet<K> getState(Object marker);
}

class PersistentTreapSet<K> extends TreapSet<K> implements PersistentSet<K> {
	private Map<Object, Node> states = new HashMap<Object, Node>();

	public PersistentTreapSet() {
		super();
	}

	public PersistentTreapSet(Comparator<? super K> comparator) {
		super(comparator);
	}

	public PersistentTreapSet(Iterable<? extends K> collection) {
		super(collection);
	}

	public PersistentTreapSet(Iterable<? extends K> collection, Comparator<? super K> comparator) {
		super(collection, comparator);
	}

	public PersistentTreapSet(Node root, Comparator<? super K> comparator, Node nullNode) {
		super(null, null, false, false, comparator, root, nullNode);
	}

	public void markState(Object marker) {
		

		states.put(marker, root);
	}

	public PersistentTreapSet<K> getState(Object marker) {
		return new PersistentTreapSet<K>(states.get(marker), comparator, nullNode);
	}

	@Override
	protected Node createNode(K k) {
		return new PersistentNode(k, rnd.nextLong());
	}

	protected class PersistentNode extends Node {
		protected PersistentNode(K key, long priority) {
			super(key, priority);
		}

		@SuppressWarnings({"CloneDoesntCallSuperClone", "CloneDoesntDeclareCloneNotSupportedException"})
		@Override
		protected Node clone() {
			Node clone = new PersistentNode(key, priority);
			clone.left = left;
			clone.right = right;
			clone.size = size;
			return clone;
		}

		@SuppressWarnings({"unchecked"})
		protected Object[] split(K key) {
			Node clone = clone();
			if (compare(key, this.key) < 0) {
				Object[] result = left.split(key);
				clone.left = (Node) result[1];
				result[1] = clone;
				clone.updateSize();
				return result;
			}
			Object[] result = right.split(key);
			clone.right = (Node) result[0];
			result[0] = clone;
			clone.updateSize();
			return result;
		}

		@SuppressWarnings({"unchecked"})
		protected Node insert(Node node) {
			if (node.priority > priority) {
				Object[] result = split(node.key);
				node.left = (Node) result[0];
				node.right = (Node) result[1];
				node.updateSize();
				return node;
			}
			Node clone = clone();
			if (compare(node.key, this.key) < 0) {
				clone.left = left.insert(node);
				clone.updateSize();
				return clone;
			}
			clone.right = right.insert(node);
			clone.updateSize();
			return clone;
		}

		protected Node merge(Node left, Node right) {
			if (left == nullNode)
				return right;
			if (right == nullNode)
				return left;
			if (left.priority > right.priority) {
				

				left = ((PersistentNode)left).clone();
				left.right = left.right.merge(left.right, right);
				left.updateSize();
				return left;
			}
			

			right = ((PersistentNode)right).clone();
			right.left = right.left.merge(left, right.left);
			right.updateSize();
			return right;
		}

		protected Node erase(K key) {
			int value = compare(key, this.key);
			if (value == 0)
				return merge(left, right);
			Node clone = clone();
			if (value < 0) {
				clone.left = left.erase(key);
				clone.updateSize();
				return clone;
			}
			clone.right = right.erase(key);
			clone.updateSize();
			return clone;
		}
	}
}

class TreapSet<K> implements NavigableSet<K> {
	protected static final Random rnd = new Random(239);

	protected final Node nullNode;
	protected final Comparator<? super K> comparator;
	protected Node root;
	private final K from;
	private final K to;
	private final boolean fromInclusive;
	private final boolean toInclusive;

	public TreapSet() {
		this((Comparator<? super K>)null);
	}

	public TreapSet(Comparator<? super K> comparator) {
		this(null, null, false, false, comparator, null, null);
	}

	public TreapSet(Iterable<? extends K> collection) {
		this(collection, null);
	}

	public TreapSet(Iterable<? extends K> collection, Comparator<? super K> comparator) {
		this(comparator);
		addAll(collection);
	}

	protected TreapSet(K from, K to, boolean fromInclusive, boolean toInclusive, Comparator<? super K> comparator, Node root, Node nullNode) {
		this.comparator = comparator;
		this.from = from;
		this.to = to;
		this.fromInclusive = fromInclusive;
		this.toInclusive = toInclusive;
		if (nullNode == null)
			nullNode = new NullNode();
		if (root == null)
			root = nullNode;
		this.root = root;
		this.nullNode = nullNode;
	}

	public boolean addAll(Iterable<? extends K> collection) {
		boolean result = false;
		for (K element : collection)
			result |= add(element);
		return result;
	}

	public K lower(K k) {
		Node target = root.lower(k);
		if (target == nullNode)
			return null;
		if (belongs(target.key))
			return target.key;
		return null;
	}

	private boolean belongs(K key) {
		int valueFrom = compare(from, key);
		int valueTo = compare(key, to);
		return (valueFrom < 0 || valueFrom == 0 && fromInclusive) && (valueTo < 0 || valueTo == 0 && toInclusive);
	}

	public K floor(K k) {
		Node target = root.floor(k);
		if (target == nullNode)
			return null;
		if (belongs(target.key))
			return target.key;
		return null;
	}

	public K ceiling(K k) {
		Node target = root.ceil(k);
		if (target == nullNode)
			return null;
		if (belongs(target.key))
			return target.key;
		return null;
	}

	public K higher(K k) {
		Node target = root.higher(k);
		if (target == nullNode)
			return null;
		if (belongs(target.key))
			return target.key;
		return null;
	}

	public K pollFirst() {
		K first = first();
		if (first == null)
			throw new NoSuchElementException();
		root.erase(first);
		return first;
	}

	public K pollLast() {
		K last = last();
		if (last == null)
			throw new NoSuchElementException();
		root.erase(last);
		return last;
	}

	public int size() {
		if (from == null && to == null)
			return root.size;
		if (from == null) {
			Node to = toInclusive ? root.floor(this.to) : root.lower(this.to);
			if (to == nullNode)
				return 0;
			return root.indexOf(to) + 1;
		}
		if (to == null) {
			Node from = fromInclusive ? root.ceil(this.from) : root.higher(this.from);
			if (from == nullNode)
				return 0;
			return root.size - root.indexOf(from);
		}
		Node from = fromInclusive ? root.ceil(this.from) : root.higher(this.from);
		if (from == nullNode || !belongs(from.key))
			return 0;
		Node to = toInclusive ? root.floor(this.to) : root.lower(this.to);
		return root.indexOf(to) - root.indexOf(from) + 1;
	}

	public boolean isEmpty() {
		return size() == 0;
	}

	@SuppressWarnings({"unchecked"})
	public boolean contains(Object o) {
		return belongs((K) o) && root.search((K) o) != nullNode;
	}

	public Iterator<K> iterator() {
		return new Iterator<K>() {
			private K current = first();

			public boolean hasNext() {
				return current != null;
			}

			public K next() {
				K result = current;
				current = higher(current);
				return result;
			}

			public void remove() {
				TreapSet.this.remove(current);
			}
		};
	}

	public Object[] toArray() {
		Object[] array = new Object[size()];
		int index = 0;
		for (K key : this)
			array[index++] = key;
		return array;
	}

	@SuppressWarnings({"unchecked"})
	public <T> T[] toArray(T[] a) {
		if (a.length < size())
			throw new IllegalArgumentException();
		int index = 0;
		for (K key : this)
			a[index++] = (T) key;
		return a;
	}

	public boolean add(K k) {
		if (k == null)
			throw new NullPointerException();
		if (contains(k))
			return false;
		root = root.insert(createNode(k));
		return true;
	}

	protected Node createNode(K k) {
		return new Node(k, rnd.nextLong());
	}

	public boolean remove(Object o) {
		if (!contains(o))
			return false;
		

		root = root.erase((K) o);
		return true;
	}

	public boolean containsAll(Collection<?> c) {
		for (Object o : c) {
			if (!contains(o))
				return false;
		}
		return true;
	}

	public boolean addAll(Collection<? extends K> c) {
		return addAll((Iterable<? extends K>)c);
	}

	public boolean retainAll(Collection<?> c) {
		List<K> toRemove = new ArrayList<K>();
		for (K key : this) {
			if (!c.contains(key))
				toRemove.add(key);
		}
		return removeAll(toRemove);
	}

	public boolean removeAll(Collection<?> c) {
		boolean result = false;
		for (Object o : c)
			result |= remove(o);
		return result;
	}

	public void clear() {
		retainAll(Collections.<Object>emptySet());
	}

	public NavigableSet<K> descendingSet() {
		throw new UnsupportedOperationException();
	}

	public Iterator<K> descendingIterator() {
		return new Iterator<K>() {
			private K current = last();

			public boolean hasNext() {
				return current != null;
			}

			public K next() {
				K result = current;
				current = lower(current);
				return result;
			}

			public void remove() {
				TreapSet.this.remove(current);
			}
		};
	}

	public NavigableSet<K> subSet(K fromElement, boolean fromInclusive, K toElement, boolean toInclusive) {
		return new TreapSet<K>(fromElement, toElement, fromInclusive, toInclusive, comparator, root, nullNode);
	}

	public NavigableSet<K> headSet(K toElement, boolean inclusive) {
		return subSet(null, false, toElement, inclusive);
	}

	public NavigableSet<K> tailSet(K fromElement, boolean inclusive) {
		return subSet(fromElement, inclusive, null, false);
	}

	public Comparator<? super K> comparator() {
		return comparator;
	}

	public SortedSet<K> subSet(K fromElement, K toElement) {
		return subSet(fromElement, true, toElement, false);
	}

	public SortedSet<K> headSet(K toElement) {
		return subSet(null, false, toElement, false);
	}

	public SortedSet<K> tailSet(K fromElement) {
		return tailSet(fromElement, true);
	}

	public K first() {
		if (isEmpty())
			return null;
		if (from == null)
			return root.first().key;
		if (fromInclusive)
			return ceiling(from);
		return higher(from);
	}

	public K last() {
		if (isEmpty())
			return null;
		if (to == null)
			return root.last().key;
		if (toInclusive)
			return floor(to);
		return lower(to);
	}

	protected int compare(K first, K second) {
		if (first == null || second == null)
			return -1;
		if (comparator != null)
			return comparator.compare(first, second);
		

		return ((Comparable<? super K>)first).compareTo(second);
	}

	protected class Node {
		protected final K key;
		protected final long priority;
		protected Node left;
		protected Node right;
		protected int size;

		protected Node(K key, long priority) {
			this.key = key;
			this.priority = priority;
			left = nullNode;
			right = nullNode;
			size = 1;
		}

		@SuppressWarnings({"unchecked"})
		protected Object[] split(K key) {
			if (compare(key, this.key) < 0) {
				Object[] result = left.split(key);
				left = (Node) result[1];
				result[1] = this;
				updateSize();
				return result;
			}
			Object[] result = right.split(key);
			right = (Node) result[0];
			result[0] = this;
			updateSize();
			return result;
		}

		protected void updateSize() {
			size = left.size + right.size + 1;
		}

		@SuppressWarnings({"unchecked"})
		protected Node insert(Node node) {
			if (node.priority > priority) {
				Object[] result = split(node.key);
				node.left = (Node) result[0];
				node.right = (Node) result[1];
				node.updateSize();
				return node;
			}
			if (compare(node.key, this.key) < 0) {
				left = left.insert(node);
				updateSize();
				return this;
			}
			right = right.insert(node);
			updateSize();
			return this;
		}

		protected Node merge(Node left, Node right) {
			if (left == nullNode)
				return right;
			if (right == nullNode)
				return left;
			if (left.priority > right.priority) {
				left.right = left.right.merge(left.right, right);
				left.updateSize();
				return left;
			}
			right.left = right.left.merge(left, right.left);
			right.updateSize();
			return right;
		}

		protected Node erase(K key) {
			int value = compare(key, this.key);
			if (value == 0)
				return merge(left, right);
			if (value < 0) {
				left = left.erase(key);
				updateSize();
				return this;
			}
			right = right.erase(key);
			updateSize();
			return this;
		}

		protected Node lower(K key) {
			if (compare(key, this.key) <= 0)
				return left.lower(key);
			Node result = right.lower(key);
			if (result == nullNode)
				return this;
			return result;
		}

		protected Node floor(K key) {
			if (compare(key, this.key) < 0)
				return left.floor(key);
			Node result = right.floor(key);
			if (result == nullNode)
				return this;
			return result;
		}

		protected Node higher(K key) {
			if (compare(key, this.key) >= 0)
				return right.higher(key);
			Node result = left.higher(key);
			if (result == nullNode)
				return this;
			return result;
		}

		protected Node ceil(K key) {
			if (compare(key, this.key) > 0)
				return right.ceil(key);
			Node result = left.ceil(key);
			if (result == nullNode)
				return this;
			return result;
		}

		protected Node first() {
			if (left == nullNode)
				return this;
			return left.first();
		}

		protected Node last() {
			if (right == nullNode)
				return this;
			return right.last();
		}

		protected Node search(K key) {
			int value = compare(key, this.key);
			if (value == 0)
				return this;
			if (value < 0)
				return left.search(key);
			return right.search(key);
		}

		public int indexOf(Node node) {
			if (this == node)
				return left.size;
			if (compare(node.key, this.key) > 0)
				return left.size + 1 + right.indexOf(node);
			return left.indexOf(node);
		}
	}

	private class NullNode extends Node {
		private NullNode() {
			super(null, Long.MIN_VALUE);
			left = this;
			right = this;
			size = 0;
		}

		@Override
		protected Object[] split(K key) {
			return new Object[]{this, this};
		}

		@Override
		protected Node insert(Node node) {
			return node;
		}

		@Override
		protected Node erase(K key) {
			return this;
		}

		@Override
		protected Node lower(K key) {
			return this;
		}

		@Override
		protected Node floor(K key) {
			return this;
		}

		@Override
		protected Node higher(K key) {
			return this;
		}

		@Override
		protected Node ceil(K key) {
			return this;
		}

		@Override
		protected Node first() {
			throw new NoSuchElementException();
		}

		@Override
		protected Node last() {
			throw new NoSuchElementException();
		}

		@Override
		protected void updateSize() {
		}

		@Override
		protected Node search(K key) {
			return this;
		}


	}
}

interface Factory<V> {
	public V create();
}

class MiscUtils {
	public static final int[] DX_4_CONNECTED = {1, 0, -1, 0};
	public static final int[] DY_4_CONNECTED = {0, -1, 0, 1};

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

	public static boolean isValidCell(int row, int column, int rowCount, int columnCount) {
		return row >= 0 && row < rowCount && column >= 0 && column < columnCount;
	}

	public static List<Integer> getPath(int[] last, int destination) {
		List<Integer> path = new ArrayList<Integer>();
		while (destination != -1) {
			path.add(destination);
			destination = last[destination];
		}
		Collections.reverse(path);
		return path;
	}

	public static List<Integer> getPath(int[][] lastIndex, int[][] lastPathNumber, int destination, int pathNumber) {
		List<Integer> path = new ArrayList<Integer>();
		while (destination != -1 || pathNumber != 0) {
			path.add(destination);
			int nextDestination = lastIndex[destination][pathNumber];
			pathNumber = lastPathNumber[destination][pathNumber];
			destination = nextDestination;
		}
		Collections.reverse(path);
		return path;
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

	public static long binarySearch(long from, long to, Function<Long, Boolean> function) {
		while (from < to) {
			long argument = from + (to - from) / 2;
			if (function.value(argument))
				to = argument;
			else
				from = argument + 1;
		}
		return from;
	}

	public static<T> boolean equals(T first, T second) {
		return first == null && second == null || first != null && first.equals(second);
	}

	public static boolean isVowel(char ch) {
		ch = Character.toUpperCase(ch);
		return ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'Y';
	}
}

interface Operation<V> extends Factory<V> {
	public V operation(V first, V second);
}

interface PowerOperation<V> extends Operation<V> {
	public V power(V base, int exponent);
}

class SequenceUtils {
	public static<T> int find(Sequence<T> sequence, T value) {
		int size = sequence.size();
		for (int i = 0; i < size; i++) {
			if (MiscUtils.equals(sequence.get(i), value))
				return i;
		}
		return -1;
	}

	public static <T> int find(Sequence<T> sequence, Filter<T> filter) {
		int size = sequence.size();
		for (int i = 0; i < size; i++) {
			if (filter.accept(sequence.get(i)))
				return i;
		}
		return -1;
	}

	public static<T extends Comparable<T>> int minIndex(Sequence<T> sequence) {
		return find(sequence, CollectionUtils.minElement(sequence));
	}

	public static<T extends Comparable<T>> int maxIndex(Sequence<T> sequence) {
		return find(sequence, CollectionUtils.maxElement(sequence));
	}

	public static<T> int minIndex(Sequence<T> sequence, Comparator<T> comparator) {
		return find(sequence, CollectionUtils.minElement(sequence, comparator));
	}

	public static<T> int maxIndex(Sequence<T> sequence, Comparator<T> comparator) {
		return find(sequence, CollectionUtils.maxElement(sequence, comparator));
	}

	public static<T> void fill(WritableSequence<T> sequence, T value) {
		for (int i = 0; i < sequence.size(); i++)
			sequence.set(i, value);
	}

	public static<T> void fill(WritableSequence<T> sequence, Factory<T> factory) {
		for (int i = 0; i < sequence.size(); i++)
			sequence.set(i, factory.create());
	}

	public static<T extends Comparable<T>> long countUnorderedPairs(final Sequence<T> sequence) {
		long result = 0;
		NavigableSet<T> set = new TreapSet<T>();
		int index = 0;
		for (T element : sequence) {
			result += index - set.headSet(element).size();
			set.add(element);
		}
		return result;
	}

	public static<T extends Comparable<T>> boolean nextPermutation(WritableSequence<T> sequence) {
		for (int i = sequence.size() - 2; i >= 0; i--) {
			if (sequence.get(i).compareTo(sequence.get(i + 1)) < 0) {
				int index = i + 1;
				for (int j = i + 2; j < sequence.size(); j++) {
					if (sequence.get(i).compareTo(sequence.get(j)) >= 0)
						break;
					else
						index = j;
				}
				T temp = sequence.get(i);
				sequence.set(i, sequence.get(index));
				sequence.set(index, temp);
				sort(sequence.subSequence(i + 1));
				return true;
			}
		}
		return false;
	}

	@SuppressWarnings({"unchecked"})
	public static<T extends Comparable<T>> WritableSequence<T> sort(WritableSequence<T> sequence) {
		return sort(sequence, null);
	}

	@SuppressWarnings({"unchecked", "RedundantCast"})
	public static<T> WritableSequence<T> sort(WritableSequence<T> sequence, Comparator<? super T> comparator) {
		makeHeap(sequence, comparator);
		for (int i = sequence.size() - 1; i > 0; i--) {
			T temp = sequence.get(0);
			sequence.set(0, sequence.get(i));
			sequence.set(i, temp);
			siftDown(sequence, 0, i, comparator);
		}
		return sequence;
	}

	private static<T> WritableSequence<T> makeHeap(WritableSequence<T> sequence, Comparator<? super T> comparator) {
		int length = sequence.size();
		for (int i = length / 2 - 1; i >= 0; i--)
			siftDown(sequence, i, length, comparator);
		return sequence;
	}

	private static<T> void siftDown(WritableSequence<T> sequence, int start, int end, Comparator<? super T> comparator) {
		int root = start;
		while (2 * root + 1 < end) {
			int childIndex = 2 * root + 1;
			if (childIndex + 1 < end && compare(sequence.get(childIndex), sequence.get(childIndex + 1), comparator) < 0)
				childIndex++;
			if (compare(sequence.get(childIndex), sequence.get(root), comparator) <= 0)
				return;
			T temp = sequence.get(root);
			sequence.set(root, sequence.get(childIndex));
			sequence.set(childIndex, temp);
			root = childIndex;
		}
	}

	private static<T> int compare(T first, T second, Comparator<? super T> comparator) {
		if (comparator != null)
			return comparator.compare(first, second);
		

		return ((Comparable<? super T>)first).compareTo(second);
	}

	public static<T> boolean isSubSequence(Sequence<T> sequence, Sequence<T> sample) {
		int index = 0;
		for (T element : sequence) {
			if (element.equals(sample.get(index))) {
				if (++index == sample.size())
					return true;
			}
		}
		return false;
	}

	public static Integer[] order(final Sequence<? extends Comparable<?>>...sequences) {
		return ArrayUtils.order(sequences[0].size(), new Comparator<Integer>() {
			public int compare(Integer o1, Integer o2) {
				for (Sequence<? extends Comparable> sequence : sequences) {
					

					int value = sequence.get(o1).compareTo(sequence.get(o2));
					if (value != 0)
						return value;
				}
				return 0;
			}
		});
	}

	public static<T> Integer[] order(final Sequence<T> sequence, final Comparator<T> comparator) {
		return ArrayUtils.order(sequence.size(), new Comparator<Integer>() {
			public int compare(Integer o1, Integer o2) {
				return comparator.compare(sequence.get(o1), sequence.get(o2));
			}
		});
	}

	public static<T> WritableSequence<T> transform(WritableSequence<T> sequence, Function<T, T> function) {
		for (int i = 0; i < sequence.size(); i++)
			sequence.set(i, function.value(sequence.get(i)));
		return sequence;
	}

	public static WritableSequence<Integer> increment(WritableSequence<Integer> path) {
		return transform(path, new Function<Integer, Integer>() {
			public Integer value(Integer argument) {
				return argument + 1;
			}
		});
	}

	public static<T> boolean contains(WritableSequence<T> sequence, T value) {
		return find(sequence, value) != -1;
	}

	public static<T> boolean contains(WritableSequence<T> sequence, Filter<T> filter) {
		return find(sequence, filter) != -1;
	}

	public static<T> List<T> filter(Sequence<T> sequence, Filter<Pair<T, Integer>> filter) {
		List<T> result = new ArrayList<T>();
		for (int i = 0; i < sequence.size(); i++) {
			T element = sequence.get(i);
			if (filter.accept(Pair.makePair(element, i)))
				result.add(element);
		}
		return result;
	}
}

class StringWrapper extends AbstractSequence<Character> {
	private final CharSequence string;

	public static Sequence<Character> wrap(CharSequence string) {
		return new StringWrapper(string);
	}

	private StringWrapper(CharSequence string) {
		this.string = string;
	}

	public int size() {
		return string.length();
	}

	public Character get(int index) {
		return string.charAt(index);
	}
}

interface WritableSequence<T> extends Sequence<T> {
	public void set(int index, T value);
	public WritableSequence<T> subSequence(int from);
	public WritableSequence<T> subSequence(int from, int to);
}

class TaskD implements Solver {
	public void solve(int testNumber, InputReader in, PrintWriter out) {
		int photoCount = in.readInt();
		int albumCount = in.readInt();
		final int[] albums = IOUtils.readIntArray(in, albumCount);
		if (albumCount == 1 || photoCount % 2 == 1 && albumCount == 2) {
			out.println(-1);
			return;
		}
		if (ArrayUtils.sumArray(albums) < photoCount) {
			out.println(-1);
			return;
		}
		int maxPhoto = (int) (ArrayUtils.sumArray(albums) - CollectionUtils.maxElement(ArrayWrapper.wrap(albums)));
		if (maxPhoto * 2 < photoCount) {
			out.println(-1);
			return;
		}
		int[] result = new int[photoCount];
		final int maxIndex = SequenceUtils.maxIndex(ArrayWrapper.wrap(albums));
		result[0] = maxIndex + 1;
		albums[maxIndex]--;
		Queue<Integer> queue = new PriorityQueue<Integer>(albumCount, new Comparator<Integer>() {
			public int compare(Integer first, Integer second) {
				if (albums[first] != albums[second])
					return albums[second] - albums[first];
				if (first == maxIndex)
					return -1;
				if (second == maxIndex)
					return 1;
				return first - second;
			}
		});
		for (int i = 0; i < albumCount; i++)
			queue.add(i);
		for (int i = 1; i < photoCount - 1; i++) {
			int index1 = queue.poll();
			int index2 = queue.poll();
			if (result[i - 1] == index1 + 1) {
				albums[index2]--;
				result[i] = index2 + 1;
			} else {
				albums[index1]--;
				result[i] = index1 + 1;
			}
			queue.add(index1);
			queue.add(index2);
		}
		for (int i = 0; i < albumCount; i++) {
			if (albums[i] != 0 && i != maxIndex && i + 1 != result[photoCount - 2]) {
				result[photoCount - 1] = i + 1;
				break;
			}
		}
		IOUtils.printArray(result, out);
	}
}

