import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BR in = new BR();
		char[] l1 = in.nx().toCharArray();
		int left = 0;
		int right = l1.length-1;
		int[] fin = new int[l1.length];
		for (int i = 0;i<l1.length;i++){
			if (l1[i] == 'l'){
				
				fin[right] = i+1;
				right--;
			}
			else {
				fin[left] = i+1;
				left++;
			}
		}
		StringBuilder print = new StringBuilder();
		for (int e: fin){
			print.append(e+"\n");
		}
		p(print);
	}

	private static BigInteger bi(long n1) {
		return BigInteger.valueOf(n1);
	}

	private static void p(Object o1) {
		System.out.print(o1);

	}

	private static void pn(Object o1) {
		System.out.println(o1);
	}

	private static void px(Object... o1) {
		System.err.println(Arrays.deepToString(o1));
	}

	private static void ex() {
		System.exit(0);
	}

	private static int ri(String k1) {
		return Integer.parseInt(k1);
	}

	private static long rl(String k1) {
		return Long.parseLong(k1);
	}

	private static double rd(String k1) {
		return Double.parseDouble(k1);
	}

	private static int[] rdigits(String k1) {
		int[] l1 = new int[k1.length()];

		for (int i = 0; i < k1.length(); i++) {
			l1[i] = k1.charAt(i) - '0';
		}
		return l1;
	}

	private static class Bit {
		public static String bin8(int n1) {
			String k1 = Integer.toBinaryString(n1);
			k1 = String.format("%8s", k1).replace(' ', '0');
			return k1;
		}

		public static String bin32(int n1) {
			String k1 = Integer.toBinaryString(n1);
			k1 = String.format("%32s", k1).replace(' ', '0');
			return k1;
		}
	}

	private static class CBT {
		public static BigInteger fact(int n1) {
			BigInteger fin = BigInteger.ONE;
			for (int i = 2; i <= n1; i++) {
				fin = fin.multiply(new BigInteger(n1 + ""));
			}
			return fin;
		}

		public static BigInteger choose(int n1, int n2) {
			BigInteger fin = fact(n1);
			fin = fin.divide(fact(n2));
			fin = fin.divide(fact(n1 - n2));
			return fin;
		}
	}

	private static class Shuffle {
		private static Random r1 = new Random();

		public static void ints(int[] l1) {
			for (int i = 0; i < l1.length; i++) {
				int k1 = i + r1.nextInt(l1.length - i);
				int temp = l1[i];
				l1[i] = l1[k1];
				l1[k1] = temp;
			}
		}

		public static void ints(int[] l1, int n1, int n2) {
			for (int i = 0; i < n2 - n1 + 1; i++) {
				int k1 = i + r1.nextInt(n2 - n1 + 1 - i);
				int temp = l1[i + n1];
				l1[i + n1] = l1[k1 + n1];
				l1[k1 + n1] = temp;
			}
		}

		public static void longs(long[] l1) {
			for (int i = 0; i < l1.length; i++) {
				int k1 = i + r1.nextInt(l1.length - i);
				long temp = l1[i];
				l1[i] = l1[k1];
				l1[k1] = temp;
			}
		}

		public static void doubles(double[] l1) {
			for (int i = 0; i < l1.length; i++) {
				int k1 = i + r1.nextInt(l1.length - i);
				double temp = l1[i];
				l1[i] = l1[k1];
				l1[k1] = temp;
			}
		}
	}

	private static class Series {
		public static int[] range(int n1) {
			int[] fin = new int[n1];
			for (int i = 0; i < n1; i++) {
				fin[i] = i;
			}
			return fin;
		}

		public static ArrayList<BigInteger> fib(long n1) {
			ArrayList<BigInteger> l1 = new ArrayList();
			l1.add(BigInteger.ZERO);
			l1.add(BigInteger.ONE);
			for (;;) {
				if (l1.size() >= n1)
					break;
				l1.add(l1.get(l1.size() - 1).add(l1.get(l1.size() - 2)));
			}
			return l1;
		}
	}

	private static class LR {
		BufferedReader k1 = null;

		public LR() throws Exception {
			k1 = new BufferedReader(new InputStreamReader(System.in));
		}

		public String nx() throws Exception {
			return k1.readLine();
		}
	}

	private static class ST {
		StreamTokenizer k1 = null;

		public ST() throws Exception {
			k1 = new StreamTokenizer(System.in);
		}

		public int ni() throws Exception {
			k1.nextToken();
			return (int) k1.nval;
		}

		public double nd() throws Exception {
			k1.nextToken();
			return (double) k1.nval;
		}

		public long nl() throws Exception {
			k1.nextToken();
			return (long) k1.nval;
		}
	}

	private static class BR {
		BufferedReader k1 = null;
		StringTokenizer k2 = null;

		public BR() {
			k1 = new BufferedReader(new InputStreamReader(System.in));
		}

		public String nx() throws Exception {
			for (;;) {
				if (k2 == null) {
					String temp = k1.readLine();
					if (temp == null)
						return null;
					k2 = new StringTokenizer(temp);
				} else if (!k2.hasMoreTokens()) {
					String temp = k1.readLine();
					if (temp == null)
						return null;
					k2 = new StringTokenizer(temp);
				} else
					break;
			}

			return k2.nextToken();
		}
		
		public int ni() throws Exception {
			return Integer.parseInt(nx());
		}
		public long nl() throws Exception {
			return Long.parseLong(nx());
		}
		public double nd() throws Exception {
			return Double.parseDouble(nx());
		}
		public BigInteger nbi() throws Exception {
			return new BigInteger(nx());
		}

	}

	private class Sorted<E extends Comparable<? super E>> {
		ArrayList<E> set = new ArrayList();
		ArrayList<Integer> count = new ArrayList();

		public Sorted(ArrayList<E> o1) {
			Collections.sort(o1);
			for (int i = 0; i < o1.size(); i++) {
				if (i == 0) {
					set.add(o1.get(i));
					count.add(1);
					continue;
				}
				E cur = o1.get(i);
				if (cur.equals(o1.get(i - 1))) {
					count.set(count.size() - 1, count.get(count.size() - 1) + 1);
				} else {
					set.add(cur);
					count.add(1);
				}
			}
		}
	}

	private static class Fenwick {
		long[] l1 = null;

		public Fenwick(int n1) {
			l1 = new long[n1];
		}

		static int[] temp = new int[100];
		static int len = -1;

		public long get(int n1) {
			int k1 = n1 + 1;
			int ptr = 0;
			for (int i = 0;; i++) {
				if (k1 == 0)
					break;
				if (k1 % 2 == 1) {
					temp[ptr++] = i;
				}
				k1 = k1 >> 1;
			}
			len = ptr;
			int ptr1 = -1;
			long fin = 0;
			for (int i = len - 1; i >= 0; i--) {
				int cur = temp[i];
				ptr1 += 1 << cur;
				fin += l1[ptr1];
			}
			return fin;
		}

		public void add(int id) {
			add(id, 1);
		}

		public void add(int id, long val) {
			int k1 = id;
			int v = 1;
			for (;;) {
				int idx = k1 * v + v - 1;
				if (idx >= l1.length) {
					break;
				}
				if (k1 % 2 == 0)
					l1[idx] += val;
				v = v << 1;
				k1 = k1 >> 1;
			}
		}

		public String toString() {
			long[] fin = new long[l1.length];
			for (int i = 0; i < l1.length; i++)
				fin[i] = get(i);
			return Arrays.toString(fin);
		}
	}

	private static class MOD {
		public long mod = -1;

		public MOD(long k1) {
			mod = k1;
		}

		public long a(long n1, long n2) {
			long k1 = (n1 + n2) % mod;
			if (k1 < 0)
				k1 += mod;
			return k1;
		}

		public long s(long n1, long n2) {
			long k1 = (n1 - n2) % mod;
			if (k1 < 0)
				k1 += mod;
			return k1;
		}

		public long t(long n1, long n2) {
			long k1 = (n1 * n2) % mod;
			if (k1 < 0)
				k1 += mod;
			return k1;
		}

		public long d(long n1, long n2) {
			return (t(n1, id1(mod, n2))) % mod;
		}

		public static long id1(long n1, long n2) {
			long k1 = n1;
			long k2 = n2;
			long[] l1 = { 1, 0 };
			long[] l2 = { 0, 1 };
			for (;;) {
				long f1 = k1 / k2;
				long f2 = k1 % k2;
				if (f2 == 0)
					break;

				long[] l3 = { 0, 0 };
				l3[0] = l1[0] - f1 * l2[0];
				l3[1] = l1[1] - f1 * l2[1];
				l1 = l2;
				l2 = l3;

				k1 = k2;
				k2 = f2;
			}
			long fin = l2[1] % n1;
			if (fin < 0) {
				fin += n1;
			}
			return fin;
		}

		public long pow(long n1, long pow) {
			if (pow == 0)
				return 1;
			else if (pow == 1)
				return t(1l, n1);
			else if (pow % 2 == 0) {
				long half = pow(n1, pow / 2);
				return t(half, half);
			} else {
				long half = pow(n1, pow / 2);
				return t(half, t(half, n1));
			}
		}
	}

	private static class DJS<E> {
		public HashMap<E, Integer> mapping = new HashMap();
		public ArrayList<E> value = new ArrayList();
		public ArrayList<Integer> p = new ArrayList();
		public ArrayList<Integer> size = new ArrayList();
		public int n = 0;

		public void add(E k1) {
			if (!mapping.containsKey(k1)) {
				mapping.put(k1, n);
				value.add(k1);
				p.add(n);
				size.add(1);
				n++;
			}
		}

		public int find(int x) {
			if (p.get(x) == x)
				return x;
			else
				return find(p.get(x));
		}

		public void union(E k1, E k2) {
			if (!mapping.containsKey(k1))
				add(k1);
			if (!mapping.containsKey(k2))
				add(k2);
			int s1 = mapping.get(k1);
			int s2 = mapping.get(k2);
			int r1 = find(s1);
			int r2 = find(s2);
			if (r1 == r2)
				return;
			if (size.get(r1) >= size.get(r2)) {
				size.set(r1, size.get(r1) + size.get(r2));
				p.set(r2, r1);
			} else {
				size.set(r2, size.get(r1) + size.get(r2));
				p.set(r1, r2);
			}
		}

		public void print() {
			System.out.println("value\n" + value);
			System.out.println("p\n" + p);
			System.out.println("size\n" + size);
		}

		public HashMap<Integer, ArrayList<E>> partition() {
			HashMap<Integer, ArrayList<E>> temp1 = new HashMap();
			for (int i = 0; i < p.size(); i++) {
				int classNo = find(i);
				if (!temp1.containsKey(classNo))
					temp1.put(classNo, new ArrayList());
				ArrayList curList = temp1.get(classNo);
				curList.add(value.get(i));
			}
			return temp1;
		}
	}

	private static class CS<E> {
		public long total = 0;
		public HashMap<E, Integer> m1 = new HashMap();

		public void add(E k1) {
			add(k1, 1);
		}

		public void remove(E k1) {
			add(k1, -1);
		}

		public void add(E k1, int n1) {
			int nv = 0;
			if (m1.containsKey(k1)) {
				nv = m1.get(k1);
			}
			m1.put(k1, nv + n1);
			total += n1;
			if (nv + n1 == 0) {
				m1.remove(k1);
			}
		}

		public void set(E k1, int n1) {
			int nv = 0;
			if (m1.containsKey(k1)) {
				nv = m1.get(k1);
			}
			m1.put(k1, n1);
			total += n1 - nv;
			if (n1 == 0) {
				m1.remove(k1);
			}
		}

		public int get(E k1) {
			if (!m1.containsKey(k1)) {
				return 0;
			} else {
				return m1.get(k1);
			}
		}

		public String toString() {
			return m1.toString();
		}
	}

	
	private static class F implements Comparable<F> {
		public long top = 1;
		public long bot = 1;

		public F() {

		}

		public F(long t1) {
			top = t1;
		}
		
		public F(long t1, long b1) {
			top = t1;
			bot = b1;
		}

		public void cl() {
			long gcd = gcd(top,bot);
			top /= gcd;
			bot /= gcd;
		}

		public F add(F f1) {
			F fin = new F();
			fin.bot = bot * f1.bot;
			fin.top = top * f1.bot + f1.top * bot;
			fin.cl();
			return fin;
		}

		public F minus(F f1) {
			return add(f1.neg());
		}

		public F times(F f1) {
			F fin = new F();
			fin.bot = bot * f1.bot;
			fin.top = top * f1.top;
			fin.cl();
			return fin;
		}

		public F div(F f1) {
			if (f1.compareTo(F.ZERO) == 0) {
				throw new ArithmeticException();
			}
			return times(f1.inv());
		}

		public F neg() {
			F fin = new F();
			fin.top = top * -1;
			fin.bot = bot;
			return fin;
		}

		public F inv() {
			F fin = new F();
			fin.top = bot;
			fin.bot = top;
			return fin;
		}

		public String toString() {
			return "(" + top + "/ " + bot + ")";
		}

		@Override
		public int compareTo(F f1) {
			long self = top* f1.bot;
			long it = f1.top * bot;
			long diff = self - it;
			if (diff > 0) return 1;
			if (diff < 0) return -1;
			return 0;
		}

		public static final F ZERO = new F(0);
		public static final F ONE = new F(1);

		public F clone() {
			F fin = new F();
			fin.top = top;
			fin.bot = bot;
			return fin;
		}
	
		public static long gcd(long n1, long n2) {
			long k1 = n1 > n2 ? n1 : n2;
			long k2 = k1 == n1 ? n2 : n1;
			long rm = k1 % k2;
			while (rm != 0) {
				k1 = k2;
				k2 = rm;
				rm = k1 % k2;
			}
			return k2;
		}
	
	}
	
	
	private static class F2 implements Comparable<F2> {
		public BigInteger top = BigInteger.ONE;
		public BigInteger bot = BigInteger.ONE;

		public F2() {

		}

		public F2(long t1, long b1) {
			top = new BigInteger(t1 + "");
			bot = new BigInteger(b1 + "");
		}

		public void cl() {
			BigInteger gcd = top.gcd(bot);
			top = top.divide(gcd);
			bot = bot.divide(gcd);
		}

		public F2 add(F2 f1) {
			F2 fin = new F2();
			fin.bot = bot.multiply(f1.bot);
			fin.top = top.multiply(f1.bot).add(f1.top.multiply(bot));
			fin.cl();
			return fin;
		}

		public F2 minus(F2 f1) {
			return add(f1.neg());
		}

		public F2 times(F2 f1) {
			F2 fin = new F2();
			fin.bot = bot.multiply(f1.bot);
			fin.top = top.multiply(f1.top);

			fin.cl();
			return fin;
		}

		public F2 div(F2 f1) {
			if (f1.compareTo(F2.zero()) == 0) {
				throw new ArithmeticException();
			}
			return times(f1.inv());
		}

		public F2 neg() {
			F2 fin = new F2();
			fin.top = top.multiply(new BigInteger(-1 + ""));
			fin.bot = bot;
			return fin;
		}

		public F2 inv() {
			F2 fin = new F2();
			fin.top = bot;
			fin.bot = top;
			return fin;
		}

		public String toString() {
			return "(" + top + "/ " + bot + ")";
		}

		@Override
		public int compareTo(F2 f1) {
			BigInteger self = top.multiply(f1.bot);
			BigInteger it = f1.top.multiply(bot);
			return self.compareTo(it);
		}

		public static F2 zero() {
			F2 fin = new F2();
			fin.top = new BigInteger(0 + "");
			return fin;
		}

		public F2 clone() {
			F2 fin = new F2();
			fin.top = top;
			fin.bot = bot;
			return fin;
		}
	}

	private static class Palin {
		public static int[] palin(String s1) {
			char[] l1 = s1.toCharArray();
			int[] l2 = new int[l1.length * 2 - 1];
			int ptr = 0;
			int k1 = 1;
			for (;;) {
				for (;;) {
					int right = ptr / 2 + k1 / 2 + 1;
					int left = ptr / 2 - k1 / 2 - 1;
					if (ptr % 2 == 1)
						left++;
					if (right > l1.length - 1)
						break;
					if (left < 0)
						break;
					if (l1[left] == l1[right])
						k1 += 2;
					else
						break;
				}
				if (ptr > l2.length - 1)
					break;
				l2[ptr] = k1;
				boolean found = false;
				for (int i = 0; i < k1 - 1; i++) {
					int temp = l2[ptr - i - 1];
					if (temp + i + 1 == k1) {
						ptr = ptr + i + 1;
						k1 = temp;
						found = true;
						break;
					} else {
						l2[ptr + i + 1] = l2[ptr - i - 1];
					}
				}
				if (!found) {
					ptr += 1;
					k1 = 0;
					if (ptr % 2 == 0)
						k1 = 1;
				}
			}
			return l2;
		}

		public static int[] id2(int id, int leng) {
			int left = (id) / 2 - leng / 2;
			if (id % 2 == 1)
				left += 1;
			int right = (id) / 2 + leng / 2;
			return new int[] { left, right };
		}
	}

	private static class Str {
		public static String reverse(String k1) {
			StringBuilder f1 = new StringBuilder();
			for (int i = k1.length() - 1; i >= 0; i--) {
				f1.append((char) k1.charAt(i));
			}
			return f1.toString();
		}

		public static ArrayList<String> id0(String str1) {
			ArrayList<String> fin = new ArrayList();
			for (int i = 1; i <= str1.length(); i++) {
				for (int j = 0; j <= str1.length() - i; j++) {
					String temp = str1.substring(j, j + i);
					fin.add(temp);
				}
			}

			return fin;
		}

		public static ArrayList<String> id3(String str1) {
			ArrayList<String> fin = new ArrayList();
			for (int i = 0; i < str1.length(); i++) {
				for (int j = i + 1; j <= str1.length(); j++) {
					String temp = str1.substring(i, j);
					fin.add(temp);
				}
			}
			return fin;
		}
	}

	private static class IntL implements Iterable<Integer> {
		public int[] l1 = null;
		public int size = 0;;

		public IntL(int initialCapacity) {
			this.l1 = new int[initialCapacity];
		}

		public IntL() {
			this(5);
		}

		public void add(int e) {
			if (size == l1.length) {
				l1 = Arrays.copyOf(l1, l1.length * 3 / 2 + 1);
			}
			l1[size++] = e;
		}

		public String toString() {
			StringBuilder fin = new StringBuilder();
			fin.append((char) '{');
			for (int i = 0; i < size; i++) {
				if (i != 0)
					fin.append(", ");
				fin.append(l1[i]);
			}
			fin.append((char) '}');
			return fin.toString();
		}

		public Iterator<Integer> iterator() {
			return new It();
		}

		public class It implements Iterator<Integer> {
			int ptr = 0;

			public boolean hasNext() {
				if (ptr < size)
					return true;
				return false;
			}

			public Integer next() {
				int fin = l1[ptr];
				ptr++;
				return fin;
			}

			public void remove() {

			}
		}
	}

	private static class LongL implements Iterable<Long> {
		public long[] l1 = null;
		public int size = 0;

		public LongL(int initialCapacity) {
			this.l1 = new long[initialCapacity];
		}

		public LongL() {
			this(5);
		}

		public void add(long e) {
			if (size == l1.length) {
				l1 = Arrays.copyOf(l1, l1.length * 3 / 2 + 1);
			}
			l1[size++] = e;
		}

		public String toString() {
			StringBuilder fin = new StringBuilder();
			fin.append((char) '{');
			for (int i = 0; i < size; i++) {
				if (i != 0)
					fin.append(", ");
				fin.append(l1[i]);
			}
			fin.append((char) '}');
			return fin.toString();
		}

		public Iterator<Long> iterator() {
			return new It();
		}

		public class It implements Iterator<Long> {
			int ptr = 0;

			public boolean hasNext() {
				if (ptr < size)
					return true;
				return false;
			}

			public Long next() {
				long fin = l1[ptr];
				ptr++;
				return fin;
			}

			public void remove() {

			}
		}
	}

	private static class Tree<E extends Comparable<E>> {

		public ArrayList<E> cont = new ArrayList();
		public ArrayList<Integer> left = new ArrayList();
		public ArrayList<Integer> right = new ArrayList();
		public ArrayList<Integer> no = new ArrayList();
		public ArrayList<Integer> child = new ArrayList();
		public int size = 0;

		public void update(int id, int n1) {
			int old = no.get(id);
			int niu = old + n1;
			if (niu < 0)
				niu = 0;
			int diff = niu - old;
			no.set(id, niu);
			size += diff;
			for (int e : finds) {
				child.set(e, child.get(e) + diff);
			}

		}

		public int newNode(E k1, int n1) {
			cont.add(k1);
			left.add(-1);
			right.add(-1);
			no.add(n1);
			child.add(n1);
			size += n1;
			for (int e : finds) {
				child.set(e, child.get(e) + n1);
			}
			return cont.size() - 1;

		}

		public ArrayList<Integer> finds = null;

		public int find(E a1) {
			finds = new ArrayList();
			if (cont.size() == 0)
				return -1;
			return recfind(a1, 0);
		}

		public int recfind(E a1, int i1) {
			finds.add(i1);
			E comp = cont.get(i1);
			int val = a1.compareTo(comp);
			if (val == 0)
				return i1;
			else if (val < 0) {
				int k1 = left.get(i1);
				if (k1 == -1)
					return -1;
				else
					return recfind(a1, k1);
			} else {
				int k1 = right.get(i1);
				if (k1 == -1)
					return -1;
				else
					return recfind(a1, k1);
			}
		}

		public int findx(int n1) {
			if (n1 > size)
				return -1;
			return id4(n1, 0, 0);
		}

		public int id4(int n1, int i1, int surplus) {
			int comp = child.get(i1);
			if (right.get(i1) != -1)
				comp -= child.get(right.get(i1));
			int upper = surplus + comp;
			int lower = upper - no.get(i1) + 1;
			if (n1 <= upper && n1 >= lower)
				return i1;
			if (n1 <= upper)
				return id4(n1, left.get(i1), surplus);
			else
				return id4(n1, right.get(i1), upper);
		}

		public void add(E a1) {
			add(a1, 1);
		}

		public void remove(E a1) {
			add(a1, -1);
		}

		public void add(E a1, int n1) {
			find(a1);
			if (finds.size() == 0)
				newNode(a1, n1);
			else {
				int id = finds.get(finds.size() - 1);
				E last = cont.get(id);
				int k1 = a1.compareTo(last);
				if (k1 == 0)
					update(id, n1);
				else if (k1 < 0) {
					if (n1 > 0)
						left.set(id, newNode(a1, n1));
				} else {
					if (n1 > 0)
						right.set(id, newNode(a1, n1));
				}
			}
		}

		public int get(E a1) {
			int k1 = find(a1);
			if (k1 == -1)
				return 0;
			else
				return no.get(k1);
		}

		public String toString() {
			StringBuilder fin = new StringBuilder();
			fin.append((char) '{');
			for (int i = 0; i < size; i++) {
				if (i != 0)
					fin.append(", ");
				fin.append(cont.get(findx(i + 1)));
			}
			fin.append((char) '}');
			return fin.toString();
		}
	}

	private static class NT {
		public static ArrayList<Integer> factor(int n1) {
			ArrayList<Integer> l1 = new ArrayList();
			for (int i = 1; i <= Math.sqrt(n1); i++) {
				if (n1 % i == 0) {
					l1.add(i);
					if (i != n1 / i)
						l1.add(n1 / i);
				}
			}
			return l1;
		}

		public static int[] factor2(int n1) {
			ArrayList<Integer> l1 = new ArrayList();
			ArrayList<Integer> l2 = new ArrayList();
			for (int i = 1; i <= Math.sqrt(n1); i++) {
				if (n1 % i == 0) {
					l1.add(i);
					if (i != n1 / i)
						l2.add(n1 / i);
				}

			}
			int[] fin = new int[l1.size() + l2.size()];
			for (int i = 0; i < l1.size(); i++) {
				fin[i] = l1.get(i);
			}
			for (int i = l1.size(); i < l1.size() + l2.size(); i++) {
				fin[i] = l2.get(l2.size() - 1 - (i - l1.size()));
			}
			return fin;
		}

		public static HashMap<Integer, int[]> facts = new HashMap();

		public static int[] facts(int n1) {
			if (facts.containsKey(n1))
				return facts.get(n1);
			int[] fin = factor2(n1);
			facts.put(n1, fin);
			return fin;
		}

		public static ArrayList<ArrayList<Integer>> mults(int k1) {
			ArrayList<ArrayList<Integer>> fin = new ArrayList();
			mults(k1, new ArrayList(), 1, fin);
			return fin;
		}

		public static void mults(int k1, ArrayList<Integer> stk, int max,
				ArrayList<ArrayList<Integer>> result) {
			if (k1 == 1) {
				result.add((ArrayList<Integer>) stk.clone());
				return;
			}
			int[] f1 = facts(k1);
			for (int i = 1; i < f1.length; i++) {
				if (f1[i] < max) {
					continue;
				}
				stk.add(f1[i]);
				int max1 = max;
				if (f1[i] > max1)
					max1 = f1[i];
				mults(k1 / f1[i], stk, max1, result);
				stk.remove(stk.size() - 1);
			}
		}

		public static int gcd(int n1, int n2) {
			int k1 = n1 > n2 ? n1 : n2;
			int k2 = k1 == n1 ? n2 : n1;
			int rm = k1 % k2;
			while (rm != 0) {
				k1 = k2;
				k2 = rm;
				rm = k1 % k2;
			}
			return k2;
		}

		public static long id1(long n1, long n2) {
			long k1 = n1;
			long k2 = n2;
			long[] l1 = { 1, 0 };
			long[] l2 = { 0, 1 };
			for (;;) {
				long f1 = k1 / k2;
				long f2 = k1 % k2;
				if (f2 == 0)
					break;

				long[] l3 = { 0, 0 };
				l3[0] = l1[0] - f1 * l2[0];
				l3[1] = l1[1] - f1 * l2[1];
				l1 = l2;
				l2 = l3;

				k1 = k2;
				k2 = f2;
			}
			long fin = l2[1] % n1;
			if (fin < 0) {
				fin += n1;
			}
			return fin;
		}

		public static ArrayList<Integer> sieve(int n1) {
			ArrayList<Integer> fin = new ArrayList();
			boolean[] l1 = new boolean[n1 + 1];
			for (int m = 2; m <= Math.sqrt(n1); m++) {
				if (!l1[m]) {
					fin.add(m);
					for (int k = m * m; k <= n1; k += m) {
						l1[k] = true;
					}
				}
			}
			for (int m = (int) Math.sqrt(n1) + 1; m <= n1; m++) {
				if (!l1[m])
					fin.add(m);
			}
			return fin;
		}

		public static BigInteger lcm(BigInteger n1, BigInteger n2) {
			BigInteger mul = n1.multiply(n2);
			return mul.divide(n1.gcd(n2));
		}

		public static int phi(int n1){
			int fin = n1;
			for (int i = 2; i*i <=n1; i++){
				if (n1 % i ==0){
					while (n1 % i == 0) n1/= i;
					fin -= fin /i;
				}
			}
			if (n1>1) fin -= fin/n1;
			return fin;
		}
	
	
	}
}
