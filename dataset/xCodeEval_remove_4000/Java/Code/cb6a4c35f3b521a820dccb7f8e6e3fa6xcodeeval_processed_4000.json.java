

import java.io.*;
import java.math.*;
import java.util.*;


public class Abra {
	void solve() throws IOException {
		int n = nextInt();
		br.readLine();
		for (int i = 0; i < n; i++) {
			String s = br.readLine();
			Stack<String> st = new Stack<String>();
			st.add("" + s.charAt(0));
			for (int j = 1; j < s.length(); j++) {
				if (lib.id4(s.charAt(j))) {
					if (lib.id4(st.peek().charAt(st.peek().length() - 1))) {
						st.push(st.pop() + s.charAt(j));
					} else {
						st.push("" + s.charAt(j));
					}
				} else {
					if (lib.id4(st.peek().charAt(st.peek().length() - 1))) {
						st.push("" + s.charAt(j));
					} else {
						st.push(st.pop() + s.charAt(j));
					}
				}
			}
			if (st.size() == 2) {
				int t = 0, d = 1;
				for (int j = st.get(0).length() - 1; j >= 0; j--) {
					t += (st.get(0).charAt(j) - 'A' + 1) * d;
					d *= 26;
				}
				out.println("R" + st.get(1) + "C" + t);
			} else {
				String t = "";
				int x = Integer.parseInt(st.get(3));
				while (x > 0) {
					t = (char)((x - 1) % 26 + 'A') + t;
					x = (x - 1) / 26;
				}
				out.println(t + st.get(1));
			}
		}
	}
	
	public static void main(String[] args) throws IOException {
		new Abra().run();
	}

	StreamTokenizer in;
	PrintWriter out;
	boolean oj;
	BufferedReader br;

	void init() throws IOException {
		oj = System.getProperty("ONLINE_JUDGE") != null;
		Reader reader = oj ? new InputStreamReader(System.in) : new FileReader("input.txt");
		Writer writer = oj ? new OutputStreamWriter(System.out) : new FileWriter("output.txt");
		br = new BufferedReader(reader);
		in = new StreamTokenizer(br);
		out = new PrintWriter(writer);
	}

	long selectionTime = 0;

	void startSelection() {
		selectionTime -= System.currentTimeMillis();
	}

	void stopSelection() {
		selectionTime += System.currentTimeMillis();
	}

	void run() throws IOException {
		long beginTime = System.currentTimeMillis();
		long beginMem = Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory();
		init();
		solve();
		long endMem = Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory();
		long endTime = System.currentTimeMillis();
		if (!oj) {
			System.out.println("Memory used = " + (endMem - beginMem));
			System.out.println("Total memory = " + (Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory()));
			System.out.println("Running time = " + (endTime - beginTime));
		}
		out.flush();
	}

	int nextInt() throws IOException {
		in.nextToken();
		return (int) in.nval;
	}

	int id8() throws IOException {
		int r = 0, d = 1;
		char c = (char) br.read();
		while (!lib.id14(c) && c != '-')
			c = (char) br.read();
		while (true) {
			if (c == '-') {
				d = -1;
			} else {
				r += (c - '0') * d;
				d *= 10;
			}
			c = (char) br.read();
			if (!lib.id14(c) && c != '-') break;
		}
		return r;
	}

	long nextLong() throws IOException {
		in.nextToken();
		return (long) in.nval;
	}

	String nextString() throws IOException {
		in.nextToken();
		return in.sval;
	}

	double nextDouble() throws IOException {
		in.nextToken();
		return in.nval;
	}

	myLib lib = new myLib();
	
	static class myLib {
		long fact(long x) {
			long a = 1;
			for (long i = 2; i <= x; i++) {
				a *= i;
			}
			return a;
		}

		long digitSum(String x) {
			long a = 0;
			for (int i = 0; i < x.length(); i++) {
				a += x.charAt(i) - '0';
			}
			return a;
		}

		long digitSum(long x) {
			long a = 0;
			while (x > 0) {
				a += x % 10;
				x /= 10;
			}
			return a;
		}

		long digitMul(long x) {
			long a = 1;
			while (x > 0) {
				a *= x % 10;
				x /= 10;
			}
			return a;
		}

		int id7(int x) {
			int a = 0;
			while (x > 0) {
				a += (x % 10) * (x % 10) * (x % 10);
				x /= 10;
			}
			return a;
		}

		double pif(double ax, double ay, double bx, double by) {
			return Math.sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
		}

		double id5(double ax, double ay, double az, double bx, double by, double bz) {
			return Math.sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by) + (az - bz) * (az - bz));
		}

		double id5(double[] a, double[] b) {
			return Math.sqrt((a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]) + (a[2] - b[2]) * (a[2] - b[2]));
		}

		long gcd(long a, long b) {
			if (a == 0 || b == 0) return 1;
			if (a < b) {
				long c = b;
				b = a;
				a = c;
			}
			while (a % b != 0) {
				a = a % b;
				if (a < b) {
					long c = b;
					b = a;
					a = c;
				}
			}
			return b;
		}

		int gcd(int a, int b) {
			if (a == 0 || b == 0) return 1;
			if (a < b) {
				int c = b;
				b = a;
				a = c;
			}
			while (a % b != 0) {
				a = a % b;
				if (a < b) {
					int c = b;
					b = a;
					a = c;
				}
			}
			return b;
		}

		long lcm(long a, long b) {
			return a * b / gcd(a, b);
		}

		int lcm(int a, int b) {
			return a * b / gcd(a, b);
		}

		int id2(String x, String y) {
			int a = 0, i = 0;
			while (true) {
				i = y.indexOf(x);
				if (i == -1) break;
				a++;
				y = y.substring(i + 1);
			}
			return a;
		}

		int[] id9(int x) {
			boolean[] id11 = new boolean[x - 1];
			List<Integer> t = new Vector<Integer>();
			int l = 0, j = 0;
			for (int i = 2; i < x; i++) {
				if (id11[i - 2]) continue;
				t.add(i);
				l++;
				j = i * 2;
				while (j < x) {
					id11[j - 2] = true;
					j += i;
				}
			}
			int[] primes = new int[l];
			Iterator<Integer> iterator = t.iterator();
			for (int i = 0; iterator.hasNext(); i++) {
				primes[i] = iterator.next().intValue();
			}
			return primes;
		}

		int rev(int x) {
			int a = 0;
			while (x > 0) {
				a = a * 10 + x % 10;
				x /= 10;
			}
			return a;
		}

		class myDate {
			int d, m, y;

			int[] ml = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

			public myDate(int da, int ma, int ya) {
				d = da;
				m = ma;
				y = ya;
				if ((ma > 12 || ma < 1 || da > ml[ma - 1] || da < 1) && !(d == 29 && m == 2 && y % 4 == 0)) {
					d = 1;
					m = 1;
					y = 9999999;
				}
			}

			void incYear(int x) {
				for (int i = 0; i < x; i++) {
					y++;
					if (m == 2 && d == 29) {
						m = 3;
						d = 1;
						return;
					}
					if (m == 3 && d == 1) {
						if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0)) {
							m = 2;
							d = 29;
						}
						return;
					}
				}
			}

			boolean less(myDate x) {
				if (y < x.y) return true;
				if (y > x.y) return false;
				if (m < x.m) return true;
				if (m > x.m) return false;
				if (d < x.d) return true;
				if (d > x.d) return false;
				return true;
			}

			void inc() {
				if ((d == 31) && (m == 12)) {
					y++;
					d = 1;
					m = 1;
				} else {
					if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0)) {
						ml[1] = 29;
					}
					if (d == ml[m - 1]) {
						m++;
						d = 1;
					} else
						d++;
				}
			}
		}

		int partition(int n, int l, int m) {

											

			

			if (n < l) return 0;
			if (n < l + 2) return 1;
			if (l == 1) return 1;
			int c = 0;
			for (int i = Math.min(n - l + 1, m); i >= (n + l - 1) / l; i--) {
				c += partition(n - i, l - 1, i);
			}
			return c;
		}

		int id10(String a, String b) {
			if (a.length() > b.length()) {
				String c = a;
				a = b;
				b = c;
			}
			int c = 0, d = b.length() - a.length();
			for (int i = a.length() - 1; i >= 0; i--) {
				if (a.charAt(i) == b.charAt(i + d)) c++;
				else
					break;
			}
			return c;
		}

		String numSym = "0123456789ABCDEF";

		String id19(int x, int y, String z) {
			if (z.equals("0")) return "0";
			String a = "";
			

			BigInteger q = BigInteger.ZERO, t = BigInteger.ONE;
			for (int i = z.length() - 1; i >= 0; i--) {
				q = q.add(t.multiply(BigInteger.valueOf(z.charAt(i) - 48)));
				t = t.multiply(BigInteger.valueOf(x));
			}
			while (q.compareTo(BigInteger.ZERO) == 1) {
				a = numSym.charAt((int) (q.mod(BigInteger.valueOf(y)).intValue())) + a;
				q = q.divide(BigInteger.valueOf(y));
			}
			return a;
		}

		double id3(int x, int y) {
			if ((x == 0) && (y > 0)) return Math.PI / 2;
			if ((x == 0) && (y < 0)) return -Math.PI / 2;
			if ((y == 0) && (x > 0)) return 0;
			if ((y == 0) && (x < 0)) return Math.PI;
			if (x > 0) return Math.atan((double) y / x);
			else {
				if (y > 0) return Math.atan((double) y / x) + Math.PI;
				else
					return Math.atan((double) y / x) - Math.PI;
			}
		}

		static boolean isNumber(String x) {
			try {
				Integer.parseInt(x);
			} catch (NumberFormatException ex) {
				return false;
			}
			return true;
		}

		static boolean id15(String x, String c) {
			for (int i = 0; i < x.length(); i++) {
				if (c.indexOf(x.charAt(i)) == -1) return false;
			}
			return true;
		}

		long pow(long a, long n) { 

			if (n == 0) return 1;
			long k = n, b = 1, c = a;
			while (k != 0) {
				if (k % 2 == 0) {
					k /= 2;
					c *= c;
				} else {
					k--;
					b *= c;
				}
			}
			return b;
		}

		int pow(int a, int n) { 

			if (n == 0) return 1;
			int k = n, b = 1, c = a;
			while (k != 0) {
				if (k % 2 == 0) {
					k /= 2;
					c *= c;
				} else {
					k--;
					b *= c;
				}
			}
			return b;
		}

		double pow(double a, int n) { 

			if (n == 0) return 1;
			double k = n, b = 1, c = a;
			while (k != 0) {
				if (k % 2 == 0) {
					k /= 2;
					c *= c;
				} else {
					k--;
					b *= c;
				}
			}
			return b;
		}

		double log2(double x) {
			return Math.log(x) / Math.log(2);
		}

		int lpd(int[] primes, int x) {

			int i;
			for (i = 0; primes[i] <= x / 2; i++) {
				if (x % primes[i] == 0) {
					return primes[i];
				}
			}
			;
			return x;
		}

		int np(int[] primes, int x) {

			for (int i = 0; true; i++) {
				if (primes[i] == x) return i;
			}
		}

		int[] dijkstra(int[][] map, int n, int s) {
			int[] p = new int[n];
			boolean[] b = new boolean[n];
			Arrays.fill(p, Integer.MAX_VALUE);
			p[s] = 0;
			b[s] = true;
			for (int i = 0; i < n; i++) {
				if (i != s) p[i] = map[s][i];
			}
			while (true) {
				int m = Integer.MAX_VALUE, mi = -1;
				for (int i = 0; i < n; i++) {
					if (!b[i] && (p[i] < m)) {
						mi = i;
						m = p[i];
					}
				}
				if (mi == -1) break;
				b[mi] = true;
				for (int i = 0; i < n; i++)
					if (p[mi] + map[mi][i] < p[i]) p[i] = p[mi] + map[mi][i];
			}
			return p;
		}

		boolean id20(char x) {
			if (((x >= 'a') && (x <= 'z')) || ((x >= 'A') && (x <= 'Z'))) return true;
			else
				return false;
		}

		boolean id4(char x) {
			if (x >= 'A' && x <= 'Z') return true;
			else
				return false;
		}

		boolean id1(char x) {
			if (x >= 'a' && x <= 'z') return true;
			else
				return false;
		}

		boolean id14(char x) {
			if (x >= '0' && x <= '9') return true;
			else
				return false;
		}

		class id18 extends Exception {
			private static final long id17 = 1L;
			String mistake;

			id18() {
				mistake = "Unknown.";
			}

			id18(String message) {
				mistake = message;
			}
		}

		class Real {
			String num = "0";
			long exp = 0;
			boolean pos = true;

			long length() {
				return num.length();
			}

			void check(String x) throws id18 {
				if (!id15(x, "0123456789+-.eE")) throw new id18("Illegal character.");
				long j = 0;
				for (long i = 0; i < x.length(); i++) {
					if ((x.charAt((int) i) == '-') || (x.charAt((int) i) == '+')) {
						if (j == 0) j = 1;
						else
							if (j == 5) j = 6;
							else
								throw new id18("Unexpected sign.");
					} else
						if ("0123456789".indexOf(x.charAt((int) i)) != -1) {
							if (j == 0) j = 2;
							else
								if (j == 1) j = 2;
								else
									if (j == 2)
									;
									else
										if (j == 3) j = 4;
										else
											if (j == 4)
											;
											else
												if (j == 5) j = 6;
												else
													if (j == 6)
													;
													else
														throw new id18("Unexpected digit.");
						} else
							if (x.charAt((int) i) == '.') {
								if (j == 0) j = 3;
								else
									if (j == 1) j = 3;
									else
										if (j == 2) j = 3;
										else
											throw new id18("Unexpected dot.");
							} else
								if ((x.charAt((int) i) == 'e') || (x.charAt((int) i) == 'E')) {
									if (j == 2) j = 5;
									else
										if (j == 4) j = 5;
										else
											throw new id18("Unexpected exponent.");
								} else
									throw new id18("O_o.");
				}
				if ((j == 0) || (j == 1) || (j == 3) || (j == 5)) throw new id18("Unexpected end.");
			}

			public Real(String x) throws id18 {
				check(x);
				if (x.charAt(0) == '-') pos = false;
				long j = 0;
				String e = "";
				boolean epos = true;
				for (long i = 0; i < x.length(); i++) {
					if ("0123456789".indexOf(x.charAt((int) i)) != -1) {
						if (j == 0) num += x.charAt((int) i);
						if (j == 1) {
							num += x.charAt((int) i);
							exp--;
						}
						if (j == 2) e += x.charAt((int) i);
					}
					if (x.charAt((int) i) == '.') {
						if (j == 0) j = 1;
					}
					if ((x.charAt((int) i) == 'e') || (x.charAt((int) i) == 'E')) {
						j = 2;
						if (x.charAt((int) (i + 1)) == '-') epos = false;
					}
				}
				while ((num.length() > 1) && (num.charAt(0) == '0'))
					num = num.substring(1);
				while ((num.length() > 1) && (num.charAt(num.length() - 1) == '0')) {
					num = num.substring(0, num.length() - 1);
					exp++;
				}
				if (num.equals("0")) {
					exp = 0;
					pos = true;
					return;
				}
				while ((e.length() > 1) && (e.charAt(0) == '0'))
					e = e.substring(1);
				try {
					if (e != "") if (epos) exp += Long.parseLong(e);
					else
						exp -= Long.parseLong(e);
				} catch (NumberFormatException exc) {
					if (!epos) {
						num = "0";
						exp = 0;
						pos = true;
					} else {
						throw new id18("Too long exponent");
					}
				}
			}

			public Real() {
			}

			String toString(long mantissa) {
				String a = "", b = "";
				if (exp >= 0) {
					a = num;
					if (!pos) a = '-' + a;
					for (long i = 0; i < exp; i++)
						a += '0';
					for (long i = 0; i < mantissa; i++)
						b += '0';
					if (mantissa == 0) return a;
					else
						return a + "." + b;
				} else {
					if (exp + length() <= 0) {
						a = "0";
						if (mantissa == 0) {
							return a;
						}
						if (mantissa < -(exp + length() - 1)) {
							for (long i = 0; i < mantissa; i++)
								b += '0';
							return a + "." + b;
						} else {
							if (!pos) a = '-' + a;
							for (long i = 0; i < mantissa; i++)
								if (i < -(exp + length())) b += '0';
								else
									if (i + exp >= 0) b += '0';
									else
										b += num.charAt((int) (i + exp + length()));
							return a + "." + b;
						}
					} else {
						if (!pos) a = "-";
						for (long i = 0; i < exp + length(); i++)
							a += num.charAt((int) i);
						if (mantissa == 0) return a;
						for (long i = exp + length(); i < exp + length() + mantissa; i++)
							if (i < length()) b += num.charAt((int) i);
							else
								b += '0';
						return a + "." + b;
					}
				}
			}
		}

		boolean id16(int... num) {
			Set<Integer> s = new TreeSet<Integer>();
			for (int d : num)
				if (!s.contains(d)) s.add(d);
				else
					return true;
			return false;
		}

		int[] rotateDice(int[] a, int n) {
			int[] c = new int[6];
			if (n == 0) {
				c[0] = a[1];
				c[1] = a[5];
				c[2] = a[2];
				c[3] = a[0];
				c[4] = a[4];
				c[5] = a[3];
			}
			if (n == 1) {
				c[0] = a[2];
				c[1] = a[1];
				c[2] = a[5];
				c[3] = a[3];
				c[4] = a[0];
				c[5] = a[4];
			}
			if (n == 2) {
				c[0] = a[3];
				c[1] = a[0];
				c[2] = a[2];
				c[3] = a[5];
				c[4] = a[4];
				c[5] = a[1];
			}
			if (n == 3) {
				c[0] = a[4];
				c[1] = a[1];
				c[2] = a[0];
				c[3] = a[3];
				c[4] = a[5];
				c[5] = a[2];
			}
			if (n == 4) {
				c[0] = a[0];
				c[1] = a[2];
				c[2] = a[3];
				c[3] = a[4];
				c[4] = a[1];
				c[5] = a[5];
			}
			if (n == 5) {
				c[0] = a[0];
				c[1] = a[4];
				c[2] = a[1];
				c[3] = a[2];
				c[4] = a[3];
				c[5] = a[5];
			}
			return c;
		}

		int min(int... a) {
			int c = Integer.MAX_VALUE;
			for (int d : a)
				if (d < c) c = d;
			return c;
		}

		int max(int... a) {
			int c = Integer.MIN_VALUE;
			for (int d : a)
				if (d > c) c = d;
			return c;
		}

		double maxD(double... a) {
			double c = Double.MIN_VALUE;
			for (double d : a)
				if (d > c) c = d;
			return c;
		}

		double minD(double... a) {
			double c = Double.MAX_VALUE;
			for (double d : a)
				if (d < c) c = d;
			return c;
		}

		int[] normalizeDice(int[] a) {
			int[] c = a.clone();
			if (c[0] != 0) if (c[1] == 0) c = rotateDice(c, 0);
			else
				if (c[2] == 0) c = rotateDice(c, 1);
				else
					if (c[3] == 0) c = rotateDice(c, 2);
					else
						if (c[4] == 0) c = rotateDice(c, 3);
						else
							if (c[5] == 0) c = rotateDice(rotateDice(c, 0), 0);
			while (c[1] != min(c[1], c[2], c[3], c[4]))
				c = rotateDice(c, 4);
			return c;
		}

		boolean sameDice(int[] a, int[] b) {
			for (int i = 0; i < 6; i++)
				if (a[i] != b[i]) return false;
			return true;
		}

		final double id12 = (1 + Math.sqrt(5)) / 2;
		final double id6 = (1 - Math.sqrt(5)) / 2;

		long Fib(int n) {
			if (n < 0) if (n % 2 == 0) return -Math.round((pow(id12, -n) - pow(id6, -n)) / Math.sqrt(5));
			else
				return -Math.round((pow(id12, -n) - pow(id6, -n)) / Math.sqrt(5));
			return Math.round((pow(id12, n) - pow(id6, n)) / Math.sqrt(5));
		}

		class id13 implements Comparator<String> {
			@Override
			public int compare(String a, String b) {
				int ai = 0, bi = 0;
				boolean m = false, ns = false;
				if (a.charAt(ai) <= '9' && a.charAt(ai) >= '0') {
					if (b.charAt(bi) <= '9' && b.charAt(bi) >= '0') m = true;
					else
						return -1;
				}
				if (b.charAt(bi) <= '9' && b.charAt(bi) >= '0') {
					if (a.charAt(ai) <= '9' && a.charAt(ai) >= '0') m = true;
					else
						return 1;
				}
				a += "!";
				b += "!";
				int na = 0, nb = 0;
				while (true) {
					if (a.charAt(ai) == '!') {
						if (b.charAt(bi) == '!') break;
						return -1;
					}
					if (b.charAt(bi) == '!') {
						return 1;
					}
					if (m) {
						int ab = -1, bb = -1;
						while (a.charAt(ai) <= '9' && a.charAt(ai) >= '0') {
							if (ab == -1) ab = ai;
							ai++;
						}
						while (b.charAt(bi) <= '9' && b.charAt(bi) >= '0') {
							if (bb == -1) bb = bi;
							bi++;
						}
						m = !m;
						if (ab == -1) {
							if (bb == -1) continue;
							else
								return 1;
						}
						if (bb == -1) return -1;
						while (a.charAt(ab) == '0' && ab + 1 != ai) {
							ab++;
							if (!ns) na++;
						}
						while (b.charAt(bb) == '0' && bb + 1 != bi) {
							bb++;
							if (!ns) nb++;
						}
						if (na != nb) ns = true;
						if (ai - ab < bi - bb) return -1;
						if (ai - ab > bi - bb) return 1;
						for (int i = 0; i < ai - ab; i++) {
							if (a.charAt(ab + i) < b.charAt(bb + i)) return -1;
							if (a.charAt(ab + i) > b.charAt(bb + i)) return 1;
						}
					} else {
						m = !m;
						while (true) {
							if (a.charAt(ai) <= 'z' && a.charAt(ai) >= 'a' && b.charAt(bi) <= 'z' && b.charAt(bi) >= 'a') {
								if (a.charAt(ai) < b.charAt(bi)) return -1;
								if (a.charAt(ai) > b.charAt(bi)) return 1;
								ai++;
								bi++;
							} else
								if (a.charAt(ai) <= 'z' && a.charAt(ai) >= 'a') return 1;
								else
									if (b.charAt(bi) <= 'z' && b.charAt(bi) >= 'a') return -1;
									else
										break;
						}
					}
				}
				if (na < nb) return 1;
				if (na > nb) return -1;
				return 0;
			}
		}

		Random random = new Random();
	}

	void id0(int[] a) throws IOException {
		for (int i = 0; i < a.length; i++)
			a[i] = nextInt();
	}

	String readChars(int l) throws IOException {
		String r = "";
		for (int i = 0; i < l; i++)
			r += (char) br.read();
		return r;
	}
	
	class fraction{
		long num = 0, den = 1;
		
		void reduce(){
			long d = lib.gcd(num, den);
			num /= d;
			den /= d;
		}
		
		fraction(long ch, long zn) {
			num = ch;
			den = zn;
			reduce();
		}
		
		fraction add(fraction t) {
			long nd = lib.lcm(den, t.den);
			fraction r = new fraction(nd / den * num + nd / t.den * t.num, nd);
			r.reduce();
			return r;
		}
		
		public String toString(){
			return num + "/" + den;
		}
	} 

	

}