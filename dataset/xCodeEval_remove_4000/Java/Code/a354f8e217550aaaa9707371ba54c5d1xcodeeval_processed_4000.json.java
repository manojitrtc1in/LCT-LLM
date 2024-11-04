import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class id7 implements Runnable {

	

	private static final id0 ALGO = id36.getInstance();

	public void run() {
		FastScanner in = new FastScanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		id10<Long> g = new id10<Long>();
		for (int i : ZeroTo.get(n))
			g.insertVertex(i + 1);
		for (int i : ZeroTo.get(m)) {
			int v1 = in.nextInt();
			int v2 = in.nextInt();
			long w = in.nextInt();
			g.addEdge(v1, v2, w);
			g.addEdge(v2, v1, w);
		}

		id17<Long> r = ALGO.calc(id6.create(g), 1, id37.getInstance());
		if (r.id1(n)) {
			for (id39<Long> e : r.getPath(n))
				System.out.print(e.from() + " ");
			System.out.println(n);
		} else {
			System.out.println(-1);
		}
	}

	public static void main(String[] args) throws Exception {
		new id7().run();
	}

}

class id36 {

	public static id0 getInstance() {
		return new Dijkstra(new id18());
	}
}

class id18 implements HeapFactory {
	
	public <T> Heap<T> create(Comparator<T> comparator) {
		return new BinaryHeap<T>(new EmptyIterable<T>(), comparator);
	}

}

class EmptyIterable<E> implements Iterable<E> {

	public static <E> Iterable<E> create() {
		return new EmptyIterable<E>();
	}

	public Iterator<E> iterator() {
		return new id14<E>() {
			public boolean hasNext() {
				return false;
			}

			public E next() {
				throw new RuntimeException();
			}
		};
	}

}

abstract class id14<T> implements Iterator<T> {
	public final void remove() {
		throw new UnsupportedOperationException();
	}
}

class BinaryHeap<T> implements Heap<T> {

	private final DynamicArray<Node> array = DynamicArray.create();
	private final Comparator<T> comparator;

	public BinaryHeap(Iterable<T> initialItems, Comparator<T> comparator) {
		this.comparator = comparator;
		for (T v : initialItems)
			array.id8(new Node(array.size(), v));
		for (int i = array.size() / 2 - 1; i >= 0; i--)
			heapify(i);
	}

	public HeapNode<T> insert(T v) {
		Node node = new Node(array.size(), v);
		array.id8(node);
		id21(node.pos);
		return node;
	}

	public T getMinimum() {
		AssertStatus.assertTrue(!isEmpty(), "empty");
		return array.get(0).key;
	}

	public T extractMinimum() {
		AssertStatus.assertTrue(!isEmpty(), "heap is empty");
		swapNode(0, array.size() - 1);
		Node r = array.removeLast();
		heapify(0);
		r.pos = -1;
		return r.key;
	}

	public boolean isEmpty() {
		return array.isEmpty();
	}

	private void swapNode(int i, int j) {
		id43.swap(array, i, j);
		array.get(i).pos = i;
		array.get(j).pos = j;
	}

	private void heapify(int i) {
		int left, right, smallest;
		while (true) {
			left = i << 1;
			right = (i << 1) + 1;
			smallest = i;
			if (left < array.size() && compare(array.get(left), array.get(smallest)) < 0)
				smallest = left;
			if (right < array.size() && compare(array.get(right), array.get(smallest)) < 0)
				smallest = right;
			if (smallest == i)
				break;
			swapNode(smallest, i);
			i = smallest;
		}
	}

	private void id21(int pos) {
		while (pos > 0 && compare(array.get(pos), array.get(pos >> 1)) < 0) {
			swapNode(pos >> 1, pos);
			pos >>= 1;
		}
	}

	private void delete(int pos) {
		id26(pos);
		extractMinimum();
	}

	private void id26(int pos) {
		while (pos > 0) {
			swapNode(pos >> 1, pos);
			pos >>= 1;
		}
	}

	private int compare(Node v1, Node v2) {
		return comparator.compare(v1.getKey(), v2.getKey());
	}

	private class Node implements HeapNode<T> {
		int pos; 

		T key;

		Node(int pos, T key) {
			this.pos = pos;
			this.key = key;
		}

		public T getKey() {
			id3();
			return key;
		}

		public void id21(T key) {
			id3();
			this.key = key;
			BinaryHeap.this.id21(pos);
		}

		public void delete() {
			id3();
			BinaryHeap.this.delete(pos);
		}

		private void id3() {
			AssertStatus.assertTrue(pos != -1, "Node is not in heap (deleted)");
		}
	}

}

class AssertStatus {
	public static void assertTrue(boolean v) {
		assertTrue(v, "");
	}

	public static void assertTrue(boolean v, String message) {
		if (!v)
			throw new RuntimeException(message);
	}
}

class id43 {
	
	public static <T> void swap(MutableArray<T> a, int p1, int p2) {
		T t = a.get(p1);
		a.set(p1, a.get(p2));
		a.set(p2, t);
	}
}

interface MutableArray<T> extends Array<T> {
	void set(int index, T value);	
}

interface Array<T> extends Collection<T> {
	T get(int index);
}

interface Collection<T> extends Iterable<T> {
	int size();
	boolean isEmpty();
}

class DynamicArray<T> implements MutableArray<T>, EqualityTester<Array<T>> {
	
	public static <T> DynamicArray<T> create() {
		return new DynamicArray<T>();
	}
	
	private T[] a;
	private int asize;
	
	@SuppressWarnings("unchecked")
	public DynamicArray() {
		asize = 0;
		a = (T[])new Object[1];
	}

	public T get(int index) {
		return a[index];
	}	
	
	public void set(int index, T value) {
		a[index] = value;		
	}
	
	public int size() {
		return asize;
	}
	
	public void clear() {
		asize = 0;
	}
	
	@SuppressWarnings("unchecked")
	public void reserve(int size) {
		if(a.length < size) {
			T[] na = (T[])new Object[size];
			for(int i=0;i<a.length;i++)
				na[i] = a[i];
			a = na;
		}
	}
	
	@SuppressWarnings("unchecked")
	public void id8(T value) {
		if(a.length == asize) {
			T[] ta = (T[])new Object[asize*2];
			for(int i=0;i<asize;i++)
				ta[i] = a[i];
			a =ta;
		}
		a[asize++] = value;						
	}
	
	public T removeLast() {
		T r = a[asize - 1];
		a[--asize] = null;
		return r;
	}
	
	public boolean equals(Object obj) {
		return id30.areEqual(this, obj, this);
	}

	public boolean areEqual(Array<T> o1, Array<T> o2) {
		return id35.areEqual(o1, o2);
	}

	public int hashCode() {
		return IterableHash.hash(this);
	}

	public final boolean isEmpty() {
		return size() == 0;
	}

	public final Iterator<T> iterator() {
		return ArrayIterator.create(this);
	}

	public final String toString() {
		return id2.toString(this);
	}
	
}

interface EqualityTester<T> {
	boolean areEqual(T o1, T o2);
}

class id35 {

	public static <T> boolean areEqual(Iterable<T> o1, Iterable<T> o2) {
		Iterator<T> iter1 = o1.iterator();
		Iterator<T> iter2 = o2.iterator();
		while (true) {
			if (iter1.hasNext() != iter2.hasNext())
				return false;
			if (!iter1.hasNext())
				return true;
			T v1 = iter1.next();
			T v2 = iter2.next();
			if (!v1.equals(v2))
				return false;
		}
	}

}

class IterableHash {

	public static <T> int hash(Iterable<T> iterable) {
		int r = 0;
		for(T v : iterable)
			r ^= id34.id5(v.hashCode());
		return r;
	}

}

class id34 {
	
	

	
	public static int id5(int key) {
		key = ~key + (key << 15); 

		key = key ^ (key >>> 12);
		key = key + (key << 2);
		key = key ^ (key >>> 4);
		key = key * 2057; 

		key = key ^ (key >>> 16);
		return key;
	}

	public static int id19(long key) { 
		key = (~key) + (key << 18); 

		key = key ^ (key >>> 31);
		key = key * 21; 

		key = key ^ (key >>> 11);
		key = key + (key << 6);
		key = key ^ (key >>> 22);
		return (int) key;
	}
}

class id2 {
	public static <T> String toString(Iterable<T> iterable) {
		StringBuilder sb = new StringBuilder();
		sb.append('(');
		boolean first = true;
		for(T v : iterable) {
			if(first)
				first = false;
			else
				sb.append(',');
			sb.append(v);
		}
		sb.append(')');
		return sb.toString();
	}
}

class id30 {
	@SuppressWarnings("unchecked")
	public static <T> boolean areEqual(T me, Object you, EqualityTester<T> tester) {
		if(me == you)
			return true;
		if(you == null)
			return false;
		if(you.getClass() != me.getClass())
			return false;
		return tester.areEqual(me, (T)you);
	}
}

class ArrayIterator {
	public static <T> Iterator<T> create(final Array<T> a) {
		return new id14<T>() {
			int p = 0;
			public boolean hasNext() {
				return p < a.size();
			}
			public T next() {
				return a.get(p++);
			}
		};
	}

	private ArrayIterator() {
	}
}

interface Heap<T> {
	
	T getMinimum();
	HeapNode<T> insert(T v);
	T extractMinimum();
	boolean isEmpty();
}

interface HeapNode<T> {
	T getKey();
	void id21(T newKey);
	void delete();
}

interface HeapFactory {
	<T> Heap<T> create(Comparator<T> comparator);

}

class Dijkstra implements id0 {

	private static final id9 MF = id45.getInstance();

	private HeapFactory factory;

	public Dijkstra(HeapFactory heapFactory) {
		this.factory = heapFactory;
	}

	public <W> id17<W> calc(id22<W> graph, Object start, final id4<W> ns) {
		final MutableMap<Object, W> distance = MF.create();
		MutableMap<Object, id39<W>> previous = MF.create();

		for (Object v : graph.getVertices())
			distance.put(v, null); 

		distance.put(start, ns.getZero());

		Heap<Object> heap = factory.create(new Comparator<Object>() {
			public int compare(Object o1, Object o2) {
				return id44.compare(ns, distance.get(o1), distance.get(o2));
			}
		});

		MutableMap<Object, HeapNode<Object>> node = MF.create();
		for (Object v : graph.getVertices())
			node.put(v, heap.insert(v));

		while (!heap.isEmpty()) {
			Object current = heap.extractMinimum();
			for (id39<W> edge : graph.getEdges(current)) {
				boolean relaxed = Relax.relax(distance, previous, edge, ns);
				if(relaxed)
					node.get(edge.to()).id21(edge.to());
			}
		}

		return id32.create(start, distance, previous);
	}

}

class id45 {

	public static id9 getInstance() {
		return id31.getInstance();
	}

}

class id31 {

	public static id9 getInstance() {
		return new id9() {
			public <K, V> MutableMap<K, V> create() {
				return id42.create(new HashMap<K, V>());
			}
		};
	}

	private id31() {
	}
}

interface MutableMap<K, V> extends Map<K, V> {
	void clear();

	void put(K key, V value);

	void remove(K key);
}

interface Map<K, V> extends Collection<MapEntry<K, V>> {

	boolean containsKey(K key);

	V get(K key);

	V get(K key, V def);

	Iterable<V> values();

	Iterable<K> keys();
}

interface MapEntry<K, V> {

	K getKey();

	V getValue();

}

interface id9 {
	<K,V> MutableMap<K,V> create();
}

class id42 {
	
	public static <K, V> MutableMap<K, V> create(final java.util.Map<K, V> map) {
		return new MutableMap<K, V>() {

			public boolean containsKey(K key) {
				return map.containsKey(key);
			}

			public V get(K key) {
				AssertStatus.assertTrue(containsKey(key));
				return map.get(key);
			}

			public V get(K key, V def) {
				if (!containsKey(key))
					return def;
				return map.get(key);
			}

			public Iterable<K> keys() {
				return map.keySet();
			}

			public void put(K key, V value) {
				map.put(key, value);
			}

			public Iterable<V> values() {
				return map.values();
			}

			public void clear() {
				map.clear();
			}

			public boolean isEmpty() {
				return map.isEmpty();
			}

			public Iterator<MapEntry<K, V>> iterator() {
				return id29.create(map.entrySet().iterator(), new DataConverter<java.util.Map.Entry<K, V>, MapEntry<K, V>>() {
					public MapEntry<K, V> convert(java.util.Map.Entry<K, V> e) {
						return new EntryWrapper<K, V>(e);
					}
				});
			}

			public int size() {
				return map.size();
			}

			public void remove(K key) {
				map.remove(key);
			}

			public String toString() {
				return map.toString();
			}

		};
	}

	private static class EntryWrapper<K, V> implements MapEntry<K, V>, EqualityTester<EntryWrapper<K, V>> {
		private java.util.Map.Entry<K, V> e;
		private EntryWrapper(java.util.Map.Entry<K, V> e) {
			this.e = e;
		}
		public K getKey() {
			return e.getKey();
		}
		public V getValue() { 
			return e.getValue();
		}
		public boolean equals(Object obj) {
			return id30.areEqual(this, obj, this);
		}
		public boolean areEqual(EntryWrapper<K, V> o1, EntryWrapper<K, V> o2) {
			return o1.getKey().equals(o2.getKey()) && o1.getValue().equals(o2.getValue());
		}
		public int hashCode() {
			return PairHash.hash(getKey().hashCode(), getValue().hashCode());
		}
	}

}

class id29 {

	public static <T1, T2> Iterator<T2> create(final Iterator<T1> original, final DataConverter<T1, T2> converter) {
		return new id14<T2>() {
			public boolean hasNext() {
				return original.hasNext();
			}
			public T2 next() {
				return converter.convert(original.next());
			}
		};
	}

	private id29() {
	}
}

interface DataConverter<T1, T2> {
	T2 convert(T1 v);
}

class PairHash {
	public static int hash(int h1, int h2) {
		return id34.id19((((long) h1) << 32) | h2);
	}
}

interface id22<W> {
	Collection<Object> getVertices();

	Iterable<id39<W>> getEdges(Object from);
}

interface id39<W> extends DirectedEdge {
	W weight();
}

interface DirectedEdge {
	Object from();
	Object to();
}

interface id4<T> extends NumberSystem<T> {
	T add(T v1, T v2);
	T subtract(T id47, T id40);
	T getZero();
	boolean isPositive(T v);
	boolean isZero(T v);
	boolean isNegative(T v);
	int getSign(T v);
}

interface NumberSystem<T> extends EqualityTester<T>, Comparator<T> {

}

class id44 {

	

	public static <W> int compare(final id4<W> ns, W d1, W d2) {
		if(d1 == null && d2 == null)
			return 0;
		if(d1 == null)
			return 1;
		if(d2 == null)
			return -1;
		return ns.compare(d1, d2);
	}

}

class Relax {

	public static <E extends id39<W>, W> boolean relax(MutableMap<Object, W> distance, MutableMap<Object, id39<W>> previous, E edge, id4<W> ns) {
		W fromDistance = distance.get(edge.from());
		if (fromDistance == null)
			return false;

		W oldDistance = distance.get(edge.to());
		W newDistance = ns.add(fromDistance, edge.weight());
		if (id44.compare(ns, oldDistance, newDistance) > 0) {
			distance.put(edge.to(), newDistance);
			previous.put(edge.to(), edge);
			return true;
		}
		return false;
	}

}

interface id0 {
	<W> id17<W> calc(id22<W> graph, Object from, id4<W> ns);
}

interface id17<W> {

	Iterable<id39<W>> getPath(Object to);

	W getDistance(Object to);

	boolean id1(Object to);
}

class id32 {

	public static <W> id17<W> create(final Object start, final Map<Object, W> distance, final Map<Object, id39<W>> previous) {
		return new id17<W>() {
			public W getDistance(Object to) {
				id27(to);
				return distance.get(to);
			}

			public Iterable<id39<W>> getPath(Object to) {
				id27(to);
				LinkedList<id39<W>> r = new LinkedList<id39<W>>();
				for (Object v = to; !v.equals(start); v = previous.get(v).from())
					r.addFirst(previous.get(v));
				return r;
			}

			public boolean id1(Object to) {
				return distance.get(to) != null;
			}

			private void id27(Object to) {
				AssertStatus.assertTrue(id1(to), "Not reachable");
			}
		};
	}

}

class ZeroTo {

	public static Iterable<Integer> get(int end) {
		return id46.create(0, 1, end);
	}
	
}

class id46 {
	public static Iterable<Integer> create(final int from, final int step, final int size) {
		return new Iterable<Integer>() {
			public Iterator<Integer> iterator() {
				return new id14<Integer>() {
					int nextIndex = 0;
					public boolean hasNext() {
						return nextIndex < size;
					}
					public Integer next() {
						return from + step * (nextIndex++);
					}
				};
			}
		};
	}

	private id46() {
	}
}

class id6 {
	public static <W> id22<W> create(final id13<W> g) {
		final MutableMap<Object, DynamicArray<id39<W>>> index = id45.getInstance().create();
		for (Object v : g.getVertices())
			index.put(v, new DynamicArray<id39<W>>());
		for (id39<W> e : g.getEdges())
			index.get(e.from()).id8(e);
		return new id22<W>() {
			public Collection<Object> getVertices() {
				return g.getVertices();
			}

			public Iterable<id39<W>> getEdges(Object from) {
				return index.get(from);
			}
		};
	}
}

interface id13<W> {

	Collection<Object> getVertices();

	Iterable<id39<W>> getEdges();

}

class id10<W> implements id13<W> {

	private MutableSet<Object> vertices = id24.getInstance().create();
	private DynamicArray<id39<W>> edges = DynamicArray.create();

	public void insertVertex(Object v) {
		vertices.insert(v);
	}

	public void addEdge(Object from, Object to, W weight) {
		id41(from);
		id41(to);
		edges.id8(id16.create(from, to, weight));
	}

	private void id41(Object v) {
		AssertStatus.assertTrue(vertices.contains(v), "vertex is not in graph");
	}

	public Collection<Object> getVertices() {
		return vertices;
	}

	public Iterable<id39<W>> getEdges() {
		return edges;
	}

	public String toString() {
		String r = "";
		for (id39<W> e : getEdges()) {
			if (r.length() != 0)
				r += ", ";
			r += e.toString();
		}
		return "Graph: " + r;
	}
}

class id24 {
	public static id33 getInstance() {
		return id28.getInstance();
	}
}

class id28 {

	public static id33 getInstance() {
		return new id33() {
			public <T> MutableSet<T> create() {
				return new id23<T>(new HashSet<T>());
			}
		};
	}

}

interface MutableSet<T> extends Set<T> {
	void clear();
	void insert(T v);
	void remove(T v);
}

interface Set<T> extends Collection<T> {
	boolean contains(T v);
}

interface id33 {
	<T> MutableSet<T> create();
}

class id23<T> implements MutableSet<T> {
	
	private final java.util.Set<T> id20;
	
	public id23(java.util.Set<T> set) {
		this.id20 = set;
	}

	public void clear() {
		id20.clear();		
	}
	
	public boolean contains(T v) {
		return id20.contains(v);		
	}
	
	public void insert(T v) {
		id20.add(v);
	}

	public Iterator<T> iterator() {
		return id20.iterator();
	}
	
	public int size() {
		return id20.size();
	}
	
	public void remove(T v) {
		id20.remove(v);
	}
	
	public boolean isEmpty() {
		return size() == 0;
	}
	
	public String toString() {
		return id2.toString(this);
	}

}

class id16 {

	public static <W> id39<W> create(final Object from, final Object to, final W weight) {
		return new id39<W>() {

			public Object from() {
				return from;
			}

			public Object to() {
				return to;
			}

			public W weight() {
				return weight;
			}

			public String toString() {
				if (weight != null)
					return to + "(" + weight + ")";
				else
					return to + "";
			}
		};
	}

}

class id37 implements id25<Long> {

	private static final id37 INSTANCE = new id37();

	public static id37 getInstance() {
		return INSTANCE;
	}

	private id37() {
	}

	public Long getZero() {
		return 0L;
	}

	public boolean isPositive(Long v) {
		return v > 0;
	}

	public boolean isZero(Long v) {
		return v == 0;
	}

	public boolean isNegative(Long v) {
		return v < 0;
	}

	public int getSign(Long v) {
		return Long.signum(v);
	}
	
	public boolean areEqual(Long o1, Long o2) {
		return o1.equals(o2);
	}

	public Long getOne() {
		return Long.valueOf(1);
	}

	public boolean isOne(Long v) {
		return v == 1;
	}
	
	public Long add(Long v1, Long v2) {
		return id11.checkedAdd(v1, v2);
	}

	public Long subtract(Long id47, Long id40) {
		return id11.checkedSubtract(id47, id40);
	}

	public Long multiply(Long v1, Long v2) {
		return id11.checkedMultiply(v1, v2);
	}

	public Long integerDivide(Long dividend, Long divisor) {
		return Long.valueOf(dividend / divisor);
	}
	
	public Long id12(Long dividend, Long divisor) {
		return Long.valueOf(dividend % divisor);
	}

	public int compare(Long o1, Long o2) {
		return o1.compareTo(o2);
	}

}

class id11 {

	public static long checkedAdd(long a, long b) {
		long result = a + b;
		id15((a ^ b) < 0 | (a ^ result) >= 0);
		return result;
	}

	public static long checkedSubtract(long a, long b) {
		long result = a - b;
		id15((a ^ b) >= 0 | (a ^ result) >= 0);
		return result;
	}

	public static long checkedMultiply(long a, long b) {
		int leadingZeros = Long.numberOfLeadingZeros(a) + Long.numberOfLeadingZeros(~a) + Long.numberOfLeadingZeros(b) + Long.numberOfLeadingZeros(~b);
		if (leadingZeros > Long.SIZE + 1) {
			return a * b;
		}
		id15(leadingZeros >= Long.SIZE);
		id15(a >= 0 | b != Long.MIN_VALUE);
		long result = a * b;
		id15(a == 0 || result / a == b);
		return result;
	}
	
	private static void id15(boolean c) {
		if (!c)
			throw OverflowException.create();
	}

}

class OverflowException {

	public static ArithmeticException create() {
		return new ArithmeticException("Overflow");
	}

}

interface id25<T> extends id38<T>, Comparator<T> {
	T integerDivide(T dividend, T divisor);
	T id12(T dividend, T divisor);
}

interface id38<T> extends id4<T> {
	T multiply(T v1, T v2);
	T getOne();
	boolean isOne(T v);
}

class FastScanner {
	
	private StringTokenizer tokenizer;

	public FastScanner(InputStream is) {
		try {
			ByteArrayOutputStream bos = new ByteArrayOutputStream(1024*1024);
			byte[] buf = new byte[1024];
			while(true) {
				int read = is.read(buf);
				if(read == -1)
					break;
				bos.write(buf, 0, read);
			}
			tokenizer = new StringTokenizer(new String(bos.toByteArray()));
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}
	
	public int nextInt() {
		return Integer.parseInt(tokenizer.nextToken());
	}
	
	public long nextLong() {
		return Long.parseLong(tokenizer.nextToken());
	}
	
	public double nextDouble() {
		return Double.parseDouble(tokenizer.nextToken());
	}
	
	public String next() {
		return tokenizer.nextToken();
	}

}

