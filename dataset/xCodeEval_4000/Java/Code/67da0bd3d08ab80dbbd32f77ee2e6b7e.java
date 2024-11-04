import java.io.BufferedInputStream;
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

public class CodeForcesAlphaRound20CDijkstra implements Runnable {

	

	private static final SingleSourceShortestPath ALGO = GoodSingleSourceShortestPath.getInstance();

	public void run() {
		FastScanner in = new FastScanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		MutableDirectedWeightedGraph<Long> g = new MutableDirectedWeightedGraph<Long>();
		for (int i : ZeroTo.get(n))
			g.insertVertex(i + 1);
		for (int i : ZeroTo.get(m)) {
			int v1 = in.nextInt();
			int v2 = in.nextInt();
			long w = in.nextInt();
			g.addEdge(v1, v2, w);
			g.addEdge(v2, v1, w);
		}

		SingleSourceShortestPathResult<Long> r = ALGO.calc(AdjacencyListableDirectedWeightedGraphFactory.create(g), 1, LongNumberSystem.getInstance());
		if (r.isReachable(n)) {
			for (DirectedWeightedEdge<Long> e : r.getPath(n))
				System.out.print(e.from() + " ");
			System.out.println(n);
		} else {
			System.out.println(-1);
		}
	}

	public static void main(String[] args) throws Exception {
		CodeforcesSolverLauncher.launch(new CodeforcesSolverFactory() {
			public Runnable create() {
				return new CodeForcesAlphaRound20CDijkstra();
			}
		}, "A1.txt", "A2.txt", "A3.txt");
	}

}

interface CodeforcesSolverFactory {
	Runnable create();
}

class CodeforcesSolverLauncher {

	public static void launch(CodeforcesSolverFactory factory, String... inputFilePath) throws FileNotFoundException, IOException {
		if (System.getProperty("ONLINE_JUDGE", "false").equals("true")) {
			factory.create().run();
		} else {
			for (String path : inputFilePath) {
				FileInputStream is = new FileInputStream(new File(path));
				System.setIn(new BufferedInputStream(is));
				factory.create().run();
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

class GoodSingleSourceShortestPath {

	public static SingleSourceShortestPath getInstance() {
		return new Dijkstra(new BinaryHeapFactory());
	}
}

class BinaryHeapFactory implements HeapFactory {
	
	public <T> Heap<T> create(Comparator<T> comparator) {
		return new BinaryHeap<T>(new EmptyIterable<T>(), comparator);
	}

}

class EmptyIterable<E> implements Iterable<E> {

	public static <E> Iterable<E> create() {
		return new EmptyIterable<E>();
	}

	public Iterator<E> iterator() {
		return new ReadOnlyIterator<E>() {
			public boolean hasNext() {
				return false;
			}

			public E next() {
				throw new RuntimeException();
			}
		};
	}

}

abstract class ReadOnlyIterator<T> implements Iterator<T> {
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
			array.addToLast(new Node(array.size(), v));
		for (int i = array.size() / 2 - 1; i >= 0; i--)
			heapify(i);
	}

	public HeapNode<T> insert(T v) {
		Node node = new Node(array.size(), v);
		array.addToLast(node);
		decreaseKey(node.pos);
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
		ArraySwapper.swap(array, i, j);
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

	private void decreaseKey(int pos) {
		while (pos > 0 && compare(array.get(pos), array.get(pos >> 1)) < 0) {
			swapNode(pos >> 1, pos);
			pos >>= 1;
		}
	}

	private void delete(int pos) {
		forceToRoot(pos);
		extractMinimum();
	}

	private void forceToRoot(int pos) {
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
			assertNotDeleted();
			return key;
		}

		public void decreaseKey(T key) {
			assertNotDeleted();
			this.key = key;
			BinaryHeap.this.decreaseKey(pos);
		}

		public void delete() {
			assertNotDeleted();
			BinaryHeap.this.delete(pos);
		}

		private void assertNotDeleted() {
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

class ArraySwapper {
	
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
	public void addToLast(T value) {
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
		return StrictEqualityTester.areEqual(this, obj, this);
	}

	public boolean areEqual(Array<T> o1, Array<T> o2) {
		return IterableEqualityTester.areEqual(o1, o2);
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
		return IterableToString.toString(this);
	}
	
}

interface EqualityTester<T> {
	boolean areEqual(T o1, T o2);
}

class IterableEqualityTester {

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
			r ^= ThomasWangHash.hash32bit(v.hashCode());
		return r;
	}

}

class ThomasWangHash {
	
	

	
	public static int hash32bit(int key) {
		key = ~key + (key << 15); 

		key = key ^ (key >>> 12);
		key = key + (key << 2);
		key = key ^ (key >>> 4);
		key = key * 2057; 

		key = key ^ (key >>> 16);
		return key;
	}

	public static int hash64bit(long key) { 
		key = (~key) + (key << 18); 

		key = key ^ (key >>> 31);
		key = key * 21; 

		key = key ^ (key >>> 11);
		key = key + (key << 6);
		key = key ^ (key >>> 22);
		return (int) key;
	}
}

class IterableToString {
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

class StrictEqualityTester {
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
		return new ReadOnlyIterator<T>() {
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
	void decreaseKey(T newKey);
	void delete();
}

interface HeapFactory {
	<T> Heap<T> create(Comparator<T> comparator);

}

class Dijkstra implements SingleSourceShortestPath {

	private static final MutableMapFactory MF = GoodMutableMapFactory.getInstance();

	private HeapFactory factory;

	public Dijkstra(HeapFactory heapFactory) {
		this.factory = heapFactory;
	}

	public <W> SingleSourceShortestPathResult<W> calc(AdjacencyListableDirectedWeightedGraph<W> graph, Object start, final AddableNumberSystem<W> ns) {
		final MutableMap<Object, W> distance = MF.create();
		MutableMap<Object, DirectedWeightedEdge<W>> previous = MF.create();

		for (Object v : graph.getVertices())
			distance.put(v, null); 

		distance.put(start, ns.getZero());

		Heap<Object> heap = factory.create(new Comparator<Object>() {
			public int compare(Object o1, Object o2) {
				return NullableDistanceCompare.compare(ns, distance.get(o1), distance.get(o2));
			}
		});

		MutableMap<Object, HeapNode<Object>> node = MF.create();
		for (Object v : graph.getVertices())
			node.put(v, heap.insert(v));

		while (!heap.isEmpty()) {
			Object current = heap.extractMinimum();
			for (DirectedWeightedEdge<W> edge : graph.getEdges(current)) {
				boolean relaxed = Relax.relax(distance, previous, edge, ns);
				if(relaxed)
					node.get(edge.to()).decreaseKey(edge.to());
			}
		}

		return SingleSourceShortestPathResultFactory.create(start, distance, previous);
	}

}

class GoodMutableMapFactory {

	public static MutableMapFactory getInstance() {
		return JavaHashMapFactory.getInstance();
	}

}

class JavaHashMapFactory {

	public static MutableMapFactory getInstance() {
		return new MutableMapFactory() {
			public <K, V> MutableMap<K, V> create() {
				return MutableMapUsingJavaMap.create(new HashMap<K, V>());
			}
		};
	}

	private JavaHashMapFactory() {
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

interface MutableMapFactory {
	<K,V> MutableMap<K,V> create();
}

class MutableMapUsingJavaMap {
	
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
				return ConvertedDataIterator.create(map.entrySet().iterator(), new DataConverter<java.util.Map.Entry<K, V>, MapEntry<K, V>>() {
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
			return StrictEqualityTester.areEqual(this, obj, this);
		}
		public boolean areEqual(EntryWrapper<K, V> o1, EntryWrapper<K, V> o2) {
			return o1.getKey().equals(o2.getKey()) && o1.getValue().equals(o2.getValue());
		}
		public int hashCode() {
			return PairHash.hash(getKey().hashCode(), getValue().hashCode());
		}
	}

}

class ConvertedDataIterator {

	public static <T1, T2> Iterator<T2> create(final Iterator<T1> original, final DataConverter<T1, T2> converter) {
		return new ReadOnlyIterator<T2>() {
			public boolean hasNext() {
				return original.hasNext();
			}
			public T2 next() {
				return converter.convert(original.next());
			}
		};
	}

	private ConvertedDataIterator() {
	}
}

interface DataConverter<T1, T2> {
	T2 convert(T1 v);
}

class PairHash {
	public static int hash(int h1, int h2) {
		return ThomasWangHash.hash64bit((((long) h1) << 32) | h2);
	}
}

interface AdjacencyListableDirectedWeightedGraph<W> {
	Collection<Object> getVertices();

	Iterable<DirectedWeightedEdge<W>> getEdges(Object from);
}

interface DirectedWeightedEdge<W> extends DirectedEdge {
	W weight();
}

interface DirectedEdge {
	Object from();
	Object to();
}

interface AddableNumberSystem<T> extends NumberSystem<T> {
	T add(T v1, T v2);
	T subtract(T minuend, T subtrahend);
	T getZero();
	boolean isPositive(T v);
	boolean isZero(T v);
	boolean isNegative(T v);
	int getSign(T v);
}

interface NumberSystem<T> extends EqualityTester<T>, Comparator<T> {

}

class NullableDistanceCompare {

	

	public static <W> int compare(final AddableNumberSystem<W> ns, W d1, W d2) {
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

	public static <E extends DirectedWeightedEdge<W>, W> boolean relax(MutableMap<Object, W> distance, MutableMap<Object, DirectedWeightedEdge<W>> previous, E edge, AddableNumberSystem<W> ns) {
		W fromDistance = distance.get(edge.from());
		if (fromDistance == null)
			return false;

		W oldDistance = distance.get(edge.to());
		W newDistance = ns.add(fromDistance, edge.weight());
		if (NullableDistanceCompare.compare(ns, oldDistance, newDistance) > 0) {
			distance.put(edge.to(), newDistance);
			previous.put(edge.to(), edge);
			return true;
		}
		return false;
	}

}

interface SingleSourceShortestPath {
	<W> SingleSourceShortestPathResult<W> calc(AdjacencyListableDirectedWeightedGraph<W> graph, Object from, AddableNumberSystem<W> ns);
}

interface SingleSourceShortestPathResult<W> {

	Iterable<DirectedWeightedEdge<W>> getPath(Object to);

	W getDistance(Object to);

	boolean isReachable(Object to);
}

class SingleSourceShortestPathResultFactory {

	public static <W> SingleSourceShortestPathResult<W> create(final Object start, final Map<Object, W> distance, final Map<Object, DirectedWeightedEdge<W>> previous) {
		return new SingleSourceShortestPathResult<W>() {
			public W getDistance(Object to) {
				assertReachable(to);
				return distance.get(to);
			}

			public Iterable<DirectedWeightedEdge<W>> getPath(Object to) {
				assertReachable(to);
				LinkedList<DirectedWeightedEdge<W>> r = new LinkedList<DirectedWeightedEdge<W>>();
				for (Object v = to; !v.equals(start); v = previous.get(v).from())
					r.addFirst(previous.get(v));
				return r;
			}

			public boolean isReachable(Object to) {
				return distance.get(to) != null;
			}

			private void assertReachable(Object to) {
				AssertStatus.assertTrue(isReachable(to), "Not reachable");
			}
		};
	}

}

class ZeroTo {

	public static Iterable<Integer> get(int end) {
		return IntSequenceIterable.create(0, 1, end);
	}
	
}

class IntSequenceIterable {
	public static Iterable<Integer> create(final int from, final int step, final int size) {
		return new Iterable<Integer>() {
			public Iterator<Integer> iterator() {
				return new ReadOnlyIterator<Integer>() {
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

	private IntSequenceIterable() {
	}
}

class AdjacencyListableDirectedWeightedGraphFactory {
	public static <W> AdjacencyListableDirectedWeightedGraph<W> create(final DirectedWeightedGraph<W> g) {
		final MutableMap<Object, DynamicArray<DirectedWeightedEdge<W>>> index = GoodMutableMapFactory.getInstance().create();
		for (Object v : g.getVertices())
			index.put(v, new DynamicArray<DirectedWeightedEdge<W>>());
		for (DirectedWeightedEdge<W> e : g.getEdges())
			index.get(e.from()).addToLast(e);
		return new AdjacencyListableDirectedWeightedGraph<W>() {
			public Collection<Object> getVertices() {
				return g.getVertices();
			}

			public Iterable<DirectedWeightedEdge<W>> getEdges(Object from) {
				return index.get(from);
			}
		};
	}
}

interface DirectedWeightedGraph<W> {

	Collection<Object> getVertices();

	Iterable<DirectedWeightedEdge<W>> getEdges();

}

class MutableDirectedWeightedGraph<W> implements DirectedWeightedGraph<W> {

	private MutableSet<Object> vertices = GoodMutableSetFactory.getInstance().create();
	private DynamicArray<DirectedWeightedEdge<W>> edges = DynamicArray.create();

	public void insertVertex(Object v) {
		vertices.insert(v);
	}

	public void addEdge(Object from, Object to, W weight) {
		assertVertexExist(from);
		assertVertexExist(to);
		edges.addToLast(DirectedWeightedEdgeFactory.create(from, to, weight));
	}

	private void assertVertexExist(Object v) {
		AssertStatus.assertTrue(vertices.contains(v), "vertex is not in graph");
	}

	public Collection<Object> getVertices() {
		return vertices;
	}

	public Iterable<DirectedWeightedEdge<W>> getEdges() {
		return edges;
	}

	public String toString() {
		String r = "";
		for (DirectedWeightedEdge<W> e : getEdges()) {
			if (r.length() != 0)
				r += ", ";
			r += e.toString();
		}
		return "Graph: " + r;
	}
}

class GoodMutableSetFactory {
	public static MutableSetFactory getInstance() {
		return JavaHashSetFactory.getInstance();
	}
}

class JavaHashSetFactory {

	public static MutableSetFactory getInstance() {
		return new MutableSetFactory() {
			public <T> MutableSet<T> create() {
				return new MutableSetUsingJavaSet<T>(new HashSet<T>());
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

interface MutableSetFactory {
	<T> MutableSet<T> create();
}

class MutableSetUsingJavaSet<T> implements MutableSet<T> {
	
	private final java.util.Set<T> javaset;
	
	public MutableSetUsingJavaSet(java.util.Set<T> set) {
		this.javaset = set;
	}

	public void clear() {
		javaset.clear();		
	}
	
	public boolean contains(T v) {
		return javaset.contains(v);		
	}
	
	public void insert(T v) {
		javaset.add(v);
	}

	public Iterator<T> iterator() {
		return javaset.iterator();
	}
	
	public int size() {
		return javaset.size();
	}
	
	public void remove(T v) {
		javaset.remove(v);
	}
	
	public boolean isEmpty() {
		return size() == 0;
	}
	
	public String toString() {
		return IterableToString.toString(this);
	}

}

class DirectedWeightedEdgeFactory {

	public static <W> DirectedWeightedEdge<W> create(final Object from, final Object to, final W weight) {
		return new DirectedWeightedEdge<W>() {

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

class LongNumberSystem implements IntegerDivisableNumberSystem<Long> {

	private static final LongNumberSystem INSTANCE = new LongNumberSystem();

	public static LongNumberSystem getInstance() {
		return INSTANCE;
	}

	private LongNumberSystem() {
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
		return GuavasLongMath.checkedAdd(v1, v2);
	}

	public Long subtract(Long minuend, Long subtrahend) {
		return GuavasLongMath.checkedSubtract(minuend, subtrahend);
	}

	public Long multiply(Long v1, Long v2) {
		return GuavasLongMath.checkedMultiply(v1, v2);
	}

	public Long integerDivide(Long dividend, Long divisor) {
		return Long.valueOf(dividend / divisor);
	}
	
	public Long integerRemainder(Long dividend, Long divisor) {
		return Long.valueOf(dividend % divisor);
	}

	public int compare(Long o1, Long o2) {
		return o1.compareTo(o2);
	}

}

class GuavasLongMath {

	public static long checkedAdd(long a, long b) {
		long result = a + b;
		assertOverflowCondition((a ^ b) < 0 | (a ^ result) >= 0);
		return result;
	}

	public static long checkedSubtract(long a, long b) {
		long result = a - b;
		assertOverflowCondition((a ^ b) >= 0 | (a ^ result) >= 0);
		return result;
	}

	public static long checkedMultiply(long a, long b) {
		int leadingZeros = Long.numberOfLeadingZeros(a) + Long.numberOfLeadingZeros(~a) + Long.numberOfLeadingZeros(b) + Long.numberOfLeadingZeros(~b);
		if (leadingZeros > Long.SIZE + 1) {
			return a * b;
		}
		assertOverflowCondition(leadingZeros >= Long.SIZE);
		assertOverflowCondition(a >= 0 | b != Long.MIN_VALUE);
		long result = a * b;
		assertOverflowCondition(a == 0 || result / a == b);
		return result;
	}
	
	private static void assertOverflowCondition(boolean c) {
		if (!c)
			throw OverflowException.create();
	}

}

class OverflowException {

	public static ArithmeticException create() {
		return new ArithmeticException("Overflow");
	}

}

interface IntegerDivisableNumberSystem<T> extends MultipliableNumberSystem<T>, Comparator<T> {
	T integerDivide(T dividend, T divisor);
	T integerRemainder(T dividend, T divisor);
}

interface MultipliableNumberSystem<T> extends AddableNumberSystem<T> {
	T multiply(T v1, T v2);
	T getOne();
	boolean isOne(T v);
}

