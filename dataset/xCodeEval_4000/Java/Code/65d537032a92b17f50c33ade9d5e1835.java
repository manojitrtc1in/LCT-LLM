
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.*;
import java.util.concurrent.ThreadLocalRandom;

public class c731 {
	public static void main(String[] args) throws IOException {

		BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pt = new PrintWriter(System.out);
		FastReader sc = new FastReader();
		int o1 = sc.nextInt();
		for (int t1 = 0; t1 < o1; t1++) {
		int n = sc.nextInt();
		long m = sc.nextInt();
		long[] arr = new long[n];
		for(int i = 0 ; i < n;i++) {
			arr[i] = sc.nextLong();
		}
		int k = sc.nextInt();
		long[] brr = new long[k];
		for(int i = 0 ; i < k;i++) {
			brr[i] = sc.nextLong();
		}
		ArrayList<prr> al1 = new ArrayList<>();
		ArrayList<prr> al2 = new ArrayList<>();
		for(int i = 0 ; i<n ; i++) {
			int s = al1.size();
			if(arr[i]%m != 0) {
				if(s >0 && al1.get(s-1).a == arr[i]) {
					al1.get(s-1).b += 1;
				}else {
					prr pp = new prr(arr[i], 1);
					
					al1.add(pp);
				}
				continue;
		
			}
			int c = 0;
			long tmp = arr[i];
			while((tmp%m) == 0) {
				c++;
				tmp /= m;
			}
			long fq = (long)Math.pow(m, c);
			
			if(s >0 && al1.get(s-1).a == tmp) {
				al1.get(s-1).b += fq;
			}else {
				prr pp = new prr(tmp, fq);
				




				al1.add(pp);
			}
			
			
			
	}
		for(int i = 0 ; i<k ; i++) {
			int s = al2.size();
			
			if(brr[i]%m != 0) {
				if(s >0 && al2.get(s-1).a == brr[i]) {


					al2.get(s-1).b += 1;
				}else {
					prr pp = new prr(brr[i], 1);
					




					al2.add(pp);
				}
				continue;
			
			}
			int c = 0;
			long tmp = brr[i];
			while((tmp%m) == 0) {
				c++;
				tmp /= m;
			}
			long fq = (long)Math.pow(m, c);
			
			if(s >0 && al2.get(s-1).a == tmp) {


				al2.get(s-1).b += fq;
			}else {
				prr pp = new prr(tmp, fq);
				




				al2.add(pp);
			}
			
			
			
	}
		if(al1.size()!=al2.size()) {
			System.out.println("NO");
		}else {
			int f = 0;
			int s = al1.size();
			for(int i = 0 ; i<s;i++) {
				prr p1 = al1.get(i);
				prr p2 = al2.get(i);
				if(p1.a!= p2.a) {
					f = 1;
					break;
				}
				if(p1.b!= p2.b) {
					f = 1;
					break;
				}
			}
		if(f == 1) {
			System.out.println("NO");
		}else {
			System.out.println("YES");
		}
		}
		












		}
	}



	public static void dfs(HashMap<Integer, ArrayList<Integer>> map, int s, int p, int[] val, int[] arr) {

		for (int x : map.get(s)) {
			if (x != p) {
				dfs(map, x, s, val, arr);


			}

		}


		for (int x : map.get(s)) {
			if (x != p) {
				val[s - 1] += val[x - 1];
			}
		}

	}

	public static ArrayList<Long> printDivisors(long n) {
		ArrayList<Long> al = new ArrayList<>();
		for (long i = 1; i <= Math.sqrt(n); i++) {
			if (n % i == 0) {
				if (n / i == i)
					al.add(i);

				else {
					al.add(i);
					al.add(n / i);
				}
			}
		}
		return al;
	}

	public static boolean palin(String s) {
		int n = s.length();
		int i = 0;
		int j = n - 1;
		while (i <= j) {
			if (s.charAt(i) != s.charAt(j)) {
				return false;
			}
			i++;
			j--;

		}
		return true;
	}

	public static boolean check(int[] arr, int n, int v, int l) {
		int x = v / 2;
		int y = v / 2;


		if (v % 2 == 1) {
			x++;
		}
		for (int i = 0; i < n; i++) {
			int d = l - arr[i];
			int c = Math.min(d / 2, y);
			y -= c;
			arr[i] -= c * 2;
			if (arr[i] > x) {
				return false;
			}
			x -= arr[i];

		}
		return true;
	}

	public static int cnt_set(long x) {
		long v = 1l;
		int c = 0;
		int f = 0;
		while (v <= x) {
			if ((v & x) != 0) {
				c++;

			}
			v = v << 1;
		}
		return c;
	}

	public static int lis(int[] arr, int[] dp) {
		int n = arr.length;
		ArrayList<Integer> al = new ArrayList<Integer>();
		al.add(arr[0]);
		dp[0] = 1;
		for (int i = 1; i < n; i++) {
			int x = al.get(al.size() - 1);
			if (arr[i] > x) {
				al.add(arr[i]);
			} else {
				int v = lower_bound(al, 0, al.size(), arr[i]);


				al.set(v, arr[i]);
			}
			dp[i] = al.size();
		}



		return al.size();
	}

	public static int lis2(int[] arr, int[] dp) {
		int n = arr.length;
		ArrayList<Integer> al = new ArrayList<Integer>();
		al.add(-arr[n - 1]);
		dp[n - 1] = 1;


		for (int i = n - 2; i >= 0; i--) {
			int x = al.get(al.size() - 1);


			if ((-arr[i]) > x) {
				al.add(-arr[i]);
			} else {
				int v = lower_bound(al, 0, al.size(), -arr[i]);


				al.set(v, -arr[i]);
			}
			dp[i] = al.size();
		}



		return al.size();
	}

	static int cntDivisors(int n) {
		int cnt = 0;
		for (int i = 1; i <= Math.sqrt(n); i++) {
			if (n % i == 0) {
				if (n / i == i)
					cnt++;

				else
					cnt += 2;
			}
		}

		return cnt;
	}

	public static long power(long x, long y, long p) {
		long res = 1;

		x = x % p;

		if (x == 0)
			return 0;

		while (y > 0) {

			if ((y & 1) != 0)
				res = (res * x) % p;

			y = y >> 1;
			x = (x * x) % p;

		}
		return res;
	}

	public static long ncr(long[] fac, int n, int r, long m) {
		if (r > n) {
			return 0;
		}
		return fac[n] * (modInverse(fac[r], m)) % m * (modInverse(fac[n - r], m)) % m;
	}

	public static int lower_bound(ArrayList<Integer> arr, int lo, int hi, int k) {
		int s = lo;
		int e = hi;
		while (s != e) {
			int mid = s + e >> 1;
			if (arr.get(mid) < k) {
				s = mid + 1;
			} else {
				e = mid;
			}
		}
		if (s == arr.size()) {
			return -1;
		}
		return s;
	}

	public static int upper_bound(ArrayList<Integer> arr, int lo, int hi, int k) {
		int s = lo;
		int e = hi;
		while (s != e) {
			int mid = s + e >> 1;
			if (arr.get(mid) <= k) {
				s = mid + 1;
			} else {
				e = mid;
			}
		}
		if (s == arr.size()) {
			return -1;
		}
		return s;
	}



	public static long gcd(long a, long b) {
		if (a == 0)
			return b;
		return gcd(b % a, a);
	}



	public static long modInverse(long a, long m) {
		long m0 = m;
		long y = 0, x = 1;

		if (m == 1)
			return 0;

		while (a > 1) {
			

			long q = a / m;

			long t = m;

			

			

			m = a % m;
			a = t;
			t = y;

			

			y = x - q * y;
			x = t;
		}

		

		if (x < 0)
			x += m0;

		return x;
	}







	public static int find(int[] parent, int u) {
		while (u != parent[u]) {
			parent[u] = parent[parent[u]];
			u = parent[u];
		}
		return u;
	}

	private static void union(int[] parent, int[] size, int u, int v) {
		int rootU = find(parent, u);
		int rootV = find(parent, v);
		if (rootU == rootV) {
			return;
		}
		if (size[rootU] < size[rootV]) {
			parent[rootU] = rootV;
			size[rootV] += size[rootU];
		} else {
			parent[rootV] = rootU;
			size[rootU] += size[rootV];
		}
	}



	

	

	public static void build(long[] seg, long[] arr, int idx, int lo, int hi) {
		if (lo == hi) {
			seg[idx] = arr[lo];
			return;
		}
		int mid = (lo + hi) / 2;
		build(seg, arr, 2 * idx + 1, lo, mid);
		build(seg, arr, idx * 2 + 2, mid + 1, hi);
		seg[idx] = seg[idx * 2 + 1] + seg[idx * 2 + 2];
	}



	public static long query(long[] seg, int idx, int lo, int hi, int l, int r) {

		if (lo >= l && hi <= r) {
			return seg[idx];
		}
		if (hi < l || lo > r) {
			return 0;
		}
		int mid = (lo + hi) / 2;
		long left = query(seg, idx * 2 + 1, lo, mid, l, r);
		long right = query(seg, idx * 2 + 2, mid + 1, hi, l, r);
		return left + right;
	}

	public static void build2(long[] seg, long[] arr, int idx, int lo, int hi) {
		if (lo == hi) {
			seg[idx] = arr[lo];
			return;
		}
		int mid = (lo + hi) / 2;
		build2(seg, arr, 2 * idx + 1, lo, mid);
		build2(seg, arr, idx * 2 + 2, mid + 1, hi);
		seg[idx] = Math.max(seg[idx * 2 + 1], seg[idx * 2 + 2]);
	}

	public static long query2(long[] seg, int idx, int lo, int hi, int l, int r) {
		if (r < l) {
			return Long.MIN_VALUE;
		}

		if (lo >= l && hi <= r) {
			return seg[idx];
		}
		if (hi < l || lo > r) {
			return Long.MIN_VALUE;
		}
		int mid = (lo + hi) / 2;
		long left = query(seg, idx * 2 + 1, lo, mid, l, r);
		long right = query(seg, idx * 2 + 2, mid + 1, hi, l, r);
		return Math.max(left, right);
	}

	public static void update(boolean[] seg, int idx, int lo, int hi, int node, boolean val) {
		if (lo == hi) {
			seg[idx] = val;
		} else {
			int mid = (lo + hi) / 2;
			if (node <= mid && node >= lo) {
				update(seg, idx * 2 + 1, lo, mid, node, val);
			} else {
				update(seg, idx * 2 + 2, mid + 1, hi, node, val);
			}
			seg[idx] = seg[idx * 2 + 1] & seg[idx * 2 + 2];

		}


	}





























































}

class FastReader {
	BufferedReader br;
	StringTokenizer st;

	public FastReader() {
		br = new BufferedReader(new InputStreamReader(System.in));
	}

	String next() {
		while (st == null || !st.hasMoreElements()) {
			try {
				st = new StringTokenizer(br.readLine());

			} catch (IOException e) {
				e.printStackTrace();
			}
		}
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

	String nextLine() {
		String str = "";
		try {
			str = br.readLine();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return str;
	}
}






class coup {
	int a;
	long b;

	public coup(int a, long b) {
		this.a = a;
		this.b = b;
	}
}

class dob {
	int a;
	long b;

	public dob(int a, long b) {
		this.a = a;
		this.b = b;
	}
}
class prr{
	long a;
	long b;
	public prr(long a, long b) {
		this.a = a;
		this.b = b;
	}
}
class trip {
	int a;
	int b;
	int c;

	public trip(int a, int b, int c) {
		this.a = a;
		this.b = b;
		this.c = c;
	}
}
