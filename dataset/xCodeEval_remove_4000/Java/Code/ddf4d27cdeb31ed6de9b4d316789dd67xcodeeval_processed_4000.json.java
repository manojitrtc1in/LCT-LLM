import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Iterator;
import java.io.BufferedWriter;
import java.util.Random;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.NoSuchElementException;
import java.io.InputStream;


public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskF solver = new TaskF();
		solver.solve(1, in, out);
		out.close();
	}

	static class TaskF {
		public void solve(int testNumber, InputReader in, OutputWriter out) {
			int n = in.readInt();
			int[] a = IOUtils.id0(in, n);
			int[] b = IOUtils.id0(in, n);
			int[] aOrder = ArrayUtils.order(a);
			int[] bOrder = ArrayUtils.order(b);
			ArrayUtils.reverse(aOrder);
			ArrayUtils.reverse(bOrder);
			int[] fA = new int[n];
			int[] fB = new int[n];
			int[] was = new int[n + 1];
			for (int i = 0; i < n; i++) {
				was[a[i]] = i + 1;
			}
			for (int i = 0; i < n; i++) {
				if (was[b[i]] != 0) {
					out.printLine(1);
					out.printLine(was[b[i]]);
					out.printLine(1);
					out.printLine(i + 1);
					return;
				}
			}
			Random r = new Random(239);
			for (int j = 0; ; j++) {
				int aSize = 0;
				int bSize = 0;
				int atA = 0;
				int atB = 0;
				int delta = 0;
				int cc = j;
				while (true) {
					if (delta >= 0) {
						if (atA == n) {
							break;
						}
						if (a[aOrder[atA]] == delta) {
							fA[aSize++] = aOrder[atA] + 1;
							print(out, fA, aSize, fB, bSize);
							return;
						}
						if ((cc & 1) != 1) {
							fA[aSize++] = aOrder[atA] + 1;
							delta -= a[aOrder[atA]];
						}
						cc >>= 1;
						atA++;
					} else {
						if (atB == n) {
							break;
						}
						if (b[bOrder[atB]] == -delta) {
							fB[bSize++] = bOrder[atB] + 1;
							print(out, fA, aSize, fB, bSize);
							return;
						}
						if ((cc & 1) != 1) {
							fB[bSize++] = bOrder[atB] + 1;
							delta += b[bOrder[atB]];
						}
						cc >>= 1;
						atB++;
					}
				}
			}


		}

		private void print(OutputWriter out, int[] fA, int aSize, int[] fB, int bSize) {
			Arrays.sort(fA, 0, aSize);
			Arrays.sort(fB, 0, bSize);
			out.printLine(aSize);
			out.printLine(Arrays.copyOf(fA, aSize));
			out.printLine(bSize);
			out.printLine(Arrays.copyOf(fB, bSize));
		}

	}

	static interface IntList extends id7 {
		public abstract int get(int index);

		public abstract void set(int index, int value);

		public abstract void addAt(int index, int value);

		public abstract void removeAt(int index);

		default public void swap(int first, int second) {
			if (first == second) {
				return;
			}
			int temp = get(first);
			set(first, get(second));
			set(second, temp);
		}

		default public IntIterator intIterator() {
			return new IntIterator() {
				private int at;
				private boolean removed;

				public int value() {
					if (removed) {
						throw new IllegalStateException();
					}
					return get(at);
				}

				public boolean advance() {
					at++;
					removed = false;
					return isValid();
				}

				public boolean isValid() {
					return !removed && at < size();
				}

				public void remove() {
					removeAt(at);
					at--;
					removed = true;
				}
			};
		}


		default public void add(int value) {
			addAt(size(), value);
		}

		default public IntList sort(IntComparator comparator) {
			Sorter.sort(this, comparator);
			return this;
		}

		default public void id5() {
			for (int i = 0, j = size() - 1; i < j; i++, j--) {
				swap(i, j);
			}
		}

		default public IntList subList(final int from, final int to) {
			return new IntList() {
				private final int shift;
				private final int size;

				{
					if (from < 0 || from > to || to > IntList.this.size()) {
						throw new IndexOutOfBoundsException("from = " + from + ", to = " + to + ", size = " + size());
					}
					shift = from;
					size = to - from;
				}

				public int size() {
					return size;
				}

				public int get(int at) {
					if (at < 0 || at >= size) {
						throw new IndexOutOfBoundsException("at = " + at + ", size = " + size());
					}
					return IntList.this.get(at + shift);
				}

				public void addAt(int index, int value) {
					throw new UnsupportedOperationException();
				}

				public void removeAt(int index) {
					throw new UnsupportedOperationException();
				}

				public void set(int at, int value) {
					if (at < 0 || at >= size) {
						throw new IndexOutOfBoundsException("at = " + at + ", size = " + size());
					}
					IntList.this.set(at + shift, value);
				}

				public IntList compute() {
					return new id8(this);
				}
			};
		}

	}

	static class OutputWriter {
		private final PrintWriter writer;

		public OutputWriter(OutputStream outputStream) {
			writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
		}

		public OutputWriter(Writer writer) {
			this.writer = new PrintWriter(writer);
		}

		public void print(int[] array) {
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

		public void close() {
			writer.close();
		}

		public void printLine(int i) {
			writer.println(i);
		}

	}

	static interface IntComparator {
		public int compare(int first, int second);

	}

	static class IntArray extends id3 implements IntList {
		private int[] data;

		public IntArray(int[] arr) {
			data = arr;
		}

		public int size() {
			return data.length;
		}

		public int get(int at) {
			return data[at];
		}

		public void addAt(int index, int value) {
			throw new UnsupportedOperationException();
		}

		public void removeAt(int index) {
			throw new UnsupportedOperationException();
		}

		public void set(int index, int value) {
			data[index] = value;
		}

	}

	static class InputReader {
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;
		private id9 filter;

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

		public int readInt() {
			int c = read();
			while (id2(c))
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
			} while (!id2(c));
			return res * sgn;
		}

		public boolean id2(int c) {
			if (filter != null)
				return filter.id2(c);
			return isWhitespace(c);
		}

		public static boolean isWhitespace(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		public interface id9 {
			public boolean id2(int ch);

		}

	}

	static class IOUtils {
		public static int[] id0(InputReader in, int size) {
			int[] array = new int[size];
			for (int i = 0; i < size; i++)
				array[i] = in.readInt();
			return array;
		}

	}

	static abstract class id3 implements IntStream {

		public String toString() {
			StringBuilder builder = new StringBuilder();
			boolean first = true;
			for (IntIterator it = intIterator(); it.isValid(); it.advance()) {
				if (first) {
					first = false;
				} else {
					builder.append(' ');
				}
				builder.append(it.value());
			}
			return builder.toString();
		}


		public boolean equals(Object o) {
			if (!(o instanceof IntStream)) {
				return false;
			}
			IntStream c = (IntStream) o;
			IntIterator it = intIterator();
			IntIterator jt = c.intIterator();
			while (it.isValid() && jt.isValid()) {
				if (it.value() != jt.value()) {
					return false;
				}
				it.advance();
				jt.advance();
			}
			return !it.isValid() && !jt.isValid();
		}


		public int hashCode() {
			int result = 0;
			for (IntIterator it = intIterator(); it.isValid(); it.advance()) {
				result *= 31;
				result += it.value();
			}
			return result;
		}

	}

	static interface IntCollection extends IntStream {
		public int size();

		default public void add(int value) {
			throw new UnsupportedOperationException();
		}

		default public int[] toArray() {
			int size = size();
			int[] array = new int[size];
			int i = 0;
			for (IntIterator it = intIterator(); it.isValid(); it.advance()) {
				array[i++] = it.value();
			}
			return array;
		}

		default public IntCollection addAll(IntStream values) {
			for (IntIterator it = values.intIterator(); it.isValid(); it.advance()) {
				add(it.value());
			}
			return this;
		}

	}

	static class id8 extends id3 implements IntList {
		private int size;
		private int[] data;

		public id8() {
			this(3);
		}

		public id8(int capacity) {
			data = new int[capacity];
		}

		public id8(IntCollection c) {
			this(c.size());
			addAll(c);
		}

		public id8(IntStream c) {
			this();
			if (c instanceof IntCollection) {
				ensureCapacity(((IntCollection) c).size());
			}
			addAll(c);
		}

		public id8(id8 c) {
			size = c.size();
			data = c.data.clone();
		}

		public id8(int[] arr) {
			size = arr.length;
			data = arr.clone();
		}

		public int size() {
			return size;
		}

		public int get(int at) {
			if (at >= size) {
				throw new IndexOutOfBoundsException("at = " + at + ", size = " + size);
			}
			return data[at];
		}

		private void ensureCapacity(int capacity) {
			if (data.length >= capacity) {
				return;
			}
			capacity = Math.max(2 * data.length, capacity);
			data = Arrays.copyOf(data, capacity);
		}

		public void addAt(int index, int value) {
			ensureCapacity(size + 1);
			if (index > size || index < 0) {
				throw new IndexOutOfBoundsException("at = " + index + ", size = " + size);
			}
			if (index != size) {
				System.arraycopy(data, index, data, index + 1, size - index);
			}
			data[index] = value;
			size++;
		}

		public void removeAt(int index) {
			if (index >= size || index < 0) {
				throw new IndexOutOfBoundsException("at = " + index + ", size = " + size);
			}
			if (index != size - 1) {
				System.arraycopy(data, index + 1, data, index, size - index - 1);
			}
			size--;
		}

		public void set(int index, int value) {
			if (index >= size) {
				throw new IndexOutOfBoundsException("at = " + index + ", size = " + size);
			}
			data[index] = value;
		}

	}

	static interface id7 extends IntCollection {
	}

	static interface IntStream extends Iterable<Integer>, Comparable<IntStream> {
		public IntIterator intIterator();

		default public Iterator<Integer> iterator() {
			return new Iterator<Integer>() {
				private IntIterator it = intIterator();

				public boolean hasNext() {
					return it.isValid();
				}

				public Integer next() {
					int result = it.value();
					it.advance();
					return result;
				}
			};
		}

		default public int compareTo(IntStream c) {
			IntIterator it = intIterator();
			IntIterator jt = c.intIterator();
			while (it.isValid() && jt.isValid()) {
				int i = it.value();
				int j = jt.value();
				if (i < j) {
					return -1;
				} else if (i > j) {
					return 1;
				}
				it.advance();
				jt.advance();
			}
			if (it.isValid()) {
				return 1;
			}
			if (jt.isValid()) {
				return -1;
			}
			return 0;
		}

	}

	static class Sorter {
		private static final int id6 = 16;

		private Sorter() {
		}

		public static void sort(IntList list, IntComparator comparator) {
			quickSort(list, 0, list.size() - 1, (Integer.bitCount(Integer.highestOneBit(list.size()) - 1) * 5) >> 1, comparator);
		}

		private static void quickSort(IntList list, int from, int to, int remaining, IntComparator comparator) {
			if (to - from < id6) {
				id4(list, from, to, comparator);
				return;
			}
			if (remaining == 0) {
				heapSort(list, from, to, comparator);
				return;
			}
			remaining--;
			int pivotIndex = (from + to) >> 1;
			int pivot = list.get(pivotIndex);
			list.swap(pivotIndex, to);
			int storeIndex = from;
			int equalIndex = to;
			for (int i = from; i < equalIndex; i++) {
				int value = comparator.compare(list.get(i), pivot);
				if (value < 0) {
					list.swap(storeIndex++, i);
				} else if (value == 0) {
					list.swap(--equalIndex, i--);
				}
			}
			quickSort(list, from, storeIndex - 1, remaining, comparator);
			for (int i = equalIndex; i <= to; i++) {
				list.swap(storeIndex++, i);
			}
			quickSort(list, storeIndex, to, remaining, comparator);
		}

		private static void heapSort(IntList list, int from, int to, IntComparator comparator) {
			for (int i = (to + from - 1) >> 1; i >= from; i--) {
				id1(list, i, to, comparator, from);
			}
			for (int i = to; i > from; i--) {
				list.swap(from, i);
				id1(list, from, i - 1, comparator, from);
			}
		}

		private static void id1(IntList list, int start, int end, IntComparator comparator, int delta) {
			int value = list.get(start);
			while (true) {
				int child = ((start - delta) << 1) + 1 + delta;
				if (child > end) {
					return;
				}
				int childValue = list.get(child);
				if (child + 1 <= end) {
					int otherValue = list.get(child + 1);
					if (comparator.compare(otherValue, childValue) > 0) {
						child++;
						childValue = otherValue;
					}
				}
				if (comparator.compare(value, childValue) >= 0) {
					return;
				}
				list.swap(start, child);
				start = child;
			}
		}

		private static void id4(IntList list, int from, int to, IntComparator comparator) {
			for (int i = from + 1; i <= to; i++) {
				int value = list.get(i);
				for (int j = i - 1; j >= from; j--) {
					if (comparator.compare(list.get(j), value) <= 0) {
						break;
					}
					list.swap(j, j + 1);
				}
			}
		}

	}

	static class Range {
		public static IntList range(int from, int to) {
			int[] result = new int[Math.abs(from - to)];
			int current = from;
			if (from <= to) {
				for (int i = 0; i < result.length; i++) {
					result[i] = current++;
				}
			} else {
				for (int i = 0; i < result.length; i++) {
					result[i] = current--;
				}
			}
			return new IntArray(result);
		}

	}

	static class ArrayUtils {
		public static int[] range(int from, int to) {
			return Range.range(from, to).toArray();
		}

		public static int[] createOrder(int size) {
			return range(0, size);
		}

		public static int[] sort(int[] array, IntComparator comparator) {
			return sort(array, 0, array.length, comparator);
		}

		public static int[] sort(int[] array, int from, int to, IntComparator comparator) {
			if (from == 0 && to == array.length)
				new IntArray(array).sort(comparator);
			else
				new IntArray(array).subList(from, to).sort(comparator);
			return array;
		}

		public static int[] order(final int[] array) {
			return sort(createOrder(array.length), new IntComparator() {
				public int compare(int first, int second) {
					if (array[first] < array[second])
						return -1;
					if (array[first] > array[second])
						return 1;
					return 0;
				}
			});
		}

		public static void reverse(int[] array) {
			new IntArray(array).id5();
		}

	}

	static interface IntIterator {
		public int value() throws NoSuchElementException;

		public boolean advance();

		public boolean isValid();

	}
}
