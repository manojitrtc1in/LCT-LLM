import java.io.*;
import java.util.*;
import java.util.function.Function;

public class id6
{
	private static BufferedReader id5 = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer stringTokenizer = null;
	private static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

	private static String next() throws IOException
	{
		while ((stringTokenizer == null) || (!stringTokenizer.hasMoreTokens()))
		{
			stringTokenizer = new StringTokenizer(id5.readLine());
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
		return id5.readLine();
	}

	public static void close()
	{
		out.close();
	}

	public static final long[] POWER2 = id4();


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

	interface id10<Type0, Type1, TypeResult>
	{
		TypeResult apply(Type0 x0, Type1 x1, TypeResult x2);
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

		private TypeVertex other(Vertex<TypeVertex, TypeEdge> vertex)
		{
			TypeVertex result;
			if (vertex0 == vertex)
			{
				result = vertex1;
			} else
			{
				result = vertex0;
			}
			return result;
		}

		public TypeVertex from(Vertex<TypeVertex, TypeEdge> to)
		{
			return other(to);
		}

		public TypeVertex to(Vertex<TypeVertex, TypeEdge> from)
		{
			return other(from);
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
		public final int index;
		public final List<TypeEdge> edges;

		public Vertex(int index)
		{
			this.index = index;
			this.edges = new ArrayList<>();
		}

		public static <TypeVertex extends Vertex<TypeVertex, TypeEdge>, TypeEdge extends Edge<TypeVertex, TypeEdge>, TypeResult> TypeResult id12(
				id10<TypeVertex, TypeEdge, TypeResult> function,
				TypeVertex vertex,
				TypeEdge edge,
				TypeResult result,
				Array<Boolean> visited
		)
		{
			if (!visited.get(vertex.index))
			{
				visited.set(vertex.index, true);
				result = function.apply(vertex, edge, result);
				for (TypeEdge edgeNext : vertex.edges)
				{
					TypeVertex vertexNext = edge.to(vertex);
					result = id12(function, vertexNext, edgeNext, result, visited);
				}
			}
			return result;
		}

		public static <TypeVertex extends Vertex<TypeVertex, TypeEdge>, TypeEdge extends Edge<TypeVertex, TypeEdge>, TypeResult> TypeResult id12(
				Array<TypeVertex> vertices,
				int id7,
				id10<TypeVertex, TypeEdge, TypeResult> function,
				TypeResult result
		)
		{
			Array<Boolean> visited = new Array(vertices.size(), false);
			return id12(function, vertices.get(id7), null, result, visited);
		}

		public static <TypeVertex extends Vertex<TypeVertex, TypeEdge>, TypeEdge extends Edge<TypeVertex, TypeEdge>, TypeResult> TypeResult id1(
				TypeVertex vertex,
				TypeEdge edge,
				id10<TypeVertex, TypeEdge, TypeResult> function,
				Array<Boolean> visited,
				LIFO<TypeVertex> verticesNext,
				LIFO<TypeEdge> edgesNext,
				TypeResult result
		)
		{
			if (!visited.get(vertex.index))
			{
				visited.set(vertex.index, true);
				result = function.apply(vertex, edge, result);
				for (TypeEdge edgeNext : vertex.edges)
				{
					TypeVertex vertexNext = edgeNext.to(vertex);
					if (!visited.get(vertexNext.index))
					{
						verticesNext.push(vertexNext);
						edgesNext.push(edgeNext);
					}
				}
			}
			return result;
		}

		public static <TypeVertex extends Vertex<TypeVertex, TypeEdge>, TypeEdge extends Edge<TypeVertex, TypeEdge>, TypeResult> TypeResult id1(
				Array<TypeVertex> vertices,
				int id7,
				id10<TypeVertex, TypeEdge, TypeResult> function,
				TypeResult result
		)
		{
			Array<Boolean> visited = new Array(vertices.size(), false);
			LIFO<TypeVertex> verticesNext = new LIFO<>();
			verticesNext.push(vertices.get(id7));
			LIFO<TypeEdge> edgesNext = new LIFO<>();
			edgesNext.push(null);
			while (!verticesNext.isEmpty())
			{
				result = id1(verticesNext.pop(), edgesNext.pop(), function, visited, verticesNext, edgesNext, result);
			}
			return result;
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

	public static class id11<Type0 extends Comparable<? super Type0>, Type1 extends Comparable<? super Type1>> extends Tuple2<Type0, Type1> implements Comparable<id11<Type0, Type1>>
	{
		public id11(Type0 v0, Type1 v1)
		{
			super(v0, v1);
		}

		@Override
		public int compareTo(id11<Type0, Type1> that)
		{
			int result = this.v0.compareTo(that.v0);
			if (result == 0)
			{
				result = this.v1.compareTo(that.v1);
			}
			return result;
		}
	}

	public static class id8<Type>
	{
		public final Type element;
		public id8<Type> next;

		public id8(Type element, id8<Type> next)
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

	public static class LIFO<Type>
	{
		public id8<Type> start;
		public id8<Type> end;

		public LIFO()
		{
			this.start = null;
			this.end = null;
		}

		public void push(Type element)
		{
			id8<Type> list = new id8<>(element, null);
			if (this.start == null)
			{
				this.start = list;
				this.end = list;
			} else
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
				} else
				{
					value += delta;
				}
				put(key, value);
				result = delta;
			} else
			{
				result = 0;
			}
			this.size += result;
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
				} else
				{
					result = delta;
					put(key, value);
				}
			} else
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
		private int size;
		private Comparator<? super TypeValue> id9;

		public MapSet()
		{
			this(null);
		}

		public MapSet(Comparator<? super TypeValue> id9)
		{
			super();
			this.size = 0;
			this.id9 = id9;
		}

		public TypeValue firstValue()
		{
			TypeValue result;
			Map.Entry<TypeKey, TreeSet<TypeValue>> firstEntry = firstEntry();
			if (firstEntry == null)
			{
				result = null;
			} else
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
			} else
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
				if (id9 == null)
				{
					set = new TreeSet<>();
				} else
				{
					set = new TreeSet<>(id9);
				}
				put(key, set);
			}
			boolean result = set.add(value);
			if (result)
			{
				this.size += 1;
			}
			return result;
		}

		public boolean remove(TypeKey key, TypeValue value)
		{
			boolean result;
			TreeSet<TypeValue> set = get(key);
			if (set == null)
			{
				result = false;
			} else
			{
				result = set.remove(value);
				if (set.size() == 0)
				{
					remove(key);
				}
				if (result)
				{
					this.size -= 1;
				}
			}
			return result;
		}

		@Override
		public int size()
		{
			return this.size;
		}
	}

	public static int id3(Function<Integer, Boolean> filter, int start, int end)
	{
		int result;
		if (start == end)
		{
			result = end;
		} else
		{
			int middle = start + (end - start) / 2;
			if (filter.apply(middle))
			{
				result = id3(filter, start, middle);
			} else
			{
				result = id3(filter, middle + 1, end);
			}
		}
		return result;
	}

	public static int id2(Function<Integer, Boolean> filter, int start, int end)
	{
		return -id3(x -> filter.apply(-x), -end, -start);
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

	public static int gcd(int a, int b)
	{
		

		int result = 1;
		int min = Math.min(a, b);
		int max = Math.max(a, b);
		for (int test = 2; result == 1 && test <= min; test++)
		{
			if (min % test == 0 && max % test == 0)
			{
				result *= test * gcd(min / test, max / test);
			}
		}
		return result;
	}

	public static long[] id4()
	{
		long[] result = new long[63];
		for (int x = 0; x < result.length; x++)
		{
			result[x] = 1L << x;
		}
		return result;
	}

	public static int lcm(int a, int b)
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

	public static void solve() throws IOException
	{
		int n = nextInt();
		int m = nextInt();
		TreeSet<Integer> poolOdd = new TreeSet<>();
		TreeSet<Integer> poolEven = new TreeSet<>();
		TreeSet<Integer> usedOdd = new TreeSet<>();
		TreeSet<Integer> usedEven = new TreeSet<>();
		for (int index = 0; index < n * 3; index++)
		{
			if (index * 2 + 1 <= m)
			{
				poolOdd.add(index * 2 + 1);
			}
			if (index * 2 + 2 <= m)
			{
				poolEven.add(index * 2 + 2);
			}
		}
		int[] a = new int[n];
		for (int index = 0; index < n; index++)
		{
			a[index] = nextInt();
			if (a[index] % 2 == 0)
			{
				usedEven.add(a[index]);
				poolEven.remove(a[index]);
			} else
			{
				usedOdd.add(a[index]);
				poolOdd.remove(a[index]);
			}
		}
		int odd = 0;
		int even = 0;
		int swaps = 0;
		boolean valid = true;
		for (int index = 0; valid && index < n; index++)
		{
			if (usedOdd.remove(a[index]) || usedEven.remove(a[index]))
			{
				if (a[index] % 2 == 0)
				{
					even += 1;
				} else
				{
					odd += 1;
				}

			} else
			{
				Integer next;
				if (odd + usedOdd.size() < even + usedEven.size())
				{
					if (poolOdd.isEmpty())
					{
						valid = false;
					}
					else
					{
						next = poolOdd.first();
						poolOdd.remove(next);
						odd += 1;
						a[index] = next;
						swaps += 1;
					}
				} else
				{
					if (poolEven.isEmpty())
					{
						valid = false;
					}
					else
					{
						next = poolEven.first();
						poolEven.remove(next);
						even += 1;
						a[index] = next;
						swaps += 1;
					}
				}
			}
		}
		for (int index = 0; index < n; index++)
		{
			if (a[index] % 2 == 0 && odd < even && !poolOdd.isEmpty())
			{
				Integer next = poolOdd.first();
				poolOdd.remove(next);
				odd += 1;
				even -= 1;
				a[index] = next;
				swaps += 1;
			}
			if (a[index] % 2 != 0 && even < odd && !poolEven.isEmpty())
			{
				Integer next = poolEven.first();
				poolEven.remove(next);
				even += 1;
				odd -= 1;
				a[index] = next;
				swaps += 1;
			}
		}
		if (valid && odd == even)
		{
			out.println(swaps);
			for (int index = 0; index < n; index++)
			{
				out.print(a[index] + " ");
			}
			out.println();
		} else
		{
			out.println(-1);
		}
	}
}