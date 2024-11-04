import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Comparator;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.SortedSet;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;
import java.util.function.BiConsumer;
import java.util.function.Consumer;
import java.util.function.Function;
import java.util.function.Supplier;
import java.util.stream.Stream;

public class id27
{
	public static final long[] POWER2 = id15();
	public static final IteratorBuffer id18 = new IteratorBuffer(streamPrime(1000000).iterator());
	private static BufferedReader id22 = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer stringTokenizer = null;
	private static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

	interface id31<Type0, Type1, TypeResult>
	{
		TypeResult apply(Type0 x0, Type1 x1, TypeResult x2);
	}

	static class Array<Type> implements Iterable<Type>
	{
		private Object[] array;

		public Array(int size)
		{
			this.array = new Object[size];
		}

		public Array(int size, Type element)
		{
			this(size);
			Arrays.fill(this.array, element);
		}

		public Array(Array<Type> array, Type element)
		{
			this(array.size() + 1);
			for (int index = 0; index < array.size(); index++)
			{
				set(index, array.get(index));
			}
			set(size() - 1, element);
		}

		public Array(List<Type> list)
		{
			this(list.size());
			int index = 0;
			for (Type element : list)
			{
				set(index, element);
				index += 1;
			}
		}

		public Type get(int index)
		{
			return (Type) this.array[index];
		}

		public Array set(int index, Type value)
		{
			this.array[index] = value;
			return this;
		}

		public int size()
		{
			return this.array.length;
		}

		public List<Type> toList()
		{
			List<Type> result = new ArrayList<>();
			for (Type element : this)
			{
				result.add(element);
			}
			return result;
		}

		@Override
		public Iterator<Type> iterator()
		{
			return new Iterator<Type>()
			{
				int index = 0;

				@Override
				public boolean hasNext()
				{
					return this.index < size();
				}

				@Override
				public Type next()
				{
					Type result = Array.this.get(index);
					index += 1;
					return result;
				}
			};
		}
	}

	static abstract class Edge<TypeVertex extends Vertex<TypeVertex, TypeEdge>, TypeEdge extends Edge<TypeVertex, TypeEdge>>
	{
		public final TypeVertex vertex0;
		public final TypeVertex vertex1;

		public Edge(TypeVertex vertex0, TypeVertex vertex1, boolean bidirectional)
		{
			this.vertex0 = vertex0;
			this.vertex1 = vertex1;
			this.vertex0.edges.add(getThis());
			if (bidirectional)
			{
				this.vertex1.edges.add(getThis());
			}
		}

		public TypeVertex other(Vertex<TypeVertex, TypeEdge> vertex)
		{
			TypeVertex result;
			if (vertex0 == vertex)
			{
				result = vertex1;
			}
			else
			{
				result = vertex0;
			}
			return result;
		}

		public abstract TypeEdge getThis();
	}

	public static class EdgeDefault<TypeVertex extends Vertex<TypeVertex, EdgeDefault<TypeVertex>>> extends Edge<TypeVertex, EdgeDefault<TypeVertex>>
	{
		public EdgeDefault(TypeVertex vertex0, TypeVertex vertex1, boolean bidirectional)
		{
			super(vertex0, vertex1, bidirectional);
		}

		@Override
		public EdgeDefault<TypeVertex> getThis()
		{
			return this;
		}
	}

	public static class Vertex<TypeVertex extends Vertex<TypeVertex, TypeEdge>, TypeEdge extends Edge<TypeVertex, TypeEdge>> implements Comparable<Vertex<? super TypeVertex, ? super TypeEdge>>
	{
		public static <TypeVertex extends Vertex<TypeVertex, TypeEdge>, TypeEdge extends Edge<TypeVertex, TypeEdge>> void id34(
				BiConsumer<TypeVertex, TypeEdge> id1,
				BiConsumer<TypeVertex, TypeEdge> id6,
				TypeVertex vertex,
				TypeEdge edge,
				Array<Boolean> visited
		)
		{
			if (!visited.get(vertex.index))
			{
				visited.set(vertex.index, true);
				id1.accept(vertex, edge);
				for (TypeEdge edgeNext : vertex.edges)
				{
					TypeVertex vertexNext = edgeNext.other(vertex);
					id34(
							id1,
							id6,
							vertexNext,
							edgeNext,
							visited);
				}
				id6.accept(vertex, edge);
			}
		}

		public static <TypeVertex extends Vertex<TypeVertex, TypeEdge>, TypeEdge extends Edge<TypeVertex, TypeEdge>> void id34(
				Array<TypeVertex> vertices,
				int id25,
				BiConsumer<TypeVertex, TypeEdge> id1,
				BiConsumer<TypeVertex, TypeEdge> id6
		)
		{
			Array<Boolean> visited = new Array(vertices.size(), false);
			id34(
					id1,
					id6,
					vertices.get(id25),
					null,
					visited);
		}

		public static <TypeVertex extends Vertex<TypeVertex, TypeEdge>, TypeEdge extends Edge<TypeVertex, TypeEdge>, TypeResult> TypeResult id2(
				TypeVertex vertex,
				TypeEdge edge,
				id31<TypeVertex, TypeEdge, TypeResult> function,
				Array<Boolean> visited,
				FIFO<TypeVertex> verticesNext,
				FIFO<TypeEdge> edgesNext,
				TypeResult result
		)
		{
			if (!visited.get(vertex.index))
			{
				visited.set(vertex.index, true);
				result = function.apply(vertex, edge, result);
				for (TypeEdge edgeNext : vertex.edges)
				{
					TypeVertex vertexNext = edgeNext.other(vertex);
					if (!visited.get(vertexNext.index))
					{
						verticesNext.push(vertexNext);
						edgesNext.push(edgeNext);
					}
				}
			}
			return result;
		}

		public static <TypeVertex extends Vertex<TypeVertex, TypeEdge>, TypeEdge extends Edge<TypeVertex, TypeEdge>, TypeResult> TypeResult id2(
				Array<TypeVertex> vertices,
				int id25,
				id31<TypeVertex, TypeEdge, TypeResult> function,
				TypeResult result
		)
		{
			Array<Boolean> visited = new Array(vertices.size(), false);
			FIFO<TypeVertex> verticesNext = new FIFO<>();
			verticesNext.push(vertices.get(id25));
			FIFO<TypeEdge> edgesNext = new FIFO<>();
			edgesNext.push(null);
			while (!verticesNext.isEmpty())
			{
				result = id2(verticesNext.pop(), edgesNext.pop(), function, visited, verticesNext, edgesNext, result);
			}
			return result;
		}

		public final int index;
		public final List<TypeEdge> edges;

		public Vertex(int index)
		{
			this.index = index;
			this.edges = new ArrayList<>();
		}

		@Override
		public int compareTo(Vertex<? super TypeVertex, ? super TypeEdge> that)
		{
			return Integer.compare(this.index, that.index);
		}
	}

	public static class VertexDefault<TypeEdge extends Edge<VertexDefault<TypeEdge>, TypeEdge>> extends Vertex<VertexDefault<TypeEdge>, TypeEdge>
	{
		public VertexDefault(int index)
		{
			super(index);
		}
	}

	public static class Tuple2<Type0, Type1>
	{
		public final Type0 v0;
		public final Type1 v1;

		public Tuple2(Type0 v0, Type1 v1)
		{
			this.v0 = v0;
			this.v1 = v1;
		}
	}

	static class Wrapper<Type>
	{
		public Type value;

		public Wrapper(Type value)
		{
			this.value = value;
		}

		public Type get()
		{
			return this.value;
		}

		public void set(Type value)
		{
			this.value = value;
		}
	}

	public static class Tuple3<Type0, Type1, Type2>
	{
		public final Type0 v0;
		public final Type1 v1;
		public final Type2 v2;

		public Tuple3(Type0 v0, Type1 v1, Type2 v2)
		{
			this.v0 = v0;
			this.v1 = v1;
			this.v2 = v2;
		}
	}

	public static class id33<Type0 extends Comparable<? super Type0>, Type1 extends Comparable<? super Type1>> extends Tuple2<Type0, Type1> implements Comparable<id33<Type0, Type1>>
	{
		public id33(Type0 v0, Type1 v1)
		{
			super(v0, v1);
		}

		@Override
		public int compareTo(id33<Type0, Type1> that)
		{
			int result = this.v0.compareTo(that.v0);
			if (result == 0)
			{
				result = this.v1.compareTo(that.v1);
			}
			return result;
		}
	}

	public static class id26<Type>
	{
		public final Type element;
		public id26<Type> next;

		public id26(Type element, id26<Type> next)
		{
			this.element = element;
			this.next = next;
		}

		public void toCollection(Collection<Type> collection)
		{
			if (this.next != null)
			{
				this.next.toCollection(collection);
			}
			collection.add(this.element);
		}
	}

	public static class FIFO<Type>
	{
		public id26<Type> start;
		public id26<Type> end;

		public FIFO()
		{
			this.start = null;
			this.end = null;
		}

		public void push(Type element)
		{
			id26<Type> list = new id26<>(element, null);
			if (this.start == null)
			{
				this.start = list;
				this.end = list;
			}
			else
			{
				this.end.next = list;
				this.end = list;
			}
		}

		public Type pop()
		{
			Type result = this.start.element;
			this.start = this.start.next;
			return result;
		}

		public boolean isEmpty()
		{
			return this.start == null;
		}
	}

	public static class MapCount extends TreeMap<Long, Long>
	{
		private int size;

		public MapCount()
		{
			this.size = 0;
		}

		public MapCount(Comparator<? super Long> comparator)
		{
			super(comparator);
		}

		public long add(Long key, Long delta)
		{
			long result;
			if (delta > 0)
			{
				Long value = get(key);
				if (value == null)
				{
					value = delta;
				}
				else
				{
					value += delta;
				}
				put(key, value);
				result = delta;
			}
			else
			{
				result = 0;
			}
			this.size += result;
			return result;
		}

		public List<Long> flatten()
		{
			List<Long> result = new ArrayList<>();
			for (Map.Entry<Long, Long> entry : entrySet())
			{
				for (long index = 0; index < entry.getValue(); index++)
				{
					result.add(entry.getKey());
				}
			}
			return result;
		}

		public long remove(Long key, Long delta)
		{
			long result;
			if (delta > 0)
			{
				Long value = get(key) - delta;
				if (value <= 0)
				{
					result = delta + value;
					remove(key);
				}
				else
				{
					result = delta;
					put(key, value);
				}
			}
			else
			{
				result = 0;
			}
			this.size -= result;
			return result;
		}

		public int size()
		{
			return this.size;
		}
	}

	public static class MapSet<TypeKey extends Comparable<? super TypeKey>, TypeValue> extends TreeMap<TypeKey, TreeSet<TypeValue>> implements Iterable<TypeValue>
	{
		private Comparator<? super TypeValue> id29;
		private int count;

		public MapSet()
		{
			this(null);
		}

		public MapSet(Comparator<? super TypeValue> id29)
		{
			super();
			this.count = 0;
			this.id29 = id29;
		}

		public TypeValue firstValue()
		{
			TypeValue result;
			Map.Entry<TypeKey, TreeSet<TypeValue>> firstEntry = firstEntry();
			if (firstEntry == null)
			{
				result = null;
			}
			else
			{
				result = firstEntry.getValue().first();
			}
			return result;
		}

		public Iterator<TypeValue> iterator()
		{
			return new Iterator<TypeValue>()
			{
				Iterator<TreeSet<TypeValue>> iteratorValues = values().iterator();
				Iterator<TypeValue> iteratorValue = null;

				@Override
				public boolean hasNext()
				{
					return iteratorValues.hasNext() || (iteratorValue != null && iteratorValue.hasNext());
				}

				@Override
				public TypeValue next()
				{
					if (iteratorValue == null || !iteratorValue.hasNext())
					{
						iteratorValue = iteratorValues.next().iterator();
					}
					return iteratorValue.next();
				}
			};
		}

		public TypeValue lastValue()
		{
			TypeValue result;
			Map.Entry<TypeKey, TreeSet<TypeValue>> lastEntry = lastEntry();
			if (lastEntry == null)
			{
				result = null;
			}
			else
			{
				result = lastEntry.getValue().last();
			}
			return result;
		}

		public boolean add(TypeKey key, TypeValue value)
		{
			TreeSet<TypeValue> set = get(key);
			if (set == null)
			{
				if (id29 == null)
				{
					set = new TreeSet<>();
				}
				else
				{
					set = new TreeSet<>(id29);
				}
				put(key, set);
			}
			boolean result = set.add(value);
			if (result)
			{
				this.count += 1;
			}
			return result;
		}

		public int count()
		{
			return this.count;
		}

		public boolean remove(TypeKey key, TypeValue value)
		{
			boolean result;
			TreeSet<TypeValue> set = get(key);
			if (set == null)
			{
				result = false;
			}
			else
			{
				result = set.remove(value);
				if (set.size() == 0)
				{
					remove(key);
				}
				if (result)
				{
					this.count -= 1;
				}
			}
			return result;
		}

		@Override
		public TreeSet<TypeValue> remove(Object key)
		{
			TreeSet<TypeValue> result = super.remove(key);
			if (result != null)
			{
				this.count -= result.size();
			}
			return result;
		}
	}

	static class IteratorBuffer<Type>
	{
		private Iterator<Type> iterator;
		private List<Type> list;

		public IteratorBuffer(Iterator<Type> iterator)
		{
			this.iterator = iterator;
			this.list = new ArrayList<Type>();
		}

		public Iterator<Type> iterator()
		{
			return new Iterator<Type>()
			{
				int index = 0;

				@Override
				public boolean hasNext()
				{
					return this.index < list.size() || iterator().hasNext();
				}

				@Override
				public Type next()
				{
					if (list.size() <= this.index)
					{
						list.add(iterator.next());
					}
					Type result = list.get(index);
					index += 1;
					return result;
				}
			};
		}
	}

	private static String next() throws IOException
	{
		while ((stringTokenizer == null) || (!stringTokenizer.hasMoreTokens()))
		{
			stringTokenizer = new StringTokenizer(id22.readLine());
		}
		return stringTokenizer.nextToken();
	}

	public static int nextInt() throws IOException
	{
		return Integer.parseInt(next());
	}

	public static double nextDouble() throws IOException
	{
		return Double.parseDouble(next());
	}

	public static long nextLong() throws IOException
	{
		return Long.parseLong(next());
	}

	public static String nextLine() throws IOException
	{
		return id22.readLine();
	}

	public static void close()
	{
		out.close();
	}

	public static int id12(Function<Integer, Boolean> filter, int start, int end)
	{
		int result;
		if (start == end)
		{
			result = end;
		}
		else
		{
			int middle = start + (end - start) / 2;
			if (filter.apply(middle))
			{
				result = id12(filter, start, middle);
			}
			else
			{
				result = id12(filter, middle + 1, end);
			}
		}
		return result;
	}

	public static int id10(Function<Integer, Boolean> filter, int start, int end)
	{
		return -id12(x -> filter.apply(-x), -end, -start);
	}

	public static long id0(long x, long y)
	{
		return (x + y - 1) / y;
	}

	public static long faculty(int n)
	{
		long result = 1;
		for (int index = 2; index <= n; index++)
		{
			result *= index;
		}
		return result;
	}

	public static LinkedList<Long> factors(long value)
	{
		LinkedList<Long> result = new LinkedList<>();
		Iterator<Long> primes = id18.iterator();
		while (value > 1)
		{
			Long prime = primes.next();
			while (value % prime == 0)
			{
				result.add(prime);
				value /= prime;
			}
		}
		return result;
	}

	public static class id11<Type extends Comparable<? super Type>> implements SortedSet<Type>
	{
		public class Node
		{
			public final Type value;
			public final Node left;
			public final Node right;
			public final int size;
			private final int height;

			public Node(Type value, Node left, Node right)
			{
				this.value = value;
				this.left = left;
				this.right = right;
				this.size = 1 + size(left) + size(right);
				this.height = 1 + Math.max(height(left), height(right));
			}

			public Node rotateLeft()
			{
				Node left = new Node(this.value, this.left, this.right.left);
				return new Node(this.right.value, left, this.right.right);
			}

			public Node rotateRight()
			{
				Node right = new Node(this.value, this.left.right, this.right);
				return new Node(this.left.value, this.left.left, right);
			}
		}

		public Node root;

		public id11()
		{
			this(null);
		}

		public id11(Node root)
		{
			this.root = root;
		}

		public Node balance(Node result)
		{
			while (result != null && 1 < Math.abs(height(result.left) - height(result.right)))
			{
				if (height(result.left) < height(result.right))
				{
					Node right = result.right;
					if (height(right.right) < height(right.left))
					{
						result = new Node(result.value, result.left, right.rotateRight());
					}
					result = result.rotateLeft();
				}
				else
				{
					Node left = result.left;
					if (height(left.left) < height(left.right))
					{
						result = new Node(result.value, left.rotateLeft(), result.right);
					}
					result = result.rotateRight();
				}
			}
			return result;
		}

		public Node delete(Node node, Type value)
		{
			Node result;
			if (node == null)
			{
				result = null;
			}
			else
			{
				int compare = value.compareTo(node.value);
				if (compare == 0)
				{
					if (node.left == null)
					{
						result = node.right;
					}
					else
					{
						if (node.right == null)
						{
							result = node.left;
						}
						else
						{
							Node first = first(node.right);
							result = new Node(first.value, node.left, delete(node.right, first.value));
						}
					}
				}
				else
				{
					if (compare < 0)
					{
						result = new Node(node.value, delete(node.left, value), node.right);
					}
					else
					{
						result = new Node(node.value, node.left, delete(node.right, value));
					}
				}
				result = balance(result);
			}
			return result;
		}

		public Node first(Node result)
		{
			while (result.left != null)
			{
				result = result.left;
			}
			return result;
		}

		public Node get(Node node, Type value)
		{
			Node result;
			if (node == null)
			{
				result = null;
			}
			else
			{
				int compare = value.compareTo(node.value);
				if (compare == 0)
				{
					result = node;
				}
				else
				{
					if (compare < 0)
					{
						result = get(node.left, value);
					}
					else
					{
						result = get(node.right, value);
					}
				}
			}
			return result;
		}

		public Node head(Node node, Type value)
		{
			Node result;
			if (node == null)
			{
				result = null;
			}
			else
			{
				int compare = value.compareTo(node.value);
				if (compare == 0)
				{
					result = node.left;
				}
				else
				{
					if (compare < 0)
					{
						result = head(node.left, value);
					}
					else
					{
						result = new Node(node.value, node.left, head(node.right, value));
					}
				}


			}
			return result;
		}

		public long headSize(Node node, Type value)
		{
			long result;
			if (node == null)
			{
				result = 0;
			}
			else
			{
				int compare = value.compareTo(node.value);
				if (compare == 0)
				{
					result = size(node.left);
				}
				else
				{
					if (compare < 0)
					{
						result = headSize(node.left, value);
					}
					else
					{
						result = 1 + size(node.left) + headSize(node.right, value);
					}
				}
			}
			return result;
		}

		public int height(Node node)
		{
			return node == null ? 0 : node.height;
		}

		public Node insert(Node node, Type value)
		{
			Node result;
			if (node == null)
			{
				result = new Node(value, null, null);
			}
			else
			{
				int compare = value.compareTo(node.value);
				if (compare == 0)
				{
					result = node;
				}
				else
				{
					if (compare < 0)
					{
						result = new Node(node.value, insert(node.left, value), node.right);
					}
					else
					{
						result = new Node(node.value, node.left, insert(node.right, value));
					}
				}
				result = balance(result);
			}
			return result;
		}

		public Node last(Node result)
		{
			while (result.right != null)
			{
				result = result.right;
			}
			return result;
		}

		public int size(Node node)
		{
			return node == null ? 0 : node.size;
		}

		public Node tail(Node node, Type value)
		{
			Node result;
			if (node == null)
			{
				result = null;
			}
			else
			{
				int compare = value.compareTo(node.value);
				if (compare == 0)
				{
					result = new Node(node.value, null, node.right);
				}
				else
				{
					if (compare < 0)
					{
						result = new Node(node.value, tail(node.left, value), node.right);
					}
					else
					{
						result = tail(node.right, value);
					}
				}


			}
			return result;
		}

		public void id5(Node node, Consumer<Type> consumer)
		{
			if (node != null)
			{
				id5(node.left, consumer);
				consumer.accept(node.value);
				id5(node.right, consumer);
			}
		}

		@Override
		public Comparator<? super Type> comparator()
		{
			throw new UnsupportedOperationException();
		}

		@Override
		public SortedSet<Type> subSet(Type valueFrom, Type valueTo)
		{
			return tailSet(valueFrom).headSet(valueTo);
		}

		public long id8(Type valueFrom, Type valueTo)
		{
			return headSize(valueTo) - headSize(valueFrom);
		}

		@Override
		public SortedSet<Type> headSet(Type value)
		{
			return new id11<>(head(this.root, value));
		}

		public long headSize(Type value)
		{
			return headSize(this.root, value);
		}

		@Override
		public SortedSet<Type> tailSet(Type value)
		{
			return new id11<>(tail(this.root, value));
		}

		@Override
		public Type first()
		{
			return first(this.root).value;
		}

		@Override
		public Type last()
		{
			return last(this.root).value;
		}

		@Override
		public int size()
		{
			return this.root == null ? 0 : this.root.size;
		}

		@Override
		public boolean isEmpty()
		{
			return this.root == null;
		}

		@Override
		public boolean contains(Object value)
		{
			return get(this.root, (Type) value) != null;
		}

		@Override
		public Iterator<Type> iterator()
		{
			throw new UnsupportedOperationException();
		}

		@Override
		public Object[] toArray()
		{
			throw new UnsupportedOperationException();
		}

		@Override
		public <T> T[] toArray(T[] ts)
		{
			throw new UnsupportedOperationException();
		}

		@Override
		public boolean add(Type value)
		{
			int sizeBefore = size();
			this.root = insert(this.root, value);
			return sizeBefore == size();
		}

		@Override
		public boolean remove(Object value)
		{
			int sizeBefore = size();
			this.root = delete(this.root, (Type) value);
			return sizeBefore == size();
		}

		@Override
		public boolean containsAll(Collection<?> collection)
		{
			return collection.stream()
					.allMatch(this::contains);
		}

		@Override
		public boolean addAll(Collection<? extends Type> collection)
		{
			return collection.stream()
					.map(this::add)
					.reduce(true, (x, y) -> x | y);
		}

		@Override
		public boolean retainAll(Collection<?> collection)
		{
			throw new UnsupportedOperationException();
		}

		@Override
		public boolean removeAll(Collection<?> collection)
		{
			return collection.stream()
					.map(this::remove)
					.reduce(true, (x, y) -> x | y);
		}

		@Override
		public void clear()
		{
			this.root = null;
		}
	}

	public static long gcd(long a, long b)
	{
		long result = 1;
		Iterator<Long> id32 = factors(a).iterator();
		Iterator<Long> id4 = factors(b).iterator();
		if (id32.hasNext() && id4.hasNext())
		{
			Long factorA = null;
			Long factorB = null;
			while ((factorA != null || id32.hasNext()) && (factorB != null || id4.hasNext()))
			{
				if (factorA == null)
				{
					factorA = id32.next();
				}
				if (factorB == null)
				{
					factorB = id4.next();
				}
				if (factorA == factorB)
				{
					result = result * factorA;
					factorA = null;
					factorB = null;
				}
				else
				{
					if (factorA < factorB)
					{
						factorA = null;
					}
					else
					{
						factorB = null;
					}
				}
			}
		}
		return result;
	}

	public static long[] id15()
	{
		long[] result = new long[63];
		for (int x = 0; x < result.length; x++)
		{
			result[x] = 1L << x;
		}
		return result;
	}

	public static boolean isPrime(long x)
	{
		boolean result = x > 1;
		Iterator<Long> iterator = id18.iterator();
		Long prime;
		while ((prime = iterator.next()) * prime <= x)
		{
			result &= x % prime > 0;
		}
		return result;
	}

	public static long knapsack(List<Tuple3<Long, Integer, Integer>> id21, int weightMaximum)
	{
		long[] valuesMaximum = new long[weightMaximum + 1];
		for (Tuple3<Long, Integer, Integer> itemValueWeightCount : id21)
		{
			long itemValue = itemValueWeightCount.v0;
			int itemWeight = itemValueWeightCount.v1;
			int itemCount = itemValueWeightCount.v2;
			for (int weight = weightMaximum; 0 <= weight; weight--)
			{
				for (int index = 1; index <= itemCount && 0 <= weight - index * itemWeight; index++)
				{
					valuesMaximum[weight] = Math.max(valuesMaximum[weight], valuesMaximum[weight - index * itemWeight] + index * itemValue);
				}
			}
		}
		long result = 0;
		for (long valueMaximum : valuesMaximum)
		{
			result = Math.max(result, valueMaximum);
		}
		return result;
	}

	public static boolean id23(List<Tuple2<Integer, Integer>> id16, int weightMaximum)
	{
		boolean[] weightPossible = new boolean[weightMaximum + 1];
		weightPossible[0] = true;
		int weightLargest = 0;
		for (Tuple2<Integer, Integer> itemWeightCount : id16)
		{
			int itemWeight = itemWeightCount.v0;
			int itemCount = itemWeightCount.v1;
			for (int weightStart = 0; weightStart < itemWeight; weightStart++)
			{
				int count = 0;
				for (int weight = weightStart; weight <= weightMaximum && (0 < count || weight <= weightLargest); weight += itemWeight)
				{
					if (weightPossible[weight])
					{
						count = itemCount;
					}
					else
					{
						if (0 < count)
						{
							weightPossible[weight] = true;
							weightLargest = weight;
							count -= 1;
						}
					}
				}
			}
		}
		return weightPossible[weightMaximum];
	}

	public static long lcm(int a, int b)
	{
		return a * b / gcd(a, b);
	}

	public static <T> List<T> permutation(long p, List<T> x)
	{
		List<T> copy = new ArrayList<>();
		for (int index = 0; index < x.size(); index++)
		{
			copy.add(x.get(index));
		}
		List<T> result = new ArrayList<>();
		for (int indexTo = 0; indexTo < x.size(); indexTo++)
		{
			int indexFrom = (int) p % copy.size();
			p = p / copy.size();
			result.add(copy.remove(indexFrom));
		}
		return result;
	}

	public static <Type> void println(Iterator<Type> iterator)
	{
		if (iterator.hasNext())
		{
			out.print(iterator.next());
		}
		while (iterator.hasNext())
		{
			out.print(" " + iterator.next());
		}
		out.println();
	}

	public static <Type> void println(Iterable<Type> iterable)
	{
		println(iterable.iterator());
	}

	public static Stream<BigInteger> id7()
	{
		return Stream.generate(new Supplier<BigInteger>()
		{
			private BigInteger n0 = BigInteger.ZERO;
			private BigInteger n1 = BigInteger.ONE;

			@Override
			public BigInteger get()
			{
				BigInteger result = n0;
				n0 = n1;
				n1 = result.add(n0);
				return result;
			}
		});
	}

	public static Stream<Long> streamPrime(int id3)
	{
		return Stream.generate(new Supplier<Long>()
		{
			private boolean[] isPrime = new boolean[id3];
			private long id20 = 2;
			private List<Long> primes = new ArrayList<>();
			private int index = 0;

			public void filter(long prime, boolean[] result)
			{
				if (prime * prime < this.id20 + id3)
				{
					long remainingStart = this.id20 % prime;
					long start = remainingStart == 0 ? 0 : prime - remainingStart;
					for (long index = start; index < id3; index += prime)
					{
						result[(int) index] = false;
					}
				}
			}

			public void id30()
			{
				Arrays.fill(this.isPrime, true);
				this.primes.forEach(prime -> filter(prime, isPrime));
				for (int index = 0; index < id3; index++)
				{
					if (isPrime[index])
					{
						this.primes.add(this.id20 + index);
						filter(this.id20 + index, isPrime);
					}
				}
				this.id20 += id3;
			}

			@Override
			public Long get()
			{
				while (this.primes.size() <= this.index)
				{
					id30();
				}
				Long result = this.primes.get(this.index);
				this.index += 1;
				return result;
			}
		});
	}

	public static void main(String[] args)
	{
		try
		{
			solve();
		} catch (IOException exception)
		{
			exception.printStackTrace();
		}
		close();
	}

	static class Station implements Comparable<Station>
	{
		public final int x;
		public final int r;
		public final int f;

		public Station(int x, int r, int f)
		{
			this.x = x;
			this.r = r;
			this.f = f;
		}

		public int getX()
		{
			return this.x;
		}

		public int getR()
		{
			return this.r;
		}

		public int id28()
		{
			return this.x - this.r;
		}

		public int id9()
		{
			return this.x + this.r;
		}

		@Override
		public int compareTo(Station that)
		{
			return Integer.compare(this.x, that.x);
		}
	}

	static class ListStations extends ArrayList<Station>
	{
	}

	public static final int id19 = 10 * 10 * 10 * 10;

	public static long solveFrequency(ListStations stationsInside, ListStations id24)
	{
		long result = 0;
		int index = 0;
		id11<Integer> id13 = new id11<>();
		for (Station station : id24)
		{
			while (index < stationsInside.size() && stationsInside.get(index).id28() <= station.getX())
			{
				id13.add(stationsInside.get(index).getX());
				index += 1;
			}
			result += id13.id8(station.getX() + 1, station.id9() + 1);
		}
		return result;
	}

	public static long solve(Station[] stations, int k)
	{
		ListStations[] id17 = new ListStations[id19];
		ListStations[] id14 = new ListStations[id19];
		for (int index = 0; index < id19; index++)
		{
			id17[index] = new ListStations();
			id14[index] = new ListStations();
		}
		Arrays.sort(stations, Comparator.comparing(Station::id28));
		for (Station station : stations)
		{
			id17[station.f].add(station);
		}
		Arrays.sort(stations);
		for (Station station : stations)
		{
			for (int frequency = Math.max(0, station.f - k); frequency <= Math.min(id19 - 1, station.f + k); frequency++)
			{
				id14[frequency].add(station);
			}
		}
		long result = 0;
		for (int frequency = 0; frequency < id19; frequency++)
		{
			result += solveFrequency(id17[frequency], id14[frequency]);
		}
		return result;

	}

	public static void solve() throws IOException
	{
		int n = nextInt();
		int k = nextInt();
		Station[] stations = new Station[n];
		for (int index = 0; index < n; index++)
		{
			stations[index] = new Station(nextInt(), nextInt(), nextInt() - 1);
		}
		out.println(solve(stations, k));
	}
}