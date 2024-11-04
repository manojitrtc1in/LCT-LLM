import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class id0 implements id32 {

	private static final id1 ALGO = id39.getInstance();

	public void solve(InputStream is) {
		FastScanner in = new FastScanner(is);
		int n = in.nextInt();
		int m = in.nextInt();
		id12<Long> g = new id12<Long>();
		for (int i : ZeroTo.get(n))
			g.insertVertex(i + 1);
		for (int i : ZeroTo.get(m)) {
			int v1 = in.nextInt();
			int v2 = in.nextInt();
			long w = in.nextInt();
			g.addEdge(v1, v2, w);
			g.addEdge(v2, v1, w);
		}

		id19<Long> r = ALGO.calc(id7.create(g), 1, id40.getInstance());
		if (r.id2(n)) {
			Iterable<id43<Long>> path = r.getPath(n);
			for (id43<Long> e : path) {
				System.out.print(e.from() + " ");
			}
			System.out.println(n);
		} else {
			System.out.println(-1);
		}
	}

	public static void main(String[] args) throws Exception {
		id11.launch(new id8() {
			public id32 create() {
				return new id0();
			}
		}, "A1.txt", "A2.txt", "A3.txt");
	}

}

interface id32 {
	void solve(InputStream is); 
}

interface id8 {
	id32 create();
}

class id11 {

	public static void launch(id8 factory, String... id42) throws FileNotFoundException, IOException {
		if(System.getProperty("ONLINE_JUDGE", "false").equals("true")) {
			factory.create().solve(System.in);
		} else { 
			for(String path : id42) {
				FileInputStream is = new FileInputStream(new File(path));
				factory.create().solve(is);
				is.close();
				System.out.println();
			}
		}
	}

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

class id39 {

	public static id1 getInstance() {
		return new Dijkstra(new id20());
	}
}

class id20 implements HeapFactory {
	
	public <T> Heap<T> create(Comparator<T> comparator) {
		return new BinaryHeap<T>(new EmptyIterable<T>(), comparator);
	}

}

class EmptyIterable<E> implements Iterable<E> {

	public static <E> Iterable<E> create() {
		return new EmptyIterable<E>();
	}

	public Iterator<E> iterator() {
		return new id16<E>() {
			public boolean hasNext() {
				return false;
			}

			public E next() {
				throw new RuntimeException();
			}
		};
	}

}

abstract class id16<T> implements Iterator<T> {
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
			array.id9(new Node(array.size(), v));
		for (int i = array.size() / 2 - 1; i >= 0; i--)
			heapify(i);
	}

	public HeapNode<T> insert(T v) {
		Node node = new Node(array.size(), v);
		array.id9(node);
		id23(node.pos);
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
		id47.swap(array, i, j);
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

	private void id23(int pos) {
		while (pos > 0 && compare(array.get(pos), array.get(pos >> 1)) < 0) {
			swapNode(pos >> 1, pos);
			pos >>= 1;
		}
	}

	private void delete(int pos) {
		id28(pos);
		extractMinimum();
	}

	private void id28(int pos) {
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
			id4();
			return key;
		}

		public void id23(T key) {
			id4();
			this.key = key;
			BinaryHeap.this.id23(pos);
		}

		public void delete() {
			id4();
			BinaryHeap.this.delete(pos);
		}

		private void id4() {
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

class id47 {
	
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
	public void id9(T value) {
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
		return id33.areEqual(this, obj, this);
	}

	public boolean areEqual(Array<T> o1, Array<T> o2) {
		return id38.areEqual(o1, o2);
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
		return id3.toString(this);
	}
	
}

interface EqualityTester<T> {
	boolean areEqual(T o1, T o2);
}

class id38 {

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
			r ^= id37.id6(v.hashCode());
		return r;
	}

}

class id37 {
	
	

	
	public static int id6(int key) {
		key = ~key + (key << 15); 

		key = key ^ (key >>> 12);
		key = key + (key << 2);
		key = key ^ (key >>> 4);
		key = key * 2057; 

		key = key ^ (key >>> 16);
		return key;
	}

	public static int id21(long key) { 
		key = (~key) + (key << 18); 

		key = key ^ (key >>> 31);
		key = key * 21; 

		key = key ^ (key >>> 11);
		key = key + (key << 6);
		key = key ^ (key >>> 22);
		return (int) key;
	}
}

class id3 {
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

class id33 {
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
		return new id16<T>() {
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
	void id23(T newKey);
	void delete();
}

interface HeapFactory {
	<T> Heap<T> create(Comparator<T> comparator);

}

class Dijkstra implements id1 {

	private static final id10 MF = id49.getInstance();

	private HeapFactory factory;

	public Dijkstra(HeapFactory heapFactory) {
		this.factory = heapFactory;
	}

	public <W> id19<W> calc(id24<W> graph, Object start, final id5<W> ns) {
		final MutableMap<Object, W> distance = MF.create();
		MutableMap<Object, id43<W>> previous = MF.create();

		for (Object v : graph.getVertices())
			distance.put(v, null); 

		distance.put(start, ns.getZero());

		Heap<Object> heap = factory.create(new Comparator<Object>() {
			public int compare(Object o1, Object o2) {
				return id48.compare(ns, distance.get(o1), distance.get(o2));
			}
		});

		MutableMap<Object, HeapNode<Object>> node = MF.create();
		for (Object v : graph.getVertices())
			node.put(v, heap.insert(v));

		while (!heap.isEmpty()) {
			Object current = heap.extractMinimum();
			for (id43<W> edge : graph.getEdges(current)) {
				boolean relaxed = Relax.relax(distance, previous, edge, ns);
				if(relaxed)
					node.get(edge.to()).id23(edge.to());
			}
		}

		return id35.create(start, distance, previous);
	}

}

class id49 {

	public static id10 getInstance() {
		return id34.getInstance();
	}

}

class id34 {

	public static id10 getInstance() {
		return new id10() {
			public <K, V> MutableMap<K, V> create() {
				return id46.create(new HashMap<K, V>());
			}
		};
	}

	private id34() {
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

interface id10 {
	<K,V> MutableMap<K,V> create();
}

class id46 {
	
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
				return id31.create(map.entrySet().iterator(), new DataConverter<java.util.Map.Entry<K, V>, MapEntry<K, V>>() {
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
			return id33.areEqual(this, obj, this);
		}
		public boolean areEqual(EntryWrapper<K, V> o1, EntryWrapper<K, V> o2) {
			return o1.getKey().equals(o2.getKey()) && o1.getValue().equals(o2.getValue());
		}
		public int hashCode() {
			return PairHash.hash(getKey().hashCode(), getValue().hashCode());
		}
	}

}

class id31 {

	public static <T1, T2> Iterator<T2> create(final Iterator<T1> original, final DataConverter<T1, T2> converter) {
		return new id16<T2>() {
			public boolean hasNext() {
				return original.hasNext();
			}
			public T2 next() {
				return converter.convert(original.next());
			}
		};
	}

	private id31() {
	}
}

interface DataConverter<T1, T2> {
	T2 convert(T1 v);
}

class PairHash {
	public static int hash(int h1, int h2) {
		return id37.id21((((long) h1) << 32) | h2);
	}
}

interface id24<W> {
	Collection<Object> getVertices();

	Iterable<id43<W>> getEdges(Object from);
}

interface id43<W> extends DirectedEdge {
	W weight();
}

interface DirectedEdge {
	Object from();
	Object to();
}

interface id5<T> extends NumberSystem<T> {
	T add(T v1, T v2);
	T subtract(T id51, T id44);
	T getZero();
	boolean isPositive(T v);
	boolean isZero(T v);
	boolean isNegative(T v);
	int getSign(T v);
}

interface NumberSystem<T> extends EqualityTester<T>, Comparator<T> {

}

class id48 {

	

	public static <W> int compare(final id5<W> ns, W d1, W d2) {
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

	public static <E extends id43<W>, W> boolean relax(MutableMap<Object, W> distance, MutableMap<Object, id43<W>> previous, E edge, id5<W> ns) {
		W fromDistance = distance.get(edge.from());
		if (fromDistance == null)
			return false;

		W oldDistance = distance.get(edge.to());
		W newDistance = ns.add(fromDistance, edge.weight());
		if (id48.compare(ns, oldDistance, newDistance) > 0) {
			distance.put(edge.to(), newDistance);
			previous.put(edge.to(), edge);
			return true;
		}
		return false;
	}

}

interface id1 {
	<W> id19<W> calc(id24<W> graph, Object from, id5<W> ns);
}

interface id19<W> {

	Iterable<id43<W>> getPath(Object to);

	W getDistance(Object to);

	boolean id2(Object to);
}

class id35 {

	public static <W> id19<W> create(final Object start, final Map<Object, W> distance, final Map<Object, id43<W>> previous) {
		return new id19<W>() {
			public W getDistance(Object to) {
				id29(to);
				return distance.get(to);
			}

			public Iterable<id43<W>> getPath(Object to) {
				id29(to);
				LinkedList<id43<W>> r = new LinkedList<id43<W>>();
				for (Object v = to; !v.equals(start); v = previous.get(v).from())
					r.addFirst(previous.get(v));
				return r;
			}

			public boolean id2(Object to) {
				return distance.get(to) != null;
			}

			private void id29(Object to) {
				AssertStatus.assertTrue(id2(to), "Not reachable");
			}
		};
	}

}

class ZeroTo {

	public static Iterable<Integer> get(int end) {
		return id50.create(0, 1, end);
	}
	
}

class id50 {
	public static Iterable<Integer> create(final int from, final int step, final int size) {
		return new Iterable<Integer>() {
			public Iterator<Integer> iterator() {
				return new id16<Integer>() {
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

	private id50() {
	}
}

class id7 {
	public static <W> id24<W> create(final id15<W> g) {
		final MutableMap<Object, DynamicArray<id43<W>>> index = id49.getInstance().create();
		for (Object v : g.getVertices())
			index.put(v, new DynamicArray<id43<W>>());
		for (id43<W> e : g.getEdges())
			index.get(e.from()).id9(e);
		return new id24<W>() {
			public Collection<Object> getVertices() {
				return g.getVertices();
			}

			public Iterable<id43<W>> getEdges(Object from) {
				return index.get(from);
			}
		};
	}
}

interface id15<W> {

	Collection<Object> getVertices();

	Iterable<id43<W>> getEdges();

}

class id12<W> implements id15<W> {

	private MutableSet<Object> vertices = id26.getInstance().create();
	private DynamicArray<id43<W>> edges = DynamicArray.create();

	public void insertVertex(Object v) {
		vertices.insert(v);
	}

	public void addEdge(Object from, Object to, W weight) {
		id45(from);
		id45(to);
		edges.id9(id18.create(from, to, weight));
	}

	private void id45(Object v) {
		AssertStatus.assertTrue(vertices.contains(v), "vertex is not in graph");
	}

	public Collection<Object> getVertices() {
		return vertices;
	}

	public Iterable<id43<W>> getEdges() {
		return edges;
	}

	public String toString() {
		String r = "";
		for (id43<W> e : getEdges()) {
			if (r.length() != 0)
				r += ", ";
			r += e.toString();
		}
		return "Graph: " + r;
	}
}

class id26 {
	public static id36 getInstance() {
		return id30.getInstance();
	}
}

class id30 {

	public static id36 getInstance() {
		return new id36() {
			public <T> MutableSet<T> create() {
				return new id25<T>(new HashSet<T>());
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

interface id36 {
	<T> MutableSet<T> create();
}

class id25<T> implements MutableSet<T> {
	
	private final java.util.Set<T> id22;
	
	public id25(java.util.Set<T> set) {
		this.id22 = set;
	}

	public void clear() {
		id22.clear();		
	}
	
	public boolean contains(T v) {
		return id22.contains(v);		
	}
	
	public void insert(T v) {
		id22.add(v);
	}

	public Iterator<T> iterator() {
		return id22.iterator();
	}
	
	public int size() {
		return id22.size();
	}
	
	public void remove(T v) {
		id22.remove(v);
	}
	
	public boolean isEmpty() {
		return size() == 0;
	}
	
	public String toString() {
		return id3.toString(this);
	}

}

class id18 {

	public static <W> id43<W> create(final Object from, final Object to, final W weight) {
		return new id43<W>() {

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

class id40 implements id27<Long> {

	private static final id40 INSTANCE = new id40();

	public static id40 getInstance() {
		return INSTANCE;
	}

	private id40() {
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
		return id13.checkedAdd(v1, v2);
	}

	public Long subtract(Long id51, Long id44) {
		return id13.checkedSubtract(id51, id44);
	}

	public Long multiply(Long v1, Long v2) {
		return id13.checkedMultiply(v1, v2);
	}

	public Long integerDivide(Long dividend, Long divisor) {
		return Long.valueOf(dividend / divisor);
	}
	
	public Long id14(Long dividend, Long divisor) {
		return Long.valueOf(dividend % divisor);
	}

	public int compare(Long o1, Long o2) {
		return o1.compareTo(o2);
	}

}

class id13 {

	public static long checkedAdd(long a, long b) {
		long result = a + b;
		id17((a ^ b) < 0 | (a ^ result) >= 0);
		return result;
	}

	public static long checkedSubtract(long a, long b) {
		long result = a - b;
		id17((a ^ b) >= 0 | (a ^ result) >= 0);
		return result;
	}

	public static long checkedMultiply(long a, long b) {
		int leadingZeros = Long.numberOfLeadingZeros(a) + Long.numberOfLeadingZeros(~a) + Long.numberOfLeadingZeros(b) + Long.numberOfLeadingZeros(~b);
		if (leadingZeros > Long.SIZE + 1) {
			return a * b;
		}
		id17(leadingZeros >= Long.SIZE);
		id17(a >= 0 | b != Long.MIN_VALUE);
		long result = a * b;
		id17(a == 0 || result / a == b);
		return result;
	}
	
	private static void id17(boolean c) {
		if (!c)
			throw OverflowException.create();
	}

}

class OverflowException {

	public static ArithmeticException create() {
		return new ArithmeticException("Overflow");
	}

}

interface id27<T> extends id41<T>, Comparator<T> {
	T integerDivide(T dividend, T divisor);
	T id14(T dividend, T divisor);
}

interface id41<T> extends id5<T> {
	T multiply(T v1, T v2);
	T getOne();
	boolean isOne(T v);
}

