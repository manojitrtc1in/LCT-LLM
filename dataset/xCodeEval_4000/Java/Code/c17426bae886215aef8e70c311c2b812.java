import java.util.Map;
import java.util.Collections;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.math.BigInteger;
import java.util.*;
import java.util.Collection;
import java.util.ArrayList;
import java.util.List;
import java.util.TreeMap;
import java.util.Comparator;
import java.io.*;
import java.util.Iterator;
import java.util.Arrays;


public class Main {
	public static void main(String[] args) {
		InputReader in = new StreamInputReader(System.in);
		PrintWriter out = new PrintWriter(System.out);
		run(in, out);
	}

	public static void run(InputReader in, PrintWriter out) {
		Solver solver = new TaskDTreap();
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

interface Solver {
	public void solve(int testNumber, InputReader in, PrintWriter out);
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

class Pair<U, V> {

	public static class Comparator<U extends Comparable<U>, V extends Comparable<V>> implements java.util.Comparator<Pair<U, V>> {
		public int compare(Pair<U, V> o1, Pair<U, V> o2) {
			int result = o1.first.compareTo(o2.first);
			if (result != 0)
				return result;
			return o1.second.compareTo(o2.second);
		}
	}

	private final U first;
	private final V second;

	public Pair(U first, V second) {
		this.first = first;
		this.second = second;
	}

	public U first() {
		return first;
	}

	public V second() {
		return second;
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

	@Override
	public String toString() {
		return "(" + first + "," + second + ")";
	}
}

class TreapSet<K> implements NavigableSet<K> {
	private static final Random rnd = new Random(239);

	private final Node nullNode;
	private final Comparator<? super K> comparator;
	private Node root;
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

	private TreapSet(K from, K to, boolean fromInclusive, boolean toInclusive, Comparator<? super K> comparator, Node root, Node nullNode) {
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
		root = root.insert(new Node(k, rnd.nextLong()));
		return true;
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

	private int compare(K first, K second) {
		if (first == null || second == null)
			return -1;
		if (comparator != null)
			return comparator.compare(first, second);
		

		return ((Comparable<? super K>)first).compareTo(second);
	}

	private class Node {
		private final K key;
		private final long priority;
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

class IntegerUtils {

	public static int longCompare(long a, long b) {
		if (a < b)
			return -1;
		if (a > b)
			return 1;
		return 0;
	}

	}

class TaskDTreap implements Solver {
	public void solve(int testNumber, InputReader in, PrintWriter out) {
		int count = in.readInt();
		int queryCount = in.readInt();
		NavigableSet<Pair<Long, Long>> byLength = new TreeSet<Pair<Long, Long>>(new Comparator<Pair<Long, Long>>() {
			public int compare(Pair<Long, Long> o1, Pair<Long, Long> o2) {
				long length1 = o1.second() - o1.first();
				long length2 = o2.second() - o2.first();
				int value = IntegerUtils.longCompare(length1, length2);
				if (value != 0)
					return -value;
				return IntegerUtils.longCompare(o2.first(), o1.first());
			}
		});
		NavigableSet<Pair<Long, Long>> byOrder = new TreeSet<Pair<Long, Long>>(new Pair.Comparator<Long, Long>());
		Pair<Long, Long> all = new Pair<Long, Long>(1L, (long)count);
		byLength.add(all);
		byOrder.add(all);
		Map<Integer, Integer> atWork = new HashMap<Integer, Integer>();
		NavigableSet<Integer> occupied = new TreapSet<Integer>();
		for (int it = 0; it < queryCount; it++) {
			int employee = in.readInt();
			if (employee == 0) {
				int from = in.readInt();
				int to = in.readInt();
				out.println(occupied.subSet(from, true, to, true).size());
			} else {
				if (!atWork.containsKey(employee)) {
					int position = add(byLength, byOrder);
					atWork.put(employee, position);
					occupied.add(position);
				} else {
					int position = atWork.get(employee);
					remove(byLength, byOrder, position);
					atWork.remove(employee);
					occupied.remove(position);
				}
			}
		}
	}

	private void remove(NavigableSet<Pair<Long, Long>> byLength, NavigableSet<Pair<Long, Long>> byOrder, long position) {
		Pair<Long, Long> toTest = new Pair<Long, Long>(position, position);
		Pair<Long, Long> left = null;
		SortedSet<Pair<Long, Long>> headSet = byOrder.headSet(toTest);
		if (!headSet.isEmpty())
			left = headSet.last();
		if (left != null && left.second() + 1 != position)
			left = null;
		Pair<Long, Long> right = null;
		SortedSet<Pair<Long, Long>> tailSet = byOrder.tailSet(toTest);
		if (!tailSet.isEmpty())
			right = tailSet.first();
		if (right != null && right.first() - 1 != position)
			right = null;
		if (left != null) {
			byLength.remove(left);
			byOrder.remove(left);
		}
		if (right != null) {
			byLength.remove(right);
			byOrder.remove(right);
		}
		Pair<Long, Long> toAdd = new Pair<Long, Long>(left != null ? left.first() : position, right != null ? right.second() : position);
		byLength.add(toAdd);
		byOrder.add(toAdd);
	}

	private int add(NavigableSet<Pair<Long, Long>> byLength, NavigableSet<Pair<Long, Long>> byOrder) {
		Pair<Long, Long> toDivide = byLength.first();
		byLength.remove(toDivide);
		byOrder.remove(toDivide);
		long position = (toDivide.first() + toDivide.second() + 1) / 2;
		Pair<Long, Long> left = new Pair<Long, Long>(toDivide.first(), position - 1);
		Pair<Long, Long> right = new Pair<Long, Long>(position + 1, toDivide.second());
		if (left.first() <= left.second()) {
			byLength.add(left);
			byOrder.add(left);
		}
		if (right.first() <= right.second()) {
			byLength.add(right);
			byOrder.add(right);
		}
		return (int) position;
	}

}
