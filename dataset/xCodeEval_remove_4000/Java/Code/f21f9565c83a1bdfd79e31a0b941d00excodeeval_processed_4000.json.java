import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.AbstractSet;
import java.util.InputMismatchException;
import java.util.Random;
import java.util.Map;
import java.io.OutputStreamWriter;
import java.util.NoSuchElementException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Iterator;
import java.io.BufferedWriter;
import java.util.Set;
import java.io.IOException;
import java.util.AbstractMap;
import java.io.Writer;
import java.util.Map.Entry;
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
		private static final long MOD = (long) (1e9 + 7);
		long[] tens;
		id1 automaton;
		long[][] result;

		public void solve(int testNumber, InputReader in, OutputWriter out) {
			String s = in.readString();
			String x = in.readString();
			String y = in.readString();
			int sCount = s.length() - x.length() / 2 + 1;
			if (sCount <= 0) {
				out.printLine(0);
				return;
			}
			String[] samples = new String[sCount];
			for (int i = 0; i < samples.length; i++) {
				samples[i] = s.substring(i, i + x.length() / 2);
			}
			automaton = new id1(samples, '0', '9');
			long answer = 0;
			tens = IntegerUtils.id5(10, x.length() + 1, MOD);
			boolean separate = false;
			result = new long[x.length() + 1][automaton.ends.length];
			ArrayUtils.fill(result, -1);
			for (int i = 0; i < x.length(); i++) {
				if (separate) {
					for (int j = x.charAt(i) - '0' + 1; j < 10; j++) {
						answer += solve(x.substring(0, i) + j, x.length() - i - 1);
					}
					for (int j = 0; j < y.charAt(i) - '0'; j++) {
						answer += solve(y.substring(0, i) + j, x.length() - i - 1);
					}
				} else {
					if (x.charAt(i) != y.charAt(i)) {
						separate = true;
						for (int j = x.charAt(i) - '0' + 1; j < y.charAt(i) - '0'; j++) {
							answer += solve(x.substring(0, i) + j, x.length() - i - 1);
						}
					}
				}
			}
			answer += solve(x, 0);
			if (!x.equals(y)) {
				answer += solve(y, 0);
			}
			answer %= MOD;
			out.printLine(answer);
		}

		long solve(String s, int remaining) {
			int start = 0;
			for (int i = 0; i < s.length(); i++) {
				start = automaton.edges[start][s.charAt(i) - '0'];
				if (automaton.ends[start] != 0) {
					return tens[remaining];
				}
			}
			return go(remaining, start);
		}

		private long go(int remaining, int start) {
			if (result[remaining][start] != -1) {
				return result[remaining][start];
			}
			if (automaton.ends[start] != 0) {
				return result[remaining][start] = tens[remaining];
			}
			result[remaining][start] = 0;
			if (remaining == 0) {
				return 0;
			}
			for (int i = 0; i < 10; i++) {
				result[remaining][start] += go(remaining - 1, automaton.edges[start][i]);
			}
			return result[remaining][start] %= MOD;
		}

	}

	static class InputReader {
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;
		private id16 filter;

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

		public interface id16 {
			public boolean id2(int ch);

		}

	}

	static abstract class id13 implements StringHash {
		public static final long id9;
		protected static final long id17;
		protected static final long id15;
		public static final long FIRST_MOD;
		public static final long SECOND_MOD;

		static {
			Random random = new Random(System.currentTimeMillis());
			FIRST_MOD = IntegerUtils.nextPrime((long) (1e9 + random.nextInt((int) 1e9)));
			SECOND_MOD = IntegerUtils.nextPrime((long) (1e9 + random.nextInt((int) 1e9)));
			id9 = random.nextInt((int) 1e9 - 257) + 257;
			id17 = IntegerUtils.reverse(id9, FIRST_MOD);
			id15 = IntegerUtils.reverse(id9, SECOND_MOD);
		}

		public long hash(int from) {
			return hash(from, length());
		}

	}

	static class Graph {
		public static final int id18 = 0;
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

		public int addEdge(int fromID, int toID, long weight, long capacity, int reverseEdge) {
			id10(edgeCount + 1);
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

		public final int id4(int from, int to, long weight, long capacity) {
			if (capacity == 0) {
				return addEdge(from, to, weight, 0, -1);
			} else {
				int id8 = edgeCount;
				addEdge(to, from, -weight, 0, id8 + id11());
				return addEdge(from, to, weight, capacity, id8);
			}
		}

		protected int id11() {
			return 1;
		}

		public final int id0(int from, int to, long weight) {
			return id4(from, to, weight, 0);
		}

		public final int id12(int from, int to) {
			return id0(from, to, 0);
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

		public final int destination(int id) {
			return to[id];
		}

		public final boolean flag(int id, int bit) {
			return (flags[id] >> bit & 1) != 0;
		}

		public final boolean isRemoved(int id) {
			return flag(id, id18);
		}

		protected void id10(int size) {
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

		protected class GraphEdge implements Edge {
			protected int id;

			protected GraphEdge(int id) {
				this.id = id;
			}

		}

	}

	static class IntegerUtils {
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

		public static long[] id5(long base, int count, long mod) {
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

	}

	static class OutputWriter {
		private final PrintWriter writer;

		public OutputWriter(OutputStream outputStream) {
			writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
		}

		public OutputWriter(Writer writer) {
			this.writer = new PrintWriter(writer);
		}

		public void close() {
			writer.close();
		}

		public void printLine(long i) {
			writer.println(i);
		}

		public void printLine(int i) {
			writer.println(i);
		}

	}

	static class Counter<K> extends id7<K, Long> {
		public Counter() {
			super();
		}

		public Counter(int capacity) {
			super(capacity);
		}

		public long add(K key) {
			long result = get(key);
			put(key, result + 1);
			return result + 1;
		}


		public Long get(Object key) {
			if (containsKey(key))
				return super.get(key);
			return 0L;
		}

	}

	static interface Edge {
	}

	static class id7<E, V> extends AbstractMap<E, V> {
		private static final int[] shifts = new int[10];
		private int size;
		private HashEntry<E, V>[] data;
		private int capacity;
		private Set<Entry<E, V>> entrySet;

		static {
			Random random = new Random(System.currentTimeMillis());
			for (int i = 0; i < 10; i++)
				shifts[i] = 1 + 3 * i + random.nextInt(3);
		}

		public id7() {
			this(4);
		}

		private void setCapacity(int size) {
			capacity = Integer.highestOneBit(4 * size);
			

			data = new HashEntry[capacity];
		}

		public id7(int maxSize) {
			setCapacity(maxSize);
			entrySet = new AbstractSet<Entry<E, V>>() {

				public Iterator<Entry<E, V>> iterator() {
					return new Iterator<Entry<E, V>>() {
						private HashEntry<E, V> last = null;
						private HashEntry<E, V> current = null;
						private HashEntry<E, V> base = null;
						private int lastIndex = -1;
						private int index = -1;

						public boolean hasNext() {
							if (current == null) {
								for (index++; index < capacity; index++) {
									if (data[index] != null) {
										base = current = data[index];
										break;
									}
								}
							}
							return current != null;
						}

						public Entry<E, V> next() {
							if (!hasNext())
								throw new NoSuchElementException();
							last = current;
							lastIndex = index;
							current = current.next;
							if (base.next != last)
								base = base.next;
							return last;
						}

						public void remove() {
							if (last == null)
								throw new IllegalStateException();
							size--;
							if (base == last)
								data[lastIndex] = last.next;
							else
								base.next = last.next;
						}
					};
				}


				public int size() {
					return size;
				}
			};
		}

		public id7(Map<E, V> map) {
			this(map.size());
			putAll(map);
		}


		public Set<Entry<E, V>> entrySet() {
			return entrySet;
		}


		public void clear() {
			Arrays.fill(data, null);
			size = 0;
		}

		private int index(Object o) {
			return getHash(o.hashCode()) & (capacity - 1);
		}

		private int getHash(int h) {
			int result = h;
			for (int i : shifts)
				result ^= h >>> i;
			return result;
		}


		public V remove(Object o) {
			if (o == null)
				return null;
			int index = index(o);
			HashEntry<E, V> current = data[index];
			HashEntry<E, V> last = null;
			while (current != null) {
				if (current.key.equals(o)) {
					if (last == null)
						data[index] = current.next;
					else
						last.next = current.next;
					size--;
					return current.value;
				}
				last = current;
				current = current.next;
			}
			return null;
		}


		public V put(E e, V value) {
			if (e == null)
				return null;
			int index = index(e);
			HashEntry<E, V> current = data[index];
			if (current != null) {
				while (true) {
					if (current.key.equals(e)) {
						V oldValue = current.value;
						current.value = value;
						return oldValue;
					}
					if (current.next == null)
						break;
					current = current.next;
				}
			}
			if (current == null)
				data[index] = new HashEntry<E, V>(e, value);
			else
				current.next = new HashEntry<E, V>(e, value);
			size++;
			if (2 * size > capacity) {
				HashEntry<E, V>[] oldData = data;
				setCapacity(size);
				for (HashEntry<E, V> entry : oldData) {
					while (entry != null) {
						HashEntry<E, V> next = entry.next;
						index = index(entry.key);
						entry.next = data[index];
						data[index] = entry;
						entry = next;
					}
				}
			}
			return null;
		}


		public V get(Object o) {
			if (o == null)
				return null;
			int index = index(o);
			HashEntry<E, V> current = data[index];
			while (current != null) {
				if (current.key.equals(o))
					return current.value;
				current = current.next;
			}
			return null;
		}


		public boolean containsKey(Object o) {
			if (o == null)
				return false;
			int index = index(o);
			HashEntry<E, V> current = data[index];
			while (current != null) {
				if (current.key.equals(o))
					return true;
				current = current.next;
			}
			return false;
		}


		public int size() {
			return size;
		}

		private static class HashEntry<E, V> implements Entry<E, V> {
			private final E key;
			private V value;
			private HashEntry<E, V> next;

			private HashEntry(E key, V value) {
				this.key = key;
				this.value = value;
			}

			public E getKey() {
				return key;
			}

			public V getValue() {
				return value;
			}

			public V setValue(V value) {
				V oldValue = this.value;
				this.value = value;
				return oldValue;
			}

		}

	}

	static class id3 extends id13 {
		private static long[] id6 = new long[0];
		private static long[] id14 = new long[0];
		private final long[] firstHash;
		private final long[] secondHash;

		public id3(CharSequence string) {
			int length = string.length();
			ensureCapacity(length);
			firstHash = new long[length + 1];
			secondHash = new long[length + 1];
			long firstPower = 1;
			long secondPower = 1;
			for (int i = 0; i < length; i++) {
				firstHash[i + 1] = (firstHash[i] + string.charAt(i) * firstPower) % FIRST_MOD;
				secondHash[i + 1] = (secondHash[i] + string.charAt(i) * secondPower) % SECOND_MOD;
				firstPower *= id9;
				firstPower %= FIRST_MOD;
				secondPower *= id9;
				secondPower %= SECOND_MOD;
			}
		}

		private void ensureCapacity(int length) {
			if (id6.length >= length)
				return;
			length = Math.max(length + 1, id6.length << 1);
			long[] oldFirst = id6;
			long[] oldSecond = id14;
			id6 = new long[length];
			id14 = new long[length];
			System.arraycopy(oldFirst, 0, id6, 0, oldFirst.length);
			System.arraycopy(oldSecond, 0, id14, 0, oldSecond.length);
			id6[0] = id14[0] = 1;
			for (int i = Math.max(oldFirst.length, 1); i < length; i++) {
				id6[i] = id6[i - 1] * id17 % FIRST_MOD;
				id14[i] = id14[i - 1] * id15 % SECOND_MOD;
			}
		}

		public long hash(int from, int to) {
			return (((firstHash[to] - firstHash[from] + FIRST_MOD) * id6[from] % FIRST_MOD) << 32) +
				((secondHash[to] - secondHash[from] + SECOND_MOD) * id14[from] % SECOND_MOD);
		}

		public int length() {
			return firstHash.length - 1;
		}

	}

	static class ArrayUtils {
		public static void fill(long[][] array, long value) {
			for (long[] row : array)
				Arrays.fill(row, value);
		}

	}

	static class Indexer<K> extends id7<K, Integer> {
		private int index = 0;


		public Integer get(Object key) {
			if (!containsKey(key))
				put((K) key, index++);
			return super.get(key);
		}

	}

	static interface StringHash {
		long hash(int from, int to);

		long hash(int from);

		int length();

	}

	static class id1 {
		public int[][] edges;
		public int[] ends;

		public id1(String[] words) {
			this(words, 'a', 'z');
		}

		public id1(String[] words, char first, char last) {
			Indexer<Long> indexer = new Indexer<>();
			Counter<Long> fullWords = new Counter<>();
			StringHash[] hashes = new StringHash[words.length];
			int totalLength = 0;
			for (int i = 0; i < words.length; i++) {
				String s = words[i];
				hashes[i] = new id3(s);
				for (int j = 0; j <= s.length(); j++)
					indexer.get(hashes[i].hash(0, j));
				fullWords.add(hashes[i].hash(0));
				totalLength += s.length();
			}
			int size = indexer.size();
			edges = new int[size][last - first + 1];
			ends = new int[size];
			int[] link = new int[size];
			Arrays.fill(link, -1);
			int[] start = new int[size];
			Arrays.fill(start, -1);
			int[] next = new int[totalLength];
			int[] to = new int[totalLength];
			int index = 0;
			Graph graph = new Graph(size);
			int[] length = new int[size];
			for (int i = 0; i < words.length; i++) {
				String s = words[i];
				for (int j = 0; j <= s.length(); j++) {
					int at = indexer.get(hashes[i].hash(0, j));
					if (j != s.length()) {
						to[index] = i;
						next[index] = start[at];
						start[at] = index++;
					}
					if (link[at] == -1) {
						length[at] = j;
						for (int k = 1; k <= j; k++) {
							long key = hashes[i].hash(k, j);
							if (indexer.containsKey(key)) {
								link[at] = indexer.get(key);
								graph.id12(link[at], at);
								break;
							}
						}
						for (int k = 0; k <= j; k++)
							ends[at] += fullWords.get(hashes[i].hash(k, j));
					}
				}
			}
			int[] queue = new int[size];
			int count = 1;
			for (int i = 0; i < count; i++) {
				int current = queue[i];
				for (int j = start[current]; j != -1; j = next[j]) {
					int at = to[j];
					edges[current][words[at].charAt(length[current]) - first] = indexer.get(hashes[at].hash(0, length[current] + 1));
				}
				for (int j = graph.firstOutbound(current); j != -1; j = graph.nextOutbound(j)) {
					int at = graph.destination(j);
					queue[count++] = at;
					System.arraycopy(edges[current], 0, edges[at], 0, last - first + 1);
				}
			}
		}

	}
}

