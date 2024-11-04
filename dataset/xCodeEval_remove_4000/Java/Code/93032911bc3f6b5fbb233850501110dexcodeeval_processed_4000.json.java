import java.io.*;
import java.util.*;



public class Parade {

	private static class Interval implements Comparable<Interval> {
		final int start, end, height;
		Interval(int start, int end, int height) {
			this.start = start;
			this.end = end;
			this.height = height;
		}
		@Override
		public int hashCode() {
			return start ^ end ^ height;
		}
		private int address() {
			return super.hashCode();
		}
		public int compareTo(Interval o) {
			int result = height - o.height;
			if(result != 0)
				return result;
			return address() - o.address();
		}
		int index;
		

		

	}
	

	private static class Point2 implements Comparable<Point2> {
		int x, h;
		@Override
		public String toString() {
			return x + " " + h;
		}
		Point2(int x, int h) {
			this.x = x;
			this.h = h;
		}
		boolean end;
		Interval interval;
		Point2(Interval interval, boolean end) {
			this(end ? interval.end : interval.start, 0);
			this.end = end;
			this.interval = interval;
		}
		

		

		

		public int compareTo(Point2 o) {
			int result = x - o.x;
			if(result != 0)
				return result;
			if(!end) {
				if(!o.end) {
					result = interval.height - o.interval.height;
					return result != 0 ? result : interval.address() - o.interval.address();
				} else
					return 1;
			} else {
				if(!o.end)
					return -1;
				else {
					result = o.interval.height - interval.height;
					return result != 0 ? result : o.interval.address() - interval.address();
				}
			}
		}
	}

	public static void solve5() throws IOException {
		Scanner scanner = new Scanner(System.in);
		int n = Integer.parseInt(scanner.next());
		Point2 points[] = new Point2[n * 2];
		Interval buildings[] = new Interval[n];
		for(int i = 0; i < n; i++) {
			int h = Integer.parseInt(scanner.next()), left = Integer.parseInt(scanner.next()), right = Integer.parseInt(scanner.next());
			assert left < right;
			buildings[i] = new Interval(left, right, h);
			points[i] = new Point2(buildings[i], false);
			points[n + i] = new Point2(buildings[i], true);
		}
		System.in.close();

		qsort( points);
		qsort(buildings);
		for(int i = 0; i < buildings.length; i++)
			buildings[i].index = i;
		{
			boolean heights[] = new boolean[buildings.length];
			short m = (short)Math.round(Math.sqrt(n)), index[] = new short[(n - 1) / m + 1];
			int top = -1, bottom = n, max = 0;
			for(int i = 0; i < points.length; i++) {
				Point2 point = points[i];
				if(!point.end) {
					heights[point.interval.index] = true;
					top = Math.max(top, point.interval.index);
					max = Math.max(max, point.interval.height);
					bottom = Math.min(bottom, point.interval.index);
					index[point.interval.index / m]++;
				} else {
					heights[point.interval.index] = false;
					index[point.interval.index / m]--;
					if(max == point.interval.height) {
						max = 0;
						if(index[top / m] == 0) {
							for(top = top / m - 1; top >= 0 && index[top] == 0; top--);
							if(top >= 0)
								top = (top + 1) * m - 1;
						}
						for(int j = top; j >= bottom; j--) {
							if(heights[j]) {
								max = buildings[top = j].height;
								break;
							}
						}
						if(max == 0) {
							bottom = n;
							top = -1;
						}
					}
				}
				if(i != 0 && points[i - 1].x == point.x)
					points[i - 1] = null;
				point.h = max;
			}
		}

		
		int r = 0, prevx = 0, prevh = -1;
		for(Point2 point : points) {
			if(point == null || point.h == prevh)
				continue;
			if(prevh == -1) {
				r++;
				prevx = point.x;
				prevh = 0;
			}
			if(point.h != prevh && point.x != prevx) {
				r++;
			}
			prevx = point.x;
			prevh = point.h;
			r++;
		}
		System.out.println(r);
		prevx = 0;
		prevh = -1;
		for(Point2 point : points) {
			if(point == null || point.h == prevh)
				continue;
			if(prevh == -1) {
				System.out.print(point.x);
				System.out.println(" 0");
				prevx = point.x;
				prevh = 0;
			}
			if(point.h != prevh && point.x != prevx) {
				System.out.print(point.x);
				System.out.print(' ');
				System.out.println(prevh);
			}
			System.out.print(prevx = point.x);
			System.out.print(' ');
			System.out.println(prevh = point.h);
		}
	}

	public static List<Point2> solve4(BufferedReader reader) throws IOException {
		int n = Integer.parseInt(reader.readLine());
		Point2 points[] = new Point2[n * 2];
		Interval buildings[] = new Interval[n];
		for(int i = 0; i < n; i++) {
			String[] s = reader.readLine().split(" ");
			assert s.length == 3;
			int h = Integer.parseInt(s[0]), left = Integer.parseInt(s[1]), right = Integer.parseInt(s[2]);
			assert left < right;
			buildings[i] = new Interval(left, right, h);
			points[i] = new Point2(buildings[i], false);
			points[n + i] = new Point2(buildings[i], true);
		}
		reader.close();
		


		qsort( points);
		qsort(buildings);
		for(int i = 0; i < buildings.length; i++)
			buildings[i].index = i;
		{
			boolean heights[] = new boolean[buildings.length];
			short m = (short)Math.round(Math.sqrt(n)), index[] = new short[(n - 1) / m + 1];
			int top = -1, bottom = n, max = 0;
			for(int i = 0; i < points.length; i++) {
				Point2 point = points[i];
				if(!point.end) {
					heights[point.interval.index] = true;
					top = Math.max(top, point.interval.index);
					max = Math.max(max, point.interval.height);
					bottom = Math.min(bottom, point.interval.index);
					index[point.interval.index / m]++;
				} else {
					heights[point.interval.index] = false;
					index[point.interval.index / m]--;
					if(max == point.interval.height) {
						max = 0;
						if(index[top / m] == 0) {
							for(top = top / m - 1; top >= 0 && index[top] == 0; top--);
							if(top >= 0)
								top = (top + 1) * m - 1;
						}
						for(int j = top; j >= bottom; j--) {
							if(heights[j]) {
								max = buildings[top = j].height;
								break;
							}
						}
						if(max == 0) {
							bottom = n;
							top = -1;
						}
					}
				}
				if(i != 0 && points[i - 1].x == point.x)
					points[i - 1] = null;
				point.h = max;
			}
		}
		


		List<Point2> result = new LinkedList<Point2>();
		Point2 prev = null;
		for(Point2 point : points) {
			if(point == null || prev != null && point.h == prev.h)
				continue;
			if(prev == null)
				result.add(prev = new Point2(point.x, 0));
			assert !point.end || point.h < prev.h;
			if(point.h != prev.h && point.x != prev.x)
				result.add(new Point2(point.x, prev.h));
			result.add(prev = point);
		}
		return result;
	}

	public static List<Point2> solve2(BufferedReader reader) throws IOException {
		int n = Integer.parseInt(reader.readLine());
		Point2 points[] = new Point2[n * 2];
		for(int i = 0; i < n; i++) {
			String[] s = reader.readLine().split(" ");
			assert s.length == 3;
			int h = Integer.parseInt(s[0]), left = Integer.parseInt(s[1]), right = Integer.parseInt(s[2]);
			assert left < right;
			Interval building = new Interval(left, right, h);
			points[i] = new Point2(building, false);
			points[n + i] = new Point2(building, true);
		}
		reader.close();

		qsort( points);

		{
			SortedSet<Interval> set = new TreeSet<Interval>();
			

			int max = 0;
			for(int i = 0; i < points.length; i++) {
				Point2 point = points[i];
				if(!point.end) {
					set.add(point.interval);
					max = Math.max(max, point.interval.height);
				} else {
					set.remove(point.interval);
					if(max == point.interval.height)
						max = !set.isEmpty() ? set.last().height : 0;
				}
				if(i != 0 && points[i - 1].x == point.x)
					points[i - 1] = null;
				point.h = max;
			}
		}
		System.gc();

		List<Point2> result = new LinkedList<Point2>();
		Point2 prev = null;
		for(Point2 point : points) {
			if(point == null || prev != null && point.h == prev.h)
				continue;
			if(prev == null)
				result.add(prev = new Point2(point.x, 0));
			assert !point.end || point.h < prev.h;
			if(point.h != prev.h && point.x != prev.x)
				result.add(new Point2(point.x, prev.h));
			result.add(prev = point);
		}
		return result;
	}

	public static void main(String[] args) throws IOException {
		
		

		

		

		System.setIn(new FileInputStream("input.txt"));
		System.setOut(new PrintStream("output.txt"));
		

		

		

		

		

		

		solve5();
	}

	public static void test1() throws IOException {
		Random random = new Random(1);
		int n = 10; 

		StringBuilder sb = new StringBuilder();
		sb.append(n).append('\n');
		for(int i = 0; i < n; i++) {
			sb.append(1 + random.nextInt((int)100)).append(' ');
			int left = 100 - random.nextInt((int)100);
			sb.append(left).append(' ');
			sb.append(left + 1 + random.nextInt((int)100)).append('\n');
		}
		char a[] = sb.toString().toCharArray();
		long startTime = System.currentTimeMillis();
		List<Point2> result2 = solve4(new BufferedReader(new CharArrayReader(a)));
		long time2 = -(startTime - (startTime = System.currentTimeMillis()));
		List<Point> result1 = solve1(new BufferedReader(new CharArrayReader(a)));
		long time1 = System.currentTimeMillis() - startTime;
		System.out.println(time2 + "/" + time1);
		

	}

	public static void test() throws IOException {
		Random random = new Random(1);
		int n = 100000; 

		StringBuilder sb = new StringBuilder();
		sb.append(n).append('\n');
		for(int i = 0; i < n; i++) {
			sb.append(1 + random.nextInt((int)10e8)).append(' ');
			int left = (int)10e8 / 2 - random.nextInt((int)10e8);
			sb.append(left).append(' ');
			sb.append(left + 1 + random.nextInt((int)10e8)).append('\n');
		}
		char a[] = sb.toString().toCharArray();
		long startTime = System.currentTimeMillis();
		List<Point2> result2 = solve4(new BufferedReader(new CharArrayReader(a)));
		long time2 = -(startTime - (startTime = System.currentTimeMillis()));
		List<Point> result1 = solve1(new BufferedReader(new CharArrayReader(a)));
		long time1 = System.currentTimeMillis() - startTime;
		System.out.println(time2 + "/" + time1);
		

	}

	public static void test34() throws IOException {
		int n = 100000;
		StringBuilder sb = new StringBuilder();
		sb.append(n).append('\n');
		for(int i = 0; i < n; i++) {
			sb.append(1 + i).append(' ');
			sb.append(i - 1000000000).append(' ');
			sb.append(1000000000 - i).append('\n');
		}
		char a[] = sb.toString().toCharArray();
		long startTime = System.currentTimeMillis();
		solve4(new BufferedReader(new CharArrayReader(a)));
		long time2 = System.currentTimeMillis() - startTime;
		System.out.println(time2);
	}

	public static void test35() throws IOException {
		int n = 100000;
		StringBuilder sb = new StringBuilder();
		sb.append(n).append('\n');
		for(int i = 0; i < n; i++) {
			sb.append(i * 10000 + 1).append(' ');
			sb.append(i * 10000 - 1000000000).append(' ');
			sb.append(1000000000 - i * 10000).append('\n');
		}
		char a[] = sb.toString().toCharArray();
		long startTime = System.currentTimeMillis();
		solve4(new BufferedReader(new CharArrayReader(a)));
		long time2 = System.currentTimeMillis() - startTime;
		System.out.println(time2);
	}

	private static class Point implements Comparable<Point> {
		protected int x, h;
		Point(int x, int h) {
			this.x = x;
			this.h = h;
		}
		public int compareTo(Point o) {
			int result = x - o.x;
			if(result != 0)
				return result;
			return h - o.h;
		}
		@Override
		public String toString() {
			return x + " " + h;
		}
		@Override
		public boolean equals(Object o) {
			return o instanceof Point && equals((Point)o);
		}
		public boolean equals(Point o) {
			return x == o.x && h == o.h;
		}
	}
	public static List<Point> solve1(BufferedReader reader) throws IOException {
		int n = Integer.parseInt(reader.readLine());
		List<Point> list = new ArrayList<Point>(2 * (n + 1));
		list.add(new Point(Integer.MIN_VALUE, 0));
		list.add(new Point(Integer.MAX_VALUE, 0));
		for(; n > 0; n--) {
			String[] s = reader.readLine().split(" ");
			assert s.length == 3;
			int h = Integer.parseInt(s[0]), left = Integer.parseInt(s[1]), right = Integer.parseInt(s[2]);
			assert left < right;
			boolean b = false;
			int ph = 0;
			for(ListIterator<Point> iterator = list.listIterator(Math.max(0, -2 - Collections.binarySearch(list, new Point(left, -1)))); iterator.hasNext();) {
				Point p = iterator.next();
				if(p.x >= left && !b) {
					iterator.previous();
					Point t = iterator.previous();
					iterator.next();
					if(p.x != left && t.h < h)
						iterator.add(new Point(left, h));
					iterator.next();
					b = true;
					ph = t.h;
				}
				if(b) {
					if(p.x >= right) {
						if(p.x != right && ph < h) {
							iterator.set(new Point(right, ph));
							iterator.add(p);
						}
						break;
					}
					ph = p.h;
					if(h > p.h)
						p.h = h;
				}
			}
		}
		assert list.size() >= 4 && list.get(0).x == Integer.MIN_VALUE && list.get(list.size() - 1).x == Integer.MAX_VALUE;
		List<Point> result = new LinkedList<Point>();
		Point prev = null;
		for(Point p : list) {
			if(prev != null && p.h == prev.h)
				continue;
			if(prev != null && p.h != prev.h && p.x != prev.x)
				result.add(new Point(p.x, prev.h));
			if(p.x != Integer.MIN_VALUE && p.x != Integer.MAX_VALUE)
				result.add(p);
			prev = p;
		}
		return result;
	}

	public static List<Point2> solve3(BufferedReader reader) throws IOException {
		int n = Integer.parseInt(reader.readLine());
		Interval buildings[] = new Interval[n];
		Point2 points[] = new Point2[n * 2];
		for(int i = 0; i < n; i++) {
			String[] s = reader.readLine().split(" ");
			assert s.length == 3;
			int h = Integer.parseInt(s[0]), left = Integer.parseInt(s[1]), right = Integer.parseInt(s[2]);
			assert left < right;
			buildings[i] = new Interval(left, right, h);
			points[i] = new Point2(buildings[i], false);
			points[n + i] = new Point2(buildings[i], true);
		}

		qsort(points);

		for(int i = 0; i < n; i++) {
			int start = Arrays.binarySearch(points, new Point2(buildings[i], false));
			int end = Arrays.binarySearch(points, new Point2(buildings[i], true));
			for(int j = start; j < end; j++) {
				points[j].h = Math.max(points[j].h, buildings[i].height);
			}
		}
		for(int i = 1; i < points.length; i++) {
			if(points[i - 1].x == points[i].x)
				points[i - 1] = null;
		}

		List<Point2> result = new LinkedList<Point2>();
		Point2 prev = null;
		for(Point2 point : points) {
			if(point == null || prev != null && point.h == prev.h)
				continue;
			if(prev == null)
				result.add(prev = new Point2(point.x, 0));
			assert !point.end || point.h < prev.h;
			if(point.h != prev.h && point.x != prev.x)
				result.add(new Point2(point.x, prev.h));
			result.add(prev = point);
		}
		return result;
	}

	private static final int H[] = new int[] {1, 4, 9, 24, 85, 126};
	private static <T extends Comparable<T>> void ssort(T[] a, int lo, int hi) {
		for(int k = H.length - 1; k >= 0; k--) {
			for(int h = H[k], i = lo + h, j; i <= hi; i++) {
				T m = a[i];
				for(j = i - h; j >= lo && a[j].compareTo(m) > 0; j -= h)
					a[j + h] = a[j];
				a[j + h] = m;
			}
		}
	}
	private static <T extends Comparable<T>> void qsort(T[] a) {
		qsort(a, 0, a.length - 1);
	}
	private static <T extends Comparable<T>> void qsort(T[] a, int lo, int hi) {
		for(;;) {
			if(hi - lo < 256) {
				ssort(a, lo, hi);
				return;
			}
			int i = lo, j = hi;
			for(T m = a[(lo + hi) / 2];;) {
				while(i < hi && a[i].compareTo(m) < 0)
					i++;
				while(j > lo && a[j].compareTo(m) > 0)
					j--;
				if(i >= j)
					break;
				T t = a[i]; a[i++] = a[j]; a[j--] = t;
			}
			if((--i - lo) < (hi - ++j)) {
				qsort(a, lo, i);
				lo = j;
			} else {
				qsort(a, j, hi);
				hi = i;
			}
		}
	}

	
}
