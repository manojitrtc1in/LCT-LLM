import java.util.NavigableSet;
import java.util.SortedSet;
import java.io.BufferedReader;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
import java.util.AbstractCollection;
import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.AbstractSet;
import java.util.ArrayList;
import java.util.Set;
import java.util.Iterator;
import java.util.Objects;
import java.util.NoSuchElementException;
import java.util.StringTokenizer;
import java.io.InputStream;


public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskD2 solver = new TaskD2();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD2 {
	public void solve(int testNumber, InputReader in, PrintWriter out) {
		int n = in.nextInt();
		int m = in.nextInt();

		int[] x1 = new int[n];
		int[] y1 = new int[n];
		int[] l1 = new int[n];
		for (int i = 0; i < n; i++) {
			x1[i] = in.nextInt();
			y1[i] = in.nextInt();
			l1[i] = in.nextInt();
		}

		int[] x2 = new int[m];
		int[] y2 = new int[m];
		int[] l2 = new int[m];
		for (int i = 0; i < m; i++) {
			x2[i] = in.nextInt();
			y2[i] = in.nextInt();
			l2[i] = in.nextInt();
		}

		int lo = 0;
		int hi = 1000_000_000;

		while (hi - lo > 1) {
			int mid = (lo + hi) >>> 1;
			List<Segment> segments = new ArrayList<>();

			for (int i = 0; i < n; i++)
				if (l1[i] >= 2 * mid)
					segments.add(new Segment(x1[i], y1[i] + mid, x1[i], y1[i] + l1[i] - mid));
			for (int i = 0; i < m; i++)
				if (l2[i] >= 2 * mid)
					segments.add(new Segment(x2[i] + mid, y2[i], x2[i] + l2[i] - mid, y2[i]));
			if (findIntersection(segments.toArray(new Segment[0])) != null) {
				lo = mid;
			} else {
				hi = mid;
			}
		}
		out.println(lo);
	}

	public static Segment[] findIntersection(Segment[] s) {
		int n = s.length;
		Event[] events = new Event[n * 2];
		for (int i = 0, cnt = 0; i < n; ++i) {
			events[cnt++] = new Event(s[i].x1, s[i].y1, 1, s[i]);
			events[cnt++] = new Event(s[i].x2, s[i].y2, -1, s[i]);
		}
		Arrays.sort(events, eventComparator);
		NavigableSet<Segment> set = new TreapSet<>(segmentComparator);

		for (Event event : events) {
			Segment cur = event.segment;
			if (event.type == 1) {
				Segment floor = set.floor(cur);
				if (floor != null && isCrossOrTouchIntersect(cur, floor))
					return new Segment[]{cur, floor};
				Segment ceiling = set.ceiling(cur);
				if (ceiling != null && isCrossOrTouchIntersect(cur, ceiling))
					return new Segment[]{cur, ceiling};
				set.add(cur);
			} else {
				Segment lower = set.lower(cur);
				Segment higher = set.higher(cur);
				if (lower != null && higher != null && isCrossOrTouchIntersect(lower, higher))
					return new Segment[]{lower, higher};
				set.remove(cur);
			}
		}
		return null;
	}

	public static class Segment {
		final int x1, y1, x2, y2;

		public Segment(int x1, int y1, int x2, int y2) {
			if (x1 < x2 || x1 == x2 && y1 < y2) {
				this.x1 = x1;
				this.y1 = y1;
				this.x2 = x2;
				this.y2 = y2;
			} else {
				this.x1 = x2;
				this.y1 = y2;
				this.x2 = x1;
				this.y2 = y1;
			}
		}
	}

	static final Comparator<Segment> segmentComparator = (a, b) -> {
		if (a.x1 == b.x1)
			return Integer.compare(a.y1, b.y1);
		if (a.x1 < b.x1) {
			long v = cross(a.x1, a.y1, a.x2, a.y2, b.x1, b.y1);
			if (v != 0)
				return v > 0 ? -1 : 1;
			return Integer.compare(a.y1, b.y1);
		} else {
			long v = cross(b.x1, b.y1, b.x2, b.y2, a.x1, a.y1);
			if (v != 0)
				return v < 0 ? -1 : 1;
			return Integer.compare(a.y1, b.y1);
		}
	};

	static class Event {
		final int x, y;
		final int type;
		final Segment segment;

		public Event(int x, int y, int type, Segment segment) {
			this.x = x;
			this.y = y;
			this.type = type;
			this.segment = segment;
		}
	}

	static final Comparator<Event> eventComparator = (a, b) -> {
		if (a.x != b.x)
			return a.x < b.x ? -1 : 1;
		if (a.type != b.type)
			return a.type > b.type ? -1 : 1;
		return Integer.compare(a.y, b.y);
	};

	static long cross(long ax, long ay, long bx, long by, long cx, long cy) {
		return (bx - ax) * (cy - ay) - (by - ay) * (cx - ax);
	}

	static boolean isCrossOrTouchIntersect(Segment s1, Segment s2) {
		long x1 = s1.x1;
		long y1 = s1.y1;
		long x2 = s1.x2;
		long y2 = s1.y2;
		long x3 = s2.x1;
		long y3 = s2.y1;
		long x4 = s2.x2;
		long y4 = s2.y2;
		if (Math.max(x1, x2) < Math.min(x3, x4) || Math.max(x3, x4) < Math.min(x1, x2)
				|| Math.max(y1, y2) < Math.min(y3, y4) || Math.max(y3, y4) < Math.min(y1, y2))
			return false;
		long z1 = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
		long z2 = (x2 - x1) * (y4 - y1) - (y2 - y1) * (x4 - x1);
		long z3 = (x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3);
		long z4 = (x4 - x3) * (y2 - y3) - (y4 - y3) * (x2 - x3);
		return (z1 <= 0 || z2 <= 0) && (z1 >= 0 || z2 >= 0) && (z3 <= 0 || z4 <= 0) && (z3 >= 0 || z4 >= 0);
	}

	static class TreapSet<E> extends AbstractSet<E> implements NavigableSet<E> {
		protected static final Random rnd = new Random();

		private class RootContainer {
			private Node root;
		}

		private final Comparator<? super E> comparator;
		private final RootContainer rc;
		private final E from;
		private final E to;
		private final boolean fromInclusive;
		private final boolean toInclusive;

		public TreapSet() {
			this(null);
		}

		public TreapSet(Comparator<? super E> comparator) {
			this(null, null, false, false, comparator, null);
		}

		protected TreapSet(E from, E to, boolean fromInclusive, boolean toInclusive, Comparator<? super E> comparator, RootContainer rc) {
			this.comparator = comparator;
			this.from = from;
			this.to = to;
			this.fromInclusive = fromInclusive;
			this.toInclusive = toInclusive;
			this.rc = rc != null ? rc : new RootContainer();
		}

		private int compare(E first, E second) {
			return comparator != null ? comparator.compare(first, second) : ((Comparable<? super E>) first).compareTo(second);
		}

		private boolean inRange(E e) {
			return (from == null || compare(from, e) < (fromInclusive ? 1 : 0)) && (to == null || compare(e, to) < (toInclusive ? 1 : 0));
		}

		private E keyOrNull(Node node) {
			return node != null && inRange(node.key) ? node.key : null;
		}

		public E lower(E e) {
			return rc.root == null ? null : keyOrNull(rc.root.lower(e));
		}

		public E floor(E e) {
			return rc.root == null ? null : keyOrNull(rc.root.floor(e));
		}

		public E ceiling(E e) {
			return rc.root == null ? null : keyOrNull(rc.root.ceil(e));
		}

		public E higher(E e) {
			return rc.root == null ? null : keyOrNull(rc.root.higher(e));
		}

		public E pollFirst() {
			E first = getFirst();
			if (first == null)
				return null;
			rc.root = rc.root.remove(first);
			return first;
		}

		public E pollLast() {
			E last = getLast();
			if (last == null)
				return null;
			rc.root = rc.root.remove(last);
			return last;
		}

		public int size() {
			if (rc.root == null)
				return 0;
			if (from == null && to == null)
				return rc.root.size;
			if (from == null) {
				Node to = toInclusive ? rc.root.floor(this.to) : rc.root.lower(this.to);
				if (to == null)
					return 0;
				return rc.root.indexOf(to.key) + 1;
			}
			if (to == null) {
				Node from = fromInclusive ? rc.root.ceil(this.from) : rc.root.higher(this.from);
				if (from == null)
					return 0;
				return rc.root.size - rc.root.indexOf(from.key);
			}
			Node from = fromInclusive ? rc.root.ceil(this.from) : rc.root.higher(this.from);
			if (from == null || !inRange(from.key))
				return 0;
			Node to = toInclusive ? rc.root.floor(this.to) : rc.root.lower(this.to);
			if (to == null || !inRange(to.key))
				return 0;
			return rc.root.indexOf(to.key) - rc.root.indexOf(from.key) + 1;
		}

		public boolean contains(Object o) {
			return rc.root != null && inRange((E) o) && rc.root.search((E) o) != null;
		}

		private abstract class TreapIterator<E> implements Iterator<E> {
			private E next = getStartKey();
			private E lastReturned = null;

			abstract E getStartKey();

			abstract E nextKey(E e);

			public boolean hasNext() {
				return next != null;
			}

			public E next() {
				if (next == null)
					throw new NoSuchElementException();
				lastReturned = next;
				next = nextKey(next);
				return lastReturned;
			}

			public void remove() {
				if (lastReturned == null)
					throw new IllegalStateException();
				TreapSet.this.remove(lastReturned);
				lastReturned = null;
			}
		}

		public Iterator<E> iterator() {
			return new TreapIterator<E>() {
				@Override
				protected E getStartKey() {
					return getFirst();
				}

				@Override
				protected E nextKey(E e) {
					return higher(e);
				}
			};
		}

		public Iterator<E> descendingIterator() {
			return new TreapIterator<E>() {
				@Override
				protected E getStartKey() {
					return getLast();
				}

				@Override
				protected E nextKey(E e) {
					return lower(e);
				}
			};
		}

		public boolean add(E e) {
			Objects.requireNonNull(e);
			if (!inRange(e))
				throw new IllegalArgumentException("key out of range");
			if (rc.root == null) {
				rc.root = createNode(e);
				return true;
			}
			if (contains(e))
				return false;
			rc.root = rc.root.insert(createNode(e));
			return true;
		}

		protected Node createNode(E e) {
			return new Node(e, rnd.nextLong());
		}

		public boolean remove(Object o) {
			if (!contains(o))
				return false;
			rc.root = rc.root.remove((E) o);
			return true;
		}

		public Comparator<? super E> comparator() {
			return comparator;
		}

		public NavigableSet<E> descendingSet() {
			throw new UnsupportedOperationException();
		}

		public NavigableSet<E> subSet(E fromElement, boolean fromInclusive, E toElement, boolean toInclusive) {
			return new TreapSet<E>(fromElement, toElement, fromInclusive, toInclusive, comparator, rc);
		}

		public SortedSet<E> subSet(E fromElement, E toElement) {
			return subSet(fromElement, true, toElement, false);
		}

		public NavigableSet<E> headSet(E toElement, boolean inclusive) {
			return subSet(null, false, toElement, inclusive);
		}

		public SortedSet<E> headSet(E toElement) {
			return headSet(toElement, false);
		}

		public NavigableSet<E> tailSet(E fromElement, boolean inclusive) {
			return subSet(fromElement, inclusive, null, false);
		}

		public SortedSet<E> tailSet(E fromElement) {
			return tailSet(fromElement, true);
		}

		private E getFirst() {
			if (isEmpty())
				return null;
			if (from == null)
				return rc.root.first().key;
			return fromInclusive ? ceiling(from) : higher(from);
		}

		public E first() {
			E res = getFirst();
			if (res == null)
				throw new NoSuchElementException();
			return res;
		}

		private E getLast() {
			if (isEmpty())
				return null;
			if (to == null)
				return rc.root.last().key;
			return toInclusive ? floor(to) : lower(to);
		}

		public E last() {
			E res = getLast();
			if (res == null)
				throw new NoSuchElementException();
			return res;
		}

		protected class Node {
			protected final E key;
			protected final long priority;
			protected Node left;
			protected Node right;
			protected int size;

			protected Node(E key, long priority) {
				this.key = key;
				this.priority = priority;
				left = null;
				right = null;
				size = 1;
			}

			protected void updateSize() {
				size = size(left) + size(right) + 1;
			}

			protected Node[] split(E minRightKey) {
				if (compare(minRightKey, key) < 0) {
					Node[] result = left == null ? new TreapSet.Node[2] : left.split(minRightKey);
					left = result[1];
					updateSize();
					result[1] = this;
					return result;
				} else {
					Node[] result = right == null ? new TreapSet.Node[2] : right.split(minRightKey);
					right = result[0];
					updateSize();
					result[0] = this;
					return result;
				}
			}

			protected Node merge(Node left, Node right) {
				if (left == null)
					return right;
				if (right == null)
					return left;
				if (left.priority > right.priority) {
					left.right = merge(left.right, right);
					left.updateSize();
					return left;
				} else {
					right.left = merge(left, right.left);
					right.updateSize();
					return right;
				}
			}

			protected Node insert(Node node) {
				if (node.priority > priority) {
					Node[] result = split(node.key);
					node.left = result[0];
					node.right = result[1];
					node.updateSize();
					return node;
				}
				if (compare(node.key, key) < 0) {
					left = left == null ? node : left.insert(node);
					updateSize();
					return this;
				} else {
					right = right == null ? node : right.insert(node);
					updateSize();
					return this;
				}
			}

			protected Node remove(E e) {
				int cmp = compare(e, key);
				if (cmp == 0)
					return merge(left, right);
				if (cmp < 0) {
					left = left == null ? null : left.remove(e);
					updateSize();
					return this;
				} else {
					right = right == null ? null : right.remove(e);
					updateSize();
					return this;
				}
			}

			protected Node lower(E e) {
				if (compare(key, e) >= 0)
					return left == null ? null : left.lower(e);
				Node result = right == null ? null : right.lower(e);
				return result == null ? this : result;
			}

			protected Node floor(E e) {
				if (compare(key, e) > 0)
					return left == null ? null : left.floor(e);
				Node result = right == null ? null : right.floor(e);
				return result == null ? this : result;
			}

			protected Node ceil(E e) {
				if (compare(key, e) < 0)
					return right == null ? null : right.ceil(e);
				Node result = left == null ? null : left.ceil(e);
				return result == null ? this : result;
			}

			protected Node higher(E e) {
				if (compare(key, e) <= 0)
					return right == null ? null : right.higher(e);
				Node result = left == null ? null : left.higher(e);
				return result == null ? this : result;
			}

			protected Node first() {
				return left == null ? this : left.first();
			}

			protected Node last() {
				return right == null ? this : right.last();
			}

			protected Node search(E e) {
				int cmp = compare(e, key);
				if (cmp == 0)
					return this;
				if (cmp < 0)
					return left == null ? null : left.search(e);
				else
					return right == null ? null : right.search(e);
			}

			protected int indexOf(E e) {
				int cmp = compare(e, key);
				if (cmp == 0)
					return size(left);
				if (cmp < 0)
					return left == null ? 0 : left.indexOf(e);
				else
					return size(left) + 1 + (right == null ? 0 : right.indexOf(e));
			}

			private int size(Node node) {
				return node == null ? 0 : node.size;
			}
		}
	}
}

class InputReader {
	public BufferedReader reader;
	public StringTokenizer tokenizer;

	public InputReader(InputStream stream) {
		reader = new BufferedReader(new InputStreamReader(stream));
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
}

