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
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;
import java.util.function.BiConsumer;
import java.util.function.Function;
import java.util.function.Supplier;
import java.util.stream.Stream;

public class id18
{
	public static final long[] POWER2 = id9();
	public static final IteratorBuffer id11 = new IteratorBuffer(streamPrime(1000000).iterator());
	public static BufferedReader id14 = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer stringTokenizer = null;
	private static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

	interface id21<Type0, Type1, TypeResult>
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
		public static <TypeVertex extends Vertex<TypeVertex, TypeEdge>, TypeEdge extends Edge<TypeVertex, TypeEdge>> void id24(
				BiConsumer<TypeVertex, TypeEdge> id1,
				BiConsumer<TypeVertex, TypeEdge> id5,
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
					id24(
							id1,
							id5,
							vertexNext,
							edgeNext,
							visited);
				}
				id5.accept(vertex, edge);
			}
		}

		public static <TypeVertex extends Vertex<TypeVertex, TypeEdge>, TypeEdge extends Edge<TypeVertex, TypeEdge>> void id24(
				Array<TypeVertex> vertices,
				int id16,
				BiConsumer<TypeVertex, TypeEdge> id1,
				BiConsumer<TypeVertex, TypeEdge> id5
		)
		{
			Array<Boolean> visited = new Array(vertices.size(), false);
			id24(
					id1,
					id5,
					vertices.get(id16),
					null,
					visited);
		}

		public static <TypeVertex extends Vertex<TypeVertex, TypeEdge>, TypeEdge extends Edge<TypeVertex, TypeEdge>, TypeResult> TypeResult id2(
				TypeVertex vertex,
				TypeEdge edge,
				id21<TypeVertex, TypeEdge, TypeResult> function,
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
				int id16,
				id21<TypeVertex, TypeEdge, TypeResult> function,
				TypeResult result
		)
		{
			Array<Boolean> visited = new Array(vertices.size(), false);
			FIFO<TypeVertex> verticesNext = new FIFO<>();
			verticesNext.push(vertices.get(id16));
			FIFO<TypeEdge> edgesNext = new FIFO<>();
			edgesNext.push(null);
			while (!verticesNext.isEmpty())
			{
				result = id2(
						verticesNext.pop(),
						edgesNext.pop(),
						function,
						visited,
						verticesNext,
						edgesNext,
						result);
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

	public static class id23<Type0 extends Comparable<? super Type0>, Type1 extends Comparable<? super Type1>> extends Tuple2<Type0, Type1> implements Comparable<id23<Type0, Type1>>
	{
		public id23(Type0 v0, Type1 v1)
		{
			super(v0, v1);
		}

		@Override
		public int compareTo(id23<Type0, Type1> that)
		{
			int result = this.v0.compareTo(that.v0);
			if (result == 0)
			{
				result = this.v1.compareTo(that.v1);
			}
			return result;
		}
	}

	public static class id17<Type>
	{
		public final Type element;
		public id17<Type> next;

		public id17(Type element, id17<Type> next)
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
		public id17<Type> start;
		public id17<Type> end;

		public FIFO()
		{
			this.start = null;
			this.end = null;
		}

		public void push(Type element)
		{
			id17<Type> list = new id17<>(element, null);
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
		private Comparator<? super TypeValue> id19;
		private int size;

		public MapSet()
		{
			this(null);
		}

		public MapSet(Comparator<? super TypeValue> id19)
		{
			super();
			this.size = 0;
			this.id19 = id19;
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
				if (id19 == null)
				{
					set = new TreeSet<>();
				}
				else
				{
					set = new TreeSet<>(id19);
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
			stringTokenizer = new StringTokenizer(id14.readLine());
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
		return id14.readLine();
	}

	public static void close()
	{
		out.close();
	}

	public static int id8(Function<Integer, Boolean> filter, int start, int end)
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
				result = id8(filter, start, middle);
			}
			else
			{
				result = id8(filter, middle + 1, end);
			}
		}
		return result;
	}

	public static int id7(Function<Integer, Boolean> filter, int start, int end)
	{
		return -id8(x -> filter.apply(-x), -end, -start);
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
		Iterator<Long> primes = id11.iterator();
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

	public static long gcd(long a, long b)
	{
		long result = 1;
		Iterator<Long> id22 = factors(a).iterator();
		Iterator<Long> id4 = factors(b).iterator();
		if (id22.hasNext() && id4.hasNext())
		{
			Long factorA = null;
			Long factorB = null;
			while ((factorA != null || id22.hasNext()) && (factorB != null || id4.hasNext()))
			{
				if (factorA == null)
				{
					factorA = id22.next();
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

	public static long[] id9()
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
		Iterator<Long> iterator = id11.iterator();
		Long prime;
		while ((prime = iterator.next()) * prime <= x)
		{
			result &= x % prime > 0;
		}
		return result;
	}

	public static long knapsack(List<Tuple3<Long, Integer, Integer>> id13, int weightMaximum)
	{
		long[] valuesMaximum = new long[weightMaximum + 1];
		for (Tuple3<Long, Integer, Integer> itemValueWeightCount : id13)
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

	public static boolean id15(List<Tuple2<Integer, Integer>> id10, int weightMaximum)
	{
		boolean[] weightPossible = new boolean[weightMaximum + 1];
		weightPossible[0] = true;
		int weightLargest = 0;
		for (Tuple2<Integer, Integer> itemWeightCount : id10)
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

	public static Stream<BigInteger> id6()
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
			private long id12 = 2;
			private List<Long> primes = new ArrayList<>();
			private int index = 0;

			public void filter(long prime, boolean[] result)
			{
				if (prime * prime < this.id12 + id3)
				{
					long remainingStart = this.id12 % prime;
					long start = remainingStart == 0 ? 0 : prime - remainingStart;
					for (long index = start; index < id3; index += prime)
					{
						result[(int) index] = false;
					}
				}
			}

			public void id20()
			{
				Arrays.fill(this.isPrime, true);
				this.primes.forEach(prime -> filter(prime, isPrime));
				for (int index = 0; index < id3; index++)
				{
					if (isPrime[index])
					{
						this.primes.add(this.id12 + index);
						filter(this.id12 + index, isPrime);
					}
				}
				this.id12 += id3;
			}

			@Override
			public Long get()
			{
				while (this.primes.size() <= this.index)
				{
					id20();
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

	static class Vertexx extends Vertex<Vertexx, Branch>
	{
		public long weightActual;
		public long weightMinimum;
		public long weightMaximum;

		public Vertexx(int index)
		{
			super(index);
		}

		public long trim(long s, Vertexx from)
		{
			long result = 0;
			for (Branch branch : edges)
			{
				Vertexx to = branch.other(this);
				if (from != to)
				{ 

					s -= Math.max(0, to.weightActual - to.weightMaximum);
				}
			}
			for (Branch branch : edges)
			{
				Vertexx to = branch.other(this);
				if (from != to)
				{
					s += Math.max(0, to.weightActual - to.weightMaximum);
					result += to.trim(s - result, this);
				}
			}
			for (Branch branch : edges)
			{
				Vertexx to = branch.other(this);
				if (from != to)
				{
					result += branch.trim(s - result, to);
				}
			}
			this.weightActual -= result;
			return result;
		}
	}

	static class Branch extends Edge<Vertexx, Branch>
	{
		public long w;
		public long p;

		public Branch(Vertexx vertex0, Vertexx vertex1, boolean bidirectional, long w, long p)
		{
			super(vertex0, vertex1, bidirectional);
			this.w = w;
			this.p = p;
		}

		public long trim(long result, Vertexx to)
		{
			result = Math.min(result, w - 1);
			result = Math.min(result, p);
			result = Math.min(result, p - to.weightActual);
			result = Math.max(0, result);
			w -= result;
			p -= result;
			return result;
		}

		@Override
		public Branch getThis()
		{
			return this;
		}

		@Override
		public String toString()
		{
			return (this.vertex0.index + 1) + " " + (this.vertex1.index + 1) + " " + this.w + " " + this.p;
		}
	}

	public static Branch[] convert(int n, int[] x, int[] y, int[] w, int[] p, Array<Vertexx> vertices)
	{
		for (int index = 0; index < n; index++)
		{
			vertices.set(index, new Vertexx(index));
		}
		Branch[] result = new Branch[n - 1];
		for (int index = 0; index < n - 1; index++)
		{
			result[index] = new Branch(vertices.get(x[index] - 1), vertices.get(y[index] - 1), true, w[index], p[index]);
		}
		return result;
	}

	public static void calculateWeight(Array<Vertexx> vertices)
	{
		Stack<Long> weightActual = new Stack<>();
		Stack<Long> weightMinimum = new Stack<>();
		Stack<Long> weightMaximum = new Stack<>();
		Vertex.id24(
				vertices,
				0,
				(vertex, branch) ->
				{
					weightActual.push(0L);
					weightMinimum.push(0L);
					weightMaximum.push(0L);
				},
				(vertex, branch) ->
				{
					vertex.weightActual = weightActual.pop();
					vertex.weightMinimum = weightMinimum.pop();
					vertex.weightMaximum = weightMaximum.pop();
					if (branch != null)
					{
						weightActual.push(weightActual.pop() + vertex.weightActual + branch.w);
						weightMinimum.push(weightMinimum.pop() + vertex.weightMinimum + branch.w - Math.min(branch.p - vertex.weightMinimum, branch.w - 1));
						vertex.weightMaximum = Math.min(vertex.weightMaximum, branch.p);
						weightMaximum.push(weightMaximum.pop() + vertex.weightMaximum + branch.w);
					}
				});
	}

	public static boolean test(Array<Vertexx> vertices)
	{
		Wrapper<Boolean> test = new Wrapper<>(true);
		Vertex.id24(
				vertices,
				0,
				(vertex, branch) ->
				{
					if (branch != null)
					{
						test.set(test.get() & vertex.weightMinimum <= branch.p);
					}
				},
				(vertex, branch) ->
				{
				});
		return test.get();
	}

	public static boolean solve(Array<Vertexx> vertices)
	{
		calculateWeight(vertices);
		boolean result = test(vertices);
		if (result)
		{
			Vertexx vertex = vertices.get(0);
			vertex.trim(Math.max(0, vertex.weightActual - vertex.weightMaximum), null);
		}
		return result;
	}

	public static void solve() throws IOException
	{
		int n = nextInt();
		int[] x = new int[n - 1];
		int[] y = new int[n - 1];
		int[] w = new int[n - 1];
		int[] p = new int[n - 1];
		for (int index = 0; index < n - 1; index++)
		{
			x[index] = nextInt();
			y[index] = nextInt();
			w[index] = nextInt();
			p[index] = nextInt();
		}
		Array<Vertexx> vertices = new Array<>(n);
		Branch[] branches = convert(n, x, y, w, p, vertices);
		if (solve(vertices))
		{
			out.println(n);
			for (Branch branch : branches)
			{
				out.println(branch);
			}
		}
		else
		{
			out.println(-1);
		}
	}
}