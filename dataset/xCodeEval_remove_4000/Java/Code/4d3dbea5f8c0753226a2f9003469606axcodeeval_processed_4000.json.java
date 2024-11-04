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
		final id13<Integer> udg = id13.create();
		for (int i : ZeroTo.get(n))
			udg.insertVertex(i + 1);
		for (int i : ZeroTo.get(n)) {
			int v1 = in.nextInt();
			int v2 = in.nextInt();
			udg.addEdge(v1, v2);
		}

		


		final DynamicArray<Integer> path = DynamicArray.create();
		final MutableSet<Integer> cycle = id26.getInstance().create();
		id48.traverse(id45.wrap(udg), new DFSVisitor<Integer, DirectedEdge<Integer>>() {
			public void id28(DirectedEdge<Integer> edge) {
				if (cycle.isEmpty() && !edge.to().equals(path.get(path.size() - 2))) {
					int pos = search(path, edge.to(), -1);
					id23.insertAll(cycle, SubArray.wrap(path, pos, path.size()));
				}
			}

			public void id5(Integer vertex, int depth) {
				path.id8(vertex);
			}

			public void onFinish(Integer vertex, int depth) {
				path.removeLast();
			}

			public void id47(DirectedEdge<Integer> edge) {
			}

			public void id42(DirectedEdge<Integer> id6) {
			}
		});

		final DataFilter<id22<Integer>> filter = new DataFilter<id22<Integer>>() {
			public boolean isAccepted(id22<Integer> v) {
				return !(cycle.contains(v.v1()) && cycle.contains(v.v2()));
			}
		};

		Graph<Integer, id22<Integer>> cycleRemoved = new Graph<Integer, id22<Integer>>() {
			public Collection<Integer> getVertices() {
				return udg.getVertices();
			}

			public Iterable<id22<Integer>> getEdges() {
				return FilteredIterable.create(udg.getEdges(), filter);
			}
		};

		final MutableMap<Integer, Integer> depthMap = id50.getInstance().create();

		id29.traverse(id45.wrap(cycleRemoved), new DFSVisitor<Integer, DirectedEdge<Integer>>() {
			public void id28(DirectedEdge<Integer> edge) {
			}

			public void id5(Integer vertex, int depth) {
				depthMap.put(vertex, depth);
			}

			public void onFinish(Integer vertex, int depth) {
			}

			public void id47(DirectedEdge<Integer> edge) {
			}

			public void id42(DirectedEdge<Integer> id6) {
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

class id50 {

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
				return id32.create(map.entrySet().iterator(), new DataConverter<java.util.Map.Entry<K, V>, MapEntry<K, V>>() {
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

class AssertStatus {
	public static void assertTrue(boolean v) {
		assertTrue(v, "");
	}

	public static void assertTrue(boolean v, String message) {
		if (!v)
			throw new RuntimeException(message);
	}
}

class id32 {

	public static <T1, T2> Iterator<T2> create(final Iterator<T1> original, final DataConverter<T1, T2> converter) {
		return new id15<T2>() {
			public boolean hasNext() {
				return original.hasNext();
			}
			public T2 next() {
				return converter.convert(original.next());
			}
		};
	}

	private id32() {
	}
}

interface DataConverter<T1, T2> {
	T2 convert(T1 v);
}

abstract class id15<T> implements Iterator<T> {
	public final void remove() {
		throw new UnsupportedOperationException();
	}
}

interface EqualityTester<T> {
	boolean areEqual(T o1, T o2);
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

class PairHash {
	public static int hash(int h1, int h2) {
		return id38.id19((((long) h1) << 32) | h2);
	}
}

class id38 {
	
	

	
	public static int id3(int key) {
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

class id26 {
	public static id35 getInstance() {
		return id31.getInstance();
	}
}

class id31 {

	public static id35 getInstance() {
		return new id35() {
			public <T> MutableSet<T> create() {
				return new id24<T>(new HashSet<T>());
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

interface id35 {
	<T> MutableSet<T> create();
}

class id24<T> implements MutableSet<T> {
	
	private final java.util.Set<T> id21;
	
	public id24(java.util.Set<T> set) {
		this.id21 = set;
	}

	public void clear() {
		id21.clear();		
	}
	
	public boolean contains(T v) {
		return id21.contains(v);		
	}
	
	public void insert(T v) {
		id21.add(v);
	}

	public Iterator<T> iterator() {
		return id21.iterator();
	}
	
	public int size() {
		return id21.size();
	}
	
	public void remove(T v) {
		id21.remove(v);
	}
	
	public boolean isEmpty() {
		return size() == 0;
	}
	
	public String toString() {
		return id1.toString(this);
	}

}

class id1 {
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
		return new id15<T>() {
			T next = null;
			Iterator<? extends T> cursor = a;

			public boolean hasNext() {
				id41();
				return next != null;
			}

			public T next() {
				id41();
				T r = next;
				next = null;
				return r;
			}

			private void id41() {
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
		return id51.create(0, 1, end);
	}
	
}

class id51 {
	public static Iterable<Integer> create(final int from, final int step, final int size) {
		return new Iterable<Integer>() {
			public Iterator<Integer> iterator() {
				return id2.create(from, step, size);
			}
		};
	}

	private id51() {
	}
}

class id2 {

	public static Iterator<Integer> create(final int start, final int step, final int size) {
		return new id15<Integer>() {
			int nextIndex = 0;
	
			public boolean hasNext() {
				return nextIndex < size;
			}
	
			public Integer next() {
				return start + step * (nextIndex++);
			}
		};
	}

	private id2() {
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
		return id33.areEqual(this, obj, this);
	}

	public boolean areEqual(Array<T> o1, Array<T> o2) {
		return id39.areEqual(o1, o2);
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
		return id1.toString(this);
	}
	
}

class id39 {

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
			r ^= id38.id3(v.hashCode());
		return r;
	}

}

interface Array<T> extends Collection<T> {
	T get(int index);
}

class ArrayIterator {
	public static <T> Iterator<T> create(final Array<T> a) {
		return new id15<T>() {
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
				return id1.toString(this);
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

	private MutableSet<V> vertices = id26.getInstance().create();
	private DynamicArray<E> edges = DynamicArray.create();

	public void insertVertex(V v) {
		vertices.insert(v);
	}

	public void addEdge(E edge) {
		edges.id8(edge);
	}

	public Set<V> getVertices() {
		return vertices;
	}

	public Iterable<E> getEdges() {
		return edges;
	}

	public String toString() {
		return id17.toString(this);
	}

}

interface Graph<V, E> {
	Collection<V> getVertices();

	Iterable<E> getEdges();
}

class id17 {

	public static <V, E> String toString(Graph<V, E> g) {
		String r = "";
		for (E e : g.getEdges()) {
			if (r.length() != 0)
				r += ", ";
			r += e.toString();
		}
		return "Graph({" + id1.toString(g.getVertices()) + "},{" + id1.toString(g.getEdges()) + "})";
	}

}

class id45 {

	public static <V, E extends id22<V>> Graph<V, DirectedEdge<V>> wrap(final Graph<V, E> original) {
		return id36.wrap(original, new DataConverter<E, DirectedEdge<V>>() {
			public DirectedEdge<V> convert(E original) {
				return id0.create(original.v1(), original.v2());
			}
		}, new DataConverter<E, DirectedEdge<V>>() {
			public DirectedEdge<V> convert(E original) {
				return id0.create(original.v2(), original.v1());
			}
		});
	}

}

class id0 {

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

class id36 {

	public static <V, W, E1, E2> Graph<V, E2> wrap(final Graph<V, E1> original, final DataConverter<E1, E2> id27, final DataConverter<E1, E2> id18) {
		return new Graph<V, E2>() {
			public Collection<V> getVertices() {
				return original.getVertices();
			}
	
			@SuppressWarnings("unchecked")
			public Iterable<E2> getEdges() {
				return MergedIterable.wrap(id20.create(id14.create(original.getEdges(), id27), id14.create(original.getEdges(), id18)));
			}

			public String toString() {
				return id17.toString(this);
			}
		};
	}

}

class id14 {
	
	public static <T1, T2> Iterable<T2> create(final Iterable<T1> outerIterable, final DataConverter<T1, T2> converter) {
		return new Iterable<T2>() {
			public Iterator<T2> iterator() {
				return id32.create(outerIterable.iterator(), converter);			
			}
		};
	}

	private id14() {
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
		return new id15<T>() {
			Iterator<? extends Iterable<? extends T>> topIterator = iterables.iterator();
			Iterator<? extends T> id40 = null;
	
			public boolean hasNext() {
				while (id40 == null || !id40.hasNext()) {
					if (topIterator.hasNext())
						id40 = topIterator.next().iterator();
					else
						return false;
				}
				return true;
			}
	
			public T next() {
				hasNext();
				return id40.next();
			}
		};
	}

}

class id20 {

	public static <T> Iterable<T> create(final T... data) {
		return new Iterable<T>() {
			public Iterator<T> iterator() {
				return id7.create(data);
			}
		};
	}

	private id20() {
	}

}

class id7 {

	public static <T> Iterator<T> create(final T... data) {
		return ArrayIterator.create(id4.create(data));
	}

	private id7() {
	}

}

class id4 {
	public static <T> Array<T> create(T... values) {
		return id12.create(values);
	}
}

class id12 {
	public static <T> MutableArray<T> create(T... values) {
		@SuppressWarnings("unchecked")
		T[] a = (T[]) new Object[values.length];
		for (int i : ZeroTo.get(a.length))
			a[i] = values[i];
		return id30.create(a);
	}
}

class id30 {

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
				return id1.toString(this);
			}

			public boolean equals(Object obj) {
				return id33.areEqual(this, obj, new EqualityTester<MutableArray<T>>() {
					public boolean areEqual(MutableArray<T> o1, MutableArray<T> o2) {
						return id39.areEqual(o1, o2);
					}
				});
			}

			public int hashCode() {
				return IterableHash.hash(this);
			}
		};
	}

	private id30() {
	}

}

interface id22<V> {
	V v1();

	V v2();
}

class id13<V> implements Graph<V, id22<V>> {

	public static <V> id13<V> create() {
		return new id13<V>();
	}

	private final MutableGraph<V, id22<V>> g = MutableGraph.create();

	public void insertVertex(V v) {
		g.insertVertex(v);
	}

	public void addEdge(V v1, V v2) {
		id44(v1);
		id44(v2);
		g.addEdge(id37.create(v1, v2));
	}

	public Collection<V> getVertices() {
		return g.getVertices();
	}

	private void id44(V v) {
		AssertStatus.assertTrue(g.getVertices().contains(v), "vertex is not in graph");
	}

	public Iterable<id22<V>> getEdges() {
		return g.getEdges();
	}

	public String toString() {
		return id17.toString(this);
	}
}

class id37 {

	public static <V> id22<V> create(final V v1, final V v2) {
		return new id22<V>() {

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

class id23 {
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

class id48 {

	public static <V, E extends DirectedEdge<V>> void traverse(Graph<V, E> graph, DFSVisitor<V, E> visitor) {
		id29.traverse(graph, visitor, graph.getVertices());
	}

}

interface DFSVisitor<V, E> {
	void id5(V vertex, int depth);

	void onFinish(V vertex, int depth);

	void id28(E edge);

	void id47(E edge);

	void id42(E id6);
}

class id29 {

	public static <V, E extends DirectedEdge<V>> void traverse(Graph<V, E> graph, DFSVisitor<V, E> visitor, Iterable<V> visitOrder) {
		MutableMap<V, DFSStatus> status = DFSCore.id16(graph);
		id9<V, E> edges = id9.create(graph);
		for (V v : visitOrder)
			if (status.get(v) == DFSStatus.NOT_DISCOVERED)
				DFSCore.traverse(edges, status, v, visitor);
	}

}

class id9<V, E extends DirectedEdge<V>> {

	public static <V, E extends DirectedEdge<V>> id9<V, E> create(Graph<V, E> g) {
		return new id9<V, E>(g);
	}

	private final DynamicArray<V> vertices = DynamicArray.create();
	private final MutableMap<V, DynamicArray<E>> index = id50.getInstance().create();

	private id9(Graph<V, E> g) {
		id43.add(vertices, g.getVertices());
		for (V v : g.getVertices())
			index.put(v, new DynamicArray<E>());
		for (E e : g.getEdges())
			index.get(e.from()).id8(e);
	}

	public Collection<V> getVertices() {
		return vertices;
	}

	public Iterable<E> getEdges(V from) {
		return index.get(from);
	}
}

class id43 {

	public static <T> void add(DynamicArray<T> target, Iterable<? extends T> values) {
		for (T v : values)
			target.id8(v);
	}

}

class DFSCore {

	private static final StackFactory STACK_FACTORY = id49.getInstance();

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

	public static <V, E extends DirectedEdge<V>> MutableMap<V, DFSStatus> id16(Graph<V, E> graph) {
		MutableMap<V, DFSStatus> r = id50.getInstance().create();
		for (V v : graph.getVertices())
			r.put(v, DFSStatus.NOT_DISCOVERED);
		return r;
	}

	public static <V, E extends DirectedEdge<V>> void traverse(id9<V, E> adj, MutableMap<V, DFSStatus> status, V start, DFSVisitor<V, E> visitor) {
		Stack<StackItem<V, E>> stack = STACK_FACTORY.create();
		status.put(start, DFSStatus.DISCOVERED);
		visitor.id5(start, 0);
		Iterator<E> iterator = adj.getEdges(start).iterator();
		stack.push(new StackItem<V, E>(start, null, 0, iterator));

		while (!stack.isEmpty()) {
			StackItem<V, E> item = stack.top();

			if (item.iter.hasNext()) {
				E edge = item.iter.next();
				V nextv = edge.to();
				DFSStatus nextc = status.get(nextv);
				if (nextc == DFSStatus.NOT_DISCOVERED) {
					visitor.id47(edge);
					status.put(item.v, DFSStatus.DISCOVERED);
					visitor.id5(nextv, item.depth + 1);
					stack.push(new StackItem<V, E>(nextv, edge, item.depth + 1, adj.getEdges(nextv).iterator()));
				} else if (nextc == DFSStatus.DISCOVERED) {
					visitor.id28(edge);
				}
			} else {
				stack.pop();
				status.put(item.v, DFSStatus.EXPLORED);
				visitor.onFinish(item.v, item.depth);
				if (item.e != null)
					visitor.id42(item.e);
			}
		}
	}

}

class id49 {

	private static final id25 INSTANCE = new id25();

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

class id25 implements StackFactory {
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
				a.id8(v);
			}

			public T top() {
				return id11.getLast(a);
			}

			public String toString() {
				return a.toString();
			}
		};
	}

}

class id11 {

	public static <T> T getLast(Array<T> a) {
		return a.get(a.size()-1);
	}

}

enum DFSStatus {
	NOT_DISCOVERED, DISCOVERED, EXPLORED,
}

