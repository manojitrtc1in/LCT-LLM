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

public class id13
{
	public static final long[] POWER2 = id17();
	public static final IteratorBuffer id22 = new IteratorBuffer(streamPrime(1000000).iterator());
	private static BufferedReader id27 = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer stringTokenizer = null;
	private static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

	interface id35<Type0, Type1, TypeResult>
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

		@Override
		public String toString()
		{
			return "[" + id13.toString(this, ", ") + "]";
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

		@Override
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

		public static <TypeVertex extends Vertex<TypeVertex, TypeEdge>, TypeEdge extends Edge<TypeVertex, TypeEdge>> void id38(
				Array<TypeVertex> vertices,
				int id30,
				BiConsumer<TypeVertex, TypeEdge> id3,
				BiConsumer<TypeVertex, TypeEdge> id8
		)
		{
			boolean[] isVisited = new boolean[vertices.size()];
			boolean[] id34 = new boolean[vertices.size()];
			Stack<TypeVertex> stackVertices = new Stack<>();
			Stack<TypeEdge> stackEdges = new Stack<>();
			TypeVertex vertexStart = vertices.get(id30);
			stackVertices.push(vertexStart);
			stackEdges.push(null);
			id34[vertexStart.index] = true;
			while (!stackVertices.isEmpty())
			{
				TypeVertex vertex = stackVertices.peek();
				TypeEdge edge = stackEdges.peek();
				if (isVisited[vertex.index])
				{
					id8.accept(vertex, edge);
					stackVertices.pop();
					stackEdges.pop();
				}
				else
				{
					id3.accept(vertex, edge);
					isVisited[vertex.index] = true;
					for (TypeEdge edgeTo : vertex.edges)
					{
						TypeVertex vertexTo = edgeTo.other(vertex);
						if (!id34[vertexTo.index])
						{
							stackVertices.push(vertexTo);
							stackEdges.push(edgeTo);
							id34[vertexTo.index] = true;
						}
					}
				}
			}
		}

		public static <TypeVertex extends Vertex<TypeVertex, TypeEdge>, TypeEdge extends Edge<TypeVertex, TypeEdge>> void id38(
				Array<TypeVertex> vertices,
				int id30,
				Consumer<TypeVertex> id3,
				Consumer<TypeVertex> id8
		)
		{
			id38(
					vertices,
					id30,
					(vertex, edge) -> id3.accept(vertex),
					(vertex, edge) -> id8.accept(vertex)
			);
		}

		public static <TypeVertex extends Vertex<TypeVertex, TypeEdge>, TypeEdge extends Edge<TypeVertex, TypeEdge>, TypeResult> TypeResult id4(
				TypeVertex vertex,
				TypeEdge edge,
				id35<TypeVertex, TypeEdge, TypeResult> function,
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
				int id30,
				id35<TypeVertex, TypeEdge, TypeResult> function,
				TypeResult result
		)
		{
			Array<Boolean> visited = new Array(vertices.size(), false);
			FIFO<TypeVertex> verticesNext = new FIFO<>();
			verticesNext.push(vertices.get(id30));
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

		@Override
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
		public static Array<id1> vertices(int n)
		{
			Array<id1> result = new Array<id1>(n);
			for (int index = 0; index < n; index++)
			{
				result.set(index, new id1(index));
			}
			return result;
		}

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

		@Override
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

		@Override
		public String toString()
		{
			return this.value.toString();
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

		@Override
		public String toString()
		{
			return "(" + this.v0 + ", " + this.v1 + ", " + this.v2 + ")";
		}
	}

	public static class id37<Type0 extends Comparable<? super Type0>, Type1 extends Comparable<? super Type1>> extends Tuple2<Type0, Type1> implements Comparable<id37<Type0, Type1>>
	{
		public id37(Type0 v0, Type1 v1)
		{
			super(v0, v1);
		}

		@Override
		public int compareTo(id37<Type0, Type1> that)
		{
			int result = this.v0.compareTo(that.v0);
			if (result == 0)
			{
				result = this.v1.compareTo(that.v1);
			}
			return result;
		}
	}

	public static class id32<Type>
	{
		public final Type element;
		public id32<Type> next;

		public id32(Type element, id32<Type> next)
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

	public static class Node<Type>
	{
		public static <Type> Node<Type> balance(Node<Type> result)
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

		public static <Type> Node<Type> clone(Node<Type> result)
		{
			if (result != null)
			{
				result = new Node(result.value, clone(result.left), clone(result.right));
			}
			return result;
		}

		public static <Type> Node<Type> delete(Node<Type> node, Type value, Comparator<? super Type> comparator)
		{
			Node<Type> result;
			if (node == null)
			{
				result = null;
			}
			else
			{
				int compare = comparator.compare(value, node.value);
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
							Node<Type> first = first(node.right);
							result = new Node(first.value, node.left, delete(node.right, first.value, comparator));
						}
					}
				}
				else
				{
					if (compare < 0)
					{
						result = new Node(node.value, delete(node.left, value, comparator), node.right);
					}
					else
					{
						result = new Node(node.value, node.left, delete(node.right, value, comparator));
					}
				}
				result = balance(result);
			}
			return result;
		}

		public static <Type> Node<Type> first(Node<Type> result)
		{
			while (result.left != null)
			{
				result = result.left;
			}
			return result;
		}

		public static <Type> Node<Type> get(Node<Type> node, Type value, Comparator<? super Type> comparator)
		{
			Node<Type> result;
			if (node == null)
			{
				result = null;
			}
			else
			{
				int compare = comparator.compare(value, node.value);
				if (compare == 0)
				{
					result = node;
				}
				else
				{
					if (compare < 0)
					{
						result = get(node.left, value, comparator);
					}
					else
					{
						result = get(node.right, value, comparator);
					}
				}
			}
			return result;
		}

		public static <Type> Node<Type> head(Node<Type> node, Type value, Comparator<? super Type> comparator)
		{
			Node<Type> result;
			if (node == null)
			{
				result = null;
			}
			else
			{
				int compare = comparator.compare(value, node.value);
				if (compare == 0)
				{
					result = node.left;
				}
				else
				{
					if (compare < 0)
					{
						result = head(node.left, value, comparator);
					}
					else
					{
						result = new Node(node.value, node.left, head(node.right, value, comparator));
					}
				}
				result = balance(result);
			}
			return result;
		}

		public static int height(Node node)
		{
			return node == null ? 0 : node.height;
		}

		public static <Type> Node<Type> insert(Node<Type> node, Type value, Comparator<? super Type> comparator)
		{
			Node<Type> result;
			if (node == null)
			{
				result = new Node(value, null, null);
			}
			else
			{
				int compare = comparator.compare(value, node.value);
				if (compare == 0)
				{
					result = new Node(value, node.left, node.right);
					;
				}
				else
				{
					if (compare < 0)
					{
						result = new Node(node.value, insert(node.left, value, comparator), node.right);
					}
					else
					{
						result = new Node(node.value, node.left, insert(node.right, value, comparator));
					}
				}
				result = balance(result);
			}
			return result;
		}

		public static <Type> Node<Type> last(Node<Type> result)
		{
			while (result.right != null)
			{
				result = result.right;
			}
			return result;
		}

		public static int size(Node node)
		{
			return node == null ? 0 : node.size;
		}

		public static <Type> Node<Type> tail(Node<Type> node, Type value, Comparator<? super Type> comparator)
		{
			Node<Type> result;
			if (node == null)
			{
				result = null;
			}
			else
			{
				int compare = comparator.compare(value, node.value);
				if (compare == 0)
				{
					result = new Node(node.value, null, node.right);
				}
				else
				{
					if (compare < 0)
					{
						result = new Node(node.value, tail(node.left, value, comparator), node.right);
					}
					else
					{
						result = tail(node.right, value, comparator);
					}
				}
				result = balance(result);
			}
			return result;
		}

		public static <Type> void id7(Node<Type> node, Consumer<Type> consumer)
		{
			if (node != null)
			{
				id7(node.left, consumer);
				consumer.accept(node.value);
				id7(node.right, consumer);
			}
		}

		public final Type value;
		public final Node<Type> left;
		public final Node<Type> right;
		public final int size;
		private final int height;

		public Node(Type value, Node<Type> left, Node<Type> right)
		{
			this.value = value;
			this.left = left;
			this.right = right;
			this.size = 1 + size(left) + size(right);
			this.height = 1 + Math.max(height(left), height(right));
		}

		public Node<Type> rotateLeft()
		{
			Node<Type> left = new Node(this.value, this.left, this.right.left);
			return new Node(this.right.value, left, this.right.right);
		}

		public Node<Type> rotateRight()
		{
			Node right = new Node(this.value, this.left.right, this.right);
			return new Node(this.left.value, this.left.left, right);
		}
	}

	public static class id12<Type> implements SortedSet<Type>
	{
		public Comparator<? super Type> comparator;
		public Node<Type> root;

		private id12(Comparator<? super Type> comparator, Node<Type> root)
		{
			this.comparator = comparator;
			this.root = root;
		}

		public id12(Comparator<? super Type> comparator)
		{
			this(comparator, null);
		}

		public id12(Collection<? extends Type> collection, Comparator<? super Type> comparator)
		{
			this(comparator, null);
			this.addAll(collection);
		}

		public id12(id12 id6)
		{
			this(id6.comparator, Node.clone(id6.root));
		}

		@Override
		public void clear()
		{
			this.root = null;
		}

		@Override
		public Comparator<? super Type> comparator()
		{
			return this.comparator;
		}

		public Type get(Type value)
		{
			Node<Type> node = Node.get(this.root, value, this.comparator);
			return node == null ? null : node.value;
		}

		@Override
		public id12<Type> subSet(Type valueStart, Type valueEnd)
		{
			return tailSet(valueStart).headSet(valueEnd);
		}

		@Override
		public id12<Type> headSet(Type valueEnd)
		{
			return new id12<>(this.comparator, Node.head(this.root, valueEnd, this.comparator));
		}

		@Override
		public id12<Type> tailSet(Type valueStart)
		{
			return new id12<>(this.comparator, Node.tail(this.root, valueStart, this.comparator));
		}

		@Override
		public Type first()
		{
			return Node.first(this.root).value;
		}

		@Override
		public Type last()
		{
			return Node.last(this.root).value;
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
			return Node.get(this.root, (Type) value, this.comparator) != null;
		}

		@Override
		public Iterator<Type> iterator()
		{
			Stack<Node<Type>> path = new Stack<>();

			return new Iterator<Type>()
			{
				{
					push(id12.this.root);
				}

				public void push(Node<Type> node)
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
						Node<Type> node = path.peek();
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
			Node.id7(this.root, list::add);
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
			this.root = Node.insert(this.root, value, this.comparator);
			return sizeBefore == size();
		}

		@Override
		public boolean remove(Object value)
		{
			int sizeBefore = size();
			this.root = Node.delete(this.root, (Type) value, this.comparator);
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
			id12<Type> set = new id12<>(this.comparator);
			collection.stream()
					.map(element -> (Type) element)
					.filter(this::contains)
					.forEach(set::add);
			boolean result = size() != set.size();
			this.root = set.root;
			return result;
		}

		@Override
		public boolean removeAll(Collection<?> collection)
		{
			return collection.stream()
					.map(this::remove)
					.reduce(true, (x, y) -> x | y);
		}

		@Override
		public String toString()
		{
			return "{" + id13.toString(this, ", ") + "}";
		}
	}

	public static class id16<TypeKey, TypeValue> implements SortedMap<TypeKey, TypeValue>
	{
		public final Comparator<? super TypeKey> comparator;
		public final id12<Entry<TypeKey, TypeValue>> entrySet;

		public id16(Comparator<? super TypeKey> comparator)
		{
			this(comparator, new id12<>((entry0, entry1) -> comparator.compare(entry0.getKey(), entry1.getKey())));
		}

		private id16(Comparator<? super TypeKey> comparator, id12<Entry<TypeKey, TypeValue>> entrySet)
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
			return new id16<>(this.comparator, this.entrySet.subSet(new AbstractMap.SimpleEntry<>(keyStart, null), new AbstractMap.SimpleEntry<>(keyEnd, null)));
		}

		@Override
		public SortedMap<TypeKey, TypeValue> headMap(TypeKey keyEnd)
		{
			return new id16<>(this.comparator, this.entrySet.headSet(new AbstractMap.SimpleEntry<>(keyEnd, null)));
		}

		@Override
		public SortedMap<TypeKey, TypeValue> tailMap(TypeKey keyStart)
		{
			return new id16<>(this.comparator, this.entrySet.tailSet(new AbstractMap.SimpleEntry<>(keyStart, null)));
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
			return new Collection<TypeValue>()
			{
				@Override
				public int size()
				{
					return id16.this.entrySet.size();
				}

				@Override
				public boolean isEmpty()
				{
					return id16.this.entrySet.isEmpty();
				}

				@Override
				public boolean contains(Object value)
				{
					throw new UnsupportedOperationException();
				}

				@Override
				public Iterator<TypeValue> iterator()
				{
					return new Iterator<TypeValue>()
					{
						Iterator<Entry<TypeKey, TypeValue>> iterator = id16.this.entrySet.iterator();

						@Override
						public boolean hasNext()
						{
							return this.iterator.hasNext();
						}

						@Override
						public TypeValue next()
						{
							return this.iterator.next().getValue();
						}
					};
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
				public boolean add(TypeValue typeValue)
				{
					throw new UnsupportedOperationException();
				}

				@Override
				public boolean remove(Object o)
				{
					throw new UnsupportedOperationException();
				}

				@Override
				public boolean containsAll(Collection<?> collection)
				{
					throw new UnsupportedOperationException();
				}

				@Override
				public boolean addAll(Collection<? extends TypeValue> collection)
				{
					throw new UnsupportedOperationException();
				}

				@Override
				public boolean removeAll(Collection<?> collection)
				{
					throw new UnsupportedOperationException();
				}

				@Override
				public boolean retainAll(Collection<?> collection)
				{
					throw new UnsupportedOperationException();
				}

				@Override
				public void clear()
				{
					throw new UnsupportedOperationException();
				}
			};
		}

		@Override
		public id12<Entry<TypeKey, TypeValue>> entrySet()
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
		public id32<Type> start;
		public id32<Type> end;

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
			id32<Type> list = new id32<>(element, null);
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

	public static class MapCount<Type> extends id16<Type, Long>
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

	public static class MapSet<TypeKey, TypeValue> extends id16<TypeKey, id12<TypeValue>> implements Iterable<TypeValue>
	{
		private Comparator<? super TypeValue> id33;
		private int count;

		public MapSet(Comparator<? super TypeKey> id18, Comparator<? super TypeValue> id33)
		{
			super(id18);
			this.count = 0;
			this.id33 = id33;
		}

		public MapSet(Comparator<? super TypeKey> id18, id12<Entry<TypeKey, id12<TypeValue>>> entrySet, Comparator<? super TypeValue> id33)
		{
			super(id18, entrySet);
			this.count = 0;
			this.id33 = id33;
		}

		public TypeValue firstValue()
		{
			TypeValue result;
			Entry<TypeKey, id12<TypeValue>> firstEntry = firstEntry();
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
				Iterator<id12<TypeValue>> iteratorValues = values().iterator();
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
			Entry<TypeKey, id12<TypeValue>> lastEntry = lastEntry();
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
			id12<TypeValue> set = get(key);
			if (set == null)
			{
				set = new id12<>(id33);
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
			id12<TypeValue> set = get(key);
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
		public id12<TypeValue> remove(Object key)
		{
			id12<TypeValue> result = super.remove(key);
			if (result != null)
			{
				this.count -= result.size();
			}
			return result;
		}

		@Override
		public MapSet<TypeKey, TypeValue> headMap(TypeKey keyEnd)
		{
			return new MapSet(this.comparator, this.entrySet.headSet(new AbstractMap.SimpleEntry<>(keyEnd, null)), this.id33);
		}

		@Override
		public MapSet<TypeKey, TypeValue> tailMap(TypeKey keyStart)
		{
			return new MapSet(this.comparator, this.entrySet.tailSet(new AbstractMap.SimpleEntry<>(keyStart, null)), this.id33);
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

	public static <Type> List<List<Type>> id10(List<Type> list)
	{
		List<List<Type>> result = new ArrayList<>();
		result.add(new ArrayList<>());
		for (Type element : list)
		{
			List<List<Type>> id10 = result;
			result = new ArrayList<>();
			for (List<Type> permutation : id10)
			{
				for (int index = 0; index <= permutation.size(); index++)
				{
					List<Type> id29 = new ArrayList<>(permutation);
					id29.add(index, element);
					result.add(id29);
				}
			}
		}
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

	public static <Type> int compare(Iterator<Type> iterator0, Iterator<Type> iterator1, Comparator<Type> comparator)
	{
		int result = 0;
		while (result == 0 && iterator0.hasNext() && iterator1.hasNext())
		{
			result = comparator.compare(iterator0.next(), iterator1.next());
		}
		if (result == 0)
		{
			if (iterator1.hasNext())
			{
				result = -1;
			}
			else
			{
				if (iterator0.hasNext())
				{
					result = 1;
				}
			}
		}
		return result;
	}

	public static <Type> int compare(Iterable<Type> id31, Iterable<Type> id15, Comparator<Type> comparator)
	{
		return compare(id31.iterator(), id15.iterator(), comparator);
	}

	private static String nextString() throws IOException
	{
		while ((stringTokenizer == null) || (!stringTokenizer.hasMoreTokens()))
		{
			stringTokenizer = new StringTokenizer(id27.readLine());
		}
		return stringTokenizer.nextToken();
	}

	private static String[] nextStrings(int n) throws IOException
	{
		String[] result = new String[n];
		{
			for (int index = 0; index < n; index++)
			{
				result[index] = nextString();
			}
		}
		return result;
	}

	public static int nextInt() throws IOException
	{
		return Integer.parseInt(nextString());
	}

	public static int[] nextInts(int n) throws IOException
	{
		int[] result = new int[n];
		{
			for (int index = 0; index < n; index++)
			{
				result[index] = nextInt();
			}
		}
		return result;
	}

	public static double nextDouble() throws IOException
	{
		return Double.parseDouble(nextString());
	}

	public static long nextLong() throws IOException
	{
		return Long.parseLong(nextString());
	}

	public static long[] id21(int n) throws IOException
	{
		long[] result = new long[n];
		{
			for (int index = 0; index < n; index++)
			{
				result[index] = nextLong();
			}
		}
		return result;
	}

	public static String nextLine() throws IOException
	{
		return id27.readLine();
	}

	public static void close()
	{
		out.close();
	}

	public static int id14(Function<Integer, Boolean> filter, int start, int end)
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
				result = id14(filter, start, middle);
			}
			else
			{
				result = id14(filter, middle + 1, end);
			}
		}
		return result;
	}

	public static int id11(Function<Integer, Boolean> filter, int start, int end)
	{
		return -id14(x -> filter.apply(-x), -end, -start);
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
		Iterator<Long> primes = id22.iterator();
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

	public static long[] id17()
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
		Iterator<Long> iterator = id22.iterator();
		Long prime;
		while ((prime = iterator.next()) * prime <= x)
		{
			result &= x % prime > 0;
		}
		return result;
	}

	public static long knapsack(List<Tuple3<Long, Integer, Integer>> id25, int weightMaximum)
	{
		long[] valuesMaximum = new long[weightMaximum + 1];
		for (Tuple3<Long, Integer, Integer> itemValueWeightCount : id25)
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

	public static boolean id28(List<Tuple2<Integer, Integer>> id20, int weightMaximum)
	{
		boolean[] weightPossible = new boolean[weightMaximum + 1];
		weightPossible[0] = true;
		int weightLargest = 0;
		for (Tuple2<Integer, Integer> itemWeightCount : id20)
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

	public static <Type> String toString(Iterator<Type> iterator, String separator)
	{
		StringBuffer stringBuffer = new StringBuffer();
		if (iterator.hasNext())
		{
			stringBuffer.append(iterator.next());
		}
		while (iterator.hasNext())
		{
			stringBuffer.append(separator);
			stringBuffer.append(iterator.next());
		}
		return stringBuffer.toString();
	}

	public static <Type> String toString(Iterator<Type> iterator)
	{
		return toString(iterator, " ");
	}

	public static <Type> String toString(Iterable<Type> iterable, String separator)
	{
		return toString(iterable.iterator(), separator);
	}

	public static <Type> String toString(Iterable<Type> iterable)
	{
		return toString(iterable, " ");
	}

	public static Stream<BigInteger> id9()
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
			private long id23 = 2;
			private List<Long> primes = new ArrayList<>();
			private int index = 0;

			public void filter(long prime, boolean[] result)
			{
				if (prime * prime < this.id23 + id5)
				{
					long remainingStart = this.id23 % prime;
					long start = remainingStart == 0 ? 0 : prime - remainingStart;
					for (long index = start; index < id5; index += prime)
					{
						result[(int) index] = false;
					}
				}
			}

			public void id36()
			{
				Arrays.fill(this.isPrime, true);
				this.primes.forEach(prime -> filter(prime, isPrime));
				for (int index = 0; index < id5; index++)
				{
					if (isPrime[index])
					{
						this.primes.add(this.id23 + index);
						filter(this.id23 + index, isPrime);
					}
				}
				this.id23 += id5;
			}

			@Override
			public Long get()
			{
				while (this.primes.size() <= this.index)
				{
					id36();
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


	public static int[] id19(int x, int[] id26)
	{
		int[] result = new int[1024];
		int index = 0;
		for (int strength = 0; strength < 1024; strength++)
		{
			int id24 = strength ^ x;
			int count = id26[strength];
			if (count > 0)
			{
				int countEven = count / 2;
				int countOdd = count / 2;
				if (count % 2 == 1)
				{
					countEven += 1;
				}
				if (index % 2 == 0)
				{
					result[strength] += countOdd;
					result[id24] += countEven;
				}
				else
				{
					result[strength] += countEven;
					result[id24] += countOdd;
				}
				index += count;
			}
		}
		return result;
	}

	public static int[] id19(int k, int x, int[] result)
	{
		for (int index = 0; index < k; index++)
		{
			result = id19(x, result);
		}
		return result;
	}

	public static int[] convert(int[] a)
	{
		int[] result = new int[1024];
		Arrays.stream(a)
				.forEach(strength -> result[strength] += 1);
		return result;
	}

	public static int[] solve(int k, int x, int[] a)
	{
		int[] result = convert(a);
		result = id19(k, x, result);
		return result;
	}

	public static int minimum(int[] id26)
	{
		Integer result = null;
		for (int index = 0; result == null && index < id26.length; index++)
		{
			if (0 < id26[index])
			{
				result = index;
			}
		}
		return result;

	}

	public static int maximum(int[] id26)
	{
		Integer result = null;
		for (int index = id26.length - 1; result == null && 0 <= index; index--)
		{
			if (0 < id26[index])
			{
				result = index;
			}
		}
		return result;
	}

	public static void solve() throws IOException
	{
		int n = nextInt();
		int k = nextInt();
		int x = nextInt();
		int[] a = nextInts(n);
		int[] id26 = solve(k, x, a);
		out.println(maximum(id26) + " " + minimum(id26));
	}
}