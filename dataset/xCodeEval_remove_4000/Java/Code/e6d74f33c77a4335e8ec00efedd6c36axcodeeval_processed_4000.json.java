import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.math.BigInteger;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;
import java.util.Arrays;
import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.util.Comparator;


public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
		String s = in.readString();
		int count = s.length();
		int[] balance = new int[count + 1];
		for (int i = 0; i < count; i++) {
			if (s.charAt(i) == '(') {
				balance[i + 1] = balance[i] + 1;
			} else {
				balance[i + 1] = balance[i] - 1;
			}
		}
		int freedom = Math.max(0, -balance[count]);
		long[] value = new long[count];
		for (int i = 0; i < count; i++) {
			value[i] = s.charAt(i) == '(' ? 0 : 1;
		}
		int[] order = ArrayUtils.order(value);
		int[] cl = new int[count];
		int current = -1;
		long last = -1;
		for (int j : order) {
			if (value[j] != last) {
				current++;
			}
			cl[j] = current;
			last = value[j];
		}
		current++;
		int[] nOrder = new int[count];
		int[] cnt = new int[count];
		int[] nCl = new int[count];
		for (int i = 1; i < count; i *= 2) {
			for (int j = 0; j < count; j++) {
				nOrder[j] = order[j] - i;
				if (nOrder[j] < 0) {
					nOrder[j] += count;
				}
			}
			Arrays.fill(cnt, 0, current, 0);
			for (int j = 0; j < count; j++) {
				cnt[cl[j]]++;
			}
			for (int j = 1; j < current; j++) {
				cnt[j] += cnt[j - 1];
			}
			for (int j = count - 1; j >= 0; j--) {
				order[--cnt[cl[nOrder[j]]]] = nOrder[j];
			}
			nCl[order[0]] = 0;
			current = 0;
			for (int j = 1; j < count; j++) {
				int s1 = order[j] + i;
				if (s1 >= count) {
					s1 -= count;
				}
				int s2 = order[j - 1] + i;
				if (s2 >= count) {
					s2 -= count;
				}
				if (cl[order[j]] != cl[order[j - 1]] || cl[s1] != cl[s2]) {
					current++;
				}
				nCl[order[j]] = current;
			}
			current++;
			System.arraycopy(nCl, 0, cl, 0, count);
		}






































		IntervalTree tree = new id7(ArrayUtils.asLong(balance)) {
			protected long neutralValue() {
				return Integer.MAX_VALUE;
			}

			protected long joinValue(long left, long right) {
				return Math.min(left, right);
			}
		};
		s += s;
		int min = ArrayUtils.minElement(balance);
		for (int i : order) {
			if (tree.query(i, count) >= balance[i] - freedom && tree.query(0, i - 1) >= balance[i] - freedom - balance[count]) {
				String answer = s.substring(i, i + count);
				for (int j = 0; j < freedom; j++) {
					out.print('(');
				}
				out.print(answer);
				for (int j = 0; j < balance[count]; j++) {
					out.print(')');
				}
				out.printLine();
				return;
			}
		}
	}
}

class InputReader {

	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;
	private id11 filter;

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

	public String readString() {
		int c = read();
		while (id2(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do {
			if (Character.isValidCodePoint(c))
				res.appendCodePoint(c);
			c = read();
		} while (!id2(c));
		return res.toString();
	}

	public boolean id2(int c) {
		if (filter != null)
			return filter.id2(c);
		return isWhitespace(c);
	}

	public static boolean isWhitespace(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	public interface id11 {
		public boolean id2(int ch);
	}
}

class OutputWriter {
	private final PrintWriter writer;

	public OutputWriter(OutputStream outputStream) {
		writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
	}

	public void print(Object...objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void printLine() {
		writer.println();
	}

	public void print(char i) {
		writer.print(i);
	}

	public void close() {
		writer.close();
	}

}

class ArrayUtils {

	public static int[] createOrder(int size) {
		int[] order = new int[size];
		for (int i = 0; i < size; i++)
			order[i] = i;
		return order;
	}

	public static int[] sort(int[] array, IntComparator comparator) {
		return sort(array, 0, array.length, comparator);
	}

	public static int[] sort(int[] array, int from, int to, IntComparator comparator) {
		if (from == 0 && to == array.length)
			new IntArray(array).id8(comparator);
		else
			new IntArray(array).subList(from, to).id8(comparator);
		return array;
	}

	public static int[] order(final long[] array) {
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

	public static int minPosition(int[] array) {
		return minPosition(array, 0, array.length);
	}

	public static int minPosition(int[] array, int from, int to) {
        if (from >= to)
            return -1;
        int min = array[from];
        int result = from;
        for (int i = from + 1; i < to; i++) {
            if (array[i] < min) {
                min = array[i];
                result = i;
            }
        }
        return result;
    }

	public static int minElement(int[] array) {
		return array[minPosition(array)];
	}

	public static long[] asLong(int[] array) {
		long[] result = new long[array.length];
		for (int i = 0; i < array.length; i++)
			result[i] = array[i];
		return result;
	}

}

abstract class IntervalTree {
	protected int size;

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

	protected abstract long id4(int root, int left, int right, int from, int to, int middle, long leftResult, long rightResult);
	protected abstract void id5(int root, int left, int right, int from, int to, int middle);
	protected abstract long queryFull(int root, int left, int right, int from, int to);
	protected abstract long id0();

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

	public long query(int from, int to) {
		return query(0, 0, size - 1, from, to);
	}

	protected long query(int root, int left, int right, int from, int to) {
		if (left > to || right < from)
			return id0();
		if (left >= from && right <= to)
			return queryFull(root, left, right, from, to);
		int middle = (left + right) >> 1;
		id5(root, left, right, from, to, middle);
		long leftResult = query(2 * root + 1, left, middle, from, to);
		long rightResult = query(2 * root + 2, middle + 1, right, from, to);
		return id4(root, left, right, from, to, middle, leftResult, rightResult);
	}
}

abstract class id7 extends IntervalTree {
	protected long[] value;
	protected long[] array;

	protected id7(long[] array) {
		super(array.length, false);
		this.array = array;
		init();
	}

	protected void initData(int size, int nodeCount) {
		value = new long[nodeCount];
	}

	protected void initAfter(int root, int left, int right, int middle) {
		value[root] = joinValue(value[2 * root + 1], value[2 * root + 2]);
	}

	protected void initBefore(int root, int left, int right, int middle) {
	}

	protected void initLeaf(int root, int index) {
		value[root] = array[index];
	}

	protected long id4(int root, int left, int right, int from, int to, int middle, long leftResult, long rightResult) {
		return joinValue(leftResult, rightResult);
	}

	protected void id5(int root, int left, int right, int from, int to, int middle) {
	}

	protected long queryFull(int root, int left, int right, int from, int to) {
		return value[root];
	}

	protected long id0() {
		return neutralValue();
	}

	protected abstract long neutralValue();
	protected abstract long joinValue(long left, long right);
}

abstract class IntCollection {
	public abstract IntIterator iterator();
	public abstract int size();

}

interface IntIterator {
	public int value() throws NoSuchElementException;
	
	public void advance() throws NoSuchElementException;
	public boolean isValid();
}

interface IntComparator {

	public int compare(int first, int second);
}

abstract class IntList extends IntCollection implements Comparable<IntList> {
	private static final int id9 = 16;

	public abstract int get(int index);
	public abstract void set(int index, int value);

	public IntIterator iterator() {
		return new IntIterator() {
			private int size = size();
			private int index = 0;

			public int value() throws NoSuchElementException {
				if (!isValid())
					throw new NoSuchElementException();
				return get(index);
			}

			public void advance() throws NoSuchElementException {
				if (!isValid())
					throw new NoSuchElementException();
				index++;
			}

			public boolean isValid() {
				return index < size;
			}
		};
	}

	public IntList subList(final int from, final int to) {
		return new SubList(from, to);
	}

	private void swap(int first, int second) {
		if (first == second)
			return;
		int temp = get(first);
		set(first, get(second));
		set(second, temp);
	}

	public id10 id8(IntComparator comparator) {
		quickSort(0, size() - 1, (Integer.bitCount(Integer.highestOneBit(size()) - 1) * 5) >> 1, comparator);
		return new id6(this, comparator);
	}

	private void quickSort(int from, int to, int remaining, IntComparator comparator) {
		if (to - from < id9) {
			id3(from, to, comparator);
			return;
		}
		if (remaining == 0) {
			heapSort(from, to, comparator);
			return;
		}
		remaining--;
		int pivotIndex = (from + to) >> 1;
		int pivot = get(pivotIndex);
		swap(pivotIndex, to);
		int storeIndex = from;
		int equalIndex = to;
		for (int i = from; i < equalIndex; i++) {
			int value = comparator.compare(get(i), pivot);
			if (value < 0)
				swap(storeIndex++, i);
			else if (value == 0)
				swap(--equalIndex, i--);
		}
		quickSort(from, storeIndex - 1, remaining, comparator);
		for (int i = equalIndex; i <= to; i++)
			swap(storeIndex++, i);
		quickSort(storeIndex, to, remaining, comparator);
	}

	private void heapSort(int from, int to, IntComparator comparator) {
		for (int i = (to + from - 1) >> 1; i >= from; i--)
			id1(i, to, comparator, from);
		for (int i = to; i > from; i--) {
			swap(from, i);
			id1(from, i - 1, comparator, from);
		}
	}

	private void id1(int start, int end, IntComparator comparator, int delta) {
		int value = get(start);
		while (true) {
			int child = ((start - delta) << 1) + 1 + delta;
			if (child > end)
				return;
			int childValue = get(child);
			if (child + 1 <= end) {
				int otherValue = get(child + 1);
				if (comparator.compare(otherValue, childValue) > 0) {
					child++;
					childValue = otherValue;
				}
			}
			if (comparator.compare(value, childValue) >= 0)
				return;
			swap(start, child);
			start = child;
		}
	}

	private void id3(int from, int to, IntComparator comparator) {
		for (int i = from + 1; i <= to; i++) {
			int value = get(i);
			for (int j = i - 1; j >= from; j--) {
				if (comparator.compare(get(j), value) <= 0)
					break;
				swap(j, j + 1);
			}
		}
	}

	public int hashCode() {
		int hashCode = 1;
		for (IntIterator i = iterator(); i.isValid(); i.advance())
			hashCode = 31 * hashCode + i.value();
		return hashCode;
	}

	public boolean equals(Object obj) {
		if (!(obj instanceof IntList))
			return false;
		IntList list = (IntList)obj;
		if (list.size() != size())
			return false;
		IntIterator i = iterator();
		IntIterator j = list.iterator();
		while (i.isValid()) {
			if (i.value() != j.value())
				return false;
			i.advance();
			j.advance();
		}
		return true;
	}

	public int compareTo(IntList o) {
		IntIterator i = iterator();
		IntIterator j = o.iterator();
		while (true) {
			if (i.isValid()) {
				if (j.isValid()) {
					if (i.value() != j.value()) {
						if (i.value() < j.value())
							return -1;
						else
							return 1;
					}
				} else
					return 1;
			} else {
				if (j.isValid())
					return -1;
				else
					return 0;
			}
			i.advance();
			j.advance();
		}
	}

	private class SubList extends IntList {
        private final int to;
        private final int from;
        private int size;

        public SubList(int from, int to) {
            this.to = to;
            this.from = from;
            size = to - from;
        }

        public int get(int index) {
            if (index < 0 || index >= size)
                throw new IndexOutOfBoundsException();
            return IntList.this.get(index + from);
        }

        public void set(int index, int value) {
            if (index < 0 || index >= size)
                throw new IndexOutOfBoundsException();
            IntList.this.set(index + from, value);
        }

        public int size() {
            return size;
        }

	}
}

abstract class id10 extends IntList {
	protected final IntComparator comparator;

	protected id10(IntComparator comparator) {
		this.comparator = comparator;
	}

	public void set(int index, int value) {
		throw new UnsupportedOperationException();
	}

	public id10 id8(IntComparator comparator) {
		if (comparator == this.comparator)
			return this;
		throw new UnsupportedOperationException();
	}

	protected void ensureSorted() {
		int size = size();
		if (size == 0)
			return;
		int last = get(0);
		for (int i = 1; i < size; i++) {
			int current = get(i);
			if (comparator.compare(last, current) > 0)
				throw new IllegalArgumentException();
			last = current;
		}
	}

	public id10 subList(final int from, final int to) {
		return new id10(comparator) {
			private int size = to - from;

			public int get(int index) {
				if (index < 0 || index >= size)
					throw new IndexOutOfBoundsException();
				return id10.this.get(index + from);
			}

			public int size() {
				return size;
			}
		};
	}
}

class IntArray extends IntList {
	private final int[] array;

	public IntArray(int[] array) {
		this.array = array;
	}

	public int get(int index) {
		return array[index];
	}

	public void set(int index, int value) {
		array[index] = value;
	}

	public int size() {
		return array.length;
	}

}

class id6 extends id10 {
	private final int[] array;

	public id6(IntCollection collection, IntComparator comparator) {
		super(comparator);
		array = new int[collection.size()];
		int i = 0;
		for (IntIterator iterator = collection.iterator(); iterator.isValid(); iterator.advance())
			array[i++] = iterator.value();
		ensureSorted();
	}

	public int get(int index) {
		return array[index];
	}

	public int size() {
		return array.length;
	}
}
