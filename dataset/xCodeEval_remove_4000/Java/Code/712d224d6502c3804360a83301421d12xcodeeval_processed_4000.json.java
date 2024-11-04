import java.io.IOException;
import java.io.InputStreamReader;
import java.io.StreamTokenizer;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.MathContext;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Locale;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class Main implements Runnable {

	
	public static void main(String[] args) {
		new Thread(new Main()).start();
	}

	public void run() {
		Locale.setDefault(Locale.US);
		try {
			run1();
		} catch (IOException e) {
			throw new RuntimeException();
		}
	}

	int nextInt(StreamTokenizer st) throws IOException {
		st.nextToken();
		return (int) st.nval;
	}

	private List<Integer> kmp(String x, String a) {
		String s = a + "$" + x;
		int[] oppa = new int[s.length()];
		oppa[0] = 0;
		int tmp = 0;
		List<Integer> res = new ArrayList<Integer>();
		for (int i = 1; i < s.length(); i++) {
			while (tmp != 0 && s.charAt(tmp) != s.charAt(i)) {
				

				tmp = oppa[tmp - 1];
			}
			if (s.charAt(tmp) == s.charAt(i))
				tmp++;
			oppa[i] = tmp;
			if (tmp == a.length()) {
				res.add(i - a.length() - a.length());
			}
		}
		return res;
	}

	double nextDouble(StreamTokenizer st) throws IOException {
		st.nextToken();
		return st.nval;
	}

	String nextLine(StreamTokenizer st) throws IOException {
		st.nextToken();
		return st.sval;
	}

	int cnt = 0;
	int[] col;

	void unite(int a, int b) {
		if (cnt % 2 == 0)
			col[getCol(a)] = getCol(b);
		else
			col[getCol(b)] = getCol(a);
		cnt++;
	}

	int getCol(int a) {
		return a == col[a] ? a : (col[a] = getCol(col[a]));
	}

	int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	int[] val = new int[11];
	int[][] dist = new int[11][11];

	int[] dnum = new int[] { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	int id0(int m, int y) {
		if (m == 2) {
			if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
				return 29;
		}
		return dnum[m];
	}

	void nextDay(int[] day) {
		day[3]++;
		day[2]++;
		if (day[2] == id0(day[1], day[0]) + 1) {
			day[1]++;
			day[2] = 1;
		}
		if (day[1] == 13) {
			day[0]++;
			day[1] = 1;
		}
	}

	long[][] C = new long[1000][1001];

	Map<Long, Long> phi = new HashMap<Long, Long>();

	long max = 100000000000000000l;

	String[] name = new String[] { "Sheldon", "Leonard", "Penny", "Rajesh",
			"Howard" };

	int[] pr;

	public void run1() throws IOException {


		 Scanner sc = new Scanner(new InputStreamReader(System.in));
		

		

		

		

		

		int n = sc.nextInt();
		int[] arr = new int[n];
		for (int i = 0; i < n; i++)
			arr[i] = sc.nextInt();
		for (int k = 0; k + k < n; k++) {
			int tmp = arr[k];
			arr[k] = arr[n - 1 - k];
			arr[n - 1 - k] = tmp;
		}
		int[][][] none = new int[n][n][2];
		if (n % 2 == 1) {
			for (int j = 0; j < n; j++)
				none[0][j][0] = arr[j];
		} else {
			for (int j = 0; j < n; j++)
				none[1][j][0] = Math.max(arr[j], arr[0]);
		}
		for (int left = 2; left < n; left++)
			if (left % 2 != n % 2) {
				for (int j = 0; j < n; j++) {
					int poss1 = none[left - 2][j][0]
							+ Math.max(arr[left - 1], arr[left - 2]);
					int poss2 = none[left - 2][left - 1][0]
							+ Math.max(arr[left - 2], arr[j]);
					int poss3 = none[left - 2][left - 2][0]
							+ Math.max(arr[left - 1], arr[j]);
					if (poss1 <= poss2 && poss1 <= poss3) {
						none[left][j][0] = poss1;
						none[left][j][1] = j;
					}
					if (poss2 <= poss3 && poss2 <= poss1) {
						none[left][j][0] = poss2;
						none[left][j][1] = left - 1;
					}
					if (poss3 <= poss2 && poss3 <= poss1) {
						none[left][j][0] = poss3;
						none[left][j][1] = left - 2;
					}
				}
			}
		System.out.println(none[n - 1][n - 1][0]);
		int cur1 = n - 1;
		int cur2 = n - 1;
		while (cur1 >= 2) {
			if (cur2 == none[cur1][cur2][1])
				System.out.println((n - (cur1 - 1)) + " "
						+ (n - (cur1 - 2) + " "));
			else if (cur1 - 1 == none[cur1][cur2][1]) {
				System.out.println((n - cur2) + " " + (n - (cur1 - 2)));
			} else if (cur1 - 2 == none[cur1][cur2][1])
				System.out.println((n - cur2) + " " + (n - (cur1 - 1)));
			cur2 = none[cur1][cur2][1];
			cur1 -= 2;
		}
		if (cur1 == 1)
			System.out.println(n - cur2 + " " + (n - (cur1 - 1)));
		else
			System.out.println(n - cur2);
	}

	long isSq(long a) {
		long b = (long) Math.sqrt(a) - 1;
		while (b * b < a)
			b++;
		if (b * b == a) {
			return b;
		}
		return -1;
	}

	void countC(int max, long mod) {
		for (int i = 0; i <= max; i++) {
			C[i][0] = C[i][i] = 1;
			for (int j = 1; j < i; j++)
				C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
		}
	}

	private void p9() {
		int max = 10000000;
		int[] last = new int[max + 1];
		for (int i = 2; i <= max; i++) {
			if (last[i] == 0)
				for (int j = i; j <= max; j += i)
					last[j] = i;
		}

		boolean[] sqFr = sqfr(max);
		boolean[] res = new boolean[max + 1];
		res[1] = true;
		for (int i = 2; i <= max; i++) {
			if (i % 16 == 0) {
				res[i] = false;
				continue;
			}
			if (i % 2 == 0) {
				res[i] = res[i / 2];
				continue;
			}
			int tmp = last[i];
			while (i / tmp % last[i] == 0) {
				tmp *= last[i];
			}
			

			

			res[i] = res[i / tmp] && sqFr[tmp - tmp / last[i]];
			

			

			

			

			

			

			

			

			

			

			

			

			

			

		}
		long r = 0;
		for (int i = 0; i <= max; i++)
			if (res[i])
				r += i;
		System.out.println(r);
	}

	long cmod(long n, long k, long mod) {
		long res = 1;
		for (int i = 1; i <= k; i++) {
			res *= inv(i, mod);
			res %= mod;
		}
		for (long i = n; i > n - k; i--) {
			res *= i;
			res %= mod;
		}
		return res;
	}

	long p6(int n, int p, int i, int j) {
		long mod = 100000007;
		int a = i - 1;
		int b = p - i;
		long res = 0;
		long cur = 1;
		for (int k = j; k <= n; k++) {
			res += cur * cmod(a + k + 1 - 1, a, mod) % mod
					* cmod(b + n - k + 1 - 1, b, mod) % mod;
			res %= mod;
			cur *= k + 1;
			cur %= mod;
			cur *= inv(k + 1 - j, mod);
			cur %= mod;
			res %= mod;
		}
		return res;
	}

	long inv(long a, long p) {
		return pow(a, p - 2, p);
	}

	boolean[] sqfr(int max) {
		boolean[] res = new boolean[max + 1];
		Arrays.fill(res, true);
		for (int i = 2; i * i <= max; i++) {
			for (int j = i * i; j <= max; j += i * i)
				res[j] = false;
		}
		return res;
	}

	private boolean check(int i, int[] last) {
		List<Integer> l = getDiv(i, last);
		Collections.sort(l);
		boolean ok = true;
		int s = 0;
		for (int j = 0; j < l.size(); j++) {
			if (s < l.get(j) - 1) {
				ok = false;
				break;
			}
			s += l.get(j);
		}
		return ok;
	}

	List<Integer> getDiv(int a, int[] last) {
		List<Integer> res = new ArrayList<Integer>();
		if (a == 1) {
			res.add(1);
			return res;
		}
		int tmp = last[a];
		List<Integer> tmpList = getDiv(a / tmp, last);
		int st = 1;
		while (a % tmp == 0) {
			st *= tmp;
			a /= tmp;
		}
		res.addAll(getDiv(a, last));
		for (int b : tmpList)
			res.add(b * tmp);
		return res;
	}

	long count(int a, int[] arr, long mod) {
		System.out.println(a + " " + mod);
		if (a == arr.length)
			return 1;
		if (mod == 1)
			return 0;
		return pow(arr[a], count(a + 1, arr, phi(mod)), mod);
	}

	long phi(long a) {
		long res = 1;
		for (int p = 2; p * p <= a; p++) {
			if (a % p == 0) {
				res *= p - 1;
				a /= p;
				while (a % p == 0) {
					res *= p;
					a /= p;
				}
			}
		}
		if (a != 1)
			res *= a - 1;
		return res;
	}

	long get(long max, List<Long> l, int cur, Map<Long, Long> map) {
		if (map.containsKey(max))
			return map.get(max);
		long fn = l.get(cur);
		if (max <= fn) {
			return get(max, l, cur - 1, map);
		}
		long res = get(fn, l, cur - 1, map) + get(max - fn, l, cur - 1, map)
				+ max - fn;
		map.put(max, res);
		return res;
	}

	void get(long prod, int i, int m, int[] pr, Set<Integer> set) {
		if (i > m)
			return;
		long p = pr[i];
		boolean op = prod != 1 || p == 2;
		prod *= p;
		while (prod <= max) {
			if (op)
				set.add((int) prod);
			get(prod, i + 1, m, pr, set);
			prod *= p;
		}
	}

	double area(double a, double b, double c) {
		double p = a + b + c;
		p /= 2;
		return Math.sqrt(p * (p - a) * (p - b) * (p - c));
	}

	long get(long a, int max1, long max2) {
		int[] pl = id2(max1);
		List<long[]> l = new LinkedList<long[]>();
		l.add(new long[] { 1, 1 });
		long sum = 1;
		for (int p : pl) {
			for (Iterator<long[]> it = l.iterator(); it.hasNext();) {
				if (it.next()[0] * p > max2)
					it.remove();
			}

			Collections.sort(l, new Comparator<long[]>() {
				public int compare(long[] a, long[] b) {
					if (a[0] > b[0])
						return 1;
					if (a[0] < b[0])
						return -1;
					return 0;
				}
			});
		}
		return 0;
	}

	int id1(long min, long max, int[] pr) {
		int n = (int) (max - min) / 2;
		boolean[] isP = new boolean[n];
		Arrays.fill(isP, true);
		int l = 0;
		int r = pr.length;
		while (l + 1 < r) {
			int m = (l + r) / 2;
			long tmp = pr[m];
			if (tmp * tmp >= max) {
				r = m;
			} else
				l = m;
		}
		for (int i = 1; i < r; i++) {
			int pi = pr[i];
			long p = pr[i];
			int st = (int) (p - min % p);
			if ((st & 1) == 0)
				st += p;
			st /= 2;
			if (st >= pi)
				st -= pi;
			while (st < n) {
				isP[st] = false;
				st += pi;
			}
		}
		int res = 0;
		

		for (int i = 0; i < n; i++)
			if (isP[i])
				res++;
		

		return res;
	}

	long pow(long a, long deg, long mod) {
		if (deg == 0)
			return 1;
		long res = pow(a, deg / 2, mod);
		res *= res;
		res %= mod;
		if (deg % 2 == 1) {
			res *= a;
			res %= mod;
		}
		return res;
	}

	BigDecimal sqrt(BigDecimal sum, MathContext mc) {
		BigDecimal l = BigDecimal.ZERO;
		BigDecimal r = sum;
		for (int k = 0; k < 100000; k++) {
			BigDecimal m = l.add(r, mc).divide(BigDecimal.valueOf(2), mc);
			if (m.multiply(m).compareTo(sum) < 0)
				l = m;
			else
				r = m;
		}
		return l;
	}

	boolean[] getP(long min, long max) {
		int n = (int) (max - min);
		boolean[] res = new boolean[n + 1];
		Arrays.fill(res, true);
		int[] pl = id2(2000000);
		for (int p : pl) {
			int st = (int) ((p - min % p) % p);
			while (st <= n) {
				res[st] = false;
				st += p;
			}
		}
		return res;
	}

	long[] del(long n) {
		long[] pd = new long[20];
		int pn = 0;
		for (long p = 2; p * p <= n; p++) {
			while (n % p == 0) {
				pd[pn++] = p;
				n /= p;
			}
		}
		if (n > 1) {
			pd[pn++] = n;
		}
		

		

		Set<Long> res = new HashSet<Long>();
		for (int mask = 0; mask < (1 << pn); mask++) {
			long tmp = 1;
			long id3 = 1;
			for (int i = 0; i < pn; i++) {
				if (((1 << i) & mask) != 0) {
					if (tmp % pd[i] == 0)
						id3 *= pd[i];
					else
						id3 *= pd[i] - 1;
					tmp *= pd[i];
				}
			}
			phi.put(tmp, id3);
			res.add(tmp);
		}
		pn = 0;
		long[] r = new long[res.size()];
		for (long a : res) {
			r[pn++] = a;
		}
		Arrays.sort(r);
		return r;
	}

	long[] prod(long[] a, long[][] b, long mod) {
		long[] res = new long[a.length];
		for (int i = 0; i < a.length; i++)
			for (int j = 0; j < a.length; j++) {
				res[j] += a[i] * b[i][j];
				res[j] %= mod;
			}
		return res;
	}

	long[] ras(long[] arr) {
		int n = arr.length;
		long[] res = new long[n - 1];
		for (int i = 0; i < n - 1; i++)
			res[i] = arr[i + 1] - arr[i];
		return res;
	}

	long[][] pow(long[][] m, long deg, long mod) {
		if (deg == 1) {
			return m;
		}
		long[][] res = pow(m, deg / 2, mod);
		res = prod(res, res, mod);
		if (deg % 2 == 1)
			res = prod(res, m, mod);
		return res;
	}

	long[][] prod(long[][] a, long[][] b, long mod) {
		int n = a.length;
		long[][] res = new long[n][n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int k = 0; k < n; k++) {
					res[i][j] += a[i][k] * b[k][j];
					res[i][j] %= mod;
				}
		return res;
	}

	void print(long[] arr) {
		for (int i = 0; i < arr.length; i++)
			System.out.print(arr[i] + " ");
		System.out.println();
	}

	void print(long[][] arr) {
		for (long[] tmp : arr)
			print(tmp);
		System.out.println();
	}

	long[] next(long[] cur, int[] per) {
		long[] res = Arrays.copyOf(cur, 8);
		res[per[0]] += 1000 * res[7] + cur[per[1]] + cur[per[2]] + cur[per[3]]
				* 2;
		res[per[4]] = cur[per[4]] * 2 + 13 * res[7];
		res[per[5]] = cur[per[5]] * 3;
		res[per[0]] += cur[per[6]];
		res[per[6]] = 0;
		return res;
	}

	BigInteger C(int n, int k) {
		BigInteger res = BigInteger.ONE;
		for (int i = 1; i <= k; i++) {
			res = res.multiply(BigInteger.valueOf(n - k + i));
			res = res.divide(BigInteger.valueOf(i));
		}
		return res;
	}

	boolean isPrime(long a) {
		for (long i = 2; i * i <= a; i++) {
			if (a % i == 0)
				return false;
		}
		return true;
	}

	long gcd(long a, long b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	boolean prevPermutation(int[] per) {
		int m = per.length;
		int t = m - 2;
		while (t >= 0 && per[t] < per[t + 1]) {
			t--;
		}
		if (t < 0)
			return false;
		if (t == 0)
			System.out.println(per[t]);
		int i = t + 1;
		int j = m - 1;
		while (i < j) {
			int tmp = per[i];
			per[i] = per[j];
			per[j] = tmp;
			i++;
			j--;
		}
		i = t + 1;
		while (per[i] > per[t])
			i++;
		{
			int tmp = per[i];
			per[i] = per[t];
			per[t] = tmp;
		}
		return true;
	}

	private int[] id2(int max) {
		boolean[] isp = new boolean[max];
		Arrays.fill(isp, true);
		isp[0] = isp[1] = false;
		for (int i = 2; i * i < max; i++)
			if (isp[i]) {
				for (int j = i + i; j < max; j += i)
					isp[j] = false;
			}
		int[] p = new int[max];
		int pn = 0;
		for (int i = 2; i * i < max; i++)
			if (isp[i])
				p[pn++] = i;
		return Arrays.copyOf(p, pn);
	}
}