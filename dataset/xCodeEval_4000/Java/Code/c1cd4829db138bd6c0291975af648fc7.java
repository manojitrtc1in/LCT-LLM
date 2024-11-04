import java.util.*;
import java.io.*;


public class Main {
	public static void main(String[] args) {
		Prepare.toSolveTheProblem();
	}
}

class Task {
	Scanner in;
	PrintWriter out;
	
	void run() {
        int n = in.nextInt();
        int m = in.nextInt();
        map.put(-1, 0);
        for (int i = 0; i < n; i++) {
        	map.put(i, i + 1);
        }

        LongSegLite seg = new LongSegLite(n + 1);
        for (int i = 0; i < m; i++) {
            int t = in.nextInt();
            int l = in.nextInt() - 1;
            int r = in.nextInt();
            if (t == 1) {
                int c = in.nextInt();
                if (!map.containsKey(l)) map.put(l, get(l));
                if (!map.containsKey(r)) map.put(r, get(r));
                int last = -1;
                int index = -1;
                for (Map.Entry<Integer, Integer> e : map.subMap(l, r + 1).entrySet()) {
                	if (index == -1) {
                		index = e.getKey();
                		last = e.getValue();
                	} else {
                		int crtIndex = e.getKey();
                		int crt = e.getValue();
                		seg.add(index, crtIndex, Math.abs(last - c) * 1L);
                		index = crtIndex;
                		last = crt;
                	}
                }
                paint(l, r, c);
            } else {
                long s = seg.sum(l, r);
                out.println(s);
            }
        }
    }
	public TreeMap<Integer, Integer> map = new TreeMap<>();

    public void paint(Integer s, Integer t, Integer c) {
    	Integer p = get(t);
        map.subMap(s, t).clear();
        if (!get(s).equals(c)) map.put(s, c);
        if (!get(t).equals(p)) map.put(t, p);
    }

    public Integer get(Integer k) {
        return map.floorEntry(k).getValue();
    }

    public boolean sameColor(Integer s, Integer t, Integer c) {
        if (!get(s).equals(c)) return false;
        for (Integer v : map.subMap(s, t).values()) {
            if (!v.equals(c)) return false;
        }
        return true;
    }
}

class LongSegLite {
    LongBIT dif, pre;

    public LongSegLite(int n) {
        dif = new LongBIT(n);
        pre = new LongBIT(n);
    }

    public void add(int s, int t, long v) {
        dif.add(s, v);
        dif.add(t, -v);
        pre.add(s, v * s);
        pre.add(t, -v * t);
    }

    public long sum(int s, int t) {
        if (s > 0) return sum(0, t) - sum(0, s);
        return dif.sum(0, t) * t - pre.sum(0, t);
    }
}
class LongBIT {
    long[] vs;

    public LongBIT(int n) {
        vs = new long[n + 1];
    }

    public void add(int k, long a) {
        for (int i = k + 1; i < vs.length; i += i & -i) {
            vs[i] += a;
        }
    }

    public long sum(int s, int t) {
        if (s > 0) return sum(0, t) - sum(0, s);
        long res = 0;
        for (int i = t; i > 0; i -= i & -i) {
            res += vs[i];
        }
        return res;
    }

    

    

    public int get(long k) {
        int p = Integer.highestOneBit(vs.length - 1);
        for (int q = p; q > 0; q >>= 1, p |= q) {
            if (p >= vs.length || k < vs[p]) p ^= q;
            else k -= vs[p];
        }
        return p;
    }
}

class Prepare {
	static void toSolveTheProblem() {
		boolean LOCAL = System.getSecurityManager() == null;
		if (LOCAL) {
			try {
				System.setIn(new FileInputStream("./../in"));
				

			} catch (IOException e) {
				LOCAL = false;
			}
		}
		long start = System.nanoTime();
		Task task = new Task();
		task.in = new Scanner(System.in);
		task.out = new PrintWriter(System.out);
		task.run();
		task.out.close();
		if (LOCAL) System.err.printf("[Time %.6fs]%n", (System.nanoTime() - start) * 1e-9);
	}
}
class Scanner {
	BufferedReader br;
	StringTokenizer st;

	Scanner(InputStream in) {
		br = new BufferedReader(new InputStreamReader(in));
		eat("");
	}

	private void eat(String string) {
		st = new StringTokenizer(string);
	}

	String nextLine() {
		try {
			return br.readLine();
		} catch (IOException e) {
			return null;
		}
	}

	boolean hasNext() {
		while (!st.hasMoreTokens()) {
			String s = nextLine();
			if (s == null)
				return false;
			eat(s);
		}
		return true;
	}

	String next() {
		hasNext();
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(next());
	}

	long nextLong() {
		return Long.parseLong(next());
	}

	double nextDouble() {
		return Double.parseDouble(next());
	}
}

class Algo {

    public static void debug(Object...os) {
        System.err.println(Arrays.deepToString(os));
    }
    public static void debugTable(Object[] os) {
        for (Object o : os) debug(o);
        debug("-------------------------------------");
    }
    public static long sum(int[] is) {
        long res = 0;
        for (int i = 0; i < is.length; i++) {
            res += is[i];
        }
        return res;
    }
    public static long sum(long[] ls) {
        long res = 0;
        for (int i = 0; i < ls.length; i++) {
            res += ls[i];
        }
        return res;
    }

    public static int min(int[] is) {
        int res = Integer.MAX_VALUE;
        for (int i = 0; i < is.length; i++) {
            res = Math.min(res, is[i]);
        }
        return res;
    }
    public static long min(long[] ls) {
        long res = Long.MAX_VALUE;
        for (int i = 0; i < ls.length; i++) {
            res = Math.min(res, ls[i]);
        }
        return res;
    }
    public static <T extends Comparable<T>> T min(T[] ts) {
        T res = null;
        for (T t : ts) {
            if (res == null || res.compareTo(t) > 0) {
                res = t;
            }
        }
        return res;
    }

    public static int minIndex(int[] is) {
        int index = -1;
        for (int i = 0; i < is.length; i++) {
            if (index == -1 || is[index] > is[i]) {
                index = i;
            }
        }
        return index;
    }
    public static int minIndex(long[] ls) {
        int index = -1;
        for (int i = 0; i < ls.length; i++) {
            if (index == -1 || ls[index] > ls[i]) {
                index = i;
            }
        }
        return index;
    }
    public static <T extends Comparable<T>> int minIndex(T[] ts) {
        int index = -1;
        for (int i = 0; i < ts.length; i++) {
            if (index == -1 || ts[index].compareTo(ts[i]) > 0) {
                index = i;
            }
        }
        return index;
    }

    public static int max(int[] is) {
        int res = Integer.MIN_VALUE;
        for (int i = 0; i < is.length; i++) {
            res = Math.max(res, is[i]);
        }
        return res;
    }
    public static long max(long[] ls) {
        long res = Long.MIN_VALUE;
        for (int i = 0; i < ls.length; i++) {
            res = Math.max(res, ls[i]);
        }
        return res;
    }
    public static <T extends Comparable<T>> T max(T[] ts) {
        T res = null;
        for (T t : ts) {
            if (res == null || res.compareTo(t) < 0) {
                res = t;
            }
        }
        return res;
    }

    public static int maxIndex(int[] is) {
        int index = -1;
        for (int i = 0; i < is.length; i++) {
            if (index == -1 || is[index] < is[i]) {
                index = i;
            }
        }
        return index;
    }
    public static int maxIndex(long[] ls) {
        int index = -1;
        for (int i = 0; i < ls.length; i++) {
            if (index == -1 || ls[index] < ls[i]) {
                index = i;
            }
        }
        return index;
    }
    public static <T extends Comparable<T>> int maxIndex(T[] ts) {
        int index = -1;
        for (int i = 0; i < ts.length; i++) {
            if (index == -1 || ts[index].compareTo(ts[i]) < 0) {
                index = i;
            }
        }
        return index;
    }

    public static int log2(int b) {
        return 31 - Integer.numberOfLeadingZeros(b);
    }
    public static int log2(long b) {
        return 63 - Long.numberOfLeadingZeros(b);
    }

    public static void swap(char[] cs, int i, int j) {
        char t = cs[i]; cs[i] = cs[j]; cs[j] = t;
    }
    public static void swap(int[] is, int i, int j) {
        int t = is[i]; is[i] = is[j]; is[j] = t;
    }
    public static void swap(long[] ls, int i, int j) {
        long t = ls[i]; ls[i] = ls[j]; ls[j] = t;
    }
    public static<T> void swap(T[] ts, int i, int j) {
        T t = ts[i]; ts[i] = ts[j]; ts[j] = t;
    }
    private static <T> void swap(List<T> tl, int i, int j) {
        T t = tl.get(i); tl.set(i, tl.get(j)); tl.set(j, t);
    }

    public static void reverse(int[] is) {
        reverse(is, 0, is.length);
    }
    public static void reverse(long[] ls) {
        reverse(ls, 0, ls.length);
    }
    public static void reverse(char[] cs) {
        reverse(cs, 0, cs.length);
    }
    public static <T> void reverse(T[] ts) { 
        reverse(ts, 0, ts.length); 
    }
    public static <T> void reverse(List<T> tl) { 
        reverse(tl, 0, tl.size()); 
    }

    public static void reverse(int[] is, int b, int e) {
        while (b < e) swap(is, b++, --e);
    }
    public static void reverse(long[] ls, int b, int e) {
        while (b < e) swap(ls, b++, --e);
    }
    public static void reverse(char[] cs, int b, int e) {
        while (b < e) swap(cs, b++, --e);
    }
    public static<T> void reverse(T[] ts, int b, int e) {
        while (b < e) swap(ts, b++, --e);
    }
    private static <T> void reverse(List<T> tl, int b, int e) {
        while (b < e) swap(tl, b++, --e);
    }

    public static boolean nextPermutation(int[] is) {
        int n = is.length;
        for (int i = n - 1; i > 0; i--) {
            if (is[i - 1] < is[i]) {
                int j = n;
                while (is[i - 1] >= is[--j]) ;
                swap(is, i - 1, j);
                reverse(is, i, n);
                return true;
            }
        }
        reverse(is, 0, n);
        return false;
    }
    public static boolean nextPermutation(long[] ls) {
        int n = ls.length;
        for (int i = n - 1; i > 0; i--) {
            if (ls[i - 1] < ls[i]) {
                int j = n;
                while (ls[i - 1] >= ls[--j]) ;
                swap(ls, i - 1, j);
                reverse(ls, i, n);
                return true;
            }
        }
        reverse(ls, 0, n);
        return false;
    }
    public static boolean nextPermutation(char[] cs) {
        int n = cs.length;
        for (int i = n - 1; i > 0; i--) {
            if (cs[i - 1] < cs[i]) {
                int j = n;
                while (cs[i - 1] >= cs[--j]) ;
                swap(cs, i - 1, j);
                reverse(cs, i, n);
                return true;
            }
        }
        reverse(cs, 0, n);
        return false;
    }
    public static <T extends Comparable<T>> boolean nextPermutation(T[] ts) {
        int n = ts.length;
        for (int i = n - 1; i > 0; i--) {
            if (ts[i - 1].compareTo(ts[i]) < 0) {
                int j = n;
                while (ts[i - 1].compareTo(ts[--j]) >= 0) ;
                swap(ts, i - 1, j);
                reverse(ts, i, n);
                return true;
            }
        }
        reverse(ts, 0, n);
        return false;
    }
    public static<T extends Comparable<T>> boolean nextPermutation(List<T> tl) {
        int n = tl.size();
        for (int i = n - 1; i > 0; i--) {
            if (tl.get(i - 1).compareTo(tl.get(i)) < 0) {
                int j = n;
                while (tl.get(i - 1).compareTo(tl.get(--j)) >= 0) ;
                swap(tl, i - 1, j);
                reverse(tl, i, n);
                return true;
            }
        }
        reverse(tl, 0, n);
        return false;
    }

    public static int[] unique(int[] is) {
        return unique(is, 0, is.length);
    }
    public static long[] unique(long[] ls) { 
        return unique(ls, 0, ls.length); 
    }
    public static char[] unique(char[] cs) { 
        return unique(cs, 0, cs.length);
    }
    public static <T extends Comparable<T>> T[] unique(T[] ts) {
        return unique(ts, 0, ts.length); 
    }
    
    public static int[] unique(int[] is, int b, int e) {
        if (b == e)
            return new int[0];
        int count = 1;
        for (int i = b + 1; i < e; i++) {
            if (is[i] != is[i - 1])
                count++;
        }
        int[] res = new int[count];
        res[0] = is[b];
        int id = 1;
        for (int i = b + 1; i < e; i++) {
            if (is[i] != is[i - 1])
                res[id++] = is[i];
        }
        return res;
    }
    public static long[] unique(long[] ls, int b, int e) {
        if (b == e)
            return new long[0];
        int cnt = 1;
        for (int i = b + 1; i < e; i++) {
            if (ls[i] != ls[i - 1])
                cnt++;
        }
        long[] res = new long[cnt];
        res[0] = ls[b];
        int id = 1;
        for (int i = b + 1; i < e; i++) {
            if (ls[i] != ls[i - 1])
                res[id++] = ls[i];
        }
        return res;
    }
    public static char[] unique(char[] cs, int b, int e) {
        if (b == e)
            return new char[0];
        int cnt = 1;
        for (int i = b + 1; i < e; i++) {
            if (cs[i] != cs[i - 1])
                cnt++;
        }
        char[] res = new char[cnt];
        res[0] = cs[b];
        int id = 1;
        for (int i = b + 1; i < e; i++) {
            if (cs[i] != cs[i - 1])
                res[id++] = cs[i];
        }
        return res;
    }
    @SuppressWarnings("unchecked")
	public static <T extends Comparable<T>> T[] unique(T[] ts, int b, int e) {
        if (b == e)
            return (T[]) new Object[0];
        int cnt = 1;
        for (int i = b + 1; i < e; i++) {
            if (ts[i].compareTo(ts[i - 1]) != 0)
                cnt++;
        }
        T[] res = (T[]) new Object[cnt];
        res[0] = ts[b];
        int id = 1;
        for (int i = b + 1; i < e; i++) {
            if (ts[i].compareTo(ts[i - 1]) != 0)
                res[id++] = ts[i];
        }
        return res;
    }

    public static int lowerBound(int[] is, int v) {
        return lowerBound(is, 0, is.length, v);
    }
    public static int lowerBound(long[] ls, long v) {
        return lowerBound(ls, 0, ls.length, v);
    }
    public static <T extends Comparable<T>> int lowerBound(T[] is, T v) {
        return lowerBound(is, 0, is.length, v);
    }
    public static <T extends Comparable<T>> int lowerBound(List<T> tl, T v) {
        return lowerBound(tl, 0, tl.size(), v);
    }

    public static int lowerBound(int[] is, int l, int r, int v) {
        while (l < r) {
            int m = (l + r) >> 1;
            if (is[m] >= v) r = m;
            else l = m + 1;
        }
        return l;
    }
    public static int lowerBound(long[] ls, int l, int r, long v) {
        while (l < r) {
            int m = (l + r) >> 1;
            if (ls[m] >= v) r = m;
            else l = m + 1;
        }
        return l;
    }
    public static<T extends Comparable<T>> int lowerBound(T[] ts, int l, int r, T v) {
        while (l < r) {
            int m = (l + r) >> 1;
            if (ts[m].compareTo(v) >= 0) r = m;
            else l = m + 1;
        }
        return l;
    }
    public static<T extends Comparable<T>> int lowerBound(List<T> tl, int l, int r, T v) {
        while (l < r) {
            int m = (l + r) >> 1;
            if (tl.get(m).compareTo(v) >= 0) r = m;
            else l = m + 1;
        }
        return l;
    }

    public static int upperBound(int[] is, int v) {
        return upperBound(is, 0, is.length, v);
    }
    public static int upperBound(long[] ls, long v) {
        return upperBound(ls, 0, ls.length, v);
    }
    public static <T extends Comparable<T>> int upperBound(T[] is, T v) {
        return upperBound(is, 0, is.length, v);
    }
    public static <T extends Comparable<T>> int upperBound(List<T> tl, T v) {
        return upperBound(tl, 0, tl.size(), v);
    }

    public static int upperBound(int[] is, int l, int r, int v) {
        while (l < r) {
            int m = (l + r) >> 1;
            if (is[m] > v) r = m;
            else l = m + 1;
        }
        return l;
    }
    public static int upperBound(long[] ls, int l, int r, long v) {
        while (l < r) {
            int m = (l + r) >> 1;
            if (ls[m] > v) r = m;
            else l = m + 1;
        }
        return l;
    }
    public static<T extends Comparable<T>> int upperBound(T[] ts, int l, int r, T v) {
        while (l < r) {
            int m = (l + r) >> 1;
            if (ts[m].compareTo(v) > 0) r = m;
            else l = m + 1;
        }
        return l;
    }
    public static<T extends Comparable<T>> int upperBound(List<T> tl, int l, int r, T v) {
        while (l < r) {
            int m = (l + r) >> 1;
            if (tl.get(m).compareTo(v) > 0) r = m;
            else l = m + 1;
        }
        return l;
    }

    public static int[] unBox(Integer[] Is) {
        int n = Is.length;
        int[] is = new int[n];
        for (int i = 0; i < n; i++) {
            is[i] = Is[i];
        }
        return is;
    }
    public static long[] unBox(Long[] Ls) {
        int n = Ls.length;
        long[] ls = new long[n];
        for (int i = 0; i < n; i++) {
            ls[i] = Ls[i];
        }
        return ls;
    }

    public static Integer[] box(int[] is) {
        int n = is.length;
        Integer[] Is = new Integer[n];
        for (int i = 0; i < n; i++) {
            Is[i] = is[i];
        }
        return Is;
    }
    public static Long[] box(long[] ls) {
        int n = ls.length;
        Long[] Ls = new Long[n];
        for (int i = 0; i < n; i++) {
            Ls[i] = ls[i];
        }
        return Ls;
    }
}
