import java.io.BufferedInputStream;
import java.io.ByteArrayOutputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.StringTokenizer;



public class id2 implements Runnable {

	@SuppressWarnings("unused")
	public void run() {
		FastScanner in = new FastScanner(new BufferedInputStream(System.in));
		int n = in.nextInt();
		final id15<Integer> graph = id15.create();
		for (int i : ZeroTo.get(n))
			graph.insertVertex(i + 1);
		for (int i : ZeroTo.get(n)) {
			int v1 = in.nextInt();
			int v2 = in.nextInt();
			graph.addEdge(v1, v2);
		}

		final MutableSet<Integer> id46 = id28.getInstance().create();
		id37.traverse(id50.wrap(graph), 1, new id45<Integer, DirectedEdge<Integer>>() {
			DynamicArray<Integer> path = DynamicArray.create();

			public void id7(Integer vertex, int depth) {
				path.id11(vertex);
			}

			public void id30(DirectedEdge<Integer> edge) {
				if (id46.isEmpty() && !edge.to().equals(path.get(path.size() - 2))) {
					int pos = LinearSearch.search(path, edge.to(), -1);
					id25.insertAll(id46, SubArray.wrap(path, pos, path.size()));
				}
			}

			public void onFinish(Integer vertex, int depth) {
				path.removeLast();
			}
		});

		Graph<Integer, id24<Integer>> id0 = id54.wrap(graph, new DataFilter<id24<Integer>>() {
			public boolean isAccepted(id24<Integer> v) {
				return !(id46.contains(v.v1()) && id46.contains(v.v2()));
			}
		});

		final int[] distance = new int[n];

		id31.traverse(id50.wrap(id0), new id45<Integer, DirectedEdge<Integer>>() {
			public void id7(Integer vertex, int d) {
				distance[vertex - 1] = d;
			}
		}, id46);

		for (int d : distance)
			System.out.print(d + " ");
		System.out.println();
	}

	public static void main(String[] args) throws Exception {
		if (args.length >= 1)
			System.setIn(new FileInputStream(args[0]));
		new id2().run();
	}

}

class id28 {
	public static id38 getInstance() {
		return id33.getInstance();
	}
}

class id33 {

	public static id38 getInstance() {
		return new id38() {
			public <T> MutableSet<T> create() {
				return new id26<T>(new HashSet<T>());
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

interface Collection<T> extends Iterable<T> {
	int size();
	boolean isEmpty();
}

interface id38 {
	<T> MutableSet<T> create();
}

class id26<T> implements MutableSet<T> {
	
	private final java.util.Set<T> id23;
	
	public id26(java.util.Set<T> set) {
		this.id23 = set;
	}

	public void clear() {
		id23.clear();		
	}
	
	public boolean contains(T v) {
		return id23.contains(v);		
	}
	
	public void insert(T v) {
		id23.add(v);
	}

	public Iterator<T> iterator() {
		return id23.iterator();
	}
	
	public int size() {
		return id23.size();
	}
	
	public void remove(T v) {
		id23.remove(v);
	}
	
	public boolean isEmpty() {
		return size() == 0;
	}
	
	public String toString() {
		return id3.toString(this);
	}

}

class id3 {
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

class ZeroTo {

	public static Iterable<Integer> get(int end) {
		return id56.create(0, 1, end);
	}
	
}

class id56 {
	public static Iterable<Integer> create(final int from, final int step, final int size) {
		return new Iterable<Integer>() {
			public Iterator<Integer> iterator() {
				return id4.create(from, step, size);
			}
		};
	}

	private id56() {
	}
}

class id4 {

	public static Iterator<Integer> create(final int start, final int step, final int size) {
		return new id17<Integer>() {
			int nextIndex = 0;
	
			public boolean hasNext() {
				return nextIndex < size;
			}
	
			public Integer next() {
				return start + step * (nextIndex++);
			}
		};
	}

	private id4() {
	}

}

abstract class id17<T> implements Iterator<T> {
	public final void remove() {
		throw new UnsupportedOperationException();
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
	public void id11(T value) {
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
		return id35.areEqual(this, obj, this);
	}

	public boolean areEqual(Array<T> o1, Array<T> o2) {
		return id42.areEqual(o1, o2);
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
		return id3.toString(this);
	}
	
}

interface EqualityTester<T> {
	boolean areEqual(T o1, T o2);
}

class id42 {

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
			r ^= id41.id5(v.hashCode());
		return r;
	}

}

class id41 {
	
	

	
	public static int id5(int key) {
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

class id35 {
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

interface Array<T> extends Collection<T> {
	T get(int index);
}

class ArrayIterator {
	public static <T> Iterator<T> create(final Array<T> a) {
		return new id17<T>() {
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
				return id3.toString(this);
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

	private MutableSet<V> vertices = id28.getInstance().create();
	private DynamicArray<E> edges = DynamicArray.create();

	public void insertVertex(V v) {
		vertices.insert(v);
	}

	public void addEdge(E edge) {
		edges.id11(edge);
	}

	public Set<V> getVertices() {
		return vertices;
	}

	public Iterable<E> getEdges() {
		return edges;
	}

	public String toString() {
		return id19.toString(this);
	}

}

interface Graph<V, E> {
	Collection<V> getVertices();

	Iterable<E> getEdges();
}

class id19 {

	public static <V, E> String toString(Graph<V, E> g) {
		String r = "";
		for (E e : g.getEdges()) {
			if (r.length() != 0)
				r += ", ";
			r += e.toString();
		}
		return "Graph({" + id3.toString(g.getVertices()) + "},{" + id3.toString(g.getEdges()) + "})";
	}

}

class id50 {

	public static <V, E extends id24<V>> Graph<V, DirectedEdge<V>> wrap(final Graph<V, E> original) {
		return id39.wrap(original, new DataConverter<E, DirectedEdge<V>>() {
			public DirectedEdge<V> convert(E original) {
				return id1.create(original.v1(), original.v2());
			}
		}, new DataConverter<E, DirectedEdge<V>>() {
			public DirectedEdge<V> convert(E original) {
				return id1.create(original.v2(), original.v1());
			}
		});
	}

}

interface DataConverter<T1, T2> {
	T2 convert(T1 v);
}

class id1 {

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

class id39 {

	public static <V, W, E1, E2> Graph<V, E2> wrap(final Graph<V, E1> original, final DataConverter<E1, E2> id29, final DataConverter<E1, E2> id20) {
		return new Graph<V, E2>() {
			public Collection<V> getVertices() {
				return original.getVertices();
			}
	
			@SuppressWarnings("unchecked")
			public Iterable<E2> getEdges() {
				return MergedIterable.wrap(id22.create(id16.create(original.getEdges(), id29), id16.create(original.getEdges(), id20)));
			}

			public String toString() {
				return id19.toString(this);
			}
		};
	}

}

class id16 {
	
	public static <T1, T2> Iterable<T2> create(final Iterable<T1> outerIterable, final DataConverter<T1, T2> converter) {
		return new Iterable<T2>() {
			public Iterator<T2> iterator() {
				return id34.create(outerIterable.iterator(), converter);			
			}
		};
	}

	private id16() {
	}
}

class id34 {

	public static <T1, T2> Iterator<T2> create(final Iterator<T1> original, final DataConverter<T1, T2> converter) {
		return new id17<T2>() {
			public boolean hasNext() {
				return original.hasNext();
			}
			public T2 next() {
				return converter.convert(original.next());
			}
		};
	}

	private id34() {
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
		return new id17<T>() {
			Iterator<? extends Iterable<? extends T>> topIterator = iterables.iterator();
			Iterator<? extends T> id43 = null;
	
			public boolean hasNext() {
				while (id43 == null || !id43.hasNext()) {
					if (topIterator.hasNext())
						id43 = topIterator.next().iterator();
					else
						return false;
				}
				return true;
			}
	
			public T next() {
				hasNext();
				return id43.next();
			}
		};
	}

}

class id22 {

	public static <T> Iterable<T> create(final T... data) {
		return new Iterable<T>() {
			public Iterator<T> iterator() {
				return id9.create(data);
			}
		};
	}

	private id22() {
	}

}

class id9 {

	public static <T> Iterator<T> create(final T... data) {
		return ArrayIterator.create(id6.create(data));
	}

	private id9() {
	}

}

class id6 {
	public static <T> Array<T> create(T... values) {
		return id14.create(values);
	}
}

class id14 {
	public static <T> MutableArray<T> create(T... values) {
		@SuppressWarnings("unchecked")
		T[] a = (T[]) new Object[values.length];
		for (int i : ZeroTo.get(a.length))
			a[i] = values[i];
		return id32.create(a);
	}
}

class id32 {

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
				return id3.toString(this);
			}

			public boolean equals(Object obj) {
				return id35.areEqual(this, obj, new EqualityTester<MutableArray<T>>() {
					public boolean areEqual(MutableArray<T> o1, MutableArray<T> o2) {
						return id42.areEqual(o1, o2);
					}
				});
			}

			public int hashCode() {
				return IterableHash.hash(this);
			}
		};
	}

	private id32() {
	}

}

interface id24<V> {
	V v1();

	V v2();
}

class id15<V> implements Graph<V, id24<V>> {

	public static <V> id15<V> create() {
		return new id15<V>();
	}

	private final MutableGraph<V, id24<V>> g = MutableGraph.create();

	public void insertVertex(V v) {
		g.insertVertex(v);
	}

	public void addEdge(V v1, V v2) {
		id49(v1);
		id49(v2);
		g.addEdge(id40.create(v1, v2));
	}

	public Collection<V> getVertices() {
		return g.getVertices();
	}

	private void id49(V v) {
		AssertStatus.assertTrue(g.getVertices().contains(v), "vertex is not in graph");
	}

	public Iterable<id24<V>> getEdges() {
		return g.getEdges();
	}

	public String toString() {
		return id19.toString(this);
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

class id40 {

	public static <V> id24<V> create(final V v1, final V v2) {
		return new id24<V>() {

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

class id25 {
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

class id45<V, E> implements DFSVisitor<V, E> {
	public void id7(V vertex, int depth) {
	}

	public void onFinish(V vertex, int depth) {
	}

	public void id30(E edge) {
	}

	public void id52(E outEdge) {
	}

	public void id47(E edge) {
	}
}

interface DFSVisitor<V, E> {
	void id7(V vertex, int depth);

	void onFinish(V vertex, int depth);

	void id30(E edge);

	void id52(E edge);

	void id47(E id8);
}

class id31 {

	public static <V, E extends DirectedEdge<V>> void traverse(Graph<V, E> graph, DFSVisitor<V, E> visitor, Iterable<V> visitOrder) {
		MutableMap<V, DFSStatus> status = DFSCore.id18(graph);
		id10<V, E> edges = id10.create(graph);
		for (V v : visitOrder)
			if (status.get(v) == DFSStatus.NOT_DISCOVERED)
				DFSCore.traverse(edges, status, v, visitor);
	}

}

class id10<V, E extends DirectedEdge<V>> {

	public static <V, E extends DirectedEdge<V>> id10<V, E> create(Graph<V, E> g) {
		return new id10<V, E>(g);
	}

	private final DynamicArray<V> vertices = DynamicArray.create();
	private final MutableMap<V, DynamicArray<E>> index = id55.getInstance().create();

	private id10(Graph<V, E> g) {
		id48.add(vertices, g.getVertices());
		for (V v : g.getVertices())
			index.put(v, new DynamicArray<E>());
		for (E e : g.getEdges())
			index.get(e.from()).id11(e);
	}

	public Collection<V> getVertices() {
		return vertices;
	}

	public Iterable<E> getEdges(V from) {
		return index.get(from);
	}
}

class id55 {

	public static id12 getInstance() {
		return id36.getInstance();
	}

}

class id36 {

	public static id12 getInstance() {
		return new id12() {
			public <K, V> MutableMap<K, V> create() {
				return id51.create(new HashMap<K, V>());
			}
		};
	}

	private id36() {
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

interface id12 {
	<K,V> MutableMap<K,V> create();
}

class id51 {

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
				return id34.create(map.entrySet().iterator(), new DataConverter<java.util.Map.Entry<K, V>, MapEntry<K, V>>() {
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
			return id35.areEqual(this, obj, this);
		}

		public boolean areEqual(EntryWrapper<K, V> o1, EntryWrapper<K, V> o2) {
			return o1.getKey().equals(o2.getKey()) && o1.getValue().equals(o2.getValue());
		}

		public int hashCode() {
			return PairHash.hash(getKey().hashCode(), getValue().hashCode());
		}
	}

}

class PairHash {
	public static int hash(int h1, int h2) {
		return id41.id21((((long) h1) << 32) | h2);
	}
}

class id48 {

	public static <T> void add(DynamicArray<T> target, Iterable<? extends T> values) {
		for (T v : values)
			target.id11(v);
	}

}



class DFSCore {

	private static final StackFactory STACK_FACTORY = id53.getInstance();

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

	public static <V, E extends DirectedEdge<V>> MutableMap<V, DFSStatus> id18(Graph<V, E> graph) {
		MutableMap<V, DFSStatus> r = id55.getInstance().create();
		for (V v : graph.getVertices())
			r.put(v, DFSStatus.NOT_DISCOVERED);
		return r;
	}

	public static <V, E extends DirectedEdge<V>> void traverse(id10<V, E> adj, MutableMap<V, DFSStatus> status, V start, DFSVisitor<V, E> visitor) {
		Stack<StackItem<V, E>> stack = STACK_FACTORY.create();
		status.put(start, DFSStatus.DISCOVERED);
		visitor.id7(start, 0);
		Iterator<E> iterator = adj.getEdges(start).iterator();
		stack.push(new StackItem<V, E>(start, null, 0, iterator));

		while (!stack.isEmpty()) {
			StackItem<V, E> item = stack.top();

			if (item.iter.hasNext()) {
				E edge = item.iter.next();
				V nextv = edge.to();
				DFSStatus nextc = status.get(nextv);
				if (nextc == DFSStatus.NOT_DISCOVERED) {
					visitor.id52(edge);
					status.put(item.v, DFSStatus.DISCOVERED);
					visitor.id7(nextv, item.depth + 1);
					stack.push(new StackItem<V, E>(nextv, edge, item.depth + 1, adj.getEdges(nextv).iterator()));
				} else if (nextc == DFSStatus.DISCOVERED) {
					visitor.id30(edge);
				}
			} else {
				stack.pop();
				status.put(item.v, DFSStatus.EXPLORED);
				visitor.onFinish(item.v, item.depth);
				if (item.e != null)
					visitor.id47(item.e);
			}
		}
	}

}

class id53 {

	private static final id27 INSTANCE = new id27();

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

class id27 implements StackFactory {
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
				a.id11(v);
			}

			public T top() {
				return id13.getLast(a);
			}

			public String toString() {
				return a.toString();
			}
		};
	}

}

class id13 {

	public static <T> T getLast(Array<T> a) {
		return a.get(a.size()-1);
	}

}

enum DFSStatus {
	NOT_DISCOVERED, DISCOVERED, EXPLORED,
}

class id37 {
	public static <V, E extends DirectedEdge<V>> void traverse(Graph<V, E> graph, V start, DFSVisitor<V, E> visitor) {
		MutableMap<V, DFSStatus> status = DFSCore.id18(graph);
		DFSCore.traverse(id10.create(graph), status, start, visitor);
	}
}

class id54 {

	public static <V, E> Graph<V, E> wrap(final Graph<V, E> udg, final DataFilter<E> filter) {
		return new Graph<V, E>() {
			public Collection<V> getVertices() {
				return udg.getVertices();
			}
	
			public Iterable<E> getEdges() {
				return FilteredIterable.create(udg.getEdges(), filter);
			}
		};
	}

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
		return new id17<T>() {
			T next = null;
			Iterator<? extends T> cursor = a;

			public boolean hasNext() {
				id44();
				return next != null;
			}

			public T next() {
				id44();
				T r = next;
				next = null;
				return r;
			}

			private void id44() {
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

class LinearSearch {

	public static <T> int search(final DynamicArray<T> array, T value, int def) {
		for (int i = 0; i < array.size(); i++)
			if (array.get(i).equals(value))
				return i;
		return def;
	}

}

