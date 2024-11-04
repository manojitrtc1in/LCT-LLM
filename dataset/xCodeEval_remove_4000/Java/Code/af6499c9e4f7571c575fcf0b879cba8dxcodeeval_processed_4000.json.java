import java.awt.Point;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.lang.reflect.Array;
import java.security.KeyStore.Entry;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;

import java.util.*;

public class test2 {
	

	static long ans = 0;
	static ArrayList<Integer> y = new ArrayList<Integer>();
	static char[] s;
	static char[] r;
	static long[][] m;
	static long[] w;
	static int[] v;
	static int n;
	static int[] h;
	static long[] m1;
	static Boolean[] m2;
	static int[][] p;
	static ArrayList<String> arr;
	static ArrayList<Integer>[] x;
	static HashMap<String, Integer> l;
	static int[][][][] m3;
	


	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		PrintWriter sp = new PrintWriter(System.out);
		int t = sc.nextInt();
		while (t-- > 0) {
			int n = sc.nextInt();
			

			

			int ev = 2;
			int od = 1;
			if (n == 1)
				sp.println(1);
			else {
				if (n % 2 == 0) {
					for (int i = 1; i <= n; i++) {
						if (i % 2 != 0) {
							sp.print(ev + " ");
							ev += 2;
						} else {
							sp.print(od + " ");
							od += 2;
						}
					}
				} else {
					od=3;
					

					

					for (int i = 1; i <= n; i++) {
						if (i % 2 != 0) {
							if (i == n)
								sp.print((int) 1 + " ");
							else {
								sp.print(ev + " ");
								ev += 2;
							}
						} else {
							if (i == 2)
								sp.print(n + " ");
							else {
								sp.print(od + " ");
								od += 2;
							}
						}
					}

				}
			}
			
		}
		sp.flush();
		


		


	}

	public static int max(int i, int r, int n1, int n2) {
		ans++;
		if (i == v.length) {
			if (r == 1 || r == 3)
				return 0;
			else
				return Integer.MIN_VALUE;
		}
		if (m3[r][n1][n2][i] != -1)
			return m3[r][n1][n2][i];
		int leave = max(i + 1, r, n1, n2);
		int take = 0;
		if (r == 1) {
			if (v[i] == n1) {
				take = 1 + max(i + 1, r, n1, n2);
			} else
				take = 1 + max(i + 1, r + 1, n1, v[i]);
		} else if (r == 2) {
			if (v[i] == n2)
				take = 1 + max(i + 1, r, n1, n2);
			else if (v[i] == n1)
				take = 1 + max(i + 1, r + 1, n1, n2);
		} else {
			if (v[i] == n1)
				take = 1 + max(i + 1, r, n1, n2);
		}
		return m3[r][n1][n2][i] = Math.max(leave, take);

		

	}

	public static ArrayList<Character> fix(String s) {
		ArrayList<Character> x = new ArrayList<Character>();
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) != ' ') {
				x.add((s.charAt(i)));
			}
		}
		return x;
	}

	public static boolean cont(String z) {
		ArrayList<Character> s = fix(z);
		if (z.length() == 0)
			return true;
		char c = s.get(0);
		for (int i = 1; i < s.size(); i++) {
			if (s.get(i) != ' ' && s.get(i) != c)
				return false;
		}
		return true;
	}

	public static boolean id3(String s) {
		if (cont(s))
			return true;
		ArrayList<Integer> x = new ArrayList<Integer>();
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) != ' ')
				x.add((int) (s.charAt(i) - '0'));
		}
		

		boolean f = false;
		boolean found = false;
		boolean fin = true;
		;
		int c = x.get(0);
		

		for (int i = 0; i < x.size() - 1; i++) {
			if (x.get(i) == x.get(i + 1))
				continue;
			else {
				if (!f) {
					c = x.get(i);
					f = true;
				} else {
					found = true;
					if (x.get(i + 1) != c) {
						

						fin = false;
						break;
					}
				}
			}
		}
		return fin & found;

	}

	public static long lp(int node) {
		

		if (x[node].size() == 0)
			return 0;
		if (m1[node] != -1)
			return m1[node];
		long z = 0;
		for (int i : x[node]) {
			z = Math.max(z, 1 + lp(i));
		}
		return m1[node] = z;
	}

	public static boolean check(String s) {
		if (s.charAt(0) == ')')
			return false;
		Stack<Character> x = new Stack<>();
		x.add(s.charAt(0));
		for (int i = 1; i < s.length(); i++) {
			if (s.charAt(i) == '(')
				x.add(s.charAt(i));
			else {
				if (x.isEmpty())
					return false;
				x.pop();
			}
		}
		if (x.isEmpty())
			return true;
		return false;
	}

	public static boolean help(boolean op, boolean cl) {
		if (op && cl)
			return false;
		else {
			if (op || cl) {
				if (ans <= 1)
					return true;
				else
					return false;
			} else
				return false;
		}
	}

	public static boolean rbs(String x, int i) {
		if (i == s.length) {
			if (check(x)) {
				ans++;
				

				

				return true;
			} else
				return false;
		}
		if (m2[i] != null) {
			return m2[i];
		}
		boolean op = true;
		boolean cl = true;
		if (s[i] != '?')
			return m2[i] = rbs(x + s[i], i + 1);
		if (i == 0 && s[i] == '?') {
			return m2[i] = rbs(x + '(', i + 1);
		} else {
			op = rbs(x + '(', i + 1);
			cl = rbs(x + ')', i + 1);
			

			return m2[i] = help(op, cl);
		}
	}

	public static long vac(int i, int prev) {
		if (i == n)
			return 0;
		long a = 0;
		long b = 0;
		long c = 0;
		if (m[prev][i] != -1)
			return m[prev][i];
		if (prev == 0) {
			a = vac(i + 1, 1) + p[i][0];
			b = vac(i + 1, 2) + p[i][1];
			c = vac(i + 1, 3) + p[i][2];
		} else if (prev == 1) {
			b = vac(i + 1, 2) + p[i][1];
			c = vac(i + 1, 3) + p[i][2];
		} else if (prev == 2) {
			a = vac(i + 1, 1) + p[i][0];
			c = vac(i + 1, 3) + p[i][2];
		} else {
			a = vac(i + 1, 1) + p[i][0];
			b = vac(i + 1, 2) + p[i][1];
		}
		long z = Math.max(a, Math.max(c, b));
		return m[prev][i] = z;
	}

	public static long jump(int i, int k) {
		if (i >= n)
			return (long) 1e12;
		if (i == n - 1)
			return 0;
		if (m1[i] != -1)
			return m1[i];
		long z = (long) 1e12;
		for (int j = 1; j <= k; j++) {
			if (i < n - j) {
				z = Math.min(z, jump(i + j, k) + Math.abs(h[i] - h[i + j]));
			}
		}
		return m1[i] = z;

	}

	public static void trace(int i, int j) {
		if (i == s.length && j == r.length)
			return;
		

		if (i < s.length && j < r.length && s[i] == r[j]) {
			trace(i + 1, j + 1);
			

			return;
		}
		long rep = Integer.MAX_VALUE;
		long del = Integer.MAX_VALUE;
		long ins = Integer.MAX_VALUE;
		if (i < s.length && j < r.length) {
			rep = 1 + change(i + 1, j + 1);
		}
		if (j < r.length) {
			ins = 1 + change(i, j + 1);
		}
		if (i < s.length) {
			del = 1 + change(i + 1, j);
		}
		long z = m[i][j];
		if (z == rep) {
			arr.add("REPLACE " + (j + 1) + " " + r[j]);
			trace(i + 1, j + 1);
		} else if (z == del) {
			arr.add("DELETE " + (j + 1));
			trace(i + 1, j);
		} else {
			arr.add("INSERT " + (j + 1) + " " + r[j]);
			trace(i, j + 1);
		}
		return;

	}

	public static long change(int i, int j) {
		if (i == s.length && j == r.length)
			return 0;
		if (m[i][j] != -1)
			return m[i][j];
		if (i < s.length && j < r.length && s[i] == r[j]) {
			return change(i + 1, j + 1);
		}
		long rep = Integer.MAX_VALUE;
		long del = Integer.MAX_VALUE;
		long ins = Integer.MAX_VALUE;
		if (i < s.length && j < r.length) {
			rep = 1 + change(i + 1, j + 1);
		}
		if (j < r.length) {
			ins = 1 + change(i, j + 1);
		}
		if (i < s.length) {
			del = 1 + change(i + 1, j);
		}
		long z = Math.min(del, Math.min(ins, rep));
		return m[i][j] = z;
	}

	public static long ks2(int i, int val) {
		if (i == v.length) {
			if (val == 0)
				return 0;
			else
				return (long) 1e12;
		}
		if (m[i][val] != -1)
			return m[i][val];
		long take = (long) 1e12;
		long leave = ks2(i + 1, val);
		if (val >= v[i])
			take = w[i] + ks2(i + 1, val - v[i]);
		long z = Math.min(take, leave);
		return m[i][val] = z;
	}

	public static long fibit(int n, long[] m, int i) {
		if (i == n && i != 0 && i != -1) {
			return m[n - 1] + m[n - 2];
		} else if (i == n && i == 0)
			return 0;
		else if (i == n && i == 1)
			return 1;
		else {
			if (i == 0)
				m[0] = 0;
			else if (i == 1)
				m[1] = 1;
			else {
				

				m[i] = m[i - 1] + m[i - 2];
			}
			return fibit(n, m, i + 1);
		}
	}

	public static long fibdp(int n, long[] m) {
		ans++;
		if (n == 0)
			return 0;
		if (n == 1)
			return 1;
		if (m[n] != -1)
			return m[n];
		return m[n] = fibdp(n - 1, m) + fibdp(n - 2, m);
	}

	public static long chang(ArrayList<Character> c, ArrayList<Character> r, int i, Stack<String> x) {
		ans++;
		if (i >= c.size() && i >= r.size()) {
			boolean isequal = true;
			if (c.size() != r.size())
				isequal = false;
			else {
				for (int j = 0; j < c.size(); j++) {
					if (c.get(j) != r.get(j)) {
						isequal = false;
						break;
					}
				}
			}
			if (isequal)
				return 0;
			else
				return Integer.MAX_VALUE;
		}
		long ins = 0;
		long del = 0;
		long rep = 0;
		long none = 0;
		if (i >= r.size() && i < c.size()) {
			c.remove(i);
			String fun = "DELETE " + i + 1;
			x.add(fun);
			del = 1 + chang(c, r, i, x);
			return del;
		} else if (i >= c.size() && i < r.size()) {
			c.add(i, r.get(i));
			String fun = "INSERT " + i + 1 + " " + r.get(i);
			x.add(fun);
			ins = 1 + chang(c, r, i + 1, x);
			return ins;
		} else {
			if (c.get(i) == r.get(i)) {
				none = chang(c, r, i + 1, x);
				return none;
			} else {
				ArrayList<Character> temp = (ArrayList<Character>) c.clone();
				temp.add(i, r.get(i));
				ins = 1 + chang(temp, r, i + 1, x);
				temp = (ArrayList<Character>) c.clone();
				temp.remove(i);
				del = 1 + chang(temp, r, i, x);
				temp = (ArrayList<Character>) c.clone();
				temp.set(i, r.get(i));
				rep = 1 + chang(temp, r, i + 1, x);
				return Math.min(rep, Math.min(del, ins));
			}
		}
	}

	public static long tet(char in, int c, int n, long[][] m) {
		if (c == n) {
			if (in == 'D')
				return 1;
			else
				return 0;
		}
		long z = 0;
		if (in == 'D') {
			if (m[0][c] != -1)
				return m[0][c];
			else {
				z = (tet('B', c + 1, n, m) % (long) (1e9 + 7)) + (tet('A', c + 1, n, m) % (long) (1e9 + 7))
						+ (tet('C', c + 1, n, m) % (long) (1e9 + 7));
				m[0][c] = z;
			}
		} else if (in == 'A') {
			if (m[1][c] != -1)
				return m[1][c];
			z = (tet('B', c + 1, n, m) % (long) (1e9 + 7)) + (tet('D', c + 1, n, m) % (long) (1e9 + 7))
					+ (tet('C', c + 1, n, m) % (long) (1e9 + 7));
			m[1][c] = z;
		} else if (in == 'B') {
			if (m[2][c] != -1)
				return m[2][c];
			z = (tet('D', c + 1, n, m) % (long) (1e9 + 7)) + (tet('A', c + 1, n, m) % (long) (1e9 + 7))
					+ (tet('C', c + 1, n, m) % (long) (1e9 + 7));
			m[2][c] = z;
		} else {
			if (m[3][c] != -1)
				return m[3][c];
			z = (tet('B', c + 1, n, m) % (long) (1e9 + 7)) + (tet('A', c + 1, n, m) % (long) (1e9 + 7))
					+ (tet('D', c + 1, n, m) % (long) (1e9 + 7));
			m[3][c] = z;
		}
		return z;
	}

	public static long wow(int i, int r) {
		if (r == 3)
			return 1;
		if (i >= s.length)
			return 0;
		if (m[i][r] != -1)
			return m[i][r];
		else {
			long take = 0;
			long leave = wow(i + 1, r);
			if (r == 0) {
				if (s[i] == 'w') {
					take = wow(i + 1, r + 1);
					

					

					

				} 

					

					

					

			} else if (r == 1) {
				if (s[i] == 'o') {
					take = wow(i + 1, r + 1);
					

					

					

				} 

					

					

					

			} else {
				if (s[i] == 'w') {
					take = wow(i + 1, r + 1);
					

					

					

				} 

					

					

					

			}
			long z = take + leave;
			return m[i][r] = z;

		}

	}

	public static long[] max(long[] x, long[] y, boolean f) {
		if (!f) {
			if (x[0] >= y[0])
				return x;
			else
				return y;
		} else {
			if (y[1] >= x[1])
				return y;
			else
				return x;
		}
	}

	

	public static void fill(ArrayList<Integer>[] x, int st, boolean[] f) {
		if (f[st])
			return;
		else {
			f[st] = true;
			y.add(st);
			for (int i = 0; i < x[st].size(); i++) {
				fill(x, x[st].get(i), f);
			}
		}
	}

	public static void count(ArrayList<Integer>[] x, int i, int m, int cat, boolean[] f, boolean[] r, int st) {
		

		if (r[i])
			return;
		else
			r[i] = true;
		if (cat > m)
			return;
		if (x[i].size() == 1 && i != st) {
			if (f[i - 1]) {
				if (cat + 1 <= m) {
					

					ans++;
					return;
				} else
					return;
			} else {
				if (cat <= m) {
					ans++;
					return;
				}
				return;
			}
		} else {
			if (f[i - 1]) {
				for (int j = 0; j < x[i].size(); j++) {
					int n = x[i].get(j);
					count(x, n, m, cat + 1, f, r, st);
				}
			} else {
				for (int j = 0; j < x[i].size(); j++) {
					int n = x[i].get(j);
					count(x, n, m, 0, f, r, st);
				}
			}
		}

	}

	public static int[] blwh(ArrayList<Integer>[] x, int i, char[] q) {
		int[] y = new int[2];
		if (x[i].size() == 0) {
			

			if (q[i] == 'B')
				y[0]++;
			else
				y[1]++;
			return y;
		} else {
			if (q[i] == 'B')
				y[0]++;
			else
				y[1]++;
			for (int j = 0; j < x[i].size(); j++) {
				

				int[] t = blwh(x, x[i].get(j), q);
				y[0] += t[0];
				y[1] += t[1];
			}
			if (y[0] == y[1])
				ans++;
			return y;
		}

	}

	

	static class Scanner {
		StringTokenizer st;
		BufferedReader br;

		public Scanner(InputStream s) {
			br = new BufferedReader(new InputStreamReader(s));
		}

		public Scanner(FileReader r) {
			br = new BufferedReader(r);
		}

		public String next() throws IOException {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}

		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		public long nextLong() throws IOException {
			return Long.parseLong(next());
		}

		public String nextLine() throws IOException {
			return br.readLine();
		}

		public double nextDouble() throws IOException {
			String x = next();
			StringBuilder sb = new StringBuilder("0");
			double res = 0, f = 1;
			boolean dec = false, neg = false;
			int start = 0;
			if (x.charAt(0) == '-') {
				neg = true;
				start++;
			}
			for (int i = start; i < x.length(); i++)
				if (x.charAt(i) == '.') {
					res = Long.parseLong(sb.toString());
					sb = new StringBuilder("0");
					dec = true;
				} else {
					sb.append(x.charAt(i));
					if (dec)
						f *= 10;
				}
			res += Long.parseLong(sb.toString()) / f;
			return res * (neg ? -1 : 1);
		}

		public long[] id0(int n) throws IOException {
			long[] a = new long[n];
			for (int i = 0; i < n; i++)
				a[i] = nextLong();
			return a;
		}

		public Long[] id4(int n) throws IOException {
			Long[] a = new Long[n];
			for (int i = 0; i < n; i++)
				a[i] = nextLong();
			return a;
		}

		public int[] id2(int n) throws IOException {
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}

		public Integer[] id1(int n) throws IOException {
			Integer[] a = new Integer[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}

		public boolean ready() throws IOException {
			return br.ready();
		}

	}

}





