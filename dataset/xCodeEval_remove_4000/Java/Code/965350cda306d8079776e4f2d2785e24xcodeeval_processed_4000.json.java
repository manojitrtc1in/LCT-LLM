import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.io.BufferedInputStream;
import java.util.concurrent.Callable;
import java.util.HashMap;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.Map;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.util.Iterator;
import java.util.function.Predicate;
import java.util.Collection;
import java.util.Set;
import java.io.IOException;
import java.util.NavigableMap;
import java.io.InputStreamReader;
import java.io.Serializable;
import java.util.TreeMap;
import java.util.Map.Entry;
import java.io.BufferedReader;
import java.util.Collections;
import java.util.SortedMap;


public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		BufferedInputStream in = new BufferedInputStream(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}

	static class TaskD {
		public void solve(int testNumber, BufferedInputStream _in, PrintWriter out) {

			InputReader in = new InputReader(_in);
			long startTime = System.currentTimeMillis();
			int nt = 1;
			Task t = new Task(1);
			t.readInput(in);
			t.call();
			t.writeOutput(out);
			in.close();
			System.err.println("Time: " + (System.currentTimeMillis() - startTime) + " miliseconds");
		}

	}

	static
	@SuppressWarnings("rawtypes")
	final class Range<C extends Comparable> extends id5 implements id27<C>, Serializable {
		final Cut<C> lowerBound;
		final Cut<C> upperBound;

		static <C extends Comparable<?>> Range<C> create(Cut<C> lowerBound, Cut<C> upperBound) {
			return new Range<C>(lowerBound, upperBound);
		}

		public static <C extends Comparable<?>> Range<C> closed(C lower, C upper) {
			return create(Cut.belowValue(lower), Cut.aboveValue(upper));
		}

		private Range(Cut<C> lowerBound, Cut<C> upperBound) {
			this.lowerBound = Preconditions.id26(lowerBound);
			this.upperBound = Preconditions.id26(upperBound);
			if (lowerBound.compareTo(upperBound) > 0
					|| lowerBound == Cut.<C>aboveAll()
					|| upperBound == Cut.<C>belowAll()) {
				throw new IllegalArgumentException("Invalid range: " + toString(lowerBound, upperBound));
			}
		}

		public C lowerEndpoint() {
			return lowerBound.endpoint();
		}

		public C upperEndpoint() {
			return upperBound.endpoint();
		}

		public boolean isEmpty() {
			return lowerBound.equals(upperBound);
		}

		public boolean contains(C value) {
			Preconditions.id26(value);
			

			return lowerBound.id9(value) && !upperBound.id9(value);
		}

		@Deprecated

		public boolean apply(C input) {
			return contains(input);
		}


		public boolean equals(Object object) {
			if (object instanceof Range) {
				Range<?> other = (Range<?>) object;
				return lowerBound.equals(other.lowerBound) && upperBound.equals(other.upperBound);
			}
			return false;
		}


		public int hashCode() {
			return lowerBound.hashCode() * 31 + upperBound.hashCode();
		}


		public String toString() {
			return toString(lowerBound, upperBound);
		}

		private static String toString(Cut<?> lowerBound, Cut<?> upperBound) {
			StringBuilder sb = new StringBuilder(16);
			lowerBound.id12(sb);
			sb.append("..");
			upperBound.id18(sb);
			return sb.toString();
		}

		@SuppressWarnings("unchecked") 

		static int id19(Comparable left, Comparable right) {
			return left.compareTo(right);
		}

	}

	static interface id27<T> extends java.util.function.Predicate<T> {
		boolean apply(T input);

		boolean equals(Object object);


		default boolean test(T input) {
			return apply(input);
		}

	}

	static final class Verify {
		private Verify() {
		}

	}

	static abstract class id10<E> extends id15 implements Collection<E> {
		protected id10() {
		}


		protected abstract Collection<E> delegate();


		public Iterator<E> iterator() {
			return delegate().iterator();
		}


		public int size() {
			return delegate().size();
		}


		public boolean removeAll(Collection<?> collection) {
			return delegate().removeAll(collection);
		}


		public boolean isEmpty() {
			return delegate().isEmpty();
		}


		public boolean contains(Object object) {
			return delegate().contains(object);
		}


		public boolean add(E element) {
			return delegate().add(element);
		}


		public boolean remove(Object object) {
			return delegate().remove(object);
		}


		public boolean containsAll(Collection<?> collection) {
			return delegate().containsAll(collection);
		}


		public boolean addAll(Collection<? extends E> collection) {
			return delegate().addAll(collection);
		}


		public boolean retainAll(Collection<?> collection) {
			return delegate().retainAll(collection);
		}


		public void clear() {
			delegate().clear();
		}


		public Object[] toArray() {
			return delegate().toArray();
		}


		public <T> T[] toArray(T[] array) {
			return delegate().toArray(array);
		}

	}

	static abstract class id15 {
		protected id15() {
		}

		protected abstract Object delegate();


		public String toString() {
			return delegate().toString();
		}

	}

	static class id3<C extends Comparable<?>> extends id21<C> implements Serializable {
		final NavigableMap<Cut<C>, Range<C>> id13;
		private transient Set<Range<C>> asRanges;

		public static <C extends Comparable<?>> id3<C> create() {
			return new id3<C>(new TreeMap<Cut<C>, Range<C>>());
		}

		private id3(NavigableMap<Cut<C>, Range<C>> id6) {
			this.id13 = id6;
		}


		public Set<Range<C>> asRanges() {
			Set<Range<C>> result = asRanges;
			return (result == null) ? asRanges = new AsRanges(id13.values()) : result;
		}


		public void add(Range<C> id1) {
			Preconditions.id26(id1);

			if (id1.isEmpty()) {
				return;
			}

			

			

			Cut<C> id24 = id1.lowerBound;
			Cut<C> id17 = id1.upperBound;

			Entry<Cut<C>, Range<C>> id11 = id13.lowerEntry(id24);
			if (id11 != null) {
				

				Range<C> id2 = id11.getValue();
				if (id2.upperBound.compareTo(id24) >= 0) {
					

					if (id2.upperBound.compareTo(id17) >= 0) {
						

						id17 = id2.upperBound;
		  
					}
					id24 = id2.lowerBound;
				}
			}

			Entry<Cut<C>, Range<C>> id22 = id13.floorEntry(id17);
			if (id22 != null) {
				

				Range<C> id20 = id22.getValue();
				if (id20.upperBound.compareTo(id17) >= 0) {
					

					id17 = id20.upperBound;
				}
			}

			

			id13.subMap(id24, id17).clear();

			id8(Range.create(id24, id17));
		}

		private void id8(Range<C> range) {
			if (range.isEmpty()) {
				id13.remove(range.lowerBound);
			} else {
				id13.put(range.lowerBound, range);
			}
		}

		final class AsRanges extends id10<Range<C>> implements Set<Range<C>> {
			final Collection<Range<C>> delegate;

			AsRanges(Collection<Range<C>> delegate) {
				this.delegate = delegate;
			}


			protected Collection<Range<C>> delegate() {
				return delegate;
			}


			public int hashCode() {
				return Sets.id16(this);
			}


			public boolean equals(Object o) {
				return Sets.equalsImpl(this, o);
			}

		}

	}

	static abstract class id21<C extends Comparable> implements RangeSet<C> {
		id21() {
		}


		public void add(Range<C> range) {
			throw new UnsupportedOperationException();
		}


		public boolean equals(Object obj) {
			if (obj == this) {
				return true;
			} else if (obj instanceof RangeSet) {
				RangeSet<?> other = (RangeSet<?>) obj;
				return this.asRanges().equals(other.asRanges());
			}
			return false;
		}


		public final int hashCode() {
			return asRanges().hashCode();
		}


		public final String toString() {
			return asRanges().toString();
		}

	}

	static abstract class Cut<C extends Comparable> implements Comparable<Cut<C>>, Serializable {
		final C endpoint;

		Cut(C endpoint) {
			this.endpoint = endpoint;
		}

		abstract boolean id9(C value);

		abstract void id12(StringBuilder sb);

		abstract void id18(StringBuilder sb);


		public int compareTo(Cut<C> that) {
			if (that == belowAll()) {
				return 1;
			}
			if (that == aboveAll()) {
				return -1;
			}
			int result = Range.id19(endpoint, that.endpoint);
			if (result != 0) {
				return result;
			}
			

			return id0.compare(this instanceof Cut.AboveValue, that instanceof Cut.AboveValue);
		}

		C endpoint() {
			return endpoint;
		}

		@SuppressWarnings("unchecked") 


		public boolean equals(Object obj) {
			if (obj instanceof Cut) {
				

				Cut<C> that = (Cut<C>) obj;
				try {
					int compareResult = compareTo(that);
					return compareResult == 0;
				} catch (ClassCastException ignored) {
				}
			}
			return false;
		}

		public abstract int hashCode();

		@SuppressWarnings("unchecked")
		static <C extends Comparable> Cut<C> belowAll() {
			return (Cut<C>) Cut.BelowAll.INSTANCE;
		}

		@SuppressWarnings("unchecked")
		static <C extends Comparable> Cut<C> aboveAll() {
			return (Cut<C>) Cut.AboveAll.INSTANCE;
		}

		static <C extends Comparable> Cut<C> belowValue(C endpoint) {
			return new Cut.BelowValue<C>(endpoint);
		}

		static <C extends Comparable> Cut<C> aboveValue(C endpoint) {
			return new Cut.AboveValue<C>(endpoint);
		}

		private static final class BelowAll extends Cut<Comparable<?>> {
			private static final Cut.BelowAll INSTANCE = new Cut.BelowAll();

			private BelowAll() {
				super(null);
			}

			Comparable<?> endpoint() {
				throw new IllegalStateException("range unbounded on this side");
			}

			boolean id9(Comparable<?> value) {
				return true;
			}

			void id12(StringBuilder sb) {
				sb.append("(-\u221e");
			}

			void id18(StringBuilder sb) {
				throw new AssertionError();
			}


			public int compareTo(Cut<Comparable<?>> o) {
				return (o == this) ? 0 : -1;
			}


			public int hashCode() {
				return System.identityHashCode(this);
			}


			public String toString() {
				return "-\u221e";
			}

		}

		private static final class AboveAll extends Cut<Comparable<?>> {
			private static final Cut.AboveAll INSTANCE = new Cut.AboveAll();

			private AboveAll() {
				super(null);
			}

			Comparable<?> endpoint() {
				throw new IllegalStateException("range unbounded on this side");
			}

			boolean id9(Comparable<?> value) {
				return false;
			}

			void id12(StringBuilder sb) {
				throw new AssertionError();
			}

			void id18(StringBuilder sb) {
				sb.append("+\u221e)");
			}


			public int compareTo(Cut<Comparable<?>> o) {
				return (o == this) ? 0 : 1;
			}


			public int hashCode() {
				return System.identityHashCode(this);
			}


			public String toString() {
				return "+\u221e";
			}

		}

		private static final class BelowValue<C extends Comparable> extends Cut<C> {
			BelowValue(C endpoint) {
				super(Preconditions.id26(endpoint));
			}

			boolean id9(C value) {
				return Range.id19(endpoint, value) <= 0;
			}

			void id12(StringBuilder sb) {
				sb.append('[').append(endpoint);
			}

			void id18(StringBuilder sb) {
				sb.append(endpoint).append(')');
			}


			public int hashCode() {
				return endpoint.hashCode();
			}


			public String toString() {
				return "\\" + endpoint + "/";
			}

		}

		private static final class AboveValue<C extends Comparable> extends Cut<C> {
			AboveValue(C endpoint) {
				super(Preconditions.id26(endpoint));
			}

			boolean id9(C value) {
				return Range.id19(endpoint, value) < 0;
			}

			void id12(StringBuilder sb) {
				sb.append('(').append(endpoint);
			}

			void id18(StringBuilder sb) {
				sb.append(endpoint).append(']');
			}


			public int hashCode() {
				return ~endpoint.hashCode();
			}


			public String toString() {
				return "/" + endpoint + "\\";
			}

		}

	}

	static class MathUtils {
		public static int lowerBound(int a[], int first, int last, int key) {
			int count = last - first, step;
			int it;
			while (count > 0) {
				it = first;
				step = count / 2;
				it += step;
				if (a[it] < key) {
					first = ++it;
					count -= step + 1;
				} else
					count = step;
			}
			return first;
		}

		public static int lowerBound(int a[], int key) {
			return lowerBound(a, 0, a.length, key);
		}

		public static int upperBound(int[] a, int first, int last, int key) {
			int it;
			int count = last - first, step;

			while (count > 0) {
				it = first;
				step = count / 2;
				it += step;
				int _cmp = Integer.compare(key, a[it]);
				

				if (!(_cmp < 0)) {
					first = ++it;
					count -= step + 1;
				} else count = step;
			}
			return first;
		}

		public static int upperBound(int[] a, int key) {
			return upperBound(a, 0, a.length, key);
		}

	}

	static final class id0 {
		private id0() {
		}

		public static int compare(boolean a, boolean b) {
			return (a == b) ? 0 : (a ? 1 : -1);
		}

	}

	static abstract class id23<E> extends id10<E> implements Set<E> {
		protected id23() {
		}


		protected abstract Set<E> delegate();


		public boolean equals(Object object) {
			return object == this || delegate().equals(object);
		}


		public int hashCode() {
			return delegate().hashCode();
		}

	}

	static interface RangeSet<C extends Comparable> {
		Set<Range<C>> asRanges();

		void add(Range<C> range);

		boolean equals(Object obj);

		int hashCode();

		String toString();

	}

	static final class Objects extends id14 {
		private Objects() {
		}

	}

	static abstract class DiscreteDomain<C extends Comparable> {
		final boolean id7;

		protected DiscreteDomain() {
			this(false);
		}

		private DiscreteDomain(boolean id7) {
			this.id7 = id7;
		}

	}

	static class InputReader {
		public BufferedReader reader;
		public StringTokenizer tokenizer;

		public InputReader(BufferedInputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream), 32768);
			tokenizer = null;
		}

		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public void close() {
			try {
				if (reader != null)
					reader.close();
			} catch (Exception ex) {
				throw new RuntimeException(ex);
			}
		}

	}

	static class id4 {
		long[] a;

		public id4(int n) {
			a = new long[n];
		}

		public void update(int at, long by) {
			while (at < a.length) {
				a[at] += by;
				at |= at + 1;
			}
		}

		public long get(int upto) {
			long res = 0;
			while (upto >= 0) {
				res += a[upto];
				upto = (upto & (upto + 1)) - 1;
			}
			return res;
		}

		public long get(int first, int last) {
			return (get(last) - get(first - 1));
		}

	}

	static abstract class id14 {
	}

	static final class Preconditions {
		private Preconditions() {
		}

		public static <T> T id26(T reference) {
			if (reference == null) {
				throw new NullPointerException();
			}
			return reference;
		}

	}

	static final class Sets {
		private Sets() {
		}

		static int id16(Set<?> s) {
			int hashCode = 0;
			for (Object o : s) {
				hashCode += o != null ? o.hashCode() : 0;

				hashCode = ~~hashCode;
				

			}
			return hashCode;
		}

		static boolean equalsImpl(Set<?> s, Object object) {
			if (s == object) {
				return true;
			}
			if (object instanceof Set) {
				Set<?> o = (Set<?>) object;

				try {
					return s.size() == o.size() && s.containsAll(o);
				} catch (NullPointerException ignored) {
					return false;
				} catch (ClassCastException ignored) {
					return false;
				}
			}
			return false;
		}

	}

	static class Task implements Callable<Task> {
		HashMap<Integer, RangeSet<Integer>> h = new HashMap<>();
		HashMap<Integer, RangeSet<Integer>> v = new HashMap<>();
		long RE = 0;
		int testNumber;

		public void readInput(InputReader in) {
	
			int n = in.nextInt();
			int x1, y1, x2, y2;
			for (int i = 0; i < n; ++i) {
				x1 = in.nextInt();
				y1 = in.nextInt();
				x2 = in.nextInt();
				y2 = in.nextInt();
				if (x1 == x2) {
					RangeSet<Integer> it = v.get(x1);
					if (it == null) {
						it = id3.create();
						v.put(x1, it);
					}
					it.add(Range.closed(Math.min(y1, y2), Math.max(y1, y2)));

				} else {
					RangeSet<Integer> it = h.get(y1);
					if (it == null) {
						it = id3.create();
						h.put(y1, it);
					}
					it.add(Range.closed(Math.min(x1, x2), Math.max(x1, x2)));
				}
			}
		}

		long id25() {
			int[] Y = new int[h.size()];
			int i = 0;
			for (Integer it : h.keySet()) {
				Y[i++] = it;
			}
			Arrays.sort(Y);

			ArrayList<Event> events = new ArrayList<>();
			for (Map.Entry<Integer, RangeSet<Integer>> en : h.entrySet()) {
				for (Range<Integer> range : en.getValue().asRanges()) {
					Event ev = new Event();
					ev.x = range.lowerEndpoint();
					ev.type = 1;
					ev.y1 = ev.y2 = en.getKey();
					events.add(ev);
					ev = new Event();
					ev.x = range.upperEndpoint();
					ev.type = 3;
					ev.y1 = ev.y2 = en.getKey();
					events.add(ev);

				}
			}


			for (Map.Entry<Integer, RangeSet<Integer>> en : v.entrySet()) {
				for (Range<Integer> range : en.getValue().asRanges()) {
					Event ev = new Event();
					ev.x = en.getKey();
					ev.type = 2;
					ev.y1 = range.lowerEndpoint();
					ev.y2 = range.upperEndpoint();
					events.add(ev);
				}
			}

			Collections.sort(events);
			long ret = 0;
			id4 fw = new id4(Y.length);

			for (Event ev : events) {
				switch (ev.type) {
					case 1: {
						int pos = Arrays.binarySearch(Y, ev.y1);
						fw.update(pos, 1);
					}
					break;
					case 2: {

						int iy1 = MathUtils.lowerBound(Y, ev.y1);
						int iy2 = MathUtils.upperBound(Y, ev.y2);
						iy2--;
						if (iy2 >= iy1)
							ret += fw.get(iy1, iy2);
					}
					break;
					case 3: {
						int pos = Arrays.binarySearch(Y, ev.y1);
						fw.update(pos, -1);
					}
					break;

				}
			}

			return ret;
		}

		long sum(RangeSet<Integer> rs) {
			long ret = 0;
			for (Range<Integer> r : rs.asRanges()) {
				ret += r.upperEndpoint() - r.lowerEndpoint() + 1L;
			}
			return ret;
		}

		public Task call() {
	

			for (Map.Entry<Integer, RangeSet<Integer>> en : h.entrySet()) {
				RE += sum(en.getValue());
			}

			for (Map.Entry<Integer, RangeSet<Integer>> en : v.entrySet()) {
				RE += sum(en.getValue());
			}

			RE -= id25();


			System.err.println("Test case: " + testNumber + " done!");
			return this;
		}

		public void writeOutput(PrintWriter out) {
			out.println(RE);
		}

		Task(int testNumber) {
			this.testNumber = testNumber;
		}

		class Event implements Comparable<Event> {
			int x;
			int type;
			int y1;
			int y2;


			public int compareTo(Event o) {
				if (x != o.x) return Integer.compare(x, o.x);
				else return Integer.compare(type, o.type);
			}

		}

	}

	static abstract class id5<C extends Comparable> implements Serializable {
	}
}

