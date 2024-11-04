import java.io.*;
import java.math.BigInteger;
import static java.lang.Math.*;
import java.util.*;
 
public class Solution {
  static BufferedReader cin;
  static PrintWriter cout;
  static StringTokenizer tok;
  static final double EPS = 1e-9;
  static final int INF = 1000000000;
  
  

  public static String nextToken() throws Exception {
    if (tok == null || !tok.hasMoreTokens()) {
      tok = new StringTokenizer(cin.readLine());
    }
    return tok.nextToken();
  }
  public static int nextInt() throws Exception {
    return Integer.parseInt(nextToken());
  }
  public static long nextLong() throws Exception {
    return Long.parseLong(nextToken());
  }
  public static BigInteger id3() throws Exception {
    return new BigInteger(nextToken());
  }
  public static double nextDouble() throws NumberFormatException, Exception {
    return Double.parseDouble(nextToken());
  }
  public static int[] id4(int n, boolean minusOne) throws Exception {
  	int[] array = new int[n];
  	for (int i = 0; i < n; i++) {
  		array[i] = nextInt() - (minusOne ? 1 : 0);
  	}
  	return array;
  }
  public static int[] id4(int n) throws Exception {
  	return id4(n, false);
  }
  public static int[] id4() throws Exception {
  	return id4(nextInt(), false);
  }
  public static int[] nextIndices(int n) throws Exception {
  	return id4(n, true);
  }
  public static int[] nextIndices() throws Exception {
  	return id4(nextInt(), true);
  }
  public static double[] id11(int n) throws Exception {
  	double[] array = new double[n];
  	for (int i = 0; i < n; i++) {
  		array[i] = nextDouble();
  	}
  	return array;
  }
  public static double[] id11() throws Exception {
  	return id11(nextInt());
  }
  public static long[] id12(int n) throws Exception {
  	long[] array = new long[n];
  	for (int i = 0; i < n; i++) {
  		array[i] = nextLong();
  	}
  	return array;
  }
  public static long[] id12() throws Exception {
  	return id12(nextInt());
  }
  public static String[] id1(int n) throws Exception {
  	String[] array = new String[n];
  	for (int i = 0; i < n; i++) {
  		array[i] = nextToken();
  	}
  	return array;
  }
  public static String[] id1() throws Exception {
  	return id1(nextInt());
  }
  public static BigInteger[] id9(int n) throws Exception {
  	BigInteger[] array = new BigInteger[n];
  	for (int i = 0; i < n; i++) {
  		array[i] = id3();
  	}
  	return array;
  }
  public static BigInteger[] id9() throws Exception {
  	return id9(nextInt());
  }
  public static void printArray(int[] array, boolean printLength, boolean plusOne) {
  	if (printLength) cout.println(array.length);
  	for (int i = 0; i < array.length; i++) {
  		cout.print((array[i] + (plusOne ? 1 : 0)) + (i < array.length - 1 ? " " : "\n"));
  	}
  }
  public static void printArray(double[] array, boolean printLength) {
  	if (printLength) cout.println(array.length);
  	for (int i = 0; i < array.length; i++) {
  		cout.print(array[i] + (i < array.length - 1 ? " " : "\n"));
  	}
  }
  public static void printArray(long[] array, boolean printLength) {
  	if (printLength) cout.println(array.length);
  	for (int i = 0; i < array.length; i++) {
  		cout.print(array[i] + (i < array.length - 1 ? " " : "\n"));
  	}
  }
  public static void printArray(Object[] array, boolean printLength) {
  	if (printLength) cout.println(array.length);
  	for (int i = 0; i < array.length; i++) {
  		cout.print(array[i] + (i < array.length - 1 ? " " : "\n"));
  	}
  }
  public static void printArray(List array, boolean printLength) {
  	int i = 0, n = array.size();
  	if (printLength) cout.println(n);
  	for (Object e : array) {
  		cout.print(e + (i < n - 1 ? " " : "\n"));
  		i++;
  	}
  }
  public static void printArray(int[] array, boolean printLength) { printArray(array, printLength, false); }
  public static void printArray(int[] array) { printArray(array, true, false); }
  public static void printIndices(int[] array, boolean printLength) { printArray(array, printLength, true); }
  public static void printIndices(int[] array) { printArray(array, true, true); }
  public static void printArray(double[] array) { printArray(array, true); }
  public static void printArray(Object[] array) { printArray(array, true); }
  public static void printArray(List array) { printArray(array, true); }
  
  
  
  
  public static int gcd(int a, int b) {
  	if (b == 0) return a; else return gcd(b, a % b);
  }
  public static double det(double a, double b, double c, double d) { return a * d - b * c; }
  public static boolean isBetween(double l, double r, double x) { return min(l, r) <= x + EPS && x <= max(l, r) + EPS; }
  public static double clamp(double t, double mn, double mx) { return min(max(t, mn), mx); }
  public static int clamp(int t, int mn, int mx) { return min(max(t, mn), mx); }
  public static long clamp(long t, long mn, long mx) { return min(max(t, mn), mx); }
  public static boolean id6(double a1, double a2, double b1, double b2) {
  	double t;
  	if (a1 > a2) { t = a2; a2 = a1; a1 = t; }
  	if (b1 > b2) { t = b2; b2 = b1; b1 = t; }
  	return max(a1, b1) <= min(a2, b2) + EPS;
  }
  
  
  
  public static class Graph {
  	public ArrayList<Integer>[] e;
  	public ArrayList<Long>[] w; 

  	public int n;
  	
  	public Graph(int n) {
  		this.n = n;
  		this.e = new ArrayList[n];
  		for (int i = 0; i < n; i++) {
  			this.e[i] = new ArrayList<Integer>();
  			this.w[i] = new ArrayList<Long>();
  		}
  	}
  	
  	public void addEdge(int a, int b, long w) {
  		this.e[a].add(b);
  		this.w[a].add(w);
  	}
  	
  	public static class SearchResults {
  		boolean[] used;
  		int[] p;
  		long[] d;
  		long[] o; 

  		public SearchResults(int n) {
      	used = new boolean[n];
      	p = new int[n];
      	d = new long[n];
      	o = new long[n];
      	for (int i = 0; i < n; i++) {
      		p[i] = -1;
      	}
  		}
  		
  		public ArrayList<Integer> id8(int e) {
  			if (!used[e]) {
  				return null;
  			}
  			ArrayList<Integer> path = new ArrayList<Integer>();
  			while (e != -1) {
  				path.add(e);
  				e = p[e];
  			}
  			Collections.reverse(path);
  			return path;
  		}
  	}
  	
    public SearchResults bfs(int s, SearchResults result) {
    	if (result == null) {
    		result = new SearchResults(n);
    	}
    	LinkedList<Integer> q = new LinkedList();
    	q.push(s);
    	result.used[s] = true;
    	result.p[s] = -1;
    	while (!q.isEmpty()) {
    		int v = q.pollFirst();
    		for (int i = 0; i < e[v].size(); i++) {
    			int to = e[v].get(i);
    			if (!result.used[to]) {
    				q.push(to);
    				result.d[to] = result.d[v] + 1;
    				result.p[to] = v;
    				result.used[to] = true;
    			}
    		}
    	}
    	return result;
    }
    
    private int dfs(int s, SearchResults result, int timer) {
    	result.used[s] = true;
			result.d[s] = timer++;
    	for (int i = 0; i < e[s].size(); i++) {
  			int to = e[s].get(i);
    		if (!result.used[to]) {
    			result.p[to] = s;
    			timer = dfs(to, result, timer);
    		}
    	}
    	result.o[s] = timer++;
    	return timer;
    }
    public SearchResults dfs(int s, SearchResults result) {
    	if (result == null) {
    		result = new SearchResults(n);
    	}
    	this.dfs(s, result, 0);
    	return result;
    }
  
    public SearchResults dijkstra(int s) {
    	SearchResults result = new SearchResults(n);
    	id0.Entry<Integer>[] entries = new id0.Entry[n];
    	id0<Integer> heap = new id0<Integer>();
    	for (int i = 0; i < n; i++) {
    		result.d[i] = i == s ? 0 : INF;
    		entries[i] = heap.enqueue(i, result.d[i]);
    	}
    	while (!heap.isEmpty()) {
    		int u = heap.id2().value;
    		for (int i = 0; i < e[u].size(); i++) {
    			int v = e[u].get(i);
    			long alt = result.d[u] + w[u].get(i);
    			if (alt < result.d[v]) {
    				result.d[v] = alt;
    				result.p[v] = u;
    				heap.id7(entries[v], alt);
    			}
    		}
    	}
    	return result;
    }
  }
  
  public static Graph nextGraph(boolean biDir) throws Exception {
  	Graph g = new Graph(nextInt());
  	int edges = nextInt();
  	for (int i = 0; i < edges; i++) {
  		int a = nextInt() - 1;
  		int b = nextInt() - 1;
  		g.addEdge(a, b, 1L);
  		if (biDir) {
  			g.addEdge(b, a, 1L);
  		}
  	}
  	return g;
  }
  
  public static class id0<T> {
    public static final class Entry<T> {
      private Entry<T> next, prev, parent, child;
      private boolean mark = false;
      private int degree = 0;

      public double priority;
      public T value;

      private Entry(T value, double priority) {
        this.value = value;
        this.priority = priority;
        next = prev = this;
      }
    }

    public Entry<T> min = null;
    public int size = 0;

    public Entry<T> enqueue(T value, double priority) {
      Entry<T> result = new Entry<T>(value, priority);
      min = mergeLists(min, result);
      size++;
      return result;
    }

    public boolean isEmpty() { return min == null; }
    
    public static <T> id0<T> merge(id0<T> one, id0<T> two) {
      id0<T> result = new id0<T>();
      result.min = mergeLists(one.min, two.min);
      result.size = one.size + two.size;
      one.size = two.size = 0;
      one.min  = null;
      two.min  = null;
      return result;
    }

    public Entry<T> id2() {
      size--;
      Entry<T> minEntry = min;
      if (min.next == min) {
        min = null;
      } else {
        min.prev.next = min.next;
        min.next.prev = min.prev;
        min = min.next;
      }

      if (minEntry.child != null) {
        Entry<?> cur = minEntry.child;
        do {
          cur.parent = null;
          cur = cur.next;
        } while (cur != minEntry.child);
      }
      
      min = mergeLists(min, minEntry.child);
      if (min == null) return minEntry;

      List<Entry<T>> treeTable = new ArrayList<Entry<T>>();
      List<Entry<T>> toVisit = new ArrayList<Entry<T>>();
      for (Entry<T> cur = min; toVisit.isEmpty() || toVisit.get(0) != cur; cur = cur.next)
        toVisit.add(cur);

      for (Entry<T> cur: toVisit) {
        while (true) {
          while (cur.degree >= treeTable.size()) treeTable.add(null);
          if (treeTable.get(cur.degree) == null) {
            treeTable.set(cur.degree, cur);
            break;
          }
          Entry<T> other = treeTable.get(cur.degree);
          treeTable.set(cur.degree, null);
          Entry<T> min = (other.priority < cur.priority)? other : cur;
          Entry<T> max = (other.priority < cur.priority)? cur  : other;
          max.next.prev = max.prev;
          max.prev.next = max.next;
          max.next = max.prev = max;
          min.child = mergeLists(min.child, max);
          max.parent = min;
          max.mark = false;
          ++min.degree;
          cur = min;
        }
        if (cur.priority <= min.priority) min = cur;
      }
      return minEntry;
    }
    
    public void delete(Entry<T> entry) {
      id7(entry, Double.NEGATIVE_INFINITY);
      id2();
    }
    
    private static <T> Entry<T> mergeLists(Entry<T> one, Entry<T> two) {
      if (one == null && two == null) return null;
      else if (one != null && two == null) return one;
      else if (one == null && two != null) return two;
      else {
        Entry<T> oneNext = one.next;
        one.next = two.next;
        one.next.prev = one;
        two.next = oneNext;
        two.next.prev = two;
        return one.priority < two.priority? one : two;
      }
    }

    public void id7(Entry<T> entry, double priority) {
      entry.priority = priority;
      if (entry.parent != null && entry.priority <= entry.parent.priority) cutNode(entry);
      if (entry.priority <= min.priority) min = entry;
    }

    private void cutNode(Entry<T> entry) {
      entry.mark = false;
      if (entry.parent == null) return;
      if (entry.next != entry) {
        entry.next.prev = entry.prev;
        entry.prev.next = entry.next;
      }
      if (entry.parent.child == entry) {
        if (entry.next != entry) {
          entry.parent.child = entry.next;
        } else {
          entry.parent.child = null;
        }
      }
      --entry.parent.degree;
      entry.prev = entry.next = entry;
      min = mergeLists(min, entry);
      if (entry.parent.mark) cutNode(entry.parent); else entry.parent.mark = true;
      entry.parent = null;
    }
  }
  
  
  
  public static int[] prefixFunc(String s) {
  	int n = s.length();
  	int[] p = new int[n];
  	for (int i = 1; i < n; i++) {
  		int j = p[i - 1];
  		while (j > 0 && s.charAt(i) != s.charAt(j)) {
  			j = p[j - 1];
  		}
  		if (s.charAt(i) == s.charAt(j)) j++;
  		p[i] = j;
  	}
  	return p;
  }
  public static ArrayList<Integer> id5(String s, String t) { 

  	int n = s.length();
  	int[] p = prefixFunc(s + "\0" + t);
  	ArrayList<Integer> result = new ArrayList<Integer>();
  	for (int i = n + 1; i < p.length; i++) {
  		if (p[i] == n) {
  			result.add(i - 2 * n);
  		}
  	}
  	return result;
  }
  
  
  
  public static class Pt implements Comparable<Pt> {
  	double x;
  	double y;
  	public static final Pt ZERO = new Pt(0, 0);
  	public Pt(double x, double y) {
  		this.x = x;
  		this.y = y;
  	}
  	public double dot(Pt p) {
  		return x * p.x + y * p.y;
  	}
  	public double distSq(Pt p) {
  		return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y);
  	}
  	public double dist(Pt p) {
  		return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
  	}
  	public double dist(Line line) {
  		return line.a * x + line.b * y + line.c;
  	}
  	public double dist(LineSegment segment) {
  		return segment.dist(this);
  	}
  	public boolean equals(Pt p) {
  		return abs(x - p.x) < EPS && abs(y - p.y) < EPS;
  	}
  	public boolean isZero() {
  		return abs(x) < EPS && abs(y) < EPS;
  	}
		@Override
		public int compareTo(Pt p) {
			if (x < p.x - EPS) {
				return -1;
			} else
			if (abs(x - p.x) < EPS) {
				if (y < p.y - EPS) {
					return -1;
				} else
				if (abs(y - p.y) < EPS) {
					return 0;
				}
			}
			return 1;
		}
  }
  public static class IndexedPt extends Pt {
  	public int i;
  	public IndexedPt(double x, double y, int i) {
  		super(x, y);
  		this.i = i;
  	}
  }
  public static class LongPt implements Comparable<LongPt> {
  	long x;
  	long y;
  	public static final LongPt ZERO = new LongPt(0, 0);
  	public LongPt(long x, long y) {
  		this.x = x;
  		this.y = y;
  	}
  	public long dot(LongPt p) {
  		return x * p.x + y * p.y;
  	}
  	public long distSq(LongPt p) {
  		return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y);
  	}
  	public double dist(LongPt p) {
  		return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
  	}
  	public boolean equals(LongPt p) {
  		return x == p.x && y == p.y;
  	}
  	public boolean isZero() {
  		return x == 0 && y == 0;
  	}
		@Override
		public int compareTo(LongPt p) {
			if (x < p.x) {
				return -1;
			} else
			if (x == p.x) {
				if (y < p.y) {
					return -1;
				} else
				if (y == p.y) {
					return 0;
				}
			}
			return 1;
		}
		public String toString() {
			return "[" + x + "," + y + "]";
		}
  }
  public static class id10 extends LongPt {
  	public int i;
  	public id10(long x, long y, int i) {
  		super(x, y);
  		this.i = i;
  	}
  }
  public static class Line {
  	double a;
  	double b;
  	double c;
  	public Line(double a, double b, double c) {
  		this.a = a;
  		this.b = b;
  		this.c = c;
  	}
  	public Line(Pt v, Pt w) {
  		a = v.y - w.y;
  		b = w.x - v.x;
  		c = - a * v.x - b * v.y;
  		normalise();
  	}
  	public void normalise() {
  		double z = sqrt(a * a + b * b);
  		if (abs(z) > EPS) {
  			a /= z;  b /= z; c /= z;
  		}
  	}
  	public double dist(Pt p) {
  		return a * p.x + b * p.y + c;
  	}
  	public Pt intersect(Line line) {
  		double zn = det(a, b, line.a, line.b);
  		if (abs(zn) < EPS) return null;
  		return new Pt(
  			-det(c, b, line.c, line.b) / zn,
  		  -det(a, c, line.a, line.c) / zn
  		);
  	}
  	public boolean isParallel(Line line) {
  		return abs(det(a, b, line.a, line.b)) < EPS;
  	}
  	public boolean equals(Line line) {
  		return abs(det(a, b, line.a, line.b)) < EPS
  				&& abs(det(a, c, line.a, line.c)) < EPS
  				&& abs(det(b, c, line.b, line.c)) < EPS;
  	}
  }
  public static class LineSegment extends Line {
  	public Pt v;
  	public Pt w;
  	public LineSegment(Pt v, Pt w) {
  		super(v, w);
  		this.v = v;
  		this.w = w;
  	}
  	public Pt closest(Pt p) {
  		double len = lengthSq();
  		if (len < EPS) {
  			return v;
  		}
  		double t = ((p.x - v.x) * (w.x - v.x) + (p.y - v.y) * (w.y - v.y)) / len;
  		t = clamp(t, 0, 1);
  		return new Pt(v.x + t * (w.x - v.x), v.y + t * (w.y - v.y));
  	}
  	public double distSq(Pt p) {
  		return p.dist(closest(p));
  	}
  	public double dist(Pt p) {
  		return sqrt(p.dist(closest(p)));
  	}
  	public double lengthSq() {
  		return (v.x - w.x) * (v.x - w.x) + (v.y - w.y) * (v.y - w.y);
  	}
  	public double length() {
  		return sqrt((v.x - w.x) * (v.x - w.x) + (v.y - w.y) * (v.y - w.y));
  	}
  }
  
  public static long slow(int n, long[] a, long[] t) throws Exception {
    id0<Integer> heap = new id0<Integer>();
    for (int i = 0; i < n; i++) {
    	heap.enqueue(i, a[i] * 1000000L + t[i]);
    }
    
    long sum = 0;
    id0.Entry prevEntry = null;
    while (!heap.isEmpty()) {
    	id0.Entry entry = heap.id2();
    	long cur = (long) (entry.priority / 1000000L);
    	if (prevEntry != null) {
	    	long prev = (long) (prevEntry.priority / 1000000L);
	    	if (prev == cur) {
	      	int i = (Integer) prevEntry.value;
	    		sum += t[i];
	    		heap.enqueue(i, prevEntry.priority + 1000000L);
	    	}
    	}
    	prevEntry = entry;
    }
    
    return sum;
  }
  
  public static long solve(int n, long[] a, long[] t) throws Exception {
  	

    LongPt[] counts = new LongPt[n];
    for (int i = 0; i < n; i++) {
    	counts[i] = new LongPt(a[i], i);
    }
    Arrays.sort(counts);
    
    long sum = 0;
    long heapTotal = 0;
    long prev = -1;
    id0<Integer> heap = new id0<Integer>();
    for (int i = 0; i < n;) {
    	long cur = counts[i].x;
    	while (prev != cur && heap.size > 0) {
      	id0.Entry mn = heap.id2();
      	heapTotal -= t[(Integer) mn.value];
      	sum += heapTotal;
      	prev++;
    	}
    	while (i < n && cur == counts[i].x) {
    		int index = (int) counts[i].y;
    		heap.enqueue(index, INF - t[index]);
    		heapTotal += t[index];
    		i++;
    	}
    	id0.Entry mn = heap.id2();
    	heapTotal -= t[(Integer) mn.value];
    	
	    sum += heapTotal;
	    prev = cur + 1;
    }
    
    while (heap.size > 0) {
    	id0.Entry mn = heap.id2();
    	heapTotal -= t[(Integer) mn.value];
    	sum += heapTotal;
    }
  	return sum;
  }

  public static void main(String[] args) throws Exception {
    cin = new BufferedReader(new InputStreamReader(System.in));
    cout = new PrintWriter(System.out);
    
    if (false) {
	    int k = nextInt();
	    for (int i = 0; i < k; i++) {
	    	int n = 1 + (int) (random() * 100);
	    	long[] a = new long[n];
	    	long[] t = new long[n];
	    	for (int j = 0; j < n; j++) {
	    		a[j] = 1 + (int) (random() * 50);
	    		t[j] = 1 + (int) (random() * 50);
	    	}
	    	
	    	long correctAns = slow(n, a, t);
	    	long fastAns = solve(n, a, t);
	    	if (correctAns != fastAns) {
	    		cout.println("DIFF:");
	    		cout.println(n);
	    		printArray(a, false);
	    		printArray(t, false);
	    		cout.println("CORRECT: " + correctAns);
	    		cout.println("FAST: " + fastAns);
	    	}
	    }
    } else {
	    int n = nextInt();
	    long[] a = id12(n);
	    long[] t = id12(n);
	    cout.println(solve(n, a, t));
    }
    cout.close();
  }
}
