import java.io.BufferedInputStream;
import java.io.ByteArrayOutputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.StringTokenizer;

public class Subway implements Runnable {

	public void run() {
		FastScanner in = new FastScanner(new BufferedInputStream(System.in));
		int n = in.nextInt();
		final MutableUndirectedGraph<Integer> udg = MutableUndirectedGraph.create();
		for (int i : ZeroTo.get(n))
			udg.insertVertex(i + 1);
		for (int i : ZeroTo.get(n)) {
			int v1 = in.nextInt();
			int v2 = in.nextInt();
			udg.addEdge(v1, v2);
		}

		


		final DynamicArray<Integer> path = DynamicArray.create();
		final MutableSet<Integer> cycle = GoodMutableSetFactory.getInstance().create();
		AllSourceDFS.traverse(DirectedGraphFromUndirected.wrap(udg), new DFSVisitor<Integer, DirectedEdge<Integer>>() {
			public void onBackEdgeFound(DirectedEdge<Integer> edge) {
				if (cycle.isEmpty() && !edge.to().equals(path.get(path.size() - 2))) {
					int pos = search(path, edge.to(), -1);
					InsertAllToSet.insertAll(cycle, SubArray.wrap(path, pos, path.size()));
				}
			}

			public void onDiscovered(Integer vertex, int depth) {
				path.addToLast(vertex);
			}

			public void onFinish(Integer vertex, int depth) {
				path.removeLast();
			}

			public void onWalkDown(DirectedEdge<Integer> edge) {
			}

			public void onWalkUp(DirectedEdge<Integer> downedEdge) {
			}
		});

		final DataFilter<UndirectedEdge<Integer>> filter = new DataFilter<UndirectedEdge<Integer>>() {
			public boolean isAccepted(UndirectedEdge<Integer> v) {
				return !(cycle.contains(v.v1()) && cycle.contains(v.v2()));
			}
		};

		Graph<Integer, UndirectedEdge<Integer>> cycleRemoved = new Graph<Integer, UndirectedEdge<Integer>>() {
			public Collection<Integer> getVertices() {
				return udg.getVertices();
			}

			public Iterable<UndirectedEdge<Integer>> getEdges() {
				return FilteredIterable.create(udg.getEdges(), filter);
			}
		};

		final MutableMap<Integer, Integer> depthMap = GoodMutableMapFactory.getInstance().create();

		MultiSourceDFS.traverse(DirectedGraphFromUndirected.wrap(cycleRemoved), new DFSVisitor<Integer, DirectedEdge<Integer>>() {
			public void onBackEdgeFound(DirectedEdge<Integer> edge) {
			}

			public void onDiscovered(Integer vertex, int depth) {
				depthMap.put(vertex, depth);
			}

			public void onFinish(Integer vertex, int depth) {
			}

			public void onWalkDown(DirectedEdge<Integer> edge) {
			}

			public void onWalkUp(DirectedEdge<Integer> downedEdge) {
			}
		}, cycle);

		for (int i : ZeroTo.get(n))
			System.out.print(depthMap.get(i + 1) + " ");
		System.out.println();
	}

	public static int search(final DynamicArray<Integer> array, Integer value, int def) {
		for (int i = 0; i < array.size(); i++)
			if (array.get(i).equals(value))
				return i;
		return def;
	}

	public static void main(String[] args) throws Exception {
		if (args.length >= 1)
			System.setIn(new FileInputStream(args[0]));
		new Subway().run();
	}

}

interface Collection<T> extends Iterable<T> {
	int size();
	boolean isEmpty();
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
				V r = map.get(key);
				if (r != null) {
					return r;
				} else { 

					AssertStatus.assertTrue(containsKey(key), "the key in not int the map");
					return null;
				}
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

class AssertStatus {
	public static void assertTrue(boolean v) {
		assertTrue(v, "");
	}

	public static void assertTrue(boolean v, String message) {
		if (!v)
			throw new RuntimeException(message);
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

abstract class ReadOnlyIterator<T> implements Iterator<T> {
	public final void remove() {
		throw new UnsupportedOperationException();
	}
}

interface EqualityTester<T> {
	boolean areEqual(T o1, T o2);
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

class PairHash {
	public static int hash(int h1, int h2) {
		return ThomasWangHash.hash64bit((((long) h1) << 32) | h2);
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

class IterableToString {
	public static <T> String toString(Iterable<T> iterable) {
		StringBuilder sb = new StringBuilder();
		boolean first = true;
		for(T v : iterable) {
			if(first)
				first = false;
			else
				sb.append(',');
			sb.append(v);
		}
		return sb.toString();
	}
}

interface DataFilter<T> {
	boolean isAccepted(T v);
}

class FilteredIterable {

	public static <T> Iterable<T> create(final Iterable<? extends T> original, final DataFilter<T> filter) {
		return new Iterable<T>() {
			public Iterator<T> iterator() {
				return FilteredIterator.create(original.iterator(), filter);
			}
		};
	}

	private FilteredIterable() {
	}

}

class FilteredIterator {

	public static <T> Iterator<T> create(final Iterator<? extends T> a, final DataFilter<T> filter) {
		return new ReadOnlyIterator<T>() {
			T next = null;
			Iterator<? extends T> cursor = a;

			public boolean hasNext() {
				tryToStepNext();
				return next != null;
			}

			public T next() {
				tryToStepNext();
				T r = next;
				next = null;
				return r;
			}

			private void tryToStepNext() {
				if (next == null) {
					while (cursor.hasNext()) {
						T value = cursor.next();
						if (filter.isAccepted(value)) {
							next = value;
							break;
						}
					}
				}
			}

		};
	}

	private FilteredIterator() {
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
				return IntSequenceIterator.create(from, step, size);
			}
		};
	}

	private IntSequenceIterable() {
	}
}

class IntSequenceIterator {

	public static Iterator<Integer> create(final int start, final int step, final int size) {
		return new ReadOnlyIterator<Integer>() {
			int nextIndex = 0;
	
			public boolean hasNext() {
				return nextIndex < size;
			}
	
			public Integer next() {
				return start + step * (nextIndex++);
			}
		};
	}

	private IntSequenceIterator() {
	}

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
		return asize == 0;
	}

	public final Iterator<T> iterator() {
		return ArrayIterator.create(this);
	}

	public final String toString() {
		return IterableToString.toString(this);
	}
	
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

interface Array<T> extends Collection<T> {
	T get(int index);
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

interface MutableArray<T> extends Array<T> {
	void set(int index, T value);	
}

class SubArray {

	public static <T> Array<T> wrap(final Array<T> original, final int start, final int end) {
		return new Array<T>() {
			public T get(int index) {
				return original.get(start + index);
			}

			public int size() {
				return end - start;
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
		};
	}

}

interface DirectedEdge<V> { 

	V from();

	V to();
}

class MutableGraph<V, E> implements Graph<V, E> {

	public static <V, E> MutableGraph<V, E> create() {
		return new MutableGraph<V, E>();
	}

	private MutableSet<V> vertices = GoodMutableSetFactory.getInstance().create();
	private DynamicArray<E> edges = DynamicArray.create();

	public void insertVertex(V v) {
		vertices.insert(v);
	}

	public void addEdge(E edge) {
		edges.addToLast(edge);
	}

	public Set<V> getVertices() {
		return vertices;
	}

	public Iterable<E> getEdges() {
		return edges;
	}

	public String toString() {
		return GraphToString.toString(this);
	}

}

interface Graph<V, E> {
	Collection<V> getVertices();

	Iterable<E> getEdges();
}

class GraphToString {

	public static <V, E> String toString(Graph<V, E> g) {
		String r = "";
		for (E e : g.getEdges()) {
			if (r.length() != 0)
				r += ", ";
			r += e.toString();
		}
		return "Graph({" + IterableToString.toString(g.getVertices()) + "},{" + IterableToString.toString(g.getEdges()) + "})";
	}

}

class DirectedGraphFromUndirected {

	public static <V, E extends UndirectedEdge<V>> Graph<V, DirectedEdge<V>> wrap(final Graph<V, E> original) {
		return EdgeDoubledGraph.wrap(original, new DataConverter<E, DirectedEdge<V>>() {
			public DirectedEdge<V> convert(E original) {
				return DirectedEdgeFactory.create(original.v1(), original.v2());
			}
		}, new DataConverter<E, DirectedEdge<V>>() {
			public DirectedEdge<V> convert(E original) {
				return DirectedEdgeFactory.create(original.v2(), original.v1());
			}
		});
	}

}

class DirectedEdgeFactory {

	public static <V> DirectedEdge<V> create(final V from, final V to) {
		return new DirectedEdge<V>() {
			public V to() {
				return to;
			}

			public V from() {
				return from;
			}

			public String toString() {
				return to + "->" + from;
			}
		};
	}

}

class EdgeDoubledGraph {

	public static <V, W, E1, E2> Graph<V, E2> wrap(final Graph<V, E1> original, final DataConverter<E1, E2> direction1Converter, final DataConverter<E1, E2> direction2Converter) {
		return new Graph<V, E2>() {
			public Collection<V> getVertices() {
				return original.getVertices();
			}
	
			@SuppressWarnings("unchecked")
			public Iterable<E2> getEdges() {
				return MergedIterable.wrap(VarargsIterable.create(ConvertedDataIterable.create(original.getEdges(), direction1Converter), ConvertedDataIterable.create(original.getEdges(), direction2Converter)));
			}

			public String toString() {
				return GraphToString.toString(this);
			}
		};
	}

}

class ConvertedDataIterable {
	
	public static <T1, T2> Iterable<T2> create(final Iterable<T1> outerIterable, final DataConverter<T1, T2> converter) {
		return new Iterable<T2>() {
			public Iterator<T2> iterator() {
				return ConvertedDataIterator.create(outerIterable.iterator(), converter);			
			}
		};
	}

	private ConvertedDataIterable() {
	}
}

class MergedIterable<T> {

	public static <T> Iterable<T> wrap(final Iterable<? extends Iterable<? extends T>> iterables) {
		return new Iterable<T>() {
			public Iterator<T> iterator() {
				return MergedIterator.create(iterables);
			}
		};
	}

	private MergedIterable() {
	}

}

class MergedIterator {

	public static <T> Iterator<T> create(final Iterable<? extends Iterable<? extends T>> iterables) {
		return new ReadOnlyIterator<T>() {
			Iterator<? extends Iterable<? extends T>> topIterator = iterables.iterator();
			Iterator<? extends T> currentSubIterator = null;
	
			public boolean hasNext() {
				while (currentSubIterator == null || !currentSubIterator.hasNext()) {
					if (topIterator.hasNext())
						currentSubIterator = topIterator.next().iterator();
					else
						return false;
				}
				return true;
			}
	
			public T next() {
				hasNext();
				return currentSubIterator.next();
			}
		};
	}

}

class VarargsIterable {

	public static <T> Iterable<T> create(final T... data) {
		return new Iterable<T>() {
			public Iterator<T> iterator() {
				return VarargsIterator.create(data);
			}
		};
	}

	private VarargsIterable() {
	}

}

class VarargsIterator {

	public static <T> Iterator<T> create(final T... data) {
		return ArrayIterator.create(ArrayFromValues.create(data));
	}

	private VarargsIterator() {
	}

}

class ArrayFromValues {
	public static <T> Array<T> create(T... values) {
		return MutableArrayFromValues.create(values);
	}
}

class MutableArrayFromValues {
	public static <T> MutableArray<T> create(T... values) {
		@SuppressWarnings("unchecked")
		T[] a = (T[]) new Object[values.length];
		for (int i : ZeroTo.get(a.length))
			a[i] = values[i];
		return MutableArrayUsingJavaArray.create(a);
	}
}

class MutableArrayUsingJavaArray {

	public static <T> MutableArray<T> create(final T[] a) {
		return new MutableArray<T>() {
			public T get(int p) {
				return a[p];
			}

			public void set(int p, T v) {
				a[p] = v;
			}

			public int size() {
				return a.length;
			}

			public boolean isEmpty() {
				return a.length == 0;
			}

			public Iterator<T> iterator() {
				return ArrayIterator.create(this);
			}

			public String toString() {
				return IterableToString.toString(this);
			}

			public boolean equals(Object obj) {
				return StrictEqualityTester.areEqual(this, obj, new EqualityTester<MutableArray<T>>() {
					public boolean areEqual(MutableArray<T> o1, MutableArray<T> o2) {
						return IterableEqualityTester.areEqual(o1, o2);
					}
				});
			}

			public int hashCode() {
				return IterableHash.hash(this);
			}
		};
	}

	private MutableArrayUsingJavaArray() {
	}

}

interface UndirectedEdge<V> {
	V v1();

	V v2();
}

class MutableUndirectedGraph<V> implements Graph<V, UndirectedEdge<V>> {

	public static <V> MutableUndirectedGraph<V> create() {
		return new MutableUndirectedGraph<V>();
	}

	private final MutableGraph<V, UndirectedEdge<V>> g = MutableGraph.create();

	public void insertVertex(V v) {
		g.insertVertex(v);
	}

	public void addEdge(V v1, V v2) {
		assertVertexExist(v1);
		assertVertexExist(v2);
		g.addEdge(UndirectedEdgeFactory.create(v1, v2));
	}

	public Collection<V> getVertices() {
		return g.getVertices();
	}

	private void assertVertexExist(V v) {
		AssertStatus.assertTrue(g.getVertices().contains(v), "vertex is not in graph");
	}

	public Iterable<UndirectedEdge<V>> getEdges() {
		return g.getEdges();
	}

	public String toString() {
		return GraphToString.toString(this);
	}
}

class UndirectedEdgeFactory {

	public static <V> UndirectedEdge<V> create(final V v1, final V v2) {
		return new UndirectedEdge<V>() {

			public V v1() {
				return v1;
			}

			public V v2() {
				return v2;
			}

			public String toString() {
				return v1 + "-" + v2;
			}
		};
	}

}

class InsertAllToSet {
	public static <T> void insertAll(MutableSet<T> set, Iterable<? extends T> values) {
		for(T v : values) 
			set.insert(v);
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
	
	public boolean hasNext() {
		return tokenizer.hasMoreTokens();
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

class AllSourceDFS {

	public static <V, E extends DirectedEdge<V>> void traverse(Graph<V, E> graph, DFSVisitor<V, E> visitor) {
		MultiSourceDFS.traverse(graph, visitor, graph.getVertices());
	}

}

interface DFSVisitor<V, E> {
	void onDiscovered(V vertex, int depth);

	void onFinish(V vertex, int depth);

	void onBackEdgeFound(E edge);

	void onWalkDown(E edge);

	void onWalkUp(E downedEdge);
}

class MultiSourceDFS {

	public static <V, E extends DirectedEdge<V>> void traverse(Graph<V, E> graph, DFSVisitor<V, E> visitor, Iterable<V> visitOrder) {
		MutableMap<V, DFSStatus> status = DFSCore.createInitialStatus(graph);
		AdjacencyListOfDirectedGraph<V, E> edges = AdjacencyListOfDirectedGraph.create(graph);
		for (V v : visitOrder)
			if (status.get(v) == DFSStatus.NOT_DISCOVERED)
				DFSCore.traverse(edges, status, v, visitor);
	}

}

class AdjacencyListOfDirectedGraph<V, E extends DirectedEdge<V>> {

	public static <V, E extends DirectedEdge<V>> AdjacencyListOfDirectedGraph<V, E> create(Graph<V, E> g) {
		return new AdjacencyListOfDirectedGraph<V, E>(g);
	}

	private final DynamicArray<V> vertices = DynamicArray.create();
	private final MutableMap<V, DynamicArray<E>> index = GoodMutableMapFactory.getInstance().create();

	private AdjacencyListOfDirectedGraph(Graph<V, E> g) {
		AddToLastAll.add(vertices, g.getVertices());
		for (V v : g.getVertices())
			index.put(v, new DynamicArray<E>());
		for (E e : g.getEdges())
			index.get(e.from()).addToLast(e);
	}

	public Collection<V> getVertices() {
		return vertices;
	}

	public Iterable<E> getEdges(V from) {
		return index.get(from);
	}
}

class AddToLastAll {

	public static <T> void add(DynamicArray<T> target, Iterable<? extends T> values) {
		for (T v : values)
			target.addToLast(v);
	}

}

class DFSCore {

	private static final StackFactory STACK_FACTORY = GoodStackFactory.getInstance();

	private static class StackItem<V, E> {
		public V v;
		public E e;
		public int depth;
		public Iterator<E> iter;

		public StackItem(V v, E e, int d, Iterator<E> iter) {
			this.v = v;
			this.e = e;
			this.depth = d;
			this.iter = iter;
		}
	}

	public static <V, E extends DirectedEdge<V>> MutableMap<V, DFSStatus> createInitialStatus(Graph<V, E> graph) {
		MutableMap<V, DFSStatus> r = GoodMutableMapFactory.getInstance().create();
		for (V v : graph.getVertices())
			r.put(v, DFSStatus.NOT_DISCOVERED);
		return r;
	}

	public static <V, E extends DirectedEdge<V>> void traverse(AdjacencyListOfDirectedGraph<V, E> adj, MutableMap<V, DFSStatus> status, V start, DFSVisitor<V, E> visitor) {
		Stack<StackItem<V, E>> stack = STACK_FACTORY.create();
		status.put(start, DFSStatus.DISCOVERED);
		visitor.onDiscovered(start, 0);
		Iterator<E> iterator = adj.getEdges(start).iterator();
		stack.push(new StackItem<V, E>(start, null, 0, iterator));

		while (!stack.isEmpty()) {
			StackItem<V, E> item = stack.top();

			if (item.iter.hasNext()) {
				E edge = item.iter.next();
				V nextv = edge.to();
				DFSStatus nextc = status.get(nextv);
				if (nextc == DFSStatus.NOT_DISCOVERED) {
					visitor.onWalkDown(edge);
					status.put(item.v, DFSStatus.DISCOVERED);
					visitor.onDiscovered(nextv, item.depth + 1);
					stack.push(new StackItem<V, E>(nextv, edge, item.depth + 1, adj.getEdges(nextv).iterator()));
				} else if (nextc == DFSStatus.DISCOVERED) {
					visitor.onBackEdgeFound(edge);
				}
			} else {
				stack.pop();
				status.put(item.v, DFSStatus.EXPLORED);
				visitor.onFinish(item.v, item.depth);
				if (item.e != null)
					visitor.onWalkUp(item.e);
			}
		}
	}

}

class GoodStackFactory {

	private static final StackFactoryUsingDynamicArray INSTANCE = new StackFactoryUsingDynamicArray();

	public static StackFactory getInstance() {
		return INSTANCE;
	}

}

interface StackFactory {
	<T> Stack<T> create();
}

interface Stack<T> {
	void push(T v);
	T pop();
	T top();
	boolean isEmpty();
}

class StackFactoryUsingDynamicArray implements StackFactory {
	public <T> Stack<T> create() {
		return new Stack<T>() {
			DynamicArray<T> a = DynamicArray.create();

			public boolean isEmpty() {
				return a.isEmpty();
			}

			public T pop() {
				return a.removeLast();
			}

			public void push(T v) {
				a.addToLast(v);
			}

			public T top() {
				return LastInArray.getLast(a);
			}

			public String toString() {
				return a.toString();
			}
		};
	}

}

class LastInArray {

	public static <T> T getLast(Array<T> a) {
		return a.get(a.size()-1);
	}

}

enum DFSStatus {
	NOT_DISCOVERED, DISCOVERED, EXPLORED,
}
