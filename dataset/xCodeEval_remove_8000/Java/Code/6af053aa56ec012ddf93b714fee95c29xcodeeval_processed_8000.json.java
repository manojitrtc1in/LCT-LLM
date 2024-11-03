import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.AbstractMap;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Comparator;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.NoSuchElementException;
import java.util.Set;
import java.util.SortedMap;
import java.util.SortedSet;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.function.BiConsumer;
import java.util.function.Consumer;
import java.util.function.Function;
import java.util.function.Supplier;
import java.util.stream.Stream;

public class id23
{
	public static final long[] POWER2 = id25();
	public static final IteratorBuffer id34 = new IteratorBuffer(streamPrime(1000000).iterator());
	private static BufferedReader id38 = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer stringTokenizer = null;
	private static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

	interface id52<Type0, Type1, TypeResult>
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

		public String toString()
		{
			String result = "[";
			for (Object object : this.array)
			{
				result += object + ", ";
			}
			result += "]";
			return result;
		}
	}

	static abstract class Edge<TypeVertex extends Vertex<TypeVertex, TypeEdge>, TypeEdge extends Edge<TypeVertex, TypeEdge>>
	{
		public final TypeVertex vertex0;
		public final TypeVertex vertex1;
		public final boolean bidirectional;

		public Edge(TypeVertex vertex0, TypeVertex vertex1, boolean bidirectional)
		{
			this.vertex0 = vertex0;
			this.vertex1 = vertex1;
			this.bidirectional = bidirectional;
			this.vertex0.edges.add(getThis());
			if (this.bidirectional)
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

		public void remove()
		{
			this.vertex0.edges.remove(getThis());
			if (this.bidirectional)
			{
				this.vertex1.edges.remove(getThis());
			}
		}

		public String toString()
		{
			return this.vertex0 + "->" + this.vertex1;
		}
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
		public static <TypeVertex extends Vertex<TypeVertex, TypeEdge>, TypeEdge extends Edge<TypeVertex, TypeEdge>> void id58(
				BiConsumer<TypeVertex, TypeEdge> id3,
				BiConsumer<TypeVertex, TypeEdge> id8,
				TypeVertex vertex,
				TypeEdge edge,
				Array<Boolean> visited
		)
		{
			if (!visited.get(vertex.index))
			{
				visited.set(vertex.index, true);
				id3.accept(vertex, edge);
				for (TypeEdge edgeNext : vertex.edges)
				{
					TypeVertex vertexNext = edgeNext.other(vertex);
					id58(
							id3,
							id8,
							vertexNext,
							edgeNext,
							visited);
				}
				id8.accept(vertex, edge);
			}
		}

		public static <TypeVertex extends Vertex<TypeVertex, TypeEdge>, TypeEdge extends Edge<TypeVertex, TypeEdge>> void id58(
				Array<TypeVertex> vertices,
				int id43,
				BiConsumer<TypeVertex, TypeEdge> id3,
				BiConsumer<TypeVertex, TypeEdge> id8
		)
		{
			Array<Boolean> visited = new Array(vertices.size(), false);
			id58(
					id3,
					id8,
					vertices.get(id43),
					null,
					visited);
		}

		public static <TypeVertex extends Vertex<TypeVertex, TypeEdge>, TypeEdge extends Edge<TypeVertex, TypeEdge>, TypeResult> TypeResult id4(
				TypeVertex vertex,
				TypeEdge edge,
				id52<TypeVertex, TypeEdge, TypeResult> function,
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

		public static <TypeVertex extends Vertex<TypeVertex, TypeEdge>, TypeEdge extends Edge<TypeVertex, TypeEdge>, TypeResult> TypeResult id4(
				Array<TypeVertex> vertices,
				int id43,
				id52<TypeVertex, TypeEdge, TypeResult> function,
				TypeResult result
		)
		{
			Array<Boolean> visited = new Array(vertices.size(), false);
			FIFO<TypeVertex> verticesNext = new FIFO<>();
			verticesNext.push(vertices.get(id43));
			FIFO<TypeEdge> edgesNext = new FIFO<>();
			edgesNext.push(null);
			while (!verticesNext.isEmpty())
			{
				result = id4(verticesNext.pop(), edgesNext.pop(), function, visited, verticesNext, edgesNext, result);
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

		public String toString()
		{
			return "" + this.index;
		}
	}

	public static class VertexDefault<TypeEdge extends Edge<VertexDefault<TypeEdge>, TypeEdge>> extends Vertex<VertexDefault<TypeEdge>, TypeEdge>
	{
		public VertexDefault(int index)
		{
			super(index);
		}
	}

	public static class id1 extends Vertex<id1, id2>
	{
		public id1(int index)
		{
			super(index);
		}
	}

	public static class id2 extends Edge<id1, id2>
	{
		public id2(id1 vertex0, id1 vertex1, boolean bidirectional)
		{
			super(vertex0, vertex1, bidirectional);
		}

		@Override
		public id2 getThis()
		{
			return this;
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

		public String toString()
		{
			return "(" + this.v0 + ", " + this.v1 + ")";
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

	public static class id56<Type0 extends Comparable<? super Type0>, Type1 extends Comparable<? super Type1>> extends Tuple2<Type0, Type1> implements Comparable<id56<Type0, Type1>>
	{
		public id56(Type0 v0, Type1 v1)
		{
			super(v0, v1);
		}

		@Override
		public int compareTo(id56<Type0, Type1> that)
		{
			int result = this.v0.compareTo(that.v0);
			if (result == 0)
			{
				result = this.v1.compareTo(that.v1);
			}
			return result;
		}
	}

	public static class id45<Type>
	{
		public final Type element;
		public id45<Type> next;

		public id45(Type element, id45<Type> next)
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

	public static class id17<Type> implements SortedSet<Type>
	{
		public static int height(id17.Node node)
		{
			return node == null ? 0 : node.height;
		}

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

		public Comparator<? super Type> comparator;
		public Node root;

		public id17(Comparator<? super Type> comparator)
		{
			this(comparator, null);
		}

		private id17(Comparator<? super Type> comparator, Node root)
		{
			this.comparator = comparator;
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
				int compare = this.comparator.compare(value, node.value);
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
				int compare = this.comparator.compare(value, node.value);
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
				int compare = this.comparator.compare(value, node.value);
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
				result = balance(result);
			}
			return result;
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
				int compare = this.comparator.compare(value, node.value);
				if (compare == 0)
				{
					result = new Node(value, node.left, node.right);
					;
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
				int compare = this.comparator.compare(value, node.value);
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
				result = balance(result);
			}
			return result;
		}

		public void id7(Node node, Consumer<Type> consumer)
		{
			if (node != null)
			{
				id7(node.left, consumer);
				consumer.accept(node.value);
				id7(node.right, consumer);
			}
		}

		@Override
		public Comparator<? super Type> comparator()
		{
			throw new UnsupportedOperationException();
		}

		public Type get(Type value)
		{
			Node node = get(this.root, value);
			return node == null ? null : node.value;
		}

		@Override
		public id17<Type> subSet(Type valueStart, Type valueEnd)
		{
			return tailSet(valueStart).headSet(valueEnd);
		}

		@Override
		public id17<Type> headSet(Type valueEnd)
		{
			return new id17<Type>(this.comparator, head(this.root, valueEnd));
		}

		@Override
		public id17<Type> tailSet(Type valueStart)
		{
			return new id17<Type>(this.comparator, tail(this.root, valueStart));
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
			Stack<Node> path = new Stack<>();

			return new Iterator<Type>()
			{
				{
					push(id17.this.root);
				}

				public void push(Node node)
				{
					while (node != null)
					{
						path.push(node);
						node = node.left;
					}
				}

				@Override
				public boolean hasNext()
				{
					return !path.isEmpty();
				}

				@Override
				public Type next()
				{
					if (path.isEmpty())
					{
						throw new NoSuchElementException();
					}
					else
					{
						Node node = path.peek();
						Type result = node.value;
						if (node.right != null)
						{
							push(node.right);
						}
						else
						{
							do
							{
								node = path.pop();
							}
							while (!path.isEmpty() && path.peek().right == node);
						}
						return result;
					}
				}
			};
		}

		@Override
		public Object[] toArray()
		{
			List<Object> list = new ArrayList<>();
			id7(this.root, list::add);
			return list.toArray();
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

		@Override
		public String toString()
		{
			String result = "{";
			Iterator iterator = iterator();
			while (iterator.hasNext())
			{
				result += iterator.next() + (iterator.hasNext() ? ", " : "");
			}
			result += "}";
			return result;
		}
	}

	public static class id24<TypeKey, TypeValue> implements SortedMap<TypeKey, TypeValue>
	{
		public final Comparator<? super TypeKey> comparator;
		public final id17<Entry<TypeKey, TypeValue>> entrySet;

		public id24(Comparator<? super TypeKey> comparator)
		{
			this(comparator, new id17<>((entry0, entry1) -> comparator.compare(entry0.getKey(), entry1.getKey())));
		}

		private id24(Comparator<? super TypeKey> comparator, id17<Entry<TypeKey, TypeValue>> entrySet)
		{
			this.comparator = comparator;
			this.entrySet = entrySet;
		}

		@Override
		public Comparator<? super TypeKey> comparator()
		{
			return this.comparator;
		}

		@Override
		public SortedMap<TypeKey, TypeValue> subMap(TypeKey keyStart, TypeKey keyEnd)
		{
			return new id24<>(this.comparator, this.entrySet.subSet(new AbstractMap.SimpleEntry<>(keyStart, null), new AbstractMap.SimpleEntry<>(keyEnd, null)));
		}

		@Override
		public SortedMap<TypeKey, TypeValue> headMap(TypeKey keyEnd)
		{
			return new id24<>(this.comparator, this.entrySet.headSet(new AbstractMap.SimpleEntry<>(keyEnd, null)));
		}

		@Override
		public SortedMap<TypeKey, TypeValue> tailMap(TypeKey keyStart)
		{
			return new id24<>(this.comparator, this.entrySet.tailSet(new AbstractMap.SimpleEntry<>(keyStart, null)));
		}

		public Entry<TypeKey, TypeValue> firstEntry()
		{
			return this.entrySet.first();
		}

		@Override
		public TypeKey firstKey()
		{
			return firstEntry().getKey();
		}

		public Entry<TypeKey, TypeValue> lastEntry()
		{
			return this.entrySet.last();
		}

		@Override
		public TypeKey lastKey()
		{
			return lastEntry().getKey();
		}

		@Override
		public int size()
		{
			return this.entrySet().size();
		}

		@Override
		public boolean isEmpty()
		{
			return this.entrySet.isEmpty();
		}

		@Override
		public boolean containsKey(Object key)
		{
			return this.entrySet().contains(key);
		}

		@Override
		public boolean containsValue(Object value)
		{
			throw new UnsupportedOperationException();
		}

		@Override
		public TypeValue get(Object key)
		{
			Entry<TypeKey, TypeValue> entry = new AbstractMap.SimpleEntry<>((TypeKey) key, null);
			entry = this.entrySet.get(entry);
			return entry == null ? null : entry.getValue();
		}

		@Override
		public TypeValue put(TypeKey key, TypeValue value)
		{
			TypeValue result = get(key);
			Entry<TypeKey, TypeValue> entry = new AbstractMap.SimpleEntry<>(key, value);
			this.entrySet().add(entry);
			return result;
		}

		@Override
		public TypeValue remove(Object key)
		{
			TypeValue result = get(key);
			Entry<TypeKey, TypeValue> entry = new AbstractMap.SimpleEntry<>((TypeKey) key, null);
			this.entrySet.remove(entry);
			return result;
		}

		@Override
		public void putAll(Map<? extends TypeKey, ? extends TypeValue> map)
		{
			map.entrySet().stream()
					.forEach(entry -> put(entry.getKey(), entry.getValue()));
		}

		@Override
		public void clear()
		{
			this.entrySet.clear();
		}

		@Override
		public Set<TypeKey> keySet()
		{
			throw new UnsupportedOperationException();
		}

		@Override
		public Collection<TypeValue> values()
		{
			throw new UnsupportedOperationException();
		}

		@Override
		public id17<Entry<TypeKey, TypeValue>> entrySet()
		{
			return this.entrySet;
		}

		@Override
		public String toString()
		{
			return this.entrySet().toString();
		}
	}

	public static class FIFO<Type>
	{
		public id45<Type> start;
		public id45<Type> end;

		public FIFO()
		{
			this.start = null;
			this.end = null;
		}

		public boolean isEmpty()
		{
			return this.start == null;
		}

		public Type peek()
		{
			return this.start.element;
		}

		public Type pop()
		{
			Type result = this.start.element;
			this.start = this.start.next;
			return result;
		}

		public void push(Type element)
		{
			id45<Type> list = new id45<>(element, null);
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
	}

	public static class MapCount<Type> extends id24<Type, Long>
	{
		private int count;

		public MapCount(Comparator<? super Type> comparator)
		{
			super(comparator);
			this.count = 0;
		}

		public long add(Type key, Long delta)
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
			this.count += result;
			return result;
		}

		public List<Type> flatten()
		{
			List<Type> result = new ArrayList<>();
			for (Entry<Type, Long> entry : entrySet())
			{
				for (long index = 0; index < entry.getValue(); index++)
				{
					result.add(entry.getKey());
				}
			}
			return result;
		}

		public long remove(Type key, Long delta)
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
			this.count -= result;
			return result;
		}

		public int count()
		{
			return this.count;
		}
	}

	public static class MapSet<TypeKey, TypeValue> extends id24<TypeKey, id17<TypeValue>> implements Iterable<TypeValue>
	{
		private Comparator<? super TypeValue> id50;
		private int count;

		public MapSet(Comparator<? super TypeKey> id26, Comparator<? super TypeValue> id50)
		{
			super(id26);
			this.count = 0;
			this.id50 = id50;
		}

		public TypeValue firstValue()
		{
			TypeValue result;
			Entry<TypeKey, id17<TypeValue>> firstEntry = firstEntry();
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
				Iterator<id17<TypeValue>> iteratorValues = values().iterator();
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
			Entry<TypeKey, id17<TypeValue>> lastEntry = lastEntry();
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
			id17<TypeValue> set = get(key);
			if (set == null)
			{
				set = new id17<>(id50);
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

		public boolean removeSet(TypeKey key, TypeValue value)
		{
			boolean result;
			id17<TypeValue> set = get(key);
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
		public id17<TypeValue> remove(Object key)
		{
			id17<TypeValue> result = super.remove(key);
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
			stringTokenizer = new StringTokenizer(id38.readLine());
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
		return id38.readLine();
	}

	public static void close()
	{
		out.close();
	}

	public static int id18(Function<Integer, Boolean> filter, int start, int end)
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
				result = id18(filter, start, middle);
			}
			else
			{
				result = id18(filter, middle + 1, end);
			}
		}
		return result;
	}

	public static int id14(Function<Integer, Boolean> filter, int start, int end)
	{
		return -id18(x -> filter.apply(-x), -end, -start);
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
		Iterator<Long> primes = id34.iterator();
		Long prime;
		while (value > 1 && (prime = primes.next()) * prime <= value)
		{
			while (value % prime == 0)
			{
				result.add(prime);
				value /= prime;
			}
		}
		if (value > 1)
		{
			result.add(value);
		}
		return result;
	}

	public static long gcd(long a, long b)
	{
		while (a != 0 && b != 0)
		{
			if (a > b)
			{
				a %= b;
			}
			else
			{
				b %= a;
			}
		}
		return a + b;
	}

	public static long[] id25()
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
		Iterator<Long> iterator = id34.iterator();
		Long prime;
		while ((prime = iterator.next()) * prime <= x)
		{
			result &= x % prime > 0;
		}
		return result;
	}

	public static long knapsack(List<Tuple3<Long, Integer, Integer>> id36, int weightMaximum)
	{
		long[] valuesMaximum = new long[weightMaximum + 1];
		for (Tuple3<Long, Integer, Integer> itemValueWeightCount : id36)
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

	public static boolean id39(List<Tuple2<Integer, Integer>> id28, int weightMaximum)
	{
		boolean[] weightPossible = new boolean[weightMaximum + 1];
		weightPossible[0] = true;
		int weightLargest = 0;
		for (Tuple2<Integer, Integer> itemWeightCount : id28)
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

	public static Stream<BigInteger> id10()
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

	public static Stream<Long> streamPrime(int id5)
	{
		return Stream.generate(new Supplier<Long>()
		{
			private boolean[] isPrime = new boolean[id5];
			private long id35 = 2;
			private List<Long> primes = new ArrayList<>();
			private int index = 0;

			public void filter(long prime, boolean[] result)
			{
				if (prime * prime < this.id35 + id5)
				{
					long remainingStart = this.id35 % prime;
					long start = remainingStart == 0 ? 0 : prime - remainingStart;
					for (long index = start; index < id5; index += prime)
					{
						result[(int) index] = false;
					}
				}
			}

			public void id53()
			{
				Arrays.fill(this.isPrime, true);
				this.primes.forEach(prime -> filter(prime, isPrime));
				for (int index = 0; index < id5; index++)
				{
					if (isPrime[index])
					{
						this.primes.add(this.id35 + index);
						filter(this.id35 + index, isPrime);
					}
				}
				this.id35 += id5;
			}

			@Override
			public Long get()
			{
				while (this.primes.size() <= this.index)
				{
					id53();
				}
				Long result = this.primes.get(this.index);
				this.index += 1;
				return result;
			}
		});
	}

	public static <Type> List<List<Type>> id11(List<Type> list)
	{
		List<List<Type>> result = new ArrayList<>();
		result.add(new ArrayList<>());
		for (Type element : list)
		{
			List<List<Type>> id11 = result;
			result = new ArrayList<>();
			for (List<Type> permutation : id11)
			{
				for (int index = 0; index <= permutation.size(); index++)
				{
					List<Type> id41 = new ArrayList<>(permutation);
					id41.add(index, element);
					result.add(id41);
				}
			}
		}
		return result;
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

	public static int compare(id1 vertex0,
							  id1 vertex1,
							  id1 id29,
							  id1 id15,
							  int depth
	)
	{
		int result = 0;
		if (depth > 0)
		{
			MapCount<id1> id42 = new MapCount<>((vertexA, vertexB) -> compare(vertexA, vertexB, vertex0, vertex0, depth - 1));
			vertex0.edges.stream()
					.map(edge -> edge.other(vertex0))
					.filter(vertex -> vertex != id29)
					.forEach(vertex -> id42.add(vertex, 1L));
			MapCount<id1> id13 = new MapCount<>((vertexA, vertexB) -> compare(vertexA, vertexB, vertex1, vertex1, depth - 1));
			vertex1.edges.stream()
					.map(edge -> edge.other(vertex1))
					.filter(vertex -> vertex != id15)
					.forEach(vertex -> id13.add(vertex, 1L));
			Iterator<Map.Entry<id1, Long>> iterator0 = id42.entrySet.iterator();
			Iterator<Map.Entry<id1, Long>> iterator1 = id13.entrySet.iterator();
			while (result == 0 && iterator0.hasNext() && iterator1.hasNext())
			{
				Map.Entry<id1, Long> entry0 = iterator0.next();
				Map.Entry<id1, Long> entry1 = iterator1.next();
				id1 id37 = entry0.getKey();
				Long count0 = entry0.getValue();
				id1 id46 = entry1.getKey();
				Long count1 = entry1.getValue();
				result = compare(id37, id46, vertex0, vertex1, depth - 1);
				if (result == 0)
				{
					result = Long.compare(count0, count1);
				}
			}
			if (iterator0.hasNext())
			{
				result = 1;
			}
			if (iterator1.hasNext())
			{
				result = -1;
			}
		}
		return result;
	}

	public static int compare(
			id1 vertex0,
			id1 vertex1,
			int depth
	)
	{
		return compare(vertex0, vertex1, null, null, depth);
	}


	public static MapCount<id1> mapCount
			(
					id1 vertex,
					id1 vertexFrom,
					int depth
			)
	{
		MapCount<id1> result = new MapCount<>((vertexA, vertexB) -> compare(vertexA, vertexB, vertex, vertex, depth - 1));
		vertex.edges.stream()
				.map(edge -> edge.other(vertex))
				.filter(vertexTo -> vertexTo != vertexFrom)
				.forEach(vertexTo -> result.add(vertexTo, 1L));
		return result;
	}


	public static List<List<Integer>> combinations(int n, int k)
	{
		List<List<Integer>> result = new ArrayList<>();
		if (k == 0)
		{
		}
		else
		{
			if (k == 1)
			{
				List<Integer> combination = new ArrayList<>();
				combination.add(n);
				result.add(combination);
			}
			else
			{
				for (int index = 0; index <= n; index++)
				{
					for (List<Integer> combination : combinations(n - index, k - 1))
					{
						combination.add(index);
						result.add(combination);
					}
				}
			}
		}
		return result;
	}

	public static final int[][][][] id47 = new int[15][1000][][];

	public static int[][] id31(int n, int k)
	{
		int[][] result = id47[n][k];
		if (result == null)
		{
			List<List<Integer>> combinations = combinations(n, k);
			result = new int[combinations.size()][k];
			for (int indexCombination = 0; indexCombination < combinations.size(); indexCombination++)
			{
				for (int indexK = 0; indexK < k; indexK++)
				{
					result[indexCombination][indexK] = combinations.get(indexCombination).get(indexK);
				}
			}
			id47[n][k] = result;
		}
		return result;
	}

	public static BigInteger id44 = BigInteger.valueOf(1000000000 + 7);

	public static BigInteger id19
			(
					List<id1> id51,
					List<Long> id21,
					List<id1> id57,
					List<Long> id27,
					BigInteger[][] id6,
					int indexT
			)
	{
		BigInteger result;
		if (indexT < id57.size())
		{
			int countT = id27.get(indexT).intValue();
			result = BigInteger.ZERO;
			for (int[] combination : id31(countT, id51.size()))
			{
				boolean validCombination = true;
				for (int indexS = 0; indexS < id51.size(); indexS++)
				{
					long countS = id21.get(indexS);
					int id54 = combination[indexS];
					if (id54 > 0)
					{
						validCombination &= BigInteger.ZERO.compareTo(id6[indexS][indexT]) < 0;
						validCombination &= id54 <= countS;
					}
				}

				if (validCombination)
				{
					BigInteger product = BigInteger.ONE;

					for (int indexS = 0; indexS < id51.size(); indexS++)
					{
						long countS = id21.get(indexS);
						int id54 = combination[indexS];
						for (int index = 0; index < id54; index++)
						{
							product = product.multiply(BigInteger.valueOf(countS));
							product = product.divide(BigInteger.valueOf(index + 1));
							product = product.multiply(id6[indexS][indexT]);
							countS -= 1;
						}
						id21.set(indexS, countS);
					}

					product =product.multiply(id19
							(
									id51,
									id21,
									id57,
									id27,
									id6,
									indexT + 1
							));
					result = result.add(product);

					for (int indexS = 0; indexS < id51.size(); indexS++)
					{
						long countS = id21.get(indexS);
						int id54 = combination[indexS];
						countS += id54;
						id21.set(indexS, countS);
					}
				}
			}
		}
		else
		{
			result = BigInteger.ONE;
		}
		return result;
	}

	public static BigInteger count(id1 vertexS,
							 id1 vertexT,
							 id1 id40,
							 id1 id22,
							 int depth
	)
	{
		MapCount<id1> id9 = mapCount(vertexS, id40, depth);
		MapCount<id1> id55 = mapCount(vertexT, id22, depth);
		List<id1> id51 = new ArrayList<>();
		List<Long> id21 = new ArrayList<>();
		id9.entrySet().forEach(entry ->
		{
			id51.add(entry.getKey());
			id21.add(entry.getValue());
		});
		List<id1> id57 = new ArrayList<>();
		List<Long> id27 = new ArrayList<>();
		id55.entrySet().forEach(entry ->
		{
			id57.add(entry.getKey());
			id27.add(entry.getValue());
		});
		BigInteger[][] id6 = new BigInteger[id51.size()][id57.size()];
		for (int indexS = 0; indexS < id51.size(); indexS++)
		{
			id1 id49 = id51.get(indexS);
			for (int indexT = 0; indexT < id57.size(); indexT++)
			{
				id1 id33 = id57.get(indexT);
				id6[indexS][indexT] = count(id49, id33, vertexS, vertexT, depth - 1);
			}
		}
		return id19
				(
						id51,
						id21,
						id57,
						id27,
						id6,
						0
				);
	}

	public static int depth(id1 vertex, id1 vertexFrom)
	{
		return vertex.edges.stream()
				.map(edge -> edge.other(vertex))
				.filter(vertexTo -> vertexTo != vertexFrom)
				.map(vertexTo -> 1 + depth(vertexTo, vertex))
				.reduce(0, (x, y) -> Math.max(x, y));
	}

	public static id1 id16(Array<id1> vertices)
	{
		id1 result = null;
		int minimum = 12;
		for (id1 vertex : vertices)
		{
			int depth = depth(vertex, null);
			if (depth < minimum)
			{
				result = vertex;
				minimum = depth;
			}
		}
		return result;
	}

	public static int id12(Array<id1> vertices, id1 root)
	{
		int result = 0;
		int depthRoot = depth(root, null);
		for (id1 vertex : vertices)
		{
			int depthVertex = depth(vertex, null);
			if (compare(vertex, root, Math.max(depthRoot, depthVertex)) == 0)
			{
				result += 1;
			}
		}
		return result;
	}

	public static long solve(Array<id1> verticesS, Array<id1> verticesT, int depthExtra)
	{
		BigInteger result = BigInteger.ZERO;
		id1 vertexT = id16(verticesT);
		int depth = depth(vertexT, null);
		for (id1 vertexS : verticesS)
		{
			result = result.add(count
					(
							vertexS,
							vertexT,
							null,
							null,
							depth + depthExtra
					));
		}
		result = result .divide(BigInteger.valueOf(id12(verticesT, vertexT)));
		result = result.mod(id44);
		return result.longValue();
	}

	public static Array<Tuple2<Integer, Integer>> readEdges() throws IOException
	{
		int n = nextInt();
		Array<Tuple2<Integer, Integer>> result = new Array<>(n - 1);
		for (int index = 0; index < n - 1; index++)
		{
			result.set(index, new Tuple2<>(nextInt() - 1, nextInt() - 1));
		}
		return result;
	}

	public static Array<id1> vertices(int n)
	{
		Array<id1> result = new Array<>(n);
		for (int index = 0; index < n; index++)
		{
			result.set(index, new id1(index));
		}
		return result;
	}

	public static Array<id2> edges(Array<id1> vertices, Array<Tuple2<Integer, Integer>> id20)
	{
		Array<id2> result = new Array<>(id20.size());
		for (int index = 0; index < id20.size(); index++)
		{
			Tuple2<Integer, Integer> edgeTuple = id20.get(index);
			id1 vertexFrom = vertices.get(edgeTuple.v0);
			id1 vertexTo = vertices.get(edgeTuple.v1);
			id2 edge = new id2(vertexFrom, vertexTo, true);
			result.set(index, edge);
		}
		return result;
	}

	public static long id32
			(
					Array<Tuple2<Integer, Integer>> id30,
					Array<Tuple2<Integer, Integer>> id48,
					int depthExtra
			)
	{
		Array<id1> verticesS = vertices(id30.size() + 1);
		Array<id1> verticesT = vertices(id48.size() + 1);
		edges(verticesS, id30);
		edges(verticesT, id48);
		return solve(verticesS, verticesT, depthExtra);
	}

	public static long id32
			(
					Array<Tuple2<Integer, Integer>> id30,
					Array<Tuple2<Integer, Integer>> id48
			)
	{
		return id32(id30, id48, 0);
	}

	public static void solve() throws IOException
	{
		Array<Tuple2<Integer, Integer>> id30 = readEdges();
		Array<Tuple2<Integer, Integer>> id48 = readEdges();










		{
			out.println(id32(id30, id48));
		}
	}

}